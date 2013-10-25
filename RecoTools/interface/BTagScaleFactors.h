//#ifndef RecoTools_METCalibrator
//#define RecoTools_METCalibrator

// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "Math/GenVector/VectorUtil.h"
#include <TFormula.h>
#include <TRandom3.h>
#include "Utilities/General/interface/FileInPath.h"

//
// class decleration

//Scalefactor types: (For 20, 25 GeV Jets) abs(eta)<2.4
//--> WARNING if asking for high pt b-Jets then nTagged SF will not work
///1.) ask for *Atleast* 1 jet pt>20(25) to be tagged
///2.) ask for *Exactly* 2 high pt jets to be tagged
///3.) (to be developed) ask for 2 jets pt>20(25) to be tagged

///For 1.) a) if more than one jet is tagged we need to average the b-tagging scalefactor
///        b) if one jet is true b-jet and one jet is fake then SF=eff(fake
///        c) if more than one jet is true b-jet(fake) then average b-jets(fake) and repeat b
///For 2.) a) SF=SF1*SF2 (where SF1,SF2 is the fake or true scalefactor)
 

class BTagScaleFactors  
{
  typedef edm::Ptr<pat::Jet> JetPtr;
  typedef std::vector<JetPtr> JetPtrVector;
 public:
  BTagScaleFactors() {}
  
  BTagScaleFactors(const edm::ParameterSet& iConfig)
    {
      
    }

  
  ~BTagScaleFactors() {
    std:: cout << "destructing b-scalefactor" <<std::endl;
  }

  
  std::pair<double,double> getCSVL1( JetPtrVector jets , bool top )
    { return CSVLoose1(jets,top);}
  std::pair<double,double> getCSVL2( JetPtrVector jets , bool top )
    { return CSVLoose2(jets,top);}
  std::pair<double,double> getCSVM1( JetPtrVector jets , bool top )
    { return CSVMedium1(jets,top);}
  std::pair<double,double> getCSVM2( JetPtrVector jets , bool top )
    { return CSVMedium2(jets,top);}
  std::pair<double,double> getCSVT1( JetPtrVector jets , bool top )
    { return CSVTight1(jets,top);}
  std::pair<double,double> getCSVT2( JetPtrVector jets , bool top )
    { return CSVTight2(jets,top);}

 private:

  std::pair<double,double> CSVLoose1( JetPtrVector jets , bool top ){
    double bdisc = 0;
    double EffWEIGHTCSVL1 = 0;
    double EffWEIGHTCSVL1err = 0;
    ///================================================================== ////Light Jet Atleast 1  
    bdisc = 0.244;
    int ntagged = 0;
    int nfakes = 0;
    double faketotal = 0;
    double faketotalerr = 0;
    int nbjets = 0;
    double bjettotal = 0;
    double bjettotalerr = 0;
    
    for(unsigned int i=0; i < jets.size(); i++){
      double jetpt, jeteta, jetflavor = 0;
      std::pair<double,double> jetpair; 
      jetpair = std::make_pair(1.,0.); //here the pair is the SF and the Error
      //cout << "ith: " << i << "jet pt " << jets.at(i)->pt()<< "bdisc value: " << jets.at(i)->bDiscriminator("combinedSecondaryVertexBJetTags")<< endl; 
      
      if(jets.at(i)->pt()<20)
	continue;
      
      if(jets.at(i)->bDiscriminator("combinedSecondaryVertexBJetTags")<bdisc) ///IF the bdiscriminiator value is less than Light value then move on to next jet in loop
	continue;
      
      jetpt = jets.at(i)->pt();
      jeteta = abs(jets.at(i)->eta());
      jetflavor = abs(jets.at(i)->partonFlavour()); //flavor == american; not this british BS
      ntagged+=1;
      
      if(jetflavor==5||jetflavor==4){
	nbjets +=1;
	if(top)jetpair = CSVLTop(jetpt); ////special algorithm for top
	else jetpair = CSVL(jetpt);
	
	bjettotal += jetpair.first;////GET b SCALEFACTOR
	bjettotalerr += jetpair.second; ///Average the error (check this?)
      }
      else if(jetflavor!=5&&jetflavor!=4){
	nfakes +=1;
	faketotal += CSVLFake(jetpt,jeteta).first; ////GET FAKE SCALEFACTOR
	faketotalerr += (CSVLFake(jetpt,jeteta).second); ///Average the error (check this?)
      }
    }

    if(nbjets>0&&nfakes>0){    ////Calculate SF for Atleast 1 bjet
      EffWEIGHTCSVL1 = (bjettotal/nbjets)*(faketotal/nfakes); 
      EffWEIGHTCSVL1err = sqrt(pow(faketotalerr,2) + pow(bjettotalerr,2));
    }
    else if(nbjets>0&&nfakes==0){
      EffWEIGHTCSVL1 = bjettotal/nbjets;
      EffWEIGHTCSVL1err = bjettotalerr/nbjets;
    }
    else if(nbjets==0&&nfakes>0){
      EffWEIGHTCSVL1 = faketotal/nfakes;
      EffWEIGHTCSVL1err = faketotalerr/nfakes;
    }
    else {EffWEIGHTCSVL1 = 0; EffWEIGHTCSVL1err = 0;}////No b-tagged jets found!

    std::pair<double,double> ScalefactorAndError = std::make_pair(EffWEIGHTCSVL1,EffWEIGHTCSVL1err);
    //cout << "EffWEIGHTCSVL1 " << EffWEIGHTCSVL1 << "EffWEIGHTCSVL1err " << EffWEIGHTCSVL1err <<endl;
    //cout<< "SF Weight " << EffWEIGHTCSVL1<< "SF Err "<< EffWEIGHTCSVL1err <<endl;
    return ScalefactorAndError;
  }


