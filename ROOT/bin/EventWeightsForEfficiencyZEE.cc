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
#include "TRandom3.h"






void readdir(TDirectory *dir,optutl::CommandLineParser parser,char TreeToUse[]); 

float ZEEFakeRate(float decayMode, float eta2, int genTaus, float genPt2){

	if(genTaus>0 || genPt2==0){
		return 1.0;
	}
	else{
		if( decayMode == 0 ){
			if(fabs(eta2) < 1.5)  return 1.37;
			else  return 1.11;
		}
		else if( decayMode == 1 ){
			if(fabs(eta2) < 1.5)  return 2.18;
			else  return 0.47;
		}
		else{
			return 1.0;
		}
	}
		

}



int main (int argc, char* argv[]) 
{
   optutl::CommandLineParser parser ("Sets Event Weights in the ntuple");
   parser.addOption("branch",optutl::CommandLineParser::kString,"Branch","ZeFakeTau");
   parser.parseArguments (argc, argv);
   
   char TreeToUse[80]="first" ;
   
   TFile *f = new TFile(parser.stringValue("outputFile").c_str(),"UPDATE");
   readdir(f,parser,TreeToUse);
   f->Close();

} 


void readdir(TDirectory *dir, optutl::CommandLineParser parser, char TreeToUse[]) 
{
  TDirectory *dirsav = gDirectory;
  TIter next(dir->GetListOfKeys());
  TKey *key;
  char stringA[80]="first";

  while ((key = (TKey*)next())) {
  
	printf("Found key=%s \n",key->GetName());
	if(!strcmp(stringA,TreeToUse)) sprintf(TreeToUse,"%s",key->GetName());
	printf("Strings %s %s \n",TreeToUse,stringA);
	TObject *obj = key->ReadObj();

    if (obj->IsA()->InheritsFrom(TDirectory::Class())) {
      dir->cd(key->GetName());
      TDirectory *subdir = gDirectory;
      readdir(subdir,parser,TreeToUse);
      dirsav->cd();
    }
    else if(obj->IsA()->InheritsFrom(TTree::Class())) {
      TTree *t = (TTree*)obj;
      float weight = 1.0;
      TBranch *newBranch = t->Branch(parser.stringValue("branch").c_str(),&weight,(parser.stringValue("branch")+"/F").c_str());

      float decayMode;
      float eta2;
      int genTaus;
      float genPt2;


      t->SetBranchAddress("tauDecayMode",&decayMode);
      t->SetBranchAddress("eta2",&eta2);
      t->SetBranchAddress("genTaus",&genTaus);
      t->SetBranchAddress("genPt2",&genPt2);

            

      printf("Found tree -> weighting\n");
      for(Int_t i=0;i<t->GetEntries();++i)
	{
	  t->GetEntry(i);
	  weight=1.0;
	  if(std::string(TreeToUse).find("eleTauEventTree")!= std::string::npos){
	    weight=ZEEFakeRate(decayMode, eta2, genTaus, genPt2);
	  }

	  newBranch->Fill();
	}

	t->Write("",TObject::kOverwrite);
	strcpy(TreeToUse,stringA) ;
    }
  }
}
