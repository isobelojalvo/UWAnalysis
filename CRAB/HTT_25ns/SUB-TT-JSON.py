import os
import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')

process.options   = cms.untracked.PSet(wantSummary = cms.untracked.bool(False))
process.options.allowUnscheduled = cms.untracked.bool(True)

process.GlobalTag.globaltag = '80X_dataRun2_2016SeptRepro_v6'

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
               $inputFileNames
		),
		inputCommands=cms.untracked.vstring(
						'keep *',
						'keep *_l1extraParticles_*_*',
		)
)

import FWCore.PythonUtilities.LumiList as LumiList
#directory=os.environ['CMSSW_BASE']
#process.source.lumisToProcess = LumiList.LumiList('/afs/hep.wisc.edu/home/ojalvo/Cert_271036-279116_13TeV_PromptReco_Collisions16_JSON.txt').getVLuminosityBlockRange()

from UWAnalysis.Configuration.JSONBtoF import myLumiList
myLumiList(process);

from UWAnalysis.Configuration.tools.analysisToolsHTauTau_WIP import *

defaultReconstruction(process,'HLT',
                      [
			'HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_Reg_v2',
                        #'HLT_DoubleMediumIsoPFTau32_Trk1_eta2p1_Reg_v2',
                        'HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_Reg_v3',
                        'HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_Reg_v4',
                        'HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_Reg_v5',
                        'HLT_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg_v5',
                        'HLT_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg_v6'
                      ])

#EventSelection
process.load("UWAnalysis.Configuration.hTauTauHadronicEmu_cff")
#process.metCalibration.applyCalibration = cms.bool(False)

process.eventSelectionTT = cms.Path(process.selectionSequenceTT)

from UWAnalysis.Configuration.tools.ntupleToolsHTauTau_WIP import addDiTauEventTree

addDiTauEventTree(process,'diTauEventTree','diTausSyncData')
addDiTauEventTree(process,'diTauEventTreeFinal','diTausSortedFinal')

addEventSummary(process,True,'TT','eventSelectionTT')

process.TFileService = cms.Service(
    "TFileService",
    fileName = cms.string("$outputFileName")
)

