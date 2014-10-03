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

float bins =50; 
float lo =20;
float hi = 200;
TString var1 ="mJJ";
TString var2 ="mJJReg";
TString inputsel1 = "&&pt2>0&&mJJ>0&&nJetsBTagCSVMPt20>1";//"&&mJJCSVSort>100&&mJJCSVSort<175&&svMass>120&&svMass<175&&btag>0";//"&&mJJ>50&&mJJ<200";
TString inputsel2 = "&&pt2>0&&mJJ>0&&nJetsBTagCSVMPt20>1";//"&&mJJCSVSort>100&&mJJCSVSort<175&&svMass>120&&svMass<175&&btag>0";//"&&mJJ>50&&mJJ<200";
//TString inputsel = "&&nTaggableJetsPt20MatchedTagged>1";
void plotMJJ(){
  gROOT->ProcessLine(".L tdrstyle.C");
  setTDRStyle();
  gROOT->SetBatch();
  tdrStyle->SetOptStat("n"); // To display the mean and RMS:   SetOptStat("mr");
  gStyle->SetOptFit(0011);

  //std::vector
  double binning_[]={0.,10.,20.,30.,40.,50.,60.,70.,80.,90.,100.,110.,120.,130.,140.,150.,160.,170.,180.,190.,200.,225.,250.,275.,300.,325.,350.,400.,500.,700.,1000.,1500.};

  TFile *HhhFile    = new TFile("/scratch/ojalvo/LTau_12_2/ggHhh300.root");

  TString selection1="pt1>20&&pt2>20"+inputsel1;//
  TString selection2="pt1>20&&pt2>20"+inputsel2;//

  TCanvas *Tcan= new TCanvas("Tcan","",100,20,600,600); Tcan->cd();  Tcan->SetFillColor(0); 
  TPad* pad1 = new TPad("pad1","The pad",0,0,0.98,1);

  pad1->SetFillColor(0);
  //pad1->SetLogy();
  pad1->Draw();  pad1->cd();  pad1->SetLeftMargin(0.2);  pad1->SetBottomMargin(0.13);

  TLegend *leg = new TLegend(0.25,0.75,0.55,0.99);//  Leg = new TLegend(0.74,0.65,0.99,0.95);
  leg->SetFillColor(0);
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);
  leg->SetHeader("");
  leg->SetShadowColor(0);

  TTree* HhhTree = (TTree*)HhhFile->Get("muTauEventTreeFinal/eventTree");

  //TH1F* Shape = new TH1F("Nominal","Nominal",31,&binning_[0]);
  TH1F* Shape = new TH1F("Nominal","Nominal",bins,lo,hi);
  HhhTree->Draw(var1+">>+Nominal","("+selection1+")");
  Shape->SetLineColor(kBlue);  Shape->SetFillColor(kBlue);
  Shape->SetFillStyle(3002);
  Shape->SetLineWidth(4);
  Shape->Fit("gaus");
  //Shape->Sumw2();
  gPad->Update();
  TPaveStats *st = (TPaveStats*)Shape->GetListOfFunctions()->FindObject("stats"));//->FindObject("stats");
  st->SetX1NDC(0.22);
  st->SetX2NDC(0.45);
  st->SetY1NDC(0.73);
  st->SetY2NDC(0.55);

  
  TH1F* Shape1 = new TH1F("Regressed","With Jet Regression",bins,lo,hi);
  HhhTree->Draw(var2+">>+Regressed","("+selection2+")","same");
  Shape1->SetLineColor(kRed);
  Shape1->SetFillColor(kRed);
  Shape1->SetFillStyle(3002);
  Shape1->SetLineWidth(4);
  Shape1->Fit("gaus");
  Shape1->Scale(Shape->Integral()/Shape1->Integral());

  gPad->Update();
  pad1->Update();

  //TPaveStats* sb2=(TPaveStats*)(g2->GetListOfFunctions()->FindObject("stats"));
  TPaveStats *st1 = (TPaveStats*)Shape1->GetListOfFunctions()->FindObject("stats"));//->FindObject("stats");
  st1->SetX1NDC(0.22);
  st1->SetX2NDC(0.45);
  st1->SetY1NDC(0.53);
  st1->SetY2NDC(0.35);


  Shape->GetXaxis()->SetTitle("M(JJ)");
  Shape->GetYaxis()->SetTitle("A.U.");
  Shape1->GetXaxis()->SetTitle("M(JJ)");
  Shape1->GetYaxis()->SetTitle("A.U.");
  Shape1->Draw("sames");
  Shape->Draw("sames");


  ///////////stupid thing to sent max bin
  float max, max1, max2 = 0;
  max = Shape->GetBinContent(Shape->GetMaximumBin());
  max1 = Shape1->GetBinContent(Shape1->GetMaximumBin());

  if(max>max1&&max>max2)
    Shape->SetMaximum(max*1.3);
  else if(max1>max&&max1>max2)
    Shape->SetMaximum(max1*1.3);
  else 
    Shape->SetMaximum(max2*1.3);

  ///
  leg->AddEntry(Shape,"mJJ nominal","l");
  leg->AddEntry(Shape1,"mJJ Regressed","l");

  //leg->AddEntry(Shape2,"Embedded 50 GeV<M(#mu#mu)<250 GeV","l");

  leg->Draw();

  
  Tcan->cd();
  /*
  pad2->Draw();
  pad2->cd();   
  pad2->SetBottomMargin(0.1);
  pad2->SetTopMargin(0.1);
  pad2->SetLeftMargin(0.2); 

  TH1F *Den = new TH1F("Den","hist",bins,lo,hi);
  TH1F *Num = new TH1F("Num","hist",bins,lo,hi);
  //Shape->Sumw2();
  TH1F *Eff = (TH1F*)Shape1->Clone();
  Eff->SetLineColor(kBlue);
  Eff->Sumw2();
  TH1F *Eff1 = (TH1F*)Shape->Clone();
  Eff1->SetLineColor(kMagenta);
  TH1F *Div = (TH1F*)Shape2->Clone();
  Div->Sumw2();
  Eff->Divide(Div);
  //Eff1->Divide(Shape3);
  //Eff2->Divide(Shape4);
  Eff->GetYaxis()->SetRangeUser(0.5,1.5);
  Eff->GetYaxis()->SetNdivisions(3);
  Eff->GetYaxis()->SetLabelSize(0.1);
  Eff->GetYaxis()->SetTitleSize(0.1);
  Eff->GetYaxis()->SetTitleOffset(0.1);
  //Eff->GetYaxis()->SetTitle(myGroup + " / " + group);                                                                                                                                                                                                  
  Eff->GetYaxis()->SetTitle("Ratio");
  Eff->GetXaxis()->SetNdivisions(-1);
  Eff->GetXaxis()->SetTitle("");
  Eff->GetXaxis()->SetLabelSize(0.0001);
  Eff->SetMarkerColor(kBlack);
  Eff->Draw("histp");
  TLine line;
  line.DrawLine(Eff->GetXaxis()->GetXmin(),1,Eff->GetXaxis()->GetXmax(),1);

  TLine lineUp;
  lineUp.DrawLine(Eff->GetXaxis()->GetXmin(),0.75,Eff->GetXaxis()->GetXmax(),0.75);

  TLine lineDown;
  lineDown.DrawLine(Eff->GetXaxis()->GetXmin(),1.25,Eff->GetXaxis()->GetXmax(),1.25);

  TF1 *f2 = new TF1("f2","x",0.5,1.5);

  TGaxis *newyaxis = new TGaxis(lo,0.5,lo,1.5,"f2");
  newyaxis->SetNdivisions(4);
  newyaxis->SetLabelSize(0.12);


  pad2->cd();
  TLine *center = new TLine(lo,1,hi,1);
  center->SetLineStyle(2);
  Eff->Draw("ap");
  //Eff1->Draw("apsame");
  //Eff2->Draw("apsame");

  center->Draw();
  line.Draw();
  lineDown.SetLineColor(kBlue);
  lineDown.Draw();
  lineUp.SetLineColor(kBlue);
  lineUp.SetLineStyle(2);
  lineUp.Draw();
  newyaxis->Draw();

  */  
  Tcan->SaveAs("~/www/htt/GenStudies/"+var1+"RegComp2.png");
}
