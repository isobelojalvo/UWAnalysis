// system include files
#include <memory>

// user include files

#include <TTree.h>
#include <TH2D.h>
#include <TFile.h>

#include "TRandom3.h"

#include "UWAnalysis/NtupleTools/interface/NtupleFillerBase.h"

#include "CondFormats/BTauObjects/interface/BTagCalibration.h"
#include "CondFormats/BTauObjects/interface/BTagCalibrationReader.h"

#include "UWAnalysis/RecoTools/plugins/BTagCalibrationStandalone.h"

#include "DataFormats/PatCandidates/interface/Jet.h"
#include "Math/GenVector/VectorUtil.h" 
#include "TMath.h"
//
// class decleration
//

template<typename T>
class EffCSVFiller : public NtupleFillerBase {
	public:
		EffCSVFiller(){
		}


		EffCSVFiller(const edm::ParameterSet& iConfig, TTree* t, edm::ConsumesCollector && iC ):
			src_(iC.consumes<std::vector<T> >(iConfig.getParameter<edm::InputTag>("src"))) 
	{
		value = new float[9];
		t->Branch("EffCSVWeight1",&value[0],"EffCSVWeight1/F");
		t->Branch("EffCSVWeight1Up",&value[1],"EffCSVWeight1Up/F");
		t->Branch("EffCSVWeight1Down",&value[2],"EffCSVWeight1Down/F");
		t->Branch("EffCSVWeight2",&value[3],"EffCSVWeight2/F");
		t->Branch("EffCSVWeight2Up",&value[4],"EffCSVWeight2Up/F");
		t->Branch("EffCSVWeight2Down",&value[5],"EffCSVWeight2Down/F");
		t->Branch("EffCSVWeight0",&value[6],"EffCSVWeight0/F");
		t->Branch("EffCSVWeight0Up",&value[7],"EffCSVWeight0Up/F");
		t->Branch("EffCSVWeight0Down",&value[8],"EffCSVWeight0Down/F");
		calib=new BTagCalibration("CSVv2", std::string(std::getenv("CMSSW_BASE"))+"/src/UWAnalysis/Configuration/data/CSVv2_76.csv");
		reader_light=new BTagCalibrationReader(calib, BTagEntry::OP_MEDIUM, "incl", "central");
		reader_light_up=new BTagCalibrationReader(calib, BTagEntry::OP_MEDIUM, "incl", "up");
		reader_light_down=new BTagCalibrationReader(calib, BTagEntry::OP_MEDIUM, "incl", "down");
		reader=new BTagCalibrationReader(calib, BTagEntry::OP_MEDIUM, "mujets", "central");
		reader_up=new BTagCalibrationReader(calib, BTagEntry::OP_MEDIUM, "mujets", "up");  // sys up
		reader_down=new BTagCalibrationReader(calib, BTagEntry::OP_MEDIUM, "mujets", "down");  // sys down
	}


		~EffCSVFiller()
		{ 
		}

