{
  TFile * fD = new TFile("sandbox/tau-fake-rates/DATA.root");
  TFile * fM = new TFile("sandbox/tau-fake-rates/QCD.root");
  TFile * fW = new TFile("sandbox/tau-fake-rates/W.root");
  TFile * fZ = new TFile("sandbox/tau-fake-rates/ZTT.root");



  TH1F *d_m_ref = (TH1F*)fD->Get("tauFakeRateMuEnriched/refPtL");
  TH1F *d_m_dm = (TH1F*)fD->Get("tauFakeRateMuEnriched/decayModeFindingptL");
  TH1F *d_m_vli = (TH1F*)fD->Get("tauFakeRateMuEnriched/byVLooseCombinedIsolationDeltaBetaCorrptL");
  TH1F *d_m_li = (TH1F*)fD->Get("tauFakeRateMuEnriched/byLooseCombinedIsolationDeltaBetaCorrptL");
  TH1F *d_m_mi = (TH1F*)fD->Get("tauFakeRateMuEnriched/byMediumCombinedIsolationDeltaBetaCorrptL");
  TH1F *d_m_ti = (TH1F*)fD->Get("tauFakeRateMuEnriched/byTightCombinedIsolationDeltaBetaCorrptL");


  TH1F *m_m_ref = (TH1F*)fM->Get("tauFakeRateMuEnriched/refPtL");
  TH1F *m_m_dm = (TH1F*)fM->Get("tauFakeRateMuEnriched/decayModeFindingptL");
  TH1F *m_m_vli = (TH1F*)fM->Get("tauFakeRateMuEnriched/byVLooseCombinedIsolationDeltaBetaCorrptL");
  TH1F *m_m_li = (TH1F*)fM->Get("tauFakeRateMuEnriched/byLooseCombinedIsolationDeltaBetaCorrptL");
  TH1F *m_m_mi = (TH1F*)fM->Get("tauFakeRateMuEnriched/byMediumCombinedIsolationDeltaBetaCorrptL");
  TH1F *m_m_ti = (TH1F*)fM->Get("tauFakeRateMuEnriched/byTightCombinedIsolationDeltaBetaCorrptL");

  TH1F *w_w_ref = (TH1F*)fW->Get("tauFakeRatewJets/refPtL");
  TH1F *w_w_dm = (TH1F*)fW->Get("tauFakeRatewJets/decayModeFindingptL");
  TH1F *w_w_vli = (TH1F*)fW->Get("tauFakeRatewJets/byVLooseCombinedIsolationDeltaBetaCorrptL");
  TH1F *w_w_li = (TH1F*)fW->Get("tauFakeRatewJets/byLooseCombinedIsolationDeltaBetaCorrptL");
  TH1F *w_w_mi = (TH1F*)fW->Get("tauFakeRatewJets/byMediumCombinedIsolationDeltaBetaCorrptL");
  TH1F *w_w_ti = (TH1F*)fW->Get("tauFakeRatewJets/byTightCombinedIsolationDeltaBetaCorrptL");

  TH1F *d_w_ref = (TH1F*)fD->Get("tauFakeRatewJets/refPtL");
  TH1F *d_w_dm = (TH1F*)fD->Get("tauFakeRatewJets/decayModeFindingptL");
  TH1F *d_w_vli = (TH1F*)fD->Get("tauFakeRatewJets/byVLooseCombinedIsolationDeltaBetaCorrptL");
  TH1F *d_w_li = (TH1F*)fD->Get("tauFakeRatewJets/byLooseCombinedIsolationDeltaBetaCorrptL");
  TH1F *d_w_mi = (TH1F*)fD->Get("tauFakeRatewJets/byMediumCombinedIsolationDeltaBetaCorrptL");
  TH1F *d_w_ti = (TH1F*)fD->Get("tauFakeRatewJets/byTightCombinedIsolationDeltaBetaCorrptL");

  TH1F *z_z_ref = (TH1F*)fZ->Get("tauFakeRateMCeffthr15/refPtL");
  TH1F *z_z_dm = (TH1F*)fZ->Get("tauFakeRateMCeffthr15/decayModeFindingptL");
  TH1F *z_z_vli = (TH1F*)fZ->Get("tauFakeRateMCeffthr15/byVLooseCombinedIsolationDeltaBetaCorrptL");
  TH1F *z_z_li = (TH1F*)fZ->Get("tauFakeRateMCeffthr15/byLooseCombinedIsolationDeltaBetaCorrptL");
  TH1F *z_z_mi = (TH1F*)fZ->Get("tauFakeRateMCeffthr15/byMediumCombinedIsolationDeltaBetaCorrptL");
  TH1F *z_z_ti = (TH1F*)fZ->Get("tauFakeRateMCeffthr15/byTightCombinedIsolationDeltaBetaCorrptL");





  TGraphAsymmErrors *m_m_fr_dm = new TGraphAsymmErrors();
  m_m_fr_dm->BayesDivide(m_m_dm,m_m_ref);
  TGraphAsymmErrors *m_m_fr_vli = new TGraphAsymmErrors();
  m_m_fr_vli->BayesDivide(m_m_vli,m_m_ref);
  TGraphAsymmErrors *m_m_fr_li = new TGraphAsymmErrors();
  m_m_fr_li->BayesDivide(m_m_li,m_m_ref);
  TGraphAsymmErrors *m_m_fr_mi = new TGraphAsymmErrors();
  m_m_fr_mi->BayesDivide(m_m_mi,m_m_ref);
  TGraphAsymmErrors *m_m_fr_ti = new TGraphAsymmErrors();
  m_m_fr_ti->BayesDivide(m_m_ti,m_m_ref);

  TGraphAsymmErrors *d_m_fr_dm = new TGraphAsymmErrors();
  d_m_fr_dm->BayesDivide(d_m_dm,d_m_ref);
  TGraphAsymmErrors *d_m_fr_vli = new TGraphAsymmErrors();
  d_m_fr_vli->BayesDivide(d_m_vli,d_m_ref);
  TGraphAsymmErrors *d_m_fr_li = new TGraphAsymmErrors();
  d_m_fr_li->BayesDivide(d_m_li,d_m_ref);
  TGraphAsymmErrors *d_m_fr_mi = new TGraphAsymmErrors();
  d_m_fr_mi->BayesDivide(d_m_mi,d_m_ref);
  TGraphAsymmErrors *d_m_fr_ti = new TGraphAsymmErrors();
  d_m_fr_ti->BayesDivide(d_m_ti,d_m_ref);




  TCanvas * c1 = new TCanvas("c1","Mu Enriched Fake Rate",600,400);

  m_m_fr_dm->GetYaxis()->SetRangeUser(0.001,1.);
  m_m_fr_dm->GetYaxis()->SetTitle("Fake Rate");
  m_m_fr_dm->GetXaxis()->SetTitle("PF Jet p_{T} [GeV/c] ");
  m_m_fr_dm->SetMarkerColor(kRed);
  m_m_fr_dm->SetMarkerStyle(20);
  m_m_fr_dm->Draw("AP");
  d_m_fr_dm->SetMarkerColor(kRed);
  d_m_fr_dm->SetMarkerStyle(20);
  d_m_fr_dm->Draw("Psame");

  m_m_fr_vli->SetMarkerColor(kBlue);
  m_m_fr_vli->SetMarkerStyle(21);
  m_m_fr_vli->Draw("Psame");
  d_m_fr_vli->SetMarkerColor(kBlue);
  d_m_fr_vli->SetMarkerStyle(21);
  d_m_fr_vli->Draw("Psame");

  m_m_fr_li->SetMarkerColor(kGreen);
  m_m_fr_li->SetMarkerStyle(22);
  m_m_fr_li->Draw("Psame");

  d_m_fr_li->SetMarkerColor(kGreen);
  d_m_fr_li->SetMarkerStyle(22);
  d_m_fr_li->Draw("Psame");

  m_m_fr_mi->SetMarkerColor(kMagenta);
  m_m_fr_mi->SetMarkerStyle(23);
  m_m_fr_mi->Draw("Psame");

  d_m_fr_mi->SetMarkerColor(kMagenta);
  d_m_fr_mi->SetMarkerStyle(23);
  d_m_fr_mi->Draw("Psame");

  m_m_fr_ti->SetMarkerColor(kBlack);
  m_m_fr_ti->SetMarkerStyle(24);
  m_m_fr_ti->Draw("Psame");

  d_m_fr_ti->SetMarkerColor(kBlack);
  d_m_fr_ti->SetMarkerStyle(24);
  d_m_fr_ti->Draw("Psame");


  TLegend *l = new TLegend(0.4,0.4,0.6,0.6);
  l->AddEntry(m_m_fr_dm,"Decay Mode Finding","p");
  l->AddEntry(m_m_fr_vli,"VLoose Isolation","p");
  l->AddEntry(m_m_fr_li,"Loose Isolation","p");
  l->AddEntry(m_m_fr_mi,"Medium Isolation","p");
  l->AddEntry(m_m_fr_ti,"Tight Isolation","p");
  l->Draw();

  c1->Draw();



  TGraphAsymmErrors *w_w_fr_dm = new TGraphAsymmErrors();
  w_w_fr_dm->BayesDivide(w_w_dm,w_w_ref);
  TGraphAsymmErrors *w_w_fr_vli = new TGraphAsymmErrors();
  w_w_fr_vli->BayesDivide(w_w_vli,w_w_ref);
  TGraphAsymmErrors *w_w_fr_li = new TGraphAsymmErrors();
  w_w_fr_li->BayesDivide(w_w_li,w_w_ref);
  TGraphAsymmErrors *w_w_fr_mi = new TGraphAsymmErrors();
  w_w_fr_mi->BayesDivide(w_w_mi,w_w_ref);
  TGraphAsymmErrors *w_w_fr_ti = new TGraphAsymmErrors();
  w_w_fr_ti->BayesDivide(w_w_ti,w_w_ref);

  TGraphAsymmErrors *d_w_fr_dm = new TGraphAsymmErrors();
  d_w_fr_dm->BayesDivide(d_w_dm,d_w_ref);
  TGraphAsymmErrors *d_w_fr_vli = new TGraphAsymmErrors();
  d_w_fr_vli->BayesDivide(d_w_vli,d_w_ref);
  TGraphAsymmErrors *d_w_fr_li = new TGraphAsymmErrors();
  d_w_fr_li->BayesDivide(d_w_li,d_w_ref);
  TGraphAsymmErrors *d_w_fr_mi = new TGraphAsymmErrors();
  d_w_fr_mi->BayesDivide(d_w_mi,d_w_ref);
  TGraphAsymmErrors *d_w_fr_ti = new TGraphAsymmErrors();
  d_w_fr_ti->BayesDivide(d_w_ti,d_w_ref);




  TCanvas * c2 = new TCanvas("c2","W+jets Fake Rate",600,400);

  w_w_fr_dm->GetYaxis()->SetRangeUser(0.001,1.);
  w_w_fr_dm->GetYaxis()->SetTitle("Fake Rate");
  w_w_fr_dm->GetXaxis()->SetTitle("PF Jet p_{T} [GeV/c] ");
  w_w_fr_dm->SetMarkerColor(kRed);
  w_w_fr_dm->SetMarkerStyle(20);
  w_w_fr_dm->Draw("AP");
  d_w_fr_dm->SetMarkerColor(kRed);
  d_w_fr_dm->SetMarkerStyle(20);
  d_w_fr_dm->Draw("Psame");

  w_w_fr_vli->SetMarkerColor(kBlue);
  w_w_fr_vli->SetMarkerStyle(21);
  w_w_fr_vli->Draw("Psame");
  d_w_fr_vli->SetMarkerColor(kBlue);
  d_w_fr_vli->SetMarkerStyle(21);
  d_w_fr_vli->Draw("Psame");

  w_w_fr_li->SetMarkerColor(kGreen);
  w_w_fr_li->SetMarkerStyle(22);
  w_w_fr_li->Draw("Psame");

  d_w_fr_li->SetMarkerColor(kGreen);
  d_w_fr_li->SetMarkerStyle(22);
  d_w_fr_li->Draw("Psame");

  w_w_fr_mi->SetMarkerColor(kMagenta);
  w_w_fr_mi->SetMarkerStyle(23);
  w_w_fr_mi->Draw("Psame");

  d_w_fr_mi->SetMarkerColor(kMagenta);
  d_w_fr_mi->SetMarkerStyle(23);
  d_w_fr_mi->Draw("Psame");

  w_w_fr_ti->SetMarkerColor(kBlack);
  w_w_fr_ti->SetMarkerStyle(24);
  w_w_fr_ti->Draw("Psame");

  d_w_fr_ti->SetMarkerColor(kBlack);
  d_w_fr_ti->SetMarkerStyle(24);
  d_w_fr_ti->Draw("Psame");


  TLegend *l = new TLegend(0.4,0.4,0.6,0.6);
  l->AddEntry(w_w_fr_dm,"Decay Mode Finding","p");
  l->AddEntry(w_w_fr_vli,"VLoose Isolation","p");
  l->AddEntry(w_w_fr_li,"Loose Isolation","p");
  l->AddEntry(w_w_fr_mi,"Medium Isolation","p");
  l->AddEntry(w_w_fr_ti,"Tight Isolation","p");
  l->Draw();

  c2->Draw();




  TGraphAsymmErrors *z_z_fr_dm = new TGraphAsymmErrors();
  z_z_fr_dm->Divide(z_z_dm,z_z_ref);
  TGraphAsymmErrors *z_z_fr_vli = new TGraphAsymmErrors();
  z_z_fr_vli->Divide(z_z_vli,z_z_ref);
  TGraphAsymmErrors *z_z_fr_li = new TGraphAsymmErrors();
  z_z_fr_li->Divide(z_z_li,z_z_ref);
  TGraphAsymmErrors *z_z_fr_mi = new TGraphAsymmErrors();
  z_z_fr_mi->Divide(z_z_mi,z_z_ref);
  TGraphAsymmErrors *z_z_fr_ti = new TGraphAsymmErrors();
  z_z_fr_ti->Divide(z_z_ti,z_z_ref);


  TCanvas * c3 = new TCanvas("c3","Z #rightarrow #tau #tau Efficiency",600,400);
  c3->cd();
  z_z_fr_dm->GetYaxis()->SetRangeUser(0.0,1.5);
  z_z_fr_dm->GetYaxis()->SetTitle("Efficiency");
  z_z_fr_dm->GetXaxis()->SetTitle("gen. visible  #tau p_{T} [GeV/c] ");
  z_z_fr_dm->SetMarkerColor(kRed);
  z_z_fr_dm->SetMarkerStyle(20);
  z_z_fr_dm->Draw("AP");
  z_z_fr_vli->SetMarkerColor(kBlue);
  z_z_fr_vli->SetMarkerStyle(21);
  z_z_fr_vli->Draw("Psame");
  z_z_fr_li->SetMarkerColor(kGreen);
  z_z_fr_li->SetMarkerStyle(22);
  z_z_fr_li->Draw("Psame");
  z_z_fr_mi->SetMarkerColor(kMagenta);
  z_z_fr_mi->SetMarkerStyle(23);
  z_z_fr_mi->Draw("Psame");
  z_z_fr_ti->SetMarkerColor(kBlack);
  z_z_fr_ti->SetMarkerStyle(24);
  z_z_fr_ti->Draw("Psame");


  TLegend *l = new TLegend(0.2,0.75,0.8,0.95);
  l->AddEntry(z_z_fr_dm,"Decay Mode Finding","p");
  l->AddEntry(z_z_fr_vli,"VLoose Isolation","p");
  l->AddEntry(z_z_fr_li,"Loose Isolation","p");
  l->AddEntry(z_z_fr_mi,"Medium Isolation","p");
  l->AddEntry(z_z_fr_ti,"Tight Isolation","p");
  l->Draw();

  c3->Draw();





}
