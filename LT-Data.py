import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')

process.GlobalTag.globaltag = '80X_dataRun2_Prompt_v8'

process.options   = cms.untracked.PSet(wantSummary = cms.untracked.bool(False))
process.options.allowUnscheduled = cms.untracked.bool(True)


process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
'/store/data/Run2016B/SingleElectron/MINIAOD/PromptReco-v2/000/273/158/00000/26868D6F-4A1A-E611-8916-02163E011D33.root',
'/store/data/Run2016B/SingleElectron/MINIAOD/PromptReco-v2/000/273/158/00000/429D71B2-1D1A-E611-A5A9-02163E013926.root' #,
#'/store/data/Run2016B/SingleElectron/MINIAOD/PromptReco-v2/000/273/158/00000/4CF12A3D-0D1A-E611-9C13-02163E011FB9.root',
#'/store/data/Run2016B/SingleElectron/MINIAOD/PromptReco-v2/000/273/158/00000/546F0CFC-131A-E611-906F-02163E013942.root',
#'/store/data/Run2016B/SingleElectron/MINIAOD/PromptReco-v2/000/273/158/00000/56DDF2F4-0F1A-E611-AD12-02163E012065.root',
#'/store/data/Run2016B/SingleElectron/MINIAOD/PromptReco-v2/000/273/158/00000/58B8145B-1E1A-E611-BBF1-02163E01262F.root',
#'/store/data/Run2016B/SingleElectron/MINIAOD/PromptReco-v2/000/273/158/00000/5A806FDD-121A-E611-AC73-02163E013929.root',
#'/store/data/Run2016B/SingleElectron/MINIAOD/PromptReco-v2/000/273/158/00000/6014DA64-0E1A-E611-BC7F-02163E011E1A.root',
#'/store/data/Run2016B/SingleElectron/MINIAOD/PromptReco-v2/000/273/158/00000/662BEDED-091A-E611-9450-02163E0125FE.root',
#'/store/data/Run2016B/SingleElectron/MINIAOD/PromptReco-v2/000/273/158/00000/689AF1F8-0B1A-E611-B9D7-02163E0139B9.root',
#'/store/data/Run2016B/SingleElectron/MINIAOD/PromptReco-v2/000/273/158/00000/6EA788B9-0A1A-E611-9786-02163E011AB8.root',
#'/store/data/Run2016B/SingleElectron/MINIAOD/PromptReco-v2/000/273/158/00000/7C4306F0-1A1A-E611-AD6A-02163E011CA6.root',
#'/store/data/Run2016B/SingleElectron/MINIAOD/PromptReco-v2/000/273/158/00000/884DDEA7-0B1A-E611-929B-02163E0127EB.root',
#'/store/data/Run2016B/SingleElectron/MINIAOD/PromptReco-v2/000/273/158/00000/8C7DE722-171A-E611-A56E-02163E012420.root',
#'/store/data/Run2016B/SingleElectron/MINIAOD/PromptReco-v2/000/273/158/00000/963C60D7-071A-E611-9A8E-02163E0142BC.root',
#'/store/data/Run2016B/SingleElectron/MINIAOD/PromptReco-v2/000/273/158/00000/98E86BEC-151A-E611-836C-02163E011E88.root',
#'/store/data/Run2016B/SingleElectron/MINIAOD/PromptReco-v2/000/273/158/00000/DC6580DF-151A-E611-8F9B-02163E011F7B.root',
#'/store/data/Run2016B/SingleElectron/MINIAOD/PromptReco-v2/000/273/158/00000/E01680AD-101A-E611-B285-02163E01373A.root',
#'/store/data/Run2016B/SingleElectron/MINIAOD/PromptReco-v2/000/273/158/00000/EE2EBA05-211A-E611-B7F6-02163E014737.root',
#'/store/data/Run2016B/SingleElectron/MINIAOD/PromptReco-v2/000/273/158/00000/F093FF0A-241A-E611-AF7A-02163E01452D.root',
#'/store/data/Run2016B/SingleElectron/MINIAOD/PromptReco-v2/000/273/158/00000/F42C53D6-081A-E611-AF0E-02163E0136B1.root'
		),
		inputCommands=cms.untracked.vstring(
						'keep *',
						'keep *_l1extraParticles_*_*',
		)
)
import FWCore.PythonUtilities.LumiList as LumiList
process.source.lumisToProcess = LumiList.LumiList(filename = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/Cert_271036-273730_13TeV_PromptReco_Collisions16_JSON.txt').getVLuminosityBlockRange()




process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

process.load("FWCore.MessageLogger.MessageLogger_cfi")


process.dump=cms.EDAnalyzer('EventContentAnalyzer')

_messageSettings = cms.untracked.PSet(
                reportEvery = cms.untracked.int32(10),
                            optionalPSet = cms.untracked.bool(True),
                            limit = cms.untracked.int32(10000000)
                        )


#added in etau and mutau triggers
from UWAnalysis.Configuration.tools.analysisToolsHTauTau_WIP import *
defaultReconstruction(process,'HLT',
                      [
			'HLT_IsoMu22_v', 
			'HLT_IsoMu24_v', 
			'HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v',
			'HLT_IsoMu19_eta2p1_LooseIsoPFTau20_v',
		        'HLT_Ele24_eta2p1_WPLoose_Gsf_v',
		        'HLT_Ele24_eta2p1_WPLoose_LooseIsoPFTau20_v',
			'HLT_Ele24_WPLoose_Gsf_v',
			'HLT_Ele23_WPLoose_Gsf_v',
			'HLT_Ele22_WPLoose_Gsf_v',
			'HLT_Ele25_eta2p1_WPLoose_Gsf_v'	
                      ])


                      

#EventSelection
process.load("UWAnalysis.Configuration.xTauTau_cff")

process.metCalibration.applyCalibration = cms.bool(False)

process.eventSelectionMT = cms.Path(process.selectionSequenceMT)
process.eventSelectionET = cms.Path(process.selectionSequenceET)

from UWAnalysis.Configuration.tools.ntupleToolsHTauTau_WIP import addMuTauEventTree
addMuTauEventTree(process,'muTauEventTree')
addMuTauEventTree(process,'muTauEventTreeFinal','muTausOS','diMuonsOSSorted')

from UWAnalysis.Configuration.tools.ntupleToolsHTauTau_WIP import addEleTauEventTree
addEleTauEventTree(process,'eleTauEventTree')
addEleTauEventTree(process,'eleTauEventTreeFinal','eleTausOS','diElectronsOSSorted')

addEventSummary(process,True,'MT','eventSelectionMT')
addEventSummary(process,True,'ET','eventSelectionET')

