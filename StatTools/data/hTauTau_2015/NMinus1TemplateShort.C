{
   gROOT->ProcessLine(".L ../../../../UWAnalysis/ROOT/macros/plotScripts/templatePlots/makePlot2015.C");

   //makeLTauStack(TString name,TString file,TString dir,int s,TString labelX,TString units = "GeV",bool left=false,TString channel = "",TString year = "2012",bool log = false,bool dndm=false,bool doRatio = false,true)
   //makeLTauStackPF("~/www/ztt/ETau/OSDM_NMinusOne/eleTau/MSSM8TeV/X/eleTau_NOtauIso_highestJetEta","eleTauNM1PlotsOSDM/MSSM/eleTau_NOtauIso_highestJetEta.root","eleTau_X",1,"Jet_{1} #eta","",true,"#tau_{#ele}#tau_{h}","2012",false,true,1,1,1,1,1,1,1,1,false,true);

//}
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_ALL_mt_1","eleTauNM1PlotsOSDM/eleTau_ALL_mt_1.root","eleTau_inclusive",3,"m_{T}","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_ALL_m_vis","eleTauNM1PlotsOSDM/eleTau_ALL_m_vis.root","eleTau_inclusive",3,"visible m_vis","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_ALL_iso_1","eleTauNM1PlotsOSDM/eleTau_ALL_iso_1.root","eleTau_inclusive",3,"e iso dR=0.3","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
  
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOtauIso_relIso","eleTauNM1PlotsOSDM/eleTau_NOtauIso_relIso.root","eleTau_inclusive",3,"(charged+neutral)/pt","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOtauIso_mt_1","eleTauNM1PlotsOSDM/eleTau_NOtauIso_mt_1.root","eleTau_inclusive",3,"m_{T}","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOtauIso_m_vis","eleTauNM1PlotsOSDM/eleTau_NOtauIso_m_vis.root","eleTau_inclusive",3,"visible m_vis","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOtauIso_tauIso","eleTauNM1PlotsOSDM/eleTau_NOtauIso_tauIso.root","eleTau_inclusive",3,"tauIso","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOtauIso_againstMuonLoose3_2","eleTauNM1PlotsOSDM/eleTau_NOtauIso_againstMuonLoose3_2.root","eleTau_inclusive",3,"against Muon Loose","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOtauIso_tauElectronTightMVA5","eleTauNM1PlotsOSDM/eleTau_NOtauIso_tauElectronTightMVA5.root","eleTau_inclusive",3,"against Electron Tight","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOtauIso_tauDecayMode","eleTauNM1PlotsOSDM/eleTau_NOtauIso_tauDecayMode.root","eleTau_inclusive",3,"Tau Decay Mode","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOtauIso_chargedIsoPtSum_2","eleTauNM1PlotsOSDM/eleTau_NOtauIso_chargedIsoPtSum_2.root","eleTau_inclusive",3,"ChargedIsoPtSum_2","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOtauIso_neutralIsoPtSum_2","eleTauNM1PlotsOSDM/eleTau_NOtauIso_neutralIsoPtSum_2.root","eleTau_inclusive",3,"neutralIsoPtSum_2","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOtauIso_tauIsoTight","eleTauNM1PlotsOSDM/eleTau_NOtauIso_tauIsoTight.root","eleTau_inclusive",3,"tauIsoTight","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOtauIso_tauIsoLoose","eleTauNM1PlotsOSDM/eleTau_NOtauIso_tauIsoLoose.root","eleTau_inclusive",3,"tauIsoLoose","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOtauIso_againstElectronMediumMVA5_2","eleTauNM1PlotsOSDM/eleTau_NOtauIso_againstElectronMediumMVA5_2.root","eleTau_inclusive",3,"againstElectronMediumMVA5_2","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
  
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOiso1_mt_1","eleTauNM1PlotsOSDM/eleTau_NOiso1_mt_1.root","eleTau_inclusive",3,"m_{T}","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOiso1_m_vis","eleTauNM1PlotsOSDM/eleTau_NOiso1_m_vis.root","eleTau_inclusive",3,"visible m_vis","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOiso1_againstMuonLoose3_2","eleTauNM1PlotsOSDM/eleTau_NOiso1_againstMuonLoose3_2.root","eleTau_inclusive",3,"against Muon Loose","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOiso1_tauElectronTightMVA5","eleTauNM1PlotsOSDM/eleTau_NOiso1_tauElectronTightMVA5.root","eleTau_inclusive",3,"against Electron Tight","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
  
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOiso04_mt_1","eleTauNM1PlotsOSDM/eleTau_NOiso04_mt_1.root","eleTau_inclusive",3,"m_{T}","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOiso04_m_vis","eleTauNM1PlotsOSDM/eleTau_NOiso04_m_vis.root","eleTau_inclusive",3,"visible m_vis","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOiso04_iso_1","eleTauNM1PlotsOSDM/eleTau_NOiso04_iso_1.root","eleTau_inclusive",3,"e iso dR=0.3","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOiso04_iso04_1","eleTauNM1PlotsOSDM/eleTau_NOiso04_iso04_1.root","eleTau_inclusive",3,"e iso dR=0.4","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOiso04_tauIso","eleTauNM1PlotsOSDM/eleTau_NOiso04_tauIso.root","eleTau_inclusive",3,"tauIso","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOiso04_againstMuonLoose3_2","eleTauNM1PlotsOSDM/eleTau_NOiso04_againstMuonLoose3_2.root","eleTau_inclusive",3,"against Muon Loose","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOiso04_tauElectronTightMVA5","eleTauNM1PlotsOSDM/eleTau_NOiso04_tauElectronTightMVA5.root","eleTau_inclusive",3,"against Electron Tight","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOiso04_tauDecayMode","eleTauNM1PlotsOSDM/eleTau_NOiso04_tauDecayMode.root","eleTau_inclusive",3,"Tau Decay Mode","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOiso04_chargedIsoPtSum_2","eleTauNM1PlotsOSDM/eleTau_NOiso04_chargedIsoPtSum_2.root","eleTau_inclusive",3,"chargedIsoPtSum_2","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOiso04_neutralIsoPtSum_2","eleTauNM1PlotsOSDM/eleTau_NOiso04_neutralIsoPtSum_2.root","eleTau_inclusive",3,"neutralIsoPtSum_2","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOiso04_tauIsoTight","eleTauNM1PlotsOSDM/eleTau_NOiso04_tauIsoTight.root","eleTau_inclusive",3,"tauIsoTight","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOiso04_tauIsoLoose","eleTauNM1PlotsOSDM/eleTau_NOiso04_tauIsoLoose.root","eleTau_inclusive",3,"tauIsoLoose","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOiso04_againstElectronMediumMVA5_2","eleTauNM1PlotsOSDM/eleTau_NOiso04_againstElectronMediumMVA5_2.root","eleTau_inclusive",3,"againstElectronMediumMVA5_2","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
  
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOagainstMuonLoose3_mt_1","eleTauNM1PlotsOSDM/eleTau_NOagainstMuonLoose3_mt_1.root","eleTau_inclusive",3,"m_{T}","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOagainstMuonLoose3_m_vis","eleTauNM1PlotsOSDM/eleTau_NOagainstMuonLoose3_m_vis.root","eleTau_inclusive",3,"visible m_vis","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOagainstMuonLoose3_iso_1","eleTauNM1PlotsOSDM/eleTau_NOagainstMuonLoose3_iso_1.root","eleTau_inclusive",3,"e iso dR=0.3","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOagainstMuonLoose3_iso04_1","eleTauNM1PlotsOSDM/eleTau_NOagainstMuonLoose3_iso04_1.root","eleTau_inclusive",3,"e iso dR=0.4","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOagainstMuonLoose3_tauIso","eleTauNM1PlotsOSDM/eleTau_NOagainstMuonLoose3_tauIso.root","eleTau_inclusive",3,"tauIso","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOagainstMuonLoose3_againstMuonLoose3_2","eleTauNM1PlotsOSDM/eleTau_NOagainstMuonLoose3_againstMuonLoose3_2.root","eleTau_inclusive",3,"against Muon Loose","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOagainstMuonLoose3_tauElectronTightMVA5","eleTauNM1PlotsOSDM/eleTau_NOagainstMuonLoose3_tauElectronTightMVA5.root","eleTau_inclusive",3,"against Electron Tight","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOagainstMuonLoose3_tauDecayMode","eleTauNM1PlotsOSDM/eleTau_NOagainstMuonLoose3_tauDecayMode.root","eleTau_inclusive",3,"Tau Decay Mode","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOagainstMuonLoose3_chargedIsoPtSum_2","eleTauNM1PlotsOSDM/eleTau_NOagainstMuonLoose3_chargedIsoPtSum_2.root","eleTau_inclusive",3,"chargedIsoPtSum_2","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOagainstMuonLoose3_neutralIsoPtSum_2","eleTauNM1PlotsOSDM/eleTau_NOagainstMuonLoose3_neutralIsoPtSum_2.root","eleTau_inclusive",3,"neutralIsoPtSum_2","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOagainstMuonLoose3_tauIsoTight","eleTauNM1PlotsOSDM/eleTau_NOagainstMuonLoose3_tauIsoTight.root","eleTau_inclusive",3,"tauIsoTight","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOagainstMuonLoose3_tauIsoLoose","eleTauNM1PlotsOSDM/eleTau_NOagainstMuonLoose3_tauIsoLoose.root","eleTau_inclusive",3,"tauIsoLoose","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOagainstMuonLoose3_againstElectronMediumMVA5_2","eleTauNM1PlotsOSDM/eleTau_NOagainstMuonLoose3_againstElectronMediumMVA5_2.root","eleTau_inclusive",3,"againstElectronMediumMVA5_2","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
  
  
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOtauElectronTight_mt_1","eleTauNM1PlotsOSDM/eleTau_NOtauElectronTight_mt_1.root","eleTau_inclusive",3,"m_{T}","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOtauElectronTight_m_vis","eleTauNM1PlotsOSDM/eleTau_NOtauElectronTight_m_vis.root","eleTau_inclusive",3,"visible m_vis","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOtauElectronTight_iso_1","eleTauNM1PlotsOSDM/eleTau_NOtauElectronTight_iso_1.root","eleTau_inclusive",3,"e iso dR=0.3","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOtauElectronTight_iso04_1","eleTauNM1PlotsOSDM/eleTau_NOtauElectronTight_iso04_1.root","eleTau_inclusive",3,"e iso dR=0.4","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOtauElectronTight_tauIso","eleTauNM1PlotsOSDM/eleTau_NOtauElectronTight_tauIso.root","eleTau_inclusive",3,"tauIso","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOtauElectronTight_againstMuonLoose3_2","eleTauNM1PlotsOSDM/eleTau_NOtauElectronTight_againstMuonLoose3_2.root","eleTau_inclusive",3,"against Muon Loose","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOtauElectronTight_tauElectronTightMVA5","eleTauNM1PlotsOSDM/eleTau_NOtauElectronTight_tauElectronTightMVA5.root","eleTau_inclusive",3,"against Electron Tight","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOtauElectronTight_tauDecayMode","eleTauNM1PlotsOSDM/eleTau_NOtauElectronTight_tauDecayMode.root","eleTau_inclusive",3,"Tau Decay Mode","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOtauElectronTight_chargedIsoPtSum_2","eleTauNM1PlotsOSDM/eleTau_NOtauElectronTight_chargedIsoPtSum_2.root","eleTau_inclusive",3,"chargedIsoPtSum_2","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOtauElectronTight_neutralIsoPtSum_2","eleTauNM1PlotsOSDM/eleTau_NOtauElectronTight_neutralIsoPtSum_2.root","eleTau_inclusive",3,"neutralIsoPtSum_2","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
 makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOtauElectronTight_tauIsoTight","eleTauNM1PlotsOSDM/eleTau_NOtauElectronTight_tauIsoTight.root","eleTau_inclusive",3,"tauIsoTight","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOtauElectronTight_tauIsoLoose","eleTauNM1PlotsOSDM/eleTau_NOtauElectronTight_tauIsoLoose.root","eleTau_inclusive",3,"tauIsoLoose","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_NOtauElectronTight_againstElectronMediumMVA5_2","eleTauNM1PlotsOSDM/eleTau_NOtauElectronTight_againstElectronMediumMVA5_2.root","eleTau_inclusive",3,"againstElectronMediumMVA5_2","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
  
  
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_mt_1","eleTauNM1PlotsOSDM/eleTau_mt_1.root","eleTau_inclusive",3,"m_{T}","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_m_vis","eleTauNM1PlotsOSDM/eleTau_m_vis.root","eleTau_inclusive",3,"visible m_vis","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_iso_1","eleTauNM1PlotsOSDM/eleTau_iso_1.root","eleTau_inclusive",3,"e iso dR=0.3","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_iso04_1","eleTauNM1PlotsOSDM/eleTau_iso04_1.root","eleTau_inclusive",3,"e iso dR=0.4","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_tauIso","eleTauNM1PlotsOSDM/eleTau_tauIso.root","eleTau_inclusive",3,"tauIso","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_againstMuonLoose3_2","eleTauNM1PlotsOSDM/eleTau_againstMuonLoose3_2.root","eleTau_inclusive",3,"against Muon Loose","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_tauElectronTightMVA5","eleTauNM1PlotsOSDM/eleTau_tauElectronTightMVA5.root","eleTau_inclusive",3,"against Electron Tight","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_tauDecayMode","eleTauNM1PlotsOSDM/eleTau_tauDecayMode.root","eleTau_inclusive",3,"Tau Decay Mode","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_chargedIsoPtSum_2","eleTauNM1PlotsOSDM/eleTau_chargedIsoPtSum_2.root","eleTau_inclusive",3,"chargedIsoPtSum_2","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_neutralIsoPtSum_2","eleTauNM1PlotsOSDM/eleTau_neutralIsoPtSum_2.root","eleTau_inclusive",3,"neutralIsoPtSum_2","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_tauIsoTight","eleTauNM1PlotsOSDM/eleTau_tauIsoTight.root","eleTau_inclusive",3,"tauIsoTight","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_tauIsoLoose","eleTauNM1PlotsOSDM/eleTau_tauIsoLoose.root","eleTau_inclusive",3,"tauIsoLoose","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OSDM_NMinusOne/eleTau_againstElectronMediumMVA5_2","eleTauNM1PlotsOSDM/eleTau_againstElectronMediumMVA5_2.root","eleTau_inclusive",3,"againstElectronMediumMVA5_2","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
  



 }


