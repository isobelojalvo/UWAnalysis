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
		value = new float[14];
		t->Branch("EffCSVWeight0",&value[0],"EffCSVWeight0/F");
		t->Branch("EffCSVWeight0Up",&value[1],"EffCSVWeight0Up/F");
		t->Branch("EffCSVWeight0UpHF",&value[2],"EffCSVWeight0UpHF/F");
		t->Branch("EffCSVWeight0UpLF",&value[3],"EffCSVWeight0UpLF/F");
		t->Branch("EffCSVWeight0Down",&value[4],"EffCSVWeight0Down/F");
		t->Branch("EffCSVWeight0DownHF",&value[5],"EffCSVWeight0DownHF/F");
		t->Branch("EffCSVWeight0DownLF",&value[6],"EffCSVWeight0DownLF/F");
		t->Branch("EffCSVWeight1",&value[7],"EffCSVWeight1/F");
		t->Branch("EffCSVWeight1Up",&value[8],"EffCSVWeight1Up/F");
		t->Branch("EffCSVWeight1UpHF",&value[9],"EffCSVWeight1UpHF/F");
		t->Branch("EffCSVWeight1UpLF",&value[10],"EffCSVWeight1UpLF/F");
		t->Branch("EffCSVWeight1Down",&value[11],"EffCSVWeight1Down/F");
		t->Branch("EffCSVWeight1DownHF",&value[12],"EffCSVWeight1DownHF/F");
		t->Branch("EffCSVWeight1DownLF",&value[13],"EffCSVWeight1DownLF/F");
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
			std::vector<double> SFupHF,SFdownHF,SFupLF,SFdownLF;

			if( iEvent.getByToken(src_,handle)){
				for( unsigned int i=0; i<handle->at(0).jets().size(); i++){
					if(handle->at(0).jets().at(i)->pt()<30 && abs(handle->at(0).jets().at(i)->eta())>2.4 ) continue;
					double pt = handle->at(0).jets().at(i)->pt();
					double eta = handle->at(0).jets().at(i)->eta();
					if (pt <20 || abs(eta)>2.4) continue;
				  	if (pt>1000) pt =999.;
					int jetflavor = abs(handle->at(0).jets().at(i)->partonFlavour());
					if (handle->at(0).jets().at(i)->bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.80){
						//std::cout<< "Flavor: "<<jetflavor<<std::endl;
						if (pt<30){
                                                       if (jetflavor==5){
                                                                SF.push_back(reader->eval(BTagEntry::FLAV_B, eta, 30. ));
                                                                SFup.push_back(2*(reader_up->eval(BTagEntry::FLAV_B, eta, 30.)));
                                                                SFupHF.push_back(2*(reader_up->eval(BTagEntry::FLAV_B, eta, 30.)));
                                                                SFdown.push_back(2*(reader_down->eval(BTagEntry::FLAV_B, eta, 30. )));
                                                                SFdownHF.push_back(2*(reader_down->eval(BTagEntry::FLAV_B, eta, 30. )));
                                                        }
                                                        else if (jetflavor==4) {
                                                                SF.push_back(reader->eval(BTagEntry::FLAV_C, eta, 30. ));
                                                                SFup.push_back(2*(reader_up->eval(BTagEntry::FLAV_C, eta, 30. )));
                                                                SFupHF.push_back(2*(reader_up->eval(BTagEntry::FLAV_C, eta, 30. )));
                                                                SFdown.push_back(2*(reader_down->eval(BTagEntry::FLAV_C, eta, 30. )));
                                                                SFdownHF.push_back(2*(reader_down->eval(BTagEntry::FLAV_C, eta, 30. )));
                                                        }
                                                        else { //Light jets go down to 20 and up to 1000 
                                                                SF.push_back(reader_light->eval(BTagEntry::FLAV_UDSG, eta, pt ));
                                                                SFup.push_back(reader_light_up->eval(BTagEntry::FLAV_UDSG, eta, pt ));
                                                                SFupLF.push_back(reader_light_up->eval(BTagEntry::FLAV_UDSG, eta, pt ));
                                                                SFdown.push_back(reader_light_down->eval(BTagEntry::FLAV_UDSG, eta, pt ));
                                                                SFdownLF.push_back(reader_light_down->eval(BTagEntry::FLAV_UDSG, eta, pt ));
                                                        }

						}
						else if (pt>670){
                                                       if (jetflavor==5){
                                                                SF.push_back(reader->eval(BTagEntry::FLAV_B, eta, 669. ));
                                                                SFup.push_back(2*(reader_up->eval(BTagEntry::FLAV_B, eta, 669.)));
                                                                SFupHF.push_back(2*(reader_up->eval(BTagEntry::FLAV_B, eta, 669.)));
                                                                SFdown.push_back(2*(reader_down->eval(BTagEntry::FLAV_B, eta, 669. )));
                                                                SFdownHF.push_back(2*(reader_down->eval(BTagEntry::FLAV_B, eta, 669. )));
                                                        }
                                                        else if (jetflavor==4) {
                                                                SF.push_back(reader->eval(BTagEntry::FLAV_C, eta, 669. ));
                                                                SFup.push_back(2*(reader_up->eval(BTagEntry::FLAV_C, eta, 669. )));
                                                                SFupHF.push_back(2*(reader_up->eval(BTagEntry::FLAV_C, eta, 669. )));
                                                                SFdown.push_back(2*(reader_down->eval(BTagEntry::FLAV_C, eta, 669. )));
                                                                SFdownHF.push_back(2*(reader_down->eval(BTagEntry::FLAV_C, eta, 669. )));
                                                        }
                                                        else { //Light jets go down to 20 and up to 1000 
                                                                SF.push_back(reader_light->eval(BTagEntry::FLAV_UDSG, eta, pt ));
                                                                SFup.push_back(reader_light_up->eval(BTagEntry::FLAV_UDSG, eta, pt ));
                                                                SFupLF.push_back(reader_light_up->eval(BTagEntry::FLAV_UDSG, eta, pt ));
                                                                SFdown.push_back(reader_light_down->eval(BTagEntry::FLAV_UDSG, eta, pt ));
                                                                SFdownLF.push_back(reader_light_down->eval(BTagEntry::FLAV_UDSG, eta, pt ));
                                                        }

						}
						else{
							if (jetflavor==5){
								SF.push_back(reader->eval(BTagEntry::FLAV_B, eta, pt ));
								SFup.push_back(reader_up->eval(BTagEntry::FLAV_B, eta, pt ));
								SFupHF.push_back(reader_up->eval(BTagEntry::FLAV_B, eta, pt ));
								SFdown.push_back(reader_down->eval(BTagEntry::FLAV_B, eta, pt ));
								SFdownHF.push_back(reader_down->eval(BTagEntry::FLAV_B, eta, pt ));
							}
							else if (jetflavor==4) {
								SF.push_back(reader->eval(BTagEntry::FLAV_C, eta, pt ));
								SFup.push_back(reader_up->eval(BTagEntry::FLAV_C, eta, pt ));
								SFupHF.push_back(reader_up->eval(BTagEntry::FLAV_C, eta, pt ));
								SFdown.push_back(reader_down->eval(BTagEntry::FLAV_C, eta, pt ));
								SFdownHF.push_back(reader_down->eval(BTagEntry::FLAV_C, eta, pt ));
							}
							else {
								SF.push_back(reader_light->eval(BTagEntry::FLAV_UDSG, eta, pt ));
								SFup.push_back(reader_light_up->eval(BTagEntry::FLAV_UDSG, eta, pt ));
								SFupLF.push_back(reader_light_up->eval(BTagEntry::FLAV_UDSG, eta, pt ));
								SFdown.push_back(reader_light_down->eval(BTagEntry::FLAV_UDSG, eta, pt ));
								SFdownLF.push_back(reader_light_down->eval(BTagEntry::FLAV_UDSG, eta, pt ));
							}
						}
					}//end pass btag
				}//end for jets
			}



			value[0]=bTagEventWeight(SF, 0);
			value[1]=bTagEventWeight(SFup, 0);
			value[2]=bTagEventWeight(SFupHF, 0);
			value[3]=bTagEventWeight(SFupLF, 0);
			value[4]=bTagEventWeight(SFdown, 0);
			value[5]=bTagEventWeight(SFdownHF, 0);
			value[6]=bTagEventWeight(SFdownLF, 0);
			value[7]=bTagEventWeight(SF, 1);
			value[8]=bTagEventWeight(SFup, 1);
			value[9]=bTagEventWeight(SFupHF, 1);
			value[10]=bTagEventWeight(SFupLF, 1);
			value[11]=bTagEventWeight(SFdown, 1);
			value[12]=bTagEventWeight(SFdownHF, 1);
			value[13]=bTagEventWeight(SFdownLF, 1);
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
typedef EffCSVFiller<PATDiTauPair> PATDiTauPairEffCSVFiller;



