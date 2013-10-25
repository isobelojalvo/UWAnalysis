#include "RooRealVar.h"
#include "RooVoigtian.h"
#include "RooPolynomial.h"
#include "RooKeysPdf.h"
#include "RooChebychev.h"
#include "RooExponential.h"
#include "RooAddPdf.h"
#include "RooHistPdf.h"
#include "RooDataSet.h"
#include "RooDataHist.h"
#include "RooGlobalFunc.h" 
#include "RooChi2Var.h"
#include "RooRealVar.h"
#include "RooLandau.h"
#include "RooGaussian.h"
#include "RooNumConvPdf.h"
#include "RooMinuit.h"
#include "RooFitResult.h"
#include "RooPlot.h"
#include "RooProdPdf.h"
#include "RooFFTConvPdf.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TLine.h"
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TStyle.h"
#include "TH1.h"
#include "TH2.h"
#include "TF1.h"
#include "RooWorkspace.h"
#include "RooDataSet.h"
#include "RooSimultaneous.h"
#include "TGraphErrors.h"
#include "TMath.h"
#include <string>
#include <fstream>
#include <sstream>
#include "TLatex.h"

void setTDRStyle() {
  TStyle *tdrStyle = new TStyle("tdrStyle","Style for P-TDR");

// For the canvas:
  tdrStyle->SetCanvasBorderMode(0);
  tdrStyle->SetCanvasColor(kWhite);
  tdrStyle->SetCanvasDefH(600); //Height of canvas
  tdrStyle->SetCanvasDefW(700); //Width of canvas
  tdrStyle->SetCanvasDefX(0);   //POsition on screen
  tdrStyle->SetCanvasDefY(0);

// For the Pad:
  tdrStyle->SetPadBorderMode(0);
  // tdrStyle->SetPadBorderSize(Width_t size = 1);
  tdrStyle->SetPadColor(kWhite);
  tdrStyle->SetPadGridX(false);
  tdrStyle->SetPadGridY(false);
  tdrStyle->SetGridColor(0);
  tdrStyle->SetGridStyle(3);
  tdrStyle->SetGridWidth(1);

// For the frame:
  tdrStyle->SetFrameBorderMode(0);
  tdrStyle->SetFrameBorderSize(1);
  tdrStyle->SetFrameFillColor(0);
  tdrStyle->SetFrameFillStyle(0);
  tdrStyle->SetFrameLineColor(1);
  tdrStyle->SetFrameLineStyle(1);
  tdrStyle->SetFrameLineWidth(1);

// For the histo:
  // tdrStyle->SetHistFillColor(1);
  // tdrStyle->SetHistFillStyle(0);
  tdrStyle->SetHistLineColor(1);
  tdrStyle->SetHistLineStyle(0);
  tdrStyle->SetHistLineWidth(1);
  // tdrStyle->SetLegoInnerR(Float_t rad = 0.5);
  // tdrStyle->SetNumberContours(Int_t number = 20);

  tdrStyle->SetEndErrorSize(2);
  //tdrStyle->SetErrorMarker(20);
  tdrStyle->SetErrorX(0.);
  
  tdrStyle->SetMarkerStyle(20);

//For the fit/function:
  tdrStyle->SetOptFit(1);
  tdrStyle->SetFitFormat("5.4g");
  tdrStyle->SetFuncColor(2);
  tdrStyle->SetFuncStyle(1);
  tdrStyle->SetFuncWidth(1);

//For the date:
  tdrStyle->SetOptDate(0);
  // tdrStyle->SetDateX(Float_t x = 0.01);
  // tdrStyle->SetDateY(Float_t y = 0.01);

// For the statistics box:
  tdrStyle->SetOptFile(0);
  tdrStyle->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");
  tdrStyle->SetStatColor(kWhite);
  tdrStyle->SetStatFont(42);
  tdrStyle->SetStatFontSize(0.025);
  tdrStyle->SetStatTextColor(1);
  tdrStyle->SetStatFormat("6.4g");
  tdrStyle->SetStatBorderSize(1);
  tdrStyle->SetStatH(0.1);
  tdrStyle->SetStatW(0.15);
  // tdrStyle->SetStatStyle(Style_t style = 1001);
  // tdrStyle->SetStatX(Float_t x = 0);
  // tdrStyle->SetStatY(Float_t y = 0);

// Margins:
  tdrStyle->SetPadTopMargin(0.1);
  tdrStyle->SetPadBottomMargin(0.13);
  tdrStyle->SetPadLeftMargin(0.16);
  tdrStyle->SetPadRightMargin(0.02);

// For the Global title:

  tdrStyle->SetOptTitle(1);
  tdrStyle->SetTitleFont(42);
  tdrStyle->SetTitleColor(1);
  tdrStyle->SetTitleTextColor(1);
  tdrStyle->SetTitleFillColor(10);
  tdrStyle->SetTitleFontSize(0.05);
  // tdrStyle->SetTitleH(0); // Set the height of the title box
  // tdrStyle->SetTitleW(0); // Set the width of the title box
  // tdrStyle->SetTitleX(0); // Set the position of the title box
  // tdrStyle->SetTitleY(0.985); // Set the position of the title box
  // tdrStyle->SetTitleStyle(Style_t style = 1001);
  // tdrStyle->SetTitleBorderSize(2);

// For the axis titles:

  tdrStyle->SetTitleColor(1, "XYZ");
  tdrStyle->SetTitleFont(42, "XYZ");
  tdrStyle->SetTitleSize(0.06, "XYZ");
  // tdrStyle->SetTitleXSize(Float_t size = 0.02); // Another way to set the size?
  // tdrStyle->SetTitleYSize(Float_t size = 0.02);
  tdrStyle->SetTitleXOffset(0.9);
  tdrStyle->SetTitleYOffset(1.25);
  // tdrStyle->SetTitleOffset(1.1, "Y"); // Another way to set the Offset

// For the axis labels:

  tdrStyle->SetLabelColor(1, "XYZ");
  tdrStyle->SetLabelFont(42, "XYZ");
  tdrStyle->SetLabelOffset(0.007, "XYZ");
  tdrStyle->SetLabelSize(0.05, "XYZ");

// For the axis:

  tdrStyle->SetAxisColor(1, "XYZ");
  tdrStyle->SetStripDecimals(kTRUE);
  tdrStyle->SetTickLength(0.03, "XYZ");
  tdrStyle->SetNdivisions(510, "XYZ");
  tdrStyle->SetPadTickX(1);  // To get tick marks on the opposite side of the frame
  tdrStyle->SetPadTickY(1);

// Change for log plots:
  tdrStyle->SetOptLogx(0);
  tdrStyle->SetOptLogy(0);
  tdrStyle->SetOptLogz(0);

// Postscript options:
  //tdrStyle->SetPaperSize(20.,20.);
  // tdrStyle->SetLineScalePS(Float_t scale = 3);
  // tdrStyle->SetLineStyleString(Int_t i, const char* text);
  // tdrStyle->SetHeaderPS(const char* header);
  // tdrStyle->SetTitlePS(const char* pstitle);

  // tdrStyle->SetBarOffset(Float_t baroff = 0.5);
  // tdrStyle->SetBarWidth(Float_t barwidth = 0.5);
  // tdrStyle->SetPaintTextFormat(const char* format = "g");
   tdrStyle->SetPalette(1,0);
  // tdrStyle->SetTimeOffset(Double_t toffset);
  // tdrStyle->SetHistMinimumZero(kTRUE);

  tdrStyle->cd();

}


