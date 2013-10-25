import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")

process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.GlobalTag.globaltag = 'GR_P_V41_AN1::All'



from UWAnalysis.Configuration.tools.analysisToolsPT import *
defaultReconstruction(process,'HLT',
                      [
						"HLT_Ele20_CaloIdVT_CaloIsoRhoT_TrkIdT_TrkIsoT_LooseIsoPFTau20",
						"HLT_Ele22_eta2p1_WP90Rho_LooseIsoPFTau20",
						"HLT_IsoMu18_eta2p1_LooseIsoPFTau20",
						"HLT_IsoMu17_eta2p1_LooseIsoPFTau20",
						"HLT_IsoMu15_eta2p1_L1ETM20"
                      ])

                      

#EventSelection
process.load("UWAnalysis.Configuration.LepTauAnalysis_cff")

process.eventSelectionMT = cms.Path(process.selectionSequenceMT)
process.eventSelectionET = cms.Path(process.selectionSequenceET)

from UWAnalysis.Configuration.tools.ntupleToolsLTau import addMuTauEventTree
addMuTauEventTree(process,'muTauEventTree')
addMuTauEventTree(process,'muTauEventTreeFinal','diTausLooseTauIsolation','diMuonsSorted')

from UWAnalysis.Configuration.tools.ntupleToolsLTau import addEleTauEventTree
addEleTauEventTree(process,'eleTauEventTree')
addEleTauEventTree(process,'eleTauEventTreeFinal','eleTausLooseIsolation','osDiElectrons')

addEventSummary(process,False,'MT','eventSelectionMT')
addEventSummary(process,False,'ET','eventSelectionET')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)



process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
       $inputFileNames
		),
		inputCommands=cms.untracked.vstring(
						'keep *',
						'drop *_finalState*_*_*',
						'drop *_patFinalStateEvent*_*_*'
		)
)


process.TFileService.fileName=cms.string("$outputFileName")

