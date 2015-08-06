import FWCore.ParameterSet.Config as cms

from UWAnalysis.Configuration.tools.analysisToolsMiniAod import TriggerPaths



def makeCollSize(srcName,tagName):
  PSet = cms.PSet(
        pluginType = cms.string("CollectionSizeFiller"),
        src        = cms.InputTag(srcName),
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

def makeMuTauPtPair(sourceDiTaus,tagName,cutName,methodName,rank):
   PSet = cms.PSet(
         pluginType  = cms.string("PATMuTauPairPtJetVarFiller"),
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

def makeEleTauPtPair(sourceDiTaus,tagName,cutName,methodName,rank):
   PSet = cms.PSet(
         pluginType  = cms.string("PATEleTauPairPtJetVarFiller"),
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


def addMuTauEventTree(process,name,src = 'diTausSorted', srcLL = 'diMuonsSorted', srcU='TightMuons', srcE='TightElectrons'):
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
                               PVs = cms.PSet(
                                  pluginType = cms.string("VertexSizeFiller"),
                                  src        = cms.InputTag("primaryVertexFilter"),
                                  tag        = cms.string("vertices")
                              ),#FILLED
 
                              muTauSize = makeCollSize(src,"nCands"),#FILLED
                              genTaus = makeCollSize("genTauCands","genTaus"), #FIXME
                              muMuSize = makeCollSize(srcLL,"diLeptons"),#CHECKME

                              muonsSizeMT = makeCollSize(srcU,"tightMuons"),#FILLED
                              electronsSizeMT = makeCollSize(srcE,"tightElectrons"),#FILLED

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
                              muTauMass = makeMuTauPair(src,"mass","mass"),#FILLED
                              muTauSVPt = makeMuTauPair(src,"svPt","svPt"),#FIXME
                              muTauSVMass = makeMuTauPair(src,"svMass","svMass"),#FILLED

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

                              muTauMETUnc = makeMuTauPair(src,"met","met.pt()"),#FILLED
                              muTauMET = makeMuTauPair(src,"metCal","calibratedMET.pt()"),#FILLED
                              METPhi = makeMuTauPair(src,"metPhi","metPhi"),#FILLED
                              CovMat00 = makeMuTauPair(src,"covMatrix00","covMatrix00"),#FIXME
                              CovMat10 = makeMuTauPair(src,"covMatrix10","covMatrix10"),#FIXME
                              CovMat01 = makeMuTauPair(src,"covMatrix01","covMatrix01"),#FIXME
                              CovMat11 = makeMuTauPair(src,"covMatrix11","covMatrix11"),#FIXME

                              muTauMT = makeMuTauPair(src,"mt","mt12MET"),#FILLED
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
                              #muTauHMass = makeMuTauPair(src,"HMass","hhMass"),
                              #muTauHMassReg = makeMuTauPair(src,"HMassReg","hhMassReg"),
                              #muTauHPt = makeMuTauPair(src,"HPt","hhPt"),
                              #muTauHEta = makeMuTauPair(src,"HEta","hhEta"),
                              #muTauHPhi = makeMuTauPair(src,"HPhi","hhPhi"),
                              #muTauHEnergy = makeMuTauPair(src,"HEnergy","hhE"),
                              muTauVBFDEta = makeMuTauPair(src,"vbfDEta","vbfDEta"),
                              #muTauVBFMass = makeMuTauPair(src,"vbfMass","vbfMass"),
                              muTauVBFMass = makeMuTauPair(src,"mjj","vbfMass"),
                              muMuVBFJets20 = makeMuTauPair(src,"njetigap20","vbfNJetsGap20"),
                              muMuVBFJets30 = makeMuTauPair(src,"njetingap","vbfNJetsGap30"),

                              #Muon IDs and Isolation
                              muTauRelPFIsoDB03 = makeMuTauPair(src,"iso_1",'leg1.userFloat("dBRelIso03")'),
                              muTauRelPFIsoDB04 = makeMuTauPair(src,"lPFIsoDB04",'leg1.userFloat("dBRelIso")'),

                              muTauRelPFIsoDB2 = makeMuTauPair(src,"lPFIsoDB2",'leg2.userFloat("dBRelIso2")'),
                              muTauLooseID = makeMuTauPair(src,"muLooseId",'leg1.isLooseMuon()'),
                              muTauMediumID = makeMuTauPair(src,"muMediumId",'leg1.isMediumMuon()'),
                              #muTauMediumID = makeMuTauPair(src,"muMediumId",'leg1.userInt("mediumID")'),
                              muTauDecayMode = makeMuTauPair(src,"tauDecayMode",'leg2.decayMode()'),
                              muTauDecayFound = makeMuTauPair(src,"tauDecayFound",'leg2.tauID("decayModeFinding")'),
                              muTauDecayFoundsyncname = makeMuTauPair(src,"decayModeFindingOldDMs_2",'leg2.tauID("decayModeFinding")'),
                              muTauDecayFoundsyncnamenew = makeMuTauPair(src,"decayModeFindingNewDMs_2",'leg2.tauID("decayModeFindingNewDMs")'),
                              muTauMuTriggerMatch = makeMuTauPair(src,"lTrigger",'leg1.userFloat("hltOverlapFilterIsoMu17LooseIsoPFTau20")'),
                              muTauTauTriggerMatch = makeMuTauPair(src,"tauTrigger",'leg2.userFloat("hltOverlapFilterIsoMu17LooseIsoPFTau20")'),
                              muTauPzeta = makeMuTauPair(src,"pZeta",'pZeta-1.5*pZetaVis'),
                              muTauPZ = makeMuTauPair(src,"pZ",'pZeta'),
                              muTauPZV = makeMuTauPair(src,"pzetavis",'pZetaVis'),
                              muTauTauZIP = makeMuTauPair(src,"tauZIP",'leg2.userFloat("zIP")'),
                              muTauHadMass = makeMuTauPair(src,"tauMass",'leg2.mass()'),

                              muTauMuDZ = makeMuTauPair(src,"dZ_1","leg1.userFloat('dZ')"),
                              muTauTauDZ = makeMuTauPair(src,"dZ_2","leg2.userFloat('dZ')"),
                              muTauMuDXY = makeMuTauPair(src,"d0_1","leg1.userFloat('dXY')"),
                              muTauTauDXY = makeMuTauPair(src,"d0_2","leg2.userFloat('dXY')"),

			      #tauIDs
                              muTauByCombIsoDBRaw3 = makeMuTauPair(src,"tauIso",'leg2.tauID("byCombinedIsolationDeltaBetaCorrRaw3Hits")'),
                              muTauByCombIsoLoose = makeMuTauPair(src,"tauIsoLoose",'leg2.tauID("byLooseCombinedIsolationDeltaBetaCorr3Hits")'),
                              muTauByCombIsoMedium = makeMuTauPair(src,"tauIsoMedium",'leg2.tauID("byMediumCombinedIsolationDeltaBetaCorr3Hits")'),
                              muTauByCombIsoTight = makeMuTauPair(src,"tauIsoTight",'leg2.tauID("byTightCombinedIsolationDeltaBetaCorr3Hits")'),
                              muTauByCharged = makeMuTauPair(src,"chargedIsoPtSum_2",'leg2.tauID("chargedIsoPtSum")'),
                              muTauByNeutral = makeMuTauPair(src,"neutralIsoPtSum_2",'leg2.tauID("neutralIsoPtSum")'),
                              muTauAgainstMuonTight3 = makeMuTauPair(src,"againstMuonTight3",'leg2.tauID("againstMuonTight3")'),
                              muTauAgainstMuonTightFixed = makeMuTauPair(src,"againstMuTightFixed",'leg2.userInt("againstMuTightFixed")'),
                              muTauAgainstEleVLooseMVA5 = makeMuTauPair(src,"againstElectronVLooseMVA5",'leg2.tauID("againstElectronVLooseMVA5")'),

                              muTauGenPt1 = makeMuTauPair(src,"genPt1",'p4Leg1gen().pt()'),
                              muTauGenPt2 = makeMuTauPair(src,"genPt2",'p4Leg2gen().pt()'),
                              muTauPdg1 = makeMuTauPair(src,"pdg1",'genPdg1()'),
                              muTauPdg2 = makeMuTauPair(src,"pdg2",'genPdg2()'),
                              muTauVisGenPt1 = makeMuTauPair(src,"genVisPt1",'p4VisLeg1gen().pt()'),
                              muTauVisGenPt2 = makeMuTauPair(src,"genVisPt2",'p4VisLeg2gen().pt()'),
                              muTauGenVisMass = makeMuTauPair(src,"genVisMass",'p4VisGen().M()'),
                              muTauGenMassMatched = makeMuTauPair(src,"genFullMassMatched",'p4gen().M()'),
                              muTauGenMass = makeMuTauPair(src,"fullGenMass",'genBosonMass()'),


                              muTauJet1PtPtSort = makeMuTauPtPair(src,"jpt_1",'abs(eta())<4.7&&pt()>20','pt()',0),
                              muTauJet2PtPtSort = makeMuTauPtPair(src,"jpt_2",'abs(eta())<4.7&&pt()>20','pt()',1),
                              muTauJet1MVAPtSort = makeMuTauPtPair(src,"jmva_1",'abs(eta())<4.7&&pt()>20',"userFloat('pileupJetId:fullDiscriminant')",0),
                              muTauJet2MVAPtSort = makeMuTauPtPair(src,"jmva_2",'abs(eta())<4.7&&pt()>20',"userFloat('pileupJetId:fullDiscriminant')",1),
                              muTauJet1EtaPtSort = makeMuTauPtPair(src,"jeta_1",'abs(eta())<4.7&&pt()>20','eta()',0),
                              muTauJet2EtaPtSort = makeMuTauPtPair(src,"jeta_2",'abs(eta())<4.7&&pt()>20','eta()',1),
                              muTauJet1PhiPtSort = makeMuTauPtPair(src,"jphi_1",'abs(eta())<4.7&&pt()>20','phi()',0),
                              muTauJet2PhiPtSort = makeMuTauPtPair(src,"jphi_2",'abs(eta())<4.7&&pt()>20','phi()',1),
                              muTauJet1FlavourPtSort = makeMuTauPtPair(src,"J1Flavour",'abs(eta())<2.4&&pt()>20','partonFlavour()',0),
                              muTauJet2FlavourPtSort = makeMuTauPtPair(src,"J2Flavour",'abs(eta())<2.4&&pt()>20','partonFlavour()',1),
                              muTauJet1CSVPtSort = makeMuTauPtPair(src,"J1CSVbtag",'abs(eta())<2.4&&pt()>20','bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")',0),
                              muTauJet2CSVPtSort = makeMuTauPtPair(src,"J2CSVbtag",'abs(eta())<2.4&&pt()>20','bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")',1),
                              #muTauJet1MVASfPtSort = makeMuTauPtPair(src,"J1MVASf",'','userFloat("mvaSF")',0),
                              #muTauJet2MVASfPtSort = makeMuTauPtPair(src,"J2MVASf",'','userFloat("mvaSF")',1),
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


                              muTauJetsPt20nbtag = makeMuTauJetCountPair(src,"nbjets",'pt()>30&&abs(eta)<2.4'),
                              muTauJetsPt30njets = makeMuTauJetCountPair(src,"njets",'pt()>30&&abs(eta)<4.7'),
                              muTauJetsPt20njets = makeMuTauJetCountPair(src,"njetspt20",'pt()>20&&abs(eta)<4.7'),



                              muTauJetsBTagCSVLPt20 = makeMuTauJetCountPair(src,"nJetsBTagCSVLPt20",'bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.423&&pt()>20&&abs(eta)<2.4'),
                              muTauJetsBTagCSVLPt25 = makeMuTauJetCountPair(src,"nJetsBTagCSVLPt25",'bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.423&&pt()>25&&abs(eta)<2.4'),
                              muTauJetsBTagCSVMPt20 = makeMuTauJetCountPair(src,"nJetsBTagCSVMPt20",'bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.814&&pt()>20&&abs(eta)<2.4'),
                              muTauJetsBTagCSVMPt25 = makeMuTauJetCountPair(src,"nJetsBTagCSVMPt25",'bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.814&&pt()>25&&abs(eta)<2.4'),
                              muTauJetsBTagCSVTPt20 = makeMuTauJetCountPair(src,"nJetsBTagCSVTPt20",'bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.941&&pt()>20&&abs(eta)<2.4'),
                              muTauJetsBTagCSVTPt25 = makeMuTauJetCountPair(src,"nJetsBTagCSVTPt25",'bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.941&&pt()>25&&abs(eta)<2.4'),
                              muTauJetsPt20 = makeMuTauJetCountPair(src,"nJetsPt20",'pt()>20'),
                              muTauJetsPt20Loose = makeMuTauJetCountPair(src,"nJetsPt20Loose",'pt()>20&&userFloat("idLoose")'),
                              muTauJetsPt20Medium = makeMuTauJetCountPair(src,"nJetsPt20Medium",'pt()>20&&userFloat("idMedium")'),
                              muTauJetsPt20Tight = makeMuTauJetCountPair(src,"nJetsPt20Tight",'pt()>20&&userFloat("idTight")'),
                              muTauJetsPt20Tag = makeMuTauJetCountPair(src,"nTaggableJetsPt20",'pt()>20&&abs(eta)<2.4'),
                              muTauJetsPt20TagMatch = makeMuTauJetCountPair(src,"nTaggableJetsPt20Matched",'pt()>20&&abs(eta)<2.4&&abs(partonFlavour)==5'),
                              muTauJetsPt20TagMatchTag = makeMuTauJetCountPair(src,"nTaggableJetsPt20MatchedTagM",'pt()>20&&abs(eta)<2.4&&abs(partonFlavour)==5&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.814'),
                              muTauJetsPt20TagNoMatch = makeMuTauJetCountPair(src,"nTaggableJetsPt20NotMatched",'pt()>30&&abs(eta)<2.4&&abs(partonFlavour)!=5'),
                              muTauJetsPt20TagNoMatchTag = makeMuTauJetCountPair(src,"nTaggableJetsPt20NotMatchedTagM",'pt()>20&&abs(eta)<2.4&&abs(partonFlavour)!=5&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.814'),
                              muTauJetsPt30 = makeMuTauJetCountPair(src,"nJetsPt30",'pt()>30'),
                              muTauJetsPt30TagMatch = makeMuTauJetCountPair(src,"nTaggableJetsPt30Matched",'pt()>30&&abs(eta)<2.4&&abs(partonFlavour)==5'),
                              muTauJetsPt30TagMatchTag = makeMuTauJetCountPair(src,"nTaggableJetsPt30MatchedTagM",'pt()>30&&abs(eta)<2.4&&abs(partonFlavour)==5&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.814'),
                              muTauJetsPt30TagNoMatch = makeMuTauJetCountPair(src,"nTaggableJetsPt30NotMatched",'pt()>30&&abs(eta)<2.4&&abs(partonFlavour)!=5'),
                              muTauJetsPt30TagNoMatchTag = makeMuTauJetCountPair(src,"nTaggableJetsPt30NotMatchedTagM",'pt()>30&&abs(eta)<2.4&&abs(partonFlavour)!=5&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.814'),

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
                              ),#FIXME
                              PVs = cms.PSet(
                                  pluginType = cms.string("VertexSizeFiller"),
                                  src        = cms.InputTag("primaryVertexFilter"),
                                  tag        = cms.string("vertices")
                              ),

                              muonsSizeET = makeCollSize(srcU,"tightMuons"),
                              electronsSizeET = makeCollSize(srcE,"tightElectrons"),

                              eleTauSize = makeCollSize(srcE,"nCands"),
                              eleEleSize = makeCollSize(srcLL,"diLeptons"),
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

                              eleTauPt = makeEleTauPair(src,"pt","pt"),
                              eleTauHT = makeEleTauPair(src,"ht","ht"),
                              eleTauMass = makeEleTauPair(src,"mass","mass"),
                              eleTauSVPt = makeEleTauPair(src,"svPt","svPt"),
                              eleTauSVMass = makeEleTauPair(src,"svMass","svMass"),

                              eleTauFullPt = makeEleTauPair(src,"fullPt","fullPt"),
                              eleTauEta = makeEleTauPair(src,"fullEta","fullEta"),
                              eleTauPhi = makeEleTauPair(src,"fullPhi","fullPhi"),
                              eleTauE = makeEleTauPair(src,"fullEnergy","fullEnergy"),

                              eleTauPt1 =  makeEleTauPair(src,"pt_1","leg1.pt"), #FILLED
                              eleTauPt2 =  makeEleTauPair(src,"pt_2","leg2.pt"), #FILLED
                              eleTauEta1 = makeEleTauPair(src,"eta_1","leg1.eta"),
                              eleTauSCEta1 = makeEleTauPair(src,"eta_1","leg1.superCluster().eta()"),
                              eleTauEta2 = makeEleTauPair(src,"eta_2","leg2.eta"),
                              eleTauPhi1 = makeEleTauPair(src,"phi_1","leg1.phi"),
                              eleTauPhi2 = makeEleTauPair(src,"phi_2","leg2.phi"),

                              eleTauMETUnc = makeEleTauPair(src,"metUnc","met.pt()"),#curretnly identical
                              eleTauMET = makeEleTauPair(src,"met","calibratedMET.pt()"),#currently identical
                              eleTauMETPhi = makeEleTauPair(src,"metPhi","metPhi"),
                              eleTauCovMat00 = makeEleTauPair(src,"covMatrix00","covMatrix00"),
                              eleTauCovMat10 = makeEleTauPair(src,"covMatrix10","covMatrix10"),
                              eleTauCovMat01 = makeEleTauPair(src,"covMatrix01","covMatrix01"),
                              eleTauCovMat11 = makeEleTauPair(src,"covMatrix11","covMatrix11"),

                              eleTauMT = makeEleTauPair(src,"mt","mt12MET"),
                              eleTauMT1 = makeEleTauPair(src,"mt_1","mt1MET"),
                              eleTauMT2 = makeEleTauPair(src,"mt_2","mt2MET"),

                              eleTauTopGenPt = makeEleTauPair(src,"topGenPt","topGenPt"),
                              eleTauAntiTopGenPt = makeEleTauPair(src,"antiTopGenPt","antiTopGenPt"),

                              #BTAGS AND JETS
                              eleTauMJJReg = makeEleTauPair(src,"mJJReg","mJJReg"),
                              eleTauMJJ = makeEleTauPair(src,"mjj","mJJ"),
                              eleTauJJPt = makeEleTauPair(src,"ptJJ","ptJJ"),
                              eleTauJJEta = makeEleTauPair(src,"etaJJ","etaJJ"),
                              eleTauJJPhi = makeEleTauPair(src,"phiJJ","phiJJ"),
                              eleTauJJEnergy = makeEleTauPair(src,"energyJJ","energyJJ"),
                              #eleTauHMass = makeEleTauPair(src,"HMass","hhMass"),
                              #eleTauHMassReg = makeEleTauPair(src,"HMassReg","hhMassReg"),
                              #eleTauHPt = makeEleTauPair(src,"HPt","hhPt"),
                              #eleTauHEta = makeEleTauPair(src,"HEta","hhEta"),
                              #eleTauHPhi = makeEleTauPair(src,"HPhi","hhPhi"),
                              #eleTauHEnergy = makeEleTauPair(src,"HEnergy","hhE"),
                              eleTauVBFDEta = makeEleTauPair(src,"vbfDEta","vbfDEta"),
                              eleTauVBFDPhi = makeEleTauPair(src,"vbfDPhi","vbfDPhi"),#EO
                              eleTauVBFMass = makeEleTauPair(src,"vbfMass","vbfMass"),
                              muMuVBFJets20 = makeEleTauPair(src,"vbfNJetsGap20","vbfNJetsGap20"),
                              muMuVBFJets30 = makeEleTauPair(src,"vbfNJetsGap30","vbfNJetsGap30"),

                              #ETAU ONLY

                              eleTauDZVZ = makeEleTauPair(src,"dz_vz",'abs(leg1.userFloat("vz")-leg2.userFloat("vz"))'),#EO #FIXME
                              #eleTauEleDZ = makeEleTauPair(src,"l1dz",'leg1.userFloat("dz")'),#EO #FIXME
                              #eleTauTauDZ = makeEleTauPair(src,"l2dz",'leg2.userFloat("dz")'),#EO #FIXME
                              eleTauDPhi = makeEleTauPair(src,"dPhi12",'dPhi12'),
                              eleTauDPhi1MET = makeEleTauPair(src,"dPhi1MET",'dPhi1MET'),
                              eleTauDPhi2MET = makeEleTauPair(src,"dPhi2MET",'dPhi2MET'),
                              eleTauPzeta = makeEleTauPair(src,"pZeta",'pZeta-1.5*pZetaVis'),#EO 
                              eleTauPZ = makeEleTauPair(src,"pZ",'pZeta'),#EO
                              eleTauPZV = makeEleTauPair(src,"pZV",'pZetaVis'),#EO

                              #Ele IDs and Isolation
                              eleTauRelPFIsoDB03 = makeEleTauPair(src,"iso_1",'leg1.userFloat("dBRelIso03")'),
                              eleTauRelPFIsoDB04 = makeEleTauPair(src,"lPFIsoDB04",'leg1.userFloat("dBRelIso")'),
                              eleTauRelPFIsoDB2 = makeEleTauPair(src,"lPFIsoDB2",'leg2.userFloat("dBRelIso")'),
                              eleTauDecayMode = makeEleTauPair(src,"tauDecayMode",'leg2.decayMode()'),
                              eleTauDecayFound = makeEleTauPair(src,"tauDecayFound",'leg2.tauID("decayModeFinding")'),
                              eleTauProngs = makeEleTauPair(src,"tauProngs",'leg2.signalChargedHadrCands.size()'),#EO
                              eleTauMuTriggerMatch = makeEleTauPair(src,"lTrigger",'leg1.userFloat("hltOverlapFilterIsoEle22WPLooseGsfLooseIsoPFTau20")'),
                              eleTauTauTriggerMatch = makeEleTauPair(src,"tauTrigger",'leg2.userFloat("hltOverlapFilterIsoEle22WPLooseGsfLooseIsoPFTau20")'),
                              eleTauTauZIP = makeEleTauPair(src,"tauZIP",'leg2.userFloat("zIP")'),
                              eleTauHadMass = makeEleTauPair(src,"tauMass",'leg2.mass()'),
                              eleTauByCombIsoDBRaw3 = makeEleTauPair(src,"tauIso",'leg2.tauID("byCombinedIsolationDeltaBetaCorrRaw3Hits")'),
                              eleTauByCombIsoLoose = makeEleTauPair(src,"tauIsoLoose",'leg2.tauID("byLooseCombinedIsolationDeltaBetaCorr3Hits")'),
                              eleTauByCombIsoMedium = makeEleTauPair(src,"tauIsoMedium",'leg2.tauID("byMediumCombinedIsolationDeltaBetaCorr3Hits")'),
                              eleTauByCombIsoTight = makeEleTauPair(src,"tauIsoTight",'leg2.tauID("byTightCombinedIsolationDeltaBetaCorr3Hits")'),
                              eleTauByCharged = makeEleTauPair(src,"chargedIsoPtSum_2",'leg2.tauID("chargedIsoPtSum")'),
                              eleTauByNeutral = makeEleTauPair(src,"neutralIsoPtSum_2",'leg2.tauID("neutralIsoPtSum")'),
 
 
                              eleTauAgainstMuonLoose3 = makeEleTauPair(src,"againstMuonLoose3",'leg2.tauID("againstMuonLoose3")'),
                              #eleTauMVATrig = makeEleTauPair(src,"BDTIDTrig",'leg1.userFloat("mvaIDTrig80")'),#CHECKME #rename
                              eleTauMVANonTrig80 = makeEleTauPair(src,"mvaIDNonTrig80",'leg1.userFloat("mvaIDNonTrig80")'),#CHECKME #rename
                              eleTauMVANonTrig90 = makeEleTauPair(src,"mvaIDNonTrig90",'leg1.userFloat("mvaIDNonTrig90")'),#CHECKME #rename
                              eleTauCBIDVeto = makeEleTauPair(src,"CBIDVeto",'leg1.userFloat("CBIDVeto")'),#CHECKME #rename
                              eleTauCBIDLoose = makeEleTauPair(src,"CBIDLoose",'leg1.userFloat("CBIDLoose")'),#CHECKME #rename
                              eleTauCBIDMedium = makeEleTauPair(src,"CBIDMedium",'leg1.userFloat("CBIDMedium")'),#CHECKME #rename
                              eleTauCBIDTight = makeEleTauPair(src,"CBIDTight",'leg1.userFloat("CBIDTight")'),#CHECKME #rename

                              eleTauEleDZ = makeEleTauPair(src,"dZ_1","leg1.userFlaot('dZ')"),
                              eleTauTauDZ = makeEleTauPair(src,"dZ_2","leg2.userFloat('dZ')"),
                              eleTauEleDXY = makeEleTauPair(src,"d0_1","leg1.userFloat('dXY')"),
                              eleTauTauDXY = makeEleTauPair(src,"d0_2","leg2.userFloat('dXY')"),
                              eleTauConversion = makeEleTauPair(src,"eleConversion","leg1.userInt('eleConversion')"),
                              eleTauPassConversion = makeEleTauPair(src,"ePassConversion",'leg1.passConversionVeto()'),
                              eleTauAgainstEleMVA5raw = makeEleTauPair(src,"againstElectronMVA5raw",'leg2.tauID("againstElectronMVA5raw")'),
                              eleTauAgainstElectronTightMVA5 = makeEleTauPair(src,"tauElectronTightMVA5",'leg2.tauID("againstElectronTightMVA5")'),
                              eleTauAgainstElectronVLooseMVA5 = makeEleTauPair(src,"tauElectronVLooseMVA5",'leg2.tauID("againstElectronVLooseMVA5")'),
                              #eleTauEleMVALoose = makeEleTauPair(src,"tauEleLoose",'leg2.userInt("againstEleMVALoose")'), #FIXME
                              #eleTauEleMVAMedium = makeEleTauPair(src,"tauEleMedium",'leg2.userInt("againstEleMVAMedium")'), #FIXME
                              #eleTauEleMVATight = makeEleTauPair(src,"tauEleTight",'leg2.userInt("againstEleMVATight")'), #FIXME
                              #eleTauEleMVAVeryTight = makeEleTauPair(src,"tauEleVeryTight",'leg2.userInt("againstEleMVAVeryTight")'), #FIXME

                              eleTauGenPt1 = makeEleTauPair(src,"genPt1",'p4Leg1gen().pt()'),
                              eleTauGenPt2 = makeEleTauPair(src,"genPt2",'p4Leg2gen().pt()'),
                              eleTauPdg1 = makeEleTauPair(src,"pdg1",'genPdg1()'),
                              eleTauPdg2 = makeEleTauPair(src,"pdg2",'genPdg2()'),
                              eleTauVisGenPt1 = makeEleTauPair(src,"genVisPt1",'p4VisLeg1gen().pt()'),
                              eleTauVisGenPt2 = makeEleTauPair(src,"genVisPt2",'p4VisLeg2gen().pt()'),
                              eleTauGenVisMass = makeEleTauPair(src,"genVisMass",'p4VisGen().M()'),
                              eleTauGenMassMatched = makeEleTauPair(src,"genFullMassMatched",'p4gen().M()'),
                              eleTauGenMass = makeEleTauPair(src,"fullGenMass",'genBosonMass()'),


                              #BJETS
                              #eleTauEventBTag = makeEleTauPair(src,"btag","EventBTag"),
                              #eleTauEventNBTags = makeEleTauPair(src,"NBTags","NBTags"),
                              #eleTauCSVL1 = makeEleTauPair(src,"EffWEIGHTCSVL",'SFCSVL1'),
                              #eleTauCSVL1err = makeEleTauPair(src,"EffWEIGHTCSVLerr",'SFCSVL1err'),
                              #eleTauCSVL2 = makeEleTauPair(src,"EffWEIGHTCSVL2",'SFCSVL2'),
                              #eleTauCSVL2err = makeEleTauPair(src,"EffWEIGHTCSVL2err",'SFCSVL2err'),
                              #eleTauCSVM1 = makeEleTauPair(src,"EffWEIGHTCSVM",'SFCSVM1'),
                              #eleTauCSVM1err = makeEleTauPair(src,"EffWEIGHTCSVMerr",'SFCSVM1err'),
                              #eleTauCSVM2 = makeEleTauPair(src,"EffWEIGHTCSVM2",'SFCSVM2'),
                              #eleTauCSVM2err = makeEleTauPair(src,"EffWEIGHTCSVM2err",'SFCSVM2err'),
                              #eleTauCSVT1 = makeEleTauPair(src,"EffWEIGHTCSVT",'SFCSVT1'),
                              #eleTauCSVT1err = makeEleTauPair(src,"EffWEIGHTCSVTerr",'SFCSVT1err'),
                              #eleTauCSVT2 = makeEleTauPair(src,"EffWEIGHTCSVT2",'SFCSVT2'),
                              #eleTauCSVT2err = makeEleTauPair(src,"EffWEIGHTCSVT2err",'SFCSVT2err'),

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



                              eleTauJetsPt20nbtag = makeEleTauJetCountPair(src,"nbjets",'pt()>30&&abs(eta)<2.4'),
                              eleTauJetsPt30njets = makeEleTauJetCountPair(src,"njets",'pt()>30&&abs(eta)<4.7'),
                              eleTauJetsPt20njets = makeEleTauJetCountPair(src,"njetspt20",'pt()>20&&abs(eta)<4.7'),



                              eleTauJet1PtPtSort = makeEleTauPtPair(src,"jpt_1",'abs(eta())<4.7&&pt()>20','pt()',0),
                              eleTauJet2PtPtSort = makeEleTauPtPair(src,"jpt_2",'abs(eta())<4.7&&pt()>20','pt()',1),
                              eleTauJet1EtaPtSort = makeEleTauPtPair(src,"jeta_1",'abs(eta())<4.7&&pt>20','eta()',0),
                              eleTauJet2EtaPtSort = makeEleTauPtPair(src,"jeta_2",'abs(eta())<4.7&&pt>20','eta()',1),
                              eleTauJet1PhiPtSort = makeEleTauPtPair(src,"jphi_1",'abs(eta())<4.7&&pt>20','phi()',0),
                              eleTauJet2PhiPtSort = makeEleTauPtPair(src,"jphi_2",'abs(eta())<4.7&&pt>20','phi()',1),
                              eleTauJet1FlavourPtSort = makeEleTauPtPair(src,"J1Flavour",'abs(eta())<2.4&&pt>0','partonFlavour()',0),
                              eleTauJet2FlavourPtSort = makeEleTauPtPair(src,"J2Flavour",'abs(eta())<2.4&&pt>0','partonFlavour()',1),
                              eleTauJet1CSVPtSort = makeEleTauPtPair(src,"J1CSVbtag",'abs(eta())<2.4','bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")',0),
                              eleTauJet2CSVPtSort = makeEleTauPtPair(src,"J2CSVbtag",'abs(eta())<2.4','bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")',1),
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

                              eleTauJetsBTagCSVLPt20 = makeEleTauJetCountPair(src,"nJetsBTagCSVLPt20",'bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.423&&pt()>20&&abs(eta)<2.4'),
                              eleTauJetsBTagCSVLPt25 = makeEleTauJetCountPair(src,"nJetsBTagCSVLPt25",'bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.423&&pt()>25&&abs(eta)<2.4'),
                              eleTauJetsBTagCSVMPt20 = makeEleTauJetCountPair(src,"nJetsBTagCSVMPt20",'bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.814&&pt()>20&&abs(eta)<2.4'),
                              eleTauJetsBTagCSVMPt25 = makeEleTauJetCountPair(src,"nJetsBTagCSVMPt25",'bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.814&&pt()>25&&abs(eta)<2.4'),
                              eleTauJetsBTagCSVTPt20 = makeEleTauJetCountPair(src,"nJetsBTagCSVTPt20",'bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.941&&pt()>20&&abs(eta)<2.4'),
                              eleTauJetsBTagCSVTPt25 = makeEleTauJetCountPair(src,"nJetsBTagCSVTPt25",'bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.941&&pt()>25&&abs(eta)<2.4'),
                              eleTauJetsPt20 = makeEleTauJetCountPair(src,"nJetsPt20",'pt()>20'),
                              eleTauJetsPt20Loose = makeEleTauJetCountPair(src,"nJetsPt20Loose",'pt()>20&&userFloat("idLoose")'),
                              eleTauJetsPt20Medium = makeEleTauJetCountPair(src,"nJetsPt20Medium",'pt()>20&&userFloat("idMedium")'),
                              eleTauJetsPt20Tight = makeEleTauJetCountPair(src,"nJetsPt20Tight",'pt()>20&&userFloat("idTight")'),

                              eleTauJetsPt20Tag = makeEleTauJetCountPair(src,"nTaggableJetsPt20",'pt()>20&&abs(eta)<2.4'),
                              eleTauJetsPt20TagMatch = makeEleTauJetCountPair(src,"nTaggableJetsPt20Matched",'pt()>20&&abs(eta)<2.4&&abs(partonFlavour)==5'),
                              eleTauJetsPt20TagMatchTag = makeEleTauJetCountPair(src,"nTaggableJetsPt20MatchedTagM",'pt()>20&&abs(eta)<2.4&&abs(partonFlavour)==5&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.814'),
                              eleTauJetsPt20TagNoMatch = makeEleTauJetCountPair(src,"nTaggableJetsPt20NotMatched",'pt()>30&&abs(eta)<2.4&&abs(partonFlavour)!=5'),
                              eleTauJetsPt20TagNoMatchTag = makeEleTauJetCountPair(src,"nTaggableJetsPt20NotMatchedTagM",'pt()>20&&abs(eta)<2.4&&abs(partonFlavour)!=5&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.814'),
                              eleTauJetsPt30 = makeEleTauJetCountPair(src,"nJetsPt30",'pt()>30'),
                              eleTauJetsPt30Tag = makeEleTauJetCountPair(src,"nbjets",'pt()>30&&abs(eta)<2.4'),
                              eleTauJetsPt30TagMatch = makeEleTauJetCountPair(src,"nTaggableJetsPt30Matched",'pt()>30&&abs(eta)<2.4&&abs(partonFlavour)==5'),
                              eleTauJetsPt30TagMatchTag = makeEleTauJetCountPair(src,"nTaggableJetsPt30MatchedTagM",'pt()>30&&abs(eta)<2.4&&abs(partonFlavour)==5&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.814'),
                              eleTauJetsPt30TagNoMatch = makeEleTauJetCountPair(src,"nTaggableJetsPt30NotMatched",'pt()>30&&abs(eta)<2.4&&abs(partonFlavour)!=5'),
                              eleTauJetsPt30TagNoMatchTag = makeEleTauJetCountPair(src,"nTaggableJetsPt30NotMatchedTagM",'pt()>30&&abs(eta)<2.4&&abs(partonFlavour)!=5&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>=0.814'),

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
                                  #src        = cms.InputTag("generator","minVisPtFilter"),
                                  tag        = cms.string("EmbWeight"),
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


