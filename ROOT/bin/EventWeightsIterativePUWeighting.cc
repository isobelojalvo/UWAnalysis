#include "PhysicsTools/FWLite/interface/CommandLineParser.h" 
#include "PhysicsTools/Utilities/interface/LumiReWeighting.h"
#include "TFile.h"
#include "TROOT.h"
#include "TKey.h"
#include "TTree.h"
#include "TH1F.h"
#include <iostream>

using std::cout;
using std::endl;

std::vector<float> data;
std::vector<float> mc;
edm::LumiReWeighting *LumiWeights;


void readdir(TDirectory *dir,optutl::CommandLineParser parser); 


int main (int argc, char* argv[]) 
{
   optutl::CommandLineParser parser ("Sets Event Weights in the ntuple");
   parser.addOption("branch",optutl::CommandLineParser::kString,"Branch","__PUWEIGHT__");
   
   parser.parseArguments (argc, argv);

   TFile *g = new TFile(parser.stringValue("outputFile").c_str(),"UPDATE");

   g->Close();
   
   TFile *f = new TFile(parser.stringValue("outputFile").c_str(),"UPDATE");   
   
   LumiWeights = new edm::LumiReWeighting("../PileUp/MC_Spring16.root","../PileUp/Data_Pileup.root","pileup","pileup");     

   readdir(f,parser);

   f->Close();

} 


void readdir(TDirectory *dir,optutl::CommandLineParser parser) 
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
		  readdir(subdir,parser);
		  dirsav->cd();
	  }
	  else if(obj->IsA()->InheritsFrom(TTree::Class())) {
		  float bx=0;
	          float weight=1.0;
		  TTree *t = (TTree*)obj;
		  TBranch *newBranch = t->Branch(parser.stringValue("branch").c_str(),&weight,(parser.stringValue("branch")+"/F").c_str());
        	  t->SetBranchAddress("puTruth",&bx);
		  printf("Found tree -> weighting\n");
		  for(Int_t i=0;i<t->GetEntries();++i)
		  {
			  t->GetEntry(i);
                          weight*=LumiWeights->weight(bx);

			  newBranch->Fill();
		  }
		  t->Write("",TObject::kOverwrite);
	  }//end else if object A
  }//end while key
}//end read directory
