
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

def defaultReconstruction(process,triggerProcess = 'HLT',triggerPaths = ['HLT_Mu9','HLT_Mu11_PFTau15_v1','HLT_Mu11_PFTau15_v1','HLT_Mu11_PFTau15_v2','HLT_Mu15_v1','HLT_Mu15_v2'],HLT = 'hltTriggerSummaryAOD'):
  process.load("UWAnalysis.Configuration.startUpSequence_cff")
  process.load("Configuration.Geometry.GeometryIdeal_cff")
  process.load("Configuration.StandardSequences.MagneticField_cff")
  process.load("Configuration.StandardSequences.Services_cff")
  process.load("TrackingTools.TransientTrack.TransientTrackBuilder_cfi")
  process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")
  process.load("DQMServices.Core.DQM_cfg")
  process.load("DQMServices.Components.DQMEnvironment_cfi")

  
  #Make the TriggerPaths Global variable to be accesed by the ntuples
  global TriggerPaths
  TriggerPaths= triggerPaths
  process.analysisSequence = cms.Sequence()

  mvaMet2(process)

  #Don't apply energy scaling but run through sequence anyways
  EScaledTaus(process,False)

  #Add trigger Matching
  muonTriggerMatchPT(process,triggerProcess,HLT)
  electronTriggerMatchPT(process,triggerProcess,HLT)
  tauTriggerMatchPT(process,triggerProcess,HLT)

  #Build good vertex collection
  goodVertexFilter(process)  
  tauOverloading(process,'triggeredPatTaus','primaryVertexFilter')
  

  TriLeptons(process)
  ReNameJetColl(process)
  #ReRunJets(process)
  jetOverloading(process,"NewSelectedPatJets")
  PATJetMVAEmbedder(process,"patOverloadedJets")  
  #Default selections for systematics
  applyDefaultSelectionsPT(process)
  

  
  process.runAnalysisSequence = cms.Path(process.analysisSequence)


def defaultReconstructionMC(process,triggerProcess = 'HLT',triggerPaths = ['HLT_Mu9','HLT_Mu11_PFTau15_v1','HLT_Mu11_PFTau15_v1','HLT_Mu11_PFTau15_v2','HLT_Mu15_v1','HLT_Mu15_v2'],HLT = 'hltTriggerSummaryAOD'):
  process.load("UWAnalysis.Configuration.startUpSequence_cff")
  process.load("Configuration.Geometry.GeometryIdeal_cff")
  process.load("Configuration.StandardSequences.MagneticField_cff")
  process.load("Configuration.StandardSequences.Services_cff")
  process.load("TrackingTools.TransientTrack.TransientTrackBuilder_cfi")
  process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")
  process.load("DQMServices.Core.DQM_cfg")
  process.load("DQMServices.Components.DQMEnvironment_cfi")




  #Make the TriggerPaths Global variable to be accesed by the ntuples
  global TriggerPaths
  TriggerPaths= triggerPaths
  process.analysisSequence = cms.Sequence()

  mvaMet2MC(process)


  #Apply Tau Energy Scale Changes
  EScaledTaus(process,True)

  #Add trigger Matching
  muonTriggerMatchPT(process,triggerProcess,HLT)
  electronTriggerMatchPT(process,triggerProcess,HLT)
  tauTriggerMatchPT(process,triggerProcess,HLT)
  
  #Build good vertex collection
  goodVertexFilter(process)  
  tauOverloading(process,'triggeredPatTaus','primaryVertexFilter')
  
  TriLeptons(process)
  ReRunJetsMC(process)
  #ReNameJetColl(process)

  jetOverloading(process,"NewSelectedPatJets")  
  PATJetMVAEmbedder(process,"patOverloadedJets")  
  #Default selections for systematics
  applyDefaultSelectionsPT(process)
  

  #Build good vertex collection

  process.runAnalysisSequence = cms.Path(process.analysisSequence)
  
  
def defaultReconstructionMCNoES(process,triggerProcess = 'HLT',triggerPaths = ['HLT_Mu9','HLT_Mu11_PFTau15_v1','HLT_Mu11_PFTau15_v1','HLT_Mu11_PFTau15_v2','HLT_Mu15_v1','HLT_Mu15_v2'],HLT = 'hltTriggerSummaryAOD'):
  process.load("UWAnalysis.Configuration.startUpSequence_cff")
  process.load("Configuration.Geometry.GeometryIdeal_cff")
  process.load("Configuration.StandardSequences.MagneticField_cff")
  process.load("Configuration.StandardSequences.Services_cff")
  process.load("TrackingTools.TransientTrack.TransientTrackBuilder_cfi")
  process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")
  process.load("DQMServices.Core.DQM_cfg")
  process.load("DQMServices.Components.DQMEnvironment_cfi")


  #Make the TriggerPaths Global variable to be accesed by the ntuples
  global TriggerPaths
  TriggerPaths= triggerPaths
  process.analysisSequence = cms.Sequence()

  mvaMet2MC(process)


  #Apply Tau Energy Scale Changes
  EScaledTaus(process,False)

  #Add trigger Matching
  muonTriggerMatchPT(process,triggerProcess,HLT)
  electronTriggerMatchPT(process,triggerProcess,HLT)
  tauTriggerMatchPT(process,triggerProcess,HLT)
  
  #Build good vertex collection
  goodVertexFilter(process)  
  tauOverloading(process,'triggeredPatTaus','primaryVertexFilter')
  
  TriLeptons(process)
  ReRunJetsMC(process)
  #ReNameJetColl(process)

  jetOverloading(process,"NewSelectedPatJets")  
  PATJetMVAEmbedder(process,"patOverloadedJets")  
  #Default selections for systematics
  applyDefaultSelectionsPT(process)
  

  #Build good vertex collection

  process.runAnalysisSequence = cms.Path(process.analysisSequence)


