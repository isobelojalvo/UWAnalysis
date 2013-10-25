#include "TStyle.h"
/*
// just after root

.L tdrstyle.C
gROOT->Reset();
setTDRStyle();

 */
// tdrGrid: Turns the grid lines on (true) or off (false)

void tdrGrid(bool gridOn) {
  tdrStyle->SetPadGridX(gridOn);
  tdrStyle->SetPadGridY(gridOn);
}

// fixOverlay: Redraws the axis

void fixOverlay() {
  gPad->RedrawAxis();
}


void applyStyle(TH1F *h) {
  h->GetXaxis()->SetLabelSize(0.050);
  h->SetLineWidth(3);
  h->GetYaxis()->SetLabelSize(0.050);
  h->GetXaxis()->SetTitleSize(0.055);
  h->GetYaxis()->SetTitleSize(0.055);
  h->GetXaxis()->SetTitleFont(42);
  h->GetYaxis()->SetTitleFont(42);
  h->GetXaxis()->SetLabelFont(42);
  h->GetYaxis()->SetLabelFont(42);
  h->SetMarkerSize (1.4);

}


void cms(int type = 1)
{
  TLatex latex;
  latex.SetNDC();
  latex.SetTextSize(0.05);
  latex.SetTextAlign(11);
  if(type==1)
    latex.DrawLatex(0.15,0.94,"CMS  2011, L = 4.7 fb^{-1}, #sqrt{s} = 7 TeV")->Draw();
  if(type==2)
    latex.DrawLatex(0.15,0.94,"CMS Simulation, #sqrt{s} = 7 TeV")->Draw();
  if(type==3)
    latex.DrawLatex(0.25,0.94,"CMS  2011, L = 4.7 fb^{-1}, #sqrt{s} = 7 TeV")->Draw();


}


void setTDRStyle() {
  TStyle *tdrStyle = new TStyle("tdrStyle","Style for P-TDR");

  tdrStyle->SetCanvasColor     (0);
  tdrStyle->SetCanvasBorderSize(10);
  tdrStyle->SetCanvasBorderMode(0);
  tdrStyle->SetCanvasDefH      (700);
  tdrStyle->SetCanvasDefW      (700);
  tdrStyle->SetCanvasDefX      (100);
  tdrStyle->SetCanvasDefY      (100);

  // color palette for 2D temperature plots
  tdrStyle->SetPalette(1,0);
  
  // Pads
  tdrStyle->SetPadColor       (0);
  tdrStyle->SetPadBorderSize  (5);
  tdrStyle->SetPadBorderMode  (0);
  tdrStyle->SetPadBorderMode  (0);
  tdrStyle->SetPadBottomMargin(0.15);
  tdrStyle->SetPadTopMargin   (0.08);
  tdrStyle->SetPadLeftMargin  (0.12);
  tdrStyle->SetPadRightMargin (0.07);
  tdrStyle->SetPadGridX       (0);
  tdrStyle->SetPadGridY       (0);
  tdrStyle->SetPadTickX       (1);
  tdrStyle->SetPadTickY       (1);

  // Frames
  tdrStyle->SetLineWidth(3);
  tdrStyle->SetFrameFillStyle ( 0);
  tdrStyle->SetFrameFillColor ( 0);
  tdrStyle->SetFrameLineColor ( 1);
  tdrStyle->SetFrameLineStyle ( 0);
  tdrStyle->SetFrameLineWidth ( 2);
  tdrStyle->SetFrameBorderSize(5);
  tdrStyle->SetFrameBorderMode( 0);

  
  tdrStyle->SetFillStyle( 0);

  // Histograms
  tdrStyle->SetHistFillColor(2);
  tdrStyle->SetHistFillStyle(0);
  tdrStyle->SetHistLineColor(1);
  tdrStyle->SetHistLineStyle(0);
  tdrStyle->SetHistLineWidth(4);
  tdrStyle->SetNdivisions(510);

  // Functions
  tdrStyle->SetFuncColor(1);
  tdrStyle->SetFuncStyle(0);
  tdrStyle->SetFuncWidth(2);

  // Various
  tdrStyle->SetMarkerStyle(20);
  tdrStyle->SetMarkerColor(kBlack);
  tdrStyle->SetMarkerSize (1.4);

  tdrStyle->SetTitleBorderSize(0);
  tdrStyle->SetTitleFillColor (0);
  tdrStyle->SetTitleX         (0.2);

  tdrStyle->SetTitleSize  (0.055,"X");
  tdrStyle->SetTitleOffset(1.200,"X");
  tdrStyle->SetLabelOffset(0.005,"X");
  tdrStyle->SetLabelSize  (0.050,"X");
  tdrStyle->SetLabelFont  (42   ,"X");

  tdrStyle->SetStripDecimals(kFALSE);

  tdrStyle->SetTitleSize  (0.055,"Y");
  tdrStyle->SetTitleOffset(1.000,"Y");
  tdrStyle->SetLabelOffset(0.010,"Y");
  tdrStyle->SetLabelSize  (0.050,"Y");
  tdrStyle->SetLabelFont  (42   ,"Y");

  tdrStyle->SetTextSize   (0.055);
  tdrStyle->SetTextFont   (42);

  tdrStyle->SetStatFont   (42);
  tdrStyle->SetTitleFont  (42);
  tdrStyle->SetTitleFont  (42,"X");
  tdrStyle->SetTitleFont  (42,"Y");

  tdrStyle->SetOptStat    (0);
  tdrStyle->SetOptTitle    (0);

  tdrStyle->SetLineStyleString(11,"20 10");


  tdrStyle->SetLegendBorderSize(0);




  tdrStyle->cd();
}
