import FWCore.ParameterSet.Config as cms

from UWAnalysis.Configuration.tools.analysisToolsPT import TriggerPaths

def addMuNuEventTreeCSV(process,name,src = 'wCandsJets'):
   process.TFileService = cms.Service("TFileService", fileName = cms.string("analysis.root") )
   eventTree = cms.EDAnalyzer('EventTreeMaker',
                              coreCollections = cms.VInputTag(
                                   cms.InputTag(src)
                              ),
                              PVs = cms.PSet(
                                    pluginType = cms.string("VertexSizeFiller"),
                                    src        = cms.InputTag("primaryVertexFilter"),
                                    tag        = cms.string("vertices")
                              ),
                              trigger = cms.PSet(
                                  pluginType = cms.string("TriggerFiller"),
                                  src        = cms.InputTag("patTrigger"),
                                  paths      = cms.vstring(TriggerPaths)
                              ),
                               muNuDZ = cms.PSet(
                                     pluginType = cms.string("PATMuonNuPairFiller"),
                                     src        = cms.InputTag(src),
                                     tag        = cms.string("dz"),
                                     method     = cms.string('abs(lepton.userFloat("dz"))'),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
                               genWs = cms.PSet(
                                     pluginType = cms.string("CollectionSizeFiller"),
                                     src        = cms.InputTag("genWs"),
                                     tag        = cms.string("genWs"),
                               ),
                               muNuFirstJetFlavor = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1JetParton"),
                                   method     = cms.string('partonFlavour()'),
                                   rank       = cms.string('first')
                               ),
                               muNuFirstMuonMulti = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1MuonMulti"),
                                   method     = cms.string('muonMultiplicity()'),
                                   rank       = cms.string('first')
                               ),
                               muNuSecondMuonMulti = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2MuonMulti"),
                                   method     = cms.string('muonMultiplicity()'),
                                   rank       = cms.string('second')
                               ),
                               muNuThirdMuonMulti = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J3MuonMulti"),
                                   method     = cms.string('muonMultiplicity()'),
                                   rank       = cms.string('third')
                               ),
                               muNuFirstChargeMulti = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1ChargeMulti"),
                                  method     = cms.string('chargedMultiplicity()'),
                                  rank       = cms.string('first')
                              ),
                              muNuSecondChargeMulti = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2ChargeMulti"),
                                  method     = cms.string('chargedMultiplicity()'),
                                  rank       = cms.string('second')
                              ),
                              muNuThirdChargeMulti = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J3ChargeMulti"),
                                  method     = cms.string('chargedMultiplicity()'),
                                  rank       = cms.string('third')
                              ),
                              muNuFirstElectronMulti = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1EleMulti"),
                                  method     = cms.string('electronMultiplicity()'),
                                  rank       = cms.string('first')
                              ),
                              muNuSecondElectronMulti = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2EleMulti"),
                                  method     = cms.string('electronMultiplicity()'),
                                  rank       = cms.string('second')
                              ),
                              muNuThirdElectronMulti = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J3EleMulti"),
                                  method     = cms.string('electronMultiplicity()'),
                                  rank       = cms.string('third')
                              ),
                              muNuFirstPhotonMulti = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1PhotonMulti"),
                                  method     = cms.string('photonMultiplicity()'),
                                  rank       = cms.string('first')
                              ),
                              muNuSecondPhotonMulti = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2PhotonMulti"),
                                  method     = cms.string('photonMultiplicity()'),
                                  rank       = cms.string('second')
                              ),
                              muNuThirdPhotonMulti = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J3PhotonMulti"),
                                  method     = cms.string('photonMultiplicity()'),
                                  rank       = cms.string('third')
                              ),
                              muNuSecondJetFlavor = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2JetParton"),
                                  method     = cms.string('partonFlavour()'),
                                  rank       = cms.string('second')
                              ),
                              muNuThirdJetFlavor = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J3JetParton"),
                                  method     = cms.string('partonFlavour()'),
                                  rank       = cms.string('third')
                              ),
                              genbb = cms.PSet(
                                  pluginType = cms.string("CollectionSizeFiller"),
                                  src        = cms.InputTag("genbbCands"),
                                  tag        = cms.string("genBs"),
                              ),
                              gencc = cms.PSet(
                                  pluginType = cms.string("CollectionSizeFiller"),
                                  src        = cms.InputTag("genccCands"),
                                  tag        = cms.string("genCs"),
                              ),
                              gendd = cms.PSet(
                                  pluginType = cms.string("CollectionSizeFiller"),
                                  src        = cms.InputTag("genddCands"),
                                  tag        = cms.string("genDs"),
                              ),
                              genuu = cms.PSet(
                                  pluginType = cms.string("CollectionSizeFiller"),
                                  src        = cms.InputTag("genuuCands"),
                                  tag        = cms.string("genUs"),
                              ),
                              genss = cms.PSet(
                                  pluginType = cms.string("CollectionSizeFiller"),
                                  src        = cms.InputTag("genSSCands"),
                                  tag        = cms.string("genSs"),
                              ),
                              muNuJJ = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("mJJ"),
                                  method     = cms.string("mJJ"),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
                               muNuJPt = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("ptJJ"),
                                   method     = cms.string("ptJJ"),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
                               muonPt = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("muonPt"),
                                   method     = cms.string("lepton().pt")
                               ),##
                               muNuPt = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("WPt"),
                                   method     = cms.string("corPt()")
                               ),                              
                               muNuCalMET = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("met"),
                                   method     = cms.string("calibratedMET.pt()"),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
                               muNuMET = cms.PSet(
                                     pluginType = cms.string("PATMuonNuPairFiller"),
                                     src        = cms.InputTag(src),
                                     tag        = cms.string("MET"),
                                     method     = cms.string("met().pt")
                               ),
                               muNuCorMET = cms.PSet(
                                     pluginType = cms.string("PATMuonNuPairFiller"),
                                     src        = cms.InputTag(src),
                                     tag        = cms.string("corMET"),
                                     method     = cms.string("trueMet")
                               ),
                               muNuEta = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("muonEta"),
                                   method     = cms.string("lepton.eta")
                               ),
                               muNuPhi = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("muonPhi"),
                                   method     = cms.string("lepton.phi")
                               ),
                               muNuCharge = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("muonCharge"),
                                   method     = cms.string("lepton.charge()")
                               ),
                               muNuMT = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("Mt"),
                                   method     = cms.string("mt")
                               ),
                               muNuCorMT = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("MtCal"),
                                   method     = cms.string("corMt()")
                               ),
                               muMuMass = cms.PSet(
                                   pluginType = cms.string("PATMuPairFiller"),
                                   src        = cms.InputTag("diMuonsSorted"),
                                   tag        = cms.string("DiMuonMass"),
                                   method     = cms.string("mass")
                               ),
                               muNuDPhi = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("muNuDPhi"),
                                   method     = cms.string("dPhi")
                               ),
                               muNuRecoil = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("muNuRecoil"),
                                   method     = cms.string("recoil().pt()")
                               ),
                               muNuMuRelPFIso = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("muNuRelPFIso"),
                                   method     = cms.string('(lepton.chargedHadronIso()+lepton.photonIso()+lepton.neutralHadronIso())/lepton.pt()')
                               ),
                               muNuRelStdIso03 = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("muNuRelStdIso03"),
                                   method     = cms.string('(lepton.isolationR03.sumPt+lepton.isolationR03.emEt+lepton.isolationR03.hadEt)/lepton.pt()')
                               ),
                               muNuJetsBTag2Pt20 = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairJetCountFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("nJetsCSVmedBTag2Pt20"),
                                   method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")>=0.679&&pt()>20&&abs(eta)<2.4'),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
## #                              muNuJetsBTag2Pt20NM = cms.PSet(
## #                                  pluginType = cms.string("PATMuonNuPairJetCountFiller"),
## #                                  src        = cms.InputTag(src),
## #                                  tag        = cms.string("nJetsBTag2Pt20NotMatched"),
## #                                  method     = cms.string('bDiscriminator("")>=2&&pt()>20&&abs(eta)<2.4&&abs(partonFlavour)!=5'),
## #                                  leadingOnly=cms.untracked.bool(True)
## #                              ),
## #                              muNuJetsBTag3Pt20M = cms.PSet(
## #                                  pluginType = cms.string("PATMuonNuPairJetCountFiller"),
## #                                  src        = cms.InputTag(src),
## #                                  tag        = cms.string("nJetsBTag3Pt20Matched"),
## #                                  method     = cms.string('bDiscriminator("")>=3.3&&pt()>20&&abs(eta)<2.4&&abs(partonFlavour)==5'),
## #                                  method     = cms.string('bDiscriminator("")>=3.3&&pt()>20&&abs(eta)<2.4'),
## #                                  leadingOnly=cms.untracked.bool(True)
## #                              ),
                               muNuJetsBTag3Pt20 = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairJetCountFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("nJetsBTagCSV3Pt20"),
                                   method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")>=0.679&&pt()>20&&abs(eta)<2.4'),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
## #                              muNuJetsBTag3Pt20NM = cms.PSet(
## #                                  pluginType = cms.string("PATMuonNuPairJetCountFiller"),
## #                                  src        = cms.InputTag(src),
## #                                  tag        = cms.string("nJetsBTag3Pt20NotMatched"),
## #                                  method     = cms.string('bDiscriminator("")>=3.3&&pt()>20&&abs(eta)<2.4&&abs(partonFlavour)!=5'),
## #                                  leadingOnly=cms.untracked.bool(True)
## #                              ),
## #                              muNuJetsBTag2Pt30 = cms.PSet(
## #                                  pluginType = cms.string("PATMuonNuPairJetCountFiller"),
## #                                  src        = cms.InputTag(src),
## #                                  tag        = cms.string("nJetsBTag2Pt30"),
## #                                  method     = cms.string('bDiscriminator("")>=2&&pt()>30&&abs(eta)<2.4'),
## #                                  leadingOnly=cms.untracked.bool(True)
## #                              ),
## #                              muNuJetsBTag2Pt30M = cms.PSet(
## #                                  pluginType = cms.string("PATMuonNuPairJetCountFiller"),
## #                                  src        = cms.InputTag(src),
## #                                  tag        = cms.string("nJetsBTag2Pt30Matched"),
## #                                  method     = cms.string('bDiscriminator("")>=2&&pt()>30&&abs(eta)<2.4&&abs(partonFlavour)==5'),
## #                                  leadingOnly=cms.untracked.bool(True)
## #                              ),
## #                              muNuJetsBTag2Pt30NM = cms.PSet(
## #                                  pluginType = cms.string("PATMuonNuPairJetCountFiller"),
## #                                  src        = cms.InputTag(src),
## #                                  tag        = cms.string("nJetsBTag2Pt30NotMatched"),
## #                                  method     = cms.string('bDiscriminator("")>=2&&pt()>30&&abs(eta)<2.4&&abs(partonFlavour)!=5'),
## #                                  leadingOnly=cms.untracked.bool(True)
## #                              ),
                               muNuJetsBTag3Pt30 = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairJetCountFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("nJetsBTag3Pt30"),
                                   method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")>=0.679&&pt()>30&&abs(eta)<2.4'),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
## #                              muNuJetsBTag3Pt30M = cms.PSet(
## #                                  pluginType = cms.string("PATMuonNuPairJetCountFiller"),
## #                                  src        = cms.InputTag(src),
## #                                  tag        = cms.string("nJetsBTag3Pt30Matched"),
## #                                  method     = cms.string('bDiscriminator("")>=3.3&&pt()>30&&abs(eta)<2.4&&abs(partonFlavour)==5'),
## #                                  leadingOnly=cms.untracked.bool(True)
## #                              ),
## #                              muNuJetsBTag3Pt30NM = cms.PSet(
## #                                  pluginType = cms.string("PATMuonNuPairJetCountFiller"),
## #                                  src        = cms.InputTag(src),
## #                                  tag        = cms.string("nJetsBTag3Pt30NotMatched"),
## #                                  method     = cms.string('bDiscriminator("")>=3.3&&pt()>30&&abs(eta)<2.4&&abs(partonFlavour)!=5'),
## #                                  leadingOnly=cms.untracked.bool(True)
## #                              ),
                               muNuJetsPt30 = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairJetCountFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("nJetsPt30"),
                                   method     = cms.string('userInt("fullIdLoose")>0&&pt()>30'),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
                               muNuJetsPt30Tag = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairJetCountFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("nTaggableJetsPt30"),
                                   method     = cms.string('userInt("fullIdLoose")>0&&pt()>30&&abs(eta)<2.4'),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