using namespace RooFit; 
using namespace std;
struct fitResult {
  double pass;
  double passError;
  double fail;
  double failError;
  double efficiency;
  double efficiencyError;
};




void createWorspace(RooWorkspace *w,const std::string& signalFile,const std::string& treeDir,const std::string& cut);
RooDataHist *createDataSet(RooWorkspace *w,const std::string& prefix,const std::string& file,const std::string& treeDir,const std::string& weightString,const std::string& cut);
void createHistPdfSig(const std::string& name,RooWorkspace *w,const std::string& var,const std::string& file,const std::string& treeDir,const std::string& weightString,const std::string& cut);
void createHistPdfBkd(const std::string& name,RooWorkspace *w,const std::string& var,const std::string& file,const std::string& treeDir,const std::string& weightString,const std::string& cut);
fitResult fitMC(RooWorkspace*,RooDataHist*,RooDataHist*);
fitResult fit(RooWorkspace*,RooDataHist*);
TH1F *createHist(RooWorkspace *w,const std::string& name,const std::string& file,const std::string& treeDir,const std::string& weightString,const std::string& cut,float factor,float lumi);
float constraint(RooWorkspace *w,const std::string& name,const std::string& file,const std::string& treeDir,const std::string& weightString,const std::string& cut,float factor,float lumi);
void run(const std::string& pt_lo,const std::string& pt_hi,const std::string& eta_lo,const std::string& eta_hi,const std::string& savefile,float factor,const std::string& dirMC,const std::string& dirData, const std::string& inTree, const std::string& cut, const std::string& var,FILE* effTex,const std::string& signal);

//binning is done later once signal is chosen
int lo;
int hi;
int bin;
int binmc;
float lumi; //integrated luminosity in inverse picobarns

vector<Float_t> x, y, xerr, yerr,xmc,ymc,xmcerr,ymcerr,cFactor,cFactorErr;

vector<vector<Float_t>> xList;
vector<vector<Float_t>> xerrList;
vector<vector<Float_t>> yList;
vector<vector<Float_t>> yerrList;
vector<vector<Float_t>> ymcList;
vector<vector<Float_t>> ymcerrList;
vector<vector<Float_t>> cFactorList;
vector<vector<Float_t>> cFactorErrList;

string passCut = "";
string failCut = "";

Int_t runCount = 0;
float currPtLo = -100.0; // to keep track of when to start a new LaTeX table

