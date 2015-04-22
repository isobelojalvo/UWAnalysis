#include "TH1F.h"
#include "TH2F.h"
#include "THStack.h"
#include "TTree.h"
#include "TChain.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TProfile.h"
#include "TGraphErrors.h"
#include <vector>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


class SimplePlotter {
public:
  SimplePlotter() {}
  ~SimplePlotter() {}
  


  void addFile(TString tree,TString name,TString label,TString preselection,int type,Color_t color,Color_t lcolor,int style = 1001)
  {
    TChain *chain = new TChain(tree);
    chain->Add(name);
    trees_.push_back(chain);
    labels_.push_back(label);
    types_.push_back(type);
    colors_.push_back(color);
    lcolors_.push_back(lcolor);
    styles_.push_back(style);
    preselection_.push_back(preselection);

  } 



  TCanvas* makeProfile(TString var,TString selection,int binsx, float minX, float maxX,float minY,float maxY,TString labelX,TString labelY,TString addLabel,double xLabel,double yLabel,double yLabel2,TString postFix = "")
  {
    TProfile *profile = new TProfile("profile","",binsx,minX,maxX,minY,maxY);
    profile->Sumw2();
    for(unsigned int i=0;i<trees_.size();++i)
      {
	if(types_[i]){//MC
	  trees_[i]->Draw(var +">>profile",preselection_[i]+"*("+selection+")","goff");
	  profile->SetMarkerStyle(20);
	}
      }
    profile->GetXaxis()->SetTitle(labelX);
    profile->GetYaxis()->SetTitle(labelY);
    profile->GetYaxis()->SetRangeUser(minY,maxY);
    
    TCanvas *c= new TCanvas(var+postFix,var+postFix,600,600);
    c->cd();
    profile->Draw();

    TLatex *l1 = new TLatex(xLabel,yLabel,"CMS Preliminary 2011!");
    l1->SetTextSize(0.045);
    l1->Draw();
    TLatex *l2 = new TLatex(xLabel,yLabel2,addLabel);
    l2->SetTextSize(0.035);
    l2->Draw();
    return c;
  }


  void make2D(TString var,TString selection,int binsx, float minX, float maxX,int binsy,float minY,float maxY,TString labelX,TString labelY,TString addLabel,double xLabel,double yLabel,double yLabel2,TString postFix = "")
  {
    for(unsigned int i=0;i<trees_.size();++i)
      {
	TCanvas *c= new TCanvas(var+postFix+labels_[i],var+postFix+labels_[i],600,600);
	  c->cd();
	  TH2F *profile = new TH2F("profile"+labels_[i],"",binsx,minX,maxX,binsy,minY,maxY);
	  profile->Sumw2();

	    trees_[i]->Draw(var +">>profile"+labels_[i],preselection_[i]+"*("+selection+")","goff");

	    //	  profile->Scale(1./profile->Integral());
	  profile->SetMarkerStyle(20);
	  profile->GetXaxis()->SetTitle(labelX);
	  profile->GetYaxis()->SetTitle(labelY);
	  profile->GetYaxis()->SetRangeUser(minY,maxY);
	  profile->SetContour(80);
	  profile->Draw("CONT4");
	  // TLatex *l1 = new TLatex(xLabel,yLabel,"CMS Preliminary 2010");
	  // l1->SetTextSize(0.045);
	  // l1->Draw();
	  // TLatex *l2 = new TLatex(xLabel,yLabel2,addLabel);
	  // l2->SetTextSize(0.035);
	  // l2->Draw();
      }
  }



