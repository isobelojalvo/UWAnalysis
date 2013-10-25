#include "PhysicsTools/FWLite/interface/CommandLineParser.h" 
#include "TFile.h"
#include "TROOT.h"
#include "TKey.h"
#include "TTree.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TF1.h"
#include <math.h> 
#include "TMath.h" 
#include <limits>




double efficiency(double m, double m0, double sigma, double alpha, double n, double norm)
 { 
   const double sqrtPiOver2 = 1.2533141373;
   const double sqrt2 = 1.4142135624;

   double sig = fabs((double) sigma);
   
   double t = (m - m0)/sig ;
   
   if (alpha < 0)
     t = -t;

   double absAlpha = fabs(alpha / sig);
   double a = TMath::Power(n/absAlpha,n)*exp(-0.5*absAlpha*absAlpha);
   double b = absAlpha - n/absAlpha;

   //   if (a>=std::numeric_limits<double>::max()) return -1. ;

   double ApproxErf ;
   double arg = absAlpha / sqrt2 ;
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



float weightEMu(float pt1,float pt2) {
  float m0 =14.4751; float sigma = 0.120967; float alpha = 0.0226; float n = 4.3709; float norm=0.874294;


  m0=2.90901; sigma=22.4641;alpha=74.3622;n=3.72143;norm=0.976318;
  float dataMUID = efficiency(pt2,m0,sigma,alpha,n,norm);

  m0=1.74118; sigma=22.5399;alpha=52.1416;n=6.59594;norm=0.980176;
  float mcMUID = efficiency(pt2,m0,sigma,alpha,n,norm);
  

  m0=2.67899; sigma=21.9374;alpha=35.4;n=155.359;norm=0.977301;
  float eleid = efficiency(pt1,m0,sigma,alpha,n,norm);

  m0=-3.1459; sigma=27.0568;alpha=81.9479;n=2.21511;norm=0.974106;
  float mceleid = efficiency(pt1,m0,sigma,alpha,n,norm);



  return dataMUID*0.997841*eleid/(mcMUID*mceleid);
 

}


float weightMuTau(float pt1,float pt2,float eta1,float eta2, float decayMode) {

  float m0; float sigma; float alpha; float n; float norm;

  m0 = 18.604910; sigma = 0.276042; alpha = 0.137039; n = 2.698437; norm = 0.940721;
  float dataBAll = efficiency(pt2,m0,sigma,alpha,n,norm);

  m0 = 18.701715; sigma = 0.216523; alpha = 0.148111; n = 2.245081; norm = 0.895320;
  float dataEAll = efficiency(pt2,m0,sigma,alpha,n,norm);



  m0 = 17.313; sigma = 0.662731; alpha = 1.3412; n = 1.05778; norm = 1.26624;
  float mu0p8p = efficiency(pt1,m0,sigma,alpha,n,norm);
  
  m0 = 16.9966; sigma = 0.550532; alpha = 0.807863; n = 1.55402; norm = 0.885134;
  float mu1p2p = efficiency(pt1,m0,sigma,alpha,n,norm);

  m0 = 15.9962; sigma = 0.000106195; alpha = 4.95058e-08; n = 1.9991; norm = 0.851294;
  float mu2p1p = efficiency(pt1,m0,sigma,alpha,n,norm);

  m0 = 16.4307; sigma = 0.226312; alpha = 0.265553; n = 1.55756; norm = 0.974462;
  float mu0p8n = efficiency(pt1,m0,sigma,alpha,n,norm);
  
  m0 = 17.3974; sigma = 0.804001; alpha = 1.47145; n = 1.24295; norm = 0.928198;
  float mu1p2n = efficiency(pt1,m0,sigma,alpha,n,norm);

  m0 = 15.9977; sigma = 7.64004e-05; alpha = 6.4951e-08; n = 1.57403; norm = 0.865325;
  float mu2p1n = efficiency(pt1,m0,sigma,alpha,n,norm);

  
    
  float MCID200p8 = 0.9647;
  float MCID201p2 = 0.9586;
  float MCID202p1 = 0.9511;
  float MCID300p8 = 0.9631;
  float MCID301p2 = 0.9578;
  float MCID302p1 = 0.9490;
  
  float DataID200p8 = 0.9471;
  float DataID201p2 = 0.9422;
  float DataID202p1 = 0.9387;
  float DataID300p8 = 0.9488;
  float DataID301p2 = 0.9434;
  float DataID302p1 = 0.9380; 
  

  /// Add reweighting for the decay mode
  float DMWeight = 1.0;
  if(decayMode == 0) {
  	DMWeight = 0.88;
  }
 
  
	if(fabs(eta2)<1.5&&pt2>20){
		if(pt1 < 30){
			if(eta1>0){
				if(fabs(eta1)<0.8)
					return DMWeight*DataID200p8*dataBAll*mu0p8p/(MCID200p8);
				else if(fabs(eta1)<1.2)
					return DMWeight*DataID201p2*dataBAll*mu1p2p/(MCID201p2);
				else
					return DMWeight*DataID202p1*dataBAll*mu2p1p/(MCID202p1);
			}
			else{
				if(fabs(eta1)<0.8)
					return DMWeight*DataID200p8*dataBAll*mu0p8n/(MCID200p8);
				else if(fabs(eta1)<1.2)
					return DMWeight*DataID201p2*dataBAll*mu1p2n/(MCID201p2);
				else
					return DMWeight*DataID202p1*dataBAll*mu2p1n/(MCID202p1);			
			}
		}
		else{
			if(eta1>0){
				if(fabs(eta1)<0.8)
					return DMWeight*DataID300p8*dataBAll*mu0p8p/(MCID300p8);
				else if(fabs(eta1)<1.2)
					return DMWeight*DataID301p2*dataBAll*mu1p2p/(MCID301p2);
				else
					return DMWeight*DataID302p1*dataBAll*mu2p1p/(MCID302p1);
			}
			else{
				if(fabs(eta1)<0.8)
					return DMWeight*DataID300p8*dataBAll*mu0p8n/(MCID300p8);
				else if(fabs(eta1)<1.2)
					return DMWeight*DataID301p2*dataBAll*mu1p2n/(MCID301p2);
				else
					return DMWeight*DataID302p1*dataBAll*mu2p1n/(MCID302p1);			
			} 
		}   		
	}	
	else if(fabs(eta2)>1.5&&pt2>20){
		if(pt1 < 30){
			if(eta1>0){
				if(fabs(eta1)<0.8)
					return DMWeight*DataID200p8*dataEAll*mu0p8p/(MCID200p8);
				else if(fabs(eta1)<1.2)
					return DMWeight*DataID201p2*dataEAll*mu1p2p/(MCID201p2);
				else
					return DMWeight*DataID202p1*dataEAll*mu2p1p/(MCID202p1);
			}
			else{
				if(fabs(eta1)<0.8)
					return DMWeight*DataID200p8*dataEAll*mu0p8n/(MCID200p8);
				else if(fabs(eta1)<1.2)
					return DMWeight*DataID201p2*dataEAll*mu1p2n/(MCID201p2);
				else
					return DMWeight*DataID202p1*dataEAll*mu2p1n/(MCID202p1);			
			}
		}
		else{
			if(eta1>0){
				if(fabs(eta1)<0.8)
					return DMWeight*DataID300p8*dataEAll*mu0p8p/(MCID300p8);
				else if(fabs(eta1)<1.2)
					return DMWeight*DataID301p2*dataEAll*mu1p2p/(MCID301p2);
				else
					return DMWeight*DataID302p1*dataEAll*mu2p1p/(MCID302p1);
			}
			else{
				if(fabs(eta1)<0.8)
					return DMWeight*DataID300p8*dataEAll*mu0p8n/(MCID300p8);
				else if(fabs(eta1)<1.2)
					return DMWeight*DataID301p2*dataEAll*mu1p2n/(MCID301p2);
				else
					return DMWeight*DataID302p1*dataEAll*mu2p1n/(MCID302p1);			
			} 
		} 
	}
	else{
	   	return 1.0;		
	}	  
  	

}


// Embedded to MC scale factors for tight electron ID
float elecEffSFTight(float pt, float eta){

  //Define histogram with weights
  Double_t xAxis1[10] = {10, 15, 20, 25, 30, 40, 55, 70, 100, 200}; 
  Double_t yAxis1[4] = {0, 0.8, 1.479, 2.5}; 
   
  TH2F hPtEtaSF("hPtEtaSF","",9, xAxis1,3, yAxis1);
  hPtEtaSF.SetBinContent(14,0.95);
  hPtEtaSF.SetBinContent(15,0.96);
  hPtEtaSF.SetBinContent(16,0.97);
  hPtEtaSF.SetBinContent(17,0.98);
  hPtEtaSF.SetBinContent(18,1.00);
  hPtEtaSF.SetBinContent(19,0.98);
  hPtEtaSF.SetBinContent(20,0.99);
  hPtEtaSF.SetBinContent(21,1.00);
  hPtEtaSF.SetBinContent(25,0.89);
  hPtEtaSF.SetBinContent(26,0.93);
  hPtEtaSF.SetBinContent(27,0.94);
  hPtEtaSF.SetBinContent(28,0.98);
  hPtEtaSF.SetBinContent(29,0.96);
  hPtEtaSF.SetBinContent(30,0.97);
  hPtEtaSF.SetBinContent(31,0.98);
  hPtEtaSF.SetBinContent(32,0.93);
  hPtEtaSF.SetBinContent(36,0.66);
  hPtEtaSF.SetBinContent(37,0.75);
  hPtEtaSF.SetBinContent(38,0.78);
  hPtEtaSF.SetBinContent(39,0.84);
  hPtEtaSF.SetBinContent(40,0.89);
  hPtEtaSF.SetBinContent(41,0.89);
  hPtEtaSF.SetBinContent(42,0.93);
  hPtEtaSF.SetBinContent(43,1.00);

  if(pt>199.99)
    pt=199.9;
  eta=fabs(eta);
  if(eta>2.49)
    eta=2.49;

  if(pt<20)
    return 0;

  float eff=0;
  Int_t bin = hPtEtaSF.FindFixBin(pt,eta);
  eff = hPtEtaSF.GetBinContent(bin);

  return eff;
}


float weightETau(float pt1,float pt2,float eta1,float eta2, float decayMode) {


  float m0; float sigma; float alpha; float n; float norm;
  
  m0 = 18.538229; sigma = 0.651562; alpha = 0.324869; n = 13.099048; norm = 0.902365;
  float TauB = efficiency(pt2,m0,sigma,alpha,n,norm);

  m0 = 18.756548; sigma = 0.230732; alpha = 0.142859; n = 3.358497; norm = 0.851919;  
  float TauE = efficiency(pt2,m0,sigma,alpha,n,norm);



  m0 = 22.9704; sigma = 1.0258; alpha = 1.26889; n = 1.31024; norm = 1.06409;
  float weightEleB = efficiency(pt1,m0,sigma,alpha,n,norm);

  m0 = 21.9816; sigma = 1.40993; alpha = 0.978597; n = 2.33144; norm = 0.937552;
  float weightEleE = efficiency(pt1,m0,sigma,alpha,n,norm);
		

  float dataIdB20 = 0.7380;
  float mcIdB20 = 0.82;
  float dataIdB30 = 0.8500;
  float mcIdB30 = 0.8961;

  float dataIdE20 = 0.3319;
  float mcIdE20 = 0.4178;
  float dataIdE30 = 0.5342;
  float mcIdE30 = 0.6026;

  float mcEmb = 1.0; //elecEffSFTight(pt1, eta1);
  
  /// Add reweighting for the decay mode
  float DMWeight = 1.0;
  if(decayMode == 0) {
  	DMWeight = 0.88;
  }
  
	if(pt1>24&&pt2>20&&abs(eta2)<1.5){
		if(pt1 < 30){
				if(fabs(eta1)<1.479)
					return DMWeight*mcEmb*dataIdB20*TauB*weightEleB/(mcIdB20);
				else
					return DMWeight*mcEmb*dataIdE20*TauB*weightEleE/(mcIdE20);
		}
		else{
				if(fabs(eta1)<1.479)
					return DMWeight*mcEmb*dataIdB30*TauB*weightEleB/(mcIdB30);
				else
					return DMWeight*mcEmb*dataIdE30*TauB*weightEleE/(mcIdE30); 
		}   		
	}	
	else if(pt1>24&&pt2>20&&abs(eta2)>1.5){
		if(pt1 < 30){
				if(fabs(eta1)<1.479)
					return DMWeight*mcEmb*dataIdB20*TauE*weightEleB/(mcIdB20);
				else
					return DMWeight*mcEmb*dataIdE20*TauE*weightEleE/(mcIdE20);
		}
		else{
				if(fabs(eta1)<1.479)
					return DMWeight*mcEmb*dataIdB30*TauE*weightEleB/(mcIdB30);
				else
					return DMWeight*mcEmb*dataIdE30*TauE*weightEleE/(mcIdE30); 
		}   		
	}
	else{
		return 1.0;
	}



}





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
      float weight = 1.0;
      TBranch *newBranch = t->Branch(parser.stringValue("branch").c_str(),&weight,(parser.stringValue("branch")+"/F").c_str());

      float pt1;
      float eta1;
      float pt2;
      float eta2;
      float decayMode;


      t->SetBranchAddress("pt1",&pt1);
      t->SetBranchAddress("eta1",&eta1);
      t->SetBranchAddress("pt2",&pt2);
      t->SetBranchAddress("eta2",&eta2);
      t->SetBranchAddress("tauDecayMode",&decayMode);
      

      printf("Found tree -> weighting\n");
      for(Int_t i=0;i<t->GetEntries();++i)
	{
	  t->GetEntry(i);
	  weight=1.0;
	  if(std::string(TreeToUse).find("muTauEventTree")!= std::string::npos){
	    weight=weightMuTau(pt1,pt2,eta1,eta2,decayMode);
	  }
	  else if(std::string(TreeToUse).find("eleTauEventTree")!= std::string::npos){
	    weight=weightETau(pt1,pt2,eta1,eta2,decayMode);
	  }
	  

	  newBranch->Fill();
	}

	t->Write("",TObject::kOverwrite);
	strcpy(TreeToUse,stringA) ;
    }
  }
}
