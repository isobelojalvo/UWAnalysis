{
   gROOT->ProcessLine(".L ../../../../UWAnalysis/ROOT/macros/plotScripts/templatePlots/makePlot.C");

   //makeLTauStack(TString name,TString file,TString dir,int s,TString labelX,TString units = "GeV",bool left=false,TString channel = "",TString year = "2012",bool log = false,bool dndm=false,bool doRatio = false)
   //makeLTauStackPF("~/www/htt/muTau/MSSM8TeV/X/muTau_highestJetEta","muTauPlots/MSSM/muTau_highestJetEta.root","muTau_X",1,"Jet_{1} #eta","",true,"#tau_{#mu}#tau_{h}","2012",false,true,1,1,1,1,1,1,1,1,false);

   makeLTauStack("~/www/ztt/muTau_svMass","muTauPlots/muTau_svMass.root","muTau_inclusive",3,"m_{#tau #tau}","GeV",false,"#tau_{#mu}#tau_{h}","2015",false,false);
   makeLTauStack("~/www/ztt/muTau_mt1","muTauPlots/muTau_mt1.root","muTau_inclusive",3,"m_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2015",false,false);
   makeLTauStack("~/www/ztt/muTau_met","muTauPlots/muTau_met.root","muTau_inclusive",3,"ME_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2015",false,false);
   makeLTauStack("~/www/ztt/muTau_pt1","muTauPlots/muTau_pt1.root","muTau_inclusive",3,"#mu P_{T} ","GeV",false,"#tau_{#mu}#tau_{h}","2015",false,false);
   makeLTauStack("~/www/ztt/muTau_genVisPt1","muTauPlots/muTau_genVisPt1.root","muTau_inclusive",3,"Gen Visible #mu P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2015",false,false);
   makeLTauStack("~/www/ztt/muTau_pt2","muTauPlots/muTau_pt2.root","muTau_inclusive",3,"#tau P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2015",false,false);
   makeLTauStack("~/www/ztt/muTau_genVisPt2","muTauPlots/muTau_genVisPt2.root","muTau_inclusive",3,"Gen Visible #tau P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","2015",false,false);
   makeLTauStack("~/www/ztt/muTau_eta1","muTauPlots/muTau_eta1.root","muTau_inclusive",3,"#eta_{#mu}","",false,"#tau_{#mu}#tau_{h}","2015",false,false);
   makeLTauStack("~/www/ztt/muTau_eta2","muTauPlots/muTau_eta2.root","muTau_inclusive",3,"#eta_{#tau}","",false,"#tau_{#mu}#tau_{h}","2015",false,false);
   makeLTauStack("~/www/ztt/muTau_mass","muTauPlots/muTau_mass.root","muTau_inclusive",3,"visible mass","GeV",false,"#tau_{#mu}#tau_{h}","2015",false,false);
   makeLTauStack("~/www/ztt/muTau_pt","muTauPlots/muTau_pt.root","muTau_inclusive",3,"Higgs Pt","GeV",false,"#tau_{#mu}#tau_{h}","2015",false,false);
   makeLTauStack("~/www/ztt/muTau_charge1","muTauPlots/muTau_charge1.root","muTau_inclusive",3,"q_{#mu}","",false,"#tau_{#mu}#tau_{h}","2015",false,false);
   makeLTauStack("~/www/ztt/muTau_charge2","muTauPlots/muTau_charge2.root","muTau_inclusive",3,"q_{#tau}","",false,"#tau_{#mu}#tau_{h}","2015",false,false);

   makeLTauStack("~/www/ztt/muTau_vertices","muTauPlots/muTau_vertices.root","muTau_inclusive",3,"vertices","",false,"#tau_{#mu}#tau_{h}","2015",false,false);
   makeLTauStack("~/www/ztt/muTau_tauDecayMode","muTauPlots/muTau_tauDecayMode.root","muTau_inclusive",3,"#tau decay mode","",false,"#tau_{#mu}#tau_{h}","2015",false,false);
   makeLTauStack("~/www/ztt/muTau_tauMass","muTauPlots/muTau_tauMass.root","muTau_inclusive",3,"M_{#tau}","GeV",false,"#tau_{#mu}#tau_{h}","2015",false,false);
   makeLTauStack("~/www/ztt/muTau_nJetsPt20","muTauPlots/muTau_nJetsPt20.root","muTau_inclusive",3,"Number Jets Pt>20","GeV",false,"#tau_{#mu}#tau_{h}","2015",false,false);
   makeLTauStack("~/www/ztt/muTau_nJetsBTagCSVLPt20","muTauPlots/muTau_nJetsBTagCSVLPt20.root","muTau_inclusive",3,"Number CISV Loose Jets Pt>20","",false,"#tau_{#mu}#tau_{h}","2015",true,false);
   makeLTauStack("~/www/ztt/muTau_nJetsBTagCSVMPt20","muTauPlots/muTau_nJetsBTagCSVMPt20.root","muTau_inclusive",3,"Number CISV Med Jets Pt>20","",false,"#tau_{#mu}#tau_{h}","2015",true,false);
   makeLTauStack("~/www/ztt/muTau_nJetsBTagCSVTPt20","muTauPlots/muTau_nJetsBTagCSVTPt20.root","muTau_inclusive",3,"Number CISV Tight Jets Pt>20","",false,"#tau_{#mu}#tau_{h}","2015",true,false);
}


}

