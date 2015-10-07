{
   gROOT->ProcessLine(".L ../../../../UWAnalysis/ROOT/macros/plotScripts/templatePlots/makePlot2015.C");





 
   makeLTauStack("~/www/ztt/ETau/FullSelectionNoDM56/eleTau_relIso","eleTauPlots/eleTau_relIso.root","eleTau_inclusive",3,"(charged+neutral)/pt","GeV",false,"#tau_{e}#tau_{h}","2015B",false,false,true);
   makeLTauStack("~/www/ztt/ETau/FullSelectionNoDM56/eleTau_chIso","eleTauPlots/eleTau_chIso.root","eleTau_inclusive",3,"Charged #tau Iso","GeV",false,"#tau_{e}#tau_{h}","2015B",false,false,true);
   makeLTauStack("~/www/ztt/ETau/FullSelectionNoDM56/eleTau_neuIso","eleTauPlots/eleTau_neuIso.root","eleTau_inclusive",3,"Neutral #tau Iso","GeV",false,"#tau_{e}#tau_{h}","2015B",false,false,true);
   makeLTauStack("~/www/ztt/ETau/FullSelectionNoDM56/eleTau_puIso","eleTauPlots/eleTau_puIso.root","eleTau_inclusive",3,"PU #tau Iso","GeV",false,"#tau_{e}#tau_{h}","2015B",false,false,true);
   makeLTauStack("~/www/ztt/ETau/FullSelectionNoDM56/eleTau_mt_1","eleTauPlots/eleTau_mt_1.root","eleTau_inclusive",3,"m_{T}","GeV",false,"#tau_{e}#tau_{h}","2015B",false,false,true);
   makeLTauStack("~/www/ztt/ETau/FullSelectionNoDM56/eleTau_m_vis","eleTauPlots/eleTau_m_vis.root","eleTau_inclusive",3,"visible m_vis","GeV",false,"#tau_{e}#tau_{h}","2015B",false,false,true);
   makeLTauStack("~/www/ztt/ETau/FullSelectionNoDM56/eleTau_iso_1","eleTauPlots/eleTau_iso_1.root","eleTau_inclusive",3,"e iso dR=0.3","GeV",false,"#tau_{e}#tau_{h}","2015B",false,false,true);
   makeLTauStack("~/www/ztt/ETau/FullSelectionNoDM56/eleTau_iso04_1","eleTauPlots/eleTau_iso04_1.root","eleTau_inclusive",3,"e iso dR=0.4","GeV",false,"#tau_{e}#tau_{h}","2015B",false,false,true);
   makeLTauStack("~/www/ztt/ETau/FullSelectionNoDM56/eleTau_tauIso","eleTauPlots/eleTau_tauIso.root","eleTau_inclusive",3,"e tauIso","GeV",false,"#tau_{e}#tau_{h}","2015B",false,false,true);
   makeLTauStack("~/www/ztt/ETau/FullSelectionNoDM56/eleTau_met","eleTauPlots/eleTau_met.root","eleTau_inclusive",3,"ME_{T}","GeV",false,"#tau_{e}#tau_{h}","2015B",false,false,true);
   makeLTauStack("~/www/ztt/ETau/FullSelectionNoDM56/eleTau_mt","eleTauPlots/eleTau_mt.root","eleTau_inclusive",3,"Total M_{T}","GeV",false,"#tau_{e}#tau_{h}","2015B",false,false,true);
   makeLTauStack("~/www/ztt/ETau/FullSelectionNoDM56/eleTau_pt_1","eleTauPlots/eleTau_pt_1.root","eleTau_inclusive",3,"e P_{T} ","GeV",false,"#tau_{e}#tau_{h}","2015B",false,false,true);
   makeLTauStack("~/www/ztt/ETau/FullSelectionNoDM56/eleTau_tauIso","eleTauPlots/eleTau_tauIso.root","eleTau_inclusive",3,"e tauIso","GeV",false,"#tau_{e}#tau_{h}","2015B",false,false,true);
   makeLTauStack("~/www/ztt/ETau/FullSelectionNoDM56/eleTau_genVisPt1","eleTauPlots/eleTau_genVisPt1.root","eleTau_inclusive",3,"Gen Visible e P_{T}","GeV",false,"#tau_{e}#tau_{h}","2015B",true,false,true);
   makeLTauStack("~/www/ztt/ETau/FullSelectionNoDM56/eleTau_pt_2","eleTauPlots/eleTau_pt_2.root","eleTau_inclusive",3,"#tau P_{T}","GeV",false,"#tau_{e}#tau_{h}","2015B",false,false,true);
   makeLTauStack("~/www/ztt/ETau/FullSelectionNoDM56/eleTau_genVisPt2","eleTauPlots/eleTau_genVisPt2.root","eleTau_inclusive",3,"Gen Visible #tau P_{T}","GeV",false,"#tau_{e}#tau_{h}","2015B",true,false,true);
   makeLTauStack("~/www/ztt/ETau/FullSelectionNoDM56/eleTau_eta_1","eleTauPlots/eleTau_eta_1.root","eleTau_inclusive",3,"#eta_{e}","",false,"#tau_{e}#tau_{h}","2015B",false,false,true);
   makeLTauStack("~/www/ztt/ETau/FullSelectionNoDM56/eleTau_eta_1_noratio","eleTauPlots/eleTau_eta_1.root","eleTau_inclusive",3,"#eta_{e}","",false,"#tau_{e}#tau_{h}","2015B",false,false,false);
   makeLTauStack("~/www/ztt/ETau/FullSelectionNoDM56/eleTau_eta_2","eleTauPlots/eleTau_eta_2.root","eleTau_inclusive",3,"#eta_{#tau}","",false,"#tau_{e}#tau_{h}","2015B",false,false,true);
   makeLTauStack("~/www/ztt/ETau/FullSelectionNoDM56/eleTau_jeta_1","eleTauPlots/eleTau_jeta_1.root","eleTau_inclusive",3,"Leading Jet #eta","",false,"#tau_{e}#tau_{h}","2015B",false,false,true);
   makeLTauStack("~/www/ztt/ETau/FullSelectionNoDM56/eleTau_jeta_2","eleTauPlots/eleTau_jeta_2.root","eleTau_inclusive",3,"Sub-Leading Jet #eta","",false,"#tau_{e}#tau_{h}","2015B",false,false,true);
   makeLTauStack("~/www/ztt/ETau/FullSelectionNoDM56/eleTau_pth","eleTauPlots/eleTau_pth.root","eleTau_inclusive",3,"Higgs Pt","GeV",false,"#tau_{e}#tau_{h}","2015B",true,false,true);
   makeLTauStack("~/www/ztt/ETau/FullSelectionNoDM56/eleTau_q_1","eleTauPlots/eleTau_q_1.root","eleTau_inclusive",3,"q_{e}","",false,"#tau_{e}#tau_{h}","2015B",false,false,true);
   makeLTauStack("~/www/ztt/ETau/FullSelectionNoDM56/eleTau_q_2","eleTauPlots/eleTau_q_2.root","eleTau_inclusive",3,"q_{#tau}","",false,"#tau_{e}#tau_{h}","2015B",false,false,true);

   makeLTauStack("~/www/ztt/ETau/FullSelectionNoDM56/eleTau_vertices","eleTauPlots/eleTau_vertices.root","eleTau_inclusive",3,"vertices","",false,"#tau_{e}#tau_{h}","2015B",false,false,true);
   makeLTauStack("~/www/ztt/ETau/FullSelectionNoDM56/eleTau_tauDecayMode","eleTauPlots/eleTau_tauDecayMode.root","eleTau_inclusive",3,"#tau decay mode","",false,"#tau_{e}#tau_{h}","2015B",false,false,true);
   makeLTauStack("~/www/ztt/ETau/FullSelectionNoDM56/eleTau_tauNIsoTracks","eleTauPlots/eleTau_tauNIsoTracks.root","eleTau_inclusive",3,"Number Isolated tracks","",false,"#tau_{e}#tau_{h}","2015B",false,false,true);
   makeLTauStack("~/www/ztt/ETau/FullSelectionNoDM56/eleTau_m_2","eleTauPlots/eleTau_m_2.root","eleTau_inclusive",3,"M_{#tau}","GeV",false,"#tau_{e}#tau_{h}","2015B",false,false,true);
   makeLTauStack("~/www/ztt/ETau/FullSelectionNoDM56/eleTau_njetspt20","eleTauPlots/eleTau_njetspt20.root","eleTau_inclusive",3,"Number Jets Pt>20","GeV",false,"#tau_{e}#tau_{h}","2015B",false,false,true);
   makeLTauStack("~/www/ztt/ETau/FullSelectionNoDM56/eleTau_nbtag","eleTauPlots/eleTau_nbtag.root","eleTau_inclusive",3,"Number CISV Medium Jets Pt>20","",false,"#tau_{e}#tau_{h}","2015B",true,false,true);
}


