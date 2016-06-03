
import FWCore.ParameterSet.Config as cms
from CommonTools.ParticleFlow.Isolation.tools_cfi import *


from PhysicsTools.PatAlgos.tools.jetTools import *
from PhysicsTools.PatAlgos.tools.helpers import *
from PhysicsTools.PatAlgos.tools.tauTools import *
from PhysicsTools.PatAlgos.tools.coreTools import *
from PhysicsTools.PatAlgos.tools.metTools import *
from PhysicsTools.PatAlgos.tools.pfTools import *
from PhysicsTools.PatAlgos.tools.trigTools import *
import sys

def defaultReconstruction(process,triggerProcess = 'HLT',triggerPaths = ['HLT_Mu9','HLT_Mu11_PFTau15_v1'],HLT = 'TriggerResults'):
  process.load("UWAnalysis.Configuration.startUpSequence_cff")
  process.load("Configuration.StandardSequences.Services_cff")
  process.load("TrackingTools.TransientTrack.TransientTrackBuilder_cfi")
  process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")
  #process.load("DQMServices.Core.DQM_cfg")
  #process.load("DQMServices.Components.DQMEnvironment_cfi")
  process.load('Configuration.StandardSequences.Services_cff')
  process.load('Configuration.EventContent.EventContent_cff')
  #process.load('SimGeneral.MixingModule.mixNoPU_cfi')
  process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
  process.load('Configuration.StandardSequences.MagneticField_38T_cff')
  process.load('Configuration.StandardSequences.EndOfProcess_cff')
 
  #Make the TriggerPaths Global variable to be accesed by the ntuples
  global TriggerPaths
  TriggerPaths= triggerPaths
  process.analysisSequence = cms.Sequence()

  MiniAODEleVIDEmbedder(process,"slimmedElectrons")  
  MiniAODMuonIDEmbedder(process,"slimmedMuons")  

  #mvaMet2(process, True) #isData
  #metSignificance(process)


  #Add trigger Matching
  muonTriggerMatchMiniAOD(process,triggerProcess,HLT,"miniAODMuonID") 
  electronTriggerMatchMiniAOD(process,triggerProcess,HLT,"miniAODElectronVID") 
  tauTriggerMatchMiniAOD(process,triggerProcess,HLT,"slimmedTaus") #ESTaus
  
  #Build good vertex collection
  #goodVertexFilter(process)  
  tauOverloading(process,'triggeredPatTaus','triggeredPatMuons','offlineSlimmedPrimaryVertices')
  
  triLeptons(process)
  jetOverloading(process,"patJetsReapplyJEC") #"slimmedJets")
  jetFilter(process,"patOverloadedJets")


  #Default selections for systematics
  applyDefaultSelectionsPT(process)

  process.runAnalysisSequence = cms.Path(process.analysisSequence)



def defaultReconstructionMC(process,triggerProcess = 'HLT',triggerPaths = ['HLT_Mu9','HLT_Mu11_PFTau15_v1','HLT_Mu11_PFTau15_v1','HLT_Mu11_PFTau15_v2','HLT_Mu15_v1','HLT_Mu15_v2'],HLT = 'TriggerResults'):
  process.load("UWAnalysis.Configuration.startUpSequence_cff")
  process.load("Configuration.StandardSequences.Services_cff")
  process.load("TrackingTools.TransientTrack.TransientTrackBuilder_cfi")
  process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")
  process.load("DQMServices.Core.DQM_cfg")
  process.load("DQMServices.Components.DQMEnvironment_cfi")
  process.load('Configuration.StandardSequences.Services_cff')
  process.load('Configuration.EventContent.EventContent_cff')
  process.load('SimGeneral.MixingModule.mixNoPU_cfi')
  process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
  process.load('Configuration.StandardSequences.MagneticField_38T_cff')
  process.load('Configuration.StandardSequences.EndOfProcess_cff')
 
  #Make the TriggerPaths Global variable to be accesed by the ntuples
  global TriggerPaths
  TriggerPaths= triggerPaths
  process.analysisSequence = cms.Sequence()

  #Apply Tau Energy Scale Changes
  #EScaledTaus(process,False)

  MiniAODEleVIDEmbedder(process,"slimmedElectrons")  
  MiniAODMuonIDEmbedder(process,"slimmedMuons")  

  #mvaMet2(process, False) #isData
  metSignificance(process)


  #Add trigger Matching
  muonTriggerMatchMiniAOD(process,triggerProcess,HLT,"miniAODMuonID")#NEW
  electronTriggerMatchMiniAOD(process,triggerProcess,HLT,"miniAODElectronVID")#NEW
  #tauTriggerMatchMiniAOD(process,triggerProcess,HLT,"ESTausID") #slimmedTaus")
  tauTriggerMatchMiniAOD(process,triggerProcess,HLT,"slimmedTaus")
  
  #Build good vertex collection
  #goodVertexFilter(process)  
  tauOverloading(process,'triggeredPatTaus','triggeredPatMuons','offlineSlimmedPrimaryVertices')
  
  triLeptons(process)
  #jetCSVShaping(process,"slimmedJets")
  #jetOverloading(process,"slimmedJets")
  jetOverloading(process,"patJetsReapplyJEC") #"slimmedJets")

  jetFilter(process,"patOverloadedJets")

  GenSumWeights(process)
  GenHTCalculator(process)
  #Default selections for systematics
  applyDefaultSelectionsPT(process)

  process.runAnalysisSequence = cms.Path(process.analysisSequence)



