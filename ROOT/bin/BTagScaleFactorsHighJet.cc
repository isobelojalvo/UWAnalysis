
#include "PhysicsTools/FWLite/interface/CommandLineParser.h" 
#include "TFile.h"
#include "TROOT.h"
#include "TKey.h"
#include "TTree.h"
#include "TH1F.h"
#include "TF1.h"
#include <math.h> 
#include "TMath.h" 
#include <limits>
#include "RooHist.h"

// RooHist *stuff = _file0->Get("MC_combRelPFISO20_2011B_pt__abseta>1.2")



void readdir(TDirectory * dir,optutl::CommandLineParser parser,int topType); 
float LightLookupCSVM(float pt, float eta);
float LightLookupCSVL(float pt, float eta);
float LightLookupCSVT(float pt, float eta);
float LightLookupJPL(float pt, float eta);
float LightLookupJPM(float pt, float eta);
float LightLookupJPT(float pt, float eta);
float LightLookupSSVHEM(float pt, float eta);
float LightLookupSSVHPT(float pt, float eta);

int main (int argc, char* argv[]) 
{

  //BTagScaleFactors outputFile='analysis.root' csvl1Jet='EffWEIGHTCSVL1' typeTop=0

   optutl::CommandLineParser parser ("Sets Event Weights in the ntuple");
   //parser.addOption("outputFile",optutl::CommandLineParser::kString,"File","corrections.root");
   //parser.addOption("eta",optutl::CommandLineParser::kString,"eta variable","eta1");
   parser.addOption("TTreeInput",optutl::CommandLineParser::kString,"TTree to scale","muNuEventTree/eventTree");
   parser.addOption("typeTop",optutl::CommandLineParser::kInteger,"Is this a top sample",0);
   parser.addOption("minPt",optutl::CommandLineParser::kDouble,"Min Jet Pt",25.);
   parser.addOption("csvl1Jet",optutl::CommandLineParser::kString,"1 loose CSV Jet weight","CSVL1Jet");
   parser.addOption("csvm1Jet",optutl::CommandLineParser::kString,"1 medium CSV Jet weight","CSVM1Jet");
   parser.addOption("csvt1Jet",optutl::CommandLineParser::kString,"1 tight CSV Jet weight","CSVT1Jet");
   parser.addOption("csvl2Jet",optutl::CommandLineParser::kString,"2 loose CSV Jet weight","CSVL2Jets");
   parser.addOption("csvm2Jet",optutl::CommandLineParser::kString,"2 medium CSV Jet weight","CSVM2Jets");
   parser.addOption("csvt2Jet",optutl::CommandLineParser::kString,"2 tight CSV Jet weight","CSVT2Jets");

   parser.addOption("ssvhem1Jet",optutl::CommandLineParser::kString,"1 medium SSVHE Jet weight","SSVHEM1Jet");
   parser.addOption("ssvhem2Jet",optutl::CommandLineParser::kString,"2 medium SSVHE Jet weight","SSVHEM2Jets");

   parser.parseArguments (argc, argv);
   
   TFile *f = new TFile(parser.stringValue("outputFile").c_str(),"UPDATE");

   printf("Now weighting: %s\n",parser.stringValue("outputFile").c_str());
   

   int topType = parser.integerValue("typeTop");
   readdir(f,parser,topType);
   
   f->Close();
} 