  std::pair<double,double> CSVMedium1( JetPtrVector jets , bool top ){
 
    double bdisc = 0.679;
    double EffWEIGHTCSVM1 = 0;
    double EffWEIGHTCSVM1err = 0;
    ///==================================================================    ////Medium Jet Atleast 1  
    int ntagged = 0;
    int nfakes = 0;
    double faketotal = 0;
    double faketotalerr = 0;
    int nbjets = 0;
    double bjettotal = 0;
    double bjettotalerr = 0;
    
    for(unsigned int i=0; i < jets.size(); i++){
      double jetpt, jeteta, jetflavor = 0;
      //cout << "i " << i << "jet pt" << jets.at(i)->pt() << endl; 
      if(jets.at(i)->pt()<20)
	continue;

      if(jets.at(i)->bDiscriminator("combinedSecondaryVertexBJetTags")<bdisc) ///IF the bdiscriminiator value is less than Light value then move on to next jet in loop
	continue;
      
      jetpt = jets.at(i)->pt();
      jeteta = abs(jets.at(i)->eta());
      jetflavor = abs(jets.at(i)->partonFlavour()); //flavor == american; not this british BS
      ntagged+=1;

      if(jetflavor==5||jetflavor==4){
	nbjets +=1;
	bjettotal += CSVM(jetpt).first;////GET b SCALEFACTOR
	bjettotalerr += (CSVM(jetpt).second); ///Average the error (check this?)
      }
      else if(jetflavor!=5&&jetflavor!=4){
	nfakes +=1;
	faketotal += CSVMFake(jetpt,jeteta).first; ////GET FAKE SCALEFACTOR
	faketotalerr += (CSVMFake(jetpt,jeteta).second); ///Average the error (check this?)
      }
    }
    //cout<< "Btag4" << endl;
    ////Calculate SF for Atleast 1 bjet
    if(nbjets>0&&nfakes>0){
      EffWEIGHTCSVM1 = (bjettotal/nbjets)*(faketotal/nfakes); 
      EffWEIGHTCSVM1err = sqrt(pow(faketotalerr,2) + pow(bjettotalerr,2));
    }
    else if(nbjets>0&&nfakes==0){
      EffWEIGHTCSVM1 = bjettotal/nbjets;
      EffWEIGHTCSVM1err = bjettotalerr/nbjets;
    }
    else if(nbjets==0&&nfakes>0){
      EffWEIGHTCSVM1 = faketotal/nfakes;
      EffWEIGHTCSVM1err = faketotalerr/nfakes;
    }
    else {EffWEIGHTCSVM1 = 0; EffWEIGHTCSVM1err = 0;}////No b-tagged jets found!
    //cout<< "Btag5" << endl;
    std::pair<double,double> ScalefactorAndError = std::make_pair(EffWEIGHTCSVM1,EffWEIGHTCSVM1err);
    //cout<< "Btag6" << endl;
    return ScalefactorAndError;

  }

  
  std::pair<double,double> CSVTight1( JetPtrVector jets , bool top ){
 
    double bdisc = 0;
    double EffWEIGHTCSVT1 = 0;
    double EffWEIGHTCSVT1err = 0;
    ///==================================================================
    ////Tight Jet Atleast 1  
    bdisc = 0.898;
    int ntagged = 0;
    int nfakes = 0;
    double faketotal = 0;
    double faketotalerr = 0;
    int nbjets = 0;
    double bjettotal = 0;
    double bjettotalerr = 0;
    
    for(unsigned int i=0; i < jets.size(); i++){
      double jetpt, jeteta, jetflavor = 0;
      //cout << "btag9" << endl;  
      //cout << "i " << i << "jet pt " << jets.at(i)->pt() << endl; 
      if(jets.at(i)->pt()<20)
	continue;

      if(jets.at(i)->bDiscriminator("combinedSecondaryVertexBJetTags")<bdisc) ///IF the bdiscriminiator value is less than Light value then move on to next jet in loop
	continue;
      
      //cout << "btag7" << endl;  
      jetpt = jets.at(i)->pt();
      jeteta = abs(jets.at(i)->eta());
      jetflavor = abs(jets.at(i)->partonFlavour()); //flavor == american; not this british BS
      ntagged+=1;
      //cout << "btag8" << endl;  
      if(jetflavor==5||jetflavor==4){
	nbjets +=1;
	bjettotal += CSVT(jetpt).first;////GET b SCALEFACTOR
	bjettotalerr += (CSVT(jetpt).second); ///Average the error (check this?)
      }
      else if(jetflavor!=5&&jetflavor!=4){
	nfakes +=1;
	faketotal += CSVTFake(jetpt,jeteta).first; ////GET FAKE SCALEFACTOR
	faketotalerr += (CSVTFake(jetpt,jeteta).second); ///Average the error (check this?)
      }
    }
    //cout<< "Btag4" << endl;
    ////Calculate SF for Atleast 1 bjet
    if(nbjets>0&&nfakes>0){
      EffWEIGHTCSVT1 = (bjettotal/nbjets)*(faketotal/nfakes); 
      EffWEIGHTCSVT1err = sqrt(pow(faketotalerr,2) + pow(bjettotalerr,2));
    }
    else if(nbjets>0&&nfakes==0){
      EffWEIGHTCSVT1 = bjettotal/nbjets;
      EffWEIGHTCSVT1err = bjettotalerr/nbjets;
    }
    else if(nbjets==0&&nfakes>0){
      EffWEIGHTCSVT1 = faketotal/nfakes;
      EffWEIGHTCSVT1err = faketotalerr/nfakes;
    }
    else {EffWEIGHTCSVT1 = 0; EffWEIGHTCSVT1err = 0;}////No b-tagged jets found!
    //cout<< "Btag5" << endl;
    std::pair<double,double> ScalefactorAndError = std::make_pair(EffWEIGHTCSVT1,EffWEIGHTCSVT1err);
    //cout<< "Btag6" << endl;
    return ScalefactorAndError;

  }


  
  std::pair<double,double> CSVLoose2( JetPtrVector jets , bool top ){
    ////==========Loose tags exactly 2  
    double jetpt0, jeteta0, jetflavor0;
    double jetpt1, jeteta1, jetflavor1;
    double SF2 = 0;
    double SF2err = 0;
    double EffWEIGHTCSVL2 = 0;
    double EffWEIGHTCSVL2err = 0;
    double bdisc = 0.244;
    //cout<< "Btag7" << endl;
    if(jets.size()>1&&jets.at(0)->pt()>20&&jets.at(1)->pt()>20)
      if(jets.at(0)->bDiscriminator("combinedSecondaryVertexBJetTags")>bdisc&&jets.at(1)->bDiscriminator("combinedSecondaryVertexBJetTags")>bdisc){
	jetpt0 = jets.at(0)->pt(); //define pt,eta,flavor
	jeteta0 = abs(jets.at(0)->eta());
	jetflavor0 = abs(jets.at(0)->partonFlavour()); 
	//cout<< "Btag8" << endl;
	jetpt1 = jets.at(1)->pt();
	jeteta1 = abs(jets.at(1)->eta());
	jetflavor1 = abs(jets.at(1)->partonFlavour()); 
	std::pair<double,double>jet0pair;
	std::pair<double,double>jet1pair;
	
	//cout << "jet1 " <<jetpt0 << " eta " << jeteta0 << " flavor " << jetflavor0 << "jet2 " << jetpt1 << " eta " << jeteta1 << " flavor " << jetflavor1 << endl;
	
	if((jetflavor0==5||jetflavor0==4)/////both true b's
	   &&(jetflavor1==5||jetflavor1==4))
	  {
	    if(top){
	      jet0pair = CSVLTop(jetpt0);
	      jet1pair = CSVLTop(jetpt1);
	    }
	    else{
	      jet0pair = CSVL(jetpt0);
	      jet1pair = CSVL(jetpt1);
	    }

	    SF2=(jet0pair.first)*(jet1pair.first);
	    SF2err=pow(pow(jet0pair.second,2)+pow(jet1pair.second,2),0.5);
	  }
	else if((jetflavor0==5||jetflavor0==4)////first true b second fake b
		&&(jetflavor1!=5&&jetflavor1!=4))
	  {
	    if(top)
	      jet0pair = CSVLTop(jetpt0);
	    else
	      jet0pair = CSVL(jetpt0);
	    
	    jet1pair = CSVLFake(jetpt1,jeteta1);
	    SF2=(jet0pair.first)*(jet1pair.first);
	    //printf("SF2 = %f jet0: %f jet1: %f",SF2,jet0pair.first,jet1pair.first);
	    SF2err=pow(pow(jet0pair.second,2)+pow(jet1pair.second,2),0.5);
	  }
	else if((jetflavor0!=5&&jetflavor0!=4)////first fake b second true b
		&&(jetflavor1==5||jetflavor1==4))
	  { 
	  jet0pair = CSVLFake(jetpt0,jeteta0);
	  
	  if(top)
	    jet1pair = CSVLTop(jetpt1);
	  else
	    jet1pair = CSVL(jetpt1);
	  
	  SF2=(jet0pair.first)*(jet1pair.first);
	  SF2err=pow(pow(jet0pair.second,2)+pow(jet1pair.second,2),0.5);
	  
	}
      else if((jetflavor0!=5&&jetflavor0!=4)////first fake b second fake b
	      &&(jetflavor1!=5&&jetflavor1!=4))
	{
	  jet0pair = CSVLFake(jetpt0,jeteta0);
	  jet1pair = CSVLFake(jetpt1,jeteta1);
	  SF2=(jet0pair.first)*(jet1pair.first);
	  SF2err=pow(pow(jet0pair.second,2)+pow(jet1pair.second,2),0.5);
	}
	//cout << "later SF2 " << SF2 << endl;
	EffWEIGHTCSVL2 = SF2;
	EffWEIGHTCSVL2err = SF2err;      
	
      }
    
    std::pair<double,double> ScalefactorAndError = std::make_pair(EffWEIGHTCSVL2,EffWEIGHTCSVL2err);
    //cout << "EffWEIGHTCSVL2 " << EffWEIGHTCSVL2 << "EffWEIGHTCSVL2err " << EffWEIGHTCSVL2err <<endl;
    return ScalefactorAndError;
  }