def jetOverloading(process,jets):

  process.patOverloadedJets = cms.EDProducer('PATJetOverloader',
                                        src = cms.InputTag(jets),
                                        genJets = cms.InputTag("slimmedGenJets")#One collections of gen jets is saved, slimmedGenJets, made from ak4GenJets
  )                                        

  process.jetOverloading = cms.Sequence(process.patOverloadedJets)
  process.analysisSequence*=process.jetOverloading


def jetFilter(process,jets):

  process.filteredJets = cms.EDProducer('PATJetFilter',
                                        src = cms.InputTag(jets)
  )                                        

  process.jetFiltering = cms.Sequence(process.filteredJets)
  process.analysisSequence*=process.jetFiltering


def jetCSVShaping(process,jets):

  process.jetsCSVweighting = cms.EDProducer('MiniAODCSVReweighting',
                                        src = cms.InputTag(jets)
  )                                        

  process.jetCSVWeights = cms.Sequence(process.jetsCSVweighting)
  process.analysisSequence*=process.jetCSVWeights

def jetJECApplication(process,jets):

  process.load('JetMETCorrections.Configuration.JetCorrectors_cff')
  process.ak4PFchsCorrectedJets   = cms.EDProducer('CorrectedPFJetProducer',
    src         = cms.InputTag('ak4PFchsJets'),
    correctors  = cms.vstring('ak4PFCHSL1FastL2L3Corrector')
  )
  process.jetJECpath = cms.Sequence(process.ak4PFCHSL1FastL2L3CorrectorChain*process.ak4PFchsCorrectedJets)
  process.analysisSequence *=process.jetJECpath


def jetCSVShaping(process,jets):

  process.jetsCSVweighting = cms.EDProducer('MiniAODCSVReweighting',
                                        src = cms.InputTag(jets)
  )                                        

  process.jetCSVWeights = cms.Sequence(process.jetsCSVweighting)
  process.analysisSequence*=process.jetCSVWeights


  process.jetsJECApplicaiton = cms.EDProducer('MiniAODCSVReweighting',
                                        src = cms.InputTag(jets)
  )                                        

  process.jetCSVWeights = cms.Sequence(process.jetsCSVweighting)
  process.analysisSequence*=process.jetCSVWeights




def PATJetMVAEmbedder(process,jets):

  process.patMVAEmbeddedJets = cms.EDProducer('PATJetMVAEmbedder',
                                        src = cms.InputTag(jets)
  )                                        

  process.jetMVAEmbedding = cms.Sequence(process.patMVAEmbeddedJets)
  process.analysisSequence*=process.jetMVAEmbedding


def MiniAODMuonIDEmbedder(process,muons):
  process.miniAODMuonID = cms.EDProducer(
      "MiniAODMuonIDEmbedder",
      src=cms.InputTag(muons),
      vertices=cms.InputTag("offlineSlimmedPrimaryVertices")
      )

  process.embedMuonIDs = cms.Sequence(process.miniAODMuonID)
  process.analysisSequence*=process.embedMuonIDs