  TCanvas* makeStackedPlot(TString var,TString selection,TString lumi, int bins, float min, float max,TString labelX,TString units,double xLegend,double yLegend,bool log,TString postFix = "",bool grid = true)
  {
    THStack *hs = new THStack("hs","CMS Preliminary 2010");
    TLegend *l = new TLegend(xLegend,yLegend,xLegend+0.3,yLegend+0.3*trees_.size()/4.);
    
    float S=0.;
    float B=0.;
    float MCErr=0.0;
    Double_t err=0.0;

    float DATA=0.0;
    

    TH1F * signal = new TH1F("signal","",bins,min,max);
    signal->Sumw2();


     std::vector<TH1F*> histos;
    for(unsigned int i=0;i<trees_.size();++i)
      {
	TH1F * hh = new TH1F("hh","",bins,min,max);
	hh->Sumw2();
	if(types_[i]<=0){//MC
	  trees_[i]->Draw(var +">>hh",lumi+"*1000*"+preselection_[i]+"*("+selection+")","goff");
	  hh->SetLineWidth(2);
	  hh->SetFillColor(colors_[i]);
	  hh->SetFillStyle(styles_[i]);

	  hh->SetLineColor(lcolors_[i]);
	  hh->SetName("hh"+var);
	  if(types_[i]==-1) {
	    S+=hh->IntegralAndError(1,hh->GetNbinsX(),err);
	    MCErr+=err*err;

	    signal->Add(hh);
	    signal->SetLineWidth(2);
	    signal->SetFillColor(colors_[i]);
	    signal->SetFillStyle(styles_[i]);
	    signal->SetLineColor(lcolors_[i]);

	  }
	  else if(types_[i]==0) {
	    B+=hh->IntegralAndError(1,hh->GetNbinsX(),err);
	    MCErr+=err*err;

	  }
	  histos.push_back(hh);

	  printf(" %s = %f\n",labels_[i].Data(),hh->Integral());

	}
	else {
	  trees_[i]->Draw(var +">>hh",preselection_[i]+"*("+selection+")","goff");
	  hh->SetMarkerStyle(20);
	  hh->SetLineWidth(2);
	  histos.push_back(hh);
	  DATA+=hh->Integral();
	}
      }
    for(unsigned int i=0;i<histos.size();++i) {

      if(types_[i]==0)
	hs->Add(histos[i]);

      //make the legend here 
      if(labels_[types_.size()-1-i]!="") {
	if(types_[types_.size()-1-i]<=0)
	  l->AddEntry(histos[labels_.size()-1-i],labels_[labels_.size()-1-i],"f");	else
	  l->AddEntry(histos[labels_.size()-1-i],labels_[labels_.size()-1-i],"p");
      }						
    }

  
   
    l->SetFillColor(kWhite);
    l->SetBorderSize(0);

    
    TCanvas *c;
    if(log)
      c = new TCanvas(var+"LOG"+postFix,var+"LOG"+postFix,600,600);
    else
      c = new TCanvas(var+postFix,var+postFix,600,600);

    c->SetLeftMargin(0.15);   

    c->cd();
    if(log)
      c->SetLogy();

    for(unsigned int i=0;i<trees_.size();++i)
      if(types_[i]>0)//DATA
      {
	if(units=="")
	  histos[i]->GetXaxis()->SetTitle(labelX);
	else
	  histos[i]->GetXaxis()->SetTitle(labelX+"["+units+"]");
	  
	TString s("Events / ");
	char binW[200];
	sprintf(binW,"%1.1f",histos[i]->GetBinWidth(1));
	
	s+=binW;
	s+=" "+units;
	histos[i]->GetYaxis()->SetTitle(s);
	histos[i]->GetYaxis()->SetTitleOffset(1.2);

	histos[i]->Draw("e1");
	if(!log)
	  histos[i]->GetYaxis()->SetRangeUser(0.1,histos[i]->GetMaximum()*1.2);
	else
	  histos[i]->GetYaxis()->SetRangeUser(0.1,histos[i]->GetMaximum()*100);
      }
    

    printf("C\n");  
  
    hs->Add(signal);
    hs->Draw("A,HIST,SAME");

    for(unsigned int i=0;i<trees_.size();++i)
      if(types_[i]>0)//DATA
      {
	histos[i]->Draw("e1,SAME");
      }
    l->Draw();


    printf("S = %f \n",S);
    printf("B = %f \n",B);
    printf("MC = %f +-%f\n",S+B,sqrt(MCErr));
    printf("DATA = %f +- %f\n",DATA,sqrt(DATA));
    printf("Purity = S/(S+B) = %f\n",S/(S+B));
    printf("Significance1 = S/SQRT(S+B) = %f\n",S/sqrt(S+B));
    printf("Significance2 = S/SQRT(B) = %f\n",S/sqrt(B));

    if(grid)
      {
	c->SetGridx();
	c->SetGridy();
      }
    c->Update();
    c->RedrawAxis();
    return c;
  }