  std::pair<double,double> CSVMedium2( JetPtrVector jets , bool top ){
    ////==========Loose tags exactly 2  
    double jetpt0, jeteta0, jetflavor0;
    double jetpt1, jeteta1, jetflavor1;
    double SF2 = 0;
    double SF2err = 0;
    double EffWEIGHTCSVM2 = 0; 
    double EffWEIGHTCSVM2err = 0;
    double bdisc = 0.679;
    //cout<< "Btag7" << endl;
    if(jets.size()>1&&jets.at(0)->pt()>20&&jets.at(1)->pt()>20)
    if(jets.at(0)->bDiscriminator("combinedSecondaryVertexBJetTags")>bdisc&&jets.at(1)->bDiscriminator("combinedSecondaryVertexBJetTags")>bdisc){
      jetpt0 = jets.at(0)->pt(); //define pt,eta,flavor
      jeteta0 = abs(jets.at(0)->eta());
      jetflavor0 = abs(jets.at(0)->partonFlavour()); 
      jetpt1 = jets.at(1)->pt();
      jeteta1 = abs(jets.at(1)->eta());
      jetflavor1 = abs(jets.at(1)->partonFlavour()); 
      std::pair<double,double>jet0pair;
      std::pair<double,double>jet1pair;

      if((jetflavor0==5||jetflavor0==4)/////both true b's
	 &&(jetflavor1==5||jetflavor1==4))
	{
	  if(top){
	    jet0pair = CSVMTop(jetpt0);
	    jet1pair = CSVMTop(jetpt1);
	  }
	  else{
	    jet0pair = CSVM(jetpt0);
	    jet1pair = CSVM(jetpt1);
	  }
	  SF2=(jet0pair.first)*(jet1pair.first);
	  SF2err=pow(pow(jet0pair.second,2)+pow(jet1pair.second,2),0.5);
	}
      else if((jetflavor0==5||jetflavor0==4)////first true b second fake b
	      &&(jetflavor1!=5&&jetflavor1!=4))
	{
	  if(top)
	    jet0pair = CSVMTop(jetpt0);
	  else
	    jet0pair = CSVM(jetpt0);

	  jet1pair = CSVMFake(jetpt1,jeteta1);
	  SF2=(jet0pair.first)*(jet1pair.first);
	  SF2err=pow(pow(jet0pair.second,2)+pow(jet1pair.second,2),0.5);

	}
      else if((jetflavor0!=5&&jetflavor0!=4)////first fake b second true b
	      &&(jetflavor1==5||jetflavor1==4))
	{ 
	  jet0pair = CSVMFake(jetpt0,jeteta0);

	  if(top)
	    jet1pair = CSVMTop(jetpt1);
	  else
	    jet1pair = CSVM(jetpt1);

	  SF2=(jet0pair.first)*(jet1pair.first);
	  SF2err=pow(pow(jet0pair.second,2)+pow(jet1pair.second,2),0.5);
	  
	}
      else if((jetflavor0!=5&&jetflavor0!=4)////first fake b second fake b
	      &&(jetflavor1!=5&&jetflavor1!=4))
	{
	  jet0pair = CSVMFake(jetpt0,jeteta0);
	  jet1pair = CSVMFake(jetpt1,jeteta1);
	  SF2=(jet0pair.first)*(jet1pair.first);
	  SF2err=pow(pow(jet0pair.second,2)+pow(jet1pair.second,2),0.5);
	}
      EffWEIGHTCSVM2 = SF2;
      EffWEIGHTCSVM2err = SF2err;      

    }
    
    std::pair<double,double> ScalefactorAndError = std::make_pair(EffWEIGHTCSVM2,EffWEIGHTCSVM2err);

    return ScalefactorAndError;
  }

