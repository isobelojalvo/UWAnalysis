#include "PhysicsTools/FWLite/interface/CommandLineParser.h" 
#include "PhysicsTools/Utilities/interface/Lumi3DReWeighting.h"
#include "PhysicsTools/Utilities/interface/LumiReWeighting.h"
#include "TFile.h"
#include "TROOT.h"
#include "TKey.h"
#include "TTree.h"
#include "TH1F.h"
#include "TFileMerger.h"


std::vector<float> data;
std::vector<float> mc;
edm::Lumi3DReWeighting *LumiWeights;
edm::LumiReWeighting *LumiWeightsOld;

void readdir(TDirectory *dir,optutl::CommandLineParser parser,std::vector<float> ev,int doPU,bool doRho,TH1F* puWeight,TH1F* rhoWeight); 



int main (int argc, char* argv[]) 
{
   optutl::CommandLineParser parser ("Sets Event Weights in the ntuple");
   parser.addOption("histoName",optutl::CommandLineParser::kString,"Counter Histogram Name","EventSummary");
   parser.addOption("weight",optutl::CommandLineParser::kDouble,"Weight to apply",1.0);
   parser.addOption("type",optutl::CommandLineParser::kInteger,"Type",0);
   parser.addOption("branch",optutl::CommandLineParser::kString,"Branch","__WEIGHT__");
   parser.addOption("doOneD",optutl::CommandLineParser::kInteger,"Do OneD",0);

   
   parser.parseArguments (argc, argv);
   
   TH1F *rhoWeight=0;
   bool doRho=false;
   TFile *fRho = new TFile("../rhoInfo.root");
   TFile *fPU2 = new TFile("../puInfo3D.root");
   //read PU info
   TH1F *puWeight=0;
   int doPU=0;
   TFile *fPU = new TFile("../puInfo.root");

   if(fPU!=0 && fPU->IsOpen()) {
     puWeight = (TH1F*)fPU->Get("weight");
     doPU=1;
     printf("ENABLING PU WEIGHTING USING VERTICES\n");

   }

   if(parser.integerValue("doOneD")) {
     doPU=3;
     LumiWeightsOld = new edm::LumiReWeighting("../PileUp/MC_Summer12_PU_S10-600bins.root ","../PileUp/Data_Pileup_2012_ReRecoPixel-600bins.root","pileup","pileup");
   }
   
 
   TFile *w = new TFile("W.root","UPDATE");

   TH1F* evC  = (TH1F*)w->Get(parser.stringValue("histoName").c_str());
   float evW = evC->GetBinContent(1);
   
   w->Close();
   
   TFile *w1 = new TFile("W1JETS.root","UPDATE");

   TH1F* evC1  = (TH1F*)w1->Get(parser.stringValue("histoName").c_str());
   float evW1 = evC1->GetBinContent(1);
   
   w1->Close();   

   TFile *w2 = new TFile("W2JETS.root","UPDATE");

   TH1F* evC2  = (TH1F*)w2->Get(parser.stringValue("histoName").c_str());
   float evW2 = evC2->GetBinContent(1);
   
   w2->Close();

   TFile *w3 = new TFile("W3JETS.root","UPDATE");

   TH1F* evC3  = (TH1F*)w3->Get(parser.stringValue("histoName").c_str());
   float evW3 = evC3->GetBinContent(1);
   
   w3->Close();

   TFile *w4 = new TFile("W4JETS.root","UPDATE");

   TH1F* evC4  = (TH1F*)w4->Get(parser.stringValue("histoName").c_str());
   float evW4 = evC4->GetBinContent(1);
   
   w4->Close();

      
   printf("Found  %f W Events\n",evW);
   printf("Found  %f W+1Jet Events\n",evW1);
   printf("Found  %f W+2Jet Events\n",evW2);
   printf("Found  %f W+3Jet Events\n",evW3);
   printf("Found  %f W+4Jet Events\n",evW4);
   
   std::vector<float> ev;
   ev.push_back(evW);
   ev.push_back(evW1/0.175999);///0.176 = W+1Jet X-section from Prep/ W Inclusive Cross Section from Prep 
                               /// Use prep X-sections here to avoid entering k-factor manually 
   ev.push_back(evW2/0.0562617);
   ev.push_back(evW3/0.0168926);
   ev.push_back(evW4/0.00692218);
   
   TFile *f0 = new TFile("W.root","UPDATE");   
   readdir(f0,parser,ev,doPU,doRho,puWeight,rhoWeight);
   f0->Close();
   
   TFile *f1 = new TFile("W1JETS.root","UPDATE");   
   readdir(f1,parser,ev,doPU,doRho,puWeight,rhoWeight);
   f1->Close();
   
   TFile *f2 = new TFile("W2JETS.root","UPDATE");   
   readdir(f2,parser,ev,doPU,doRho,puWeight,rhoWeight);
   f2->Close();
   
   TFile *f3 = new TFile("W3JETS.root","UPDATE");   
   readdir(f3,parser,ev,doPU,doRho,puWeight,rhoWeight);
   f3->Close();
   
   TFile *f4 = new TFile("W4JETS.root","UPDATE");   
   readdir(f4,parser,ev,doPU,doRho,puWeight,rhoWeight);
   f4->Close();
   
   if(fPU!=0 && fPU->IsOpen())
     fPU->Close();

   if(fPU2!=0 && fPU2->IsOpen())
     fPU2->Close();


} 


