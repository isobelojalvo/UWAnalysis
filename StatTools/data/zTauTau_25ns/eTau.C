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


void eTau(){
  TString selectionNominalOS="pt_1>23&&pt_2>20&&vertices>0&&diLeptons==0&&iso_1<0.1&&tauIso<1.5&&tightElectrons<=1&&charge==0&&tightMuons==0";
  TString selectionNominalSS="pt_1>23&&pt_2>20&&vertices>0&&diLeptons==0&&iso_1<0.1&&tauIso<1.5&&tightElectrons<=1&&charge!=0&&tightMuons==0";
  TString selectionRelaxedOS = "pt_1>23&&pt_2>20&&vertices>0&&charge==0";
  TString selectionRelaxedSS = "pt_1>23&&pt_2>20&&vertices>0";
  TString selectionOS = selectionNominalOS;//selectionRelaxedOS;//
  TString selectionSS = selectionNominalSS;//selectionRelaxedSS;//
  TString outFile = "eleTau_mt_1_SS.root";
  //TString outFile = "eleTau_m_visSS.root";

  //TString variable = "m_vis"; int bins = 30;float low = 0, high = 300;
  TString variable = "mt_1"; int bins = 40;float low = 0, high = 200;

  TFile *f    = new TFile("/nfs_scratch/laura/ztt_weighted7/eleDATA.root");
  TFile *fQCD    = new TFile("/nfs_scratch/laura/ztt_emQCD/emQCD.root");
  TFile *fZTT    = new TFile("/nfs_scratch/laura/ztt_weighted7/ZJets.root");
  TFile *fTT    = new TFile("/nfs_scratch/laura/ztt_weighted7/TTJets.root");
  TFile *fZ    = new TFile("/nfs_scratch/laura/ztt_weighted7/ZJets.root");
  TFile *fW    = new TFile("/nfs_scratch/laura/ztt_weighted7/WJets.root");
  TFile *fVV    = new TFile("/nfs_scratch/laura/ztt_weighted7/VV.root");

  TTree* tree = (TTree*)f->Get("eleTauEventTree/eventTree");
  TTree* treeZ = (TTree*)fZTT->Get("eleTauEventTree/eventTree");
  TTree* treeTT = (TTree*)fTT->Get("eleTauEventTree/eventTree");
  TTree* treeW = (TTree*)fW->Get("eleTauEventTree/eventTree");
  TTree* treeQCD = (TTree*)fQCD->Get("eleTauEventTree/eventTree");
  TTree* treeVV = (TTree*)fVV->Get("eleTauEventTree/eventTree");

  TH1F* Shape = new TH1F("data_obs1","data_obs1",bins,low,high);
  tree->Draw(variable+">>+data_obs1","("+selectionOS+")");
  std::cout<<"Opposite Sign Data "<<Shape->Integral()<<std::endl;
  //Shape->Write("",TObject::kOverwrite);//"vertices",TObject::kOverwrite);

  TH1F* Shape1 = new TH1F("data_obs","data_obs",bins,low,high);
  tree->Draw(variable+">>+data_obs","("+selectionSS+")");
  std::cout<<"    Same Sign Data "<<Shape1->Integral()<<std::endl;

  TH1F* ShapeZ = new TH1F("NominalZ","NominalZ",bins,low,high);
  treeZ->Draw(variable+">>+NominalZ","("+selectionOS+")*__WEIGHT__*40");
  std::cout<<"Opposite Sign Z "<<ShapeZ->Integral()<<std::endl;

  TH1F* ShapeZ1 = new TH1F("NominalZ1","NominalZ1",bins,low,high);
  treeZ->Draw(variable+">>+NominalZ1","("+selectionSS+")*__WEIGHT__*40");
  std::cout<<"    Same Sign Z "<<ShapeZ1->Integral()<<std::endl;

  TH1F* ShapeTT = new TH1F("NominalTT","NominalTT",bins,low,high);
  treeTT->Draw(variable+">>+NominalTT","("+selectionOS+")*__WEIGHT__*40");
  std::cout<<"Opposite Sign TT "<<ShapeTT->Integral()<<std::endl;

  TH1F* ShapeTT1 = new TH1F("NominalTT1","NominalTT1",bins,low,high);
  treeTT->Draw(variable+">>+NominalTT1","("+selectionSS+")*__WEIGHT__*40");
  std::cout<<"    Same Sign TT "<<ShapeTT1->Integral()<<std::endl;


  TH1F* ShapeW = new TH1F("NominalW","NominalW",bins,low,high);
  treeW->Draw(variable+">>+NominalW","("+selectionOS+")*__WEIGHT__*40");
  std::cout<<"Opposite Sign W "<<ShapeW->Integral()<<std::endl;

  TH1F* ShapeW1 = new TH1F("NominalW1","NominalW1",bins,low,high);
  treeW->Draw(variable+">>+NominalW1","("+selectionSS+")*__WEIGHT__*40");
  std::cout<<"    Same Sign W "<<ShapeW1->Integral()<<std::endl;

  TH1F* ShapeQCD = new TH1F("NominalQCD","NominalQCD",bins,low,high);
  treeQCD->Draw(variable+">>+NominalQCD","("+selectionOS+")*__WEIGHT__*40");
  std::cout<<"Opposite Sign QCD "<<ShapeQCD->Integral()<<std::endl;

  TH1F* ShapeQCD1 = new TH1F("NominalQCD1","NominalQCD1",bins,low,high);
  treeQCD->Draw(variable+">>+NominalQCD1","("+selectionSS+")*__WEIGHT__*40");
  std::cout<<"    Same Sign QCD "<<ShapeQCD1->Integral()<<std::endl;

  TH1F* ShapeVV = new TH1F("NominalVV","NominalVV",bins,low,high);
  treeVV->Draw(variable+">>+NominalVV","("+selectionOS+")*__WEIGHT__*40");
  std::cout<<"Opposite Sign VV "<<ShapeVV->Integral()<<std::endl;

  TH1F* ShapeVV1 = new TH1F("NominalVV1","NominalVV1",bins,low,high);
  treeVV->Draw(variable+">>+NominalVV1","("+selectionSS+")*__WEIGHT__*40");
  std::cout<<"    Same Sign VV "<<ShapeVV1->Integral()<<std::endl;

  //TFile f2("mt_1SS.root","RECREATE");
  TFile f2(outFile,"RECREATE");
  f2.mkdir("eleTau_inclusive");
  f2.cd("eleTau_inclusive");

  ShapeZ1->Write("ZTT",TObject::kOverwrite);//"vertices",TObject::kOverwrite);
  ShapeTT1->Write("TT",TObject::kOverwrite);//"vertices",TObject::kOverwrite);
  ShapeW1->Write("W",TObject::kOverwrite);//"vertices",TObject::kOverwrite);
  ShapeQCD1->Write("QCD",TObject::kOverwrite);//"vertices",TObject::kOverwrite);
  ShapeVV1->Write("VV",TObject::kOverwrite);//"vertices",TObject::kOverwrite);
  ShapeVV1->Write("ZL",TObject::kOverwrite);//"vertices",TObject::kOverwrite);
  ShapeVV1->Write("ZJ",TObject::kOverwrite);//"vertices",TObject::kOverwrite);
  Shape1->Write("data_obs",TObject::kOverwrite);//"vertices",TObject::kOverwrite);
  /*
  TFile *f1    = new TFile("/nfs_scratch/laura/ztt_weighted/ZJets.root");
  TTree* tree1 = (TTree*)f1->Get("eleTauEventTree/eventTree");
  TH1F* Shape1 = new TH1F("Nominal1","Nominal1",bins,low,high);
  tree1->Draw("vertices>>+Nominal1","("+selection1+")");
  Shape1->Scale(1/Shape1->Integral());

  TFile f2("vertices.root","RECREATE");
  TH1F* Shape2 = new TH1F("Nominal2","Nominal2",25,0,50);
  Shape2->Divide(Shape,Shape1);
  std::cout<<"Bin content of bin with 12 vertices "<<Shape2->GetBinContent(Shape2->FindBin(20))<<std::endl;
  std::cout<<"Shape integral "<< Shape2->Integral()<<std::endl;
  //f2->cd();

  */
}
