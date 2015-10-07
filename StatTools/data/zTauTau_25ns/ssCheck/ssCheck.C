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
#include "TStyle.h"
#include "TAxis.h"
#include "TGaxis.h"

using namespace std;


void ssCheck(){
  TString selectionNominalOS="pt1>18&&pt2>20&&vertices>0&&diLeptons==0&&lPFIsoDB<0.1&&tauIso<1.5&&lTrigger==1&&tauTrigger>0&&tightMuons<=1&&charge==0&&mt1<40";
  TString selectionNominalSS="pt1>18&&pt2>20&&vertices>0&&diLeptons==0&&lPFIsoDB<0.1&&tauIso<1.5&&lTrigger==1&&tauTrigger>0&&tightMuons<=1&&charge!=0&&mt1<40";
  TString selectionRelaxedOS = "pt1>18&&pt2>20&&vertices>0&&diLeptons==0&&tauIso<10&&lPFIsoDB>0.2&&lPFIsoDB<0.9&&charge==0&&lTrigger==1&&tauTrigger>0";
  TString selectionRelaxedSS = "pt1>18&&pt2>20&&vertices>0&&diLeptons==0&&tauIso<10&&lPFIsoDB>0.2&&lPFIsoDB<0.9&&charge!=0";
  TString selectionOS = selectionNominalOS;//selectionRelaxedOS;
  TString selectionSS = selectionNominalSS;//selectionRelaxedSS;
  TString outFile = "svMassSameSign.root";

  TString variable = "svMass"; int bins = 25;float low = 0, high = 300;
  //TString variable = "mt1"; int bins = 25;float low = 0, high = 200;

  TFile *f    = new TFile("/nfs_scratch/$USER/ztt_weighted3/muDATA.root");
  TFile *fZTT    = new TFile("/nfs_scratch/$USER/ztt_weighted3/ZJets.root");
  TFile *fTT    = new TFile("/nfs_scratch/$USER/ztt_weighted3/TTJets.root");
  TFile *fZ    = new TFile("/nfs_scratch/$USER/ztt_weighted3/ZJets.root");
  TFile *fW    = new TFile("/nfs_scratch/$USER/ztt_weighted3/WJets.root");
  TFile *fQCD    = new TFile("/nfs_scratch/$USER/ztt_weighted3/muQCD.root");
  TFile *fVV    = new TFile("/nfs_scratch/$USER/ztt_weighted3/VV.root");

  TTree* tree = (TTree*)f->Get("muTauEventTree/eventTree");
  TTree* treeZ = (TTree*)fZTT->Get("muTauEventTree/eventTree");
  TTree* treeTT = (TTree*)fTT->Get("muTauEventTree/eventTree");
  //TTree* treeZ = (TTree*)fZ->Get("muTauEventTree/eventTree");
  TTree* treeW = (TTree*)fW->Get("muTauEventTree/eventTree");
  TTree* treeQCD = (TTree*)fQCD->Get("muTauEventTree/eventTree");
  TTree* treeVV = (TTree*)fVV->Get("muTauEventTree/eventTree");

  TH1F* Shape = new TH1F("data_obs1","data_obs1",bins,low,high);
  tree->Draw(variable+">>+data_obs1","("+selectionOS+")");
  std::cout<<"Opposite Sign Data "<<Shape->Integral()<<std::endl;
  //Shape->Write("",TObject::kOverwrite);//"vertices",TObject::kOverwrite);

  TH1F* Shape1 = new TH1F("data_obs","data_obs",bins,low,high);
  tree->Draw(variable+">>+data_obs","("+selectionSS+")");
  std::cout<<"    Same Sign Data "<<Shape1->Integral()<<std::endl;

  TH1F* ShapeZ = new TH1F("NominalZ","NominalZ",bins,low,high);
  treeZ->Draw(variable+">>+NominalZ","("+selectionOS+")*__WEIGHT__*6");
  std::cout<<"Opposite Sign Z "<<ShapeZ->Integral()<<std::endl;

  TH1F* ShapeZ1 = new TH1F("NominalZ1","NominalZ1",bins,low,high);
  treeZ->Draw(variable+">>+NominalZ1","("+selectionSS+")*__WEIGHT__*6");
  std::cout<<"    Same Sign Z "<<ShapeZ1->Integral()<<std::endl;

  TH1F* ShapeTT = new TH1F("NominalTT","NominalTT",bins,low,high);
  treeTT->Draw(variable+">>+NominalTT","("+selectionOS+")*__WEIGHT__*6");
  std::cout<<"Opposite Sign TT "<<ShapeTT->Integral()<<std::endl;

  TH1F* ShapeTT1 = new TH1F("NominalTT1","NominalTT1",bins,low,high);
  treeTT->Draw(variable+">>+NominalTT1","("+selectionSS+")*__WEIGHT__*6");
  std::cout<<"    Same Sign TT "<<ShapeTT1->Integral()<<std::endl;


  TH1F* ShapeW = new TH1F("NominalW","NominalW",bins,low,high);
  treeW->Draw(variable+">>+NominalW","("+selectionOS+")*__WEIGHT__*6*1.4");
  std::cout<<"Opposite Sign W "<<ShapeW->Integral()<<std::endl;

  TH1F* ShapeW1 = new TH1F("NominalW1","NominalW1",bins,low,high);
  treeW->Draw(variable+">>+NominalW1","("+selectionSS+")*__WEIGHT__*6*1.4");
  std::cout<<"    Same Sign W "<<ShapeW1->Integral()<<std::endl;

  TH1F* ShapeQCD = new TH1F("NominalQCD","NominalQCD",bins,low,high);
  treeQCD->Draw(variable+">>+NominalQCD","("+selectionOS+")*__WEIGHT__*6");
  std::cout<<"Opposite Sign QCD "<<ShapeQCD->Integral()<<std::endl;

  TH1F* ShapeQCD1 = new TH1F("NominalQCD1","NominalQCD1",bins,low,high);
  treeQCD->Draw(variable+">>+NominalQCD1","("+selectionSS+")*__WEIGHT__*6");
  std::cout<<"    Same Sign QCD "<<ShapeQCD1->Integral()<<std::endl;

  TH1F* ShapeVV = new TH1F("NominalVV","NominalVV",bins,low,high);
  treeVV->Draw(variable+">>+NominalVV","("+selectionOS+")*__WEIGHT__*6");
  std::cout<<"Opposite Sign VV "<<ShapeVV->Integral()<<std::endl;

  TH1F* ShapeVV1 = new TH1F("NominalVV1","NominalVV1",bins,low,high);
  treeVV->Draw(variable+">>+NominalVV1","("+selectionSS+")*__WEIGHT__*6");
  std::cout<<"    Same Sign VV "<<ShapeVV1->Integral()<<std::endl;

  TFile f2(outFile,"RECREATE");
  f2.mkdir("muTau_inclusive");
  f2.cd("muTau_inclusive");

  ShapeZ1->Write("ZTT",TObject::kOverwrite);
  ShapeTT1->Write("TT",TObject::kOverwrite);
  ShapeW1->Write("W",TObject::kOverwrite);
  ShapeQCD1->Write("QCD",TObject::kOverwrite);
  ShapeVV1->Write("VV",TObject::kOverwrite);
  ShapeVV1->Write("ZL",TObject::kOverwrite);
  ShapeVV1->Write("ZJ",TObject::kOverwrite);
  Shape1->Write("data_obs",TObject::kOverwrite);
}