## #                              muNuJetsPt30TagMatch = cms.PSet(
## #                                  pluginType = cms.string("PATMuonNuPairJetCountFiller"),
## #                                  src        = cms.InputTag(src),
## #                                  tag        = cms.string("nTaggableJetsPt30Matched"),
## #                                  method     = cms.string('pt()>30&&abs(eta)<2.4&&abs(partonFlavour)==5'),
## #                                  leadingOnly=cms.untracked.bool( True)
## #                              ),
                               muNuFirstJetPt = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("highestJetPt"),
                                   method     = cms.string('pt()'),
                                   rank       = cms.string('first')
                               ),
                               muNuSecondJetPt = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("secondJetPt"),
                                   method     = cms.string('pt()'),
                                   rank       = cms.string('second')
                               ),
                               muNuThirdJetPt = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("thirdJetPt"),
                                   method     = cms.string('pt()'),
                                   rank       = cms.string('third')
                               ),
                               muNuFirstJetEta = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("highestJetEta"),
                                   method     = cms.string('eta()'),
                                   rank       = cms.string('first')
                               ),
                               muNuSecondJetEta = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("secondJetEta"),
                                   method     = cms.string('eta()'),
                                   rank       = cms.string('second')
                               ),
                               muNuThirdJetEta = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("thirdJetEta"),
                                   method     = cms.string('eta()'),
                                   rank       = cms.string('third')
                               ),
                               muNuFirstJetPhi = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("highestJetPhi"),
                                   method     = cms.string('phi()'),
                                   rank       = cms.string('first')
                               ),
                               muNuSecondJetPhi = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("secondJetPhi"),
                                   method     = cms.string('phi()'),
                                   rank       = cms.string('second')
                               ),
                               muNuThirdJetPhi = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("thirdJetPhi"),
                                   method     = cms.string('phi()'),
                                   rank       = cms.string('third')
                               ),
                                muNuFirstJetChargedMultiplicity = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1nCharges"),
                                   method     = cms.string('chargedHadronMultiplicity()'),
                                   rank       = cms.string('first')
                               ),
                              muNuFirstJetTCHEbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1TCHEbtag"),
                                  method     = cms.string('bDiscriminator("trackCountingHighEffBJetTags")'),
                                  rank       = cms.string('first')
                              ),
                              muNuFirstJetTCHPbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1TCHPbtag"),
                                  method     = cms.string('bDiscriminator("trackCountingHighPurBJetTags")'),
                                  rank       = cms.string('first')
                              ),
                              muNuFirstJetSSVHEbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1SSVHEbtag"),
                                  method     = cms.string('bDiscriminator("simpleSecondaryVertexHighEffBJetTags")'),
                                  rank       = cms.string('first')
                              ),
                              muNuFirstJetCSVbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1CSVbtag"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")'),
                                  rank       = cms.string('first')
                              ),
                              muNuFirstJetCSVMVAbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1CSVMVAbtag"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexMVABJetTags")'),
                                  rank       = cms.string('first')
                              ),
                              muNuFirstJetCharge = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1Charge"),
                                  method     = cms.string('jetCharge'),
                                  rank       = cms.string('first')
                              ),
                               muNuFirstJetMass = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1Mass"),
                                   method     = cms.string('mass'),
                                   rank       = cms.string('first')
                               ),
                               muNuFirstPhotonEnergy = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1PhotonEnergy"),
                                   method     = cms.string('photonEnergy'),
                                   rank       = cms.string('first')
                               ),
                               muNuFirstPhotonEnergyFrac = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1PhotonEnergyFrac"),
                                   method     = cms.string('photonEnergyFraction'),
                                   rank       = cms.string('first')
                               ),
                               muNuFirstElectronEnergy = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1ElectronEnergy"),
                                   method     = cms.string('electronEnergy'),
                                   rank       = cms.string('first')
                               ),
                               muNuFirstElectronEnergyFrac = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1ElectronEnergyFrac"),
                                   method     = cms.string('chargedEmEnergyFraction'),
                                   rank       = cms.string('first')
                               ),
                               muNuFirstMuEnergy = cms.PSet(
                                    pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("J1MuonEnergy"),
                                    method     = cms.string('chargedMuEnergy'),
                                    rank       = cms.string('first')
                                ),
                                muNuFirstMuEnergyFrac = cms.PSet(
                                    pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("J1MuEnergyFrac"),
                                    method     = cms.string('muonEnergyFraction'),
                                    rank       = cms.string('first')
                                ),
                              muNuSecondJetChargedMultiplicity = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2nCharges"),
                                  method     = cms.string('chargedHadronMultiplicity()'),
                                  rank       = cms.string('second')
                              ),
                              muNuSecondJetTCHEbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2TCHEbtag"),
                                  method     = cms.string('bDiscriminator("trackCountingHighEffBJetTags")'),
                                  rank       = cms.string('second')
                              ),
                              muNuSecondJetTCHPbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2TCHPbtag"),
                                  method     = cms.string('bDiscriminator("trackCountingHighPurBJetTags")'),
                                  rank       = cms.string('second')
                              ),
                              muNuSecondJetSSVHEbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2SSVHEbtag"),
                                  method     = cms.string('bDiscriminator("simpleSecondaryVertexHighEffBJetTags")'),
                                  rank       = cms.string('second')
                              ),
                              muNuSecondJetCSVbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2CSVbtag"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")'),
                                  rank       = cms.string('second')
                              ),
                              muNuSecondJetCSVMVAbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2CSVMVAbtag"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexMVABJetTags")'),
                                  rank       = cms.string('second')
                              ),#####
                              muNuSecondJetCharge = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2Charge"),
                                  method     = cms.string('jetCharge'),
                                  rank       = cms.string('second')
                              ),
                               muNuSecondJetMass = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2Mass"),
                                   method     = cms.string('mass'),
                                   rank       = cms.string('second')
                               ),
                               muNuSecondPhotonEnergy = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2PhotonEnergy"),
                                   method     = cms.string('photonEnergy'),
                                   rank       = cms.string('second')
                               ),
                               muNuSecondPhotonEnergyFrac = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2PhotonEnergyFrac"),
                                   method     = cms.string('photonEnergyFraction'),
                                   rank       = cms.string('second')
                               ),
                               muNuSecondElectronEnergy = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2ElectronEnergy"),
                                   method     = cms.string('electronEnergy'),
                                   rank       = cms.string('second')
                               ),
                               muNuSecondElectronEnergyFrac = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2ElectronEnergyFrac"),
                                   method     = cms.string('chargedEmEnergyFraction'),
                                   rank       = cms.string('second')
                               ),
                               muNuSecondMuEnergy = cms.PSet(
                                    pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("J2MuonEnergy"),
                                    method     = cms.string('chargedMuEnergy'),
                                    rank       = cms.string('second')
                                ),
                                muNuSecondMuEnergyFrac = cms.PSet(
                                    pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("J2MuEnergyFrac"),
                                    method     = cms.string('muonEnergyFraction'),
                                    rank       = cms.string('second')
                                ),

                               muNuThirdJetChargedMultiplicity = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J3nCharges"),
                                  method     = cms.string('chargedHadronMultiplicity()'),
                                  rank       = cms.string('third')
                              ),
                              muNuThirdJetTCHEbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J3TCHEbtag"),
                                  method     = cms.string('bDiscriminator("trackCountingHighEffBJetTags")'),
                                  rank       = cms.string('third')
                              ),
                              muNuThirdJetCharge = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J3Charge"),
                                  method     = cms.string('jetCharge'),
                                  rank       = cms.string('third')
                              ),
                               muNuThirdJetMass = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J3Mass"),
                                   method     = cms.string('mass'),
                                   rank       = cms.string('third')
                               ),
                               muNuThirdPhotonEnergy = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J3PhotonEnergy"),
                                   method     = cms.string('photonEnergy'),
                                   rank       = cms.string('third')
                               ),
                               muNuThirdPhotonEnergyFrac = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J3PhotonEnergyFrac"),
                                   method     = cms.string('photonEnergyFraction'),
                                   rank       = cms.string('third')
                               ),
                               muNuThirdElectronEnergy = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J3ElectronEnergy"),
                                   method     = cms.string('electronEnergy'),
                                   rank       = cms.string('third')
                               ),
                               muNuThirdElectronEnergyFrac = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J3ElectronEnergyFrac"),
                                   method     = cms.string('chargedEmEnergyFraction'),
                                   rank       = cms.string('third')
                               ),
                               muNuThirdMuEnergy = cms.PSet(
                                    pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("J3MuonEnergy"),
                                    method     = cms.string('chargedMuEnergy'),
                                    rank       = cms.string('third')
                                ),
                                muNuThirdMuEnergyFrac = cms.PSet(
                                    pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("J3MuEnergyFrac"),
                                    method     = cms.string('muonEnergyFraction'),
                                    rank       = cms.string('third')
                                ),
                               mu1DXY = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("l1DXY"),
                                   method     = cms.string('lepton.userFloat("ipDXY")'),
                                   leadingOnly=cms.untracked.bool(True)
                                   )
                          
                              

   )
   setattr(process, name, eventTree)
   p = cms.Path(getattr(process,name))
   setattr(process, name+'Path', p)


