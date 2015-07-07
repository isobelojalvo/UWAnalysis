{

///// Configurable Parameters /////
//Cuts need to be checked!!
TString Cuts =  "pt1>18&&pt2>20&&abs(eta1)<2.1&&abs(eta2)<2.3";

//Input Your Sample Here!!
 
 TFile f("/scratch/laura/HhhSync21Aug2014/ggHhh300.root","UPDATE");

// TFile f("/scratch/laura/ggHhh300.root","UPDATE");

TString OutputFile = "/scratch/laura/sandboxSync/muTauSync_Wisc";
TString Dir = "muTauEventTree/eventTree";


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
SyncTree.SetAlias("q_1", "charge1");
SyncTree.SetAlias("q_2", "charge2");
SyncTree.SetAlias("d0_1", "l1Dxy");
SyncTree.SetAlias("dZ_1", "l1dz");
SyncTree.SetAlias("mva_1", "lIDMVANonTrig");
SyncTree.SetAlias("mva_2", "embeddedWeight");
SyncTree.SetAlias("m_1", "embeddedWeight");
SyncTree.SetAlias("m_2", "tauMass");
SyncTree.SetAlias("mt_1", "mt1");
SyncTree.SetAlias("mt_2", "mt2");
SyncTree.SetAlias("iso_1", "lPFIsoDB");
SyncTree.SetAlias("iso_2", "tauMVAIso");//TODO
SyncTree.SetAlias("id_m_loose_1", "looseId");
SyncTree.SetAlias("id_m_loose_2", "looseId");
SyncTree.SetAlias("id_m_medium_1", "mediumId");
SyncTree.SetAlias("id_m_medium_2", "mediumId");
SyncTree.SetAlias("id_m_tight_1", "tightId");
SyncTree.SetAlias("id_m_tight_2", "tightId");
SyncTree.SetAlias("id_m_tightnovtx_1", "tightId");//TODO
SyncTree.SetAlias("id_m_tightnovtx_2", "tightId");//TODO
SyncTree.SetAlias("id_e_mva_nt_loose_1", "tightId");
SyncTree.SetAlias("id_e_mva_nt_loose_2", "tightId");
SyncTree.SetAlias("id_e_mva_nt_tight_1", "tightId");
SyncTree.SetAlias("id_e_mva_nt_tight_2", "tightId");
SyncTree.SetAlias("id_e_cut_veto_1", "tightId");
SyncTree.SetAlias("id_e_cut_veto_2", "tightId");
SyncTree.SetAlias("id_e_cut_loose_1", "tightId");
SyncTree.SetAlias("id_e_cut_loose_2", "tightId");
SyncTree.SetAlias("id_e_cut_medium_1", "tightId");
SyncTree.SetAlias("id_e_cut_medium_2", "tightId");
SyncTree.SetAlias("id_e_cut_tight_1", "tightId");
SyncTree.SetAlias("id_e_cut_tight_2", "tightId");
SyncTree.SetAlias("trigweight_1", "tightId");
SyncTree.SetAlias("trigweight_2", "tightId");
SyncTree.SetAlias("againstElectronVLooseMVA5_1", "tightId");
SyncTree.SetAlias("againstElectronVLooseMVA5_2", "tightId");
SyncTree.SetAlias("againstElectronLooseMVA5_1", "tightId");
SyncTree.SetAlias("againstElectronLooseMVA5_2", "tightId");
SyncTree.SetAlias("againstElectronMediumMVA5_1", "tightId");
SyncTree.SetAlias("againstElectronMediumMVA5_2", "tightId");
SyncTree.SetAlias("againstElectronTightMVA5_1", "tightId");
SyncTree.SetAlias("againstElectronTightMVA5_2", "tightId");
SyncTree.SetAlias("againstElectronVTightMVA5_1", "tightId");
SyncTree.SetAlias("againstElectronVTightMVA5_2", "tightId");
SyncTree.SetAlias("againstMuonLoose3_1", "tightId");
SyncTree.SetAlias("againstMuonLoose3_2", "tightId");
SyncTree.SetAlias("againstMuonTight3_1", "tightId");
SyncTree.SetAlias("againstMuonTight3_2", "tightId");
SyncTree.SetAlias("byCombinedIsolationDeltaBetaCorrRaw3Hits_1", "tightId");
SyncTree.SetAlias("byCombinedIsolationDeltaBetaCorrRaw3Hits_2", "tightId");
SyncTree.SetAlias("byIsolationMVA3newDMwoLTraw_1", "");
SyncTree.SetAlias("byIsolationMVA3newDMwoLTraw_2", "");
SyncTree.SetAlias("byIsolationMVA3oldDMwoLTraw_1", "");
SyncTree.SetAlias("byIsolationMVA3oldDMwoLTraw_2", "");
SyncTree.SetAlias("byIsolationMVA3newDMwLTraw_1", "");
SyncTree.SetAlias("byIsolationMVA3newDMwLTraw_2", "");
SyncTree.SetAlias("byIsolationMVA3oldDMwLTraw_1", "");
SyncTree.SetAlias("byIsolationMVA3oldDMwLTraw_2", "");
SyncTree.SetAlias("chargedIsoPtSum_1", "");
SyncTree.SetAlias("chargedIsoPtSum_2", "");
SyncTree.SetAlias("decayModeFinding_1", "");
SyncTree.SetAlias("decayModeFinding_2", "");
SyncTree.SetAlias("decayModeFindingNewDMs_1", "");
SyncTree.SetAlias("decayModeFindingNewDMs_2", "");
SyncTree.SetAlias("neutralIsoPtSum_1", "");
SyncTree.SetAlias("neutralIsoPtSum_2", "");
SyncTree.SetAlias("puCorrPtSum_1", "");
SyncTree.SetAlias("puCorrPtSum_2", "");
//ditau system
SyncTree.SetAlias("pth", "");
SyncTree.SetAlias("m_vis", "");
SyncTree.SetAlias("m_sv", "svMass");//MarkovSchain
SyncTree.SetAlias("pt_sv", "svPt");//MarkovSchain
SyncTree.SetAlias("eta_sv", "svEta");//MarkovSchain svFit.svEta
SyncTree.SetAlias("phi_sv", "svPhi");//MarkovSchain svFit.svPhi
SyncTree.SetAlias("met_sv", "svMet");//MarkovSchaini svFit.fittedMET
SyncTree.SetAlias("met", "");//rawPFMET
SyncTree.SetAlias("mvamet", "");//change back to met
SyncTree.SetAlias("metphi", "");
SyncTree.SetAlias("mvametphi", "");
SyncTree.SetAlias("pzetavis", "pZV");
SyncTree.SetAlias("pzetamiss", "pZ-pZV");
SyncTree.SetAlias("metcov00", "");
SyncTree.SetAlias("metcov01", "");
SyncTree.SetAlias("metcov10", "");
SyncTree.SetAlias("metcov11", "");
SyncTree.SetAlias("mvacov00", "covMatrix00");
SyncTree.SetAlias("mvacov01", "covMatrix01");
SyncTree.SetAlias("mvacov10", "covMatrix10");
SyncTree.SetAlias("mvacov11", "covMatrix11");
//vfb system
SyncTree.SetAlias("mjj", "vbfMass");
SyncTree.SetAlias("jdeta", "vbfDEta");
SyncTree.SetAlias("jdphi", "vbfDPhi");
SyncTree.SetAlias("njetingap", "vbfNJetsGap30");
SyncTree.SetAlias("dijetpt", "vbfDiJetPt");
SyncTree.SetAlias("dijetphi", "embeddedWeight");
SyncTree.SetAlias("hdijetphi", "vbfDPhiHJ");
SyncTree.SetAlias("visjeteta", "vbfC1");
SyncTree.SetAlias("ptvis", "vbfC2");
//additional jets
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
SyncTree.SetAlias("mva", "vbfMVA");
//additionaljets
SyncTree.SetAlias("nbtag", "nJetsBTagCSVMPt20");
SyncTree.SetAlias("njets", "nJetsPt30");
SyncTree.SetAlias("njetspt20", "nJetsPt20");

SyncTree->Write("", TObject::kOverwrite);
newfile->Close();

}