  TCanvas* makeStackedPlotRatio(TString var,TString selection,TString lumi, int bins, float min, float max,TString labelX,TString units,double xLegend,double yLegend,bool log,float syst = 0.0,TString postFix = "",bool grid = true)
  {
    THStack *hs = new THStack("hs","CMS Preliminary 2010");
    TLegend *l = new TLegend(xLegend,yLegend,xLegend+0.3,yLegend+0.3*trees_.size()/4.);
    
    float S=0.;
    float B=0.;
    float MCErr=0.0;
    Double_t err=0.0;

    float DATA=0.0;
    

    TH1F * signal = new TH1F("signal","",bins,min,max);
    signal->Sumw2();

    TH1F * dataH = new TH1F("dataH","",bins,min,max);
    TH1F * mcH   = new TH1F("mcH","",bins,min,max);

    dataH->Sumw2();
    mcH->Sumw2();

     std::vector<TH1F*> histos;
    for(unsigned int i=0;i<trees_.size();++i)
      {
	TH1F * hh = new TH1F("hh","",bins,min,max);
	hh->Sumw2();
	if(types_[i]<=0){//MC
	  trees_[i]->Draw(var +">>hh",lumi+"*1000*"+preselection_[i]+"*("+selection+")","goff");
	  hh->SetLineWidth(2);
	  hh->SetFillColor(colors_[i]);
	  hh->SetFillStyle(styles_[i]);

	  hh->SetLineColor(lcolors_[i]);
	  hh->SetName("hh"+var);
	  if(types_[i]==-1) {
	    S+=hh->IntegralAndError(1,hh->GetNbinsX(),err);
	    MCErr+=err*err;

	    signal->Add(hh);
	    signal->SetLineWidth(2);
	    signal->SetFillColor(colors_[i]);
	    signal->SetFillStyle(styles_[i]);
	    signal->SetLineColor(lcolors_[i]);
	    
	  }
	  else if(types_[i]==0) {
	    B+=hh->IntegralAndError(1,hh->GetNbinsX(),err);
	    MCErr+=err*err;

	  }
	  histos.push_back(hh);
	  mcH->Add(hh);
	  printf(" %s = %f\n",labels_[i].Data(),hh->Integral());

	}
	else {
	  trees_[i]->Draw(var +">>hh",preselection_[i]+"*("+selection+")","goff");
	  hh->SetMarkerStyle(20);
	  hh->SetLineWidth(2);
	  histos.push_back(hh);
	  DATA+=hh->Integral();
	  dataH->Add(hh);
	}
      }
    for(unsigned int i=0;i<histos.size();++i) {

      if(types_[i]==0)
	hs->Add(histos[i]);

      //make the legend here 
      if(labels_[types_.size()-1-i]!="") {
	if(types_[types_.size()-1-i]<=0)
	  l->AddEntry(histos[labels_.size()-1-i],labels_[labels_.size()-1-i],"f");	else
	  l->AddEntry(histos[labels_.size()-1-i],labels_[labels_.size()-1-i],"p");
      }						
    }

  
   
    l->SetFillColor(kWhite);
    l->SetFillStyle(1);
    l->SetBorderSize(1);

    
    TCanvas *c;
    if(log)
      c = new TCanvas(var+"LOG"+postFix,var+"LOG"+postFix,600,600);
    else
      c = new TCanvas(var+postFix,var+postFix,600,600);

    c->SetLeftMargin(0.15);   


    TPad * plotPad = new TPad("pad1","",0.0,0.3,1.0,1.0);
    TPad * ratioPad = new TPad("pad2","",0.0,0.0,1.0,0.3);

    plotPad->Draw();
    ratioPad->Draw();
    plotPad->cd();

    if(log)
      plotPad->SetLogy();

    for(unsigned int i=0;i<trees_.size();++i)
      if(types_[i]>0)//DATA
      {
	if(units=="")
	  histos[i]->GetXaxis()->SetTitle(labelX);
	else
	  histos[i]->GetXaxis()->SetTitle(labelX+"["+units+"]");
	  
	TString s("Events  ");
	char binW[200];
	sprintf(binW," / %1.1f",histos[i]->GetBinWidth(1));
	
	s+=binW;
	s+=" "+units;

	if(units=="")
	  s="Events";

	histos[i]->GetYaxis()->SetTitle(s);
	histos[i]->GetYaxis()->SetTitleOffset(1.0);

	histos[i]->Draw("e1");
	if(!log)
	  histos[i]->GetYaxis()->SetRangeUser(0.1,histos[i]->GetMaximum()*1.2);
	else
	  histos[i]->GetYaxis()->SetRangeUser(0.1,histos[i]->GetMaximum()*100);
      }
    

    printf("C\n");  
  
    hs->Add(signal);
    hs->Draw("A,HIST,SAME");

    for(unsigned int i=0;i<trees_.size();++i)
      if(types_[i]>0)//DATA
      {
	histos[i]->Draw("e1,SAME");
      }
    l->Draw();


    printf("S = %f \n",S);
    printf("B = %f \n",B);
    printf("MC = %f +-%f\n",S+B,sqrt(MCErr));
    printf("DATA = %f +- %f\n",DATA,sqrt(DATA));
    printf("Purity = S/(S+B) = %f\n",S/(S+B));
    printf("Significance1 = S/SQRT(S+B) = %f\n",S/sqrt(S+B));
    printf("Significance2 = S/SQRT(B) = %f\n",S/sqrt(B));

    if(grid)
      {
	plotPad->SetGridx();
	plotPad->SetGridy();
      }
    plotPad->Update();
    plotPad->RedrawAxis();

    ratioPad->cd();

    dataH->Divide(dataH,mcH);
    dataH->SetMarkerStyle(20);

    dataH->GetYaxis()->SetTitle("Data/MC");
    dataH->GetYaxis()->SetTitleOffset(0.42);
    dataH->GetYaxis()->SetTitleSize(0.12);
    dataH->GetYaxis()->SetLabelSize(0.12);
    dataH->GetXaxis()->SetLabelSize(0.12);
    dataH->GetYaxis()->SetNdivisions(5);
    dataH->GetYaxis()->SetRangeUser(0.5,1.5);



	ratioPad->SetGridx();
	ratioPad->SetGridy();




    TGraphErrors* g = new TGraphErrors();

    g->GetYaxis()->SetTitle("Data/MC");
    g->GetYaxis()->SetTitleOffset(0.42);
    g->GetYaxis()->SetTitleSize(0.12);
    g->GetYaxis()->SetLabelSize(0.12);
    g->GetXaxis()->SetLabelSize(0.12);
    g->GetYaxis()->SetNdivisions(5);
    g->GetYaxis()->SetRangeUser(0.5,1.5);

    int C=0;
    for(int i=1;i<=dataH->GetNbinsX();++i) 
      if(dataH->GetBinContent(i)>0)
      {
	g->SetPoint(C,dataH->GetXaxis()->GetBinCenter(i),dataH->GetBinContent(i));
	g->SetPointError(C,dataH->GetXaxis()->GetBinWidth(i)/2.,sqrt(dataH->GetBinError(i)*dataH->GetBinError(i)+dataH->GetBinContent(i)*dataH->GetBinContent(i)*syst*syst));

	C++;
      }
    dataH->Draw("P");
    g->SetFillColor(kYellow);
    g->Draw("3,same");
    dataH->Draw("Psame");


    plotPad->cd();
    return c;
  }