void readdir(TDirectory * dir,optutl::CommandLineParser parser,int topType) 
{
   double minPt = parser.doubleValue("minPt");
  TDirectory *dirsav = gDirectory;
  TIter next(dir->GetListOfKeys());
  TKey *key;
  while((key = (TKey*)next())){
    printf("Found key=%s \n",key->GetName());
    TObject *obj = key->ReadObj();
    if(obj->IsA()->InheritsFrom(TDirectory::Class())){
      dir->cd(key->GetName());
      TDirectory *subdir = gDirectory;
      readdir(subdir,parser,topType);
      dirsav->cd();
    }
    else if(obj->IsA()->InheritsFrom(TTree::Class())){
      TTree *t = (TTree*)obj;

      //get muon pt,eta
      float pt;
      float eta;
      int typeeta = 0;
      int typept = 0;
      int i;
      int j;
      float x;

      /*      int nJetsBTagCSV1Pt30 = -5;
      int nJetsBTagCSV1Pt30Matched = -5;
      int nJetsBTagCSV1Pt30NMatched = -5;
      int nJetsBTagCSV2Pt30 = -5;
      int nJetsBTagCSV2Pt30Matched = -5;
      int nJetsBTagCSV2Pt30NMatched = -5;
      int nJetsBTagCSV3Pt30 = -5;
      int nJetsBTagCSV3Pt30Matched = -5;
      int nJetsBTagCSV3Pt30NMatched = -5;
      */
      float J1Parton = -5;
      float J2Parton = -5;
      float J3Parton = -5;
      float J4Parton = -5;
      float J5Parton = -5;
      float J6Parton = -5;
      float J7Parton = -5;
      float J8Parton = -5;

      float j1pt = -5;
      float j2pt = -5;
      float j3pt = -5;
      float j4pt = -5;
      float j5pt = -5;
      float j6pt = -5;
      float j7pt = -5;
      float j8pt = -5;

      float j1eta = -5;
      float j2eta = -5;
      float j3eta = -5;
      float j4eta = -5;
      float j5eta = -5;
      float j6eta = -5;
      float j7eta = -5;
      float j8eta = -5;

      float J1CSVbtag = -5;
      float J2CSVbtag = -5;
      float J3CSVbtag = -5;

      float J1SSVHEbtag = -5;
      float J2SSVHEbtag = -5;

      float fakeCSVL2J = 1;
      float fakeCSVM2J = 1;
      float fakeCSVT2J = 1;
      float fakeCSV1_2j = 1; 
      float fakeCSV2_2j = 1; 
 
      float fakeCSVL = -5; 
      float fakeCSVM = -5; 
      float fakeCSVT = -5; 
      float fakeCSV1 = -5; 
      float fakeCSV2 = -5; 
      float fakeCSV3 = -5; 

      float effCSVL2J = -5; 
      float effCSVM2J = -5; 
      float effCSVT2J = -5; 
      float effCSV1_2j = -5; 
      float effCSV2_2j = -5; 
      float effCSVL = -5; 
      float effCSVM = -5; 
      float effCSVT = -5; 
      float effCSV1 = -5; 
      float effCSV2 = -5; 

      float SFCSVL1Jet = 0;
      float SFCSVM1Jet = 0;
      float SFCSVT1Jet = 0;
      float SFCSVL2Jet = 0;
      float SFCSVM2Jet = 0;
      float SFCSVT2Jet = 0;
      float SFSSVHEM1Jet = 0;
      float SFSSVHEM2Jet = 0;

      float SFb1=0;
      float SFb2=0;

      t->SetBranchAddress("muonPt",&pt);
      t->SetBranchAddress("muonEta",&eta);
      //
      t->SetBranchAddress("J1JetParton",&J1Parton);
      t->SetBranchAddress("J2JetParton",&J2Parton);
      t->SetBranchAddress("J3JetParton",&J3Parton);
      t->SetBranchAddress("J4JetParton",&J4Parton);
      t->SetBranchAddress("J5JetParton",&J5Parton);
      t->SetBranchAddress("J6JetParton",&J6Parton);
      t->SetBranchAddress("J7JetParton",&J7Parton);
      t->SetBranchAddress("J8JetParton",&J8Parton);

      t->SetBranchAddress("highestJetPt",&j1pt);
      t->SetBranchAddress("secondJetPt",&j2pt);
      t->SetBranchAddress("thirdJetPt",&j3pt);
      t->SetBranchAddress("J4Pt",&j4pt);
      t->SetBranchAddress("J5Pt",&j5pt);
      t->SetBranchAddress("J6Pt",&j6pt);
      t->SetBranchAddress("J7Pt",&j7pt);
      t->SetBranchAddress("J8Pt",&j8pt);

      t->SetBranchAddress("highestJetEta",&j1eta);
      t->SetBranchAddress("secondJetEta",&j2eta);
      t->SetBranchAddress("thirdJetEta",&j3eta);
      t->SetBranchAddress("J4Eta",&j4eta);
      t->SetBranchAddress("J5Eta",&j5eta);
      t->SetBranchAddress("J6Eta",&j6eta);
      t->SetBranchAddress("J7Eta",&j7eta);
      t->SetBranchAddress("J8Eta",&j8eta);

      t->SetBranchAddress("J1CSVbtag",&J1CSVbtag);
      t->SetBranchAddress("J2CSVbtag",&J2CSVbtag);
      t->SetBranchAddress("J3CSVbtag",&J3CSVbtag);

      t->SetBranchAddress("J1SSVHEbtag",&J1SSVHEbtag);
      t->SetBranchAddress("J2SSVHEbtag",&J2SSVHEbtag);

      //get branch and add in value
      TBranch *CSVLEff1Jet = t->Branch(parser.stringValue("csvl1Jet").c_str(),&SFCSVL1Jet,(parser.stringValue("csvl1Jet")+"/F").c_str());
      TBranch *CSVMEff1Jet = t->Branch(parser.stringValue("csvm1Jet").c_str(),&SFCSVM1Jet,(parser.stringValue("csvm1Jet")+"/F").c_str());
      TBranch *CSVTEff1Jet = t->Branch(parser.stringValue("csvt1Jet").c_str(),&SFCSVT1Jet,(parser.stringValue("csvt1Jet")+"/F").c_str());
      TBranch *CSVLEff2Jets = t->Branch(parser.stringValue("csvl2Jet").c_str(),&SFCSVL2Jet,(parser.stringValue("csvl2Jet")+"/F").c_str());
      TBranch *CSVMEff2Jets = t->Branch(parser.stringValue("csvm2Jet").c_str(),&SFCSVM2Jet,(parser.stringValue("csvm2Jet")+"/F").c_str());
      TBranch *CSVTEff2Jets = t->Branch(parser.stringValue("csvt2Jet").c_str(),&SFCSVT2Jet,(parser.stringValue("csvt2Jet")+"/F").c_str());
  
      TBranch *SSVHEMEff1Jet = t->Branch(parser.stringValue("ssvhem1Jet").c_str(),&SFSSVHEM1Jet,(parser.stringValue("ssvhem1Jet")+"/F").c_str());
      TBranch *SSVHEMEff2Jets = t->Branch(parser.stringValue("ssvhem2Jet").c_str(),&SFSSVHEM2Jet,(parser.stringValue("ssvhem2Jet")+"/F").c_str());
      ///////
      //std::vector<double> weights = parser.doubleVector("weights");
      //std::vector<std::string> correctors = parser.stringVector("correctors");
      printf("Found tree -> weighting\n");
      printf("Entries %i \n",(int)t->GetEntries());
      printf("\nNow looking at Loose CSV\n");
      ////////////////////////////////////////////////////////////CSVLiGHT

      for(Int_t k=0;k<t->GetEntries();++k)
	{
	  t->GetEntry(k);
	  i = 0;effCSVM=1;effCSV1 = 0;effCSV2 = 0; effCSVT2J = 1; effCSV1_2j = 1; effCSV2_2j = 1;
	  j = 0;fakeCSVM=1;fakeCSV1 = 0; fakeCSV2 = 0; effCSVT2J = 1; effCSV1_2j = 1; effCSV2_2j = 1;
	  SFCSVL1Jet =1;
	  SFCSVL2Jet =1;
	  //do loop for 1 Btagged Loose x = 0.679;
	  x = 0.244;
	  if(j1pt>minPt&&J1CSVbtag>x&&fabs(j1eta)<2.4){
	    i+=1;
	    if(fabs(J1Parton)==5||fabs(J1Parton)==4){
	      if((topType) == 1 ){
		effCSV1 = 1.01;
	      }
	      else{
		effCSV1 = 1.02658*(1+0.0195388*j1pt)/(1+(0.0209145*j1pt));
	      }
	    }
	    else{
	      fakeCSV1 = LightLookupCSVL(j1pt, j1eta);
	    }
	  }

	  if(j2pt>minPt&&J2CSVbtag>x&&fabs(j2eta)<2.4){
	    if(fabs(J2Parton)==5||fabs(J2Parton)==4){
	      if((topType) == 1 ){
		effCSV2 = 1.01;
		if(effCSV1>0){SFCSVL1Jet =(effCSV1+effCSV2)/2; SFCSVL2Jet = effCSV1*effCSV2;}
		else if(fakeCSV1>0){SFCSVL1Jet =fakeCSV1*effCSV2; SFCSVL2Jet = fakeCSV1*effCSV2;}
		else SFCSVL1Jet = effCSV2;
	      }
	      else{
		effCSV2 = 1.02658*(1+0.0195388*j2pt)/(1+(0.0209145*j2pt));
		if(effCSV1>0){SFCSVL1Jet = (effCSV1+effCSV2)/2; SFCSVL2Jet = effCSV1*effCSV2;}
		else if(fakeCSV1>0){SFCSVL1Jet = fakeCSV1*effCSV2; SFCSVL2Jet = fakeCSV1*effCSV2;}
		else SFCSVL1Jet = effCSV2;
	      }
	    }
	    else { 
	      fakeCSV2 = LightLookupCSVL(j2pt, j2eta);
	      if(effCSV1>0){ SFCSVL1Jet =(effCSV1*fakeCSV2); SFCSVL2Jet = fakeCSV2*effCSV1;}
	      else if(fakeCSV1>0){SFCSVL1Jet =(fakeCSV1+fakeCSV2)/2; SFCSVL2Jet = fakeCSV1*fakeCSV2;}
	      else {SFCSVL1Jet = fakeCSV2;}

	    }
	  }
	  else if(fakeCSV1>0) SFCSVL1Jet = fakeCSV1;
	  else if(effCSV1>0) SFCSVL1Jet = effCSV1;

	  //if(J1CSVbtag>0.244)
	  //printf("Pt:%f %f btag:%f %f SF:%f %f \n",j1pt,j2pt,J1CSVbtag,J2CSVbtag,SFCSVL1Jet,SFCSVL2Jet);	  

	  CSVLEff1Jet->Fill();
	  CSVLEff2Jets->Fill();

	}


      //////////////////////////////////////////////////////////////CSVMedium


      printf("\nNow looking at Medium CSV\n");
      for(Int_t k=0;k<t->GetEntries();++k)
	{
	  t->GetEntry(k);
	  i = 0;effCSVM=1;effCSV1 = 0;effCSV2 = 0; effCSVT2J = 1; effCSV1_2j = 1; effCSV2_2j = 1;
	  j = 0;fakeCSVM=1;fakeCSV1 = 0; fakeCSV2 = 0; effCSVT2J = 1; effCSV1_2j = 1; effCSV2_2j = 1;
	  SFCSVM1Jet =1;
	  SFCSVM2Jet =1;
	  //do loop for 1 Btagged Loose x = 0.679;
	  x = 0.679;
	  if(j1pt>minPt&&J1CSVbtag>x&&fabs(j1eta)<2.4){
	    i+=1;
	    if(fabs(J1Parton)==5||fabs(J1Parton)==4){
	      if((topType) == 1 ){
		effCSV1 = 0.97;
	      }
	      else{
		effCSV1 = 0.6981*((1.+(0.414063*j1pt))/(1.+(0.300155*j1pt)));
	      }
	    }
	    else{
	      fakeCSV1 = LightLookupCSVM(j1pt, j1eta);
	    }
	  }

	  if(j2pt>minPt&&J2CSVbtag>x&&fabs(j2eta)<2.4){
	    if(fabs(J2Parton)==5||fabs(J2Parton)==4){
	      if((topType) == 1 ){
		effCSV2 = 0.97;
		if(effCSV1>0){SFCSVM1Jet =(effCSV1+effCSV2)/2; SFCSVM2Jet = effCSV1*effCSV2;}
		else if(fakeCSV1>0){SFCSVM1Jet =fakeCSV1*effCSV2; SFCSVM2Jet = fakeCSV1*effCSV2;}
		else SFCSVM1Jet = effCSV2;
	      }
	      else{
		effCSV2 = 0.6981*((1.+(0.414063*j2pt))/(1.+(0.300155*j2pt))); 
		if(effCSV1>0){SFCSVM1Jet = (effCSV1+effCSV2)/2; SFCSVM2Jet = effCSV1*effCSV2;}
		else if(fakeCSV1>0){SFCSVM1Jet = fakeCSV1*effCSV2; SFCSVM2Jet = fakeCSV1*effCSV2;}
		else SFCSVM1Jet = effCSV2;
	      }
	    }
	    else { 
	      fakeCSV2 = LightLookupCSVM(j2pt, j2eta);
	      if(effCSV1>0){ SFCSVM1Jet =(effCSV1*fakeCSV2); SFCSVM2Jet = fakeCSV2*effCSV1;}
	      else if(fakeCSV1>0){SFCSVM1Jet =(fakeCSV1+fakeCSV2)/2; SFCSVM2Jet = fakeCSV1*fakeCSV2;}
	      else {SFCSVM1Jet = fakeCSV2;}

	    }
	  }
	  else if(fakeCSV1>0) SFCSVM1Jet = fakeCSV1;
	  else if(effCSV1>0) SFCSVM1Jet = effCSV1;

	  CSVMEff1Jet->Fill();
	  CSVMEff2Jets->Fill();


	}

      //////////////////////////////////////////////////////////////CSVMedium
      printf("\nNow looking at Tight CSV\n");
      for(Int_t k=0;k<t->GetEntries();++k)
	{
	  t->GetEntry(k);
	  i = 0;effCSVT=1;effCSV1 = 0;effCSV2 = 0; effCSVT2J = 1; effCSV1_2j = 1; effCSV2_2j = 1;
	  j = 0;fakeCSVT=1;fakeCSV1 = 0; fakeCSV2 = 0; effCSVT2J = 1; effCSV1_2j = 1; effCSV2_2j = 1;
	  SFCSVT1Jet =1;
	  SFCSVT2Jet =1;
	  //do loop for 1 Btagged Loose x = 0.679;
	  x = 0.898;
	  if(j1pt>minPt&&J1CSVbtag>x&&fabs(j1eta)<2.4){
	    i+=1;
	    if(fabs(J1Parton)==5||fabs(J1Parton)==4){
	      if((topType) == 1 ){
		effCSV1 = 0.96;
	      }
	      else{
		effCSV1 = 0.901615*(1+0.552628*j1pt)/(1+(0.547195*j1pt)); 

	      }
	    }
	    else{
	      fakeCSV1 = LightLookupCSVT(j1pt, j1eta);
	    }
	  }

	  if(j2pt>minPt&&J2CSVbtag>x&&fabs(j2eta)<2.4){
	    if(fabs(J2Parton)==5||fabs(J2Parton)==4){
	      if((topType) == 1 ){
		effCSV2 = 0.96;
		if(effCSV1>0){SFCSVT1Jet =(effCSV1+effCSV2)/2; SFCSVT2Jet = effCSV1*effCSV2;}
		else if(fakeCSV1>0){SFCSVT1Jet =fakeCSV1*effCSV2; SFCSVT2Jet = fakeCSV1*effCSV2;}
		else SFCSVT1Jet = effCSV2;
	      }
	      else{
		effCSV2 = 0.901615*(1+0.552628*j2pt)/(1+(0.547195*j2pt)); 
		if(effCSV1>0){SFCSVT1Jet =(effCSV1+effCSV2)/2; SFCSVT2Jet = effCSV1*effCSV2;}
		else if(fakeCSV1>0){SFCSVT1Jet =fakeCSV1*effCSV2; SFCSVT2Jet = fakeCSV1*effCSV2;}
		else SFCSVT1Jet = effCSV2;
	      }
	    }
	    else{
	      fakeCSV2 = LightLookupCSVT(j2pt, j2eta);
	      if(effCSV1>0){SFCSVT1Jet =(effCSV1*fakeCSV2); SFCSVT2Jet = fakeCSV2*effCSV1;}
	      else if(fakeCSV1>0){SFCSVT1Jet =(fakeCSV1+fakeCSV2)/2; SFCSVT2Jet = fakeCSV1*fakeCSV2;}
	      else SFCSVT1Jet = fakeCSV2;
	    }
	  }
	  else if(fakeCSV1>0) SFCSVT1Jet = fakeCSV1;
	  else if(effCSV1>0) SFCSVT1Jet = effCSV1;

	  //if(J1CSVbtag>0.898)
	  //printf("Pt:%f %f btag:%f %f SF:%f %f \n",j1pt,j2pt,J1CSVbtag,J2CSVbtag,SFCSVT1Jet,SFCSVT2Jet);	  


	  CSVTEff1Jet->Fill();
	  CSVTEff2Jets->Fill();

	}


      printf("\nNow looking at Medium SSVHE\n");
      for(Int_t k=0;k<t->GetEntries();++k)
	{
	  t->GetEntry(k);
	  i = 0;effCSVM=1;effCSV1 = 0;effCSV2 = 0; effCSVT2J = 1; effCSV1_2j = 1; effCSV2_2j = 1;
	  j = 0;fakeCSVM=1;fakeCSV1 = 0; fakeCSV2 = 0; effCSVT2J = 1; effCSV1_2j = 1; effCSV2_2j = 1;
	  SFSSVHEM1Jet =1;
	  SFSSVHEM2Jet =1;
	  //do loop for 1 Btagged Loose x = 0.679;
	  x = 0;
	  if(j1pt>minPt&&J1SSVHEbtag>x&&fabs(j1eta)<2.4){
	    i+=1;
	    if(fabs(J1Parton)==5||fabs(J1Parton)==4){
	      if((topType) == 1 ){
		effCSV1 = 0.96;
	      }
	      else{
		effCSV1 = 0.896462*((1.+(0.00957275*j1pt))/(1.+(0.00837582*j1pt)));}
	    }
	    else{
	      fakeCSV1 = LightLookupSSVHEM(j1pt, j1eta);
	    }
	  }

	  if(j2pt>minPt&&J2SSVHEbtag>x&&fabs(j2eta)<2.4){
	    if(fabs(J2Parton)==5||fabs(J2Parton)==4){
	      if((topType) == 1 ){
		effCSV2 = 0.96;
		if(effCSV1>0){SFSSVHEM1Jet =(effCSV1+effCSV2)/2; SFSSVHEM2Jet = effCSV1*effCSV2;}
		else if(fakeCSV1>0){SFSSVHEM1Jet =fakeCSV1*effCSV2; SFSSVHEM2Jet = fakeCSV1*effCSV2;}
		else SFSSVHEM1Jet = effCSV2;
	      }
	      else{
		effCSV2 =0.896462*((1.+(0.00957275*j2pt))/(1.+(0.00837582*j2pt)));
		if(effCSV1>0){SFSSVHEM1Jet = (effCSV1+effCSV2)/2; SFSSVHEM2Jet = effCSV1*effCSV2;}
		else if(fakeCSV1>0){SFSSVHEM1Jet = fakeCSV1*effCSV2; SFSSVHEM2Jet = fakeCSV1*effCSV2;}
		else SFSSVHEM1Jet = effCSV2;
	      }
	    }
	    else { 
	      fakeCSV2 = LightLookupSSVHEM(j2pt, j2eta);
	      if(effCSV1>0){ SFSSVHEM1Jet =(effCSV1*fakeCSV2); SFSSVHEM2Jet = fakeCSV2*effCSV1;}
	      else if(fakeCSV1>0){SFSSVHEM1Jet =(fakeCSV1+fakeCSV2)/2; SFSSVHEM2Jet = fakeCSV1*fakeCSV2;}
	      else {SFSSVHEM1Jet = fakeCSV2;}
	    }
	  }
	  else if(fakeCSV1>0) SFSSVHEM1Jet = fakeCSV1;
	  else if(effCSV1>0) SFSSVHEM1Jet = effCSV1;

	  //if(fakeCSV1>0||effCSV1>0)
	  //  printf("Pt:%f %f btag:%f %f SF:%f %f \n",j1pt,j2pt,J1SSVHEbtag,J2SSVHEbtag,SFSSVHEM1Jet,SFSSVHEM2Jet);	  

	  SSVHEMEff1Jet->Fill();
	  SSVHEMEff2Jets->Fill();
	}
	  


      t->Write("",TObject::kOverwrite);
      return;
    }
  }
}



