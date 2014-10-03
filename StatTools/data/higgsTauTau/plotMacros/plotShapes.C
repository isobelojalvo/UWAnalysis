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

#include <iostream>
#include <cmath>
#include "TLegend.h"
#include "TFile.h"
#include "TROOT.h"
#include "TCanvas.h"
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
#include "tdrstyle.C"
#include "TStyle.h"
#include "TAxis.h"
#include "TGaxis.h"

using namespace std;

void plotJetProfile(){
  gROOT->ProcessLine(".L tdrstyle.C");
  setTDRStyle();
  gROOT->SetBatch();


  double binning_[]={0.,10.,20.,30.,40.,50.,60.,70.,80.,90.,100.,110.,120.,130.,140.,150.,160.,170.,180.,190.,200.,225.,250.,275.,300.,325.,350.,400.,500.,700.,1000.,1500.};

  TFile *HhhFile    = new TFile("/scratch/ojalvo/HhhGenStudies/Hhhttbb300.root");
  TFile *TOPFile = new TFile("/scratch/ojalvo/LTau_103/TOP2.root");
  TFile *MTEMFile = new TFile("/scratch/ojalvo/HhhGenStudies/MTEM.root");

  TString selection="pt1>20&&pt2>20"+inputsel;//
  //TString selection="pt1>20&&pt2>20&&vertices>0&&diLeptons==0&&lPFIsoDB<0.1&&tauIso<1.5&&tightElectrons==0&&tightMuons<=1&&mt1<30&&J1Pt>20&&J2Pt>20";//

  TCanvas *Tcan= new TCanvas("Tcan","",100,20,600,800); Tcan->cd();  Tcan->SetFillColor(0); 

  TPad* pad1 = new TPad("pad1","The pad",0,0.2,1,1);
  TPad* pad2 = new TPad("pad2","the other pad",0,0,1,0.2);
  pad1->SetFillColor(0);
  //pad1->SetLogy();
  pad1->Draw();  pad1->cd();  pad1->SetLeftMargin(0.2);  pad1->SetBottomMargin(0.13);

  TLegend *leg = new TLegend(0.55,0.75,0.99,0.99);//  Leg = new TLegend(0.74,0.65,0.99,0.95);
  leg->SetFillColor(0);
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);
  leg->SetHeader("");
  leg->SetShadowColor(0);

  TTree* HhhTree = (TTree*)HhhFile->Get("muTauEventTreeFinal/eventTree");

  //TH1F* Shape = new TH1F("hist1","hist1",31,&binning_[0]);
  TH1F* Shape = new TH1F("hist1","hist1",bins,lo,hi);
  HhhTree->Draw(var+">>+hist1","("+selection+")");
  Shape->SetLineColor(kBlue);  Shape->SetFillColor(kBlue);
  Shape->SetFillStyle(3002);
  Shape->SetLineWidth(4);
  //Shape->Sumw2();

  
  TTree* TOPTree = (TTree*)TOPFile->Get("muTauEventTreeFinal/eventTree");
  TH1F* Shape1 = new TH1F("hist2","hist2",bins,lo,hi);
  TOPTree->Draw(+var+">>+hist2","("+selection+")","same");

  Shape1->SetLineColor(kRed);
  Shape1->SetFillColor(kRed);
  Shape1->SetFillStyle(3002);
  Shape1->SetLineWidth(4);
  Shape1->Scale(Shape->Integral()/Shape1->Integral());

  //Shape1->Sumw2();

  TTree* MTEMTree = (TTree*)MTEMFile->Get("muTauEventTree/eventTree");
  TH1F* Shape2 = new TH1F("hist1","hist1",bins,lo,hi);
  MTEMTree->Draw(var+">>+hist1","("+selection+")","same");
  Shape2->SetLineColor(kBlack);
  Shape2->SetLineStyle(2);
  Shape2->SetLineWidth(4);
  Shape2->Scale(Shape->Integral()/Shape2->Integral());
  

  Shape->GetXaxis()->SetTitle(var);
  Shape->GetYaxis()->SetTitle("A.U.");
  Shape1->Draw("same");
  Shape->Draw("same");

  ///////////stupid thing to sent max bin
  float max, max1, max2 = 0;
  max = Shape->GetBinContent(Shape->GetMaximumBin());
  max1 = Shape1->GetBinContent(Shape1->GetMaximumBin());
  max2 = Shape2->GetBinContent(Shape2->GetMaximumBin());

  if(max>max1&&max>max2)
    Shape->SetMaximum(max*1.1);
  else if(max1>max&&max1>max2)
    Shape->SetMaximum(max1*1.1);
  else 
    Shape->SetMaximum(max2*1.1);

  ///
  leg->AddEntry(Shape,"300GeV H Signal","l");
  leg->AddEntry(Shape1,"t#bar{t}","l");
  leg->AddEntry(Shape2,"Z #rightarrow #tau#tau","l");
  //leg->AddEntry(Shape2,"Embedded 50 GeV<M(#mu#mu)<250 GeV","l");

  leg->Draw();

  
  Tcan->cd();

Tcan->SaveAs("~/www/htt/GenStudies/"+var+"2TightTagReq.png");

}
