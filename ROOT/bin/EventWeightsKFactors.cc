#include "PhysicsTools/FWLite/interface/CommandLineParser.h" 
#include "PhysicsTools/Utilities/interface/Lumi3DReWeighting.h"
#include "TFile.h"
#include "TROOT.h"
#include "TKey.h"
#include "TTree.h"
#include "TH1F.h"
#include "TH1D.h"

//Distribution from Fall 2011

std::vector<float> data;
std::vector<float> mc;
edm::Lumi3DReWeighting *LumiWeights;



void readdir(TDirectory *dir,TH1F* kfactor); 



int main (int argc, char* argv[]) 
{
   optutl::CommandLineParser parser ("Sets Event Weights in the ntuple");
   parser.addOption("mass",optutl::CommandLineParser::kString,"HiggsMass","EventSummary");
   parser.addOption("branch",optutl::CommandLineParser::kString,"Branch","__WEIGHT__");
   parser.addOption("fehipro",optutl::CommandLineParser::kInteger,"UseFeHiPro",1);
  

   parser.parseArguments (argc, argv);
   


   TH1F *weight;
   TFile *fH;
   if(parser.integerValue("fehipro")==0) {
     fH = new TFile(("/afs/cern.ch/user/j/jueugste/public/html/kfactors/Kfactors_"+parser.stringValue("mass")+"_AllScales.root").c_str());
     weight = (TH1F*)fH->Get(("kfactors/kfact_mh"+parser.stringValue("mass")+"_ren"+parser.stringValue("mass")+"_fac"+parser.stringValue("mass")).c_str());
   }
   else
     {

       fH = new TFile(("/afs/cern.ch/user/m/mbluj/public/weight_hqt_fehipro/weight_ptH_"+parser.stringValue("mass")+".root").c_str());
       if(fH==0 || !fH->IsOpen())       
	 { printf("File not found\n"); return 0;}


       weight = (TH1F*)fH->Get(("powheg_weight/weight_hqt_fehipro_fit_"+parser.stringValue("mass")).c_str());
       printf("Testing Weight@ 100 GeV = %f\n",weight->Interpolate(100.));
     }


   TFile *f = new TFile(parser.stringValue("outputFile").c_str(),"UPDATE");

   printf("A\n");

   readdir(f,weight);
   f->Close();

   if(fH->IsOpen())
     fH->Close();

} 


void readdir(TDirectory *dir,TH1F *weight) 
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
      readdir(subdir,weight);
      dirsav->cd();
    }
    else if(obj->IsA()->InheritsFrom(TTree::Class())) {
      printf("Doing tree\n");
      TTree *t = (TTree*)obj;
      float hqtweight=1.0;
      TBranch *newBranch = t->Branch("__HQT__",&hqtweight,"__HQT__/F");
      float pt;
      t->SetBranchAddress("higgsPt",&pt);
      for(Int_t i=0;i<t->GetEntries();++i)
	{
	  t->GetEntry(i);
  	  if(pt<499.)
  	    hqtweight= weight->Interpolate(pt);
  	  else
  	    hqtweight= weight->Interpolate(499.);

	  newBranch->Fill();
	}
      t->Write("",TObject::kOverwrite);
    }

  }

}
