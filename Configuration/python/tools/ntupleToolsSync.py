import FWCore.ParameterSet.Config as cms

from UWAnalysis.Configuration.tools.analysisToolsHTauTauSync import TriggerPaths



def makeCollSize(srcName,tagName):
  PSet = cms.PSet(
        pluginType = cms.string("CollectionSizeFiller"),
        src        = cms.InputTag(srcName),
        tag        = cms.string(tagName)
  )
  return PSet

def makeCollSizeVeto(srcName,size, tagName):
  PSet = cms.PSet(
        pluginType = cms.string("CollectionSizeVetoFiller"),
        src        = cms.InputTag(srcName),
        size       = cms.untracked.double(size),
        tag        = cms.string(tagName)
  )
  return PSet


def makeLTauGeneric(plugin,sourceDiTaus,tagName,methodName):
   PSet = cms.PSet(
         pluginType  = cms.string(plugin),
         src         = cms.InputTag(sourceDiTaus),
         tag         = cms.string(tagName),
         method      = cms.string(methodName),
   )
   return PSet

def makeMuTauPair(sourceDiTaus,tagName,methodName,leadingOnly=True):
   PSet = cms.PSet(
         pluginType  = cms.string("PATMuTauPairFiller"),
         src         = cms.InputTag(sourceDiTaus),
         tag         = cms.string(tagName),
         method      = cms.string(methodName),
         leadingOnly = cms.untracked.bool(leadingOnly)
   )
   return PSet

def makeMuTauCSVPair(sourceDiTaus,tagName,cutName,methodName,rank):
   PSet = cms.PSet(
         pluginType  = cms.string("PATMuTauPairCSVJetVarFiller"),
         src         = cms.InputTag(sourceDiTaus),
         tag         = cms.string(tagName),
         cut         = cms.string(cutName),
         method      = cms.string(methodName),
         rank = cms.untracked.double(rank)
   )
   return PSet

def makeMuTauPtNoPair(sourceDiTaus,tagName,cutName,methodName,rank):
   PSet = cms.PSet(
         pluginType  = cms.string("PATMuTauPairPtJetVarFiller"),
         src         = cms.InputTag(sourceDiTaus),
         tag         = cms.string(tagName),
         cut         = cms.string(cutName),
         method      = cms.string(methodName),
         rank = cms.untracked.double(rank)
   )
   return PSet

def makeMuTauPtPair(sourceDiTaus,tagName,cutName,methodName,rank):
   PSet = cms.PSet(
         pluginType  = cms.string("PATMuTauPairPtJetPairVarFiller"),
         src         = cms.InputTag(sourceDiTaus),
         tag         = cms.string(tagName),
         cut         = cms.string(cutName),
         method      = cms.string(methodName),
         rank = cms.untracked.double(rank)
   )
   return PSet


def makeMuTauJetCountPair(sourceDiTaus,tagName,methodName,leadingOnly=True):
   PSet = cms.PSet(
         pluginType  = cms.string("PATMuTauPairJetCountFiller"),
         src         = cms.InputTag(sourceDiTaus),
         tag         = cms.string(tagName),
         method      = cms.string(methodName),
         leadingOnly = cms.untracked.bool(leadingOnly)
   )
   return PSet

def makeEleTauPair(sourceDiTaus,tagName,methodName,leadingOnly=True):
   PSet = cms.PSet(
         pluginType  = cms.string("PATEleTauPairFiller"),
         src         = cms.InputTag(sourceDiTaus),
         tag         = cms.string(tagName),
         method      = cms.string(methodName),
         leadingOnly = cms.untracked.bool(leadingOnly)
   )
   return PSet

def makeEleTauCSVPair(sourceDiTaus,tagName,cutName,methodName,rank):
   PSet = cms.PSet(
         pluginType  = cms.string("PATEleTauPairCSVJetVarFiller"),
         src         = cms.InputTag(sourceDiTaus),
         tag         = cms.string(tagName),
         cut         = cms.string(cutName),
         method      = cms.string(methodName),
         rank = cms.untracked.double(rank)
   )
   return PSet

def makeEleTauPtNoPair(sourceDiTaus,tagName,cutName,methodName,rank):
   PSet = cms.PSet(
         pluginType  = cms.string("PATEleTauPairPtJetVarFiller"),
         src         = cms.InputTag(sourceDiTaus),
         tag         = cms.string(tagName),
         cut         = cms.string(cutName),
         method      = cms.string(methodName),
         rank = cms.untracked.double(rank)
   )
   return PSet

def makeEleTauPtPair(sourceDiTaus,tagName,cutName,methodName,rank):
   PSet = cms.PSet(
         pluginType  = cms.string("PATEleTauPairPtJetPairVarFiller"),
         src         = cms.InputTag(sourceDiTaus),
         tag         = cms.string(tagName),
         cut         = cms.string(cutName),
         method      = cms.string(methodName),
         rank = cms.untracked.double(rank)
   )
   return PSet

def makeEleTauJetCountPair(sourceDiTaus,tagName,methodName,leadingOnly=True):
   PSet = cms.PSet(
         pluginType  = cms.string("PATEleTauPairJetCountFiller"),
         src         = cms.InputTag(sourceDiTaus),
         tag         = cms.string(tagName),
         method      = cms.string(methodName),
         leadingOnly = cms.untracked.bool(leadingOnly)
   )
   return PSet