def defaultReconstructionEMBMT(process,triggerProcess = 'HLT',triggerPaths = ['HLT_Mu9','HLT_Mu11_PFTau15_v1','HLT_Mu11_PFTau15_v1','HLT_Mu11_PFTau15_v2','HLT_Mu15_v1','HLT_Mu15_v2'],HLT = 'hltTriggerSummaryAOD'):
  process.load("UWAnalysis.Configuration.startUpSequence_cff")
  process.load("Configuration.Geometry.GeometryIdeal_cff")
  process.load("Configuration.StandardSequences.MagneticField_cff")
  process.load("Configuration.StandardSequences.Services_cff")
  process.load("TrackingTools.TransientTrack.TransientTrackBuilder_cfi")
  process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")
  process.load("DQMServices.Core.DQM_cfg")
  process.load("DQMServices.Components.DQMEnvironment_cfi")


  #Make the TriggerPaths Global variable to be accesed by the ntuples
  global TriggerPaths
  TriggerPaths= triggerPaths
  process.analysisSequence = cms.Sequence()

  mvaMet2(process)


  #Apply Tau Energy Scale Changes
  EScaledTaus(process,True)

  #Add trigger Matching
  muonTriggerMatchPT(process,triggerProcess,HLT)
  electronTriggerMatchPT(process,triggerProcess,HLT)
  tauTriggerMatchPT(process,triggerProcess,HLT)

  #Build good vertex collection
  goodVertexFilter(process)  
  tauOverloading(process,'triggeredPatTaus','primaryVertexFilter')
  
  TriLeptons(process)
  #ReRunJets(process)
  ReNameJetColl(process)
  
  #kineWeightsEmbMT(process)
  jetOverloading(process,"NewSelectedPatJets")  
  PATJetMVAEmbedder(process,"patOverloadedJets")  
  #Default selections for systematics
  applyDefaultSelectionsPT(process)
  

  #Build good vertex collection

  process.runAnalysisSequence = cms.Path(process.analysisSequence)
  

def defaultReconstructionEMBET(process,triggerProcess = 'HLT',triggerPaths = ['HLT_Mu9','HLT_Mu11_PFTau15_v1','HLT_Mu11_PFTau15_v1','HLT_Mu11_PFTau15_v2','HLT_Mu15_v1','HLT_Mu15_v2'],HLT = 'hltTriggerSummaryAOD'):
  process.load("UWAnalysis.Configuration.startUpSequence_cff")
  process.load("Configuration.Geometry.GeometryIdeal_cff")
  process.load("Configuration.StandardSequences.MagneticField_cff")
  process.load("Configuration.StandardSequences.Services_cff")
  process.load("TrackingTools.TransientTrack.TransientTrackBuilder_cfi")
  process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")
  process.load("DQMServices.Core.DQM_cfg")
  process.load("DQMServices.Components.DQMEnvironment_cfi")


  #Make the TriggerPaths Global variable to be accesed by the ntuples
  global TriggerPaths
  TriggerPaths= triggerPaths
  process.analysisSequence = cms.Sequence()

  mvaMet2(process)


  #Apply Tau Energy Scale Changes
  EScaledTaus(process,True)

  #Add trigger Matching
  muonTriggerMatchPT(process,triggerProcess,HLT)
  electronTriggerMatchPT(process,triggerProcess,HLT)
  tauTriggerMatchPT(process,triggerProcess,HLT)

  #Build good vertex collection
  goodVertexFilter(process)  
  tauOverloading(process,'triggeredPatTaus','primaryVertexFilter')
  
  TriLeptons(process)
  #ReRunJets(process)
  ReNameJetColl(process)
  
  #kineWeightsEmbET(process)
  jetOverloading(process,"NewSelectedPatJets")  
  PATJetMVAEmbedder(process,"patOverloadedJets")  
  #Default selections for systematics
  applyDefaultSelectionsPT(process)
  

  #Build good vertex collection

  process.runAnalysisSequence = cms.Path(process.analysisSequence)

def jetOverloading(process,jets):

  process.patOverloadedJets = cms.EDProducer('PATJetOverloader',
                                        src = cms.InputTag(jets),
                                        genJets = cms.InputTag("ak5GenJets")
  )                                        

  process.jetOverloading = cms.Sequence(process.patOverloadedJets)
  #process.createOverloadedJets=cms.Path(process.jetOverloading)
  process.analysisSequence*=process.jetOverloading

def PATJetMVAEmbedder(process,jets):

  process.patMVAEmbeddedJets = cms.EDProducer('PATJetMVAEmbedder',
                                        src = cms.InputTag(jets)
  )                                        

  process.jetMVAEmbedding = cms.Sequence(process.patMVAEmbeddedJets)
  process.analysisSequence*=process.jetMVAEmbedding
    