def MiniAODEleVIDEmbedder(process, eles):
  #Turn on versioned cut-based ID
  from PhysicsTools.SelectorUtils.tools.vid_id_tools import setupAllVIDIdsInModule, setupVIDElectronSelection, switchOnVIDElectronIdProducer, DataFormat, setupVIDSelection
  #from PhysicsTools.SelectorUtils.tools.vid_id_tools import  setupAllVIDIdsInModule, setupVIDElectronSelection, switchOnVIDElectronIdProducer, DataFormat
  switchOnVIDElectronIdProducer(process, DataFormat.MiniAOD)
  process.load("RecoEgamma.ElectronIdentification.egmGsfElectronIDs_cfi")
  process.egmGsfElectronIDs.physicsObjectSrc = cms.InputTag(eles)
  from PhysicsTools.SelectorUtils.centralIDRegistry import central_id_registry
  #egmGsfElectronIDSequence should already be defined in egmGsfElectronIDs_cfi 
  #process.egmGsfElectronIDSequence = cms.Sequence(process.egmGsfElectronIDs)
  process.egmGsfElectronIDSequence = cms.Sequence(process.electronMVAValueMapProducer+process.egmGsfElectronIDs)
  id_modules = [
      'RecoEgamma.ElectronIdentification.Identification.cutBasedElectronID_Spring15_25ns_V1_cff',
      'RecoEgamma.ElectronIdentification.Identification.heepElectronID_HEEPV60_cff',
      'RecoEgamma.ElectronIdentification.Identification.mvaElectronID_Spring15_25ns_nonTrig_V1_cff']
  for idmod in id_modules:
      setupAllVIDIdsInModule(process,idmod,setupVIDElectronSelection,None,False)
  
  IDLabels = ["eleMVAIDnonTrig80", "eleMVAIDnonTrig90","CBIDVeto", "CBIDLoose", "CBIDMedium", "CBIDTight","eleHEEPid"] # keys of based id user floats
  IDTags = [
          cms.InputTag('egmGsfElectronIDs:mvaEleID-Spring15-25ns-nonTrig-V1-wp80'),
          cms.InputTag('egmGsfElectronIDs:mvaEleID-Spring15-25ns-nonTrig-V1-wp90'),
	  cms.InputTag('egmGsfElectronIDs:cutBasedElectronID-Spring15-25ns-V1-standalone-veto'),
          cms.InputTag('egmGsfElectronIDs:cutBasedElectronID-Spring15-25ns-V1-standalone-loose'),
          cms.InputTag('egmGsfElectronIDs:cutBasedElectronID-Spring15-25ns-V1-standalone-medium'),
          cms.InputTag('egmGsfElectronIDs:cutBasedElectronID-Spring15-25ns-V1-standalone-tight'),
          cms.InputTag('egmGsfElectronIDs:heepElectronID-HEEPV60')
  ]
  # Embed cut-based VIDs
  process.miniAODElectronVID = cms.EDProducer(
      "MiniAODElectronVIDEmbedder",
      src=cms.InputTag(eles),
      idLabels = cms.vstring(*IDLabels),
      ids = cms.VInputTag(*IDTags),
      eleIsoLabel = cms.string("dBRelIso")
  )
   
  process.embedEleIDs = cms.Sequence(process.egmGsfElectronIDSequence+process.miniAODElectronVID)
  process.analysisSequence*=process.embedEleIDs

   
def EScaledTaus(process,smearing):  #second arg is bool

  process.ESTausID = cms.EDProducer("ESTauProducer",
                                    src = cms.InputTag("slimmedTaus"),
                                    module_label = cms.string("FROGS"),
                                    genParticles = cms.InputTag("genParticles"),
                                    smearConstituents = cms.bool(smearing),
                                    smearMCParticle = cms.bool(False),
                                    energyScale  = cms.double(1.0),
                                    energyScaleDB= cms.int32(0),
                                    deltaEta     = cms.double(0.0),
                                    deltaPhi     = cms.double(0.0),
                                    deltaPtB     = cms.double(0.0),
                                    deltaPtE     = cms.double(0.0)
                                    )
  
  process.EScaledTaus = cms.Sequence(process.ESTausID)
  process.analysisSequence*=process.EScaledTaus



def mvaMet(process):
   #I added
   process.load("PhysicsTools.PatAlgos.producersLayer1.metProducer_cfi")  

   from JetMETCorrections.Configuration.DefaultJEC_cff import ak4PFL1Fastjet
   process.load("RecoJets.JetProducers.ak4PFJets_cfi")
   process.ak4PFJets.src = cms.InputTag("packedPFCandidates")
   process.ak4PFJets.doAreaFastjet = cms.bool(True)
   process.load('JetMETCorrections.Configuration.JetCorrectors_cff')
  
   #from JetMETCorrections.Configuration.JetCorrectionServices_cff import ak4PFL1Fastjet
   process.load("JetMETCorrections.Configuration.DefaultJEC_cff")
   
   process.load("RecoMET.METPUSubtraction.mvaPFMET_cff")
   #process.pfMVAMEt.srcLeptons = cms.VInputTag(
   #   cms.InputTag("slimmedTaus", "", ""),
   #   cms.InputTag("slimmedMuons", "", ""),
   #)
   process.pfMVAMEt.srcPFCandidates = cms.InputTag("packedPFCandidates")
   process.pfMVAMEt.srcVertices = cms.InputTag("offlineSlimmedPrimaryVertices")
   
   process.puJetIdForPFMVAMEt.jec =  cms.string('AK4PF')
   process.puJetIdForPFMVAMEt.vertexes = cms.InputTag("offlineSlimmedPrimaryVertices")
   process.puJetIdForPFMVAMEt.rho = cms.InputTag("fixedGridRhoFastjetAll")
  
   process.patMVAMet = process.patMETs.clone(
         metSource = cms.InputTag('pfMVAMEt'),
         addMuonCorrections = cms.bool(False),
         addGenMET = cms.bool(False)
   )

   #process.analysisSequence = cms.Sequence(process.analysisSequence*process.pfMVAMEtSequence*process.patMVAMet)
   process.analysisSequence = cms.Sequence(process.analysisSequence*process.ak4PFJets*process.ak4PFL1FastL2L3CorrectorChain*process.pfMVAMEtSequence*process.patMVAMet)