def addMuTauEventTree(process,name,src = 'muTausSorted', srcLL = 'osDiMuons', srcU='TightMuons', srcE='TightElectrons'):
   process.TFileService = cms.Service("TFileService", fileName = cms.string("analysis.root") )
   eventTree = cms.EDAnalyzer('EventTreeMaker',
                              genEvent = cms.InputTag('generator'),
                              coreCollections = cms.VInputTag(
                                  cms.InputTag(src)
                              ),
                              trigger = cms.PSet(
                                  pluginType = cms.string("TriggerFiller"),
                                  src        = cms.InputTag("patTrigger"),
                                  paths      = cms.vstring(TriggerPaths)
                              ),
                              pu = cms.PSet(
                                  pluginType = cms.string("PUFiller"),
                                  src        = cms.InputTag("addPileupInfo"),
                                  tag        = cms.string("pu"),
                              ),
			      cov = cms.PSet(
                                  pluginType = cms.string("METSignificanceFiller"),
                                  src        = cms.InputTag("METSignificance"),
                                  tag        = cms.string("metcov")
                              ),
                              PVs = cms.PSet(
                                  pluginType = cms.string("VertexSizeFiller"),
                                  src        = cms.InputTag("offlineSlimmedPrimaryVertices"),
                                  #src        = cms.InputTag("primaryVertexFilter"),
                                  tag        = cms.string("npv")
                              ),#FILLED
 
                              muTauSize = makeCollSize(src,"nCands"),#FILLED
                              genTaus = makeCollSize("genTauCands","genTaus"), #FIXME
                              muMuSize = makeCollSize(srcLL,"diLeptons"),#CHECKME
                              muMuSizeVeto = makeCollSizeVeto(srcLL,0,"dilepton_veto"),#CHECKME

                              muonsSizeMT = makeCollSize(srcU,"tightMuons"),#FILLED
                              muonsSizeMTVeto = makeCollSizeVeto(srcU,1,"extramuon_veto"),#FILLED
                              electronsSizeMT = makeCollSize(srcE,"tightElectrons"),#FILLED
                              electronsSizeMTVeto = makeCollSizeVeto(srcE,0,"extraelec_veto"),#FILLED

                              tauNIsoTracks =  makeMuTauPair(src,"tauNIsoTracks","leg2.userFloat('nIsoTracks')"), #FILLED
                              tauNMatchedSeg =  makeMuTauPair(src,"tauMuonNMatchedSeg","leg2.userFloat('muonNMatchedSeg')"),#FILLED
                              tauTauHadMatched = makeMuTauPair(src,"tauMuonMatched","leg2.userFloat('muonTauHadMatched')"),#FILLED
                              tauLeadChargedHadrTrackPt = makeMuTauPair(src,"tauLeadChargedHadrTrackPt","leg2.userFloat('leadChargedHadrTrackPt')"),#FILLED

                              mass2ES = makeMuTauPair(src,"mass2ES","leg2.userFloat('ESmass')"),#FILLED
                              pt2ES = makeMuTauPair(src,"pt2ES","leg2.userFloat('ESpt')"),#FILLED
                              pt2initial = makeMuTauPair(src,"pt2preES","leg2.userFloat('preESpt')"),#FILLED
                              phi2initial = makeMuTauPair(src,"phi2preES","leg2.userFloat('preESphi')"),#FILLED

                              muTauCharge = makeMuTauPair(src,"charge","charge"),#FILLED
                              q_1 = makeMuTauPair(src,"q_1","leg1.charge"),#FILLED
                              q_2 = makeMuTauPair(src,"q_2","leg2.charge"),#FILLED

                              muTauPt = makeMuTauPair(src,"pth","pt"),#FILLED
                              muTauHT = makeMuTauPair(src,"ht","ht"),#FILLED
                              muTauMass = makeMuTauPair(src,"m_vis","mass"),#FILLED
                              muTauSVPt = makeMuTauPair(src,"pt_sv","svPt"),#FIXME
                              muTauSVMass = makeMuTauPair(src,"m_sv","svMass"),#FILLED
                              #muTauSVEta = makeMuTauPair(src,"eta_sv","svEta"),#FILLED
                              #muTauSVPhi = makeMuTauPair(src,"phi_sv","svPhi"),#FILLED

                              muTauFullPt = makeMuTauPair(src,"fullPt","fullPt"),#FILLED
                              muTauEta = makeMuTauPair(src,"fullEta","fullEta"),#FILLED
                              muTauPhi = makeMuTauPair(src,"fullPhi","fullPhi"),#FILLED
                              muTauE = makeMuTauPair(src,"fullEnergy","fullEnergy"),#FILLED

                              muTauPt1 =  makeMuTauPair(src,"pt_1","leg1.pt"), #FILLED
                              muTauPt2 =  makeMuTauPair(src,"pt_2","leg2.pt"), #FILLED
                              muTauEta1 = makeMuTauPair(src,"eta_1","leg1.eta"),#FILLED
                              muTauEta2 = makeMuTauPair(src,"eta_2","leg2.eta"),#FILLED
                              muTauPhi1 = makeMuTauPair(src,"phi_1","leg1.phi"),#FILLED
                              muTauPhi2 = makeMuTauPair(src,"phi_2","leg2.phi"),#FILLED

                              muTauMET = makeMuTauPair(src,"met","met.pt()"),#FILLED
                              muTauMETPhi = makeMuTauPair(src,"metphi","met.phi()"),#FILLED

                              #muTauMETCal = makeMuTauPair(src,"metCal","calibratedMET.pt()"),#FILLED

                              #muTauMVAMET = makeMuTauPair(src,"mvamet","mvamet"),#FILLED
                              #muTauMVAMETPhi = makeMuTauPair(src,"mvametphi","mvametphi"),#FILLED

                              muTauCovMat00 = makeMuTauPair(src,"mvacov00","covMatrix00"),#FIXME
                              muTauCovMat10 = makeMuTauPair(src,"mvacov10","covMatrix10"),#FIXME
                              muTauCovMat01 = makeMuTauPair(src,"mvacov01","covMatrix01"),#FIXME
                              muTauCovMat11 = makeMuTauPair(src,"mvacov11","covMatrix11"),#FIXME

                              muTauMT = makeMuTauPair(src,"mt12","mt12MET"),#FILLED
                              muTauMT1 = makeMuTauPair(src,"mt_1","mt1MET"),#FILLED
                              muTauMT2 = makeMuTauPair(src,"mt_2","mt2MET"),#FILLED
                              
		              muTauTopGenPt = makeMuTauPair(src,"topGenPt","topGenPt"),#FIXME
		              muTauAntiTopGenPt = makeMuTauPair(src,"antiTopGenPt","antiTopGenPt"),#FIXME

                              #BTAGS AND JETS
                              muTauMJJReg = makeMuTauPair(src,"mJJReg","mJJReg"),#FIXME
                              #muTauMJJ = makeMuTauPair(src,"mjj","mJJ"),#FILLED
                              muTauJJPt = makeMuTauPair(src,"ptJJ","ptJJ"),
                              muTauJJEta = makeMuTauPair(src,"etaJJ","etaJJ"),
                              muTauJJPhi = makeMuTauPair(src,"phiJJ","phiJJ"),
                              muTauJJEnergy = makeMuTauPair(src,"energyJJ","energyJJ"),
                              muTauVBFDEta = makeMuTauPair(src,"jdeta","vbfDEta"),
                              muTauVBFDPhi = makeMuTauPair(src,"jdphi","vbfDPhi"),
                              #muTauVBFMass = makeMuTauPair(src,"vbfMass","vbfMass"),
                              muTauVBFMass = makeMuTauPair(src,"mjj","vbfMass"),
                              muMuVBFJets20 = makeMuTauPair(src,"njetigap20","vbfNJetsGap20"),
                              muMuVBFJets30 = makeMuTauPair(src,"njetingap","vbfNJetsGap30"),

                              #Muon IDs and Isolation
                              muTauRelPFIsoDB03 = makeMuTauPair(src,"iso_1",'leg1.userFloat("dBRelIso03")'),
                              muTauRel2PFIsoDB03 = makeMuTauPair(src,"iso_2",'leg2.userFloat("dBRelIso03")'),
                              muTauRelPFIsoDB04 = makeMuTauPair(src,"lPFIsoDB04",'leg1.userFloat("dBRelIso")'),

                              muTauLooseID = makeMuTauPair(src,"id_m_loose_1",'leg1.isLooseMuon()'),
                              muTauMediumID = makeMuTauPair(src,"id_m_medium_1",'leg1.isMediumMuon()'),
                              muTauUserMediumID = makeMuTauPair(src,"muMediumId",'leg1.userInt("mediumID")'),
                              muTauDecayMode = makeMuTauPair(src,"tauDecayMode",'leg2.decayMode()'),
                              muTauDecayFound = makeMuTauPair(src,"decayModeFinding_2",'leg2.tauID("decayModeFinding")'),
                              muTauDecayFoundOld = makeMuTauPair(src,"decayModeFindingOldDMs_2",'leg2.tauID("decayModeFinding")'),
                              muTauDecayFoundNew = makeMuTauPair(src,"decayModeFindingNewDMs_2",'leg2.tauID("decayModeFindingNewDMs")'),
                              #muTauMuTriggerMatch = makeMuTauPair(src,"lTrigger",'leg1.userFloat("hltOverlapFilterIsoMu17LooseIsoPFTau20")'),
                              #muTauTauTriggerMatch = makeMuTauPair(src,"tauTrigger",'leg2.userFloat("hltOverlapFilterIsoMu17LooseIsoPFTau20")'),
                              muTauPzeta = makeMuTauPair(src,"pZeta",'pZeta-1.5*pZetaVis'),
                              muTauPZ = makeMuTauPair(src,"pZ",'pZeta'),
                              muTauPZV = makeMuTauPair(src,"pzetavis",'pZetaVis'),
                              muTauTauZIP = makeMuTauPair(src,"tauZIP",'leg2.userFloat("zIP")'),
                              muTauHadMass = makeMuTauPair(src,"m_2",'leg2.mass()'),

                              muTauMuDZ = makeMuTauPair(src,"dZ_1","leg1.userFloat('dZ')"),
                              muTauTauDZ = makeMuTauPair(src,"dZ_2","leg2.userFloat('taudZ')"),
                              muTauMuDXY = makeMuTauPair(src,"d0_1","leg1.userFloat('dXY')"),
                              muTauTauDXY = makeMuTauPair(src,"d0_2","leg2.userFloat('taudXY')"),

			      #tauIDs
                              muTauByCombIsoDBRaw3 = makeMuTauPair(src,"byCombinedIsolationDeltaBetaCorrRaw3Hits_2",'leg2.tauID("byCombinedIsolationDeltaBetaCorrRaw3Hits")'),
                              muTauByCombIsoLoose = makeMuTauPair(src,"tauIsoLoose",'leg2.tauID("byLooseCombinedIsolationDeltaBetaCorr3Hits")'),
                              muTauByCombIsoMedium = makeMuTauPair(src,"tauIsoMedium",'leg2.tauID("byMediumCombinedIsolationDeltaBetaCorr3Hits")'),
                              muTauByCombIsoTight = makeMuTauPair(src,"tauIsoTight",'leg2.tauID("byTightCombinedIsolationDeltaBetaCorr3Hits")'),
                              muTauByCharged = makeMuTauPair(src,"chargedIsoPtSum_2",'leg2.tauID("chargedIsoPtSum")'),
                              muTauByNeutral = makeMuTauPair(src,"neutralIsoPtSum_2",'leg2.tauID("neutralIsoPtSum")'),
                              muTauAgainstMuonTight3 = makeMuTauPair(src,"againstMuonTight3_2",'leg2.tauID("againstMuonTight3")'),
                              muTauAgainstEleVLooseMVA5 = makeMuTauPair(src,"againstElectronVLooseMVA5_2",'leg2.tauID("againstElectronVLooseMVA5")'),

                              muTauGenPt1 = makeMuTauPair(src,"genPt1",'p4Leg1gen().pt()'),
                              muTauGenPt2 = makeMuTauPair(src,"genPt2",'p4Leg2gen().pt()'),
                              muTauPdg1 = makeMuTauPair(src,"pdg1",'genPdg1()'),
                              muTauPdg2 = makeMuTauPair(src,"pdg2",'genPdg2()'),
                              muTauVisGenPt1 = makeMuTauPair(src,"genVisPt1",'p4VisLeg1gen().pt()'),
                              muTauVisGenPt2 = makeMuTauPair(src,"genVisPt2",'p4VisLeg2gen().pt()'),
                              muTauGenVisMass = makeMuTauPair(src,"genVisMass",'p4VisGen().M()'),
                              muTauGenMassMatched = makeMuTauPair(src,"genFullMassMatched",'p4gen().M()'),
                              muTauGenMass = makeMuTauPair(src,"fullGenMass",'genBosonMass()'),
                              muTauGenMatch1 = makeMuTauPair(src,"gen_match_1",'genPdgId1()'),
                              muTauGenMatch2 = makeMuTauPair(src,"gen_match_2",'genPdgId2()'),


                              muTauGenIsPrompt1 = makeMuTauPair(src,"isPrompt1",'isPrompt1()'),
                              muTauGenIsPromptFS1 = makeMuTauPair(src,"isPromptFS1",'isPromptFS1()'),
                              muTauGenIsDirectTauDecay1 = makeMuTauPair(src,"isTauDecay1",'isDirectPromptTauDecayProduct1()'),
                              muTauGenIsDirectTauDecayFS1 = makeMuTauPair(src,"isTauDecayFS1",'isDirectPromptTauDecayProductFS1()'),

                              muTauGenIsPrompt2 = makeMuTauPair(src,"isPrompt2",'isPrompt2()'),
                              muTauGenIsPromptFS2 = makeMuTauPair(src,"isPromptFS2",'isPromptFS2()'),
                              muTauGenIsDirectTauDecay2 = makeMuTauPair(src,"isTauDecay2",'isDirectPromptTauDecayProduct2()'),
                              muTauGenIsDirectTauDecayFS2 = makeMuTauPair(src,"isTauDecayFS2",'isDirectPromptTauDecayProductFS2()'),




                              muTauJetsPt20nbtag = makeMuTauJetCountPair(src,"nbtag",'pt()>20&&abs(eta)<2.4&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.890'),
                              muTauJetsPt30njets = makeMuTauJetCountPair(src,"njets",'pt()>30&&abs(eta)<4.7&&userFloat("idLoose")'),
                              muTauJetsPt20njets = makeMuTauJetCountPair(src,"njetspt20",'pt()>20&&abs(eta)<4.7&&userFloat("idLoose")'),


                              muTauJet1PtPtSort = makeMuTauPtPair(src,"jpt_1",'abs(eta())<4.7&&pt()>20&&userFloat("idLoose")','pt()',0),
                              muTauJet2PtPtSort = makeMuTauPtPair(src,"jpt_2",'abs(eta())<4.7&&pt()>20&&userFloat("idLoose")','pt()',1),
                              muTauJet1PFIDPtSort = makeMuTauPtPair(src,"jpfid_1",'abs(eta())<4.7&&pt()>20&&userFloat("idLoose")','userFloat("idLoose")',0),
                              muTauJet2PFIDPtSort = makeMuTauPtPair(src,"jpfid_2",'abs(eta())<4.7&&pt()>20&&userFloat("idLoose")','userFloat("idLoose")',1),
                              muTauJet1PUIDPtSort = makeMuTauPtPair(src,"jpuid_1",'abs(eta())<4.7&&pt()>20&&userFloat("idLoose")','userFloat("puID")',0),
                              muTauJet2PUIDPtSort = makeMuTauPtPair(src,"jpuid_2",'abs(eta())<4.7&&pt()>20&&userFloat("idLoose")','userFloat("puID")',1),
                              muTauJet1MVAPtSort = makeMuTauPtPair(src,"jmva_1",'abs(eta())<4.7&&pt()>20&&userFloat("idLoose")',"userFloat('pileupJetId:fullDiscriminant')",0),
                              muTauJet2MVAPtSort = makeMuTauPtPair(src,"jmva_2",'abs(eta())<4.7&&pt()>20&&userFloat("idLoose")',"userFloat('pileupJetId:fullDiscriminant')",1),
                              muTauJet1EtaPtSort = makeMuTauPtPair(src,"jeta_1",'abs(eta())<4.7&&pt()>20&&userFloat("idLoose")','eta()',0),
                              muTauJet2EtaPtSort = makeMuTauPtPair(src,"jeta_2",'abs(eta())<4.7&&pt()>20&&userFloat("idLoose")','eta()',1),
                              muTauJet1PhiPtSort = makeMuTauPtPair(src,"jphi_1",'abs(eta())<4.7&&pt()>20&&userFloat("idLoose")','phi()',0),
                              muTauJet2PhiPtSort = makeMuTauPtPair(src,"jphi_2",'abs(eta())<4.7&&pt()>20&&userFloat("idLoose")','phi()',1),
                              muTauJet1CSVPtSort = makeMuTauPtPair(src,"jcsv_1",'abs(eta())<4.7&&pt()>20','bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")',0),
                              muTauJet2CSVPtSort = makeMuTauPtPair(src,"jcsv_2",'abs(eta())<4.7&&pt()>20','bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")',1),


                              muTauJet1FlavourPtSort = makeMuTauPtPair(src,"J1Flavour",'abs(eta())<2.4&&pt()>20&&userFloat("idLoose")','partonFlavour()',0),
                              muTauJet2FlavourPtSort = makeMuTauPtPair(src,"J2Flavour",'abs(eta())<2.4&&pt()>20&&userFloat("idLoose")','partonFlavour()',1),
                              muTauJet1LooseIdPtSort = makeMuTauPtPair(src,"J1LooseId",'','userFloat("idLoose")',0),
                              muTauJet2LooseIdPtSort = makeMuTauPtPair(src,"J2LooseId",'','userFloat("idLoose")',1),
                              muTauJet1MedIdPtSort = makeMuTauPtPair(src,"J1MediumId",'','userFloat("idMedium")',0),
                              muTauJet2MedIdPtSort = makeMuTauPtPair(src,"J2MediumId",'','userFloat("idMedium")',1),
                              muTauJet1TightIdPtSort = makeMuTauPtPair(src,"J1TightId",'','userFloat("idTight")',0),
                              muTauJet2TightIdPtSort = makeMuTauPtPair(src,"J2TightId",'','userFloat("idTight")',1),
                              muTauJet1GenPtPtSort = makeMuTauPtPair(src,"J1GenPt",'','userFloat("genJetPt")',0),
                              muTauJet2GenPtPtSort = makeMuTauPtPair(src,"J2GenPt",'','userFloat("genJetPt")',1),
                              muTauJet1GenEtaPtSort = makeMuTauPtPair(src,"J1GenEta",'','userFloat("genJetEta")',0),#FIXME
                              muTauJet2GenEtaPtSort = makeMuTauPtPair(src,"J2GenEta",'','userFloat("genJetEta")',1),#FIXME
                              muTauJet1GenPhiPtSort = makeMuTauPtPair(src,"J1GenPhi",'','userFloat("genJetPhi")',0),#FIXME
                              muTauJet2GenPhiPtSort = makeMuTauPtPair(src,"J2GenPhi",'','userFloat("genJetPhi")',1),#FIXME


                              muTauJetsBTagCSVLPt20 = makeMuTauJetCountPair(src,"nJetsBTagCSVLPt20",'bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.605&&pt()>20&&abs(eta)<2.4'),
                              muTauJetsBTagCSVLPt25 = makeMuTauJetCountPair(src,"nJetsBTagCSVLPt25",'bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.605&&pt()>25&&abs(eta)<2.4'),
                              muTauJetsBTagCSVMPt20 = makeMuTauJetCountPair(src,"nJetsBTagCSVMPt20",'bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.890&&pt()>20&&abs(eta)<2.4'),
                              muTauJetsBTagCSVMPt25 = makeMuTauJetCountPair(src,"nJetsBTagCSVMPt25",'bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.890&&pt()>25&&abs(eta)<2.4'),
                              muTauJetsBTagCSVTPt20 = makeMuTauJetCountPair(src,"nJetsBTagCSVTPt20",'bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.97&&pt()>20&&abs(eta)<2.4'),
                              muTauJetsBTagCSVTPt25 = makeMuTauJetCountPair(src,"nJetsBTagCSVTPt25",'bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.97&&pt()>25&&abs(eta)<2.4'),
                              muTauJetsPt20 = makeMuTauJetCountPair(src,"nJetsPt20",'pt()>20'),
                              muTauJetsPt20Loose = makeMuTauJetCountPair(src,"nJetsPt20Loose",'pt()>20&&userFloat("idLoose")'),
                              muTauJetsPt20Medium = makeMuTauJetCountPair(src,"nJetsPt20Medium",'pt()>20&&userFloat("idMedium")'),
                              muTauJetsPt20Tight = makeMuTauJetCountPair(src,"nJetsPt20Tight",'pt()>20&&userFloat("idTight")'),
                              muTauJetsPt20Tag = makeMuTauJetCountPair(src,"nTaggableJetsPt20",'pt()>20&&abs(eta)<2.4'),
                              muTauJetsPt20TagMatch = makeMuTauJetCountPair(src,"nTaggableJetsPt20Matched",'pt()>20&&abs(eta)<2.4&&abs(partonFlavour)==5'),
                              muTauJetsPt20TagMatchTag = makeMuTauJetCountPair(src,"nTaggableJetsPt20MatchedTagM",'pt()>20&&abs(eta)<2.4&&abs(partonFlavour)==5&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.890'),
                              muTauJetsPt20TagNoMatch = makeMuTauJetCountPair(src,"nTaggableJetsPt20NotMatched",'pt()>30&&abs(eta)<2.4&&abs(partonFlavour)!=5'),
                              muTauJetsPt20TagNoMatchTag = makeMuTauJetCountPair(src,"nTaggableJetsPt20NotMatchedTagM",'pt()>20&&abs(eta)<2.4&&abs(partonFlavour)!=5&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.890'),
                              muTauJetsPt30 = makeMuTauJetCountPair(src,"nJetsPt30",'pt()>30'),
                              muTauJetsPt30TagMatch = makeMuTauJetCountPair(src,"nTaggableJetsPt30Matched",'pt()>30&&abs(eta)<2.4&&abs(partonFlavour)==5'),
                              muTauJetsPt30TagMatchTag = makeMuTauJetCountPair(src,"nTaggableJetsPt30MatchedTagM",'pt()>30&&abs(eta)<2.4&&abs(partonFlavour)==5&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.890'),
                              muTauJetsPt30TagNoMatch = makeMuTauJetCountPair(src,"nTaggableJetsPt30NotMatched",'pt()>30&&abs(eta)<2.4&&abs(partonFlavour)!=5'),
                              muTauJetsPt30TagNoMatchTag = makeMuTauJetCountPair(src,"nTaggableJetsPt30NotMatchedTagM",'pt()>30&&abs(eta)<2.4&&abs(partonFlavour)!=5&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.890'),

                              muTauFirstJetID53X = makeLTauGeneric("PATMuTauPairHighestPtJetVarFiller",src,"highestJetID53X","userFloat('pileupJetId:fullDiscriminant')"), 
                              muTauFirstJetID53XPuPass = makeLTauGeneric("PATMuTauPairHighestPtJetVarFiller",src,"highestJetID53XPuPass","userFloat('puID')"), 
                              muTauFirstJetFlavour = makeLTauGeneric("PATMuTauPairHighestPtJetVarFiller",src,"highestJetFlavour",'partonFlavour()'),
                              muTauFirstJetShape = makeLTauGeneric("PATMuTauPairHighestPtJetVarFiller",src,"highestJetShape",'userFloat("ptRMS")'),
                              muTauFirstJetCSV = makeLTauGeneric("PATMuTauPairHighestPtJetVarFiller",src,"highestJetBTagCSV",'bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")'),
                              muTauFirstJetChMult = makeLTauGeneric("PATMuTauPairHighestPtJetVarFiller",src,"highestJetNCharged",'chargedMultiplicity()'),
                              muTauFirstJetNeuMult = makeLTauGeneric("PATMuTauPairHighestPtJetVarFiller",src,"highestJetNNeutral",'photonMultiplicity()+neutralHadronMultiplicity()'),

                              mumuDR = makeLTauGeneric("PATMuPairFiller",srcLL,"diLeptonDR","dR12"),#FIXME

                              higgsPt = cms.PSet(
                                  pluginType = cms.string("PATGenParticleFiller"),
                                  src        = cms.InputTag("genDaughters"),
                                  tag        = cms.string("higgsPt"),
                                  method     = cms.string('pt()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED in higgs sample

                              muTauLHEProduct = cms.PSet(
                                  pluginType = cms.string("LHEProductFiller"),
                                  src        = cms.InputTag("source"),
                                  tag        = cms.string("LHEProduct"),
                              ),
                              muTauLHEProduct2 = cms.PSet(
                                  pluginType = cms.string("LHEProductFiller"),
                                  src        = cms.InputTag("externalLHEProducer"),
                                  tag        = cms.string("LHEProduct2"),
                              ),
                              muTauEmbedPtWeight = cms.PSet(
                                  pluginType = cms.string("GenFilterInfoWeightFiller"),
                                  src        = cms.InputTag("generator"),
                                  #src        = cms.InputTag("generator","EmbWeight"),
                                  tag        = cms.string("EmbWeight"),
                              ),#FIXME #CHECKME
                              muTauEmbedPt = cms.PSet(
                                  pluginType = cms.string("PATGenParticleFiller"),
                                  src        = cms.InputTag("genDaughters"),
                                  tag        = cms.string("embeddedPt"),#CHECKME
                                  method     = cms.string("pt"),
                                  leadingOnly=cms.untracked.bool(False)
                              ),#FIXME #CHECKME
                              muTauEmbedEta = cms.PSet(
                                  pluginType = cms.string("PATGenParticleFiller"),
                                  src        = cms.InputTag("genDaughters"),
                                  tag        = cms.string("embeddedEta"),
                                  method     = cms.string("eta"),
                                  leadingOnly=cms.untracked.bool(False)
                              )#FIXME #CHECKME

   )

   setattr(process, name, eventTree)
   p = cms.Path(getattr(process,name))
   setattr(process, name+'Path', p)



#Tree for e+tau + MET final state
def addEleTauEventTree(process,name,src='eleTausSorted',srcLL='osDiElectrons', srcU='TightMuons', srcE='TightElectrons'):
   process.TFileService = cms.Service("TFileService", fileName = cms.string("analysis.root") )
   eventTree = cms.EDAnalyzer('EventTreeMaker',
                              genEvent = cms.InputTag('generator'),
                              coreCollections = cms.VInputTag(
                                  cms.InputTag(src)
                              ),
                              trigger = cms.PSet(
                                  pluginType = cms.string("TriggerFiller"),
                                  src        = cms.InputTag("patTrigger"),
                                  paths      = cms.vstring(TriggerPaths)
                              ),
                              pu = cms.PSet(
                                  pluginType = cms.string("PUFiller"),
                                  src        = cms.InputTag("addPileupInfo"),
                                  tag        = cms.string("pu"),
                              ),
			      cov = cms.PSet(
                                  pluginType = cms.string("METSignificanceFiller"),
                                  src        = cms.InputTag("METSignificance"),
                                  tag        = cms.string("metcov")
                              ),
                              PVs = cms.PSet(
                                  pluginType = cms.string("VertexSizeFiller"),
                                  src        = cms.InputTag("offlineSlimmedPrimaryVertices"),
                                  #src        = cms.InputTag("primaryVertexFilter"),
                                  tag        = cms.string("npv")
                              ),

                              muonsSizeET = makeCollSize(srcU,"tightMuons"),
                              muonsSizeETVeto = makeCollSizeVeto(srcU,0,"extramuon_veto"),
                              electronsSizeET = makeCollSize(srcE,"tightElectrons"),
                              electronsSizeETVeto = makeCollSizeVeto(srcE, 1,"extraelec_veto"),

                              eleTauSize = makeCollSize(srcE,"nCands"),
                              eleEleSize = makeCollSize(srcLL,"diLeptons"),
                              eleEleSizeVeto = makeCollSizeVeto(srcLL,0,"dilepton_veto"),
                              genTaus = makeCollSize("genTauCands","genTaus"), #FIXME
 
                              tauNIsoTracks =  makeEleTauPair(src,"tauNIsoTracks","leg2.userFloat('nIsoTracks')"), #FILLED
                              tauNMatchedSeg =  makeEleTauPair(src,"tauMuonNMatchedSeg","leg2.userFloat('muonNMatchedSeg')"), #FILLED
                              tauTauHadMatched = makeEleTauPair(src,"tauMuonMatched","leg2.userFloat('muonTauHadMatched')"),
                              tauLeadChargedHadrTrackPt = makeEleTauPair(src,"tauLeadChargedHadrTrackPt","leg2.userFloat('leadChargedHadrTrackPt')"),
                              tauLeadChargedHadrTrackPtErr = makeEleTauPair(src,"tauLeadChargedHadrTrackPtErr","leg2.userFloat('leadPFTrackPtErr')"), #FIXME

                              mass2ES = makeEleTauPair(src,"mass2ES","leg2.userFloat('ESmass')"),#FIXME
                              pt2ES = makeEleTauPair(src,"pt2ES","leg2.userFloat('ESpt')"),#FIXME
                              eleTauPt2initial = makeEleTauPair(src,"pt2preES","leg2.userFloat('preESpt')"),
                              eleTauPhi2initial = makeEleTauPair(src,"phi2preES","leg2.userFloat('preESphi')"),


                              eleTauCharge = makeEleTauPair(src,"charge","charge"),
                              eleTauCharge1 = makeEleTauPair(src,"q_1","leg1.charge"),
                              eleTauCharge2 = makeEleTauPair(src,"q_2","leg2.charge"),

                              eleTauPt = makeEleTauPair(src,"pth","pt"),
                              eleTauHT = makeEleTauPair(src,"ht","ht"),
                              eleTauMass = makeEleTauPair(src,"m_vis","mass"),
                              eleTauSVPt = makeEleTauPair(src,"pt_sv","svPt"),
                              eleTauSVMass = makeEleTauPair(src,"m_sv","svMass"),
                              #eleTauSVEta = makeEleTauPair(src,"eta_sv","svEta"),
                              #eleTauSVPhi = makeEleTauPair(src,"phi_sv","svPhi"),

                              eleTauFullPt = makeEleTauPair(src,"fullPt","fullPt"),
                              eleTauEta = makeEleTauPair(src,"fullEta","fullEta"),
                              eleTauPhi = makeEleTauPair(src,"fullPhi","fullPhi"),
                              eleTauE = makeEleTauPair(src,"fullEnergy","fullEnergy"),

                              eleTauPt1 =  makeEleTauPair(src,"pt_1","leg1.pt"), #FILLED
                              eleTauPt2 =  makeEleTauPair(src,"pt_2","leg2.pt"), #FILLED
                              eleTauEta1 = makeEleTauPair(src,"eta_1","leg1.eta"),
                              eleTauSCEta1 = makeEleTauPair(src,"SCeta_1","leg1.superCluster().eta()"),
                              eleTauEta2 = makeEleTauPair(src,"eta_2","leg2.eta"),
                              eleTauPhi1 = makeEleTauPair(src,"phi_1","leg1.phi"),
                              eleTauPhi2 = makeEleTauPair(src,"phi_2","leg2.phi"),

                              eleTauGenIsPrompt1 = makeEleTauPair(src,"isPrompt1",'isPrompt1()'),
                              eleTauGenIsPromptFS1 = makeEleTauPair(src,"isPromptFS1",'isPromptFS1()'),
                              eleTauGenIsDirectTauDecay1 = makeEleTauPair(src,"isTauDecay1",'isDirectPromptTauDecayProduct1()'),
                              eleTauGenIsDirectTauDecayFS1 = makeEleTauPair(src,"isTauDecayFS1",'isDirectPromptTauDecayProductFS1()'),
                              eleTauGenIsPrompt2 = makeEleTauPair(src,"isPrompt2",'isPrompt2()'),
                              eleTauGenIsPromptFS2 = makeEleTauPair(src,"isPromptFS2",'isPromptFS2()'),
                              eleTauGenIsDirectTauDecay2 = makeEleTauPair(src,"isTauDecay2",'isDirectPromptTauDecayProduct2()'),
                              eleTauGenIsDirectTauDecayFS2 = makeEleTauPair(src,"isTauDecayFS2",'isDirectPromptTauDecayProductFS2()'),


                              #eleTauMETUnc = makeEleTauPair(src,"metUnc","met.pt()"),#curretnly identical
                              #eleTauMET = makeEleTauPair(src,"met","calibratedMET.pt()"),#currently identical
                              #eleTauMETPhi = makeEleTauPair(src,"metphi","metPhi"),


                              eleTauMET = makeEleTauPair(src,"met","met.pt()"),#currently identical
                              eleTauMETPhi = makeEleTauPair(src,"metphi","met.phi()"),

                              #eleTauMVAMET = makeEleTauPair(src,"mvamet","mvamet"),#currently identical
                              #eleTauMVAMETPhi = makeEleTauPair(src,"mvametphi","mvametphi"),#currently identical
                              eleTauCovMat00 = makeEleTauPair(src,"mvacov00","covMatrix00"),
                              eleTauCovMat10 = makeEleTauPair(src,"mvacov10","covMatrix10"),
                              eleTauCovMat01 = makeEleTauPair(src,"mvacov01","covMatrix01"),
                              eleTauCovMat11 = makeEleTauPair(src,"mvacov11","covMatrix11"),

                              eleTauMT = makeEleTauPair(src,"mt12","mt12MET"),
                              eleTauMT1 = makeEleTauPair(src,"mt_1","mt1MET"),
                              eleTauMT2 = makeEleTauPair(src,"mt_2","mt2MET"),

                              eleTauTopGenPt = makeEleTauPair(src,"topGenPt","topGenPt"),
                              eleTauAntiTopGenPt = makeEleTauPair(src,"antiTopGenPt","antiTopGenPt"),

                              #BTAGS AND JETS
                              eleTauMJJReg = makeEleTauPair(src,"mJJReg","mJJReg"),
                              #eleTauMJJ = makeEleTauPair(src,"mjj","mJJ"),
                              eleTauJJPt = makeEleTauPair(src,"ptJJ","ptJJ"),
                              eleTauJJEta = makeEleTauPair(src,"etaJJ","etaJJ"),
                              eleTauJJPhi = makeEleTauPair(src,"phiJJ","phiJJ"),
                              eleTauJJEnergy = makeEleTauPair(src,"energyJJ","energyJJ"),
                              eleTauVBFDEta = makeEleTauPair(src,"vbfDEta","vbfDEta"),
                              eleTauVBFDPhi = makeEleTauPair(src,"vbfDPhi","vbfDPhi"),#EO
                              eleTauVBFMass = makeEleTauPair(src,"mjj","vbfMass"),
                              #eleTauVBFMass = makeEleTauPair(src,"vbfMass","vbfMass"),
                              muMuVBFJets20 = makeEleTauPair(src,"njetingap20","vbfNJetsGap20"),
                              muMuVBFJets30 = makeEleTauPair(src,"njetingap","vbfNJetsGap30"),

                              #ETAU ONLY

                              eleTauDZVZ = makeEleTauPair(src,"dz_vz",'abs(leg1.userFloat("vz")-leg2.userFloat("vz"))'),#EO #FIXME
                              eleTauDPhi = makeEleTauPair(src,"dPhi12",'dPhi12'),
                              eleTauDPhi1MET = makeEleTauPair(src,"dPhi1MET",'dPhi1MET'),
                              eleTauDPhi2MET = makeEleTauPair(src,"dPhi2MET",'dPhi2MET'),
                              eleTauPzeta = makeEleTauPair(src,"pZeta",'pZeta-1.5*pZetaVis'),#EO 
                              eleTauPZ = makeEleTauPair(src,"pzeta",'pZeta'),#EO
                              eleTauPZV = makeEleTauPair(src,"pzetavis",'pZetaVis'),#EO

                              #Ele IDs and Isolation
                              eleTauRelPFIsoDB03 = makeEleTauPair(src,"iso_1",'leg1.userFloat("dBRelIso03")'),
                              eleTauRel2PFIsoDB03 = makeEleTauPair(src,"iso_2",'leg2.userFloat("dBRelIso03")'),
                              eleTauRelPFIsoDB04 = makeEleTauPair(src,"lPFIsoDB04",'leg1.userFloat("dBRelIso")'),
                              eleTauDecayMode = makeEleTauPair(src,"tauDecayMode",'leg2.decayMode()'),
                              eleTauDecayFound = makeEleTauPair(src,"decayModeFinding_2",'leg2.tauID("decayModeFinding")'),
                              eleTauDecayFoundOld = makeEleTauPair(src,"decayModeFindingOldDMs_2",'leg2.tauID("decayModeFinding")'),
                              eleTauDecayFoundNew = makeEleTauPair(src,"decayModeFindingNewDMs_2",'leg2.tauID("decayModeFindingNewDMs")'),
                              eleTauProngs = makeEleTauPair(src,"tauProngs",'leg2.signalChargedHadrCands.size()'),#EO
                              #eleTauMuTriggerMatch = makeEleTauPair(src,"trigweight_1",'leg1.userFloat("hltEle32WP75GsfTrackIsoFilter")>0||leg1.userFloat("hltEle22WP75L1IsoEG20erTau20erGsfTrackIsoFilter")>0)'),
                              #eleTauTauTriggerMatch = makeEleTauPair(src,"trigweight_2",'leg2.userFloat("hltPFTau20TrackLooseIso")'),
                              eleTauHadMass = makeEleTauPair(src,"m_2",'leg2.mass()'),
                              eleTauByCombIsoDBRaw3 = makeEleTauPair(src,"byCombinedIsolationDeltaBetaCorrRaw3Hits_2",'leg2.tauID("byCombinedIsolationDeltaBetaCorrRaw3Hits")'),
                              eleTauByCharged = makeEleTauPair(src,"chargedIsoPtSum_2",'leg2.tauID("chargedIsoPtSum")'),
                              eleTauByNeutral = makeEleTauPair(src,"neutralIsoPtSum_2",'leg2.tauID("neutralIsoPtSum")'),
                              eleTauByPU = makeEleTauPair(src,"puCorrPtSum_2",'leg2.tauID("puCorrPtSum")'),
 
 
                              eleTauAgainstMuonLoose3 = makeEleTauPair(src,"againstMuonLoose3_2",'leg2.tauID("againstMuonLoose3")'),
                              eleTauAgainstMuonTight3 = makeEleTauPair(src,"againstMuonTight3_2",'leg2.tauID("againstMuonTight3")'),
                              eleTauMVANonTrig80 = makeEleTauPair(src,"id_e_mva_nt_loose_1",'leg1.userFloat("eleMVAIDnonTrig80")'),#CHECKME #rename
                              eleTauMVANonTrig90 = makeEleTauPair(src,"id_e_mva_nt_tight_1",'leg1.userFloat("eleMVAIDnonTrig90")'),#CHECKME #rename
                              eleTauCBIDVeto = makeEleTauPair(src,"id_e_cut_veto_1",'leg1.userFloat("CBIDVeto")'),#CHECKME #rename
                              eleTauCBIDLoose = makeEleTauPair(src,"id_e_cut_loose_1",'leg1.userFloat("CBIDLoose")'),#CHECKME #rename
                              eleTauCBIDMedium = makeEleTauPair(src,"id_e_cut_medium_1",'leg1.userFloat("CBIDMedium")'),#CHECKME #rename
                              eleTauCBIDTight = makeEleTauPair(src,"id_e_cut_tight_1",'leg1.userFloat("CBIDTight")'),#CHECKME #rename

                              eleTauEleDZ = makeEleTauPair(src,"dZ_1","leg1.userFloat('dZ')"),
                              eleTauTauDZ = makeEleTauPair(src,"dZ_2","leg2.userFloat('taudZ')"),
                              eleTauEleDXY = makeEleTauPair(src,"d0_1","leg1.userFloat('dXY')"),
                              eleTauTauDXY = makeEleTauPair(src,"d0_2","leg2.userFloat('taudXY')"),
                              eleTauConversion = makeEleTauPair(src,"eleConversion","leg1.userInt('eleConversion')"),
                              eleTauPassConversion = makeEleTauPair(src,"ePassConversion",'leg1.passConversionVeto()'),
                              eleTauAgainstEleMVA5raw = makeEleTauPair(src,"againstElectronMVA5raw",'leg2.tauID("againstElectronMVA5raw")'),
                              eleTauAgainstElectronTightMVA5 = makeEleTauPair(src,"tauElectronTightMVA5",'leg2.tauID("againstElectronTightMVA5")'),
                              eleTauAgainstElectronVLooseMVA5 = makeEleTauPair(src,"tauElectronVLooseMVA5",'leg2.tauID("againstElectronVLooseMVA5")'),

                              eleTauGenPt1 = makeEleTauPair(src,"genPt1",'p4Leg1gen().pt()'),
                              eleTauGenPt2 = makeEleTauPair(src,"genPt2",'p4Leg2gen().pt()'),
                              eleTauPdg1 = makeEleTauPair(src,"pdg1",'genPdg1()'),
                              eleTauPdg2 = makeEleTauPair(src,"pdg2",'genPdg2()'),
                              eleTauVisGenPt1 = makeEleTauPair(src,"genVisPt1",'p4VisLeg1gen().pt()'),
                              eleTauVisGenPt2 = makeEleTauPair(src,"genVisPt2",'p4VisLeg2gen().pt()'),
                              eleTauGenVisMass = makeEleTauPair(src,"genVisMass",'p4VisGen().M()'),
                              eleTauGenMassMatched = makeEleTauPair(src,"genFullMassMatched",'p4gen().M()'),
                              eleTauGenMass = makeEleTauPair(src,"fullGenMass",'genBosonMass()'),

                              eleTauGenMatch1 = makeEleTauPair(src,"gen_match_1",'genPdgId1()'),
                              eleTauGenMatch2 = makeEleTauPair(src,"gen_match_2",'genPdgId2()'),





                              eleTauJet1Muf = makeEleTauCSVPair(src,"J1Muf",'abs(eta())<2.4','muonEnergyFraction()',0),
                              eleTauJet2Muf = makeEleTauCSVPair(src,"J2Muf",'abs(eta())<2.4','muonEnergyFraction()',1),
                              eleTauJet1Nhf = makeEleTauCSVPair(src,"J1Nhf",'abs(eta())<2.4','neutralHadronEnergyFraction()',0),
                              eleTauJet2Nhf = makeEleTauCSVPair(src,"J2Nhf",'abs(eta())<2.4','neutralHadronEnergyFraction()',1),
                              eleTauJet1Phf = makeEleTauCSVPair(src,"J1Phf",'abs(eta())<2.4','photonEnergyFraction()',0),
                              eleTauJet2Phf = makeEleTauCSVPair(src,"J2Phf",'abs(eta())<2.4','photonEnergyFraction()',1),
                              eleTauJet1PtCSVSort = makeEleTauCSVPair(src,"J1PtCSVSort",'abs(eta())<2.4','pt()',0),
                              eleTauJet2PtCSVSort = makeEleTauCSVPair(src,"J2PtCSVSort",'abs(eta())<2.4','pt()',1),
                              eleTauJet1EtaCSVSort = makeEleTauCSVPair(src,"J1EtaCSVSort",'abs(eta())<2.4','eta()',0),
                              eleTauJet2EtaCSVSort = makeEleTauCSVPair(src,"J2EtaCSVSort",'abs(eta())<2.4','eta()',1),
                              eleTauJet1PhiCSVSort = makeEleTauCSVPair(src,"J1PhiCSVSort",'abs(eta())<2.4','phi()',0),
                              eleTauJet2PhiCSVSort = makeEleTauCSVPair(src,"J2PhiCSVSort",'abs(eta())<2.4','phi()',1),
                              eleTauJet1FlavourCSVSort = makeEleTauCSVPair(src,"J1FlavourCSVSort",'abs(eta())<2.4','partonFlavour()',0),
                              eleTauJet2FlavourCSVSort = makeEleTauCSVPair(src,"J2FlavourCSVSort",'abs(eta())<2.4','partonFlavour()',1),
                              eleTauJet1CSVCSVSort = makeEleTauCSVPair(src,"J1CSVbtagCSVSort",'abs(eta())<2.4','bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")',0),
                              eleTauJet2CSVCSVSort = makeEleTauCSVPair(src,"J2CSVbtagCSVSort",'abs(eta())<2.4','bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")',1),



                              eleTauJetsPt20nbtag = makeEleTauJetCountPair(src,"nbtag",'pt()>20&&abs(eta)<2.4&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.890'),
                              eleTauJetsPt30njets = makeEleTauJetCountPair(src,"njets",'pt()>30&&abs(eta)<4.7&&userFloat("idLoose")'),
                              eleTauJetsPt20njets = makeEleTauJetCountPair(src,"njetspt20",'pt()>20&&abs(eta)<4.7&&userFloat("idLoose")'),



                              eleTauJet1PtPtSort = makeEleTauPtPair(src,"jpt_1",'abs(eta())<4.7&&pt()>20&&userFloat("idLoose")','pt()',0),
                              eleTauJet2PtPtSort = makeEleTauPtPair(src,"jpt_2",'abs(eta())<4.7&&pt()>20&&userFloat("idLoose")','pt()',1),
                              eleTauJet1MVAPtSort = makeEleTauPtPair(src,"jmva_1",'abs(eta())<4.7&&pt()>20&&userFloat("idLoose")',"userFloat('pileupJetId:fullDiscriminant')",0),
                              eleTauJet2MVAPtSort = makeEleTauPtPair(src,"jmva_2",'abs(eta())<4.7&&pt()>20&&userFloat("idLoose")',"userFloat('pileupJetId:fullDiscriminant')",1),
                              eleTauJet1PFIDPtSort = makeEleTauPtPair(src,"jpfid_1",'abs(eta())<4.7&&pt()>20&&userFloat("idLoose")','userFloat("idLoose")',0),
                              eleTauJet2PFIDPtSort = makeEleTauPtPair(src,"jpfid_2",'abs(eta())<4.7&&pt()>20&&userFloat("idLoose")','userFloat("idLoose")',1),
                              eleTauJet1PUIDPtSort = makeEleTauPtPair(src,"jpuid_1",'abs(eta())<4.7&&pt()>20&&userFloat("idLoose")','userFloat("puID")',0),
                              eleTauJet2PUIDPtSort = makeEleTauPtPair(src,"jpuid_2",'abs(eta())<4.7&&pt()>20&&userFloat("idLoose")','userFloat("puID")',1),
                              eleTauJet1EtaPtSort = makeEleTauPtPair(src,"jeta_1",'abs(eta())<4.7&&pt>20&&userFloat("idLoose")','eta()',0),
                              eleTauJet2EtaPtSort = makeEleTauPtPair(src,"jeta_2",'abs(eta())<4.7&&pt>20&&userFloat("idLoose")','eta()',1),
                              eleTauJet1PhiPtSort = makeEleTauPtPair(src,"jphi_1",'abs(eta())<4.7&&pt>20&&userFloat("idLoose")','phi()',0),
                              eleTauJet2PhiPtSort = makeEleTauPtPair(src,"jphi_2",'abs(eta())<4.7&&pt>20&&userFloat("idLoose")','phi()',1),
                              eleTauJet1CSVPtSort = makeEleTauPtPair(src,"jcsv_1",'abs(eta())<4.7&&pt>20&&userFloat("idLoose")','bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")',0),
                              eleTauJet2CSVPtSort = makeEleTauPtPair(src,"jcsv_2",'abs(eta())<4.7&&pt>20&&userFloat("idLoose")','bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")',1),
                              eleTauJet1FlavourPtSort = makeEleTauPtPair(src,"J1Flavour",'abs(eta())<2.4&&pt>20&&userFloat("idLoose")','partonFlavour()',0),
                              eleTauJet2FlavourPtSort = makeEleTauPtPair(src,"J2Flavour",'abs(eta())<2.4&&pt>20&&userFloat("idLoose")','partonFlavour()',1),
                              #eleTauJet1MVASfPtSort = makeEleTauPtPair(src,"J1MVASf",'','userFloat("mvaSF")',0),
                              #eleTauJet2MVASfPtSort = makeEleTauPtPair(src,"J2MVASf",'','userFloat("mvaSF")',1),
                              eleTauJet1LooseIdPtSort = makeEleTauPtPair(src,"J1LooseId",'','userFloat("idLoose")',0),
                              eleTauJet2LooseIdPtSort = makeEleTauPtPair(src,"J2LooseId",'','userFloat("idLoose")',1),
                              eleTauJet1MedIdPtSort = makeEleTauPtPair(src,"J1MediumId",'','userFloat("idMedium")',0),
                              eleTauJet2MedIdPtSort = makeEleTauPtPair(src,"J2MediumId",'','userFloat("idMedium")',1),
                              eleTauJet1TightIdPtSort = makeEleTauPtPair(src,"J1TightId",'','userFloat("idTight")',0),
                              eleTauJet2TightIdPtSort = makeEleTauPtPair(src,"J2TightId",'','userFloat("idTight")',1),
 
                              eleTauJet1GenPtPtSort = makeEleTauPtPair(src,"J1GenPt",'','userFloat("genJetPt")',0),
                              eleTauJet2GenPtPtSort = makeEleTauPtPair(src,"J2GenPt",'','userFloat("genJetPt")',1),
                              eleTauJet1GenEtaPtSort = makeEleTauPtPair(src,"J1GenEta",'','userFloat("genJetEta")',0),
                              eleTauJet2GenEtaPtSort = makeEleTauPtPair(src,"J2GenEta",'','userFloat("genJetEta")',1),
                              eleTauJet1GenPhiPtSort = makeEleTauPtPair(src,"J1GenPhi",'','userFloat("genJetPhi")',0),
                              eleTauJet2GenPhiPtSort = makeEleTauPtPair(src,"J2GenPhi",'','userFloat("genJetPhi")',1),

                              eleTauJetsBTagCSVLPt20 = makeEleTauJetCountPair(src,"nJetsBTagCSVLPt20",'bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.605&&pt()>20&&abs(eta)<2.4'),
                              eleTauJetsBTagCSVLPt25 = makeEleTauJetCountPair(src,"nJetsBTagCSVLPt25",'bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.605&&pt()>25&&abs(eta)<2.4'),
                              eleTauJetsBTagCSVMPt20 = makeEleTauJetCountPair(src,"nJetsBTagCSVMPt20",'bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.890&&pt()>20&&abs(eta)<2.4'),
                              eleTauJetsBTagCSVMPt25 = makeEleTauJetCountPair(src,"nJetsBTagCSVMPt25",'bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.890&&pt()>25&&abs(eta)<2.4'),
                              eleTauJetsBTagCSVTPt20 = makeEleTauJetCountPair(src,"nJetsBTagCSVTPt20",'bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.97&&pt()>20&&abs(eta)<2.4'),
                              eleTauJetsBTagCSVTPt25 = makeEleTauJetCountPair(src,"nJetsBTagCSVTPt25",'bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.97&&pt()>25&&abs(eta)<2.4'),
                              eleTauJetsPt20 = makeEleTauJetCountPair(src,"nJetsPt20",'pt()>20'),
                              eleTauJetsPt20Loose = makeEleTauJetCountPair(src,"nJetsPt20Loose",'pt()>20&&userFloat("idLoose")'),
                              eleTauJetsPt20Medium = makeEleTauJetCountPair(src,"nJetsPt20Medium",'pt()>20&&userFloat("idMedium")'),
                              eleTauJetsPt20Tight = makeEleTauJetCountPair(src,"nJetsPt20Tight",'pt()>20&&userFloat("idTight")'),


                              eleTauFirstJetID53X = makeLTauGeneric("PATEleTauPairHighestPtJetVarFiller",src,"highestJetID53X","userFloat('pileupJetId:fullDiscriminant')"), 
                              eleTauFirstJetID53XPuPass = makeLTauGeneric("PATEleTauPairHighestPtJetVarFiller",src,"highestJetID53XPuPass","userFloat('puID')"), 
                              eleTauFirstJetFlavour = makeLTauGeneric("PATEleTauPairHighestPtJetVarFiller",src,"highestJetFlavour",'partonFlavour()'),
                              eleTauFirstJetShape = makeLTauGeneric("PATEleTauPairHighestPtJetVarFiller",src,"highestJetShape",'userFloat("ptRMS")'),
                              eleTauFirstJetCSV = makeLTauGeneric("PATEleTauPairHighestPtJetVarFiller",src,"highestJetBTagCSV",'bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")'),
                              eleTauFirstJetChMult = makeLTauGeneric("PATEleTauPairHighestPtJetVarFiller",src,"highestJetNCharged",'chargedMultiplicity()'),
                              eleTauFirstJetNeuMult = makeLTauGeneric("PATEleTauPairHighestPtJetVarFiller",src,"highestJetNNeutral",'photonMultiplicity()+neutralHadronMultiplicity()'),

                              eeDR = makeLTauGeneric("PATElePairFiller",srcLL,"diLeptonDR","dR12"),#FIXME

                              eleTauLHEProduct = cms.PSet(
                                  pluginType = cms.string("LHEProductFiller"),
                                  src        = cms.InputTag("source"),
                                  tag        = cms.string("LHEProduct"),
                              ),#WHAT IS THIS
                              eleTauLHEProduct2 = cms.PSet(
                                  pluginType = cms.string("LHEProductFiller"),
                                  src        = cms.InputTag("externalLHEProducer"),
                                  tag        = cms.string("LHEProduct2"),
                              ),#WHAT IS THIS
                              eleTauEmbedPtWeight = cms.PSet(
                                  pluginType = cms.string("GenFilterInfoWeightFiller"),
                                  src        = cms.InputTag("generator"),
                                  tag        = cms.string("aMCNLO_weight"),
                              ),
                              higgsPt = cms.PSet(
                                  pluginType = cms.string("PATGenParticleFiller"),
                                  src        = cms.InputTag("genDaughters"),
                                  tag        = cms.string("higgsPt"),
                                  method     = cms.string('pt()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauEmbedPt = cms.PSet(
                                  pluginType = cms.string("PATGenParticleFiller"),
                                  src        = cms.InputTag("genDaughters"),
                                  tag        = cms.string("embeddedPt"),#CHECKME
                                  method     = cms.string("pt"),
                                  leadingOnly=cms.untracked.bool(False)
                              ),
                              eleTauEmbedEta = cms.PSet(
                                  pluginType = cms.string("PATGenParticleFiller"),
                                  src        = cms.InputTag("genDaughters"),
                                  tag        = cms.string("embeddedEta"),
                                  method     = cms.string("eta"),
                                  leadingOnly=cms.untracked.bool(False)
                              )
   )

   setattr(process, name, eventTree)
   p = cms.Path(getattr(process,name))
   setattr(process, name+'Path', p)