  std::pair<double,double> CSVTight2( JetPtrVector jets , bool top ){
    ////==========Loose tags exactly 2  
    double jetpt0, jeteta0, jetflavor0;
    double jetpt1, jeteta1, jetflavor1;
    double SF2 = 0;
    double SF2err = 0;
    double EffWEIGHTCSVT2 = 0;
    double EffWEIGHTCSVT2err = 0;
    double bdisc = 0.898;
    //cout<< "Btag7" << endl;
    if(jets.size()>1&&jets.at(0)->pt()>20&&jets.at(1)->pt()>20)
    if(jets.at(0)->bDiscriminator("combinedSecondaryVertexBJetTags")>bdisc&&jets.at(1)->bDiscriminator("combinedSecondaryVertexBJetTags")>bdisc){
      jetpt0 = jets.at(0)->pt(); //define pt,eta,flavor
      jeteta0 = abs(jets.at(0)->eta());
      jetflavor0 = abs(jets.at(0)->partonFlavour()); 
      //cout<< "Btag8" << endl;
      jetpt1 = jets.at(1)->pt();
      jeteta1 = abs(jets.at(1)->eta());
      jetflavor1 = abs(jets.at(1)->partonFlavour()); 
      std::pair<double,double>jet0pair;
      std::pair<double,double>jet1pair;

      if((jetflavor0==5||jetflavor0==4)/////both true b's
	 &&(jetflavor1==5||jetflavor1==4))
	{
	  if(top){
	    jet0pair = CSVTTop(jetpt0);
	    jet1pair = CSVTTop(jetpt1);
	  }
	  else{
	    jet0pair = CSVT(jetpt0);
	    jet1pair = CSVT(jetpt1);
	  }

	  SF2=(jet0pair.first)*(jet1pair.first);
	  SF2err=pow(pow(jet0pair.second,2)+pow(jet1pair.second,2),0.5);
	}
      else if((jetflavor0==5||jetflavor0==4)////first true b second fake b
	      &&(jetflavor1!=5&&jetflavor1!=4))
	{
	  if(top)
	    jet0pair = CSVTTop(jetpt0);
	  else
	    jet0pair = CSVT(jetpt0);

	  jet1pair = CSVTFake(jetpt1,jeteta1);
	  SF2=(jet0pair.first)*(jet1pair.first);
	  SF2err=pow(pow(jet0pair.second,2)+pow(jet1pair.second,2),0.5);

	}
      else if((jetflavor0!=5&&jetflavor0!=4)////first fake b second true b
	      &&(jetflavor1==5||jetflavor1==4))
	{ 
	  jet0pair = CSVTFake(jetpt0,jeteta0);

	  if(top)
	    jet1pair = CSVTTop(jetpt1);
	  else
	    jet1pair = CSVT(jetpt1);

	  SF2=(jet0pair.first)*(jet1pair.first);
	  SF2err=pow(pow(jet0pair.second,2)+pow(jet1pair.second,2),0.5);
	  
	}
      else if((jetflavor0!=5&&jetflavor0!=4)////first fake b second fake b
	      &&(jetflavor1!=5&&jetflavor1!=4))
	{
	  jet0pair = CSVTFake(jetpt0,jeteta0);
	  jet1pair = CSVTFake(jetpt1,jeteta1);
	  SF2=(jet0pair.first)*(jet1pair.first);
	  SF2err=pow(pow(jet0pair.second,2)+pow(jet1pair.second,2),0.5);
	}
      EffWEIGHTCSVT2 = SF2;
      EffWEIGHTCSVT2err = SF2err;      

    }
    
    std::pair<double,double> ScalefactorAndError = std::make_pair(EffWEIGHTCSVT2,EffWEIGHTCSVT2err);

    return ScalefactorAndError;
  }


					   
  std::pair<double,double> CSVL(double jetpt){ ////return pair (value,error)
    double SF = 1.00572*((1.+(0.013676*jetpt))/(1.+(0.0143279*jetpt)));//0.981149*((1.+(-0.000713295*jetpt))/(1.+(-0.000703264*jetpt)));
    double SFerr=0;
    double SFb_error[16] = {
      0.033408,
      0.015446,
      0.0146992,
      0.0183964,
      0.0185363,
      0.0145547,
      0.0176743,
      0.0203609,
      0.0143342,
      0.0148771,
      0.0157936,
      0.0176496,
      0.0209156,
      0.0278529,
      0.0346877,
      0.0350101};

    double ptmin[16] = {20, 30, 40, 50, 60, 70, 80, 100, 120, 160, 210, 260, 320, 400, 500, 600};
    double ptmax[16] = {30, 40, 50, 60, 70, 80,100, 120, 160, 210, 260, 320, 400, 500, 600, 800};
    int index=0;
    
    if(jetpt<800)
      for(int i = 0; i<17; i++){
	if(jetpt>=ptmin[i]&&jetpt<ptmax[i]){
	  index = i; break;}
      }
    
    if(jetpt<800)
      SFerr = SFb_error[index];
    else
      SFerr=0;
    //std::cout<< "Printing b-Tagging SFerr " << SFerr <<std::endl;
    return std::make_pair(SF,SFerr); 
  }

