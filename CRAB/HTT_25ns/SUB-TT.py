import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')

process.GlobalTag.globaltag = '80X_mcRun2_asymptotic_v14'


process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(20000)
)



process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        '/store/mc/RunIISpring16MiniAODv1/GluGluHToTauTau_M125_13TeV_powheg_pythia8/MINIAODSIM/PUSpring16_80X_mcRun2_asymptotic_2016_v3-v1/10000/06A0B340-8025-E611-8262-B8CA3A708F98.root'
		),
		inputCommands=cms.untracked.vstring(
						'keep *',
						'keep *_l1extraParticles_*_*',
		)
)


#from UWAnalysis.Configuration.tools.analysisToolsZTauTauXSec import *
from UWAnalysis.Configuration.tools.analysisToolsHTauTau_WIP import *
defaultReconstructionMC(process,'HLT',
                      [
			'HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_Reg_v2'
                      ])

                      

#EventSelection
process.load("UWAnalysis.Configuration.hTauTauHadronicEmu_cff")
#process.metCalibration.applyCalibration = cms.bool(False)

process.eventSelectionTT = cms.Path(process.selectionSequenceTT)
createGeneratedParticles(process,
                         'genDaughters',
                          [
                           "keep++ pdgId = {Z0}",
                           "keep pdgId = {tau+}",
                           "keep pdgId = {tau-}",
#                           "keep pdgId = {mu+}",
#                           "keep pdgId = {mu-}",
                           "keep pdgId = 6",
                           "keep pdgId = -6",
                           "keep pdgId = 11",
                           "keep pdgId = -11",
                           "keep pdgId = 25",
                           "keep pdgId = 35",
                           "keep abs(pdgId) = 36"
                          ]
)


createGeneratedParticles(process,
                         'genTauCands',
                          [
                           "keep pdgId = {tau+} ",
                           "keep pdgId = {tau-} "
                          ]
)


from UWAnalysis.Configuration.tools.ntupleToolsHTauTau_WIP import addDiTauEventTree

addDiTauEventTree(process,'diTauEventTree','diTausAntiMu')
addDiTauEventTree(process,'diTauEventTreeFinal','diTausSortedFinal')

addEventSummary(process,True,'TT','eventSelectionTT')

#Systematic Shifts 1sigma
#process.eventSelectionTTTauUp    = createSystematics(process,process.selectionSequenceTT,'TauUp',1.00,1.0,1.03,0,1.0)
#process.eventSelectionTTauDown  = createSystematics(process,process.selectionSequenceTT,'TauDown',1.0,1.0,0.97,0,1.0)
#process.eventSelectionTTJetUp    = createSystematics(process,process.selectionSequenceTT,'JetUp',1.0,1.0,1.0,1,1.0)
#process.eventSelectionTTJetDown  = createSystematics(process,process.selectionSequenceTT,'JetDown',1.0,1.0,1.0,-1,1.0)


process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
       $inputFileNames
		),
		inputCommands=cms.untracked.vstring(
						'keep *',
		)
)

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

#process.TFileService.fileName=cms.string("$outputFileName")
process.TFileService = cms.Service(
    "TFileService",
    fileName = cms.string("$outputFileName")
)
