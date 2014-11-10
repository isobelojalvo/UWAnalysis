{

///// Configurable Parameters /////
//Cuts need to be checked!!
TString Cuts = "pt1>24&&pt2>20&&diLeptons==0&&tightElectrons<=1&&tightMuons==0&&tauElectronTightMVAPass>0 && abs(eta1)< 2.1 && abs(eta2) <2.3 && (tightElectrons+tightMuons)<=1";

//Input Your Sample Here!!
TFile f("/scratch/ojalvo/HhhSync20June2014/ggHhh300.root","UPDATE");

TString OutputFile = "/scratch/ojalvo/sandboxSync/eleTauSync_Wisc";
TString Dir = "eleTauEventTreeFinal/eventTree";

///// Do Not Change //////

/// Copy the old tree and keep the appropriate branches ///
TString OutputRootFile = OutputFile+".root";
TString OutputTextFile = OutputFile+".txt";
TTree* tree = f->Get(Dir);
TFile *newfile = new TFile(OutputRootFile,"recreate");
TTree* SyncTree = tree->CopyTree(Cuts);
 SyncTree->SetName("TauCheck"); 
((TTreePlayer*)(SyncTree->GetPlayer()))->SetScanRedirect(true); 
((TTreePlayer*)(SyncTree->GetPlayer()))->SetScanFileName(OutputTextFile);
SyncTree.Scan("RUN:LUMI:EVENT","","colsize=15");


/// Set the aliases ///

SyncTree.SetAlias("evt", "EVENT");
SyncTree.SetAlias("lumi", "LUMI");
SyncTree.SetAlias("run", "RUN");
SyncTree.SetAlias("npv", "vertices");
SyncTree.SetAlias("npu", "puTruth");
SyncTree.SetAlias("rho", "Rho");
SyncTree.SetAlias("pt_1", "pt1");
SyncTree.SetAlias("pt_2", "pt2");
SyncTree.SetAlias("eta_1", "eta1");
SyncTree.SetAlias("eta_2", "eta2");
SyncTree.SetAlias("phi_1", "phi1");
SyncTree.SetAlias("phi_2", "phi2");
SyncTree.SetAlias("mva_1", "lIDMVANonTrig");
SyncTree.SetAlias("mva_2", "embeddedWeight");
SyncTree.SetAlias("m_1", "embeddedWeight");
SyncTree.SetAlias("m_2", "tauMass");
SyncTree.SetAlias("iso_1", "lPFIsoDB");
SyncTree.SetAlias("iso_2", "tauMVAIso");
SyncTree.SetAlias("m_sv", "svMass");
SyncTree.SetAlias("m_sv_Up", "embeddedWeight");
SyncTree.SetAlias("m_sv_Down", "embeddedWeight");
SyncTree.SetAlias("mcweight", "__WEIGHT__/__PUWEIGHT__");
SyncTree.SetAlias("puweight", "__PUWEIGHT__");
SyncTree.SetAlias("effweight", "__CORR__");
SyncTree.SetAlias("weight", "__WEIGHT__*__CORR__");
SyncTree.SetAlias("d0_1", "l1Dxy");
SyncTree.SetAlias("dz_1", "l1dz");
SyncTree.SetAlias("passid_1", "embeddedWeight");
SyncTree.SetAlias("passid_2", "embeddedWeight");
SyncTree.SetAlias("passiso_1", "embeddedWeight");
SyncTree.SetAlias("passiso_2", "embeddedWeight");
SyncTree.SetAlias("mt_1", "mt1");
SyncTree.SetAlias("mt_2", "mt2");
SyncTree.SetAlias("met", "embeddedWeight");
SyncTree.SetAlias("metphi", "embeddedWeight");
 SyncTree.SetAlias("mvamet", "metOld");//change back to met
SyncTree.SetAlias("mvametphi", "metOldPhi");
SyncTree.SetAlias("pzetavis", "pZV");
SyncTree.SetAlias("pzetamiss", "pZ-pZV");
SyncTree.SetAlias("metcov00", "embeddedWeight");
SyncTree.SetAlias("metcov01", "embeddedWeight");
SyncTree.SetAlias("metcov10", "embeddedWeight");
SyncTree.SetAlias("metcov11", "embeddedWeight");
SyncTree.SetAlias("mvacov00", "covMatrix00");
SyncTree.SetAlias("mvacov01", "covMatrix01");
SyncTree.SetAlias("mvacov10", "covMatrix10");
SyncTree.SetAlias("mvacov11", "covMatrix11");
SyncTree.SetAlias("jpt_1", "highestJetPt");
SyncTree.SetAlias("jeta_1", "highestJetEta");
SyncTree.SetAlias("jphi_1", "embeddedWeight");
SyncTree.SetAlias("jptraw_1", "embeddedWeight");
SyncTree.SetAlias("jptunc_1", "embeddedWeight");
SyncTree.SetAlias("jmva_1", "highestJetID");
SyncTree.SetAlias("jpass_1", "embeddedWeight");
SyncTree.SetAlias("jpt_2", "vbfPt2");
SyncTree.SetAlias("jeta_2", "vbfEta2");
SyncTree.SetAlias("jphi_2", "embeddedWeight");
SyncTree.SetAlias("jptraw_2", "embeddedWeight");
SyncTree.SetAlias("jptunc_2", "embeddedWeight");
SyncTree.SetAlias("jmva_2", "embeddedWeight");
SyncTree.SetAlias("jpass_2", "embeddedWeight");
SyncTree.SetAlias("bpt", "embeddedWeight");
SyncTree.SetAlias("beta", "embeddedWeight");
SyncTree.SetAlias("bphi", "embeddedWeight");
SyncTree.SetAlias("mjj", "vbfMass");
SyncTree.SetAlias("jdeta", "vbfDEta");
SyncTree.SetAlias("njetingap", "vbfNJetsGap30");
SyncTree.SetAlias("mva", "vbfMVA");
SyncTree.SetAlias("jdphi", "vbfDPhi");
SyncTree.SetAlias("dijetpt", "vbfDiJetPt");
SyncTree.SetAlias("dijetphi", "embeddedWeight");
SyncTree.SetAlias("hdijetphi", "vbfDPhiHJ");
SyncTree.SetAlias("visjeteta", "vbfC1");
SyncTree.SetAlias("ptvis", "vbfC2");
SyncTree.SetAlias("nbtag", "nJetsBTagCSVMPt20");
SyncTree.SetAlias("njets", "nJetsPt30");
SyncTree.SetAlias("q_1", "charge1");
SyncTree.SetAlias("q_2", "charge2");

SyncTree->Write("", TObject::kOverwrite);
newfile->Close();

}
