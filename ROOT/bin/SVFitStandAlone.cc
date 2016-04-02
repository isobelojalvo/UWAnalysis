#include "PhysicsTools/FWLite/interface/CommandLineParser.h" 
#include "TFile.h"
#include "TROOT.h"
#include "TLorentzVector.h"
#include "TKey.h"
#include "TTree.h"
#include "TH1F.h"
#include "TF1.h"
#include <math.h> 
#include "TMath.h" 
#include <limits>
#include "TSystem.h"

#include "FWCore/ParameterSet/interface/FileInPath.h"

#include "TauAnalysis/SVfitStandalone/interface/SVfitStandaloneAlgorithm.h"
#include "HTT-utilities/RecoilCorrections/interface/RecoilCorrector.h"

#include "TFile.h"
#include "TTree.h"
#include "TH1.h"

//If recoilType 0 then don't do recoil
//              1 then aMC@NLO DY and W+Jets MC samples
//              2 MG5 DY and W+Jets MC samples or Higgs MC samples

void copyFiles( optutl::CommandLineParser parser, TFile* fOld, TFile* fNew) ;
void readdir(TDirectory *dir, optutl::CommandLineParser parser, char TreeToUse[], int recoilType) ;
void CopyFile(const char *fname, optutl::CommandLineParser parser);
void CopyDir(TDirectory *source,optutl::CommandLineParser parser);
void runSVFit(std::vector<svFitStandalone::MeasuredTauLepton> & measuredTauLeptons, double measuredMETx, double measuredMETy, TMatrixD &covMET, float num, float &svFitMass, float& svFitPt, float &svFitEta, float &svFitPhi, float &svFitMET);

int main (int argc, char* argv[]) 
{
   optutl::CommandLineParser parser ("Sets Event Weights in the ntuple");
   parser.addOption("branch",optutl::CommandLineParser::kString,"Branch","__svFit__");
   parser.addOption("newFile",optutl::CommandLineParser::kString,"newFile","newFile");
   parser.addOption("newOutputFile",optutl::CommandLineParser::kDouble,"New Output File",0.0);
   parser.addOption("recoilType",optutl::CommandLineParser::kDouble,"recoilType",0.0);

   parser.parseArguments (argc, argv);
   
   char TreeToUse[80]="first" ;

   TFile *fProduce;//= new TFile(parser.stringValue("newFile").c_str(),"UPDATE");

   if(parser.doubleValue("newOutputFile")>0){
   TFile *f = new TFile(parser.stringValue("outputFile").c_str(),"READ");
     std::cout<<"Creating new outputfile"<<std::endl;
     std::string newFileName = parser.stringValue("newFile");

     fProduce = new TFile(newFileName.c_str(),"RECREATE");
     copyFiles(parser, f, fProduce);//new TFile(parser.stringValue("outputFile").c_str()+"SVFit","UPDATE");
     fProduce = new TFile(newFileName.c_str(),"UPDATE");
     std::cout<<"listing the directories================="<<std::endl;
     fProduce->ls();
     readdir(fProduce,parser,TreeToUse,parser.doubleValue("recoilType"));
     fProduce->Close();
     f->Close();
   }
   else{
     TFile *f = new TFile(parser.stringValue("outputFile").c_str(),"UPDATE");
     readdir(f,parser,TreeToUse,parser.doubleValue("recoilType"));
     f->Close();
   }


} 


