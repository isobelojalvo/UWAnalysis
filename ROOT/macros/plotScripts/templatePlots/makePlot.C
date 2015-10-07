
 void applyStyle(TH1F* h, Color_t fill, Color_t line,int fillStyle)
 {
   h->SetFillColor(fill);
   h->SetLineColor(line);
   h->SetLineWidth(2);
   h->SetFillStyle(fillStyle);
 }


 void applySignalStyle(TH1F* h)
 {
   h->SetFillStyle(0);
   h->SetLineWidth(3);
   h->SetLineColor(kBlue+3);
   h->SetLineStyle(7);
 }


 void applyDATAStyle(TH1F* h)
 {
   h->SetMarkerStyle(20.);
   h->SetMarkerSize (1.3);
   h->SetLineWidth  ( 3.);

 }

 void convertToDNDM(TH1F* histo) {
   for(int i=1;i<=histo->GetNbinsX();++i) {
     histo->SetBinContent(i,histo->GetBinContent(i)/histo->GetXaxis()->GetBinWidth(i));
     histo->SetBinError(i,histo->GetBinError(i)/histo->GetXaxis()->GetBinWidth(i));
   }
 }



 makeLTauStack(TString name,TString file,TString dir,int s,TString labelX,TString units = "GeV",bool left=false,TString channel = "",TString year = "2015",bool log = false,bool dndm=false,bool doRatio = false)
 {
  gROOT->LoadMacro("tdrstyle.C");
  setTDRStyle();

  //gROOT->LoadMacro("CMS_lumi.C");

  //writeExtraText = true;       // if extra text
 // extraText  = "Preliminary";  // default extra text is "Preliminary"
//  lumi_8TeV  = "19.1 fb^{-1}"; // default is "19.7 fb^{-1}"
 // lumi_7TeV  = "4.9 fb^{-1}";  // default is "5.1 fb^{-1}"

//  int iPeriod = 4;    // 1=7TeV, 2=8TeV, 3=7+8TeV, 7=7+8+13TeV 


   float xR=0.45;
   if(left)
     xR=0.2;


   if(doRatio){
	 TCanvas * c = new TCanvas(name,name,600,600);
   }
   else{
	 TCanvas * c = new TCanvas(name,name,600,600);
     c->SetLeftMargin     (0.18);
     c->SetRightMargin    (0.05);
     c->SetTopMargin      (0.08);
     c->SetBottomMargin   (0.15);
   }



   c->cd();

   if(doRatio){
	 TPad * plotPad = new TPad("pad1","",0.0,0.3,1.0,1.0);
	 plotPad->SetLeftMargin  (0.18);
     plotPad->SetTopMargin   (0.10);
     plotPad->SetRightMargin (0.07);
     plotPad->SetBottomMargin(0.03); 
     TPad * ratioPad = new TPad("pad2","",0.0,0.0,1.0,0.3);
     ratioPad->SetLeftMargin  (0.18);
     ratioPad->SetTopMargin   (0.00);
     ratioPad->SetRightMargin (0.07);
     ratioPad->SetBottomMargin(0.30);
     ratioPad->SetGridy(1);
   }
   else{
	 TPad * plotPad = new TPad("pad1","",0.0,0.0,1.0,1.0);
	 plotPad->SetLeftMargin     (0.18);
     plotPad->SetRightMargin    (0.05);
     plotPad->SetTopMargin      (0.08);
     plotPad->SetBottomMargin   (0.15);
   }

   plotPad->Draw();
   plotPad->cd();


   TFile *f = new TFile(file);


   TH1F * data = (TH1F*)(f->Get(dir+"/data_obs"));
   if (dndm) convertToDNDM(data);

   applyDATAStyle(data);

   TH1F * QCD = (TH1F*)(f->Get(dir+"/QCD"));
   if (dndm) convertToDNDM(QCD);

   applyStyle(QCD,kMagenta-10,1,1001);

   TH1F * ttbar = (TH1F*)(f->Get(dir+"/TT"));
   if (dndm) convertToDNDM(ttbar);
   applyStyle(ttbar,kBlue-8,1,1001);

	 if(channel == "#tau_{e}#tau_{h}" || channel == "#tau_{#mu}#tau_{h}"){

	   TH1F * EWK = (TH1F*)(f->Get(dir+"/W"));
	   EWK->Add((TH1F*)(f->Get(dir+"/VV")));
	   if (dndm) convertToDNDM(EWK);
	   applyStyle(EWK,kRed+2,1,1001);

	   if(f->Get(dir+"/ZLL")!=0)
		 TH1F * ZEE = (TH1F*)(f->Get(dir+"/ZLL"));	  	
	   if(f->Get(dir+"/ZL")!=0&&f->Get(dir+"/ZLL")==0)
		 TH1F * ZEE = (TH1F*)(f->Get(dir+"/ZL"));
	   if(f->Get(dir+"/ZJ")!=0&&f->Get(dir+"/ZLL")==0)
		 ZEE->Add((TH1F*)(f->Get(dir+"/ZJ")));

	   if (dndm) convertToDNDM(ZEE);
	   applyStyle(ZEE,kAzure+2,1,1001);	

	 }
	 else {

	   TH1F * EWK = (TH1F*)(f->Get(dir+"/W"));
	   if(f->Get(dir+"/ZL")!=0)
		 EWK->Add((TH1F*)(f->Get(dir+"/ZL")),1.);
	   if(f->Get(dir+"/ZJ")!=0)
		 EWK->Add((TH1F*)(f->Get(dir+"/ZJ")));
	   if(f->Get(dir+"/ZLL")!=0)
		 EWK->Add((TH1F*)(f->Get(dir+"/ZLL")));
	   EWK->Add((TH1F*)(f->Get(dir+"/VV")));

	   if (dndm) convertToDNDM(EWK);
	   applyStyle(EWK,kRed+2,1,1001);

	 }

   TH1F * ZTT = (TH1F*)(f->Get(dir+"/ZTT"));
   if (dndm) convertToDNDM(ZTT);
   applyStyle(ZTT,kOrange-4,kBlack,1001);

   TH1F *signal=0;

   if(s==1) {
     TH1F * MSSM = (TH1F*)(f->Get(dir+"/ggH160"));
     MSSM->Scale(1.875);
     TH1F * MSSM2 = (TH1F*)(f->Get(dir+"/bbH160"));
     MSSM2->Scale(5.96);
     MSSM->Add(MSSM2);
     MSSM->SetLineStyle(11);

     signal=MSSM;
   if (dndm) convertToDNDM(signal);

     applySignalStyle(signal);

   }
   else if(s==2) {
     TH1F * MSSM = (TH1F*)(f->Get(dir+"/GGHNoJet120"));
     MSSM->Add((TH1F*)(f->Get(dir+"/GGHJet120")));
     MSSM->Scale(11.22);
     TH1F * MSSM2 = (TH1F*)(f->Get(dir+"/BBHNoJet120"));
     MSSM2->Add((TH1F*)(f->Get(dir+"/BBHJet120")));
     MSSM2->Add((TH1F*)(f->Get(dir+"/BBHBJet120")));
     MSSM2->Scale(16.);
     MSSM->Add(MSSM2);
     MSSM->SetLineStyle(11);
     signal=MSSM;
   if (dndm) convertToDNDM(signal);

     applySignalStyle(signal);

   }
   else if(s==3) {
     TH1F * SM = (TH1F*)(f->Get(dir+"/ggH125"));
     TH1F *sm = SM;
     sm->Scale(1);//FIXME
     TH1F * SM2 = (TH1F*)(f->Get(dir+"/qqH125"));
     TH1F *sm2 = SM2;
     sm2->Scale(1);//FIXME
     sm->Add(sm2);
     sm->SetLineStyle(11);
     signal=sm;

   if (dndm) convertToDNDM(signal);

     applySignalStyle(signal);
   }
   else if(s==4) {
     TH1F * MSSM = (TH1F*)(f->Get(dir+"/ggHTohhTo2Tau2B300"));
     MSSM->Scale(1);
     MSSM->SetLineStyle(11);

     signal=MSSM;
   if (dndm) convertToDNDM(signal);

     applySignalStyle(signal);

   }

   THStack *hs = new THStack("hs","");
   TLegend *l = new TLegend(xR,0.6,xR+0.5,0.9);

   l->AddEntry(data,"Observed","P");

   l->AddEntry(ZTT,"Z#rightarrow #tau #tau","F");
   l->AddEntry(EWK,"Electroweak","F");
   l->AddEntry(QCD,"QCD","F");
   l->AddEntry(ttbar,"t#bar{t}","F");
   if(channel == "#tau_{e}#tau_{h}") l->AddEntry(ZEE,"Z#rightarrow ee","F");
   if(channel == "#tau_{#mu}#tau_{h}") l->AddEntry(ZEE,"Z#rightarrow #mu#mu","F");


   if(log){
	   if(s<3&&s>0)
		 l->AddEntry(signal,"#phi#rightarrow #tau #tau(m_{A}=120 GeV,tan#beta=20)","L");
	   else if(s==3)
		 l->AddEntry(signal,"SM H(125) #rightarrow #tau #tau","L");
   }
   else{
	   if(s<3&&s>0)
		 l->AddEntry(signal,"10X #phi#rightarrow #tau #tau(m_{A}=160 GeV,tan#beta=8)","F");
	   else if(s==3)
		 l->AddEntry(signal,"SM H(125) #rightarrow #tau #tau","F");
	   if(s==4){
	     l->AddEntry(signal,"#splitline{10X H#rightarrow hh#rightarrow #tau#tau bb}{ (m_{H}=300 GeV,tan#beta=2)}","F");
	     l->SetTextSize(0.025);
	   }
   }


   hs->Add(ttbar);
   hs->Add(QCD);
   hs->Add(EWK);
   if(channel == "#tau_{e}#tau_{h}") hs->Add(ZEE);
   if(channel == "#tau_{#mu}#tau_{h}") hs->Add(ZEE);
   hs->Add(ZTT);

 //if(s>0&(!log))
 //  hs->Add(signal);


   // if(sm) {
   //   TH1F * SM = (TH1F*)(f->Get(dir+"/SM120"));
   //   SM->Add((TH1F*)(f->Get(dir+"/VBF120")));
   //   applyStyle(SM,kGray+2,1,3005);
   //   hs->Add(SM);
   // }
   //  else {
   //  hs->Add(MSSM);



   hs->Draw("HIST");
     hs->SetMaximum(hs->GetMaximum()*1.8);
   //if(data->GetMaximum()*1.2+sqrt(data->GetMaximum())>hs->GetMaximum()) {
    // float max=0.0;
    // if(data->GetMaximum()>hs->GetMaximum())
    //   max=data->GetMaximum();
   //  else
   //    max=hs->GetMaximum();

     //if(log) {
      // max*=10;
      // hs->SetMinimum(0.5);
    // }
    // hs->SetMaximum(max*1.5+sqrt(data->GetMaximum()));

  // }
   //else{
    // hs->SetMaximum(hs->GetMaximum()*1.8);
   //}
   if(dndm)       hs->SetMinimum(0.001);


   hs->Draw("HIST");
   if(doRatio){
	 hs->GetXaxis()->SetLabelSize(0);
   }
   else
   {
	   if(units!="")
		 hs->GetXaxis()->SetTitle(labelX+" ["+units+"]");
	   else
		 hs->GetXaxis()->SetTitle(labelX);
   }

   hs->GetYaxis()->SetTitle("Events");
   if(dndm)
     hs->GetYaxis()->SetTitle("dN/d"+labelX);

   if(s>0)
     signal->Draw("HIST,SAME");

   data->Draw("e,SAME");


   c->cd();

   if(doRatio){

     TH1F * data2 = (TH1F*)data->Clone("data");
     TH1F * mc = (TH1F*)(ttbar);
     mc->Add(QCD);
     mc->Add(EWK);
     mc->Add(ZTT);
     //BUG WAS HERE
     //if(channel == "#tau_{e}#tau_{h}") 
     mc->Add(ZEE);
    
    double xmin = mc->GetXaxis()->GetXmin();
    double xmax = mc->GetXaxis()->GetXmax();
    TLine *line = new TLine(xmin,1.0,xmax,1.0);
    line->SetLineWidth(3);
    line->SetLineColor(kBlack);
    
    
    ratioPad->Draw();
  	ratioPad->cd();
  	

  	data2->Divide(data2,mc);
  	

    data2->SetMarkerStyle(20);
    data2->SetTitleSize  (0.12,"Y");
    data2->SetTitleOffset(0.60,"Y");
    data2->SetTitleSize  (0.12,"X");
    data2->SetLabelSize  (0.10,"X");
    data2->SetLabelSize  (0.08,"Y");
    data2->GetYaxis()->SetTitleFont(42);
    data2->GetYaxis()->CenterTitle(kTRUE);
    data2->GetXaxis()->SetTitleFont(42);
    data2->GetYaxis()->SetRangeUser(0.5,2);
    data2->GetYaxis()->SetNdivisions(305);
    data2->GetYaxis()->SetTitle("Data/MC");
    data2->SetMarkerSize(1);
    gStyle->SetOptTitle(0);


    if(units!="")
	  data2->GetXaxis()->SetTitle(labelX+" ["+units+"]");
    else
	  data2->GetXaxis()->SetTitle(labelX);
	  
    data2->Draw("P");
    line->Draw();
    
    
    
  }
  
  c->cd();
  plotPad->cd();  

//  if(!log){
	  l->SetBorderSize(0);
	  l->SetFillColor(0);
	  l->SetFillStyle (0);
	
	  l->Draw();
//  }

  float factor=0.0;
  if(left) factor = 1./2.2;
  else factor = 1.05;


  float xL = hs->GetXaxis()->GetXmin()+(hs->GetXaxis()->GetXmax()-hs->GetXaxis()->GetXmin())*xR*factor;
  float yL = hs->GetMaximum()*0.35;

  if(log)
  yL = hs->GetMaximum()*0.35;

  float offsetF=yL-0.1*hs->GetMaximum();
  float offsetFF=yL-0.2*hs->GetMaximum();

  if(log) {

    offsetF=yL/2.;
    offsetFF=yL/5.;

  }


  TLatex latex;
  latex.SetNDC();
  if(doRatio)
  	latex.SetTextSize(0.05);
  else
  	latex.SetTextSize(0.04);
  	
  latex.SetTextAlign(11);

  latex.SetTextFont(42);
 // latex.DrawLatex(0.20,0.94,"CMS Preliminary 2015, 40 pb^{-1}, #sqrt{s} = 13 TeV      "+channel);
  latex.DrawLatex(0.20,0.94,"CMS Preliminary 2015D, ~130 pb^{-1}, #sqrt{s} = 13 TeV      "+channel);

 if(log)
   plotPad->SetLogy();

 // c->RedrawAxis(); 
  c->SaveAs(name+".png");
  c->SaveAs(name+".pdf");
  c->SaveAs(name+".root");

}



