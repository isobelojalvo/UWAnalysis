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

#include "TFile.h"
#include "TTree.h"
#include "TH1.h"

void copyFiles( optutl::CommandLineParser parser, TFile* fOld, TFile* fNew) ;
void readdir(TDirectory *dir, optutl::CommandLineParser parser, char TreeToUse[]) ;
//void copyFiles( optutl::CommandLineParser parser, TFile* fOld, TFile* fNew);
void CopyFile(const char *fname, optutl::CommandLineParser parser);
void CopyDir(TDirectory *source,optutl::CommandLineParser parser);
float runSVFit(std::vector<svFitStandalone::MeasuredTauLepton> & measuredTauLeptons, double measuredMETx, double measuredMETy, TMatrixD &covMET, float num);

int main (int argc, char* argv[]) 
{
   optutl::CommandLineParser parser ("Sets Event Weights in the ntuple");
   parser.addOption("branch",optutl::CommandLineParser::kString,"Branch","__svFit__");
   parser.addOption("newFile",optutl::CommandLineParser::kString,"newFile","newFile");
   parser.addOption("newOutputFile",optutl::CommandLineParser::kDouble,"New Output File",0.0);
   //parser.addOption("--newOutputFile",optutl::CommandLineParser::kBool,"NewOutputFile",true);
   parser.parseArguments (argc, argv);
   
   char TreeToUse[80]="first" ;

   TFile *fProduce;// = new TFile("dummy","UPDATE");

   TFile *f = new TFile(parser.stringValue("outputFile").c_str(),"UPDATE");

   if(parser.doubleValue("newOutputFile")>0){

     std::string newFileName = parser.stringValue("newFile");
     fProduce = new TFile(newFileName.c_str(),"recreate");
     copyFiles(parser, f, fProduce);//new TFile(parser.stringValue("outputFile").c_str()+"SVFit","UPDATE");
     //Note copyFiles closes fProduce
     ///ANd here is the locaiton of the bug... UPDATE, not RECREATE
     fProduce = new TFile(newFileName.c_str(),"UPDATE");
     readdir(fProduce,parser,TreeToUse);
     fProduce->ls();
     fProduce->Close();
   }
   else{
     readdir(f,parser,TreeToUse);
   }
   f->Close();

} 