void readdir(TDirectory *dir, optutl::CommandLineParser parser, char TreeToUse[], int recoilType) 
{
  std::string recoilFileName = "";
  if(recoilType == 1) //amc@nlo
    recoilFileName = "HTT-utilities/RecoilCorrections/data/recoilMvaMEt_76X_newTraining.root";
  if(recoilType == 2) //MG5
    recoilFileName = "HTT-utilities/RecoilCorrections/data/recoilMvaMEt_76X_newTraining_MG5.root";

  TDirectory *dirsav = gDirectory;
  TIter next(dir->GetListOfKeys());
  TKey *key;
  char stringA[80]="first";
  dir->cd();      
  while ((key = (TKey*)next())) {
    printf("Found key=%s \n",key->GetName());

    TObject *obj = key->ReadObj();
    if (obj->IsA()->InheritsFrom(TDirectory::Class())) {
      dir->cd(key->GetName());
      TDirectory *subdir = gDirectory;
      sprintf(TreeToUse,"%s",key->GetName());
      readdir(subdir,parser,TreeToUse,parser.doubleValue("recoilType"));
      dirsav->cd();
    }
    else if(obj->IsA()->InheritsFrom(TTree::Class())) {
      // use this RooT file when running on aMC@NLO DY and W+Jets MC samples
      RecoilCorrector recoilMvaMetCorrector(recoilFileName);

      TTree *t = (TTree*)obj;
      float svFitMass = -10;
      float svFitPt = -10;
      float svFitEta = -10;
      float svFitPhi = -10;
      float svFitMET = -10;

      float mvametcorr_ex=-10; // corrected met px (float)
      float mvametcorr_ey=10;  // corrected met py (float)

      //TBranch *newBranch = t->Branch(parser.stringValue("branch").c_str(),&svFitMass,(parser.stringValue("branch")+"/F").c_str());
      TBranch *newBranch1 = t->Branch("m_sv", &svFitMass, "m_sv/F");
      TBranch *newBranch2 = t->Branch("p_sv", &svFitPt, "pt_sv/F");
      TBranch *newBranch3 = t->Branch("eta_sv", &svFitEta, "eta_sv/F");
      TBranch *newBranch4 = t->Branch("phi_sv", &svFitPhi, "phi_sv/F");
      TBranch *newBranch5 = t->Branch("met_sv", &svFitMET, "met_sv/F");

      TBranch *newBranch6 = t->Branch("mvametcorr_ex", &mvametcorr_ex, "mvametcorr_ex/F");
      TBranch *newBranch7 = t->Branch("mvametcorr_ey", &mvametcorr_ey, "mvametcorr_ey/F");

      unsigned int evt, run, lumi;
      float pt1;
      float eta1;
      float phi1;
      float pt2;
      float eta2;
      float phi2;
      float m2;
      float decayMode;
      float decayMode2;
      float covMatrix00;
      float covMatrix10;
      float covMatrix01;
      float covMatrix11;
      float mvamet_ex, // uncorrected mva met px (float)
	    mvamet_ey, // uncorrected mva met py (float)
	    genPx    , // generator Z/W/Higgs px (float)
	    genPy    , // generator Z/W/Higgs py (float)
	    visPx    , // generator visible Z/W/Higgs px (float)
	    visPy    , // generator visible Z/W/Higgs py (float)
	    njets    ;  // number of jets (hadronic jet multiplicity) (int)

      // define MET
      double measuredMETx;
      double measuredMETy;
      float met;
      float metphi;
      TLorentzVector TMet(0,0,0,0);
      // define MET covariance
      TMatrixD covMET(2, 2);
      //ele/mu variables
      svFitStandalone::kDecayType decayType1 = svFitStandalone::kUndefinedDecayType; //svFitStandalone::kTauToElecDecay
      svFitStandalone::kDecayType decayType2 = svFitStandalone::kUndefinedDecayType; //svFitStandalone::kTauToElecDecay
      // Both masses should depend on decay mode and particle?
      float mass1;
      float mass2;
      std::string channel = "x";
      if(std::string(TreeToUse).find("muTauEvent")!= std::string::npos){
	decayType1 = svFitStandalone::kTauToMuDecay;
	decayType2 = svFitStandalone::kTauToHadDecay; 
	mass1 = 0.105658;
	mass2 = 0;
	channel = "mt";
      }
      else if(std::string(TreeToUse).find("eleTauEvent")!= std::string::npos){
	std::cout<<"eleTauTree"<<std::endl;
	decayType1 = svFitStandalone::kTauToElecDecay;
	decayType2 = svFitStandalone::kTauToHadDecay;
	mass1 = 0.00051100;
	mass2 = 0;
	channel = "et";
      }
      //else if(parser.stringValue("outputFile").find("_em.root") != std::string::npos){
      else if(std::string(TreeToUse).find("em")!= std::string::npos){
        //std::cout<< parser.stringValue("outputFile").c_str() << std::endl;
        std::cout<< "EMu sample" <<std::endl;
	decayType1 = svFitStandalone::kTauToElecDecay;
	decayType2 = svFitStandalone::kTauToMuDecay;
	mass1 = 0.00051100;
	mass2 = 0;
	channel = "em";
      }
      //else if(parser.stringValue("outputFile").find("_tt.root") != std::string::npos){
      else if(std::string(TreeToUse).find("tt")!= std::string::npos){
        //std::cout<< parser.stringValue("outputFile").c_str() << std::endl;
        std::cout<< "Double Hadronic sample" <<std::endl;
	decayType1 = svFitStandalone::kTauToHadDecay;
	decayType2 = svFitStandalone::kTauToHadDecay;
	mass1 = 0.13957;
	mass2 = 0.13957;
	channel = "tt";
      }
      else{
	std::cout<<"TreeToUse "<< std::string(TreeToUse)<<" does not match muTauEvent or eleTauEvent... Skipping!!"<<std::endl;
	continue;
      }
      
      //MET, MET Covariance, lepton objects,
      TBranch *pt1branch;
      //TBranch *newBranch = t->Branch(parser.stringValue("branch").c_str(),&svFitMass,(parser.stringValue("branch")+"/F").c_str());
      //newBranch->SetFile("svfitout.root:/input/muTauEventTree");

      if(channel=="tt") {
        t->SetBranchAddress("t1Pt",&pt1,&pt1branch);
        t->SetBranchAddress("t1Eta",&eta1);
        t->SetBranchAddress("t1Phi",&phi1);
        t->SetBranchAddress("t2Pt",&pt2);
        t->SetBranchAddress("t2Eta",&eta2);
        t->SetBranchAddress("t2Phi",&phi2);
        t->SetBranchAddress("t1DecayMode",&decayMode);
        t->SetBranchAddress("t2DecayMode",&decayMode2);/*

        t->SetBranchAddress("mvaMetCov00",&covMatrix00);
        t->SetBranchAddress("mvaMetCov01",&covMatrix01);
        t->SetBranchAddress("mvaMetCov10",&covMatrix10);
        t->SetBranchAddress("mvaMetCov11",&covMatrix11);
	t->SetBranchAddress("mvaMetEt",&met);
	t->SetBranchAddress("mvaMetPhi",&metphi);
 mvaMetCov00     = 267.274
 mvaMetCov01     = 193.226
 mvaMetCov10     = 193.226
 mvaMetCov11     = 336.776
 mvaMetEt        = 30.5186
 mvaMetPhi       = -0.874371*/
        t->SetBranchAddress("t1_t2_TTpairMvaMetCovMatrix00",&covMatrix00);
        t->SetBranchAddress("t1_t2_TTpairMvaMetCovMatrix01",&covMatrix01);
        t->SetBranchAddress("t1_t2_TTpairMvaMetCovMatrix10",&covMatrix10);
        t->SetBranchAddress("t1_t2_TTpairMvaMetCovMatrix11",&covMatrix11);
        t->SetBranchAddress("t1_t2_TTpairMvaMet",&met);
        t->SetBranchAddress("t1_t2_TTpairMvaMetPhi",&metphi);

      }

      else if(channel=="em") {
        t->SetBranchAddress("ePt",&pt1,&pt1branch);
        t->SetBranchAddress("eEta",&eta1);
        t->SetBranchAddress("ePhi",&phi1);
        t->SetBranchAddress("mPt",&pt2);
        t->SetBranchAddress("mEta",&eta2);
        t->SetBranchAddress("mPhi",&phi2);/*
        t->SetBranchAddress("mvaMetCov00",&covMatrix00);
        t->SetBranchAddress("mvaMetCov01",&covMatrix01);
        t->SetBranchAddress("mvaMetCov10",&covMatrix10);
        t->SetBranchAddress("mvaMetCov11",&covMatrix11);
	t->SetBranchAddress("mvaMetEt",&met);
	t->SetBranchAddress("mvaMetPhi",&metphi);
*/
	
        t->SetBranchAddress("e_m_EMpairMvaMetCovMatrix00",&covMatrix00);
        t->SetBranchAddress("e_m_EMpairMvaMetCovMatrix01",&covMatrix01);
        t->SetBranchAddress("e_m_EMpairMvaMetCovMatrix10",&covMatrix10);
        t->SetBranchAddress("e_m_EMpairMvaMetCovMatrix11",&covMatrix11);
        t->SetBranchAddress("e_m_EMpairMvaMet",&met);
        t->SetBranchAddress("e_m_EMpairMvaMetPhi",&metphi);
      }
      else {
	t->SetBranchAddress("EVENT",&evt);
	t->SetBranchAddress("run",&run);
	t->SetBranchAddress("lumi",&lumi);
        t->SetBranchAddress("pt_1",&pt1,&pt1branch);
        t->SetBranchAddress("eta_1",&eta1);
        t->SetBranchAddress("phi_1",&phi1);
        t->SetBranchAddress("pt_2",&pt2);
        t->SetBranchAddress("eta_2",&eta2);
        t->SetBranchAddress("phi_2",&phi2);
        t->SetBranchAddress("m_2",&m2);
        t->SetBranchAddress("tauDecayMode",&decayMode);
        t->SetBranchAddress("t2DecayMode",&decayMode2);
        t->SetBranchAddress("mvacov00",&covMatrix00);
        t->SetBranchAddress("mvacov01",&covMatrix01);
        t->SetBranchAddress("mvacov10",&covMatrix10);
        t->SetBranchAddress("mvacov11",&covMatrix11);
        t->SetBranchAddress("mvamet",&met);
        t->SetBranchAddress("mvametphi",&metphi);
      }
      //Check me mvamet_ex?
      t->SetBranchAddress( "mvamet_ex",&mvamet_ex);
      t->SetBranchAddress( "mvamet_ey",&mvamet_ey);
      t->SetBranchAddress( "genPx", &genPx);
      t->SetBranchAddress( "genPy", &genPy);
      t->SetBranchAddress( "visPx", &visPx);
      t->SetBranchAddress( "visPy", &visPy);
      t->SetBranchAddress( "njets", &njets);

      printf("Found tree -> weighting\n");
      for(Int_t i=0;i<t->GetEntries();++i)
	{
	  t->GetEntry(i);
	  TMet.SetPtEtaPhiM(met,0,metphi,0);
	  
	  measuredMETx = met*TMath::Cos(metphi);
	  measuredMETy = met*TMath::Sin(metphi);
	  //Recoil Correction time
	  if(recoilType != 0){
	    recoilMvaMetCorrector.CorrectByMeanResolution(measuredMETx, // uncorrected mva met px (float)
							  measuredMETy, // uncorrected mva met py (float)
							  genPx, // generator Z/W/Higgs px (float)
							  genPy, // generator Z/W/Higgs py (float)
							  visPx, // generator visible Z/W/Higgs px (float)
							  visPy, // generator visible Z/W/Higgs py (float)
							  njets,  // number of jets (hadronic jet multiplicity) (int)
							  mvametcorr_ex, // corrected met px (float)
							  mvametcorr_ey  // corrected met py (float)
							  );}
	  else{
	    mvametcorr_ex = measuredMETx;
	    mvametcorr_ey = measuredMETy;
	  }


	  if(channel=="et" || channel=="mt"){
	    mass2 = m2;
	    if(decayMode==0)
	    mass2 = 0.13957;
	  }
	  //mods needed for tau tau here

	  covMET[0][0] =  covMatrix00;
	  covMET[1][0] =  covMatrix10;
	  covMET[0][1] =  covMatrix01;
	  covMET[1][1] =  covMatrix11;
	  //std::cout<<"getting decay mode "<< decayMode<<std::endl;
	  if(decayMode==0||decayMode==1||decayMode==10){
	    // define lepton four vectors
	    std::vector<svFitStandalone::MeasuredTauLepton> measuredTauLeptons;
	    // check if electron or muon
	    measuredTauLeptons.push_back(
		 svFitStandalone::MeasuredTauLepton(decayType1, pt1, eta1,  phi1, mass1)
					 ); // tau -> electron decay (Pt, eta, phi, mass)
	    
	    measuredTauLeptons.push_back(
	  	  svFitStandalone::MeasuredTauLepton(decayType2,  pt2, eta2, phi2,  mass2, decayMode)
	  				 ); // tau -> 1prong0pi0 hadronic decay (Pt, eta, phi, mass, pat::Tau.decayMode())
	    std::cout<< "evt: "<<evt<<" run: "<<run<<" lumi: "<<lumi<< " pt1 " << pt1 << " mass1 " << mass1 << " pt2: "<< pt2<< " mass2: "<< mass2 <<std::endl;        
	    //modified
	    runSVFit(measuredTauLeptons, mvametcorr_ex, mvametcorr_ey, covMET, 0, svFitMass, svFitPt, svFitEta, svFitPhi, svFitMET);
	    std::cout<<"finished runningSVFit"<<std::endl;
	    /*
	    SVfitStandaloneAlgorithm algo(measuredTauLeptons, measuredMETx, measuredMETy, covMET, 0);
	    algo.addLogM(false);  
	    algo.shiftVisPt(true, inputFile_visPtResolution);
	    algo.integrateMarkovChain();
	    svFitMass = algo.getMass(); // return value is in units of GeV
 	    svFitPt = algo.pt();
	    svFitEta = algo.eta();
	    svFitPhi = algo.phi();
	    svFitMET = algo.fittedMET().Rho();
	    if ( algo.isValidSolution() ) {

	      std::cout << "found mass = " << svFitMass << std::endl;
        }
	    else {
	      std::cout << "sorry -- status of NLL is not valid [" << algo.isValidSolution() << "]" << std::endl;
	    }
	    */
	  } // eTau / muTau

	  else if(channel=="em"){
	    // define lepton four vectors
	    std::vector<svFitStandalone::MeasuredTauLepton> measuredTauLeptons;
	    // check if electron or muon
	      measuredTauLeptons.push_back(
		   svFitStandalone::MeasuredTauLepton(decayType1, pt1, eta1,  phi1, mass1)
		  			 ); // tau -> electron decay (Pt, eta, phi, mass)
	    
	      measuredTauLeptons.push_back(
		   svFitStandalone::MeasuredTauLepton(decayType2,  pt2, eta2, phi2, mass2)
					 ); // tau -> 1prong0pi0 hadronic decay (Pt, eta, phi, mass, pat::Tau.decayMode())

	    SVfitStandaloneAlgorithm algo(measuredTauLeptons, measuredMETx, measuredMETy, covMET, 1);
	    algo.addLogM(false);  
	    //algo.shiftVisPt(true, inputFile_visPtResolution);
	    algo.integrateMarkovChain();
	    svFitMass = algo.getMass(); // return value is in units of GeV
	    svFitPt = algo.pt();
	    svFitEta = algo.eta();
	    svFitPhi = algo.phi();
	    svFitMET = algo.fittedMET().Rho();
	    if ( algo.isValidSolution() ) {
	      std::cout << "found mass = " << svFitMass << std::endl;
	    }
	    else {
	      std::cout << "sorry -- status of NLL is not valid [" << algo.isValidSolution() << "]" << std::endl;
	    }
	  } // eMu
	  else if(channel=="tt"){
	    // define lepton four vectors
	    std::vector<svFitStandalone::MeasuredTauLepton> measuredTauLeptons;
	    // check if electron or muon
	      measuredTauLeptons.push_back(
		   svFitStandalone::MeasuredTauLepton(decayType1, pt1, eta1,  phi1, mass1, decayMode)
		  			 ); // tau -> electron decay (Pt, eta, phi, mass)
	    
	      measuredTauLeptons.push_back(
	  	   svFitStandalone::MeasuredTauLepton(decayType2,  pt2, eta2, phi2,  mass2, decayMode2)
	  				 ); // tau -> 1prong0pi0 hadronic decay (Pt, eta, phi, mass, pat::Tau.decayMode())

	    SVfitStandaloneAlgorithm algo(measuredTauLeptons, measuredMETx, measuredMETy, covMET, 1);
	    algo.addLogM(false);  
	    //algo.shiftVisPt(true, inputFile_visPtResolution);
	    algo.integrateMarkovChain();
	    svFitMass = algo.getMass(); // return value is in units of GeV
	    if ( algo.isValidSolution() ) {
	      std::cout << "found mass = " << svFitMass << std::endl;
	  } else {
	      std::cout << "sorry -- status of NLL is not valid [" << algo.isValidSolution() << "]" << std::endl;
	    }
      } // Double Hadronic (TT)

	  else {
	    svFitMass = -100;
        svFitPt = -100;
        svFitEta = -100;
        svFitPhi = -100;
        svFitMET = -100;
      }
	  newBranch1->Fill();
	  newBranch2->Fill();
	  newBranch3->Fill();
	  newBranch4->Fill();
	  newBranch5->Fill();
	  newBranch6->Fill();
	  newBranch7->Fill();
	}
      dir->cd();
      t->Write("",TObject::kOverwrite);
      strcpy(TreeToUse,stringA) ;

    }
  }
}

