{
   gROOT->ProcessLine(".L UWAnalysis/ROOT/macros/plotScripts/templatePlots/makePlot.C");

   makeLTauStack("muTau/7TeV/decayMode_muTau_2011","muTauPlots42X/muTau_TDMode.root","muTau_X",0,"","",false,"#tau_{#mu}#tau_{h}","2011",false,false,true);

   makeLTauStack("muTau/7TeV/pt_1_muTau_2011","muTauPlots42X/muTau_pt1.root","muTau_X",0,"#mu p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,false,false);
   makeLTauStack("muTau/7TeV/pt_1_muTau_2011_LOG","muTauPlots42X/muTau_pt1.root","muTau_X",0,"#mu p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2011",true,false,false);

   makeLTauStack("muTau/7TeV/pt_2_muTau_2011","muTauPlots42X/muTau_pt2.root","muTau_X",0,"#tau p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,false);
   makeLTauStack("muTau/7TeV/pt_2_muTau_2011_LOG","muTauPlots42X/muTau_pt2.root","muTau_X",0,"#tau p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2011",true,false);

   makeLTauStack("muTau/7TeV/eta_1_muTau_2011","muTauPlots42X/muTau_eta1.root","muTau_X",0,"#mu #eta","",true,"#tau_{#mu}#tau_{h}","2011",false,false);
   makeLTauStack("muTau/7TeV/eta_1_muTau_2011_LOG","muTauPlots42X/muTau_eta1.root","muTau_X",0,"#mu #eta","",true,"#tau_{#mu}#tau_{h}","2011",true,false);

   makeLTauStack("muTau/7TeV/eta_2_muTau_2011","muTauPlots42X/muTau_eta2.root","muTau_X",0,"#tau #eta","",true,"#tau_{#mu}#tau_{h}","2011",false,false);
   makeLTauStack("muTau/7TeV/eta_2_muTau_2011_LOG","muTauPlots42X/muTau_eta2.root","muTau_X",0,"#tau #eta","",true,"#tau_{#mu}#tau_{h}","2011",true,false);

   makeLTauStack("muTau/7TeV/tauMass1P_muTau_2011","muTauPlots42X/muTau_tauMass1P.root","muTau_X",0,"#tau Mass","GeV",true,"#tau_{#mu}#tau_{h}","2011",false,false);
   makeLTauStack("muTau/7TeV/tauMass3P_muTau_2011","muTauPlots42X/muTau_tauMass3P.root","muTau_X",0,"#tau Mass","GeV",true,"#tau_{#mu}#tau_{h}","2011",false,false);

   makeLTauStack("muTau/7TeV/mvis_muTau_2011","muTauPlots42X/muTau_MVis.root","muTau_X",3,"m_{vis}","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,false);
   makeLTauStack("muTau/7TeV/mvis_muTau_2011_LOG","muTauPlots42X/muTau_MVis.root","muTau_X",3,"m_{vis}","GeV",false,"#tau_{#mu}#tau_{h}","2011",true,false);
   
   makeLTauStack("muTau/7TeV/m_sv_muTau_2011","muTauPlots42X/muTauSM.root","muTau_X",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,true);
   makeLTauStack("muTau/7TeV/m_sv_muTau_2011_LOG","muTauPlots42X/muTauSM.root","muTau_X",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",true,true);

//    makeLTauStack("muTau/7TeV/mvis_0JetLow_muTau_2011","muTauPlots42X/muTauSMMVis.root","muTau_0jet_low",3,"m_{#mu#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,true);
//    makeLTauStack("muTau/7TeV/mvis_0JetLow_muTau_2011_LOG","muTauPlots42X/muTauSMMVis.root","muTau_0jet_low",3,"m_{#mu#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",true,true);
// 
//    makeLTauStack("muTau/7TeV/mvis_0JetHigh_muTau_2011","muTauPlots42X/muTauSMMVis.root","muTau_0jet_high",3,"m_{#mu#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,true);
//    makeLTauStack("muTau/7TeV/mvis_0JetHigh_muTau_2011_LOG","muTauPlots42X/muTauSMMVis.root","muTau_0jet_high",3,"m_{#mu#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",true,true);
// 
//    makeLTauStack("muTau/7TeV/mvis_1JetLow_muTau_2011","muTauPlots42X/muTauSMMVis.root","muTau_boost_low",3,"m_{#mu#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,true);
//    makeLTauStack("muTau/7TeV/mvis_1JetLow_muTau_2011_LOG","muTauPlots42X/muTauSMMVis.root","muTau_boost_low",3,"m_{#mu#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",true,true);
// 
//    makeLTauStack("muTau/7TeV/mvis_1JetHigh_muTau_2011","muTauPlots42X/muTauSMMVis.root","muTau_boost_high",3,"m_{#mu#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,true);
//    makeLTauStack("muTau/7TeV/mvis_1JetHigh_muTau_2011_LOG","muTauPlots42X/muTauSMMVis.root","muTau_boost_high",3,"m_{#mu#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",true,true);

//   makeLTauStack("muTau/7TeV/mvis_vbf_muTau_2011","muTauPlots42X/muTauSMMVis.root","muTau_vbf",3,"m_{#mu#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,true);
//   makeLTauStack("muTau/7TeV/mvis_vbf_muTau_2011_LOG","muTauPlots42X/muTauSMMVis.root","muTau_vbf",3,"m_{#mu#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",true,true);

   makeLTauStack("muTau/7TeV/m_sv_0JetLow_muTau_2011","muTauPlots42X/muTauSM.root","muTau_0jet_low",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,true);
   makeLTauStack("muTau/7TeV/m_sv_0JetLow_muTau_2011_LOG","muTauPlots42X/muTauSM.root","muTau_0jet_low",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",true,true);

   makeLTauStack("muTau/7TeV/m_sv_0JetHigh_muTau_2011","muTauPlots42X/muTauSM.root","muTau_0jet_high",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,true);
   makeLTauStack("muTau/7TeV/m_sv_0JetHigh_muTau_2011_LOG","muTauPlots42X/muTauSM.root","muTau_0jet_high",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",true,true);

   makeLTauStack("muTau/7TeV/m_sv_1JetLow_muTau_2011","muTauPlots42X/muTauSM.root","muTau_boost_low",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,true);
   makeLTauStack("muTau/7TeV/m_sv_1JetLow_muTau_2011_LOG","muTauPlots42X/muTauSM.root","muTau_boost_low",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",true,true);

   makeLTauStack("muTau/7TeV/m_sv_1JetHigh_muTau_2011","muTauPlots42X/muTauSM.root","muTau_boost_high",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,true);
   makeLTauStack("muTau/7TeV/m_sv_1JetHigh_muTau_2011_LOG","muTauPlots42X/muTauSM.root","muTau_boost_high",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",true,true);
// 
//    makeLTauStack("muTau/7TeV/m_sv_2Jet_muTau_2011","muTauPlots42X/muTauSM.root","muTau_2jet",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,true);
//    makeLTauStack("muTau/7TeV/m_sv_2Jet_muTau_2011_LOG","muTauPlots42X/muTauSM.root","muTau_2jet",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",true,true);

   makeLTauStack("muTau/7TeV/m_sv_vbf_muTau_2011","muTauPlots42X/muTauSM.root","muTau_vbf",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,true);
   makeLTauStack("muTau/7TeV/m_sv_vbf_muTau_2011_LOG","muTauPlots42X/muTauSM.root","muTau_vbf",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",true,true);

//    makeLTauStack("muTau/7TeV/m_sv_vh_muTau_2011","muTauPlots42X/muTauSM.root","muTau_vh",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,true);
//    makeLTauStack("muTau/7TeV/m_sv_vh_muTau_2011_LOG","muTauPlots42X/muTauSM.root","muTau_vh",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",true,true);

//    makeLTauStack("muTau/7TeV/m_sv_0JetLow_muTau_2011_hm","muTauPlots42X/muTau.root","muTau_0jet_low",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,true);
//    makeLTauStack("muTau/7TeV/m_sv_0JetLow_muTau_2011_hm_LOG","muTauPlots42X/muTau.root","muTau_0jet_low",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",true,true);
// 
//    makeLTauStack("muTau/7TeV/m_sv_0JetHigh_muTau_2011_hm","muTauPlots42X/muTau.root","muTau_0jet_high",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,true);
//    makeLTauStack("muTau/7TeV/m_sv_0JetHigh_muTau_2011_hm_LOG","muTauPlots42X/muTau.root","muTau_0jet_high",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",true,true);

//    makeLTauStack("muTau/7TeV/m_sv_1JetLow_muTau_2011_hm","muTauPlots42X/muTau.root","muTau_boost_low",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,true);
//    makeLTauStack("muTau/7TeV/m_sv_1JetLow_muTau_2011_hm_LOG","muTauPlots42X/muTau.root","muTau_boost_low",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",true,true);
// 
//    makeLTauStack("muTau/7TeV/m_sv_1JetHigh_muTau_2011_hm","muTauPlots42X/muTau.root","muTau_boost_high",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,true);
//    makeLTauStack("muTau/7TeV/m_sv_1JetHigh_muTau_2011_hm_LOG","muTauPlots42X/muTau.root","muTau_boost_high",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",true,true);

//    makeLTauStack("muTau/7TeV/m_sv_bJetLow_muTau_2011_hm","muTauPlots42X/muTau.root","muTau_btag_low",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,true);
//    makeLTauStack("muTau/7TeV/m_sv_bJetLow_muTau_2011_hm_LOG","muTauPlots42X/muTau.root","muTau_btag_low",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",true,true);
// 
//    makeLTauStack("muTau/7TeV/m_sv_bJetHigh_muTau_2011_hm","muTauPlots42X/muTau.root","muTau_btag_high",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,true);
//    makeLTauStack("muTau/7TeV/m_sv_bJetHigh_muTau_2011_hm_LOG","muTauPlots42X/muTau.root","muTau_btag_high",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",true,true);
// 
//    makeLTauStack("muTau/7TeV/m_sv_bJet_muTau_2011_hm","muTauPlots42X/muTau.root","muTau_btag",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,true);
//    makeLTauStack("muTau/7TeV/m_sv_bJet_muTau_2011_hm_LOG","muTauPlots42X/muTau.root","muTau_btag",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",true,true);
// 
//    makeLTauStack("muTau/7TeV/m_sv_NobJet_muTau_2011_hm","muTauPlots42X/muTau.root","muTau_nobtag",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,true);
//    makeLTauStack("muTau/7TeV/m_sv_NobJet_muTau_2011_hm_LOG","muTauPlots42X/muTau.root","muTau_nobtag",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",true,true);

//    makeLTauStack("muTau/7TeV/mt_1_0JetLow_muTau_2011","muTauPlots42X/muTauSMMT.root","muTau_0jet_low",3,"M_{T}(#mu,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,false);
//    makeLTauStack("muTau/7TeV/mt_1_0JetLow_muTau_2011_LOG","muTauPlots42X/muTauSMMT.root","muTau_0jet_low",3,"M_{T}(#mu,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2011",true,false);
// 
//    makeLTauStack("muTau/7TeV/mt_1_0JetHigh_muTau_2011","muTauPlots42X/muTauSMMT.root","muTau_0jet_high",3,"M_{T}(#mu,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,false);
//    makeLTauStack("muTau/7TeV/mt_1_0JetHigh_muTau_2011_LOG","muTauPlots42X/muTauSMMT.root","muTau_0jet_high",3,"M_{T}(#mu,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2011",true,false);
// 
//    makeLTauStack("muTau/7TeV/mt_1_1JetLow_muTau_2011","muTauPlots42X/muTauSMMT.root","muTau_boost_low",3,"M_{T}(#mu,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,false);
//    makeLTauStack("muTau/7TeV/mt_1_1JetLow_muTau_2011_LOG","muTauPlots42X/muTauSMMT.root","muTau_boost_low",3,"M_{T}(#mu,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2011",true,false);
// 
//    makeLTauStack("muTau/7TeV/mt_1_1JetHigh_muTau_2011","muTauPlots42X/muTauSMMT.root","muTau_boost_high",3,"M_{T}(#mu,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,false);
//    makeLTauStack("muTau/7TeV/mt_1_1JetHigh_muTau_2011_LOG","muTauPlots42X/muTauSMMT.root","muTau_boost_high",3,"M_{T}(#mu,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2011",true,false);

//    makeLTauStack("muTau/7TeV/mt_1_bJetLow_muTau_2011","muTauPlots42X/muTauMT.root","muTau_btag_low",1,"M_{T}(#mu,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,false);
//    makeLTauStack("muTau/7TeV/mt_1_bJetLow_muTau_2011_LOG","muTauPlots42X/muTauMT.root","muTau_btag_low",1,"M_{T}(#mu,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2011",true,false);
// 
//    makeLTauStack("muTau/7TeV/mt_1_bJetHigh_muTau_2011","muTauPlots42X/muTauMT.root","muTau_btag_high",1,"M_{T}(#mu,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,false);
//    makeLTauStack("muTau/7TeV/mt_1_bJetHigh_muTau_2011_LOG","muTauPlots42X/muTauMT.root","muTau_btag_high",1,"M_{T}(#mu,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2011",true,false);
// 
//    makeLTauStack("muTau/7TeV/mt_1_vbf_muTau_2011","muTauPlots42X/muTauSMMT.root","muTau_vbf",3,"M_{T}(#mu,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,false);
//    makeLTauStack("muTau/7TeV/mt_1_vbf_muTau_2011_LOG","muTauPlots42X/muTauSMMT.root","muTau_vbf",3,"M_{T}(#mu,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2011",true,false);

   makeLTauStack("muTau/7TeV/njets_muTau_2011","muTauPlots42X/muTau_jets.root","muTau_X",0,"Number of Jets","",false,"#tau_{#mu}#tau_{h}","2011",false,false);
   makeLTauStack("muTau/7TeV/njets_muTau_2011_LOG","muTauPlots42X/muTau_jets.root","muTau_X",0,"Number of  Jets","",false,"#tau_{#mu}#tau_{h}","2011",true,false);

//    makeLTauStack("muTau/7TeV/nbtags_muTau_2011","muTauPlots42X/muTau_bjets.root","muTau_X",0,"Number of  b-Tagged Jets","",false,"#tau_{#mu}#tau_{h}","2011",false,false);
//    makeLTauStack("muTau/7TeV/nbtags_muTau_2011_LOG","muTauPlots42X/muTau_bjets.root","muTau_X",0,"Number of b-Tagged Jets","",false,"#tau_{#mu}#tau_{h}","2011",true,false);

   makeLTauStack("muTau/7TeV/jdeta_muTau_2011","muTauPlots42X/muTau_DEta.root","muTau_vbf",3,"#Delta #eta(jj)","",false,"#tau_{#mu}#tau_{h}","2011",false,false);
   makeLTauStack("muTau/7TeV/mjj_muTau_2011","muTauPlots42X/muTau_MJJ.root","muTau_vbf",3,"M(jj)","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,false);
   
//    makeLTauStack("muTau/7TeV/jeta_1_muTau_2011","muTauPlots42X/muTau_vbfEta1.root","muTau_vbf",3,"Leading Jet #eta","",true,"#tau_{#mu}#tau_{h}","2011",false,false);
//    makeLTauStack("muTau/7TeV/jeta_2_muTau_2011","muTauPlots42X/muTau_vbfEta2.root","muTau_vbf",3,"Sub-Leading Jet #eta","",true,"#tau_{#mu}#tau_{h}","2011",false,false);
//    
//    makeLTauStack("muTau/7TeV/jpt_1_muTau_2011","muTauPlots42X/muTau_vbfPt1.root","muTau_vbf",3,"Leading Jet p_{T}","",false,"#tau_{#mu}#tau_{h}","2011",false,false);
//    makeLTauStack("muTau/7TeV/jpt_2_muTau_2011","muTauPlots42X/muTau_vbfPt2.root","muTau_vbf",3,"Sub-Leading Jet p_{T}","",false,"#tau_{#mu}#tau_{h}","2011",false,false);

   makeLTauStack("muTau/7TeV/jdeta_muTau_2011_LOG","muTauPlots42X/muTau_DEta.root","muTau_vbf",3,"#Delta #eta(jj)","",false,"#tau_{#mu}#tau_{h}","2011",true,false);
   makeLTauStack("muTau/7TeV/mjj_muTau_2011_LOG","muTauPlots42X/muTau_MJJ.root","muTau_vbf",3,"M(jj)","GeV",false,"#tau_{#mu}#tau_{h}","2011",true,false);

   makeLTauStack("muTau/7TeV/mt_1_muTau_2011","muTauPlots42X/muTau_MT.root","muTau_X",0,"M_{T}(#mu,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,false);
   makeLTauStack("muTau/7TeV/met_muTau_2011","muTauPlots42X/muTau_MET.root","muTau_X",0,"MET","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,false);

   makeLTauStack("muTau/7TeV/hjetpt_muTau_2011","muTauPlots42X/muTau_BoostedPt.root","muTau_X",0,"highest Jet P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,false);
   makeLTauStack("muTau/7TeV/hjeteta_muTau_2011","muTauPlots42X/muTau_BoostedEta.root","muTau_X",0,"highest Jet #eta","GeV",true,"#tau_{#mu}#tau_{h}","2011",false,false);

//    makeLTauStack("muTau/7TeV/bpt_muTau_2011","muTauPlots42X/muTau_BJetPt.root","muTau_X",0,"B Jet P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,false);
//    makeLTauStack("muTau/7TeV/beta_muTau_2011","muTauPlots42X/muTau_BJetEta.root","muTau_X",0,"B Jet #eta","GeV",true,"#tau_{#mu}#tau_{h}","2011",false,false);

   makeLTauStack("muTau/7TeV/pvs_muTau_2011","muTauPlots42X/muTau_NPVs.root","muTau_X",0,"PVs","",false,"#tau_{#mu}#tau_{h}","2011",false,false);

// makeLTauStack("muTau/7TeV/cjv_muTau_2011","muTauPlots42X/muTau_cjv.root","muTau_vbf",3,"Central Jets p_{T}>30 GeV","",false,"#tau_{#mu}#tau_{h}","2011",false,false,false);
// makeLTauStack("muTau/7TeV/cjv_muTau_2011_LOG","muTauPlots42X/muTau_cjv.root","muTau_vbf",3,"Central Jets p_{T}>30 GeV","",false,"#tau_{#mu}#tau_{h}","2011",true,false,false);



   makeLTauStack("eleTau/7TeV/decayMode_eleTau_2011","eleTauPlots42X/eleTau_TDMode.root","eleTau_X",0,"","",false,"#tau_{e}#tau_{h}","2011",false,false,true);

   makeLTauStack("eleTau/7TeV/pt_1_eTau_2011","eleTauPlots42X/eleTau_pt1.root","eleTau_X",0,"e p_{T}","GeV",false,"#tau_{e}#tau_{h}","2011",false,false);
   makeLTauStack("eleTau/7TeV/pt_1_eTau_2011_LOG","eleTauPlots42X/eleTau_pt1.root","eleTau_X",0,"e p_{T}","GeV",false,"#tau_{e}#tau_{h}","2011",true,false);

   makeLTauStack("eleTau/7TeV/pt_2_eTau_2011","eleTauPlots42X/eleTau_pt2.root","eleTau_X",0,"#tau p_{T}","GeV",false,"#tau_{e}#tau_{h}","2011",false,false);
   makeLTauStack("eleTau/7TeV/pt_2_eTau_2011_LOG","eleTauPlots42X/eleTau_pt2.root","eleTau_X",0,"#tau p_{T}","GeV",false,"#tau_{e}#tau_{h}","2011",true,false);

   makeLTauStack("eleTau/7TeV/eta_1_eTau_2011","eleTauPlots42X/eleTau_eta1.root","eleTau_X",0,"e #eta","",true,"#tau_{e}#tau_{h}","2011",false,false);
   makeLTauStack("eleTau/7TeV/eta_1_eTau_2011_LOG","eleTauPlots42X/eleTau_eta1.root","eleTau_X",0,"e #eta","",true,"#tau_{e}#tau_{h}","2011",true,false);

   makeLTauStack("eleTau/7TeV/eta_2_eTau_2011","eleTauPlots42X/eleTau_eta2.root","eleTau_X",0,"#tau #eta","",true,"#tau_{e}#tau_{h}","2011",false,false);
   makeLTauStack("eleTau/7TeV/eta_2_eTau_2011_LOG","eleTauPlots42X/eleTau_eta2.root","eleTau_X",0,"#tau #eta","",true,"#tau_{e}#tau_{h}","2011",true,false);

   makeLTauStack("eleTau/7TeV/mvis_eTau_2011","eleTauPlots42X/eleTau_MVis.root","eleTau_X",3,"m_{vis}","GeV",false,"#tau_{e}#tau_{h}","2011",false,false);
   makeLTauStack("eleTau/7TeV/mvis_eTau_2011_LOG","eleTauPlots42X/eleTau_MVis.root","eleTau_X",3,"m_{vis}","GeV",false,"#tau_{e}#tau_{h}","2011",true,false);
   
   makeLTauStack("eleTau/7TeV/m_sv_eTau_2011","eleTauPlots42X/eleTauSM.root","eleTau_X",3,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",false,true);
   makeLTauStack("eleTau/7TeV/m_sv_eTau_2011_LOG","eleTauPlots42X/eleTauSM.root","eleTau_X",3,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",true,true);


//    makeLTauStack("eleTau/7TeV/mvis_0JetLow_eTau_2011","eleTauPlots42X/eleTauSMMVis.root","eleTau_0jet_low",3,"m_{e#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",false,true);
//    makeLTauStack("eleTau/7TeV/mvis_0JetLow_eTau_2011_LOG","eleTauPlots42X/eleTauSMMVis.root","eleTau_0jet_low",3,"m_{e#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",true,true);
// 
//    makeLTauStack("eleTau/7TeV/mvis_0JetHigh_eTau_2011","eleTauPlots42X/eleTauSMMVis.root","eleTau_0jet_high",3,"m_{e#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",false,true);
//    makeLTauStack("eleTau/7TeV/mvis_0JetHigh_eTau_2011_LOG","eleTauPlots42X/eleTauSMMVis.root","eleTau_0jet_high",3,"m_{e#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",true,true);
// 
//    makeLTauStack("eleTau/7TeV/mvis_1JetLow_eTau_2011","eleTauPlots42X/eleTauSMMVis.root","eleTau_boost_low",3,"m_{e#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",false,true);
//    makeLTauStack("eleTau/7TeV/mvis_1JetLow_eleTau_2011_LOG","eleTauPlots42X/eleTauSMMVis.root","eleTau_boost_low",3,"m_{e#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",true,true);
// 
//    makeLTauStack("eleTau/7TeV/mvis_1JetHigh_eTau_2011","eleTauPlots42X/eleTauSMMVis.root","eleTau_boost_high",3,"m_{e#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",false,true);
//    makeLTauStack("eleTau/7TeV/mvis_1JetHigh_eTau_2011_LOG","eleTauPlots42X/eleTauSMMVis.root","eleTau_boost_high",3,"m_{e#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",true,true);
// 
//    makeLTauStack("eleTau/7TeV/mvis_vbf_eTau_2011","eleTauPlots42X/eleTauSMMVis.root","eleTau_vbf",3,"m_{e#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",false,true);
//    makeLTauStack("eleTau/7TeV/mvis_vbf_eTau_2011_LOG","eleTauPlots42X/eleTauSMMVis.root","eleTau_vbf",3,"m_{e#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",true,true);

   makeLTauStack("eleTau/7TeV/m_sv_0JetLow_eTau_2011","eleTauPlots42X/eleTauSM.root","eleTau_0jet_low",3,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",false,true);
   makeLTauStack("eleTau/7TeV/m_sv_0JetLow_eTau_2011_LOG","eleTauPlots42X/eleTauSM.root","eleTau_0jet_low",3,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",true,true);

   makeLTauStack("eleTau/7TeV/m_sv_0JetHigh_eTau_2011","eleTauPlots42X/eleTauSM.root","eleTau_0jet_high",3,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",false,true);
   makeLTauStack("eleTau/7TeV/m_sv_0JetHigh_eTau_2011_LOG","eleTauPlots42X/eleTauSM.root","eleTau_0jet_high",3,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",true,true);

   makeLTauStack("eleTau/7TeV/m_sv_1JetLow_eTau_2011","eleTauPlots42X/eleTauSM.root","eleTau_boost_low",3,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",false,true);
   makeLTauStack("eleTau/7TeV/m_sv_1JetLow_eTau_2011_LOG","eleTauPlots42X/eleTauSM.root","eleTau_boost_low",3,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",true,true);

   makeLTauStack("eleTau/7TeV/m_sv_1JetHigh_eTau_2011","eleTauPlots42X/eleTauSM.root","eleTau_boost_high",3,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",false,true);
   makeLTauStack("eleTau/7TeV/m_sv_1JetHigh_eTau_2011_LOG","eleTauPlots42X/eleTauSM.root","eleTau_boost_high",3,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",true,true);

//    makeLTauStack("eleTau/7TeV/m_sv_2Jet_eTau_2011","eleTauPlots42X/eleTauSM.root","eleTau_2jet",3,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",false,true);
//    makeLTauStack("eleTau/7TeV/m_sv_2Jet_eTau_2011_LOG","eleTauPlots42X/eleTauSM.root","eleTau_2jet",3,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",true,true);

//    makeLTauStack("eleTau/7TeV/m_sv_vh_eTau_2011","eleTauPlots42X/eleTauSM.root","eleTau_vh",3,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",false,true);
//    makeLTauStack("eleTau/7TeV/m_sv_vh_eTau_2011_LOG","eleTauPlots42X/eleTauSM.root","eleTau_vh",3,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",true,true);

   makeLTauStack("eleTau/7TeV/m_sv_vbf_eTau_2011","eleTauPlots42X/eleTauSM.root","eleTau_vbf",3,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",false,true);
   makeLTauStack("eleTau/7TeV/m_sv_vbf_eTau_2011_LOG","eleTauPlots42X/eleTauSM.root","eleTau_vbf",3,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",true,true);

//    makeLTauStack("eleTau/7TeV/m_sv_0JetLow_eTau_2011_hm","eleTauPlots42X/eleTau.root","eleTau_0jet_low",1,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",false,true);
//    makeLTauStack("eleTau/7TeV/m_sv_0JetLow_eTau_2011_hm_LOG","eleTauPlots42X/eleTau.root","eleTau_0jet_low",1,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",true,true);
// 
//    makeLTauStack("eleTau/7TeV/m_sv_0JetHigh_eTau_2011_hm","eleTauPlots42X/eleTau.root","eleTau_0jet_high",1,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",false,true);
//    makeLTauStack("eleTau/7TeV/m_sv_0JetHigh_eTau_2011_hm_LOG","eleTauPlots42X/eleTau.root","eleTau_0jet_high",1,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",true,true);
// 
//    makeLTauStack("eleTau/7TeV/m_sv_1JetLow_eTau_2011_hm","eleTauPlots42X/eleTau.root","eleTau_boost_low",1,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",false,true);
//    makeLTauStack("eleTau/7TeV/m_sv_1JetLow_eTau_2011_hm_LOG","eleTauPlots42X/eleTau.root","eleTau_boost_low",1,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",true,true);
// 
//    makeLTauStack("eleTau/7TeV/m_sv_1JetHigh_eTau_2011_hm","eleTauPlots42X/eleTau.root","eleTau_boost_high",1,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",false,true);
//    makeLTauStack("eleTau/7TeV/m_sv_1JetHigh_eTau_2011_hm_LOG","eleTauPlots42X/eleTau.root","eleTau_boost_high",1,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",true,true);
// 
//    makeLTauStack("eleTau/7TeV/m_sv_bJetLow_eTau_2011_hm","eleTauPlots42X/eleTau.root","eleTau_btag_low",1,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",false,true);
//    makeLTauStack("eleTau/7TeV/m_sv_bJetLow_eTau_2011_hm_LOG","eleTauPlots42X/eleTau.root","eleTau_btag_low",1,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",true,true);

//    makeLTauStack("eleTau/7TeV/m_sv_bJet_eTau_2011_hm","eleTauPlots42X/eleTau.root","eleTau_btag",1,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",false,true);
//    makeLTauStack("eleTau/7TeV/m_sv_bJet_eTau_2011_hm_LOG","eleTauPlots42X/eleTau.root","eleTau_btag",1,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",true,true);
// 
//    makeLTauStack("eleTau/7TeV/m_sv_NobJet_eTau_2011_hm","eleTauPlots42X/eleTau.root","eleTau_nobtag",1,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",false,true);
//    makeLTauStack("eleTau/7TeV/m_sv_NobJet_eTau_2011_hm_LOG","eleTauPlots42X/eleTau.root","eleTau_nobtag",1,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",true,true);

//    makeLTauStack("eleTau/7TeV/m_sv_bJetHigh_eTau_2011_hm","eleTauPlots42X/eleTau.root","eleTau_btag_high",1,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",false,true);
//    makeLTauStack("eleTau/7TeV/m_sv_bJetHigh_eTau_2011_hm_LOG","eleTauPlots42X/eleTau.root","eleTau_btag_high",1,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",true,true);




//    makeLTauStack("eleTau/7TeV/mt_1_0JetLow_eTau_2011","eleTauPlots42X/eleTauSMMT.root","eleTau_0jet_low",3,"M_{T}(e,MET)","GeV",false,"#tau_{e}#tau_{h}","2011",false,false);
//    makeLTauStack("eleTau/7TeV/mt_1_0JetLow_eTau_2011_LOG","eleTauPlots42X/eleTauSMMT.root","eleTau_0jet_low",3,"M_{T}(e,MET)","GeV",false,"#tau_{e}#tau_{h}","2011",true,false);
// 
//    makeLTauStack("eleTau/7TeV/mt_1_0JetHigh_eTau_2011","eleTauPlots42X/eleTauSMMT.root","eleTau_0jet_high",3,"M_{T}(e,MET)","GeV",false,"#tau_{e}#tau_{h}","2011",false,false);
//    makeLTauStack("eleTau/7TeV/mt_1_0JetHigh_eTau_2011_LOG","eleTauPlots42X/eleTauSMMT.root","eleTau_0jet_high",3,"M_{T}(e,MET)","GeV",false,"#tau_{e}#tau_{h}","2011",true,false);
// 
//    makeLTauStack("eleTau/7TeV/mt_1_1JetLow_eTau_2011","eleTauPlots42X/eleTauSMMT.root","eleTau_boost_low",3,"M_{T}(e,MET)","GeV",false,"#tau_{e}#tau_{h}","2011",false,false);
//    makeLTauStack("eleTau/7TeV/mt_1_1JetLow_eTau_2011_LOG","eleTauPlots42X/eleTauSMMT.root","eleTau_boost_low",3,"M_{T}(e,MET)","GeV",false,"#tau_{e}#tau_{h}","2011",true,false);
// 
//    makeLTauStack("eleTau/7TeV/mt_1_1JetHigh_eTau_2011","eleTauPlots42X/eleTauSMMT.root","eleTau_boost_high",3,"M_{T}(e,MET)","GeV",false,"#tau_{e}#tau_{h}","2011",false,false);
//    makeLTauStack("eleTau/7TeV/mt_1_1JetHigh_eTau_2011_LOG","eleTauPlots42X/eleTauSMMT.root","eleTau_boost_high",3,"M_{T}(e,MET)","GeV",false,"#tau_{e}#tau_{h}","2011",true,false);
// 
//    makeLTauStack("eleTau/7TeV/mt_1_vbf_eTau_2011","eleTauPlots42X/eleTauSMMT.root","eleTau_vbf",3,"M_{T}(e,MET)","GeV",false,"#tau_{e}#tau_{h}","2011",false,false);
//    makeLTauStack("eleTau/7TeV/mt_1_vbf_eTau_2011_LOG","eleTauPlots42X/eleTauSMMT.root","eleTau_vbf",3,"M_{T}(e,MET)","GeV",false,"#tau_{e}#tau_{h}","2011",true,false);
// 
//    makeLTauStack("eleTau/7TeV/mt_1_bJetLow_eTau_2011","eleTauPlots42X/eleTauMT.root","eleTau_btag_low",1,"M_{T}(e,MET)","GeV",false,"#tau_{e}#tau_{h}","2011",false,false);
//    makeLTauStack("eleTau/7TeV/mt_1_bJetLow_eTau_2011_LOG","eleTauPlots42X/eleTauMT.root","eleTau_btag_low",1,"M_{T}(e,MET)","GeV",false,"#tau_{e}#tau_{h}","2011",true,false);
// 
//    makeLTauStack("eleTau/7TeV/mt_1_bJetHigh_eTau_2011","eleTauPlots42X/eleTauMT.root","eleTau_btag_high",1,"M_{T}(e,MET)","GeV",false,"#tau_{e}#tau_{h}","2011",false,false);
//    makeLTauStack("eleTau/7TeV/mt_1_bJetHigh_eTau_2011_LOG","eleTauPlots42X/eleTauMT.root","eleTau_btag_high",1,"M_{T}(e,MET)","GeV",false,"#tau_{e}#tau_{h}","2011",true,false);

   makeLTauStack("eleTau/7TeV/njets_eTau_2011","eleTauPlots42X/eleTau_jets.root","eleTau_X",0,"Number of Jets","",false,"#tau_{e}#tau_{h}","2011",false,false);
   makeLTauStack("eleTau/7TeV/njets_eTau_2011_LOG","eleTauPlots42X/eleTau_jets.root","eleTau_X",0,"Number of  Jets","",false,"#tau_{e}#tau_{h}","2011",true,false);

//    makeLTauStack("eleTau/7TeV/nbtags_eTau_2011","eleTauPlots42X/eleTau_bjets.root","eleTau_X",0,"Number of  b-Tagged Jets","",false,"#tau_{e}#tau_{h}","2011",false,false);
//    makeLTauStack("eleTau/7TeV/nbtags_eTau_2011_LOG","eleTauPlots42X/eleTau_bjets.root","eleTau_X",0,"Number of b-Tagged Jets","",false,"#tau_{e}#tau_{h}","2011",true,false);

   makeLTauStack("eleTau/7TeV/jdeta_eTau_2011","eleTauPlots42X/eleTau_DEta.root","eleTau_vbf",3,"#Delta #eta(jj)","",false,"#tau_{e}#tau_{h}","2011",false,false);
   makeLTauStack("eleTau/7TeV/mjj_eTau_2011","eleTauPlots42X/eleTau_MJJ.root","eleTau_vbf",3,"M(jj)","GeV",false,"#tau_{e}#tau_{h}","2011",false,false);
  

// makeLTauStack("eleTau/7TeV/cjv_eleTau_2011","eleTauPlots42X/eleTau_cjv.root","eleTau_vbf",3,"Central Jets p_{T}>30 GeV","",false,"#tau_{e}#tau_{h}","2011",false,false,false);
// makeLTauStack("eleTau/7TeV/cjv_eleTau_2011_LOG","eleTauPlots42X/eleTau_cjv.root","eleTau_vbf",3,"Central Jets p_{T}>30 GeV","",false,"#tau_{e}#tau_{h}","2011",true,false,false);

 //   makeLTauStack("eleTau/7TeV/jeta_1_eTau_2011","eleTauPlots42X/eleTau_vbfEta1.root","eleTau_vbf",3,"Leading Jet #eta","",true,"#tau_{e}#tau_{h}","2011",false,false);
//    makeLTauStack("eleTau/7TeV/jeta_2_eTau_2011","eleTauPlots42X/eleTau_vbfEta2.root","eleTau_vbf",3,"Sub-Leading Jet #eta","",true,"#tau_{e}#tau_{h}","2011",false,false);
//    
//    makeLTauStack("eleTau/7TeV/jpt_1_eTau_2011","eleTauPlots42X/eleTau_vbfPt1.root","eleTau_vbf",3,"Leading Jet p_{T}","",false,"#tau_{e}#tau_{h}","2011",false,false);
//    makeLTauStack("eleTau/7TeV/jpt_2_eTau_2011","eleTauPlots42X/eleTau_vbfPt2.root","eleTau_vbf",3,"Sub-Leading Jet p_{T}","",false,"#tau_{e}#tau_{h}","2011",false,false);

   makeLTauStack("eleTau/7TeV/jdeta_eTau_2011_LOG","eleTauPlots42X/eleTau_DEta.root","eleTau_vbf",3,"#Delta #eta(jj)","",false,"#tau_{e}#tau_{h}","2011",true,false);
   makeLTauStack("eleTau/7TeV/mjj_eTau_2011_LOG","eleTauPlots42X/eleTau_MJJ.root","eleTau_vbf",3,"M(jj)","GeV",false,"#tau_{e}#tau_{h}","2011",true,false);

   makeLTauStack("eleTau/7TeV/mt_1_eTau_2011","eleTauPlots42X/eleTau_MT.root","eleTau_X",0,"M_{T}(e,MET)","GeV",false,"#tau_{e}#tau_{h}","2011",false,false);
   makeLTauStack("eleTau/7TeV/met_eTau_2011","eleTauPlots42X/eleTau_MET.root","eleTau_X",0,"MET","GeV",false,"#tau_{e}#tau_{h}","2011",false,false);

   makeLTauStack("eleTau/7TeV/hjetpt_eTau_2011","eleTauPlots42X/eleTau_BoostedPt.root","eleTau_X",0,"highest Jet P_{T}","GeV",false,"#tau_{e}#tau_{h}","2011",false,false);
   makeLTauStack("eleTau/7TeV/hjeteta_eTau_2011","eleTauPlots42X/eleTau_BoostedEta.root","eleTau_X",0,"highest Jet #eta","GeV",true,"#tau_{e}#tau_{h}","2011",false,false);

//    makeLTauStack("eleTau/7TeV/bpt_eTau_2011","eleTauPlots42X/eleTau_BJetPt.root","eleTau_X",0,"B Jet P_{T}","GeV",false,"#tau_{e}#tau_{h}","2011",false,false);
//    makeLTauStack("eleTau/7TeV/beta_eTau_2011","eleTauPlots42X/eleTau_BJetEta.root","eleTau_X",0,"B Jet #eta","GeV",true,"#tau_{e}#tau_{h}","2011",false,false);

   makeLTauStack("eleTau/7TeV/pvs_eTau_2011","eleTauPlots42X/eleTau_NPVs.root","eleTau_X",0,"PVs","",false,"#tau_{e}#tau_{h}","2011",false,false);





}