  void   extractPU(TString selection, int bins, float min, float max)
  {
	TH1F * mc = new TH1F("mcPU","",bins,min,max);
	TH1F * data = new TH1F("dataPU","",bins,min,max);
	mc->Sumw2();
	data->Sumw2();
    
	for(unsigned int i=0;i<trees_.size();++i)
	  {
	    TH1F * hh = new TH1F("hh","",bins,min,max);
	    hh->Sumw2();
	    if(types_[i]<=0){//MC
	      trees_[i]->Draw("vertices>>hh",preselection_[i]+"*("+selection+")","goff");
	      mc->Add(hh);
	    }
	    else {
	      trees_[i]->Draw("vertices>>hh",preselection_[i]+"*("+selection+")","goff");
	      data->Add(hh);
	    }
	  }

	//normalize
	mc->Scale(1./mc->Integral());
	data->Scale(1./data->Integral());
	
	TFile *f = new TFile("puInfo.root","RECREATE");
	f->cd();
	mc->Write();
	data->Write();
	data->SetDirectory(0);
	data->SetName("weight");
	data->Divide(mc);
	data->Write();
	f->Close();
  }
  void   extractRho(TString selection, int bins, float min, float max)
  {
	TH1F * mc = new TH1F("mcRho","",bins,min,max);
	TH1F * data = new TH1F("dataRho","",bins,min,max);
	mc->Sumw2();
	data->Sumw2();
    
	for(unsigned int i=0;i<trees_.size();++i)
	  {
	    TH1F * hh = new TH1F("hh","",bins,min,max);
	    hh->Sumw2();
	    if(types_[i]<=0){//MC
	      trees_[i]->Draw("Rho>>hh",preselection_[i]+"*("+selection+")","goff");
	      mc->Add(hh);
	    }
	    else {
	      trees_[i]->Draw("Rho>>hh",preselection_[i]+"*("+selection+")","goff");
	      data->Add(hh);
	    }
	  }

	//normalize
	mc->Scale(1./mc->Integral());
	data->Scale(1./data->Integral());
	
	TFile *f = new TFile("rhoInfo.root","RECREATE");
	f->cd();
	mc->Write();
	data->Write();
	data->SetDirectory(0);
	data->SetName("weight");
	data->Divide(mc);
	data->Write();
	f->Close();
  }





