{
   gROOT->ProcessLine(".L ../../../../UWAnalysis/ROOT/macros/plotScripts/templatePlots/makePlot.C");

   //makeLTauStack(TString name,TString file,TString dir,int s,TString labelX,TString units = "GeV",bool left=false,TString channel = "",TString year = "2012",bool log = false,bool dndm=false,bool doRatio = false,true)
   //makeLTauStackPF("~/www/ztt/MuTau/FullSelectionNoDM56/muTau/MSSM8TeV/X/muTau_highestJetEta","muTauPlots/MSSM/muTau_highestJetEta.root","muTau_X",1,"Jet_{1} #eta","",true,"#tau_{#mu}#tau_{h}","2012",false,true,1,1,1,1,1,1,1,1,false,true);

   //makeLTauStack("~/www/ztt/MuTau/FullSelectionNoDM56/muTau_m_sv","muTauPlots/muTau_m_sv.root","muTau_inclusive",3,"m_{#tau #tau}","GeV",false,"#tau_{#mu}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/FullSelectionNoDM56/muTau_mt_1","muTauPlots/muTau_mt_1.root","muTau_inclusive",3,"m_{T}","GeV",false,"#tau_{#mu}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/FullSelectionNoDM56/muTau_iso_1","muTauPlots/muTau_iso_1.root","muTau_inclusive",3,"Isolation #mu DR=0.3","GeV",false,"#tau_{#mu}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/FullSelectionNoDM56/muTau_tauIso","muTauPlots/muTau_tauIso.root","muTau_inclusive",3,"Raw Tau Isolation","GeV",false,"#tau_{#mu}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/FullSelectionNoDM56/muTau_met","muTauPlots/muTau_met.root","muTau_inclusive",3,"ME_{T}","GeV",false,"#tau_{#mu}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/FullSelectionNoDM56/muTau_mt","muTauPlots/muTau_mt.root","muTau_inclusive",3,"Total M_{T}","GeV",false,"#tau_{#mu}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/FullSelectionNoDM56/muTau_pt1","muTauPlots/muTau_pt_1.root","muTau_inclusive",3,"#mu P_{T} ","GeV",false,"#tau_{#mu}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/FullSelectionNoDM56/muTau_genVisPt1","muTauPlots/muTau_genVisPt1.root","muTau_inclusive",3,"Gen Visible #mu P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","40",true,false,true);
   makeLTauStack("~/www/ztt/MuTau/FullSelectionNoDM56/muTau_pt_2","muTauPlots/muTau_pt_2.root","muTau_inclusive",3,"#tau P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/FullSelectionNoDM56/muTau_genVisPt2","muTauPlots/muTau_genVisPt2.root","muTau_inclusive",3,"Gen Visible #tau P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","40",true,false,true);
   makeLTauStack("~/www/ztt/MuTau/FullSelectionNoDM56/muTau_eta_1","muTauPlots/muTau_eta_1.root","muTau_inclusive",3,"#eta_{#mu}","",false,"#tau_{#mu}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/FullSelectionNoDM56/muTau_eta_2","muTauPlots/muTau_eta_2.root","muTau_inclusive",3,"#eta_{#tau}","",false,"#tau_{#mu}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/FullSelectionNoDM56/muTau_m_vis","muTauPlots/muTau_m_vis.root","muTau_inclusive",3,"visible mass","GeV",false,"#tau_{#mu}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/FullSelectionNoDM56/muTau_pt","muTauPlots/muTau_pt.root","muTau_inclusive",3,"Higgs Pt","GeV",false,"#tau_{#mu}#tau_{h}","40",true,false,true);
   makeLTauStack("~/www/ztt/MuTau/FullSelectionNoDM56/muTau_q_1","muTauPlots/muTau_q_1.root","muTau_inclusive",3,"q_{#mu}","",false,"#tau_{#mu}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/FullSelectionNoDM56/muTau_q_2","muTauPlots/muTau_q_2.root","muTau_inclusive",3,"q_{#tau}","",false,"#tau_{#mu}#tau_{h}","40",false,false,true);

   makeLTauStack("~/www/ztt/MuTau/FullSelectionNoDM56/muTau_npv","muTauPlots/muTau_npv.root","muTau_inclusive",3,"npv","",false,"#tau_{#mu}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/FullSelectionNoDM56/muTau_tauDecayMode","muTauPlots/muTau_tauDecayMode.root","muTau_inclusive",3,"#tau decay mode","",false,"#tau_{#mu}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/FullSelectionNoDM56/muTau_m_2","muTauPlots/muTau_m_2.root","muTau_inclusive",3,"M_{#tau}","GeV",false,"#tau_{#mu}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/FullSelectionNoDM56/muTau_njetspt20","muTauPlots/muTau_njetspt20.root","muTau_inclusive",3,"Number Jets Pt>20","GeV",false,"#tau_{#mu}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/FullSelectionNoDM56/muTau_jeta_1","muTauPlots/muTau_jeta_1.root","muTau_inclusive",3,"Leading jet #eta","GeV",false,"#tau_{#mu}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/FullSelectionNoDM56/muTau_jeta_2","muTauPlots/muTau_jeta_2.root","muTau_inclusive",3,"Sub-Leading jet #eta","GeV",false,"#tau_{#mu}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/MuTau/FullSelectionNoDM56/muTau_tauNIsoTracks","muTauPlots/muTau_tauNIsoTracks.root","muTau_inclusive",3,"Number Isolated Tracks","GeV",false,"#tau_{#mu}#tau_{h}","40",false,false,true);


}