void readdir(TDirectory *dir, optutl::CommandLineParser parser, char TreeToUse[]) 
{
  TDirectory *dirsav = gDirectory;
  TIter next(dir->GetListOfKeys());
  TKey *key;
  char stringA[80]="first";
  //dir->cd();      
  while ((key = (TKey*)next())) {
    printf("Found key=%s \n",key->GetName());

    TObject *obj = key->ReadObj();
    if (obj->IsA()->InheritsFrom(TDirectory::Class())) {
      dir->cd(key->GetName());
      TDirectory *subdir = gDirectory;
      sprintf(TreeToUse,"%s",key->GetName());
      readdir(subdir,parser,TreeToUse);
      dirsav->cd();
    }
    else if(obj->IsA()->InheritsFrom(TTree::Class())) {
      TTree *t = (TTree*)obj;
      float svFitMass = -10;
      float svFitPt = -10;
      float svFitEta = -10;
      float svFitPhi = -10;
      float svFitMET = -10;
      //TBranch *newBranch = t->Branch(parser.stringValue("branch").c_str(),&svFitMass,(parser.stringValue("branch")+"/F").c_str());
      TBranch *newBranch1 = t->Branch("m_sv", &svFitMass, "m_sv/F");
      TBranch *newBranch2 = t->Branch("pt_sv", &svFitPt, "pt_sv/F");
      TBranch *newBranch3 = t->Branch("eta_sv", &svFitEta, "eta_sv/F");
      TBranch *newBranch4 = t->Branch("phi_sv", &svFitPhi, "phi_sv/F");
      TBranch *newBranch5 = t->Branch("met_sv", &svFitMET, "met_sv/F");
      float pt1;
      float eta1;
      float phi1;
      float pt2;
      float eta2;
      float phi2;
      float decayMode;
      float decayMode2;
      float covMatrix00;
      float covMatrix10;
      float covMatrix01;
      float covMatrix11;
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
	mass1 = 105.658e-3;
	mass2 = 0.13957;
    channel = "mt";
      }
      else if(std::string(TreeToUse).find("eleTauEvent")!= std::string::npos){
	decayType1 = svFitStandalone::kTauToElecDecay;
    decayType2 = svFitStandalone::kTauToHadDecay;
	mass1 = 0.51100e-3;
	mass2 = 0.13957;
    channel = "et";
      }
      //else if(parser.stringValue("outputFile").find("_em.root") != std::string::npos){
      else if(std::string(TreeToUse).find("em")!= std::string::npos){
        //std::cout<< parser.stringValue("outputFile").c_str() << std::endl;
        std::cout<< "EMu sample" <<std::endl;
	decayType1 = svFitStandalone::kTauToElecDecay;
	decayType2 = svFitStandalone::kTauToMuDecay;
	mass1 = 0.51100e-3;
	mass2 = 105.658e-3;
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
	std::cout<<"TreeToUse "<< std::string(TreeToUse)<<" does not match muTauEvent or eleTauEvent or 'em' or 'tt'... Skipping!!"<<std::endl;
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
        t->SetBranchAddress("t2DecayMode",&decayMode2);
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
        t->SetBranchAddress("mPhi",&phi2);
        t->SetBranchAddress("e_m_EMpairMvaMetCovMatrix00",&covMatrix00);
        t->SetBranchAddress("e_m_EMpairMvaMetCovMatrix01",&covMatrix01);
        t->SetBranchAddress("e_m_EMpairMvaMetCovMatrix10",&covMatrix10);
        t->SetBranchAddress("e_m_EMpairMvaMetCovMatrix11",&covMatrix11);
        t->SetBranchAddress("e_m_EMpairMvaMet",&met);
        t->SetBranchAddress("e_m_EMpairMvaMetPhi",&metphi);
      }

      else {
        t->SetBranchAddress("pt_1",&pt1,&pt1branch);
        t->SetBranchAddress("eta_1",&eta1);
        t->SetBranchAddress("phi_1",&phi1);
        t->SetBranchAddress("pt_2",&pt2);
        t->SetBranchAddress("eta_2",&eta2);
        t->SetBranchAddress("phi_2",&phi2);
        t->SetBranchAddress("t1DecayMode",&decayMode);
        t->SetBranchAddress("t2DecayMode",&decayMode2);
        t->SetBranchAddress("covMatrix00",&covMatrix00);
        t->SetBranchAddress("covMatrix01",&covMatrix01);
        t->SetBranchAddress("covMatrix10",&covMatrix10);
        t->SetBranchAddress("covMatrix11",&covMatrix11);
        t->SetBranchAddress("mvamet",&met);
        t->SetBranchAddress("mvametphi",&metphi);
      }
      
      printf("Found tree -> weighting\n");
      for(Int_t i=0;i<t->GetEntries();++i)
	{
	  //if(j>1)break ;
	  t->GetEntry(i);

	  TMet.SetPtEtaPhiM(met,0,metphi,0);
	  
	  measuredMETx = met*TMath::Cos(metphi);
	  measuredMETy = met*TMath::Sin(metphi);
	  /*
	  if(measuredMETx<0.0001){
	    std::cout<<"something seems funny with measuredMETx closing"<<std::endl;
	    std::cout<<"measuredMETx "<<measuredMETx<<" measuredMETy "<<measuredMETy<<" met "<< met<<" metphi "<< metphi<<std::endl;
	    std::cout<<"TLorentz MetX "<<TMet.Px() <<std::endl;
	    std::cout<<"TLorentz MetY "<<TMet.Py() <<std::endl;
	    return;
	    }*/
	  ////if(decayMode==0)
	  ////  mass2 = 0.13957;
	  ////else if(decayMode==1)
	  ////  mass2 = 0.13957*2;
	  ////else if(decayMode==3)
	  ////  mass2 = 0.13957*3;
      if(channel=="et" || channel=="mt"){
	    if(decayMode==0)
	      mass2 = 0.13957;
	    else if(decayMode==1)
	      mass2 = 0.13957*2;
	    else if(decayMode==3)
	      mass2 = 0.13957*3;}
      if(channel=="tt"){
	    if(decayMode==0)
	      mass1 = 0.13957;
	    else if(decayMode==1)
	      mass1 = 0.13957*2;
	    else if(decayMode==3)
	      mass1 = 0.13957*3;
	    if(decayMode2==0)
	      mass2 = 0.13957;
	    else if(decayMode2==1)
	      mass2 = 0.13957*2;
	    else if(decayMode2==3)
	      mass2 = 0.13957*3;}

	  covMET[0][0] =  covMatrix00;
	  covMET[1][0] =  covMatrix10;
	  covMET[0][1] =  covMatrix01;
	  covMET[1][1] =  covMatrix11;


	  if((decayMode==0||decayMode==1||decayMode==10)&&(channel=="et"||channel=="mt")){
	    // define lepton four vectors
	    std::vector<svFitStandalone::MeasuredTauLepton> measuredTauLeptons;
	    // check if electron or muon
	    measuredTauLeptons.push_back(
		  svFitStandalone::MeasuredTauLepton(decayType1, pt1, eta1,  phi1, mass1)
		  			 ); // tau -> electron decay (Pt, eta, phi, mass)
	    
	    measuredTauLeptons.push_back(
	  	  svFitStandalone::MeasuredTauLepton(decayType2,  pt2, eta2, phi2,  mass2, decayMode)
	  				 ); // tau -> 1prong0pi0 hadronic decay (Pt, eta, phi, mass, pat::Tau.decayMode())
        
	    //std::cout<<"Here 0"<<std::endl;
	    SVfitStandaloneAlgorithm algo(measuredTauLeptons, measuredMETx, measuredMETy, covMET, 1);
	    //std::cout<<"Here 1"<<std::endl;
	    algo.addLogM(false);  
	    //std::cout<<"Here 2"<<std::endl;
	    //algo.shiftVisPt(true, inputFile_visPtResolution);
	    //std::cout<<"Here 3"<<std::endl;
	    algo.integrateMarkovChain();
	    //std::cout<<"Here 4"<<std::endl;
	    svFitMass = algo.getMass(); // return value is in units of GeV
	    svFitPt = algo.pt();
	    svFitEta = algo.eta();
	    svFitPhi = algo.phi();
	    svFitMET = algo.fittedMET().Rho();
	    //std::cout<<"Here 5"<<std::endl;
	    if ( algo.isValidSolution() ) {
	      std::cout << "found mass = " << svFitMass << std::endl;
        }
	    else {
	      std::cout << "sorry -- status of NLL is not valid [" << algo.isValidSolution() << "]" << std::endl;
	    }
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


	  //else if((decayMode==0||decayMode==1||decayMode==10)&&(decayMode2==0||decayMode2==1||decayMode2==10)&&channel=="tt"){
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
      } // Double Hadronic (TT)

	  else {
	    svFitMass = -100;
        svFitPt = -100;
        svFitEta = -100;
        svFitPhi = -100;
        svFitMET = -100;
      }
	  
      std::cout << "Mass: " << svFitMass << " Pt: " << svFitPt << " Eta: " << svFitEta;
      std::cout << " Phi: " << svFitPhi << " MET: " << svFitMET << std::endl;
	  newBranch1->Fill();
	  newBranch2->Fill();
	  newBranch3->Fill();
	  newBranch4->Fill();
	  newBranch5->Fill();
      svFitMass = -100;
      svFitPt = -100;
      svFitEta = -100;
      svFitPhi = -100;
      svFitMET = -100;
	}

	  
      t->Write("",TObject::kOverwrite);
      strcpy(TreeToUse,stringA) ;

    }
  }
}