float LightLookupCSVM(float pt, float eta){
  if(fabs(eta)>0&&fabs(eta)<0.8)
    {//mean
      return ((1.06182+(0.000617034*pt))+(-1.5732e-06*(pt*pt)))+(3.02909e-10*(pt*(pt*pt)));
      //min (0.972455+(7.51396e-06*pt))+(4.91857e-07*(pt*pt)))+(-1.47661e-09*(pt*(pt*pt)))
      //max (1.15116+(0.00122657*pt))+(-3.63826e-06*(pt*pt)))+(2.08242e-09*(pt*(pt*pt)))
    }
  else if(fabs(eta)>0.8&&fabs(eta)<1.6)
    {
      //mean
      return ((1.111+(-9.64191e-06*pt))+(1.80811e-07*(pt*pt)))+(-5.44868e-10*(pt*(pt*pt)));
      //min ((1.02055+(-0.000378856*x))+(1.49029e-06*(x*x)))+(-1.74966e-09*(x*(x*x)))
      //max ((1.20146+(0.000359543*x))+(-1.12866e-06*(x*x)))+(6.59918e-10*(x*(x*x)))
    }
  else if( fabs(eta)>1.6 && fabs(eta)<2.4)
    {//mean
      return ((1.08498+(-0.000701422*pt))+(3.43612e-06*(pt*pt)))+(-4.11794e-09*(pt*(pt*pt)));
      //min ((0.983476+(-0.000607242*x))+(3.17997e-06*(x*x)))+(-4.01242e-09*(x*(x*x)));
      //max ((1.18654+(-0.000795808*x))+(3.69226e-06*(x*x)))+(-4.22347e-09*(x*(x*x)));
    }
    return 0;
}