def mvaMet2(process, isData):

   from RecoMET.METPUSubtraction.MVAMETConfiguration_cff import runMVAMET

   from RecoMET.METPUSubtraction.localSqlite import recorrectJets
   recorrectJets(process, isData)

   runMVAMET( process, jetCollectionPF = "patJetsReapplyJEC"  )
   process.MVAMET.srcLeptons  = cms.VInputTag("slimmedMuons", "slimmedElectrons", "slimmedTaus")
   process.MVAMET.requireOS = cms.bool(False)
   process.MVAMET.debug = cms.bool(False)
   #process.mvaMETTauL = cms.EDProducer('MVAMET',
   #                          **process.MVAMET.parameters_())

   #process.mvaMETTauL.srcLeptons  = cms.VInputTag("slimmedMuons", "slimmedElectrons", "slimmedTaus")
   #process.mvaMETTauL.requireOS = cms.bool(False)
   #process.mvaMETTauL.debug = cms.bool(True)


   process.analysisSequence = cms.Sequence(process.analysisSequence*process.MVAMET)



def mvaPairMet(process):
   #I added
   process.load("PhysicsTools.PatAlgos.producersLayer1.metProducer_cfi")  

   from JetMETCorrections.Configuration.DefaultJEC_cff import ak4PFL1Fastjet
   process.load("RecoJets.JetProducers.ak4PFJets_cfi")
   process.ak4PFJets.src = cms.InputTag("packedPFCandidates")
   process.ak4PFJets.doAreaFastjet = cms.bool(True)
   process.load('JetMETCorrections.Configuration.JetCorrectors_cff')
  
   process.load("JetMETCorrections.Configuration.DefaultJEC_cff")
   
   
   process.load("RecoMET.METPUSubtraction.mvaPFMET_cff")
   process.pfMVAMEt.srcPFCandidates = cms.InputTag("packedPFCandidates")
   process.pfMVAMEt.srcVertices = cms.InputTag("offlineSlimmedPrimaryVertices")

   process.puJetIdForPFMVAMEt.jec =  cms.string('AK4PF')
   process.puJetIdForPFMVAMEt.vertexes = cms.InputTag("offlineSlimmedPrimaryVertices")
   process.puJetIdForPFMVAMEt.rho = cms.InputTag("fixedGridRhoFastjetAll")
 
   process.mvaMETTauMu = cms.EDProducer('PFMETProducerMVATauTau', 
                             **process.pfMVAMEt.parameters_())

   process.mvaMETTauMu.srcPFCandidates = cms.InputTag("packedPFCandidates")
   process.mvaMETTauMu.srcVertices = cms.InputTag("offlineSlimmedPrimaryVertices")
   process.mvaMETTauMu.srcRho = cms.InputTag("fixedGridRhoFastjetAll")
   process.mvaMETTauMu.srcLeptons = cms.VInputTag(
      cms.InputTag("slimmedMuons"), 
      cms.InputTag("slimmedTaus")
   )
   process.mvaMETTauMu.permuteLeptons = cms.bool(True)

   process.mvaMETTauEle = cms.EDProducer('PFMETProducerMVATauTau', 
                             **process.pfMVAMEt.parameters_())

   process.mvaMETTauEle.srcPFCandidates = cms.InputTag("packedPFCandidates")
   process.mvaMETTauEle.srcVertices = cms.InputTag("offlineSlimmedPrimaryVertices")
   process.mvaMETTauEle.srcRho = cms.InputTag("fixedGridRhoFastjetAll")
   process.mvaMETTauEle.srcLeptons = cms.VInputTag(
      cms.InputTag("slimmedElectrons"), 
      cms.InputTag("slimmedTaus")
   )
   process.mvaMETTauEle.permuteLeptons = cms.bool(True)

   process.analysisSequence = cms.Sequence(process.analysisSequence*process.ak4PFJets*process.ak4PFL1FastL2L3CorrectorChain*process.pfMVAMEtSequence*process.mvaMETTauMu*process.mvaMETTauEle)