  std::pair<double,double> CSVM(double jetpt){ ////return pair (value,error)
    double SF = (0.939158+(0.000158694*jetpt))+(-2.53962e-07*(jetpt*jetpt));//0.726981*((1.+(0.253238*jetpt))/(1.+(0.188389*jetpt)));
    double SFerr=0;
    double SFb_error[16] = {
      0.0415694,
      0.023429,
      0.0261074,
      0.0239251,
      0.0232416,
      0.0197251,
      0.0217319,
      0.0198108,
      0.0193,
      0.0276144,
      0.0205839,
      0.026915,
      0.0312739,
      0.0415054,
      0.0740561,
      0.0598311};
    
    double ptmin[16] = {20, 30, 40, 50, 60, 70, 80, 100, 120, 160, 210, 260, 320, 400, 500, 600};
    double ptmax[16] = {30, 40, 50, 60, 70, 80,100, 120, 160, 210, 260, 320, 400, 500, 600, 800};
    int index=0;
    
    if(jetpt<800)
      for(int i = 0; i<17; i++){
	if(jetpt>=ptmin[i]&&jetpt<ptmax[i]){
	  index = i; break;}
      }
    
    if(jetpt<800)
      SFerr = SFb_error[index];
    else
      SFerr=0;

    return std::make_pair(SF,SFerr); 
  }
  
