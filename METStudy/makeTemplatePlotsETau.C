{
   gROOT->ProcessLine(".L ../../../../UWAnalysis/ROOT/macros/plotScripts/templatePlots/makePlot2015.C");

   //makeLTauStack(TString name,TString file,TString dir,int s,TString labelX,TString units = "GeV",bool left=false,TString channel = "",TString year = "2012",bool log = false,bool dndm=false,bool doRatio = false,true)
   //makeLTauStackPF("~/www/ztt/ETau/25ns_FullSelection/eleTau/MSSM8TeV/X/eleTau_highestJetEta","eleTauPlots/MSSM/eleTau_highestJetEta.root","eleTau_X",1,"Jet_{1} #eta","",true,"#tau_{#ele}#tau_{h}","2012",false,true,1,1,1,1,1,1,1,1,false,true);

//}
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_m_vis","eleTauPlots/eleTau_m_vis.root","et_inclusivemtnotwoprong",3,"visible m_vis","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_relIso","eleTauPlots/eleTau_relIso.root","et_inclusivemtnotwoprong",3,"(charged+neutral)/pt","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_chIso","eleTauPlots/eleTau_chIso.root","et_inclusivemtnotwoprong",3,"Charged #tau Iso","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_neuIso","eleTauPlots/eleTau_neuIso.root","et_inclusivemtnotwoprong",3,"Neutral #tau Iso","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_puIso","eleTauPlots/eleTau_puIso.root","et_inclusivemtnotwoprong",3,"PU #tau Iso","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_mt_1","eleTauPlots/eleTau_mt_1.root","et_inclusivemtnotwoprong",3,"m_{T}","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_mt_2","eleTauPlots/eleTau_mt_2.root","et_inclusivemtnotwoprong",3,"e +MET m_{T}","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_mt_2_nocut","eleTauPlots/eleTau_mt_2_nocut.root","et_inclusivemtnotwoprong",3,"e +MET m_{T}(no mt cut)","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_m_vis","eleTauPlots/eleTau_m_vis.root","et_inclusivemtnotwoprong",3,"visible m_vis","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_iso_1","eleTauPlots/eleTau_iso_1.root","et_inclusivemtnotwoprong",3,"e iso dR=0.3","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_iso04_1","eleTauPlots/eleTau_iso04_1.root","et_inclusivemtnotwoprong",3,"e iso dR=0.4","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_met","eleTauPlots/eleTau_met.root","et_inclusivemtnotwoprong",3,"ME_{T}","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_mt","eleTauPlots/eleTau_mt.root","et_inclusivemtnotwoprong",3,"Total M_{T}","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_pt_1","eleTauPlots/eleTau_pt_1.root","et_inclusivemtnotwoprong",3,"e P_{T} ","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_tauIso","eleTauPlots/eleTau_tauIso.root","et_inclusivemtnotwoprong",3,"e tauIso","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_genVisPt1","eleTauPlots/eleTau_genVisPt1.root","et_inclusivemtnotwoprong",3,"Gen Visible e P_{T}","GeV",false,"#tau_{e}#tau_{h}","Golden",true,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_pt_2","eleTauPlots/eleTau_pt_2.root","et_inclusivemtnotwoprong",3,"#tau P_{T}","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_genVisPt2","eleTauPlots/eleTau_genVisPt2.root","et_inclusivemtnotwoprong",3,"Gen Visible #tau P_{T}","GeV",false,"#tau_{e}#tau_{h}","Golden",true,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_eta_1","eleTauPlots/eleTau_eta_1.root","et_inclusivemtnotwoprong",3,"#eta_{e}","",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_eta_2","eleTauPlots/eleTau_eta_2.root","et_inclusivemtnotwoprong",3,"#eta_{#tau}","",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_jeta_1","eleTauPlots/eleTau_jeta_1.root","et_inclusivemtnotwoprong",3,"Leading Jet #eta","",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_jeta_2","eleTauPlots/eleTau_jeta_2.root","et_inclusivemtnotwoprong",3,"Sub-Leading Jet #eta","",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_pth","eleTauPlots/eleTau_pth.root","et_inclusivemtnotwoprong",3,"Higgs Pt","GeV",false,"#tau_{e}#tau_{h}","Golden",true,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_q_1","eleTauPlots/eleTau_q_1.root","et_inclusivemtnotwoprong",3,"q_{e}","",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_q_2","eleTauPlots/eleTau_q_2.root","et_inclusivemtnotwoprong",3,"q_{#tau}","",false,"#tau_{e}#tau_{h}","Golden",false,false,true);

   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_vertices","eleTauPlots/eleTau_vertices.root","et_inclusivemtnotwoprong",3,"vertices","",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_tauDecayMode","eleTauPlots/eleTau_tauDecayMode.root","et_inclusivemtnotwoprong",3,"#tau decay mode","",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_tauZIP","eleTauPlots/eleTau_tauZIP.root","et_inclusivemtnotwoprong",3,"#tau ZIP","",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_tauNIsoTracks","eleTauPlots/eleTau_tauNIsoTracks.root","et_inclusivemtnotwoprong",3,"Number Isolated tracks","",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_m_2","eleTauPlots/eleTau_m_2.root","et_inclusivemtnotwoprong",3,"M_{#tau}","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_mjj","eleTauPlots/eleTau_mjj.root","et_inclusivemtnotwoprong",3,"M_{JJ}","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_njetspt20","eleTauPlots/eleTau_njetspt20.root","et_inclusivemtnotwoprong",3,"Number Jets Pt>20","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_njets","eleTauPlots/eleTau_njets.root","et_inclusivemtnotwoprong",3,"Number Jets Pt>30","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_nbtag","eleTauPlots/eleTau_nbtag.root","et_inclusivemtnotwoprong",3,"Number CISV Medium Jets Pt>20","",false,"#tau_{e}#tau_{h}","Golden",true,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_jpt_1","eleTauPlots/eleTau_jpt_1.root","et_inclusivemtnotwoprong",3,"Leading Jet Pt","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_jpt_2","eleTauPlots/eleTau_jpt_2.root","et_inclusivemtnotwoprong",3,"Sub-Leading Jet Pt","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
}