def metSignificance(process):
   process.load("RecoMET.METProducers.METSignificance_cfi")
   process.load("RecoMET.METProducers.METSignificanceParams_cfi")

   from RecoMET.METProducers.METSignificanceParams_cfi import METSignificanceParams
 
   process.METSignificance = cms.EDProducer(
       "METSignificanceProducer",
       srcLeptons = cms.VInputTag(
          'slimmedElectrons',
          'slimmedMuons',
          'slimmedPhotons'
       ),
       srcPfJets            = cms.InputTag('slimmedJets'),
       srcMet               = cms.InputTag('slimmedMETs'),
       srcPFCandidates      = cms.InputTag('packedPFCandidates'),
       srcJetSF             = cms.string('AK4PFchs'),
       srcJetResPt          = cms.string('AK4PFchs_pt'),
       srcJetResPhi         = cms.string('AK4PFchs_phi'),
       srcRho               = cms.InputTag('fixedGridRhoAll'),
 
       parameters = METSignificanceParams
   )
   process.analysisSequence *= process.METSignificance


def GenSumWeights(process):

  process.sumweights = cms.EDFilter("GenWeightSum")
  
  process.analysisSequence*= process.sumweights

def GenHTCalculator(process):

  process.sumPUP = cms.EDFilter("GenHTCalculatorLHE",
       PartonMultiplicity=cms.untracked.int32(5)
  )

  process.analysisSequence*= process.sumPUP


def triLeptons(process):

  process.TightElectrons = cms.EDFilter("PATElectronSelector",
  							src = cms.InputTag("miniAODElectronVID"),
  							cut = cms.string('pt>10&&abs(eta)<2.5&&abs(userFloat("dZ"))<0.2&&abs(userFloat("dXY"))<0.045&&userFloat("dBRelIso03")<0.3&&userFloat("eleMVAIDnonTrig90")>0&&userInt("eleConversion")==0'),
  							filter = cms.bool(False)
  						)
  						
  process.TightMuons = cms.EDFilter("PATMuonSelector",
  							src = cms.InputTag("miniAODMuonID"),
  							cut = cms.string('pt>10&&abs(eta)<2.4&&abs(userFloat("dZ"))<0.2&&abs(userFloat("dXY"))<0.045&&isMediumMuon>0&&userFloat("dBRelIso03")<0.3'),
  							filter = cms.bool(False)
  						)

  process.analysisSequence = cms.Sequence(process.analysisSequence*process.TightMuons*process.TightElectrons)
  						
   
def kineWeightsEmbET(process):

  process.load('TauAnalysis/MCEmbeddingTools/embeddingKineReweight_cff')

  process.embeddingKineReweightRECembedding.inputFileName = cms.FileInPath('TauAnalysis/MCEmbeddingTools/data/embeddingKineReweight_ePtGt20tauPtGt18_recEmbedded.root')
  
  process.analysisSequence = cms.Sequence(process.analysisSequence*process.embeddingKineReweightSequenceRECembedding)
  
  
def kineWeightsEmbMT(process):

  process.load('TauAnalysis/MCEmbeddingTools/embeddingKineReweight_cff')

  process.embeddingKineReweightRECembedding.inputFileName = cms.FileInPath('TauAnalysis/MCEmbeddingTools/data/embeddingKineReweight_muPtGt16tauPtGt18_recEmbedded.root')
  
  process.analysisSequence = cms.Sequence(process.analysisSequence*process.embeddingKineReweightSequenceRECembedding)
  						

  						