void runSVFit(std::vector<svFitStandalone::MeasuredTauLepton> & measuredTauLeptons, double measuredMETx, double measuredMETy, TMatrixD &covMET, float num, float &svFitMass, float& svFitPt, float &svFitEta, float &svFitPhi, float &svFitMET){

  edm::FileInPath inputFileName_visPtResolution("TauAnalysis/SVfitStandalone/data/svFitVisMassAndPtResolutionPDF.root");
  TH1::AddDirectory(false);  
  TFile* inputFile_visPtResolution = new TFile(inputFileName_visPtResolution.fullPath().data());  
  //float svFitMass = 0;
  SVfitStandaloneAlgorithm algo(measuredTauLeptons, measuredMETx, measuredMETy, covMET, 0);
  algo.addLogM(false);  
  algo.shiftVisPt(true, inputFile_visPtResolution);
  algo.integrateMarkovChain();
  svFitMass = algo.getMass(); // return value is in units of GeV
  svFitPt = algo.pt();
  svFitEta = algo.eta();
  svFitPhi = algo.phi();
  svFitMET = algo.fittedMET().Rho();
  if ( algo.isValidSolution() ) {
    std::cout << "found mass = " << svFitMass << std::endl;
  } else {
    std::cout << "sorry -- status of NLL is not valid [" << algo.isValidSolution() << "]" << std::endl;
  }
  delete inputFile_visPtResolution;

}

