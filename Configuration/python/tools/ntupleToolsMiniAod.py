import FWCore.ParameterSet.Config as cms

from UWAnalysis.Configuration.tools.analysisToolsMiniAod import TriggerPaths


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
                              muonsSizeMT = cms.PSet(
                                    pluginType = cms.string("CollectionSizeFiller"),
                                    src        = cms.InputTag(srcU),
                                    tag        = cms.string("tightMuons"),
                              ),    
                              electronsSizeMT = cms.PSet(
                                    pluginType = cms.string("CollectionSizeFiller"),
                                    src        = cms.InputTag(srcE),
                                    tag        = cms.string("tightElectrons"),
                              ),                                  
                              pt1 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("pt1"),
                                  method     = cms.string("leg1.pt"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              pt2 = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("pt2"),
                                    method     = cms.string("leg2.pt"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              tauNIsoTracks = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("tauNIsoTracks"),
                                    method     = cms.string("leg2.userFloat('nIsoTracks')"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              tauNMatchedSeg = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("tauMuonNMatchedSeg"),
                                    method     = cms.string("leg2.userFloat('muonNMatchedSeg')"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              tauTauHadMatched = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("tauMuonMatched"),
                                    method     = cms.string("leg2.userFloat('muonTauHadMatched')"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              tauLeadPFTrackPt = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("tauLeadPFTrackPt"),
                                    method     = cms.string("leg2.userFloat('leadPFTrackPt')"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              tauLeadPFTrackPtErr = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("tauLeadPFTrackPtErr"),
                                    method     = cms.string("leg2.userFloat('leadPFTrackPtErr')"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),#FIXME
                              mass2ES = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("mass2ES"),
                                    method     = cms.string("leg2.userFloat('ESmass')"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),#FIXME
                              pt2ES = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("pt2ES"),
                                    method     = cms.string("leg2.userFloat('ESpt')"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),#FIXME
                              pt2initial = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("pt2preES"),
                                    method     = cms.string("leg2.userFloat('preESpt')"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              phi2initial = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("phi2preES"),
                                    method     = cms.string("leg2.userFloat('preESphi')"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              charge1 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("charge1"),
                                  method     = cms.string("leg1.charge"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              charge2 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("charge2"),
                                  method     = cms.string("leg2.charge"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              pt = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("pt"),
                                    method     = cms.string("pt"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),#WTF
                              muTauEta = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("fullEta"),
                                    method     = cms.string("fullEta"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),#WTF
                              muTauPhi = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("fullPhi"),
                                    method     = cms.string("fullPhi"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),#WTF
                              muTauE = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("fullEnergy"),
                                    method     = cms.string("fullEnergy"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),#WTF
                              muTauEta1 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("eta1"),
                                  method     = cms.string("leg1.eta"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              muTauEta2 = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("eta2"),
                                    method     = cms.string("leg2.eta"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              muTauPhi1 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("phi1"),
                                  method     = cms.string("leg1.phi"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              muTauPhi2 = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("phi2"),
                                    method     = cms.string("leg2.phi"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              METPhi = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("metPhi"),
                                    method     = cms.string("metPhi"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              CovMat00 = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("covMatrix00"),
                                    method     = cms.string("covMatrix00"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              CovMat10 = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("covMatrix10"),
                                    method     = cms.string("covMatrix10"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              CovMat01 = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("covMatrix01"),
                                    method     = cms.string("covMatrix01"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              CovMat11 = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("covMatrix11"),
                                    method     = cms.string("covMatrix11"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              muTauCharge = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("charge"),
                                  method     = cms.string("charge"), #-2,0,2(Sum of charges?
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              muTauMass = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("mass"),
                                  method     = cms.string("mass"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED #WTF #MASS OF WHAT--svmass?
                              muTauSVMass = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("svMass"),
                                  method     = cms.string("svMass"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED #FIXME switch to standalone                             
                              muTauSVPt = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("svPt"),
                                  method     = cms.string("svPt"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FIXME NOTFILLED switch to standalone                              
                              muTauFullPt = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("fullPt"),
                                  method     = cms.string("fullPt"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#WTF
                              muTauMT1 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("mt1"),
                                  method     = cms.string("mt1MET"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED #CHECKME
                              muTauMT = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("mt"),
                                  method     = cms.string("mt12MET"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED #CHECKME
                              muTauMT2 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("mt2"),
                                  method     = cms.string("mt2MET"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED #CHECKME
                              muTauMET = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("met"),
                                  method     = cms.string("calibratedMET.pt()"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED corrently uncorrected
                              muTauMETUnc = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("metUnc"),
                                  method     = cms.string("met.pt()"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED                              
                              muTauHT = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("ht"),
                                  method     = cms.string("ht"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              muTauEventBTag = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("btag"),
                                  method     = cms.string("EventBTag"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FIXME
                              muTauEventNBTags = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("NBTags"),
                                  method     = cms.string("NBTags"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FIXME
                               muTaumJJReg = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("mJJReg"),
                                   method     = cms.string("mJJReg"),
                                   leadingOnly=cms.untracked.bool(True)
                              ),#FIXME NO Regression Applied
                              muTauJJ = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("mJJ"),
                                  method     = cms.string("mJJ"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              muTauJJPt = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("ptJJ"),
                                  method     = cms.string("ptJJ"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              muTauJJEta = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("etaJJ"),
                                  method     = cms.string("etaJJ"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FLLED
                              muTauJJPhi = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("phiJJ"),
                                  method     = cms.string("phiJJ"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              muTauJJEnergy = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("energyJJ"),
                                  method     = cms.string("energyJJ"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              muTauHMass = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("HMass"),
                                  method     = cms.string("hhMass"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#CHECKME #FILLED
                              muTauHMassReg= cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("HMassReg"),
                                  method     = cms.string("hhMassReg"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED NOTAPPLIED
                              muTauHPt = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("HPt"),
                                  method     = cms.string("hhPt"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              muTauHEta = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("HEta"),
                                  method     = cms.string("hhEta"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              muTauHPhi = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("HPhi"),
                                  method     = cms.string("hhPhi"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              muTauHEnergy = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("HEnergy"),
                                  method     = cms.string("hhE"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              muTauVBFDEta = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfDEta"),
                                  method     = cms.string("vbfDEta"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#WTF #FILLED
                              muTauVBFMass = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfMass"),
                                  method     = cms.string("vbfMass"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#WTF #FILLED
                              muMuVBFJets20 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfNJetsGap20"),
                                  method     = cms.string("vbfNJetsGap20"),
                                  leadingOnly=cms.untracked.bool(True)
                               ),#WTF #FILLED
                              muMuVBFJets30 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfNJetsGap30"),
                                  method     = cms.string("vbfNJetsGap30"),
                                  leadingOnly=cms.untracked.bool(True)
                               ),#WTF #FILLED
                              muTauPFID = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("lPFId"),
                                  method     = cms.string('leg1.pfCandidateRef().isNonnull()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ), #FIXME                             
                              muTauRelPFIsoDB = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("lPFIsoDB"),
                                  method     = cms.string('(leg1.userIso(0)+max(leg1.photonIso()+leg1.neutralHadronIso()-0.5*leg1.puChargedHadronIso,0.0))/leg1.pt()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ), #FIXME #CHECKME
                              muTauDecayMode = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauDecayMode"),
                                  method     = cms.string('leg2.decayMode()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              muTauMuTriggerMatch = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("lTrigger"),
                                  method     = cms.string('leg1.userFloat("hltOverlapFilterIsoMu17LooseIsoPFTau20")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED #CHECKME
                              muTauTauTriggerMatch = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauTrigger"),
                                  method     = cms.string('leg2.userFloat("hltOverlapFilterIsoMu17LooseIsoPFTau20")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED #CHECKME 
                               muTauPzeta = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("pZeta"),
                                   method     = cms.string('pZeta-1.5*pZetaVis'),
                                   leadingOnly=cms.untracked.bool(True)
                               ),#FILLED
                               muTauPZ = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("pZ"),
                                   method     = cms.string('pZeta'),
                                   leadingOnly=cms.untracked.bool(True)
                               ),#FILLED
                               muTauPZV = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("pZV"),
                                   method     = cms.string('pZetaVis'),
                                   leadingOnly=cms.untracked.bool(True)
                               ),#FILLED
                              muTauHadMass = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauMass"),
                                  method     = cms.string('leg2.mass()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              muTauByCombIsoDBRaw3 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauIso"),
                                  method     = cms.string('leg2.tauID("byCombinedIsolationDeltaBetaCorrRaw3Hits")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED #CHECKME
                              muTauAgainstMuonTight2 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("againstMuonTight3"),
                                  method     = cms.string('leg2.tauID("againstMuonTight3")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              muTauAgainstMuonTightFixed = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("againstMuTightFixed"),
                                  method     = cms.string('leg2.userInt("againstMuTightFixed")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              muTauDecayFound = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauDecayFound"),
                                  method     = cms.string('leg2.tauID("decayModeFinding")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED #CHECKME
                               muTauFirstJetMuf = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1Muf"),
                                   cut        = cms.string('abs(eta())<2.4'),
                                   method     = cms.string('muonEnergyFraction()'),
                                   rank       = cms.untracked.double(0)
                               ),#FILLED
                               muTauSecondJetMuf = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2Muf"),
                                   cut        = cms.string('abs(eta())<2.4'),
                                   method     = cms.string('muonEnergyFraction()'),
                                   rank       = cms.untracked.double(1)
                               ),#FILLED
                               muTauFirstJetNhf = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1Nhf"),
                                   cut        = cms.string('abs(eta())<2.4'),
                                   method     = cms.string('neutralHadronEnergyFraction()'),
                                   rank       = cms.untracked.double(0)
                               ),#FILLED
                               muTauSecondJetNhf = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2Nhf"),
                                   cut        = cms.string('abs(eta())<2.4'),
                                   method     = cms.string('neutralHadronEnergyFraction()'),
                                   rank       = cms.untracked.double(1)
                               ),#FILLED
                               muTauFirstJetPhf = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1Phf"),
                                   cut        = cms.string('abs(eta())<2.4'),
                                   method     = cms.string('photonEnergyFraction()'),
                                   rank       = cms.untracked.double(0)
                               ),#FILLED
                               muTauSecondJetPhf = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2Phf"),
                                   cut        = cms.string('abs(eta())<2.4'),
                                   method     = cms.string('photonEnergyFraction()'),
                                   rank       = cms.untracked.double(1)
                               ),#FILLED
                                muTauCSVL1 = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("EffWEIGHTCSVL"),
                                    method     = cms.string("SFCSVL1"),
                                    leadingOnly=cms.untracked.bool(True)
                                ),#FIXME ==1 
                                muTauCSVL2 = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("EffWEIGHTCSVL2"),
                                    method     = cms.string("SFCSVL2"),
                                    leadingOnly=cms.untracked.bool(True)
                                ),#FIXME
                                muTauCSVM1 = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("EffWEIGHTCSVM"),
                                    method     = cms.string("SFCSVM1"),
                                    leadingOnly=cms.untracked.bool(True)
                                ),#FIXME
                                muTauCSVM2 = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("EffWEIGHTCSVM2"),
                                    method     = cms.string("SFCSVM2"),
                                    leadingOnly=cms.untracked.bool(True)
                                ),#FIXME
                                muTauCSVT1 = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("EffWEIGHTCSVT"),
                                    method     = cms.string("SFCSVT1"),
                                    leadingOnly=cms.untracked.bool(True)
                                ),#FIXME
                                muTauCSVT2 = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("EffWEIGHTCSVT2"),
                                    method     = cms.string("SFCSVT2"),
                                    leadingOnly=cms.untracked.bool(True)
                                ),#FIXME
                                muTauCSVL1err = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("EffWEIGHTCSVLerr"),
                                    method     = cms.string("SFCSVL1err"),
                                    leadingOnly=cms.untracked.bool(True)
                                ),#FIXME
                                muTauCSVL2err = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("EffWEIGHTCSVL2err"),
                                    method     = cms.string("SFCSVL2err"),
                                    leadingOnly=cms.untracked.bool(True)
                                ),#FIXME
                                muTauCSVM1err = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("EffWEIGHTCSVMerr"),
                                    method     = cms.string("SFCSVM1err"),
                                    leadingOnly=cms.untracked.bool(True)
                                ),#FIXME
                                muTauCSVM2err = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("EffWEIGHTCSVM2err"),
                                    method     = cms.string("SFCSVM2err"),
                                    leadingOnly=cms.untracked.bool(True)
                                ),#FIXME
                                muTauCSVT1err = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("EffWEIGHTCSVTerr"),
                                    method     = cms.string("SFCSVT1err"),
                                    leadingOnly=cms.untracked.bool(True)
                                ),#FIXME
                                muTauCSVT2err = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("EffWEIGHTCSVT2err"),
                                    method     = cms.string("SFCSVT2err"),
                                    leadingOnly=cms.untracked.bool(True)
                                ),#FIXME
                              muTauJetsBTagCSVLPt20 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsBTagCSVLPt20"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")>=0.244&&pt()>20&&abs(eta)<2.4'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FIXME
                              muTauJetsBTagCSVLPt25 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsBTagCSVLPt25"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")>=0.244&&pt()>25&&abs(eta)<2.4'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FIXME
                              muTauJetsBTagCSVMPt20 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsBTagCSVMPt20"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")>=0.679&&pt()>20&&abs(eta)<2.4'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FIXME
                              muTauJetsBTagCSVMPt25 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsBTagCSVMPt25"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")>=0.679&&pt()>25&&abs(eta)<2.4'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),  #FIXME
                              muTauJetsBTagCSVTPt20 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsBTagCSVTPt20"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")>=0.898&&pt()>20&&abs(eta)<2.4'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),  #FIXME
                              muTauJetsBTagCSVTPt25 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsBTagCSVTPt25"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")>=0.898&&pt()>25&&abs(eta)<2.4'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),   #FIXME     
                              muTauJetsPt30 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsPt30"),
                                  method     = cms.string('pt()>30'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FIXME #add in Loose Jet ID
                              muTauJetsPt30Tag = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nTaggableJetsPt30"),
                                  method     = cms.string('pt()>30&&abs(eta)<2.4'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FIXME #removed fullIdLoose
                              muTauJetsPt30TagMatch = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nTaggableJetsPt30Matched"),
                                  method     = cms.string('userInt("fullIdLoose")>0&&pt()>30&&abs(eta)<2.4&&abs(partonFlavour)==5'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FIXME
                              muTauJetsPt30TagNoMatch = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nTaggableJetsPt30NotMatched"),
                                  method     = cms.string('userInt("fullIdLoose")>0&&pt()>30&&abs(eta)<2.4&&abs(partonFlavour)!=5'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FIXME
                              muTauJetsPt20 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsPt20"),
                                  method     = cms.string('pt()>20'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FIXME #ADD IN LOOSE ID
                              muTauJetsPt20Tag = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nTaggableJetsPt20"),
                                  method     = cms.string('pt()>20&&abs(eta)<2.4'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FIXME #removed userInt("fullIdLoose")>0&&
                              muTauJetsPt20TagMatch = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nTaggableJetsPt20Matched"),
                                  method     = cms.string('userInt("fullIdLoose")>0&&pt()>20&&abs(eta)<2.4&&abs(partonFlavour)==5'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FIXME
                              muTauJetsPt20TagNoMatch = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nTaggableJetsPt20NotMatched"),
                                  method     = cms.string('userInt("fullIdLoose")>0&&pt()>20&&abs(eta)<2.4&&abs(partonFlavour)!=5'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FIXME
                              muTauJetsPt20TagMatchTag = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nTaggableJetsPt20MatchedTagged"),
                                  method     = cms.string('userInt("fullIdLoose")>0&&pt()>20&&abs(eta)<2.4&&abs(partonFlavour)==5&&bDiscriminator("combinedSecondaryVertexBJetTags")>=0.679'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FIXME
                              muTauJetsPt20TagNoMatchTag = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nTaggableJetsPt20NotMatchedTagged"),
                                  method     = cms.string('userInt("fullIdLoose")>0&&pt()>20&&abs(eta)<2.4&&abs(partonFlavour)!=5&&bDiscriminator("combinedSecondaryVertexBJetTags")>=0.679'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FIXME
                              muTauGenPt1 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("genPt1"),
                                  method     = cms.string('p4Leg1gen().pt()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              muTauGenPt2 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("genPt2"),
                                  method     = cms.string('p4Leg2gen().pt()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              muTauPdg1 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("pdg1"),
                                  method     = cms.string("genPdg1()"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              muTauPdg2 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("pdg2"),
                                  method     = cms.string("genPdg2()"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              muTauVisGenPt1 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("genVisPt1"),
                                  method     = cms.string('p4VisLeg1gen().pt()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FIXME #mostly zero?
                              muTauVisGenPt2 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("genVisPt2"),
                                  method     = cms.string('p4VisLeg2gen().pt()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FIXME #mostly zero

                              muTauGenVisMass = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("genVisMass"),
                                  method     = cms.string('p4VisGen().M()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FIXME #FILLED LOOKS WRONG
                              muTauGenMassMatched = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("genFullMassMatched"),
                                  method     = cms.string('p4gen().M()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#CHECKME #FILLED LOOKS WRONG
                              muTauGenMass = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("genFullMass"),
                                  method     = cms.string('genBosonMass()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED #CHECKME
                              muTauFirstJetID = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairHighestPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("highestJetID"),
                                  method     = cms.string("userFloat('fullDiscriminant')"),
                              ), #FIXME                             
                              muTauFirstJetFlavour = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairHighestPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("highestJetFlavour"),
                                  method     = cms.string('partonFlavour()'),
                              ), #FILLED
                              muTauFirstJetShape = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairHighestPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("highestJetShape"),
                                  method     = cms.string('userFloat("ptRMS")'),
                              ),#FILLED #sum of jet constituents ptRMS
                              muTauFirstJetChMultiplicity = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairHighestPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("highestJetNCharged"),
                                  method     = cms.string('chargedMultiplicity()'),
                              ),#FILLED
                              muTauFirstJetBTagCSV = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairHighestPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("highestJetBTagCSV"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")'),
                              ), #FIXME
                              muTauFirstJetNeutMultiplicity = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairHighestPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("highestJetNNeutral"),
                                  method     = cms.string('photonMultiplicity()+neutralHadronMultiplicity()'),
                              ),#FILLED
                              PVs = cms.PSet(
                                    pluginType = cms.string("VertexSizeFiller"),
                                    src        = cms.InputTag("primaryVertexFilter"),
                                    tag        = cms.string("vertices")
                              ),#FILLED
                              mumuSize = cms.PSet(
                                    pluginType = cms.string("CollectionSizeFiller"),
                                    src        = cms.InputTag(srcLL),
                                    tag        = cms.string("diLeptons"),
                              ),#FIXME #ALWAYS ZERO
                              mumuDR = cms.PSet(
                                   pluginType = cms.string("PATMuPairFiller"),
                                   src        = cms.InputTag(srcLL),
                                   tag        = cms.string("diLeptonDR"),
                                   method     = cms.string("dR12")
                               ),#FIXME #ALWAYS -1
                              genTaus = cms.PSet(
                                    pluginType = cms.string("CollectionSizeFiller"),
                                    src        = cms.InputTag("genTauCands"),
                                    tag        = cms.string("genTaus"),
                              ),#FIXME #ALWAYS ZERO
                              higgsPt = cms.PSet(
                                  pluginType = cms.string("PATGenParticleFiller"),
                                  src        = cms.InputTag("genDaughters"),
                                  tag        = cms.string("higgsPt"),
                                  method     = cms.string('pt()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FIXME (TOP SAMPLE)
                              muTauSize = cms.PSet(
                                    pluginType = cms.string("CollectionSizeFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("nCands"),
                              ),#FILLED
                              muTauLHEProduct = cms.PSet(
                                    pluginType = cms.string("LHEProductFiller"),
                                    src        = cms.InputTag("source"),
                                    tag        = cms.string("LHEProduct"),
                              ),#FIXME
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
                              ),#FIXME #CHECKME
                               muTauFirstJetMVASF = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1MVASf"),
                                   method     = cms.string('userFloat("mvaSF")'),
                                   rank       = cms.untracked.double(0)
                               ),#FIXME #no reg applied
                               muTauSecondJetMVASF = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2MVASf"),
                                   method     = cms.string('userFloat("mvaSF")'),
                                   rank       = cms.untracked.double(1)
                               ),#FIXME #no reg applied
                              muTauGenJetPt1 = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1GenPt"),
                                   method     = cms.string('userFloat("genJetPt")'),
                                   rank       = cms.untracked.double(0)
                               ),#FIXME
                               muTauGenJetPt2 = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2GenPt"),
                                   method     = cms.string('userFloat("genJetPt")'),
                                   rank       = cms.untracked.double(1)
                               ),#FIXME
                              muTauGenJetEta1 = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1GenEta"),
                                   method     = cms.string('userFloat("genJetEta")'),
                                   rank       = cms.untracked.double(0)
                               ),#FIXME
                               muTauGenJetEta2 = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2GenEta"),
                                   method     = cms.string('userFloat("genJetEta")'),
                                   rank       = cms.untracked.double(1)
                               ),#FIXME
                              muTauGenJetPhi1 = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1GenPhi"),
                                   method     = cms.string('userFloat("genJetPhi")'),
                                   rank       = cms.untracked.double(0)
                               ),#FIXME
                               muTauGenJetPhi2 = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2GenPhi"),
                                   method     = cms.string('userFloat("genJetPhi")'),
                                   rank       = cms.untracked.double(1)
                               ),#FIXME
                              muTauFirstJetPt1 = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1Pt"),
                                   method     = cms.string('pt()'),
                                   rank       = cms.untracked.double(0)
                               ),#FILLED
                               muTauSecondJetPt = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2Pt"),
                                   method     = cms.string('pt()'),
                                   rank       = cms.untracked.double(1)
                               ),#FILLED
                               muTauFirstJetEta1 = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1Eta"),
                                   method     = cms.string('eta()'),
                                   rank       = cms.untracked.double(0)
                               ),#FILLED
                               muTauSecondJetEta = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2Eta"),
                                   method     = cms.string('eta()'),
                                   rank       = cms.untracked.double(1)
                               ),#FILLED 
                               muTauFirstJetPhi1 = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1Phi"),
                                   method     = cms.string('phi()'),
                                   rank       = cms.untracked.double(0)
                               ),#FILLED
                               muTauSecondJetPhi = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2Phi"),
                                   method     = cms.string('phi()'),
                                   rank       = cms.untracked.double(1)
                               ),#FILLED
                              muTauFirstJetCSVbtag1 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1CSVbtag"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")'),
                                  rank       = cms.untracked.double(0)
                              ),#FIXME
                               muTauSecondJetCSVbtag = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2CSVbtag"),
                                   method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")'),
                                   rank       = cms.untracked.double(1)
                               ),#FIXME
                                muTauFirstJetPt1CSVSort = cms.PSet(
                                     pluginType = cms.string("PATMuTauPairCSVJetVarFiller"),
                                     src        = cms.InputTag(src),
                                     tag        = cms.string("J1PtCSVSort"),
                                     method     = cms.string('pt()'),
                                     cut        = cms.string('abs(eta())<2.4'),
                                     rank       = cms.untracked.double(0)
                                 ),#FILLED #FIXME #CHECKME #MUST BE WRONG
                                  muTauSecondJetPtCSVSort = cms.PSet(
                                      pluginType = cms.string("PATMuTauPairCSVJetVarFiller"),
                                      src        = cms.InputTag(src),
                                      tag        = cms.string("J2PtCSVSort"),
                                      cut        = cms.string('abs(eta())<2.4'),
                                      method     = cms.string('pt()'),
                                      rank       = cms.untracked.double(1)
                                  ),#FILLED #FIXME #CHECKME #MUST BE WRONG
                                  muTauFirstJetEtaCSVSort = cms.PSet(
                                      pluginType = cms.string("PATMuTauPairCSVJetVarFiller"),
                                      src        = cms.InputTag(src),
                                      tag        = cms.string("J1EtaCSVSort"),
                                      cut        = cms.string('abs(eta())<2.4'),
                                      method     = cms.string('eta()'),
                                      rank       = cms.untracked.double(0)
                                  ),#FILLED #FIXME #CHECKME #MUST BE WRONG
                                  muTauSecondJetEtaCSVSort = cms.PSet(
                                      pluginType = cms.string("PATMuTauPairCSVJetVarFiller"),
                                      src        = cms.InputTag(src),
                                      tag        = cms.string("J2EtaCSVSort"),
                                      cut        = cms.string('abs(eta())<2.4'),
                                      method     = cms.string('eta()'),
                                      rank       = cms.untracked.double(1)
                                  ),#FILLED #FIXME #CHECKME #MUST BE WRONG
                                  muTauFirstJetPhiCSVSort = cms.PSet(
                                      pluginType = cms.string("PATMuTauPairCSVJetVarFiller"),
                                      src        = cms.InputTag(src),
                                      tag        = cms.string("J1PhiCSVSort"),
                                      cut        = cms.string('abs(eta())<2.4'),
                                      method     = cms.string('phi()'),
                                      rank       = cms.untracked.double(0)
                                  ),#FILLED #FIXME #CHECKME #MUST BE WRONG
                                  muTauSecondJetPhiCSVSort = cms.PSet(
                                      pluginType = cms.string("PATMuTauPairCSVJetVarFiller"),
                                      src        = cms.InputTag(src),
                                      tag        = cms.string("J2PhiCSVSort"),
                                      cut        = cms.string('abs(eta())<2.4'),
                                      method     = cms.string('phi()'),
                                      rank       = cms.untracked.double(1)
                                  ),#FILLED #FIXME #CHECKME #MUST BE WRONG
                                  muTauFirstJetFlavorCSVSort = cms.PSet(
                                      pluginType = cms.string("PATMuTauPairCSVJetVarFiller"),
                                      src        = cms.InputTag(src),
                                      tag        = cms.string("J1FlavorCSVSort"),
                                      cut        = cms.string('abs(eta())<2.4'),
                                      method     = cms.string('partonFlavour()'),
                                      rank       = cms.untracked.double(0)
                                  ),#FILLED #FIXME #CHECKME #MUST BE WRONG
                                  muTauSecondJetFlavorCSVSort = cms.PSet(
                                      pluginType = cms.string("PATMuTauPairCSVJetVarFiller"),
                                      src        = cms.InputTag(src),
                                      tag        = cms.string("J2FlavorCSVSort"),
                                      cut        = cms.string('abs(eta())<2.4'),
                                      method     = cms.string('partonFlavour()'),
                                      rank       = cms.untracked.double(1)
                                 ),#FILLED #FIXME #CHECKME #MUST BE WRONG
                                 muTauFirstJetCSVbtagCSVSort = cms.PSet(
                                     pluginType = cms.string("PATMuTauPairCSVJetVarFiller"),
                                     src        = cms.InputTag(src),
                                     tag        = cms.string("J1CSVbtagCSVSort"),
                                     cut        = cms.string('abs(eta())<2.4'),
                                     method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")'),
                                     rank       = cms.untracked.double(0)
                                 ),#FIXME
                                 muTauSecondJetCSVbtagCSVSort = cms.PSet(
                                     pluginType = cms.string("PATMuTauPairCSVJetVarFiller"),
                                     src        = cms.InputTag(src),
                                     tag        = cms.string("J2CSVbtagCSVSort"),
                                     cut        = cms.string('abs(eta())<2.4'),
                                     method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")'),
                                     rank       = cms.untracked.double(1)
                               ),#FIXME
                              muTauTauZIP = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauZIP"),
                                  method     = cms.string('leg2.userFloat("zIP")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED
                              muTauMuTight = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauMuTightFixed"),
                                  method     = cms.string('leg2.userInt("againstMuTightFixed")'),
                                  leadingOnly=cms.untracked.bool(True)
                              )#FILLED #AgainstMuTight3                                                                                                                
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
                              eleTauSize = cms.PSet(
                                    pluginType = cms.string("CollectionSizeFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("nCands"),
                              ),  
                              muonsSizeET = cms.PSet(
                                    pluginType = cms.string("CollectionSizeFiller"),
                                    src        = cms.InputTag(srcU),
                                    tag        = cms.string("tightMuons"),
                              ),   
                              electronsSizeET = cms.PSet(
                                    pluginType = cms.string("CollectionSizeFiller"),
                                    src        = cms.InputTag(srcE),
                                    tag        = cms.string("tightElectrons"),
                              ),                              
                              pu = cms.PSet(
                                  pluginType = cms.string("PUFiller"),
                                  src        = cms.InputTag("addPileupInfo"),
                                  tag        = cms.string("pu"),
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
                              tauNIsoTracks = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("tauNIsoTracks"),
                                    method     = cms.string("leg2.userFloat('nIsoTracks')"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),
                              tauNMatchedSeg = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("tauMuonNMatchedSeg"),
                                    method     = cms.string("leg2.userFloat('muonNMatchedSeg')"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),
                              tauTauHadMatched = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("tauMuonMatched"),
                                    method     = cms.string("leg2.userFloat('muonTauHadMatched')"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),
                              tauLeadPFTrackPt = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("tauLeadPFTrackPt"),
                                    method     = cms.string("leg2.userFloat('leadPFTrackPt')"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),
                              tauLeadPFTrackPtErr = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("tauLeadPFTrackPtErr"),
                                    method     = cms.string("leg2.userFloat('leadPFTrackPtErr')"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),
                              mass2initial = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("mass2ES"),
                                    method     = cms.string("leg2.userFloat('ESmass')"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),
                              pt2ES = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("pt2ES"),
                                    method     = cms.string("leg2.userFloat('ESpt')"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),
                              eletaupt2initial = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("pt2preES"),
                                    method     = cms.string("leg2.userFloat('preESpt')"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),
                              eletauphi2initial = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("phi2preES"),
                                    method     = cms.string("leg2.userFloat('preESphi')"),
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
                              eleTauSCEta1 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("SCeta1"),
                                  method     = cms.string("leg1.superCluster().eta()"),
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
                              eleTauConversion = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("eMatchedConversion"),
                                  method     = cms.string('leg1.userInt("HasMatchedConversion")'),
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
                              eleTauEta = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("fullEta"),
                                    method     = cms.string("fullEta"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauPhi = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("fullPhi"),
                                    method     = cms.string("fullPhi"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauE = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("fullEnergy"),
                                    method     = cms.string("fullEnergy"),
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
                              EleTauMETPhi = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("metPhi"),
                                    method     = cms.string("metPhi"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              EleTauCovMat00 = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("covMatrix00"),
                                    method     = cms.string("covMatrix00"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              EleTauCovMat10 = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("covMatrix10"),
                                    method     = cms.string("covMatrix10"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              EleTauCovMat01 = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("covMatrix01"),
                                    method     = cms.string("covMatrix01"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              EleTauCovMat11 = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("covMatrix11"),
                                    method     = cms.string("covMatrix11"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),                              
                              eleTauSVMass = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("svMass"),
                                  method     = cms.string("svMass"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),                                
                              eleTauSVPt = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("svPt"),
                                  method     = cms.string("svPt"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauFullPt = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("fullPt"),
                                  method     = cms.string("fullPt"),
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
                                  method =cms.string("calibratedMET.pt()"),
                                  leadingOnly=cms.untracked.bool(True)
                                  ),
                              eleTauMETUnc = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("metUnc"),
                                  method     = cms.string("met.pt()"),
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
                              eleTauEventBTag = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("btag"),
                                  method     = cms.string("EventBTag"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauEventNBTags = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("NBTags"),
                                  method     = cms.string("NBTags"),
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
                              eleTauElectronTightMVA3Pass = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauElectronTightMVA3Pass"),
                                  method     = cms.string('leg2.tauID("againstElectronTightMVA3")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ), 
                              eleTauHadMass = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauMass"),
                                  method     = cms.string('leg2.mass()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauByCombIsoDBRaw3 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauIso"),
                                  method     = cms.string('leg2.tauID("byCombinedIsolationDeltaBetaCorrRaw3Hits")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauAgainstEleMVA3raw = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("againstElectronMVA3raw_2"),
                                  method     = cms.string('leg2.tauID("againstElectronMVA3raw")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauAgainstMuonLoose2 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("againstMuonLoose2_2"),
                                  method     = cms.string('leg2.tauID("againstMuonLoose2")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauDecayMode = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauDecayMode"),
                                  method     = cms.string('leg2.decayMode()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauRAWMVAIso = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauMVAIso"),
                                  method     = cms.string('leg2.tauID("byIsolationMVA2raw")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                               eleTauFirstJetElef = cms.PSet(
                                   pluginType = cms.string("PATEleTauPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1Muf"),
                                   cut        = cms.string('abs(eta())<2.4'),
                                   method     = cms.string('muonEnergyFraction()'),
                                   rank       = cms.untracked.double(0)
                               ),
                               eleTauSecondJetMuf = cms.PSet(
                                   pluginType = cms.string("PATEleTauPairCSVJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2Muf"),
                                   cut        = cms.string('abs(eta())<2.4'),
                                   method     = cms.string('muonEnergyFraction()'),
                                   rank       = cms.untracked.double(1)
                               ),
                                eleTauCSVL1 = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("EffWEIGHTCSVL"),
                                    method     = cms.string("SFCSVL1"),
                                    leadingOnly=cms.untracked.bool(True)
                                ),
                                eleTauCSVL2 = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("EffWEIGHTCSVL2"),
                                    method     = cms.string("SFCSVL2"),
                                    leadingOnly=cms.untracked.bool(True)
                                ),
                                eleTauCSVM1 = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("EffWEIGHTCSVM"),
                                    method     = cms.string("SFCSVM1"),
                                    leadingOnly=cms.untracked.bool(True)
                                ),
                                eleTauCSVM2 = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("EffWEIGHTCSVM2"),
                                    method     = cms.string("SFCSVM2"),
                                    leadingOnly=cms.untracked.bool(True)
                                ),
                                eleTauCSVT1 = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("EffWEIGHTCSVT"),
                                    method     = cms.string("SFCSVT1"),
                                    leadingOnly=cms.untracked.bool(True)
                                ),
                                eleTauCSVT2 = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("EffWEIGHTCSVT2"),
                                    method     = cms.string("SFCSVT2"),
                                    leadingOnly=cms.untracked.bool(True)
                                ),
                                eleTauCSVL1err = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("EffWEIGHTCSVLerr"),
                                    method     = cms.string("SFCSVL1err"),
                                    leadingOnly=cms.untracked.bool(True)
                                ),
                                eleTauCSVL2err = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("EffWEIGHTCSVL2err"),
                                    method     = cms.string("SFCSVL2err"),
                                    leadingOnly=cms.untracked.bool(True)
                                ),
                                eleTauCSVM1err = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("EffWEIGHTCSVMerr"),
                                    method     = cms.string("SFCSVM1err"),
                                    leadingOnly=cms.untracked.bool(True)
                                ),
                                eleTauCSVM2err = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("EffWEIGHTCSVM2err"),
                                    method     = cms.string("SFCSVM2err"),
                                    leadingOnly=cms.untracked.bool(True)
                                ),
                                eleTauCSVT1err = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("EffWEIGHTCSVTerr"),
                                    method     = cms.string("SFCSVT1err"),
                                    leadingOnly=cms.untracked.bool(True)
                                ),
                                eleTauCSVT2err = cms.PSet(
                                    pluginType = cms.string("PATEleTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("EffWEIGHTCSVT2err"),
                                    method     = cms.string("SFCSVT2err"),
                                    leadingOnly=cms.untracked.bool(True)
                                 ),
                              eleTauJetsBTagCSVLPt20 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsBTagCSVLPt20"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")>=0.244&&pt()>20&&abs(eta)<2.4'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauJetsBTagCSVLPt25 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsBTagCSVLPt25"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")>=0.244&&pt()>25&&abs(eta)<2.4'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauJetsBTagCSVMPt20 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsBTagCSVMPt20"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")>=0.679&&pt()>20&&abs(eta)<2.4'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauJetsBTagCSVMPt25 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsBTagCSVMPt25"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")>=0.679&&pt()>25&&abs(eta)<2.4'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),  
                              eleTauJetsBTagCSVTPt20 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsBTagCSVTPt20"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")>=0.898&&pt()>20&&abs(eta)<2.4'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),  
                              eleTauJetsBTagCSVTPt25 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsBTagCSVTPt25"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")>=0.898&&pt()>25&&abs(eta)<2.4'),
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
                              eleTauJJEta = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("etaJJ"),
                                  method     = cms.string("etaJJ"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauJJPhi = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("phiJJ"),
                                  method     = cms.string("phiJJ"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauJJEnergy = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("energyJJ"),
                                  method     = cms.string("energyJJ"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTaumJJReg = cms.PSet(
                                   pluginType = cms.string("PATEleTauPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("mJJReg"),
                                   method     = cms.string("mJJReg"),
                                   leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauHMass = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("HMass"),
                                  method     = cms.string("hhMass"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauHMassReg= cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("HMassReg"),
                                  method     = cms.string("hhMassReg"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauHPt = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("HPt"),
                                  method     = cms.string("hhPt"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauHEta = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("HEta"),
                                  method     = cms.string("hhEta"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauHPhi = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("HPhi"),
                                  method     = cms.string("hhPhi"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauHEnergy = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("HEnergy"),
                                  method     = cms.string("hhE"),
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
                              eleTauJets20TagMatchTag = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nTaggableJetsPt20MatchedTagged"),
                                  method     = cms.string('userInt("fullIdLoose")>0&&pt()>20&&abs(eta)<2.4&&abs(partonFlavour)==5&&bDiscriminator("combinedSecondaryVertexBJetTags")>=0.679'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauJets20TagNoMatchTag = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nTaggableJetsPt20NotMatchedTagged"),
                                  method     = cms.string('userInt("fullIdLoose")>0&&pt()>20&&abs(eta)<2.4&&abs(partonFlavour)!=5&&bDiscriminator("combinedSecondaryVertexBJetTags")>=0.679'),
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
                              eleTauVBFDPhi = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfDPhi"),
                                  method     = cms.string("vbfDPhi"),
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
                                  method     = cms.string('p4Leg1gen().pt()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauGenPt2 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("genPt2"),
                                  method     = cms.string('p4Leg2gen().pt()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauVisGenPt1 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("genVisPt1"),
                                  method     = cms.string('p4VisLeg1gen().pt()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauVisGenPt2 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("genVisPt2"),
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
                              eleTauGenMassMatched = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("genFullMassMatched"),
                                  method     = cms.string('p4gen().M()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauGenMass = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("genFullMass"),
                                  method     = cms.string('genBosonMass()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                               eleTauFirstJetMVASF = cms.PSet(
                                   pluginType = cms.string("PATEleTauPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1MVASf"),
                                   method     = cms.string('userFloat("mvaSF")'),
                                   rank       = cms.untracked.double(0)
                               ),
                               eleTauSecondJetMVASF = cms.PSet(
                                   pluginType = cms.string("PATEleTauPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2MVASf"),
                                   method     = cms.string('userFloat("mvaSF")'),
                                   rank       = cms.untracked.double(1)
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
                              eleTauFirstJetBTagCSV = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairHighestPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("highestJetBTagCSV"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")'),
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
                              eeDR = cms.PSet(
                                   pluginType = cms.string("PATElePairFiller"),
                                   src        = cms.InputTag(srcLL),
                                   tag        = cms.string("diLeptonDR"),
                                   method     = cms.string("dR12")
                               ),
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
                              ),
                              eleTauFirstJetPt1 = cms.PSet(
                                   pluginType = cms.string("PATEleTauPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1Pt"),
                                   method     = cms.string('pt()'),
                                   rank       = cms.untracked.double(0)
                               ),
                               eleTauSecondJetPt = cms.PSet(
                                   pluginType = cms.string("PATEleTauPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2Pt"),
                                   method     = cms.string('pt()'),
                                   rank       = cms.untracked.double(1)
                               ),
                               eleTauFirstJetEta1 = cms.PSet(
                                   pluginType = cms.string("PATEleTauPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1Eta"),
                                   method     = cms.string('eta()'),
                                   rank       = cms.untracked.double(0)
                               ),
                               eleTauSecondJetEta = cms.PSet(
                                   pluginType = cms.string("PATEleTauPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2Eta"),
                                   method     = cms.string('eta()'),
                                   rank       = cms.untracked.double(1)
                               ),
                               eleTauFirstJetPhi1 = cms.PSet(
                                   pluginType = cms.string("PATEleTauPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1Phi"),
                                   method     = cms.string('phi()'),
                                   rank       = cms.untracked.double(0)
                               ),
                               eleTauSecondJetPhi = cms.PSet(
                                   pluginType = cms.string("PATEleTauPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2Phi"),
                                   method     = cms.string('phi()'),
                                   rank       = cms.untracked.double(1)
                               ),
                              eleTauFirstJetCSVbtag1 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1CSVbtag"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")'),
                                  rank       = cms.untracked.double(0)
                              ),
                              eleTauSecondJetCSVbtag = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J2CSVbtag"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")'),
                                  rank       = cms.untracked.double(1)
                              ),
                              eleTauEleMVALoose = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauEleLoose"),
                                  method     = cms.string('leg2.userInt("againstEleMVALoose")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ), 
                              eleTauEleMVAMedium = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauEleMedium"),
                                  method     = cms.string('leg2.userInt("againstEleMVAMedium")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ), 
                              eleTauEleMVATight = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauEleTight"),
                                  method     = cms.string('leg2.userInt("againstEleMVATight")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ), 
                              eleTauEleMVAVTight = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauEleVeryTight"),
                                  method     = cms.string('leg2.userInt("againstEleMVAVeryTight")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                                eleTauFirstJetPt1CSVSort = cms.PSet(
                                     pluginType = cms.string("PATEleTauPairCSVJetVarFiller"),
                                     src        = cms.InputTag(src),
                                     tag        = cms.string("J1PtCSVSort"),
                                     cut        = cms.string('abs(eta())<2.4'),
                                     method     = cms.string('pt()'),
                                     rank       = cms.untracked.double(0)
                                 ),
                                  eleTauSecondJetPtCSVSort = cms.PSet(
                                      pluginType = cms.string("PATEleTauPairCSVJetVarFiller"),
                                      src        = cms.InputTag(src),
                                      tag        = cms.string("J2PtCSVSort"),
                                      cut        = cms.string('abs(eta())<2.4'),
                                      method     = cms.string('pt()'),
                                      rank       = cms.untracked.double(1)
                                  ),
                                  eleTauFirstJetEtaCSVSort = cms.PSet(
                                      pluginType = cms.string("PATEleTauPairCSVJetVarFiller"),
                                      src        = cms.InputTag(src),
                                      tag        = cms.string("J1EtaCSVSort"),
                                      cut        = cms.string('abs(eta())<2.4'),
                                      method     = cms.string('eta()'),
                                      rank       = cms.untracked.double(0)
                                  ),
                                  eleTauSecondJetEtaCSVSort = cms.PSet(
                                      pluginType = cms.string("PATEleTauPairCSVJetVarFiller"),
                                      src        = cms.InputTag(src),
                                      tag        = cms.string("J2EtaCSVSort"),
                                      cut        = cms.string('abs(eta())<2.4'),
                                      method     = cms.string('eta()'),
                                      rank       = cms.untracked.double(1)
                                  ),
                                  eleTauFirstJetPhiCSVSort = cms.PSet(
                                      pluginType = cms.string("PATEleTauPairCSVJetVarFiller"),
                                      src        = cms.InputTag(src),
                                      tag        = cms.string("J1PhiCSVSort"),
                                      cut        = cms.string('abs(eta())<2.4'),
                                      method     = cms.string('phi()'),
                                      rank       = cms.untracked.double(0)
                                  ),
                                  eleTauSecondJetPhiCSVSort = cms.PSet(
                                      pluginType = cms.string("PATEleTauPairCSVJetVarFiller"),
                                      src        = cms.InputTag(src),
                                      tag        = cms.string("J2PhiCSVSort"),
                                      cut        = cms.string('abs(eta())<2.4'),
                                      method     = cms.string('phi()'),
                                      rank       = cms.untracked.double(1)
                                  ),
                                  eleTauFirstJetFlavorCSVSort = cms.PSet(
                                      pluginType = cms.string("PATEleTauPairCSVJetVarFiller"),
                                      src        = cms.InputTag(src),
                                      tag        = cms.string("J1FlavorCSVSort"),
                                      cut        = cms.string('abs(eta())<2.4'),
                                      method     = cms.string('partonFlavour()'),
                                      rank       = cms.untracked.double(0)
                                  ),
                                  eleTauSecondJetFlavorCSVSort = cms.PSet(
                                      pluginType = cms.string("PATEleTauPairCSVJetVarFiller"),
                                      src        = cms.InputTag(src),
                                      tag        = cms.string("J2FlavorCSVSort"),
                                      cut        = cms.string('abs(eta())<2.4'),
                                      method     = cms.string('partonFlavour()'),
                                      rank       = cms.untracked.double(1)
                                 ),
                                 eleTauFirstJetCSVbtagCSVSort = cms.PSet(
                                     pluginType = cms.string("PATEleTauPairCSVJetVarFiller"),
                                     src        = cms.InputTag(src),
                                     tag        = cms.string("J1CSVbtagCSVSort"),
                                     cut        = cms.string('abs(eta())<2.4'),
                                     method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")'),
                                     rank       = cms.untracked.double(0)
                                 ),
                                 eleTauSecondJetCSVbtagCSVSort = cms.PSet(
                                     pluginType = cms.string("PATEleTauPairCSVJetVarFiller"),
                                     src        = cms.InputTag(src),
                                     tag        = cms.string("J2CSVbtagCSVSort"),
                                     cut        = cms.string('abs(eta())<2.4'),
                                     method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")'),
                                     rank       = cms.untracked.double(1)
                               ),
                              eleTauTauZIP = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauZIP"),
                                  method     = cms.string('leg2.userFloat("zIP")'),
                                  leadingOnly=cms.untracked.bool(True)
                              )                                                            
   )



   setattr(process, name, eventTree)
   p = cms.Path(getattr(process,name))
   setattr(process, name+'Path', p)


