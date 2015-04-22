{
  NtuplePlotter *data = new NtuplePlotter("muMuEventTree/eventTree");
  data->registerFile("sandbox/muon-iso/DATA.root");
  NtuplePlotter *mc = new NtuplePlotter("muMuEventTree/eventTree");
  mc->registerFile("sandbox/muon-iso/MC.root");

  NtuplePlotter *z = new NtuplePlotter("muMuEventTree/eventTree");
  z->registerFile("sandbox/muon-iso/ZMM.root");

}
