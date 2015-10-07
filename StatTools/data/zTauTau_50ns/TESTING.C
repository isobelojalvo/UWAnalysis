{
   gROOT->ProcessLine(".L ../../../../UWAnalysis/ROOT/macros/plotScripts/templatePlots/makePlot.C");

   //makeLTauStack(TString name,TString file,TString dir,int s,TString labelX,TString units = "GeV",bool left=false,TString channel = "",TString year = "2012",bool log = false,bool dndm=false,bool doRatio = false,true)
   //makeLTauStackPF("~/www/ztt/ETau/Testing/eleTau/MSSM8TeV/X/eleTau_highestJetEta","eleTauPlots/MSSM/eleTau_highestJetEta.root","eleTau_X",1,"Jet_{1} #eta","",true,"#tau_{#ele}#tau_{h}","2012",false,true,1,1,1,1,1,1,1,1,false,true);

//}
 
   makeLTauStack("~/www/ztt/ETau/Testing/eleTau_mt_1","eleTauPlots/eleTau_mt_1.root","eleTau_inclusive",3,"m_{T}","GeV",false,"#tau_{e}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/ETau/Testing/eleTau_m_vis","eleTauPlots/eleTau_m_vis.root","eleTau_inclusive",3,"visible m_vis","GeV",false,"#tau_{e}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/ETau/Testing/eleTau_iso_1","eleTauPlots/eleTau_iso_1.root","eleTau_inclusive",3,"e iso dR=0.3","GeV",false,"#tau_{e}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/ETau/Testing/eleTau_iso04_1","eleTauPlots/eleTau_iso04_1.root","eleTau_inclusive",3,"e iso dR=0.4","GeV",false,"#tau_{e}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/ETau/Testing/eleTau_tauElectronTightMVA5","eleTauPlots/eleTau_tauElectronTightMVA5.root","eleTau_inclusive",3,"against electron tight","GeV",false,"#tau_{e}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/ETau/Testing/eleTau_againstMuonLoose3_2","eleTauPlots/eleTau_againstMuonLoose3_2.root","eleTau_inclusive",3,"against Muon Loose","GeV",false,"#tau_{e}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/ETau/Testing/eleTau_tauIso","eleTauPlots/eleTau_tauIso.root","eleTau_inclusive",3,"e tauIso","GeV",false,"#tau_{e}#tau_{h}","40",true,false,true);
}
   makeLTauStack("~/www/ztt/ETau/Testing/eleTau_met","eleTauPlots/eleTau_met.root","eleTau_inclusive",3,"ME_{T}","GeV",false,"#tau_{e}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/ETau/Testing/eleTau_mt","eleTauPlots/eleTau_mt.root","eleTau_inclusive",3,"Total M_{T}","GeV",false,"#tau_{e}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/ETau/Testing/eleTau_pt_1","eleTauPlots/eleTau_pt_1.root","eleTau_inclusive",3,"e P_{T} ","GeV",false,"#tau_{e}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/ETau/Testing/eleTau_tauIso","eleTauPlots/eleTau_tauIso.root","eleTau_inclusive",3,"e tauIso","GeV",false,"#tau_{e}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/ETau/Testing/eleTau_genVisPt1","eleTauPlots/eleTau_genVisPt1.root","eleTau_inclusive",3,"Gen Visible e P_{T}","GeV",false,"#tau_{e}#tau_{h}","40",true,false,true);
   makeLTauStack("~/www/ztt/ETau/Testing/eleTau_pt_2","eleTauPlots/eleTau_pt_2.root","eleTau_inclusive",3,"#tau P_{T}","GeV",false,"#tau_{e}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/ETau/Testing/eleTau_genVisPt2","eleTauPlots/eleTau_genVisPt2.root","eleTau_inclusive",3,"Gen Visible #tau P_{T}","GeV",false,"#tau_{e}#tau_{h}","40",true,false,true);
   makeLTauStack("~/www/ztt/ETau/Testing/eleTau_eta_1","eleTauPlots/eleTau_eta_1.root","eleTau_inclusive",3,"#eta_{e}","",false,"#tau_{e}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/ETau/Testing/eleTau_eta_2","eleTauPlots/eleTau_eta_2.root","eleTau_inclusive",3,"#eta_{#tau}","",false,"#tau_{e}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/ETau/Testing/eleTau_pth","eleTauPlots/eleTau_pth.root","eleTau_inclusive",3,"Higgs Pt","GeV",false,"#tau_{e}#tau_{h}","40",true,false,true);
   makeLTauStack("~/www/ztt/ETau/Testing/eleTau_q_1","eleTauPlots/eleTau_q_1.root","eleTau_inclusive",3,"q_{e}","",false,"#tau_{e}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/ETau/Testing/eleTau_q_2","eleTauPlots/eleTau_q_2.root","eleTau_inclusive",3,"q_{#tau}","",false,"#tau_{e}#tau_{h}","40",false,false,true);

   makeLTauStack("~/www/ztt/ETau/Testing/eleTau_vertices","eleTauPlots/eleTau_vertices.root","eleTau_inclusive",3,"vertices","",false,"#tau_{e}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/ETau/Testing/eleTau_tauDecayMode","eleTauPlots/eleTau_tauDecayMode.root","eleTau_inclusive",3,"#tau decay mode","",false,"#tau_{e}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/ETau/Testing/eleTau_m_2","eleTauPlots/eleTau_m_2.root","eleTau_inclusive",3,"M_{#tau}","GeV",false,"#tau_{e}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/ETau/Testing/eleTau_njetspt20","eleTauPlots/eleTau_njetspt20.root","eleTau_inclusive",3,"Number Jets Pt>20","GeV",false,"#tau_{e}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/ETau/Testing/eleTau_nbtag","eleTauPlots/eleTau_nbtag.root","eleTau_inclusive",3,"Number CISV Medium Jets Pt>20","",false,"#tau_{e}#tau_{h}","40",true,false,true);
}


