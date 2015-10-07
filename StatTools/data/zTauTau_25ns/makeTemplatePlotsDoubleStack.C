{
   gROOT->ProcessLine(".L ../../../../UWAnalysis/ROOT/macros/plotScripts/templatePlots/makePlot.C");

   //makeLTauStack(TString name,TString file,TString dir,int s,TString labelX,TString units = "GeV",bool left=false,TString channel = "",TString year = "2012",bool log = false,bool dndm=false,bool doRatio = false)
   //makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/X/muTau_highestJetEta","muTauPlots/MSSM/muTau_highestJetEta.root","muTau_X",1,"Jet_{1} #eta","",true,"#tau_{#mu}#tau_{h}","2012",false,true,1,1,1,1,1,1,1,1,false);

   cout<<"SVMass============"<<endl;
   makeLTauDoubleStackPAS("~/www/ztt/lTau_m_sv","muTauPlots/muTau_m_sv.root","eleTauPlots/eleTau_m_sv.root","muTau_inclusive","eleTau_inclusive",-1,"m_{#tau#tau}","GeV",false,"#tau_{l}#tau_{h}","2015",false,false);

   makeLTauDoubleStackPAS("~/www/ztt/lTau_m_vis","muTauPlots/muTau_m_vis.root","eleTauPlots/eleTau_m_vis.root","muTau_inclusive","eleTau_inclusive",-1,"m_{vis}","GeV",false,"#tau_{l}#tau_{h}","2015",false,false);
   makeLTauDoubleStackPAS("~/www/ztt/lTau_mt_1","muTauPlots/muTau_mt_1.root","eleTauPlots/eleTau_mt_1.root","muTau_inclusive","eleTau_inclusive",-1,"m_{T}","GeV",false,"#tau_{l}#tau_{h}","2015",false,false);
   makeLTauDoubleStackPAS("~/www/ztt/lTau_met","muTauPlots/muTau_met.root","eleTauPlots/eleTau_met.root","muTau_inclusive","eleTau_inclusive",-1,"E_{T}^{miss}","GeV",false,"#tau_{l}#tau_{h}","2015",false,false);
   makeLTauDoubleStackPAS("~/www/ztt/lTau_m_2","muTauPlots/muTau_m_2.root","eleTauPlots/eleTau_m_2.root","muTau_inclusive","eleTau_inclusive",-1,"m_{#tau}","GeV",false,"#tau_{l}#tau_{h}","2015",false,false);
   makeLTauDoubleStackPAS("~/www/ztt/lTau_tauDecayMode","muTauPlots/muTau_tauDecayMode.root","eleTauPlots/eleTau_tauDecayMode.root","muTau_inclusive","eleTau_inclusive",-1,"#tau_{h} decay mode","",false,"#tau_{l}#tau_{h}","2015",false,false);
   makeLTauDoubleStackPAS("~/www/ztt/lTau_npv","muTauPlots/muTau_npv.root","eleTauPlots/eleTau_npv.root","muTau_inclusive","eleTau_inclusive",-1,"npv","",false,"#tau_{#mu}#tau_{h}","2015",false,false);
   makeLTauDoubleStackPAS("~/www/ztt/lTau_njetspt20","muTauPlots/muTau_njetspt20.root","eleTauPlots/eleTau_njetspt20.root","muTau_inclusive","eleTau_inclusive",-1,"Number Jets Pt>20","GeV",false,"#tau_{#mu}#tau_{h}","2015",false,false);
}