float runSVFit(std::vector<svFitStandalone::MeasuredTauLepton> & measuredTauLeptons, double measuredMETx, double measuredMETy, TMatrixD &covMET, float num){
  edm::FileInPath inputFileName_visPtResolution("TauAnalysis/SVfitStandalone/data/svFitVisMassAndPtResolutionPDF.root");
  TH1::AddDirectory(false);  
  TFile* inputFile_visPtResolution = new TFile(inputFileName_visPtResolution.fullPath().data());  
  float svFitMass = 0;
  SVfitStandaloneAlgorithm algo(measuredTauLeptons, measuredMETx, measuredMETy, covMET, 1);
  algo.addLogM(false);  
  algo.shiftVisPt(true, inputFile_visPtResolution);
  algo.integrateMarkovChain();
  svFitMass = algo.getMass(); // return value is in units of GeV
  if ( algo.isValidSolution() ) {
    std::cout << "found mass = " << svFitMass << std::endl;
  } else {
    std::cout << "sorry -- status of NLL is not valid [" << algo.isValidSolution() << "]" << std::endl;
  }
  delete inputFile_visPtResolution;
  return svFitMass;

}


//Thank you Renee Brun :)
void CopyDir(TDirectory *source, optutl::CommandLineParser parser) {
  //copy all objects and subdirs of directory source as a subdir of the current directory
  //source->ls();
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