makeLTauStackPF(TString name,TString file,TString dir,int s,TString labelX,TString units = "GeV",bool left=false,TString channel = "",TString year = "2012",bool log = false,bool dndm=false, Double_t ztt, Double_t tt, Double_t w, Double_t zj, Double_t zl, Double_t vv, Double_t qcd, Double_t err, bool doRatio=false)
{
  setStyle();

  float xR=0.45;
  if(left)
    xR=0.2;



	TCanvas * c = new TCanvas(name,name,600,600);
	c->SetLeftMargin     (0.18);
	c->SetRightMargin    (0.05);
	c->SetTopMargin      (0.08);
	c->SetBottomMargin   (0.15);


  c->cd();
  
  if(doRatio){
  	TPad * plotPad = new TPad("pad1","",0.0,0.3,1.0,1.0);
  	plotPad->SetLeftMargin  (0.18);
    plotPad->SetTopMargin   (0.10);
    plotPad->SetRightMargin (0.07);
    plotPad->SetBottomMargin(0.03); 
    TPad * ratioPad = new TPad("pad2","",0.0,0.0,1.0,0.3);
    ratioPad->SetLeftMargin  (0.18);
    ratioPad->SetTopMargin   (0.00);
    ratioPad->SetRightMargin (0.07);
    ratioPad->SetBottomMargin(0.30);
    ratioPad->SetGridy(1);
  }
  else{
  	TPad * plotPad = new TPad("pad1","",0.0,0.0,1.0,1.0);
  	plotPad->SetLeftMargin     (0.18);
    plotPad->SetRightMargin    (0.05);
    plotPad->SetTopMargin      (0.08);
    plotPad->SetBottomMargin   (0.15);
  }
  
  plotPad->Draw();
  plotPad->cd();
  
  
  TFile *f = new TFile(file);


  TH1F * data = (TH1F*)(f->Get(dir+"/data_obs"));
  if (dndm) convertToDNDM(data);

  applyDATAStyle(data);

  TH1F * QCD = (TH1F*)(f->Get(dir+"/QCD"));
  TH1F *q = QCD;
  q->Scale(qcd);
  if (dndm) convertToDNDM(q);

  applyStyle(q,kMagenta-10,1,1001);

  TH1F * ttbar = (TH1F*)(f->Get(dir+"/TT"));
  TH1F *TT = ttbar;
  TT->Scale(tt);
  if (dndm) convertToDNDM(TT);
  applyStyle(TT,kBlue-8,1,1001);

  TH1F *EWK;
  
	if(channel == "#tau_{e}#tau_{h}"){

	  TH1F * W = (TH1F*)(f->Get(dir+"/W"));
      EWK = W;
      EWK->Scale(w);	
	  TH1F * VV = (TH1F*)(f->Get(dir+"/VV"));
      TH1F *diboson = VV;
      diboson->Scale(vv);	            
	  EWK->Add(diboson);

	  if (dndm) convertToDNDM(EWK);
	  applyStyle(EWK,kRed+2,1,1001);
	  	
	  if(f->Get(dir+"/ZL")!=0){
		TH1F * ZEE = (TH1F*)(f->Get(dir+"/ZL"));
		TH1F *zee = ZEE;
		zee->Scale(zl);
	  }
	  if(f->Get(dir+"/ZJ")!=0){
		TH1F * ZJ = (TH1F*)(f->Get(dir+"/ZJ"));
		TH1F *zjft = ZJ;
		zjft->Scale(zj);
		zee->Add(zjft);
	  }
	  if(f->Get(dir+"/ZLL")!=0){
		TH1F * ZEE = (TH1F*)(f->Get(dir+"/ZLL"));
		TH1F *zee = ZEE;
		zee->Scale(zl);
	  }
	  if (dndm) convertToDNDM(zee);
	  applyStyle(zee,kAzure+2,1,1001);	
	  
	}
	else {
	
	  TH1F * W = (TH1F*)(f->Get(dir+"/W"));
      EWK = W;
      EWK->Scale(w);	
	  TH1F * VV = (TH1F*)(f->Get(dir+"/VV"));
      TH1F *diboson = VV;
      diboson->Scale(vv);	            
	  EWK->Add(diboson);

	  if(f->Get(dir+"/ZL")!=0){
		TH1F * ZLL = (TH1F*)(f->Get(dir+"/ZL"));
		TH1F *zll = ZLL;
		zll->Scale(zl);
	  }
	  if(f->Get(dir+"/ZJ")!=0){
		TH1F * ZJ = (TH1F*)(f->Get(dir+"/ZJ"));
		TH1F *zjft = ZJ;
		zjft->Scale(zj);
		EWK->Add(zjft);
	  }
	  if(f->Get(dir+"/ZLL")!=0){
		TH1F * ZLL = (TH1F*)(f->Get(dir+"/ZLL"));
		TH1F *zll = ZLL;
		zll->Scale(zl);
	  }
	  EWK->Add(zll);		
	  if (dndm) convertToDNDM(EWK);
	  applyStyle(EWK,kRed+2,1,1001);

	}
	
  TH1F * ZTT = (TH1F*)(f->Get(dir+"/ZTT"));
  TH1F *ztautau = ZTT;
  ztautau->Scale(ztt);  
  if (dndm) convertToDNDM(ztautau);
  applyStyle(ztautau,kOrange-4,kBlack,1001);


  THStack *hs = new THStack("hs","");
  TLegend *l = new TLegend(xR,0.6,xR+0.5,0.9);

  l->AddEntry(data,"Observed","P");


  l->AddEntry(ztautau,"Z#rightarrow #tau #tau","F");
  l->AddEntry(EWK,"Electroweak","F");
  l->AddEntry(q,"QCD","F");
  l->AddEntry(TT,"t#bar{t}","F");
  if(channel == "#tau_{e}#tau_{h}") l->AddEntry(zee,"Z#rightarrow ee","F");
    
  hs->Add(TT);
  hs->Add(q);
  hs->Add(EWK);
  if(channel == "#tau_{e}#tau_{h}") hs->Add(zee);
  hs->Add(ztautau);
  
  TH1F* errorBand = (TH1F*)TT->Clone();
  errorBand->Add(EWK);
  errorBand->Add(q);
  errorBand->Add(ztautau);
  if(channel == "#tau_{e}#tau_{h}") errorBand->Add(zee);
  errorBand  ->SetMarkerSize(0);
  errorBand  ->SetFillColor(1);
  errorBand  ->SetFillStyle(3013);
  errorBand  ->SetLineWidth(1);
  l->AddEntry(errorBand, "bkg. uncertainty" , "F" );
  float y = 0;
    for(int i=1;i<errorBand->GetNbinsX();++i){
    		y = errorBand->GetBinContent(i);
    		errorBand->SetBinError(i,y*err);
    }  
  
  


  hs->Draw("HIST");
  
  if(doRatio){
  	hs->GetXaxis()->SetLabelSize(0);
  }
  
  //if(data->GetMaximum()*1.2+sqrt(data->GetMaximum())>hs->GetMaximum()) {
  if(data->GetMaximum()*1.2+sqrt(data->GetMaximum())>hs->GetMaximum()) {
    float max=0.0;
    if(data->GetMaximum()>hs->GetMaximum())
      max=data->GetMaximum();
    else
      max=hs->GetMaximum();

    if(log) {
      max*=10;
      hs->SetMinimum(0.5);
    }
    hs->SetMaximum(max*1.8+sqrt(data->GetMaximum()));
  }
  else{
    hs->SetMaximum(hs->GetMaximum()*1.8);
    //std::cout<< "Maximum "<< hs->GetMaximum()<<std::endl;
  }

  //std::cout<< "Maximum "<< hs->GetMaximum()<<std::endl;

  if(dndm)       hs->SetMinimum(0.001);


  hs->Draw("HIST");
  errorBand->Draw("e2same");

  if(units!="")
	hs->GetXaxis()->SetTitle(labelX+" ["+units+"]");
  else
	hs->GetXaxis()->SetTitle(labelX);


  hs->GetYaxis()->SetTitle("Events");
  if(dndm)
    hs->GetYaxis()->SetTitle("dN/d"+labelX);

  if(s>0&&log)
    signal->Draw("HIST,SAME");

  data->Draw("e,SAME");
  
  if(!log){
	  l->SetBorderSize(0);
	  l->SetFillColor(0);
	  l->SetFillStyle (0);
	
	  l->Draw();
  }

  c->cd();
  
  if(doRatio){
    
    TH1F * data2 = (TH1F*)data->Clone("data");
    TH1F * mc = (TH1F*)(ttbar);
    mc->Add(QCD);
    mc->Add(EWK);
    mc->Add(ZTT);
    if(channel == "#tau_{e}#tau_{h}") mc->Add(ZEE);
    
    double xmin = mc->GetXaxis()->GetXmin();
    double xmax = mc->GetXaxis()->GetXmax();
    TLine *line = new TLine(xmin,1.0,xmax,1.0);
    line->SetLineWidth(3);
    line->SetLineColor(kBlack);
    
    
    ratioPad->Draw();
  	ratioPad->cd();
  	

  	data2->Divide(data2,mc);
  	

    data2->SetMarkerStyle(20);
    data2->SetTitleSize  (0.12,"Y");
    data2->SetTitleOffset(0.60,"Y");
    data2->SetTitleSize  (0.12,"X");
    data2->SetLabelSize  (0.10,"X");
    data2->SetLabelSize  (0.08,"Y");
    data2->GetYaxis()->SetTitleFont(42);
    data2->GetYaxis()->CenterTitle(kTRUE);
    data2->GetXaxis()->SetTitleFont(42);
    data2->GetYaxis()->SetRangeUser(0.6,1.4);
    data2->GetYaxis()->SetNdivisions(305);
    data2->GetYaxis()->SetTitle("Data/MC");
    data2->SetMarkerSize(1);
    gStyle->SetOptTitle(0);


    if(units!="")
	  data2->GetXaxis()->SetTitle(labelX+" ["+units+"]");
    else
	  data2->GetXaxis()->SetTitle(labelX);
	  
    data2->Draw("P");
    line->Draw();
        
  }
  
  c->cd();
  plotPad->cd();  

  float factor=0.0;
  if(left) factor = 1./2.2;
  else factor = 1.05;


  float xL = hs->GetXaxis()->GetXmin()+(hs->GetXaxis()->GetXmax()-hs->GetXaxis()->GetXmin())*xR*factor;
  float yL = hs->GetMaximum()*0.35;

  if(log)
  yL = hs->GetMaximum()*0.35;

  float offsetF=yL-0.1*hs->GetMaximum();
  float offsetFF=yL-0.2*hs->GetMaximum();

  if(log) {

    offsetF=yL/2.;
    offsetFF=yL/5.;

  }


  TLatex latex;
  latex.SetNDC();

  latex.SetTextSize(0.04);
  	
  latex.SetTextAlign(11);

  latex.SetTextFont(42);

	if(year == "2012")
  		latex.DrawLatex(0.20,0.94,"CMS Preliminary 2012, 19.7 fb^{-1}, #sqrt{s} = 8 TeV      "+channel);
  	else
  		latex.DrawLatex(0.20,0.94,"CMS Preliminary 2011, 4.9 fb^{-1}, #sqrt{s} = 7 TeV      "+channel);

 if(log)
   plotPad->SetLogy();

 // c->RedrawAxis(); 
  c->SaveAs(name+".png");
  c->SaveAs(name+".pdf");
  c->SaveAs(name+".root");

}


