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


#include "TRandom3.h"
#include <iostream>

class BtagSFV
{
	public:
		TRandom3* randm;
		BtagSFV( int seed=12345 ){
			randm = new TRandom3(seed);
		}


		BtagSFV(const edm::ParameterSet& iConfig)
		{

		}


		~BtagSFV() {
			std:: cout << "Destructing b-scalefactor" <<std::endl;
			delete randm;
		}

		/*
		   bool isbtagged(Float_t pt, Float_t eta, Float_t csv, Int_t jetflavor, Bool_t isdata, UInt_t btagsys, UInt_t mistagsys, Bool_t is2015);
		   Double_t getSFb(Float_t pt, UInt_t btagsys, Bool_t is2015);
		   Double_t getSFc(Float_t pt, UInt_t btagsys, Bool_t is2015);
		   Double_t getSFl(Float_t pt, Float_t eta, UInt_t mistagsys, Bool_t is2015);
		   Double_t getMistag(Float_t pt, Float_t eta);
		   */

		enum { kNo, kDown, kUp };                     // systematic variations 



		Bool_t isbtagged(Float_t pt, Float_t eta, Float_t csv, Int_t jetflavor, Bool_t isdata, UInt_t btagsys, UInt_t mistagsys, Bool_t is2015)
		{
			cout<< "Random Generator" <<endl;

			//TRandom3 * randm;
			//randm = new TRandom3(12345);
			//randm->SetSeed((int)((eta+5)*100000));

			Bool_t btagged = kFALSE;
			cout<< "btagged set to false" <<endl;
			if(isdata) {
				if(csv>0.8) btagged = kTRUE;
				else          btagged = kFALSE;
				return btagged;
			}

			cout<< "Efficiencies and SF set at start" <<endl;
			Double_t SFb = 0.0;
			Double_t eff_b = 0.719; //FIXME NEW

			cout<< "getSFb" <<endl;
			SFb = getSFb(pt, btagsys, is2015);

			Double_t promoteProb_btag=0; // ~probability to promote to tagged
			Double_t demoteProb_btag=0; // ~probability to demote from tagged

			cout<< "Promote demote here " <<endl;
			if(SFb < 1) {
				demoteProb_btag = fabs(1.0 - SFb);
			} else {
				promoteProb_btag = fabs(SFb - 1.0)/((SFb/eff_b) - 1.0);
			}
			cout<< "Real B Jet" <<endl;
			if(fabs(jetflavor) == 5) {                // real b-jet
				if(csv > 0.80) {                       // if tagged
					btagged = kTRUE;

					if(demoteProb_btag > 0 && randm->Uniform() > demoteProb_btag) btagged = kTRUE;  // leave it tagged
					else                                                          btagged = kFALSE; // demote it to untagged
				} else {
					btagged = kFALSE;
					if(promoteProb_btag > 0 && randm->Uniform() < promoteProb_btag) btagged = kTRUE;  // promote it to tagged
					else                                                            btagged = kFALSE; // leave it untagged
				}
				return btagged;
			}

			// not a real b-jet, apply mistag

			//cout<< "Gets Here 5" <<endl;
			// c or light
			cout<< "Fake B Jet: mistag" <<endl;
			Double_t SFl = 0, eff_l = 0;
			if(fabs(jetflavor) == 4) {
				// SFc = SFb with twice the quoted uncertainty
				SFl = getSFc(pt, btagsys, is2015);
				eff_l = 0.192*SFl; // eff_c in MC for CSVM = (-1.5734604211*x*x*x*x +  1.52798999269*x*x*x +  0.866697059943*x*x +  -1.66657942274*x +  0.780639301724), x = 0.80
			} else {
				SFl = getSFl(pt, eta, mistagsys, is2015);
				eff_l = getMistag(pt, eta);
			}
			//cout<< "Gets Here 6" <<endl;
			Double_t promoteProb_mistag=0; // ~probability to promote to tagged
			Double_t demoteProb_mistag=0; // ~probability to demote from tagged

			if(SFl > 1) {
				promoteProb_mistag = fabs(SFl - 1.0)/((SFl/eff_l) - 1.0);
			}
			else {
				demoteProb_mistag = SFl;
			}

			if(csv > 0.80) {         // if tagged
				btagged = kTRUE;
				if(demoteProb_mistag > 0 && randm->Uniform() > demoteProb_mistag) btagged = kFALSE; // demote it to untagged
				else                                                              btagged = kTRUE;  // leave it tagged
			}
			else {                    // not tagged
				btagged = kFALSE;
				if(promoteProb_mistag > 0 && randm->Uniform() < promoteProb_mistag) btagged = kTRUE;  // promote it to tagged
				else                                                                btagged = kFALSE; // leave it untagged
			}
			//cout<< "Gets Here 8" <<endl;
			return btagged;
		}

