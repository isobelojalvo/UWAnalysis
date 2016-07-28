import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')


process.GlobalTag.globaltag = '80X_dataRun2_Prompt_ICHEP16JEC_v0'
#process.GlobalTag.globaltag = '80X_dataRun2_Prompt_v9'


process.options   = cms.untracked.PSet(wantSummary = cms.untracked.bool(True))
process.options.allowUnscheduled = cms.untracked.bool(True)



process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
		$inputFileNames
		),
		inputCommands=cms.untracked.vstring(
						'keep *',
		)
)

import FWCore.PythonUtilities.LumiList as LumiList
process.source.lumisToProcess = LumiList.LumiList(filename = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/Cert_271036-276811_13TeV_PromptReco_Collisions16_JSON.txt').getVLuminosityBlockRange()


process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)


#added in etau and mutau triggers
from UWAnalysis.Configuration.tools.analysisToolsHTauTau_WIP import *
defaultReconstruction(process,'HLT',
                      [
			'HLT_IsoMu18_v', 
			'HLT_IsoMu20_v', 
			'HLT_IsoMu22_v', 
			'HLT_IsoMu22_eta2p1_v', 
			'HLT_IsoMu24_v', 
			'HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v',
			'HLT_IsoMu17_eta2p1_LooseIsoPFTau20_SingleL1_v',
			'HLT_IsoMu19_eta2p1_LooseIsoPFTau20_v',
			'HLT_IsoMu19_eta2p1_LooseIsoPFTau20_SingleL1_v',
			'HLT_IsoMu21_eta2p1_LooseIsoPFTau20_SingleL1_v',
		        'HLT_Ele22_eta2p1_WPLoose_LooseIsoPFTau20_v',
		        'HLT_Ele22_eta2p1_WPLoose_LooseIsoPFTau20_SingleL1_v',
			'HLT_Ele23_WPLoose_Gsf_v',
		        'HLT_Ele24_eta2p1_WPLoose_Gsf_v',
		        'HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_v',
		        'HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_SingleL1_v',
			'HLT_Ele24_WPLoose_Gsf_v',
			'HLT_Ele25_eta2p1_WPLoose_Gsf_v',
			'HLT_Ele25_eta2p1_WPTight_Gsf_v',	
			'HLT_Ele27_WPLoose_Gsf_v',
			'HLT_Ele27_WPTight_Gsf_v',
			'HLT_Ele27_eta2p1_WPLoose_Gsf_v',
			'HLT_Ele27_eta2p1_WPTight_Gsf_v',
			'HLT_VLooseIsoPFTau140_Trk50_eta2p1_v',
			'HLT_VLooseIsoPFTau120_Trk50_eta2p1_v',
			'HLT_PFMET170_NoiseCleaned',
			'HLT_PFMET90_PFMHT90_IDTight',
			'HLT_CaloJet500_NoJetID',
			'HLT_ECALHT800'
			])



#EventSelection
process.load("UWAnalysis.Configuration.hTauTau_cff")

process.metCalibration.applyCalibration = cms.bool(False)

process.eventSelectionMT = cms.Path(process.selectionSequenceMT)
process.eventSelectionET = cms.Path(process.selectionSequenceET)


from UWAnalysis.Configuration.tools.ntupleToolsHTauTau_WIP import addMuTauEventTree
addMuTauEventTree(process,'muTauEventTree')
addMuTauEventTree(process,'muTauEventTreeFinal','muTausOS','diMuonsOSSorted')


from UWAnalysis.Configuration.tools.ntupleToolsHTauTau_WIP import addEleTauEventTree
addEleTauEventTree(process,'eleTauEventTree')
addEleTauEventTree(process,'eleTauEventTreeFinal','eleTausOS','diElectronsOSSorted')

addEventSummary(process,False,'MT','eventSelectionMT')
addEventSummary(process,False,'ET','eventSelectionET')


process.TFileService.fileName=cms.string("$outputFileName")