//Thank you Renee Brun :)
void CopyDir(TDirectory *source, optutl::CommandLineParser parser) {
  //copy all objects and subdirs of directory source as a subdir of the current directory
  TDirectory *savdir = gDirectory;
  TDirectory *adir = savdir; 
  if(source->GetName()!=parser.stringValue("outputFile")){
    adir = savdir->mkdir(source->GetName());
    std::cout<<"Source name is not outputfile name"<<std::endl;
    adir->cd();    
  }
  else{
    //adir = savdir->mkdir("input");
    adir->cd();    
  }

  //loop on all entries of this directory
  TKey *key;
  TIter nextkey(source->GetListOfKeys());
  while ((key = (TKey*)nextkey())) {
    const char *classname = key->GetClassName();
    TClass *cl = gROOT->GetClass(classname);
    if (!cl) continue;
    if (cl->InheritsFrom(TDirectory::Class())) {
      source->cd(key->GetName());
      TDirectory *subdir = gDirectory;
      adir->cd();
      CopyDir(subdir,parser);
      adir->cd();
    } else if (cl->InheritsFrom(TTree::Class())) {
      TTree *T = (TTree*)source->Get(key->GetName());
      adir->cd();
      TTree *newT = T->CloneTree(-1,"fast");
      newT->Write();
    } else {
      source->cd();
      TObject *obj = key->ReadObj();
      adir->cd();
      obj->Write();
      delete obj;
    }
  }
  adir->SaveSelf(kTRUE);
  savdir->cd();
}
void CopyFile(const char *fname, optutl::CommandLineParser parser) {
  //Copy all objects and subdirs of file fname as a subdir of the current directory
  TDirectory *target = gDirectory;
  TFile *f = TFile::Open(fname);
  if (!f || f->IsZombie()) {
    printf("Cannot copy file: %s\n",fname);
    target->cd();
    return;
  }
  target->cd();
  CopyDir(f,parser);
  delete f;
  target->cd();
}
void copyFiles( optutl::CommandLineParser parser, TFile* fOld, TFile* fNew) 
{
  //prepare files to be copied
  if(gSystem->AccessPathName(parser.stringValue("outputFile").c_str())) {
    gSystem->CopyFile("hsimple.root", parser.stringValue("outputFile").c_str());
  }

  fNew->cd();
  CopyFile(parser.stringValue("outputFile").c_str(),parser);
  fNew->ls();
  fNew->Close();

}
