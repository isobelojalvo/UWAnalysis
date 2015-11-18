#include "TCanvas.h"
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TH1.h"
#include "TF1.h"
#include <math.h>
#include <TEfficiency.h>
#include <TMath.h>
#include <iostream>
#include <string>

#include <cmath>
#include "TLegend.h"
#include "TPad.h"
#include "TH1D.h"
#include "TH2.h"
#include "THStack.h"
#include "TStyle.h"
#include "TAxis.h"
#include "TGaxis.h"
#include "TTree.h"
#include "TPaveText.h"

using namespace std;


void createVertexDistribution_OfficialPU(){
  TString selectionMC="pt_1>18";

  TFile *f    = new TFile("MyDataPileupHistogram.root");
  TH1D* h = (TH1D*)f->Get("pileup");


  h->Scale(1/h->Integral());

  TFile *f1    = new TFile("/nfs_scratch/laura/ztt_unweighted12_NoHF/ZJets.root");
  TTree* tree1 = (TTree*)f1->Get("muTauEventTree/eventTree");
  TH1D* Shape1 = new TH1D("Nominal1","Nominal1",50,0,50);
  tree1->Draw("vertices>>+Nominal1","("+selectionMC+")");
  Shape1->Scale(1/Shape1->Integral());

  TFile f2("vertices.root","RECREATE");
  TH1D* Shape2 = new TH1D("Nominal2","Nominal2",50,0,50);
  Shape2->Divide(h,Shape1);
  std::cout<<"Bin content of bin with 20 vertices "<<Shape2->GetBinContent(Shape2->FindBin(20))<<std::endl;
  std::cout<<"Shape integral "<< Shape2->Integral()<<std::endl;
  //f2->cd();
  Shape2->Write("vertices",TObject::kOverwrite);//"vertices",TObject::kOverwrite);

}