void readdir(TDirectory *dir,optutl::CommandLineParser parser,std::vector<float> ev,int doPU,bool doRho,TH1F *puWeight,TH1F *rhoWeight) 
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
      readdir(subdir,parser,ev,doPU,doRho,puWeight,rhoWeight);
      dirsav->cd();
    }
    else if(obj->IsA()->InheritsFrom(TTree::Class())) {
      TTree *t = (TTree*)obj;
      float weight;
      int   type = parser.integerValue("type");


      TBranch *newBranch = t->Branch(parser.stringValue("branch").c_str(),&weight,(parser.stringValue("branch")+"/F").c_str());
      TBranch *typeBranch = t->Branch("TYPE",&type,"TYPE/I");
      int vertices;
      float bxm=0;
      float bx=0;
      float bxp=0;
      int LHEProduct1=0;
      int LHEProduct2=0;
      int LHEProduct=0;
      t->SetBranchAddress("LHEProduct",&LHEProduct1);
      t->SetBranchAddress("LHEProduct2",&LHEProduct2);


      if(doPU==1)
		t->SetBranchAddress("vertices",&vertices);
      else if(doPU==2) {
		t->SetBranchAddress("puBXminus",&bxm);
		t->SetBranchAddress("puBX0",&bx);
		t->SetBranchAddress("puBXplus",&bxp);
      }
      else if( doPU==3 ){
      	t->SetBranchAddress("puTruth",&bx);
      }

      float rho=0.0;
      if(doRho)
	  t->SetBranchAddress("Rho",&rho);

      printf("Found tree -> weighting\n");
      for(Int_t i=0;i<t->GetEntries();++i){
	  t->GetEntry(i);
	  
      if(LHEProduct1!=0)
      	LHEProduct=LHEProduct1;
     	
      if(LHEProduct2!=0)
      	LHEProduct=LHEProduct2;	  
	  
	  if(LHEProduct<5)
	  	printf("LHE Product is less then 5, check what is happening!");
	  else if(LHEProduct==5)
	  	weight = parser.doubleValue("weight")/(ev[0]);
	  else if(LHEProduct==6)
	  	weight = parser.doubleValue("weight")/(ev[0]+ev[1]);
	  else if(LHEProduct==7)
	  	weight = parser.doubleValue("weight")/(ev[0]+ev[2]);
	  else if(LHEProduct==8)
	  	weight = parser.doubleValue("weight")/(ev[0]+ev[3]);
	  else
	  	weight = parser.doubleValue("weight")/(ev[0]+ev[4]);
	  	
	  if(doPU==1) {
	    int bin=puWeight->FindBin(vertices);
	    if(bin>puWeight->GetNbinsX())
	      {
		printf("Overflow using max bin\n");
		bin = puWeight->GetNbinsX();
	      }
	    weight*=puWeight->GetBinContent(bin);
	    if(i==1)
	      printf("PU WEIGHT = %f\n",puWeight->GetBinContent(puWeight->FindBin(vertices)));

	  }
	  else if(doPU==2) {
	   	float w = LumiWeights->weight3D( bxm,bx,bxp);
	    if(i==1)
	      printf("PU WEIGHT = %f\n",w);
	    weight*=w;
	  }
	  else if(doPU==3) {
	    weight*=LumiWeightsOld->weight(bx);
	  }
	  if(doRho) {
	    weight*=rhoWeight->GetBinContent(rhoWeight->FindBin(rho));
	    if(i==1)
	      printf("RHO WEIGHT = %f\n",rhoWeight->GetBinContent(rhoWeight->FindBin(rho)));
	  }

	  newBranch->Fill();
	  typeBranch->Fill();
	}
      t->Write("",TObject::kOverwrite);
    }



  }

}
