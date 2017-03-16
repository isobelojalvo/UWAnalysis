#include "PhysicsTools/FWLite/interface/CommandLineParser.h" 
#include <fstream>
#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
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
   //std::cout<<"efficiency m: "<<m<<" m0: "<<m0<<" sigma: "<<sigma<<" alpha: "<<alpha<<" n: "<<n<<" norm: "<<norm<<std::endl;

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
   std::cout<<std::endl;
   std::cout<<"weighting file: "<<parser.stringValue("outputFile").c_str() <<std::endl;   

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
      float trigWeight_1 = 1.0;
      float trigWeight_2 = 1.0;
      float trigWeight = 1.0;
      float zPtWeight;
      float XSecLumiWeight;
      float m_sv;
      float pt_sv;
      
      float weightHighPt;
      float weightHighPtUp;
      float weightHighPtDown;
      
      float weightVBF;
      float weightBoost;

      float weightFake;
      float weightFakeUp;
      float weightFakeDown;
      float weightFake1;
      float weightFake2;



      TBranch *newBranchTrig     = t->Branch(parser.stringValue("branch").c_str(),&trigWeight,(parser.stringValue("branch")+"/F").c_str());
      TBranch *newBranchLeg1  = t->Branch("trigweight_1",   &trigWeight_1,"trigweight_1/F");
      TBranch *newBranchLeg2  = t->Branch("trigweight_2",   &trigWeight_2,"trigweight_2/F");
      TBranch *newBranchZXsec = t->Branch("XSecLumiWeight", &XSecLumiWeight,"XSecLumiWeight/F");

      TBranch *newBranchHighTau     = t->Branch("highTauEffi",    &weightHighPt,"highTauEffi/F");
      TBranch *newBranchHighTauUp   = t->Branch("highTauEffiUp",  &weightHighPtUp,"highTauEffiUp/F");
      TBranch *newBranchHighTauDown = t->Branch("highTauEffiDown",&weightHighPtDown,"highTauEffiDown/F");

      //weight by category + ZPT
      TBranch *newBranchFake     = t->Branch("jetToTauFakeWeight",    &weightFake,"jetToTauFakeWeight/F");
      TBranch *newBranchFake1    = t->Branch("jetToTauFakeWeight_1",  &weightFake1,"jetToTauFakeWeight_1/F");
      TBranch *newBranchFake2    = t->Branch("jetToTauFakeWeight_2",  &weightFake2,"jetToTauFakeWeight_2/F");
      TBranch *newBranchFakeUp   = t->Branch("jetToTauFakeWeightUp",  &weightFakeUp,"jetToTauFakeWeightUp/F");
      TBranch *newBranchFakeDown = t->Branch("jetToTauFakeWeightDown",&weightFakeDown,"jetToTauFakeWeightDown/F");

      float pt1;
      float eta1;
      float isoLoose1;
      float isoVLoose1;
      float isoMed1;
      float isoTight1;
      float isoVTight1;
      float pt2;
      float eta2;
      float isoVLoose2;
      float isoLoose2;
      float isoMed2;
      float isoTight2;
      float isoVTight2;
      float gen_match_1;
      float gen_match_2;
      float genPx=0;
      float genPy=0;
      float genTauPt=0;

      float decayMode_1;
      float decayMode_2;

      t->SetBranchAddress("pt_1",       &pt1);
      t->SetBranchAddress("eta_1",      &eta1);
      t->SetBranchAddress("isoVLoose_1",&isoVLoose1);
      t->SetBranchAddress("isoLoose_1", &isoLoose1);
      t->SetBranchAddress("isoMed_1",   &isoMed1);
      t->SetBranchAddress("isoTight_1", &isoTight1);
      t->SetBranchAddress("isoVTight_1",&isoVTight1);


      t->SetBranchAddress("pt_2",       &pt2);
      t->SetBranchAddress("eta_2",      &eta2);
      t->SetBranchAddress("isoVLoose_2",&isoVLoose2);
      t->SetBranchAddress("isoLoose_2", &isoLoose2);
      t->SetBranchAddress("isoMed_2",   &isoMed2);
      t->SetBranchAddress("isoTight_2", &isoTight2);
      t->SetBranchAddress("isoVTight_2",&isoVTight2);

      t->SetBranchAddress("__WEIGHT__", &XSecLumiWeight);
      t->SetBranchAddress("__ZWEIGHT__",&zPtWeight);

      t->SetBranchAddress("gen_match_1",&gen_match_1);
      t->SetBranchAddress("gen_match_2",&gen_match_2);

      t->SetBranchAddress("decayMode_1",&decayMode_1);
      t->SetBranchAddress("decayMode_2",&decayMode_2);

      t->SetBranchAddress("genpX",&genPx); //genPx
      t->SetBranchAddress("genpY",&genPy); //genPy
      t->SetBranchAddress("genPt2",&genTauPt); //genPy
      int n = 0;
      
      // Short alias for this namespace
      namespace pt = boost::property_tree;

      // Create a root
      pt::ptree root;
      
      // first read in the json file 
      pt::read_json("/data/ojalvo/Htt_80X/check825/CMSSW_8_0_25/src/UWAnalysis/ROOT/bin/triggerJSONs/triggerSF/di-tau/fitresults_tt_moriond2017.json", root);
      
      
      printf("Found tree -> weighting\n");
      for(Int_t i=0;i<t->GetEntries();++i)
	{
	  //n++;
	  //if(n>10)
	  //break;
	  t->GetEntry(i);
	  trigWeight_1=1.0;
	  trigWeight_2=1.0;
	  trigWeight = 1.0;


	  //std::cout<<"tau1(pt,eta,dm): ("<< pt1<<","<<eta1<<","<<decayMode_1<<")"<<std::endl;
	  //std::cout<<"tau2(pt,eta,dm): ("<< pt2<<","<<eta2<<","<<decayMode_2<<")"<<std::endl;
	  //std::cout<<"isoLoose_1 "<<isoLoose1<<" isoMed1 "<< isoMed1 << " isoTight1 " <<isoTight1<<" isoVTight1 "<<isoVTight1<<std::endl;
	  //std::cout<<"isoLoose_2 "<<isoLoose2<<" isoMed2 "<< isoMed2 << " isoTight2 " <<isoTight2<<" isoVTight2 "<<isoVTight2<<std::endl;

	  float effMC_1 = 1.0;
	  float effData_1 = 1.0;
	  float effMC_2 = 1.0;
	  float effData_2 = 1.0;

	  std::string prefixData = "data_genuine_";
	  std::string prefixMC = "mc_genuine_";
	  std::string postFix = "_dm1";
	  std::string isoWP = "TIso";
	  if(decayMode_1 == 0)
	    postFix = "_dm0";
	  if(decayMode_1 == 1)
	    postFix = "_dm1";
	  if(decayMode_1 == 10)
	    postFix = "_dmTEN";
	  
	  //not using this currently... if switch then keep an eye on naming scheme
	  // if(isoTight1>0.5)
	  //isoWP = "TIso";
	  //else
	  //isoWP = "LIso";	   

	  effData_1 = efficiency(pt1, 
				 root.get<float>(prefixData+isoWP+postFix+".m_{0}", 0), 
				 root.get<float>(prefixData+isoWP+postFix+".sigma", 0), 
				 root.get<float>(prefixData+isoWP+postFix+".alpha", 0), 
				 root.get<float>(prefixData+isoWP+postFix+".n", 0), 
				 root.get<float>(prefixData+isoWP+postFix+".norm", 0) );
	  effMC_1 = efficiency(pt1, 
			       root.get<float>(prefixMC+isoWP+postFix+".m_{0}", 0), 
			       root.get<float>(prefixMC+isoWP+postFix+".sigma", 0), 
			       root.get<float>(prefixMC+isoWP+postFix+".alpha", 0), 
			       root.get<float>(prefixMC+isoWP+postFix+".n", 0), 
			       root.get<float>(prefixMC+isoWP+postFix+".norm", 0) );
	  if(decayMode_2 == 0)
	    postFix = "_dm0";
	  if(decayMode_2 == 1)
	    postFix = "_dm1";
	  if(decayMode_2 == 10)
	    postFix = "_dmTEN";

	  effData_2 = efficiency(pt2, 
				 root.get<float>(prefixData+isoWP+postFix+".m_{0}", 0), 
				 root.get<float>(prefixData+isoWP+postFix+".sigma", 0), 
				 root.get<float>(prefixData+isoWP+postFix+".alpha", 0), 
				 root.get<float>(prefixData+isoWP+postFix+".n", 0), 
				 root.get<float>(prefixData+isoWP+postFix+".norm", 0) );
	  effMC_2 = efficiency(pt2, 
			       root.get<float>(prefixMC+isoWP+postFix+".m_{0}", 0), 
			       root.get<float>(prefixMC+isoWP+postFix+".sigma", 0), 
			       root.get<float>(prefixMC+isoWP+postFix+".alpha", 0), 
			       root.get<float>(prefixMC+isoWP+postFix+".n", 0), 
			       root.get<float>(prefixMC+isoWP+postFix+".norm", 0) );
	  
	  trigWeight_1 = effData_1/effMC_1;
	  trigWeight_2 = effData_2/effMC_2;
	  //std::cout<<"effData_1 "<<effData_1<<" effMC_1 "<<effMC_1<<std::endl;
	  //std::cout<<"effData_2 "<<effData_2<<" effMC_2 "<<effMC_2<<std::endl;
	  //std::cout<<"weight: "<<weight<<" weight_1: "<<weight_1<<" weight_2: "<<trigWeight_2<<std::endl;
	  trigWeight = trigWeight_1*trigWeight_2;
	  
	  float genPt = TMath::Sqrt(genPx*genPx+genPy*genPy);
	  
	  weightFake = 1;
	  weightFake1 = 0;
	  weightFake2 = 0;
	  
	  if(gen_match_1 == 6)
	    weightFake1 = 0.2*pt1/100;
	  
	  if(gen_match_2 == 6)
	    weightFake2 = 0.2*pt2/100;
	  
	  weightFake = 1 + weightFake1 + weightFake2;
	  weightFakeDown = 1 + weightFake1 + weightFake2;
	  weightFakeUp = 1 - weightFake1 - weightFake2;

	  weightHighPt    = 0.2 * genTauPt/1000.;
	  weightHighPtUp   = 1 + 0.2 * genTauPt/1000.;
	  weightHighPtDown = 1 - 0.2 * genTauPt/1000.;
	  
	  
	  if(n>20)
	    exit(0);
	  
	  newBranchTrig->Fill();     
	  newBranchLeg1->Fill(); 
	  newBranchLeg2->Fill(); 
	  newBranchZXsec->Fill();
	  
	  newBranchHighTau->Fill();
	  newBranchHighTauUp->Fill();
	  newBranchHighTauDown->Fill();

	  newBranchFake->Fill();
	  newBranchFake1->Fill();
	  newBranchFake2->Fill();
	  newBranchFakeUp->Fill();
	  newBranchFakeDown->Fill();

	}
      
      t->Write("",TObject::kOverwrite);
      strcpy(TreeToUse,stringA) ;
    }
  }
}


/*
//VTightIso
        "m_{0}": 38.63953827612661, 
        "sigma":  7.389378523494392, 
        "alpha": 11.190558467918098, 
        "n":      1.6373712046498128
        "norm":   0.818539785184176, 
38.6395, 7.3893, 11.1905, 1.6373, 0.8185,
 */

/*
//Noiso
        "m_{0}": 44.61974911191058, 
        "sigma":  8.823024805816253, 
        "alpha": 11.841403541663073, 
        "n":      1.2807865720447276
        "norm":   0.9999999986555769, 
44.6197, 8.8230, 11.8414, 1.2807, 0.9999
 */