def EScaledTaus(process,smearing):  #second arg is bool

  process.ESTausID = cms.EDProducer("ESTauProducer",
                                    src = cms.InputTag("cleanPatTaus"),
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

  #process.createESTausID=cms.Path(process.analysisSequence*process.EScaledTaus)
  
#def EScaledMet(process,smearing):  #second arg is bool

#  process.ESMet = cms.EDProducer("ESMetProducer",
#                                    src = cms.InputTag("patMVAMet"),
#                                    Taus = cms.InputTag("cleanPatTaus"),
#                                    module_label = cms.string("FROGS"),
#                                    smearConstituents = cms.bool(True),
#                                    smearMCParticle = cms.bool(False),
#                                    energyScale  = cms.double(1.0),
#                                    energyScaleDB= cms.int32(0),
#                                    deltaEta     = cms.double(0.0),
#                                    deltaPhi     = cms.double(0.0),
#                                    deltaPtB     = cms.double(0.0),
#                                    deltaPtE     = cms.double(0.0)
#                                    )
#  
#  process.EScaledMet = cms.Sequence(process.ESMet)
#  process.analysisSequence*=process.EScaledMet
  #process.createESTausID=cms.Path(process.analysisSequence*process.EScaledTaus)
  


def mvaMet2(process):

  #process.load('RecoMET.METProducers.mvaPFMET_cff_leptons')
  #process.load("JetMETCorrections.METPUSubtraction.mvaPFMET_leptons_PAT_cfi")
  process.load("JetMETCorrections.METPUSubtraction.mvaPFMET_leptons_data_cff")

  process.load("PhysicsTools.PatAlgos.producersLayer1.metProducer_cfi")

  process.load("RecoJets.Configuration.RecoPFJets_cff")
  process.ak5PFJets.doAreaFastjet = True

  
  process.patMVAMet = process.patMETs.clone(
  	metSource = cms.InputTag('pfMEtMVA'),
  	addMuonCorrections = cms.bool(False),
  	addGenMET = cms.bool(False)
  )
  
  process.analysisSequence = cms.Sequence(process.analysisSequence*process.ak5PFJets*process.calibratedAK5PFJetsForPFMEtMVA*process.pfMEtMVAsequence*process.patMVAMet)
  #process.analysisSequence = cms.Sequence(process.analysisSequence*process.pfMEtMVAsequence*process.patMVAMet)

  #process.analysisSequence = cms.Sequence(process.analysisSequence*process.pfMEtMVAsequence*process.patMVAMet)

def mvaMet2MC(process):

  #process.load('RecoMET.METProducers.mvaPFMET_cff_leptons')
  #process.load("JetMETCorrections.METPUSubtraction.mvaPFMET_leptons_PAT_cfi")
  process.load("JetMETCorrections.METPUSubtraction.mvaPFMET_leptons_cff")

  process.load("PhysicsTools.PatAlgos.producersLayer1.metProducer_cfi")

  process.load("RecoJets.Configuration.RecoPFJets_cff")
  process.ak5PFJets.doAreaFastjet = True
  
  process.patMVAMet = process.patMETs.clone(
  	metSource = cms.InputTag('pfMEtMVA'),
  	addMuonCorrections = cms.bool(False),
  	addGenMET = cms.bool(False)
  )
  
  process.analysisSequence = cms.Sequence(process.analysisSequence*process.ak5PFJets*process.calibratedAK5PFJetsForPFMEtMVA*process.pfMEtMVAsequence*process.patMVAMet)
  #process.analysisSequence = cms.Sequence(process.analysisSequence*process.pfMEtMVAsequence*process.patMVAMet)

  #process.analysisSequence = cms.Sequence(process.analysisSequence*process.pfMEtMVAsequence*process.patMVAMet)

def ReNameJetColl(process):

  process.load("PhysicsTools.PatAlgos.patSequences_cff")
  
  process.NewSelectedPatJets = process.selectedPatJets.clone(src = cms.InputTag("selectedPatJets"))
  
  process.analysisSequence*= process.NewSelectedPatJets
  

def ReRunJetsMC(process):
  process.load("RecoJets.Configuration.RecoPFJets_cff") 
  import PhysicsTools.PatAlgos.tools.jetTools as jettools
  process.load("PhysicsTools.PatAlgos.patSequences_cff")
  process.load("UWAnalysis.Configuration.tools.patJetPUId_cfi")
  from RecoBTag.SoftLepton.softLepton_cff import *
  from RecoBTag.ImpactParameter.impactParameter_cff import *
  from RecoBTag.SecondaryVertex.secondaryVertex_cff import *
  from RecoBTau.JetTagComputer.combinedMVA_cff import *
  process.pileupJetIdProducer.applyJec = cms.bool(True)

  process.load('RecoVertex/AdaptiveVertexFinder/inclusiveVertexing_cff')
  #process.load('RecoBTag/SecondaryVertex/bToCharmDecayVertexMerger_cfi')

  process.simpleSecondaryVertex = cms.ESProducer("SimpleSecondaryVertexESProducer",
                                                       use3d = cms.bool(True),
                                                       unBoost = cms.bool(False),
                                                       useSignificance = cms.bool(True),
                                                       minTracks = cms.uint32(2)
                                                   )

  # Define options for BTagging - these are release dependent.
  btag_options = {'doBTagging': True}
  btag_options['btagInfo'] = [
    'impactParameterTagInfos',
    'secondaryVertexTagInfos',
    'softMuonTagInfos'
  ]
  btag_options['btagdiscriminators'] = [
    'simpleSecondaryVertexHighEffBJetTags',
    'simpleSecondaryVertexHighPurBJetTags',
    'combinedSecondaryVertexMVABJetTags',
    'combinedSecondaryVertexBJetTags',
    ]
    
  jec = ['L1FastJet', 'L2Relative', 'L3Absolute']
  # For Data jec.extend(['L2L3Residual'])
  
  jettools.switchJetCollection(
        process,
        cms.InputTag('ak5PFJets'),
        doJTA=False,
        jetCorrLabel=('AK5PF', jec),
        #jetCorrLabel = None,
        doType1MET=False,
        doJetID=True,
        genJetCollection=cms.InputTag("ak5GenJets"),
        outputModules=[],
        **btag_options       
  )
  process.patJets.embedPFCandidates = False
  process.patJets.embedCaloTowers = False
  process.patJets.embedGenJetMatch = False
  process.patJets.addAssociatedTracks = False
  process.patJets.embedGenPartonMatch = False
  process.patJets.tagInfoSources = cms.VInputTag(
    cms.InputTag("impactParameterTagInfos"),
    #cms.InputTag("secondaryVertexNegativeTagInfos"),
    cms.InputTag("secondaryVertexTagInfos"))
  process.patJets.discriminatorSources = cms.VInputTag(
    cms.InputTag("combinedSecondaryVertexMVABJetTags"),
    cms.InputTag("combinedSecondaryVertexBJetTags"),
    cms.InputTag("simpleSecondaryVertexHighPurBJetTags"),
    cms.InputTag("simpleSecondaryVertexHighEffBJetTags"))
  process.patJets.trackAssociationSource = cms.InputTag("ak5JetTracksAssociatorAtVertex")
  process.patJets.addBTagInfo = cms.bool(True)
  process.patJets.addDiscriminators = cms.bool(True)
  process.patJets.addTagInfos = cms.bool(True)

  process.ak5JetTracksAssociatorAtVertex = cms.EDProducer("JetTracksAssociatorAtVertex",
                                                          tracks       = cms.InputTag("generalTracks"),
                                                          jets         = cms.InputTag("ak5PFJets"),
                                                          coneSize     = cms.double(0.5)
                                                          )
  
  process.load('UWAnalysis.Configuration.tools.RecoBTag_cff')  
  process.patJetCharge.src = cms.InputTag("ak5JetTracksAssociatorAtVertex")
  process.NewSelectedPatJets = process.selectedPatJets.clone(src = cms.InputTag("patJetId"))
  process.analysisSequence = cms.Sequence(
  					process.analysisSequence*
  					process.ak5PFJets*
  					process.ak5JetTracksAssociatorAtVertex*
  					process.btagging*
  					process.pileupJetIdProducer*
  					process.makePatJets*
  					process.patJetsPUID*
  					process.patJetId*
  					process.NewSelectedPatJets  					
  					)

def ReRunJets(process):

  process.load("RecoJets.Configuration.RecoPFJets_cff") 
  import PhysicsTools.PatAlgos.tools.jetTools as jettools
  process.load("PhysicsTools.PatAlgos.patSequences_cff")
  process.load("UWAnalysis.Configuration.tools.patJetPUId_cfi")
  from RecoBTag.SoftLepton.softLepton_cff import *
  from RecoBTag.ImpactParameter.impactParameter_cff import *
  from RecoBTag.SecondaryVertex.secondaryVertex_cff import *
  from RecoBTau.JetTagComputer.combinedMVA_cff import *

  process.pileupJetIdProducer.applyJec = cms.bool(True)

  # Define options for BTagging - these are release dependent.
  btag_options = {'doBTagging': True}
  btag_options['btagInfo'] = [
            'secondaryVertexTagInfos',
  ]
  btag_options['btagdiscriminators'] = [
    'simpleSecondaryVertexHighEffBJetTags',
    'simpleSecondaryVertexHighPurBJetTags',
    'combinedSecondaryVertexMVABJetTags',
    'combinedSecondaryVertexBJetTags',
  ]

  jec = ['L1FastJet', 'L2Relative', 'L3Absolute', 'L2L3Residual']

  
  jettools.switchJetCollection(
        process,
        cms.InputTag('ak5PFJets'),
        doJTA=False,
        jetCorrLabel=('AK5PF', jec),
        #jetCorrLabel = None,
        doType1MET=False,
        doJetID=True,
        genJetCollection=cms.InputTag("ak5GenJets"),
        outputModules=[],
        **btag_options       
  )
  process.patJets.embedPFCandidates = False
  process.patJets.embedCaloTowers = False
  process.patJets.embedGenJetMatch = False
  process.patJets.addAssociatedTracks = False
  process.patJets.embedGenPartonMatch = False
  process.patJets.tagInfoSources = cms.VInputTag(cms.InputTag("secondaryVertexTagInfos"))
  process.patJets.discriminatorSources = cms.VInputTag(cms.InputTag("combinedSecondaryVertexMVABJetTags"), cms.InputTag("combinedSecondaryVertexBJetTags"), cms.InputTag("simpleSecondaryVertexHighPurBJetTags"), cms.InputTag("simpleSecondaryVertexHighEffBJetTags"))
  process.patJets.addBTagInfo = cms.bool(True)
  
  process.ak5JetTracksAssociatorAtVertex = cms.EDProducer("JetTracksAssociatorAtVertex",
   	  tracks       = cms.InputTag("generalTracks"),
      jets         = cms.InputTag("ak5PFJets"),
      coneSize     = cms.double(0.5)
  )
  
  process.load('UWAnalysis.Configuration.tools.RecoBTag_cff')  
  process.patJetCharge.src = cms.InputTag("ak5JetTracksAssociatorAtVertex")
  process.NewSelectedPatJets = process.selectedPatJets.clone(src = cms.InputTag("patJetId"))
  process.makePatJetsData = cms.Sequence(process.patJetCorrFactors+
  										process.patJetCharge+
  										process.patJets)
  
  process.analysisSequence = cms.Sequence(
  					process.analysisSequence*
  					process.ak5PFJets*
  					process.ak5JetTracksAssociatorAtVertex*
  					process.btagging*
  					process.pileupJetIdProducer*
  					process.makePatJetsData*
  					process.patJetsPUID*
  					process.patJetId*
  					process.NewSelectedPatJets  					
  					)


def ReRunJetsEMB(process):

  process.load("RecoJets.Configuration.RecoPFJets_cff") 
  import PhysicsTools.PatAlgos.tools.jetTools as jettools
  process.load("PhysicsTools.PatAlgos.patSequences_cff")
  process.load("UWAnalysis.Configuration.tools.patJetPUId_cfi")
  from RecoBTag.SoftLepton.softLepton_cff import *
  from RecoBTag.ImpactParameter.impactParameter_cff import *
  from RecoBTag.SecondaryVertex.secondaryVertex_cff import *
  from RecoBTau.JetTagComputer.combinedMVA_cff import *

  process.pileupJetIdProducer.applyJec = cms.bool(True)

  # Define options for BTagging - these are release dependent.
  btag_options = {'doBTagging': True}
  btag_options['btagInfo'] = [
            'secondaryVertexTagInfos',
  ]
  btag_options['btagdiscriminators'] = [
            'combinedSecondaryVertexMVABJetTags',
            'combinedSecondaryVertexBJetTags',
  ]

  jec = ['L1FastJet', 'L2Relative', 'L3Absolute', 'L2L3Residual']

  
  jettools.switchJetCollection(
        process,
        cms.InputTag('ak5PFJets'),
        doJTA=False,
        jetCorrLabel=('AK5PF', jec),
        #jetCorrLabel = None,
        doType1MET=False,
        doJetID=True,
        genJetCollection=cms.InputTag("ak5GenJets"),
        outputModules=[],
        **btag_options       
  )
  process.patJets.embedPFCandidates = False
  process.patJets.embedCaloTowers = False
  process.patJets.embedGenJetMatch = False
  process.patJets.addAssociatedTracks = False
  process.patJets.embedGenPartonMatch = False
  process.patJets.tagInfoSources = cms.VInputTag(cms.InputTag("secondaryVertexTagInfos"))
  process.patJets.discriminatorSources = cms.VInputTag(cms.InputTag("combinedSecondaryVertexMVABJetTags"), cms.InputTag("combinedSecondaryVertexBJetTags"))
  process.patJets.addBTagInfo = cms.bool(True)
  
  process.ak5JetTracksAssociatorAtVertex = cms.EDProducer("JetTracksAssociatorAtVertex",
   	  tracks       = cms.InputTag("tmfTracks"),
      jets         = cms.InputTag("ak5PFJets"),
      coneSize     = cms.double(0.5)
  )
  
  process.load('UWAnalysis.Configuration.tools.RecoBTag_cff')  
  process.patJetCharge.src = cms.InputTag("ak5JetTracksAssociatorAtVertex")
  process.NewSelectedPatJets = process.selectedPatJets.clone(src = cms.InputTag("patJetId"))
  process.analysisSequence = cms.Sequence(
  					process.analysisSequence*
  					process.ak5PFJets*
  					process.ak5JetTracksAssociatorAtVertex*
  					process.btagging*
  					process.pileupJetIdProducer*
  					process.makePatJets*
  					process.patJetsPUID*
  					process.patJetId*
  					process.NewSelectedPatJets  					
  					)

def kineWeightsEmbET(process):

  process.load('TauAnalysis/MCEmbeddingTools/embeddingKineReweight_cff')

  process.embeddingKineReweightRECembedding.inputFileName = cms.FileInPath('TauAnalysis/MCEmbeddingTools/data/embeddingKineReweight_ePtGt20tauPtGt18_recEmbedded.root')
  
  process.analysisSequence = cms.Sequence(process.analysisSequence*process.embeddingKineReweightSequenceRECembedding)
  
  
def kineWeightsEmbMT(process):

  process.load('TauAnalysis/MCEmbeddingTools/embeddingKineReweight_cff')

  process.embeddingKineReweightRECembedding.inputFileName = cms.FileInPath('TauAnalysis/MCEmbeddingTools/data/embeddingKineReweight_muPtGt16tauPtGt18_recEmbedded.root')
  
  process.analysisSequence = cms.Sequence(process.analysisSequence*process.embeddingKineReweightSequenceRECembedding)
  

def LHEFilter(process):

  process.LHEFilter = cms.EDFilter("GenFilterLHE",
       PartonMultiplicity=cms.untracked.int32(5),
  )
  
  process.analysisSequence*= process.LHEFilter

def TriLeptons(process):

  process.TightElectrons = cms.EDFilter("PATElectronSelector",
  							src = cms.InputTag("cleanPatElectrons"),
  							cut = cms.string('pt>10&&abs(eta)<2.5&&userInt("mvaidwp")>0&&abs(userFloat("dz"))<0.2&&abs(userFloat("ipDXY"))<0.045&&(!(userInt("HasMatchedConversion")>0))&&userInt("missingHits")==0&&(userIso(0)+max(userIso(1)+neutralHadronIso()-0.5*userIso(2),0.0))/pt()<0.3'),
  							filter = cms.bool(False)
  						)
  						
  process.TightMuons = cms.EDFilter("PATMuonSelector",
  							src = cms.InputTag("cleanPatMuons"),
  							cut = cms.string('pt>10&&abs(eta)<2.4&&userInt("tightID")>0&&abs(userFloat("dz"))<0.2&&abs(userFloat("ipDXY"))<0.045&&isGlobalMuon&&(userIso(0)+max(photonIso+neutralHadronIso()-0.5*puChargedHadronIso,0.0))/pt()<0.3'),
  							filter = cms.bool(False)
  						)

  process.analysisSequence = cms.Sequence(process.analysisSequence*process.TightMuons*process.TightElectrons)
  						
  						

  						
def applyDefaultSelectionsPT(process):
  #DONT CHANGE THOSE HERE:: THEY ARE NOT USED FOR YOUR SELECTIONS!!!
  #ONLY FOR SYSTEMATICS . PLEASE CHANGE THEM in YOUR CFG FILE IF REALLY NEEDED
  process.selectedPatTaus = cms.EDFilter("PATTauSelector",
                                           src = cms.InputTag("ESTausID"),
                                           cut = cms.string('pt>15&&tauID("byCombinedIsolationDeltaBetaCorrRaw3Hits")<3&&tauID("againstElectronLoose")&&tauID("againstMuonLoose2")'),
                                           filter = cms.bool(False)
  										)  
  process.selectedPatElectrons = cms.EDFilter("PATElectronSelector",
                                           src = cms.InputTag("cleanPatElectrons"),
                                           cut = cms.string('pt>10&&userFloat("wp95")>0&&(userIso(0)+max(photonIso+neutralHadronIso()-0.5*userIso(2),0.0))/pt()<0.3'),
                                           filter = cms.bool(False)
  										)
  process.selectedPatMuons = cms.EDFilter("PATMuonSelector",
                                           src = cms.InputTag("cleanPatMuons"),
                                           cut = cms.string('pt>10&&userInt("tightID")&&(userIso(0)+max(photonIso+neutralHadronIso()-0.5*puChargedHadronIso,0.0))/pt()<0.3'),
                                           filter = cms.bool(False)
  										) 
  process.cleanPatJets = cms.EDProducer("PATJetCleaner",
                                           src = cms.InputTag("patMVAEmbeddedJets"),#patOverloadedJets
                                           preselection = cms.string('abs(eta)<4.7&&userFloat("idLoose")>0&&pt>10&&userInt("fullIdLoose")>0'),
                                           checkOverlaps = cms.PSet(),
                                           finalCut = cms.string('')
  										)								 									  
  process.selectedObjectsForSyst = cms.Sequence(process.selectedPatTaus+process.selectedPatElectrons+process.selectedPatMuons+process.cleanPatJets)
  process.analysisSequence = cms.Sequence(process.analysisSequence*process.selectedObjectsForSyst)


def muonTriggerMatchPT(process,triggerProcess,HLT):

   process.triggeredPatMuons = cms.EDProducer("MuonTriggerMatcher",
                                            src = cms.InputTag("cleanPatMuons"),
                                            trigEvent = cms.InputTag(HLT),
                                            filters = cms.VInputTag(
                                                cms.InputTag('hltSingleMuIsoL3IsoFiltered12','',triggerProcess),
                                                cms.InputTag('hltSingleMuIsoL3IsoFiltered15','',triggerProcess),
                                                cms.InputTag('hltSingleMuIsoL3IsoFiltered24','',triggerProcess),
                                                cms.InputTag('hltOverlapFilterIsoMu15IsoPFTau15','',triggerProcess),
                                                cms.InputTag('hltOverlapFilterIsoMu12IsoPFTau10','',triggerProcess),
                                                cms.InputTag('hltSingleMuIsoL3IsoFiltered17','',triggerProcess),                                               
                                                cms.InputTag('hltSingleMuIsoL1s14L3IsoFiltered15eta2p1',"",triggerProcess),
                                                cms.InputTag('hltL3IsoL1sMu14Eta2p1L1f0L2f14QL2IsoL3f24L3IsoFiltered','',triggerProcess),
                                                cms.InputTag('hltOverlapFilterIsoMu15IsoPFTau20','',triggerProcess),
                                                cms.InputTag('hltL3crIsoL1sMu16Eta2p1L1f0L2f16QL3f18QL3crIsoFiltered10','',triggerProcess),
                                                cms.InputTag('hltL3crIsoL1sMu16Eta2p1L1f0L2f16QL3f24QL3crIsoFiltered10','',triggerProcess),
                                                cms.InputTag('hltOverlapFilterIsoMu18LooseIsoPFTau20','',triggerProcess),
                                                cms.InputTag('hltOverlapFilterIsoMu17LooseIsoPFTau20','',triggerProcess),
                                                cms.InputTag('hltL3crIsoL1sMu14erORMu16erL1f0L2f14QL3f17QL3crIsoRhoFiltered0p15','',triggerProcess),
                                                cms.InputTag('hltL3crIsoL1sMu16Eta2p1L1f0L2f16QL3f18QL3crIsoFiltered10','',triggerProcess),

                                                ### MC
                                                cms.InputTag('hltL3crIsoL1sMu16Eta2p1L1f0L2f16QL3f24QL3crIsoFiltered10','',triggerProcess),
                                                ### Data
                                                cms.InputTag('hltL3crIsoL1sMu16Eta2p1L1f0L2f16QL3f24QL3crIsoRhoFiltered0p15','',triggerProcess),
                                                cms.InputTag('hltL2fL1sMu16Eta2p1L1f0L2Filtered16Q','',triggerProcess),
                                                cms.InputTag('hltL3fL1sMu16Eta2p1L1f0L2f16QL3Filtered24Q','',triggerProcess),
                                                #####
                                                cms.InputTag('hltDiMuonMu17Mu8DzFiltered0p2','',triggerProcess),
                                                cms.InputTag('hltL3fL1DoubleMu10MuOpenL1f0L2f10L3Filtered17','',triggerProcess),
                                                cms.InputTag('hltL3pfL1DoubleMu10MuOpenL1f0L2pf0L3PreFiltered8','',triggerProcess),
                                                cms.InputTag('hltL3fL1DoubleMu10MuOpenOR3p5L1f0L2f10L3Filtered17','',triggerProcess),
                                                cms.InputTag('hltL3pfL1DoubleMu10MuOpenOR3p5L1f0L2pf0L3PreFiltered8','',triggerProcess)
                                            ),
                                            pdgId = cms.int32(13)
   )
  
   process.analysisSequence*= process.triggeredPatMuons

def electronTriggerMatchPT(process,triggerProcess,HLT):

   process.triggeredPatElectronsL = cms.EDProducer("ElectronTriggerMatcher",
                                            src = cms.InputTag("cleanPatElectrons"),
                                            trigEvent = cms.InputTag(HLT),
                                            filters = cms.VInputTag(
                                                cms.InputTag('hltEle17CaloIdLCaloIsoVLPixelMatchFilterDoubleEG125','',triggerProcess),
                                            ),
                                            pdgId = cms.int32(0)
   )
   process.triggeredPatElectrons = cms.EDProducer("ElectronTriggerMatcher",
                                            src = cms.InputTag("cleanPatElectrons"),
                                            trigEvent = cms.InputTag(HLT),
                                            filters = cms.VInputTag(
                                                cms.InputTag('hltOverlapFilterIsoEle15IsoPFTau20','',triggerProcess),
                                                cms.InputTag('hltOverlapFilterIsoEle15TightIsoPFTau20','',triggerProcess),
                                                cms.InputTag('hltOverlapFilterIsoEle18MediumIsoPFTau20','',triggerProcess),                                                
                                                cms.InputTag('hltOverlapFilterIsoEle18TightIsoPFTau20','',triggerProcess),
                                                cms.InputTag('hltOverlapFilterIsoEle18IsoPFTau20','',triggerProcess),
                                                cms.InputTag('hltOverlapFilterIsoEle20MediumIsoPFTau20','',triggerProcess),
                                                cms.InputTag('hltOverlapFilterIsoEle20LooseIsoPFTau20','',triggerProcess),
                                                cms.InputTag('hltOverlapFilterIsoEle20WP90LooseIsoPFTau20','',triggerProcess),
                                                cms.InputTag('hltEle20CaloIdVTCaloIsoTTrkIdTTrkIsoTTrackIsoFilterL1IsoEG18OrEG20','',triggerProcess),
                                                cms.InputTag('hltEle22WP90RhoTrackIsoFilter','',triggerProcess),
                                                cms.InputTag('hltEle27WP80TrackIsoFilter','',triggerProcess),
                                                cms.InputTag('hltEle27WP80TrackIsoFilter','',triggerProcess),
                                                cms.InputTag('hltEle17TightIdLooseIsoEle8TightIdLooseIsoTrackIsoDoubleFilter','',triggerProcess),
                                                cms.InputTag('hltEle17TightIdLooseIsoEle8TightIdLooseIsoTrackIsoFilter','',triggerProcess)
                                            ),
                                            pdgId = cms.int32(11)
   )
   
   process.analysisSequence=cms.Sequence(process.analysisSequence*process.triggeredPatElectronsL*process.triggeredPatElectrons)

def tauTriggerMatchPT(process,triggerProcess,HLT):
   strTrig=''
   for i in TriggerPaths:
    if i==TriggerPaths[0]:
      strTrig+='path(\"'+i+'\")'
    else:  
      strTrig+='|| path(\"'+i+'\")'


   #Match With The triggers
   process.preTriggeredPatTaus = cms.EDProducer("TauTriggerMatcher",
                                            src = cms.InputTag("ESTausID"),#cleanPatTaus
                                            trigEvent = cms.InputTag(HLT),
                                            filters = cms.VInputTag(
                                                cms.InputTag('hltFilterDoubleIsoPFTau20Trk5LeadTrack5IsolationL1HLTMatched','',triggerProcess),
                                                cms.InputTag('hltOverlapFilterIsoEle20LooseIsoPFTau20','',triggerProcess),
                                                cms.InputTag('hltOverlapFilterIsoMu18LooseIsoPFTau20','',triggerProcess),
                                                cms.InputTag('hltOverlapFilterIsoEle20WP90LooseIsoPFTau20','',triggerProcess),
                                                cms.InputTag('hltOverlapFilterIsoMu17LooseIsoPFTau20','',triggerProcess)
                                            ),
                                            pdgId = cms.int32(0)
   )

   process.triggeredPatTaus = cms.EDProducer("TauTriggerMatcher",
                                            src = cms.InputTag("preTriggeredPatTaus"),
                                            trigEvent = cms.InputTag(HLT),
                                            filters = cms.VInputTag(
                                                cms.InputTag('hltOverlapFilterIsoMu15IsoPFTau15','',triggerProcess),
                                                cms.InputTag('hltOverlapFilterIsoMu15IsoPFTau20','',triggerProcess),
                                                cms.InputTag('hltOverlapFilterIsoMu15MediumIsoPFTau20','',triggerProcess),
                                                cms.InputTag('hltOverlapFilterIsoMu15TightIsoPFTau20','',triggerProcess),
                                                cms.InputTag('hltOverlapFilterMu15IsoPFTau20','',triggerProcess),
                                                cms.InputTag('hltOverlapFilterIsoMu12IsoPFTau10','',triggerProcess),
                                                cms.InputTag('hltOverlapFilterIsoMu15IsoPFTau20','',triggerProcess),
                                                cms.InputTag('hltOverlapFilterIsoEle15IsoPFTau20','',triggerProcess),
                                                cms.InputTag('hltOverlapFilterIsoEle15TightIsoPFTau20','',triggerProcess),
                                                cms.InputTag('hltOverlapFilterIsoEle18MediumIsoPFTau20','',triggerProcess),
                                                cms.InputTag('hltOverlapFilterIsoEle20MediumIsoPFTau20','',triggerProcess),
                                                cms.InputTag('hltOverlapFilterIsoEle20LooseIsoPFTau20','',triggerProcess),
                                                cms.InputTag('hltOverlapFilterIsoMu18LooseIsoPFTau20','',triggerProcess),
                                                cms.InputTag('hltOverlapFilterIsoEle20WP90LooseIsoPFTau20','',triggerProcess),
                                                cms.InputTag('hltOverlapFilterIsoMu17LooseIsoPFTau20','',triggerProcess)                                              
                                            ),
                                            pdgId = cms.int32(15)
   )
                                            
   process.analysisSequence=cms.Sequence(process.analysisSequence*process.preTriggeredPatTaus*process.triggeredPatTaus)

def tauOverloading(process,src,vtxSrc):


  process.patOverloadedTaus = cms.EDProducer('PATTauOverloader',
                                        src = cms.InputTag(src),
                                        muons = cms.InputTag('cleanPatMuons'),
                                        vtxSrc = cms.InputTag(vtxSrc)
  )                                        

  process.analysisSequence=cms.Sequence(process.analysisSequence*process.patOverloadedTaus)

## def muonOverloading(process,muons,taus):


##   process.patOverloadedMuons = cms.EDProducer('PATMuonOverloader',
##                                         taus = cms.InputTag(taus),
##                                         muons = cms.InputTag(muons),
##                                         vtxSrc = cms.InputTag('primaryVertexFilter')
##   )                                        

##   process.analysisSequence=cms.Sequence(process.analysisSequence*process.patOverloadedMuons)

  

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
                                               convertOnEndRun = cms.untracked.bool(True)
                                               )
        eventSummaryPath=cms.EndPath(process.EDMtoMEConverter+getattr(process,name))
        setattr(process,name+"Path",eventSummaryPath)
   else:
        eventSummaryPath=cms.EndPath(getattr(process,name))
        setattr(process,name+"Path",eventSummaryPath)