		void fill(const edm::Event& iEvent, const edm::EventSetup& iSetup)
		{
			double nbtagweight=0;
			double nbtagweightup=0;
			double nbtagweightdown=0;



			edm::Handle<std::vector<T>> handle;


			std::vector<double> SF,SFup,SFdown;

			if( iEvent.getByToken(src_,handle)){
				for( int i=0; i<handle->at(0).jets().size(); i++){
					if(handle->at(0).jets().at(i)->pt()<30 && abs(handle->at(0).jets().at(i)->eta())>2.4 ) continue;
					if (SF.size()>1) break;//if 2 SF jets with cuts pass-> break
					double pt = handle->at(0).jets().at(i)->pt();
					double eta = handle->at(0).jets().at(i)->eta();
					int jetflavor = abs(handle->at(0).jets().at(i)->partonFlavour());
					if (handle->at(0).jets().at(i)->bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.80){
						std::cout<< "Flavor: "<<jetflavor<<std::endl;
						if (jetflavor==5){
							SF.push_back(reader->eval(BTagEntry::FLAV_B, eta, pt ));
							SFup.push_back(reader_up->eval(BTagEntry::FLAV_B, eta, pt ));
							SFdown.push_back(reader_down->eval(BTagEntry::FLAV_B, eta, pt ));
						}
						else if (jetflavor==4) {
							SF.push_back(reader->eval(BTagEntry::FLAV_C, eta, pt ));
							SFup.push_back(reader_up->eval(BTagEntry::FLAV_C, eta, pt ));
							SFdown.push_back(reader_down->eval(BTagEntry::FLAV_C, eta, pt ));
						}
						else {
							SF.push_back(reader_light->eval(BTagEntry::FLAV_UDSG, eta, pt ));
							SFup.push_back(reader_light_up->eval(BTagEntry::FLAV_UDSG, eta, pt ));
							SFdown.push_back(reader_light_down->eval(BTagEntry::FLAV_UDSG, eta, pt ));
						}
					}//end pass btag
				}//end for jets
			}
			nbtagweight=bTagEventWeight(SF, 1); 
			nbtagweightup=bTagEventWeight(SFup, 1); 
			nbtagweightdown=bTagEventWeight(SFdown, 1); 



			value[0]=bTagEventWeight(SF, 1);
			value[1]=bTagEventWeight(SFup, 1);
			value[2]=bTagEventWeight(SFdown, 1);
			value[3]=bTagEventWeight(SF, 2);
			value[4]=bTagEventWeight(SFup, 2);
			value[5]=bTagEventWeight(SFdown, 2);
			value[6]=bTagEventWeight(SF, 0);
			value[7]=bTagEventWeight(SFup, 0);
			value[8]=bTagEventWeight(SFdown, 0);
		}


		double bTagEventWeight(std::vector<double>& SFsForBTaggedJets, unsigned int nBTags){
			if( SFsForBTaggedJets.size() > 2 )
			{
				edm::LogError("MyAnalyzer::bTagEventWeight") << "Only two leading jets are considered. Hence, the number of b-tagged jets cannot exceed 2.";
				exit(1);
			}
			if( nBTags > 2 )
			{
				edm::LogError("MyAnalyzer::bTagEventWeight") << "Only two leading jets are considered. Hence, the number of b-tags cannot exceed 2.";
				exit(1);
			}
			/*
##################################################################
Event weight matrix:
------------------------------------------------------------------
nBTags\b-tagged jets  |    0        1             2
------------------------------------------------------------------
0                   |    1      1-SF      (1-SF1)(1-SF2)

1                   |    0       SF    SF1(1-SF2)+(1-SF1)SF2

2                   |    0        0           SF1SF2
##################################################################
*/

			if( nBTags > SFsForBTaggedJets.size() ) return 0.0;

			if( nBTags==0 && SFsForBTaggedJets.size()==0 ) return 1.0;

			double weight = 0;

			if( SFsForBTaggedJets.size()==1 )
			{
				double SF = SFsForBTaggedJets.at(0);

				for( unsigned int i=0; i<=1; ++i )
				{
					if( i != nBTags ) continue;

					weight += pow(SF,i)*pow(1-SF,1-i);
				}
			}
			else if( SFsForBTaggedJets.size()==2 )
			{
				double SF1 = SFsForBTaggedJets.at(0);
				double SF2 = SFsForBTaggedJets.at(1);

				for( unsigned int i=0; i<=1; ++i )
				{
					for( unsigned int j=0; j<=1; ++j )
					{
						if( (i+j) != nBTags ) continue;

						weight += pow(SF1,i)*pow(1-SF1,1-i)*pow(SF2,j)*pow(1-SF2,1-j);
					}
				}
			}
			return weight;
		}

	protected:
		edm::EDGetTokenT<std::vector<T> > src_;
		std::string tag_;
		float* value;

		BTagCalibration *calib;
		BTagCalibrationReader *reader;
		BTagCalibrationReader *reader_up;
		BTagCalibrationReader *reader_down;
		BTagCalibrationReader *reader_light;
		BTagCalibrationReader *reader_light_up;
		BTagCalibrationReader *reader_light_down;

};


#include "UWAnalysis/DataFormats/interface/CompositePtrCandidateT1T2MEt.h"
#include "UWAnalysis/DataFormats/interface/CompositePtrCandidateTMEt.h"

typedef EffCSVFiller<PATMuTauPair> PATMuTauPairEffCSVFiller;
typedef EffCSVFiller<PATElecTauPair> PATEleTauPairEffCSVFiller;