  TCanvas* makeStackedNormalizedPlot(TString var,TString selection,TString lumi, int bins, float min, float max,TString labelX,TString units,double xLabel,double yLabel,double yLabel2,double xLegend,double yLegend,bool log,double ymin,double ymax,TString postFix = "",bool ofl = false )
  {
    THStack *hs = new THStack("hs","CMS Preliminary 2010");
    TLegend *l = new TLegend(xLegend,yLegend,xLegend+0.3,yLegend+0.3);
    
    float S=0.;
    float B=0.;
    float DATA=0.0;

     std::vector<TH1F*> histos;
    for(unsigned int i=0;i<trees_.size();++i)
      {
	TH1F * hh = new TH1F("hh","",bins,min,max);
	hh->Sumw2();
	if(types_[i]<=0){//MC
	  trees_[i]->Draw(var +">>hh",lumi+"*"+preselection_[i]+"*("+selection+")","goff");
	  hh->SetLineWidth(2);
	  hh->SetFillColor(colors_[i]);
	  hh->SetFillStyle(styles_[i]);

	  hh->SetLineColor(lcolors_[i]);
	  hh->SetName("hh"+var);
	  if(types_[i]==-1) 
	    S+=hh->Integral();
	  else if(types_[i]==0)
	    B+=hh->Integral();
	  histos.push_back(hh);
	}
	else {
	  trees_[i]->Draw(var +">>hh",preselection_[i]+"*("+selection+")","goff");
	  hh->SetMarkerStyle(20);
	  hh->SetLineWidth(2);
	  histos.push_back(hh);
	  DATA+=hh->Integral();
	}
      }
    for(unsigned int i=0;i<histos.size();++i) {
      if(ofl)
	{
	  histos[i]->SetBinContent(bins,histos[i]->GetBinContent(bins)+
				   histos[i]->GetBinContent(bins+1));
	  histos[i]->SetBinContent(bins+1,0.0);
	}
      
      


      if(types_[i]<=0) {
	histos[i]->Scale(1./(S+B));
	hs->Add(histos[i]);
      }
      //make the legend here 
      if(labels_[types_.size()-1-i]!="") {
	if(types_[types_.size()-1-i]<=0)
	  l->AddEntry(histos[labels_.size()-1-i],labels_[labels_.size()-1-i],"f");	else
	  l->AddEntry(histos[labels_.size()-1-i],labels_[labels_.size()-1-i],"p");
      }						
    } 							
   
    l->SetFillColor(kWhite);
    l->SetBorderSize(0);

    
    TCanvas *c;
    if(log)
      c = new TCanvas(var+"LOG"+postFix,var+"LOG"+postFix,600,600);
    else
      c = new TCanvas(var+postFix,var+postFix,600,600);

    c->cd();
    if(log)
      c->SetLogy();

    for(unsigned int i=0;i<trees_.size();++i)
      if(types_[i]>0)//DATA
      {
	if(units=="")
	  histos[i]->GetXaxis()->SetTitle(labelX);
	else
	  histos[i]->GetXaxis()->SetTitle(labelX+"["+units+"]");
	  
	TString s("a u. ");
	histos[i]->GetYaxis()->SetTitle(s);
	histos[i]->DrawNormalized("e1");
	histos[i]->GetYaxis()->SetRangeUser(ymin,ymax);
      }
    

    printf("C\n");  
    hs->Draw("A,HIST,SAME");

    TLatex *l1 = new TLatex(xLabel,yLabel,"CMS  2010");
    l1->SetTextSize(0.04);
    l1->Draw();
    TLatex *l2 = new TLatex(xLabel,yLabel2,"L_{int} = "+lumi+" pb^{-1}, #sqrt{s} = 7 TeV");
    l2->SetTextSize(0.04);
    l2->Draw();


    for(unsigned int i=0;i<trees_.size();++i)
      if(types_[i]>0)//DATA
      {
	histos[i]->DrawNormalized("e1,SAME");
      }
    l->Draw();


    printf("S = %f \n",S);
    printf("B = %f \n",B);
    printf("MC = %f \n",S+B);
    printf("DATA = %f \n",DATA);
    printf("Purity = S/(S+B) = %f\n",S/(S+B));
    printf("Significance1 = S/SQRT(S+B) = %f\n",S/sqrt(S+B));
    printf("Significance2 = S/SQRT(B) = %f\n",S/sqrt(B));
    c->RedrawAxis();
    return c;
  }