float LightLookupCSVL(float pt, float eta){

  if(fabs(eta)>0.0&&fabs(eta)<0.5){//mean

    return (float) ((1.07536+(0.000175506*pt))+(-8.63317e-07*(pt*pt)))+(3.27516e-10*(pt*(pt*pt)));
    //min((0.994425+(-8.66392e-05*pt))+(-3.03813e-08*(pt*pt)))+(-3.52151e-10*(pt*(pt*pt)));
    //max((1.15628+(0.000437668*pt))+(-1.69625e-06*(pt*pt)))+(1.00718e-09*(pt*(pt*pt)));

  }
  else if( fabs(eta)>0.5 && fabs(eta)<1.0){//mean

    return (float) ((1.07846+(0.00032458*pt))+(-1.30258e-06*(pt*pt)))+(8.50608e-10*(pt*(pt*pt)));
    //min((0.998088+(6.94916e-05*pt))+(-4.82731e-07*(pt*pt)))+(1.63506e-10*(pt*(pt*pt)));
    //max((1.15882+(0.000579711*pt))+(-2.12243e-06*(pt*pt)))+(1.53771e-09*(pt*(pt*pt)));
  }
  else if( fabs(eta)>1.0 && fabs(eta)<1.5){//mean

    return (float) ((1.08294+(0.000474818*pt))+(-1.43857e-06*(pt*pt)))+(1.13308e-09*(pt*(pt*pt)));
    //min ((1.00294+(0.000289844*pt))+(-7.9845e-07*(pt*pt)))+(5.38525e-10*(pt*(pt*pt)));
    //max ((1.16292+(0.000659848*pt))+(-2.07868e-06*(pt*pt)))+(1.72763e-09*(pt*(pt*pt)));
  }
  else if( fabs(eta)>1.5 && fabs(eta)<2.4){//mean

    return (float) ((1.0617+(0.000173654*pt))+(-5.29009e-07*(pt*pt)))+(5.55931e-10*(pt*(pt*pt)));
    //min ((0.979816+(0.000138797*x))+(-3.14503e-07*(x*x)))+(2.38124e-10*(x*(x*x)));
    //mean((1.14357+(0.00020854*x))+(-7.43519e-07*(x*x)))+(8.73742e-10*(x*(x*x)));
  }

  return 0;
}