int main(int argc, char* argv[]){ 
 
  runCount = 0; 
  string var; // testing the efficiency of this variable
  string varname;
  string dirMC;
  string dirData;
  string inTree;
  string signal; // DYee or DYmumu 

  if (string(argv[1]).compare("DYee")!=0 && string(argv[1]).compare("DYmumu")!=0) {
    std::cerr<<"Error: signal type must either be 'DYee' or 'DYmumu'"<<endl;
    exit(2);
  } 

  if (argc!= 9){
        std::cerr<<"Usage: TagAndProbeMCEtaBins [signalType] [dirMC] [DataFile] [dirTree] [cut name] [pass cut] [fail cut] [config file]" << std::endl;
 	exit(1);
  } 
  else {
    signal = argv[1];
    dirMC = argv[2];
    dirData = argv[3];
    inTree = argv[4];
    varname = argv[5];
    var = argv[6];
    passCut = argv[6];
    failCut = argv[7];     	
  }
  
  //DYee and DYmumu lumi in inverse picobarns
  if(string(signal).compare("DYee")==0){
        lumi = 8708;	
//lumi = 693.3;   //DYee lumi
	lo = 68;
	hi = 110;
	bin =14;
	binmc=14;
  }
  else{
        lumi = 9918;
//	lumi = 4402.0;  //DYmumu lumi
	lo = 68;
	hi = 112;
	bin = 22;
	binmc = 22;
  }
  
  vector<string> ptLos;
  vector<string> ptHis;
  vector<string> etaLos;
  vector<string> etaHis;

  // read in interval file
  ifstream intervals;
  printf("opening config file %s \n",string(argv[8]).c_str());
  intervals.open(argv[8]);
  if (!intervals) {
    printf("unable to open config file. \n");
    exit(2);
  }
  else {
    string line;
    int nLine = 0; // line it's on
    while (intervals.good()) {
      nLine++;
      getline(intervals,line);
      istringstream iss(line);
      while (iss.good()) {
        string s;
        iss >> s;
        if (s.compare("")==0) continue;
        if (nLine == 1) {
          ptLos.push_back(s);
        }
        if (nLine == 2) {
          ptHis.push_back(s);
        }
        if (nLine == 3) {
          etaLos.push_back(s);
        }
        if (nLine == 4) {
          etaHis.push_back(s);
        }
      }
    }
  }
  
  FILE *effTex = fopen(TString::Format("%s/SummaryPlots/Tables/efficiencies%s-%s.tex",signal.c_str(),signal.c_str(),varname.c_str()), "w");
  TFile *eff = new TFile("eff.root","RECREATE");
  eff->cd();
 
  fprintf(effTex, "\\documentclass[final,letterpaper,twoside,12pt]{article}\n"
                        "\\usepackage{chngpage}\n"
                        "\\usepackage{tabularx}\n"      
                  "\\begin{document}\n");

  string columnHeader = "|c|";
  string tableHeader = "$p_{T} (GeV)$"; 
  for (unsigned int i=0; i<etaLos.size(); i++) {
    columnHeader += "c|";
    tableHeader += TString::Format("& $%s < |\\eta| < %s$ ",etaLos[i].c_str(),etaHis[i].c_str());
  } 

  fprintf(effTex,TString::Format("\\begin{table}[htbp]\n"
                  "\\begin{adjustwidth}{-4em}{-4em}\n"
                  "\\centering\n"
                  "\\begin{tabular}{%s} \\hline \n"
                  "%s \\\\ \n"
                  "\\hline \\hline \n",columnHeader.c_str(),tableHeader.c_str()));

  for (unsigned int i=0; i<ptLos.size(); i++) {
    for (unsigned int j=0; j<etaLos.size(); j++) {
      run(ptLos[i],ptHis[i],etaLos[j],etaHis[j],varname,1,dirMC,dirData,inTree,"",var,effTex,signal);
    }
    fprintf(effTex, TString::Format("\\\\ \\hline \n"));
  }
 
  fprintf(effTex, TString::Format(
                      "\\end{tabular}\n"
                     // "\\end{center}\n"
                      "\\caption {Efficiencies-%s}\n"
                      "\\label{tab:cqdata0}\n"
		      "\\end{adjustwidth}"	
                      "\\end{table}\n\n"
                      "\\end{document}",varname.c_str()));

  int nEtaRanges = etaLos.size();
  for (unsigned int j=0; j<etaLos.size(); j++) {
    vector<Float_t> xtemp;
    vector<Float_t> xerrtemp;
    vector<Float_t> ytemp;
    vector<Float_t> yerrtemp;
    vector<Float_t> ymctemp;
    vector<Float_t> ymcerrtemp;
    vector<Float_t> cFactortemp;
    vector<Float_t> cFactorErrtemp;

    for (unsigned int i=0; i<(etaLos.size()*ptLos.size()); i++) {

      if (i%nEtaRanges==j) {
        xtemp.push_back(x[i]);
        xerrtemp.push_back(xerr[i]);
        ytemp.push_back(y[i]);
        yerrtemp.push_back(yerr[i]);
        ymctemp.push_back(ymc[i]);
        ymcerrtemp.push_back(ymcerr[i]); 
        cFactortemp.push_back(cFactor[i]);
        cFactorErrtemp.push_back(cFactorErr[i]);
      }
    }
    xList.push_back(xtemp);
    xerrList.push_back(xerrtemp);
    yList.push_back(ytemp);
    yerrList.push_back(yerrtemp);
    ymcList.push_back(ymctemp);
    ymcerrList.push_back(ymcerrtemp);
    cFactorList.push_back(cFactortemp);
    cFactorErrList.push_back(cFactorErrtemp);
  }
  
  // make summary plots
    setTDRStyle();
  gStyle->SetTitleYOffset(1.25);

  gStyle->SetMarkerSize(1.);
  TCanvas *c2 = new TCanvas("c", "cc",6,70,400,400);
  gStyle->SetOptFit(1);
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  c2->SetFillColor(0);
  c2->SetBorderMode(0);
  c2->SetBorderSize(2);
  c2->SetTickx(1);
  c2->SetTicky(1);
  c2->SetLeftMargin(0.16);
  c2->SetRightMargin(0.08);
  c2->SetTopMargin(0.1);
  c2->SetBottomMargin(0.13);
  c2->SetFrameFillStyle(0);
  c2->SetFrameBorderMode(0);
  c2->SetFrameFillStyle(0);
  c2->SetFrameBorderMode(0);
    
  for (unsigned int i=0; i<etaLos.size(); i++) {
 
  // plot Data/MC efficiencies
    
    TGraphErrors *gd = new TGraphErrors(ptLos.size(),&xList[i][0],&yList[i][0],&xerrList[i][0],&yerrList[i][0]);
    TGraphErrors *gm = new TGraphErrors(ptLos.size(),&xList[i][0],&ymcList[i][0],&xerrList[i][0],&ymcerrList[i][0]);

    gd->GetYaxis()->SetRangeUser(0,1);
    gm->GetYaxis()->SetRangeUser(0,1);
    gd->GetYaxis()->SetTitle(TString::Format("Efficiency_{%s}",varname.c_str()));
    gd->GetXaxis()->SetTitle("p_{T}, GeV");
    gm->SetMarkerStyle(24);
    gm->SetMarkerColor(4);
    gd->SetMarkerStyle(20);
    gd->SetMarkerColor(1);
    gd->Draw("AP");
    gm->Draw("Psame");
    TLatex latex;
    latex.SetNDC();
    latex.SetTextSize(0.045);
    latex.SetTextAlign(11);
    latex.DrawLatex(0.20,0.96,"CMS Preliminary 2012, #sqrt{s}=8 TeV ");
    latex.DrawLatex(0.40,0.5,TString::Format("eta range: %s-%s",etaLos[i].c_str(),etaHis[i].c_str()));
    TLegend *le = new TLegend(0.6,0.4,0.85,0.15,"");
    le->AddEntry(gd,"Data","p");
    le->AddEntry(gm,"Simulation","p");
    le->SetBorderSize(0);
    le->SetFillColor(0);
    le->Draw();

    c2->SaveAs(TString::Format("%s/SummaryPlots/%s/EfficiencyGraph_eta%s_to_%s-%s.png",signal.c_str(),varname.c_str(),etaLos[i].c_str(),etaHis[i].c_str(),varname.c_str()));
   
  
    // plot correction factors

    TGraphErrors *cFactors = new TGraphErrors(ptLos.size(),&xList[i][0],&cFactorList[i][0],&xerrList[i][0],&cFactorErrList[i][0]);

    //cFactors->SetTitle("");
    cFactors->SetMarkerColor(2);
    cFactors->SetMarkerStyle(10);
    cFactors->SetMaximum(1.25);
    cFactors->SetMinimum(.75);
    cFactors->GetXaxis()->SetTitle("p_{T}, GeV");
    cFactors->GetYaxis()->SetTitle(TString::Format("Efficiency ratio_{%s}",varname.c_str()));
 
    cFactors->Draw("AP");
    TLine *line1 = new TLine(cFactors->GetXaxis()->GetXmax(),1.0,cFactors->GetXaxis()->GetXmin(),1.0);
    line1->Draw();
    latex.DrawLatex(0.40,0.8,TString::Format("eta range: %s-%s",etaLos[i].c_str(),etaHis[i].c_str()));
    latex.DrawLatex(0.20,0.96,"CMS Preliminary 2012, #sqrt{s}=8 TeV ");
    TLegend *le2 = new TLegend(0.6,0.4,0.85,0.15,"");
    le2->AddEntry(cFactors,"Data/Simulation","p");
    le2->SetBorderSize(0);
    le2->SetFillColor(0);
    le2->Draw();

    c2->SaveAs(TString::Format("%s/SummaryPlots/%s/CorrectionFactors_eta%s_to_%s-%s.png",signal.c_str(),varname.c_str(),etaLos[i].c_str(),etaHis[i].c_str(),varname.c_str()));

  }
  c2->Close();

  return 0;
}
void run(const std::string& pt_lo,const std::string& pt_hi,const std::string& eta_lo,const std::string& eta_hi,const std::string& savefile,float factor,const std::string& dirMC,const std::string& dirData, const std::string& inTree,const std::string& cut, const std::string& var,FILE *effTex,const std::string& signal){

  FILE *file; 
  file = fopen("efficiencies.txt","a+");
  printf(TString::Format("runCount = %i \n",runCount));
  // start a new table if at a new pt range 
  bool newPt = atof(pt_lo.c_str()) != currPtLo;
  if (newPt) {
   currPtLo = atof(pt_lo.c_str());
   fprintf(effTex,
	       "%s - %s",pt_lo.c_str(), pt_hi.c_str());
  }

  gROOT->SetBatch(kTRUE);
  
  //gROOT->SetStyle("Plain");
  setTDRStyle();

  RooWorkspace *w = new RooWorkspace("w","workspace");
  string cutPassBarrel;
  string cutFailBarrel;
  
  printf("pt_lo: %s eta_lo:%s \n",pt_lo.c_str(),eta_lo.c_str());

  cutPassBarrel = "("+cut+"matchPass==1&&(abs(eta)>"+eta_lo+"&&abs(eta)<"+eta_hi+")&&("+passCut+")&&pt>"+pt_lo+"&&pt<"+pt_hi+")";
  cutFailBarrel = "("+cut+"matchPass==1&&(abs(eta)>"+eta_lo+"&&abs(eta)<"+eta_hi+")&&("+failCut+")&&pt>"+pt_lo+"&&pt<"+pt_hi+")"; 

  printf("%s \n",cutPassBarrel.c_str());
  printf("%s \n",cutFailBarrel.c_str());


  createWorspace(w,dirData,inTree,cutPassBarrel);
  createHistPdfSig(signal,w,"mcSample",dirMC+signal+".root",inTree,"__WEIGHT__",cutPassBarrel);
  //createHistPdfSig("DYtautau",w,"mcSample",dirMC+"DYtautau.root",inTree,"__WEIGHT__",cutPassBarrel);
  //createHistPdfSig("TOP",w,"mcSample",dirMC+"TOP.root",inTree,"__WEIGHT__",cutPassBarrel);
  //createHistPdfSig("QCDEM",w,"mcSample",dirMC+"QCDEM30.root",inTree,"__WEIGHT__",cutPassBarrel);
  //createHistPdfSig("W",w,"mcSample",dirMC+"W.root",inTree,"__WEIGHT__",cutPassBarrel);

  createHistPdfSig(signal+"Fail",w,"mcSample",dirMC+signal+".root",inTree,"__WEIGHT__",cutFailBarrel);
  //createHistPdfSig("DYtautauFail",w,"mcSample",dirMC+"DYtautau.root",inTree,"__WEIGHT__",cutFailBarrel);
  //createHistPdfSig("TOPFail",w,"mcSample",dirMC+"TOP.root",inTree,"__WEIGHT__",cutFailBarrel);
  //createHistPdfSig("QCDEMFail",w,"mcSample",dirMC+"QCDEM30.root",inTree,"__WEIGHT__",cutFailBarrel);
  //createHistPdfSig("WFail",w,"mcSample",dirMC+"W.root",inTree,"__WEIGHT__",cutFailBarrel);  

  TFile *tmp = new TFile("tmp.root","RECREATE");
  TFile *Data = new TFile(dirData.c_str());
  printf("about to create a data tree\n");
  TTree* tree = (TTree*)Data->Get(inTree.c_str());  
  printf("created data tree\n");
  if(tree==NULL){
        std::cerr << "Could not get tree \n" << std::endl;
  }
  TH1F *hd = new TH1F("hd","hd", bin, lo, hi);
  tree->Draw("mass>>hd",cutPassBarrel.c_str());
  printf("drew the cut\n");
  printf("Passed Events in Data %f\n",hd->Integral());  
  tmp->cd();
  RooDataHist *data = new RooDataHist("data","dataset with mass",*w->var("mass"),hd);

  TH1F *hdFail = new TH1F("hdFail","hdFail", bin, lo, hi);
  tree->Draw("mass>>hdFail",cutFailBarrel.c_str());
  printf("Failed Events in Data %f\n",hdFail->Integral());
  RooDataHist *dataFail = new RooDataHist("dataFail","Fail dataset with mass",*w->var("mass"),hdFail);
  
  delete hd;
  delete hdFail;

  /////////////////Constraints

  double signalYield = constraint(w,signal,dirMC+signal+".root",inTree,"__WEIGHT__",cutPassBarrel,factor,lumi);
  double bkgrdYield =constraint(w,signal,dirMC+signal+".root",inTree,"__WEIGHT__",("((mass<75||mass>105)&&"+cutPassBarrel+")").c_str(),factor,lumi);

  printf("Background Pass Region Yield %f\n", bkgrdYield);
  if(string(signal.c_str()).compare("DYee") == 0){
  	w->factory(TString::Format("nExp[%f,0,1000000000]",(bkgrdYield*2)+10));
       printf("It's DYee!!\n");
       printf("Signal: %s\n",signal.c_str());
  }
  else{
	w->factory(TString::Format("nExp[%f,0,1000000000.0]",bkgrdYield+10));
        printf("It's DYumu!!\n");
  }
 
  //double DYtautauYield = constraint(w,"DYtautau",dirMC+"DYtautau.root",inTree,"__WEIGHT__",cutPassBarrel,factor,lumi);
  //w->factory(TString::Format("nTauTau[%f,0,%f]",DYtautauYield,DYtautauYield*100)); 

  
  //double TOPYield = constraint(w,"TOP",dirMC+"TOP.root",inTree,"__WEIGHT__",cutPassBarrel,factor,lumi);
  //w->factory(TString::Format("nTOP[%f,%f,%f]",TOPYield,TOPYield*0.66,TOPYield*1.33)); 
  
  //double WYield = constraint(w,"W",dirMC+"W.root",inTree,"__WEIGHT__",cutPassBarrel,factor,lumi);
  //w->factory(TString::Format("nW[%f,0,%f]",WYield,WYield*1.33)); 
  
  double SignalFailYield = constraint(w,signal,dirMC+signal+".root",inTree,"__WEIGHT__",cutFailBarrel,factor,lumi);


  double bkgrdFailYield = constraint(w,signal,dirMC+signal+".root",inTree,"__WEIGHT__",("((mass<75||mass>105)&&"+cutFailBarrel+")").c_str(),factor,lumi);
  if (bkgrdFailYield != 0) {
    w->factory(TString::Format("nExpFail[%f,0,%f]",bkgrdFailYield*2+10,bkgrdFailYield*1000));
  }
  else w->factory("nExpFail[10,0,10000000]");
  //***changedforZMuMuw->factory(TString::Format("nExpFail[%f,0,10000000.0]",bkgrdFailYield)); 
  printf("Background Fail Region Yield %f\n",bkgrdFailYield);

  //double DYtautauFailYield = constraint(w,"DYtautau",dirMC+"DYtautau.root",inTree,"__WEIGHT__",cutFailBarrel,factor,lumi);
  //w->factory(TString::Format("nTauTauFail[%f,0,%f]",DYtautauFailYield,DYtautauFailYield*100)); 
  
  //double TOPFailYield = constraint(w,"TOP",dirMC+"TOP.root",inTree,"__WEIGHT__",cutFailBarrel,factor,lumi);
  //w->factory(TString::Format("nTOPFail[%f,%f,%f]",TOPFailYield,TOPFailYield*0.66,TOPFailYield*1.33)); 
  //double WFailYield = constraint(w,"W",dirMC+"W.root",inTree,"__WEIGHT__",cutFailBarrel,factor,lumi);
   // w->factory(TString::Format("nWFail[%f,1,%f]",WFailYield,WFailYield*1.5)); 

 //   printf("Yields for Z->tautau: %f Yield for Background: %f\n",DYtautauYield,bkgrdYield);


  ////////end Yield estimates

  //---------------------
  w->factory("Gaussian::gauss(mass,mg[0,-3,3],sigmaGaus[.2,0.1,10])") ;
  //w->factory(TString::Format("Gaussian::gauss(mass,mg[3,0,6],sigmaGaus[%f,%f,%f])",SigmaMean,SigmaMin,SigmaMax));  
  w->factory("eff[0.5,0.3,1]");

  w->factory(TString::Format("nTotal[%f,0,100000000.0]",3*signalYield));
  //w->factory(TString::Format("nTotal[%f,0,100000000.0]",DYeeYield*1.3));

  //w->factory("CBShape::CB(mass,m2[-2,-5,1],s[5,0,10],a[5,0,10],n[0.5,0,0.9])");
  //if(string(signal).compare("DYee")){
  	w->factory(TString::Format("FCONV::SigGaus(mass,%s,gauss)",signal.c_str()));
 // }
  w->factory("prod::nSig(eff,nTotal)");

 
 // w->factory(TString::Format("nWFail[%f,%f,%f]",WFailYield,WFailYield*0.66,WFailYield*1.33));
  //w->factory("SUM::sum(nSig*SigGaus,nTauTau*DYtautau,nTOP*TOP,nExp*background1,nW*W)") ;
  ///---------------------SUM Pdfs used for fitting Pass Region here--------------------------- (if fits fail to converge it may be necessary to get rid of some pdfs)
 // if(string(signal).compare("DYee")){
  w->factory("SUM::sum(nSig*SigGaus,nExp*background1)") ;
 // }
	
  RooFormulaVar nSigFail("nSigFail","(1-eff)*nTotal",RooArgSet(*w->var("eff"),*w->var("nTotal")));

  w->import(nSigFail);

  w->factory("Gaussian::gaussFail(mass,mgFail[0,-3,3],sigmaGausFail[.1,.05,5])") ;
  //w->factory("CBShape::CBFail(mass,m2[-2,-5,1],s[5,0,10],a[5,0,10],n[0.5,0,0.9])");
  // changed to DYee
 
  if (SignalFailYield == 0.0) {
    // pdf might be zero, use pass shape
    w->factory(TString::Format("FCONV::SigGausFail(mass,%s,gaussFail)",signal.c_str())) ;
  }
  else w->factory(TString::Format("FCONV::SigGausFail(mass,%sFail,gaussFail)",signal.c_str())) ;

  ///---------------------SUM Pdfs used for fitting Fail Region here--------------------------- (if fits fail to converge it may be necessary to get rid of some pdfs)
  w->factory("SUM::sumFail(nSigFail*SigGausFail,nExpFail*background1Fail)") ;

  tmp->cd();

  //-----Define Categories for a COMBINED Fit
  RooDataHist *combData = new RooDataHist("combData","combined data",*w->var("mass"),Index(*w->cat("sample")),Import("Pass",*data),Import("Fail",*dataFail)) ;
  w->factory("SIMUL::smodel(sample,Pass=sum,Fail=sumFail)");

  fitResult result =  fit(w,combData); ///fit done in "fit" function
  printf("--------------Efficiency = %f +- %f-----------------\n",w->var("eff")->getVal(),w->var("eff")->getError());

  //write Data fit to
  fprintf(file,"variable: %s \n", savefile.c_str()); 
  fprintf(file,"%s eta %s Pt Range %s to %s: Efficiency Data = %f +- %f \n",eta_lo.c_str(),eta_hi.c_str(),pt_lo.c_str(),pt_hi.c_str(),w->var("eff")->getVal(),w->var("eff")->getError()); 
 
  x.push_back((atof(pt_hi.c_str()) + atof(pt_lo.c_str()))/2.0);
  xerr.push_back(x[runCount] - atof(pt_lo.c_str()));
  y.push_back(w->var("eff")->getVal());
  yerr.push_back(w->var("eff")->getError()); 
  
 /*// avoid problems with decimal point in filename (so annoying!)
 int eta_lo_f = (int) (100*atof(eta_lo.c_str()));
 int eta_hi_f = (int) (100*atof(eta_hi.c_str()));*/

 //------- Plot Pdfs------ 
 RooPlot *frameDhistP = w->var("mass")->frame();
 //w->pdf("TOP")->plotOn(frameDhistP,LineColor(kMagenta));
 w->pdf(signal.c_str())->plotOn(frameDhistP,LineColor(kRed));
 //w->pdf("DYtautau")->plotOn(frameDhistP,LineColor(kBlue));
 TCanvas *Tcan = new TCanvas("Tcan","CCCC");
 frameDhistP->GetXaxis()->SetTitle(TString::Format("PASS Barrel %s>eta>%s  Probe Pt%s      Mass",eta_lo.c_str(),eta_hi.c_str(),savefile.c_str()));
 frameDhistP->Draw();
 //Tcan->SaveAs(TString::Format("%s/IndividualFits/%s/Pdfs_%s_eta%s-%s_pt%s-%s_PASS.png",signal.c_str(),savefile.c_str(),savefile.c_str(),eta_lo.c_str(),eta_hi.c_str(),pt_lo.c_str(),pt_hi.c_str()));
 delete Tcan;

 RooPlot *frameDhistF = w->var("mass")->frame();
 //w->pdf("TOPFail")->plotOn(frameDhistF,LineColor(kMagenta));
 w->pdf(TString::Format("%sFail",signal.c_str()))->plotOn(frameDhistF,LineColor(kRed));
 //w->pdf("DYtautauFail")->plotOn(frameDhistF,LineColor(kBlue));
 TCanvas *Tcan2 = new TCanvas("Tcan2","CCCC");

 frameDhistF->GetXaxis()->SetTitle(TString::Format("FAIL Barrel   Probe Pt%s      Mass",savefile.c_str()));
 frameDhistF->Draw();
 //Tcan2->SaveAs(TString::Format("%s/IndividualFits/%s/Pdfs_%s_eta%s-%s_pt%s-%s_FAIL.png",signal.c_str(),savefile.c_str(),savefile.c_str(),eta_lo.c_str(),eta_hi.c_str(),pt_lo.c_str(),pt_hi.c_str()));
 delete Tcan2;

  ////-----Finish Plotting PDFs-------------

  
  ////-----Begin Plotting Pass Region--------
  RooPlot *frameDP = w->var("mass")->frame();
  combData->plotOn(frameDP,Cut("sample==sample::Pass"));
  w->cat("sample=Pass");
  w->pdf("smodel")->plotOn(frameDP,Slice(*w->cat("sample"),"Pass"),ProjWData(*combData),DrawOption("L9"));
  w->pdf("smodel")->plotOn(frameDP,Slice(*w->cat("sample"),"Pass"),Components("background1"),ProjWData(*combData),LineColor(kRed),LineStyle(kDashed)) ;
  w->pdf("smodel")->plotOn(frameDP,Components("SigGaus"),Slice(*w->cat("sample"),"Pass"),ProjWData(*combData),LineColor(kOrange),DrawOption("L9")) ;
  //w->pdf("smodel")->plotOn(frameDP,Components("TOP"),Slice(*w->cat("sample"),"Pass"),ProjWData(*combData),LineColor(kMagenta),LineStyle(kDashed)) ;
  //w->pdf("smodel")->plotOn(frameDP,Components("DYtautau"),Slice(*w->cat("sample"),"Pass"),ProjWData(*combData),LineColor(kCyan),LineStyle(kDashed)) ;

  TCanvas *cDP = new TCanvas("cDP","CCCC");

  frameDP->GetXaxis()->SetTitle(TString::Format("PASS   Probe %s      Mass",savefile.c_str()));
  frameDP->Draw();
  cDP->SaveAs(TString::Format("%s/IndividualFits/%s/Pass_%s_eta%s-%s_pt%s-%s_.png",signal.c_str(),savefile.c_str(),savefile.c_str(),eta_lo.c_str(),eta_hi.c_str(),pt_lo.c_str(),pt_hi.c_str()));
  delete cDP;
  delete frameDP;

  ////-----Begin Plotting Fail Region--------
  RooPlot *frameDF = w->var("mass")->frame();
  combData->plotOn(frameDF,Cut("sample==sample::Fail"));
  w->pdf("smodel")->plotOn(frameDF,Slice(*w->cat("sample"),"Fail"),ProjWData(*combData),DrawOption("C"));
  w->pdf("smodel")->plotOn(frameDF,Components("background1Fail"),Slice(*w->cat("sample"),"Fail"),ProjWData(*combData),LineColor(kRed),LineStyle(kDashed)) ;
  w->pdf("smodel")->plotOn(frameDF,Components("SigGausFail"),Slice(*w->cat("sample"),"Fail"),ProjWData(*combData),LineColor(kOrange),DrawOption("L9")) ;
  //w->pdf("smodel")->plotOn(frameDF,Components("DYtautauFail"),Slice(*w->cat("sample"),"Fail"),ProjWData(*combData),LineColor(kCyan),LineStyle(kDashed)) ;
  //w->pdf("smodel")->plotOn(frameDF,Components("TOPFail"),Slice(*w->cat("sample"),"Fail"),ProjWData(*combData),LineColor(kMagenta),LineStyle(kDashed)) ;
  //w->pdf("smodel")->plotOn(frameDF,Components("WFail"),Slice(*w->cat("sample"),"Fail"),ProjWData(*combData),LineColor(kCyan),LineStyle(kDashed)) ;
  TCanvas *cDF = new TCanvas("cDF","CCCC");
  frameDF->GetXaxis()->SetTitle(TString::Format("Fail Probe %s    Mass",savefile.c_str()));
  frameDF->Draw();
  cDF->SaveAs(TString::Format("%s/IndividualFits/%s/Fail_%s_eta%s-%s_pt%s-%s_.png",signal.c_str(),savefile.c_str(),savefile.c_str(),eta_lo.c_str(),eta_hi.c_str(),pt_lo.c_str(),pt_hi.c_str()));
  delete cDF;
  delete frameDF;
  delete tmp;

  ////////Create MC to Fit
  //w->factory("eff2[0.5,0.001,1]");
  TFile *tmp1 = new TFile("tmp1.root","RECREATE");
  TH1F *MCfit = new TH1F("MCfit","MCfit", bin, lo, hi);
  TH1F *MCfitFail = new TH1F("MCfitFail","MCfit", bin, lo, hi);

  printf("-----%f------- \n",MCfit->Integral(0,60));

  TH1F *signalHist = createHist(w,signal,dirMC+signal+".root",inTree,"__WEIGHT__",cutPassBarrel,factor,lumi);
  //TH1F *DYtautauHist = createHist(w,"DYtautau",dirMC+"DYtautau.root",inTree,"__WEIGHT__",cutPassBarrel,factor,lumi);
  //TH1F *TOPHist = createHist(w,"TOP",dirMC+"TOP.root",inTree,"__WEIGHT__",cutPassBarrel,factor,lumi);
  //TH1F *WHist = createHist(w,"W",dirMC+"W.root",inTree,"__WEIGHT__",cutPassBarrel,factor,lumi);

  MCfit->Add(signalHist);
  //MCfit->Add(DYtautauHist);
  //MCfit->Add(TOPHist);
  //MCfit->Add(WHist);

  TH1F *signalHistFail = createHist(w,signal,dirMC+signal+".root",inTree,"__WEIGHT__",cutFailBarrel,factor,lumi);
  //TH1F *DYtautauHistFail = createHist(w,"DYtautau",dirMC+"DYtautau.root",inTree,"__WEIGHT__",cutFailBarrel,factor,lumi);
  //TH1F *TOPHistFail = createHist(w,"TOP",dirMC+"TOP.root",inTree,"__WEIGHT__",cutFailBarrel,factor,lumi);
  //TH1F *WHistFail = createHist(w,"W",dirMC+"W.root",inTree,"__WEIGHT__",cutFailBarrel,factor,lumi);

  MCfitFail->Add(signalHistFail);
  //MCfitFail->Add(DYtautauHistFail);
  //MCfitFail->Add(TOPHistFail);
  //MCfitFail->Add(WHistFail);

  RooDataHist *MCFail = new RooDataHist("MCfail","MC Fail",*w->var("mass"),MCfitFail);
  RooDataHist *MCPass = new RooDataHist("MCHistfit","Weighted MC with mass",*w->var("mass"),MCfit);

  RooDataHist *combDataMC = new RooDataHist("combDataMC","combined dataMC",*w->var("mass"),Index(*w->cat("sample")),Import("Pass",*MCPass),Import("Fail",*MCFail)) ;

  fitResult resultMC  =  fit(w,combDataMC);

  fprintf(file,"%s eta %s Pt Range %s to %s: Efficiency MC = %f +- %f \n",eta_lo.c_str(),eta_hi.c_str(),pt_lo.c_str(),pt_hi.c_str(),w->var("eff")->getVal(),w->var("eff")->getError()); 
  
  // add efficiencies to graph
  //xmc[runCount]=atof(pt_lo.c_str())+5;
  //xmcerr[runCount]=5;
  ymc.push_back(w->var("eff")->getVal());
  ymcerr.push_back(w->var("eff")->getError());
  //add efficiencies to LaTeX table
  cFactor.push_back(y[runCount]/ymc[runCount]);
  cFactorErr.push_back((y[runCount]/ymc[runCount])* TMath::Sqrt(TMath::Power((yerr[runCount]/y[runCount]),2.0) + TMath::Power((ymcerr[runCount]/ymc[runCount]),2.0)));
  fprintf(effTex," & \\parbox[c]{1.1 in}{ \\scriptsize  Data: %.3f $\\pm$ %.3f \\newline MC: %.3f $\\pm$ %.3f \\newline $\\frac{\\rm{Data}}{\\rm{MC}}$: %.3f $\\pm$ %.3f}",y[runCount],yerr[runCount],ymc[runCount],ymcerr[runCount],cFactor[runCount],cFactorErr[runCount]);
  ////////////////////////////////////////////////

  RooPlot *frameMCPass = w->var("mass")->frame();

  combDataMC->plotOn(frameMCPass,Cut("sample==sample::Pass"));
  

  w->cat("sample=Pass");
  printf("getsHere Line466 \n");
  w->pdf("smodel")->plotOn(frameMCPass,Slice(*w->cat("sample"),"Pass"),ProjWData(*combDataMC),DrawOption("L9"));
  w->pdf("smodel")->plotOn(frameMCPass,Slice(*w->cat("sample"),"Pass"),Components("background1"),ProjWData(*combDataMC),LineColor(kRed),LineStyle(kDashed)) ;
  w->pdf("smodel")->plotOn(frameMCPass,Components("SigGaus"),Slice(*w->cat("sample"),"Pass"),ProjWData(*combDataMC),LineColor(kOrange),DrawOption("L9")) ;
  //w->pdf("smodel")->plotOn(frameMCPass,Components("TOP"),Slice(*w->cat("sample"),"Pass"),ProjWData(*combDataMC),LineColor(kMagenta),LineStyle(kDashed)) ;
  //w->pdf("smodel")->plotOn(frameMCPass,Components("DYtautau"),Slice(*w->cat("sample"),"Pass"),ProjWData(*combDataMC),LineColor(kCyan),LineStyle(kDashed)) ;

  
  TCanvas *cMCP = new TCanvas("cMCP","CCCC");


  frameMCPass->GetXaxis()->SetTitle(TString::Format("MC PASS  Probe %s      Mass",savefile.c_str()));
  frameMCPass->Draw();
  cMCP->SaveAs(TString::Format("%s/IndividualFits/%s/PassMC_%s_eta%s-%s_pt%s-%s_.png",signal.c_str(),savefile.c_str(),savefile.c_str(),eta_lo.c_str(),eta_hi.c_str(),pt_lo.c_str(),pt_hi.c_str()));

  delete cMCP;
  delete frameMCPass;


  ////////////////////////////////////////////////


  RooPlot *frameMCFail = w->var("mass")->frame();
  combDataMC->plotOn(frameMCFail,Cut("sample==sample::Fail"));
  printf("Passes to Here Line 498 ----\n");
  //RooAbsPdf *sumFail = w->pdf("sumFail");
  w->cat("sample=Fail");
  w->pdf("smodel")->plotOn(frameMCFail,Slice(*w->cat("sample"),"Fail"),ProjWData(*combDataMC),DrawOption("C"));
  w->pdf("smodel")->plotOn(frameMCFail,Components("background1Fail"),Slice(*w->cat("sample"),"Fail"),ProjWData(*combDataMC),LineColor(kRed),LineStyle(kDashed)) ;
  w->pdf("smodel")->plotOn(frameMCFail,Components("SigGausFail"),Slice(*w->cat("sample"),"Fail"),ProjWData(*combDataMC),LineColor(kOrange),DrawOption("L9")) ;
  //w->pdf("smodel")->plotOn(frameMCFail,Components("DYtautauFail"),Slice(*w->cat("sample"),"Fail"),ProjWData(*combDataMC),LineColor(kCyan),LineStyle(kDashed)) ;
  //w->pdf("smodel")->plotOn(frameMCFail,Components("TOPFail"),Slice(*w->cat("sample"),"Fail"),ProjWData(*combDataMC),LineColor(kMagenta),LineStyle(kDashed)) ;
  //w->pdf("smodel")->plotOn(frameMCFail,Components("WFail"),Slice(*w->cat("sample"),"Fail"),ProjWData(*combDataMC),LineColor(kCyan),LineStyle(kDashed)) ;

  TCanvas *cMCF = new TCanvas("cMCF","CCCC");


    frameMCFail->GetXaxis()->SetTitle(TString::Format("Fail   Probe %s      Mass",savefile.c_str()));
    frameMCFail->Draw();
    cMCF->SaveAs(TString::Format("%s/IndividualFits/%s/FailMC_%s_eta%s-%s_pt%s-%s_.png",signal.c_str(),savefile.c_str(),savefile.c_str(),eta_lo.c_str(),eta_hi.c_str(),pt_lo.c_str(),pt_hi.c_str()));

  
  delete cMCF;
  delete frameMCFail;
  //delete tmp;
  //delete hd;
  //delete hdFail;  
  

  


  fclose(file); /*done!*/ 
  //getchar(); /* pause and wait for key */ 
  //return 0; 

  ///////////////////////////////////////////////

  //delete tmp1;

  runCount++;
  // assume that if running on endcap the next pt range will be new (should probably fix)
/*  if (atof(eta_hi.c_str())==2.4) {  
    fprintf(effTex, TString::Format("\\hline \n"
                      "\\end{tabular}\n"
                      "\\end{center}\n"
                      "\\caption {Efficiencies-Pt %s to %s}\n"
                      "\\label{tab:cqdata0}\n"
                      "\\end{table}\n\n" ,pt_lo.c_str(),pt_hi.c_str()));
  }*/
  
} 

