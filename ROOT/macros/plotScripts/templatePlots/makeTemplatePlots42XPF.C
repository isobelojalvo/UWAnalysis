{
   gROOT->ProcessLine(".L UWAnalysis/ROOT/macros/plotScripts/templatePlots/makePlot.C");

   makeLTauStackPF("Postfit/pt_2_muTau_2011","muTauPlots42X/muTau_pt2.root","muTau_X",3,"#tau p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,false,0.977,1.037,0.87,1.07,1.28,1.01,1.20,0.047);
   makeLTauStackPF("Postfit/pt_1_muTau_2011","muTauPlots42X/muTau_pt1.root","muTau_X",3,"#mu p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,false,0.977,1.037,0.87,1.07,1.28,1.01,1.20,0.047);
   makeLTauStackPF("Postfit/eta_2_muTau_2011","muTauPlots42X/muTau_eta2.root","muTau_X",3,"#tau #eta","",false,"#tau_{#mu}#tau_{h}","2011",false,false,0.977,1.037,0.87,1.07,1.28,1.01,1.20,0.047);
   makeLTauStackPF("Postfit/eta_1_muTau_2011","muTauPlots42X/muTau_eta1.root","muTau_X",3,"#mu #eta","",false,"#tau_{#mu}#tau_{h}","2011",false,false,0.977,1.037,0.87,1.07,1.28,1.01,1.20,0.047);
   makeLTauStackPF("Postfit/met_muTau_2011","muTauPlots42X/muTau_MET.root","muTau_X",3,"MET","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,false,0.977,1.037,0.87,1.07,1.28,1.01,1.20,0.047);
   makeLTauStackPF("Postfit/mvis_muTau_2011","muTauPlots42X/muTau_MVis.root","muTau_X",3,"M_{#mu#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,false,0.977,1.037,0.87,1.07,1.28,1.01,1.20,0.047);
   makeLTauStackPF("Postfit/m_sv_muTau_2011","muTauPlots42X/muTauSM.root","muTau_X",3,"M_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,true,0.977,1.037,0.87,1.07,1.28,1.01,1.20,0.047);
   makeLTauStackPF("Postfit/njets_muTau_2011","muTauPlots42X/muTau_jets.root","muTau_X",3,"Number of Jets","",false,"#tau_{#mu}#tau_{h}","2011",false,false,0.977,1.037,0.87,1.07,1.28,1.01,1.20,0.047);
   makeLTauStackPF("Postfit/pvs_muTau_2011","muTauPlots42X/muTau_NPVs.root","muTau_X",3,"PVs","",false,"#tau_{#mu}#tau_{h}","2011",false,false,0.977,1.037,0.87,1.07,1.28,1.01,1.20,0.047);
   makeLTauStackPF("Postfit/tauMass1P_muTau_2011","muTauPlots42X/muTau_tauMass1P.root","muTau_X",0,"#tau Mass","GeV",true,"#tau_{#mu}#tau_{h}","2011",false,false,0.977,1.037,0.87,1.07,1.28,1.01,1.20,0.047);
   makeLTauStackPF("Postfit/tauMass3P_muTau_2011","muTauPlots42X/muTau_tauMass3P.root","muTau_X",0,"#tau Mass","GeV",true,"#tau_{#mu}#tau_{h}","2011",false,false,0.977,1.037,0.87,1.07,1.28,1.01,1.20,0.047);

   makeLTauStackPF("Postfit/hjetpt_muTau_2011","muTauPlots42X/muTau_BoostedPt.root","muTau_X",0,"highest Jet P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,false,0.988,1.039,1.07,1.09,1.28,1.02,1.19,0.053);
   makeLTauStackPF("Postfit/hjeteta_muTau_2011","muTauPlots42X/muTau_BoostedEta.root","muTau_X",0,"highest Jet #eta","GeV",true,"#tau_{#mu}#tau_{h}","2011",false,false,0.988,1.039,1.07,1.09,1.28,1.02,1.19,0.053);

   makeLTauStackPF("Postfit/mt_1_muTau_2011","muTauPlots42X/muTau_MT.root","muTau_X",0,"M_{T}(#mu,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2011",false,false,0.977,1.037,1.0,1.07,1.28,1.01,1.20,0.047);



   makeLTauStackPF("Postfit/pt_2_eTau_2011","eleTauPlots42X/eleTau_pt2.root","eleTau_X",3,"#tau p_{T}","GeV",false,"#tau_{e}#tau_{h}","2011",false,false,0.976,1.036,1.05,1.13,0.93,1.01,1.036,0.048);
   makeLTauStackPF("Postfit/pt_1_eTau_2011","eleTauPlots42X/eleTau_pt1.root","eleTau_X",3,"e p_{T}","GeV",false,"#tau_{e}#tau_{h}","2011",false,false,0.976,1.036,1.05,1.13,0.93,1.01,1.036,0.048);
   makeLTauStackPF("Postfit/eta_2_eTau_2011","eleTauPlots42X/eleTau_eta2.root","eleTau_X",3,"#tau #eta","",false,"#tau_{e}#tau_{h}","2011",false,false,0.976,1.036,1.05,1.13,0.93,1.01,1.036,0.048);
   makeLTauStackPF("Postfit/eta_1_eTau_2011","eleTauPlots42X/eleTau_eta1.root","eleTau_X",3,"e #eta","",false,"#tau_{e}#tau_{h}","2011",false,false,0.976,1.036,1.05,1.13,0.93,1.01,1.036,0.048);
   makeLTauStackPF("Postfit/met_eTau_2011","eleTauPlots42X/eleTau_MET.root","eleTau_X",3,"MET","GeV",false,"#tau_{e}#tau_{h}","2011",false,false,0.976,1.036,1.05,1.13,0.93,1.01,1.036,0.048);
   makeLTauStackPF("Postfit/mvis_eTau_2011","eleTauPlots42X/eleTau_MVis.root","eleTau_X",3,"M_{e#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",false,false,0.976,1.036,1.05,1.13,0.93,1.01,1.036,0.048);
   makeLTauStackPF("Postfit/m_sv_eTau_2011","eleTauPlots42X/eleTauSM.root","eleTau_X",3,"M_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2011",false,true,0.976,1.036,1.05,1.13,0.93,1.01,1.036,0.048);
   makeLTauStackPF("Postfit/njets_eTau_2011","eleTauPlots42X/eleTau_jets.root","eleTau_X",3,"Number of Jets","",false,"#tau_{e}#tau_{h}","2011",false,false,0.976,1.036,1.05,1.13,0.93,1.01,1.036,0.048);
   makeLTauStackPF("Postfit/pvs_eTau_2011","eleTauPlots42X/eleTau_NPVs.root","eleTau_X",3,"PVs","",false,"#tau_{e}#tau_{h}","2011",false,false,0.976,1.036,1.05,1.13,0.93,1.01,1.036,0.048);


   makeLTauStackPF("Postfit/hjetpt_eTau_2011","eleTauPlots42X/eleTau_BoostedPt.root","eleTau_X",0,"highest Jet P_{T}","GeV",false,"#tau_{e}#tau_{h}","2011",false,false,1.0,1.037,1.03,1.04,0.94,1.01,1.04,0.061);
   makeLTauStackPF("Postfit/hjeteta_eTau_2011","eleTauPlots42X/eleTau_BoostedEta.root","eleTau_X",0,"highest Jet #eta","GeV",true,"#tau_{e}#tau_{h}","2011",false,false,1.0,1.037,1.03,1.04,0.94,1.01,1.04,0.061);

   makeLTauStackPF("Postfit/mt_1_eTau_2011","eleTauPlots42X/eleTau_MT.root","eleTau_X",0,"M_{T}(e,MET)","GeV",false,"#tau_{e}#tau_{h}","2011",false,false,0.976,1.036,1.00,1.13,0.93,1.01,1.036,0.048);

}

