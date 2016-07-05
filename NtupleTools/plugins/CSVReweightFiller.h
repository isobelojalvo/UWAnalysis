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
class CSVReweightFiller : public NtupleFillerBase {
	public:
		CSVReweightFiller(){
		}


		CSVReweightFiller(const edm::ParameterSet& iConfig, TTree* t, edm::ConsumesCollector && iC ):
			src_(iC.consumes<std::vector<T> >(iConfig.getParameter<edm::InputTag>("src"))) 
	{
		value = new float[19];
		t->Branch("CSVShapeWeight",&value[0],"CSVShapeWeight/F");
		t->Branch("CSVShapeWeightUpJes",&value[1],"CSVShapeWeightUpJes/F");
		t->Branch("CSVShapeWeightUpHF",&value[2],"CSVShapeWeightUpHF/F");
		t->Branch("CSVShapeWeightUpLF",&value[3],"CSVShapeWeightUpLF/F");
		t->Branch("CSVShapeWeightUpHFStats1",&value[4],"CSVShapeWeightUpHFStats1/F");
		t->Branch("CSVShapeWeightUpHFStats2",&value[5],"CSVShapeWeightUpHFStats2/F");
		t->Branch("CSVShapeWeightUpLFStats1",&value[6],"CSVShapeWeightUpLFStats1/F");
		t->Branch("CSVShapeWeightUpLFStats2",&value[7],"CSVShapeWeightUpLFStats2/F");
		t->Branch("CSVShapeWeightUpCFErr1",&value[8],"CSVShapeWeightUpCFErr1/F");
		t->Branch("CSVShapeWeightUpCFErr2",&value[9],"CSVShapeWeightUpCFErr2/F");
		t->Branch("CSVShapeWeightDownJES",&value[10],"CSVShapeWeightDownJES/F");
		t->Branch("CSVShapeWeightDownHF",&value[11],"CSVShapeWeightDownHF/F");
		t->Branch("CSVShapeWeightDownLF",&value[12],"CSVShapeWeightDownLF/F");
		t->Branch("CSVShapeWeightDownHFStats1",&value[13],"CSVShapeWeightDownHFStats1/F");
		t->Branch("CSVShapeWeightDownHFStats2",&value[14],"CSVShapeWeightDownHFStats2/F");
		t->Branch("CSVShapeWeightDownLFStats1",&value[15],"CSVShapeWeightDownLFStats1/F");
		t->Branch("CSVShapeWeightDownLFStats2",&value[16],"CSVShapeWeightDownLFStats2/F");
		t->Branch("CSVShapeWeightDownCFErr1",&value[17],"CSVShapeWeightDownCFErr1/F");
		t->Branch("CSVShapeWeightDownCFErr2",&value[18],"CSVShapeWeightDownCFErr2/F");
		calib=new BTagCalibration("CSVv2", std::string(std::getenv("CMSSW_BASE"))+"/src/UWAnalysis/Configuration/data/CSVv2_76.csv");
		reader=new BTagCalibrationReader(calib, BTagEntry::OP_RESHAPING, "iterativefit", "central");
		//JES applicable for bottom and light
		reader_up_jes=new BTagCalibrationReader(calib, BTagEntry::OP_RESHAPING, "iterativefit", "up_jes");  // sys up
		reader_down_jes=new BTagCalibrationReader(calib, BTagEntry::OP_RESHAPING, "iterativefit", "down_jes");  // sys up
		//LF light flavor contamination for b jets
		reader_up_lf=new BTagCalibrationReader(calib, BTagEntry::OP_RESHAPING, "iterativefit", "up_lf");  // sys up
		reader_down_lf=new BTagCalibrationReader(calib, BTagEntry::OP_RESHAPING, "iterativefit", "down_lf");  // sys up
		//HFstats1 Linear and quadratic statistical fluctuations
		reader_up_hfstats1=new BTagCalibrationReader(calib, BTagEntry::OP_RESHAPING, "iterativefit", "up_hfstats1");  // sys up
		reader_down_hfstats1=new BTagCalibrationReader(calib, BTagEntry::OP_RESHAPING, "iterativefit", "down_hfstats1");  // sys up
		//HFstats2 Linear and quadratic statistical fluctuations
		reader_up_hfstats2=new BTagCalibrationReader(calib, BTagEntry::OP_RESHAPING, "iterativefit", "up_hfstats2");  // sys up
		reader_down_hfstats2=new BTagCalibrationReader(calib, BTagEntry::OP_RESHAPING, "iterativefit", "down_hfstats2");  // sys up
		//hf contamination- for light jets
		reader_up_hf=new BTagCalibrationReader(calib, BTagEntry::OP_RESHAPING, "iterativefit", "up_hf");  // sys up
		reader_down_hf=new BTagCalibrationReader(calib, BTagEntry::OP_RESHAPING, "iterativefit", "down_hf");  // sys up
		//LFstats1 Linear and quadratic statistical fluctuations
		//LFstats2 Linear and quadratic statistical fluctuations
		reader_up_lfstats1=new BTagCalibrationReader(calib, BTagEntry::OP_RESHAPING, "iterativefit", "up_hfstats1");  // sys up
		reader_down_lfstats1=new BTagCalibrationReader(calib, BTagEntry::OP_RESHAPING, "iterativefit", "down_hfstats1");  // sys up
		reader_up_lfstats2=new BTagCalibrationReader(calib, BTagEntry::OP_RESHAPING, "iterativefit", "up_hfstats2");  // sys up
		reader_down_lfstats2=new BTagCalibrationReader(calib, BTagEntry::OP_RESHAPING, "iterativefit", "down_hfstats2");  // sys up
		//charm jet uncertantites
		reader_up_cferr1=new BTagCalibrationReader(calib, BTagEntry::OP_RESHAPING, "iterativefit", "up_cferr1");  // sys up
		reader_down_cferr1=new BTagCalibrationReader(calib, BTagEntry::OP_RESHAPING, "iterativefit", "down_cferr1");  // sys up
		reader_up_cferr2=new BTagCalibrationReader(calib, BTagEntry::OP_RESHAPING, "iterativefit", "up_cferr2");  // sys up
		reader_down_cferr2=new BTagCalibrationReader(calib, BTagEntry::OP_RESHAPING, "iterativefit", "down_cferr2");  // sys up
	}


