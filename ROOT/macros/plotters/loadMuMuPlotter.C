{
  gROOT->ProcessLine(".L UWAnalysis/ROOT/interactive/SimplePlotter.C+");
  gROOT->ProcessLine(".L UWAnalysis/ROOT/interactive/tdrstyle.C");
  setTDRStyle();
  
  SimplePlotter *plotter = new SimplePlotter();

  plotter->addFile("muMuEventTree/eventTree","sandbox/muon-iso/OTHER.root","W/t#bar{t}/QCD","__WEIGHT__",0,kYellow-2,1);
  //  plotter->addFile("muMuEventTree/eventTree","sandbox/muon-iso/QCD.root","","__WEIGHT__",0,kViolet-5,1);
  //  plotter->addFile("muMuEventTree/eventTree","sandbox/muon-id-iso/W.root","","__WEIGHT__",0,kYellow-2,1);

  //  plotter->addFile("muMuEventTree/eventTree","sandbox/muon-id-iso/QCD.root","QCD","__WEIGHT__",0,kViolet-5,1);
  // plotter->addFile("muMuEventTree/eventTree","sandbox/muon-id-iso/TOP.root","TOP","__WEIGHT__",0,kYellow-2,1);
  // plotter->addFile("muMuEventTree/eventTree","sandbox/muon-id-iso/W.root","W","__WEIGHT__",0,kBlue-2,1);

  plotter->addFile("muMuEventTree/eventTree","sandbox/muon-iso/ZMM.root","Z #rightarrow #mu #mu","__WEIGHT__",-1,kOrange-4,kBlack);
  plotter->addFile("muMuEventTree/eventTree","sandbox/muon-iso/DATA.root","Observed","1",1,kBlack,0);



}