	private:

		Double_t getSFb(Float_t pt, UInt_t btagsys, Bool_t is2015)
		{

			// pT dependent scale factors
			// Tagger: CSVM within 30 < pt < 670 GeV, abs(eta) < 2.4, x = pt
			// SFb = (0.938887+(0.00017124*x))+(-2.76366e-07*(x*x)); (2015)
			// for pt > 670 (800) GeV: use the SFb value at 670 (800) GeV with twice the quoted uncertainty for 2011 (2015)
			// for pt < 30 (20) GeV: use the SFb value at 30 (20) GeV with a +/-0.12 absolute uncertainty (twice the quoted uncertainty) for 2011 (2015)
			// i.e SFb(pt<30) = SFb(pt=30) +/- 0.12, so the relative uncertainty is 0.12/SFb(pt=30) for 2011

			Float_t x = pt;
			if(is2015 && pt >= 800.0) x = 799.9; //Cap Jet pt
			if(is2015 && pt < 20.0) {x = 20.0;} //Min Jet Pt THIS LOOKS WRONG

			Double_t SFb = 1.0; 
			if (is2015)	SFb = (0.938887+(0.00017124*x))+(-2.76366e-07*(x*x)); //From a fit!?!?
			if(btagsys == kNo)        return SFb;
				
			cout<<" Up or Down sys"<<endl;
			Double_t SFb_error_2015[] = {0.0415707, 0.0204209, 0.0223227, 0.0206655, 0.0199325, 0.0174121, 0.0202332, 0.0182446, 0.0159777, 0.0218531, 0.0204688, 0.0265191, 0.0313175, 0.0415417, 0.0740446, 0.0596716};
			Float_t ptmin_2015[] = {20, 30, 40, 50, 60, 70, 80, 100, 120, 160, 210, 260, 320, 400, 500, 600};
			Float_t ptmax_2015[] = {30, 40, 50, 60, 70, 80,100, 120, 160, 210, 260, 320, 400, 500, 600, 800};

			Double_t SFb_error_x = 0.0;

			UInt_t nbins = 16;
			//UInt_t nbins = is2015 ? 16: 14;

			for (UInt_t ibin=0; ibin<nbins; ibin++) {
				if(x >= ptmin_2015[ibin] && x < ptmax_2015[ibin]) SFb_error_x = SFb_error_2015[ibin];
			}
			if(pt >= 800.0) SFb_error_x = 2.0*0.0717567;
			if(pt <   20.0) SFb_error_x = 2.0*0.0554504;

			Double_t scalefactor = SFb;

			if(btagsys == kDown) scalefactor = (SFb - SFb_error_x);
			if(btagsys == kUp)   scalefactor = (SFb + SFb_error_x);

			return scalefactor;

		}