def addMuNuEventTreePt(process,name,src = 'wCandsJets'):
   process.TFileService = cms.Service("TFileService", fileName = cms.string("analysis.root") )
   eventTree = cms.EDAnalyzer('EventTreeMaker',
                              coreCollections = cms.VInputTag(
                                   cms.InputTag(src)
                              ),
                              PVs = cms.PSet(
                                    pluginType = cms.string("VertexSizeFiller"),
                                    src        = cms.InputTag("primaryVertexFilter"),
                                    tag        = cms.string("vertices")
                              ),
                              trigger = cms.PSet(
                                  pluginType = cms.string("TriggerFiller"),
                                  src        = cms.InputTag("patTrigger"),
                                  paths      = cms.vstring(TriggerPaths)
                              ),
                               muNuDZ = cms.PSet(
                                     pluginType = cms.string("PATMuonNuPairFiller"),
                                     src        = cms.InputTag(src),
                                     tag        = cms.string("dz"),
                                     method     = cms.string('abs(lepton.userFloat("dz"))'),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
                               genWs = cms.PSet(
                                     pluginType = cms.string("CollectionSizeFiller"),
                                     src        = cms.InputTag("genWs"),
                                     tag        = cms.string("genWs"),
                               ),
                               muNuFirstJetFlavor = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1JetParton"),
                                   method     = cms.string('partonFlavour()'),
                                   rank       = cms.string('first')
                               ),
                               muNuFirstMuonMulti = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1MuonMulti"),
                                   method     = cms.string('muonMultiplicity()'),
                                   rank       = cms.string('first')
                               ),
                               muNuSecondMuonMulti = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2MuonMulti"),
                                   method     = cms.string('muonMultiplicity()'),
                                   rank       = cms.string('second')
                               ),
                               muNuThirdMuonMulti = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J3MuonMulti"),
                                   method     = cms.string('muonMultiplicity()'),
                                   rank       = cms.string('third')
                               ),
                               muNuFirstChargeMulti = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1ChargeMulti"),
                                  method     = cms.string('chargedMultiplicity()'),
                                  rank       = cms.string('first')
                              ),
                              muNuSecondChargeMulti = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2ChargeMulti"),
                                  method     = cms.string('chargedMultiplicity()'),
                                  rank       = cms.string('second')
                              ),
                              muNuThirdChargeMulti = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J3ChargeMulti"),
                                  method     = cms.string('chargedMultiplicity()'),
                                  rank       = cms.string('third')
                              ),
                              muNuFirstElectronMulti = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1EleMulti"),
                                  method     = cms.string('electronMultiplicity()'),
                                  rank       = cms.string('first')
                              ),
                              muNuSecondElectronMulti = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2EleMulti"),
                                  method     = cms.string('electronMultiplicity()'),
                                  rank       = cms.string('second')
                              ),
                              muNuThirdElectronMulti = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J3EleMulti"),
                                  method     = cms.string('electronMultiplicity()'),
                                  rank       = cms.string('third')
                              ),
                              muNuFirstPhotonMulti = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1PhotonMulti"),
                                  method     = cms.string('photonMultiplicity()'),
                                  rank       = cms.string('first')
                              ),
                              muNuSecondPhotonMulti = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2PhotonMulti"),
                                  method     = cms.string('photonMultiplicity()'),
                                  rank       = cms.string('second')
                              ),
                              muNuThirdPhotonMulti = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J3PhotonMulti"),
                                  method     = cms.string('photonMultiplicity()'),
                                  rank       = cms.string('third')
                              ),
                              muNuSecondJetFlavor = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2JetParton"),
                                  method     = cms.string('partonFlavour()'),
                                  rank       = cms.string('second')
                              ),
                              muNuThirdJetFlavor = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J3JetParton"),
                                  method     = cms.string('partonFlavour()'),
                                  rank       = cms.string('third')
                              ),
                              genbb = cms.PSet(
                                  pluginType = cms.string("CollectionSizeFiller"),
                                  src        = cms.InputTag("genbbCands"),
                                  tag        = cms.string("genBs"),
                              ),
                              gencc = cms.PSet(
                                  pluginType = cms.string("CollectionSizeFiller"),
                                  src        = cms.InputTag("genccCands"),
                                  tag        = cms.string("genCs"),
                              ),
                              gendd = cms.PSet(
                                  pluginType = cms.string("CollectionSizeFiller"),
                                  src        = cms.InputTag("genddCands"),
                                  tag        = cms.string("genDs"),
                              ),
                              genuu = cms.PSet(
                                  pluginType = cms.string("CollectionSizeFiller"),
                                  src        = cms.InputTag("genuuCands"),
                                  tag        = cms.string("genUs"),
                              ),
                              genss = cms.PSet(
                                  pluginType = cms.string("CollectionSizeFiller"),
                                  src        = cms.InputTag("genSSCands"),
                                  tag        = cms.string("genSs"),
                              ),
                              muNuJJ = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("mJJ"),
                                  method     = cms.string("mJJ"),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
                               muNuJPt = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("ptJJ"),
                                   method     = cms.string("ptJJ"),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
                               muonPt = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("muonPt"),
                                   method     = cms.string("lepton().pt")
                               ),##
                               muNuPt = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("WPt"),
                                   method     = cms.string("corPt()")
                               ),                              
                               muNuCalMET = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("met"),
                                   method     = cms.string("calibratedMET.pt()"),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
                               muNuMET = cms.PSet(
                                     pluginType = cms.string("PATMuonNuPairFiller"),
                                     src        = cms.InputTag(src),
                                     tag        = cms.string("MET"),
                                     method     = cms.string("met().pt")
                               ),
                               muNuCorMET = cms.PSet(
                                     pluginType = cms.string("PATMuonNuPairFiller"),
                                     src        = cms.InputTag(src),
                                     tag        = cms.string("corMET"),
                                     method     = cms.string("trueMet")
                               ),
                               muNuEta = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("muonEta"),
                                   method     = cms.string("lepton.eta")
                               ),
                               muNuPhi = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("muonPhi"),
                                   method     = cms.string("lepton.phi")
                               ),
                               muNuCharge = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("muonCharge"),
                                   method     = cms.string("lepton.charge()")
                               ),
                               muNuMT = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("Mt"),
                                   method     = cms.string("mt")
                               ),
                               muNuCorMT = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("MtCal"),
                                   method     = cms.string("corMt()")
                               ),
                               muMuMass = cms.PSet(
                                   pluginType = cms.string("PATMuPairFiller"),
                                   src        = cms.InputTag("diMuonsSorted"),
                                   tag        = cms.string("DiMuonMass"),
                                   method     = cms.string("mass")
                               ),
                               muNuDPhi = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("muNuDPhi"),
                                   method     = cms.string("dPhi")
                               ),
                               muNuRecoil = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("muNuRecoil"),
                                   method     = cms.string("recoil().pt()")
                               ),
                               muNuMuRelPFIso = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("muNuRelPFIso"),
                                   method     = cms.string('(lepton.chargedHadronIso()+lepton.photonIso()+lepton.neutralHadronIso())/lepton.pt()')
                               ),
                               muNuRelStdIso03 = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("muNuRelStdIso03"),
                                   method     = cms.string('(lepton.isolationR03.sumPt+lepton.isolationR03.emEt+lepton.isolationR03.hadEt)/lepton.pt()')
                               ),
                               muNuJetsBTagCSVloosePt30 = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairJetCountFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("nJetsBTagCSV1Pt30"),
                                   method     = cms.string('userInt("fullIdLoose")>0&&bDiscriminator("combinedSecondaryVertexBJetTags")>=0.244&&pt()>30&&abs(eta)<2.1'),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
                               muNuJetsBTagCSVMedPt30 = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairJetCountFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("nJetsBTagCSV2Pt30"),
                                   method     = cms.string('userInt("fullIdLoose")>0&&bDiscriminator("combinedSecondaryVertexBJetTags")>=0.679&&pt()>30&&abs(eta)<2.1'),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
                               muNuJetsBTagCSVTightPt30 = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairJetCountFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("nJetsBTagCSV3Pt30"),
                                   method     = cms.string('userInt("fullIdLoose")>0&&bDiscriminator("combinedSecondaryVertexBJetTags")>=0.898&&pt()>30&&abs(eta)<2.1'),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
                              muNuJetsBTagTCHPTightPt30 = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsBTagTCHP3Pt30"),
                                  method     = cms.string('userInt("fullIdLoose")>0&&bDiscriminator("trackCountingHighPurBJetTags")>=3.41&&pt()>30&&abs(eta)<2.1'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muNuJetsBTagJPL1Pt30 = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsBTagJPL1Pt30"),
                                  method     = cms.string('userInt("fullIdLoose")>0&&bDiscriminator("jetProbabilityBJetTags")>=0.275&&pt()>30&&abs(eta)<2.1'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muNuJetsBTagJPL2Pt30 = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsBTagJPL2Pt30"),
                                  method     = cms.string('userInt("fullIdLoose")>0&&bDiscriminator("jetProbabilityBJetTags")>=0.545&&pt()>30&&abs(eta)<2.1'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muNuJetsBTagJPL3Pt30 = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsBTagJPL3Pt30"),
                                  method     = cms.string('userInt("fullIdLoose")>0&&bDiscriminator("")>=0.790&&pt()>30&&abs(eta)<2.1'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),                              
                              muNuJetsBTagTCHP1Pt30 = cms.PSet(
                                 pluginType = cms.string("PATMuonNuPairJetCountFiller"),
                                 src        = cms.InputTag(src),
                                 tag        = cms.string("nJetsBTagTCHP1Pt30"),
                                 method     = cms.string('userInt("fullIdLoose")>0&&bDiscriminator("trackCountingHighPurBJetTags")>=1.19&&pt()>30&&abs(eta)<2.1'),
                                 leadingOnly=cms.untracked.bool(True)
                             ),
                             muNuJetsBTagTCHP3Pt30 = cms.PSet(
                                 pluginType = cms.string("PATMuonNuPairJetCountFiller"),
                                 src        = cms.InputTag(src),
                                 tag        = cms.string("nJetsBTagTCHP3Pt30"),
                                 method     = cms.string('userInt("fullIdLoose")>0&&bDiscriminator("jetProbabilityBJetTags")>=3.41&&pt()>30&&abs(eta)<2.1'),
                                 leadingOnly=cms.untracked.bool(True)
                             ),
## #                              muNuJetsBTag3Pt30M = cms.PSet(
## #                                  pluginType = cms.string("PATMuonNuPairJetCountFiller"),
## #                                  src        = cms.InputTag(src),
## #                                  tag        = cms.string("nJetsBTag3Pt30Matched"),
## #                                  method     = cms.string('bDiscriminator("")>=3.3&&pt()>30&&abs(eta)<2.4&&abs(partonFlavour)==5'),
## #                                  leadingOnly=cms.untracked.bool(True)
## #                              ),
## #                              muNuJetsBTag3Pt30NM = cms.PSet(
## #                                  pluginType = cms.string("PATMuonNuPairJetCountFiller"),
## #                                  src        = cms.InputTag(src),
## #                                  tag        = cms.string("nJetsBTag3Pt30NotMatched"),
## #                                  method     = cms.string('bDiscriminator("")>=3.3&&pt()>30&&abs(eta)<2.4&&abs(partonFlavour)!=5'),
## #                                  leadingOnly=cms.untracked.bool(True)
## #                              ),
                               muNuJetsPt30 = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairJetCountFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("nJetsPt30"),
                                   method     = cms.string('userInt("fullIdLoose")>0&&pt()>30'),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
                               muNuJetsPt25 = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairJetCountFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("nJetsPt25"),
                                   method     = cms.string('userInt("fullIdLoose")>0&&pt()>25'),
                                   leadingOnly=cms.untracked.bool(True)
                               ),                              
                               muNuJetsPt30Tag = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairJetCountFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("nTaggableJetsPt30"),
                                   method     = cms.string('userInt("fullIdLoose")>0&&pt()>30&&abs(eta)<2.1'),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
                               muNuJetsPt25Tag = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairJetCountFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("nTaggableJetsPt25"),
                                   method     = cms.string('userInt("fullIdLoose")>0&&pt()>25'),
                                   leadingOnly=cms.untracked.bool(True)
                               ),                              
## #                              muNuJetsPt30TagMatch = cms.PSet(
## #                                  pluginType = cms.string("PATMuonNuPairJetCountFiller"),
## #                                  src        = cms.InputTag(src),
## #                                  tag        = cms.string("nTaggableJetsPt30Matched"),
## #                                  method     = cms.string('pt()>30&&abs(eta)<2.4&&abs(partonFlavour)==5'),
## #                                  leadingOnly=cms.untracked.bool( True)
## #                              ),
                               muNuFirstJetPt = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("highestJetPt"),
                                   method     = cms.string('pt()'),
                                   rank       = cms.string('first')
                               ),
                               muNuSecondJetPt = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("secondJetPt"),
                                   method     = cms.string('pt()'),
                                   rank       = cms.string('second')
                               ),
                               muNuThirdJetPt = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("thirdJetPt"),
                                   method     = cms.string('pt()'),
                                   rank       = cms.string('third')
                               ),
                               muNuFirstJetEta = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("highestJetEta"),
                                   method     = cms.string('eta()'),
                                   rank       = cms.string('first')
                               ),
                               muNuSecondJetEta = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("secondJetEta"),
                                   method     = cms.string('eta()'),
                                   rank       = cms.string('second')
                               ),
                               muNuThirdJetEta = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("thirdJetEta"),
                                   method     = cms.string('eta()'),
                                   rank       = cms.string('third')
                               ),
                               muNuFirstJetPhi = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("highestJetPhi"),
                                   method     = cms.string('phi()'),
                                   rank       = cms.string('first')
                               ),
                               muNuSecondJetPhi = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("secondJetPhi"),
                                   method     = cms.string('phi()'),
                                   rank       = cms.string('second')
                               ),
                               muNuThirdJetPhi = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("thirdJetPhi"),
                                   method     = cms.string('phi()'),
                                   rank       = cms.string('third')
                               ),
                                muNuFirstJetChargedMultiplicity = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1nCharges"),
                                   method     = cms.string('chargedHadronMultiplicity()'),
                                   rank       = cms.string('first')
                               ),
                              muNuFirstJetTCHEbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1TCHEbtag"),
                                  method     = cms.string('bDiscriminator("trackCountingHighEffBJetTags")'),
                                  rank       = cms.string('first')
                              ),
                              muNuFirstJetTCHPbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1TCHPbtag"),
                                  method     = cms.string('bDiscriminator("trackCountingHighPurBJetTags")'),
                                  rank       = cms.string('first')
                              ),
                              muNuFirstJetSSVHEbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1SSVHEbtag"),
                                  method     = cms.string('bDiscriminator("simpleSecondaryVertexHighEffBJetTags")'),
                                  rank       = cms.string('first')
                              ),
                              muNuFirstJetCSVbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1CSVbtag"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")'),
                                  rank       = cms.string('first')
                              ),
                              muNuFirstJetCSVMVAbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1CSVMVAbtag"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexMVABJetTags")'),
                                  rank       = cms.string('first')
                              ),
                              muNuFirstJetCharge = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1Charge"),
                                  method     = cms.string('jetCharge'),
                                  rank       = cms.string('first')
                              ),
                               muNuFirstJetMass = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1Mass"),
                                   method     = cms.string('mass'),
                                   rank       = cms.string('first')
                               ),
                               muNuFirstPhotonEnergy = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1PhotonEnergy"),
                                   method     = cms.string('photonEnergy'),
                                   rank       = cms.string('first')
                               ),
                               muNuFirstPhotonEnergyFrac = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1PhotonEnergyFrac"),
                                   method     = cms.string('photonEnergyFraction'),
                                   rank       = cms.string('first')
                               ),
                               muNuFirstElectronEnergy = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1ElectronEnergy"),
                                   method     = cms.string('electronEnergy'),
                                   rank       = cms.string('first')
                               ),
                               muNuFirstElectronEnergyFrac = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1ElectronEnergyFrac"),
                                   method     = cms.string('chargedEmEnergyFraction'),
                                   rank       = cms.string('first')
                               ),
                               muNuFirstMuEnergy = cms.PSet(
                                    pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("J1MuonEnergy"),
                                    method     = cms.string('chargedMuEnergy'),
                                    rank       = cms.string('first')
                                ),
                                muNuFirstMuEnergyFrac = cms.PSet(
                                    pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("J1MuEnergyFrac"),
                                    method     = cms.string('muonEnergyFraction'),
                                    rank       = cms.string('first')
                                ),
                              muNuSecondJetChargedMultiplicity = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2nCharges"),
                                  method     = cms.string('chargedHadronMultiplicity()'),
                                  rank       = cms.string('second')
                              ),
                              muNuSecondJetTCHEbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2TCHEbtag"),
                                  method     = cms.string('bDiscriminator("trackCountingHighEffBJetTags")'),
                                  rank       = cms.string('second')
                              ),
                              muNuSecondJetTCHPbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2TCHPbtag"),
                                  method     = cms.string('bDiscriminator("trackCountingHighPurBJetTags")'),
                                  rank       = cms.string('second')
                              ),
                              muNuSecondJetSSVHEbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2SSVHEbtag"),
                                  method     = cms.string('bDiscriminator("simpleSecondaryVertexHighEffBJetTags")'),
                                  rank       = cms.string('second')
                              ),
                              muNuSecondJetCSVbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2CSVbtag"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")'),
                                  rank       = cms.string('second')
                              ),
                              muNuSecondJetCSVMVAbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2CSVMVAbtag"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexMVABJetTags")'),
                                  rank       = cms.string('second')
                              ),#####
                              muNuSecondJetCharge = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2Charge"),
                                  method     = cms.string('jetCharge'),
                                  rank       = cms.string('second')
                              ),
                               muNuSecondJetMass = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2Mass"),
                                   method     = cms.string('mass'),
                                   rank       = cms.string('second')
                               ),
                               muNuSecondPhotonEnergy = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2PhotonEnergy"),
                                   method     = cms.string('photonEnergy'),
                                   rank       = cms.string('second')
                               ),
                               muNuSecondPhotonEnergyFrac = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2PhotonEnergyFrac"),
                                   method     = cms.string('photonEnergyFraction'),
                                   rank       = cms.string('second')
                               ),
                               muNuSecondElectronEnergy = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2ElectronEnergy"),
                                   method     = cms.string('electronEnergy'),
                                   rank       = cms.string('second')
                               ),
                               muNuSecondElectronEnergyFrac = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2ElectronEnergyFrac"),
                                   method     = cms.string('chargedEmEnergyFraction'),
                                   rank       = cms.string('second')
                               ),
                               muNuSecondMuEnergy = cms.PSet(
                                    pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("J2MuonEnergy"),
                                    method     = cms.string('chargedMuEnergy'),
                                    rank       = cms.string('second')
                                ),
                                muNuSecondMuEnergyFrac = cms.PSet(
                                    pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("J2MuEnergyFrac"),
                                    method     = cms.string('muonEnergyFraction'),
                                    rank       = cms.string('second')
                                ),

                               muNuThirdJetChargedMultiplicity = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J3nCharges"),
                                  method     = cms.string('chargedHadronMultiplicity()'),
                                  rank       = cms.string('third')
                              ),
                              muNuThirdJetTCHEbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J3TCHEbtag"),
                                  method     = cms.string('bDiscriminator("trackCountingHighEffBJetTags")'),
                                  rank       = cms.string('third')
                              ),
                              muNuThirdJetCharge = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J3Charge"),
                                  method     = cms.string('jetCharge'),
                                  rank       = cms.string('third')
                              ),
                               muNuThirdJetMass = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J3Mass"),
                                   method     = cms.string('mass'),
                                   rank       = cms.string('third')
                               ),
                               muNuThirdPhotonEnergy = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J3PhotonEnergy"),
                                   method     = cms.string('photonEnergy'),
                                   rank       = cms.string('third')
                               ),
                               muNuThirdPhotonEnergyFrac = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J3PhotonEnergyFrac"),
                                   method     = cms.string('photonEnergyFraction'),
                                   rank       = cms.string('third')
                               ),
                               muNuThirdElectronEnergy = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J3ElectronEnergy"),
                                   method     = cms.string('electronEnergy'),
                                   rank       = cms.string('third')
                               ),
                               muNuThirdElectronEnergyFrac = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J3ElectronEnergyFrac"),
                                   method     = cms.string('chargedEmEnergyFraction'),
                                   rank       = cms.string('third')
                               ),
                               muNuThirdMuEnergy = cms.PSet(
                                    pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("J3MuonEnergy"),
                                    method     = cms.string('chargedMuEnergy'),
                                    rank       = cms.string('third')
                                ),
                                muNuThirdMuEnergyFrac = cms.PSet(
                                    pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("J3MuEnergyFrac"),
                                    method     = cms.string('muonEnergyFraction'),
                                    rank       = cms.string('third')
                                ),
                               mu1DXY = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("l1DXY"),
                                   method     = cms.string('lepton.userFloat("ipDXY")'),
                                   leadingOnly=cms.untracked.bool(True)
                                   )
                          
                              

   )
   setattr(process, name, eventTree)
   p = cms.Path(getattr(process,name))
   setattr(process, name+'Path', p)