  std::pair<double,double> CSVT(double jetpt){ ////return pair (value,error)
    double SF = (0.9203+(-3.32421e-05*jetpt))+(-7.74664e-08*(jetpt*jetpt));//0.869965*((1.+(0.0335062*jetpt))/(1.+(0.0304598*jetpt))); 
      //double SF =  0.607239*jetpt*jetpt*jetpt*jetpt+-1.49984*jetpt*jetpt*jetpt+1.3473*jetpt*jetpt+-0.599888*jetpt+1.09396;
    double SFerr=0;
    double SFb_error[16] = {
      0.0511028,
      0.0306671,
      0.0317498,
      0.032779,
      0.0291528,
      0.0249308,
      0.0301118,
      0.032047,
      0.0348072,
      0.0357745,
      0.0378756,
      0.0412608,
      0.0777516,
      0.0860741,
      0.0942209,
      0.104106 };
    
    double ptmin[16] = {20, 30, 40, 50, 60, 70, 80, 100, 120, 160, 210, 260, 320, 400, 500, 600};
    double ptmax[16] = {30, 40, 50, 60, 70, 80,100, 120, 160, 210, 260, 320, 400, 500, 600, 800};
    int index=0;
    
    if(jetpt<800)
      for(int i = 0; i<17; i++){
	if(jetpt>=ptmin[i]&&jetpt<ptmax[i]){
	  index = i; break;}
      }
    
    if(jetpt<800)
      SFerr = SFb_error[index];
    else
      SFerr=0;
    
    return std::make_pair(SF,SFerr); 
  }


  std::pair<double,double> CSVLTop(double jetpt){ ////return pair (value,error)
    double SF = 1.008;
    double SFerr = 0.023;
    return std::make_pair(SF,SFerr); 
  }

  std::pair<double,double> CSVMTop(double jetpt){ ////return pair (value,error)
    double SF = 0.963;
    double SFerr = 0.02;
    return std::make_pair(SF,SFerr); 
  }

  std::pair<double,double> CSVTTop(double jetpt){ ////return pair (value,error)
    double SF = 0.947;
    double SFerr = 0.025;
    return std::make_pair(SF,SFerr); 
  }


