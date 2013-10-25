{
  gROOT->ProcessLine(".L UWAnalysis/ROOT/interactive/SimplePlotter.C+");
  gROOT->ProcessLine(".L UWAnalysis/ROOT/interactive/tdrstyle.C");
  setTDRStyle();
  
  SimplePlotter *plotter = new SimplePlotter();

     plotter->addFile("eleTauEventTree/eventTree","sandbox/et-dec12/VV.root"," Diboson","__WEIGHT__*(charge==0)",0,kRed+2,kRed+4);
     plotter->addFile("eleTauEventTree/eventTree","sandbox/et-dec12/TOP.root"," TTbar","__WEIGHT__*(charge==0)",0,kRed+1,kRed+8);
     plotter->addFile("eleTauEventTree/eventTree","sandbox/et-dec12/W.root","W+jets","__WEIGHT__*((charge==0)-(charge!=0))",0,kRed-2,kRed+4);
     plotter->addFile("eleTauEventTree/eventTree","sandbox/et-dec12/DATA.root","QCD","(HLT_Any&&charge!=0)/4600.",0,kViolet-5,kViolet+3);
     plotter->addFile("eleTauEventTree/eventTree","sandbox/et-dec12/ZJETS.root","Z+jets","__WEIGHT__*(genTaus==0)*((charge==0)-(charge!=0))",0,kOrange+7,1);
     plotter->addFile("eleTauEventTree/eventTree","sandbox/et-dec12/ZJETS.root","Z#rightarrow #tau #tau","__WEIGHT__*(genTaus==2&&charge==0)",0,10,1);

     plotter->addFile("eleTauEventTree/eventTree","sandbox/et-dec12/DATA.root","DATA","(charge==0)",1,kBlack,1);

  














}
