{
   gROOT->ProcessLine(".L ../../../../UWAnalysis/ROOT/macros/plotScripts/templatePlots/makePlot.C");

   //makeLTauStack(TString name,TString file,TString dir,int s,TString labelX,TString units = "GeV",bool left=false,TString channel = "",TString year = "2012",bool log = false,bool dndm=false,bool doRatio = false)
   //makeLTauStackPF("~/www/htt/eleTau/MSSM8TeV/X/eleTau_highestJetEta","eleTauPlots/MSSM/eleTau_highestJetEta.root","eleTau_X",1,"Jet_{1} #eta","",true,"#tau_{#ele}#tau_{h}","2012",false,true,1,1,1,1,1,1,1,1,false);

 //  makeLTauStack("~/www/ztt/eleTau_svMass","eleTauPlots/eleTau_svMass.root","eleTau_inclusive",3,"m_{#tau #tau}","GeV",false,"#tau_{e}#tau_{h}","2015",false,false);
 //  makeLTauStack("~/www/ztt/eleTau_mt1","eleTauPlots/eleTau_mt1.root","eleTau_inclusive",3,"m_{T}","GeV",false,"#tau_{e}#tau_{h}","2015",false,false);
//}
 
   makeLTauStack("~/www/ztt/eleTau_svMass","eleTauPlots/eleTau_svMass.root","eleTau_inclusive",3,"m_{#tau #tau}","GeV",false,"#tau_{e}#tau_{h}","2015",false,false);
   makeLTauStack("~/www/ztt/eleTau_mt1","eleTauPlots/eleTau_mt1.root","eleTau_inclusive",3,"m_{T}","GeV",false,"#tau_{e}#tau_{h}","2015",false,false);
   makeLTauStack("~/www/ztt/eleTau_met","eleTauPlots/eleTau_met.root","eleTau_inclusive",3,"ME_{T}","GeV",false,"#tau_{e}#tau_{h}","2015",false,false);
   makeLTauStack("~/www/ztt/eleTau_pt1","eleTauPlots/eleTau_pt1.root","eleTau_inclusive",3,"e P_{T} ","GeV",false,"#tau_{e}#tau_{h}","2015",false,false);
   makeLTauStack("~/www/ztt/eleTau_genVisPt1","eleTauPlots/eleTau_genVisPt1.root","eleTau_inclusive",3,"Gen Visible e P_{T}","GeV",false,"#tau_{e}#tau_{h}","2015",true,false);
   makeLTauStack("~/www/ztt/eleTau_pt2","eleTauPlots/eleTau_pt2.root","eleTau_inclusive",3,"#tau P_{T}","GeV",false,"#tau_{e}#tau_{h}","2015",false,false);
   makeLTauStack("~/www/ztt/eleTau_genVisPt2","eleTauPlots/eleTau_genVisPt2.root","eleTau_inclusive",3,"Gen Visible #tau P_{T}","GeV",false,"#tau_{e}#tau_{h}","2015",true,false);
   makeLTauStack("~/www/ztt/eleTau_eta1","eleTauPlots/eleTau_eta1.root","eleTau_inclusive",3,"#eta_{e}","",false,"#tau_{e}#tau_{h}","2015",false,false);
   makeLTauStack("~/www/ztt/eleTau_eta2","eleTauPlots/eleTau_eta2.root","eleTau_inclusive",3,"#eta_{#tau}","",false,"#tau_{e}#tau_{h}","2015",false,false);
   makeLTauStack("~/www/ztt/eleTau_mass","eleTauPlots/eleTau_mass.root","eleTau_inclusive",3,"visible mass","GeV",false,"#tau_{e}#tau_{h}","2015",false,false);
   makeLTauStack("~/www/ztt/eleTau_pt","eleTauPlots/eleTau_pt.root","eleTau_inclusive",3,"Higgs Pt","GeV",false,"#tau_{e}#tau_{h}","2015",true,false);
   makeLTauStack("~/www/ztt/eleTau_charge1","eleTauPlots/eleTau_charge1.root","eleTau_inclusive",3,"q_{e}","",false,"#tau_{e}#tau_{h}","2015",false,false);
   makeLTauStack("~/www/ztt/eleTau_charge2","eleTauPlots/eleTau_charge2.root","eleTau_inclusive",3,"q_{#tau}","",false,"#tau_{e}#tau_{h}","2015",false,false);

   makeLTauStack("~/www/ztt/eleTau_vertices","eleTauPlots/eleTau_vertices.root","eleTau_inclusive",3,"vertices","",false,"#tau_{e}#tau_{h}","2015",false,false);
   makeLTauStack("~/www/ztt/eleTau_tauDecayMode","eleTauPlots/eleTau_tauDecayMode.root","eleTau_inclusive",3,"#tau decay mode","",false,"#tau_{e}#tau_{h}","2015",false,false);
   makeLTauStack("~/www/ztt/eleTau_tauMass","eleTauPlots/eleTau_tauMass.root","eleTau_inclusive",3,"M_{#tau}","GeV",false,"#tau_{e}#tau_{h}","2015",false,false);
   makeLTauStack("~/www/ztt/eleTau_nJetsPt20","eleTauPlots/eleTau_nJetsPt20.root","eleTau_inclusive",3,"Number Jets Pt>20","GeV",false,"#tau_{e}#tau_{h}","2015",false,false);
   makeLTauStack("~/www/ztt/eleTau_nJetsBTagCSVLPt20","eleTauPlots/eleTau_nJetsBTagCSVLPt20.root","eleTau_inclusive",3,"Number CISV Loose Jets Pt>20","",false,"#tau_{e}#tau_{h}","2015",true,false);
   makeLTauStack("~/www/ztt/eleTau_nJetsBTagCSVMPt20","eleTauPlots/eleTau_nJetsBTagCSVMPt20.root","eleTau_inclusive",3,"Number CISV Med Jets Pt>20","",false,"#tau_{e}#tau_{h}","2015",true,false);
   makeLTauStack("~/www/ztt/eleTau_nJetsBTagCSVTPt20","eleTauPlots/eleTau_nJetsBTagCSVTPt20.root","eleTau_inclusive",3,"Number CISV Tight Jets Pt>20","",false,"#tau_{e}#tau_{h}","2015",true,false);
}


