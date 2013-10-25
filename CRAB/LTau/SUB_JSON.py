import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")

process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.GlobalTag.globaltag = 'FT_53_V21_AN4::All'



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
addMuTauEventTree(process,'muTauEventTreeFinal','diTausOS','diMuonsSorted')

from UWAnalysis.Configuration.tools.ntupleToolsLTau import addEleTauEventTree
addEleTauEventTree(process,'eleTauEventTree')
addEleTauEventTree(process,'eleTauEventTreeFinal','eleTausOS','osDiElectrons')

addEventSummary(process,False,'MT','eventSelectionMT')
addEventSummary(process,False,'ET','eventSelectionET')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

import FWCore.PythonUtilities.LumiList as LumiList

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


process.source.lumisToProcess = LumiList.LumiList(filename = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions12/8TeV/Reprocessing/Cert_190456-208686_8TeV_22Jan2013ReReco_Collisions12_JSON.txt').getVLuminosityBlockRange()

process.TFileService.fileName=cms.string("$outputFileName")