float LightLookupCSVT(float pt, float eta){
	if(fabs(eta) >0.0 && fabs(eta)<2.4){
	  return (float) ((0.948463+(0.00288102*pt))+(-7.98091e-06*(pt*pt)))+(5.50157e-09*(pt*(pt*pt)));
	  //min ((0.899715+(0.00102278*x))+(-2.46335e-06*(x*x)))+(9.71143e-10*(x*(x*x)));
	  //max ((0.997077+(0.00473953*x))+(-1.34985e-05*(x*x)))+(1.0032e-08*(x*(x*x)));
	}
	return 0;
}

float LightLookupJPL(float pt, float eta){
  if( fabs(eta)> 0.0 && fabs(eta)<0.5){
    return (float) ((1.02571+(-0.000391686*pt))+(1.01948e-06*(pt*pt)))+(-1.16475e-09*(pt*(pt*pt)));
    //min ((0.931859+(-0.00045457*x))+(1.25431e-06*(x*x)))+(-1.36433e-09*(x*(x*x)));
    //max ((1.11958+(-0.00032886*x))+(7.84649e-07*(x*x)))+(-9.65161e-10*(x*(x*x)));
  }	
  else if(fabs(eta)>0.5 && fabs(eta)<1.0){
    return (float) ((1.03375+(-0.00068776*pt))+(2.13443e-06*(pt*pt)))+(-2.24163e-09*(pt*(pt*pt)));
    //min ((0.936905+(-0.000681017*x))+(2.13885e-06*(x*x)))+(-2.22607e-09*(x*(x*x)));
    //max ((1.13063+(-0.000694616*x))+(2.13001e-06*(x*x)))+(-2.25719e-09*(x*(x*x)));		
  }
  else if(fabs(eta)>1.0 && fabs(eta)<1.5){
    return (float) ((1.03597+(-0.000778058*pt))+(3.02129e-06*(pt*pt)))+(-3.0478e-09*(pt*(pt*pt)));
    //min ((0.938438+(-0.00074623*x))+(2.89732e-06*(x*x)))+(-2.92483e-09*(x*(x*x)));
    //mean ((1.13355+(-0.000810039*x))+(3.14525e-06*(x*x)))+(-3.17077e-09*(x*(x*x)));
  }
  else if( fabs(eta)>1.5 && fabs(eta)<2.4){
    return (float)((0.95897+(-0.000111286*pt))+(1.6091e-06*(pt*pt)))+(-2.18387e-09*(pt*(pt*pt)));
    //min ((0.867768+(-9.92078e-05*x))+(1.46903e-06*(x*x)))+(-2.02118e-09*(x*(x*x)));
    //max ((1.0502+(-0.000123474*x))+(1.74917e-06*(x*x)))+(-2.34655e-09*(x*(x*x)));
  }
  return 0;
}