  /////CSVL Fake Algo Defines a Scale factor (SF), a High Scale Factor(SFH) and a Low Scale Factor (SFL)
  /////Using SFH-SFL for error estimate; perhaps better to just output SFH and SFL but much more messy
  /////For the future: Consider implementing high and low values
  std::pair<double,double> CSVLFake(double jetpt = 0,double jeteta = 0){ ////return pair (value,error)
    double SF, SFL, SFH , SFerr= 0;

    if(abs(jeteta)>0&&abs(jeteta)<0.5){
      SF  = ((1.01177+(0.0023066*jetpt))+(-4.56052e-06*(jetpt*jetpt)))+(2.57917e-09*(jetpt*(jetpt*jetpt))); //((1.04901+(0.00152181*jetpt))+(-3.43568e-06*(jetpt*jetpt)))+(2.17219e-09*(jetpt*(jetpt*jetpt)));
      SFL = ((0.977761+(0.00170704*jetpt))+(-3.2197e-06*(jetpt*jetpt)))+(1.78139e-09*(jetpt*(jetpt*jetpt)));//((0.973773+(0.00103049*jetpt))+(-2.2277e-06*(jetpt*jetpt)))+(1.37208e-09*(jetpt*(jetpt*jetpt)));
      SFH = ((1.04582+(0.00290226*jetpt))+(-5.89124e-06*(jetpt*jetpt)))+(3.37128e-09*(jetpt*(jetpt*jetpt)));//((1.12424+(0.00201136*jetpt))+(-4.64021e-06*(jetpt*jetpt)))+(2.97219e-09*(jetpt*(jetpt*jetpt)));
    }
    else if(abs(jeteta)>0.5&&abs(jeteta)<1.0){
      SF  = ((0.975966+(0.00196354*jetpt))+(-3.83768e-06*(jetpt*jetpt)))+(2.17466e-09*(jetpt*(jetpt*jetpt)));//((0.991915+(0.00172552*jetpt))+(-3.92652e-06*(jetpt*jetpt)))+(2.56816e-09*(jetpt*(jetpt*jetpt)));
      SFL = ((0.945135+(0.00146006*jetpt))+(-2.70048e-06*(jetpt*jetpt)))+(1.4883e-09*(jetpt*(jetpt*jetpt)));//((0.921518+(0.00129098*jetpt))+(-2.86488e-06*(jetpt*jetpt)))+(1.86022e-09*(jetpt*(jetpt*jetpt)));
      SFH = ((1.00683+(0.00246404*jetpt))+(-4.96729e-06*(jetpt*jetpt)))+(2.85697e-09*(jetpt*(jetpt*jetpt)));//((1.06231+(0.00215815*jetpt))+(-4.9844e-06*(jetpt*jetpt)))+(3.27623e-09*(jetpt*(jetpt*jetpt)));
    }
    else if(abs(jeteta)>1.0&&abs(jeteta)<1.5){
      SF  = ((0.93821+(0.00180935*jetpt))+(-3.86937e-06*(jetpt*jetpt)))+(2.43222e-09*(jetpt*(jetpt*jetpt)));//((0.962127+(0.00192796*jetpt))+(-4.53385e-06*(jetpt*jetpt)))+(3.0605e-09*(jetpt*(jetpt*jetpt)));
      SFL = ((0.911657+(0.00142008*jetpt))+(-2.87569e-06*(jetpt*jetpt)))+(1.76619e-09*(jetpt*(jetpt*jetpt)));//((0.895419+(0.00153387*jetpt))+(-3.48409e-06*(jetpt*jetpt)))+(2.30899e-09*(jetpt*(jetpt*jetpt)));
      SFH = ((0.964787+(0.00219574*jetpt))+(-4.85552e-06*(jetpt*jetpt)))+(3.09457e-09*(jetpt*(jetpt*jetpt)));//((1.02883+(0.00231985*jetpt))+(-5.57924e-06*(jetpt*jetpt)))+(3.81235e-09*(jetpt*(jetpt*jetpt)));
    }
    else if(abs(jeteta)>1.5&&abs(jeteta)<2.4){
      SF  = ((1.00022+(0.0010998*jetpt))+(-3.10672e-06*(jetpt*jetpt)))+(2.35006e-09*(jetpt*(jetpt*jetpt)));//((1.06121+(0.000332747*jetpt))+(-8.81201e-07*(jetpt*jetpt)))+(7.43896e-10*(jetpt*(jetpt*jetpt)));
      SFL = ((0.970045+(0.000862284*jetpt))+(-2.31714e-06*(jetpt*jetpt)))+(1.68866e-09*(jetpt*(jetpt*jetpt)));//((0.983607+(0.000196747*jetpt))+(-3.98327e-07*(jetpt*jetpt)))+(2.95764e-10*(jetpt*(jetpt*jetpt)));
      SFH = ((1.03039+(0.0013358*jetpt))+(-3.89284e-06*(jetpt*jetpt)))+(3.01155e-09*(jetpt*(jetpt*jetpt)));//((1.1388+(0.000468418*jetpt))+(-1.36341e-06*(jetpt*jetpt)))+(1.19256e-09*(jetpt*(jetpt*jetpt)));
    }
    else{ SF = 1; SFH=0; SFL=0;}

    SFerr = (SFH-SFL)/2;

    //cout << "SF Light fake: " << SF << " SFerr: " << SFerr << " SFH - SF: " << SFH-SF << " SF-SFL: " << SF-SFL <<endl;
    //cout << "btag1" << endl;
    return std::make_pair(SF,SFerr); 
  }


