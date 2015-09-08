#include "PhysicsTools/FWLite/interface/CommandLineParser.h" 
#include "PhysicsTools/Utilities/interface/Lumi3DReWeighting.h"
#include "PhysicsTools/Utilities/interface/LumiReWeighting.h"
#include "TFile.h"
#include "TROOT.h"
#include "TKey.h"
#include "TTree.h"
#include "TH1F.h"
#include <iostream>

using std::cout;
using std::endl;

void readdir(TDirectory *dir,optutl::CommandLineParser parser,float ev,TH1F* puWeight); 


int main (int argc, char* argv[]) 
{
   optutl::CommandLineParser parser ("Sets Event Weights in the ntuple");
   parser.addOption("histoName",optutl::CommandLineParser::kString,"Counter Histogram Name","EventSummary");
   parser.addOption("weight",optutl::CommandLineParser::kDouble,"Weight to apply",1.0);
   parser.addOption("branch",optutl::CommandLineParser::kString,"Branch","__WEIGHT__");

   
   parser.parseArguments (argc, argv);
   

 
   TFile *g = new TFile(parser.stringValue("outputFile").c_str(),"UPDATE");

   TH1F* evC  = (TH1F*)g->Get(parser.stringValue("histoName").c_str());
   float ev = evC->GetBinContent(1);
   

   g->Close();
   
   printf("Found  %f Events Counted\n",ev);
   
   TFile *f = new TFile(parser.stringValue("outputFile").c_str(),"UPDATE");   
   
   TFile *fPileUp    = new TFile("vertices.root","UPDATE");
   TH1F* puWeight = 0;
   if(fPileUp!=0 && fPileUp->IsOpen()) {
     puWeight = (TH1F*)fPileUp->Get("vertices");;
     printf("ENABLING PU WEIGHTING USING VERTICES\n");
   }  
   else{
     cout<<"ERROR!!! EXITING!!"<<endl;
     return 0;
   }
     
   cout<<"Bin content of bin with 12 vertices "<<puWeight->GetBinContent(puWeight->FindBin(9))<<endl;

   readdir(f,parser,ev,puWeight);

   f->Close();
   if(fPileUp!=0 && fPileUp->IsOpen())
     fPileUp->Close();

} 


void readdir(TDirectory *dir,optutl::CommandLineParser parser,float ev,TH1F* puWeight) 
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
		  readdir(subdir,parser,ev, puWeight);
		  dirsav->cd();
	  }
	  else if(obj->IsA()->InheritsFrom(TTree::Class())) {
		  int vertices;
		  float weight = parser.doubleValue("weight")/(ev);

		  TTree *t = (TTree*)obj;
		  TBranch *newBranch = t->Branch(parser.stringValue("branch").c_str(),&weight,(parser.stringValue("branch")+"/F").c_str());
		  t->SetBranchAddress("vertices",&vertices);

		  printf("Found tree -> weighting\n");
		  for(Int_t i=0;i<t->GetEntries();++i)
		  {
			  t->GetEntry(i);
			  //cout<<"nVertices "<<vertices<<endl;
			  //cout<< "i "<< i <<" bin "<<puWeight->FindBin(vertices)<<endl;
			  int bin=puWeight->FindBin(vertices);

			  weight = parser.doubleValue("weight")/(ev);
			  weight*=puWeight->GetBinContent(bin);

			  if(i==1)
				  printf("PU WEIGHT = %f\n",puWeight->GetBinContent(puWeight->FindBin(vertices)));

			  newBranch->Fill();
		  }
		  t->Write("",TObject::kOverwrite);
	  }//end else if object A
  }//end while key
}//end read directory
