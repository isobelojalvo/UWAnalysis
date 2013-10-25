import FWCore.ParameterSet.Config as cms

from UWAnalysis.Configuration.tools.analysisToolsPT import TriggerPaths


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
                              ),
                              pt2 = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("pt2"),
                                    method     = cms.string("leg2.pt"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),
                              tauNIsoTracks = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("tauNIsoTracks"),
                                    method     = cms.string("leg2.userFloat('nIsoTracks')"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),
                              tauNMatchedSeg = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("tauMuonNMatchedSeg"),
                                    method     = cms.string("leg2.userFloat('muonNMatchedSeg')"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),
                              tauTauHadMatched = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("tauMuonMatched"),
                                    method     = cms.string("leg2.userFloat('muonTauHadMatched')"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),
                              tauLeadPFTrackPt = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("tauLeadPFTrackPt"),
                                    method     = cms.string("leg2.userFloat('leadPFTrackPt')"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),
                              tauLeadPFTrackPtErr = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("tauLeadPFTrackPtErr"),
                                    method     = cms.string("leg2.userFloat('leadPFTrackPtErr')"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),
                              mass2ES = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("mass2ES"),
                                    method     = cms.string("leg2.userFloat('ESmass')"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),
                              pt2ES = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("pt2ES"),
                                    method     = cms.string("leg2.userFloat('ESpt')"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),
                              pt2initial = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("pt2preES"),
                                    method     = cms.string("leg2.userFloat('preESpt')"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),
                              phi2initial = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("phi2preES"),
                                    method     = cms.string("leg2.userFloat('preESphi')"),
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
                              muTauEta = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("fullEta"),
                                    method     = cms.string("fullEta"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauPhi = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("fullPhi"),
                                    method     = cms.string("fullPhi"),
                                    leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauE = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("fullEnergy"),
                                    method     = cms.string("fullEnergy"),
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
#                               muTauDZ = cms.PSet(
#                                     pluginType = cms.string("PATMuTauPairFiller"),
#                                     src        = cms.InputTag(src),
#                                     tag        = cms.string("dz"),
#                                     method     = cms.string('abs(leg1.userFloat("vz")-leg2.vz())'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
#                               muTauMudZ = cms.PSet(
#                                     pluginType = cms.string("PATMuTauPairFiller"),
#                                     src        = cms.InputTag(src),
#                                     tag        = cms.string("l1dz"),
#                                     method     = cms.string('abs(leg1.userFloat("dz"))'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
#                               muTauTaudZ = cms.PSet(
#                                     pluginType = cms.string("PATMuTauPairFiller"),
#                                     src        = cms.InputTag(src),
#                                     tag        = cms.string("l2dz"),
#                                     method     = cms.string('abs(leg2.userFloat("dZ"))'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),  
#                               muTauMuvZ = cms.PSet(
#                                     pluginType = cms.string("PATMuTauPairFiller"),
#                                     src        = cms.InputTag(src),
#                                     tag        = cms.string("l1Vz"),
#                                     method     = cms.string('leg1.userFloat("vz")'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
#                               muTauTauvZ = cms.PSet(
#                                     pluginType = cms.string("PATMuTauPairFiller"),
#                                     src        = cms.InputTag(src),
#                                     tag        = cms.string("l2Vz"),
#                                     method     = cms.string('leg2.userFloat("vz")'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),   
#                               muTauEleDXY = cms.PSet(
#                                   pluginType = cms.string("PATMuTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("l1Dxy"),
#                                   method     = cms.string('leg1.userFloat("ipDXY")'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),                                                                                     
#                               muTauRho = cms.PSet(
#                                   pluginType = cms.string("EventWeightFiller"),
#                                   src        = cms.InputTag("kt6PFJetsForRhoComputationVoronoi","rho"),
#                                   tag        = cms.string("Rho")
#                               ),

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
#                               projMET = cms.PSet(
#                                     pluginType = cms.string("PATMuTauPairFiller"),
#                                     src        = cms.InputTag(src),
#                                     tag        = cms.string("projMET"),
#                                     method     = cms.string("projMET"),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
                              METPhi = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("metPhi"),
                                    method     = cms.string("metPhi"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              CovMat00 = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("covMatrix00"),
                                    method     = cms.string("covMatrix00"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              CovMat10 = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("covMatrix10"),
                                    method     = cms.string("covMatrix10"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              CovMat01 = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("covMatrix01"),
                                    method     = cms.string("covMatrix01"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              CovMat11 = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("covMatrix11"),
                                    method     = cms.string("covMatrix11"),
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
                              muTauSVPt = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("svPt"),
                                  method     = cms.string("svPt"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),                              
                              muTauFullPt = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("fullPt"),
                                  method     = cms.string("fullPt"),
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
#                               muTauMETOld = cms.PSet(
#                                   pluginType = cms.string("PATMuTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("metOld"),
#                                   method     = cms.string("metOld.pt()"),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
#                               muTauMETOldphi = cms.PSet(
#                                   pluginType = cms.string("PATMuTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("metOldphi"),
#                                   method     = cms.string("metOld.phi()"),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
                              muTauMET = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("met"),
                                  method     = cms.string("calibratedMET.pt()"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauMETUnc = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("metUnc"),
                                  method     = cms.string("met.pt()"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),                              
#                               muTauDPhi = cms.PSet(
#                                   pluginType = cms.string("PATMuTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("dPhi"),
#                                   method     = cms.string("dPhi12"),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
#                               muTauDR = cms.PSet(
#                                   pluginType = cms.string("PATMuTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("dR"),
#                                   method     = cms.string("dR12"),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
#                               muTauDPhi1MET = cms.PSet(
#                                   pluginType = cms.string("PATMuTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("dPhi1MET"),
#                                   method     = cms.string("dPhi1MET"),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
#                               muTauDPhi2MET = cms.PSet(
#                                   pluginType = cms.string("PATMuTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("dPhi2MET"),
#                                   method     = cms.string("dPhi2MET"),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
                              muTauHT = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("ht"),
                                  method     = cms.string("ht"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauEventBTag = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("btag"),
                                  method     = cms.string("EventBTag"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauEventNBTags = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("NBTags"),
                                  method     = cms.string("NBTags"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                               muTauJJHMassSort = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("mJJHMassSort"),
                                   method     = cms.string("mJJHMassSort"),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
                               muTauJJCSVSort = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("mJJCSVSort"),
                                   method     = cms.string("mJJCSVSort"),
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
                              muTauJJEta = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("etaJJ"),
                                  method     = cms.string("etaJJ"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauJJPhi = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("phiJJ"),
                                  method     = cms.string("phiJJ"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauJJEnergy = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("energyJJ"),
                                  method     = cms.string("energyJJ"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauHMass = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("HMass"),
                                  method     = cms.string("hhMass"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauHPt = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("HPt"),
                                  method     = cms.string("hhPt"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauHEta = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("HEta"),
                                  method     = cms.string("hhEta"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauHPhi = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("HPhi"),
                                  method     = cms.string("hhPhi"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauHEnergy = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("HEnergy"),
                                  method     = cms.string("hhE"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauVBFDEta = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfDEta"),
                                  method     = cms.string("vbfDEta"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
#                               muTauVBFPt1 = cms.PSet(
#                                   pluginType = cms.string("PATMuTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("vbfPt1"),
#                                   method     = cms.string("vbfPt1"),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
#                               muTauVBFPt2 = cms.PSet(
#                                   pluginType = cms.string("PATMuTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("vbfPt2"),
#                                   method     = cms.string("vbfPt2"),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
#                               muTauVBFEta1 = cms.PSet(
#                                   pluginType = cms.string("PATMuTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("vbfEta1"),
#                                   method     = cms.string("vbfEta1"),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
#                               muTauVBFEta2 = cms.PSet(
#                                   pluginType = cms.string("PATMuTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("vbfEta2"),
#                                   method     = cms.string("vbfEta2"),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
                              muTauVBFMass = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("vbfMass"),
                                  method     = cms.string("vbfMass"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
#                               muTauVBFDPhi = cms.PSet(
#                                   pluginType = cms.string("PATMuTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("vbfDPhi"),
#                                   method     = cms.string("vbfDPhi"),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ), 
#                               muTauVBFDiJetPt = cms.PSet(
#                                   pluginType = cms.string("PATMuTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("vbfDiJetPt"),
#                                   method     = cms.string("vbfDiJetPt"),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ), 
#                               muTauVBFDiTauPt = cms.PSet(
#                                   pluginType = cms.string("PATMuTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("vbfDiTauPt"),
#                                   method     = cms.string("vbfDiTauPt"),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),                               
#                               muTauVBFDPhiHJ = cms.PSet(
#                                   pluginType = cms.string("PATMuTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("vbfDPhiHJ"),
#                                   method     = cms.string("vbfDPhiHJ"),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ), 
#                               muTauVBFC1 = cms.PSet(
#                                   pluginType = cms.string("PATMuTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("vbfC1"),
#                                   method     = cms.string("vbfC1"),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),  
#                               muTauVBFC2 = cms.PSet(
#                                   pluginType = cms.string("PATMuTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("vbfC2"),
#                                   method     = cms.string("vbfC2"),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),                                                                                                                                                                                   
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
#                               muTauWWID = cms.PSet(
#                                   pluginType = cms.string("PATMuTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("lWWId"),
#                                   method     = cms.string('leg1.userInt("WWID2011")'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
                              muTauPFID = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("lPFId"),
                                  method     = cms.string('leg1.pfCandidateRef().isNonnull()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),                              
#                               muTauMVAID = cms.PSet(
#                                   pluginType = cms.string("PATMuTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("lMVAId"),
#                                   method     = cms.string('leg1.userFloat("idmva")'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),   
#                               muTauMVAIso = cms.PSet(
#                                   pluginType = cms.string("PATMuTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("lMVAIso"),
#                                   method     = cms.string('leg1.userFloat("isomva")'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),   
#                               muTauRingMVAIso = cms.PSet(
#                                   pluginType = cms.string("PATMuTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("lRingMVAIso"),
#                                   method     = cms.string('leg1.userFloat("isoringsradmva")'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),                                                                                        
#                               muTauRelStdIso03 = cms.PSet(
#                                   pluginType = cms.string("PATMuTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("lStdRelIso"),
#                                   method     = cms.string('(leg1.isolationR03.sumPt+leg1.isolationR03.emEt+leg1.isolationR03.hadEt)/leg1.pt()'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),                              
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
#                               muTauMuTriggerMatch2 = cms.PSet(
#                                   pluginType = cms.string("PATMuTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("muTrigger"),
#                                   method     = cms.string('leg1.userFloat("hltL3crIsoL1sMu14erORMu16erL1f0L2f14QL3f17QL3crIsoRhoFiltered0p15")+leg1.userFloat("hltL3crIsoL1sMu16Eta2p1L1f0L2f16QL3f18QL3crIsoFiltered10")'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),                              
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
                                  leadingOnly=cms.untracked.bool(True)###
                              ),
                              muTauByCombIsoDBRaw3 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauIso"),
                                  method     = cms.string('leg2.tauID("byCombinedIsolationDeltaBetaCorrRaw3Hits")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
#                               muTauAgainstEleMVA3raw = cms.PSet(
#                                   pluginType = cms.string("PATMuTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("againstElectronMVA3raw_2"),
#                                   method     = cms.string('leg2.tauID("againstElectronMVA3raw")'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
#                               muTauByIsolationMVA2raw = cms.PSet(
#                                   pluginType = cms.string("PATMuTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("byIsolationMVA2raw_2"),
#                                   method     = cms.string('leg2.tauID("byIsolationMVA2raw")'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
#                               muTauAgainstMuonLoose2 = cms.PSet(
#                                   pluginType = cms.string("PATMuTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("againstMuonLoose2_2"),
#                                   method     = cms.string('leg2.tauID("againstMuonLoose2")'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
#                               muTauAgainstMuonMedium2 = cms.PSet(
#                                   pluginType = cms.string("PATMuTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("againstMuonMedium2_2"),
#                                   method     = cms.string('leg2.tauID("againstMuonMedium2")'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
                              muTauAgainstMuonTight2 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("againstMuonTight2_2"),
                                  method     = cms.string('leg2.tauID("againstMuonTight2")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauAgainstMuonTightFixed = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("againstMuTightFixed"),
                                  method     = cms.string('leg2.userInt("againstMuTightFixed")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauDecayFound = cms.PSet(####
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauDecayFound"),
                                  method     = cms.string('leg2.tauID("decayModeFinding")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
#                               muTauVLooseIso = cms.PSet(
#                                   pluginType = cms.string("PATMuTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("tauVLooseIso"),
#                                   method     = cms.string('leg2.tauID("byVLooseIsolation")'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
#                               muTauLooseIso = cms.PSet(
#                                   pluginType = cms.string("PATMuTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("tauLooseIso"),
#                                   method     = cms.string('leg2.tauID("byLooseIsolation")'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
                              muTauLooseIsoMVA = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauLooseMVAIso"),
                                  method     = cms.string('leg2.tauID("byLooseIsolationMVA2")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauRAWMVAIso = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauMVAIso"),
                                  method     = cms.string('leg2.tauID("byIsolationMVA2raw")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                                muTauCSVL1 = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("EffWEIGHTCSVL"),
                                    method     = cms.string("SFCSVL1"),
                                    leadingOnly=cms.untracked.bool(True)
                                ),
                                muTauCSVL2 = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("EffWEIGHTCSVL2"),
                                    method     = cms.string("SFCSVL2"),
                                    leadingOnly=cms.untracked.bool(True)
                                ),
                                muTauCSVM1 = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("EffWEIGHTCSVM"),
                                    method     = cms.string("SFCSVM1"),
                                    leadingOnly=cms.untracked.bool(True)
                                ),
                                muTauCSVM2 = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("EffWEIGHTCSVM2"),
                                    method     = cms.string("SFCSVM2"),
                                    leadingOnly=cms.untracked.bool(True)
                                ),
                                muTauCSVT1 = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("EffWEIGHTCSVT"),
                                    method     = cms.string("SFCSVT1"),
                                    leadingOnly=cms.untracked.bool(True)
                                ),
                                muTauCSVT2 = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("EffWEIGHTCSVT2"),
                                    method     = cms.string("SFCSVT2"),
                                    leadingOnly=cms.untracked.bool(True)
                                ),
                                muTauCSVL1err = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("EffWEIGHTCSVLerr"),
                                    method     = cms.string("SFCSVL1err"),
                                    leadingOnly=cms.untracked.bool(True)
                                ),
                                muTauCSVL2err = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("EffWEIGHTCSVL2err"),
                                    method     = cms.string("SFCSVL2err"),
                                    leadingOnly=cms.untracked.bool(True)
                                ),
                                muTauCSVM1err = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("EffWEIGHTCSVMerr"),
                                    method     = cms.string("SFCSVM1err"),
                                    leadingOnly=cms.untracked.bool(True)
                                ),
                                muTauCSVM2err = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("EffWEIGHTCSVM2err"),
                                    method     = cms.string("SFCSVM2err"),
                                    leadingOnly=cms.untracked.bool(True)
                                ),
                                muTauCSVT1err = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("EffWEIGHTCSVTerr"),
                                    method     = cms.string("SFCSVT1err"),
                                    leadingOnly=cms.untracked.bool(True)
                                ),
                                muTauCSVT2err = cms.PSet(
                                    pluginType = cms.string("PATMuTauPairFiller"),
                                    src        = cms.InputTag(src),
                                    tag        = cms.string("EffWEIGHTCSVT2err"),
                                    method     = cms.string("SFCSVT2err"),
                                    leadingOnly=cms.untracked.bool(True)
                                ),
                              muTauJetsBTagCSVLPt20 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsBTagCSVLPt20"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")>=0.244&&pt()>20&&abs(eta)<2.4'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauJetsBTagCSVLPt25 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsBTagCSVLPt25"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")>=0.244&&pt()>25&&abs(eta)<2.4'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauJetsBTagCSVMPt20 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsBTagCSVMPt20"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")>=0.679&&pt()>20&&abs(eta)<2.4'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauJetsBTagCSVMPt25 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsBTagCSVMPt25"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")>=0.679&&pt()>25&&abs(eta)<2.4'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),  
                              muTauJetsBTagCSVTPt20 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsBTagCSVTPt20"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")>=0.898&&pt()>20&&abs(eta)<2.4'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),  
                              muTauJetsBTagCSVTPt25 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nJetsBTagCSVTPt25"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")>=0.898&&pt()>25&&abs(eta)<2.4'),
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
                              muTauJetsPt20TagMatchTag = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nTaggableJetsPt20MatchedTagged"),
                                  method     = cms.string('userInt("fullIdLoose")>0&&pt()>20&&abs(eta)<2.4&&abs(partonFlavour)==5&&bDiscriminator("combinedSecondaryVertexBJetTags")>=0.679'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauJetsPt20TagNoMatchTag = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairJetCountFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("nTaggableJetsPt20NotMatchedTagged"),
                                  method     = cms.string('userInt("fullIdLoose")>0&&pt()>20&&abs(eta)<2.4&&abs(partonFlavour)!=5&&bDiscriminator("combinedSecondaryVertexBJetTags")>=0.679'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauGenPt1 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("genPt1"),
                                  method     = cms.string('p4Leg1gen().pt()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauGenPt2 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("genPt2"),
                                  method     = cms.string('p4Leg2gen().pt()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauPdg1 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("pdg1"),
                                  method     = cms.string("genPdg1()"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauPdg2 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("pdg2"),
                                  method     = cms.string("genPdg2()"),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauVisGenPt1 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("genVisPt1"),
                                  method     = cms.string('p4VisLeg1gen().pt()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauVisGenPt2 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("genVisPt2"),
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
                              muTauGenMassMatched = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("genFullMassMatched"),
                                  method     = cms.string('p4gen().M()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauGenMass = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("genFullMass"),
                                  method     = cms.string('genBosonMass()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
#                               muTauFirstJetPt = cms.PSet(
#                                   pluginType = cms.string("PATMuTauPairHighestPtJetVarFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("highestJetPt"),
#                                   method     = cms.string('pt()'),
#                               ),
#                               muTauFirstJetEta = cms.PSet(
#                                   pluginType = cms.string("PATMuTauPairHighestPtJetVarFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("highestJetEta"),
#                                   method     = cms.string('eta()'),
#                               ),
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
                              muTauFirstJetBTagCSV = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairHighestPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("highestJetBTagCSV"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")'),
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
                              mumuDR = cms.PSet(
                                   pluginType = cms.string("PATMuPairFiller"),
                                   src        = cms.InputTag(srcLL),
                                   tag        = cms.string("diLeptonDR"),
                                   method     = cms.string("dR12")
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
                                    src        = cms.InputTag("generator","minVisPtFilter"),
                                    tag        = cms.string("EmbPtWeight"),
                              ),
#                               muTauEmbedSpinWeight = cms.PSet(
#                                     pluginType = cms.string("EventWeightFiller"),
#                                     src        = cms.InputTag("TauSpinnerReco","TauSpinnerWT"),
#                                     tag        = cms.string("EmbSpinWeight"),
#                               ),
#                               muTauEmbedZMMWeight = cms.PSet(
#                                     pluginType = cms.string("EventWeightFiller"),
#                                     src        = cms.InputTag("ZmumuEvtSelEffCorrWeightProducer","weight"),
#                                     tag        = cms.string("EmbZMMWeight"),
#                               ),
#                               muTauEmbedRadWeight = cms.PSet(
#                                     pluginType = cms.string("EventWeightFiller"),
#                                     src        = cms.InputTag("muonRadiationCorrWeightProducer","weight"),
#                                     tag        = cms.string("EmbRadWeight"),
#                               ),
#                               muTauEmbedKinePtWeight = cms.PSet(
#                                     pluginType = cms.string("EventWeightFiller"),
#                                     src        = cms.InputTag("embeddingKineReweightRECembedding","genTau2PtVsGenTau1Pt"),
#                                     tag        = cms.string("EmbKinePtWeight"),
#                               ),
#                               muTauEmbedKineEtaWeight = cms.PSet(
#                                     pluginType = cms.string("EventWeightFiller"),
#                                     src        = cms.InputTag("embeddingKineReweightRECembedding","genTau2EtaVsGenTau1Eta"),
#                                     tag        = cms.string("EmbKineEtaWeight"),
#                               ),
#                               muTauEmbedKineMassWeight = cms.PSet(
#                                     pluginType = cms.string("EventWeightFiller"),
#                                     src        = cms.InputTag("embeddingKineReweightRECembedding","genDiTauMassVsGenDiTauPt"),
#                                     tag        = cms.string("EmbKineMassWeight"),
#                               ),                                                                                                                                                                                    
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
#                               muTauMVANoTrig = cms.PSet(
#                                   pluginType = cms.string("PATMuTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("lIDMVANonTrig"),
#                                   method     = cms.string('leg1.userFloat("mvaNonTrigV0")'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
                              muTauElectronMVAPass = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauElectronMVAPass"),
                                  method     = cms.string('leg2.tauID("againstElectronMVA")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauGenJetPt1 = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1GenPt"),
                                   method     = cms.string('userFloat("genJetPt")'),
                                   rank       = cms.untracked.double(0)
                               ),
                               muTauGenJetPt2 = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2GenPt"),
                                   method     = cms.string('userFloat("genJetPt")'),
                                   rank       = cms.untracked.double(1)
                               ),
                              muTauGenJetEta1 = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1GenEta"),
                                   method     = cms.string('userFloat("genJetEta")'),
                                   rank       = cms.untracked.double(0)
                               ),
                               muTauGenJetEta2 = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2GenEta"),
                                   method     = cms.string('userFloat("genJetEta")'),
                                   rank       = cms.untracked.double(1)
                               ),
                              muTauGenJetPhi1 = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1GenPhi"),
                                   method     = cms.string('userFloat("genJetPhi")'),
                                   rank       = cms.untracked.double(0)
                               ),
                               muTauGenJetPhi2 = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2GenPhi"),
                                   method     = cms.string('userFloat("genJetPhi")'),
                                   rank       = cms.untracked.double(1)
                               ),
                              muTauFirstJetPt1 = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1Pt"),
                                   method     = cms.string('pt()'),
                                   rank       = cms.untracked.double(0)
                               ),
                               muTauSecondJetPt = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2Pt"),
                                   method     = cms.string('pt()'),
                                   rank       = cms.untracked.double(1)
                               ),
                               muTauFirstJetEta1 = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1Eta"),
                                   method     = cms.string('eta()'),
                                   rank       = cms.untracked.double(0)
                               ),
                               muTauSecondJetEta = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2Eta"),
                                   method     = cms.string('eta()'),
                                   rank       = cms.untracked.double(1)
                               ),
                               muTauFirstJetPhi1 = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J1Phi"),
                                   method     = cms.string('phi()'),
                                   rank       = cms.untracked.double(0)
                               ),
                               muTauSecondJetPhi = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2Phi"),
                                   method     = cms.string('phi()'),
                                   rank       = cms.untracked.double(1)
                               ),
                              muTauFirstJetCSVbtag1 = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairPtJetVarFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("J1CSVbtag"),
                                  method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")'),
                                  rank       = cms.untracked.double(0)
                              ),
                               muTauSecondJetCSVbtag = cms.PSet(
                                   pluginType = cms.string("PATMuTauPairPtJetVarFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("J2CSVbtag"),
                                   method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")'),
                                   rank       = cms.untracked.double(1)
                               ),
                                muTauFirstJetPt1CSVSort = cms.PSet(
                                     pluginType = cms.string("PATMuTauPairCSVJetVarFiller"),
                                     src        = cms.InputTag(src),
                                     tag        = cms.string("J1PtCSVSort"),
                                     method     = cms.string('pt()'),
                                     rank       = cms.untracked.double(0)
                                 ),
                                  muTauSecondJetPtCSVSort = cms.PSet(
                                      pluginType = cms.string("PATMuTauPairCSVJetVarFiller"),
                                      src        = cms.InputTag(src),
                                      tag        = cms.string("J2PtCSVSort"),
                                      method     = cms.string('pt()'),
                                      rank       = cms.untracked.double(1)
                                  ),
                                  muTauFirstJetEtaCSVSort = cms.PSet(
                                      pluginType = cms.string("PATMuTauPairCSVJetVarFiller"),
                                      src        = cms.InputTag(src),
                                      tag        = cms.string("J1EtaCSVSort"),
                                      method     = cms.string('eta()'),
                                      rank       = cms.untracked.double(0)
                                  ),
                                  muTauSecondJetEtaCSVSort = cms.PSet(
                                      pluginType = cms.string("PATMuTauPairCSVJetVarFiller"),
                                      src        = cms.InputTag(src),
                                      tag        = cms.string("J2EtaCSVSort"),
                                      method     = cms.string('eta()'),
                                      rank       = cms.untracked.double(1)
                                  ),
                                  muTauFirstJetPhiCSVSort = cms.PSet(
                                      pluginType = cms.string("PATMuTauPairCSVJetVarFiller"),
                                      src        = cms.InputTag(src),
                                      tag        = cms.string("J1PhiCSVSort"),
                                      method     = cms.string('phi()'),
                                      rank       = cms.untracked.double(0)
                                  ),
                                  muTauSecondJetPhiCSVSort = cms.PSet(
                                      pluginType = cms.string("PATMuTauPairCSVJetVarFiller"),
                                      src        = cms.InputTag(src),
                                      tag        = cms.string("J2PhiCSVSort"),
                                      method     = cms.string('phi()'),
                                      rank       = cms.untracked.double(1)
                                  ),
                                  muTauFirstJetFlavorCSVSort = cms.PSet(
                                      pluginType = cms.string("PATMuTauPairCSVJetVarFiller"),
                                      src        = cms.InputTag(src),
                                      tag        = cms.string("J1FlavorCSVSort"),
                                      method     = cms.string('partonFlavour()'),
                                      rank       = cms.untracked.double(0)
                                  ),
                                  muTauSecondJetFlavorCSVSort = cms.PSet(
                                      pluginType = cms.string("PATMuTauPairCSVJetVarFiller"),
                                      src        = cms.InputTag(src),
                                      tag        = cms.string("J2FlavorCSVSort"),
                                      method     = cms.string('partonFlavour()'),
                                      rank       = cms.untracked.double(1)
                                 ),
                                 muTauFirstJetCSVbtagCSVSort = cms.PSet(
                                     pluginType = cms.string("PATMuTauPairCSVJetVarFiller"),
                                     src        = cms.InputTag(src),
                                     tag        = cms.string("J1CSVbtagCSVSort"),
                                     method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")'),
                                     rank       = cms.untracked.double(0)
                                 ),
                                 muTauSecondJetCSVbtagCSVSort = cms.PSet(
                                     pluginType = cms.string("PATMuTauPairCSVJetVarFiller"),
                                     src        = cms.InputTag(src),
                                     tag        = cms.string("J2CSVbtagCSVSort"),
                                     method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")'),
                                     rank       = cms.untracked.double(1)
                               ),
                              muTauTauZIP = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauZIP"),
                                  method     = cms.string('leg2.userFloat("zIP")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              muTauMuTight = cms.PSet(
                                  pluginType = cms.string("PATMuTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauMuTightFixed"),
                                  method     = cms.string('leg2.userInt("againstMuTightFixed")'),
                                  leadingOnly=cms.untracked.bool(True)
                              )                                                                                                                       
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
                                  paths      = cms.vstring(
                                      TriggerPaths
                                  )
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
#                               eleTauRho = cms.PSet(
#                                   pluginType = cms.string("EventWeightFiller"),
#                                   src        = cms.InputTag("kt6PFJetsForRhoComputationVoronoi","rho"),
#                                   tag        = cms.string("Rho")
#                               ),
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
#                               eleTauWW = cms.PSet(
#                                   pluginType = cms.string("PATEleTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("lWWID"),
#                                   method     = cms.string('leg1.userFloat("WWID")'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
#                               eleTauWWMVA = cms.PSet(
#                                   pluginType = cms.string("PATEleTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("lWWIDMVA"),
#                                   method     = cms.string('leg1.userFloat("MITID")'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
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
#                               eleTauEleTriggerMatch2 = cms.PSet(
#                                   pluginType = cms.string("PATEleTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("eleTrigger"),
#                                   method     = cms.string('leg1.userFloat("hltEle20CaloIdVTCaloIsoTTrkIdTTrkIsoTTrackIsoFilterL1IsoEG18OrEG20")+leg1.userFloat("hltEle22WP90RhoTrackIsoFilter")'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),  
#                               eleTauEleTriggerMatch3 = cms.PSet(
#                                   pluginType = cms.string("PATEleTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("ele27Trigger"),
#                                   method     = cms.string('leg1.userFloat("hltEle27WP80TrackIsoFilter")'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),                                                           
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
#                               eleTauEleDXY = cms.PSet(
#                                   pluginType = cms.string("PATEleTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("l1Dxy"),
#                                   method     = cms.string('leg1.userFloat("ipDXY")'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
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
#                               eleTauRelIso03B = cms.PSet(
#                                     pluginType = cms.string("PATEleTauPairFiller"),
#                                     src        = cms.InputTag(src),
#                                     tag        = cms.string("lStandardRelIso"),
#                                     method     = cms.string("leg1.isEB()*((leg1.dr03TkSumPt()+max(leg1.dr03EcalRecHitSumEt()-1.0,0.0)+leg1.dr03HcalTowerSumEt())/leg1.pt())+leg1.isEE()*((leg1.dr03TkSumPt()+leg1.dr03EcalRecHitSumEt()+leg1.dr03HcalTowerSumEt())/leg1.pt())"),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
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
#                               eleTauPFRelIsoMVA = cms.PSet(
#                                   pluginType =cms.string("PATEleTauPairFiller"),
#                                   src = cms.InputTag(src),
#                                   tag = cms.string("lPfRelIso"),
#                                   method =cms.string('leg1.userFloat("isomva")'),
#                                   leadingOnly=cms.untracked.bool(True)
#                                   ),                                                                                                                                                            
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
                              eleTauElectronTightMVA3Pass = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauElectronTightMVA3Pass"),
                                  method     = cms.string('leg2.tauID("againstElectronTightMVA3")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ), 
#                               eleTauPzeta = cms.PSet(
#                                   pluginType = cms.string("PATEleTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("pZeta"),
#                                   method     = cms.string('pZeta-1.5*pZetaVis'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
#                               eleTauPZ = cms.PSet(
#                                   pluginType = cms.string("PATEleTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("pZ"),
#                                   method     = cms.string('pZeta'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
#                               eleTauPZV = cms.PSet(
#                                   pluginType = cms.string("PATEleTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("pZV"),
#                                   method     = cms.string('pZetaVis'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),                              
#                               eleTauProjMET = cms.PSet(
#                                   pluginType = cms.string("PATEleTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("projMET"),
#                                   method     = cms.string('projMET'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
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
                              eleTauByIsolationMVA2raw = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("byIsolationMVA2raw_2"),
                                  method     = cms.string('leg2.tauID("byIsolationMVA2raw")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauAgainstMuonLoose2 = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("againstMuonLoose2_2"),
                                  method     = cms.string('leg2.tauID("againstMuonLoose2")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
#                               eleTauAgainstMuonMedium2 = cms.PSet(
#                                   pluginType = cms.string("PATEleTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("againstMuonMedium2_2"),
#                                   method     = cms.string('leg2.tauID("againstMuonMedium2")'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
#                               eleTauAgainstMuonTight2 = cms.PSet(
#                                   pluginType = cms.string("PATEleTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("againstMuonTight2_2"),
#                                   method     = cms.string('leg2.tauID("againstMuonTight2")'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
                              eleTauDecayMode = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauDecayMode"),
                                  method     = cms.string('leg2.decayMode()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
#                               eleTauE = cms.PSet(
#                                   pluginType = cms.string("PATEleTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("tauE"),
#                                   method     = cms.string('leg2.leadPFCand().ecalEnergy()'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
#                               eleTauH = cms.PSet(
#                                   pluginType = cms.string("PATEleTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("tauH"),
#                                   method     = cms.string('leg2.leadPFCand().hcalEnergy()'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
#                               eleTauLC = cms.PSet(
#                                   pluginType = cms.string("PATEleTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("tauLCharge"),
#                                   method     = cms.string('leg2.leadPFCand().charge()'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
#                               eleTauPT = cms.PSet(
#                                   pluginType = cms.string("PATEleTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("tauPT"),
#                                   method     = cms.string('leg2.leadPFCand().pt()'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
#                               eleTauCMVA = cms.PSet(
#                                   pluginType = cms.string("PATEleTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("tauCMVA"),
#                                   method     = cms.string('leg2.leadPFChargedHadrCand().mva_e_pi()'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
#                               eleTauGammas = cms.PSet(
#                                   pluginType = cms.string("PATEleTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("tauGammas"),
#                                   method     = cms.string('leg2.signalPFGammaCands.size()'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
#                               eleTauVLooseIso = cms.PSet(
#                                   pluginType = cms.string("PATEleTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("tauVLooseIso"),
#                                   method     = cms.string('leg2.tauID("byVLooseIsolation")'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
#                               eleTauLooseIso = cms.PSet(
#                                   pluginType = cms.string("PATEleTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("tauLooseIso"),
#                                   method     = cms.string('leg2.tauID("byLooseIsolation")'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
#                               eleTauMediumIso = cms.PSet(
#                                   pluginType = cms.string("PATEleTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("tauMediumIso"),
#                                   method     = cms.string('leg2.tauID("byMediumIsolation")'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
#                               eleTauTightIso = cms.PSet(
#                                   pluginType = cms.string("PATEleTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("tauTightIso"),
#                                   method     = cms.string('leg2.tauID("byTightIsolation")'),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),
                              eleTauLooseIsoMVA = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauLooseMVAIso"),
                                  method     = cms.string('leg2.tauID("byLooseIsolationMVA2")'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),
                              eleTauRAWMVAIso = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("tauMVAIso"),
                                  method     = cms.string('leg2.tauID("byIsolationMVA2raw")'),
                                  leadingOnly=cms.untracked.bool(True)
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
                               eleTauJJHMassSort = cms.PSet(
                                   pluginType = cms.string("PATEleTauPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("mJJHMassSort"),
                                   method     = cms.string("mJJHMassSort"),
                                   leadingOnly=cms.untracked.bool(True)
                               ),
                               eleTauJJCSVSort = cms.PSet(
                                   pluginType = cms.string("PATEleTauPairFiller"),
                                   src        = cms.InputTag(src),
                                   tag        = cms.string("mJJCSVSort"),
                                   method     = cms.string("mJJCSVSort"),
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
                              eleTauHMass = cms.PSet(
                                  pluginType = cms.string("PATEleTauPairFiller"),
                                  src        = cms.InputTag(src),
                                  tag        = cms.string("HMass"),
                                  method     = cms.string("hhMass"),
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
#                               eleTauVBFDiTauPt = cms.PSet(
#                                   pluginType = cms.string("PATEleTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("vbfDiTauPt"),
#                                   method     = cms.string("vbfDiTauPt"),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),                                
#                               eleTauVBFDiJetPt = cms.PSet(
#                                   pluginType = cms.string("PATEleTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("vbfDiJetPt"),
#                                   method     = cms.string("vbfDiJetPt"),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ), 
#                               eleTauVBFDPhiHJ = cms.PSet(
#                                   pluginType = cms.string("PATEleTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("vbfDPhiHJ"),
#                                   method     = cms.string("vbfDPhiHJ"),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ), 
#                               eleTauVBFC1 = cms.PSet(
#                                   pluginType = cms.string("PATEleTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("vbfC1"),
#                                   method     = cms.string("vbfC1"),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),  
#                               eleTauVBFC2 = cms.PSet(
#                                   pluginType = cms.string("PATEleTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("vbfC2"),
#                                   method     = cms.string("vbfC2"),
#                                   leadingOnly=cms.untracked.bool(True)
#                               ),                                                           
#                               eleTauVBFPt1 = cms.PSet(
#                                   pluginType = cms.string("PATEleTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("vbfPt1"),
#                                   method     = cms.string("vbfPt1"),
#                                   leadingOnly=cms.untracked.bool(True)
#                                ),
#                               eleTauVBFPt2 = cms.PSet(
#                                   pluginType = cms.string("PATEleTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("vbfPt2"),
#                                   method     = cms.string("vbfPt2"),
#                                   leadingOnly=cms.untracked.bool(True)
#                                ),
#                               eleTauVBFEta1 = cms.PSet(
#                                   pluginType = cms.string("PATEleTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("vbfEta1"),
#                                   method     = cms.string("vbfEta1"),
#                                   leadingOnly=cms.untracked.bool(True)
#                                ),
#                               eleTauVBFEta2 = cms.PSet(
#                                   pluginType = cms.string("PATEleTauPairFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("vbfEta2"),
#                                   method     = cms.string("vbfEta2"),
#                                   leadingOnly=cms.untracked.bool(True)
#                                ),

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
#                               eleTauFirstJetPt = cms.PSet(
#                                   pluginType = cms.string("PATEleTauPairHighestPtJetVarFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("highestJetPt"),
#                                   method     = cms.string('pt()'),
#                               ),
#                               eleTauFirstJetEta = cms.PSet(
#                                   pluginType = cms.string("PATEleTauPairHighestPtJetVarFiller"),
#                                   src        = cms.InputTag(src),
#                                   tag        = cms.string("highestJetEta"),
#                                   method     = cms.string('eta()'),
#                               ),
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
#                               eleTauEmbedSpinWeight = cms.PSet(
#                                     pluginType = cms.string("EventWeightFiller"),
#                                     src        = cms.InputTag("TauSpinnerReco","TauSpinnerWT"),
#                                     tag        = cms.string("EmbSpinWeight"),
#                               ),
#                               eleTauEmbedZMMWeight = cms.PSet(
#                                     pluginType = cms.string("EventWeightFiller"),
#                                     src        = cms.InputTag("ZmumuEvtSelEffCorrWeightProducer","weight"),
#                                     tag        = cms.string("EmbZMMWeight"),
#                               ),
#                               eleTauEmbedRadWeight = cms.PSet(
#                                     pluginType = cms.string("EventWeightFiller"),
#                                     src        = cms.InputTag("muonRadiationCorrWeightProducer","weight"),
#                                     tag        = cms.string("EmbRadWeight"),
#                               ),
#                               eleTauEmbedKinePtWeight = cms.PSet(
#                                     pluginType = cms.string("EventWeightFiller"),
#                                     src        = cms.InputTag("embeddingKineReweightRECembedding","genTau2PtVsGenTau1Pt"),
#                                     tag        = cms.string("EmbKinePtWeight"),
#                               ),
#                               eleTauEmbedKineEtaWeight = cms.PSet(
#                                     pluginType = cms.string("EventWeightFiller"),
#                                     src        = cms.InputTag("embeddingKineReweightRECembedding","genTau2EtaVsGenTau1Eta"),
#                                     tag        = cms.string("EmbKineEtaWeight"),
#                               ),
#                               eleTauEmbedKineMassWeight = cms.PSet(
#                                     pluginType = cms.string("EventWeightFiller"),
#                                     src        = cms.InputTag("embeddingKineReweightRECembedding","genDiTauMassVsGenDiTauPt"),
#                                     tag        = cms.string("EmbKineMassWeight"),
#                               ), 
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
                                     method     = cms.string('pt()'),
                                     rank       = cms.untracked.double(0)
                                 ),
                                  eleTauSecondJetPtCSVSort = cms.PSet(
                                      pluginType = cms.string("PATEleTauPairCSVJetVarFiller"),
                                      src        = cms.InputTag(src),
                                      tag        = cms.string("J2PtCSVSort"),
                                      method     = cms.string('pt()'),
                                      rank       = cms.untracked.double(1)
                                  ),
                                  eleTauFirstJetEtaCSVSort = cms.PSet(
                                      pluginType = cms.string("PATEleTauPairCSVJetVarFiller"),
                                      src        = cms.InputTag(src),
                                      tag        = cms.string("J1EtaCSVSort"),
                                      method     = cms.string('eta()'),
                                      rank       = cms.untracked.double(0)
                                  ),
                                  eleTauSecondJetEtaCSVSort = cms.PSet(
                                      pluginType = cms.string("PATEleTauPairCSVJetVarFiller"),
                                      src        = cms.InputTag(src),
                                      tag        = cms.string("J2EtaCSVSort"),
                                      method     = cms.string('eta()'),
                                      rank       = cms.untracked.double(1)
                                  ),
                                  eleTauFirstJetPhiCSVSort = cms.PSet(
                                      pluginType = cms.string("PATEleTauPairCSVJetVarFiller"),
                                      src        = cms.InputTag(src),
                                      tag        = cms.string("J1PhiCSVSort"),
                                      method     = cms.string('phi()'),
                                      rank       = cms.untracked.double(0)
                                  ),
                                  eleTauSecondJetPhiCSVSort = cms.PSet(
                                      pluginType = cms.string("PATEleTauPairCSVJetVarFiller"),
                                      src        = cms.InputTag(src),
                                      tag        = cms.string("J2PhiCSVSort"),
                                      method     = cms.string('phi()'),
                                      rank       = cms.untracked.double(1)
                                  ),
                                  eleTauFirstJetFlavorCSVSort = cms.PSet(
                                      pluginType = cms.string("PATEleTauPairCSVJetVarFiller"),
                                      src        = cms.InputTag(src),
                                      tag        = cms.string("J1FlavorCSVSort"),
                                      method     = cms.string('partonFlavour()'),
                                      rank       = cms.untracked.double(0)
                                  ),
                                  eleTauSecondJetFlavorCSVSort = cms.PSet(
                                      pluginType = cms.string("PATEleTauPairCSVJetVarFiller"),
                                      src        = cms.InputTag(src),
                                      tag        = cms.string("J2FlavorCSVSort"),
                                      method     = cms.string('partonFlavour()'),
                                      rank       = cms.untracked.double(1)
                                 ),
                                 eleTauFirstJetCSVbtagCSVSort = cms.PSet(
                                     pluginType = cms.string("PATEleTauPairCSVJetVarFiller"),
                                     src        = cms.InputTag(src),
                                     tag        = cms.string("J1CSVbtagCSVSort"),
                                     method     = cms.string('bDiscriminator("combinedSecondaryVertexBJetTags")'),
                                     rank       = cms.untracked.double(0)
                                 ),
                                 eleTauSecondJetCSVbtagCSVSort = cms.PSet(
                                     pluginType = cms.string("PATEleTauPairCSVJetVarFiller"),
                                     src        = cms.InputTag(src),
                                     tag        = cms.string("J2CSVbtagCSVSort"),
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