  TCanvas* makeComparison(TString var,TString selection,TString lumi, int bins, float min, float max,TString labelX)
  {
    THStack *hs = new THStack("hs","");
    TLegend *l = new TLegend(0.6,0.6,0.9,0.9);
    

     std::vector<TH1F*> histos;
    for(unsigned int i=0;i<trees_.size();++i)
      {
	TH1F * hh = new TH1F("hh","hh",bins,min,max);
	hh->Sumw2();
	trees_[i]->Draw(var +">>hh",lumi+"*"+preselection_[i]+"*("+selection+")","goff");
	if(lumi=="1")  
	  hh->Scale((float)1./hh->Integral());

	if(lumi=="0")  
	  hh->Scale((float)1./hh->GetEntries());


	printf(" %s = %f\n",labels_[i].Data(),hh->Integral());
	
	hh->SetLineWidth(3);
	hh->SetLineColor(lcolors_[i]);
	hh->SetFillColor(colors_[i]);
	hh->SetFillStyle(styles_[i]);
	hh->SetName("hh"+var);
	hh->GetXaxis()->SetTitle(labelX);
	hh->GetYaxis()->SetTitle("a.u");

	if(styles_[i]!=0)
	  l->AddEntry(hh,labels_[i],"lf");	
	else
	  l->AddEntry(hh,labels_[i],"l");	

	histos.push_back(hh);
	
      }
    for(unsigned int i=0;i<histos.size();++i)
	hs->Add(histos[i]);
   
    l->SetFillColor(kWhite);
    l->SetBorderSize(0);
    
    TCanvas * c = new TCanvas(var,var,600,600);
    c->cd();
    c->SetLeftMargin(c->GetLeftMargin()*1.1);

    hs->Draw("HIST,NOSTACK");
    hs->GetXaxis()->SetTitle(labelX);
    hs->GetYaxis()->SetTitle("a.u");
    hs->GetYaxis()->SetNdivisions(505);
    hs->GetYaxis()->SetTitleOffset(1.25);

    l->Draw();

    c->RedrawAxis();
    return c;
  }






