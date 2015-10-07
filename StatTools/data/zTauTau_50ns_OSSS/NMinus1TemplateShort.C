{
   gROOT->ProcessLine(".L ../../../../UWAnalysis/ROOT/macros/plotScripts/templatePlots/makePlot2015.C");

   //makeLTauStack(TString name,TString file,TString dir,int s,TString labelX,TString units = "GeV",bool left=false,TString channel = "",TString year = "2012",bool log = false,bool dndm=false,bool doRatio = false,true)
   //makeLTauStackPF("~/www/ztt/ETau/OS_SSStudy/OS_eleTau/MSSM8TeV/X/eleTau_NOtauIso_highestJetEta","eleTauNM1PlotsOSDM/MSSM/eleTau_NOtauIso_highestJetEta.root","eleTau_X",1,"Jet_{1} #eta","",true,"#tau_{#ele}#tau_{h}","2012",false,true,1,1,1,1,1,1,1,1,false,true);

//}
   makeLTauStack("~/www/ztt/ETau/OS_SSStudy/OS_eleTau_ALL_mt_1","eleTauNM1PlotsOSDM/eleTau_ALL_mt_1.root","eleTau_inclusive",3,"m_{T}","GeV",false,"#tau_{e}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OS_SSStudy/OS_eleTau_ALL_m_vis","eleTauNM1PlotsOSDM/eleTau_ALL_m_vis.root","eleTau_inclusive",3,"visible m_vis","GeV",false,"#tau_{e}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OS_SSStudy/OS_eleTau_ALL_LLmass","eleTauNM1PlotsOSDM/eleTau_ALL_LLmass.root","eleTau_inclusive",3,"diLepton Mass","GeV",false,"#tau_{e}#tau_{h}","40",false,false,true);
  
   makeLTauStack("~/www/ztt/ETau/OS_SSStudy/OS_eleTau_NOtauElectronTight_mt_1","eleTauNM1PlotsOSDM/eleTau_NOtauElectronTight_mt_1.root","eleTau_inclusive",3,"m_{T}","GeV",false,"#tau_{e}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OS_SSStudy/OS_eleTau_NOtauElectronTight_m_vis","eleTauNM1PlotsOSDM/eleTau_NOtauElectronTight_m_vis.root","eleTau_inclusive",3,"visible m_vis","GeV",false,"#tau_{e}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OS_SSStudy/OS_eleTau_NOtauElectronTight_LLmass","eleTauNM1PlotsOSDM/eleTau_NOtauElectronTight_LLmass.root","eleTau_inclusive",3,"diLepton Mass","GeV",false,"#tau_{e}#tau_{h}","40",false,false,true);
 

   //SAME SIGN

   makeLTauStack("~/www/ztt/ETau/OS_SSStudy/SS_eleTau_ALL_mt_1","eleTauNM1PlotsSSDM/eleTau_ALL_mt_1.root","eleTau_inclusive",3,"m_{T}","GeV",false,"#tau_{e}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OS_SSStudy/SS_eleTau_ALL_m_vis","eleTauNM1PlotsSSDM/eleTau_ALL_m_vis.root","eleTau_inclusive",3,"visible m_vis","GeV",false,"#tau_{e}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OS_SSStudy/SS_eleTau_ALL_LLmass","eleTauNM1PlotsSSDM/eleTau_ALL_LLmass.root","eleTau_inclusive",3,"diLepton Mass","GeV",false,"#tau_{e}#tau_{h}","40",false,false,true);
  
   makeLTauStack("~/www/ztt/ETau/OS_SSStudy/SS_eleTau_NOtauElectronTight_mt_1","eleTauNM1PlotsSSDM/eleTau_NOtauElectronTight_mt_1.root","eleTau_inclusive",3,"m_{T}","GeV",false,"#tau_{e}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OS_SSStudy/SS_eleTau_NOtauElectronTight_m_vis","eleTauNM1PlotsSSDM/eleTau_NOtauElectronTight_m_vis.root","eleTau_inclusive",3,"visible m_vis","GeV",false,"#tau_{e}#tau_{h}","40",false,false,true);
   makeLTauStack("~/www/ztt/ETau/OS_SSStudy/SS_eleTau_NOtauElectronTight_LLmass","eleTauNM1PlotsSSDM/eleTau_NOtauElectronTight_LLmass.root","eleTau_inclusive",3,"diLepton Mass","GeV",false,"#tau_{e}#tau_{h}","40",false,false,true);
 


 }