def addMuNuEventTreeCSV(process,name,src = 'wCandsJets'):
   process.TFileService = cms.Service("TFileService", fileName = cms.string("analysis.root") )
   eventTree = cms.EDAnalyzer('EventTreeMaker',
                              coreCollections = cms.VInputTag(
                                   cms.InputTag(src)
                              ),
                              PVs = cms.PSet(
                                    pluginType = cms.string("VertexSizeFiller"),
                                    src        = cms.InputTag("primaryVertexFilter"),
                                    tag        = cms.string("vertices")
                              ),
                              trigger = cms.PSet(
                                  pluginType = cms.string("TriggerFiller"),
                                  src        = cms.InputTag("patTrigger"),
                                  paths      = cms.vstring(TriggerPaths)
                              ),
                               muNuDZ = cms.PSet(
                                     pluginType = cms.string("PATMuonNuPairFiller"),
                                     src        = cms.InputTag(src),
                                     tag        = cms.string("dz"),
                                     method     = cms.string('abs(lepton.userFloat("dz"))'),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
                               genWs = cms.PSet(
                                     pluginType = cms.string("CollectionSizeFiller"),
                                     src        = cms.InputTag("genWs"),
                                     tag        = cms.string("genWs"),
                               ),
                               muNuFirstJetFlavor = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1JetParton"),
                                   method     = cms.string('partonFlavour()'),
                                   rank       = cms.string('first')
                               ),
                               muNuFirstMuonMulti = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1MuonMulti"),
                                   method     = cms.string('muonMultiplicity()'),
                                   rank       = cms.string('first')
                               ),
                               muNuSecondMuonMulti = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2MuonMulti"),
                                   method     = cms.string('muonMultiplicity()'),
                                   rank       = cms.string('second')
                               ),
                               muNuThirdMuonMulti = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J3MuonMulti"),
                                   method     = cms.string('muonMultiplicity()'),
                                   rank       = cms.string('third')
                               ),
                               muNuFirstChargeMulti = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1ChargeMulti"),
                                  method     = cms.string('chargedMultiplicity()'),
                                  rank       = cms.string('first')
                              ),
                              muNuSecondChargeMulti = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2ChargeMulti"),
                                  method     = cms.string('chargedMultiplicity()'),
                                  rank       = cms.string('second')
                              ),
                              muNuThirdChargeMulti = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J3ChargeMulti"),
                                  method     = cms.string('chargedMultiplicity()'),
                                  rank       = cms.string('third')
                              ),
                              muNuFirstElectronMulti = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1EleMulti"),
                                  method     = cms.string('electronMultiplicity()'),
                                  rank       = cms.string('first')
                              ),
                              muNuSecondElectronMulti = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2EleMulti"),
                                  method     = cms.string('electronMultiplicity()'),
                                  rank       = cms.string('second')
                              ),
                              muNuThirdElectronMulti = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J3EleMulti"),
                                  method     = cms.string('electronMultiplicity()'),
                                  rank       = cms.string('third')
                              ),
                              muNuFirstPhotonMulti = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1PhotonMulti"),
                                  method     = cms.string('photonMultiplicity()'),
                                  rank       = cms.string('first')
                              ),
                              muNuSecondPhotonMulti = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2PhotonMulti"),
                                  method     = cms.string('photonMultiplicity()'),
                                  rank       = cms.string('second')
                              ),
                              muNuThirdPhotonMulti = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J3PhotonMulti"),
                                  method     = cms.string('photonMultiplicity()'),
                                  rank       = cms.string('third')
                              ),
                              muNuSecondJetFlavor = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2JetParton"),
                                  method     = cms.string('partonFlavour()'),
                                  rank       = cms.string('second')
                              ),
                              muNuThirdJetFlavor = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J3JetParton"),
                                  method     = cms.string('partonFlavour()'),
                                  rank       = cms.string('third')
                              ),
                              genbb = cms.PSet(
                                  pluginType = cms.string("CollectionSizeFiller"),
                                  src        = cms.InputTag("genbbCands"),
                                  tag        = cms.string("genBs"),
                              ),
                              gencc = cms.PSet(
                                  pluginType = cms.string("CollectionSizeFiller"),
                                  src        = cms.InputTag("genccCands"),
                                  tag        = cms.string("genCs"),
                              ),
                              gendd = cms.PSet(
                                  pluginType = cms.string("CollectionSizeFiller"),
                                  src        = cms.InputTag("genddCands"),
                                  tag        = cms.string("genDs"),
                              ),
                              genuu = cms.PSet(
                                  pluginType = cms.string("CollectionSizeFiller"),
                                  src        = cms.InputTag("genuuCands"),
                                  tag        = cms.string("genUs"),
                              ),
                              genss = cms.PSet(
                                  pluginType = cms.string("CollectionSizeFiller"),
                                  src        = cms.InputTag("genSSCands"),
                                  tag        = cms.string("genSs"),
                              ),
                              muNuJJ = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("mJJ"),
                                  method     = cms.string("mJJ"),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
                               muNuJPt = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("ptJJ"),
                                   method     = cms.string("ptJJ"),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
                               muonPt = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("muonPt"),
                                   method     = cms.string("lepton().pt")
                               ),##
                               muNuPt = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("WPt"),
                                   method     = cms.string("corPt()")
                               ),                              
                               muNuCalMET = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("met"),
                                   method     = cms.string("calibratedMET.pt()"),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
                               muNuMET = cms.PSet(
                                     pluginType = cms.string("PATMuonNuPairFiller"),
                                     src        = cms.InputTag(src),
                                     tag        = cms.string("MET"),
                                     method     = cms.string("met().pt")
                               ),
                               muNuCorMET = cms.PSet(
                                     pluginType = cms.string("PATMuonNuPairFiller"),
                                     src        = cms.InputTag(src),
                                     tag        = cms.string("corMET"),
                                     method     = cms.string("trueMet")
                               ),
                               muNuEta = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("muonEta"),
                                   method     = cms.string("lepton.eta")
                               ),
                               muNuPhi = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("muonPhi"),
                                   method     = cms.string("lepton.phi")
                               ),
                               muNuCharge = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("muonCharge"),
                                   method     = cms.string("lepton.charge()")
                               ),
                               muNuMT = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("Mt"),
                                   method     = cms.string("mt")
                               ),
                               muNuCorMT = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("MtCal"),
                                   method     = cms.string("corMt()")
                               ),
                               muMuMass = cms.PSet(
                                   pluginType = cms.string("PATMuPairFiller"),
                                   src        = cms.InputTag("diMuonsSorted"),
                                   tag        = cms.string("DiMuonMass"),
                                   method     = cms.string("mass")
                               ),
                               muNuDPhi = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("muNuDPhi"),
                                   method     = cms.string("dPhi")
                               ),
                               muNuRecoil = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("muNuRecoil"),
                                   method     = cms.string("recoil().pt()")
                               ),
                               muNuMuRelPFIso = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("muNuRelPFIso"),
                                   method     = cms.string('(lepton.chargedHadronIso()+lepton.photonIso()+lepton.neutralHadronIso())/lepton.pt()')
                               ),
                               muNuRelStdIso03 = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("muNuRelStdIso03"),
                                   method     = cms.string('(lepton.isolationR03.sumPt+lepton.isolationR03.emEt+lepton.isolationR03.hadEt)/lepton.pt()')
                               ),
                               muNuJetsBTag2Pt20 = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairJetCountFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("nJetsCSVmedBTag2Pt20"),
                                   method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")>=0.679&&pt()>20&&abs(eta)<2.4'),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
## #                              muNuJetsBTag2Pt20NM = cms.PSet(
## #                                  pluginType = cms.string("PATMuonNuPairJetCountFiller"),
## #                                  src        = cms.InputTag(src),
## #                                  tag        = cms.string("nJetsBTag2Pt20NotMatched"),
## #                                  method     = cms.string('bDiscriminator("")>=2&&pt()>20&&abs(eta)<2.4&&abs(partonFlavour)!=5'),
## #                                  leadingOnly=cms.untracked.bool(True)
## #                              ),
## #                              muNuJetsBTag3Pt20M = cms.PSet(
## #                                  pluginType = cms.string("PATMuonNuPairJetCountFiller"),
## #                                  src        = cms.InputTag(src),
## #                                  tag        = cms.string("nJetsBTag3Pt20Matched"),
## #                                  method     = cms.string('bDiscriminator("")>=3.3&&pt()>20&&abs(eta)<2.4&&abs(partonFlavour)==5'),
## #                                  method     = cms.string('bDiscriminator("")>=3.3&&pt()>20&&abs(eta)<2.4'),
## #                                  leadingOnly=cms.untracked.bool(True)
## #                              ),
                               muNuJetsBTag3Pt20 = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairJetCountFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("nJetsBTagCSV3Pt20"),
                                   method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")>=0.679&&pt()>20&&abs(eta)<2.4'),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
## #                              muNuJetsBTag3Pt20NM = cms.PSet(
## #                                  pluginType = cms.string("PATMuonNuPairJetCountFiller"),
## #                                  src        = cms.InputTag(src),
## #                                  tag        = cms.string("nJetsBTag3Pt20NotMatched"),
## #                                  method     = cms.string('bDiscriminator("")>=3.3&&pt()>20&&abs(eta)<2.4&&abs(partonFlavour)!=5'),
## #                                  leadingOnly=cms.untracked.bool(True)
## #                              ),
## #                              muNuJetsBTag2Pt30 = cms.PSet(
## #                                  pluginType = cms.string("PATMuonNuPairJetCountFiller"),
## #                                  src        = cms.InputTag(src),
## #                                  tag        = cms.string("nJetsBTag2Pt30"),
## #                                  method     = cms.string('bDiscriminator("")>=2&&pt()>30&&abs(eta)<2.4'),
## #                                  leadingOnly=cms.untracked.bool(True)
## #                              ),
## #                              muNuJetsBTag2Pt30M = cms.PSet(
## #                                  pluginType = cms.string("PATMuonNuPairJetCountFiller"),
## #                                  src        = cms.InputTag(src),
## #                                  tag        = cms.string("nJetsBTag2Pt30Matched"),
## #                                  method     = cms.string('bDiscriminator("")>=2&&pt()>30&&abs(eta)<2.4&&abs(partonFlavour)==5'),
## #                                  leadingOnly=cms.untracked.bool(True)
## #                              ),
## #                              muNuJetsBTag2Pt30NM = cms.PSet(
## #                                  pluginType = cms.string("PATMuonNuPairJetCountFiller"),
## #                                  src        = cms.InputTag(src),
## #                                  tag        = cms.string("nJetsBTag2Pt30NotMatched"),
## #                                  method     = cms.string('bDiscriminator("")>=2&&pt()>30&&abs(eta)<2.4&&abs(partonFlavour)!=5'),
## #                                  leadingOnly=cms.untracked.bool(True)
## #                              ),
                               muNuJetsBTag3Pt30 = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairJetCountFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("nJetsBTag3Pt30"),
                                   method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")>=0.679&&pt()>30&&abs(eta)<2.4'),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
## #                              muNuJetsBTag3Pt30M = cms.PSet(
## #                                  pluginType = cms.string("PATMuonNuPairJetCountFiller"),
## #                                  src        = cms.InputTag(src),
## #                                  tag        = cms.string("nJetsBTag3Pt30Matched"),
## #                                  method     = cms.string('bDiscriminator("")>=3.3&&pt()>30&&abs(eta)<2.4&&abs(partonFlavour)==5'),
## #                                  leadingOnly=cms.untracked.bool(True)
## #                              ),
## #                              muNuJetsBTag3Pt30NM = cms.PSet(
## #                                  pluginType = cms.string("PATMuonNuPairJetCountFiller"),
## #                                  src        = cms.InputTag(src),
## #                                  tag        = cms.string("nJetsBTag3Pt30NotMatched"),
## #                                  method     = cms.string('bDiscriminator("")>=3.3&&pt()>30&&abs(eta)<2.4&&abs(partonFlavour)!=5'),
## #                                  leadingOnly=cms.untracked.bool(True)
## #                              ),
                               muNuJetsPt30 = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairJetCountFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("nJetsPt30"),
                                   method     = cms.string('userInt("fullIdLoose")>0&&pt()>30'),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
                               muNuJetsPt30Tag = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairJetCountFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("nTaggableJetsPt30"),
                                   method     = cms.string('userInt("fullIdLoose")>0&&pt()>30&&abs(eta)<2.4'),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
## #                              muNuJetsPt30TagMatch = cms.PSet(
## #                                  pluginType = cms.string("PATMuonNuPairJetCountFiller"),
## #                                  src        = cms.InputTag(src),
## #                                  tag        = cms.string("nTaggableJetsPt30Matched"),
## #                                  method     = cms.string('pt()>30&&abs(eta)<2.4&&abs(partonFlavour)==5'),
## #                                  leadingOnly=cms.untracked.bool( True)
## #                              ),
                               muNuFirstJetPt = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("highestJetPt"),
                                   method     = cms.string('pt()'),
                                   rank       = cms.string('first')
                               ),
                               muNuSecondJetPt = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("secondJetPt"),
                                   method     = cms.string('pt()'),
                                   rank       = cms.string('second')
                               ),
                               muNuThirdJetPt = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("thirdJetPt"),
                                   method     = cms.string('pt()'),
                                   rank       = cms.string('third')
                               ),
                               muNuFirstJetEta = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("highestJetEta"),
                                   method     = cms.string('eta()'),
                                   rank       = cms.string('first')
                               ),
                               muNuSecondJetEta = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("secondJetEta"),
                                   method     = cms.string('eta()'),
                                   rank       = cms.string('second')
                               ),
                               muNuThirdJetEta = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("thirdJetEta"),
                                   method     = cms.string('eta()'),
                                   rank       = cms.string('third')
                               ),
                               muNuFirstJetPhi = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("highestJetPhi"),
                                   method     = cms.string('phi()'),
                                   rank       = cms.string('first')
                               ),
                               muNuSecondJetPhi = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("secondJetPhi"),
                                   method     = cms.string('phi()'),
                                   rank       = cms.string('second')
                               ),
                               muNuThirdJetPhi = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("thirdJetPhi"),
                                   method     = cms.string('phi()'),
                                   rank       = cms.string('third')
                               ),
                                muNuFirstJetChargedMultiplicity = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1nCharges"),
                                   method     = cms.string('chargedHadronMultiplicity()'),
                                   rank       = cms.string('first')
                               ),
                              muNuFirstJetTCHEbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1TCHEbtag"),
                                  method     = cms.string('bDiscriminator("trackCountingHighEffBJetTags")'),
                                  rank       = cms.string('first')
                              ),
                              muNuFirstJetTCHPbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1TCHPbtag"),
                                  method     = cms.string('bDiscriminator("trackCountingHighPurBJetTags")'),
                                  rank       = cms.string('first')
                              ),
                              muNuFirstJetSSVHEbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1SSVHEbtag"),
                                  method     = cms.string('bDiscriminator("simpleSecondaryVertexHighEffBJetTags")'),
                                  rank       = cms.string('first')
                              ),
                              muNuFirstJetCSVbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1CSVbtag"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")'),
                                  rank       = cms.string('first')
                              ),
                              muNuFirstJetCSVMVAbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1CSVMVAbtag"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexMVABJetTags")'),
                                  rank       = cms.string('first')
                              ),
                              muNuFirstJetCharge = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1Charge"),
                                  method     = cms.string('jetCharge'),
                                  rank       = cms.string('first')
                              ),
                               muNuFirstJetMass = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1Mass"),
                                   method     = cms.string('mass'),
                                   rank       = cms.string('first')
                               ),
                               muNuFirstPhotonEnergy = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1PhotonEnergy"),
                                   method     = cms.string('photonEnergy'),
                                   rank       = cms.string('first')
                               ),
                               muNuFirstPhotonEnergyFrac = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1PhotonEnergyFrac"),
                                   method     = cms.string('photonEnergyFraction'),
                                   rank       = cms.string('first')
                               ),
                               muNuFirstElectronEnergy = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1ElectronEnergy"),
                                   method     = cms.string('electronEnergy'),
                                   rank       = cms.string('first')
                               ),
                               muNuFirstElectronEnergyFrac = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1ElectronEnergyFrac"),
                                   method     = cms.string('chargedEmEnergyFraction'),
                                   rank       = cms.string('first')
                               ),
                               muNuFirstMuEnergy = cms.PSet(
                                    pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("J1MuonEnergy"),
                                    method     = cms.string('chargedMuEnergy'),
                                    rank       = cms.string('first')
                                ),
                                muNuFirstMuEnergyFrac = cms.PSet(
                                    pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("J1MuEnergyFrac"),
                                    method     = cms.string('muonEnergyFraction'),
                                    rank       = cms.string('first')
                                ),
                              muNuSecondJetChargedMultiplicity = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2nCharges"),
                                  method     = cms.string('chargedHadronMultiplicity()'),
                                  rank       = cms.string('second')
                              ),
                              muNuSecondJetTCHEbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2TCHEbtag"),
                                  method     = cms.string('bDiscriminator("trackCountingHighEffBJetTags")'),
                                  rank       = cms.string('second')
                              ),
                              muNuSecondJetTCHPbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2TCHPbtag"),
                                  method     = cms.string('bDiscriminator("trackCountingHighPurBJetTags")'),
                                  rank       = cms.string('second')
                              ),
                              muNuSecondJetSSVHEbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2SSVHEbtag"),
                                  method     = cms.string('bDiscriminator("simpleSecondaryVertexHighEffBJetTags")'),
                                  rank       = cms.string('second')
                              ),
                              muNuSecondJetCSVbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2CSVbtag"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")'),
                                  rank       = cms.string('second')
                              ),
                              muNuSecondJetCSVMVAbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2CSVMVAbtag"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexMVABJetTags")'),
                                  rank       = cms.string('second')
                              ),#####
                              muNuSecondJetCharge = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2Charge"),
                                  method     = cms.string('jetCharge'),
                                  rank       = cms.string('second')
                              ),
                               muNuSecondJetMass = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2Mass"),
                                   method     = cms.string('mass'),
                                   rank       = cms.string('second')
                               ),
                               muNuSecondPhotonEnergy = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2PhotonEnergy"),
                                   method     = cms.string('photonEnergy'),
                                   rank       = cms.string('second')
                               ),
                               muNuSecondPhotonEnergyFrac = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2PhotonEnergyFrac"),
                                   method     = cms.string('photonEnergyFraction'),
                                   rank       = cms.string('second')
                               ),
                               muNuSecondElectronEnergy = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2ElectronEnergy"),
                                   method     = cms.string('electronEnergy'),
                                   rank       = cms.string('second')
                               ),
                               muNuSecondElectronEnergyFrac = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2ElectronEnergyFrac"),
                                   method     = cms.string('chargedEmEnergyFraction'),
                                   rank       = cms.string('second')
                               ),
                               muNuSecondMuEnergy = cms.PSet(
                                    pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("J2MuonEnergy"),
                                    method     = cms.string('chargedMuEnergy'),
                                    rank       = cms.string('second')
                                ),
                                muNuSecondMuEnergyFrac = cms.PSet(
                                    pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("J2MuEnergyFrac"),
                                    method     = cms.string('muonEnergyFraction'),
                                    rank       = cms.string('second')
                                ),

                               muNuThirdJetChargedMultiplicity = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J3nCharges"),
                                  method     = cms.string('chargedHadronMultiplicity()'),
                                  rank       = cms.string('third')
                              ),
                              muNuThirdJetTCHEbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J3TCHEbtag"),
                                  method     = cms.string('bDiscriminator("trackCountingHighEffBJetTags")'),
                                  rank       = cms.string('third')
                              ),
                              muNuThirdJetCharge = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J3Charge"),
                                  method     = cms.string('jetCharge'),
                                  rank       = cms.string('third')
                              ),
                               muNuThirdJetMass = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J3Mass"),
                                   method     = cms.string('mass'),
                                   rank       = cms.string('third')
                               ),
                               muNuThirdPhotonEnergy = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J3PhotonEnergy"),
                                   method     = cms.string('photonEnergy'),
                                   rank       = cms.string('third')
                               ),
                               muNuThirdPhotonEnergyFrac = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J3PhotonEnergyFrac"),
                                   method     = cms.string('photonEnergyFraction'),
                                   rank       = cms.string('third')
                               ),
                               muNuThirdElectronEnergy = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J3ElectronEnergy"),
                                   method     = cms.string('electronEnergy'),
                                   rank       = cms.string('third')
                               ),
                               muNuThirdElectronEnergyFrac = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J3ElectronEnergyFrac"),
                                   method     = cms.string('chargedEmEnergyFraction'),
                                   rank       = cms.string('third')
                               ),
                               muNuThirdMuEnergy = cms.PSet(
                                    pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("J3MuonEnergy"),
                                    method     = cms.string('chargedMuEnergy'),
                                    rank       = cms.string('third')
                                ),
                                muNuThirdMuEnergyFrac = cms.PSet(
                                    pluginType = cms.string("PATMuonNuPairCSVJetVarFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("J3MuEnergyFrac"),
                                    method     = cms.string('muonEnergyFraction'),
                                    rank       = cms.string('third')
                                ),
                               mu1DXY = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("l1DXY"),
                                   method     = cms.string('lepton.userFloat("ipDXY")'),
                                   leadingOnly=cms.untracked.bool(True)
                                   )
                          
                              

   )
   setattr(process, name, eventTree)
   p = cms.Path(getattr(process,name))
   setattr(process, name+'Path', p)

