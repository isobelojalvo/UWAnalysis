import os
import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')

process.options   = cms.untracked.PSet(wantSummary = cms.untracked.bool(False))
process.options.allowUnscheduled = cms.untracked.bool(True)


process.GlobalTag.globaltag = '80X_dataRun2_2016SeptRepro_v7'


process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(100)
)

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        '/store/data/Run2016B/Tau/MINIAOD/03Feb2017_ver2-v2/50000/3C8A5A44-51ED-E611-A52F-0025905A497A.root',
        '/store/data/Run2016B/Tau/MINIAOD/03Feb2017_ver2-v2/50000/42A56B3F-51ED-E611-B8F8-0CC47A78A42E.root',
        '/store/data/Run2016B/Tau/MINIAOD/03Feb2017_ver2-v2/50000/42A773D7-54ED-E611-8943-0CC47A4C8EBA.root',
        '/store/data/Run2016B/Tau/MINIAOD/03Feb2017_ver2-v2/50000/42DEB8DC-55ED-E611-8C03-0025905B85DA.root',
        '/store/data/Run2016B/Tau/MINIAOD/03Feb2017_ver2-v2/50000/F603D842-51ED-E611-B936-0CC47A78A45A.root'

        #'file:output-100.root'
        #'file:pickevents/pickevents1.root',
        #'file:pickevents/pickevents2.root'
        #'file:pickevents/pickevents3.root',
        #'file:pickevents/pickevents4.root',
        #'file:pickevents/pickevents5.root',
        #'file:pickevents/pickevents6.root',
        #'file:pickevents/pickevents7.root',
        #'file:pickevents/pickevents8.root',
        #'file:pickevents/pickevents9.root',
        #'file:pickevents/pickevents10.root',
        #'file:pickevents/pickevents11.root',
        #'file:pickevents/pickevents12.root',
        #'file:pickevents/pickevents13.root',
        #'file:pickevents/pickevents14.root',
        #'file:pickevents/pickevents15.root'
        #'/store/data/Run2016B/Tau/MINIAOD/23Sep2016-v3/00000/0004DF01-8099-E611-8C1C-0242AC130003.root'
		),
		inputCommands=cms.untracked.vstring(
						'keep *',
						'keep *_l1extraParticles_*_*',
		)
)

#import FWCore.PythonUtilities.LumiList as LumiList
from UWAnalysis.Configuration.JSONBtoH import myLumiList
myLumiList(process);


from UWAnalysis.Configuration.tools.analysisToolsHTauTau_WIP import *

defaultReconstruction(process,'HLT',
                      [
			'HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_Reg_v',
                        'HLT_DoubleMediumCombinedIsoPFTau35_Trk1_eta2p1_Reg_v'
                      ])

#EventSelection
process.load("UWAnalysis.Configuration.hTauTauHadronicEmu_cff")
#process.metCalibration.applyCalibration = cms.bool(False)

process.eventSelectionTT = cms.Path(process.selectionSequenceTT)

from UWAnalysis.Configuration.tools.ntupleToolsHTauTau_WIP import addDiTauEventTree

addDiTauEventTree(process,'diTauEventTree','diTausSync',triggerCollection='HLT')
addDiTauEventTree(process,'diTauEventTreeFinal','diTausSyncTrig',triggerCollection='HLT')

addEventSummary(process,True,'TT','eventSelectionTT')