makeEMuStack(TString name,TString file,TString dir,int s,TString labelX,TString units = "GeV",bool left=false,bool log = false)
{
  setStyle();

  float xR=0.45;
  if(left)
    xR=0.2;


  TCanvas * c = new TCanvas(name,name,600,600);
  c->SetLeftMargin     (0.18);
  c->SetRightMargin    (0.05);
  c->SetTopMargin      (0.08);
  c->SetBottomMargin   (0.15);


  c->cd();
  TFile *f = new TFile(file);

  TH1F * data = (TH1F*)(f->Get(dir+"/data_obs"));
  applyDATAStyle(data);

  TH1F * QCD = (TH1F*)(f->Get(dir+"/FAKES"));
  applyStyle(QCD,kBlue-8,1,1001);

  TH1F * ttbar = (TH1F*)(f->Get(dir+"/TT"));
  applyStyle(ttbar,kMagenta-10,1,1001);


  TH1F * EWK = (TH1F*)(f->Get(dir+"/VV"));
  applyStyle(EWK,kRed+2,1,1001);

  TH1F * ZTT = (TH1F*)(f->Get(dir+"/ZTT"));
  applyStyle(ZTT,kOrange-4,kBlack,1001);

  TH1F *signal=0;

  if(s==1) {
    TH1F * MSSM = (TH1F*)(f->Get(dir+"/GGH120"));
    MSSM->Scale(11.22);
    TH1F * MSSM2 = (TH1F*)(f->Get(dir+"/BBH120"));
    MSSM2->Scale(16.);
    MSSM->Add(MSSM2);
    MSSM->SetLineStyle(11);

    signal=MSSM;
    applySignalStyle(signal);

  }
  else if(s==2) {
    TH1F * MSSM = (TH1F*)(f->Get(dir+"/GGHNoJet120"));
    MSSM->Add((TH1F*)(f->Get(dir+"/GGHJet120")));
    MSSM->Scale(11.22);
    TH1F * MSSM2 = (TH1F*)(f->Get(dir+"/BBHNoJet120"));
    MSSM2->Add((TH1F*)(f->Get(dir+"/BBHJet120")));
    MSSM2->Add((TH1F*)(f->Get(dir+"/BBHBJet120")));
    MSSM2->Scale(16.);
    MSSM->Add(MSSM2);
    MSSM->SetLineStyle(11);
    signal=MSSM;
    applySignalStyle(signal);

  }
  else if(s==3) {
    TH1F * SM = (TH1F*)(f->Get(dir+"/SM120"));
    TH1F * SM2 = (TH1F*)(f->Get(dir+"/VBF120"));
    SM->Add(SM2);
    SM->SetLineStyle(11);

    signal=SM;
    signal->Scale(1.0);
    applySignalStyle(signal);
  }


  THStack *hs = new THStack("hs","");
  TLegend *l = new TLegend(xR,0.6,xR+0.5,0.9);

  l->AddEntry(data,"Observed","P");
  if(s>0&&s<3)
    l->AddEntry(signal,"#phi#rightarrow #tau #tau(m_{A}=120 GeV,tan#beta=20)","F");
  else if(s==3)
    l->AddEntry(signal,"5xSM H(120) #rightarrow #tau #tau","F");
  if(log){
	  if(s<3)
		l->AddEntry(signal,"#phi#rightarrow #tau #tau(m_{A}=120 GeV,tan#beta=20)","L");
	  else if(s==3)
		l->AddEntry(signal,"2xSM H(120) #rightarrow #tau #tau","L");
  }
  else{
	  if(s<3)
		l->AddEntry(signal,"#phi#rightarrow #tau #tau(m_{A}=120 GeV,tan#beta=20)","F");
	  else if(s==3)
		l->AddEntry(signal,"2xSM H(120) #rightarrow #tau #tau","F");
  }  


  l->AddEntry(ZTT,"Z#rightarrow #tau #tau","F");
  l->AddEntry(EWK,"Electroweak","F");
  l->AddEntry(QCD,"Fakes","F");
  l->AddEntry(ttbar,"t#bar{t}","F");
    
  hs->Add(ttbar);
  hs->Add(QCD);
  hs->Add(EWK);
  hs->Add(ZTT);


  if(s>0&(!log))
    hs->Add(signal);

  
  // if(sm) {
  //   TH1F * SM = (TH1F*)(f->Get(dir+"/SM120"));
  //   SM->Add((TH1F*)(f->Get(dir+"/VBF120")));
  //   applyStyle(SM,kGray+2,1,3005);
  //   hs->Add(SM);
  // }
  //  else {
  //  hs->Add(MSSM);



  hs->Draw("HIST");
  if(data->GetMaximum()*1.35+sqrt(data->GetMaximum())>hs->GetMaximum()) {
    float max=0.0;
    if(data->GetMaximum()>hs->GetMaximum())
      max=data->GetMaximum();
    else
      max=hs->GetMaximum();

    if(log) {
      max*=5000;
      hs->SetMinimum(0.5);


    }
    hs->SetMaximum(max*1.5+sqrt(data->GetMaximum()));

  }

  hs->Draw("HIST");
  hs->GetXaxis()->SetTitle(labelX+" ["+units+"]");
  hs->GetYaxis()->SetTitle(TString::Format("Events / %2.f ",hs->GetXaxis()->GetBinWidth(1))+units);

  if(s>0&&log)
    signal->Draw("HIST,SAME");


  data->Draw("e,SAME");


  l->SetBorderSize(0);
  l->SetFillColor(0);
  l->SetFillStyle (0);

  l->Draw();


  float factor=0.0;
  if(left) factor = 1./2.2;
  else factor = 1.05;


  float xL = hs->GetXaxis()->GetXmin()+(hs->GetXaxis()->GetXmax()-hs->GetXaxis()->GetXmin())*xR*factor;
  float yL = hs->GetMaximum()*0.35;

  if(log)
  yL = hs->GetMaximum()*0.35;

  float offsetF=yL-0.1*hs->GetMaximum();
  float offsetFF=yL-0.2*hs->GetMaximum();

  if(log) {

    offsetF=yL/2.;
    offsetFF=yL/5.;

  }


  TLatex latex;
  latex.SetNDC();
  latex.SetTextSize(0.04);
  latex.SetTextAlign(11);

  latex.DrawLatex(0.20,0.94,"CMS  2011, L = 4.7 fb^{-1}, #sqrt{s} = 7 TeV       e+$\mu");

 if(log)
   c->SetLogy();

 // c->RedrawAxis(); 
  c->SaveAs(name+".png");
  c->SaveAs(name+".pdf");
  c->SaveAs(name+".root");

}