		Double_t getSFc(Float_t pt, UInt_t btagsys, Bool_t is2015)
		{

			// SFc = SFb with twice the quoted uncertainty

			Float_t x = pt;
			if(is2015 && pt >= 800.0) x = 799.9;
			if(is2015 && pt < 20.0) x = 20.0;

			Double_t SFc = 1.0;
			if (is2015)SFc = (0.938887+(0.00017124*x))+(-2.76366e-07*(x*x));
			if(btagsys == kNo)        return SFc;

			Double_t SFb_error_2015[] = {0.0415707, 0.0204209, 0.0223227, 0.0206655, 0.0199325, 0.0174121, 0.0202332, 0.0182446, 0.0159777, 0.0218531, 0.0204688, 0.0265191, 0.0313175, 0.0415417, 0.0740446, 0.0596716};
			Float_t ptmin_2015[] = {20, 30, 40, 50, 60, 70, 80, 100, 120, 160, 210, 260, 320, 400, 500, 600};
			Float_t ptmax_2015[] = {30, 40, 50, 60, 70, 80,100, 120, 160, 210, 260, 320, 400, 500, 600, 800};

			Double_t SFc_error_x = 0.0;

			UInt_t nbins = is2015 ? 16: 14;

			for (UInt_t ibin=0; ibin<nbins; ibin++) {
				if(x >= ptmin_2015[ibin] && x < ptmax_2015[ibin]) SFc_error_x = 2.0*SFb_error_2015[ibin];
			}

			if(pt >= 800.0) SFc_error_x = 2.0*2.0*0.0717567;
			if(pt <   20.0) SFc_error_x = 2.0*2.0*0.0554504;

			Double_t scalefactor = SFc;

			if(btagsys == kDown) scalefactor = (SFc - SFc_error_x);
			if(btagsys == kUp)   scalefactor = (SFc + SFc_error_x);

			return scalefactor;

		}

		Double_t getSFl(Float_t pt, Float_t eta, UInt_t mistagsys, Bool_t is2015)
		{

			Float_t x = min(double(pt), is2015 ? 670.0 : 800.0);

			Double_t SFl = 0;

			if(fabs(eta) >= 0.0 && fabs(eta) < 0.8) {
				if(mistagsys == kNo)        SFl = ((1.07541+(0.00231827*x))+(-4.74249e-06*(x*x)))+(2.70862e-09*(x*(x*x)));
				else if(mistagsys == kDown) SFl = ((0.964527+(0.00149055*x))+(-2.78338e-06*(x*x)))+(1.51771e-09*(x*(x*x)));
				else if(mistagsys == kUp)   SFl = ((1.18638+(0.00314148*x))+(-6.68993e-06*(x*x)))+(3.89288e-09*(x*(x*x)));
			} else if(fabs(eta) >= 0.8 && fabs(eta) < 1.6) {
				if(mistagsys == kNo)        SFl = ((1.05613+(0.00114031*x))+(-2.56066e-06*(x*x)))+(1.67792e-09*(x*(x*x)));
				else if(mistagsys == kDown) SFl = ((0.946051+(0.000759584*x))+(-1.52491e-06*(x*x)))+(9.65822e-10*(x*(x*x)));
				else if(mistagsys == kUp)   SFl = ((1.16624+(0.00151884*x))+(-3.59041e-06*(x*x)))+(2.38681e-09*(x*(x*x)));
			} else if(fabs(eta) >= 1.6 && fabs(eta) < 2.4) {
				if(mistagsys == kNo)        SFl = ((1.05625+(0.000487231*x))+(-2.22792e-06*(x*x)))+(1.70262e-09*(x*(x*x)));
				else if(mistagsys == kDown) SFl = ((0.956736+(0.000280197*x))+(-1.42739e-06*(x*x)))+(1.0085e-09*(x*(x*x)));
				else if(mistagsys == kUp)   SFl = ((1.15575+(0.000693344*x))+(-3.02661e-06*(x*x)))+(2.39752e-09*(x*(x*x)));
			}

			return SFl;

		}

		Double_t getMistag(Float_t pt, Float_t eta)
		{

			Float_t x = min(double(pt), 670.0);

			Double_t eff_l = 0.0;

			if(fabs(eta) >= 0.0 && fabs(eta) < 0.8) {
				eff_l = ((0.00967751+(2.54564e-05*x))+(-6.92256e-10*(x*x)));
			} else if(fabs(eta) >= 0.8 && fabs(eta) < 1.6) {
				eff_l = ((0.00974141+(5.09503e-05*x))+(2.0641e-08*(x*x)));
			} else if(fabs(eta) >= 1.6 && fabs(eta) < 2.4) {
				eff_l = ((0.013595+(0.000104538*x))+(-1.36087e-08*(x*x)));
			}

			return eff_l;

		}

};
