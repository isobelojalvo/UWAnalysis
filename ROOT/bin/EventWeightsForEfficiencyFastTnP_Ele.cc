#include "PhysicsTools/FWLite/interface/CommandLineParser.h" 
#include "TFile.h"
#include "TROOT.h"
#include "TKey.h"
#include "TTree.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TH2D.h"
#include "TF1.h"
#include <math.h> 
#include "TMath.h" 
#include <limits>
#include "UWAnalysis/ROOT/bin/HTTTnP.C" 



void readdir(TDirectory *dir,optutl::CommandLineParser parser, TH2F* mhist, TH2F* ehist ); 


float weightMuTau(float pt1,float eta1) {
  return mHTTID(pt1,eta1)*mHTTISO(pt1,eta1);

}



float weightETau(float pt1,float eta1) {
  return eHTTID(pt1,eta1)*eHTTISO(pt1,eta1);
}



int main (int argc, char* argv[]) 
{
   optutl::CommandLineParser parser ("Sets Event Weights in the ntuple");
   parser.addOption("branchTrig",optutl::CommandLineParser::kString,"Branch","__TRIGGER__");
   parser.addOption("branchTnP",optutl::CommandLineParser::kString,"Branch","__IDISO__");
   parser.addOption("muTrigFile",optutl::CommandLineParser::kString,"MuTrig Hist","IsoMu20.root");
   parser.addOption("eTrigFile",optutl::CommandLineParser::kString,"ETrig Hist","IsoEle23WPLOOSE.root");
   parser.parseArguments (argc, argv);
   
   
   TFile *f = new TFile(parser.stringValue("outputFile").c_str(),"UPDATE");

 
   TFile *fmTrig    = new TFile(parser.stringValue("muTrigFile").c_str(),"UPDATE");
   TH2F* mTrig = 0;
   if(fmTrig!=0 && fmTrig->IsOpen()) {
     mTrig = (TH2F*)fmTrig->Get("probe_abseta_probe_pt_PLOT");;
     printf("ENABLING TRIG WEIGHTING USING HISTOGRAM\n");
   }
   else{
     printf("ERROR!!! MU TRIG WEIGHT FILE NOT FOUND!!! EXITING!!!\n");
     return 0;
   }
 
 
  TFile *feTrig    = new TFile(parser.stringValue("ETrigFile").c_str(),"UPDATE");
   TH2F* eTrig = 0;
   if(feTrig!=0 && feTrig->IsOpen()) {
     eTrig = (TH2F*)feTrig->Get("probe_sc_abseta_probe_sc_pt_PLOT");;
     printf("ENABLING TRIG WEIGHTING USING HISTOGRAM\n");
   }
   else{
     printf("ERROR!!! E TRIG WEIGHT FILE NOT FOUND!!! EXITING!!!\n");
     return 0;
   }

   readdir(f,parser, mTrig, eTrig);
   f->Close();

} 


void readdir(TDirectory *dir, optutl::CommandLineParser parser, TH2F* mhist, TH2F* ehist ) 
{



  TDirectory *dirsav = gDirectory;
  TIter next(dir->GetListOfKeys());
  TKey *key;
  while ((key = (TKey*)next())) {
	  printf("Found key=%s \n",key->GetName());
	  TString keyname = key->GetName();
	  if (keyname=="CircJetID_puv2"||keyname=="sumweights"){
		  printf("Skipping key %s . Not weighting. \n",key->GetName());
		  continue;
	  }

	  TObject *obj = key->ReadObj();

	  if (obj->IsA()->InheritsFrom(TDirectory::Class())) {
		  dir->cd(key->GetName());
		  TDirectory *subdir = gDirectory;
		  readdir(subdir,parser,mhist,ehist);
		  dirsav->cd();
	  }
	  else if(obj->IsA()->InheritsFrom(TTree::Class())) {
		  TTree *t = (TTree*)obj;
		  float weightTrig = 1.0;
		  float weightTnP = 1.0;
		  TBranch *newBranchTrig = t->Branch(parser.stringValue("branchTrig").c_str(),&weightTrig,(parser.stringValue("branchTrig")+"/F").c_str());
		  TBranch *newBranchTnP  = t->Branch(parser.stringValue("branchTnP").c_str(),&weightTnP,(parser.stringValue("branchTnP")+"/F").c_str());

		  float pt1;
		  float eta1;

		  t->SetBranchAddress("pt_1",&pt1);
		  t->SetBranchAddress("eta_1",&eta1);

		  printf("Found tree -> weighting\n");
                  std::cout<<"KeyName "<<keyname<<" or ket->GetName() "<<key->GetName()<<std::endl;
		  for(Int_t i=0;i<t->GetEntries();++i)
		  {
			  t->GetEntry(i);
			  weightTnP=1.0;
			  weightTrig=1.0;
			  float abseta = std::abs(eta1);
			  float p = pt1;
			  if (pt1>200.) p=201.;
			  //printf("pt: %0.2f eta: %0.2f \n", p, abseta);

			  weightTnP=weightETau(p,abseta);
			  weightTrig = ehist->GetBinContent(ehist->GetXaxis()->FindBin(abseta),ehist->GetYaxis()->FindBin(p));

			  newBranchTrig->Fill();
			  newBranchTnP->Fill();
		  }

		  t->Write("",TObject::kOverwrite);
	  }
  }
}
