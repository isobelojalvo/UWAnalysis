{
   gROOT->ProcessLine(".L ../../../../UWAnalysis/ROOT/macros/plotScripts/templatePlots/makePlot2015.C");

   //makeLTauStack(TString name,TString file,TString dir,int s,TString labelX,TString units = "GeV",bool left=false,TString channel = "",TString year = "2012",bool log = false,bool dndm=false,bool doRatio = false,true)

   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection/muTau_m_vis","muTauPlots/muTau_m_vis.root","mt_inclusivemtnotwoprong",3,"visible mass","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   //makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection/muTau_m_vis","datacards/htt_mt.inputs-sm-13TeV.root","mt_inclusivemtnotwoprong",3,"visible mass","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection/muTau_mt_1","muTauPlots/muTau_mt_1.root","mt_inclusivemtnotwoprong",3,"m_{T}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection/muTau_mt_2","muTauPlots/muTau_mt_2.root","mt_inclusivemtnotwoprong",3,"#mu +MET m_{T}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection/muTau_mt","muTauPlots/muTau_mt.root","mt_inclusivemtnotwoprong",3,"Total m_{T}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection/muTau_m_vis","muTauPlots/muTau_m_vis.root","mt_inclusivemtnotwoprong",3,"visible mass","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection/muTau_m_vis_nocut","muTauPlots/muTau_m_vis_nocut.root","mt_inclusivemtnotwoprong",3,"visible mass","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection/muTau_iso_1","muTauPlots/muTau_iso_1.root","mt_inclusivemtnotwoprong",3,"Isolation #mu DR=0.3","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection/muTau_tauIso","muTauPlots/muTau_tauIso.root","mt_inclusivemtnotwoprong",3,"Raw Tau Isolation","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection/muTau_met","muTauPlots/muTau_met.root","mt_inclusivemtnotwoprong",3,"ME_{T}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection/muTau_pt1","muTauPlots/muTau_pt_1.root","mt_inclusivemtnotwoprong",3,"#mu P_{T} ","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection/muTau_genVisPt1","muTauPlots/muTau_genVisPt1.root","mt_inclusivemtnotwoprong",3,"Gen Visible #mu P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",true,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection/muTau_pt_2","muTauPlots/muTau_pt_2.root","mt_inclusivemtnotwoprong",3,"#tau P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection/muTau_genVisPt2","muTauPlots/muTau_genVisPt2.root","mt_inclusivemtnotwoprong",3,"Gen Visible #tau P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",true,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection/muTau_eta_1","muTauPlots/muTau_eta_1.root","mt_inclusivemtnotwoprong",3,"#eta_{#mu}","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection/muTau_eta_2","muTauPlots/muTau_eta_2.root","mt_inclusivemtnotwoprong",3,"#eta_{#tau}","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection/muTau_m_vis","muTauPlots/muTau_m_vis.root","mt_inclusivemtnotwoprong",3,"visible mass","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection/muTau_pt","muTauPlots/muTau_pt.root","mt_inclusivemtnotwoprong",3,"di-tau Pt","GeV",false,"#tau_{#mu}#tau_{h}","Golden",true,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection/muTau_q_1","muTauPlots/muTau_q_1.root","mt_inclusivemtnotwoprong",3,"q_{#mu}","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection/muTau_q_2","muTauPlots/muTau_q_2.root","mt_inclusivemtnotwoprong",3,"q_{#tau}","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);

   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection/muTau_npv","muTauPlots/muTau_npv.root","mt_inclusivemtnotwoprong",3,"npv","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection/muTau_tauDecayMode","muTauPlots/muTau_tauDecayMode.root","mt_inclusivemtnotwoprong",3,"#tau decay mode","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection/muTau_m_2","muTauPlots/muTau_m_2.root","mt_inclusivemtnotwoprong",3,"M_{#tau}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection/muTau_mjj","muTauPlots/muTau_mjj.root","mt_inclusivemtnotwoprong",3,"M_{JJ}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection/muTau_njetspt20","muTauPlots/muTau_njetspt20.root","mt_inclusivemtnotwoprong",3,"Number Jets Pt>20","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection/muTau_njets","muTauPlots/muTau_njets.root","mt_inclusivemtnotwoprong",3,"Number Jets Pt>30","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection/muTau_nbtag","muTauPlots/muTau_nbtag.root","mt_inclusivemtnotwoprong",3,"Number Jets Pt>30","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection/muTau_jeta_1","muTauPlots/muTau_jeta_1.root","mt_inclusivemtnotwoprong",3,"Leading jet #eta","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection/muTau_jeta_2","muTauPlots/muTau_jeta_2.root","mt_inclusivemtnotwoprong",3,"Sub-Leading jet #eta","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection/muTau_tauNIsoTracks","muTauPlots/muTau_tauNIsoTracks.root","mt_inclusivemtnotwoprong",3,"Number Isolated Tracks","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);

   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection/muTau_jpt_1","muTauPlots/muTau_jpt_1.root","mt_inclusivemtnotwoprong",3,"Leading jet Pt","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelection/muTau_jpt_2","muTauPlots/muTau_jpt_2.root","mt_inclusivemtnotwoprong",3,"Sub-Leading jet Pt","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);

}
