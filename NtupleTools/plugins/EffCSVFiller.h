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
		value = new float[6];
		t->Branch("EffCSVWeight1",&value[0],"EffCSVWeight1/F");
		t->Branch("EffCSVWeight1Up",&value[1],"EffCSVWeight1Up/F");
		t->Branch("EffCSVWeight1Down",&value[2],"EffCSVWeight1Down/F");
		t->Branch("EffCSVWeight0",&value[3],"EffCSVWeight0/F");
		t->Branch("EffCSVWeight0Up",&value[4],"EffCSVWeight0Up/F");
		t->Branch("EffCSVWeight0Down",&value[5],"EffCSVWeight0Down/F");
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



			edm::Handle<std::vector<T>> handle;


			std::vector<double> SF,SFup,SFdown;

			if( iEvent.getByToken(src_,handle)){
				for( unsigned int i=0; i<handle->at(0).jets().size(); i++){
					if(handle->at(0).jets().at(i)->pt()<30 && abs(handle->at(0).jets().at(i)->eta())>2.4 ) continue;
					double pt = handle->at(0).jets().at(i)->pt();
					double eta = handle->at(0).jets().at(i)->eta();
					int jetflavor = abs(handle->at(0).jets().at(i)->partonFlavour());
					if (handle->at(0).jets().at(i)->bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.80){
						//std::cout<< "Flavor: "<<jetflavor<<std::endl;
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



			value[0]=bTagEventWeight(SF, 0);
			value[1]=bTagEventWeight(SFup, 0);
			value[2]=bTagEventWeight(SFdown, 0);
			value[3]=bTagEventWeight(SF, 1);
			value[4]=bTagEventWeight(SFup, 1);
			value[5]=bTagEventWeight(SFdown, 1);
		}


		double bTagEventWeight(std::vector<double>& SFsForBTaggedJets, unsigned int nBTags){
			if( nBTags > 1 )
			{
				edm::LogError("bTagEventWeight") << "Only 0 btag and 1+ btagincluded. btag!>1 ";
				exit(1);
			}
			//##################################################################
			//Event weight matrix:
			//------------------------------------------------------------------
			//nBTags\b-tagged jets  |    0        1+    
			//------------------------------------------------------------------
			//0                     |    1        Product_ibtagged (1-SF_i)     
			//
			//1+                    |    0        1- (Product_ibtagged (1-SF_i) )   
			//
			//##################################################################

			if( nBTags > SFsForBTaggedJets.size() ) return 0.0;

			if( nBTags==0 && SFsForBTaggedJets.size()==0 ) return 1.0;

			double weight = 1;

			for (unsigned int i=0;i<SFsForBTaggedJets.size() ; ++i){
				double SF_i = SFsForBTaggedJets.at(i);
				weight *= (1-SF_i);
			}
			double atleastone = 1-weight;
			if (nBTags==1) {return atleastone;}
			else {return weight;}
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