def applyDefaultSelectionsPT(process):#FIXME THISWILL HVAE TO CHANGE-- not cureently used!!!
  #DONT CHANGE THOSE HERE:: THEY ARE NOT USED FOR YOUR SELECTIONS!!!
  #ONLY FOR SYSTEMATICS . PLEASE CHANGE THEM in YOUR CFG FILE IF REALLY NEEDED
  process.selectedPatTaus = cms.EDFilter("PATTauSelector",
                                           src = cms.InputTag("patOverloadedTaus"),
                                           cut = cms.string('pt>15&&tauID("byCombinedIsolationDeltaBetaCorrRaw3Hits")<3&&tauID("decayModeFindingNewDMs")&&tauID("againstElectronVLooseMVA6")&&tauID("againstMuonLoose3")'),
                                           filter = cms.bool(False)
  										)  
  process.selectedPatElectrons = cms.EDFilter("PATElectronSelector",
                                           src = cms.InputTag("miniAODElectronVID"),
                                           cut = cms.string('pt>10&&userFloat("eleMVAIDnonTrig90")>0&&userFloat("dBRelIso03")<0.3'),
                                           filter = cms.bool(False)
  										)
  process.selectedPatMuons = cms.EDFilter("PATMuonSelector",
                                           src = cms.InputTag("miniAODMuonID"),
                                           cut = cms.string('pt>10&&isMediumMuon>0&&userFloat("dBRelIso03")<0.3'),
                                           filter = cms.bool(False)
  										) 
  process.cleanPatJets = cms.EDProducer("PATJetCleaner",
                                           src = cms.InputTag("filteredJets"),#"patMVAEmbeddedJets"
                                           preselection = cms.string('abs(eta)<4.7&&pt>10&&userFloat("idLoose")'),
                                           checkOverlaps = cms.PSet(),
                                           finalCut = cms.string('')
  										)								 									  
  process.selectedObjectsForSyst = cms.Sequence(process.selectedPatTaus+process.selectedPatElectrons+process.selectedPatMuons+process.cleanPatJets)
  process.analysisSequence = cms.Sequence(process.analysisSequence*process.selectedObjectsForSyst)

def tauTriggerMatchMiniAOD(process,triggerProcess,HLT,srcTau):
   strTrig=''
   for i in TriggerPaths:
    if i==TriggerPaths[0]:
      strTrig+='path(\"'+i+'\")'
    else:  
      strTrig+='|| path(\"'+i+'\")'


   process.triggeredPatTaus = cms.EDProducer("TauTriggerMatcherMiniAOD",
                                            src = cms.InputTag(srcTau),
                                            trigEvent = cms.InputTag(HLT),
                                            filtersAND = cms.vstring(
                                                'hltOverlapFilterIsoMu17LooseIsoPFTau20',
                                                'hltOverlapFilterIsoEle22WP75GsfLooseIsoPFTau20',
                                                'hltOverlapFilterIsoEle22WPLooseGsfLooseIsoPFTau20'
                                            ),
                                            filters = cms.vstring(
                                                'hltPFTau20TrackLooseIsoAgainstMuon',
                                                'hltPFTau20TrackLooseIso',
                                                'hltPFTau20TrackLooseIso'
                                            ),
                                            bits = cms.InputTag("TriggerResults","","HLT"),
                                            prescales = cms.InputTag("patTrigger"),
                                            objects = cms.InputTag("selectedPatTrigger"),
                                            ptCut = cms.int32(10) #too low to affect anything
   )
                                            
   #process.analysisSequence=cms.Sequence(process.analysisSequence*process.preTriggeredPatTaus*process.triggeredPatTaus)
   process.analysisSequence=cms.Sequence(process.analysisSequence*process.triggeredPatTaus)

def muonTriggerMatchMiniAOD(process,triggerProcess,HLT,srcMuon):

   process.triggeredPatMuons = cms.EDProducer("MuonTriggerMatcherMiniAOD",
                                            src = cms.InputTag(srcMuon),#"miniAODMuonID"
                                            trigEvent = cms.InputTag(HLT),
                                            filters = cms.vstring(
						'hltL3crIsoL1sMu16erTauJet20erL1f0L2f10QL3f17QL3trkIsoFiltered0p09',
						'hltL3crIsoL1sMu20Eta2p1L1f0L2f10QL3f24QL3trkIsoFiltered0p09',
						'hltL3crIsoL1sMu20L1f0L2f10QL3f22QL3trkIsoFiltered0p09', #2015D
						'hltL3crIsoL1sSingleMu16erL1f0L2f10QL3f17QL3trkIsoFiltered0p09', #2015D Sync
						'hltL3crIsoL1sMu16L1f0L2f10QL3f18QL3trkIsoFiltered0p09' #2015D IsoMu18
                                            ),
					    filtersAND = cms.vstring(
					    	'hltOverlapFilterIsoMu17LooseIsoPFTau20',
						'hltL3crIsoL1sMu20Eta2p1L1f0L2f10QL3f24QL3trkIsoFiltered0p09', 
						'hltL3crIsoL1sMu20L1f0L2f10QL3f22QL3trkIsoFiltered0p09', #2015D Sync
						'hltL3crIsoL1sSingleMu16erL1f0L2f10QL3f17QL3trkIsoFiltered0p09', #2015D Sync
						'hltL3crIsoL1sMu16L1f0L2f10QL3f18QL3trkIsoFiltered0p09' #2015D IsoMu18
					    ),
                                            bits = cms.InputTag("TriggerResults","","HLT"),
                                            prescales = cms.InputTag("patTrigger"),
                                            objects = cms.InputTag("selectedPatTrigger"),
                                            ptCut = cms.int32(0) 
   )
  
   process.analysisSequence*= process.triggeredPatMuons

