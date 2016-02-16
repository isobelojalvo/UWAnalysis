{
   gROOT->ProcessLine(".L ../../../../UWAnalysis/ROOT/macros/plotScripts/templatePlots/makePlot2015.C");

   //makeLTauStack(TString name,TString file,TString dir,int s,TString labelX,TString units = "GeV",bool left=false,TString channel = "",TString year = "2012",bool log = false,bool dndm=false,bool doRatio = false,true)

   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection_WithPU/muTau_m_vis","muTauPlotsPuWeight/muTau_m_vis.root","mt_inclusivemtnotwoprong",3,"visible mass","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   //makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection_WithPU/muTau_m_vis","datacards/htt_mt.inputs-sm-13TeV.root","mt_inclusivemtnotwoprong",3,"visible mass","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection_WithPU/muTau_mt_1","muTauPlotsPuWeight/muTau_mt_1.root","mt_inclusivemtnotwoprong",3,"m_{T}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection_WithPU/muTau_mt_2","muTauPlotsPuWeight/muTau_mt_2.root","mt_inclusivemtnotwoprong",3,"#mu +MET m_{T}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection_WithPU/muTau_mt","muTauPlotsPuWeight/muTau_mt.root","mt_inclusivemtnotwoprong",3,"Total m_{T}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection_WithPU/muTau_m_vis","muTauPlotsPuWeight/muTau_m_vis.root","mt_inclusivemtnotwoprong",3,"visible mass","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection_WithPU/muTau_m_vis_nocut","muTauPlotsPuWeight/muTau_m_vis_nocut.root","mt_inclusivemtnotwoprong",3,"visible mass","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection_WithPU/muTau_iso_1","muTauPlotsPuWeight/muTau_iso_1.root","mt_inclusivemtnotwoprong",3,"Isolation #mu DR=0.3","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection_WithPU/muTau_tauIso","muTauPlotsPuWeight/muTau_tauIso.root","mt_inclusivemtnotwoprong",3,"Raw Tau Isolation","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection_WithPU/muTau_met","muTauPlotsPuWeight/muTau_met.root","mt_inclusivemtnotwoprong",3,"ME_{T}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection_WithPU/muTau_pt1","muTauPlotsPuWeight/muTau_pt_1.root","mt_inclusivemtnotwoprong",3,"#mu P_{T} ","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection_WithPU/muTau_genVisPt1","muTauPlotsPuWeight/muTau_genVisPt1.root","mt_inclusivemtnotwoprong",3,"Gen Visible #mu P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",true,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection_WithPU/muTau_pt_2","muTauPlotsPuWeight/muTau_pt_2.root","mt_inclusivemtnotwoprong",3,"#tau P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection_WithPU/muTau_genVisPt2","muTauPlotsPuWeight/muTau_genVisPt2.root","mt_inclusivemtnotwoprong",3,"Gen Visible #tau P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",true,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection_WithPU/muTau_eta_1","muTauPlotsPuWeight/muTau_eta_1.root","mt_inclusivemtnotwoprong",3,"#eta_{#mu}","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection_WithPU/muTau_eta_2","muTauPlotsPuWeight/muTau_eta_2.root","mt_inclusivemtnotwoprong",3,"#eta_{#tau}","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection_WithPU/muTau_m_vis","muTauPlotsPuWeight/muTau_m_vis.root","mt_inclusivemtnotwoprong",3,"visible mass","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection_WithPU/muTau_pt","muTauPlotsPuWeight/muTau_pt.root","mt_inclusivemtnotwoprong",3,"di-tau Pt","GeV",false,"#tau_{#mu}#tau_{h}","Golden",true,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection_WithPU/muTau_q_1","muTauPlotsPuWeight/muTau_q_1.root","mt_inclusivemtnotwoprong",3,"q_{#mu}","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection_WithPU/muTau_q_2","muTauPlotsPuWeight/muTau_q_2.root","mt_inclusivemtnotwoprong",3,"q_{#tau}","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);

   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection_WithPU/muTau_npv","muTauPlotsPuWeight/muTau_npv.root","mt_inclusivemtnotwoprong",3,"npv","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection_WithPU/muTau_tauDecayMode","muTauPlotsPuWeight/muTau_tauDecayMode.root","mt_inclusivemtnotwoprong",3,"#tau decay mode","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection_WithPU/muTau_m_2","muTauPlotsPuWeight/muTau_m_2.root","mt_inclusivemtnotwoprong",3,"M_{#tau}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection_WithPU/muTau_mjj","muTauPlotsPuWeight/muTau_mjj.root","mt_inclusivemtnotwoprong",3,"M_{JJ}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection_WithPU/muTau_njetspt20","muTauPlotsPuWeight/muTau_njetspt20.root","mt_inclusivemtnotwoprong",3,"Number Jets Pt>20","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection_WithPU/muTau_njets","muTauPlotsPuWeight/muTau_njets.root","mt_inclusivemtnotwoprong",3,"Number Jets Pt>30","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection_WithPU/muTau_nbtag","muTauPlotsPuWeight/muTau_nbtag.root","mt_inclusivemtnotwoprong",3,"Number Jets Pt>30","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection_WithPU/muTau_jeta_1","muTauPlotsPuWeight/muTau_jeta_1.root","mt_inclusivemtnotwoprong",3,"Leading jet #eta","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection_WithPU/muTau_jeta_2","muTauPlotsPuWeight/muTau_jeta_2.root","mt_inclusivemtnotwoprong",3,"Sub-Leading jet #eta","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection_WithPU/muTau_tauNIsoTracks","muTauPlotsPuWeight/muTau_tauNIsoTracks.root","mt_inclusivemtnotwoprong",3,"Number Isolated Tracks","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);

   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection_WithPU/muTau_jpt_1","muTauPlotsPuWeight/muTau_jpt_1.root","mt_inclusivemtnotwoprong",3,"Leading jet Pt","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection_WithPU/muTau_jpt_2","muTauPlotsPuWeight/muTau_jpt_2.root","mt_inclusivemtnotwoprong",3,"Sub-Leading jet Pt","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);

}
