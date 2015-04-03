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
         pluginType  = cms.string("PATMuTauPairJetCountFiller"),
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
         pluginType  = cms.string("PATEleTauPairJetCountFiller"),
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
                              tauLeadChargedHadrTrackPtErr = makeMuTauPair(src,"tauLeadChargedHadrTrackPtErr","leg2.userFloat('leadPFTrackPtErr')"), #FIXME

                              mass2ES = makeMuTauPair(src,"mass2ES","leg2.userFloat('ESmass')"),#FILLED
                              pt2ES = makeMuTauPair(src,"pt2ES","leg2.userFloat('ESpt')"),#FILLED
                              pt2initial = makeMuTauPair(src,"pt2preES","leg2.userFloat('preESpt')"),#FILLED
                              phi2initial = makeMuTauPair(src,"phi2preES","leg2.userFloat('preESphi')"),#FILLED

                              muTauCharge = makeMuTauPair(src,"charge","charge"),#FILLED
                              charge1 = makeMuTauPair(src,"charge1","leg1.charge"),#FILLED
                              charge2 = makeMuTauPair(src,"charge2","leg2.charge"),#FILLED

                              muTauPt = makeMuTauPair(src,"pt","pt"),#FILLED
                              muTauHT = makeMuTauPair(src,"ht","ht"),#FILLED
                              muTauMass = makeMuTauPair(src,"mass","mass"),#FILLED
                              muTauSVPt = makeMuTauPair(src,"svPt","svPt"),#FIXME
                              muTauSVMass = makeMuTauPair(src,"svMass","svMass"),#FILLED

                              muTauFullPt = makeMuTauPair(src,"fullPt","fullPt"),#FILLED
                              muTauEta = makeMuTauPair(src,"fullEta","fullEta"),#FILLED
                              muTauPhi = makeMuTauPair(src,"fullPhi","fullPhi"),#FILLED
                              muTauE = makeMuTauPair(src,"fullEnergy","fullEnergy"),#FILLED

                              muTauPt1 =  makeMuTauPair(src,"pt1","leg1.pt"), #FILLED
                              muTauPt2 =  makeMuTauPair(src,"pt2","leg2.pt"), #FILLED
                              muTauEta1 = makeMuTauPair(src,"eta1","leg1.eta"),#FILLED
                              muTauEta2 = makeMuTauPair(src,"eta2","leg2.eta"),#FILLED
                              muTauPhi1 = makeMuTauPair(src,"phi1","leg1.phi"),#FILLED
                              muTauPhi2 = makeMuTauPair(src,"phi2","leg2.phi"),#FILLED

                              muTauMETUnc = makeMuTauPair(src,"metUnc","met.pt()"),#FILLED
                              muTauMET = makeMuTauPair(src,"met","calibratedMET.pt()"),#FILLED
                              METPhi = makeMuTauPair(src,"metPhi","metPhi"),#FILLED
                              CovMat00 = makeMuTauPair(src,"covMatrix00","covMatrix00"),#FILLED
                              CovMat10 = makeMuTauPair(src,"covMatrix10","covMatrix10"),#FILLED
                              CovMat01 = makeMuTauPair(src,"covMatrix01","covMatrix01"),#FILLED
                              CovMat11 = makeMuTauPair(src,"covMatrix11","covMatrix11"),#FILLED

                              muTauMT = makeMuTauPair(src,"mt","mt12MET"),#FILLED
                              muTauMT1 = makeMuTauPair(src,"mt1","mt1MET"),#FILLED
                              muTauMT2 = makeMuTauPair(src,"mt2","mt2MET"),#FILLED

                              #BTAGS AND JETS
                              muTauMJJReg = makeMuTauPair(src,"mJJReg","mJJReg"),#FIXME
                              muTauMJJ = makeMuTauPair(src,"mJJ","mJJ"),#FILLED
                              muTauJJPt = makeMuTauPair(src,"ptJJ","ptJJ"),
                              muTauJJEta = makeMuTauPair(src,"etaJJ","etaJJ"),
                              muTauJJPhi = makeMuTauPair(src,"phiJJ","phiJJ"),
                              muTauJJEnergy = makeMuTauPair(src,"energyJJ","energyJJ"),
                              muTauHMass = makeMuTauPair(src,"HMass","hhMass"),
                              muTauHMassReg = makeMuTauPair(src,"HMassReg","hhMassReg"),
                              muTauHPt = makeMuTauPair(src,"HPt","hhPt"),
                              muTauHEta = makeMuTauPair(src,"HEta","hhEta"),
                              muTauHPhi = makeMuTauPair(src,"HPhi","hhPhi"),
                              muTauHEnergy = makeMuTauPair(src,"HEnergy","hhE"),
                              muTauVBFDEta = makeMuTauPair(src,"vbfDEta","vbfDEta"),
                              muTauVBFMass = makeMuTauPair(src,"vbfMass","vbfMass"),
                              muMuVBFJets20 = makeMuTauPair(src,"vbfNJetsGap20","vbfNJetsGap20"),
                              muMuVBFJets30 = makeMuTauPair(src,"vbfNJetsGap30","vbfNJetsGap30"),

                              #Muon IDs and Isolation
                              muTauRelPFIsoDB = makeMuTauPair(src,"lPFIsoDB",'(leg1.userIso(0)+max(leg1.photonIso()+leg1.neutralHadronIso()-0.5*leg1.puChargedHadronIso,0.0))/leg1.pt()'),
                              muTauDecayMode = makeMuTauPair(src,"tauDecayMode",'leg2.decayMode()'),
                              muTauDecayFound = makeMuTauPair(src,"tauDecayFound",'leg2.tauID("decayModeFinding")'),
                              muTauMuTriggerMatch = makeMuTauPair(src,"lTrigger",'leg1.userFloat("hltOverlapFilterIsoMu17LooseIsoPFTau20")'),
                              muTauTauTriggerMatch = makeMuTauPair(src,"tauTrigger",'leg2.userFloat("hltOverlapFilterIsoMu17LooseIsoPFTau20")'),
                              muTauPzeta = makeMuTauPair(src,"pZeta",'pZeta-1.5*pZetaVis'),
                              muTauPZ = makeMuTauPair(src,"pZ",'pZeta'),
                              muTauPZV = makeMuTauPair(src,"pZV",'pZetaVis'),
                              muTauTauZIP = makeMuTauPair(src,"tauZIP",'leg2.userFloat("zIP")'),
                              muTauHadMass = makeMuTauPair(src,"tauMass",'leg2.mass()'),

                              muTauPFID = makeMuTauPair(src,"lPFId",'leg1.pfCandidateRef().isNonnull()'),#FIXME
                              muTauByCombIsoDBRaw3 = makeMuTauPair(src,"tauIso",'leg2.tauID("byCombinedIsolationDeltaBetaCorrRaw3Hits")'),
                              muTauAgainstMuonTight3 = makeMuTauPair(src,"againstMuonTight3",'leg2.tauID("againstMuonTight3")'),
                              muTauAgainstMuonTightFixed = makeMuTauPair(src,"againstMuTightFixed",'leg2.userInt("againstMuTightFixed")'),

                              muTauGenPt1 = makeMuTauPair(src,"genPt1",'p4Leg1gen().pt()'),
                              muTauGenPt2 = makeMuTauPair(src,"genPt2",'p4Leg2gen().pt()'),
                              muTauPdg1 = makeMuTauPair(src,"pdg1",'genPdg1()'),
                              muTauPdg2 = makeMuTauPair(src,"pdg2",'genPdg2()'),
                              muTauVisGenPt1 = makeMuTauPair(src,"genVisPt1",'p4VisLeg1gen().pt()'),
                              muTauVisGenPt2 = makeMuTauPair(src,"genVisPt2",'p4VisLeg2gen().pt()'),
                              muTauGenVisMass = makeMuTauPair(src,"genVisMass",'p4VisGen().M()'),
                              muTauGenMassMatched = makeMuTauPair(src,"genFullMassMatched",'p4gen().M()'),
                              muTauGenMass = makeMuTauPair(src,"fullGenMass",'genBosonMass()'),

                              #BJETS
                              muTauEventBTag = makeMuTauPair(src,"btag","EventBTag"),
                              muTauEventNBTags = makeMuTauPair(src,"NBTags","NBTags"),
                              muTauCSVL1 = makeMuTauPair(src,"EffWEIGHTCSVL",'SFCSVL1'),
                              muTauCSVL1err = makeMuTauPair(src,"EffWEIGHTCSVLerr",'SFCSVL1err'),
                              muTauCSVL2 = makeMuTauPair(src,"EffWEIGHTCSVL2",'SFCSVL2'),
                              muTauCSVL2err = makeMuTauPair(src,"EffWEIGHTCSVL2err",'SFCSVL2err'),
                              muTauCSVM1 = makeMuTauPair(src,"EffWEIGHTCSVM",'SFCSVM1'),
                              muTauCSVM1err = makeMuTauPair(src,"EffWEIGHTCSVMerr",'SFCSVM1err'),
                              muTauCSVM2 = makeMuTauPair(src,"EffWEIGHTCSVM2",'SFCSVM2'),
                              muTauCSVM2err = makeMuTauPair(src,"EffWEIGHTCSVM2err",'SFCSVM2err'),
                              muTauCSVT1 = makeMuTauPair(src,"EffWEIGHTCSVT",'SFCSVT1'),
                              muTauCSVT1err = makeMuTauPair(src,"EffWEIGHTCSVTerr",'SFCSVT1err'),
                              muTauCSVT2 = makeMuTauPair(src,"EffWEIGHTCSVT2",'SFCSVT2'),
                              muTauCSVT2err = makeMuTauPair(src,"EffWEIGHTCSVT2err",'SFCSVT2err'),

                              muTauJet1Muf = makeMuTauCSVPair(src,"J1Muf",'abs(eta())<2.4','muonEnergyFraction()',0),
                              muTauJet2Muf = makeMuTauCSVPair(src,"J2Muf",'abs(eta())<2.4','muonEnergyFraction()',1),
                              muTauJet1Nhf = makeMuTauCSVPair(src,"J1Nhf",'abs(eta())<2.4','neutralHadronEnergyFraction()',0),
                              muTauJet2Nhf = makeMuTauCSVPair(src,"J2Nhf",'abs(eta())<2.4','neutralHadronEnergyFraction()',1),
                              muTauJet1Phf = makeMuTauCSVPair(src,"J1Phf",'abs(eta())<2.4','photonEnergyFraction()',0),
                              muTauJet2Phf = makeMuTauCSVPair(src,"J2Phf",'abs(eta())<2.4','photonEnergyFraction()',1),
                              muTauJet1PtCSVSort = makeMuTauCSVPair(src,"J1PtCSVSort",'abs(eta())<2.4','pt()',0),
                              muTauJet2PtCSVSort = makeMuTauCSVPair(src,"J2PtCSVSort",'abs(eta())<2.4','pt()',1),
                              muTauJet1EtaCSVSort = makeMuTauCSVPair(src,"J1EtaCSVSort",'abs(eta())<2.4','eta()',0),
                              muTauJet2EtaCSVSort = makeMuTauCSVPair(src,"J2EtaCSVSort",'abs(eta())<2.4','eta()',1),
                              muTauJet1PhiCSVSort = makeMuTauCSVPair(src,"J1PhiCSVSort",'abs(eta())<2.4','phi()',0),
                              muTauJet2PhiCSVSort = makeMuTauCSVPair(src,"J2PhiCSVSort",'abs(eta())<2.4','phi()',1),
                              muTauJet1FlavourCSVSort = makeMuTauCSVPair(src,"J1FlavourCSVSort",'abs(eta())<2.4','partonFlavour()',0),
                              muTauJet2FlavourCSVSort = makeMuTauCSVPair(src,"J2FlavourCSVSort",'abs(eta())<2.4','partonFlavour()',1),
                              muTauJet1CSVCSVSort = makeMuTauCSVPair(src,"J1CSVbtagCSVSort",'abs(eta())<2.4','bDiscriminator("combinedInclusiveSecondaryVertexV2BJetTags")',0),
                              muTauJet2CSVCSVSort = makeMuTauCSVPair(src,"J2CSVbtagCSVSort",'abs(eta())<2.4','bDiscriminator("combinedInclusiveSecondaryVertexV2BJetTags")',1),

                              muTauJet1PtPtSort = makeMuTauPtPair(src,"J1Pt",'abs(eta())<2.4','pt()',0),
                              muTauJet2PtPtSort = makeMuTauPtPair(src,"J2Pt",'abs(eta())<2.4','pt()',1),
                              muTauJet1EtaPtSort = makeMuTauPtPair(src,"J1Eta",'abs(eta())<2.4','eta()',0),
                              muTauJet2EtaPtSort = makeMuTauPtPair(src,"J2Eta",'abs(eta())<2.4','eta()',1),
                              muTauJet1PhiPtSort = makeMuTauPtPair(src,"J1Phi",'abs(eta())<2.4','phi()',0),
                              muTauJet2PhiPtSort = makeMuTauPtPair(src,"J2Phi",'abs(eta())<2.4','phi()',1),
                              muTauJet1FlavourPtSort = makeMuTauPtPair(src,"J1Flavour",'abs(eta())<2.4','partonFlavour()',0),
                              muTauJet2FlavourPtSort = makeMuTauPtPair(src,"J2Flavour",'abs(eta())<2.4','partonFlavour()',1),
                              muTauJet1CSVPtSort = makeMuTauPtPair(src,"J1CSVbtag",'abs(eta())<2.4','bDiscriminator("combinedInclusiveSecondaryVertexV2BJetTags")',0),
                              muTauJet2CSVPtSort = makeMuTauPtPair(src,"J2CSVbtag",'abs(eta())<2.4','bDiscriminator("combinedInclusiveSecondaryVertexV2BJetTags")',1),
                              muTauJet1MVASfPtSort = makeMuTauPtPair(src,"J1MVASf",'','userFloat("mvaSF")',0),
                              muTauJet2MVASfPtSort = makeMuTauPtPair(src,"J2MVASf",'','userFloat("mvaSF")',1),
                              muTauJet1GenPtPtSort = makeMuTauPtPair(src,"J1GenPt",'','userFloat("genJetPt")',0),
                              muTauJet2GenPtPtSort = makeMuTauPtPair(src,"J2GenPt",'','userFloat("genJetPt")',1),
                              muTauJet1GenEtaPtSort = makeMuTauPtPair(src,"J1GenEta",'','userFloat("genJetEta")',0),
                              muTauJet2GenEtaPtSort = makeMuTauPtPair(src,"J2GenEta",'','userFloat("genJetEta")',1),
                              muTauJet1GenPhiPtSort = makeMuTauPtPair(src,"J1GenPhi",'','userFloat("genJetPhi")',0),
                              muTauJet2GenPhiPtSort = makeMuTauPtPair(src,"J2GenPhi",'','userFloat("genJetPhi")',1),

                              muTauJetsBTagCSVLPt20 = makeMuTauJetCountPair(src,"nJetsBTagCSVLPt20",'bDiscriminator("combinedInclusiveSecondaryVertexV2BJetTags")>=0.423&&pt()>20&&abs(eta)<2.4'),
                              muTauJetsBTagCSVLPt25 = makeMuTauJetCountPair(src,"nJetsBTagCSVLPt25",'bDiscriminator("combinedInclusiveSecondaryVertexV2BJetTags")>=0.423&&pt()>25&&abs(eta)<2.4'),
                              muTauJetsBTagCSVMPt20 = makeMuTauJetCountPair(src,"nJetsBTagCSVMPt20",'bDiscriminator("combinedInclusiveSecondaryVertexV2BJetTags")>=0.814&&pt()>20&&abs(eta)<2.4'),
                              muTauJetsBTagCSVMPt25 = makeMuTauJetCountPair(src,"nJetsBTagCSVMPt25",'bDiscriminator("combinedInclusiveSecondaryVertexV2BJetTags")>=0.814&&pt()>25&&abs(eta)<2.4'),
                              muTauJetsBTagCSVTPt20 = makeMuTauJetCountPair(src,"nJetsBTagCSVTPt20",'bDiscriminator("combinedInclusiveSecondaryVertexV2BJetTags")>=0.941&&pt()>20&&abs(eta)<2.4'),
                              muTauJetsBTagCSVTPt25 = makeMuTauJetCountPair(src,"nJetsBTagCSVTPt25",'bDiscriminator("combinedInclusiveSecondaryVertexV2BJetTags")>=0.941&&pt()>25&&abs(eta)<2.4'),
                              muTauJetsPt20 = makeMuTauJetCountPair(src,"nJetsPt20",'pt()>20'),
                              muTauJetsPt20Tag = makeMuTauJetCountPair(src,"nTaggableJetsPt20",'pt()>20&&abs(eta)<2.4'),
                              muTauJetsPt20TagMatch = makeMuTauJetCountPair(src,"nTaggableJetsPt20Matched",'pt()>20&&abs(eta)<2.4&&abs(partonFlavour)==5'),
                              muTauJetsPt20TagMatchTag = makeMuTauJetCountPair(src,"nTaggableJetsPt20MatchedTagM",'pt()>20&&abs(eta)<2.4&&abs(partonFlavour)==5&&bDiscriminator("combinedInclusiveSecondaryVertexV2BJetTags")>=0.814'),
                              muTauJetsPt20TagNoMatch = makeMuTauJetCountPair(src,"nTaggableJetsPt20NotMatched",'pt()>30&&abs(eta)<2.4&&abs(partonFlavour)!=5'),
                              muTauJetsPt20TagNoMatchTag = makeMuTauJetCountPair(src,"nTaggableJetsPt20NotMatchedTagM",'pt()>20&&abs(eta)<2.4&&abs(partonFlavour)!=5&&bDiscriminator("combinedInclusiveSecondaryVertexV2BJetTags")>=0.814'),
                              muTauJetsPt30 = makeMuTauJetCountPair(src,"nJetsPt30",'pt()>30'),
                              muTauJetsPt30Tag = makeMuTauJetCountPair(src,"nTaggableJetsPt30",'pt()>30&&abs(eta)<2.4'),
                              muTauJetsPt30TagMatch = makeMuTauJetCountPair(src,"nTaggableJetsPt30Matched",'pt()>30&&abs(eta)<2.4&&abs(partonFlavour)==5'),
                              muTauJetsPt30TagMatchTag = makeMuTauJetCountPair(src,"nTaggableJetsPt30MatchedTagM",'pt()>30&&abs(eta)<2.4&&abs(partonFlavour)==5&&bDiscriminator("combinedInclusiveSecondaryVertexV2BJetTags")>=0.814'),
                              muTauJetsPt30TagNoMatch = makeMuTauJetCountPair(src,"nTaggableJetsPt30NotMatched",'pt()>30&&abs(eta)<2.4&&abs(partonFlavour)!=5'),
                              muTauJetsPt30TagNoMatchTag = makeMuTauJetCountPair(src,"nTaggableJetsPt30NotMatchedTagM",'pt()>30&&abs(eta)<2.4&&abs(partonFlavour)!=5&&bDiscriminator("combinedInclusiveSecondaryVertexV2BJetTags")>=0.814'),

                              muTauFirstJetID53X = makeLTauGeneric("PATMuTauPairHighestPtJetVarFiller",src,"highestJetID53X","userFloat('pileupJetId:fullDiscriminant')"), 
                              muTauFirstJetFlavour = makeLTauGeneric("PATMuTauPairHighestPtJetVarFiller",src,"highestJetFlavour",'partonFlavour()'),
                              muTauFirstJetShape = makeLTauGeneric("PATMuTauPairHighestPtJetVarFiller",src,"highestJetShape",'userFloat("ptRMS")'),
                              muTauFirstJetCSV = makeLTauGeneric("PATMuTauPairHighestPtJetVarFiller",src,"highestJetBTagCSV",'bDiscriminator("combinedInclusiveSecondaryVertexV2BJetTags")'),
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
                              ),#FILLED in higgs sample
                              muTauLHEProduct2 = cms.PSet(
                                  pluginType = cms.string("LHEProductFiller"),
                                  src        = cms.InputTag("externalLHEProducer"),
                                  tag        = cms.string("LHEProduct2"),
                              ),#FIXME
                              muTauEmbedPtWeight = cms.PSet(
                                  pluginType = cms.string("GenFilterInfoWeightFiller"),
                                  src        = cms.InputTag("generator","minVisPtFilter"),
                                  tag        = cms.string("EmbPtWeight"),
                              ),#FIXME #CHECKME
                              muTauEmbedPt = cms.PSet(
                                  pluginType = cms.string("PATGenParticleFiller"),
                                  src        = cms.InputTag("genDaughters"),
                                  tag        = cms.string("embeddedPt"),
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

                              eleTauSize = makeCollSize(srcU,"nCands"),
                              eleEleSize = makeCollSize(srcLL,"diLeptons"),
                              genTaus = makeCollSize("genTausCands","genTaus"),
 
                              tauNIsoTracks =  makeEleTauPair(src,"tauNIsoTracks","leg2.userFloat('nIsoTracks')"), #FILLED
                              tauNMatchedSeg =  makeEleTauPair(src,"tauMuonNMatchedSeg","leg2.userFloat('muonNMatchedSeg')"), #FILLED
                              tauTauHadMatched = makeEleTauPair(src,"tauMuonMatched","leg2.userFloat('muonTauHadMatched')"),
                              tauLeadChargedHadrTrackPt = makeEleTauPair(src,"tauLeadChargedHadrTrackPt","leg2.userFloat('leadChargedHadrTrackPt')"),
                              tauLeadChargedHadrTrackPtErr = makeEleTauPair(src,"tauLeadChargedHadrTrackPtErr","leg2.userFloat('leadPFTrackPtErr')"), #FIXME

                              mass2ES = makeEleTauPair(src,"mass2ES","leg2.userFloat('ESmass')"),
                              pt2ES = makeEleTauPair(src,"pt2ES","leg2.userFloat('ESpt')"),
                              eleTauPt2initial = makeEleTauPair(src,"pt2preES","leg2.userFloat('preESpt')"),
                              eleTauPhi2initial = makeEleTauPair(src,"phi2preES","leg2.userFloat('preESphi')"),

                              eleTauCharge = makeEleTauPair(src,"charge","charge"),
                              eleTauCharge1 = makeEleTauPair(src,"charge1","leg1.charge"),
                              eleTauCharge2 = makeEleTauPair(src,"charge2","leg2.charge"),

                              eleTauPt = makeEleTauPair(src,"pt","pt"),
                              eleTauHT = makeEleTauPair(src,"ht","ht"),
                              eleTauMass = makeEleTauPair(src,"mass","mass"),
                              eleTauSVPt = makeEleTauPair(src,"svPt","svPt"),
                              eleTauSVMass = makeEleTauPair(src,"svMass","svMass"),

                              eleTauFullPt = makeEleTauPair(src,"fullPt","fullPt"),
                              eleTauEta = makeEleTauPair(src,"fullEta","fullEta"),
                              eleTauPhi = makeEleTauPair(src,"fullPhi","fullPhi"),
                              eleTauE = makeEleTauPair(src,"fullEnergy","fullEnergy"),

                              eleTauPt1 =  makeEleTauPair(src,"pt1","leg1.pt"), #FILLED
                              eleTauPt2 =  makeEleTauPair(src,"pt2","leg2.pt"), #FILLED
                              eleTauEta1 = makeEleTauPair(src,"eta1","leg1.eta"),
                              eleTauSCEta1 = makeEleTauPair(src,"eta1","leg1.superCluster().eta()"),
                              eleTauEta2 = makeEleTauPair(src,"eta2","leg2.eta"),
                              eleTauPhi1 = makeEleTauPair(src,"phi1","leg1.phi"),
                              eleTauPhi2 = makeEleTauPair(src,"phi2","leg2.phi"),

                              eleTauMETUnc = makeEleTauPair(src,"metUnc","met.pt()"),
                              eleTauMET = makeEleTauPair(src,"met","calibratedMET.pt()"),
                              eleTauMETPhi = makeEleTauPair(src,"metPhi","metPhi"),
                              eleTauCovMat00 = makeEleTauPair(src,"covMatrix00","covMatrix00"),
                              eleTauCovMat10 = makeEleTauPair(src,"covMatrix10","covMatrix10"),
                              eleTauCovMat01 = makeEleTauPair(src,"covMatrix01","covMatrix01"),
                              eleTauCovMat11 = makeEleTauPair(src,"covMatrix11","covMatrix11"),

                              eleTauMT = makeEleTauPair(src,"mt","mt12MET"),
                              eleTauMT1 = makeEleTauPair(src,"mt1","mt1MET"),
                              eleTauMT2 = makeEleTauPair(src,"mt2","mt2MET"),

                              #BTAGS AND JETS
                              eleTauMJJReg = makeEleTauPair(src,"mJJReg","mJJReg"),
                              eleTauMJJ = makeEleTauPair(src,"mJJ","mJJ"),
                              eleTauJJPt = makeEleTauPair(src,"ptJJ","ptJJ"),
                              eleTauJJEta = makeEleTauPair(src,"etaJJ","etaJJ"),
                              eleTauJJPhi = makeEleTauPair(src,"phiJJ","phiJJ"),
                              eleTauJJEnergy = makeEleTauPair(src,"energyJJ","energyJJ"),
                              eleTauHMass = makeEleTauPair(src,"HMass","hhMass"),
                              eleTauHMassReg = makeEleTauPair(src,"HMassReg","hhMassReg"),
                              eleTauHPt = makeEleTauPair(src,"HPt","hhPt"),
                              eleTauHEta = makeEleTauPair(src,"HEta","hhEta"),
                              eleTauHPhi = makeEleTauPair(src,"HPhi","hhPhi"),
                              eleTauHEnergy = makeEleTauPair(src,"HEnergy","hhE"),
                              eleTauVBFDEta = makeEleTauPair(src,"vbfDEta","vbfDEta"),
                              eleTauVBFDPhi = makeEleTauPair(src,"vbfDPhi","vbfDPhi"),#EO
                              eleTauVBFMass = makeEleTauPair(src,"vbfMass","vbfMass"),
                              muMuVBFJets20 = makeEleTauPair(src,"vbfNJetsGap20","vbfNJetsGap20"),
                              muMuVBFJets30 = makeEleTauPair(src,"vbfNJetsGap30","vbfNJetsGap30"),

                              #ETAU ONLY
                              eleTauDZ = makeEleTauPair(src,"dz",'abs(leg1.userFloat("vz")-leg2.userFloat("vz"))'),#EO
                              eleTauEleDZ = makeEleTauPair(src,"l1dz",'leg1.userFloat("dz")'),#EO
                              eleTauTauDZ = makeEleTauPair(src,"l2dz",'leg2.userFloat("dz")'),#EO
                              eleTauDPhi = makeEleTauPair(src,"dPhi12",'dPhi12'),
                              eleTauDPhi1MET = makeEleTauPair(src,"dPhi1MET",'dPhi1MET'),
                              eleTauDPhi2MET = makeEleTauPair(src,"dPhi2MET",'dPhi2MET'),
                              eleTauPzeta = makeEleTauPair(src,"pZeta",'pZeta-1.5*pZetaVis'),#EO
                              eleTauPZ = makeEleTauPair(src,"pZ",'pZeta'),#EO
                              eleTauPZV = makeEleTauPair(src,"pZV",'pZetaVis'),#EO

                              #Ele IDs and Isolation
                              eleTauRelPFIsoDB = makeEleTauPair(src,"lPFIsoDB",'(leg1.userIso(0)+max(leg1.userIso(1)+leg1.neutralHadronIso()-0.5*leg1.userIso(2),0.0))/leg1.pt()'),
                              eleTauDecayMode = makeEleTauPair(src,"tauDecayMode",'leg2.decayMode()'),
                              eleTauDecayFound = makeEleTauPair(src,"tauDecayFound",'leg2.tauID("decayModeFinding")'),
                              eleTauProngs = makeEleTauPair(src,"tauProngs",'leg2.signalChargedHadrCands.size()'),#EO
                              eleTauMuTriggerMatch = makeEleTauPair(src,"lTrigger",'leg1.userFloat("hltOverlapFilterIsoEle22WP85GsfLooseIsoPFTau20")'),
                              eleTauTauTriggerMatch = makeEleTauPair(src,"tauTrigger",'leg2.userFloat("hltOverlapFilterIsoEle22WP85GsfLooseIsoPFTau20")'),
                              eleTauTauZIP = makeEleTauPair(src,"tauZIP",'leg2.userFloat("zIP")'),
                              eleTauHadMass = makeEleTauPair(src,"tauMass",'leg2.mass()'),
                              eleTauPFID = makeEleTauPair(src,"lPFId",'leg1.pfCandidateRef().isNonnull()'),#FIXME
                              eleTauByCombIsoDBRaw3 = makeEleTauPair(src,"tauIso",'leg2.tauID("byCombinedIsolationDeltaBetaCorrRaw3Hits")'),

                              eleTauAgainstElectronTight = makeEleTauPair(src,"againstElectronTight",'leg2.tauID("againstElectronTight")'),
                              eleTauAgainstMuonTight3 = makeEleTauPair(src,"againstMuonTight3",'leg2.tauID("againstMuonTight3")'),
                              eleTauAgainstMuonLoose3 = makeEleTauPair(src,"againstMuonLoose3",'leg2.tauID("againstMuonLoose3")'),
                              eleTauMVATrig = makeEleTauPair(src,"lIDMVATrig",'leg1.electronID("eidTight")'),#FIXME #PLACEHOLDER
                              eleTauMVANonTrig = makeEleTauPair(src,"lIDMVANonTrig",'leg1.electronID("eidTight")'),#FIXME #PLACEHOLDER
                              eleTauConversion = makeEleTauPair(src,"eMatchedConversion",'leg1.userInt("hasMatchedConversion")'),#FIXME
                              eleTauPassConversion = makeEleTauPair(src,"ePassConversion",'leg1.passConversionVeto()'),#FIXME
                              eleTauAgainstElectronMedium = makeEleTauPair(src,"tauElectronMedPass",'leg2.tauID("againstElectronMedium")'),
                              eleTauAgainstEleMVA5raw = makeEleTauPair(src,"againstElectronMVA5raw",'leg2.tauID("againstElectronMVA5raw")'),
                              eleTauElectronTightMVA5 = makeEleTauPair(src,"tauElectronTightMVA5",'leg2.tauID("againstElectronTightMVA5")'),
                              eleTauEleMVALoose = makeEleTauPair(src,"tauEleLoose",'leg2.userInt("againstEleMVALoose")'),
                              eleTauEleMVAMedium = makeEleTauPair(src,"tauEleMedium",'leg2.userInt("againstEleMVAMedium")'),
                              eleTauEleMVATight = makeEleTauPair(src,"tauEleTight",'leg2.userInt("againstEleMVATight")'),
                              eleTauEleMVAVeryTight = makeEleTauPair(src,"tauEleVeryTight",'leg2.userInt("againstEleMVAVeryTight")'),

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
                              eleTauEventBTag = makeEleTauPair(src,"btag","EventBTag"),
                              eleTauEventNBTags = makeEleTauPair(src,"NBTags","NBTags"),
                              eleTauCSVL1 = makeEleTauPair(src,"EffWEIGHTCSVL",'SFCSVL1'),
                              eleTauCSVL1err = makeEleTauPair(src,"EffWEIGHTCSVLerr",'SFCSVL1err'),
                              eleTauCSVL2 = makeEleTauPair(src,"EffWEIGHTCSVL2",'SFCSVL2'),
                              eleTauCSVL2err = makeEleTauPair(src,"EffWEIGHTCSVL2err",'SFCSVL2err'),
                              eleTauCSVM1 = makeEleTauPair(src,"EffWEIGHTCSVM",'SFCSVM1'),
                              eleTauCSVM1err = makeEleTauPair(src,"EffWEIGHTCSVMerr",'SFCSVM1err'),
                              eleTauCSVM2 = makeEleTauPair(src,"EffWEIGHTCSVM2",'SFCSVM2'),
                              eleTauCSVM2err = makeEleTauPair(src,"EffWEIGHTCSVM2err",'SFCSVM2err'),
                              eleTauCSVT1 = makeEleTauPair(src,"EffWEIGHTCSVT",'SFCSVT1'),
                              eleTauCSVT1err = makeEleTauPair(src,"EffWEIGHTCSVTerr",'SFCSVT1err'),
                              eleTauCSVT2 = makeEleTauPair(src,"EffWEIGHTCSVT2",'SFCSVT2'),
                              eleTauCSVT2err = makeEleTauPair(src,"EffWEIGHTCSVT2err",'SFCSVT2err'),

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
                              eleTauJet1CSVCSVSort = makeEleTauCSVPair(src,"J1CSVbtagCSVSort",'abs(eta())<2.4','bDiscriminator("combinedInclusiveSecondaryVertexV2BJetTags")',0),
                              eleTauJet2CSVCSVSort = makeEleTauCSVPair(src,"J2CSVbtagCSVSort",'abs(eta())<2.4','bDiscriminator("combinedInclusiveSecondaryVertexV2BJetTags")',1),

                              eleTauJet1PtPtSort = makeEleTauPtPair(src,"J1Pt",'abs(eta())<2.4','pt()',0),
                              eleTauJet2PtPtSort = makeEleTauPtPair(src,"J2Pt",'abs(eta())<2.4','pt()',1),
                              eleTauJet1EtaPtSort = makeEleTauPtPair(src,"J1Eta",'abs(eta())<2.4','eta()',0),
                              eleTauJet2EtaPtSort = makeEleTauPtPair(src,"J2Eta",'abs(eta())<2.4','eta()',1),
                              eleTauJet1PhiPtSort = makeEleTauPtPair(src,"J1Phi",'abs(eta())<2.4','phi()',0),
                              eleTauJet2PhiPtSort = makeEleTauPtPair(src,"J2Phi",'abs(eta())<2.4','phi()',1),
                              eleTauJet1FlavourPtSort = makeEleTauPtPair(src,"J1Flavour",'abs(eta())<2.4','partonFlavour()',0),
                              eleTauJet2FlavourPtSort = makeEleTauPtPair(src,"J2Flavour",'abs(eta())<2.4','partonFlavour()',1),
                              eleTauJet1CSVPtSort = makeEleTauPtPair(src,"J1CSVbtag",'abs(eta())<2.4','bDiscriminator("combinedInclusiveSecondaryVertexV2BJetTags")',0),
                              eleTauJet2CSVPtSort = makeEleTauPtPair(src,"J2CSVbtag",'abs(eta())<2.4','bDiscriminator("combinedInclusiveSecondaryVertexV2BJetTags")',1),
                              eleTauJet1MVASfPtSort = makeEleTauPtPair(src,"J1MVASf",'','userFloat("mvaSF")',0),
                              eleTauJet2MVASfPtSort = makeEleTauPtPair(src,"J2MVASf",'','userFloat("mvaSF")',1),
                              eleTauJet1GenPtPtSort = makeEleTauPtPair(src,"J1GenPt",'','userFloat("genJetPt")',0),
                              eleTauJet2GenPtPtSort = makeEleTauPtPair(src,"J2GenPt",'','userFloat("genJetPt")',1),
                              eleTauJet1GenEtaPtSort = makeEleTauPtPair(src,"J1GenEta",'','userFloat("genJetEta")',0),
                              eleTauJet2GenEtaPtSort = makeEleTauPtPair(src,"J2GenEta",'','userFloat("genJetEta")',1),
                              eleTauJet1GenPhiPtSort = makeEleTauPtPair(src,"J1GenPhi",'','userFloat("genJetPhi")',0),
                              eleTauJet2GenPhiPtSort = makeEleTauPtPair(src,"J2GenPhi",'','userFloat("genJetPhi")',1),

                              eleTauJetsBTagCSVLPt20 = makeEleTauJetCountPair(src,"nJetsBTagCSVLPt20",'bDiscriminator("combinedInclusiveSecondaryVertexV2BJetTags")>=0.423&&pt()>20&&abs(eta)<2.4'),
                              eleTauJetsBTagCSVLPt25 = makeEleTauJetCountPair(src,"nJetsBTagCSVLPt25",'bDiscriminator("combinedInclusiveSecondaryVertexV2BJetTags")>=0.423&&pt()>25&&abs(eta)<2.4'),
                              eleTauJetsBTagCSVMPt20 = makeEleTauJetCountPair(src,"nJetsBTagCSVMPt20",'bDiscriminator("combinedInclusiveSecondaryVertexV2BJetTags")>=0.814&&pt()>20&&abs(eta)<2.4'),
                              eleTauJetsBTagCSVMPt25 = makeEleTauJetCountPair(src,"nJetsBTagCSVMPt25",'bDiscriminator("combinedInclusiveSecondaryVertexV2BJetTags")>=0.814&&pt()>25&&abs(eta)<2.4'),
                              eleTauJetsBTagCSVTPt20 = makeEleTauJetCountPair(src,"nJetsBTagCSVTPt20",'bDiscriminator("combinedInclusiveSecondaryVertexV2BJetTags")>=0.941&&pt()>20&&abs(eta)<2.4'),
                              eleTauJetsBTagCSVTPt25 = makeEleTauJetCountPair(src,"nJetsBTagCSVTPt25",'bDiscriminator("combinedInclusiveSecondaryVertexV2BJetTags")>=0.941&&pt()>25&&abs(eta)<2.4'),
                              eleTauJetsPt20 = makeEleTauJetCountPair(src,"nJetsPt20",'pt()>20'),
                              eleTauJetsPt20Tag = makeEleTauJetCountPair(src,"nTaggableJetsPt20",'pt()>20&&abs(eta)<2.4'),
                              eleTauJetsPt20TagMatch = makeEleTauJetCountPair(src,"nTaggableJetsPt20Matched",'pt()>20&&abs(eta)<2.4&&abs(partonFlavour)==5'),
                              eleTauJetsPt20TagMatchTag = makeEleTauJetCountPair(src,"nTaggableJetsPt20MatchedTagM",'pt()>20&&abs(eta)<2.4&&abs(partonFlavour)==5&&bDiscriminator("combinedInclusiveSecondaryVertexV2BJetTags")>=0.814'),
                              eleTauJetsPt20TagNoMatch = makeEleTauJetCountPair(src,"nTaggableJetsPt20NotMatched",'pt()>30&&abs(eta)<2.4&&abs(partonFlavour)!=5'),
                              eleTauJetsPt20TagNoMatchTag = makeEleTauJetCountPair(src,"nTaggableJetsPt20NotMatchedTagM",'pt()>20&&abs(eta)<2.4&&abs(partonFlavour)!=5&&bDiscriminator("combinedInclusiveSecondaryVertexV2BJetTags")>=0.814'),
                              eleTauJetsPt30 = makeEleTauJetCountPair(src,"nJetsPt30",'pt()>30'),
                              eleTauJetsPt30Tag = makeEleTauJetCountPair(src,"nTaggableJetsPt30",'pt()>30&&abs(eta)<2.4'),
                              eleTauJetsPt30TagMatch = makeEleTauJetCountPair(src,"nTaggableJetsPt30Matched",'pt()>30&&abs(eta)<2.4&&abs(partonFlavour)==5'),
                              eleTauJetsPt30TagMatchTag = makeEleTauJetCountPair(src,"nTaggableJetsPt30MatchedTagM",'pt()>30&&abs(eta)<2.4&&abs(partonFlavour)==5&&bDiscriminator("combinedInclusiveSecondaryVertexV2BJetTags")>=0.814'),
                              eleTauJetsPt30TagNoMatch = makeEleTauJetCountPair(src,"nTaggableJetsPt30NotMatched",'pt()>30&&abs(eta)<2.4&&abs(partonFlavour)!=5'),
                              eleTauJetsPt30TagNoMatchTag = makeEleTauJetCountPair(src,"nTaggableJetsPt30NotMatchedTagM",'pt()>30&&abs(eta)<2.4&&abs(partonFlavour)!=5&&bDiscriminator("combinedInclusiveSecondaryVertexV2BJetTags")>=0.814'),

                              eleTauFirstJetID53X = makeLTauGeneric("PATEleTauPairHighestPtJetVarFiller",src,"highestJetID53X","userFloat('pileupJetId:fullDiscriminant')"), 
                              eleTauFirstJetFlavour = makeLTauGeneric("PATEleTauPairHighestPtJetVarFiller",src,"highestJetFlavour",'partonFlavour()'),
                              eleTauFirstJetShape = makeLTauGeneric("PATEleTauPairHighestPtJetVarFiller",src,"highestJetShape",'userFloat("ptRMS")'),
                              eleTauFirstJetCSV = makeLTauGeneric("PATEleTauPairHighestPtJetVarFiller",src,"highestJetBTagCSV",'bDiscriminator("combinedInclusiveSecondaryVertexV2BJetTags")'),
                              eleTauFirstJetChMult = makeLTauGeneric("PATEleTauPairHighestPtJetVarFiller",src,"highestJetNCharged",'chargedMultiplicity()'),
                              eleTauFirstJetNeuMult = makeLTauGeneric("PATEleTauPairHighestPtJetVarFiller",src,"highestJetNNeutral",'photonMultiplicity()+neutralHadronMultiplicity()'),

                              eeDR = makeLTauGeneric("PATElePairFiller",srcLL,"diLeptonDR","dR12"),#FIXME

                              eleTauLHEProduct = cms.PSet(
                                  pluginType = cms.string("LHEProductFiller"),
                                  src        = cms.InputTag("source"),
                                  tag        = cms.string("LHEProduct"),
                              ),
                              eleTauLHEProduct2 = cms.PSet(
                                  pluginType = cms.string("LHEProductFiller"),
                                  src        = cms.InputTag("externalLHEProducer"),
                                  tag        = cms.string("LHEProduct2"),
                              ),
                              eleTauEmbedPtWeight = cms.PSet(
                                  pluginType = cms.string("GenFilterInfoWeightFiller"),
                                  src        = cms.InputTag("generator","minVisPtFilter"),
                                  tag        = cms.string("EmbPtWeight"),
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
                                  tag        = cms.string("embeddedPt"),
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


