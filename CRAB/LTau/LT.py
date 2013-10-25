import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")

process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.GlobalTag.globaltag = 'FT_53_V21_AN4::All'

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(1000)
)



process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
       'file:/hdfs/store/user/tapas/TauPlusX/Run2012C-22Jan2013-v1/AOD/2013-06-11-8TeV-53X-PatTuple_Master/patTuple_cfg-80B01A12-BF77-E211-9BC0-0030487E52A5.root'
		),
		inputCommands=cms.untracked.vstring(
						'keep *',
						'drop *_finalState*_*_*',
						'drop *_patFinalStateEvent*_*_*'
		)
)


from UWAnalysis.Configuration.tools.analysisToolsPT import *
defaultReconstruction(process,'HLT',
                      [
                         "HLT_IsoMu12_LooseIsoPFTau10",
                         "HLT_IsoMu15_LooseIsoPFTau15",
                         "HLT_IsoMu15_eta2p1_LooseIsoPFTau20",
                         "HLT_Ele15_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_LooseIsoPFTau20",
                         "HLT_Ele15_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_TightIsoPFTau20",
                         "HLT_Ele18_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_MediumIsoPFTau20",
                         "HLT_Ele20_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_MediumIsoPFTau20"
                      ])

                      

#EventSelection
process.load("UWAnalysis.Configuration.LepTauAnalysis_cff")

process.eventSelectionMT = cms.Path(process.selectionSequenceMT)
process.eventSelectionET = cms.Path(process.selectionSequenceET)

from UWAnalysis.Configuration.tools.ntupleToolsLTau import addMuTauEventTree
addMuTauEventTree(process,'muTauEventTree')
addMuTauEventTree(process,'muTauEventTreeFinal','diTausOS','diMuonsSorted')

from UWAnalysis.Configuration.tools.ntupleToolsLTau import addEleTauEventTree
addEleTauEventTree(process,'eleTauEventTree')
addEleTauEventTree(process,'eleTauEventTreeFinal','eleTausOS','osDiElectrons')

addEventSummary(process,False,'MT','eventSelectionMT')
addEventSummary(process,False,'ET','eventSelectionET')
