{
   gROOT->ProcessLine(".L ../../../../UWAnalysis/ROOT/macros/plotScripts/templatePlots/makePlot.C");

   //makeLTauStack(TString name,TString file,TString dir,int s,TString labelX,TString units = "GeV",bool left=false,TString channel = "",TString year = "2012",bool log = false,bool dndm=false,bool doRatio = false)
   //makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/X/muTau_highestJetEta","muTauPlots/MSSM/muTau_highestJetEta.root","muTau_X",1,"Jet_{1} #eta","",true,"#tau_{#mu}#tau_{h}","2012",false,true,1,1,1,1,1,1,1,1,false);
   makeLTauStack("~/www/htt/muTau/Hhh/X/muTau_HMassReg1","muTauPlots/muTau_HMassReg.root","muTau_inclusive",4,"m(H)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);

   exit;
   makeLTauStack("~/www/htt/muTau/Hhh/X/muTau_met_ttbar","muTauPlots/muTau_met_top.root","muTau_inclusive",4,"met","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);

   makeLTauStack("~/www/htt/muTau/Hhh/1btag/muTau_HMassReg","muTauPlots/muTau_HMassReg.root","muTau_1btag",4,"m(H)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);
   

   makeLTauStack("~/www/htt/muTau/Hhh/X/muTau_svMass_ttbar","muTauPlots/muTau_svMass_ttbar.root","muTau_inclusive",4,"m(#tau#tau)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/Hhh/1btag/muTau_svMass_ttbar","muTauPlots/muTau_svMass_ttbar.root","muTau_1btag",4,"m(#tau#tau)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);

   makeLTauStack("~/www/htt/muTau/Hhh/X/muTau_mt_ttbar","muTauPlots/muTau_mt_ttbar.root","muTau_inclusive",4,"m_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/Hhh/1btag/muTau_mt_ttbar","muTauPlots/muTau_mt_ttbar.root","muTau_1btag",4,"m_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);

   makeLTauStack("~/www/htt/muTau/Hhh/X/muTau_mJJ_ttbar","muTauPlots/muTau_mJJ_ttbar.root","muTau_inclusive",4,"m(jj)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/Hhh/1btag/muTau_mJJ_ttbar","muTauPlots/muTau_mJJ_ttbar.root","muTau_1btag",4,"m(jj)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);

   makeLTauStack("~/www/htt/muTau/Hhh/X/muTau_met_ttbar","muTauPlots/muTau_met_ttbar.root","muTau_inclusive",4,"m(jj)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/Hhh/1btag/muTau_met_ttbar","muTauPlots/muTau_met_ttbar.root","muTau_1btag",4,"m(jj)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);

   makeLTauStack("~/www/htt/muTau/Hhh/X/muTau_mJJ","muTauPlots/muTau_mJJ.root","muTau_inclusive",4,"m(jj)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/Hhh/1btag/muTau_mJJ","muTauPlots/muTau_mJJ.root","muTau_1btag",4,"m(jj)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);

   makeLTauStack("~/www/htt/muTau/Hhh/X/muTau_ptJJ","muTauPlots/muTau_ptJJ.root","muTau_inclusive",4,"p_{T}(jj)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/Hhh/1btag/muTau_ptJJ","muTauPlots/muTau_ptJJ.root","muTau_1btag",4,"p_{T}(jj)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);

   makeLTauStack("~/www/htt/muTau/Hhh/X/muTau_mJJReg","muTauPlots/muTau_mJJReg.root","muTau_inclusive",4,"m(jj)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);
   makeLTauStack("~/www/htt/muTau/Hhh/1btag/muTau_mJJReg","muTauPlots/muTau_mJJReg.root","muTau_1btag",4,"m(jj)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);


   makeLTauStack("~/www/htt/muTau/Hhh/X/muTau_J1Pt","muTauPlots/muTau_J1Pt.root","muTau_inclusive",4,"Highest Jet p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/Hhh/1btag/muTau_J1Pt","muTauPlots/muTau_J1Pt.root","muTau_1btag",4,"Highest Jet p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);

   makeLTauStack("~/www/htt/muTau/Hhh/X/muTau_J2Pt","muTauPlots/muTau_J2Pt.root","muTau_inclusive",4,"Second Jet p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/Hhh/1btag/muTau_J2Pt","muTauPlots/muTau_J2Pt.root","muTau_1btag",4,"Second Jet p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);

   makeLTauStack("~/www/htt/muTau/Hhh/X/muTau_mt1","muTauPlots/muTau_mt1.root","muTau_inclusive",0,"m_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/Hhh/1btag/muTau_mt1","muTauPlots/muTau_mt1.root","muTau_1btag",4,"m_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);

   makeLTauStack("~/www/htt/muTau/Hhh/X/muTau_pZeta","muTauPlots/muTau_pZeta.root","muTau_inclusive",0,"#mu p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/Hhh/1btag/muTau_pZeta","muTauPlots/muTau_pZeta.root","muTau_1btag",4,"#mu p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);

   makeLTauStack("~/www/htt/muTau/Hhh/X/muTau_nJetsPt30","muTauPlots/muTau_nJetsPt30.root","muTau_inclusive",4,"nJets p_{T} 30","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/Hhh/1btag/muTau_nJetsPt30","muTauPlots/muTau_nJetsPt30.root","muTau_1btag",4,"nJets p_{T} 30","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);

   makeLTauStack("~/www/htt/muTau/Hhh/X/muTau_nJetsBTagCSVMPt20_log","muTauPlots/muTau_nJetsBTagCSVMPt20.root","muTau_inclusive",4,"N Medium bTags p_{T} 20","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,false,true);
   makeLTauStack("~/www/htt/muTau/Hhh/X/muTau_nJetsBTagCSVMPt20","muTauPlots/muTau_nJetsBTagCSVMPt20.root","muTau_inclusive",4,"N Medium bTags p_{T} 20","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false,true);
   makeLTauStack("~/www/htt/muTau/Hhh/1btag/muTau_nJetsBTagCSVMPt20","muTauPlots/muTau_nJetsBTagCSVMPt20.root","muTau_1btag",4,"N Medium BTags p_{T} 20","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,false,true);


   makeLTauStack("~/www/htt/muTau/Hhh/X/muTau_svMass","muTauPlots/muTau_svMass.root","muTau_inclusive",4,"m(#tau#tau)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/Hhh/1btag/muTau_svMass","muTauPlots/muTau_svMass.root","muTau_1btag",4,"m(#tau#tau)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);

   makeLTauStack("~/www/htt/muTau/Hhh/1btag/muTau_svMass2tag","muTauPlots/muTau_svMass2tag.root","muTau_1btag",4,"m(#tau#tau)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);


   makeLTauStack("~/www/htt/muTau/Hhh/X/muTau_HMass","muTauPlots/muTau_HMass.root","muTau_inclusive",0,"m(H)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/Hhh/1btag/muTau_HMass","muTauPlots/muTau_HMass.root","muTau_1btag",4,"m(H)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);


   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_Pt1","muTauPlots2011/MSSM/muTau_pt1.root","muTau_inclusive",0,"#mu p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_MetUnc","muTauPlots2011/MSSM/muTau_metUnc.root","muTau_inclusive",,"m_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);

   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_met","muTauPlots2011/MSSM/muTau_met.root","muTau_inclusive",0,"MET","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_MVis","muTauPlots2011/MSSM/muTau_MVisNoLog.root","muTau_inclusive",0,"m_{vis}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_SVMass","muTauPlots2011/MSSM/muTau_svMass.root","muTau_inclusive",0,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);   

   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_Mt","muTauPlots2011/MSSM/muTau_Mt.root","muTau_inclusive",0,"m_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/nobtag/muTau_Mt","muTauPlots2011/MSSM/muTau_Mt.root","muTau_nobtag",0,"m_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/btag/muTau_Mt","muTauPlots2011/MSSM/muTau_Mt.root","muTau_btag",0,"m_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);

   /*
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_SVMass_noBlind","muTauPlots/MSSM/muTau_svMass.root","muTau_X",0,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/nobtag/muTau_SVMass_noBlind","muTauPlots2011/MSSM/muTau_svMass.root","muTau_nobtag",0,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   //makeLTauStack("~/www/htt/muTau/MSSM7TeV/cat1/muTau_SVMass_noBlind","muTauPlots2011/MSSM/muTau_svMass.root","muTau_MSSM1",0,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/btag/muTau_SVMass_noBlind","muTauPlots2011/MSSM/muTau_svMass.root","muTau_btag",0,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   //makeLTauStack("~/www/htt/muTau/MSSM7TeV/cat3/muTau_SVMass_noBlind","muTauPlots2011/MSSM/muTau_svMass.root","muTau_MSSM3",0,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);

   //makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_J1PtTagged","muTauPlots2011/MSSM/muTau_J1PtTagged.root","muTau_X",0,"Jet_{1} p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   */
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_tauMass1","muTauPlots2011/MSSM/muTau_tauMass1.root","muTau_X",0,"M_{#tau}","GeV",true,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/nobtag/muTau_tauMass1","muTauPlots2011/MSSM/muTau_tauMass1.root","muTau_nobtag",0,"M_{#tau}","GeV",true,"#tau_{#mu}#tau_{h}","2012",false,true);
   //makeLTauStack("~/www/htt/muTau/MSSM7TeV/cat1/muTau_tauMass1","muTauPlots2011/MSSM/muTau_tauMass1.root","muTau_MSSM1",0,"M_{#tau}","GeV",true,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/btag/muTau_tauMass1","muTauPlots2011/MSSM/muTau_tauMass1.root","muTau_btag",0,"M_{#tau}","GeV",true,"#tau_{#mu}#tau_{h}","2012",false,true);
   //makeLTauStack("~/www/htt/muTau/MSSM7TeV/cat3/muTau_tauMass1","muTauPlots2011/MSSM/muTau_tauMass1.root","muTau_MSSM3",0,"M_{#tau}","GeV",true,"#tau_{#mu}#tau_{h}","2012",false,true);

   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_tauMass10","muTauPlots2011/MSSM/muTau_tauMass10.root","muTau_X",0,"M_{#tau}","GeV",true,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/nobtag/muTau_tauMass10","muTauPlots2011/MSSM/muTau_tauMass10.root","muTau_nobtag",0,"M_{#tau}","GeV",true,"#tau_{#mu}#tau_{h}","2012",false,true);
   //makeLTauStack("~/www/htt/muTau/MSSM7TeV/cat1/muTau_tauMass10","muTauPlots2011/MSSM/muTau_tauMass10.root","muTau_MSSM1",0,"M_{#tau}","GeV",true,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/btag/muTau_tauMass10","muTauPlots2011/MSSM/muTau_tauMass10.root","muTau_btag",0,"M_{#tau}","GeV",true,"#tau_{#mu}#tau_{h}","2012",false,true);
   //makeLTauStack("~/www/htt/muTau/MSSM7TeV/cat3/muTau_tauMass10","muTauPlots2011/MSSM/muTau_tauMass10.root","muTau_MSSM3",0,"M_{#tau}","GeV",true,"#tau_{#mu}#tau_{h}","2012",false,true);
   
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_J1Eta","muTauPlots2011/MSSM/muTau_J1Eta.root","muTau_inclusive",0,"Jet_{1} #eta","",true,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/nobtag/muTau_J1Eta","muTauPlots2011/MSSM/muTau_J1Eta.root","muTau_nobtag",0,"Jet_{1} #eta","",true,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/btag/muTau_J1Eta","muTauPlots2011/MSSM/muTau_J1Eta.root","muTau_btag",0,"Jet_{1} #eta","",true,"#tau_{#mu}#tau_{h}","2012",false,true);


   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_MVisLOG","muTauPlots2011/MSSM/muTau_MVisBlind.root","muTau_inclusive",0,"m_{vis}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/nobtag/muTau_MVisLOG","muTauPlots2011/MSSM/muTau_MVisBlind.root","muTau_nobtag",0,"m_{vis}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/btag/muTau_MVisLOG","muTauPlots2011/MSSM/muTau_MVisBlind.root","muTau_btag",0,"m_{vis}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);

   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_MVis","muTauPlots2011/MSSM/muTau_MVisNoLog.root","muTau_inclusive",0,"m_{vis}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/nobtag/muTau_MVis","muTauPlots2011/MSSM/muTau_MVisNoLog.root","muTau_nobtag",0,"m_{vis}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/btag/muTau_MVis","muTauPlots2011/MSSM/muTau_MVisNoLog.root","muTau_btag",0,"m_{vis}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);

   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_SVMassLOG","muTauPlots2011/MSSM/muTau_svMassBlind.root","muTau_inclusive",0,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/nobtag/muTau_SVMassLOG","muTauPlots2011/MSSM/muTau_svMassBlind.root","muTau_nobtag",0,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/btag/muTau_SVMassLOG","muTauPlots2011/MSSM/muTau_svMassBlind.root","muTau_btag",0,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);

   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_SVMass","muTauPlots2011/MSSM/muTau_svMassNoLog.root","muTau_inclusive",0,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/nobtag/muTau_SVMass","muTauPlots2011/MSSM/muTau_svMassNoLog.root","muTau_nobtag",0,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/btag/muTau_SVMass","muTauPlots2011/MSSM/muTau_svMassNoLog.root","muTau_btag",0,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);


   /*
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_lPFisoDB","muTauPlots2011/MSSM/muTau_lPFIsoDB.root","muTau_inclusive",0,"PFisoDB","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/cat1/muTau_lPFisoDB","muTauPlots2011/MSSM/muTau_lPFIsoDB.root","muTau_MSSM1",0,"PFisoDB","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/btag/muTau_lPFisoDB","muTauPlots2011/MSSM/muTau_lPFIsoDB.root","muTau_btag",0,"PFisoDB","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);
   */

   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_met","muTauPlots2011/MSSM/muTau_met.root","muTau_inclusive",0,"MET","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/nobtag/muTau_met","muTauPlots2011/MSSM/muTau_met.root","muTau_nobtag",0,"MET","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/btag/muTau_met","muTauPlots2011/MSSM/muTau_met.root","muTau_btag",0,"MET","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);

   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_J1Pt","muTauPlots2011/MSSM/muTau_J1Pt.root","muTau_inclusive",0,"Jet_{1} p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/nobtag/muTau_J1Pt","muTauPlots2011/MSSM/muTau_J1Pt.root","muTau_nobtag",0,"Jet_{1} p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/btag/muTau_J1Pt","muTauPlots2011/MSSM/muTau_J1Pt.root","muTau_btag",0,"Jet_{1} p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);

   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_Pt1","muTauPlots2011/MSSM/muTau_pt1.root","muTau_inclusive",0,"#mu p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/nobtag/muTau_Pt1","muTauPlots2011/MSSM/muTau_pt1.root","muTau_nobtag",0,"#mu p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/btag/muTau_Pt1","muTauPlots2011/MSSM/muTau_pt1.root","muTau_btag",0,"#mu p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);

   //makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_Eta1","muTauPlots2011/MSSM/muTau_eta1.root","muTau_inclusive",0,"#mu #eta","",true,"#tau_{#mu}#tau_{h}","2012",false,true);
   //makeLTauStack("~/www/htt/muTau/MSSM7TeV/nobtag/muTau_Eta1","muTauPlots2011/MSSM/muTau_eta1.root","muTau_nobtag",0,"#mu #eta","",true,"#tau_{#mu}#tau_{h}","2012",false,true);
   //makeLTauStack("~/www/htt/muTau/MSSM7TeV/btag/muTau_Eta1","muTauPlots2011/MSSM/muTau_eta1.root","muTau_btag",0,"#mu #eta","",true,"#tau_{#mu}#tau_{h}","2012",false,true);

   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_Pt2","muTauPlots2011/MSSM/muTau_pt2.root","muTau_inclusive",0,"#tau p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/nobtag/muTau_Pt2","muTauPlots2011/MSSM/muTau_pt2.root","muTau_nobtag",0,"#tau p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/btag/muTau_Pt2","muTauPlots2011/MSSM/muTau_pt2.root","muTau_btag",0,"#tau p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);

   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_Eta2","muTauPlots2011/MSSM/muTau_eta2.root","muTau_inclusive",0,"#tau #eta","",true,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/nobtag/muTau_Eta2","muTauPlots2011/MSSM/muTau_eta2.root","muTau_nobtag",0,"#tau #eta","",true,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/btag/muTau_Eta2","muTauPlots2011/MSSM/muTau_eta2.root","muTau_btag",0,"#tau #eta","",true,"#tau_{#mu}#tau_{h}","2012",false,true);

   //makeLTauStack("~/www/htt/muTau/MSSM7TeV/btag/muTau_Mt1","muTauPlots2011/MSSM/muTau_Mt1.root","muTau_btag",0,"m_{e,MET}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   /*
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_MVis_noBlind","muTauPlots2011/MSSM/muTau_MVis.root","muTau_inclusive",0,"m_{vis}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/nobtag/muTau_MVis_noBlind","muTauPlots2011/MSSM/muTau_MVis.root","muTau_nobtag",0,"m_{vis}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/btag/muTau_MVis_noBlind","muTauPlots2011/MSSM/muTau_MVis.root","muTau_btag",0,"m_{vis}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   */

   //makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_tauMass","muTauPlots2011/MSSM/muTau_tauMass.root","muTau_inclusive",0,"M_{#tau}","GeV",true,"#tau_{#mu}#tau_{h}","2012",false,true);
   //makeLTauStack("~/www/htt/muTau/MSSM7TeV/nobtag/muTau_tauMass","muTauPlots2011/MSSM/muTau_tauMass.root","muTau_nobtag",0,"M_{#tau}","GeV",true,"#tau_{#mu}#tau_{h}","2012",false,true);
   //makeLTauStack("~/www/htt/muTau/MSSM7TeV/btag/muTau_tauMass","muTauPlots2011/MSSM/muTau_tauMass.root","muTau_btag",0,"M_{#tau}","GeV",true,"#tau_{#mu}#tau_{h}","2012",false,true);

   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_CSVJ1","muTauPlots2011/MSSM/muTau_CSVJ1.root","muTau_inclusive",0,"CSV b-Disc","",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_CSVJ1LOG","muTauPlots2011/MSSM/muTau_CSVJ1.root","muTau_inclusive",0,"CSV b-Disc","",false,"#tau_{#mu}#tau_{h}","2012",true,true);

   //makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_nJetsPt20","muTauPlots2011/MSSM/muTau_nJetsPt20.root","muTau_inclusive",0,"nJetsPt20","",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   //makeLTauStack("~/www/htt/muTau/MSSM7TeV/nobtag/muTau_nJetsPt20","muTauPlots2011/MSSM/muTau_nJetsPt20.root","muTau_nobtag",0,"nJetsPt20","",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   //makeLTauStack("~/www/htt/muTau/MSSM7TeV/btag/muTau_nJetsPt20","muTauPlots2011/MSSM/muTau_nJetsPt20.root","muTau_btag",0,"nJetsPt20","",false,"#tau_{#mu}#tau_{h}","2012",false,true);

   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_nJetsPt20LOG","muTauPlots2011/MSSM/muTau_nJetsPt20.root","muTau_inclusive",0,"nJetsPt20","",false,"#tau_{#mu}#tau_{h}","2012",true,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/nobtag/muTau_nJetsPt20LOG","muTauPlots2011/MSSM/muTau_nJetsPt20.root","muTau_nobtag",0,"nJetsPt20","",false,"#tau_{#mu}#tau_{h}","2012",true,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/btag/muTau_nJetsPt20LOG","muTauPlots2011/MSSM/muTau_nJetsPt20.root","muTau_btag",0,"nJetsPt20","",false,"#tau_{#mu}#tau_{h}","2012",true,true);
   
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_nJetsPt30","muTauPlots2011/MSSM/muTau_nJetsPt30.root","muTau_inclusive",0,"nJetsPt20","",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/nobtag/muTau_nJetsPt30","muTauPlots2011/MSSM/muTau_nJetsPt30.root","muTau_nobtag",0,"nJetsPt20","",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/btag/muTau_nJetsPt30","muTauPlots2011/MSSM/muTau_nJetsPt30.root","muTau_btag",0,"nJetsPt20","",false,"#tau_{#mu}#tau_{h}","2012",false,true);

   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_nJetsPt30LOG","muTauPlots2011/MSSM/muTau_nJetsPt30.root","muTau_inclusive",0,"nJetsPt20","",false,"#tau_{#mu}#tau_{h}","2012",true,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/nobtag/muTau_nJetsPt30LOG","muTauPlots2011/MSSM/muTau_nJetsPt30.root","muTau_nobtag",0,"nJetsPt20","",false,"#tau_{#mu}#tau_{h}","2012",true,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/btag/muTau_nJetsPt30LOG","muTauPlots2011/MSSM/muTau_nJetsPt30.root","muTau_btag",0,"nJetsPt20","",false,"#tau_{#mu}#tau_{h}","2012",true,true);
   
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_nJetsBTagCSVLPt20LOG","muTauPlots2011/MSSM/muTau_nBJetsPt20Light.root","muTau_inclusive",0,"nJetsBtagLightPt20","",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_nJetsBTagCSVMPt20LOG","muTauPlots2011/MSSM/muTau_nBJetsPt20Medium.root","muTau_inclusive",0,"nJetsBtagMediumPt20","",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_nJetsBTagCSVTPt20LOG","muTauPlots2011/MSSM/muTau_nBJetsPt20Tight.root","muTau_inclusive",0,"nJetsBtagTightPt20","",false,"#tau_{#mu}#tau_{h}","2012",false,true);

   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_NPVs","muTauPlots2011/MSSM/muTau_NPVs.root","muTau_inclusive",0,"PVs","",false,"#tau_{#mu}#tau_{h}",false,false);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/nobtag/muTau_NPVs","muTauPlots2011/MSSM/muTau_NPVs.root","muTau_nobtag",0,"PVs","",false,"#tau_{#mu}#tau_{h}",false,false);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/btag/muTau_NPVs","muTauPlots2011/MSSM/muTau_NPVs.root","muTau_btag",0,"PVs","",false,"#tau_{#mu}#tau_{h}",false,false);


   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_ht","muTauPlots2011/MSSM/muTau_ht.root","muTau_inclusive",0,"H_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/nobtag/muTau_ht","muTauPlots2011/MSSM/muTau_ht.root","muTau_nobtag",0,"H_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/btag/muTau_ht","muTauPlots2011/MSSM/muTau_ht.root","muTau_btag",0,"H_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);


   /*
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/cat1/muTau_MVis_noBlind","muTauPlots2011/MSSM/muTau_MVisNoBlind.root","muTau_MSSM1",0,"m_{vis}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/btag/muTau_MVis_noBlind","muTauPlots2011/MSSM/muTau_MVisNoBlind.root","muTau_MSSM2",0,"m_{vis}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);

   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_nJetsBTagCSVLPt20","muTauPlots2011/MSSM/muTau_nBJetsPt20Lighta.root","muTau_inclusive",0,"nJetsBtagLightPt20","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_nJetsBTagCSVMPt20","muTauPlots2011/MSSM/muTau_nBJetsPt20Mediuma.root","muTau_inclusive",0,"nJetsBtagMediumPt20","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_nJetsBTagCSVTPt20","muTauPlots2011/MSSM/muTau_nBJetsPt20Tighta.root","muTau_inclusive",0,"nJetsBtagTightPt20","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);

   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_nJetsBTagCSVLPt20min2","muTauPlots2011/MSSM/muTau_nBJetsPt20Light_min2.root","muTau_inclusive",0,"nJetsBtagLightPt20","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_nJetsBTagCSVMPt20min2","muTauPlots2011/MSSM/muTau_nBJetsPt20Medium_min2.root","muTau_inclusive",0,"nJetsBtagMediumPt20","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_nJetsBTagCSVTPt20min2","muTauPlots2011/MSSM/muTau_nBJetsPt20Tight_min2.root","muTau_inclusive",0,"nJetsBtagTightPt20","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);

   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_MVis","muTauPlots2011/MSSM/muTau_MVis.root","muTau_inclusive",0,"m_{vis}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/X/muTau_J1Pt","muTauPlots2011/MSSM/muTau_J1Pt.root","muTau_inclusive",0,"Jet_{1}p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);

   makeLTauStack("~/www/htt/muTau/MSSM7TeV/cat1/muTau_SVMass","muTauPlots2011/MSSM/muTau_SVMassA.root","muTau_MSSM1",0,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/cat1/muTau_SVMassLOG","muTauPlots2011/MSSM/muTau_SVMassA.root","muTau_MSSM1",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/cat1/muTau_MVis","muTauPlots2011/MSSM/muTau_MVis.root","muTau_MSSM1",1,"m_{vis}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/cat1/muTau_J1Pt","muTauPlots2011/MSSM/muTau_J1Pt.root","muTau_MSSM1",1,"Jet_{1}p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/cat1/muTau_nJetsPt20","muTauPlots2011/MSSM/muTau_nJetsPt20.root","muTau_MSSM1",1,"nJetsPt20","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/cat1/muTau_nJetsPt30","muTauPlots2011/MSSM/muTau_nJetsPt30.root","muTau_MSSM1",1,"nJetsPt30","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);

   makeLTauStack("~/www/htt/muTau/MSSM7TeV/btag/muTau_SVMass_2","muTauPlots2011/MSSM/muTau_SVMassA.root","muTau_MSSM2",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/btag/muTau_SVMassLOG_2","muTauPlots2011/MSSM/muTau_SVMassA.root","muTau_MSSM2",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/btag/muTau_MVis_2","muTauPlots2011/MSSM/muTau_MVis.root","muTau_MSSM2",1,"m_{vis}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/btag/muTau_J1Pt_2","muTauPlots2011/MSSM/muTau_J1Pt.root","muTau_MSSM2",1,"Jet_{1}p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/btag/muTau_J1Pt","muTauPlots2011/MSSM/muTau_J1Pt.root","muTau_MSSM2",1,"Jet_{1}p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/btag/muTau_nJetsPt20","muTauPlots2011/MSSM/muTau_nJetsPt20.root","muTau_MSSM2",1,"nJetsPt20","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/btag/muTau_nJetsPt30","muTauPlots2011/MSSM/muTau_nJetsPt30.root","muTau_MSSM2",1,"nJetsPt30","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);

   //eleTau_MVis.root

   makeLTauStack("~/www/htt/muTau/MSSM7TeV/muTau_CSVJ1","muTauPlots2011/MSSM/muTau_CSVJ1.root","muTau_inclusive",1,"CSV b-Disc","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/muTau_CSVJ1LOG","muTauPlots2011/MSSM/muTau_CSVJ1.root","muTau_inclusive",1,"CSV b-Disc","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/muTau_nJetsBTagCSVLPt20","muTauPlots2011/MSSM/muTau_nBJetsPt20Light.root","muTau_inclusive",1,"nJetsBtagLightPt20","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/muTau_nJetsBTagCSVMPt20","muTauPlots2011/MSSM/muTau_nBJetsPt20Medium.root","muTau_inclusive",1,"nJetsBtagMediumPt20","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);
   makeLTauStack("~/www/htt/muTau/MSSM7TeV/muTau_nJetsBTagCSVTPt20","muTauPlots2011/MSSM/muTau_nBJetsPt20Tight.root","muTau_inclusive",1,"nJetsBtagTightPt20","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);
   */

//    makeLTauStack("eleTau/JPTDisc","eleTauPlots/eleTau_JPTDisc.root","eleTau_X",3,"e p_{T}","GeV",false,"#tau_{#mu}#tau_{h}",false,false);
//   makeLTauStack("eleTau/JPTDiscLOG","eleTauPlots/eleTau_JPTDisc.root","eleTau_X",3,"e p_{T}","GeV",false,"#tau_{#mu}#tau_{h}",true);

//   makeLTauStack("eleTau/pt1","eleTauPlots/eleTau_pt1.root","eleTau_X",3,"e p_{T}","GeV",false,"#tau_{#mu}#tau_{h}",false,false);
//    makeLTauStack("eleTau/pt1LOG","eleTauPlots/eleTau_pt1.root","eleTau_X",3,"e p_{T}","GeV",false,"#tau_{#mu}#tau_{h}",true);

    //   makeLTauStack("eleTau/eta1","eleTauPlots/eleTau_eta1.root","eleTau_X",3,"e #eta","",true,"#tau_{#mu}#tau_{h}",false,false);
//   makeLTauStack("eleTau/eta1LOG","eleTauPlots/eleTau_eta1.root","eleTau_X",3,"e #eta","",true,"#tau_{#mu}#tau_{h}",true);

//    makeLTauStack("eleTau/pt2","eleTauPlots/eleTau_pt2.root","eleTau_X",3,"#tau p_{T}","GeV",false,"#tau_{#mu}#tau_{h}",false,false);
//    makeLTauStack("eleTau/pt2LOG","eleTauPlots/eleTau_pt2.root","eleTau_X",3,"#tau p_{T}","GeV",false,"#tau_{#mu}#tau_{h}",true);
 
//   makeLTauStack("eleTau/eta2","eleTauPlots/eleTau_eta2.root","eleTau_X",3,"#tau #eta","",true,"#tau_{#mu}#tau_{h}",false,false);
//   makeLTauStack("eleTau/eta2LOG","eleTauPlots/eleTau_eta2.root","eleTau_X",3,"#tau #eta","",true,"#tau_{#mu}#tau_{h}",true);

//    makeLTauStack("eleTau/etauID","eleTauPlots/eleTau_tauEIdMVA.root","eleTau_X",3,"E Tau ID MVA","",false,"#tau_{#mu}#tau_{h}",false,false); 

//    makeLTauStack("eleTau/mvis","eleTauPlots/eleTau_MVis.root","eleTau_X",3,"m_{vis}","GeV",false,"#tau_{#mu}#tau_{h}",false,false);
//    makeLTauStack("eleTau/mvisLOG","eleTauPlots/eleTau_MVis.root","eleTau_X",3,"m_{vis}","GeV",false,"#tau_{#mu}#tau_{h}",true);
 
//    makeLTauStack("eleTau/sv","eleTauPlots/eleTau_svMass.root","eleTau_X",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}",false,false);
//    makeLTauStack("eleTau/svLOG","eleTauPlots/eleTau_svMass.root","eleTau_X",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}",true);
 
//    makeLTauStack("eleTau/mvis_NOB","eleTauPlots/eleTau_MVis.root","eleTau_NoB",2,"m_{vis}","GeV",false,"#tau_{#mu}#tau_{h}",false);
//    makeLTauStack("eleTau/mvis_NOBLOG","eleTauPlots/eleTau_MVis.root","eleTau_NoB",2,"m_{vis}","GeV",false,"#tau_{#mu}#tau_{h}",true);

//    makeLTauStack("eleTau/sv_NOB","eleTauPlots/eleTau.root","eleTau_NoB",2,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}",false,true);
//    makeLTauStack("eleTau/sv_NOBLOG","eleTauPlots/eleTau.root","eleTau_NoB",2,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}",true,true);

//    makeLTauStack("eleTau/mvis_B","eleTauPlots/eleTau_MVisLS.root","eleTau_B",1,"m_{vis}","GeV",false,"#tau_{#mu}#tau_{h}",false);
//    makeLTauStack("eleTau/mvis_BLOG","eleTauPlots/eleTau_MVisLS.root","eleTau_B",1,"m_{vis}","GeV",false,"#tau_{#mu}#tau_{h}",true);

//    makeLTauStack("eleTau/sv_B","eleTauPlots/eleTau_SVFitLS.root","eleTau_B",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}",false);
//    makeLTauStack("eleTau/sv_BLOG","eleTauPlots/eleTau_SVFitLS.root","eleTau_B",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}",true);

//    makeLTauStack("eleTau/mvis_0JetLow","eleTauPlots/eleTauMVis.root","eleTau_0jet_low",3,"m_{e#tau}","GeV",false,"#tau_{#mu}#tau_{h}",false,true);
//    makeLTauStack("eleTau/mvis_0JetLowLOG","eleTauPlots/eleTauMVis.root","eleTau_0jet_low",3,"m_{e#tau}","GeV",false,"#tau_{#mu}#tau_{h}",true,true);

//    makeLTauStack("eleTau/mvis_0JetHigh","eleTauPlots/eleTauMVis.root","eleTau_0jet_high",3,"m_{e#tau}","GeV",false,"#tau_{#mu}#tau_{h}",false,true);
//    makeLTauStack("eleTau/mvis_0JetHighLOG","eleTauPlots/eleTauMVis.root","eleTau_0jet_high",3,"m_{e#tau}","GeV",false,"#tau_{#mu}#tau_{h}",true,true);

//    makeLTauStack("eleTau/mvis_1JetLow","eleTauPlots/eleTauMVis.root","eleTau_boost_low",3,"m_{e#tau}","GeV",false,"#tau_{#mu}#tau_{h}",false,true);
//    makeLTauStack("eleTau/mvis_1JetLowLOG","eleTauPlots/eleTauMVis.root","eleTau_boost_low",3,"m_{e#tau}","GeV",false,"#tau_{#mu}#tau_{h}",true,true);

//    makeLTauStack("eleTau/mvis_1JetHigh","eleTauPlots/eleTauMVis.root","eleTau_boost_high",3,"m_{e#tau}","GeV",false,"#tau_{#mu}#tau_{h}",false,true);
//    makeLTauStack("eleTau/mvis_1JetHighLOG","eleTauPlots/eleTauMVis.root","eleTau_boost_high",3,"m_{e#tau}","GeV",false,"#tau_{#mu}#tau_{h}",true,true);

//    makeLTauStack("eleTau/mvis_vbf","eleTauPlots/eleTauMVis.root","eleTau_vbf",3,"m_{e#tau}","GeV",false,"#tau_{#mu}#tau_{h}",false,true);
//    makeLTauStack("eleTau/mvis_vbfLOG","eleTauPlots/eleTauMVis.root","eleTau_vbf",3,"m_{e#tau}","GeV",false,"#tau_{#mu}#tau_{h}",true,true);

//    makeLTauStack("eleTau/sv_0JetLow","eleTauPlots/eleTauSM.root","eleTau_0jet_low",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}",false,true);
//    makeLTauStack("eleTau/sv_0JetLowLOG","eleTauPlots/eleTauSM.root","eleTau_0jet_low",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}",true,true);

//    makeLTauStack("eleTau/sv_0JetHigh","eleTauPlots/eleTauSM.root","eleTau_0jet_high",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}",false,true);
//    makeLTauStack("eleTau/sv_0JetHighLOG","eleTauPlots/eleTauSM.root","eleTau_0jet_high",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}",true,true);

//    makeLTauStack("eleTau/sv_1JetLow","eleTauPlots/eleTauSM.root","eleTau_boost_low",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}",false,true);
//    makeLTauStack("eleTau/sv_1JetLowLOG","eleTauPlots/eleTauSM.root","eleTau_boost_low",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}",true,true);

//    makeLTauStack("eleTau/sv_1JetHigh","eleTauPlots/eleTauSM.root","eleTau_boost_high",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}",false,true);
//    makeLTauStack("eleTau/sv_1JetHighLOG","eleTauPlots/eleTauSM.root","eleTau_boost_high",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}",true,true);

//    makeLTauStack("eleTau/sv_vbf","eleTauPlots/eleTauSM.root","eleTau_vbf",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}",false,true);
//    makeLTauStack("eleTau/sv_vbfLOG","eleTauPlots/eleTauSM.root","eleTau_vbf",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}",true,true);

//    makeLTauStack("eleTau/PZ","eleTauPlots/eleTau_PZ.root","eleTau_X",3,"p_{#zeta} - 1.5 x p_{#zeta}^{vis}","GeV",true,"#tau_{#mu}#tau_{h}",false,false);
//    makeLTauStack("eleTau/MT","eleTauPlots/eleTau_MT.root","eleTau_X",3,"M_{T}(e,MET)","GeV",false,"#tau_{#mu}#tau_{h}",false,false);
//    makeLTauStack("eleTau/MET","eleTauPlots/eleTau_MET.root","eleTau_X",3,"MET","GeV",false,"#tau_{#mu}#tau_{h}",false,false);


//    makeLTauStack("eleTau/jets","eleTauPlots/eleTau_jets.root","eleTau_X",3,"Number of Jets","",false,"#tau_{#mu}#tau_{h}",false,false);
//    makeLTauStack("eleTau/jetsLOG","eleTauPlots/eleTau_jets.root","eleTau_X",3,"Number of Jets","",false,"#tau_{#mu}#tau_{h}",true);

//     makeLTauStack("eleTau/vbfEta1","eleTauPlots/eleTau_vbfEta1.root","eleTau_vbf",3,"Leading Jet #eta","",true,"#tau_{#mu}#tau_{h}",false,false);
//    makeLTauStack("eleTau/vbfEta2","eleTauPlots/eleTau_vbfEta2.root","eleTau_vbf",3,"Sub-Leading Jet #eta","",true,"#tau_{#mu}#tau_{h}",false,false);
   
//     makeLTauStack("eleTau/vbfPt1","eleTauPlots/eleTau_vbfPt1.root","eleTau_vbf",3,"Leading Jet p_{T}","",false,"#tau_{#mu}#tau_{h}",false,false);
//     makeLTauStack("eleTau/vbfPt2","eleTauPlots/eleTau_vbfPt2.root","eleTau_vbf",3,"Sub-Leading Jet p_{T}","",false,"#tau_{#mu}#tau_{h}",false,false);

//    makeLTauStack("eleTau/bjets","eleTauPlots/eleTau_bjets.root","eleTau_X",3,"Number of b-Tagged Jets","",false,"#tau_{#mu}#tau_{h}",false,false);
//    makeLTauStack("eleTau/bjetsLOG","eleTauPlots/eleTau_bjets.root","eleTau_X",3,"Number of b-Tagged Jets","",false,"#tau_{#mu}#tau_{h}",true);

//    makeLTauStack("eleTau/BoostPt","eleTauPlots/eleTau_BoostedPt.root","eleTau_X",3,"highest Jet P_{T}","GeV",false,"#tau_{#mu}#tau_{h}",false,false);
//    makeLTauStack("eleTau/BoostEta","eleTauPlots/eleTau_BoostedEta.root","eleTau_X",3,"highest Jet #eta","GeV",true,"#tau_{#mu}#tau_{h}",false,false);

//    makeLTauStack("eleTau/vbfMVA","eleTauPlots/eleTau_vbfMVA.root","eleTau_vbf",3,"vbf MVA","",false,"#tau_{#mu}#tau_{h}",false,false);

//    makeLTauStack("eleTau/vbfDPhi","eleTauPlots/eleTau_vbfDPhi.root","eleTau_vbf",3,"#Delta#phi_{jj}","",false,"#tau_{#mu}#tau_{h}",false,false);
//    makeLTauStack("eleTau/vbfDPhiHJ","eleTauPlots/eleTau_vbfDPhiHJ.root","eleTau_vbf",3,"#Delta#phi_{HJ}","",false,"#tau_{#mu}#tau_{h}",false,false);
//    makeLTauStack("eleTau/vbfDiJetPt","eleTauPlots/eleTau_vbfDiJetPt.root","eleTau_vbf",3,"p_{T}_{jj}","",false,"#tau_{#mu}#tau_{h}",false,false);
//    makeLTauStack("eleTau/deta","eleTauPlots/eleTau_DEta.root","eleTau_vbf",3,"#Delta #eta(jj)","",false,"#tau_{#mu}#tau_{h}",false,false);
//    makeLTauStack("eleTau/Mjj","eleTauPlots/eleTau_MJJ.root","eleTau_vbf",3,"M(jj)","GeV",false,"#tau_{#mu}#tau_{h}",false,false);
//    makeLTauStack("eleTau/vbfDiTauPt","eleTauPlots/eleTau_vbfDiTauPt.root","eleTau_vbf",3,"Di-#tau p_{T}","GeV",false,"#tau_{#mu}#tau_{h}",false,false);
//    makeLTauStack("eleTau/vbfC1","eleTauPlots/eleTau_vbfC1.root","eleTau_vbf",3,"Min(#Delta#eta_{Di-#tau,j})","",false,"#tau_{#mu}#tau_{h}",false,false);
//    makeLTauStack("eleTau/vbfC2","eleTauPlots/eleTau_vbfC2.root","eleTau_vbf",3,"Visible Di-#tau p_{T}","",false,"#tau_{#mu}#tau_{h}",false,false);

//    makeLTauStack("eleTau/vbfDPhiLOG","eleTauPlots/eleTau_vbfDPhi.root","eleTau_vbf",3,"#Delta#phi_{jj}","",false,"#tau_{#mu}#tau_{h}",true,false);
//    makeLTauStack("eleTau/vbfDPhiHJLOG","eleTauPlots/eleTau_vbfDPhiHJ.root","eleTau_vbf",3,"#Delta#phi_{HJ}","",false,"#tau_{#mu}#tau_{h}",true,false);
//    makeLTauStack("eleTau/vbfDiJetPtLOG","eleTauPlots/eleTau_vbfDiJetPt.root","eleTau_vbf",3,"p_{T}_{jj}","",false,"#tau_{#mu}#tau_{h}",true,false);
//    makeLTauStack("eleTau/detaLOG","eleTauPlots/eleTau_DEta.root","eleTau_vbf",3,"#Delta #eta(jj)","",false,"#tau_{#mu}#tau_{h}",true,false);
//    makeLTauStack("eleTau/MjjLOG","eleTauPlots/eleTau_MJJ.root","eleTau_vbf",3,"M(jj)","GeV",false,"#tau_{#mu}#tau_{h}",true,false);
//    makeLTauStack("eleTau/vbfDiTauPtLOG","eleTauPlots/eleTau_vbfDiTauPt.root","eleTau_vbf",3,"Di-#tau p_{T}","GeV",false,"#tau_{#mu}#tau_{h}",true,false);
//    makeLTauStack("eleTau/vbfC1LOG","eleTauPlots/eleTau_vbfC1.root","eleTau_vbf",3,"Min(#Delta#eta_{Di-#tau,j})","",false,"#tau_{#mu}#tau_{h}",true,false);
//    makeLTauStack("eleTau/vbfC2LOG","eleTauPlots/eleTau_vbfC2.root","eleTau_vbf",3,"Visible Di-#tau p_{T}","",false,"#tau_{#mu}#tau_{h}",true,false);
//    makeLTauStack("eleTau/vbfMVALOG","eleTauPlots/eleTau_vbfMVA.root","eleTau_vbf",3,"vbf MVA","",false,"#tau_{#mu}#tau_{h}",true,false);

//    makeLTauStack("eleTau/NPVs","eleTauPlots/eleTau_NPVs.root","eleTau_X",3,"PVs","",false,"#tau_{#mu}#tau_{h}",false,false);

//   makeLTauStack("eleTau/8TeV/m_sv_vbf_eTau_2012","eleTauPlots/eleTauSM.root","eleTau_vbf",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
//   makeLTauStack("eleTau/8TeV/m_sv_vbf_eTau_2012_LOG","eleTauPlots/eleTauSM.root","eleTau_vbf",3,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);

//    makeLTauStack("eleTau/8TeV/m_sv_0JetLow_eTau_2012_hm","eleTauPlots/eleTau.root","eleTau_0jet_low",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
//    makeLTauStack("eleTau/8TeV/m_sv_0JetLow_eTau_2012_hm_LOG","eleTauPlots/eleTau.root","eleTau_0jet_low",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);
// 
//    makeLTauStack("eleTau/8TeV/m_sv_0JetHigh_eTau_2012_hm","eleTauPlots/eleTau.root","eleTau_0jet_high",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
//    makeLTauStack("eleTau/8TeV/m_sv_0JetHigh_eTau_2012_hm_LOG","eleTauPlots/eleTau.root","eleTau_0jet_high",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);
// 
//    makeLTauStack("eleTau/8TeV/m_sv_1JetLow_eTau_2012_hm","eleTauPlots/eleTau.root","eleTau_boost_low",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
//    makeLTauStack("eleTau/8TeV/m_sv_1JetLow_eTau_2012_hm_LOG","eleTauPlots/eleTau.root","eleTau_boost_low",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);
// 
//    makeLTauStack("eleTau/8TeV/m_sv_1JetHigh_eTau_2012_hm","eleTauPlots/eleTau.root","eleTau_boost_high",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
//    makeLTauStack("eleTau/8TeV/m_sv_1JetHigh_eTau_2012_hm_LOG","eleTauPlots/eleTau.root","eleTau_boost_high",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);
// 
//    makeLTauStack("eleTau/8TeV/m_sv_bJetLow_eTau_2012_hm","eleTauPlots/eleTau.root","eleTau_btag_low",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
//    makeLTauStack("eleTau/8TeV/m_sv_bJetLow_eTau_2012_hm_LOG","eleTauPlots/eleTau.root","eleTau_btag_low",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);

//    makeLTauStack("eleTau/8TeV/m_sv_bJet_eTau_2012_hm","eleTauPlots/eleTau.root","eleTau_btag",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
//    makeLTauStack("eleTau/8TeV/m_sv_bJet_eTau_2012_hm_LOG","eleTauPlots/eleTau.root","eleTau_btag",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);
// 
//    makeLTauStack("eleTau/8TeV/m_sv_NobJet_eTau_2012_hm","eleTauPlots/eleTau.root","eleTau_nobtag",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
//    makeLTauStack("eleTau/8TeV/m_sv_NobJet_eTau_2012_hm_LOG","eleTauPlots/eleTau.root","eleTau_nobtag",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);

//    makeLTauStack("eleTau/8TeV/m_sv_bJetHigh_eTau_2012_hm","eleTauPlots/eleTau.root","eleTau_btag_high",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true);
//    makeLTauStack("eleTau/8TeV/m_sv_bJetHigh_eTau_2012_hm_LOG","eleTauPlots/eleTau.root","eleTau_btag_high",1,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true);




//    makeLTauStack("eleTau/8TeV/mt_1_0JetLow_eTau_2012","eleTauPlots/eleTauSMMT.root","eleTau_0jet_low",3,"M_{T}(e,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);
//    makeLTauStack("eleTau/8TeV/mt_1_0JetLow_eTau_2012_LOG","eleTauPlots/eleTauSMMT.root","eleTau_0jet_low",3,"M_{T}(e,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,false);
// 
//    makeLTauStack("eleTau/8TeV/mt_1_0JetHigh_eTau_2012","eleTauPlots/eleTauSMMT.root","eleTau_0jet_high",3,"M_{T}(e,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);
//    makeLTauStack("eleTau/8TeV/mt_1_0JetHigh_eTau_2012_LOG","eleTauPlots/eleTauSMMT.root","eleTau_0jet_high",3,"M_{T}(e,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,false);
// 
//    makeLTauStack("eleTau/8TeV/mt_1_1JetLow_eTau_2012","eleTauPlots/eleTauSMMT.root","eleTau_boost_low",3,"M_{T}(e,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);
//    makeLTauStack("eleTau/8TeV/mt_1_1JetLow_eTau_2012_LOG","eleTauPlots/eleTauSMMT.root","eleTau_boost_low",3,"M_{T}(e,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,false);
// 
//    makeLTauStack("eleTau/8TeV/mt_1_1JetHigh_eTau_2012","eleTauPlots/eleTauSMMT.root","eleTau_boost_high",3,"M_{T}(e,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);
//    makeLTauStack("eleTau/8TeV/mt_1_1JetHigh_eTau_2012_LOG","eleTauPlots/eleTauSMMT.root","eleTau_boost_high",3,"M_{T}(e,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,false);
// 
//    makeLTauStack("eleTau/8TeV/mt_1_vbf_eTau_2012","eleTauPlots/eleTauSMMT.root","eleTau_vbf",3,"M_{T}(e,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);
//    makeLTauStack("eleTau/8TeV/mt_1_vbf_eTau_2012_LOG","eleTauPlots/eleTauSMMT.root","eleTau_vbf",3,"M_{T}(e,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,false);
// 
//    makeLTauStack("eleTau/8TeV/mt_1_bJetLow_eTau_2012","eleTauPlots/eleTauMT.root","eleTau_btag_low",1,"M_{T}(e,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);
//    makeLTauStack("eleTau/8TeV/mt_1_bJetLow_eTau_2012_LOG","eleTauPlots/eleTauMT.root","eleTau_btag_low",1,"M_{T}(e,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,false);
// 
//    makeLTauStack("eleTau/8TeV/mt_1_bJetHigh_eTau_2012","eleTauPlots/eleTauMT.root","eleTau_btag_high",1,"M_{T}(e,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);
//    makeLTauStack("eleTau/8TeV/mt_1_bJetHigh_eTau_2012_LOG","eleTauPlots/eleTauMT.root","eleTau_btag_high",1,"M_{T}(e,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,false);

//   makeLTauStack("eleTau/8TeV/njets_eTau_2012","eleTauPlots/eleTau_jets.root","eleTau_X",0,"Number of Jets","",false,"#tau_{#mu}#tau_{h}","2012",false,false);
//   makeLTauStack("eleTau/8TeV/njets_eTau_2012_LOG","eleTauPlots/eleTau_jets.root","eleTau_X",0,"Number of  Jets","",false,"#tau_{#mu}#tau_{h}","2012",true,false);

//    makeLTauStack("eleTau/8TeV/nbtags_eTau_2012","eleTauPlots/eleTau_bjets.root","eleTau_X",0,"Number of  b-Tagged Jets","",false,"#tau_{#mu}#tau_{h}","2012",false,false);
//    makeLTauStack("eleTau/8TeV/nbtags_eTau_2012_LOG","eleTauPlots/eleTau_bjets.root","eleTau_X",0,"Number of b-Tagged Jets","",false,"#tau_{#mu}#tau_{h}","2012",true,false);

//   makeLTauStack("eleTau/8TeV/jdeta_eTau_2012","eleTauPlots/eleTau_DEta.root","eleTau_vbf",3,"#Delta #eta(jj)","",false,"#tau_{#mu}#tau_{h}","2012",false,false);
//   makeLTauStack("eleTau/8TeV/mjj_eTau_2012","eleTauPlots/eleTau_MJJ.root","eleTau_vbf",3,"M(jj)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);
//   makeLTauStack("eleTau/8TeV/met_vbf_eTau_2012","eleTauPlots/eleTau_vbfMET.root","eleTau_vbf",3,"MET","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);
  

// makeLTauStack("eleTau/8TeV/cjv_eleTau_2012","eleTauPlots/eleTau_cjv.root","eleTau_vbf",3,"Central Jets p_{T}>30 GeV","",false,"#tau_{#mu}#tau_{h}","2012",false,false,false);
// makeLTauStack("eleTau/8TeV/cjv_eleTau_2012_LOG","eleTauPlots/eleTau_cjv.root","eleTau_vbf",3,"Central Jets p_{T}>30 GeV","",false,"#tau_{#mu}#tau_{h}","2012",true,false,false);

 //   makeLTauStack("eleTau/8TeV/jeta_1_eTau_2012","eleTauPlots/eleTau_vbfEta1.root","eleTau_vbf",3,"Leading Jet #eta","",true,"#tau_{#mu}#tau_{h}","2012",false,false);
//    makeLTauStack("eleTau/8TeV/jeta_2_eTau_2012","eleTauPlots/eleTau_vbfEta2.root","eleTau_vbf",3,"Sub-Leading Jet #eta","",true,"#tau_{#mu}#tau_{h}","2012",false,false);
//    
//    makeLTauStack("eleTau/8TeV/jpt_1_eTau_2012","eleTauPlots/eleTau_vbfPt1.root","eleTau_vbf",3,"Leading Jet p_{T}","",false,"#tau_{#mu}#tau_{h}","2012",false,false);
//    makeLTauStack("eleTau/8TeV/jpt_2_eTau_2012","eleTauPlots/eleTau_vbfPt2.root","eleTau_vbf",3,"Sub-Leading Jet p_{T}","",false,"#tau_{#mu}#tau_{h}","2012",false,false);

/*
   makeLTauStack("eleTau/8TeV/jdeta_eTau_2012_LOG","eleTauPlots/eleTau_DEta.root","eleTau_vbf",3,"#Delta #eta(jj)","",false,"#tau_{#mu}#tau_{h}","2012",true,false);
   makeLTauStack("eleTau/8TeV/mjj_eTau_2012_LOG","eleTauPlots/eleTau_MJJ.root","eleTau_vbf",3,"M(jj)","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,false);

   makeLTauStack("eleTau/8TeV/mt_1_eTau_2012","eleTauPlots/eleTau_MT.root","eleTau_X",0,"M_{T}(e,MET)","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);
   makeLTauStack("eleTau/8TeV/met_eTau_2012","eleTauPlots/eleTau_MET.root","eleTau_X",0,"MET","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);

   makeLTauStack("eleTau/8TeV/hjetpt_eTau_2012","eleTauPlots/eleTau_BoostedPt.root","eleTau_X",0,"highest Jet P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);
   makeLTauStack("eleTau/8TeV/hjeteta_eTau_2012","eleTauPlots/eleTau_BoostedEta.root","eleTau_X",0,"highest Jet #eta","GeV",true,"#tau_{#mu}#tau_{h}","2012",false,false);
*/
//    makeLTauStack("eleTau/8TeV/bpt_eTau_2012","eleTauPlots/eleTau_BJetPt.root","eleTau_X",0,"B Jet P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false);
//    makeLTauStack("eleTau/8TeV/beta_eTau_2012","eleTauPlots/eleTau_BJetEta.root","eleTau_X",0,"B Jet #eta","GeV",true,"#tau_{#mu}#tau_{h}","2012",false,false);

//   makeLTauStack("eleTau/8TeV/pvs_eTau_2012","eleTauPlots/eleTau_NPVs.root","eleTau_X",0,"PVs","",false,"#tau_{#mu}#tau_{h}","2012",false,false);







}