float LightLookupJPM(float pt, float eta){
  if(fabs(eta)>0.0 && fabs(eta)<0.8){
    return (float)((0.970028+(0.00118179*pt))+(-4.23119e-06*(pt*pt)))+(3.61065e-09*(pt*(pt*pt)));
    //min ((0.840326+(0.000626372*x))+(-2.08293e-06*(x*x)))+(1.57604e-09*(x*(x*x)));
     //max ((1.09966+(0.00173739*x))+(-6.37946e-06*(x*x)))+(5.64527e-09*(x*(x*x)));
  }
  if( fabs(eta)>0.8 && fabs(eta)<1.6){
    return (float)((0.918387+(0.000898595*pt))+(-2.00643e-06*(pt*pt)))+(1.26486e-09*(pt*(pt*pt)));
    //min ((0.790843+(0.000548016*x))+(-6.70941e-07*(x*x)))+(1.90355e-11*(x*(x*x)));
    //max ((1.0459+(0.00124924*x))+(-3.34192e-06*(x*x)))+(2.51068e-09*(x*(x*x)));
  }
  if( fabs(eta)>1.6 && fabs(eta)<2.4){
    return (float) ((0.790103+(0.00117865*pt))+(-2.07334e-06*(pt*pt)))+(1.42608e-09*(pt*(pt*pt)));
    //min ((0.667144+(0.00105593*x))+(-1.43608e-06*(x*x)))+(5.24039e-10*(x*(x*x)));
    //max ((0.913027+(0.00130143*x))+(-2.71061e-06*(x*x)))+(2.32812e-09*(x*(x*x)));
  }
  return 0;
}