  TCanvas* makeStackedPlotAndSave(TString var,TString selection,TString lumi, int bins, float min, float max,TString labelX,TString units,double xLabel,double yLabel,double yLabel2,double xLegend,double yLegend,bool log,double ymin,double ymax,TString postFix = "" )
  {
    THStack *hs = new THStack("hs","CMS Preliminary 2010");
    TLegend *l = new TLegend(xLegend,yLegend,xLegend+0.3,yLegend+0.3);
    TFile *f = new TFile("histograms.root","RECREATE");
    f->cd();

    float S=0.;
    float B=0.;
    float DATA=0.0;

     std::vector<TH1F*> histos;
    for(unsigned int i=0;i<trees_.size();++i)
      {
	TH1F * hh = new TH1F("hh","",bins,min,max);
	hh->Sumw2();
	if(types_[i]<=0){//MC
	  trees_[i]->Draw(var +">>hh",lumi+"*"+preselection_[i]+"*("+selection+")","goff");
	  hh->SetLineWidth(2);
	  hh->SetFillColor(colors_[i]);
	  hh->SetFillStyle(styles_[i]);

	  hh->SetLineColor(kBlack);
	  hh->SetName("hh"+var);
	  if(types_[i]==-1) 
	    S+=hh->Integral();
	  else if(types_[i]==0)
	    B+=hh->Integral();
	  l->AddEntry(hh,labels_[i],"f");
	  histos.push_back(hh);

	  hh->SetName(labels_[i]);
	  hh->Write();
	  
	}
	else {
	  trees_[i]->Draw(var +">>hh",preselection_[i]+"*("+selection+")","goff");
	  hh->SetMarkerStyle(20);
	  l->AddEntry(hh,labels_[i],"p");
	  histos.push_back(hh);
	  DATA+=hh->Integral();

	  hh->SetName(labels_[i]);
	  hh->Write();
	}
      }
    for(unsigned int i=0;i<histos.size();++i)
      if(types_[i]<=0)
	hs->Add(histos[i]);
   
    l->SetFillColor(kWhite);
    l->SetBorderSize(0);

    
    TCanvas *c;
    if(log)
      c = new TCanvas(var+"LOG"+postFix,var+"LOG"+postFix,600,600);
    else
      c = new TCanvas(var+postFix,var+postFix,600,600);

    c->cd();
    if(log)
      c->SetLogy();

    for(unsigned int i=0;i<trees_.size();++i)
      if(types_[i]>0)//DATA
      {
	if(units=="")
	  histos[i]->GetXaxis()->SetTitle(labelX);
	else
	  histos[i]->GetXaxis()->SetTitle(labelX+"["+units+"]");
	  
	TString s("Events / ");
	char binW[200];
	sprintf(binW,"%1.1f",histos[i]->GetBinWidth(1));
	
	s+=binW;
	s+=" "+units;
	histos[i]->GetYaxis()->SetTitle(s);
	histos[i]->Draw("e1");
	histos[i]->GetYaxis()->SetRangeUser(ymin,ymax);
      }
    

    printf("C\n");  
    hs->Draw("A,HIST,SAME");

    TLatex *l1 = new TLatex(xLabel,yLabel,"CMS Preliminary 2010");
    l1->SetTextSize(0.04);
    l1->Draw();
    TLatex *l2 = new TLatex(xLabel,yLabel2,"L_{int} = "+lumi+" pb^{-1}, #sqrt{s} = 7 TeV");
    l2->SetTextSize(0.04);
    l2->Draw();


    for(unsigned int i=0;i<trees_.size();++i)
      if(types_[i]>0)//DATA
      {
	histos[i]->Draw("e1,SAME");
      }
    l->Draw();


    printf("S = %f \n",S);
    printf("B = %f \n",B);
    printf("MC = %f \n",S+B);
    printf("DATA = %f \n",DATA);
    printf("Purity = S/(S+B) = %f\n",S/(S+B));
    printf("Significance1 = S/SQRT(S+B) = %f\n",S/sqrt(S+B));
    printf("Significance2 = S/SQRT(B) = %f\n",S/sqrt(B));
   

    f->Close();

    return c;
  }







private:
  std::vector<TChain*> trees_;
  std::vector<TString> labels_;
  std::vector<TString> preselection_;
  std::vector<int> types_;
  std::vector<int> styles_;
  std::vector<Color_t> colors_;
  std::vector<Color_t> lcolors_;
};
