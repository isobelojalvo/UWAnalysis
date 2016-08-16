import FWCore.ParameterSet.Config as cms

from UWAnalysis.Configuration.tools.analysisToolsHTauTau_WIP import TriggerPaths,TriggerRes,TriggerProcess



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


############LTau Filler###############
def makeLTauGeneric(plugin,sourceDiTaus,tagName,methodName):
   PSet = cms.PSet(
         pluginType  = cms.string(plugin),
         src         = cms.InputTag(sourceDiTaus),
         tag         = cms.string(tagName),
         method      = cms.string(methodName),
   )
   return PSet

############Mu-Tau Filler###############
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
def makeMuTauPOGSF(sourceDiTaus):
   PSet = cms.PSet(
         pluginType  = cms.string("PATMuTauPairPOGSFsFiller"),
         src         = cms.InputTag(sourceDiTaus),
         isMu      = cms.bool(True)
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


############Ele-Tau Pair##############
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
def makeEleTauPOGSF(sourceDiTaus):
   PSet = cms.PSet(
         pluginType  = cms.string("PATEleTauPairPOGSFsFiller"),
         src         = cms.InputTag(sourceDiTaus),
         isMu      = cms.bool(False)
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



###############di-Tau#################
def makeDiTauPair(sourceDiTaus,tagName,methodName,leadingOnly=True):
   PSet = cms.PSet(
         pluginType  = cms.string("PATDiTauPairFiller"),
         src         = cms.InputTag(sourceDiTaus),
         tag         = cms.string(tagName),
         method      = cms.string(methodName),
         leadingOnly = cms.untracked.bool(leadingOnly)
   )
   return PSet
def makeDiTauMET(sourceDiTaus, sourceMET, prefix):
   PSet = cms.PSet(
         pluginType  = cms.string("PATDiTauPairMETFiller"),
         src         = cms.InputTag(sourceDiTaus),
         met         = cms.InputTag(sourceMET),
         tag         = cms.string(prefix)
   )
   return PSet


#removed srcLL from this, can be added back
def addDiTauEventTree(process,name,src = 'diTausSorted', srcU='TightMuons', srcE='TightElectrons'):
   process.TFileService = cms.Service("TFileService", fileName = cms.string("analysis.root") )
   eventTree = cms.EDAnalyzer('EventTreeMaker',
                              genEvent = cms.InputTag('generator'),
                              coreCollections = cms.InputTag(src),
                              trigger = cms.PSet(
                                  pluginType = cms.string("TriggerFiller"),
                                  src = cms.InputTag(TriggerRes,"",TriggerProcess),
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
                              ),#FILLED
                              PVs = cms.PSet(
                                  pluginType = cms.string("VertexSizeFiller"),
                                  src        = cms.InputTag("offlineSlimmedPrimaryVertices"),
                                  tag        = cms.string("vertices")
                              ),#FILLED
 
                              diTauSize = makeCollSize(src,"nCands"),#FILLED
                              diTauOS = makeCollSizeOS(src,0,"os"),#FILLED
                              genTaus = makeCollSize("genTauCands","genTaus"), 

                              muonsSizeMT = makeCollSize(srcU,"tightMuons"),#FILLED
                              muonsSizeMTVeto = makeCollSizeVeto(srcU,1,"extramuon_veto"),#FILLED
                              electronsSizeMT = makeCollSize(srcE,"tightElectrons"),#FILLED
                              electronsSizeMTVeto = makeCollSizeVeto(srcE,0,"extraelec_veto"),#FILLED

                              diTauDR = makeDiTauPair(src,"dR","dR12"), 
                              tauSingleL1 =  makeDiTauPair(src,"tauSingleL1_2","leg2.userFloat('LooseIsoPFTau20_SingleL1')"), 
                              tauL1 =  makeDiTauPair(src,"tauL1_2","leg2.userFloat('LooseIsoPFTau20')"), 
                              tauMediumL1 =  makeDiTauPair(src,"tauMediumL1_2","leg2.userFloat('MediumIsoPFTau35_Trk_eta2p1')"),

                              tauNIsoTracks =  makeDiTauPair(src,"tauNIsoTracks","leg2.userFloat('nIsoTracks')"), #FILLED
                              diTaunIsoGamma = makeDiTauPair(src,"nIsoGamma",'leg2.userFloat("nIsoGamma")'),
                              diTaunIsoNeutral = makeDiTauPair(src,"nIsoNeutral",'leg2.userFloat("nIsoNeutral")'),


                              tauLeadChargedHadrTrackPt = makeDiTauPair(src,"tauLeadChargedHadrTrackPt","leg2.userFloat('leadChargedHadrTrackPt')"),#FILLED

                              diTauCharge = makeDiTauPair(src,"charge","charge"),#FILLED
                              q_1 = makeDiTauPair(src,"q_1","leg1.charge"),#FILLED
                              q_2 = makeDiTauPair(src,"q_2","leg2.charge"),#FILLED

                              diTauPt = makeDiTauPair(src,"pth","pt"),#FILLED
                              diTauHT = makeDiTauPair(src,"ht","ht"),#FILLED
                              diTauMass = makeDiTauPair(src,"m_vis","mass"),#FILLED
               			      diTaulVeto = makeDiTauPair(src,"lVeto","lVeto"),

                              diTauPt1 =  makeDiTauPair(src,"pt_1","leg1.pt"), #FILLED
                              diTauPt2 =  makeDiTauPair(src,"pt_2","leg2.pt"), #FILLED
                              diTauEta1 = makeDiTauPair(src,"eta_1","leg1.eta"),#FILLED
                              diTauEta2 = makeDiTauPair(src,"eta_2","leg2.eta"),#FILLED
                              diTauPhi1 = makeDiTauPair(src,"phi_1","leg1.phi"),#FILLED
                              diTauPhi2 = makeDiTauPair(src,"phi_2","leg2.phi"),#FILLED

                              diTauMET1 = makeDiTauMET(src,"slimmedMETs","pf"),#FILLED
                              diTauMET2 = makeDiTauMET(src,"slimmedMETsPuppi","puppi"),#FILLED
                              diTauMET3 = makeDiTauMET(src,"MVAMET:MVAMET","mva"),#FILLED
 
                              diTauMET = makeDiTauPair(src,"met","met.pt()"),#FILLED
                              diTauMETPhi = makeDiTauPair(src,"metphi","met.phi()"),#FILLED

                              diTauMT = makeDiTauPair(src,"mt12","mt12MET"),#FILLED
                              diTauMT1 = makeDiTauPair(src,"mt_1","mt1MET"),#FILLED
                              diTauMT2 = makeDiTauPair(src,"mt_2","mt2MET"),#FILLED
                              
		                      diTauTopGenPt = makeDiTauPair(src,"topGenPt","topGenPt"),#FIXME
		                      diTauAntiTopGenPt = makeDiTauPair(src,"antiTopGenPt","antiTopGenPt"),#FIXME

                              #BTAGS AND JETS
                              diTauMJJReg = makeDiTauPair(src,"mJJReg","mJJReg"),#FIXME
                              diTauMJJ = makeDiTauPair(src,"mJJ","mJJ"),#FILLED
                              diTauJJPt = makeDiTauPair(src,"ptJJ","ptJJ"),
                              diTauJJEta = makeDiTauPair(src,"etaJJ","etaJJ"),
                              diTauJJPhi = makeDiTauPair(src,"phiJJ","phiJJ"),
                              diTauJJEnergy = makeDiTauPair(src,"energyJJ","energyJJ"),
                              diTauVBFDEta = makeDiTauPair(src,"vbfDEta","vbfDEta"),
                              diTauVBFDPhi = makeDiTauPair(src,"vbfDPhi","vbfDPhi"),
                              diTauVBFMass = makeDiTauPair(src,"vbfMass","vbfMass"),#vbfMass
                              diTauVBFJets20 = makeDiTauPair(src,"njetigap20","vbfNJetsGap20"),
                              diTauVBFJets30 = makeDiTauPair(src,"njetingap","vbfNJetsGap30"),

                              diTauDecayFound = makeDiTauPair(src,"decayModeFinding_2",'leg2.tauID("decayModeFinding")'),
                              diTauDecayFoundNew = makeDiTauPair(src,"decayModeFindingNewDMs_2",'leg2.tauID("decayModeFindingNewDMs")'),
                              diTauProngs = makeDiTauPair(src,"tauProngs",'leg2.signalChargedHadrCands.size()'),#see Decay Modes
                              diTauPzeta = makeDiTauPair(src,"pZeta",'pZeta-1.5*pZetaVis'),
                              diTauPZ = makeDiTauPair(src,"pZ",'pZeta'),
                              diTauPZV = makeDiTauPair(src,"pzetavis",'pZetaVis'),
                              diTauTauZIP = makeDiTauPair(src,"tauZIP",'leg2.userFloat("zIP")'),
                              diTauHadMass = makeDiTauPair(src,"m_2",'leg2.mass()'),

                              diTauMuDZ = makeDiTauPair(src,"dZ_1","leg1.userFloat('taudZ')"),
                              diTauTauDZ = makeDiTauPair(src,"dZ_2","leg2.userFloat('taudZ')"),
                              diTauMuDXY = makeDiTauPair(src,"d0_1","leg1.userFloat('taudXY')"),
                              diTauTauDXY = makeDiTauPair(src,"d0_2","leg2.userFloat('taudXY')"),
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

                              diTauGenIsPrompt1 = makeDiTauPair(src,"isPrompt1",'isPrompt1()'),
                              diTauGenIsPromptFS1 = makeDiTauPair(src,"isPromptFS1",'isPromptFS1()'),
                              diTauGenIsDirectTauDecay1 = makeDiTauPair(src,"isTauDecay1",'isDirectPromptTauDecayProduct1()'),
                              diTauGenIsDirectTauDecayFS1 = makeDiTauPair(src,"isTauDecayFS1",'isDirectPromptTauDecayProductFS1()'),

                              diTauGenIsPrompt2 = makeDiTauPair(src,"isPrompt2",'isPrompt2()'),
                              diTauGenIsPromptFS2 = makeDiTauPair(src,"isPromptFS2",'isPromptFS2()'),
                              diTauGenIsDirectTauDecay2 = makeDiTauPair(src,"isTauDecay2",'isDirectPromptTauDecayProduct2()'),
                              diTauGenIsDirectTauDecayFS2 = makeDiTauPair(src,"isTauDecayFS2",'isDirectPromptTauDecayProductFS2()'),
                              higgsPt = cms.PSet(
                                  pluginType = cms.string("PATGenParticleFiller"),
                                  src        = cms.InputTag("genDaughters"),
                                  tag        = cms.string("higgsPt"),
                                  method     = cms.string('pt()'),
                                  leadingOnly=cms.untracked.bool(True)
                              ),#FILLED in higgs sample

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
                              )#FIXME #CHECKME

   )

   setattr(process, name, eventTree)
   p = cms.Path(getattr(process,name))
   setattr(process, name+'Path', p)







def addMuTauEventTree(process,name,src = 'muTausSorted', srcLL = 'diMuonsOSSorted', srcU='TightMuons', srcE='TightElectrons'):
   process.TFileService = cms.Service("TFileService", fileName = cms.string("analysis.root") )
   eventTree = cms.EDAnalyzer('EventTreeMaker',
                              genEvent = cms.InputTag('generator'),
                              coreCollections = cms.InputTag(src),
                              trigger = cms.PSet(
                                  pluginType = cms.string("TriggerFiller"),
                                  src = cms.InputTag(TriggerRes,"",TriggerProcess),
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
                              ),#FILLED
                              PVs = cms.PSet(
                                  pluginType = cms.string("VertexSizeFiller"),
                                  src        = cms.InputTag("offlineSlimmedPrimaryVertices"),
                                  tag        = cms.string("vertices")
                              ),#FILLED
 
                              muTauPOG = makeMuTauPOGSF(src),#FILLED
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

                              muTauDR = makeMuTauPair(src,"dR","dR12"), 
                              tauSingleL1 =  makeMuTauPair(src,"tauSingleL1_2","leg2.userFloat('LooseIsoPFTau20_SingleL1')"), 
                              tauL1 =  makeMuTauPair(src,"tauL1_2","leg2.userFloat('LooseIsoPFTau20')"), 
                              tauMediumL1 =  makeMuTauPair(src,"tauMediumL1_2","leg2.userFloat('MediumIsoPFTau35_Trk_eta2p1')"),

                              tauNIsoTracks =  makeMuTauPair(src,"tauNIsoTracks","leg2.userFloat('nIsoTracks')"), #FILLED
                              muTaunIsoGamma = makeMuTauPair(src,"nIsoGamma",'leg2.userFloat("nIsoGamma")'),
                              muTaunIsoNeutral = makeMuTauPair(src,"nIsoNeutral",'leg2.userFloat("nIsoNeutral")'),


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
                              muTauVBFDEta = makeMuTauPair(src,"vbfDEta","vbfDEta"),
                              muTauVBFDPhi = makeMuTauPair(src,"vbfDPhi","vbfDPhi"),
                              muTauVBFMass = makeMuTauPair(src,"vbfMass","vbfMass"),#vbfMass
                              muTauVBFJets20 = makeMuTauPair(src,"njetigap20","vbfNJetsGap20"),
                              muTauVBFJets30 = makeMuTauPair(src,"njetingap","vbfNJetsGap30"),

                              #Muon IDs and Isolation
                              muTauRelPFIsoDB03 = makeMuTauPair(src,"iso_1",'leg1.userFloat("dBRelIso03")'),
                              muTauRelPFIsoDB04 = makeMuTauPair(src,"iso04_1",'leg1.userFloat("dBRelIso")'),
                              muTausumCharged04 = makeMuTauPair(src,"sumChargedHadronPt04_1",'leg1.pfIsolationR04().sumChargedHadronPt'),
                              muTausumNeutral04 = makeMuTauPair(src,"sumNeutralHadronPt04_1",'leg1.pfIsolationR04().sumNeutralHadronEt'),
                              muTausumPhoton04 = makeMuTauPair(src,"sumPhotonPt04_1",'leg1.pfIsolationR04().sumPhotonEt'),
                              muTausumPU04 = makeMuTauPair(src,"sumPUPt04_1",'leg1.pfIsolationR04().sumPUPt'),

                              muTausumCharged03 = makeMuTauPair(src,"sumChargedHadronPt03_1",'leg1.pfIsolationR03().sumChargedHadronPt'),
                              muTausumNeutral03 = makeMuTauPair(src,"sumNeutralHadronPt03_1",'leg1.pfIsolationR03().sumNeutralHadronEt'),
                              muTausumPhoton03 = makeMuTauPair(src,"sumPhotonPt03_1",'leg1.pfIsolationR03().sumPhotonEt'),
                              muTausumPU03 = makeMuTauPair(src,"sumPUPt03_1",'leg1.pfIsolationR03().sumPUPt'),

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

                              muTauHaddxy = makeMuTauPair(src,"dxy_2",'leg2.dxy()'),
                              muTauHaddxy_Sig = makeMuTauPair(src,"dxy_Sig_2",'leg2.dxy_Sig()'),

                              muTauHadflightLengthx = makeMuTauPair(src,"flightLengthx_2",'leg2.flightLength().x()'),
                              muTauHadflightLengthy = makeMuTauPair(src,"flightLengthy_2",'leg2.flightLength().y()'),
                              muTauHadflightLengthz = makeMuTauPair(src,"flightLengthz_2",'leg2.flightLength().x()'),
                              muTauHadflightLength = makeMuTauPair(src,"flightLength_2",'sqrt(leg2.flightLength().Mag2)'),
                              muTauHadflightLengthSig = makeMuTauPair(src,"flightLengthSig_2",'leg2.flightLengthSig()'),
                              muTauHadhasSecondaryVertex = makeMuTauPair(src,"hasSecondaryVertex_2",'leg2.hasSecondaryVertex()'),


                              muTautau_pt_weighted_dr_signal = makeMuTauPair(src,"tau_pt_weighted_dr_signal",'leg2.userFloat("tau_pt_weighted_dr_signal")'),
                              muTautau_pt_weighted_deta_strip = makeMuTauPair(src,"tau_pt_weighted_deta_strip",'leg2.userFloat("tau_pt_weighted_deta_strip")'),
                              muTautau_pt_weighted_dphi_strip = makeMuTauPair(src,"tau_pt_weighted_dphi_strip",'leg2.userFloat("tau_pt_weighted_dphi_strip")'),
                              muTautau_pt_weighted_dr_iso = makeMuTauPair(src,"tau_pt_weighted_dr_iso",'leg2.userFloat("tau_pt_weighted_dr_iso")'),
                              muTaun_photons_total = makeMuTauPair(src,"n_photons_total",'leg2.userFloat("n_photons_total")'),
			      #tauIDs
                              muTauByCombIsoDBRaw3 = makeMuTauPair(src,"byCombinedIsolationDeltaBetaCorrRaw3Hits_2",'leg2.tauID("byCombinedIsolationDeltaBetaCorrRaw3Hits")'),
                              muTauByCombIsoLoose = makeMuTauPair(src,"tauIsoLoose",'leg2.tauID("byLooseCombinedIsolationDeltaBetaCorr3Hits")'),
                              muTauByCombIsoMedium = makeMuTauPair(src,"tauIsoMedium",'leg2.tauID("byMediumCombinedIsolationDeltaBetaCorr3Hits")'),
                              muTauByCombIsoTight = makeMuTauPair(src,"tauIsoTight",'leg2.tauID("byTightCombinedIsolationDeltaBetaCorr3Hits")'),
			      muTauByNewDMMVAIso = makeMuTauPair(src,"byIsolationMVArun2v1DBnewDMwLTraw_2",'leg2.tauID("byIsolationMVArun2v1DBnewDMwLTraw")'),
			      muTauByOldDMMVAIso = makeMuTauPair(src,"byIsolationMVArun2v1DBoldDMwLTraw_2",'leg2.tauID("byIsolationMVArun2v1DBoldDMwLTraw")'),
                              muTauByOldDMMVAIsoTight = makeMuTauPair(src,"byTightIsolationMVArun2v1DBoldDMwLT_2",'leg2.tauID("byTightIsolationMVArun2v1DBoldDMwLT")'),
                              muTaubyTightIsolationMVArun2v1DBdR03oldDMwLT = makeMuTauPair(src,"byTightIsolationMVArun2v1DBdR03oldDMwLT_2",'leg2.tauID("byTightIsolationMVArun2v1DBdR03oldDMwLT")'),
                              muTaubyTightIsolationMVArun2v1PWdR03oldDMwLT = makeMuTauPair(src,"byTightIsolationMVArun2v1PWdR03oldDMwLT_2",'leg2.tauID("byTightIsolationMVArun2v1PWdR03oldDMwLT")'),
                              muTaubyTightIsolationMVArun2v1PWoldDMwLT = makeMuTauPair(src,"byTightIsolationMVArun2v1PWoldDMwLT_2",'leg2.tauID("byTightIsolationMVArun2v1PWoldDMwLT")'),
                              muTauByOldDMMVAIsoMedium = makeMuTauPair(src,"byMediumIsolationMVArun2v1DBoldDMwLT_2",'leg2.tauID("byMediumIsolationMVArun2v1DBoldDMwLT")'),
                              muTauByOldDMMVAIsoLoose = makeMuTauPair(src,"byLooseIsolationMVArun2v1DBoldDMwLT_2",'leg2.tauID("byLooseIsolationMVArun2v1DBoldDMwLT")'),
                              muTauByCharged = makeMuTauPair(src,"chargedIsoPtSum_2",'leg2.tauID("chargedIsoPtSum")'),
                              muTauByNeutral = makeMuTauPair(src,"neutralIsoPtSum_2",'leg2.tauID("neutralIsoPtSum")'),
                              muTauByPU = makeMuTauPair(src,"puCorrPtSum_2",'leg2.tauID("puCorrPtSum")'), 
                              muTauAgainstMuonTight3 = makeMuTauPair(src,"againstMuonTight3_2",'leg2.tauID("againstMuonTight3")'),
                              #muTauAgainstMuonTight4 = makeMuTauPair(src,"againstMuonTight4_2",'leg2.tauID("againstMuonTight4")'),
                              muTauAgainstEleVLooseMVA6 = makeMuTauPair(src,"againstElectronVLooseMVA6_2",'leg2.tauID("againstElectronVLooseMVA6")'),
                              muTauagainstElectronMVA6Raw = makeMuTauPair(src,"againstElectronMVA6Raw_2",'leg2.tauID("againstElectronMVA6Raw")'),
                              muTauagainstElectronMVA6category = makeMuTauPair(src,"againstElectronMVA6category_2",'leg2.tauID("againstElectronMVA6category")'),
                              muTauagainstElectronMediumMVA6 = makeMuTauPair(src,"againstElectronMediumMVA6_2",'leg2.tauID("againstElectronMediumMVA6")'),
                              muTauagainstElectronTightMVA6 = makeMuTauPair(src,"againstElectronTightMVA6_2",'leg2.tauID("againstElectronTightMVA6")'),
                              muTauagainstElectronVLooseMVA6 = makeMuTauPair(src,"againstElectronVLooseMVA6_2",'leg2.tauID("againstElectronVLooseMVA6")'),
                              muTauagainstElectronVTightMVA6 = makeMuTauPair(src,"againstElectronVTightMVA6_2",'leg2.tauID("againstElectronVTightMVA6")'),
                              muTaubyIsolationMVArun2v1DBdR03oldDMwLTraw = makeMuTauPair(src,"byIsolationMVArun2v1DBdR03oldDMwLTraw_2",'leg2.tauID("byIsolationMVArun2v1DBdR03oldDMwLTraw")'),
                              muTaubyPhotonPtSumOutsideSignalCone = makeMuTauPair(src,"byPhotonPtSumOutsideSignalCone_2",'leg2.tauID("byPhotonPtSumOutsideSignalCone")'),
                              muTauchargedIsoPtSumdR03 = makeMuTauPair(src,"chargedIsoPtSumdR03_2",'leg2.tauID("chargedIsoPtSumdR03")'),
                              muTauneutralIsoPtSumWeight = makeMuTauPair(src,"neutralIsoPtSumWeight_2",'leg2.tauID("neutralIsoPtSumWeight")'),
                              muTauneutralIsoPtSumWeightdR03 = makeMuTauPair(src,"neutralIsoPtSumWeightdR03_2",'leg2.tauID("neutralIsoPtSumWeightdR03")'),
                              muTauneutralIsoPtSumdR03 = makeMuTauPair(src,"neutralIsoPtSumdR03_2",'leg2.tauID("neutralIsoPtSumdR03")'),
                              muTauphotonPtSumOutsideSignalCone = makeMuTauPair(src,"photonPtSumOutsideSignalCone_2",'leg2.tauID("photonPtSumOutsideSignalCone")'),
                              muTauphotonPtSumOutsideSignalConedR03 = makeMuTauPair(src,"photonPtSumOutsideSignalConedR03_2",'leg2.tauID("photonPtSumOutsideSignalConedR03")'),
                              muTaufootprintCorrection = makeMuTauPair(src,"footprintCorrection_2",'leg2.tauID("footprintCorrection")'),
                              muTaufootprintCorrectiondR03 = makeMuTauPair(src,"footprintCorrectiondR03_2",'leg2.tauID("footprintCorrectiondR03")'),

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
                              trigger = cms.PSet(
                                  pluginType = cms.string("TriggerFiller"),
                                  #src        = cms.InputTag("TriggerResults","","HLT"),
                                  src = cms.InputTag(TriggerRes,"",TriggerProcess),
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
                                  #src        = cms.InputTag("primaryVertexFilter"),
                                  tag        = cms.string("npv")
                              ),
                              PVs = cms.PSet(
                                  pluginType = cms.string("VertexSizeFiller"),
                                  src        = cms.InputTag("offlineSlimmedPrimaryVertices"),
                                  #src        = cms.InputTag("primaryVertexFilter"),
                                  tag        = cms.string("vertices")
                              ),


                              eTauPOG = makeEleTauPOGSF(src),#FILLED
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

                              eleTauDR = makeEleTauPair(src,"dR","dR12"), 
                              
                              tauSingleL1 =  makeEleTauPair(src,"tauSingleL1_2","leg2.userFloat('LooseIsoPFTau20_SingleL1')"), 
                              tauL1 =  makeEleTauPair(src,"tauL1_2","leg2.userFloat('LooseIsoPFTau20')"), 
                              tauMediumL1 =  makeEleTauPair(src,"tauMediumL1_2","leg2.userFloat('MediumIsoPFTau35_Trk_eta2p1')"),


                              tauNIsoTracks =  makeEleTauPair(src,"tauNIsoTracks","leg2.userFloat('nIsoTracks')"), #FILLED
                              eleTaunIsoGamma = makeEleTauPair(src,"nIsoGamma",'leg2.userFloat("nIsoGamma")'),
                              eleTaunIsoNeutral = makeEleTauPair(src,"nIsoNeutral",'leg2.userFloat("nIsoNeutral")'),


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
                              eleTauHaddxy = makeEleTauPair(src,"dxy_2",'leg2.dxy()'),
                              eleTauHaddxy_Sig = makeEleTauPair(src,"dxy_Sig_2",'leg2.dxy_Sig()'),
                              eleTauHadflightLengthx = makeEleTauPair(src,"flightLengthx_2",'leg2.flightLength().x()'),
                              eleTauHadflightLengthy = makeEleTauPair(src,"flightLengthy_2",'leg2.flightLength().y()'),
                              eleTauHadflightLengthz = makeEleTauPair(src,"flightLengthz_2",'leg2.flightLength().x()'),
                              eleTauHadflightLength = makeEleTauPair(src,"flightLength_2",'sqrt(leg2.flightLength().Mag2)'),
                              eleTauHadflightLengthSig = makeEleTauPair(src,"flightLengthSig_2",'leg2.flightLengthSig()'),
                              eleTauHadhasSecondaryVertex = makeEleTauPair(src,"hasSecondaryVertex_2",'leg2.hasSecondaryVertex()'),



                              eleTautau_pt_weighted_dr_signal = makeEleTauPair(src,"tau_pt_weighted_dr_signal",'leg2.userFloat("tau_pt_weighted_dr_signal")'),
                              eleTautau_pt_weighted_deta_strip = makeEleTauPair(src,"tau_pt_weighted_deta_strip",'leg2.userFloat("tau_pt_weighted_deta_strip")'),
                              eleTautau_pt_weighted_dphi_strip = makeEleTauPair(src,"tau_pt_weighted_dphi_strip",'leg2.userFloat("tau_pt_weighted_dphi_strip")'),
                              eleTautau_pt_weighted_dr_iso = makeEleTauPair(src,"tau_pt_weighted_dr_iso",'leg2.userFloat("tau_pt_weighted_dr_iso")'),
                              eleTaun_photons_total = makeEleTauPair(src,"n_photons_total",'leg2.userFloat("n_photons_total")'),
			      #tauIDs



                              eleTauByCombIsoLoose = makeEleTauPair(src,"tauIsoLoose",'leg2.tauID("byLooseCombinedIsolationDeltaBetaCorr3Hits")'),
                              eleTauByCombIsoMedium = makeEleTauPair(src,"tauIsoMedium",'leg2.tauID("byMediumCombinedIsolationDeltaBetaCorr3Hits")'),
                              eleTauByCombIsoTight = makeEleTauPair(src,"tauIsoTight",'leg2.tauID("byTightCombinedIsolationDeltaBetaCorr3Hits")'),
 
                              eleTauByOldDMMVAIsoTight = makeEleTauPair(src,"byTightIsolationMVArun2v1DBoldDMwLT_2",'leg2.tauID("byTightIsolationMVArun2v1DBoldDMwLT")'),
                              eleTaubyTightIsolationMVArun2v1DBdR03oldDMwLT = makeEleTauPair(src,"byTightIsolationMVArun2v1DBdR03oldDMwLT_2",'leg2.tauID("byTightIsolationMVArun2v1DBdR03oldDMwLT")'),
                              eleTaubyTightIsolationMVArun2v1PWoldDMwLT = makeEleTauPair(src,"byTightIsolationMVArun2v1PWoldDMwLT_2",'leg2.tauID("byTightIsolationMVArun2v1PWoldDMwLT")'),
                              eleTaubyTightIsolationMVArun2v1PWdR03oldDMwLT = makeEleTauPair(src,"byTightIsolationMVArun2v1PWdR03oldDMwLT_2",'leg2.tauID("byTightIsolationMVArun2v1PWdR03oldDMwLT")'),
                              eleTauByOldDMMVAIsoMedium = makeEleTauPair(src,"byMediumIsolationMVArun2v1DBoldDMwLT_2",'leg2.tauID("byMediumIsolationMVArun2v1DBoldDMwLT")'),
                              eleTauByOldDMMVAIsoLoose = makeEleTauPair(src,"byLooseIsolationMVArun2v1DBoldDMwLT_2",'leg2.tauID("byLooseIsolationMVArun2v1DBoldDMwLT")'),
                              eleTauByCombIsoDBRaw3 = makeEleTauPair(src,"byCombinedIsolationDeltaBetaCorrRaw3Hits_2",'leg2.tauID("byCombinedIsolationDeltaBetaCorrRaw3Hits")'),
                              eleTauByCombIsoDBRaw3Iso = makeEleTauPair(src,"tauIso",'leg2.tauID("byCombinedIsolationDeltaBetaCorrRaw3Hits")'),
                              eleTauByCharged = makeEleTauPair(src,"chargedIsoPtSum_2",'leg2.tauID("chargedIsoPtSum")'),
                              eleTauByNeutral = makeEleTauPair(src,"neutralIsoPtSum_2",'leg2.tauID("neutralIsoPtSum")'),
                              eleTauByPU = makeEleTauPair(src,"puCorrPtSum_2",'leg2.tauID("puCorrPtSum")'), 
                              eleTauAgainstMuonLoose3 = makeEleTauPair(src,"againstMuonLoose3_2",'leg2.tauID("againstMuonLoose3")'),
                              eleTauAgainstMuonTight3 = makeEleTauPair(src,"againstMuonTight3_2",'leg2.tauID("againstMuonTight3")'),

                              eleTauagainstElectronMVA6Raw = makeEleTauPair(src,"againstElectronMVA6Raw_2",'leg2.tauID("againstElectronMVA6Raw")'),
                              eleTauagainstElectronMVA6category = makeEleTauPair(src,"againstElectronMVA6category_2",'leg2.tauID("againstElectronMVA6category")'),
                              eleTauAgainstEleVLooseMVA6 = makeEleTauPair(src,"againstElectronVLooseMVA6_2",'leg2.tauID("againstElectronVLooseMVA6")'),
                              eleTauAgainstElectronLooseMVA6 = makeEleTauPair(src,"againstElectronLooseMVA6_2",'leg2.tauID("againstElectronLooseMVA6")'),
                              eleTauagainstElectronMediumMVA6 = makeEleTauPair(src,"againstElectronMediumMVA6_2",'leg2.tauID("againstElectronMediumMVA6")'),
                              eleTauagainstElectronTightMVA6 = makeEleTauPair(src,"againstElectronTightMVA6_2",'leg2.tauID("againstElectronTightMVA6")'),
                              eleTauagainstElectronVTightMVA6 = makeEleTauPair(src,"againstElectronVTightMVA6_2",'leg2.tauID("againstElectronVTightMVA6")'),

			      eleTauByNewDMMVAIso = makeEleTauPair(src,"byIsolationMVArun2v1DBnewDMwLTraw_2",'leg2.tauID("byIsolationMVArun2v1DBnewDMwLTraw")'),
			      eleTauByOldDMMVAIso = makeEleTauPair(src,"byIsolationMVArun2v1DBoldDMwLTraw_2",'leg2.tauID("byIsolationMVArun2v1DBoldDMwLTraw")'),
                              eleTaubyIsolationMVArun2v1DBdR03oldDMwLTraw = makeEleTauPair(src,"byIsolationMVArun2v1DBdR03oldDMwLTraw_2",'leg2.tauID("byIsolationMVArun2v1DBdR03oldDMwLTraw")'),
                              eleTaubyIsolationMVArun2v1PWdR03oldDMwLTraw = makeEleTauPair(src,"byIsolationMVArun2v1PWdR03oldDMwLTraw_2",'leg2.tauID("byIsolationMVArun2v1PWdR03oldDMwLTraw")'),
                              eleTaubyIsolationMVArun2v1PWoldDMwLTraw = makeEleTauPair(src,"byIsolationMVArun2v1PWoldDMwLTraw_2",'leg2.tauID("byIsolationMVArun2v1PWoldDMwLTraw")'),
                              eleTaubyPhotonPtSumOutsideSignalCone = makeEleTauPair(src,"byPhotonPtSumOutsideSignalCone_2",'leg2.tauID("byPhotonPtSumOutsideSignalCone")'),
                              eleTauchargedIsoPtSumdR03 = makeEleTauPair(src,"chargedIsoPtSumdR03_2",'leg2.tauID("chargedIsoPtSumdR03")'),
                              eleTauneutralIsoPtSumWeight = makeEleTauPair(src,"neutralIsoPtSumWeight_2",'leg2.tauID("neutralIsoPtSumWeight")'),
                              eleTauneutralIsoPtSumWeightdR03 = makeEleTauPair(src,"neutralIsoPtSumWeightdR03_2",'leg2.tauID("neutralIsoPtSumWeightdR03")'),
                              eleTauneutralIsoPtSumdR03 = makeEleTauPair(src,"neutralIsoPtSumdR03_2",'leg2.tauID("neutralIsoPtSumdR03")'),
                              eleTauphotonPtSumOutsideSignalCone = makeEleTauPair(src,"photonPtSumOutsideSignalCone_2",'leg2.tauID("photonPtSumOutsideSignalCone")'),
                              eleTauphotonPtSumOutsideSignalConedR03 = makeEleTauPair(src,"photonPtSumOutsideSignalConedR03_2",'leg2.tauID("photonPtSumOutsideSignalConedR03")'),
                              eleTaufootprintCorrection = makeEleTauPair(src,"footprintCorrection_2",'leg2.tauID("footprintCorrection")'),
                              eleTaufootprintCorrectiondR03 = makeEleTauPair(src,"footprintCorrectiondR03_2",'leg2.tauID("footprintCorrectiondR03")'),


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



                              eleTauJetsPt20TagMatch = makeEleTauJetCountPair(src,"nTaggableJetsPt20Matched",'pt()>20&&abs(eta)<2.4&&abs(partonFlavour)==5'),
                              eleTauJetsPt20TagNoMatch = makeEleTauJetCountPair(src,"nTaggableJetsPt20NotMatched",'pt()>30&&abs(eta)<2.4&&abs(partonFlavour)!=5'),
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