float LightLookupJPT(float pt, float eta){
  return (float)((0.831392+(0.00269525*pt))+(-7.33391e-06*(pt*pt)))+(5.73942e-09*(pt*(pt*pt)));
  //min ((0.671888+(0.0020106*x))+(-5.03177e-06*(x*x)))+(3.74225e-09*(x*(x*x)));
  //max ((0.990774+(0.00338018*x))+(-9.63606e-06*(x*x)))+(7.73659e-09*(x*(x*x)));

}

float LightLookupSSVHEM(float pt, float eta){
  if( fabs(eta)>0.0 && fabs(eta)<0.8){
    return (float)((0.86318+(0.000801639*pt))+(-1.64119e-06*(pt*pt)))+(2.59121e-10*(pt*(pt*pt)));
    //min((0.790364+(0.000463086*pt))+(-4.35934e-07*(pt*pt)))+(-9.08296e-10*(pt*(pt*pt)))
    //max ((0.935969+(0.0011402*pt))+(-2.84645e-06*(pt*pt)))+(1.42654e-09*(pt*(pt*pt)))
    
  }
  else if( fabs(eta)>0.8 && fabs(eta)<1.6){
    return (float)((0.958973+(-0.000269555*pt))+(1.381e-06*(pt*pt)))+(-1.87744e-09*(pt*(pt*pt)));
    //min((0.865771+(-0.000279908*pt))+(1.34144e-06*(pt*pt)))+(-1.75588e-09*(pt*(pt*pt)))
    //max((1.0522+(-0.000259296*pt))+(1.42056e-06*(pt*pt)))+(-1.999e-09*(pt*(pt*pt)))
  }
  else if( fabs(eta)>1.6 && fabs(eta)<2.4){
    return (float)((0.923033+(-0.000898227*pt))+(4.74565e-06*(pt*pt)))+(-6.11053e-09*(pt*(pt*pt)));
    //min((0.828021+(-0.000731926*pt))+(4.19613e-06*(pt*pt)))+(-5.81379e-09*(pt*(pt*pt)))
    //max((1.01812+(-0.00106483*pt))+(5.29518e-06*(pt*pt)))+(-6.40728e-09*(pt*(pt*pt)))
  }
    return 0;   
}

float LightLookupSSVHPT(float pt, float eta){

  return (float) ((0.97409+(0.000646241*pt))+(-2.86294e-06*(pt*pt)))+(2.79484e-09*(pt*(pt*pt)));
  //min((0.807222+(0.00103676*pt))+(-3.6243e-06*(pt*pt)))+(3.17368e-09*(pt*(pt*pt)))", 20.,670.);
  //max((1.14091+(0.00025586*pt))+(-2.10157e-06*(pt*pt)))+(2.41599e-09*(pt*(pt*pt)))", 20.,670.);
}


