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

float getSF(float pt, float eta){

  float x = std::min(double(pt), 799.9);
  float SF = 1;
  if(fabs(eta) < 0.8){
  	SF = ((1.06238+(0.00198635*x))+(-4.89082e-06*(x*x)))+(3.29312e-09*(x*(x*x))); 
  }
  else if(fabs(eta) < 1.6){
  	SF = ((1.08048+(0.00110831*x))+(-2.96189e-06*(x*x)))+(2.16266e-09*(x*(x*x))); 
  }
  else if(fabs(eta) < 2.4){
  	SF = ((1.09145+(0.000687171*x))+(-2.45054e-06*(x*x)))+(1.7844e-09*(x*(x*x))); 
  }
  else{
  	SF = 1;
  }
  
  return SF;

}

float getMistag(Float_t pt, Float_t eta){

  float x = std::min(double(pt), 670.0);

  float eff = 0.0;

  if(fabs(eta) >= 0.0 && fabs(eta) < 0.8) {
    eff = ((0.00967751+(2.54564e-05*x))+(-6.92256e-10*(x*x)));
  } 
  else if(fabs(eta) >= 0.8 && fabs(eta) < 1.6) {
    eff = ((0.00974141+(5.09503e-05*x))+(2.0641e-08*(x*x)));
  } 
  else if(fabs(eta) >= 1.6 && fabs(eta) < 2.4) {
    eff = ((0.013595+(0.000104538*x))+(-1.36087e-08*(x*x)));
  } 

  return eff;

}

int BTagData(int Tagged){

		int BTAG = 0;
		
		if(Tagged >=1){
			BTAG = 1;
		}
		
		return BTAG;
		
}

int BTagMC(TRandom3* randm, int matchTag, int Tagged, int NoMatchNoTag, float pt1, float pt2, float eta1, float eta2) {

		
		int BTAG = 0;
		
		if(Tagged >=1){
			BTAG = 1;
		}
		
		if(matchTag>=1){
		
			BTAG = 1;
			
			if(randm->Uniform() > pow(0.03,matchTag)) BTAG = 1;  // leave it tagged
      		else    BTAG = 0; // demote it to untagged
      		
      	}
      	
      	
      	if(NoMatchNoTag>=1 && BTAG == 0){
      	
      		float SF_1 = getSF(pt1, eta1);
      		float eff_1 = getMistag(pt1, eta1);
      		float promoteProb = fabs(SF_1 - 1.0)/((SF_1/eff_1) - 1.0);
      		
			if(randm->Uniform() < promoteProb) BTAG=1;  // promote it to tagged
			else                      BTAG=0; // leave it untagged 
			
			if(NoMatchNoTag>=2 && BTAG == 0){
				float SF_2 = getSF(pt2, eta2);
				float eff_2 = getMistag(pt2, eta2);
				float promoteProb = fabs(SF_2 - 1.0)/((SF_2/eff_2) - 1.0);
				
				if(randm->Uniform() < promoteProb) BTAG=1;  // promote it to tagged
				else                      BTAG=0; // leave it untagged
			}
			
		}	
		
		return BTAG;	
				     		

}


int main (int argc, char* argv[]) 
{
   optutl::CommandLineParser parser ("Sets Event Weights in the ntuple");
   parser.addOption("branch",optutl::CommandLineParser::kString,"Branch","btag");
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

  TRandom3* randm;
  randm = new TRandom3(0);
	
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
      int btag = 0;
      TBranch *newBranch = t->Branch(parser.stringValue("branch").c_str(),&btag,(parser.stringValue("branch")+"/I").c_str());

      int matchTag;
      int tagged;
      int noMatchNoTag;
      float pt1;
      float pt2;
      float eta1;
      float eta2;


      t->SetBranchAddress("nTaggableJetsPt20MatchedTagged",&matchTag);
      t->SetBranchAddress("nJetsBTagCSVMPt20",&tagged);
      t->SetBranchAddress("nTaggableJetsPt20NotMatched",&noMatchNoTag);
      t->SetBranchAddress("J1Pt",&pt1);
      t->SetBranchAddress("J2Pt",&pt2);
      t->SetBranchAddress("J1Eta",&eta1);
      t->SetBranchAddress("J2Eta",&eta2);
            

      printf("Found tree -> tagging\n");
      for(Int_t i=0;i<t->GetEntries();++i)
	{
	  t->GetEntry(i);
	  btag=0;
	  if(parser.stringValue("outputFile").c_str() == std::string("DATA.root") && std::string(TreeToUse).find("EventTree")!= std::string::npos){
	  	btag=BTagData(tagged);
	  }
	  else if(parser.stringValue("outputFile").c_str() == std::string("ETEM.root") && std::string(TreeToUse).find("EventTree")!= std::string::npos){
	  	btag=BTagData(tagged);
	  }
	  else if(parser.stringValue("outputFile").c_str() == std::string("MTEM.root") && std::string(TreeToUse).find("EventTree")!= std::string::npos){
	  	btag=BTagData(tagged);
	  }
	  else if(std::string(TreeToUse).find("EventTree")!= std::string::npos){
	    btag=BTagMC(randm, matchTag, tagged, noMatchNoTag, pt1, pt2, eta1, eta2);
	  }

	  newBranch->Fill();
	}

	t->Write("",TObject::kOverwrite);
	strcpy(TreeToUse,stringA) ;
    }
  }
}