def createGeneratedParticles(process,name,commands):


  refObjects = cms.EDProducer("GenParticlePruner",
    src = cms.InputTag("genParticles"),
    select = cms.vstring(
    "drop  *  " 
    )
   )
  refObjects.select.extend(commands)
  setattr(process,name,refObjects)
  process.analysisSequence*= getattr(process,name)

def createGeneratedParticles2(process,name,commands):


  refObjects = cms.EDProducer("GenParticlePruner",
    src = cms.InputTag("genParticles"),
    select = cms.vstring(
    "drop  *  " 
    )
   )
  refObjects.select.extend(commands)
  setattr(process,name,refObjects)
  #process.analysisSequence*= getattr(process,name)



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

  process.primaryVertexFilter = cms.EDFilter("VertexSelector",
                                        src = cms.InputTag('offlinePrimaryVertices'),
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

    # Get PFMET w/ singificance
    process.load("TauAnalysis.CandidateTools.PFMETSignCovMatrixEmbedder_cfi")

    process.metWithSig = process.patMETSignEmbedder.clone(
        src = cms.InputTag("systematicsMET"),
        srcCov = cms.InputTag("pfMEtSignCovMatrix")
    )


    process.analysisSequence = cms.Sequence(
        process.analysisSequence *
        process.metWithSig
    )
    

# stephane's addition
def addTagAndProbePlotter(process,type,name,src,ref,selections,methods,triggers,triggersProbe):

  process.TFileService = cms.Service("TFileService", fileName = cms.string("analysis.root") )
  muonAnalysis = cms.EDAnalyzer(type,
                                src=cms.InputTag(src),
                                vertices=cms.InputTag("primaryVertexFilter"),
                                ref=cms.InputTag(ref),
                                patTrigger = cms.InputTag("patTrigger"),
                                id= cms.vstring(selections),
                                methods= cms.vstring(methods),
                                triggers = cms.vstring(triggers),
                                triggersProbe = cms.vstring(triggersProbe),
  )                                
  
  setattr(process,'tagAndProbe'+name,muonAnalysis)
  p = cms.EndPath(getattr(process,'tagAndProbe'+name))
  setattr(process,'tagAndProbePath'+name,p)   


def pfMetWithSignficance(process):

    # Get PFMET w/ singificance
    process.load("UWAnalysis.Configuration.tools.pfMetCovariance_cfi")
    process.load("TauAnalysis.CandidateTools.PFMETSignCovMatrixEmbedder_cfi")


    process.metWithSig = process.patMETSignEmbedder.clone(
        src = cms.InputTag("systematicsMET"),
        srcCov = cms.InputTag("pfMEtSignCovMatrix")
    )


    process.analysisSequence = cms.Sequence(
        process.analysisSequence *
        process.metSignficanceSequence *
        process.metWithSig
    )

