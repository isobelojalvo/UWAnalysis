import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')

process.GlobalTag.globaltag = '80X_dataRun2_Prompt_ICHEP16JEC_v0'


process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        "file:pickHighNJetEvents.root"
        #"/store/data/Run2016B/Tau/MINIAOD/PromptReco-v2/000/275/310/00000/0EC2725C-D737-E611-ACE9-02163E0141D7.root"
		),
		inputCommands=cms.untracked.vstring(
						'keep *',
						'keep *_l1extraParticles_*_*',
		)
)

import FWCore.PythonUtilities.LumiList as LumiList
#process.source.lumisToProcess = LumiList.LumiList(filename = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/Cert_271036-277148_13TeV_PromptReco_Collisions16_JSON.txt').getVLuminosityBlockRange()
process.source.lumisToProcess = LumiList.LumiList(filename = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/Cert_271036-279116_13TeV_PromptReco_Collisions16_JSON_NoL1T.txt').getVLuminosityBlockRange()

from UWAnalysis.Configuration.tools.analysisToolsHTauTau_WIP import *

defaultReconstruction(process,'HLT',
                      [
			'HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_Reg_v2',
                        'HLT_DoubleMediumIsoPFTau32_Trk1_eta2p1_Reg_v2',
                        'HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_Reg_v3',
                        'HLT_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg_v5'
                      ])

#EventSelection
process.load("UWAnalysis.Configuration.hTauTauHadronicEmu_cff")
#process.metCalibration.applyCalibration = cms.bool(False)

process.eventSelectionTT = cms.Path(process.selectionSequenceTT)

from UWAnalysis.Configuration.tools.ntupleToolsHTauTau_WIP import addDiTauEventTree

addDiTauEventTree(process,'diTauEventTree','diTausSync')
addDiTauEventTree(process,'diTauEventTreeFinal','diTausSortedFinal')

addEventSummary(process,True,'TT','eventSelectionTT')


