{
   gROOT->ProcessLine(".L ../../../../UWAnalysis/ROOT/macros/plotScripts/templatePlots/makePlot2015.C");

   //makeLTauStack(TString name,TString file,TString dir,int s,TString labelX,TString units = "GeV",bool left=false,TString channel = "",TString year = "2012",bool log = false,bool dndm=false,bool doRatio = false,true)
   //makeLTauStackPF("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau/MSSM8TeV/X/eleTau_highestJetEta","eleTauPlotsSS/MSSM/eleTau_highestJetEta.root","eleTau_X",1,"Jet_{1} #eta","",true,"#tau_{#ele}#tau_{h}","2012",false,true,1,1,1,1,1,1,1,1,false,true);

//}
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau_m_vis","eleTauPlotsSS/eleTau_m_vis.root","eleTau_inclusive",3,"visible m_vis","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
 
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau_relIso","eleTauPlotsSS/eleTau_relIso.root","eleTau_inclusive",3,"(charged+neutral)/pt","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau_chIso","eleTauPlotsSS/eleTau_chIso.root","eleTau_inclusive",3,"Charged #tau Iso","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau_neuIso","eleTauPlotsSS/eleTau_neuIso.root","eleTau_inclusive",3,"Neutral #tau Iso","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau_puIso","eleTauPlotsSS/eleTau_puIso.root","eleTau_inclusive",3,"PU #tau Iso","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau_mt_1","eleTauPlotsSS/eleTau_mt_1.root","eleTau_inclusive",3,"m_{T}","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau_mt_2","eleTauPlotsSS/eleTau_mt_2.root","eleTau_inclusive",3,"e +MET m_{T}","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau_mt_2_nocut","eleTauPlotsSS/eleTau_mt_2_nocut.root","eleTau_inclusive",3,"e +MET m_{T}(no mt cut)","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau_m_vis","eleTauPlotsSS/eleTau_m_vis.root","eleTau_inclusive",3,"visible m_vis","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau_iso_1","eleTauPlotsSS/eleTau_iso_1.root","eleTau_inclusive",3,"e iso dR=0.3","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau_iso04_1","eleTauPlotsSS/eleTau_iso04_1.root","eleTau_inclusive",3,"e iso dR=0.4","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau_met","eleTauPlotsSS/eleTau_met.root","eleTau_inclusive",3,"ME_{T}","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau_mt","eleTauPlotsSS/eleTau_mt.root","eleTau_inclusive",3,"Total M_{T}","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau_pt_1","eleTauPlotsSS/eleTau_pt_1.root","eleTau_inclusive",3,"e P_{T} ","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau_tauIso","eleTauPlotsSS/eleTau_tauIso.root","eleTau_inclusive",3,"e tauIso","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau_genVisPt1","eleTauPlotsSS/eleTau_genVisPt1.root","eleTau_inclusive",3,"Gen Visible e P_{T}","GeV",false,"#tau_{e}#tau_{h}","Golden",true,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau_pt_2","eleTauPlotsSS/eleTau_pt_2.root","eleTau_inclusive",3,"#tau P_{T}","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau_genVisPt2","eleTauPlotsSS/eleTau_genVisPt2.root","eleTau_inclusive",3,"Gen Visible #tau P_{T}","GeV",false,"#tau_{e}#tau_{h}","Golden",true,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau_eta_1","eleTauPlotsSS/eleTau_eta_1.root","eleTau_inclusive",3,"#eta_{e}","",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau_eta_2","eleTauPlotsSS/eleTau_eta_2.root","eleTau_inclusive",3,"#eta_{#tau}","",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau_jeta_1","eleTauPlotsSS/eleTau_jeta_1.root","eleTau_inclusive",3,"Leading Jet #eta","",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau_jeta_2","eleTauPlotsSS/eleTau_jeta_2.root","eleTau_inclusive",3,"Sub-Leading Jet #eta","",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau_pth","eleTauPlotsSS/eleTau_pth.root","eleTau_inclusive",3,"Higgs Pt","GeV",false,"#tau_{e}#tau_{h}","Golden",true,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau_q_1","eleTauPlotsSS/eleTau_q_1.root","eleTau_inclusive",3,"q_{e}","",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau_q_2","eleTauPlotsSS/eleTau_q_2.root","eleTau_inclusive",3,"q_{#tau}","",false,"#tau_{e}#tau_{h}","Golden",false,false,true);

   makeLTauStack("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau_vertices","eleTauPlotsSS/eleTau_vertices.root","eleTau_inclusive",3,"vertices","",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau_tauDecayMode","eleTauPlotsSS/eleTau_tauDecayMode.root","eleTau_inclusive",3,"#tau decay mode","",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau_tauZIP","eleTauPlotsSS/eleTau_tauZIP.root","eleTau_inclusive",3,"#tau ZIP","",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau_tauNIsoTracks","eleTauPlotsSS/eleTau_tauNIsoTracks.root","eleTau_inclusive",3,"Number Isolated tracks","",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau_m_2","eleTauPlotsSS/eleTau_m_2.root","eleTau_inclusive",3,"M_{#tau}","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau_mjj","eleTauPlotsSS/eleTau_mjj.root","eleTau_inclusive",3,"M_{JJ}","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau_njetspt20","eleTauPlotsSS/eleTau_njetspt20.root","eleTau_inclusive",3,"Number Jets Pt>20","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau_njets","eleTauPlotsSS/eleTau_njets.root","eleTau_inclusive",3,"Number Jets Pt>30","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau_nbtag","eleTauPlotsSS/eleTau_nbtag.root","eleTau_inclusive",3,"Number CISV Medium Jets Pt>20","",false,"#tau_{e}#tau_{h}","Golden",true,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau_jpt_1","eleTauPlotsSS/eleTau_jpt_1.root","eleTau_inclusive",3,"Leading Jet Pt","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelectionSS/eleTau_jpt_2","eleTauPlotsSS/eleTau_jpt_2.root","eleTau_inclusive",3,"Sub-Leading Jet Pt","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
}


