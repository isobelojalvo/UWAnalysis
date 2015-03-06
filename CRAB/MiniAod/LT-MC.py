import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")

process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.GlobalTag.globaltag = 'PLS170_V7AN1::All'


process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(500)
)



process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
'file:/hdfs/store/mc/Phys14DR/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/MINIAODSIM/PU4bx50_PHYS14_25_V1-v1/10000/FE06FEE7-E97B-E411-9AE2-0025905A608A.root'
		),
		inputCommands=cms.untracked.vstring(
						'keep *',
						'keep *_l1extraParticles_*_*',
		)
)


#added in etau and mutau triggers
from UWAnalysis.Configuration.tools.analysisToolsMiniAod import *
defaultReconstructionMC(process,'HLT',
                      [
						'HLT_Ele22_eta2p1_WP85_Gsf_LooseIsoPFTau20_v1',
						'HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v1'
                      ])

                      

#EventSelection
process.load("UWAnalysis.Configuration.MiniAodAnalysis_cff")

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
                           "keep pdgId = {tau+} & mother.pdgId()= {Z0}",
                           "keep pdgId = {tau-} & mother.pdgId() = {Z0}"
                          ]
)


from UWAnalysis.Configuration.tools.ntupleToolsMiniAod import addMuTauEventTree
addMuTauEventTree(process,'muTauEventTree')
addMuTauEventTree(process,'muTauEventTreeFinal','diTausOS','diMuonsSorted')

from UWAnalysis.Configuration.tools.ntupleToolsMiniAod import addEleTauEventTree
addEleTauEventTree(process,'eleTauEventTree')
addEleTauEventTree(process,'eleTauEventTreeFinal','eleTausOS','osDiElectrons')

addEventSummary(process,True,'MT','eventSelectionMT')
addEventSummary(process,True,'ET','eventSelectionET')

