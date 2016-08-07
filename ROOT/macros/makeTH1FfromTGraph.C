#include "TCanvas.h"
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TH1.h"
#include <TEfficiency.h>
#include <TMath.h>
#include "TH1D.h"
#include "TH2.h"
#include "TAxis.h"
#include "TGaxis.h"
#include "TTree.h"
#include "TGraph.h"
#include "TGraphAsymmErrors.h"

using namespace std;

void makeTH1FfromTGraph(){
   TFile *f_file4 = new TFile("tracking_effi.root","READONLY");
   TGraphAsymmErrors *gr1    = (TGraphAsymmErrors*)f_file4->Get("ratio_eta");

   TFile f("tracking_eta.root","RECREATE");
   float bins[] = { -2.4, -2.1, -1.6, -1.1, -0.6, 0, 0.6, 1.1, 1.6, 2.1, 2.4 };
   int  binnum = sizeof(bins)/sizeof(Float_t) - 1; // or just = 9
   std::cout<<"number of bins: "<<binnum<<endl;
   TH1F* h1 = new TH1F("h1","h1",binnum, bins);
   int n=gr1->GetN();
   //search points (may be more than 1)
   Int_t j = 0;

   for (j=0;j<n;j++) {
       float X=gr1->GetX()[j];
       int bin = gr1->GetXaxis()->FindBin(X);
       float SF=gr1->GetY()[j];
       float ERR=gr1->GetErrorY(j);
       //float ERR=gr1->GetErrorY()[j]; 
       //cout<<"X: "<<X<<endl;
       //cout<<"bin X: "<<bin<<endl;
       //cout<<"SF X: "<<SF<<endl;
       //cout<<"ERR X: "<<ERR<<endl;
       int i = h1->GetXaxis()->FindBin(X);
       h1->SetBinContent(i,SF);
       h1->SetBinError(i,ERR);
   }
   h1->Write("tracking_eta",TObject::kOverwrite);
}
