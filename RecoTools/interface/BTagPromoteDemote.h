#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "Math/GenVector/VectorUtil.h"
#include <TFormula.h>
#include "Utilities/General/interface/FileInPath.h"

#include "CondFormats/BTauObjects/interface/BTagCalibration.h"
#include "CondFormats/BTauObjects/interface/BTagCalibrationReader.h"

#include "UWAnalysis/RecoTools/plugins/BTagCalibrationStandalone.h"

#include "TFile.h"

#include "TRandom3.h"
#include "TH2D.h"
#include <iostream>

class BtagSFV
{
	public:
  


		BtagSFV(const edm::ParameterSet& iConfig)
		{

		}


		~BtagSFV() {
			std:: cout << "Destructing b-scalefactor" <<std::endl;
		}

		/*
		   bool isbtagged(Float_t pt, Float_t eta, Float_t csv, Int_t jetflavor, Bool_t isdata, UInt_t btagsys, UInt_t mistagsys, Bool_t is2015);
		   */

		enum { kNo, kDown, kUp };                     // systematic variations 


		Bool_t isbtagged(Float_t pt, Float_t eta, Float_t csv, Int_t jetflavor, Bool_t isdata, UInt_t btagsys, UInt_t mistagsys, Bool_t is2015)
		{

			std:: cout << "BTag Calibration Creators" <<std::endl;
			BTagCalibration btagcalib("CSVv2",string(std::getenv("CMSSW_BASE"))+"/src/UWAnalysis/Configuration/data/CSVv2_76.csv");
			BTagCalibrationReader btag_reader_light(&btagcalib, BTagEntry::OP_MEDIUM, "incl", "central");
			BTagCalibrationReader btag_reader_light_up(&btagcalib, BTagEntry::OP_MEDIUM, "incl", "up");
			BTagCalibrationReader btag_reader_light_down(&btagcalib, BTagEntry::OP_MEDIUM, "incl", "down");
			BTagCalibrationReader btag_reader(&btagcalib, BTagEntry::OP_MEDIUM, "mujets", "central");
			BTagCalibrationReader btag_reader_up(&btagcalib, BTagEntry::OP_MEDIUM, "mujets", "up");  // sys up
			BTagCalibrationReader btag_reader_down(&btagcalib, BTagEntry::OP_MEDIUM, "mujets", "down");  // sys down

			std::cout << "Efficiency Creators" <<std::endl;
			edm::FileInPath fipEffMap("UWAnalysis/Configuration/data/bTaggingEfficiency.root");
			std::string path=fipEffMap.fullPath();
			std::cout << "File In Path:" << path <<std::endl;
			f_EffMap = new TFile(path.c_str(),"READONLY");
			std:: cout << "f_EffMap " <<std::endl;

			h2_EffMapB    = (TH2D*)f_EffMap->Get("effi/h2_BTaggingEff_b");
			h2_EffMapC    = (TH2D*)f_EffMap->Get("effi/h2_BTaggingEff_c");
			h2_EffMapUDSG = (TH2D*)f_EffMap->Get("effi/h2_BTaggingEff_udsg");
			std:: cout << "TH2D Acquired" <<std::endl;

			//btagged set to false
			Bool_t btagged = kFALSE;

			//Don't fix data
			if(isdata) {
				if(csv>0.8)   btagged = kTRUE;
				else          btagged = kFALSE;
				return btagged;
			}

			cout<< "Efficiencies and SF set at start" <<endl;
			Double_t SF = 0.0;
			Double_t eff = 0.0; 
			bool pass = false; 
			if (csv>0.8) pass = true;

			cout<< "JET" <<endl;
			cout<< "pt: " <<pt<<endl;
			cout<< "eta: " <<eta<<endl;
			cout<< "flavor: " <<jetflavor<<endl;
			cout<< "before SF: " <<SF<<endl;
			cout<< "before eff: " <<eff<<endl;
			cout<< "before pass: " <<eff<<endl;

			if (fabs(jetflavor) == 5) {                // real b-jet
				SF = btag_reader.eval(BTagEntry::FLAV_B, eta, pt );
				eff = h2_EffMapB->GetBinContent( h2_EffMapB->GetXaxis()->FindBin(pt), h2_EffMapB->GetYaxis()->FindBin(fabs(eta)) );
			}
			else if (fabs(jetflavor) == 4) { 
				SF = btag_reader.eval(BTagEntry::FLAV_C, eta, pt );
				eff = h2_EffMapC->GetBinContent( h2_EffMapC->GetXaxis()->FindBin(pt), h2_EffMapC->GetYaxis()->FindBin(fabs(eta)) );
			}  
			else {
				SF = btag_reader.eval(BTagEntry::FLAV_UDSG, eta, pt );
				eff = h2_EffMapUDSG->GetBinContent( h2_EffMapUDSG->GetXaxis()->FindBin(pt), h2_EffMapUDSG->GetYaxis()->FindBin(fabs(eta)) );
			}

			cout<< "after SF: " <<SF<<endl;
			cout<< "after eff: " <<eff<<endl;

			btagged = applySF(pass, SF, eff);
			cout<< "after pass: " <<pass<<endl;

			cout<< "Gets To Return" <<endl;
			return btagged;
		}


		bool applySF(bool& isBTagged, float Btag_SF, float Btag_eff){
			TRandom3 * rand_;
			rand_ = new TRandom3(12345);
	
			bool newBTag = isBTagged;

			if (Btag_SF == 1) return newBTag; //no correction needed 

			//throw die
			float coin = rand_->Uniform(1.);    
			std::cout<<"Uniform coin: "<<coin<<std::endl;

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




	private:
		TFile *f_EffMap;
		TH2D *h2_EffMapB;
		TH2D *h2_EffMapC;
		TH2D *h2_EffMapUDSG;
};
