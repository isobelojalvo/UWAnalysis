import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")
#process.load('Configuration.StandardSequences.Services_cff')
process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')

process.GlobalTag.globaltag = 'PHYS14_25_V1'


process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(4000)
)



process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
'file:/hdfs/store/mc/Phys14DR/GluGluToHToTauTau_M-125_13TeV-powheg-pythia6/MINIAODSIM/PU20bx25_tsg_PHYS14_25_V1-v1/10000/86CFA7C5-B96F-E411-B077-00266CF25490.root'
#'file:/hdfs/store/mc/Phys14DR/TT_Tune4C_13TeV-pythia8-tauola/MINIAODSIM/PU20bx25_tsg_PHYS14_25_V1-v1/10000/F842EB7D-B470-E411-B141-0025905A60CE.root'
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
						'HLT_Ele22_eta2p1_WP85_Gsf_LooseIsoPFTau20_v1', #etau
                                                'HLT_Ele27_eta2p1_WP85_Gsf_v1', #etau
						'HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v1', #mutau
                                                'HLT_IsoMu24_eta2p1_IterTrk02_v1' #mutau
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

from UWAnalysis.Configuration.tools.ntupleToolsMiniAod import addEleTauEventTree
addEleTauEventTree(process,'eleTauEventTree')

addEventSummary(process,True,'MT','eventSelectionMT')
addEventSummary(process,True,'ET','eventSelectionET')