  std::pair<double,double> CSVMFake(double jetpt = 0,double jeteta = 0){ ////return pair (value,error)
    double SF, SFL, SFH , SFerr= 0;

    if(abs(jeteta)>0&&abs(jeteta)<0.8){
      SF  = ((1.07541+(0.00231827*jetpt))+(-4.74249e-06*(jetpt*jetpt)))+(2.70862e-09*(jetpt*(jetpt*jetpt)));//((1.06238+(0.00198635*jetpt))+(-4.89082e-06*(jetpt*jetpt)))+(3.29312e-09*(jetpt*(jetpt*jetpt)));
      SFL = ((0.964527+(0.00149055*jetpt))+(-2.78338e-06*(jetpt*jetpt)))+(1.51771e-09*(jetpt*(jetpt*jetpt)));//((0.972746+(0.00104424*jetpt))+(-2.36081e-06*(jetpt*jetpt)))+(1.53438e-09*(jetpt*(jetpt*jetpt)));
      SFH = ((1.18638+(0.00314148*jetpt))+(-6.68993e-06*(jetpt*jetpt)))+(3.89288e-09*(jetpt*(jetpt*jetpt)));//((1.15201+(0.00292575*jetpt))+(-7.41497e-06*(jetpt*jetpt)))+(5.0512e-09*(jetpt*(jetpt*jetpt)));
    }
    else if(abs(jeteta)>0.8&&abs(jeteta)<1.6){
      SF  = ((1.05613+(0.00114031*jetpt))+(-2.56066e-06*(jetpt*jetpt)))+(1.67792e-09*(jetpt*(jetpt*jetpt)));//((1.08048+(0.00110831*jetpt))+(-2.96189e-06*(jetpt*jetpt)))+(2.16266e-09*(jetpt*(jetpt*jetpt)));
      SFL = ((0.946051+(0.000759584*jetpt))+(-1.52491e-06*(jetpt*jetpt)))+(9.65822e-10*(jetpt*(jetpt*jetpt)));//((0.9836+(0.000649761*jetpt))+(-1.59773e-06*(jetpt*jetpt)))+(1.14324e-09*(jetpt*(jetpt*jetpt)));
      SFH = ((1.16624+(0.00151884*jetpt))+(-3.59041e-06*(jetpt*jetpt)))+(2.38681e-09*(jetpt*(jetpt*jetpt)));//((1.17735+(0.00156533*jetpt))+(-4.32257e-06*(jetpt*jetpt)))+(3.18197e-09*(jetpt*(jetpt*jetpt)));
    }
    else if(abs(jeteta)>1.6&&abs(jeteta)<2.4){
      SF = ((1.05625+(0.000487231*jetpt))+(-2.22792e-06*(jetpt*jetpt)))+(1.70262e-09*(jetpt*(jetpt*jetpt)));//((1.09145+(0.000687171*jetpt))+(-2.45054e-06*(jetpt*jetpt)))+(1.7844e-09*(jetpt*(jetpt*jetpt)));
      SFL = ((0.956736+(0.000280197*jetpt))+(-1.42739e-06*(jetpt*jetpt)))+(1.0085e-09*(jetpt*(jetpt*jetpt)));//((1.00616+(0.000358884*jetpt))+(-1.23768e-06*(jetpt*jetpt)))+(6.86678e-10*(jetpt*(jetpt*jetpt)));
      SFH = ((1.15575+(0.000693344*jetpt))+(-3.02661e-06*(jetpt*jetpt)))+(2.39752e-09*(jetpt*(jetpt*jetpt)));//((1.17671+(0.0010147*jetpt))+(-3.66269e-06*(jetpt*jetpt)))+(2.88425e-09*(jetpt*(jetpt*jetpt)));
    }
    else{ SF = 1; SFH=0; SFL=0;}

    SFerr = (SFH-SFL)/2;

    //cout << "SF Med fake: " << SF << " SFerr: " << SFerr << " SFH - SF: " << SFH-SF << " SF-SFL: " << SF-SFL <<endl;
    //cout << "btag1" << endl;
    return std::make_pair(SF,SFerr); 
  }

  std::pair<double,double> CSVTFake(double jetpt = 0,double jeteta = 0){ ////return pair (value,error)
    double SF, SFL, SFH , SFerr= 0;

    if(abs(jeteta)>0&&abs(jeteta)<2.4){
      SF  = ((1.00462+(0.00325971*jetpt))+(-7.79184e-06*(jetpt*jetpt)))+(5.22506e-09*(jetpt*(jetpt*jetpt)));//((1.01739+(0.00283619*jetpt))+(-7.93013e-06*(jetpt*jetpt)))+(5.97491e-09*(jetpt*(jetpt*jetpt)));
      SFL = ((0.845757+(0.00186422*jetpt))+(-4.6133e-06*(jetpt*jetpt)))+(3.21723e-09*(jetpt*(jetpt*jetpt)));//((0.953587+(0.00124872*jetpt))+(-3.97277e-06*(jetpt*jetpt)))+(3.23466e-09*(jetpt*(jetpt*jetpt)));
      SFH = ((1.16361+(0.00464695*jetpt))+(-1.09467e-05*(jetpt*jetpt)))+(7.21896e-09*(jetpt*(jetpt*jetpt)));//((1.08119+(0.00441909*jetpt))+(-1.18764e-05*(jetpt*jetpt)))+(8.71372e-09*(jetpt*(jetpt*jetpt)));
    }
    else{ SF = 1; SFH=0; SFL=0;}

    SFerr = (SFH-SFL)/2;

    //cout << "SF Tight fake: " << SF << " SFerr " << SFerr << " SFH - SF: " << SFH-SF << " SF-SFL: " << SF-SFL <<endl;
    //cout << "btag1" << endl;
    return std::make_pair(SF,SFerr); 
  }

  bool top_;

};