void createWorspace(RooWorkspace *w,const std::string& signalFile,const std::string& treeDir,const std::string& cut) {
  using namespace RooFit;
  //Create a common variable for the invariant mass                                                                                                                                                            
  RooRealVar mass("mass","mass",91,lo,hi);
  mass.setBins(bin); //needed to correctly do fit
  w->import(mass);
  w->var("mass")->setPlotLabel("l^{+} l^{-} Mass [GeV/c^{2}]");
  w->factory("sample[Pass=1,Fail=0]");
  //CREATE THE CATEGORY                                                                                                                                                                                        
  w->factory(TString::Format("%s[pass=1,fail=0]","prefix"));
  w->factory("__WEIGHT__[0.5,0.,100]");

  w->factory("b1[0,-7,0]");
  w->factory("b2[0,-7,0]");
  w->factory("NpassB[1,1,10000000.]");
  w->factory("NfailB[1,1,100000.]");
  RooRealVar bkrdRange("bkrdRange","bkrdRange",lo,hi);
  w->import(bkrdRange);
  //declare background PDFS
  w->factory("Exponential::background1(mass,b1)");
  w->factory("Exponential::background1Fail(mass,b2)");
  //w->factory("Polynomial::background1(mass,{aPoly[0,-10,10],bPoly[0,-10,10],cPoly[0,-10,10],dPoly[0,-10,10],ePoly[0,-10,10]})");
  //w->factory("Polynomial::background1Fail(mass,{aPolyFail[0,-10,10],bPolyFail[0,-10,10],cPolyFail[-0,-10,10],dPolyFail[0,-10,10],ePolyFail[0,-10,10]})");
  //w->factory("Polynomial::background1(mass,{aPoly[10,-10,1000],bPoly[-10,-100,1000]})");
  //w->factory("Polynomial::background1Fail(mass,{aPolyFail[10,-10,1000],bPolyFail[-10,-100,1000]})");
 
  
   
  printf("Background pdfs declared\n");


}