def electronTriggerMatchMiniAOD(process,triggerProcess,HLT,srcEle):

   process.triggeredPatElectrons = cms.EDProducer("ElectronTriggerMatcherMiniAOD",
                                            src = cms.InputTag(srcEle),#"miniAODElectronVID"
                                            trigEvent = cms.InputTag(HLT),#unused
                                            filters = cms.vstring(
						'hltEle22WP75L1IsoEG20erTau20erGsfTrackIsoFilter', #spring15 ETau
						'hltEle22WPLooseL1IsoEG20erTau20erGsfTrackIsoFilter', #2015D ETau
					        'hltSingleEle22WPLooseGsfTrackIsoFilter', #2015B ETau
						'hltEle32WP75GsfTrackIsoFilter', #Spring15 E
 						'hltSingleEle22WP75GsfTrackIsoFilter', #SYNC v2
						'hltEle32WPTightGsfTrackIsoFilter', #2015B, 2015D single E
						'hltSingleEle22WPTightGsfTrackIsoFilter', #2015D single E
						'hltEle23WPLooseGsfTrackIsoFilter' #2015D single E
                                            ),
					    filtersAND = cms.vstring(
						'hltOverlapFilterIsoEle22WP75GsfLooseIsoPFTau20', #spring15 ETau 
						'hltOverlapFilterIsoEle22WPLooseGsfLooseIsoPFTau20', #2015D ETau
						'hltOverlapFilterIsoEle22WPLooseGsfLooseIsoPFTau20', #2015B ETau
 						'hltEle32WP75GsfTrackIsoFilter', #spring15 E
 						'hltSingleEle22WP75GsfTrackIsoFilter', #SYNC v2
 						'hltEle32WPTightGsfTrackIsoFilter', #2015B, 2015D single E 
 						'hltSingleEle22WPTightGsfTrackIsoFilter', #2015D single E 
						'hltEle23WPLooseGsfTrackIsoFilter' #2015D single E
					    ),
                                            bits = cms.InputTag("TriggerResults","","HLT"),
                                            prescales = cms.InputTag("patTrigger"),
                                            objects = cms.InputTag("selectedPatTrigger"),
                                            ptCut = cms.int32(0) 
   )
  
   process.analysisSequence*= process.triggeredPatElectrons


def tauOverloading(process,src, muons, vtxSrc):


  process.patOverloadedTaus = cms.EDProducer('PATTauOverloader',
                                        src = cms.InputTag(src),
                                        muons = cms.InputTag(muons),
                                        vtxSrc = cms.InputTag(vtxSrc)
  )                                        

  process.analysisSequence=cms.Sequence(process.analysisSequence*process.patOverloadedTaus)


def getAllEventCounters(process,path,onSkim = False):
        stringList = []
        if onSkim:
          stringList.append('processedEvents')

        modules = listModules(path)
    
        for mod in modules:
            if(hasattr(mod,'label')):
                if mod.label().find('Counter') !=-1 :
                    stringList.append(mod.name.value())
        print 'List Of Filters'        
        print stringList
        
        return cms.untracked.vstring(stringList)

def addEventSummary(process,onSkim = False,name = 'summary',path = 'eventSelection'):
    
   process.TFileService = cms.Service("TFileService", fileName = cms.string("analysis.root") )

   summary = cms.EDAnalyzer('EventSummary',
                            src =getAllEventCounters(process,getattr(process,path),onSkim)
   )

   setattr(process,name,summary)
   if onSkim:
        process.EDMtoMEConverter = cms.EDAnalyzer("EDMtoMEConverter",
                                                  Name = cms.untracked.string('EDMtoMEConverter'),
                                                  Verbosity = cms.untracked.int32(1), # 0 provides no output
                                                  # 1 provides basic output
                                                  Frequency = cms.untracked.int32(50),
                                                  convertOnEndLumi = cms.untracked.bool(True),
                                                  convertOnEndRun = cms.untracked.bool(True),
                                                  runInputTag = cms.InputTag('MEtoEDMConverter', 'MEtoEDMConverterRun'),
                                                  lumiInputTag = cms.InputTag('MEtoEDMConverter', 'MEtoEDMConverterLumi')
                                               )
        eventSummaryPath=cms.EndPath(process.EDMtoMEConverter+getattr(process,name))
        setattr(process,name+"Path",eventSummaryPath)
   else:
        eventSummaryPath=cms.EndPath(getattr(process,name))
        setattr(process,name+"Path",eventSummaryPath)



