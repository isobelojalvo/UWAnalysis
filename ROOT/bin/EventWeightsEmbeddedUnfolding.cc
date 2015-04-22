#include "PhysicsTools/FWLite/interface/CommandLineParser.h" 
#include "PhysicsTools/Utilities/interface/Lumi3DReWeighting.h"
#include "TFile.h"
#include "TROOT.h"
#include "TKey.h"
#include "TTree.h"
#include "TH2F.h"
#include "TH1D.h"

//Distribution from Fall 2011

std::vector<float> data;
std::vector<float> mc;
edm::Lumi3DReWeighting *LumiWeights;



void readdir(TDirectory *dir,TH2F* kfactor1,TH2F *kfactor2); 



int main (int argc, char* argv[]) 
{
   optutl::CommandLineParser parser ("Sets Event Weights in the ntuple");
   parser.addOption("mass",optutl::CommandLineParser::kString,"HiggsMass","EventSummary");
  

   parser.parseArguments (argc, argv);
   



   TFile *fH1 =  new TFile("Unfold2D_1.root");
   TFile *fH2 =  new TFile("Unfold2D_2.root");

   TH2F *weight1 = (TH2F*) fH1->FindObjectAny("UnfoldDen1");
   TH2F *weight2 = (TH2F*) fH2->FindObjectAny("UnfoldDen2");

   TFile *f = new TFile(parser.stringValue("outputFile").c_str(),"UPDATE");



   readdir(f,weight1,weight2);
   f->Close();

   if(fH1->IsOpen())
     fH1->Close();
   if(fH2->IsOpen())
     fH2->Close();

} 


void readdir(TDirectory *dir,TH2F *weight1,TH2F * weight2) 
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
      readdir(subdir,weight1,weight2);
      dirsav->cd();
    }
    else if(obj->IsA()->InheritsFrom(TTree::Class())) {
      printf("Doing tree\n");
      TTree *t = (TTree*)obj;
      float weight=1.0;
      TBranch *newBranch = t->Branch("__UNFOLD__",&weight,"__UNFOLD__/F");
      std::vector<double> * embeddedPt = new std::vector<double>();
      std::vector<double> * embeddedEta = new std::vector<double>();

      t->SetBranchAddress("embeddedPt",&embeddedPt);
      t->SetBranchAddress("embeddedEta",&embeddedEta);
      for(Int_t i=0;i<t->GetEntries();++i)
	{
	  t->GetEntry(i);
	  float pt1=0; 
	  float eta1=0;
	  float pt2=0; 
	  float eta2=0;

	  if(embeddedPt->at(0)>embeddedPt->at(1)) {
	    pt1=embeddedPt->at(0); 
	    pt2=embeddedPt->at(1); 
	    eta1=embeddedEta->at(0); 
	    eta2=embeddedEta->at(1); 
	  }
	  else
	    {
	      pt1=embeddedPt->at(1); 
	      pt2=embeddedPt->at(0); 
	      eta1=embeddedEta->at(1); 
	      eta2=embeddedEta->at(0); 

	    }

	  float w1 = weight1->GetBinContent(weight1->GetXaxis()->FindBin(eta1),weight1->GetYaxis()->FindBin(pt1));
	  float w2 = weight2->GetBinContent(weight2->GetXaxis()->FindBin(eta2),weight2->GetYaxis()->FindBin(pt2));
	  //	  printf("%f %f %f %f %f %f\n",w1,w2,pt1,pt2,eta1,eta2);
	  weight=w1*w2;

	  
	  newBranch->Fill();
	}
      t->Write("",TObject::kOverwrite);
      delete embeddedPt;
      delete embeddedEta;
	

    }

  }

}
