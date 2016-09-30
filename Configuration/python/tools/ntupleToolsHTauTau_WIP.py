import FWCore.ParameterSet.Config as cms

from UWAnalysis.Configuration.tools.analysisToolsHTauTau_WIP import TriggerPaths



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

def makeCollSizeOS(srcName,size, tagName):
  PSet = cms.PSet(
        pluginType = cms.string("OSCollectionSizeFiller"),
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


##start diTaus


def makeDiTauPair(sourceDiTaus,tagName,methodName,leadingOnly=True):
   PSet = cms.PSet(
         pluginType  = cms.string("PATDiTauPairFiller"),
         src         = cms.InputTag(sourceDiTaus),
         tag         = cms.string(tagName),
         method      = cms.string(methodName),
         leadingOnly = cms.untracked.bool(leadingOnly)
   )
   return PSet

def makeDiTauCSVPair(sourceDiTaus,tagName,cutName,methodName,rank):
   PSet = cms.PSet(
         pluginType  = cms.string("PATDiTauPairCSVJetVarFiller"),
         src         = cms.InputTag(sourceDiTaus),
         tag         = cms.string(tagName),
         cut         = cms.string(cutName),
         method      = cms.string(methodName),
         rank = cms.untracked.double(rank)
   )
   return PSet

def makeDiTauPtNoPair(sourceDiTaus,tagName,cutName,methodName,rank):
   PSet = cms.PSet(
         pluginType  = cms.string("PATDiTauPairPtJetVarFiller"),
         src         = cms.InputTag(sourceDiTaus),
         tag         = cms.string(tagName),
         cut         = cms.string(cutName),
         method      = cms.string(methodName),
         rank = cms.untracked.double(rank)
   )
   return PSet

def makeDiTauPtPair(sourceDiTaus,tagName,cutName,methodName,rank):
   PSet = cms.PSet(
         pluginType  = cms.string("PATDiTauPairPtJetPairVarFiller"),
         src         = cms.InputTag(sourceDiTaus),
         tag         = cms.string(tagName),
         cut         = cms.string(cutName),
         method      = cms.string(methodName),
         rank = cms.untracked.double(rank)
   )
   return PSet

def makeDiTauEventWeight(sourceDiTaus):
   PSet = cms.PSet(
         pluginType  = cms.string("PATDiTauPairWeightFiller"),
         src         = cms.InputTag(sourceDiTaus),
         tag         = cms.string("Mu"),
         isMuon      = cms.bool(True)
   )
   return PSet

def makeDiTauGenMatch(sourceDiTaus):
   PSet = cms.PSet(
         pluginType  = cms.string("PATDiTauPairGenMCMatching"),
         src         = cms.InputTag(sourceDiTaus)
   )
   return PSet

def makeDiTauNBTag(sourceDiTaus):
   PSet = cms.PSet(
         pluginType  = cms.string("PATDiTauPairNBTagFiller"),
         src         = cms.InputTag(sourceDiTaus),
         doEffMap      = cms.bool(True)
   )
   return PSet

def makeDiTauEffCSV(sourceDiTaus):
   PSet = cms.PSet(
         pluginType  = cms.string("PATDiTauPairEffCSVFiller"),
         src         = cms.InputTag(sourceDiTaus)
   )
   return PSet

def makeDiTauCSVShape(sourceDiTaus):
   PSet = cms.PSet(
         pluginType  = cms.string("PATDiTauPairCSVReweightFiller"),
         src         = cms.InputTag(sourceDiTaus)
   )
   return PSet


def makeDiTauJetCountPair(sourceDiTaus,tagName,methodName,leadingOnly=True):
   PSet = cms.PSet(
         pluginType  = cms.string("PATDiTauPairJetCountFiller"),
         src         = cms.InputTag(sourceDiTaus),
         tag         = cms.string(tagName),
         method      = cms.string(methodName),
         leadingOnly = cms.untracked.bool(leadingOnly)
   )
   return PSet

###finish ditaus
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

def makeMuTauMET(sourceDiTaus, sourceMET, prefix):
   PSet = cms.PSet(
         pluginType  = cms.string("PATMuTauPairMETFiller"),
         src         = cms.InputTag(sourceDiTaus),
         met         = cms.InputTag(sourceMET),
         tag         = cms.string(prefix)
   )
   return PSet

def makeMuTauEventWeight(sourceDiTaus):
   PSet = cms.PSet(
         pluginType  = cms.string("PATMuTauPairWeightFiller"),
         src         = cms.InputTag(sourceDiTaus),
         tag         = cms.string("Mu"),
         isMuon      = cms.bool(True)
   )
   return PSet

def makeMuTauEventWeightTmp(sourceDiTaus):
   PSet = cms.PSet(
         pluginType  = cms.string("PATMuTauPairWeightFillerTmp"),
         src         = cms.InputTag(sourceDiTaus),
         tag         = cms.string("MyMu"),
         isMuon      = cms.bool(True)
   )
   return PSet
def makeMuTauGenMatch(sourceDiTaus):
   PSet = cms.PSet(
         pluginType  = cms.string("PATMuTauPairGenMCMatching"),
         src         = cms.InputTag(sourceDiTaus)
   )
   return PSet
def makeMuTauNBTag(sourceDiTaus):
   PSet = cms.PSet(
         pluginType  = cms.string("PATMuTauPairNBTagFiller"),
         src         = cms.InputTag(sourceDiTaus),
         doEffMap      = cms.bool(True)
   )
   return PSet

def makeMuTauEffCSV(sourceDiTaus):
   PSet = cms.PSet(
         pluginType  = cms.string("PATMuTauPairEffCSVFiller"),
         src         = cms.InputTag(sourceDiTaus)
   )
   return PSet

def makeMuTauCSVShape(sourceDiTaus):
   PSet = cms.PSet(
         pluginType  = cms.string("PATMuTauPairCSVReweightFiller"),
         src         = cms.InputTag(sourceDiTaus)
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

def makeEleTauMET(sourceDiTaus, sourceMET, prefix):
   PSet = cms.PSet(
         pluginType  = cms.string("PATEleTauPairMETFiller"),
         src         = cms.InputTag(sourceDiTaus),
         met         = cms.InputTag(sourceMET),
         tag         = cms.string(prefix)
   )
   return PSet


def makeEleTauEventWeight(sourceDiTaus):
   PSet = cms.PSet(
         pluginType  = cms.string("PATEleTauPairWeightFiller"),
         src         = cms.InputTag(sourceDiTaus),
         tag         = cms.string("Ele"),
         isMuon      = cms.bool(False)
   )
   return PSet

def makeEleTauEventWeightTmp(sourceDiTaus):
   PSet = cms.PSet(
         pluginType  = cms.string("PATEleTauPairWeightFillerTmp"),
         src         = cms.InputTag(sourceDiTaus),
         tag         = cms.string("MyEle"),
         isMuon      = cms.bool(False)
   )
   return PSet
def makeEleTauGenMatch(sourceDiTaus):
   PSet = cms.PSet(
         pluginType  = cms.string("PATEleTauPairGenMCMatching"),
         src         = cms.InputTag(sourceDiTaus)
   )
   return PSet
def makeEleTauNBTag(sourceDiTaus):
   PSet = cms.PSet(
         pluginType  = cms.string("PATEleTauPairNBTagFiller"),
         src         = cms.InputTag(sourceDiTaus),
         doEffMap      = cms.bool(True)
   )
   return PSet

def makeEleTauEffCSV(sourceDiTaus):
   PSet = cms.PSet(
         pluginType  = cms.string("PATEleTauPairEffCSVFiller"),
         src         = cms.InputTag(sourceDiTaus)
   )
   return PSet

def makeEleTauCSVShape(sourceDiTaus):
   PSet = cms.PSet(
         pluginType  = cms.string("PATEleTauPairCSVReweightFiller"),
         src         = cms.InputTag(sourceDiTaus)
   )
   return PSet


def addDiTauEventTree(process,name,src = 'diTausOS', srcLL = 'diMuonsOSSorted', srcU='TightMuons', srcE='TightElectrons',triggerCollection='HLT2'):
   process.TFileService = cms.Service("TFileService", fileName = cms.string("analysis.root") )
   eventTree = cms.EDAnalyzer('EventTreeMaker',
                              genEvent = cms.InputTag('generator'),
                              coreCollections = cms.InputTag(src),
                              ##PUT ME BACK!
                              trigger = cms.PSet(
                                  pluginType = cms.string("TriggerFiller"),
				  src        = cms.InputTag("TriggerResults","",triggerCollection),
				  prescales = cms.InputTag("patTrigger"),
                                  paths      = cms.vstring(TriggerPaths)
                              ),
                              pu = cms.PSet(
                                  pluginType = cms.string("PUFiller"),
                                  src        = cms.InputTag("slimmedAddPileupInfo"),
                                  tag        = cms.string("pu")
                              ),
                              cov = cms.PSet(
                                  pluginType = cms.string("METSignificanceFiller"),
                                  src        = cms.InputTag("METSignificance"),
                                  tag        = cms.string("metcov")
                              ),
                              PVsSync = cms.PSet(
                                  pluginType = cms.string("VertexSizeFiller"),
                                  src        = cms.InputTag("offlineSlimmedPrimaryVertices"),
                                  tag        = cms.string("npv")
                              ),
                              PVs = cms.PSet(
                                  pluginType = cms.string("VertexSizeFiller"),
                                  src        = cms.InputTag("offlineSlimmedPrimaryVertices"),
                                  tag        = cms.string("vertices")
                              ),
                              diTauGenMCMatch = makeDiTauGenMatch(src),
                              diTauPt1 =  makeDiTauPair(src,"pt_1","leg1.pt"),
                              diTauPt2 =  makeDiTauPair(src,"pt_2","leg2.pt"), 
                              diTauEta1 = makeDiTauPair(src,"eta_1","leg1.eta"),
                              diTauEta2 = makeDiTauPair(src,"eta_2","leg2.eta"),
                              diTauPhi1 = makeDiTauPair(src,"phi_1","leg1.phi"),
                              diTauPhi2 = makeDiTauPair(src,"phi_2","leg2.phi"),
                              diTauCharge = makeDiTauPair(src,"charge","charge"),
                              q_1 = makeDiTauPair(src,"q_1","leg1.charge"),
                              q_2 = makeDiTauPair(src,"q_2","leg2.charge"),
                              diTauPt = makeDiTauPair(src,"pth","pt"),#FILLED
                              diTauHT = makeDiTauPair(src,"ht","ht"),#FILLED
                              diTauMass = makeDiTauPair(src,"m_vis","mass"),#FILLED
                              #diTauSVPt = makeDiTauPair(src,"pt_sv","svPt"),#FILLEDATLATERSTAGE
                              #diTauSVMass = makeDiTauPair(src,"m_sv","svMass"),#FILLEDATLATERSTAGE
			      diTaulVeto = makeDiTauPair(src,"lVeto","lVeto"),
		              diTauTopGenPt = makeDiTauPair(src,"topGenPt","topGenPt"),#FIXME
		              diTauAntiTopGenPt = makeDiTauPair(src,"antiTopGenPt","antiTopGenPt"),#FIXM

                              diTauFullPt = makeDiTauPair(src,"fullPt","fullPt"),#FILLED
                              diTauEta = makeDiTauPair(src,"fullEta","fullEta"),#FILLED
                              diTauPhi = makeDiTauPair(src,"fullPhi","fullPhi"),#FILLED
                              diTauE = makeDiTauPair(src,"fullEnergy","fullEnergy"),#FILLED
                              diTauMET = makeDiTauPair(src,"met","met.pt()"),#FILLED
                              diTauMETPhi = makeDiTauPair(src,"metphi","met.phi()"),#FILLED

                              diTauMT = makeDiTauPair(src,"mt12","mt12MET"),#FILLED
                              diTauMT1 = makeDiTauPair(src,"mt_1","mt1MET"),#FILLED
                              diTaupfMT1 = makeDiTauPair(src,"pfmt_1","mt1MET"),#FILLED
                              diTauMT2 = makeDiTauPair(src,"mt_2","mt2MET"),#FILLED
                              diTaupfMT2 = makeDiTauPair(src,"pfmt_2","mt2MET"),#FILLED
                              

			      diTauMassLL = makeLTauGeneric("PATMuPairFiller",srcLL,"LLmass","mass"),
                              diTauPt1LL =  makeLTauGeneric("PATMuPairFiller",srcLL,"LLpt_1","leg1.pt"), #FILLED
                              diTauPt2LL =  makeLTauGeneric("PATMuPairFiller",srcLL,"LLpt_2","leg2.pt"), #FILLED
                              diTauEta1LL = makeLTauGeneric("PATMuPairFiller",srcLL,"LLeta_1","leg1.eta"),#FILLED
                              diTauEta2LL = makeLTauGeneric("PATMuPairFiller",srcLL,"LLeta_2","leg2.eta"),#FILLED
                              diTauPhi1LL = makeLTauGeneric("PATMuPairFiller",srcLL,"LLphi_1","leg1.phi"),#FILLED
                              diTauPhi2LL = makeLTauGeneric("PATMuPairFiller",srcLL,"LLphi_2","leg2.phi"),#FILLED
                              #diTauEffCSV = makeDiTauEffCSV(src),  ##need to put csv eff back in
                              #diTauCSVShape = makeDiTauCSVShape(src), ## need to put csv shape back in
                              diTauSize = makeCollSize(src,"nCands"),
                              diTauOS = makeCollSizeOS(src,0,"os"),
                              genTaus = makeCollSize("genTauCands","genTaus"), 
                              muMuSize = makeCollSize(srcLL,"diLeptons"),#CHECKME
                              muMuSizeVeto = makeCollSizeVeto(srcLL,0,"dilepton_veto"),#CHECKME
                              muonsSizeMT = makeCollSize(srcU,"tightMuons"),#FILLED
                              muonsSizeMTVeto = makeCollSizeVeto(srcU,0,"extramuon_veto"),#FILLED
                              electronsSizeMT = makeCollSize(srcE,"tightElectrons"),#FILLED
                              electronsSizeMTVeto = makeCollSizeVeto(srcE,0,"extraelec_veto"),#FILLED
                              #tauNIsoTracks =  makeDiTauPair(src,"tauNIsoTracks","leg2.userFloat('nIsoTracks')"), #FILLED
                              #tauNMatchedSeg =  makeDiTauPair(src,"tauMuonNMatchedSeg","leg2.userFloat('muonNMatchedSeg')"),#FILLED
                              #tauTauHadMatched = makeDiTauPair(src,"tauMuonMatched","leg2.userFloat('muonTauHadMatched')"),#FILLED
                              #tauLeadChargedHadrTrackPt = makeDiTauPair(src,"tauLeadChargedHadrTrackPt","leg2.userFloat('leadChargedHadrTrackPt')"),
                              diTauDecayModeLeg1 = makeDiTauPair(src,"decayMode_1",'leg1.decayMode()'),
                              diTauDecayModeLeg2 = makeDiTauPair(src,"decayMode_2",'leg2.decayMode()'),

                              diTauAgainstMuonTight3Leg1 = makeDiTauPair(src,"againstMuonTight3_1",'leg1.tauID("againstMuonTight3")'),
                              diTauAgainstMuonTight3Leg2 = makeDiTauPair(src,"againstMuonTight3_2",'leg2.tauID("againstMuonTight3")'),
                              diTauAgainstMuonLoose3Leg1 = makeDiTauPair(src,"againstMuonLoose3_1",'leg1.tauID("againstMuonLoose3")'),
                              diTauAgainstMuonLoose3Leg2 = makeDiTauPair(src,"againstMuonLoose3_2",'leg2.tauID("againstMuonLoose3")'),
                              diTauAgainstEleVLooseMVA6Leg1 = makeDiTauPair(src,"againstElectronVLooseMVA6_1",'leg1.tauID("againstElectronVLooseMVA6")'),
                              diTauAgainstEleVLooseMVA6Leg2 = makeDiTauPair(src,"againstElectronVLooseMVA6_2",'leg2.tauID("againstElectronVLooseMVA6")'),
                              diTauAgainstEleMVA6rawLeg1 = makeDiTauPair(src,"againstElectronMVA6Raw_1",'leg1.tauID("againstElectronMVA6Raw")'),
                              diTauAgainstEleMVA6rawLeg2 = makeDiTauPair(src,"againstElectronMVA6Raw_2",'leg2.tauID("againstElectronMVA6Raw")'),
                              diTauVTightIsoLeg1 = makeDiTauPair(src,"iso_1",'leg1.tauID("byVTightIsolationMVArun2v1DBoldDMwLT")'),
                              diTauVTightIsoLeg2 = makeDiTauPair(src,"iso_2",'leg2.tauID("byVTightIsolationMVArun2v1DBoldDMwLT")'),

                              diTauTightIsoLeg1 = makeDiTauPair(src,"isoTight_1",'leg1.tauID("byTightIsolationMVArun2v1DBoldDMwLT")'),
                              diTauTightIsoLeg2 = makeDiTauPair(src,"isoTight_2",'leg2.tauID("byTightIsolationMVArun2v1DBoldDMwLT")'),
                              diTauMediumIsoLeg1 = makeDiTauPair(src,"isoMed_1",'leg1.tauID("byMediumIsolationMVArun2v1DBoldDMwLT")'),
                              diTauMediumIsoLeg2 = makeDiTauPair(src,"isoMed_2",'leg2.tauID("byMediumIsolationMVArun2v1DBoldDMwLT")'),
                              diTauLooseIsoLeg1 = makeDiTauPair(src,"isoLoose_1",'leg1.tauID("byLooseIsolationMVArun2v1DBoldDMwLT")'),
                              diTauLooseIsoLeg2 = makeDiTauPair(src,"isoLoose_2",'leg2.tauID("byLooseIsolationMVArun2v1DBoldDMwLT")'),

			      diTauRawMVAIso1 = makeDiTauPair(src,"isoMVARaw_1",'leg1.tauID("byIsolationMVArun2v1DBoldDMwLTraw")'),
			      diTauRawMVAIso2 = makeDiTauPair(src,"isoMVARaw_2",'leg2.tauID("byIsolationMVArun2v1DBoldDMwLTraw")'),
			      diTauRawDBIso1 = makeDiTauPair(src,"isoDBRaw_1",'leg1.tauID("byCombinedIsolationDeltaBetaCorrRaw3Hits")'),
			      diTauRawDBIso2 = makeDiTauPair(src,"isoDBRaw_2",'leg2.tauID("byCombinedIsolationDeltaBetaCorrRaw3Hits")'),
                              diTauGenPt1 = makeDiTauPair(src,"genPt1",'p4Leg1gen().pt()'),
                              diTauGenPt2 = makeDiTauPair(src,"genPt2",'p4Leg2gen().pt()'),
                              diTauPdg1 = makeDiTauPair(src,"pdg1",'genPdg1()'),
                              diTauPdg2 = makeDiTauPair(src,"pdg2",'genPdg2()'),
                              diTauVisGenPt1 = makeDiTauPair(src,"genVisPt1",'p4VisLeg1gen().pt()'),
                              diTauVisGenPt2 = makeDiTauPair(src,"genVisPt2",'p4VisLeg2gen().pt()'),
                              diTauGenVisMass = makeDiTauPair(src,"genVisMass",'p4VisGen().M()'),
                              diTauGenMassMatched = makeDiTauPair(src,"genFullMassMatched",'p4gen().M()'),
                              diTauGenMass = makeDiTauPair(src,"fullGenMass",'genBosonMass()'),
                              diTauGenBosonPt = makeDiTauPair(src,"genpT",'p4GenBoson().pt()'),
                              diTauGenBosonMass = makeDiTauPair(src,"genMass",'p4GenBoson().M()'),
                              diTauGenBosonPx = makeDiTauPair(src,"genpX",'p4GenBoson().px()'),
                              diTauGenBosonPy = makeDiTauPair(src,"genpY",'p4GenBoson().py()'),
                              diTauGenBosonVisPx = makeDiTauPair(src,"vispX",'p4GenBosonVis().px()'),
                              diTauGenBosonVisPy = makeDiTauPair(src,"vispY",'p4GenBosonVis().py()'),
                              #Jets
                              diTauMJJReg = makeDiTauPair(src,"mJJReg","mJJReg"),#FIXME
                              diTauMJJ    = makeDiTauPair(src,"mJJ","mJJ"),#FILLED
                              diTauJJPt   = makeDiTauPair(src,"ptJJ","ptJJ"),
                              diTauJJEta  = makeDiTauPair(src,"etaJJ","etaJJ"),

                              diTauJJEnergy = makeDiTauPair(src,"energyJJ","energyJJ"),
                              diTauVBFDEta = makeDiTauPair(src,"jdeta","vbfDEta"),
                              diTauVBFMass = makeDiTauPair(src,"mjj","vbfMass"),#vbfMass
                              diTauVBFJets20 = makeDiTauPair(src,"njetigap20","vbfNJetsGap20"),
                              diTauVBFJets30 = makeDiTauPair(src,"njetingap","vbfNJetsGap30"),
                              ##FIX ME apply loose ID
                              #diTauJetsPt20nbtag = makeDiTauJetCountPair(src,"nbtag",'userFloat("isbtagged")&&pt()>20&&abs(eta)<2.4&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>.8'),
                              diTauJetsPt20nbtagLoose = makeDiTauJetCountPair(src,"nbtagLooseNoSF",'pt()>20&&abs(eta)<2.4&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>.46'),
                              diTauJetsPt20nbtagNoSF = makeDiTauJetCountPair(src,"nbtagNoSF",'pt()>20&&abs(eta)<2.4&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>.8'),
                              #diTauJetsPt30nbtagNoSf = makeDiTauJetCountPair(src,"nbtag30",'userFloat("isbtagged")&&pt()>30&&abs(eta)<2.4&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>.8'),
                              diTauJetsPt30nbtag = makeDiTauJetCountPair(src,"nbtag30",'pt()>30&&abs(eta)<2.4&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>.8'),

                              diTauJetsPt30njets = makeDiTauJetCountPair(src,"njets",'pt()>30&&abs(eta)<4.7'),
                              #diTauJetsPt30njetsnopu = makeDiTauJetCountPair(src,"njetspuID",'pt()>30&&abs(eta)<4.7&&!userFloat("puIDLoose")'),
                              diTauJetsPt20njets = makeDiTauJetCountPair(src,"njetspt20",'pt()>20&&abs(eta)<4.7'),
                              #diTauJetsPt20njetsnopu = makeDiTauJetCountPair(src,"njetspt20puID",'pt()>20&&abs(eta)<4.7&&!userFloat("puIDLoose")'),


                              diTauJet1PtPtSort = makeDiTauPtPair(src,"jpt_1",'abs(eta())<4.7&&pt()>20','pt()',0),
                              diTauJet2PtPtSort = makeDiTauPtPair(src,"jpt_2",'abs(eta())<4.7&&pt()>20','pt()',1),
                              #diTauJet1PFIDPtSort = makeDiTauPtPair(src,"jpfid_1",'abs(eta())<4.7&&pt()>20','userFloat("idLoose")',0),
                              #diTauJet2PFIDPtSort = makeDiTauPtPair(src,"jpfid_2",'abs(eta())<4.7&&pt()>20','userFloat("idLoose")',1),
                              #diTauJet1PUIDPtSort = makeDiTauPtPair(src,"jpuid_1",'abs(eta())<4.7&&pt()>20','userFloat("puID")',0),
                              #diTauJet2PUIDPtSort = makeDiTauPtPair(src,"jpuid_2",'abs(eta())<4.7&&pt()>20','userFloat("puID")',1),
                              #diTauJet1MVAPtSort = makeDiTauPtPair(src,"jmva_1",'abs(eta())<4.7&&pt()>20',"userFloat('pileupJetId:fullDiscriminant')",0),
                              #diTauJet2MVAPtSort = makeDiTauPtPair(src,"jmva_2",'abs(eta())<4.7&&pt()>20',"userFloat('pileupJetId:fullDiscriminant')",1),
                              diTauJet1EtaPtSort = makeDiTauPtPair(src,"jeta_1",'abs(eta())<4.7&&pt()>20','eta()',0),
                              diTauJet2EtaPtSort = makeDiTauPtPair(src,"jeta_2",'abs(eta())<4.7&&pt()>20','eta()',1),
                              diTauJet1PhiPtSort = makeDiTauPtPair(src,"jphi_1",'abs(eta())<4.7&&pt()>20','phi()',0),
                              diTauJet2PhiPtSort = makeDiTauPtPair(src,"jphi_2",'abs(eta())<4.7&&pt()>20','phi()',1),
                              diTauJet1CSVPtSort = makeDiTauPtPair(src,"jcsv_1",'abs(eta())<2.4&&pt()>20','bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")',0),
                              diTauJet2CSVPtSort = makeDiTauPtPair(src,"jcsv_2",'abs(eta())<2.4&&pt()>20','bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")',1),
                              #diTauJet1MedIdPtSort = makeDiTauPtPair(src,"jtlvID_1",'','userFloat("idTightLepVeto")',0),
                              #diTauJet2MedIdPtSort = makeDiTauPtPair(src,"jtlvID_2",'','userFloat("idTightLepVeto")',1),
                              #diTauJet1TightIdPtSort = makeDiTauPtPair(src,"jtightID_1",'','userFloat("idTight")',0),
                              #diTauJet2TightIdPtSort = makeDiTauPtPair(src,"jtightID_2",'','userFloat("idTight")',1),

                              diTauBJet1PtPtSort = makeDiTauPtPair(src,"bpt_1",'abs(eta())<2.4&&pt()>20&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8','pt()',0),
                              diTauBJet2PtPtSort = makeDiTauPtPair(src,"bpt_2",'abs(eta())<2.4&&pt()>20&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8','pt()',1),
                              #diTauBJet1MVAPtSort = makeDiTauPtPair(src,"bmva_1",'abs(eta())<2.4&&pt()>20&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8',"userFloat('pileupJetId:fullDiscriminant')",0),
                              #diTauBJet2MVAPtSort = makeDiTauPtPair(src,"bmva_2",'abs(eta())<2.4&&pt()>20&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8',"userFloat('pileupJetId:fullDiscriminant')",1),
                              #diTauBJet1PFIDPtSort = makeDiTauPtPair(src,"bpfid_1",'abs(eta())<2.4&&pt()>20&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8','userFloat("idLoose")',0),
                              #diTauBJet2PFIDPtSort = makeDiTauPtPair(src,"bpfid_2",'abs(eta())<2.4&&pt()>20&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8','userFloat("idLoose")',1),
                              #diTauBJet1PUIDPtSort = makeDiTauPtPair(src,"bpuid_1",'abs(eta())<2.4&&pt()>20&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8','userFloat("puID")',0),
                              #diTauBJet2PUIDPtSort = makeDiTauPtPair(src,"bpuid_2",'abs(eta())<2.4&&pt()>20&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8','userFloat("puID")',1),
                              diTauBJet1EtaPtSort = makeDiTauPtPair(src,"beta_1",'abs(eta())<2.4&&pt>20&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8','eta()',0),
                              diTauBJet2EtaPtSort = makeDiTauPtPair(src,"beta_2",'abs(eta())<2.4&&pt>20&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8','eta()',1),
                              diTauBJet1PhiPtSort = makeDiTauPtPair(src,"bphi_1",'abs(eta())<2.4&&pt>20&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8','phi()',0),
                              diTauBJet2PhiPtSort = makeDiTauPtPair(src,"bphi_2",'abs(eta())<2.4&&pt>20&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8','phi()',1),
                              diTauBJet1CSVPtSort = makeDiTauPtPair(src,"bcsv_1",'abs(eta())<2.4&&pt()>20&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>.8','bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")',0),
                              diTauBJet2CSVPtSort = makeDiTauPtPair(src,"bcsv_2",'abs(eta())<2.4&&pt()>20&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>.8','bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")',1),

                              diTauJetsPt20TagMatch = makeDiTauJetCountPair(src,"nTaggableJetsPt20Matched",'pt()>20&&abs(eta)<2.4&&abs(partonFlavour)==5'),
                              diTauJetsPt20TagNoMatch = makeDiTauJetCountPair(src,"nTaggableJetsPt20NotMatched",'pt()>30&&abs(eta)<2.4&&abs(partonFlavour)!=5'),
                              #diTauFirstJetShape = makeLTauGeneric("PATDiTauPairHighestPtJetVarFiller",src,"highestJetShape",'userFloat("ptRMS")'),
                              diTauFirstJetCSV = makeLTauGeneric("PATDiTauPairHighestPtJetVarFiller",src,"highestJetBTagCSV",'bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")'),

                              higgsPt = cms.PSet(
                                  pluginType = cms.string("PATGenParticleFiller"),
                                  src        = cms.InputTag("genDaughters"),
                                  tag        = cms.string("higgsPt"),
                                  method     = cms.string('pt()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              diTauLHEProduct2 = cms.PSet(
                                  pluginType = cms.string("LHEProductFiller"),
                                  src        = cms.InputTag("externalLHEProducer"),
                                  tag        = cms.string("LHEProduct"),
                              ),
                              diTauEmbedPtWeight = cms.PSet(
                                  pluginType = cms.string("GenFilterInfoWeightFiller"),
                                  src        = cms.InputTag("generator"),
                                  #src        = cms.InputTag("generator","EmbWeight"),
                                  tag        = cms.string("aMCNLO_weight"),
                              ),#FIXME #CHECKME
                              diTauEmbedPt = cms.PSet(
                                  pluginType = cms.string("PATGenParticleFiller"),
                                  src        = cms.InputTag("genDaughters"),
                                  tag        = cms.string("embeddedPt"),#CHECKME
                                  method     = cms.string("pt"),
                                  leadingOnly=cms.untracked.bool(False)
                              ),#FIXME #CHECKME
                              diTauEmbedEta = cms.PSet(
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



def addMuTauEventTree(process,name,src = 'diTausOS', srcLL = 'diMuonsOSSorted', srcU='TightMuons', srcE='TightElectrons'):
   process.TFileService = cms.Service("TFileService", fileName = cms.string("analysis.root") )
   eventTree = cms.EDAnalyzer('EventTreeMaker',
                              genEvent = cms.InputTag('generator'),
                              coreCollections = cms.InputTag(src),
                              #trigger = cms.PSet(
                              #    pluginType = cms.string("TriggerFiller"),
		#		  src        = cms.InputTag("TriggerResults","","HLT"),
		#		  prescales = cms.InputTag("patTrigger"),
                #                  paths      = cms.vstring(TriggerPaths)
                 #             ),

                              pu = cms.PSet(
                                  pluginType = cms.string("PUFiller"),
                                  src        = cms.InputTag("slimmedAddPileupInfo"),
                                  tag        = cms.string("pu")
                              ),
                              cov = cms.PSet(
                                  pluginType = cms.string("METSignificanceFiller"),
                                  src        = cms.InputTag("METSignificance"),
                                  tag        = cms.string("metcov")
                              ),
                              PVsSync = cms.PSet(
                                  pluginType = cms.string("VertexSizeFiller"),
                                  src        = cms.InputTag("offlineSlimmedPrimaryVertices"),
                                  tag        = cms.string("npv")
                              ),#FILLED
                              PVs = cms.PSet(
                                  pluginType = cms.string("VertexSizeFiller"),
                                  src        = cms.InputTag("offlineSlimmedPrimaryVertices"),
                                  tag        = cms.string("vertices")
                              ),#FILLED
 
                              muTauEventWeight = makeMuTauEventWeight(src),#FILLED
                              muTauEventWeightTmp = makeMuTauEventWeightTmp(src),#FILLED
                              muTauGenMCMatch = makeMuTauGenMatch(src),#FILLED
                              #muTauNBTags = makeMuTauNBTag(src),#FILLED
                              muTauEffCSV = makeMuTauEffCSV(src),#FILLED
                              muTauCSVShape = makeMuTauCSVShape(src),#FILLED
                              muTauSize = makeCollSize(src,"nCands"),#FILLED
                              muTauOS = makeCollSizeOS(src,0,"os"),#FILLED
                              genTaus = makeCollSize("genTauCands","genTaus"), 
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

                              #mass2ES = makeMuTauPair(src,"mass2ES","leg2.userFloat('ESmass')"),#FILLED
                              #pt2ES = makeMuTauPair(src,"pt2ES","leg2.userFloat('ESpt')"),#FILLED
                              #pt2initial = makeMuTauPair(src,"pt2preES","leg2.userFloat('preESpt')"),#FILLED
                              #phi2initial = makeMuTauPair(src,"phi2preES","leg2.userFloat('preESphi')"),#FILLED

                              muTauCharge = makeMuTauPair(src,"charge","charge"),#FILLED
                              q_1 = makeMuTauPair(src,"q_1","leg1.charge"),#FILLED
                              q_2 = makeMuTauPair(src,"q_2","leg2.charge"),#FILLED

                              muTauPt = makeMuTauPair(src,"pth","pt"),#FILLED
                              muTauHT = makeMuTauPair(src,"ht","ht"),#FILLED
                              muTauMass = makeMuTauPair(src,"m_vis","mass"),#FILLED
                              #muTauSVPt = makeMuTauPair(src,"pt_sv","svPt"),#FILLEDATLATERSTAGE
                              #muTauSVMass = makeMuTauPair(src,"m_sv","svMass"),#FILLEDATLATERSTAGE
			      muTaulVeto = makeMuTauPair(src,"lVeto","lVeto"),

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

                              #muTauMETCal = makeMuTauPair(src,"metCal","calibratedMET.pt()"),#NOLONGLERUSED
                              #muTauMETPhi = makeMuTauPair(src,"metphi","metPhi"),#NOLONGERUSED
                              muTauMET1 = makeMuTauMET(src,"slimmedMETs","pf"),#FILLED
                              muTauMET2 = makeMuTauMET(src,"slimmedMETsPuppi","puppi"),#FILLED
                              muTauMET3 = makeMuTauMET(src,"MVAMET:MVAMET","mva"),#FILLED
 
                              #muTauGenMET = makeMuTauPair(src,"genMET","met.genMET().pt"),#FILLED
                              muTauMET = makeMuTauPair(src,"met","met.pt()"),#FILLED
                              muTauMETPhi = makeMuTauPair(src,"metphi","met.phi()"),#FILLED
                              #muTauMET = makeMuTauPair(src,"mvamet","met.pt()"),#FILLED
                              #muTauMETx = makeMuTauPair(src,"mvamet_ex","met.px()"),#FILLED
                              #muTauMETy = makeMuTauPair(src,"mvamet_ey","met.py()"),#FILLED
                              #muTauMETPhi = makeMuTauPair(src,"mvametphi","met.phi()"),#FILLED
                              #muTauMvaCovMat00 = makeMuTauPair(src,"mvacov00","covMatrix00"),#FIXME
                              #muTauMvaCovMat10 = makeMuTauPair(src,"mvacov10","covMatrix10"),#FIXME
                              #muTauMvaCovMat01 = makeMuTauPair(src,"mvacov01","covMatrix01"),#FIXME
                              #muTauMvaCovMat11 = makeMuTauPair(src,"mvacov11","covMatrix11"),#FIXME

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
                              muTauRelPFIsoDB04 = makeMuTauPair(src,"iso04_1",'leg1.userFloat("dBRelIso")'),

                              muTauLooseID = makeMuTauPair(src,"id_m_loose_1",'leg1.isLooseMuon()'),
                              #muTauMediumID = makeMuTauPair(src,"id_m_medium_1",'leg1.isMediumMuon()'),
                              muTauMediumID = makeMuTauPair(src,"id_m_medium_1_INVALID",'leg1.isMediumMuon()'),
                              muTauUserMediumID = makeMuTauPair(src,"id_m_medium_1",'leg1.userInt("mediumID")'),
                              muTauDecayMode = makeMuTauPair(src,"tauDecayMode",'leg2.decayMode()'),
                              muTauDecayFound = makeMuTauPair(src,"decayModeFinding_2",'leg2.tauID("decayModeFinding")'),
                              muTauDecayFoundOld = makeMuTauPair(src,"decayModeFindingOldDMs_2",'leg2.tauID("decayModeFinding")'),
                              muTauDecayFoundNew = makeMuTauPair(src,"decayModeFindingNewDMs_2",'leg2.tauID("decayModeFindingNewDMs")'),
                              muTauProngs = makeMuTauPair(src,"tauProngs",'leg2.signalChargedHadrCands.size()'),#see Decay Modes
                              muTauMuTriggerMatch = makeMuTauPair(src,"lTrigger",'leg1.userFloat("hltL3crIsoL1sMu20L1f0L2f10QL3f22QL3trkIsoFiltered0p09")'),
                              muTauMuTriggerMatchTau = makeMuTauPair(src,"lt1Trigger",'leg1.userFloat("hltOverlapFilterSingleIsoMu19LooseIsoPFTau20")'),
                              muTauMuTriggerMatchTau1 = makeMuTauPair(src,"lt2Trigger",'leg1.userFloat("hltL3crIsoL1sSingleMu18erIorSingleMu20erL1f0L2f10QL3f19QL3trkIsoFiltered0p09")'),
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
			      muTauByNewDMMVAIso = makeMuTauPair(src,"byIsolationMVArun2v1DBnewDMwLTraw_2",'leg2.tauID("byIsolationMVArun2v1DBnewDMwLTraw")'),
			      muTauByOldDMMVAIso = makeMuTauPair(src,"byIsolationMVArun2v1DBoldDMwLTraw_2",'leg2.tauID("byIsolationMVArun2v1DBoldDMwLTraw")'),
                              muTauByOldDMMVAIsoTight = makeMuTauPair(src,"byTightIsolationMVArun2v1DBoldDMwLT_2",'leg2.tauID("byTightIsolationMVArun2v1DBoldDMwLT")'),
                              muTauByOldDMMVAIsoMedium = makeMuTauPair(src,"byMediumIsolationMVArun2v1DBoldDMwLT_2",'leg2.tauID("byMediumIsolationMVArun2v1DBoldDMwLT")'),
                              muTauByOldDMMVAIsoLoose = makeMuTauPair(src,"byLooseIsolationMVArun2v1DBoldDMwLT_2",'leg2.tauID("byLooseIsolationMVArun2v1DBoldDMwLT")'),
                              muTauByCharged = makeMuTauPair(src,"chargedIsoPtSum_2",'leg2.tauID("chargedIsoPtSum")'),
                              muTauByNeutral = makeMuTauPair(src,"neutralIsoPtSum_2",'leg2.tauID("neutralIsoPtSum")'),
                              muTauByPU = makeMuTauPair(src,"puCorrPtSum_2",'leg2.tauID("puCorrPtSum")'), 
                              muTauAgainstMuonTight3 = makeMuTauPair(src,"againstMuonTight3_2",'leg2.tauID("againstMuonTight3")'),
                              #muTauAgainstMuonTight4 = makeMuTauPair(src,"againstMuonTight4_2",'leg2.tauID("againstMuonTight4")'),
                              muTauAgainstEleVLooseMVA6 = makeMuTauPair(src,"againstElectronVLooseMVA6_2",'leg2.tauID("againstElectronVLooseMVA6")'),
                              muTauAgainstEleMVA6raw = makeMuTauPair(src,"againstElectronMVA6Raw",'leg2.tauID("againstElectronMVA6Raw")'),

                              muTauGenPt1 = makeMuTauPair(src,"genPt1",'p4Leg1gen().pt()'),
                              muTauGenPt2 = makeMuTauPair(src,"genPt2",'p4Leg2gen().pt()'),
                              muTauPdg1 = makeMuTauPair(src,"pdg1",'genPdg1()'),
                              muTauPdg2 = makeMuTauPair(src,"pdg2",'genPdg2()'),
                              muTauVisGenPt1 = makeMuTauPair(src,"genVisPt1",'p4VisLeg1gen().pt()'),
                              muTauVisGenPt2 = makeMuTauPair(src,"genVisPt2",'p4VisLeg2gen().pt()'),
                              muTauGenVisMass = makeMuTauPair(src,"genVisMass",'p4VisGen().M()'),
                              muTauGenMassMatched = makeMuTauPair(src,"genFullMassMatched",'p4gen().M()'),
                              muTauGenMass = makeMuTauPair(src,"fullGenMass",'genBosonMass()'),
                              muTauGenBosonPt = makeMuTauPair(src,"genpT",'p4GenBoson().pt()'),
                              muTauGenBosonMass = makeMuTauPair(src,"genMass",'p4GenBoson().M()'),
                              muTauGenBosonPx = makeMuTauPair(src,"genpX",'p4GenBoson().px()'),
                              muTauGenBosonPy = makeMuTauPair(src,"genpY",'p4GenBoson().py()'),
                              muTauGenBosonVisPx = makeMuTauPair(src,"vispX",'p4GenBosonVis().px()'),
                              muTauGenBosonVisPy = makeMuTauPair(src,"vispY",'p4GenBosonVis().py()'),

                              muTauGenIsPrompt1 = makeMuTauPair(src,"isPrompt1",'isPrompt1()'),
                              muTauGenIsPromptFS1 = makeMuTauPair(src,"isPromptFS1",'isPromptFS1()'),
                              muTauGenIsDirectTauDecay1 = makeMuTauPair(src,"isTauDecay1",'isDirectPromptTauDecayProduct1()'),
                              muTauGenIsDirectTauDecayFS1 = makeMuTauPair(src,"isTauDecayFS1",'isDirectPromptTauDecayProductFS1()'),

                              muTauGenIsPrompt2 = makeMuTauPair(src,"isPrompt2",'isPrompt2()'),
                              muTauGenIsPromptFS2 = makeMuTauPair(src,"isPromptFS2",'isPromptFS2()'),
                              muTauGenIsDirectTauDecay2 = makeMuTauPair(src,"isTauDecay2",'isDirectPromptTauDecayProduct2()'),
                              muTauGenIsDirectTauDecayFS2 = makeMuTauPair(src,"isTauDecayFS2",'isDirectPromptTauDecayProductFS2()'),



			      #Jets
                              muTauJetsPt20nbtag = makeMuTauJetCountPair(src,"nbtag",'userFloat("isbtagged")&&pt()>20&&abs(eta)<2.4&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>.8'),
                              muTauJetsPt20nbtagLoose = makeMuTauJetCountPair(src,"nbtagLooseNoSF",'pt()>20&&abs(eta)<2.4&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>.46'),
                              muTauJetsPt20nbtagNoSF = makeMuTauJetCountPair(src,"nbtagNoSF",'pt()>20&&abs(eta)<2.4&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>.8'),
                              muTauJetsPt30nbtagNoSf = makeMuTauJetCountPair(src,"nbtag30",'userFloat("isbtagged")&&pt()>30&&abs(eta)<2.4&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>.8'),
                              muTauJetsPt30nbtag = makeMuTauJetCountPair(src,"nbtag30",'pt()>30&&abs(eta)<2.4&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>.8'),

                              muTauJetsPt30njets = makeMuTauJetCountPair(src,"njets",'pt()>30&&abs(eta)<4.7&&userFloat("idLoose")'),
                              muTauJetsPt30njetsnopu = makeMuTauJetCountPair(src,"njetspuID",'pt()>30&&abs(eta)<4.7&&userFloat("idLoose")&&!userFloat("puIDLoose")'),
                              muTauJetsPt20njets = makeMuTauJetCountPair(src,"njetspt20",'pt()>20&&abs(eta)<4.7&&userFloat("idLoose")'),
                              muTauJetsPt20njetsnopu = makeMuTauJetCountPair(src,"njetspt20puID",'pt()>20&&abs(eta)<4.7&&userFloat("idLoose")&&!userFloat("puIDLoose")'),


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
                              muTauJet1CSVPtSort = makeMuTauPtPair(src,"jcsv_1",'abs(eta())<2.4&&pt()>20&&userFloat("idLoose")','bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")',0),
                              muTauJet2CSVPtSort = makeMuTauPtPair(src,"jcsv_2",'abs(eta())<2.4&&pt()>20&&userFloat("idLoose")','bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")',1),
                              muTauJet1MedIdPtSort = makeMuTauPtPair(src,"jtlvID_1",'','userFloat("idTightLepVeto")',0),
                              muTauJet2MedIdPtSort = makeMuTauPtPair(src,"jtlvID_2",'','userFloat("idTightLepVeto")',1),
                              muTauJet1TightIdPtSort = makeMuTauPtPair(src,"jtightID_1",'','userFloat("idTight")',0),
                              muTauJet2TightIdPtSort = makeMuTauPtPair(src,"jtightID_2",'','userFloat("idTight")',1),

                              muTauBJet1PtPtSort = makeMuTauPtPair(src,"bpt_1",'abs(eta())<2.4&&pt()>20&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8','pt()',0),
                              muTauBJet2PtPtSort = makeMuTauPtPair(src,"bpt_2",'abs(eta())<2.4&&pt()>20&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8','pt()',1),
                              muTauBJet1MVAPtSort = makeMuTauPtPair(src,"bmva_1",'abs(eta())<2.4&&pt()>20&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8',"userFloat('pileupJetId:fullDiscriminant')",0),
                              muTauBJet2MVAPtSort = makeMuTauPtPair(src,"bmva_2",'abs(eta())<2.4&&pt()>20&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8',"userFloat('pileupJetId:fullDiscriminant')",1),
                              muTauBJet1PFIDPtSort = makeMuTauPtPair(src,"bpfid_1",'abs(eta())<2.4&&pt()>20&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8','userFloat("idLoose")',0),
                              muTauBJet2PFIDPtSort = makeMuTauPtPair(src,"bpfid_2",'abs(eta())<2.4&&pt()>20&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8','userFloat("idLoose")',1),
                              muTauBJet1PUIDPtSort = makeMuTauPtPair(src,"bpuid_1",'abs(eta())<2.4&&pt()>20&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8','userFloat("puID")',0),
                              muTauBJet2PUIDPtSort = makeMuTauPtPair(src,"bpuid_2",'abs(eta())<2.4&&pt()>20&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8','userFloat("puID")',1),
                              muTauBJet1EtaPtSort = makeMuTauPtPair(src,"beta_1",'abs(eta())<2.4&&pt>20&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8','eta()',0),
                              muTauBJet2EtaPtSort = makeMuTauPtPair(src,"beta_2",'abs(eta())<2.4&&pt>20&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8','eta()',1),
                              muTauBJet1PhiPtSort = makeMuTauPtPair(src,"bphi_1",'abs(eta())<2.4&&pt>20&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8','phi()',0),
                              muTauBJet2PhiPtSort = makeMuTauPtPair(src,"bphi_2",'abs(eta())<2.4&&pt>20&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8','phi()',1),
                              muTauBJet1CSVPtSort = makeMuTauPtPair(src,"bcsv_1",'abs(eta())<2.4&&pt()>20&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>.8','bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")',0),
                              muTauBJet2CSVPtSort = makeMuTauPtPair(src,"bcsv_2",'abs(eta())<2.4&&pt()>20&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>.8','bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")',1),

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

                              #muTauLHEProduct = cms.PSet(
                              #    pluginType = cms.string("LHEProductFiller"),
                              #    src        = cms.InputTag("source"),
                              #    tag        = cms.string("LHEProduct"),
                              #),
                              muTauLHEProduct2 = cms.PSet(
                                  pluginType = cms.string("LHEProductFiller"),
                                  src        = cms.InputTag("externalLHEProducer"),
                                  tag        = cms.string("LHEProduct"),
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
def addEleTauEventTree(process,name,src='eleTausSorted',srcLL='diElectronsOSSorted', srcU='TightMuons', srcE='TightElectrons'):
   process.TFileService = cms.Service("TFileService", fileName = cms.string("analysis.root") )
   eventTree = cms.EDAnalyzer('EventTreeMaker',
                              genEvent = cms.InputTag('generator'),
                              coreCollections = cms.InputTag(src),
                             # trigger = cms.PSet(
                             #     pluginType = cms.string("TriggerFiller"),
                             #     src        = cms.InputTag("TriggerResults","","HLT"),
		#		  prescales = cms.InputTag("patTrigger"),
	#			  paths      = cms.vstring(TriggerPaths)
         #                     ),
                              pu = cms.PSet(
                                  pluginType = cms.string("PUFiller"),
                                  src        = cms.InputTag("slimmedAddPileupInfo"),
                                  tag        = cms.string("pu")
                              ),
                              cov = cms.PSet(
                                  pluginType = cms.string("METSignificanceFiller"),
                                  src        = cms.InputTag("METSignificance"),
                                  tag        = cms.string("metcov")
                              ),
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


                              eTauEventWeight = makeEleTauEventWeight(src),#FILLED
                              eTauEventWeightTmp = makeEleTauEventWeightTmp(src),#FILLED
                              #eleTauNBTags = makeEleTauNBTag(src),#FILLED
                              eleTauEffCSV = makeEleTauEffCSV(src),#FILLED
                              eleTauCSVShape = makeEleTauCSVShape(src),#FILLED
                              eTauGenMCMatch = makeEleTauGenMatch(src),#FILLED

                              muonsSizeET = makeCollSize(srcU,"tightMuons"),
                              muonsSizeETVeto = makeCollSizeVeto(srcU,0,"extramuon_veto"),
                              electronsSizeET = makeCollSize(srcE,"tightElectrons"),
                              electronsSizeETVeto = makeCollSizeVeto(srcE, 1,"extraelec_veto"),

                              eleTauSize = makeCollSize(src,"nCands"),
                              eleTauOS = makeCollSizeOS(src,0,"os"),
                              eleEleSize = makeCollSize(srcLL,"diLeptons"),
                              eleEleSizeVeto = makeCollSizeVeto(srcLL,0,"dilepton_veto"),
                              genTaus = makeCollSize("genTauCands","genTaus"), #FIXME
 
                              tauNIsoTracks =  makeEleTauPair(src,"tauNIsoTracks","leg2.userFloat('nIsoTracks')"), #FILLED
                              tauNMatchedSeg =  makeEleTauPair(src,"tauMuonNMatchedSeg","leg2.userFloat('muonNMatchedSeg')"), #FILLED
                              tauTauHadMatched = makeEleTauPair(src,"tauMuonMatched","leg2.userFloat('muonTauHadMatched')"),
                              tauLeadChargedHadrTrackPt = makeEleTauPair(src,"tauLeadChargedHadrTrackPt","leg2.userFloat('leadChargedHadrTrackPt')"),

                              #mass2ES = makeEleTauPair(src,"mass2ES","leg2.userFloat('ESmass')"),#FIXME
                              #pt2ES = makeEleTauPair(src,"pt2ES","leg2.userFloat('ESpt')"),#FIXME
                              #eleTauPt2initial = makeEleTauPair(src,"pt2preES","leg2.userFloat('preESpt')"),
                              #eleTauPhi2initial = makeEleTauPair(src,"phi2preES","leg2.userFloat('preESphi')"),


                              eleTauCharge = makeEleTauPair(src,"charge","charge"),
                              eleTauCharge1 = makeEleTauPair(src,"q_1","leg1.charge"),
                              eleTauCharge2 = makeEleTauPair(src,"q_2","leg2.charge"),

                              eleTauPt = makeEleTauPair(src,"pth","pt"),
                              eleTauHT = makeEleTauPair(src,"ht","ht"),
                              eleTauMass = makeEleTauPair(src,"m_vis","mass"),
                              #eleTauSVPt = makeEleTauPair(src,"pt_sv","svPt"),
                              #eleTauSVMass = makeEleTauPair(src,"m_sv","svMass"),
			      eleTaulVeto = makeEleTauPair(src,"lVeto","lVeto"),

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
                              #eleTauMETPhi = makeEleTauPair(src,"metphi","metPhi"),
                              #eleTauGenMET = makeEleTauPair(src,"genMET","met.genMET()"),

			      eleTauMET1 = makeEleTauMET(src,"slimmedMETs","pf"),#FILLED
			      eleTauMET2 = makeEleTauMET(src,"slimmedMETsPuppi","puppi"),#FILLED
			      eleTauMET3 = makeEleTauMET(src,"MVAMET:MVAMET","mva"),#FILLED
        
                              eleTauMET = makeEleTauPair(src,"met","met.pt()"),
                              eleTauMETPhi = makeEleTauPair(src,"metphi","met.phi()"),
                              #eleTauMET = makeEleTauPair(src,"mvamet","met.pt()"),
                              #eleTauMETx = makeEleTauPair(src,"mvamet_ex","met.px()"),
                              #eleTauMETy = makeEleTauPair(src,"mvamet_ey","met.py()"),
                              #eleTauMETPhi = makeEleTauPair(src,"mvametphi","met.phi()"),
                              #eleTauCovMat00 = makeEleTauPair(src,"mvacov00","covMatrix00"),
                              #eleTauCovMat10 = makeEleTauPair(src,"mvacov10","covMatrix10"),
                              #eleTauCovMat01 = makeEleTauPair(src,"mvacov01","covMatrix01"),
                              #eleTauCovMat11 = makeEleTauPair(src,"mvacov11","covMatrix11"),

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

                              eleTauDZVZ = makeEleTauPair(src,"dz_vz",'abs(leg1.vz-leg2.vz)'),
                              eleTauDPhi = makeEleTauPair(src,"dPhi12",'dPhi12'),
                              eleTauDPhi1MET = makeEleTauPair(src,"dPhi1MET",'dPhi1MET'),
                              eleTauDPhi2MET = makeEleTauPair(src,"dPhi2MET",'dPhi2MET'),
                              eleTauPzeta = makeEleTauPair(src,"pZeta",'pZeta-1.5*pZetaVis'),#EO 
                              eleTauPZ = makeEleTauPair(src,"pzeta",'pZeta'),#EO
                              eleTauPZV = makeEleTauPair(src,"pzetavis",'pZetaVis'),#EO

			      #Trigger
                              eleTauEleTriggerMatch2016_25 = makeEleTauPair(src,"lTrigger25",'leg1.userFloat("hltEle25erWPTightGsfTrackIsoFilter")'),
                              eleTauEleTriggerMatch2016_27 = makeEleTauPair(src,"lTrigger27",'leg1.userFloat("hltEle27erWPLooseGsfTrackIsoFilter")'),
                              eleTauEleTriggerMatch2016_1 = makeEleTauPair(src,"lt1Trigger",'leg1.userFloat("hltOverlapFilterIsoEle24WPLooseGsfLooseIsoPFTau20")'),
                              eleTauEleTriggerMatch2016_2 = makeEleTauPair(src,"lt2Trigger",'leg1.userFloat("hltEle24WPLooseL1SingleIsoEG22erGsfTrackIsoFilter")'),


                              #Ele IDs and Isolation
                              eleTauRelPFIsoDB03 = makeEleTauPair(src,"iso_1",'leg1.userFloat("dBRelIso03")'),
                              muTauRel2PFIsoDB03 = makeMuTauPair(src,"iso_2",'leg2.tauID("byIsolationMVArun2v1DBoldDMwLTraw")'),
			      eleTauRel2PFIsoDB03 = makeEleTauPair(src,"iso_2",'leg2.tauID("byIsolationMVArun2v1DBoldDMwLTraw")'),
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
			      eleTauByNewDMMVAIso = makeEleTauPair(src,"byIsolationMVArun2v1DBnewDMwLTraw_2",'leg2.tauID("byIsolationMVArun2v1DBnewDMwLTraw")'),
			      eleTauByOldDMMVAIso = makeEleTauPair(src,"byIsolationMVArun2v1DBoldDMwLTraw_2",'leg2.tauID("byIsolationMVArun2v1DBoldDMwLTraw")'),
 
                              eleTauByOldDMMVAIsoTight = makeEleTauPair(src,"byTightIsolationMVArun2v1DBoldDMwLT_2",'leg2.tauID("byTightIsolationMVArun2v1DBoldDMwLT")'),
                              eleTauByOldDMMVAIsoMedium = makeEleTauPair(src,"byMediumIsolationMVArun2v1DBoldDMwLT_2",'leg2.tauID("byMediumIsolationMVArun2v1DBoldDMwLT")'),
                              eleTauByOldDMMVAIsoLoose = makeEleTauPair(src,"byLooseIsolationMVArun2v1DBoldDMwLT_2",'leg2.tauID("byLooseIsolationMVArun2v1DBoldDMwLT")'),
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
                              eleTauAgainstEleMVA6raw = makeEleTauPair(src,"againstElectronMVA6Raw",'leg2.tauID("againstElectronMVA6Raw")'),
                              eleTauAgainstElectronVTightMVA6 = makeEleTauPair(src,"againstElectronVTightMVA6_2",'leg2.tauID("againstElectronVTightMVA6")'),
                              eleTauAgainstElectronTightMVA6 = makeEleTauPair(src,"againstElectronTightMVA6_2",'leg2.tauID("againstElectronTightMVA6")'),
                              eleTauAgainstElectronMediumMVA6 = makeEleTauPair(src,"againstElectronMediumMVA6_2",'leg2.tauID("againstElectronMediumMVA6")'),
                              eleTauAgainstElectronVLooseMVA6 = makeEleTauPair(src,"againstElectronVLooseMVA6_2",'leg2.tauID("againstElectronVLooseMVA6")'),
                              eleTauAgainstElectronLooseMVA6 = makeEleTauPair(src,"againstElectronLooseMVA6_2",'leg2.tauID("againstElectronLooseMVA6")'),

                              eleTauGenPt1 = makeEleTauPair(src,"genPt1",'p4Leg1gen().pt()'),
                              eleTauGenPt2 = makeEleTauPair(src,"genPt2",'p4Leg2gen().pt()'),
                              eleTauPdg1 = makeEleTauPair(src,"pdg1",'genPdg1()'),
                              eleTauPdg2 = makeEleTauPair(src,"pdg2",'genPdg2()'),
                              eleTauVisGenPt1 = makeEleTauPair(src,"genVisPt1",'p4VisLeg1gen().pt()'),
                              eleTauVisGenPt2 = makeEleTauPair(src,"genVisPt2",'p4VisLeg2gen().pt()'),
                              eleTauGenVisMass = makeEleTauPair(src,"genVisMass",'p4VisGen().M()'),
                              eleTauGenMassMatched = makeEleTauPair(src,"genFullMassMatched",'p4gen().M()'),
                              eleTauGenBosonMass = makeEleTauPair(src,"genMass",'p4GenBoson().M()'),
                              eleTauGenBosonPt = makeEleTauPair(src,"genpT",'p4GenBoson().pt()'),
                              eleTauGenBosonPx = makeEleTauPair(src,"genpX",'p4GenBoson().px()'),
                              eleTauGenBosonPy = makeEleTauPair(src,"genpY",'p4GenBoson().py()'),
                              eleTauGenBosonVisPx = makeEleTauPair(src,"vispX",'p4GenBosonVis().px()'),
                              eleTauGenBosonVisPy = makeEleTauPair(src,"vispY",'p4GenBosonVis().py()'),
                              eleTauGenMass = makeEleTauPair(src,"fullGenMass",'genBosonMass()'),

                              eleTauGenIsPrompt1 = makeEleTauPair(src,"isPrompt1",'isPrompt1()'),
                              eleTauGenIsPromptFS1 = makeEleTauPair(src,"isPromptFS1",'isPromptFS1()'),
                              eleTauGenIsDirectTauDecay1 = makeEleTauPair(src,"isTauDecay1",'isDirectPromptTauDecayProduct1()'),
                              eleTauGenIsDirectTauDecayFS1 = makeEleTauPair(src,"isTauDecayFS1",'isDirectPromptTauDecayProductFS1()'),
                              eleTauGenIsPrompt2 = makeEleTauPair(src,"isPrompt2",'isPrompt2()'),
                              eleTauGenIsPromptFS2 = makeEleTauPair(src,"isPromptFS2",'isPromptFS2()'),
                              eleTauGenIsDirectTauDecay2 = makeEleTauPair(src,"isTauDecay2",'isDirectPromptTauDecayProduct2()'),
                              eleTauGenIsDirectTauDecayFS2 = makeEleTauPair(src,"isTauDecayFS2",'isDirectPromptTauDecayProductFS2()'),



			      #Jets
                              eleTauJetsPt20nbtag = makeEleTauJetCountPair(src,"nbtag",'userFloat("isbtagged")&&pt()>20&&abs(eta)<2.4&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8'),
                              eleTauJetsPt20nbtagNoSF = makeEleTauJetCountPair(src,"nbtagNoSF",'pt()>20&&abs(eta)<2.4&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8'),
                              eleTauJetsPt20nbtagLoose = makeEleTauJetCountPair(src,"nbtagLooseNoSF",'pt()>20&&abs(eta)<2.4&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.46'),
                              eleTauJetsPt30nbtagNoSF = makeEleTauJetCountPair(src,"nbtag30NoSF",'pt()>30&&abs(eta)<2.4&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8'),
                              eleTauJetsPt30nbtag = makeEleTauJetCountPair(src,"nbtag30",'userFloat("isbtagged")&&pt()>30&&abs(eta)<2.4&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8'),
                              eleTauJetsPt30njets = makeEleTauJetCountPair(src,"njets",'pt()>30&&abs(eta)<4.7&&userFloat("idLoose")'),
                              eleTauJetsPt30njetsLoosepu = makeEleTauJetCountPair(src,"njetspuID",'pt()>30&&abs(eta)<4.7&&userFloat("idLoose")&&!userFloat("puIDLoose")'),
                              eleTauJetsPt20njets = makeEleTauJetCountPair(src,"njetspt20",'pt()>20&&abs(eta)<4.7&&userFloat("idLoose")'),
                              eleTauJetsPt20njetsLoosepu = makeEleTauJetCountPair(src,"njetspt20puID",'pt()>20&&abs(eta)<4.7&&userFloat("idLoose")&&!userFloat("puIDLoose")'),

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
                              eleTauJet1MedIdPtSort = makeEleTauPtPair(src,"jtlvID_1",'abs(eta())<4.7&&pt>20&&userFloat("idLoose")','userFloat("idTightLepVeto")',0),
                              eleTauJet2MedIdPtSort = makeEleTauPtPair(src,"jtlvID_2",'abs(eta())<4.7&&pt>20&&userFloat("idLoose")','userFloat("idTightLepVeto")',1),
                              eleTauJet1TightIdPtSort = makeEleTauPtPair(src,"jtightID_1",'abs(eta())<4.7&&pt>20&&userFloat("idLoose")','userFloat("idTight")',0),
                              eleTauJet2TightIdPtSort = makeEleTauPtPair(src,"jtightID_2",'abs(eta())<4.7&&pt>20&&userFloat("idLoose")','userFloat("idTight")',1),

                              eleTauBJet1PtPtSort = makeEleTauPtPair(src,"bpt_1",'abs(eta())<2.4&&pt()>20&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8','pt()',0),
                              eleTauBJet2PtPtSort = makeEleTauPtPair(src,"bpt_2",'abs(eta())<2.4&&pt()>20&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8','pt()',1),
                              eleTauBJet1MVAPtSort = makeEleTauPtPair(src,"bmva_1",'abs(eta())<2.4&&pt()>20&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8',"userFloat('pileupJetId:fullDiscriminant')",0),
                              eleTauBJet2MVAPtSort = makeEleTauPtPair(src,"bmva_2",'abs(eta())<2.4&&pt()>20&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8',"userFloat('pileupJetId:fullDiscriminant')",1),
                              eleTauBJet1PFIDPtSort = makeEleTauPtPair(src,"bpfid_1",'abs(eta())<2.4&&pt()>20&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8','userFloat("idLoose")',0),
                              eleTauBJet2PFIDPtSort = makeEleTauPtPair(src,"bpfid_2",'abs(eta())<2.4&&pt()>20&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8','userFloat("idLoose")',1),
                              eleTauBJet1PUIDPtSort = makeEleTauPtPair(src,"bpuid_1",'abs(eta())<2.4&&pt()>20&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8','userFloat("puID")',0),
                              eleTauBJet2PUIDPtSort = makeEleTauPtPair(src,"bpuid_2",'abs(eta())<2.4&&pt()>20&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8','userFloat("puID")',1),
                              eleTauBJet1EtaPtSort = makeEleTauPtPair(src,"beta_1",'abs(eta())<2.4&&pt>20&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8','eta()',0),
                              eleTauBJet2EtaPtSort = makeEleTauPtPair(src,"beta_2",'abs(eta())<2.4&&pt>20&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8','eta()',1),
                              eleTauBJet1PhiPtSort = makeEleTauPtPair(src,"bphi_1",'abs(eta())<2.4&&pt>20&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8','phi()',0),
                              eleTauBJet2PhiPtSort = makeEleTauPtPair(src,"bphi_2",'abs(eta())<2.4&&pt>20&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8','phi()',1),
                              eleTauBJet1CSVPtSort = makeEleTauPtPair(src,"bcsv_1",'abs(eta())<2.4&&pt()>20&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>.8','bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")',0),
                              eleTauBJet2CSVPtSort = makeEleTauPtPair(src,"bcsv_2",'abs(eta())<2.4&&pt()>20&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>.8','bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")',1),



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



                              #eleTauLHEProduct = cms.PSet(
                              #    pluginType = cms.string("LHEProductFiller"),
                              #    src        = cms.InputTag("source"),
                              #    tag        = cms.string("LHEProduct"),
                              #),
                              eleTauLHEProduct2 = cms.PSet(
                                  pluginType = cms.string("LHEProductFiller"),
                                  src        = cms.InputTag("externalLHEProducer"),
                                  tag        = cms.string("LHEProduct"),
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
                                  tag        = cms.string("embeddedEta"),#CHECKME
                                  method     = cms.string("eta"),
                                  leadingOnly=cms.untracked.bool(False)
                              )
   )

   setattr(process, name, eventTree)
   p = cms.Path(getattr(process,name))
   setattr(process, name+'Path', p)