fitResult fitMC(RooWorkspace* w, RooDataHist* combData,  RooDataHist* dataFail )
{ 

   TFile *ff = new TFile("tmp2.root","RECREATE");
   ff->cd();
   //RooRealVar *mass = w->var("mass");
   w->pdf("smodel")->fitTo(*combData,SumW2Error(kFALSE));
   fitResult result;
   result.efficiency = w->var("eff")->getVal();
   result.efficiencyError = w->var("eff")->getError();
  //int stats;
  //result.status = stats;
  //printf("--------------Efficiency = %f +- %f-----------------\n",w->var("eff")->getVal(),w->var("eff")->getError());
  //fprintf(file,"%s","This is just an example :)"); /*writes*/ 

  ff->Close();
  return result;

}


fitResult fit(RooWorkspace* w , RooDataHist* combData)
{ 

   TFile *ff = new TFile("tmp2.root","RECREATE");
   ff->cd();
   //RooRealVar *mass = w->var("mass");
   w->pdf("smodel")->fitTo(*combData,SumW2Error(kFALSE));
   fitResult result;
   
   //int stats;
   //stats = result.status();
   //printf("the result status = %i\n",stats);


   result.efficiency = w->var("eff")->getVal();
   result.efficiencyError = w->var("eff")->getError();
   printf("--------------Efficiency = %f +- %f-----------------\n",w->var("eff")->getVal(),w->var("eff")->getError());
   ff->Close();
   return result;

}



