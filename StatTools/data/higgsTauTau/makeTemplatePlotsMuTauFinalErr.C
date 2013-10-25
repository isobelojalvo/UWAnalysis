{
   gROOT->ProcessLine(".L ../../../../UWAnalysis/ROOT/macros/plotScripts/templatePlots/makePlot.C");
   ////btag
   //       unc    postfit   total
   // ztt   1.03   0.13      1.004
   // tt    1.10   0.03      1.003
   // w     1.30  +0.18      1.054
   // zl    1.20  +0.42      1.084 
   // zj    1.20   0.00      1.000 
   // vv    1.15  -0.11      0.984
   // qcd   1.20   0.14      0.966
   ///
   ////ztt    tt    w      zl   zj   vv   qcd
   ///nobtag
   //       unc    postfit   total
   // ztt   1.03   0.13      1.004
   // tt    1.08   0.03      1.002
   // w     1.10  -0.62      0.938
   // zl    1.20   0.42      1.084
   // zj    1.20   1.09      1.100 
   // vv    1.15  -0.11      0.984
   // qcd   1.10   0.77      0.077
   // zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false);
   float ztt = 1.004;      float zttb =1.004; 
   float tt  = 1.002;	   float ttb  =1.003; 
   float w   = 0.938;	   float wb   =1.054; 
   float zl  = 1.084;	   float zlb  =1.084; 
   float zj  = 1.100;	   float zjb  =1.000; 
   float vv  = 0.984;	   float vvb  =0.984;	   
   float qcd = 1.077; 	   float qcdb =0.966; 
   float err = 0.04;	   float errb =0.04; 

   makeLTauStackPF("~/www/htt/muTau/J1PtCSVSort","muTauPlots/muTau_J1PtCSVSort.root","muTau_1btag",0,"Jet_{1} P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false,ztt,tt,w,zl,zj,vv,qcd,err,true);
   //makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/X/muTau_pt2ES.root","muTauPlots/muTau_pt2ES.root","muTau_inclusive",1,"M_{#tau}","GeV",true,"#tau_{#mu}#tau_{h}","2012",false,false,1,1,1,1,1,1,1,err,false);
   /*
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/X/muTau_tauMass1","muTauPlots/MSSM/muTau_tauMass1.root","muTau_inclusive",1,"M_{#tau}","GeV",true,"#tau_{#mu}#tau_{h}","2012",false,false,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/nobtag/muTau_tauMass1","muTauPlots/MSSM/muTau_tauMass1.root","muTau_nobtag",1,"M_{#tau}","GeV",true,"#tau_{#mu}#tau_{h}","2012",false,false,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/btag/muTau_tauMass1","muTauPlots/MSSM/muTau_tauMass1.root","muTau_btag",1,"M_{#tau}","GeV",true,"#tau_{#mu}#tau_{h}","2012",false,false,zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false);

   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/X/muTau_tauMass10","muTauPlots/MSSM/muTau_tauMass10.root","muTau_inclusive",1,"M_{#tau}","GeV",true,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/nobtag/muTau_tauMass10","muTauPlots/MSSM/muTau_tauMass10.root","muTau_nobtag",1,"M_{#tau}","GeV",true,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/btag/muTau_tauMass10","muTauPlots/MSSM/muTau_tauMass10.root","muTau_btag",1,"M_{#tau}","GeV",true,"#tau_{#mu}#tau_{h}","2012",false,true,zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false);
   */
   //makeLTauStackPF("~/www/htt/muTau/pt_2_Mt1_50","muTauPlots/MSSMTemp/muTau_pt2Mt1_50.root","muTau_inclusive",0,"#tau p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,true);

   //makeLTauStackPF("~/www/htt/muTau/pt_2_Mt1_50_noTauIso","muTauPlots/MSSMTemp/muTau_pt2Mt1_50_noTauIso.root","muTau_inclusiveNoIso",0,"#tau p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,true);

   //makeLTauStackPF("~/www/htt/muTau/tauIso_hMass_nobtag","muTauPlots/MSSMTemp/muTau_tauIso_hMass_nobtag.root","muTau_inclusiveNoIso",0,"tauIso","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false,ztt,tt,w,zl,zj,vv,qcd,err,true);
   // makeLTauStackPF("~/www/htt/muTau/muonIso_hMass_nobtag","muTauPlots/MSSMTemp/muTau_lPFIsoDB_hMass_nobtag.root","muTau_inclusiveNoIso",0,"muonIso","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false,ztt,tt,w,zl,zj,vv,qcd,err,true);

   makeLTauStackPF("~/www/htt/muTau/tauIsoMt1_50_hMass","muTauPlots/MSSMTemp/muTau_tauIsoMt1_50_hMass.root","muTau_inclusiveNoIso",0,"tauIso","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false,ztt,tt,w,zl,zj,vv,qcd,err,true);

   makeLTauStackPF("~/www/htt/muTau/tauIso_hMass","muTauPlots/MSSMTemp/muTau_tauIso_hMass_btag.root","muTau_inclusiveNoIso",0,"tauIso","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false,ztt,tt,w,zl,zj,vv,qcd,err,true);
   makeLTauStackPF("~/www/htt/muTau/tauIso_hMass_btag","muTauPlots/MSSMTemp/muTau_tauIso_hMass_btag.root","muTau_inclusiveNoIso",0,"tauIso","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false,ztt,tt,w,zl,zj,vv,qcd,err,true);
   makeLTauStackPF("~/www/htt/muTau/muonIso_hMass_btag","muTauPlots/MSSMTemp/muTau_lPFIsoDB_hMass_btag.root","muTau_inclusiveNoIso",0,"muonIso","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false,ztt,tt,w,zl,zj,vv,qcd,err,true);

   /*
   makeLTauStackPF("~/www/htt/muTau/decayMode_Mt1_50_nobtag","muTauPlots/MSSMTemp/muTau_decayMode_mt1_50.root","muTau_nobtag",0,"#tau Decay Mode","",false,"#tau_{#mu}#tau_{h}","2012",false,false,ztt,tt,w,zl,zj,vv,qcd,err,true);
   makeLTauStackPF("~/www/htt/muTau/decayMode_hMass_nobtag","muTauPlots/MSSMTemp/muTau_decayMode_hMass.root","muTau_nobtag",0,"#tau Decay Mode","",false,"#tau_{#mu}#tau_{h}","2012",false,false,ztt,tt,w,zl,zj,vv,qcd,err,true);
   makeLTauStackPF("~/www/htt/muTau/pt_2_hMass_nobtag","muTauPlots/MSSMTemp/muTau_pt2_hMass.root","muTau_nobtag",0,"#tau p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,false,ztt,tt,w,zl,zj,vv,qcd,err,true);
   makeLTauStackPF("~/www/htt/muTau/met_hMass_nobtag","muTauPlots/MSSMTemp/muTau_met_hMass.root","muTau_nobtag",0,"MET","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false,ztt,tt,w,zl,zj,vv,qcd,err,true);
   */

   makeLTauStackPF("~/www/htt/muTau/decayMode_Mt1_50","muTauPlots/MSSMTemp/muTau_decayMode_mt1_50.root","muTau_inclusive",0,"#tau Decay Mode","",false,"#tau_{#mu}#tau_{h}","2012",false,false,ztt,tt,w,zl,zj,vv,qcd,err,true);
   makeLTauStackPF("~/www/htt/muTau/decayMode_hMass","muTauPlots/MSSMTemp/muTau_decayMode_hMass.root","muTau_inclusive",0,"#tau Decay Mode","",false,"#tau_{#mu}#tau_{h}","2012",false,false,ztt,tt,w,zl,zj,vv,qcd,err,true);
   makeLTauStackPF("~/www/htt/muTau/pt_2_hMass","muTauPlots/MSSMTemp/muTau_pt2_hMass.root","muTau_inclusive",0,"#tau p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,false,ztt,tt,w,zl,zj,vv,qcd,err,true);
   makeLTauStackPF("~/www/htt/muTau/met_hMass","muTauPlots/MSSMTemp/muTau_met_hMass.root","muTau_inclusive",0,"MET","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false,ztt,tt,w,zl,zj,vv,qcd,err,true);

   makeLTauStackPF("~/www/htt/muTau/decayMode_Mt1_50_btag","muTauPlots/MSSMTemp/muTau_decayMode_mt1_50.root","muTau_btag",0,"#tau Decay Mode","",false,"#tau_{#mu}#tau_{h}","2012",false,false,ztt,tt,w,zl,zj,vv,qcd,err,true);
   makeLTauStackPF("~/www/htt/muTau/decayMode_hMass_btag","muTauPlots/MSSMTemp/muTau_decayMode_hMass.root","muTau_btag",0,"#tau Decay Mode","",false,"#tau_{#mu}#tau_{h}","2012",false,false,ztt,tt,w,zl,zj,vv,qcd,err,true);
   makeLTauStackPF("~/www/htt/muTau/pt_2_hMass_btag","muTauPlots/MSSMTemp/muTau_pt2_hMass.root","muTau_btag",0,"#tau p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,false,ztt,tt,w,zl,zj,vv,qcd,err,true);
   makeLTauStackPF("~/www/htt/muTau/met_hMass_btag","muTauPlots/MSSMTemp/muTau_met_hMass.root","muTau_btag",0,"MET","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false,ztt,tt,w,zl,zj,vv,qcd,err,true);


   makeLTauStackPF("~/www/htt/muTau/tauIso_hMass","muTauPlots/MSSMTemp/muTau_tauIso_hMass.root","muTau_inclusiveNoIso",0,"tauIso","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,false,ztt,tt,w,zl,zj,vv,qcd,err,true);
   makeLTauStackPF("~/www/htt/muTau/muonIso_hMass_log","muTauPlots/MSSMTemp/muTau_lPFIsoDB_hMass.root","muTau_inclusiveNoIso",0,"muon Iso","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,false,ztt,tt,w,zl,zj,vv,qcd,err,true);

   makeLTauStackPF("~/www/htt/muTau/pt_2_ttbar","muTauPlots/MSSMTemp/muTau_pt2_ttbar.root","muTau_inclusive",0,"#tau p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,true);
   makeLTauStackPF("~/www/htt/muTau/pt_2_ttbar_btag","muTauPlots/MSSMTemp/muTau_pt2_ttbar.root","muTau_btag",0,"#tau p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,true);


   makeLTauStackPF("~/www/htt/muTau/tauIsoMt1_50_2Jets","muTauPlots/MSSMTemp/muTau_tauIsoMt1_50_2Jets.root","muTau_inclusiveNoIso",0,"#tau p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,true);

   makeLTauStackPF("~/www/htt/muTau/tauIsoMt1_50","muTauPlots/MSSMTemp/muTau_tauIsoMt1_50.root","muTau_inclusiveNoIso",0,"#tau p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,true);
   makeLTauStackPF("~/www/htt/muTau/tauIsoMt1_50_Pt2_50","muTauPlots/MSSMTemp/muTau_tauIsoMt1_50_Pt2_50.root","muTau_inclusiveNoIso",0,"#tau p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,true);

   makeLTauStackPF("~/www/htt/muTau/pt_2_Pt2Mt1_10","muTauPlots/MSSMTemp/muTau_Pt2Mt1_10.root","muTau_inclusive",0,"#tau p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,true);
   makeLTauStackPF("~/www/htt/muTau/pt_2_Pt2Mt1_10_log","muTauPlots/MSSMTemp/muTau_Pt2Mt1_10.root","muTau_inclusive",0,"#tau p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true,ztt,tt,w,zl,zj,vv,qcd,err,true);
   makeLTauStackPF("~/www/htt/muTau/muTau_SVMassMt1_10_log","muTauPlots/MSSMTemp/muTau_svMassMt1_10_log.root","muTau_inclusive",0,"SV Mass","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true,ztt,tt,w,zl,zj,vv,qcd,err,true,0.0001);
   makeLTauStackPF("~/www/htt/muTau/muTau_SVMassMt1_10","muTauPlots/MSSMTemp/muTau_svMassMt1_10.root","muTau_inclusive",0,"SV Mass","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,true,0.0001);

   makeLTauStackPF("~/www/htt/muTau/pt_2_preES_2012","muTauPlots/MSSMTemp/muTau_pt2preES.root","muTau_inclusive",0,"#tau p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,true);
   makeLTauStackPF("~/www/htt/muTau/tauIsoPt2_50","muTauPlots/MSSMTemp/muTau_tauIsoPt2_50.root","muTau_inclusiveNoIso",0,"#tau p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,true);
   makeLTauStackPF("~/www/htt/muTau/tauIsoPt2_100","muTauPlots/MSSMTemp/muTau_tauIsoPt2_100.root","muTau_inclusiveNoIso",0,"#tau p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,true);

   makeLTauStackPF("~/www/htt/muTau/hjetpt_WJETS","muTauPlots/MSSMTemp/muTau_J1Pt_MTGT50.root","muTau_inclusive",0,"Jet_{1} p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,true);
   makeLTauStackPF("~/www/htt/muTau/hjetpt_WJETS_log","muTauPlots/MSSMTemp/muTau_J1Pt_MTGT50.root","muTau_inclusive",0,"Jet_{1} p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true,ztt,tt,w,zl,zj,vv,qcd,err,true);

   makeLTauStackPF("~/www/htt/muTau/hjetpt_muTau_2012_ratio","muTauPlots/MSSM/muTau_J1Pt.root","muTau_inclusive",0,"Jet_{1} p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,true);
   makeLTauStackPF("~/www/htt/muTau/hjetpt_muTau_2012_ratio","muTauPlots/MSSM/muTau_J1Pt.root","muTau_nobtag",0,"Jet_{1} p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,true);
   makeLTauStackPF("~/www/htt/muTau/hjetpt_muTau_2012_ratio","muTauPlots/MSSM/muTau_J1Pt.root","muTau_btag",0,"Jet_{1} p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true,zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,true);


   makeLTauStackPF("~/www/htt/muTau/muTau_SVMass","muTauPlots/MSSM/muTau_svMass.root","muTau_inclusive",0,"SV Mass","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true,ztt,tt,w,zl,zj,vv,qcd,err,true,0.0001);
   makeLTauStackPF("~/www/htt/muTau/pt_2_muTau_2012","muTauPlots/MSSM/muTau_pt2.root","muTau_inclusive",0,"#tau p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,true);
   makeLTauStackPF("~/www/htt/muTau/pt_2_muTau_2012_log","muTauPlots/MSSM/muTau_pt2.root","muTau_inclusive",0,"#tau p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true,ztt,tt,w,zl,zj,vv,qcd,err,true);
   makeLTauStackPF("~/www/htt/muTau/muTau_SVMassPt2_30","muTauPlots/MSSM/muTau_svMassPt2_30.root","muTau_inclusive",0,"SV Mass","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true,ztt,tt,w,zl,zj,vv,qcd,err,true,0.0001);
   makeLTauStackPF("~/www/htt/muTau/muTau_SVMassPt2_40","muTauPlots/MSSM/muTau_svMassPt2_40.root","muTau_inclusive",0,"SV Mass","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true,ztt,tt,w,zl,zj,vv,qcd,err,true,0.0001);
   makeLTauStackPF("~/www/htt/muTau/muTau_SVMassPt2_50","muTauPlots/MSSM/muTau_svMassPt2_50.root","muTau_inclusive",0,"SV Mass","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true,ztt,tt,w,zl,zj,vv,qcd,err,true,0.0001);

   //////delete to here

   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/X/hjeteta_muTau_2012","muTauPlots/MSSM/muTau_J1Eta.root","muTau_inclusive",1,"Jet_{1} #eta","",true,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/nobtag/hjeteta_muTau_2012","muTauPlots/MSSM/muTau_J1Eta.root","muTau_nobtag",1,"Jet_{1} #eta","",true,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/btag/hjeteta_muTau_2012","muTauPlots/MSSM/muTau_J1Eta.root","muTau_btag",1,"Jet_{1} #eta","",true,"#tau_{#mu}#tau_{h}","2012",false,true,zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false);
 
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/X/mt_1_muTau_2012","muTauPlots/MSSM/muTau_Mt.root","muTau_inclusive",1,"m_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/nobtag/mt_1_muTau_2012","muTauPlots/MSSM/muTau_Mt.root","muTau_nobtag",1,"m_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/btag/mt_1_muTau_2012","muTauPlots/MSSM/muTau_Mt.root","muTau_btag",1,"m_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true,zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false);

   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/X/mvis_muTau_2012","muTauPlots/MSSM/muTau_MVisNoLog.root","muTau_inclusive",1,"m_{vis}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/nobtag/mvis_muTau_2012","muTauPlots/MSSM/muTau_MVisNoLog.root","muTau_nobtag",1,"m_{vis}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/btag/mvis_muTau_2012","muTauPlots/MSSM/muTau_MVisNoLog.root","muTau_btag",1,"m_{vis}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true,zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false);

   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/X/mvis_muTau_2012_log","muTauPlots/MSSM/muTau_MVis.root","muTau_inclusive",0,"m_{vis}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true,ztt,tt,w,zl,zj,vv,qcd,err,false,0.1);
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/nobtag/mvis_muTau_2012_log","muTauPlots/MSSM/muTau_MVis.root","muTau_nobtag",0,"m_{vis}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true,ztt,tt,w,zl,zj,vv,qcd,err,false,0.1);
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/btag/mvis_muTau_2012_log","muTauPlots/MSSM/muTau_MVisBlind.root","muTau_btag",0,"m_{vis}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true,zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false,0.1);
 
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/X/m_sv_muTau_2012","muTauPlots/MSSM/muTau_svMassNoLog.root","muTau_inclusive",0,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/nobtag/m_sv_muTau_2012","muTauPlots/MSSM/muTau_svMassNoLog.root","muTau_nobtag",0,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/btag/m_sv_muTau_2012","muTauPlots/MSSM/muTau_svMassNoLog.root","muTau_btag",0,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true,zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false);

   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/X/m_sv_muTau_2012_log","muTauPlots/MSSM/muTau_svMass.root","muTau_inclusive",0,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true,ztt,tt,w,zl,zj,vv,qcd,err,false,0.0001);
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/nobtag/m_sv_muTau_2012_log","muTauPlots/MSSM/muTau_svMass.root","muTau_nobtag",0,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true,ztt,tt,w,zl,zj,vv,qcd,err,false,0.0001);
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/btag/m_sv_muTau_2012","muTauPlots/MSSM/muTau_svMass.root","muTau_btag",0,"m_{#tau#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2012",true,true,zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false,0.0001);

   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/X/met_muTau_2012","muTauPlots/MSSM/muTau_met.root","muTau_inclusive",0,"MET","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,true);
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/nobtag/met_muTau_2012","muTauPlots/MSSM/muTau_met.root","muTau_nobtag",0,"MET","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/btag/met_muTau_2012","muTauPlots/MSSM/muTau_met.root","muTau_btag",0,"MET","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true,zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false);



   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/X/pt_1_muTau_2012","muTauPlots/MSSM/muTau_pt1.root","muTau_inclusive",0,"#mu p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,true);
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/nobtag/pt_1_muTau_2012","muTauPlots/MSSM/muTau_pt1.root","muTau_nobtag",0,"#mu p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/btag/pt_1_muTau_2012","muTauPlots/MSSM/muTau_pt1.root","muTau_btag",0,"#mu p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true,zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false);

   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/X/eta_1_muTau_2012","muTauPlots/MSSM/muTau_eta1.root","muTau_inclusive",0,"#mu #eta","",true,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/nobtag/eta_1_muTau_2012","muTauPlots/MSSM/muTau_eta1.root","muTau_nobtag",0,"#mu #eta","",true,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/btag/eta_1_muTau_2012","muTauPlots/MSSM/muTau_eta1.root","muTau_btag",0,"#mu #eta","",true,"#tau_{#mu}#tau_{h}","2012",false,true,zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false);

   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/X/pt_2_muTau_2012","muTauPlots/MSSM/muTau_pt2.root","muTau_inclusive",0,"#tau p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/nobtag/pt_2_muTau_2012","muTauPlots/MSSM/muTau_pt2.root","muTau_nobtag",0,"#tau p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/btag/pt_2_muTau_2012","muTauPlots/MSSM/muTau_pt2.root","muTau_btag",0,"#tau p_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2012",false,true,zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false);

   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/X/eta_2_muTau_2012","muTauPlots/MSSM/muTau_eta2.root","muTau_inclusive",0,"#tau #eta","",true,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/nobtag/eta_2_muTau_2012","muTauPlots/MSSM/muTau_eta2.root","muTau_nobtag",0,"#tau #eta","",true,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/btag/eta_2_muTau_2012","muTauPlots/MSSM/muTau_eta2.root","muTau_btag",0,"#tau #eta","",true,"#tau_{#mu}#tau_{h}","2012",false,true,zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false);

   //makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/X/muTau_tauMass","muTauPlots/MSSM/muTau_tauMass.root","muTau_inclusive",0,"M_{#tau}","GeV",true,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   //makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/nobtag/muTau_tauMass","muTauPlots/MSSM/muTau_tauMass.root","muTau_nobtag",0,"M_{#tau}","GeV",true,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   //makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/btag/muTau_tauMass","muTauPlots/MSSM/muTau_tauMass.root","muTau_btag",0,"M_{#tau}","GeV",true,"#tau_{#mu}#tau_{h}","2012",false,true,zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false);

   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/X/muTau_CSVJ1","muTauPlots/MSSM/muTau_CSVJ1.root","muTau_inclusive",0,"CSV b-Disc","",false,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/X/muTau_CSVJ1LOG","muTauPlots/MSSM/muTau_CSVJ1.root","muTau_inclusive",0,"CSV b-Disc","",false,"#tau_{#mu}#tau_{h}","2012",true,true,ztt,tt,w,zl,zj,vv,qcd,err,false,500);


   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/X/njets_muTau_2012","muTauPlots/MSSM/muTau_nJetsPt30.root","muTau_inclusive",0,"nJetsPt30","",false,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/nobtag/njets_muTau_2012","muTauPlots/MSSM/muTau_nJetsPt30.root","muTau_nobtag",0,"nJetsPt30","",false,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/btag/njets_muTau_2012","muTauPlots/MSSM/muTau_nJetsPt30.root","muTau_btag",0,"nJetsPt30","",false,"#tau_{#mu}#tau_{h}","2012",false,true,zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false);

   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/X/njets_muTau_2012_log","muTauPlots/MSSM/muTau_nJetsPt30.root","muTau_inclusive",0,"nJetsPt30","",false,"#tau_{#mu}#tau_{h}","2012",true,true,ztt,tt,w,zl,zj,vv,qcd,err,false,10);
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/nobtag/njets_muTau_2012_log","muTauPlots/MSSM/muTau_nJetsPt30.root","muTau_nobtag",0,"nJetsPt30","",false,"#tau_{#mu}#tau_{h}","2012",true,true,ztt,tt,w,zl,zj,vv,qcd,err,false,0.1);
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/btag/njets_muTau_2012_log","muTauPlots/MSSM/muTau_nJetsPt30.root","muTau_btag",0,"nJetsPt30","",false,"#tau_{#mu}#tau_{h}","2012",true,true,zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false,0.1);
   
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/X/nbtags_muTau_2012","muTauPlots/MSSM/muTau_nBJetsPt20Medium.root","muTau_inclusive",0,"nJetsBtagMediumPt20","",false,"#tau_{#mu}#tau_{h}","2012",false,true,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/X/nbtags_muTau_2012_log","muTauPlots/MSSM/muTau_nBJetsPt20Medium.root","muTau_inclusive",0,"nJetsBtagMediumPt20","",false,"#tau_{#mu}#tau_{h}","2012",true,true,ztt,tt,w,zl,zj,vv,qcd,err,false);

   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/X/muTau_NPVs","muTauPlots/MSSM/muTau_NPVs.root","muTau_inclusive",0,"PVs","",false,"#tau_{#mu}#tau_{h}","2012",false,false,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/nobtag/muTau_NPVs","muTauPlots/MSSM/muTau_NPVs.root","muTau_nobtag",0,"PVs","",false,"#tau_{#mu}#tau_{h}","2012",false,false,ztt,tt,w,zl,zj,vv,qcd,err,false);
   makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/PostFit/btag/muTau_NPVs","muTauPlots/MSSM/muTau_NPVs.root","muTau_btag",0,"PVs","",false,"#tau_{#mu}#tau_{h}","2012",false,false,zttb,ttb,wb,zlb,zjb,vvb,qcdb,errb,false);





}