		~CSVReweightFiller()
		{ 
		}

		void fill(const edm::Event& iEvent, const edm::EventSetup& iSetup)
		{



			edm::Handle<std::vector<T>> handle;


			std::vector<double> SF;
			std::vector<double> SFupJes,SFupHF,SFupLF,SFupHFstats1,SFupHFstats2,SFupLFstats1,SFupLFstats2,SFupCFErr1,SFupCFErr2;
			std::vector<double> SFdownJes,SFdownHF,SFdownLF,SFdownHFstats1,SFdownHFstats2,SFdownLFstats1,SFdownLFstats2,SFdownCFErr1,SFdownCFErr2;

			if( iEvent.getByToken(src_,handle)){
				for( unsigned int i=0; i<handle->at(0).jets().size(); i++){
					double pt = handle->at(0).jets().at(i)->pt();
					double eta = handle->at(0).jets().at(i)->eta();
					if (pt <20 || abs(eta)>2.4) continue;
					if( pt > 1000 ) pt = 999.;
					double csv = handle->at(0).jets().at(i)->bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags");
					int flavor = abs(handle->at(0).jets().at(i)->partonFlavour());
					BTagEntry::JetFlavor jf = BTagEntry::FLAV_UDSG;

					if (csv>0.80){
						if( flavor ==5 ) { 
							jf = BTagEntry::FLAV_B;
							SFupJes.push_back(reader_up_jes->eval(jf, eta, pt,csv ));
							SFdownJes.push_back(reader_down_jes->eval(jf, eta, pt,csv ));
							SFupLF.push_back(reader_up_lf->eval(jf, eta, pt,csv ));
							SFdownLF.push_back(reader_down_lf->eval(jf, eta, pt,csv ));
							SFupHFstats1.push_back(reader_up_hfstats2->eval(jf, eta, pt,csv ));
							SFdownHFstats1.push_back(reader_down_hfstats2->eval(jf, eta, pt,csv ));
							SFupHFstats2.push_back(reader_up_hfstats2->eval(jf, eta, pt,csv ));
							SFdownHFstats2.push_back(reader_down_hfstats2->eval(jf, eta, pt,csv ));

						}
						else if(flavor ==4 ){
							jf = BTagEntry::FLAV_C;
							SFupCFErr1.push_back(reader_up_cferr1->eval(jf, eta, pt,csv ));
							SFdownCFErr1.push_back(reader_down_cferr1->eval(jf, eta, pt,csv ));
							SFupCFErr2.push_back(reader_up_cferr2->eval(jf, eta, pt,csv ));
							SFdownCFErr2.push_back(reader_down_cferr2->eval(jf, eta, pt,csv ));
						}
						else {
							jf = BTagEntry::FLAV_UDSG;
							SFupJes.push_back(reader_up_jes->eval(jf, eta, pt,csv ));
							SFdownJes.push_back(reader_down_jes->eval(jf, eta, pt,csv ));
							SFupHF.push_back(reader_up_hf->eval(jf, eta, pt,csv ));
							SFdownHF.push_back(reader_down_hf->eval(jf, eta, pt,csv ));
							SFupLFstats1.push_back(reader_up_lfstats1->eval(jf, eta, pt,csv ));
							SFdownLFstats1.push_back(reader_down_lfstats1->eval(jf, eta, pt,csv ));
							SFupLFstats2.push_back(reader_up_lfstats2->eval(jf, eta, pt,csv ));
							SFdownLFstats2.push_back(reader_down_lfstats2->eval(jf, eta, pt,csv ));
						}
						SF.push_back(reader->eval(jf, eta, pt,csv ));
					}//end if CSV
				}//end for jets
			}//handle



			value[0]=bTagEventWeight(SF);
			value[1]=bTagEventWeight(SFupJes);
			value[2]=bTagEventWeight(SFupHF);
			value[3]=bTagEventWeight(SFupLF);
			value[4]=bTagEventWeight(SFupHFstats1);
			value[5]=bTagEventWeight(SFupHFstats2);
			value[6]=bTagEventWeight(SFupLFstats1);
			value[7]=bTagEventWeight(SFupLFstats2);
			value[8]=bTagEventWeight(SFupCFErr1);
			value[9]=bTagEventWeight(SFupCFErr2);

			value[10]=bTagEventWeight(SFdownJes);
			value[11]=bTagEventWeight(SFdownHF);
			value[12]=bTagEventWeight(SFdownLF);
			value[13]=bTagEventWeight(SFdownHFstats1);
			value[14]=bTagEventWeight(SFdownHFstats2);
			value[15]=bTagEventWeight(SFdownLFstats1);
			value[16]=bTagEventWeight(SFdownLFstats2);
			value[17]=bTagEventWeight(SFdownCFErr1);
			value[18]=bTagEventWeight(SFdownCFErr2);



		}