///create a function that calls create dataset and creates a roohistPDF
void createHistPdfSig(const std::string& name,RooWorkspace *w,const std::string& var,const std::string& file,const std::string& treeDir,const std::string& weightString,const std::string& cut)
{
  TFile *ff = new TFile("tmp2.root","RECREATE");
  ff->cd();
  TFile *f = new TFile(file.c_str());
  TTree *t = (TTree*)f->Get(treeDir.c_str());
  //t->Print();
  TH1F *he = new TH1F("he","he",binmc,lo,hi);
  //RooRealVar *mass = w->var("mass");
  printf("about the draw the cut\n");
  t->Draw("mass>>he",cut.c_str());
  printf("drew the cut\n");
  
  RooDataHist *mc = new RooDataHist((name+"mc").c_str(),"mc",*w->var("mass"),he);//binned dat
  printf("created a roodatahist\n");
  //w->factory("RooHistPdf::mcPdf(mass,*mc,he)");
  RooHistPdf *MCPdf = new RooHistPdf(name.c_str(),name.c_str(),*w->var("mass"),*mc,2);//set interpolation here
  printf("created a roohistpdf\n");
  int x = MCPdf->getInterpolationOrder();

  w->import(*MCPdf,RenameConflictNodes(name.c_str())); 
  printf("imported w\n");
  delete MCPdf;
  delete mc;
  delete t;
  delete he;
  ff->Close();
  delete ff;
  printf("done with everything\n");
}

