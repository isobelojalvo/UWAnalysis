import FWCore.ParameterSet.Config as cms

from UWAnalysis.Configuration.tools.analysisToolsHTauTau_WIP import TriggerPaths,TriggerRes,TriggerProcess,TriggerFilter

from RecoMET.METFilters.BadChargedCandidateFilter_cfi import *


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

def makeDiTauVBFPair(sourceDiTaus):
   PSet = cms.PSet(
         pluginType  = cms.string("PATDiTauPairVBFVariableFiller"),
         src         = cms.InputTag(sourceDiTaus)
   )
   return PSet

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


def addDiTauEventTree(process,name,src = 'diTausOS', srcLL = 'diMuonsOSSorted', srcU='TightMuons', srcE='TightElectrons',triggerCollection='HLT'):
   process.TFileService = cms.Service("TFileService", fileName = cms.string("analysis.root") )
   eventTree = cms.EDAnalyzer('EventTreeMaker',
                              genEvent = cms.InputTag('generator'),
                              coreCollections = cms.InputTag(src),
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
                              metfilter = cms.PSet(
                                  pluginType = cms.string("TriggerFilterFiller"),
                                  src = cms.InputTag(TriggerRes,"",TriggerFilter),
                                  BadChargedCandidateFilter = cms.InputTag("BadChargedCandidateFilter"),
                                  BadPFMuonFilter           = cms.InputTag("BadPFMuonFilter"),
                                  paths      = cms.vstring(
                                      "Flag_noBadMuons",
                                      "Flag_HBHENoiseFilter",
                                      "Flag_HBHENoiseIsoFilter",
                                      "Flag_globalTightHalo2016Filter",
                                      "Flag_goodVertices",
                                      "Flag_eeBadScFilter",
                                      "Flag_EcalDeadCellTriggerPrimitiveFilter"
                                      )
                              ),
                              diTauPt1 =  makeDiTauPair(src,"pt_1","leg1.pt"),
                              diTauPt2 =  makeDiTauPair(src,"pt_2","leg2.pt"), 
                              diTauEta1 = makeDiTauPair(src,"eta_1","leg1.eta"),
                              diTauEta2 = makeDiTauPair(src,"eta_2","leg2.eta"),
                              diTauPhi1 = makeDiTauPair(src,"phi_1","leg1.phi"),
                              diTauPhi2 = makeDiTauPair(src,"phi_2","leg2.phi"),
                              diTauHadMass1 = makeDiTauPair(src,"m_1",'leg1.mass()'),
                              diTauHadMass2 = makeDiTauPair(src,"m_2",'leg2.mass()'),
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
                              diTauJES = makeDiTauVBFPair(src),#FILLED

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

                              diTauIsoLeg1 = makeDiTauPair(src,"iso_1",'leg1.tauID("byIsolationMVArun2v1DBoldDMwLTraw")'),
                              diTauIsoLeg2 = makeDiTauPair(src,"iso_2",'leg2.tauID("byIsolationMVArun2v1DBoldDMwLTraw")'),

                              diTauVTightIsoLeg1 = makeDiTauPair(src,"isoVTight_1",'leg1.tauID("byVTightIsolationMVArun2v1DBoldDMwLT")'),
                              diTauVTightIsoLeg2 = makeDiTauPair(src,"isoVTight_2",'leg2.tauID("byVTightIsolationMVArun2v1DBoldDMwLT")'),
                              diTauTightIsoLeg1 = makeDiTauPair(src,"isoTight_1",'leg1.tauID("byTightIsolationMVArun2v1DBoldDMwLT")'),
                              diTauTightIsoLeg2 = makeDiTauPair(src,"isoTight_2",'leg2.tauID("byTightIsolationMVArun2v1DBoldDMwLT")'),
                              diTauMediumIsoLeg1 = makeDiTauPair(src,"isoMed_1",'leg1.tauID("byMediumIsolationMVArun2v1DBoldDMwLT")'),
                              diTauMediumIsoLeg2 = makeDiTauPair(src,"isoMed_2",'leg2.tauID("byMediumIsolationMVArun2v1DBoldDMwLT")'),
                              diTauLooseIsoLeg1 = makeDiTauPair(src,"isoLoose_1",'leg1.tauID("byLooseIsolationMVArun2v1DBoldDMwLT")'),
                              diTauLooseIsoLeg2 = makeDiTauPair(src,"isoLoose_2",'leg2.tauID("byLooseIsolationMVArun2v1DBoldDMwLT")'),
                              diTauVLooseIsoLeg1 = makeDiTauPair(src,"isoVLoose_1",'leg1.tauID("byVLooseIsolationMVArun2v1DBoldDMwLT")'),
                              diTauVLooseIsoLeg2 = makeDiTauPair(src,"isoVLoose_2",'leg2.tauID("byVLooseIsolationMVArun2v1DBoldDMwLT")'),

			      diTauRawMVAIso1 = makeDiTauPair(src,"isoMVARaw_1",'leg1.tauID("byIsolationMVArun2v1DBoldDMwLTraw")'),
			      diTauRawMVAIso2 = makeDiTauPair(src,"isoMVARaw_2",'leg2.tauID("byIsolationMVArun2v1DBoldDMwLTraw")'),
			      diTauRawDBIso1 = makeDiTauPair(src,"isoDBRaw_1",'leg1.tauID("byCombinedIsolationDeltaBetaCorrRaw3Hits")'),
			      diTauRawDBIso2 = makeDiTauPair(src,"isoDBRaw_2",'leg2.tauID("byCombinedIsolationDeltaBetaCorrRaw3Hits")'),

####Rerun

                              #diTauIsoLeg1ReRun =  makeDiTauPair(src,"isoRerun_1",'leg1.userFloat("byVTightIsolationMVArun2v1DBoldDMwLTRerun")'),
                              #diTauIsoLeg2ReRun =  makeDiTauPair(src,"isoRerun_2",'leg2.userFloat("byVTightIsolationMVArun2v1DBoldDMwLTRerun")'),

                              #diTauVTightIsoLeg1ReRun =  makeDiTauPair(src,"isoVTightRerun_1",'leg1.userFloat("byVTightIsolationMVArun2v1DBoldDMwLTRerun")'),
                              #diTauVTightIsoLeg2ReRun =  makeDiTauPair(src,"isoVTightRerun_2",'leg2.userFloat("byVTightIsolationMVArun2v1DBoldDMwLTRerun")'),
                              #diTauTightIsoLeg1ReRun =  makeDiTauPair(src,"isoTightRerun_1",'leg1.userFloat("byTightIsolationMVArun2v1DBoldDMwLTRerun")'),
                              #diTauTightIsoLeg2ReRun =  makeDiTauPair(src,"isoTightRerun_2",'leg2.userFloat("byTightIsolationMVArun2v1DBoldDMwLTRerun")'),
                              #diTauMediumIsoLeg1ReRun =  makeDiTauPair(src,"isoMedRerun_1",'leg1.userFloat("byMediumIsolationMVArun2v1DBoldDMwLTRerun")'),
                              #diTauMediumIsoLeg2ReRun =  makeDiTauPair(src,"isoMedRerun_2",'leg2.userFloat("byMediumIsolationMVArun2v1DBoldDMwLTRerun")'),
                              #diTauLooseIsoLeg1ReRun =  makeDiTauPair(src,"isoLooseRerun_1",'leg1.userFloat("byLooseIsolationMVArun2v1DBoldDMwLTRerun")'),
                              #diTauLooseIsoLeg2ReRun =  makeDiTauPair(src,"isoLooseRerun_2",'leg2.userFloat("byLooseIsolationMVArun2v1DBoldDMwLTRerun")'),
                              #diTauVLooseIsoLeg1ReRun =  makeDiTauPair(src,"isoVLooseRerun_1",'leg1.userFloat("byVLooseIsolationMVArun2v1DBoldDMwLTRerun")'),
                              #diTauVLooseIsoLeg2ReRun =  makeDiTauPair(src,"isoVLooseRerun_2",'leg2.userFloat("byVLooseIsolationMVArun2v1DBoldDMwLTRerun")'),

			      #diTauRawMVAIso1ReRun =  makeDiTauPair(src,"isoMVARawRerun_1",'leg1.userFloat("byIsolationMVArun2v1DBoldDMwLTrawRerun")'),
			      #diTauRawMVAIso2ReRun =  makeDiTauPair(src,"isoMVARawRerun_2",'leg2.userFloat("byIsolationMVArun2v1DBoldDMwLTrawRerun")'),

####Rerun
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
                              diTauVBFJets20 = makeDiTauPair(src,"njetingap20","vbfNJetsGap20"),
                              diTauVBFJets30 = makeDiTauPair(src,"njetingap","vbfNJetsGap30"),
                              ##FIX ME apply loose ID
                              #diTauJetsPt20nbtag = makeDiTauJetCountPair(src,"nbtag",'userFloat("isbtagged")&&pt()>20&&abs(eta)<2.4&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>.8484'),
                              diTauJetsPt20nbtagLoose = makeDiTauJetCountPair(src,"nbtagLooseNoSF",'pt()>20&&abs(eta)<2.4&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>.46'),
                              diTauJetsPt20nbtagNoSF = makeDiTauJetCountPair(src,"nbtagNoSF",'pt()>20&&abs(eta)<2.4&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>.8484'),
                              #diTauJetsPt30nbtagNoSf = makeDiTauJetCountPair(src,"nbtag30",'userFloat("isbtagged")&&pt()>30&&abs(eta)<2.4&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>.8484'),
                              diTauJetsPt30nbtag = makeDiTauJetCountPair(src,"nbtag30",'pt()>30&&abs(eta)<2.4&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>.8484'),

                              diTauJetsPt30njets = makeDiTauJetCountPair(src,"njets",'pt()>30&&abs(eta)<4.7&&userFloat("idLoose")'),
                              diTauJetsPt30njetsnopu = makeDiTauJetCountPair(src,"njetspuID",'pt()>30&&abs(eta)<4.7&&!userFloat("puIDLoose")'),
                              diTauJetsPt20njets = makeDiTauJetCountPair(src,"njetspt20",'pt()>20&&abs(eta)<4.7&&userFloat("idLoose")'),
                              diTauJetsPt20njetsnopu = makeDiTauJetCountPair(src,"njetspt20puID",'pt()>20&&abs(eta)<4.7&&!userFloat("puIDLoose")'),


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

                              diTauBJet1PtPtSort = makeDiTauPtPair(src,"bpt_1",'abs(eta())<2.4&&pt()>20&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8484','pt()',0),
                              diTauBJet2PtPtSort = makeDiTauPtPair(src,"bpt_2",'abs(eta())<2.4&&pt()>20&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8484','pt()',1),
                              #diTauBJet1MVAPtSort = makeDiTauPtPair(src,"bmva_1",'abs(eta())<2.4&&pt()>20&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8484',"userFloat('pileupJetId:fullDiscriminant')",0),
                              #diTauBJet2MVAPtSort = makeDiTauPtPair(src,"bmva_2",'abs(eta())<2.4&&pt()>20&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8484',"userFloat('pileupJetId:fullDiscriminant')",1),
                              #diTauBJet1PFIDPtSort = makeDiTauPtPair(src,"bpfid_1",'abs(eta())<2.4&&pt()>20&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8484','userFloat("idLoose")',0),
                              #diTauBJet2PFIDPtSort = makeDiTauPtPair(src,"bpfid_2",'abs(eta())<2.4&&pt()>20&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8484','userFloat("idLoose")',1),
                              #diTauBJet1PUIDPtSort = makeDiTauPtPair(src,"bpuid_1",'abs(eta())<2.4&&pt()>20&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8484','userFloat("puID")',0),
                              #diTauBJet2PUIDPtSort = makeDiTauPtPair(src,"bpuid_2",'abs(eta())<2.4&&pt()>20&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8484','userFloat("puID")',1),
                              diTauBJet1EtaPtSort = makeDiTauPtPair(src,"beta_1",'abs(eta())<2.4&&pt>20&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8484','eta()',0),
                              diTauBJet2EtaPtSort = makeDiTauPtPair(src,"beta_2",'abs(eta())<2.4&&pt>20&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8484','eta()',1),
                              diTauBJet1PhiPtSort = makeDiTauPtPair(src,"bphi_1",'abs(eta())<2.4&&pt>20&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8484','phi()',0),
                              diTauBJet2PhiPtSort = makeDiTauPtPair(src,"bphi_2",'abs(eta())<2.4&&pt>20&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8484','phi()',1),
                              diTauBJet1CSVPtSort = makeDiTauPtPair(src,"bcsv_1",'abs(eta())<2.4&&pt()>20&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>.8484','bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")',0),
                              diTauBJet2CSVPtSort = makeDiTauPtPair(src,"bcsv_2",'abs(eta())<2.4&&pt()>20&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>.8484','bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")',1),

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
                              )
                              )
   setattr(process, name, eventTree)
   p = cms.Path(getattr(process,name))
   setattr(process, name+'Path', p)

