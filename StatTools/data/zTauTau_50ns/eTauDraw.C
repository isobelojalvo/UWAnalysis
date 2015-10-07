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


void eTauDraw(){
	//TFile *f    = new TFile("eleTau_m_visSS.root");
	TFile *f    = new TFile("eleTau_mt_1_SS.root");
	f->cd("eleTau_inclusive");

	THStack *hs = new THStack("hs","SS Yields and Shapes");
	ZTT->SetFillColor(kOrange);
	W->SetFillColor(kRed+3);
	TT->SetFillColor(kBlue-9);
	QCD->SetFillColor(kPink+2);
	VV->SetFillColor(kGreen+3);
	data_obs->SetMarkerStyle(22);
	data_obs->SetMarkerColor(kBlack);

	hs->Add(TT);
	hs->Add(VV);
	hs->Add(W);
	hs->Add(W);
	hs->Add(W);
	hs->Add(ZTT);


        hs->SetMaximum(120);
	hs->Draw();

	data_obs->Draw("sameE0");

	TLegend *legend=new TLegend(0.6,0.65,0.88,0.85);
	legend->AddEntry(ZTT,"ZTT");
	legend->AddEntry(W,"W");
	legend->AddEntry(VV,"VV");
	legend->AddEntry(TT,"TT");
	legend->AddEntry(data_obs,"2015B data SS");
	legend->Draw("same");
}