void createHistPdfBkd(const std::string& name,RooWorkspace *w,const std::string& var,const std::string& file,const std::string& treeDir,const std::string& weightString,const std::string& cut)
{
  TFile *ff = new TFile("tmp2.root","RECREATE");
  ff->cd();
  TFile *f = new TFile(file.c_str());
  TTree *t = (TTree*)f->Get(treeDir.c_str());
    if(t==NULL){
       printf("Could not get tree \n");
  }
  //t->Print();
  TH1F *he = new TH1F("he","he",binmc,lo,hi);

  t->Draw("mass>>he",cut.c_str());
  

  RooDataHist *mc = new RooDataHist((name+"mc").c_str(),"mc",*w->var("bkrdRange"),he);//binned dat

  RooHistPdf *MCBkdPdf = new RooHistPdf(name.c_str(),name.c_str(),*w->var("bkrdRange"),*mc);

  w->import(*MCBkdPdf,RenameConflictNodes(name.c_str())); 
  
  delete MCBkdPdf;
  delete mc;
  delete t;
  delete he;
 ff->Close();
  delete ff;


}


RooDataHist *createDataSet(RooWorkspace *w,const std::string& var,const std::string& file,const std::string& treeDir,const std::string& weightString,const std::string& cut)
{
  TFile *f = new TFile(file.c_str());
  TFile* tmp = new TFile("tmp.root","RECREATE");

  tmp->cd();
  TTree *t = (TTree*)f->Get(treeDir.c_str());
  TTree *t2 = t->CopyTree(cut.c_str());


  RooRealVar * mass = w->var("mass");
  RooRealVar NSig("NSig","NSig",50000,0,1000000);
  TH1F *dat = new TH1F("dat","dat",600,lo,hi);

  RooDataHist *data = new RooDataHist("data", "dsd",*mass,dat);
  RooDataHist *data1 = new RooDataHist("data1", "dsd",*mass,dat);

  
  data->Print();
  printf("Gets Here\n");
  w->import(*data1);
  
  return data;
  delete t2;
  //ff->Close();
}

