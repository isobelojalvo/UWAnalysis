import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")
#process.load('Configuration.StandardSequences.Services_cff')
#process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')

process.GlobalTag.globaltag = 'MCRUN2_74_V9'


process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(20000)
)



process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
'file:/hdfs/store/mc/RunIISpring15DR74/SUSYGluGluToHToTauTau_M-160_TuneCUETP8M1_13TeV-pythia8/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/10000/2A3929AE-5303-E511-9EFE-0025905A48C0.root'
		),
firstEvent = cms.untracked.uint32(1),
		inputCommands=cms.untracked.vstring(
						'keep *',
						'keep *_l1extraParticles_*_*',
		)
)


#added in etau and mutau triggers
from UWAnalysis.Configuration.tools.analysisToolsMiniAod import *
defaultReconstructionMC(process,'HLT',
                      [
						'HLT_Ele22_eta2p1_WP75_Gsf_LooseIsoPFTau20_v1', #etau
                                                'HLT_Ele27_eta2p1_WP75_Gsf_v1', #etau
						'HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v1', #mutau
                                                'HLT_IsoMu24_eta2p1_IterTrk02_v1' #mutau
                      ])

                      

#EventSelection
process.load("UWAnalysis.Configuration.HiggsTauTauSync_cff")

process.metCalibration.applyCalibration = cms.bool(False)

process.eventSelectionMT = cms.Path(process.selectionSequenceMT)
process.eventSelectionET = cms.Path(process.selectionSequenceET)

createGeneratedParticles(process,
                         'genDaughters',
                          [
                           "keep++ pdgId = {Z0}",
                           "keep pdgId = {tau+}",
                           "keep pdgId = {tau-}",
                           "keep pdgId = {mu+}",
                           "keep pdgId = {mu-}",
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
                           "keep pdgId = {tau+} & mother.pdgId()= 25",#{Z0}
                           "keep pdgId = {tau-} & mother.pdgId() = 25"
                          ]
)


from UWAnalysis.Configuration.tools.ntupleToolsSync import addMuTauEventTree
addMuTauEventTree(process,'muTauEventTree')

from UWAnalysis.Configuration.tools.ntupleToolsSync import addEleTauEventTree
addEleTauEventTree(process,'eleTauEventTree')

addEventSummary(process,True,'MT','eventSelectionMT')
addEventSummary(process,True,'ET','eventSelectionET')

# Make the framework shut up.
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 100

