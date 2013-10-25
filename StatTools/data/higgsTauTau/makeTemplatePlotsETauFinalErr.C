{
   gROOT->ProcessLine(".L ../../../../UWAnalysis/ROOT/macros/plotScripts/templatePlots/makePlot.C");
   ////btag
   //       unc    postfit   total
   // ztt   1.03   0.23      1.007
   // tt    1.10   0.09      1.009
   // w     1.30  -0.42      0.874
   // zl    1.20   0.14      1.028 
   // zj    1.20   0.14      1.026 
   // vv    1.15  -0.12      0.982
   // qcd   1.20   0.16      1.032
   ///
   ////ztt    tt    w      zl   zj   vv   qcd
   ///nobtag
   //       unc    postfit   total
   // ztt   1.03   0.23      1.007
   // tt    1.10   0.09      1.009
   // w     1.30  -0.66      0.802
   // zl    1.20   0.14      1.028
   // zj    1.20   0.13      1.026 
   // vv    1.15  -0.12      0.982
   // qcd   1.20   0.50      0.900
   // zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false);
   float ztt = 1.007;      float zttb =1.007; 
   float tt  = 1.009;	   float ttb  =1.009; 
   float w   = 0.820;	   float wb   =0.874; 
   float zl  = 1.032;	   float zlb  =1.028; 
   float zj  = 1.026;	   float zjb  =1.026; 
   float vv  = 0.982;	   float vvb  =0.982;	   
   float qcd = 1.100; 	   float qcdb =1.032; 
   float err = 0.021;	   float errb =0.021; 

   /*
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/X/eleTau_tauMass1","eleTauPlots/MSSM/eleTau_tauMass1.root","eleTau_inclusive",1,"M_{#tau}","GeV",true,"#tau_{e}#tau_{h}","2012",false,false,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/nobtag/eleTau_tauMass1","eleTauPlots/MSSM/eleTau_tauMass1.root","eleTau_nobtag",1,"M_{#tau}","GeV",true,"#tau_{e}#tau_{h}","2012",false,false,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/btag/eleTau_tauMass1","eleTauPlots/MSSM/eleTau_tauMass1.root","eleTau_btag",1,"M_{#tau}","GeV",true,"#tau_{e}#tau_{h}","2012",false,false,zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false);

   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/X/eleTau_tauMass10","eleTauPlots/MSSM/eleTau_tauMass10.root","eleTau_inclusive",1,"M_{#tau}","GeV",true,"#tau_{e}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/nobtag/eleTau_tauMass10","eleTauPlots/MSSM/eleTau_tauMass10.root","eleTau_nobtag",1,"M_{#tau}","GeV",true,"#tau_{e}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/btag/eleTau_tauMass10","eleTauPlots/MSSM/eleTau_tauMass10.root","eleTau_btag",1,"M_{#tau}","GeV",true,"#tau_{e}#tau_{h}","2012",false,true,zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false);
   */

   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/X/hjeteta_eTau_2012","eleTauPlots/MSSM/eleTau_highestJetEta.root","eleTau_inclusive",1,"Jet_{1} #eta","",true,"#tau_{e}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/nobtag/hjeteta_eTau_2012","eleTauPlots/MSSM/eleTau_highestJetEta.root","eleTau_nobtag",1,"Jet_{1} #eta","",true,"#tau_{e}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/btag/hjeteta_eTau_2012","eleTauPlots/MSSM/eleTau_highestJetEta.root","eleTau_btag",1,"Jet_{1} #eta","",true,"#tau_{e}#tau_{h}","2012",false,true,zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false);
 
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/X/mt_1_eTau_2012","eleTauPlots/MSSM/eleTau_Mt.root","eleTau_inclusive",1,"m_{T}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true,ztt,tt,0.95,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/nobtag/mt_1_eTau_2012","eleTauPlots/MSSM/eleTau_Mt.root","eleTau_nobtag",1,"m_{T}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true,ztt,tt,0.95,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/btag/mt_1_eTau_2012","eleTauPlots/MSSM/eleTau_Mt.root","eleTau_btag",1,"m_{T}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true,zttb,ttb,0.9,zlb,zjb,vvb,qcdb,errb,false);

   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/X/mvis_eTau_2012","eleTauPlots/MSSM/eleTau_MVisNoLog.root","eleTau_inclusive",1,"m_{vis}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/nobtag/mvis_eTau_2012","eleTauPlots/MSSM/eleTau_MVisNoLog.root","eleTau_nobtag",1,"m_{vis}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/btag/mvis_eTau_2012","eleTauPlots/MSSM/eleTau_MVisNoLog.root","eleTau_btag",1,"m_{vis}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true,zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false);

   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/X/mvis_eTau_2012_log","eleTauPlots/MSSM/eleTau_MVis.root","eleTau_inclusive",1,"m_{vis}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/nobtag/mvis_eTau_2012_log","eleTauPlots/MSSM/eleTau_MVis.root","eleTau_nobtag",1,"m_{vis}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/btag/mvis_eTau_2012_log","eleTauPlots/MSSM/eleTau_MVisBlind.root","eleTau_btag",1,"m_{vis}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true,zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false);
 
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/X/m_sv_eTau_2012","eleTauPlots/MSSM/eleTau_svMassNoLog.root","eleTau_inclusive",0,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/nobtag/m_sv_eTau_2012","eleTauPlots/MSSM/eleTau_svMassNoLog.root","eleTau_nobtag",0,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/btag/m_sv_eTau_2012","eleTauPlots/MSSM/eleTau_svMassNoLog.root","eleTau_btag",0,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true,zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false);

   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/X/m_sv_eTau_2012_log","eleTauPlots/MSSM/eleTau_svMass.root","eleTau_inclusive",0,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",true,true,ztt,tt,w,zl,zj,vv,qcd,err,false,0.0001);
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/nobtag/m_sv_eTau_2012_log","eleTauPlots/MSSM/eleTau_svMass.root","eleTau_nobtag",0,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",true,true,ztt,tt,w,zl,zj,vv,qcd,err,false,0.0001);
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/btag/m_sv_eTau_2012","eleTauPlots/MSSM/eleTau_svMass.root","eleTau_btag",0,"m_{#tau#tau}","GeV",false,"#tau_{e}#tau_{h}","2012",true,true,zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false,0.0001);

   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/X/met_eTau_2012","eleTauPlots/MSSM/eleTau_met.root","eleTau_inclusive",0,"MET","GeV",false,"#tau_{e}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/nobtag/met_eTau_2012","eleTauPlots/MSSM/eleTau_met.root","eleTau_nobtag",0,"MET","GeV",false,"#tau_{e}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/btag/met_eTau_2012","eleTauPlots/MSSM/eleTau_met.root","eleTau_btag",0,"MET","GeV",false,"#tau_{e}#tau_{h}","2012",false,true,zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false);

   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/X/hjetpt_eTau_2012","eleTauPlots/MSSM/eleTau_J1Pt.root","eleTau_inclusive",0,"Jet_{1} p_{T}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/nobtag/hjetpt_eTau_2012","eleTauPlots/MSSM/eleTau_J1Pt.root","eleTau_nobtag",0,"Jet_{1} p_{T}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/btag/hjetpt_eTau_2012","eleTauPlots/MSSM/eleTau_J1Pt.root","eleTau_btag",0,"Jet_{1} p_{T}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true,zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false);


   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/X/pt_1_eTau_2012","eleTauPlots/MSSM/eleTau_Pt1.root","eleTau_inclusive",0,"e p_{T}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/nobtag/pt_1_eTau_2012","eleTauPlots/MSSM/eleTau_Pt1.root","eleTau_nobtag",0,"e p_{T}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/btag/pt_1_eTau_2012","eleTauPlots/MSSM/eleTau_Pt1.root","eleTau_btag",0,"e p_{T}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true,zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false);

   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/X/eta_1_eTau_2012","eleTauPlots/MSSM/eleTau_eta1.root","eleTau_inclusive",0,"e #eta","",true,"#tau_{e}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/nobtag/eta_1_eTau_2012","eleTauPlots/MSSM/eleTau_eta1.root","eleTau_nobtag",0,"e #eta","",true,"#tau_{e}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/btag/eta_1_eTau_2012","eleTauPlots/MSSM/eleTau_eta1.root","eleTau_btag",0,"e #eta","",true,"#tau_{e}#tau_{h}","2012",false,true,zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false);

   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/X/pt_2_eTau_2012","eleTauPlots/MSSM/eleTau_Pt2.root","eleTau_inclusive",0,"#tau p_{T}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/nobtag/pt_2_eTau_2012","eleTauPlots/MSSM/eleTau_Pt2.root","eleTau_nobtag",0,"#tau p_{T}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/btag/pt_2_eTau_2012","eleTauPlots/MSSM/eleTau_Pt2.root","eleTau_btag",0,"#tau p_{T}","GeV",false,"#tau_{e}#tau_{h}","2012",false,true,zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false);

   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/X/eta_2_eTau_2012","eleTauPlots/MSSM/eleTau_eta2.root","eleTau_inclusive",0,"#tau #eta","",true,"#tau_{e}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/nobtag/eta_2_eTau_2012","eleTauPlots/MSSM/eleTau_eta2.root","eleTau_nobtag",0,"#tau #eta","",true,"#tau_{e}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/btag/eta_2_eTau_2012","eleTauPlots/MSSM/eleTau_eta2.root","eleTau_btag",0,"#tau #eta","",true,"#tau_{e}#tau_{h}","2012",false,true,zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false);

   //makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/X/eleTau_tauMass","eleTauPlots/MSSM/eleTau_tauMass.root","eleTau_inclusive",0,"M_{#tau}","GeV",true,"#tau_{e}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   //makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/nobtag/eleTau_tauMass","eleTauPlots/MSSM/eleTau_tauMass.root","eleTau_nobtag",0,"M_{#tau}","GeV",true,"#tau_{e}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   //makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/btag/eleTau_tauMass","eleTauPlots/MSSM/eleTau_tauMass.root","eleTau_btag",0,"M_{#tau}","GeV",true,"#tau_{e}#tau_{h}","2012",false,true,zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false);

   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/X/hjetcsv_eTau_2012","eleTauPlots/MSSM/eleTau_CSVJ1.root","eleTau_inclusive",0,"CSV b-Disc","",false,"#tau_{e}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/X/hjetcsv_eTau_2012_log","eleTauPlots/MSSM/eleTau_CSVJ1.root","eleTau_inclusive",0,"CSV b-Disc","",false,"#tau_{e}#tau_{h}","2012",true,true,ztt,tt,w,zl,zj,vv,qcd,err,false,100);


   //makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/X/njets_eTau_2012_LOG","eleTauPlots/MSSM/eleTau_nJetsPt20.root","eleTau_inclusive",0,"nJetsPt20","",false,"#tau_{e}#tau_{h}","2012",true,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   //makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/nobtag/njets_eTau_2012_LOG","eleTauPlots/MSSM/eleTau_nJetsPt20.root","eleTau_nobtag",0,"nJetsPt20","",false,"#tau_{e}#tau_{h}","2012",true,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   //makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/btag/njets_eTau_2012_LOG","eleTauPlots/MSSM/eleTau_nJetsPt20.root","eleTau_btag",0,"nJetsPt20","",false,"#tau_{e}#tau_{h}","2012",true,true,zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false);
   
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/X/njets_eTau_2012","eleTauPlots/MSSM/eleTau_nJetsPt30.root","eleTau_inclusive",0,"nJetsPt30","",false,"#tau_{e}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/nobtag/njets_eTau_2012","eleTauPlots/MSSM/eleTau_nJetsPt30.root","eleTau_nobtag",0,"nJetsPt30","",false,"#tau_{e}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/btag/njets_eTau_2012","eleTauPlots/MSSM/eleTau_nJetsPt30.root","eleTau_btag",0,"nJetsPt30","",false,"#tau_{e}#tau_{h}","2012",false,true,zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false);

   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/X/njets_eTau_2012_log","eleTauPlots/MSSM/eleTau_nJetsPt30.root","eleTau_inclusive",0,"nJetsPt30","",false,"#tau_{e}#tau_{h}","2012",true,true,ztt,tt,w,zl,zj,vv,qcd,err,false,5);
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/nobtag/njets_eTau_2012_log","eleTauPlots/MSSM/eleTau_nJetsPt30.root","eleTau_nobtag",0,"nJetsPt30","",false,"#tau_{e}#tau_{h}","2012",true,true,ztt,tt,w,zl,zj,vv,qcd,err,false,0.1);
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/btag/njets_eTau_2012_log","eleTauPlots/MSSM/eleTau_nJetsPt30.root","eleTau_btag",0,"nJetsPt30","",false,"#tau_{e}#tau_{h}","2012",true,true,zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false,0.1);
   
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/X/nbtags_eTau_2012","eleTauPlots/MSSM/eleTau_nBJetsPt20Medium.root","eleTau_inclusive",0,"nJetsBtagMediumPt20","",false,"#tau_{e}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/X/nbtags_eTau_2012_log","eleTauPlots/MSSM/eleTau_nBJetsPt20Medium.root","eleTau_inclusive",0,"nJetsBtagMediumPt20","",false,"#tau_{e}#tau_{h}","2012",true,true,ztt,tt,w,zl,zj,vv,qcd,err,false);

   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/X/eleTau_NPVs","eleTauPlots/MSSM/eleTau_NPVs.root","eleTau_inclusive",0,"PVs","",false,"#tau_{e}#tau_{h}",false,false,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/nobtag/eleTau_NPVs","eleTauPlots/MSSM/eleTau_NPVs.root","eleTau_nobtag",0,"PVs","",false,"#tau_{e}#tau_{h}",false,false,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/PostFit/btag/eleTau_NPVs","eleTauPlots/MSSM/eleTau_NPVs.root","eleTau_btag",0,"PVs","",false,"#tau_{e}#tau_{h}",false,false,zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false);


   /////////////


}

