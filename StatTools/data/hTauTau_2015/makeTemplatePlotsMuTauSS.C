{
   gROOT->ProcessLine(".L ../../../../UWAnalysis/ROOT/macros/plotScripts/templatePlots/makePlot2015.C");

   //makeLTauStack(TString name,TString file,TString dir,int s,TString labelX,TString units = "GeV",bool left=false,TString channel = "",TString year = "2012",bool log = false,bool dndm=false,bool doRatio = false,true)

   //makeLTauStack("~/www/ztt/MuTau/25ns_FullSelectionSS/muTau_m_vis","datacards/htt_mt.inputs-sm-13TeV.root","muTau_inclusive",3,"visible mass","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelectionSS/muTau_mt_1","muTauPlotsSS/muTau_mt_1.root","muTau_inclusive",3,"m_{T}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelectionSS/muTau_mt_2","muTauPlotsSS/muTau_mt_2.root","muTau_inclusive",3,"#mu +MET m_{T}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelectionSS/muTau_mt","muTauPlotsSS/muTau_mt.root","muTau_inclusive",3,"Total m_{T}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelectionSS/muTau_m_vis","muTauPlotsSS/muTau_m_vis.root","muTau_inclusive",3,"visible mass","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelectionSS/muTau_m_vis_nocut","muTauPlotsSS/muTau_m_vis_nocut.root","muTau_inclusive",3,"visible mass","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelectionSS/muTau_iso_1","muTauPlotsSS/muTau_iso_1.root","muTau_inclusive",3,"Isolation #mu DR=0.3","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelectionSS/muTau_tauIso","muTauPlotsSS/muTau_tauIso.root","muTau_inclusive",3,"Raw Tau Isolation","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelectionSS/muTau_met","muTauPlotsSS/muTau_met.root","muTau_inclusive",3,"ME_{T}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelectionSS/muTau_pt1","muTauPlotsSS/muTau_pt_1.root","muTau_inclusive",3,"#mu P_{T} ","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelectionSS/muTau_genVisPt1","muTauPlotsSS/muTau_genVisPt1.root","muTau_inclusive",3,"Gen Visible #mu P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",true,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelectionSS/muTau_pt_2","muTauPlotsSS/muTau_pt_2.root","muTau_inclusive",3,"#tau P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelectionSS/muTau_genVisPt2","muTauPlotsSS/muTau_genVisPt2.root","muTau_inclusive",3,"Gen Visible #tau P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",true,false,true);
}
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelectionSS/muTau_eta_1","muTauPlotsSS/muTau_eta_1.root","muTau_inclusive",3,"#eta_{#mu}","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelectionSS/muTau_eta_2","muTauPlotsSS/muTau_eta_2.root","muTau_inclusive",3,"#eta_{#tau}","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelectionSS/muTau_pt","muTauPlotsSS/muTau_pt.root","muTau_inclusive",3,"di-tau Pt","GeV",false,"#tau_{#mu}#tau_{h}","Golden",true,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelectionSS/muTau_q_1","muTauPlotsSS/muTau_q_1.root","muTau_inclusive",3,"q_{#mu}","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelectionSS/muTau_q_2","muTauPlotsSS/muTau_q_2.root","muTau_inclusive",3,"q_{#tau}","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);

   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelectionSS/muTau_npv","muTauPlotsSS/muTau_npv.root","muTau_inclusive",3,"npv","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelectionSS/muTau_tauDecayMode","muTauPlotsSS/muTau_tauDecayMode.root","muTau_inclusive",3,"#tau decay mode","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelectionSS/muTau_m_2","muTauPlotsSS/muTau_m_2.root","muTau_inclusive",3,"M_{#tau}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelectionSS/muTau_mjj","muTauPlotsSS/muTau_mjj.root","muTau_inclusive",3,"M_{JJ}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelectionSS/muTau_njetspt20","muTauPlotsSS/muTau_njetspt20.root","muTau_inclusive",3,"Number Jets Pt>20","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelectionSS/muTau_njets","muTauPlotsSS/muTau_njets.root","muTau_inclusive",3,"Number Jets Pt>30","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelectionSS/muTau_nbtag","muTauPlotsSS/muTau_nbtag.root","muTau_inclusive",3,"Number Jets Pt>30","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelectionSS/muTau_jeta_1","muTauPlotsSS/muTau_jeta_1.root","muTau_inclusive",3,"Leading jet #eta","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelectionSS/muTau_jeta_2","muTauPlotsSS/muTau_jeta_2.root","muTau_inclusive",3,"Sub-Leading jet #eta","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelectionSS/muTau_tauNIsoTracks","muTauPlotsSS/muTau_tauNIsoTracks.root","muTau_inclusive",3,"Number Isolated Tracks","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);

   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelectionSS/muTau_jpt_1","muTauPlotsSS/muTau_jpt_1.root","muTau_inclusive",3,"Leading jet Pt","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/25ns_FullSelectionSS/muTau_jpt_2","muTauPlotsSS/muTau_jpt_2.root","muTau_inclusive",3,"Sub-Leading jet Pt","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);

}
