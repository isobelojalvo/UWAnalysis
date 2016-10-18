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


double efficiency(double m, double m0, double sigma, double alpha, double n, double norm)
 { 
   const double sqrtPiOver2 = 1.2533141373;
   const double sqrt2 = 1.4142135624;

   double sig = fabs((double) sigma);
   
   double t = (m - m0)/sig;
   
   if (alpha < 0)
     t = -t;

   double absAlpha = fabs(alpha / sig);
   double a = TMath::Power(n/absAlpha,n)*exp(-0.5*absAlpha*absAlpha);
   double b = absAlpha - n/absAlpha;
   double arg = absAlpha / sqrt2 ;

   //   if (a>=std::numeric_limits<double>::max()) return -1. ;

   double ApproxErf ;

   if (arg > 5.) ApproxErf = 1 ;
   else if (arg < -5.) ApproxErf = -1 ;
   else ApproxErf = TMath::Erf(arg) ;

   double leftArea = (1 + ApproxErf) * sqrtPiOver2 ;
   double rightArea = ( a * 1/TMath::Power(absAlpha - b,n-1)) / (n - 1);
   double area = leftArea + rightArea;

   if ( t <= absAlpha ){
     arg = t / sqrt2 ;
     if (arg > 5.) ApproxErf = 1 ;
     else if (arg < -5.) ApproxErf = -1 ;
     else ApproxErf = TMath::Erf(arg) ;
     return norm * (1 + ApproxErf) * sqrtPiOver2 / area ;
   }
   else{
     return norm * (leftArea +  a * (1/TMath::Power(t-b,n-1) - 1/TMath::Power(absAlpha - b,n-1)) / (1 - n)) / area ;
   }
 }


void readdir(TDirectory *dir,optutl::CommandLineParser parser,char TreeToUse[]); 



int main (int argc, char* argv[]) 
{
   optutl::CommandLineParser parser ("Sets Event Weights in the ntuple");
   parser.addOption("branch",optutl::CommandLineParser::kString,"Branch","__CORR__");
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
      float weight_1 = 1.0;
      float weight_2 = 1.0;
      float weight = 1.0;
      TBranch *newBranch = t->Branch(parser.stringValue("branch").c_str(),&weight,(parser.stringValue("branch")+"/F").c_str());

      float pt1;
      float eta1;
      float iso1;
      float pt2;
      float eta2;
      float iso2;
      float decayMode;


      t->SetBranchAddress("pt_1",&pt1);
      t->SetBranchAddress("eta_1",&eta1);
      t->SetBranchAddress("iso_1",&iso1);
      t->SetBranchAddress("pt_2",&pt2);
      t->SetBranchAddress("eta_2",&eta2);
      t->SetBranchAddress("iso_2",&iso2);
      //t->SetBranchAddress("tauDecayMode",&decayMode);
      

      printf("Found tree -> weighting\n");
      for(Int_t i=0;i<t->GetEntries();++i)
	{
	  t->GetEntry(i);
	  weight_1=1.0;
	  weight_2=1.0;

	  //iso WP          m0       sigma       alpha           n        norm
	  //NoIso  3.86506E+01 5.81155E+00 5.82783E+00 3.38903E+00 9.33449E+00
	  //iso WP          m0       sigma       alpha           n        norm
	  //VTight 3.77850E+01 4.93611E+00 4.22634E+00 2.85533E+00 9.92196E-01

	  if(iso1 > 0.5)
	    weight_1=efficiency(pt1,3.77850*10,4.93611,4.22634,2.85533,9.92196*0.1);//VTight
	  else
	    weight_1=efficiency(pt1,3.86506*10,5.81155,5.82783,3.38903,9.33449);//NoIso

	  if(iso2 > 0.5)
	    weight_2 = efficiency(pt2,3.77850*10,4.93611,4.22634,2.85533,9.92196*0.1);//VTight
	  else
	    weight_2 = efficiency(pt2,3.86506*10,5.81155,5.82783,3.38903,9.33449);//NoIso

	  weight = weight_1*weight_2;

	  newBranch->Fill();
	}

	t->Write("",TObject::kOverwrite);
	strcpy(TreeToUse,stringA) ;
    }
  }
}
