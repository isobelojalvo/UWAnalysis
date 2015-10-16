import FWCore.ParameterSet.Config as cms

from UWAnalysis.Configuration.tools.analysisToolsZTauTauXSec import TriggerPaths



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


def addMuTauEventTree(process,name,src = 'muTausSorted', srcLL = 'diMuonsOSSorted', srcU='TightMuons', srcE='TightElectrons'):
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
                              PVsSync = cms.PSet(
                                  pluginType = cms.string("VertexSizeFiller"),
                                  src        = cms.InputTag("offlineSlimmedPrimaryVertices"),
                                  #src        = cms.InputTag("primaryVertexFilter"),
                                  tag        = cms.string("npv")
                              ),#FILLED
                              PVs = cms.PSet(
                                  pluginType = cms.string("VertexSizeFiller"),
                                  src        = cms.InputTag("offlineSlimmedPrimaryVertices"),
                                  #src        = cms.InputTag("primaryVertexFilter"),
                                  tag        = cms.string("vertices")
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

                              muTauPt = makeMuTauPair(src,"pt","pt"),#FILLED
                              muTauHT = makeMuTauPair(src,"ht","ht"),#FILLED
                              muTauMass = makeMuTauPair(src,"m_vis","mass"),#FILLED
                              muTauSVPt = makeMuTauPair(src,"pt_sv","svPt"),#FIXME
                              muTauSVMass = makeMuTauPair(src,"m_sv","svMass"),#FILLED

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

			      muTauMassLL = makeLTauGeneric("PATMuPairFiller",srcLL,"LLmass","mass"),
                              muTauPt1LL =  makeLTauGeneric("PATMuPairFiller",srcLL,"LLpt_1","leg1.pt"), #FILLED
                              muTauPt2LL =  makeLTauGeneric("PATMuPairFiller",srcLL,"LLpt_2","leg2.pt"), #FILLED
                              muTauEta1LL = makeLTauGeneric("PATMuPairFiller",srcLL,"LLeta_1","leg1.eta"),#FILLED
                              muTauEta2LL = makeLTauGeneric("PATMuPairFiller",srcLL,"LLeta_2","leg2.eta"),#FILLED
                              muTauPhi1LL = makeLTauGeneric("PATMuPairFiller",srcLL,"LLphi_1","leg1.phi"),#FILLED
                              muTauPhi2LL = makeLTauGeneric("PATMuPairFiller",srcLL,"LLphi_2","leg2.phi"),#FILLED

                              muTauMET = makeMuTauPair(src,"met","met.pt()"),#FILLED
                              muTauMETCal = makeMuTauPair(src,"metCal","calibratedMET.pt()"),#FILLED
                              #muTauMETPhi = makeMuTauPair(src,"metphi","metPhi"),#FILLED
                              muTauMETPhi = makeMuTauPair(src,"metphi","met.phi()"),#FILLED
                              muTauCovMat00 = makeMuTauPair(src,"covMatrix00","covMatrix00"),#FIXME
                              muTauCovMat10 = makeMuTauPair(src,"covMatrix10","covMatrix10"),#FIXME
                              muTauCovMat01 = makeMuTauPair(src,"covMatrix01","covMatrix01"),#FIXME
                              muTauCovMat11 = makeMuTauPair(src,"covMatrix11","covMatrix11"),#FIXME

                              muTauMT = makeMuTauPair(src,"mt12","mt12MET"),#FILLED
                              muTauMT1 = makeMuTauPair(src,"mt_1","mt1MET"),#FILLED
                              muTauMT2 = makeMuTauPair(src,"mt_2","mt2MET"),#FILLED
                              
		              muTauTopGenPt = makeMuTauPair(src,"topGenPt","topGenPt"),#FIXME
		              muTauAntiTopGenPt = makeMuTauPair(src,"antiTopGenPt","antiTopGenPt"),#FIXME

                              #BTAGS AND JETS
                              muTauMJJReg = makeMuTauPair(src,"mJJReg","mJJReg"),#FIXME
                              muTauMJJ = makeMuTauPair(src,"mJJ","mJJ"),#FILLED
                              muTauJJPt = makeMuTauPair(src,"ptJJ","ptJJ"),
                              muTauJJEta = makeMuTauPair(src,"etaJJ","etaJJ"),
                              muTauJJPhi = makeMuTauPair(src,"phiJJ","phiJJ"),
                              muTauJJEnergy = makeMuTauPair(src,"energyJJ","energyJJ"),
                              muTauVBFDEta = makeMuTauPair(src,"jdeta","vbfDEta"),
                              muTauVBFMass = makeMuTauPair(src,"mjj","vbfMass"),#vbfMass
                              muTauVBFJets20 = makeMuTauPair(src,"njetigap20","vbfNJetsGap20"),
                              muTauVBFJets30 = makeMuTauPair(src,"njetingap","vbfNJetsGap30"),

                              #Muon IDs and Isolation
                              muTauRelPFIsoDB03 = makeMuTauPair(src,"iso_1",'leg1.userFloat("dBRelIso03")'),
                              muTauRel2PFIsoDB03 = makeMuTauPair(src,"iso_2",'leg2.userFloat("dBRelIso03")'),
                              muTauRelPFIsoDB04 = makeMuTauPair(src,"iso04_1",'leg1.userFloat("dBRelIso")'),

                              muTauLooseID = makeMuTauPair(src,"id_m_loose_1",'leg1.isLooseMuon()'),
                              muTauMediumID = makeMuTauPair(src,"id_m_medium_1",'leg1.isMediumMuon()'),
                              muTauUserMediumID = makeMuTauPair(src,"muMediumId",'leg1.userInt("mediumID")'),
                              muTauDecayMode = makeMuTauPair(src,"tauDecayMode",'leg2.decayMode()'),
                              muTauDecayFound = makeMuTauPair(src,"decayModeFinding_2",'leg2.tauID("decayModeFinding")'),
                              muTauDecayFoundOld = makeMuTauPair(src,"decayModeFindingOldDMs_2",'leg2.tauID("decayModeFinding")'),
                              muTauDecayFoundNew = makeMuTauPair(src,"decayModeFindingNewDMs_2",'leg2.tauID("decayModeFindingNewDMs")'),
                              muTauProngs = makeMuTauPair(src,"tauProngs",'leg2.signalChargedHadrCands.size()'),#see Decay Modes
                              #muTauTriggerMatch = makeMuTauPair(src,"triggered",'(leg1.userFloat("hltL3crIsoL1sMu16erTauJet20erL1f0L2f10QL3f17QL3trkIsoFiltered0p09")>0&&leg2.userFloat("hltPFTau20TrackLooseIsoAgainstMuon")>0)||(leg1.userFloat("hltL3crIsoL1sMu20Eta2p1L1f0L2f10QL3f24QL3trkIsoFiltered0p09")>0&&leg1.pt()>25)'),
                              muTauCrossTriggerMatch = makeMuTauPair(src,"crossTrigger",'leg1.userFloat("hltL3crIsoL1sMu16erTauJet20erL1f0L2f10QL3f17QL3trkIsoFiltered0p09")+leg2.userFloat("hltPFTau20TrackLooseIsoAgainstMuon")'),
                              muTauCrossTriggerMatch2015B = makeMuTauPair(src,"crossTrigger_50ns",'leg1.userFloat("hltL3crIsoL1sMu16erTauJet20erL1f0L2f10QL3f17QL3trkIsoFiltered0p09")+leg2.userFloat("hltPFTau20TrackLooseIsoAgainstMuon")'),
                              muTauCrossTriggerMatch2015D = makeMuTauPair(src,"crossTrigger_25ns",'leg1.userFloat("hltL3crIsoL1sMu16erTauJet20erL1f0L2f10QL3f17QL3trkIsoFiltered0p09")+leg2.userFloat("hltPFTau20TrackLooseIsoAgainstMuon")'),
                              muTauMuTriggerMatch = makeMuTauPair(src,"lTrigger",'leg1.userFloat("hltL3crIsoL1sMu20Eta2p1L1f0L2f10QL3f24QL3trkIsoFiltered0p09")'),
                              muTauMuTriggerMatch2015B = makeMuTauPair(src,"lTrigger_50ns",'leg1.userFloat("hltL3crIsoL1sMu20Eta2p1L1f0L2f10QL3f24QL3trkIsoFiltered0p09")'),
                              muTauMuTriggerMatch2015D = makeMuTauPair(src,"lTrigger_25ns",'leg1.userFloat("hltL3crIsoL1sMu20L1f0L2f10QL3f22QL3trkIsoFiltered0p09")'),
                              muTauMuTriggerMatch2015D_v2 = makeMuTauPair(src,"lTrigger_25ns_v2",'leg1.userFloat("hltL3crIsoL1sMu16L1f0L2f10QL3f18QL3trkIsoFiltered0p09")'),
                              #muTauMuTriggerMatch = makeMuTauPair(src,"lTrigger",'leg1.userFloat("hltL3crIsoL1sMu20Eta2p1L1f0L2f10QL3f24QL3trkIsoFiltered0p09")>0&&leg1.pt>25'),
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
                              muTauByCombIsoDBRaw3Name = makeMuTauPair(src,"tauIso",'leg2.tauID("byCombinedIsolationDeltaBetaCorrRaw3Hits")'),
                              muTauByCombIsoLoose = makeMuTauPair(src,"tauIsoLoose",'leg2.tauID("byLooseCombinedIsolationDeltaBetaCorr3Hits")'),
                              muTauByCombIsoMedium = makeMuTauPair(src,"tauIsoMedium",'leg2.tauID("byMediumCombinedIsolationDeltaBetaCorr3Hits")'),
                              muTauByCombIsoTight = makeMuTauPair(src,"tauIsoTight",'leg2.tauID("byTightCombinedIsolationDeltaBetaCorr3Hits")'),
                              muTauByCharged = makeMuTauPair(src,"chargedIsoPtSum_2",'leg2.tauID("chargedIsoPtSum")'),
                              muTauByNeutral = makeMuTauPair(src,"neutralIsoPtSum_2",'leg2.tauID("neutralIsoPtSum")'),
                              muTauByPU = makeMuTauPair(src,"puCorrPtSum_2",'leg2.tauID("puCorrPtSum")'), 
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
                              muTauGenIsPrompt = makeMuTauPair(src,"isPrompt",'isPrompt()'),
                              muTauGenIsPromptFS = makeMuTauPair(src,"isPromptFS",'isPromptFS()'),
                              muTauGenIsDirectTauDecay = makeMuTauPair(src,"isTauDecay",'isDirectPromptTauDecayProduct()'),
                              muTauGenIsDirectTauDecayFS = makeMuTauPair(src,"isTauDecayFS",'isDirectPromptTauDecayProductFS()'),

			      #Jets
                              muTauJetsPt20nbtag = makeMuTauJetCountPair(src,"nbtag",'pt()>20&&abs(eta)<2.4&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.814'),
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
                              muTauJet1CSVPtSort = makeMuTauPtPair(src,"jcsv_1",'abs(eta())<2.4&&pt()>20','bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")',0),
                              muTauJet2CSVPtSort = makeMuTauPtPair(src,"jcsv_2",'abs(eta())<2.4&&pt()>20','bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")',1),
                              muTauJet1MedIdPtSort = makeMuTauPtPair(src,"jmedID_1",'','userFloat("idMedium")',0),
                              muTauJet2MedIdPtSort = makeMuTauPtPair(src,"jmedID_2",'','userFloat("idMedium")',1),
                              muTauJet1TightIdPtSort = makeMuTauPtPair(src,"jtightID_1",'','userFloat("idTight")',0),
                              muTauJet2TightIdPtSort = makeMuTauPtPair(src,"jtightID_2",'','userFloat("idTight")',1),

                              muTauJetsPt20TagMatch = makeMuTauJetCountPair(src,"nTaggableJetsPt20Matched",'pt()>20&&abs(eta)<2.4&&abs(partonFlavour)==5'),
                              muTauJetsPt20TagNoMatch = makeMuTauJetCountPair(src,"nTaggableJetsPt20NotMatched",'pt()>30&&abs(eta)<2.4&&abs(partonFlavour)!=5'),
                              muTauFirstJetShape = makeLTauGeneric("PATMuTauPairHighestPtJetVarFiller",src,"highestJetShape",'userFloat("ptRMS")'),
                              muTauFirstJetCSV = makeLTauGeneric("PATMuTauPairHighestPtJetVarFiller",src,"highestJetBTagCSV",'bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")'),

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
                                  tag        = cms.string("aMCNLO_weight"),
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
def addEleTauEventTree(process,name,src='eleTausSorted',srcLL='diElectronsOS', srcU='TightMuons', srcE='TightElectrons'):
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
                              ),#FIXME
                              PVsSync = cms.PSet(
                                  pluginType = cms.string("VertexSizeFiller"),
                                  src        = cms.InputTag("offlineSlimmedPrimaryVertices"),
                                  #src        = cms.InputTag("primaryVertexFilter"),
                                  tag        = cms.string("npv")
                              ),
                              PVs = cms.PSet(
                                  pluginType = cms.string("VertexSizeFiller"),
                                  src        = cms.InputTag("offlineSlimmedPrimaryVertices"),
                                  #src        = cms.InputTag("primaryVertexFilter"),
                                  tag        = cms.string("vertices")
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


                              #eleTauMETUnc = makeEleTauPair(src,"metUnc","met.pt()"),#curretnly identical
                              #eleTauMET = makeEleTauPair(src,"met","calibratedMET.pt()"),#currently identical
                              eleTauMET = makeEleTauPair(src,"met","met.pt()"),#currently identical
                              #eleTauMETPhi = makeEleTauPair(src,"metphi","metPhi"),
                              eleTauMETPhi = makeEleTauPair(src,"metphi","met.phi()"),
                              eleTauCovMat00 = makeEleTauPair(src,"covMatrix00","covMatrix00"),
                              eleTauCovMat10 = makeEleTauPair(src,"covMatrix10","covMatrix10"),
                              eleTauCovMat01 = makeEleTauPair(src,"covMatrix01","covMatrix01"),
                              eleTauCovMat11 = makeEleTauPair(src,"covMatrix11","covMatrix11"),

                              eleTauMT = makeEleTauPair(src,"mt12","mt12MET"),
                              eleTauMT1 = makeEleTauPair(src,"mt_1","mt1MET"),
                              eleTauMT2 = makeEleTauPair(src,"mt_2","mt2MET"),

                              eleTauTopGenPt = makeEleTauPair(src,"topGenPt","topGenPt"),
                              eleTauAntiTopGenPt = makeEleTauPair(src,"antiTopGenPt","antiTopGenPt"),

                              #BTAGS AND JETS
                              eleTauMJJReg = makeEleTauPair(src,"mJJReg","mJJReg"),
                              eleTauMJJ = makeEleTauPair(src,"mJJ","mJJ"),
                              eleTauJJPt = makeEleTauPair(src,"ptJJ","ptJJ"),
                              eleTauJJEta = makeEleTauPair(src,"etaJJ","etaJJ"),
                              eleTauJJPhi = makeEleTauPair(src,"phiJJ","phiJJ"),
                              eleTauJJEnergy = makeEleTauPair(src,"energyJJ","energyJJ"),
                              eleTauVBFDEta = makeEleTauPair(src,"vbfDEta","vbfDEta"),
                              eleTauVBFDPhi = makeEleTauPair(src,"vbfDPhi","vbfDPhi"),
                              eleTauVBFMass = makeEleTauPair(src,"mjj","vbfMass"), #vbfMass
                              eleTauVBFJets20 = makeEleTauPair(src,"njetingap20","vbfNJetsGap20"),
                              eleTauVBFJets30 = makeEleTauPair(src,"njetingap","vbfNJetsGap30"),

                              eleTauDZVZ = makeEleTauPair(src,"dz_vz",'abs(leg1.userFloat("vz")-leg2.userFloat("vz"))'),#EO #FIXME
                              eleTauDPhi = makeEleTauPair(src,"dPhi12",'dPhi12'),
                              eleTauDPhi1MET = makeEleTauPair(src,"dPhi1MET",'dPhi1MET'),
                              eleTauDPhi2MET = makeEleTauPair(src,"dPhi2MET",'dPhi2MET'),
                              eleTauPzeta = makeEleTauPair(src,"pZeta",'pZeta-1.5*pZetaVis'),#EO 
                              eleTauPZ = makeEleTauPair(src,"pzeta",'pZeta'),#EO
                              eleTauPZV = makeEleTauPair(src,"pzetavis",'pZetaVis'),#EO

			      #Trigger
                              eleTauCrossTriggerMatch = makeEleTauPair(src,"crossTrigger",'leg2.userFloat("hltPFTau20TrackLooseIso")+leg1.userFloat("hltEle22WP75L1IsoEG20erTau20erGsfTrackIsoFilter")'),
                              eleTauCrossTriggerMatch2015B = makeEleTauPair(src,"crossTrigger_50ns",'leg2.userFloat("hltPFTau20TrackLooseIso")+leg1.userFloat("hltSingleEle22WPLooseGsfTrackIsoFilter")'),
                              eleTauCrossTriggerMatch2015D = makeEleTauPair(src,"crossTrigger_25ns",'leg2.userFloat("hltPFTau20TrackLooseIso")+leg1.userFloat("hltEle22WPLooseL1IsoEG20erTau20erGsfTrackIsoFilter")'),
                              eleTauEleTriggerMatch = makeEleTauPair(src,"lTrigger",'leg1.userFloat("hltEle32WP75GsfTrackIsoFilter")'),
                              eleTauEleTriggerMatch2015B = makeEleTauPair(src,"lTrigger_50ns",'leg1.userFloat("hltEle32WPTightGsfTrackIsoFilter")'),
                              eleTauEleTriggerMatch2015C = makeEleTauPair(src,"lTrigger_25ns",'leg1.userFloat("hltEle32WPTightGsfTrackIsoFilter")'),
                              eleTauEleTriggerMatch2015D = makeEleTauPair(src,"lTrigger_25ns_v2",'leg1.userFloat("hltEle23WPLooseGsfTrackIsoFilter")'),
                              eleTauEleTriggerMatch2015D_v2 = makeEleTauPair(src,"lTrigger_25ns_v3",'leg1.userFloat("hltSingleEle22WPTightGsfTrackIsoFilter")'),
                              eleTauEleTriggerMatch2015D_v3 = makeEleTauPair(src,"lTrigger_25ns_v4",'leg1.userFloat("hltSingleEle22WPLooseGsfTrackIsoFilter")'),


                              #Ele IDs and Isolation
                              eleTauRelPFIsoDB03 = makeEleTauPair(src,"iso_1",'leg1.userFloat("dBRelIso03")'),
                              eleTauRel2PFIsoDB03 = makeEleTauPair(src,"iso_2",'leg2.userFloat("dBRelIso03")'),
                              eleTauRelPFIsoDB04 = makeEleTauPair(src,"iso04_1",'leg1.userFloat("dBRelIso")'),
                              eleTauEleIsoChHadIso = makeEleTauPair(src,"eleIsoChHadIso",'leg1.userFloat("eleIsoChHadIso")'),
                              eleTauEleIsoPUChHadIso = makeEleTauPair(src,"eleIsoPUChHadIso",'leg1.userFloat("eleIsoPUChHadIso")'),
                              eleTauEleIsoPhotonIso = makeEleTauPair(src,"eleIsoPhotonIso",'leg1.userFloat("eleIsoPhotonIso")'),
                              eleTauEleIsoNeuHadIso = makeEleTauPair(src,"eleIsoNeuHadIso",'leg1.userFloat("eleIsoNeuHadIso")'),
                              eleTauEleIsoSumChHadPt = makeEleTauPair(src,"eleIsoSumChHadPt",'leg1.userFloat("eleIsoSumChHadPt")'),
                              eleTauEleIsoSumNeuHadPt = makeEleTauPair(src,"eleIsoSumNeuHadPt",'leg1.userFloat("eleIsoSumNeuHadPt")'),
                              eleTauEleIsoSumPhoEt = makeEleTauPair(src,"eleIsoSumPhoEt",'leg1.userFloat("eleIsoSumPhoEt")'),
                              eleTauEleIsoSumPUPt = makeEleTauPair(src,"eleIsoSumPUPt",'leg1.userFloat("eleIsoSumPUPt")'),

                              eleTauDecayMode = makeEleTauPair(src,"tauDecayMode",'leg2.decayMode()'),
                              eleTauDecayFound = makeEleTauPair(src,"decayModeFinding_2",'leg2.tauID("decayModeFinding")'),
                              eleTauDecayFoundOld = makeEleTauPair(src,"decayModeFindingOldDMs_2",'leg2.tauID("decayModeFinding")'),
                              eleTauDecayFoundNew = makeEleTauPair(src,"decayModeFindingNewDMs_2",'leg2.tauID("decayModeFindingNewDMs")'),
                              eleTauProngs = makeEleTauPair(src,"tauProngs",'leg2.signalChargedHadrCands.size()'),#see Decay Modes
                              eleTauHadMass = makeEleTauPair(src,"m_2",'leg2.mass()'),

                              eleTauByCombIsoLoose = makeEleTauPair(src,"tauIsoLoose",'leg2.tauID("byLooseCombinedIsolationDeltaBetaCorr3Hits")'),
                              eleTauByCombIsoMedium = makeEleTauPair(src,"tauIsoMedium",'leg2.tauID("byMediumCombinedIsolationDeltaBetaCorr3Hits")'),
                              eleTauByCombIsoTight = makeEleTauPair(src,"tauIsoTight",'leg2.tauID("byTightCombinedIsolationDeltaBetaCorr3Hits")'),
 
                              eleTauByCombIsoDBRaw3 = makeEleTauPair(src,"byCombinedIsolationDeltaBetaCorrRaw3Hits_2",'leg2.tauID("byCombinedIsolationDeltaBetaCorrRaw3Hits")'),
                              eleTauByCombIsoDBRaw3Iso = makeEleTauPair(src,"tauIso",'leg2.tauID("byCombinedIsolationDeltaBetaCorrRaw3Hits")'),
                              eleTauByCharged = makeEleTauPair(src,"chargedIsoPtSum_2",'leg2.tauID("chargedIsoPtSum")'),
                              eleTauByNeutral = makeEleTauPair(src,"neutralIsoPtSum_2",'leg2.tauID("neutralIsoPtSum")'),
                              eleTauByPU = makeEleTauPair(src,"puCorrPtSum_2",'leg2.tauID("puCorrPtSum")'), 
                              eleTauAgainstMuonLoose3 = makeEleTauPair(src,"againstMuonLoose3_2",'leg2.tauID("againstMuonLoose3")'),
                              eleTauAgainstMuonTight3 = makeEleTauPair(src,"againstMuonTight3_2",'leg2.tauID("againstMuonTight3")'),
                              eleTauMVANonTrig80 = makeEleTauPair(src,"id_e_mva_nt_80_1",'leg1.userFloat("eleMVAIDnonTrig80")'),#CHECKME #rename
                              eleTauMVANonTrig90 = makeEleTauPair(src,"id_e_mva_nt_90_1",'leg1.userFloat("eleMVAIDnonTrig90")'),#CHECKME #rename
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
                              eleTauAgainstElectronTightMVA52 = makeEleTauPair(src,"againstElectronTightMVA5",'leg2.tauID("againstElectronTightMVA5")'),
                              eleTauAgainstElectronMediumMVA5 = makeEleTauPair(src,"againstElectronMediumMVA5",'leg2.tauID("againstElectronMediumMVA5")'),
                              eleTauAgainstElectronVLooseMVA5 = makeEleTauPair(src,"againstElectronVLooseMVA5",'leg2.tauID("againstElectronVLooseMVA5")'),
                              eleTauAgainstElectronLooseMVA5 = makeEleTauPair(src,"againstElectronLooseMVA5",'leg2.tauID("againstElectronLooseMVA5")'),

                              eleTauGenPt1 = makeEleTauPair(src,"genPt1",'p4Leg1gen().pt()'),
                              eleTauGenPt2 = makeEleTauPair(src,"genPt2",'p4Leg2gen().pt()'),
                              eleTauPdg1 = makeEleTauPair(src,"pdg1",'genPdg1()'),
                              eleTauPdg2 = makeEleTauPair(src,"pdg2",'genPdg2()'),
                              eleTauVisGenPt1 = makeEleTauPair(src,"genVisPt1",'p4VisLeg1gen().pt()'),
                              eleTauVisGenPt2 = makeEleTauPair(src,"genVisPt2",'p4VisLeg2gen().pt()'),
                              eleTauGenVisMass = makeEleTauPair(src,"genVisMass",'p4VisGen().M()'),
                              eleTauGenMassMatched = makeEleTauPair(src,"genFullMassMatched",'p4gen().M()'),
                              eleTauGenMass = makeEleTauPair(src,"fullGenMass",'genBosonMass()'),
                              eleTauGenIsPrompt = makeEleTauPair(src,"isPrompt",'isPrompt()'),
                              eleTauGenIsPromptFS = makeEleTauPair(src,"isPromptFS",'isPromptFS()'),
                              eleTauGenIsDirectTauDecay = makeEleTauPair(src,"isTauDecay",'isDirectPromptTauDecayProduct()'),
                              eleTauGenIsDirectTauDecayFS = makeEleTauPair(src,"isTauDecayFS",'isDirectPromptTauDecayProductFS()'),


			      #Jets
                              eleTauJetsPt20nbtag = makeEleTauJetCountPair(src,"nbtag",'pt()>20&&abs(eta)<2.4&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.814'),
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
                              eleTauJet1CSVPtSort = makeEleTauPtPair(src,"jcsv_1",'abs(eta())<4.7&&pt()>20','bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")',0),
                              eleTauJet2CSVPtSort = makeEleTauPtPair(src,"jcsv_2",'abs(eta())<4.7&&pt()>20','bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")',1),
                              eleTauJet1MedIdPtSort = makeEleTauPtPair(src,"jmedID_1",'abs(eta())<4.7','userFloat("idMedium")',0),
                              eleTauJet2MedIdPtSort = makeEleTauPtPair(src,"jmedID_2",'abs(eta())<4.7','userFloat("idMedium")',1),
                              eleTauJet1TightIdPtSort = makeEleTauPtPair(src,"jtightID_1",'abs(eta())<4.7','userFloat("idTight")',0),
                              eleTauJet2TightIdPtSort = makeEleTauPtPair(src,"jtightID_2",'abs(eta())<4.7','userFloat("idTight")',1),

                              eleTauJetsPt20TagMatch = makeMuTauJetCountPair(src,"nTaggableJetsPt20Matched",'pt()>20&&abs(eta)<2.4&&abs(partonFlavour)==5'),
                              eleTauJetsPt20TagNoMatch = makeMuTauJetCountPair(src,"nTaggableJetsPt20NotMatched",'pt()>30&&abs(eta)<2.4&&abs(partonFlavour)!=5'),
                              eleTauFirstJetShape = makeLTauGeneric("PATEleTauPairHighestPtJetVarFiller",src,"highestJetShape",'userFloat("ptRMS")'),
                              eleTauFirstJetCSV = makeLTauGeneric("PATEleTauPairHighestPtJetVarFiller",src,"highestJetBTagCSV",'bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")'),

                              eeDR = makeLTauGeneric("PATElePairFiller",srcLL,"diLeptonDR","dR12"),#FIXME

                              eleTauMassLL =  makeLTauGeneric("PATElePairFiller",srcLL,"LLmass","mass"), #FILLED
                              eleTauPt1LL =  makeLTauGeneric("PATElePairFiller",srcLL,"LLpt_1","leg1.pt()"), #FILLED
                              eleTauPt2LL =  makeLTauGeneric("PATElePairFiller",srcLL,"LLpt_2","leg2.pt()"), #FILLED
                              eleTauEta1LL = makeLTauGeneric("PATElePairFiller",srcLL,"LLeta_1","leg1.eta()"),
                              eleTauEta2LL = makeLTauGeneric("PATElePairFiller",srcLL,"LLeta_2","leg2.eta()"),
                              eleTauPhi1LL = makeLTauGeneric("PATElePairFiller",srcLL,"LLphi_1","leg1.phi()"),
                              eleTauPhi2LL = makeLTauGeneric("PATElePairFiller",srcLL,"LLphi_2","leg2.phi()"),



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


