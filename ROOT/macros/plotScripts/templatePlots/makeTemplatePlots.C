{
   gROOT->ProcessLine(".L UWAnalysis/ROOT/macros/plotScripts/templatePlots/makePlot.C");

   makeLTauStack("muTau/8TeV/decayMode_muTau_2012","muTauPlots/muTau_TDMode.root","muTau_X",0,"","",false,"#tau_{#mu}#tau_{h}","2012",false,false,true);

   makeLTauStack("muTau/8TeV/pt_1_muTau_2012","muTauPlots/muTau_pt1.root","muTau_X",0,"#mu p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false,false);
   makeLTauStack("muTau/8TeV/pt_1_muTau_2012_LOG","muTauPlots/muTau_pt1.root","muTau_X",0,"#mu p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,false,false);

   makeLTauStack("muTau/8TeV/pt_2_muTau_2012","muTauPlots/muTau_pt2.root","muTau_X",0,"#tau p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);
   makeLTauStack("muTau/8TeV/pt_2_muTau_2012_LOG","muTauPlots/muTau_pt2.root","muTau_X",0,"#tau p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,false);

   makeLTauStack("muTau/8TeV/eta_1_muTau_2012","muTauPlots/muTau_eta1.root","muTau_X",0,"#mu #eta","",true,"#tau_{#mu}#tau_{h}","2012",false,false);
   makeLTauStack("muTau/8TeV/eta_1_muTau_2012_LOG","muTauPlots/muTau_eta1.root","muTau_X",0,"#mu #eta","",true,"#tau_{#mu}#tau_{h}","2012",true,false);

   makeLTauStack("muTau/8TeV/eta_2_muTau_2012","muTauPlots/muTau_eta2.root","muTau_X",0,"#tau #eta","",true,"#tau_{#mu}#tau_{h}","2012",false,false);
   makeLTauStack("muTau/8TeV/eta_2_muTau_2012_LOG","muTauPlots/muTau_eta2.root","muTau_X",0,"#tau #eta","",true,"#tau_{#mu}#tau_{h}","2012",true,false);

   makeLTauStack("muTau/8TeV/tauMass1P_muTau_2012","muTauPlots/muTau_tauMass1P.root","muTau_X",0,"#tau Mass","GeV",true,"#tau_{#mu}#tau_{h}","2012",false,false);
   makeLTauStack("muTau/8TeV/tauMass3P_muTau_2012","muTauPlots/muTau_tauMass3P.root","muTau_X",0,"#tau Mass","GeV",true,"#tau_{#mu}#tau_{h}","2012",false,false);

   makeLTauStack("muTau/8TeV/mvis_muTau_2012","muTauPlots/muTau_MVis.root","muTau_X",3,"m_{vis}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);
   makeLTauStack("muTau/8TeV/mvis_muTau_2012_LOG","muTauPlots/muTau_MVis.root","muTau_X",3,"m_{vis}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,false);
   
   makeLTauStack("muTau/8TeV/m_sv_muTau_2012","muTauPlots/muTauSM.root","muTau_X",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("muTau/8TeV/m_sv_muTau_2012_LOG","muTauPlots/muTauSM.root","muTau_X",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);

//    makeLTauStack("muTau/8TeV/mvis_0JetLow_muTau_2012","muTauPlots/muTauSMMVis.root","muTau_0jet_low",3,"m_{#mu#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
//    makeLTauStack("muTau/8TeV/mvis_0JetLow_muTau_2012_LOG","muTauPlots/muTauSMMVis.root","muTau_0jet_low",3,"m_{#mu#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);
// 
//    makeLTauStack("muTau/8TeV/mvis_0JetHigh_muTau_2012","muTauPlots/muTauSMMVis.root","muTau_0jet_high",3,"m_{#mu#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
//    makeLTauStack("muTau/8TeV/mvis_0JetHigh_muTau_2012_LOG","muTauPlots/muTauSMMVis.root","muTau_0jet_high",3,"m_{#mu#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);
// 
//    makeLTauStack("muTau/8TeV/mvis_1JetLow_muTau_2012","muTauPlots/muTauSMMVis.root","muTau_boost_low",3,"m_{#mu#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
//    makeLTauStack("muTau/8TeV/mvis_1JetLow_muTau_2012_LOG","muTauPlots/muTauSMMVis.root","muTau_boost_low",3,"m_{#mu#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);
// 
//    makeLTauStack("muTau/8TeV/mvis_1JetHigh_muTau_2012","muTauPlots/muTauSMMVis.root","muTau_boost_high",3,"m_{#mu#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
//    makeLTauStack("muTau/8TeV/mvis_1JetHigh_muTau_2012_LOG","muTauPlots/muTauSMMVis.root","muTau_boost_high",3,"m_{#mu#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);

//   makeLTauStack("muTau/8TeV/mvis_vbf_muTau_2012","muTauPlots/muTauSMMVis.root","muTau_vbf",3,"m_{#mu#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
//   makeLTauStack("muTau/8TeV/mvis_vbf_muTau_2012_LOG","muTauPlots/muTauSMMVis.root","muTau_vbf",3,"m_{#mu#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);

   makeLTauStack("muTau/8TeV/m_sv_0JetLow_muTau_2012","muTauPlots/muTauSM.root","muTau_0jet_low",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("muTau/8TeV/m_sv_0JetLow_muTau_2012_LOG","muTauPlots/muTauSM.root","muTau_0jet_low",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);

   makeLTauStack("muTau/8TeV/m_sv_0JetHigh_muTau_2012","muTauPlots/muTauSM.root","muTau_0jet_high",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("muTau/8TeV/m_sv_0JetHigh_muTau_2012_LOG","muTauPlots/muTauSM.root","muTau_0jet_high",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);

   makeLTauStack("muTau/8TeV/m_sv_1JetLow_muTau_2012","muTauPlots/muTauSM.root","muTau_boost_low",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("muTau/8TeV/m_sv_1JetLow_muTau_2012_LOG","muTauPlots/muTauSM.root","muTau_boost_low",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);

   makeLTauStack("muTau/8TeV/m_sv_1JetHigh_muTau_2012","muTauPlots/muTauSM.root","muTau_boost_high",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("muTau/8TeV/m_sv_1JetHigh_muTau_2012_LOG","muTauPlots/muTauSM.root","muTau_boost_high",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);

   makeLTauStack("muTau/8TeV/m_sv_2Jet_muTau_2012","muTauPlots/muTauSM.root","muTau_2jet",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("muTau/8TeV/m_sv_2Jet_muTau_2012_LOG","muTauPlots/muTauSM.root","muTau_2jet",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);

   makeLTauStack("muTau/8TeV/m_sv_vbf_muTau_2012","muTauPlots/muTauSM.root","muTau_vbf",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("muTau/8TeV/m_sv_vbf_muTau_2012_LOG","muTauPlots/muTauSM.root","muTau_vbf",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);

//    makeLTauStack("muTau/8TeV/m_sv_vh_muTau_2012","muTauPlots/muTauSM.root","muTau_vh",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
//    makeLTauStack("muTau/8TeV/m_sv_vh_muTau_2012_LOG","muTauPlots/muTauSM.root","muTau_vh",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);

//    makeLTauStack("muTau/8TeV/m_sv_0JetLow_muTau_2012_hm","muTauPlots/muTau.root","muTau_0jet_low",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
//    makeLTauStack("muTau/8TeV/m_sv_0JetLow_muTau_2012_hm_LOG","muTauPlots/muTau.root","muTau_0jet_low",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);
// 
//    makeLTauStack("muTau/8TeV/m_sv_0JetHigh_muTau_2012_hm","muTauPlots/muTau.root","muTau_0jet_high",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
//    makeLTauStack("muTau/8TeV/m_sv_0JetHigh_muTau_2012_hm_LOG","muTauPlots/muTau.root","muTau_0jet_high",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);

//    makeLTauStack("muTau/8TeV/m_sv_1JetLow_muTau_2012_hm","muTauPlots/muTau.root","muTau_boost_low",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
//    makeLTauStack("muTau/8TeV/m_sv_1JetLow_muTau_2012_hm_LOG","muTauPlots/muTau.root","muTau_boost_low",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);
// 
//    makeLTauStack("muTau/8TeV/m_sv_1JetHigh_muTau_2012_hm","muTauPlots/muTau.root","muTau_boost_high",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
//    makeLTauStack("muTau/8TeV/m_sv_1JetHigh_muTau_2012_hm_LOG","muTauPlots/muTau.root","muTau_boost_high",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);

//    makeLTauStack("muTau/8TeV/m_sv_bJetLow_muTau_2012_hm","muTauPlots/muTau.root","muTau_btag_low",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
//    makeLTauStack("muTau/8TeV/m_sv_bJetLow_muTau_2012_hm_LOG","muTauPlots/muTau.root","muTau_btag_low",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);
// 
//    makeLTauStack("muTau/8TeV/m_sv_bJetHigh_muTau_2012_hm","muTauPlots/muTau.root","muTau_btag_high",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
//    makeLTauStack("muTau/8TeV/m_sv_bJetHigh_muTau_2012_hm_LOG","muTauPlots/muTau.root","muTau_btag_high",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);
// 
//    makeLTauStack("muTau/8TeV/m_sv_bJet_muTau_2012_hm","muTauPlots/muTau.root","muTau_btag",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
//    makeLTauStack("muTau/8TeV/m_sv_bJet_muTau_2012_hm_LOG","muTauPlots/muTau.root","muTau_btag",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);
// 
//    makeLTauStack("muTau/8TeV/m_sv_NobJet_muTau_2012_hm","muTauPlots/muTau.root","muTau_nobtag",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
//    makeLTauStack("muTau/8TeV/m_sv_NobJet_muTau_2012_hm_LOG","muTauPlots/muTau.root","muTau_nobtag",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);

//    makeLTauStack("muTau/8TeV/mt_1_0JetLow_muTau_2012","muTauPlots/muTauSMMT.root","muTau_0jet_low",3,"M_{T}(#mu,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);
//    makeLTauStack("muTau/8TeV/mt_1_0JetLow_muTau_2012_LOG","muTauPlots/muTauSMMT.root","muTau_0jet_low",3,"M_{T}(#mu,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,false);
// 
//    makeLTauStack("muTau/8TeV/mt_1_0JetHigh_muTau_2012","muTauPlots/muTauSMMT.root","muTau_0jet_high",3,"M_{T}(#mu,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);
//    makeLTauStack("muTau/8TeV/mt_1_0JetHigh_muTau_2012_LOG","muTauPlots/muTauSMMT.root","muTau_0jet_high",3,"M_{T}(#mu,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,false);
// 
//    makeLTauStack("muTau/8TeV/mt_1_1JetLow_muTau_2012","muTauPlots/muTauSMMT.root","muTau_boost_low",3,"M_{T}(#mu,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);
//    makeLTauStack("muTau/8TeV/mt_1_1JetLow_muTau_2012_LOG","muTauPlots/muTauSMMT.root","muTau_boost_low",3,"M_{T}(#mu,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,false);
// 
//    makeLTauStack("muTau/8TeV/mt_1_1JetHigh_muTau_2012","muTauPlots/muTauSMMT.root","muTau_boost_high",3,"M_{T}(#mu,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);
//    makeLTauStack("muTau/8TeV/mt_1_1JetHigh_muTau_2012_LOG","muTauPlots/muTauSMMT.root","muTau_boost_high",3,"M_{T}(#mu,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,false);

//    makeLTauStack("muTau/8TeV/mt_1_bJetLow_muTau_2012","muTauPlots/muTauMT.root","muTau_btag_low",1,"M_{T}(#mu,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);
//    makeLTauStack("muTau/8TeV/mt_1_bJetLow_muTau_2012_LOG","muTauPlots/muTauMT.root","muTau_btag_low",1,"M_{T}(#mu,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,false);
// 
//    makeLTauStack("muTau/8TeV/mt_1_bJetHigh_muTau_2012","muTauPlots/muTauMT.root","muTau_btag_high",1,"M_{T}(#mu,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);
//    makeLTauStack("muTau/8TeV/mt_1_bJetHigh_muTau_2012_LOG","muTauPlots/muTauMT.root","muTau_btag_high",1,"M_{T}(#mu,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,false);
// 
//    makeLTauStack("muTau/8TeV/mt_1_vbf_muTau_2012","muTauPlots/muTauSMMT.root","muTau_vbf",3,"M_{T}(#mu,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);
//    makeLTauStack("muTau/8TeV/mt_1_vbf_muTau_2012_LOG","muTauPlots/muTauSMMT.root","muTau_vbf",3,"M_{T}(#mu,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,false);

   makeLTauStack("muTau/8TeV/njets_muTau_2012","muTauPlots/muTau_jets.root","muTau_X",0,"Number of Jets","",false,"#tau_{#mu}#tau_{h}","2012",false,false);
   makeLTauStack("muTau/8TeV/njets_muTau_2012_LOG","muTauPlots/muTau_jets.root","muTau_X",0,"Number of  Jets","",false,"#tau_{#mu}#tau_{h}","2012",true,false);

//    makeLTauStack("muTau/8TeV/nbtags_muTau_2012","muTauPlots/muTau_bjets.root","muTau_X",3,"Number of  b-Tagged Jets","",false,"#tau_{#mu}#tau_{h}","2012",false,false);
//    makeLTauStack("muTau/8TeV/nbtags_muTau_2012_LOG","muTauPlots/muTau_bjets.root","muTau_X",3,"Number of b-Tagged Jets","",false,"#tau_{#mu}#tau_{h}","2012",true,false);

   makeLTauStack("muTau/8TeV/jdeta_muTau_2012","muTauPlots/muTau_DEta.root","muTau_vbf",3,"#Delta #eta(jj)","",false,"#tau_{#mu}#tau_{h}","2012",false,false);
   makeLTauStack("muTau/8TeV/mjj_muTau_2012","muTauPlots/muTau_MJJ.root","muTau_vbf",3,"M(jj)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);
   makeLTauStack("muTau/8TeV/met_vbf_muTau_2012","muTauPlots/muTau_vbfMET.root","muTau_vbf",3,"MET","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);
   
//    makeLTauStack("muTau/8TeV/jeta_1_muTau_2012","muTauPlots/muTau_vbfEta1.root","muTau_vbf",3,"Leading Jet #eta","",true,"#tau_{#mu}#tau_{h}","2012",false,false);
//    makeLTauStack("muTau/8TeV/jeta_2_muTau_2012","muTauPlots/muTau_vbfEta2.root","muTau_vbf",3,"Sub-Leading Jet #eta","",true,"#tau_{#mu}#tau_{h}","2012",false,false);
//    
//    makeLTauStack("muTau/8TeV/jpt_1_muTau_2012","muTauPlots/muTau_vbfPt1.root","muTau_vbf",3,"Leading Jet p_{T}","",false,"#tau_{#mu}#tau_{h}","2012",false,false);
//    makeLTauStack("muTau/8TeV/jpt_2_muTau_2012","muTauPlots/muTau_vbfPt2.root","muTau_vbf",3,"Sub-Leading Jet p_{T}","",false,"#tau_{#mu}#tau_{h}","2012",false,false);

   makeLTauStack("muTau/8TeV/jdeta_muTau_2012_LOG","muTauPlots/muTau_DEta.root","muTau_vbf",3,"#Delta #eta(jj)","",false,"#tau_{#mu}#tau_{h}","2012",true,false);
   makeLTauStack("muTau/8TeV/mjj_muTau_2012_LOG","muTauPlots/muTau_MJJ.root","muTau_vbf",3,"M(jj)","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,false);

   makeLTauStack("muTau/8TeV/mt_1_muTau_2012","muTauPlots/muTau_MT.root","muTau_X",0,"M_{T}(#mu,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);
   makeLTauStack("muTau/8TeV/met_muTau_2012","muTauPlots/muTau_MET.root","muTau_X",0,"MET","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);

   makeLTauStack("muTau/8TeV/hjetpt_muTau_2012","muTauPlots/muTau_BoostedPt.root","muTau_X",0,"highest Jet P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);
   makeLTauStack("muTau/8TeV/hjeteta_muTau_2012","muTauPlots/muTau_BoostedEta.root","muTau_X",0,"highest Jet #eta","GeV",true,"#tau_{#mu}#tau_{h}","2012",false,false);

//    makeLTauStack("muTau/8TeV/bpt_muTau_2012","muTauPlots/muTau_BJetPt.root","muTau_X",3,"B Jet P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);
//    makeLTauStack("muTau/8TeV/beta_muTau_2012","muTauPlots/muTau_BJetEta.root","muTau_X",3,"B Jet #eta","GeV",true,"#tau_{#mu}#tau_{h}","2012",false,false);

   makeLTauStack("muTau/8TeV/pvs_muTau_2012","muTauPlots/muTau_NPVs.root","muTau_X",0,"PVs","",false,"#tau_{#mu}#tau_{h}","2012",false,false);

// makeLTauStack("muTau/8TeV/cjv_muTau_2012","muTauPlots/muTau_cjv.root","muTau_vbf",3,"Central Jets p_{T}>30 GeV","",false,"#tau_{#mu}#tau_{h}","2012",false,false,false);
// makeLTauStack("muTau/8TeV/cjv_muTau_2012_LOG","muTauPlots/muTau_cjv.root","muTau_vbf",3,"Central Jets p_{T}>30 GeV","",false,"#tau_{#mu}#tau_{h}","2012",true,false,false);



   makeLTauStack("eleTau/8TeV/decayMode_eleTau_2012","eleTauPlots/eleTau_TDMode.root","eleTau_X",0,"","",false,"#tau_{e}#tau_{h}","2012",false,false,true);

   makeLTauStack("eleTau/8TeV/pt_1_eTau_2012","eleTauPlots/eleTau_pt1.root","eleTau_X",0,"e p_{T}","GeV",false,"#tau_{e}#tau_{h}","2012",false,false);
   makeLTauStack("eleTau/8TeV/pt_1_eTau_2012_LOG","eleTauPlots/eleTau_pt1.root","eleTau_X",0,"e p_{T}","GeV",false,"#tau_{e}#tau_{h}","2012",true,false);

   makeLTauStack("eleTau/8TeV/pt_2_eTau_2012","eleTauPlots/eleTau_pt2.root","eleTau_X",0,"#tau p_{T}","GeV",false,"#tau_{e}#tau_{h}","2012",false,false);
   makeLTauStack("eleTau/8TeV/pt_2_eTau_2012_LOG","eleTauPlots/eleTau_pt2.root","eleTau_X",0,"#tau p_{T}","GeV",false,"#tau_{e}#tau_{h}","2012",true,false);

   makeLTauStack("eleTau/8TeV/eta_1_eTau_2012","eleTauPlots/eleTau_eta1.root","eleTau_X",0,"e #eta","",true,"#tau_{e}#tau_{h}","2012",false,false);
   makeLTauStack("eleTau/8TeV/eta_1_eTau_2012_LOG","eleTauPlots/eleTau_eta1.root","eleTau_X",0,"e #eta","",true,"#tau_{e}#tau_{h}","2012",true,false);

   makeLTauStack("eleTau/8TeV/eta_2_eTau_2012","eleTauPlots/eleTau_eta2.root","eleTau_X",0,"#tau #eta","",true,"#tau_{e}#tau_{h}","2012",false,false);
   makeLTauStack("eleTau/8TeV/eta_2_eTau_2012_LOG","eleTauPlots/eleTau_eta2.root","eleTau_X",0,"#tau #eta","",true,"#tau_{e}#tau_{h}","2012",true,false);

   makeLTauStack("eleTau/8TeV/mvis_eTau_2012","eleTauPlots/eleTau_MVis.root","eleTau_X",3,"m_{vis}","GeV",false,"#tau_{e}#tau_{h}","2012",false,false);
   makeLTauStack("eleTau/8TeV/mvis_eTau_2012_LOG","eleTauPlots/eleTau_MVis.root","eleTau_X",3,"m_{vis}","GeV",false,"#tau_{e}#tau_{h}","2012",true,false);
   
   makeLTauStack("eleTau/8TeV/m_sv_eTau_2012","eleTauPlots/eleTauSM.root","eleTau_X",3,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true);
   makeLTauStack("eleTau/8TeV/m_sv_eTau_2012_LOG","eleTauPlots/eleTauSM.root","eleTau_X",3,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",true,true);


//    makeLTauStack("eleTau/8TeV/mvis_0JetLow_eTau_2012","eleTauPlots/eleTauSMMVis.root","eleTau_0jet_low",3,"m_{e#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true);
//    makeLTauStack("eleTau/8TeV/mvis_0JetLow_eTau_2012_LOG","eleTauPlots/eleTauSMMVis.root","eleTau_0jet_low",3,"m_{e#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",true,true);
// 
//    makeLTauStack("eleTau/8TeV/mvis_0JetHigh_eTau_2012","eleTauPlots/eleTauSMMVis.root","eleTau_0jet_high",3,"m_{e#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true);
//    makeLTauStack("eleTau/8TeV/mvis_0JetHigh_eTau_2012_LOG","eleTauPlots/eleTauSMMVis.root","eleTau_0jet_high",3,"m_{e#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",true,true);
// 
//    makeLTauStack("eleTau/8TeV/mvis_1JetLow_eTau_2012","eleTauPlots/eleTauSMMVis.root","eleTau_boost_low",3,"m_{e#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true);
//    makeLTauStack("eleTau/8TeV/mvis_1JetLow_eleTau_2012_LOG","eleTauPlots/eleTauSMMVis.root","eleTau_boost_low",3,"m_{e#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",true,true);
// 
//    makeLTauStack("eleTau/8TeV/mvis_1JetHigh_eTau_2012","eleTauPlots/eleTauSMMVis.root","eleTau_boost_high",3,"m_{e#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true);
//    makeLTauStack("eleTau/8TeV/mvis_1JetHigh_eTau_2012_LOG","eleTauPlots/eleTauSMMVis.root","eleTau_boost_high",3,"m_{e#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",true,true);
// 
//    makeLTauStack("eleTau/8TeV/mvis_vbf_eTau_2012","eleTauPlots/eleTauSMMVis.root","eleTau_vbf",3,"m_{e#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true);
//    makeLTauStack("eleTau/8TeV/mvis_vbf_eTau_2012_LOG","eleTauPlots/eleTauSMMVis.root","eleTau_vbf",3,"m_{e#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",true,true);

   makeLTauStack("eleTau/8TeV/m_sv_0JetLow_eTau_2012","eleTauPlots/eleTauSM.root","eleTau_0jet_low",3,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true);
   makeLTauStack("eleTau/8TeV/m_sv_0JetLow_eTau_2012_LOG","eleTauPlots/eleTauSM.root","eleTau_0jet_low",3,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",true,true);

   makeLTauStack("eleTau/8TeV/m_sv_0JetHigh_eTau_2012","eleTauPlots/eleTauSM.root","eleTau_0jet_high",3,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true);
   makeLTauStack("eleTau/8TeV/m_sv_0JetHigh_eTau_2012_LOG","eleTauPlots/eleTauSM.root","eleTau_0jet_high",3,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",true,true);

   makeLTauStack("eleTau/8TeV/m_sv_1JetLow_eTau_2012","eleTauPlots/eleTauSM.root","eleTau_boost_low",3,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true);
   makeLTauStack("eleTau/8TeV/m_sv_1JetLow_eTau_2012_LOG","eleTauPlots/eleTauSM.root","eleTau_boost_low",3,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",true,true);

   makeLTauStack("eleTau/8TeV/m_sv_1JetHigh_eTau_2012","eleTauPlots/eleTauSM.root","eleTau_boost_high",3,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true);
   makeLTauStack("eleTau/8TeV/m_sv_1JetHigh_eTau_2012_LOG","eleTauPlots/eleTauSM.root","eleTau_boost_high",3,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",true,true);

   makeLTauStack("eleTau/8TeV/m_sv_2Jet_eTau_2012","eleTauPlots/eleTauSM.root","eleTau_2jet",3,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true);
   makeLTauStack("eleTau/8TeV/m_sv_2Jet_eTau_2012_LOG","eleTauPlots/eleTauSM.root","eleTau_2jet",3,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",true,true);

//    makeLTauStack("eleTau/8TeV/m_sv_vh_eTau_2012","eleTauPlots/eleTauSM.root","eleTau_vh",3,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true);
//    makeLTauStack("eleTau/8TeV/m_sv_vh_eTau_2012_LOG","eleTauPlots/eleTauSM.root","eleTau_vh",3,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",true,true);

   makeLTauStack("eleTau/8TeV/m_sv_vbf_eTau_2012","eleTauPlots/eleTauSM.root","eleTau_vbf",3,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true);
   makeLTauStack("eleTau/8TeV/m_sv_vbf_eTau_2012_LOG","eleTauPlots/eleTauSM.root","eleTau_vbf",3,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",true,true);

//    makeLTauStack("eleTau/8TeV/m_sv_0JetLow_eTau_2012_hm","eleTauPlots/eleTau.root","eleTau_0jet_low",1,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true);
//    makeLTauStack("eleTau/8TeV/m_sv_0JetLow_eTau_2012_hm_LOG","eleTauPlots/eleTau.root","eleTau_0jet_low",1,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",true,true);
// 
//    makeLTauStack("eleTau/8TeV/m_sv_0JetHigh_eTau_2012_hm","eleTauPlots/eleTau.root","eleTau_0jet_high",1,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true);
//    makeLTauStack("eleTau/8TeV/m_sv_0JetHigh_eTau_2012_hm_LOG","eleTauPlots/eleTau.root","eleTau_0jet_high",1,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",true,true);
// 
//    makeLTauStack("eleTau/8TeV/m_sv_1JetLow_eTau_2012_hm","eleTauPlots/eleTau.root","eleTau_boost_low",1,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true);
//    makeLTauStack("eleTau/8TeV/m_sv_1JetLow_eTau_2012_hm_LOG","eleTauPlots/eleTau.root","eleTau_boost_low",1,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",true,true);
// 
//    makeLTauStack("eleTau/8TeV/m_sv_1JetHigh_eTau_2012_hm","eleTauPlots/eleTau.root","eleTau_boost_high",1,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true);
//    makeLTauStack("eleTau/8TeV/m_sv_1JetHigh_eTau_2012_hm_LOG","eleTauPlots/eleTau.root","eleTau_boost_high",1,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",true,true);
// 
//    makeLTauStack("eleTau/8TeV/m_sv_bJetLow_eTau_2012_hm","eleTauPlots/eleTau.root","eleTau_btag_low",1,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true);
//    makeLTauStack("eleTau/8TeV/m_sv_bJetLow_eTau_2012_hm_LOG","eleTauPlots/eleTau.root","eleTau_btag_low",1,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",true,true);

//    makeLTauStack("eleTau/8TeV/m_sv_bJet_eTau_2012_hm","eleTauPlots/eleTau.root","eleTau_btag",1,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true);
//    makeLTauStack("eleTau/8TeV/m_sv_bJet_eTau_2012_hm_LOG","eleTauPlots/eleTau.root","eleTau_btag",1,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",true,true);
// 
//    makeLTauStack("eleTau/8TeV/m_sv_NobJet_eTau_2012_hm","eleTauPlots/eleTau.root","eleTau_nobtag",1,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true);
//    makeLTauStack("eleTau/8TeV/m_sv_NobJet_eTau_2012_hm_LOG","eleTauPlots/eleTau.root","eleTau_nobtag",1,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",true,true);

//    makeLTauStack("eleTau/8TeV/m_sv_bJetHigh_eTau_2012_hm","eleTauPlots/eleTau.root","eleTau_btag_high",1,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true);
//    makeLTauStack("eleTau/8TeV/m_sv_bJetHigh_eTau_2012_hm_LOG","eleTauPlots/eleTau.root","eleTau_btag_high",1,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",true,true);




//    makeLTauStack("eleTau/8TeV/mt_1_0JetLow_eTau_2012","eleTauPlots/eleTauSMMT.root","eleTau_0jet_low",3,"M_{T}(e,MET)","GeV",false,"#tau_{e}#tau_{h}","2012",false,false);
//    makeLTauStack("eleTau/8TeV/mt_1_0JetLow_eTau_2012_LOG","eleTauPlots/eleTauSMMT.root","eleTau_0jet_low",3,"M_{T}(e,MET)","GeV",false,"#tau_{e}#tau_{h}","2012",true,false);
// 
//    makeLTauStack("eleTau/8TeV/mt_1_0JetHigh_eTau_2012","eleTauPlots/eleTauSMMT.root","eleTau_0jet_high",3,"M_{T}(e,MET)","GeV",false,"#tau_{e}#tau_{h}","2012",false,false);
//    makeLTauStack("eleTau/8TeV/mt_1_0JetHigh_eTau_2012_LOG","eleTauPlots/eleTauSMMT.root","eleTau_0jet_high",3,"M_{T}(e,MET)","GeV",false,"#tau_{e}#tau_{h}","2012",true,false);
// 
//    makeLTauStack("eleTau/8TeV/mt_1_1JetLow_eTau_2012","eleTauPlots/eleTauSMMT.root","eleTau_boost_low",3,"M_{T}(e,MET)","GeV",false,"#tau_{e}#tau_{h}","2012",false,false);
//    makeLTauStack("eleTau/8TeV/mt_1_1JetLow_eTau_2012_LOG","eleTauPlots/eleTauSMMT.root","eleTau_boost_low",3,"M_{T}(e,MET)","GeV",false,"#tau_{e}#tau_{h}","2012",true,false);
// 
//    makeLTauStack("eleTau/8TeV/mt_1_1JetHigh_eTau_2012","eleTauPlots/eleTauSMMT.root","eleTau_boost_high",3,"M_{T}(e,MET)","GeV",false,"#tau_{e}#tau_{h}","2012",false,false);
//    makeLTauStack("eleTau/8TeV/mt_1_1JetHigh_eTau_2012_LOG","eleTauPlots/eleTauSMMT.root","eleTau_boost_high",3,"M_{T}(e,MET)","GeV",false,"#tau_{e}#tau_{h}","2012",true,false);
// 
//    makeLTauStack("eleTau/8TeV/mt_1_vbf_eTau_2012","eleTauPlots/eleTauSMMT.root","eleTau_vbf",3,"M_{T}(e,MET)","GeV",false,"#tau_{e}#tau_{h}","2012",false,false);
//    makeLTauStack("eleTau/8TeV/mt_1_vbf_eTau_2012_LOG","eleTauPlots/eleTauSMMT.root","eleTau_vbf",3,"M_{T}(e,MET)","GeV",false,"#tau_{e}#tau_{h}","2012",true,false);
// 
//    makeLTauStack("eleTau/8TeV/mt_1_bJetLow_eTau_2012","eleTauPlots/eleTauMT.root","eleTau_btag_low",1,"M_{T}(e,MET)","GeV",false,"#tau_{e}#tau_{h}","2012",false,false);
//    makeLTauStack("eleTau/8TeV/mt_1_bJetLow_eTau_2012_LOG","eleTauPlots/eleTauMT.root","eleTau_btag_low",1,"M_{T}(e,MET)","GeV",false,"#tau_{e}#tau_{h}","2012",true,false);
// 
//    makeLTauStack("eleTau/8TeV/mt_1_bJetHigh_eTau_2012","eleTauPlots/eleTauMT.root","eleTau_btag_high",1,"M_{T}(e,MET)","GeV",false,"#tau_{e}#tau_{h}","2012",false,false);
//    makeLTauStack("eleTau/8TeV/mt_1_bJetHigh_eTau_2012_LOG","eleTauPlots/eleTauMT.root","eleTau_btag_high",1,"M_{T}(e,MET)","GeV",false,"#tau_{e}#tau_{h}","2012",true,false);

   makeLTauStack("eleTau/8TeV/njets_eTau_2012","eleTauPlots/eleTau_jets.root","eleTau_X",0,"Number of Jets","",false,"#tau_{e}#tau_{h}","2012",false,false);
   makeLTauStack("eleTau/8TeV/njets_eTau_2012_LOG","eleTauPlots/eleTau_jets.root","eleTau_X",0,"Number of  Jets","",false,"#tau_{e}#tau_{h}","2012",true,false);

//    makeLTauStack("eleTau/8TeV/nbtags_eTau_2012","eleTauPlots/eleTau_bjets.root","eleTau_X",0,"Number of  b-Tagged Jets","",false,"#tau_{e}#tau_{h}","2012",false,false);
//    makeLTauStack("eleTau/8TeV/nbtags_eTau_2012_LOG","eleTauPlots/eleTau_bjets.root","eleTau_X",0,"Number of b-Tagged Jets","",false,"#tau_{e}#tau_{h}","2012",true,false);

   makeLTauStack("eleTau/8TeV/jdeta_eTau_2012","eleTauPlots/eleTau_DEta.root","eleTau_vbf",3,"#Delta #eta(jj)","",false,"#tau_{e}#tau_{h}","2012",false,false);
   makeLTauStack("eleTau/8TeV/mjj_eTau_2012","eleTauPlots/eleTau_MJJ.root","eleTau_vbf",3,"M(jj)","GeV",false,"#tau_{e}#tau_{h}","2012",false,false);
   makeLTauStack("eleTau/8TeV/met_vbf_eTau_2012","eleTauPlots/eleTau_vbfMET.root","eleTau_vbf",3,"MET","GeV",false,"#tau_{e}#tau_{h}","2012",false,false);
  

// makeLTauStack("eleTau/8TeV/cjv_eleTau_2012","eleTauPlots/eleTau_cjv.root","eleTau_vbf",3,"Central Jets p_{T}>30 GeV","",false,"#tau_{e}#tau_{h}","2012",false,false,false);
// makeLTauStack("eleTau/8TeV/cjv_eleTau_2012_LOG","eleTauPlots/eleTau_cjv.root","eleTau_vbf",3,"Central Jets p_{T}>30 GeV","",false,"#tau_{e}#tau_{h}","2012",true,false,false);

 //   makeLTauStack("eleTau/8TeV/jeta_1_eTau_2012","eleTauPlots/eleTau_vbfEta1.root","eleTau_vbf",3,"Leading Jet #eta","",true,"#tau_{e}#tau_{h}","2012",false,false);
//    makeLTauStack("eleTau/8TeV/jeta_2_eTau_2012","eleTauPlots/eleTau_vbfEta2.root","eleTau_vbf",3,"Sub-Leading Jet #eta","",true,"#tau_{e}#tau_{h}","2012",false,false);
//    
//    makeLTauStack("eleTau/8TeV/jpt_1_eTau_2012","eleTauPlots/eleTau_vbfPt1.root","eleTau_vbf",3,"Leading Jet p_{T}","",false,"#tau_{e}#tau_{h}","2012",false,false);
//    makeLTauStack("eleTau/8TeV/jpt_2_eTau_2012","eleTauPlots/eleTau_vbfPt2.root","eleTau_vbf",3,"Sub-Leading Jet p_{T}","",false,"#tau_{e}#tau_{h}","2012",false,false);

   makeLTauStack("eleTau/8TeV/jdeta_eTau_2012_LOG","eleTauPlots/eleTau_DEta.root","eleTau_vbf",3,"#Delta #eta(jj)","",false,"#tau_{e}#tau_{h}","2012",true,false);
   makeLTauStack("eleTau/8TeV/mjj_eTau_2012_LOG","eleTauPlots/eleTau_MJJ.root","eleTau_vbf",3,"M(jj)","GeV",false,"#tau_{e}#tau_{h}","2012",true,false);

   makeLTauStack("eleTau/8TeV/mt_1_eTau_2012","eleTauPlots/eleTau_MT.root","eleTau_X",0,"M_{T}(e,MET)","GeV",false,"#tau_{e}#tau_{h}","2012",false,false);
   makeLTauStack("eleTau/8TeV/met_eTau_2012","eleTauPlots/eleTau_MET.root","eleTau_X",0,"MET","GeV",false,"#tau_{e}#tau_{h}","2012",false,false);

   makeLTauStack("eleTau/8TeV/hjetpt_eTau_2012","eleTauPlots/eleTau_BoostedPt.root","eleTau_X",0,"highest Jet P_{T}","GeV",false,"#tau_{e}#tau_{h}","2012",false,false);
   makeLTauStack("eleTau/8TeV/hjeteta_eTau_2012","eleTauPlots/eleTau_BoostedEta.root","eleTau_X",0,"highest Jet #eta","GeV",true,"#tau_{e}#tau_{h}","2012",false,false);

//    makeLTauStack("eleTau/8TeV/bpt_eTau_2012","eleTauPlots/eleTau_BJetPt.root","eleTau_X",0,"B Jet P_{T}","GeV",false,"#tau_{e}#tau_{h}","2012",false,false);
//    makeLTauStack("eleTau/8TeV/beta_eTau_2012","eleTauPlots/eleTau_BJetEta.root","eleTau_X",0,"B Jet #eta","GeV",true,"#tau_{e}#tau_{h}","2012",false,false);

   makeLTauStack("eleTau/8TeV/pvs_eTau_2012","eleTauPlots/eleTau_NPVs.root","eleTau_X",0,"PVs","",false,"#tau_{e}#tau_{h}","2012",false,false);







}