def createGeneratedParticles(process,name,commands):


  refObjects = cms.EDProducer("GenParticlePruner",
    src = cms.InputTag("prunedGenParticles"),
    select = cms.vstring(
    "drop * " 
    )
   )
  refObjects.select.extend(commands)
  setattr(process,name,refObjects)
  process.analysisSequence*= getattr(process,name)




def createGeneratedTaus(process,decayMode,fiducialCuts):
  process.generatedTaus = cms.EDFilter("TauGenJetDecayModeSelector",
                                       src = cms.InputTag("tauGenJets"),
                                       select = cms.vstring(decayMode),
                                       filter = cms.bool(False)
                                       )
  process.generatedTausInAcceptance = cms.EDFilter("GenJetSelector",
                                           src = cms.InputTag("generatedTaus"),
                                           cut = cms.string(fiducialCuts),
                                           filter = cms.bool(False)
                                           )

  process.analysisSequence*= process.generatedTaus
  process.analysisSequence*= process.generatedTausInAcceptance


def goodVertexFilter(process):
  #CHECKME new vertex selection for taus available?
  process.primaryVertexFilter = cms.EDFilter("VertexSelector",
                                        src = cms.InputTag('offlineSlimmedPrimaryVertices'),
                                        cut = cms.string('ndof()>4&&position().rho()<2&&abs(z())<24'),
                                        filter = cms.bool(False)
  )   
  process.analysisSequence*= process.primaryVertexFilter  


def cloneAndReplaceInputTag(process,sequence,oldValue,newValue,postfix):
  #First Clone the sequence
  p = cloneProcessingSnippet(process, sequence, postfix)
  massSearchReplaceAnyInputTag(p,oldValue,newValue )
  modules = listModules(p)

  #Change the labels of the counters
  for mod in modules:
    if(hasattr(mod,'label')):
      if mod.label().find('Counter') !=-1 :
        if(hasattr(mod,'name')):
          newValue = mod.name.value()+postfix
          mod.name=cms.string(newValue)
  return p



def createSystematics(process,sequence,postfix,muScale,eScale,tauScale,jetScale,unclusteredScale,electronresb = 0.0, electronrese = 0.0):

  #First Clone the sequence
  p = cloneProcessingSnippet(process, sequence, postfix)
  modules = listModules(p)

  #Change the labels of the counters and the smearign modules
  for mod in modules:
    if(hasattr(mod,'label')):
      if mod.label().find('Counter') !=-1 :
        if(hasattr(mod,'name')):
          newValue = mod.name.value()+postfix
          mod.name=cms.string(newValue)
      if mod.label().find('smearedMuons') !=-1 :
          mod.energyScale = cms.double(muScale)
      if mod.label().find('smearedTaus') !=-1 :
          mod.energyScale = cms.double(tauScale)
      if mod.label().find('smearedElectrons') !=-1 :
          mod.energyScale = cms.double(eScale)
          mod.deltaPtB = cms.double(electronresb)
          mod.deltaPtE = cms.double(electronrese)
      if mod.label().find('smearedJets') !=-1 :
          mod.energyScaleDB = cms.int32(jetScale)
      if mod.label().find('smearedMET') !=-1 :
          mod.unclusteredScale= cms.double(unclusteredScale)
  return cms.Path(p) 





def createRecoilSystematics(process,sequence,postfix,metScale,metResolution):

  #First Clone the sequence
  p = cloneProcessingSnippet(process, sequence, postfix)
  modules = listModules(p)

  #Change the labels of the counters and the smearign modules
  for mod in modules:
    if(hasattr(mod,'label')):
      if mod.label().find('Counter') !=-1 :
        if(hasattr(mod,'name')):
          newValue = mod.name.value()+postfix
          mod.name=cms.string(newValue)
    if(hasattr(mod,'metCalibration')):
          mod.metCalibration.shiftScale = cms.untracked.double(metScale)
          mod.metCalibration.shiftRes   = cms.untracked.double(metResolution)
      
  return cms.Path(p) 




def pfMetWithSignficance(process):

    # Get PFMET w/ significance
    process.load("TauAnalysis.CandidateTools.PFMETSignCovMatrixEmbedder_cfi")

    process.metWithSig = process.patMETSignEmbedder.clone(
        src = cms.InputTag("systematicsMET"),
        srcCov = cms.InputTag("pfMEtSignCovMatrix")
    )


    process.analysisSequence = cms.Sequence(
        process.analysisSequence *
        process.metWithSig
    )
 

