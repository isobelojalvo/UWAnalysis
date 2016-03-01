// system include files
#include <memory>

// user include files

#include <TTree.h>
#include <TH2D.h>
#include <TFile.h>

#include "TRandom3.h"

#include "UWAnalysis/NtupleTools/interface/NtupleFillerBase.h"
#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h"

#include "CondFormats/BTauObjects/interface/BTagCalibration.h"
#include "CondFormats/BTauObjects/interface/BTagCalibrationReader.h"

#include "UWAnalysis/RecoTools/plugins/BTagCalibrationStandalone.h"

#include "CommonTools/Utils/interface/StringObjectFunction.h"
#include "boost/filesystem.hpp"

//
// class decleration
//

template<typename T>
class NBTagFiller : public NtupleFillerBase {
	public:
		NBTagFiller(){
		}


		NBTagFiller(const edm::ParameterSet& iConfig, TTree* t, edm::ConsumesCollector && iC ):
			src_(iC.consumes<std::vector<T> >(iConfig.getParameter<edm::InputTag>("src"))), 
			doEff_(iConfig.getParameter<bool>("doEffMap"))
	{
		value = new float[3];
		t->Branch("NBtagPD",&value[0],"NBtagPD/F");
		t->Branch("NBtagPDUp",&value[1],"NBtagPDUp/F");
		t->Branch("NBtagPDDown",&value[2],"NBtagPDDown/F");
		calib=new BTagCalibration("CSVv2", std::string(std::getenv("CMSSW_BASE"))+"/src/UWAnalysis/Configuration/data/CSVv2_76.csv");
		reader_light=new BTagCalibrationReader(calib, BTagEntry::OP_MEDIUM, "incl", "central");
		reader_light_up=new BTagCalibrationReader(calib, BTagEntry::OP_MEDIUM, "incl", "up");
		reader_light_down=new BTagCalibrationReader(calib, BTagEntry::OP_MEDIUM, "incl", "down");
		reader=new BTagCalibrationReader(calib, BTagEntry::OP_MEDIUM, "mujets", "central");
		reader_up=new BTagCalibrationReader(calib, BTagEntry::OP_MEDIUM, "mujets", "up");  // sys up
		reader_down=new BTagCalibrationReader(calib, BTagEntry::OP_MEDIUM, "mujets", "down");  // sys down

		std::string base = std::getenv("CMSSW_BASE");
		std::string fEff =   "/src/UWAnalysis/Configuration/data/efficiency.root";
		std::string path= base+fEff;
		isEffFile_   = boost::filesystem::exists( path  );
		if (isEffFile_ && doEff_){
			std::cout<<"INFO::NBTagFiller using efficiency map"<<std::endl;
			f_EffMap = new TFile(path.c_str(),"READONLY");
			h2_TTEffMapB    = (TH2D*)f_EffMap->Get("TT_effi/efficiency_b");
			h2_TTEffMapC    = (TH2D*)f_EffMap->Get("TT_effi/efficiency_c");
			h2_TTEffMapUDSG = (TH2D*)f_EffMap->Get("TT_effi/efficiency_udsg");
			h2_ZJetsEffMapB    = (TH2D*)f_EffMap->Get("ZJets_effi/efficiency_b");
			h2_ZJetsEffMapC    = (TH2D*)f_EffMap->Get("ZJets_effi/efficiency_c");
			h2_ZJetsEffMapUDSG = (TH2D*)f_EffMap->Get("ZJets_effi/efficiency_udsg");
		}
		else { std::cout<<"WARNING::NBTagFiller No efficiency file found!!!"<<std::endl;}

	}


		~NBTagFiller()
		{ 
		}

