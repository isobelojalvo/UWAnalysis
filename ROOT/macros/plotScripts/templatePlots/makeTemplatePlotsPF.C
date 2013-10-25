{
   gROOT->ProcessLine(".L UWAnalysis/ROOT/macros/plotScripts/templatePlots/makePlot.C");

   makeLTauStackPF("Postfit/pt_2_muTau_2012","muTauPlots/muTau_pt2.root","muTau_X",3,"#tau p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false,0.968,1.16,0.97,1.14,0.97,1.01,1.01,0.045);
   makeLTauStackPF("Postfit/pt_1_muTau_2012","muTauPlots/muTau_pt1.root","muTau_X",3,"#mu p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false,0.968,1.16,0.97,1.14,0.97,1.01,1.01,0.045);
   makeLTauStackPF("Postfit/eta_2_muTau_2012","muTauPlots/muTau_eta2.root","muTau_X",3,"#tau #eta","",false,"#tau_{#mu}#tau_{h}","2012",false,false,0.968,1.16,0.97,1.14,0.97,1.01,1.01,0.045);
   makeLTauStackPF("Postfit/eta_1_muTau_2012","muTauPlots/muTau_eta1.root","muTau_X",3,"#mu #eta","",false,"#tau_{#mu}#tau_{h}","2012",false,false,0.968,1.16,0.97,1.14,0.97,1.01,1.01,0.045);
   makeLTauStackPF("Postfit/met_muTau_2012","muTauPlots/muTau_MET.root","muTau_X",3,"MET","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false,0.968,1.16,0.97,1.14,0.97,1.01,1.01,0.045);
   makeLTauStackPF("Postfit/mvis_muTau_2012","muTauPlots/muTau_MVis.root","muTau_X",3,"M_{#mu#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false,0.968,1.16,0.97,1.14,0.97,1.01,1.01,0.045);
   makeLTauStackPF("Postfit/m_sv_muTau_2012","muTauPlots/muTauSM.root","muTau_X",3,"M_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true,0.968,1.16,0.97,1.14,0.97,1.01,1.01,0.045);
   makeLTauStackPF("Postfit/njets_muTau_2012","muTauPlots/muTau_jets.root","muTau_X",3,"Number of Jets","",false,"#tau_{#mu}#tau_{h}","2012",false,false,0.968,1.16,0.97,1.14,0.97,1.01,1.01,0.045);
   makeLTauStackPF("Postfit/pvs_muTau_2012","muTauPlots/muTau_NPVs.root","muTau_X",3,"PVs","",false,"#tau_{#mu}#tau_{h}","2012",false,false,0.968,1.16,0.97,1.14,0.97,1.01,1.01,0.045);
   makeLTauStackPF("Postfit/tauMass1P_muTau_2012","muTauPlots/muTau_tauMass1P.root","muTau_X",0,"#tau Mass","GeV",true,"#tau_{#mu}#tau_{h}","2012",false,false,0.968,1.16,0.97,1.14,0.97,1.01,1.01,0.045);
   makeLTauStackPF("Postfit/tauMass3P_muTau_2012","muTauPlots/muTau_tauMass3P.root","muTau_X",0,"#tau Mass","GeV",true,"#tau_{#mu}#tau_{h}","2012",false,false,0.968,1.16,0.97,1.14,0.97,1.01,1.01,0.045);

   makeLTauStackPF("Postfit/hjetpt_muTau_2012","muTauPlots/muTau_BoostedPt.root","muTau_X",0,"highest Jet P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false,0.96,1.00,0.92,0.99,0.95,0.94,1.17,0.048);
   makeLTauStackPF("Postfit/hjeteta_muTau_2012","muTauPlots/muTau_BoostedEta.root","muTau_X",0,"highest Jet #eta","GeV",true,"#tau_{#mu}#tau_{h}","2012",false,false,0.96,1.00,0.92,0.99,0.95,0.94,1.17,0.048);

   makeLTauStackPF("Postfit/mt_1_muTau_2012","muTauPlots/muTau_MT.root","muTau_X",0,"M_{T}(#mu,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false,0.968,1.16,1.0,1.14,0.97,1.01,1.01,0.045);





   makeLTauStackPF("Postfit/pt_2_eTau_2012","eleTauPlots/eleTau_pt2.root","eleTau_X",3,"#tau p_{T}","GeV",false,"#tau_{e}#tau_{h}","2012",false,false,0.98,1.2,0.82,1.21,0.97,1.0,1.07,0.046);
   makeLTauStackPF("Postfit/pt_1_eTau_2012","eleTauPlots/eleTau_pt1.root","eleTau_X",3,"e p_{T}","GeV",false,"#tau_{e}#tau_{h}","2012",false,false,0.98,1.2,0.82,1.21,0.97,1.0,1.07,0.046);
   makeLTauStackPF("Postfit/eta_2_eTau_2012","eleTauPlots/eleTau_eta2.root","eleTau_X",3,"#tau #eta","",false,"#tau_{e}#tau_{h}","2012",false,false,0.98,1.2,0.82,1.21,0.97,1.0,1.07,0.046);
   makeLTauStackPF("Postfit/eta_1_eTau_2012","eleTauPlots/eleTau_eta1.root","eleTau_X",3,"e #eta","",false,"#tau_{e}#tau_{h}","2012",false,false,0.98,1.2,0.82,1.21,0.97,1.0,1.07,0.046);
   makeLTauStackPF("Postfit/met_eTau_2012","eleTauPlots/eleTau_MET.root","eleTau_X",3,"MET","GeV",false,"#tau_{e}#tau_{h}","2012",false,false,0.98,1.2,0.82,1.21,0.97,1.0,1.07,0.046);
   makeLTauStackPF("Postfit/mvis_eTau_2012","eleTauPlots/eleTau_MVis.root","eleTau_X",3,"M_{e#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",false,false,0.98,1.2,0.82,1.21,0.97,1.0,1.07,0.046);
   makeLTauStackPF("Postfit/m_sv_eTau_2012","eleTauPlots/eleTauSM.root","eleTau_X",3,"M_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true,0.98,1.2,0.82,1.21,0.97,1.0,1.07,0.046);
   makeLTauStackPF("Postfit/njets_eTau_2012","eleTauPlots/eleTau_jets.root","eleTau_X",3,"Number of Jets","",false,"#tau_{e}#tau_{h}","2012",false,false,0.98,1.2,0.82,1.21,0.97,1.0,1.07,0.046);
   makeLTauStackPF("Postfit/pvs_eTau_2012","eleTauPlots/eleTau_NPVs.root","eleTau_X",3,"PVs","",false,"#tau_{e}#tau_{h}","2012",false,false,0.98,1.2,0.82,1.21,0.97,1.0,1.07,0.046);

   makeLTauStackPF("Postfit/hjetpt_eTau_2012","eleTauPlots/eleTau_BoostedPt.root","eleTau_X",0,"highest Jet P_{T}","GeV",false,"#tau_{e}#tau_{h}","2012",false,false,0.954,0.987,0.99,0.91,0.81,0.97,0.98,0.055);
   makeLTauStackPF("Postfit/hjeteta_eTau_2012","eleTauPlots/eleTau_BoostedEta.root","eleTau_X",0,"highest Jet #eta","GeV",true,"#tau_{e}#tau_{h}","2012",false,false,0.954,0.987,0.99,0.91,0.81,0.97,0.98,0.055);

   makeLTauStackPF("Postfit/mt_1_eTau_2012","eleTauPlots/eleTau_MT.root","eleTau_X",0,"M_{T}(e,MET)","GeV",false,"#tau_{e}#tau_{h}","2012",false,false,0.98,1.2,1.0,1.21,0.97,1.0,1.07,0.046);


}



