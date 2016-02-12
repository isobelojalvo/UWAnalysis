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

  TFile *f    = new TFile("MyDataPileupHistogram.root");
  TH1D* h = (TH1D*)f->Get("pileup");


  h->Scale(1/h->Integral());

//  TFile *f1    = new TFile("/nfs_scratch/laura/ztt_unweighted13_NoHF/ZJets.root");
//  TTree* tree1 = (TTree*)f1->Get("muTauEventTree/eventTree");
//  TH1D* Shape1 = new TH1D("Nominal1","Nominal1",50,0,50);

  vector<double> MC = { 4.8551E-07,
                        1.74806E-06,
                        3.30868E-06,
                        1.62972E-05,
                        4.95667E-05,
                        0.000606966,
                        0.003307249,
                        0.010340741,
                        0.022852296,
                        0.041948781,
                        0.058609363,
                        0.067475755,
                        0.072817826,
                        0.075931405,
                        0.076782504,
                        0.076202319,
                        0.074502547,
                        0.072355135,
                        0.069642102,
                        0.064920999,
                        0.05725576,
                        0.047289348,
                        0.036528446,
                        0.026376131,
                        0.017806872,
                        0.011249422,
                        0.006643385,
                        0.003662904,
                        0.001899681,
                        0.00095614,
                        0.00050028,
                        0.000297353,
                        0.000208717,
                        0.000165856,
                        0.000139974,
                        0.000120481,
                        0.000103826,
                        8.88868E-05,
                        7.53323E-05,
                        6.30863E-05,
                        5.21356E-05,
                        4.24754E-05,
                        3.40876E-05,
                        2.69282E-05,
                        2.09267E-05,
                        1.5989E-05,
                        4.8551E-06,
                        2.42755E-06,
                        4.8551E-07,
                        2.42755E-07,
                        1.21378E-07,
                        4.8551E-08};

  TH1D* Shape1 = new TH1D("Nominal1","Nominal1",52,0,52);
  for (i=1;i<53;i++){
     Shape1->SetBinContent(i,MC[i-1]);
  }

  Shape1->Scale(1/Shape1->Integral());

  TFile f2("vertices.root","RECREATE");
  TH1D* Shape2 = new TH1D("Nominal2","Nominal2",52,0,52);
  Shape2->Divide(h,Shape1);
  std::cout<<"Bin content of bin with 20 vertices "<<Shape2->GetBinContent(Shape2->FindBin(20))<<std::endl;
  std::cout<<"Shape integral "<< Shape2->Integral()<<std::endl;
  //f2->cd();
  Shape2->Write("vertices",TObject::kOverwrite);//"vertices",TObject::kOverwrite);

}
