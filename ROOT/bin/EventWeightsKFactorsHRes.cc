#include "PhysicsTools/FWLite/interface/CommandLineParser.h" 
#include "PhysicsTools/Utilities/interface/Lumi3DReWeighting.h"
#include "TFile.h"
#include "TROOT.h"
#include "TKey.h"
#include "TTree.h"
#include "TH1F.h"
#include "TH1D.h"



void readdir(TDirectory *dir,TH1F* kfactor, TH1F* kfactorUp, TH1F* kfactorDown); 



int main (int argc, char* argv[]) 
{
   optutl::CommandLineParser parser ("Sets Event Weights in the ntuple");
   parser.addOption("mass",optutl::CommandLineParser::kInteger,"HiggsMass",125);
   parser.addOption("branch",optutl::CommandLineParser::kString,"Branch","__WEIGHT__");
   parser.addOption("fehipro",optutl::CommandLineParser::kInteger,"UseFeHiPro",1);
  

   parser.parseArguments (argc, argv);
   


   TH1F *weight;
   TH1F *weightUp;
   TH1F *weightDown;
   TFile *fH;
   if(parser.integerValue("fehipro")==0) {
     fH = new TFile(("/afs/cern.ch/user/j/jueugste/public/html/kfactors/Kfactors_"+parser.stringValue("mass")+"_AllScales.root").c_str());
     weight = (TH1F*)fH->Get(("kfactors/kfact_mh"+parser.stringValue("mass")+"_ren"+parser.stringValue("mass")+"_fac"+parser.stringValue("mass")).c_str());
   }
   else
     {

       //fH = new TFile(("/afs/cern.ch/user/m/mbluj/public/weight_hqt_fehipro/weight_ptH_"+parser.stringValue("mass")+".root").c_str());
       if(parser.integerValue("mass")<=110){
       		fH = new TFile("/afs/cern.ch/user/b/benitezj/public/HTTSync/Summer13/HiggsPtWeight/HRes_weight_pTH_mH100_8TeV.root");
       }
       else if(parser.integerValue("mass")<=135){
       		fH = new TFile("/afs/cern.ch/user/b/benitezj/public/HTTSync/Summer13/HiggsPtWeight/HRes_weight_pTH_mH125_8TeV.root");
       }
       else{
       		fH = new TFile("/afs/cern.ch/user/b/benitezj/public/HTTSync/Summer13/HiggsPtWeight/HRes_weight_pTH_mH150_8TeV.root");
       }
       if(fH==0 || !fH->IsOpen())       
	 		{ printf("File not found\n"); return 0;}


       weight = (TH1F*)fH->Get("Nominal");
       weightUp = (TH1F*)fH->Get("Up");
       weightDown = (TH1F*)fH->Get("Down");
       printf("Testing Weight@ 100 GeV = %f\n",weight->Interpolate(100.));
     }


   TFile *f = new TFile(parser.stringValue("outputFile").c_str(),"UPDATE");

   printf("A\n");

   readdir(f,weight,weightUp,weightDown);
   f->Close();

   if(fH->IsOpen())
     fH->Close();

} 


void readdir(TDirectory *dir,TH1F *weight, TH1F *weightUp, TH1F *weightDown) 
{
  TDirectory *dirsav = gDirectory;
  TIter next(dir->GetListOfKeys());
  TKey *key;
  while ((key = (TKey*)next())) {
    printf("Found key=%s \n",key->GetName());
    TObject *obj = key->ReadObj();

    if (obj->IsA()->InheritsFrom(TDirectory::Class())) {
      dir->cd(key->GetName());
      TDirectory *subdir = gDirectory;
      readdir(subdir,weight,weightUp,weightDown);
      dirsav->cd();
    }
    else if(obj->IsA()->InheritsFrom(TTree::Class())) {
      printf("Doing tree\n");
      TTree *t = (TTree*)obj;
      float hresweight=1.0;
      float hresweightUp=1.0;
      float hresweightDown=1.0;
      TBranch *newBranch1 = t->Branch("__HPT__",&hresweight,"__HPT__/F");
      TBranch *newBranch2 = t->Branch("__HPTUp__",&hresweightUp,"__HPTUp__/F");
      TBranch *newBranch3 = t->Branch("__HPTDown__",&hresweightDown,"__HPTDown__/F");
      float pt;
      t->SetBranchAddress("higgsPt",&pt);
      for(Int_t i=0;i<t->GetEntries();++i)
	{
	  t->GetEntry(i);
  	  if(pt<499.){
  	    hresweight= weight->Interpolate(pt);
  	    hresweightUp= weightUp->Interpolate(pt);
  	    hresweightDown= weightDown->Interpolate(pt);
  	  }
  	  else{
  	    hresweight= weight->Interpolate(499.);
  	    hresweightUp= weightUp->Interpolate(499.);
  	    hresweightDown= weightDown->Interpolate(499.);
  	  }

	  newBranch1->Fill();
	  newBranch2->Fill();
	  newBranch3->Fill();
	}
      t->Write("",TObject::kOverwrite);
    }

  }

}