		double bTagEventWeight(std::vector<double>& SFsForBTaggedJets){
			//##################################################################
			//Event weight matrix:
			// Product SF_i
			//##################################################################

			double weight = 1;

			for (unsigned int i=0;i<SFsForBTaggedJets.size() ; ++i){
				double SF_i = SFsForBTaggedJets.at(i);
				weight *=SF_i;
			}
			return weight;
		}


	protected:
		edm::EDGetTokenT<std::vector<T> > src_;
		std::string tag_;
		float* value;

		BTagCalibration *calib;
		BTagCalibrationReader *reader;
		BTagCalibrationReader *reader_up_jes;
		BTagCalibrationReader *reader_down_jes;
		BTagCalibrationReader *reader_up_hf;
		BTagCalibrationReader *reader_down_hf;
		BTagCalibrationReader *reader_up_lf;
		BTagCalibrationReader *reader_down_lf;
		BTagCalibrationReader *reader_up_hfstats1;
		BTagCalibrationReader *reader_down_hfstats1;
		BTagCalibrationReader *reader_up_hfstats2;
		BTagCalibrationReader *reader_down_hfstats2;
		BTagCalibrationReader *reader_up_lfstats1;
		BTagCalibrationReader *reader_down_lfstats1;
		BTagCalibrationReader *reader_up_lfstats2;
		BTagCalibrationReader *reader_down_lfstats2;
		BTagCalibrationReader *reader_up_cferr1;
		BTagCalibrationReader *reader_down_cferr1;
		BTagCalibrationReader *reader_up_cferr2;
		BTagCalibrationReader *reader_down_cferr2;



};


#include "UWAnalysis/DataFormats/interface/CompositePtrCandidateT1T2MEt.h"
#include "UWAnalysis/DataFormats/interface/CompositePtrCandidateTMEt.h"

typedef CSVReweightFiller<PATMuTauPair> PATMuTauPairCSVReweightFiller;
typedef CSVReweightFiller<PATElecTauPair> PATEleTauPairCSVReweightFiller;
typedef CSVReweightFiller<PATDiTauPair> PATDiTauPairCSVReweightFiller;


