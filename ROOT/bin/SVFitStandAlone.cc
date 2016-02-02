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

int main (int argc, char* argv[]) 
{
   optutl::CommandLineParser parser ("Sets Event Weights in the ntuple");
   parser.addOption("branch",optutl::CommandLineParser::kString,"Branch","svFit");
   parser.addOption("newFile",optutl::CommandLineParser::kString,"newFile","newFile");
   parser.addOption("newOutputFile",optutl::CommandLineParser::kDouble,"New Output File",0.0);
   //parser.addOption("--newOutputFile",optutl::CommandLineParser::kBool,"NewOutputFile",true);
   parser.parseArguments (argc, argv);
   
   char TreeToUse[80]="first" ;

   TFile *fProduce = new TFile("dummy","UPDATE");

   TFile *f = new TFile(parser.stringValue("outputFile").c_str(),"UPDATE");

   //if(parser.boolValue("--newOutputFile")){
   if(parser.doubleValue("newOutputFile")>0){
     std::cout<<"Creating new outputfile"<<std::endl;
     std::string newFileName = parser.stringValue("newFile");
     fProduce = new TFile(newFileName.c_str(),"recreate");
     copyFiles(parser, f, fProduce);//new TFile(parser.stringValue("outputFile").c_str()+"SVFit","UPDATE");
     std::cout<<"listing the directories================="<<std::endl;
     fProduce->ls();
     readdir(fProduce,parser,TreeToUse);
   }
   else{
     readdir(f,parser,TreeToUse);
   }
   f->Close();
   fProduce->Close();



} 


void readdir(TDirectory *dir, optutl::CommandLineParser parser, char TreeToUse[]) 
{
  int j = 0;
  TDirectory *dirsav = gDirectory;
  TIter next(dir->GetListOfKeys());
  TKey *key;
  char stringA[80]="first";
  edm::FileInPath inputFileName_visPtResolution("TauAnalysis/SVfitStandalone/data/svFitVisMassAndPtResolutionPDF.root");
  TH1::AddDirectory(false);  
  TFile* inputFile_visPtResolution = new TFile(inputFileName_visPtResolution.fullPath().data());  
  std::cout<<"reading dir"<<std::endl;
  while ((key = (TKey*)next())) {
    std::cout<<"reading keys"<<std::endl;
    printf("Found key=%s \n",key->GetName());
    //if(!strcmp(stringA,TreeToUse)) 
    //printf("Strings %s %s \n",TreeToUse,stringA);
    TObject *obj = key->ReadObj();
    
    if (obj->IsA()->InheritsFrom(TDirectory::Class())) {
      dir->cd(key->GetName());
      TDirectory *subdir = gDirectory;
      sprintf(TreeToUse,"%s",key->GetName());
      readdir(subdir,parser,TreeToUse);
      dirsav->cd();
    }
    else if(obj->IsA()->InheritsFrom(TTree::Class())) {
      std::cout<<"Object inherits from TTree Class Tree to use: "<<TreeToUse<<std::endl;

      TTree *t = (TTree*)obj;

      float svFitMass = -1;
      TBranch *newBranch = t->Branch(parser.stringValue("branch").c_str(),&svFitMass,(parser.stringValue("branch")+"/F").c_str());
      float pt1;
      float eta1;
      float phi1;
      float pt2;
      float eta2;
      float phi2;
      float decayMode;
      float mvacov00;
      float mvacov10;
      float mvacov01;
      float mvacov11;
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
      svFitStandalone::kDecayType decayType2 = svFitStandalone::kTauToHadDecay; //svFitStandalone::kTauToElecDecay
      float mass1;
      //Should mass2 depend on hadronic tau decay mode?
      float mass2 = 0.139;
      //determine if electron or muon
      if(std::string(TreeToUse).find("muTauEvent")!= std::string::npos){
	decayType1 = svFitStandalone::kTauToMuDecay;
	mass1 = 105.658e-3;
      }
      else if(std::string(TreeToUse).find("eleTauEvent")!= std::string::npos){
	decayType1 = svFitStandalone::kTauToElecDecay;
	mass1 = 0.51100e-3;
      }
      else{
	std::cout<<"TreeToUse "<< std::string(TreeToUse)<<" does not match muTauEvent or eleTauEvent... Skipping!!"<<std::endl;
	continue;
      }
      
      //MET, MET Covariance, lepton objects,
      t->SetBranchAddress("pt_1",&pt1);
      t->SetBranchAddress("eta_1",&eta1);
      t->SetBranchAddress("phi_1",&phi1);
      t->SetBranchAddress("pt_2",&pt2);
      t->SetBranchAddress("eta_2",&eta2);
      t->SetBranchAddress("phi_2",&phi2);
      t->SetBranchAddress("tauDecayMode",&decayMode);
      t->SetBranchAddress("mvacov00",&mvacov00);
      t->SetBranchAddress("mvacov01",&mvacov01);
      t->SetBranchAddress("mvacov10",&mvacov10);
      t->SetBranchAddress("mvacov11",&mvacov11);
      t->SetBranchAddress("met",&met);
      t->SetBranchAddress("metphi",&metphi);
      
      printf("Found tree -> weighting\n");
      for(Int_t i=0;i<t->GetEntries();++i)
	{
	  if(j>1)break ;
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
	  if(decayMode==0)
	    mass2 = 0.13957;
	  else if(decayMode==1)
	    mass2 = 0.13957*2;
	  else if(decayMode==3)
	    mass2 = 0.13957*3;

	  covMET[0][0] =  mvacov00;
	  covMET[1][0] =  mvacov10;
	  covMET[0][1] =  mvacov01;
	  covMET[1][1] =  mvacov11;
	  ///comment me out 
	  //covMET[0][0] =  787.352;
	  //covMET[1][0] = -178.63;
	  //covMET[0][1] = -178.63;
	  //covMET[1][1] =  179.545;
	  /// to here once we have real covMET... 0's cause SVFit to SegFault.

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
	    //std::cout<<"Here 0"<<std::endl;
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
	  }
	  else
	    svFitMass = 0;
	  
	  newBranch->Fill();
	}
      dir->cd();      
      t->Write("",TObject::kOverwrite);
      strcpy(TreeToUse,stringA) ;
      delete inputFile_visPtResolution;
    }
  }
}


//Thank you Renee Brun :)
void CopyDir(TDirectory *source, optutl::CommandLineParser parser) {
  //copy all objects and subdirs of directory source as a subdir of the current directory
  source->ls();
  TDirectory *savdir = gDirectory;
  std::cout<<"source getname "<<source->GetName()<<std::endl;
  TDirectory *adir = savdir; 
  if(source->GetName()!=parser.stringValue("outputFile")){
    adir = savdir->mkdir(source->GetName());
    std::cout<<"Source name is not outputfile name"<<std::endl;
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
  //main function copying 4 files as subdirectories of a new file
  //std::string newFileName = parser.stringValue("newFile");
  //fNew = new TFile(newFileName.c_str(),"recreate");
  fNew->cd();
  CopyFile(parser.stringValue("outputFile").c_str(),parser);
  //fNew->ls();

}
