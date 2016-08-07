#include "PhysicsTools/FWLite/interface/CommandLineParser.h" 
#include "TFile.h"
#include "TROOT.h"
#include "TKey.h"
#include "TTree.h"
#include "TH1F.h"
#include "TFileMerger.h"


std::vector<float> data;
std::vector<float> mc;

void readdir(TDirectory *dir,optutl::CommandLineParser parser,std::vector<float> ev,int type); 



int main (int argc, char* argv[]) 
{
   optutl::CommandLineParser parser ("Sets Event Weights in the ntuple");
   parser.addOption("histoName",optutl::CommandLineParser::kString,"Counter Histogram Name","EventSummary");
   parser.addOption("weight",optutl::CommandLineParser::kDouble,"Weight to apply",1.0);
   parser.addOption("branch",optutl::CommandLineParser::kString,"Branch","__WEIGHT__");
   parser.addOption("root200",optutl::CommandLineParser::kString,"root200","root.root");
   parser.addOption("root400",optutl::CommandLineParser::kString,"root400","root.root");
   parser.addOption("root600",optutl::CommandLineParser::kString,"root600","root.root");
   parser.addOption("root800",optutl::CommandLineParser::kString,"root800","root.root");
   parser.addOption("root1200",optutl::CommandLineParser::kString,"root1200","root.root");
   parser.addOption("root2500",optutl::CommandLineParser::kString,"root2500","root.root");
   parser.addOption("rootinf",optutl::CommandLineParser::kString,"rootinf","root.root");

   
   parser.parseArguments (argc, argv);
   

   

 
   TFile *w = new TFile(parser.stringValue("root200").c_str(),"UPDATE");
   TH1F* evC  = (TH1F*)w->Get(parser.stringValue("histoName").c_str());
   float evW = evC->GetBinContent(1);
   w->Close();
  
   TFile *w1 = new TFile(parser.stringValue("root400").c_str(),"UPDATE");
   TH1F* evC1  = (TH1F*)w1->Get(parser.stringValue("histoName").c_str());
   float evW1 = evC1->GetBinContent(1);
   w1->Close();   

   TFile *w2 = new TFile(parser.stringValue("root600").c_str(),"UPDATE");
   TH1F* evC2  = (TH1F*)w2->Get(parser.stringValue("histoName").c_str());
   float evW2 = evC2->GetBinContent(1);
   w2->Close();

   TFile *w3 = new TFile(parser.stringValue("root800").c_str(),"UPDATE");
   TH1F* evC3  = (TH1F*)w3->Get(parser.stringValue("histoName").c_str());
   float evW3 = evC3->GetBinContent(1);
   w3->Close();

   TFile *w4 = new TFile(parser.stringValue("root1200").c_str(),"UPDATE");
   TH1F* evC4  = (TH1F*)w4->Get(parser.stringValue("histoName").c_str());
   float evW4 = evC4->GetBinContent(1);
   w4->Close();


   TFile *w5 = new TFile(parser.stringValue("root2500").c_str(),"UPDATE");
   TH1F* evC5  = (TH1F*)w5->Get(parser.stringValue("histoName").c_str());
   float evW5 = evC5->GetBinContent(1);
   w5->Close();
     

   TFile *w6 = new TFile(parser.stringValue("rootinf").c_str(),"UPDATE");
   TH1F* evC6  = (TH1F*)w6->Get(parser.stringValue("histoName").c_str());
   float evW6 = evC6->GetBinContent(1);
   w6->Close();

   printf("Found  %f ZNuNu HT 100-200 Events\n",evW);
   printf("Found  %f ZNuNu HT 200-400 Events\n",evW1);
   printf("Found  %f ZNuNu HT 400-600 Events\n",evW2);
   printf("Found  %f ZNuNu HT 600-800 Events\n",evW3);
   printf("Found  %f ZNuNu HT 800-1200 Events\n",evW4);
   printf("Found  %f ZNuNu HT 1200-2500 Events\n",evW5);
   printf("Found  %f ZNuNu HT 2500-inf Events\n",evW6);
  
   double LOtoNNLO=1.23;

   double ZNuNuLo=evW/(LOtoNNLO*280.92);
   double ZNuNuLo1=evW1/(LOtoNNLO*77.64);
   double ZNuNuLo2=evW2/(LOtoNNLO*10.671);
   double ZNuNuLo3=evW3/(LOtoNNLO*2.5611);
   double ZNuNuLo4=evW4/(LOtoNNLO*1.1778);
   double ZNuNuLo5=evW5/(LOtoNNLO*0.2874);
   double ZNuNuLo6=evW6/(LOtoNNLO*0.006933);

 
   std::vector<float> ev;
   ev.push_back(ZNuNuLo);
   ev.push_back(ZNuNuLo1);
   ev.push_back(ZNuNuLo2);
   ev.push_back(ZNuNuLo3);
   ev.push_back(ZNuNuLo4);
   ev.push_back(ZNuNuLo5);
   ev.push_back(ZNuNuLo6);
   
   TFile *f0 = new TFile(parser.stringValue("root200").c_str(),"UPDATE");
   readdir(f0,parser,ev,0);
   f0->Close();
   
   TFile *f1 = new TFile(parser.stringValue("root400").c_str(),"UPDATE");
   readdir(f1,parser,ev,1);
   f1->Close();
   
   TFile *f2 = new TFile(parser.stringValue("root600").c_str(),"UPDATE");
   readdir(f2,parser,ev,2);
   f2->Close();
   
   TFile *f3 = new TFile(parser.stringValue("root800").c_str(),"UPDATE");
   readdir(f3,parser,ev,3);
   f3->Close();
   
   TFile *f4 = new TFile(parser.stringValue("root1200").c_str(),"UPDATE");
   readdir(f4,parser,ev,4);
   f4->Close();
 
   TFile *f5 = new TFile(parser.stringValue("root2500").c_str(),"UPDATE");
   readdir(f5,parser,ev,5);
   f5->Close();

   TFile *f6 = new TFile(parser.stringValue("rootinf").c_str(),"UPDATE");
   readdir(f6,parser,ev,6);
   f6->Close();


  } 


void readdir(TDirectory *dir,optutl::CommandLineParser parser,std::vector<float> ev, int type) 
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
      readdir(subdir,parser,ev,type);
      dirsav->cd();
    }
    else if(obj->IsA()->InheritsFrom(TTree::Class())) {
      TTree *t = (TTree*)obj;
      float weight;


      TBranch *newBranch = t->Branch(parser.stringValue("branch").c_str(),&weight,(parser.stringValue("branch")+"/F").c_str());

      printf("Found tree -> weighting\n");
      for(Int_t i=0;i<t->GetEntries();++i){
	      t->GetEntry(i);
		      if(type==0)
			      weight = parser.doubleValue("weight")/(ev[0]);
		      else if(type==1)
			      weight = parser.doubleValue("weight")/(ev[1]);
		      else if(type==2)
			      weight = parser.doubleValue("weight")/(ev[2]);
		      else if(type==3)
			      weight = parser.doubleValue("weight")/(ev[3]);
		      else if(type==4)
			      weight = parser.doubleValue("weight")/(ev[4]);
		      else if(type==5) 
			      weight = parser.doubleValue("weight")/(ev[5]);
		      else 
			      weight = parser.doubleValue("weight")/(ev[6]);

	      newBranch->Fill();
      }
      t->Write("",TObject::kOverwrite);
    }



  }

}