TH1F *createHist(RooWorkspace *w,const std::string& name,const std::string& file,const std::string& treeDir,const std::string& weightString,const std::string& cut, float factor, float lumi)
{
  TFile *f = new TFile(file.c_str());
  TFile* tmp = new TFile("tmp.root","RECREATE");


  TTree *t = (TTree*)f->Get(treeDir.c_str());
  TH1F *DYee = new TH1F(name.c_str(),name.c_str(), bin, lo, hi);

  t->Draw(("mass>>"+name).c_str(),TString::Format("(%s)*__WEIGHT__*%f*%f",cut.c_str(),lumi,factor));
  printf("Line 617-%s----------- %f\n",name.c_str(),DYee->Integral());


  return DYee;
  delete t; 
  delete f;
  delete tmp;

}


float constraint(RooWorkspace *w,const std::string& name,const std::string& file,const std::string& treeDir,const std::string& weightString,const std::string& cut, float factor, float lumi)
{
  TFile *f = new TFile(file.c_str());
  TFile* tmp = new TFile("tmp.root","RECREATE");


  TTree *t = (TTree*)f->Get(treeDir.c_str());
  
  TH1F *DYee = new TH1F(name.c_str(),name.c_str(), bin, lo, hi);

  t->Draw(("mass>>"+name).c_str(),TString::Format("(%s)*__WEIGHT__*%f*%f",cut.c_str(),lumi,factor));  


  printf("Integral of-%s----------- %f\n",name.c_str(),DYee->Integral());
  float Val = DYee->Integral();

  return Val;
  delete t; 
  delete f;
  delete tmp;

}