#########

def addMuNuEventTreePt(process,name,src = 'wCandsJets'):
   process.TFileService = cms.Service("TFileService", fileName = cms.string("analysis.root") )
   eventTree = cms.EDAnalyzer('EventTreeMaker',
                              coreCollections = cms.VInputTag(
                                   cms.InputTag(src)
                              ),
                              PVs = cms.PSet(
                                    pluginType = cms.string("VertexSizeFiller"),
                                    src        = cms.InputTag("primaryVertexFilter"),
                                    tag        = cms.string("vertices")
                              ),
                              trigger = cms.PSet(
                                  pluginType = cms.string("TriggerFiller"),
                                  src        = cms.InputTag("patTrigger"),
                                  paths      = cms.vstring(TriggerPaths)
                              ),
                               muNuDZ = cms.PSet(
                                     pluginType = cms.string("PATMuonNuPairFiller"),
                                     src        = cms.InputTag(src),
                                     tag        = cms.string("dz"),
                                     method     = cms.string('abs(lepton.userFloat("dz"))'),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
                               genWs = cms.PSet(
                                     pluginType = cms.string("CollectionSizeFiller"),
                                     src        = cms.InputTag("genWs"),
                                     tag        = cms.string("genWs"),
                               ),
                               muNuFirstJetFlavor = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1JetParton"),
                                   method     = cms.string('partonFlavour()'),
                                   rank       = cms.string('first')
                               ),
                               muNuFirstMuonMulti = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1MuonMulti"),
                                   method     = cms.string('muonMultiplicity()'),
                                   rank       = cms.string('first')
                               ),
                               muNuSecondMuonMulti = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2MuonMulti"),
                                   method     = cms.string('muonMultiplicity()'),
                                   rank       = cms.string('second')
                               ),
                               muNuThirdMuonMulti = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J3MuonMulti"),
                                   method     = cms.string('muonMultiplicity()'),
                                   rank       = cms.string('third')
                               ),
                               muNuFirstChargeMulti = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1ChargeMulti"),
                                  method     = cms.string('chargedMultiplicity()'),
                                  rank       = cms.string('first')
                              ),
                              muNuSecondChargeMulti = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2ChargeMulti"),
                                  method     = cms.string('chargedMultiplicity()'),
                                  rank       = cms.string('second')
                              ),
                              muNuThirdChargeMulti = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J3ChargeMulti"),
                                  method     = cms.string('chargedMultiplicity()'),
                                  rank       = cms.string('third')
                              ),
                              muNuFirstElectronMulti = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1EleMulti"),
                                  method     = cms.string('electronMultiplicity()'),
                                  rank       = cms.string('first')
                              ),
                              muNuSecondElectronMulti = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2EleMulti"),
                                  method     = cms.string('electronMultiplicity()'),
                                  rank       = cms.string('second')
                              ),
                              muNuThirdElectronMulti = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J3EleMulti"),
                                  method     = cms.string('electronMultiplicity()'),
                                  rank       = cms.string('third')
                              ),
                              muNuFirstPhotonMulti = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1PhotonMulti"),
                                  method     = cms.string('photonMultiplicity()'),
                                  rank       = cms.string('first')
                              ),
                              muNuSecondPhotonMulti = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2PhotonMulti"),
                                  method     = cms.string('photonMultiplicity()'),
                                  rank       = cms.string('second')
                              ),
                              muNuThirdPhotonMulti = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J3PhotonMulti"),
                                  method     = cms.string('photonMultiplicity()'),
                                  rank       = cms.string('third')
                              ),
                              muNuSecondJetFlavor = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2JetParton"),
                                  method     = cms.string('partonFlavour()'),
                                  rank       = cms.string('second')
                              ),
                              muNuThirdJetFlavor = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J3JetParton"),
                                  method     = cms.string('partonFlavour()'),
                                  rank       = cms.string('third')
                              ),
                              genbb = cms.PSet(
                                  pluginType = cms.string("CollectionSizeFiller"),
                                  src        = cms.InputTag("genbbCands"),
                                  tag        = cms.string("genBs"),
                              ),
                              gencc = cms.PSet(
                                  pluginType = cms.string("CollectionSizeFiller"),
                                  src        = cms.InputTag("genccCands"),
                                  tag        = cms.string("genCs"),
                              ),
                              gendd = cms.PSet(
                                  pluginType = cms.string("CollectionSizeFiller"),
                                  src        = cms.InputTag("genddCands"),
                                  tag        = cms.string("genDs"),
                              ),
                              genuu = cms.PSet(
                                  pluginType = cms.string("CollectionSizeFiller"),
                                  src        = cms.InputTag("genuuCands"),
                                  tag        = cms.string("genUs"),
                              ),
                              genss = cms.PSet(
                                  pluginType = cms.string("CollectionSizeFiller"),
                                  src        = cms.InputTag("genSSCands"),
                                  tag        = cms.string("genSs"),
                              ),
                              muNuJJ = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("mJJ"),
                                  method     = cms.string("mJJ"),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
                               muNuJPt = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("ptJJ"),
                                   method     = cms.string("ptJJ"),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
                               muonPt = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("muonPt"),
                                   method     = cms.string("lepton().pt")
                               ),##
                               muNuPt = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("WPt"),
                                   method     = cms.string("corPt()")
                               ),                              
                               muNuCalMET = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("met"),
                                   method     = cms.string("calibratedMET.pt()"),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
                               muNuMET = cms.PSet(
                                     pluginType = cms.string("PATMuonNuPairFiller"),
                                     src        = cms.InputTag(src),
                                     tag        = cms.string("MET"),
                                     method     = cms.string("met().pt")
                               ),
                               muNuCorMET = cms.PSet(
                                     pluginType = cms.string("PATMuonNuPairFiller"),
                                     src        = cms.InputTag(src),
                                     tag        = cms.string("corMET"),
                                     method     = cms.string("trueMet")
                               ),
                               muNuEta = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("muonEta"),
                                   method     = cms.string("lepton.eta")
                               ),
                               muNuPhi = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("muonPhi"),
                                   method     = cms.string("lepton.phi")
                               ),
                               muNuCharge = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("muonCharge"),
                                   method     = cms.string("lepton.charge()")
                               ),
                               muNuMT = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("Mt"),
                                   method     = cms.string("mt")
                               ),
                               muNuCorMT = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("MtCal"),
                                   method     = cms.string("corMt()")
                               ),
                               muMuMass = cms.PSet(
                                   pluginType = cms.string("PATMuPairFiller"),
                                   src        = cms.InputTag("diMuonsSorted"),
                                   tag        = cms.string("DiMuonMass"),
                                   method     = cms.string("mass")
                               ),
                               muNuDPhi = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("muNuDPhi"),
                                   method     = cms.string("dPhi")
                               ),
                               muNuRecoil = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("muNuRecoil"),
                                   method     = cms.string("recoil().pt()")
                               ),
                               muNuMuRelPFIso = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("muNuRelPFIso"),
                                   method     = cms.string('(lepton.chargedHadronIso()+lepton.photonIso()+lepton.neutralHadronIso())/lepton.pt()')
                               ),
                               muNuRelStdIso03 = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("muNuRelStdIso03"),
                                   method     = cms.string('(lepton.isolationR03.sumPt+lepton.isolationR03.emEt+lepton.isolationR03.hadEt)/lepton.pt()')
                               ),
                               muNuJetsBTagCSVloosePt30 = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairJetCountFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("nJetsBTagCSV1Pt30"),
                                   method     = cms.string('userInt("fullIdLoose")>0&&bDiscriminator("combinedSecondaryVertexBJetTags")>=0.244&&pt()>30&&abs(eta)<2.1'),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
                               muNuJetsBTagCSVMedPt30 = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairJetCountFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("nJetsBTagCSV2Pt30"),
                                   method     = cms.string('userInt("fullIdLoose")>0&&bDiscriminator("combinedSecondaryVertexBJetTags")>=0.679&&pt()>30&&abs(eta)<2.1'),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
                               muNuJetsBTagCSVTightPt30 = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairJetCountFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("nJetsBTagCSV3Pt30"),
                                   method     = cms.string('userInt("fullIdLoose")>0&&bDiscriminator("combinedSecondaryVertexBJetTags")>=0.898&&pt()>30&&abs(eta)<2.1'),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
                              muNuJetsBTagTCHPTightPt30 = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsBTagTCHP3Pt30"),
                                  method     = cms.string('userInt("fullIdLoose")>0&&bDiscriminator("trackCountingHighPurBJetTags")>=3.41&&pt()>30&&abs(eta)<2.1'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muNuJetsBTagJPL1Pt30 = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsBTagJPL1Pt30"),
                                  method     = cms.string('userInt("fullIdLoose")>0&&bDiscriminator("jetProbabilityBJetTags")>=0.275&&pt()>30&&abs(eta)<2.1'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muNuJetsBTagJPL2Pt30 = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsBTagJPL2Pt30"),
                                  method     = cms.string('userInt("fullIdLoose")>0&&bDiscriminator("jetProbabilityBJetTags")>=0.545&&pt()>30&&abs(eta)<2.1'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muNuJetsBTagJPL3Pt30 = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsBTagJPL3Pt30"),
                                  method     = cms.string('userInt("fullIdLoose")>0&&bDiscriminator("")>=0.790&&pt()>30&&abs(eta)<2.1'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),                              
                              muNuJetsBTagTCHP1Pt30 = cms.PSet(
                                 pluginType = cms.string("PATMuonNuPairJetCountFiller"),
                                 src        = cms.InputTag(src),
                                 tag        = cms.string("nJetsBTagTCHP1Pt30"),
                                 method     = cms.string('userInt("fullIdLoose")>0&&bDiscriminator("trackCountingHighPurBJetTags")>=1.19&&pt()>30&&abs(eta)<2.1'),
                                 leadingOnly=cms.untracked.bool(True)
                             ),
                             muNuJetsBTagTCHP3Pt30 = cms.PSet(
                                 pluginType = cms.string("PATMuonNuPairJetCountFiller"),
                                 src        = cms.InputTag(src),
                                 tag        = cms.string("nJetsBTagTCHP3Pt30"),
                                 method     = cms.string('userInt("fullIdLoose")>0&&bDiscriminator("jetProbabilityBJetTags")>=3.41&&pt()>30&&abs(eta)<2.1'),
                                 leadingOnly=cms.untracked.bool(True)
                             ),
## #                              muNuJetsBTag3Pt30M = cms.PSet(
## #                                  pluginType = cms.string("PATMuonNuPairJetCountFiller"),
## #                                  src        = cms.InputTag(src),
## #                                  tag        = cms.string("nJetsBTag3Pt30Matched"),
## #                                  method     = cms.string('bDiscriminator("")>=3.3&&pt()>30&&abs(eta)<2.4&&abs(partonFlavour)==5'),
## #                                  leadingOnly=cms.untracked.bool(True)
## #                              ),
## #                              muNuJetsBTag3Pt30NM = cms.PSet(
## #                                  pluginType = cms.string("PATMuonNuPairJetCountFiller"),
## #                                  src        = cms.InputTag(src),
## #                                  tag        = cms.string("nJetsBTag3Pt30NotMatched"),
## #                                  method     = cms.string('bDiscriminator("")>=3.3&&pt()>30&&abs(eta)<2.4&&abs(partonFlavour)!=5'),
## #                                  leadingOnly=cms.untracked.bool(True)
## #                              ),
                               muNuJetsPt30 = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairJetCountFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("nJetsPt30"),
                                   method     = cms.string('userInt("fullIdLoose")>0&&pt()>30'),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
                               muNuJetsPt25 = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairJetCountFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("nJetsPt25"),
                                   method     = cms.string('userInt("fullIdLoose")>0&&pt()>25'),
                                   leadingOnly=cms.untracked.bool(True)
                               ),                              
                               muNuJetsPt30Tag = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairJetCountFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("nTaggableJetsPt30"),
                                   method     = cms.string('userInt("fullIdLoose")>0&&pt()>30&&abs(eta)<2.1'),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
                               muNuJetsPt25Tag = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairJetCountFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("nTaggableJetsPt25"),
                                   method     = cms.string('userInt("fullIdLoose")>0&&pt()>25'),
                                   leadingOnly=cms.untracked.bool(True)
                               ),                              
## #                              muNuJetsPt30TagMatch = cms.PSet(
## #                                  pluginType = cms.string("PATMuonNuPairJetCountFiller"),
## #                                  src        = cms.InputTag(src),
## #                                  tag        = cms.string("nTaggableJetsPt30Matched"),
## #                                  method     = cms.string('pt()>30&&abs(eta)<2.4&&abs(partonFlavour)==5'),
## #                                  leadingOnly=cms.untracked.bool( True)
## #                              ),
                               muNuFirstJetPt = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("highestJetPt"),
                                   method     = cms.string('pt()'),
                                   rank       = cms.string('first')
                               ),
                               muNuSecondJetPt = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("secondJetPt"),
                                   method     = cms.string('pt()'),
                                   rank       = cms.string('second')
                               ),
                               muNuThirdJetPt = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("thirdJetPt"),
                                   method     = cms.string('pt()'),
                                   rank       = cms.string('third')
                               ),
                               muNuFirstJetEta = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("highestJetEta"),
                                   method     = cms.string('eta()'),
                                   rank       = cms.string('first')
                               ),
                               muNuSecondJetEta = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("secondJetEta"),
                                   method     = cms.string('eta()'),
                                   rank       = cms.string('second')
                               ),
                               muNuThirdJetEta = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("thirdJetEta"),
                                   method     = cms.string('eta()'),
                                   rank       = cms.string('third')
                               ),
                               muNuFirstJetPhi = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("highestJetPhi"),
                                   method     = cms.string('phi()'),
                                   rank       = cms.string('first')
                               ),
                               muNuSecondJetPhi = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("secondJetPhi"),
                                   method     = cms.string('phi()'),
                                   rank       = cms.string('second')
                               ),
                               muNuThirdJetPhi = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("thirdJetPhi"),
                                   method     = cms.string('phi()'),
                                   rank       = cms.string('third')
                               ),
                                muNuFirstJetChargedMultiplicity = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1nCharges"),
                                   method     = cms.string('chargedHadronMultiplicity()'),
                                   rank       = cms.string('first')
                               ),
                              muNuFirstJetTCHEbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1TCHEbtag"),
                                  method     = cms.string('bDiscriminator("trackCountingHighEffBJetTags")'),
                                  rank       = cms.string('first')
                              ),
                              muNuFirstJetTCHPbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1TCHPbtag"),
                                  method     = cms.string('bDiscriminator("trackCountingHighPurBJetTags")'),
                                  rank       = cms.string('first')
                              ),
                              muNuFirstJetSSVHEbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1SSVHEbtag"),
                                  method     = cms.string('bDiscriminator("simpleSecondaryVertexHighEffBJetTags")'),
                                  rank       = cms.string('first')
                              ),
                              muNuFirstJetCSVbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1CSVbtag"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")'),
                                  rank       = cms.string('first')
                              ),
                              muNuFirstJetCSVMVAbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1CSVMVAbtag"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexMVABJetTags")'),
                                  rank       = cms.string('first')
                              ),
                              muNuFirstJetCharge = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1Charge"),
                                  method     = cms.string('jetCharge'),
                                  rank       = cms.string('first')
                              ),
                               muNuFirstJetMass = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1Mass"),
                                   method     = cms.string('mass'),
                                   rank       = cms.string('first')
                               ),
                               muNuFirstPhotonEnergy = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1PhotonEnergy"),
                                   method     = cms.string('photonEnergy'),
                                   rank       = cms.string('first')
                               ),
                               muNuFirstPhotonEnergyFrac = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1PhotonEnergyFrac"),
                                   method     = cms.string('photonEnergyFraction'),
                                   rank       = cms.string('first')
                               ),
                               muNuFirstElectronEnergy = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1ElectronEnergy"),
                                   method     = cms.string('electronEnergy'),
                                   rank       = cms.string('first')
                               ),
                               muNuFirstElectronEnergyFrac = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1ElectronEnergyFrac"),
                                   method     = cms.string('chargedEmEnergyFraction'),
                                   rank       = cms.string('first')
                               ),
                               muNuFirstMuEnergy = cms.PSet(
                                    pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("J1MuonEnergy"),
                                    method     = cms.string('chargedMuEnergy'),
                                    rank       = cms.string('first')
                                ),
                                muNuFirstMuEnergyFrac = cms.PSet(
                                    pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("J1MuEnergyFrac"),
                                    method     = cms.string('muonEnergyFraction'),
                                    rank       = cms.string('first')
                                ),
                              muNuSecondJetChargedMultiplicity = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2nCharges"),
                                  method     = cms.string('chargedHadronMultiplicity()'),
                                  rank       = cms.string('second')
                              ),
                              muNuSecondJetTCHEbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2TCHEbtag"),
                                  method     = cms.string('bDiscriminator("trackCountingHighEffBJetTags")'),
                                  rank       = cms.string('second')
                              ),
                              muNuSecondJetTCHPbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2TCHPbtag"),
                                  method     = cms.string('bDiscriminator("trackCountingHighPurBJetTags")'),
                                  rank       = cms.string('second')
                              ),
                              muNuSecondJetSSVHEbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2SSVHEbtag"),
                                  method     = cms.string('bDiscriminator("simpleSecondaryVertexHighEffBJetTags")'),
                                  rank       = cms.string('second')
                              ),
                              muNuSecondJetCSVbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2CSVbtag"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")'),
                                  rank       = cms.string('second')
                              ),
                              muNuSecondJetCSVMVAbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2CSVMVAbtag"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexMVABJetTags")'),
                                  rank       = cms.string('second')
                              ),#####
                              muNuSecondJetCharge = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2Charge"),
                                  method     = cms.string('jetCharge'),
                                  rank       = cms.string('second')
                              ),
                               muNuSecondJetMass = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2Mass"),
                                   method     = cms.string('mass'),
                                   rank       = cms.string('second')
                               ),
                               muNuSecondPhotonEnergy = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2PhotonEnergy"),
                                   method     = cms.string('photonEnergy'),
                                   rank       = cms.string('second')
                               ),
                               muNuSecondPhotonEnergyFrac = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2PhotonEnergyFrac"),
                                   method     = cms.string('photonEnergyFraction'),
                                   rank       = cms.string('second')
                               ),
                               muNuSecondElectronEnergy = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2ElectronEnergy"),
                                   method     = cms.string('electronEnergy'),
                                   rank       = cms.string('second')
                               ),
                               muNuSecondElectronEnergyFrac = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2ElectronEnergyFrac"),
                                   method     = cms.string('chargedEmEnergyFraction'),
                                   rank       = cms.string('second')
                               ),
                               muNuSecondMuEnergy = cms.PSet(
                                    pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("J2MuonEnergy"),
                                    method     = cms.string('chargedMuEnergy'),
                                    rank       = cms.string('second')
                                ),
                                muNuSecondMuEnergyFrac = cms.PSet(
                                    pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("J2MuEnergyFrac"),
                                    method     = cms.string('muonEnergyFraction'),
                                    rank       = cms.string('second')
                                ),

                               muNuThirdJetChargedMultiplicity = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J3nCharges"),
                                  method     = cms.string('chargedHadronMultiplicity()'),
                                  rank       = cms.string('third')
                              ),
                              muNuThirdJetTCHEbtag = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J3TCHEbtag"),
                                  method     = cms.string('bDiscriminator("trackCountingHighEffBJetTags")'),
                                  rank       = cms.string('third')
                              ),
                              muNuThirdJetCharge = cms.PSet(
                                  pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J3Charge"),
                                  method     = cms.string('jetCharge'),
                                  rank       = cms.string('third')
                              ),
                               muNuThirdJetMass = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J3Mass"),
                                   method     = cms.string('mass'),
                                   rank       = cms.string('third')
                               ),
                               muNuThirdPhotonEnergy = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J3PhotonEnergy"),
                                   method     = cms.string('photonEnergy'),
                                   rank       = cms.string('third')
                               ),
                               muNuThirdPhotonEnergyFrac = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J3PhotonEnergyFrac"),
                                   method     = cms.string('photonEnergyFraction'),
                                   rank       = cms.string('third')
                               ),
                               muNuThirdElectronEnergy = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J3ElectronEnergy"),
                                   method     = cms.string('electronEnergy'),
                                   rank       = cms.string('third')
                               ),
                               muNuThirdElectronEnergyFrac = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J3ElectronEnergyFrac"),
                                   method     = cms.string('chargedEmEnergyFraction'),
                                   rank       = cms.string('third')
                               ),
                               muNuThirdMuEnergy = cms.PSet(
                                    pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("J3MuonEnergy"),
                                    method     = cms.string('chargedMuEnergy'),
                                    rank       = cms.string('third')
                                ),
                                muNuThirdMuEnergyFrac = cms.PSet(
                                    pluginType = cms.string("PATMuonNuPairPtJetVarFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("J3MuEnergyFrac"),
                                    method     = cms.string('muonEnergyFraction'),
                                    rank       = cms.string('third')
                                ),
                               mu1DXY = cms.PSet(
                                   pluginType = cms.string("PATMuonNuPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("l1DXY"),
                                   method     = cms.string('lepton.userFloat("ipDXY")'),
                                   leadingOnly=cms.untracked.bool(True)
                                   )
                          
                              

   )
   setattr(process, name, eventTree)
   p = cms.Path(getattr(process,name))
   setattr(process, name+'Path', p)



def addMuTauEventTree(process,name,src = 'diTausSorted', srcLL = 'diMuonsSorted'):
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
                                  
                              pt1 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("pt1"),
                                  method     = cms.string("leg1.pt"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              pt2 = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("pt2"),
                                    method     = cms.string("leg2.pt"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),
                              charge1 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("charge1"),
                                  method     = cms.string("leg1.charge"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              charge2 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("charge2"),
                                  method     = cms.string("leg2.charge"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              pt = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("pt"),
                                    method     = cms.string("pt"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),
                              eta = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("eta"),
                                    method     = cms.string("eta"),
                                    leadingOnly=cms.untracked.bool(True)

                              ),
                              muTauEta1 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("eta1"),
                                  method     = cms.string("leg1.eta"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauEta2 = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("eta2"),
                                    method     = cms.string("leg2.eta"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauPhi1 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("phi1"),
                                  method     = cms.string("leg1.phi"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauPhi2 = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("phi2"),
                                    method     = cms.string("leg2.phi"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauDZ = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("dz"),
                                    method     = cms.string('abs(leg1.userFloat("vz")-leg2.userFloat("vz"))'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauMudZ = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("l1dz"),
                                    method     = cms.string('abs(leg1.userFloat("dz"))'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauTaudZ = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("l2dz"),
                                    method     = cms.string('abs(leg2.userFloat("dz"))'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),  
                              muTauMuvZ = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("l1Vz"),
                                    method     = cms.string('leg1.userFloat("vz")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauTauvZ = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("l2Vz"),
                                    method     = cms.string('leg2.userFloat("vz")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),   
                              muTauEleDXY = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("l1Dxy"),
                                  method     = cms.string('leg1.userFloat("ipDXY")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),                                                                                     
                              muTauRho = cms.PSet(
                                  pluginType = cms.string("EventWeightFiller"),
                                  src        = cms.InputTag("kt6PFJetsForRhoComputationVoronoi","rho"),
                                  tag        = cms.string("Rho")
                              ),

#                               muTauDCA = cms.PSet(
#                                     pluginType = cms.string("PATMuTauPairFiller"),
#                                     src        = cms.InputTag(src),
#                                     tag        = cms.string("dca"),
#                                     method     = cms.string("dca"),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
#                               muTauDist = cms.PSet(
#                                     pluginType = cms.string("PATMuTauPairFiller"),
#                                     src        = cms.InputTag(src),
#                                     tag        = cms.string("xPointDist"),
#                                     method     = cms.string("crossingPointDistance"),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
                              projMET = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("projMET"),
                                    method     = cms.string("projMET"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauCharge = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("charge"),
                                  method     = cms.string("charge"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauMass = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("mass"),
                                  method     = cms.string("mass"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauSVMass = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("svMass"),
                                  method     = cms.string("svMass"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),                              
                              muTauMT1 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("mt1"),
                                  method     = cms.string("mt1MET"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauMT = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("mt"),
                                  method     = cms.string("mt12MET"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauMT2 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("mt2"),
                                  method     = cms.string("mt2MET"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauMET = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("met"),
                                  method     = cms.string("calibratedMET.pt()"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauDPhi = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("dPhi"),
                                  method     = cms.string("dPhi12"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauDR = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("dR"),
                                  method     = cms.string("dR12"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauDPhi1MET = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("dPhi1MET"),
                                  method     = cms.string("dPhi1MET"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauDPhi2MET = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("dPhi2MET"),
                                  method     = cms.string("dPhi2MET"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauHT = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("ht"),
                                  method     = cms.string("ht"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauJJ = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("mJJ"),
                                  method     = cms.string("mJJ"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauJJPt = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("ptJJ"),
                                  method     = cms.string("ptJJ"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauVBFDEta = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfDEta"),
                                  method     = cms.string("vbfDEta"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauVBFPt1 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfPt1"),
                                  method     = cms.string("vbfPt1"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauVBFPt2 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfPt2"),
                                  method     = cms.string("vbfPt2"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauVBFEta1 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfEta1"),
                                  method     = cms.string("vbfEta1"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauVBFEta2 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfEta2"),
                                  method     = cms.string("vbfEta2"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauVBFMass = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfMass"),
                                  method     = cms.string("vbfMass"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauVBFMVA = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfMVA"),
                                  method     = cms.string("vbfMVA"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),  
                              muTauVBFDPhi = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfDPhi"),
                                  method     = cms.string("vbfDPhi"),
                                  leadingOnly=cms.untracked.bool(True)
                              ), 
                              muTauVBFDiJetPt = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfDiJetPt"),
                                  method     = cms.string("vbfDiJetPt"),
                                  leadingOnly=cms.untracked.bool(True)
                              ), 
                              muTauVBFDiTauPt = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfDiTauPt"),
                                  method     = cms.string("vbfDiTauPt"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),                               
                              muTauVBFDPhiHJ = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfDPhiHJ"),
                                  method     = cms.string("vbfDPhiHJ"),
                                  leadingOnly=cms.untracked.bool(True)
                              ), 
                              muTauVBFC1 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfC1"),
                                  method     = cms.string("vbfC1"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),  
                              muTauVBFC2 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfC2"),
                                  method     = cms.string("vbfC2"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),                                                                                                                                                                                   
                              muMuVBFJets20 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfNJetsGap20"),
                                  method     = cms.string("vbfNJetsGap20"),
                                  leadingOnly=cms.untracked.bool(True)
                               ),
                              muMuVBFJets30 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfNJetsGap30"),
                                  method     = cms.string("vbfNJetsGap30"),
                                  leadingOnly=cms.untracked.bool(True)
                               ),
                              muTauWWID = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("lWWId"),
                                  method     = cms.string('leg1.userInt("WWID2011")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauPFID = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("lPFId"),
                                  method     = cms.string('leg1.pfCandidateRef().isNonnull()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),                              
                              muTauMVAID = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("lMVAId"),
                                  method     = cms.string('leg1.userFloat("idmva")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),   
                              muTauMVAIso = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("lMVAIso"),
                                  method     = cms.string('leg1.userFloat("isomva")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),   
                              muTauRingMVAIso = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("lRingMVAIso"),
                                  method     = cms.string('leg1.userFloat("isoringsradmva")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),                                                                                        
                              muTauRelStdIso03 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("lStdRelIso"),
                                  method     = cms.string('(leg1.isolationR03.sumPt+leg1.isolationR03.emEt+leg1.isolationR03.hadEt)/leg1.pt()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),                              
                              muTauRelPFIsoDB = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("lPFIsoDB"),
                                  method     = cms.string('(leg1.userIso(0)+max(leg1.photonIso()+leg1.neutralHadronIso()-0.5*leg1.puChargedHadronIso,0.0))/leg1.pt()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauDecayMode = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauDecayMode"),
                                  method     = cms.string('leg2.decayMode()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauMuTriggerMatch = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("lTrigger"),
                                  method     = cms.string('leg1.userFloat("hltOverlapFilterIsoMu18LooseIsoPFTau20")+leg1.userFloat("hltOverlapFilterIsoMu17LooseIsoPFTau20")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauMuTriggerMatch2 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("muTrigger"),
                                  method     = cms.string('leg1.userFloat("hltL3crIsoL1sMu14erORMu16erL1f0L2f14QL3f17QL3crIsoRhoFiltered0p15")+leg1.userFloat("hltL3crIsoL1sMu16Eta2p1L1f0L2f16QL3f18QL3crIsoFiltered10")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),                              
                              muTauTauTriggerMatch = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauTrigger"),
                                  method     = cms.string('leg2.userFloat("hltOverlapFilterIsoMu18LooseIsoPFTau20")+leg2.userFloat("hltOverlapFilterIsoMu17LooseIsoPFTau20")+leg2.userFloat("hltOverlapFilterIsoMu15IsoPFTau15")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauPzeta = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("pZeta"),
                                  method     = cms.string('pZeta-1.5*pZetaVis'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauPZ = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("pZ"),
                                  method     = cms.string('pZeta'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauPZV = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("pZV"),
                                  method     = cms.string('pZetaVis'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauHadMass = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauMass"),
                                  method     = cms.string('leg2.mass()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauDecayFound = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauDecayFound"),
                                  method     = cms.string('leg2.tauID("decayModeFinding")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauVLooseIso = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauVLooseIso"),
                                  method     = cms.string('leg2.tauID("byVLooseIsolation")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauLooseIso = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauLooseIso"),
                                  method     = cms.string('leg2.tauID("byLooseIsolation")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauLooseIsoMVA = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauLooseMVAIso"),
                                  method     = cms.string('leg2.tauID("byLooseIsolationMVA")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauRAWMVAIso = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauMVAIso"),
                                  method     = cms.string('leg2.tauID("byIsolationMVAraw")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauMedIsoMVA = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauMedMVAIso"),
                                  method     = cms.string('leg2.tauID("byMediumIsolationMVA")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),                                                                                          
                              muTauMediumIso = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauMediumIso"),
                                  method     = cms.string('leg2.tauID("byMediumIsolation")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauTightIso = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),

                                  tag        = cms.string("tauTightIso"),
                                  method     = cms.string('leg2.tauID("byTightIsolation")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauLooseDBPtIso = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauLooseIsoDBPt"),
                                  method     = cms.string('leg2.tauID("byLooseCombinedIsolationDeltaBetaCorr")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauVLooseDBPtIso = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauVLooseIsoDBPt"),
                                  method     = cms.string('leg2.tauID("byVLooseCombinedIsolationDeltaBetaCorr")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauMediumDBPtIso = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauMediumIsoDBPt"),
                                  method     = cms.string('leg2.tauID("byMediumCombinedIsolationDeltaBetaCorr")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauTightDBPtIso = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauTightIsoDBPt"),
                                  method     = cms.string('leg2.tauID("byTightCombinedIsolationDeltaBetaCorr")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauElectronTightMVA = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauElectronMVAPass"),
                                  method     = cms.string('leg2.tauID("againstElectronTightMVA2")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauElectronVLMVA2Pass = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauElectronVLooseMVA"),
                                  method     = cms.string('leg2.tauID("againstElectronVLooseMVA2")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),                              
                              muTauH = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauH"),
                                  method     = cms.string('leg2.leadPFChargedHadrCand().hcalEnergy()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauE = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauE"),
                                  method     = cms.string('leg2.leadPFChargedHadrCand().ecalEnergy()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauP = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauP"),
                                  method     = cms.string('leg2.leadPFChargedHadrCand().p()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauJetsBTagCSVLPt20 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsBTagCSVLPt20"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")>=0.244&&pt()>20&&abs(eta)<2.4'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauJetsBTagCSVMPt20 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsBTagCSVMPt20"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")>=0.679&&pt()>20&&abs(eta)<2.4'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),  
                              muTauJetsBTagCSVTPt20 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsBTagCSVTPt20"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")>=0.898&&pt()>20&&abs(eta)<2.4'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),                                                                                            
                              muTauJetsPt30 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsPt30"),
                                  method     = cms.string('userInt("fullIdLoose")>0&&pt()>30'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauJetsPt30Tag = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nTaggableJetsPt30"),
                                  method     = cms.string('userInt("fullIdLoose")>0&&pt()>30&&abs(eta)<2.4'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauJetsPt30TagMatch = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nTaggableJetsPt30Matched"),
                                  method     = cms.string('userInt("fullIdLoose")>0&&pt()>30&&abs(eta)<2.4&&abs(partonFlavour)==5'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauJetsPt30TagNoMatch = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nTaggableJetsPt30NotMatched"),
                                  method     = cms.string('userInt("fullIdLoose")>0&&pt()>30&&abs(eta)<2.4&&abs(partonFlavour)!=5'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauJetsPt20 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsPt20"),
                                  method     = cms.string('userInt("fullIdLoose")>0&&pt()>20'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauJetsPt20Tag = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nTaggableJetsPt20"),
                                  method     = cms.string('userInt("fullIdLoose")>0&&pt()>20&&abs(eta)<2.4'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauJetsPt20TagMatch = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nTaggableJetsPt20Matched"),
                                  method     = cms.string('userInt("fullIdLoose")>0&&pt()>20&&abs(eta)<2.4&&abs(partonFlavour)==5'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauJetsPt20TagNoMatch = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nTaggableJetsPt20NotMatched"),
                                  method     = cms.string('userInt("fullIdLoose")>0&&pt()>20&&abs(eta)<2.4&&abs(partonFlavour)!=5'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauGenPt1 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("genPt1"),
                                  method     = cms.string('p4VisLeg1gen().pt()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauGenPt2 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("genPt2"),
                                  method     = cms.string('p4VisLeg2gen().pt()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauGenVisMass = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("genVisMass"),
                                  method     = cms.string('p4VisGen().M()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauGenMass = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("genFullMass"),
                                  method     = cms.string('p4gen().M()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauFirstJetPt = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairHighestPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("highestJetPt"),
                                  method     = cms.string('pt()'),
                              ),
                              muTauFirstJetEta = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairHighestPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("highestJetEta"),
                                  method     = cms.string('eta()'),
                              ),
                              muTauFirstJetID = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairHighestPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("highestJetID"),
                                  method     = cms.string("userFloat('fullDiscriminant')"),
                              ),                              
                              muTauFirstJetFlavour = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairHighestPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("highestJetFlavour"),
                                  method     = cms.string('partonFlavour()'),
                              ),
                              muTauFirstJetShape = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairHighestPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("highestJetShape"),
                                  method     = cms.string('userFloat("ptRMS")'),
                              ),
                              muTauFirstJetChMultiplicity = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairHighestPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("highestJetNCharged"),
                                  method     = cms.string('chargedMultiplicity()'),
                              ),
                              muTauFirstJetNeutMultiplicity = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairHighestPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("highestJetNNeutral"),
                                  method     = cms.string('photonMultiplicity()+neutralHadronMultiplicity()'),
                              ),
                              PVs = cms.PSet(
                                    pluginType = cms.string("VertexSizeFiller"),
                                    src        = cms.InputTag("primaryVertexFilter"),
                                    tag        = cms.string("vertices")
                              ),
                              mumuSize = cms.PSet(
                                    pluginType = cms.string("CollectionSizeFiller"),
                                    src        = cms.InputTag(srcLL),
                                    tag        = cms.string("diLeptons"),
                              ),
                              genTaus = cms.PSet(
                                    pluginType = cms.string("CollectionSizeFiller"),
                                    src        = cms.InputTag("genTauCands"),
                                    tag        = cms.string("genTaus"),
                              ),
                              higgsPt = cms.PSet(
                                  pluginType = cms.string("PATGenParticleFiller"),
                                  src        = cms.InputTag("genDaughters"),
                                  tag        = cms.string("higgsPt"),
                                  method     = cms.string('pt()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauSize = cms.PSet(
                                    pluginType = cms.string("CollectionSizeFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("nCands"),
                              ),
                              muTauEmbedWeight = cms.PSet(
                                    pluginType = cms.string("GenFilterInfoWeightFiller"),
                                    src        = cms.InputTag("generator","minVisPtFilter"),
                                    tag        = cms.string("embeddedWeight"),
                              ),
                              muTauEmbedPt = cms.PSet(
                                    pluginType = cms.string("PATGenParticleFiller"),
                                    src        = cms.InputTag("genDaughters"),
                                    tag        = cms.string("embeddedPt"),
                                    method     = cms.string("pt"),
                                    leadingOnly=cms.untracked.bool(False)

                              ),
                              muTauEmbedEta = cms.PSet(
                                    pluginType = cms.string("PATGenParticleFiller"),
                                    src        = cms.InputTag("genDaughters"),
                                    tag        = cms.string("embeddedEta"),
                                    method     = cms.string("eta"),
                                    leadingOnly=cms.untracked.bool(False)
                              ),
                              muTauMVANoTrig = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("lIDMVANonTrig"),
                                  method     = cms.string('leg1.userFloat("mvaNonTrigV0")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauElectronMVAPass = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauElectronMVAPass"),
                                  method     = cms.string('leg2.tauID("againstElectronMVA")'),
                                  leadingOnly=cms.untracked.bool(True)
                              )                              
   )

   setattr(process, name, eventTree)
   p = cms.Path(getattr(process,name))
   setattr(process, name+'Path', p)



#Tree for e+tau + MET final state
def addEleTauEventTree(process,name,src='eleTausSorted',srcLL='osDiElectrons',srcLT='eleTracksSorted',srcLG='eleGSFTracksSorted'):
   process.TFileService = cms.Service("TFileService", fileName = cms.string("analysis.root") )
   eventTree = cms.EDAnalyzer('EventTreeMaker',
                              coreCollections = cms.VInputTag(
                                   cms.InputTag(src)
                              ),
                              trigger = cms.PSet(
                                  pluginType = cms.string("TriggerFiller"),
                                  src        = cms.InputTag("patTrigger"),
                                  paths      = cms.vstring(
                                      TriggerPaths
                                  )
                              ),
                              eleTauSize = cms.PSet(
                                    pluginType = cms.string("CollectionSizeFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("nCands"),
                              ),                              
                              pu = cms.PSet(
                                  pluginType = cms.string("PUFiller"),
                                  src        = cms.InputTag("addPileupInfo"),
                                  tag        = cms.string("pu"),
                              ),
                              eleTauRho = cms.PSet(
                                  pluginType = cms.string("EventWeightFiller"),
                                  src        = cms.InputTag("kt6PFJetsForRhoComputationVoronoi","rho"),
                                  tag        = cms.string("Rho")
                              ),
							  genTaus = cms.PSet(
                                    pluginType = cms.string("CollectionSizeFiller"),
                                    src        = cms.InputTag("genTauCands"),
                                    tag        = cms.string("genTaus"),
                              ),
                              eleTauPt1 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("pt1"),
                                  method     = cms.string("leg1.pt"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauPdg1 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("pdg1"),
                                  method     = cms.string("genPdg1()"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauPdg2 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("pdg2"),
                                  method     = cms.string("genPdg2()"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauPt2 = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("pt2"),
                                    method     = cms.string("leg2.pt"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauPt = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("pt"),
                                    method     = cms.string("pt"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauEta1 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("eta1"),
                                  method     = cms.string("leg1.eta"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauWW = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("lWWID"),
                                  method     = cms.string('leg1.userFloat("WWID")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauWWMVA = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("lWWIDMVA"),
                                  method     = cms.string('leg1.userFloat("MITID")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauMVATrig = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("lIDMVATrig"),
                                  method     = cms.string('leg1.electronID("mvaTrigV0")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauMVANoTrig = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("lIDMVANonTrig"),
                                  method     = cms.string('leg1.electronID("mvaNonTrigV0")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),    
                              eleTauMVAIso = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("lRingMVAIso"),
                                  method     = cms.string('leg1.userFloat("isomva")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),                                                                                      
                              eleTauEleTriggerMatch = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("lTrigger"),
                                  method     = cms.string('leg1.userFloat("hltOverlapFilterIsoEle20LooseIsoPFTau20")+leg1.userFloat("hltOverlapFilterIsoEle20WP90LooseIsoPFTau20")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauEleTriggerMatch2 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("eleTrigger"),
                                  method     = cms.string('leg1.userFloat("hltEle20CaloIdVTCaloIsoTTrkIdTTrkIsoTTrackIsoFilterL1IsoEG18OrEG20")+leg1.userFloat("hltEle22WP90RhoTrackIsoFilter")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),  
                              eleTauEleTriggerMatch3 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("ele27Trigger"),
                                  method     = cms.string('leg1.userFloat("hltEle27WP80TrackIsoFilter")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),                                                           
                              eleTautauTriggerMatch = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauTrigger"),
                                  method     = cms.string('leg2.userFloat("hltOverlapFilterIsoEle20LooseIsoPFTau20")+leg2.userFloat("hltOverlapFilterIsoEle20WP90LooseIsoPFTau20")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauEta2 = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("eta2"),
                                    method     = cms.string("leg2.eta"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauEleDXY = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("l1Dxy"),
                                  method     = cms.string('leg1.userFloat("ipDXY")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauPhi1 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("phi1"),
                                  method     = cms.string("leg1.phi"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauPhi2 = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("phi2"),
                                    method     = cms.string("leg2.phi"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauDZ = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("dz"),
                                  method     = cms.string('abs(leg1.userFloat("vz")-leg2.userFloat("vz"))'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauEledZ = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("l1dz"),
                                    method     = cms.string('leg1.userFloat("dz")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauTaudZ = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("l2dz"),
                                    method     = cms.string('leg2.userFloat("dz")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),                                                              
#                               eleTauDCA = cms.PSet(
#                                   pluginType = cms.string("PATEleTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("dca"),
#                                   method     = cms.string("dca"),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
#                               eleTauDist = cms.PSet(
#                                   pluginType = cms.string("PATEleTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("xPointDist"),
#                                   method     = cms.string("dca"),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
                              eleTauEta = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("eta"),
                                    method     = cms.string("eta"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauRelIso03B = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("lStandardRelIso"),
                                    method     = cms.string("leg1.isEB()*((leg1.dr03TkSumPt()+max(leg1.dr03EcalRecHitSumEt()-1.0,0.0)+leg1.dr03HcalTowerSumEt())/leg1.pt())+leg1.isEE()*((leg1.dr03TkSumPt()+leg1.dr03EcalRecHitSumEt()+leg1.dr03HcalTowerSumEt())/leg1.pt())"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauCharge = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("charge"),
                                  method     = cms.string("charge"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTaucharge1 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("charge1"),
                                  method     = cms.string("leg1.charge"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTaucharge2 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("charge2"),
                                  method     = cms.string("leg2.charge"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),                              
                              eleTauMass = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("mass"),
                                  method     = cms.string("mass"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauSVMass = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("svMass"),
                                  method     = cms.string("svMass"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),                                
                              eleTauMT1 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("mt1"),
                                  method     = cms.string("mt1MET"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauMT2 = cms.PSet(
                                  pluginType =cms.string("PATEleTauPairFiller"),
                                  src = cms.InputTag(src),
                                  tag =cms.string("mt2"),
                                  method =cms.string("mt2MET"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauMET = cms.PSet(
                                  pluginType= cms.string("PATEleTauPairFiller"),
                                  src = cms.InputTag(src),
                                  tag =cms.string("met"),
                                  method =cms.string("met.pt()"),
                                  leadingOnly=cms.untracked.bool(True)
                                  ),
                              eleTauDPhi = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src = cms.InputTag(src),
                                  tag =cms.string("dPhi"),
                                  method =cms.string("dPhi12"),
                                  leadingOnly=cms.untracked.bool(True)
                                  ),
                              eleTauDPhi1MET = cms.PSet(
                                  pluginType =cms.string("PATEleTauPairFiller"),
                                  src = cms.InputTag(src),
                                  tag =cms.string("dPhi1MET"),
                                  method =cms.string("dPhi1MET"),
                                  leadingOnly=cms.untracked.bool(True)
                                  ),
                              eleTauDPhi2MET = cms.PSet(
                                  pluginType =cms.string("PATEleTauPairFiller"),
                                  src = cms.InputTag(src),
                                  tag = cms.string("dPhi2MET"),
                                  method = cms.string("dPhi2MET"),
                                  leadingOnly=cms.untracked.bool(True)
                                  ),
                              eleTauHT = cms.PSet(
                                  pluginType =cms.string("PATEleTauPairFiller"),
                                  src = cms.InputTag(src),
                                  tag = cms.string("ht"),
                                  method =cms.string("ht"),
                                  leadingOnly=cms.untracked.bool(True)
                                  ),
                              eleTauPFRelIsoMVA = cms.PSet(
                                  pluginType =cms.string("PATEleTauPairFiller"),
                                  src = cms.InputTag(src),
                                  tag = cms.string("lPfRelIso"),
                                  method =cms.string('leg1.userFloat("isomva")'),
                                  leadingOnly=cms.untracked.bool(True)
                                  ),                                                                                                                                                            
                              eleTauRelPFIsoDB = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("lPFIsoDB"),
                                  method     = cms.string('(leg1.userIso(0)+max(leg1.userIso(1)+leg1.neutralHadronIso()-0.5*leg1.userIso(2),0.0))/leg1.pt()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),                                                         
                              eleTauProngs = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauProngs"),
                                  method     = cms.string('leg2.signalPFChargedHadrCands.size()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauElectronDecision = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauTightElectronVeto"),
                                  method     = cms.string('leg2.tauID("againstElectronTight")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauElectronMVAPass = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauElectronMVAPass"),
                                  method     = cms.string('leg2.tauID("againstElectronMVA")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauElectronMed = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauElectronMedPass"),
                                  method     = cms.string('leg2.tauID("againstElectronMedium")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),                              
                              eleTauElectronTightMVAPass = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauElectronTightMVAPass"),
                                  method     = cms.string('leg2.tauID("againstElectronTightMVA2")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),                              
                              eleTauPzeta = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("pZeta"),
                                  method     = cms.string('pZeta-1.5*pZetaVis'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauPZ = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("pZ"),
                                  method     = cms.string('pZeta'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauPZV = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("pZV"),
                                  method     = cms.string('pZetaVis'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),                              
                              eleTauProjMET = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("projMET"),
                                  method     = cms.string('projMET'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauHadMass = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauMass"),
                                  method     = cms.string('leg2.mass()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauDecayMode = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauMode"),
                                  method     = cms.string('leg2.decayMode()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauE = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauE"),
                                  method     = cms.string('leg2.leadPFCand().ecalEnergy()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauH = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauH"),
                                  method     = cms.string('leg2.leadPFCand().hcalEnergy()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauLC = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauLCharge"),
                                  method     = cms.string('leg2.leadPFCand().charge()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauPT = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauPT"),
                                  method     = cms.string('leg2.leadPFCand().pt()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauCMVA = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauCMVA"),
                                  method     = cms.string('leg2.leadPFChargedHadrCand().mva_e_pi()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauGammas = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauGammas"),
                                  method     = cms.string('leg2.signalPFGammaCands.size()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauVLooseIso = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauVLooseIso"),
                                  method     = cms.string('leg2.tauID("byVLooseIsolation")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauLooseIso = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauLooseIso"),
                                  method     = cms.string('leg2.tauID("byLooseIsolation")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauMediumIso = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauMediumIso"),
                                  method     = cms.string('leg2.tauID("byMediumIsolation")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauTightIso = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauTightIso"),
                                  method     = cms.string('leg2.tauID("byTightIsolation")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauLooseIsoMVA = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauLooseMVAIso"),
                                  method     = cms.string('leg2.tauID("byLooseIsolationMVA")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauRAWMVAIso = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauMVAIso"),
                                  method     = cms.string('leg2.tauID("byIsolationMVAraw")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauMedIsoMVA = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauMedMVAIso"),
                                  method     = cms.string('leg2.tauID("byMediumIsolationMVA")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),                                
                              eleTauLooseDBPtIso = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauLooseIsoDBPt"),
                                  method     = cms.string('leg2.tauID("byLooseCombinedIsolationDeltaBetaCorr")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauVLooseDBPtIso = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauVLooseIsoDBPt"),
                                  method     = cms.string('leg2.tauID("byVLooseCombinedIsolationDeltaBetaCorr")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauMediumDBPtIso = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauMediumIsoDBPt"),
                                  method     = cms.string('leg2.tauID("byMediumCombinedIsolationDeltaBetaCorr")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauTightDBPtIso = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauTightIsoDBPt"),
                                  method     = cms.string('leg2.tauID("byTightCombinedIsolationDeltaBetaCorr")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauJetsBTagCSVLPt20 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsBTagCSVLPt20"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")>=0.244&&pt()>20&&abs(eta)<2.4'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauJetsBTagCSVMPt20 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsBTagCSVMPt20"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")>=0.679&&pt()>20&&abs(eta)<2.4'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),  
                              eleTauJetsBTagCSVTPt20 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsBTagCSVTPt20"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")>=0.898&&pt()>20&&abs(eta)<2.4'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),                               
                              eleTauJets30 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsPt30"),
                                  method     = cms.string('userInt("fullIdLoose")>0&&pt()>30'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauJets30Tag = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nTaggableJetsPt30"),
                                  method     = cms.string('userInt("fullIdLoose")>0&&pt()>30&&abs(eta)<2.4'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauJets30TagMatch = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nTaggableJetsPt30Matched"),
                                  method     = cms.string('userInt("fullIdLoose")>0&&pt()>30&&abs(eta)<2.4&&abs(partonFlavour)==5'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauJets30TagNoMatch = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nTaggableJetsPt30NotMatched"),
                                  method     = cms.string('userInt("fullIdLoose")>0&&pt()>30&&abs(eta)<2.4&&abs(partonFlavour)!=5'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),                                                            
                              eleTauJJ = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("mJJ"),
                                  method     = cms.string("mJJ"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauJJPt = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("ptJJ"),
                                  method     = cms.string("ptJJ"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),

                              eleTauJets20 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsPt20"),
                                  method     = cms.string('userInt("fullIdLoose")>0&&pt()>20'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauJets20Tag = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nTaggableJetsPt20"),
                                  method     = cms.string('userInt("fullIdLoose")>0&&pt()>20&&abs(eta)<2.4'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauJets20TagMatch = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nTaggableJetsPt20Matched"),
                                  method     = cms.string('userInt("fullIdLoose")>0&&pt()>20&&abs(eta)<2.4&&abs(partonFlavour)==5'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauJets20TagNoMatch = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nTaggableJetsPt20NotMatched"),
                                  method     = cms.string('userInt("fullIdLoose")>0&&pt()>20&&abs(eta)<2.4&&abs(partonFlavour)!=5'),
                                  leadingOnly=cms.untracked.bool(True)
                              ), 
                              eleTauVBFDEta = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfDEta"),
                                  method     = cms.string("vbfDEta"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauVBFMass = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfMass"),
                                  method     = cms.string("vbfMass"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauVBFMVA = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfMVA"),
                                  method     = cms.string("vbfMVA"),
                                  leadingOnly=cms.untracked.bool(True)
                              ), 
                              eleTauVBFDPhi = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfDPhi"),
                                  method     = cms.string("vbfDPhi"),
                                  leadingOnly=cms.untracked.bool(True)
                              ), 
                              eleTauVBFDiTauPt = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfDiTauPt"),
                                  method     = cms.string("vbfDiTauPt"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),                                
                              eleTauVBFDiJetPt = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfDiJetPt"),
                                  method     = cms.string("vbfDiJetPt"),
                                  leadingOnly=cms.untracked.bool(True)
                              ), 
                              eleTauVBFDPhiHJ = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfDPhiHJ"),
                                  method     = cms.string("vbfDPhiHJ"),
                                  leadingOnly=cms.untracked.bool(True)
                              ), 
                              eleTauVBFC1 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfC1"),
                                  method     = cms.string("vbfC1"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),  
                              eleTauVBFC2 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfC2"),
                                  method     = cms.string("vbfC2"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),                                                           
                              eleTauVBFPt1 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfPt1"),
                                  method     = cms.string("vbfPt1"),
                                  leadingOnly=cms.untracked.bool(True)
                               ),
                              eleTauVBFPt2 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfPt2"),
                                  method     = cms.string("vbfPt2"),
                                  leadingOnly=cms.untracked.bool(True)
                               ),
                              eleTauVBFEta1 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfEta1"),
                                  method     = cms.string("vbfEta1"),
                                  leadingOnly=cms.untracked.bool(True)
                               ),
                              eleTauVBFEta2 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfEta2"),
                                  method     = cms.string("vbfEta2"),
                                  leadingOnly=cms.untracked.bool(True)
                               ),

                              eleTauVBFJets20 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfNJetsGap20"),
                                  method     = cms.string("vbfNJetsGap20"),
                                  leadingOnly=cms.untracked.bool(True)
                               ),
                              eleTauVBFJets30 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfNJetsGap30"),
                                  method     = cms.string("vbfNJetsGap30"),
                                  leadingOnly=cms.untracked.bool(True)
                               ),
                              eleTauJetsPt30 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsPt30"),
                                  method     = cms.string('pt()>30'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauJetsPt20 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsPt20"),
                                  method     = cms.string('pt()>20'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauGenPt1 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("genPt1"),
                                  method     = cms.string('p4VisLeg1gen().pt()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauGenPt2 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("genPt2"),
                                  method     = cms.string('p4VisLeg2gen().pt()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauGenVisMass = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("genVisMass"),
                                  method     = cms.string('p4VisGen().M()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauGenMass = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("genFullMass"),
                                  method     = cms.string('p4gen().M()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauFirstJetPt = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairHighestPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("highestJetPt"),
                                  method     = cms.string('pt()'),
                              ),
                              eleTauFirstJetEta = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairHighestPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("highestJetEta"),
                                  method     = cms.string('eta()'),
                              ),
                              eleTauFirstJetID = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairHighestPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("highestJetID"),
                                  method     = cms.string("userFloat('fullDiscriminant')"),
                              ),                              
                              eleTauFirstJetFlavour = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairHighestPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("highestJetFlavour"),
                                  method     = cms.string('partonFlavour()'),
                              ),
                              eleTauFirstJetShape = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairHighestPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("highestJetShape"),
                                  method     = cms.string('userFloat("ptRMS")'),
                              ),
                              eleTauFirstJetChMultiplicity = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairHighestPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("highestJetNCharged"),
                                  method     = cms.string('chargedMultiplicity()'),
                              ),
                              eleTauFirstJetNeutMultiplicity = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairHighestPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("highestJetNNeutral"),
                                  method     = cms.string('photonMultiplicity()+neutralHadronMultiplicity()'),
                              ),
                              PVs = cms.PSet(
                                    pluginType = cms.string("VertexSizeFiller"),
                                    src        = cms.InputTag("primaryVertexFilter"),
                                    tag        = cms.string("vertices")
                              ),
                              eleeleSize = cms.PSet(
                                    pluginType = cms.string("CollectionSizeFiller"),
                                    src        = cms.InputTag(srcLL),
                                    tag        = cms.string("diLeptons"),

                              ),
                              eleTauEmbedWeight = cms.PSet(
                                    pluginType = cms.string("GenFilterInfoWeightFiller"),
                                    src        = cms.InputTag("generator","minVisPtFilter"),
                                    tag        = cms.string("embeddedWeight"),
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


