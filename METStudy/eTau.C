#include "TCanvas.h"
#include "TROOT.h"
#include "TFile.h"
#include "TChain.h"
#include <math.h>
#include <TEfficiency.h>
#include <TMath.h>
#include <string>
#include <iostream>
#include <cmath>
#include "TLegend.h"
#include "TPad.h"
#include "TH1.h"
#include "TH1F.h"
#include "TH2.h"
#include "TF1.h"
#include "THStack.h"
#include "TStyle.h"
#include "TAxis.h"
#include "TGaxis.h"
#include "TTree.h"
#include "TPaveText.h"
#include "TStyle.h"
#include "TGaxis.h"

using namespace std;


void eTau(){

  TCanvas *c1 = new TCanvas("c1","",900,700);
  TString selectionNominalOS="pt_1>24&&pt_2>20&&vertices>0&&diLeptons==0&&iso_1<0.3&&tauIsoMedium>0&&tightElectrons<=1&&charge==0&&tightMuons==0";
  TString selectionOS = selectionNominalOS;//selectionRelaxedOS;//
  TString outFile = "eTau_met.root";
  //TString outFile = "muTau_m_visSS.root";

  //TString variable = "m_vis"; int bins = 30;float low = 0, high = 300;
  TString variable = "mvamet"; int bins = 20000;float low = 0, high = 200;

  TFile *fNorm    = new TFile("NormalMETMethod.root");
  TFile *fMVAUP    = new TFile("RErunMVAMETUp.root");
  TFile *fMVADown    = new TFile("RErunMVAMETDown.root");

  TTree* tree = (TTree*)fNorm->Get("eleTauEventTree/eventTree");
  TTree* treeUp = (TTree*)fNorm->Get("eleTauEventTreeTauUp/eventTree");
  TTree* treeDown = (TTree*)fNorm->Get("eleTauEventTreeTauDown/eventTree");
  TTree* treeMVAUp = (TTree*)fMVAUP->Get("eleTauEventTree/eventTree");
  TTree* treeMVADown = (TTree*)fMVADown->Get("eleTauEventTree/eventTree");

  TH1F* Met = new TH1F("MVAMET","MVAMET",bins,low,high);
  Met->SetLineColor(kGreen+4);
  //Met->SetNormFactor(1);
  Met->GetXaxis()->SetTitle("MVA MET Systemic Tau Shifts (e #tau)");
  tree->Draw(variable+">>+MVAMET","("+selectionOS+")","e1");
  int n1 = Met->GetEntries();
  cout<<"MVA: "<<n1<<endl;

  TH1F* MetUp = new TH1F("METUP","METUP",bins,low,high);
  MetUp->SetLineColor(kBlue-9);
  //MetUp->SetNormFactor(1);
  treeUp->Draw(variable+">>+METUP","("+selectionOS+")","e1 same");
  int n2 = MetUp->GetEntries();
  cout<<"MetUp: "<<n2<<endl;

  TH1F* MetDown = new TH1F("METDOWN","METDOWN",bins,low,high);
  MetDown->SetLineColor(kBlue-4);
  //MetDown->SetNormFactor(1);
  treeDown->Draw(variable+">>+METDOWN","("+selectionOS+")"," e1 same");
  int n3 = MetDown->GetEntries();
  cout<<"MetDown: "<<n3<<endl;

  TH1F* MVAMetUp = new TH1F("MVAMETUP","MVAMETUP",bins,low,high);
  MVAMetUp->SetLineColor(kPink-9);
  //MVAMetUp->SetNormFactor(1);
  treeMVAUp->Draw(variable+">>+MVAMETUP","("+selectionOS+")","e1 same");
  int n4 = MVAMetUp->GetEntries();
  cout<<"MVAMetDown: "<<n4<<endl;

  TH1F* MVAMetDown = new TH1F("MVAMETDOWN","MVAMETDOWN",bins,low,high);
  MVAMetDown->SetLineColor(kPink-4);
  //MVAMetDown->SetNormFactor(1);
  treeMVADown->Draw(variable+">>+MVAMETDOWN","("+selectionOS+")","e1 same");
  int n5 = MVAMetUp->GetEntries();
  cout<<"MVAMetUp: "<< n5<<endl;

  double ks_up = MetUp->KolmogorovTest(MVAMetUp);
  double ks_down = MetDown->KolmogorovTest(MVAMetDown);
  cout<<"KS Test: Up="<<ks_up<<" Down="<<ks_down<<endl;



  TLegend *legend=new TLegend(0.6,0.65,0.88,0.85);
  legend->AddEntry(Met,"Unshifted MVAMET");
  legend->AddEntry(MetUp,"METUP");
  legend->AddEntry(MetDown,"METDOWN");
  legend->AddEntry(MVAMetUp,"MVAMET rerun UP");
  legend->AddEntry(MVAMetDown,"MVAMET rerun Down");
  legend->Draw("same");

  c1->SaveAs("etMETSys.png");
  c1->SaveAs("etMETSys.root");

}