		void fill(const edm::Event& iEvent, const edm::EventSetup& iSetup)
		{
			int nbtags=0;
			int nbtagsup=0;
			int nbtagsdown=0;
			bool top =false;

			edm::Handle<std::vector<T>> handle;
			if( iEvent.getByToken(src_,handle)){

				if (handle->at(0).isTop()){top =true;}
				for ( int i=0;i<handle->at(0).jets().size();i++){
					bool btagged = false;
					bool btaggedup = false;
					bool btaggeddown = false;
					bool pass = false;
					double pt = handle->at(0).jets().at(i)->pt();
					if (pt>670.) {pt=670.;}
					else if (pt<30) {continue;}
					double eta = handle->at(0).jets().at(i)->eta();
					int jetflavor = handle->at(0).jets().at(i)->partonFlavour();
					double SF =0,SFup=0,SFdown=0,eff=0;
					if (handle->at(0).jets().at(i)->bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.80) pass =true;
					if (fabs(jetflavor) == 5) {                // real b-jet
						SF = reader->eval(BTagEntry::FLAV_B, eta, pt );
						SFup = reader_up->eval(BTagEntry::FLAV_B, eta, pt );
						SFdown = reader_down->eval(BTagEntry::FLAV_B, eta, pt );
						eff = 0.6829; 
						if (doEff_ && top )eff = h2_TTEffMapB->GetBinContent( h2_TTEffMapB->GetXaxis()->FindBin(pt), h2_TTEffMapB->GetYaxis()->FindBin(fabs(eta)) );
						else if (doEff_ )eff = h2_ZJetsEffMapB->GetBinContent( h2_ZJetsEffMapB->GetXaxis()->FindBin(pt), h2_ZJetsEffMapB->GetYaxis()->FindBin(fabs(eta)) );
					}
					else if (fabs(jetflavor) == 4) { 
						//cout<< "Flavor 4" <<endl;
						SF = reader->eval(BTagEntry::FLAV_C, eta, pt );
						SFup= reader_up->eval(BTagEntry::FLAV_C, eta, pt );
						SFdown = reader_up->eval(BTagEntry::FLAV_C, eta, pt );
						eff =0.18;
						if (doEff_&&top) eff = h2_TTEffMapC->GetBinContent( h2_TTEffMapC->GetXaxis()->FindBin(pt), h2_TTEffMapC->GetYaxis()->FindBin(fabs(eta)) );
						else if (doEff_) eff = h2_ZJetsEffMapC->GetBinContent( h2_ZJetsEffMapC->GetXaxis()->FindBin(pt), h2_ZJetsEffMapC->GetYaxis()->FindBin(fabs(eta)) );
					}  
					else {
						//cout<< "Flavor UDSG" <<endl;
						SF = reader_light->eval(BTagEntry::FLAV_UDSG, eta, pt );
						SFup = reader_light_up->eval(BTagEntry::FLAV_UDSG, eta, pt );
						SFdown = reader_light_down->eval(BTagEntry::FLAV_UDSG, eta, pt );
						//cout<< "Flavor UDSG: SF" <<endl;
						eff =0.012;
						if (doEff_&&top ) eff = h2_TTEffMapUDSG->GetBinContent( h2_TTEffMapUDSG->GetXaxis()->FindBin(pt), h2_TTEffMapUDSG->GetYaxis()->FindBin(fabs(eta)) );
						else if (doEff_) eff = h2_ZJetsEffMapUDSG->GetBinContent( h2_ZJetsEffMapUDSG->GetXaxis()->FindBin(pt), h2_ZJetsEffMapUDSG->GetYaxis()->FindBin(fabs(eta)) );
						//cout<< "Flavor UDSG: EFF" <<endl;
					}
					//cout<< "after SF: " <<SF<<endl;
					//cout<< "after eff: " <<eff<<endl;

					//std::cout<<"pt: "<<pt<<std::endl;
					//std::cout<<"flavor: "<<fabs(jetflavor)<<std::endl;
					//std::cout<<"SF: "<<SF<<std::endl;
					//std::cout<<"eff: "<<eff<<std::endl;
					btagged = applySF(pass, SF, eff);
					btaggedup = applySF(pass, SFup, eff);
					btaggeddown = applySF(pass, SFdown, eff);

					//cout<< "Gets To Return" <<endl;
					if (handle->at(0).isData()){
						if (pass) nbtags++;
						//nosystematic shifts up and down
					}
					else{
						if (btagged) nbtags++;
						if (btaggedup) nbtagsup++;
						if (btaggeddown) nbtagsdown++;
					}
				}//end for jets
			}


			value[0]=nbtags;
			value[1]=nbtagsup;
			value[2]=nbtagsdown;
		}


	protected:
		edm::EDGetTokenT<std::vector<T> > src_;
		std::string tag_;
		bool doEff_;
		bool isEffFile_;
		float* value;
		TFile *f_EffMap;
		TH2D *h2_TTEffMapB;
		TH2D *h2_TTEffMapC;
		TH2D *h2_TTEffMapUDSG;
		TH2D *h2_ZJetsEffMapB;
		TH2D *h2_ZJetsEffMapC;
		TH2D *h2_ZJetsEffMapUDSG;


		BTagCalibration *calib;
		BTagCalibrationReader *reader;
		BTagCalibrationReader *reader_up;
		BTagCalibrationReader *reader_down;
		BTagCalibrationReader *reader_light;
		BTagCalibrationReader *reader_light_up;
		BTagCalibrationReader *reader_light_down;

		bool applySF(bool& isBTagged, float Btag_SF, float Btag_eff){
			TRandom3 * rand_;
			rand_ = new TRandom3(0);
			//rand_ = new TRandom3(12345);

			bool newBTag = isBTagged;

			if (Btag_SF == 1) return newBTag; //no correction needed 

			//throw die
			float coin = rand_->Uniform();    
			//std::cout<<"Uniform coin: "<<coin<<std::endl;

			if(Btag_SF > 1){  // use this if SF>1

				if( !isBTagged ) {

					//fraction of jets that need to be upgraded
					float mistagPercent = (1.0 - Btag_SF) / (1.0 - (Btag_SF/Btag_eff) );

					//upgrade to tagged
					if( coin < mistagPercent ) {newBTag = true;}
				}

			}else{  // use this if SF<1

				//downgrade tagged to untagged
				if( isBTagged && coin > Btag_SF ) {newBTag = false;}

			}

			return newBTag;
		}


};

#include "UWAnalysis/DataFormats/interface/CompositePtrCandidateT1T2MEt.h"
#include "UWAnalysis/DataFormats/interface/CompositePtrCandidateTMEt.h"

typedef NBTagFiller<PATMuTauPair> PATMuTauPairNBTagFiller;
typedef NBTagFiller<PATElecTauPair> PATEleTauPairNBTagFiller;



