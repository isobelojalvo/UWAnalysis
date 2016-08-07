import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')

process.GlobalTag.globaltag = '80X_mcRun2_asymptotic_2016_miniAODv2_v1'



#process.options   = cms.untracked.PSet(wantSummary = cms.untracked.bool(True))
process.options   = cms.untracked.PSet(wantSummary = cms.untracked.bool(True))
process.options.allowUnscheduled = cms.untracked.bool(True)


process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)


# Make the framework shut up.
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 100


process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
#'file:tester.root'
'/store/mc/RunIISpring16MiniAODv2/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-400_13TeV-madgraph/MINIAODSIM/PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/20000/20EC6D85-8D3A-E611-BB26-0025905B85DE.root'
		),
		inputCommands=cms.untracked.vstring(
						'keep *',
						'keep *_l1extraParticles_*_*',
		)
)

#process.dump=cms.EDAnalyzer('EventContentAnalyzer')


#added in etau and mutau triggers
from UWAnalysis.Configuration.tools.analysisToolsHTauTau_WIP import *
defaultReconstructionMC(process,'HLT2',
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

createGeneratedParticles(process,
                         'genDaughters',
                          [
                           "keep++ pdgId = {Z0}",
                           "keep pdgId = {tau+}",
                           "keep pdgId = {tau-}",
                           "keep pdgId = {mu+}",
                           "keep pdgId = {mu-}",
                           "keep pdgId = 6",
                           "keep pdgId = -6",
                           "keep pdgId = 11",
                           "keep pdgId = -11",
                           "keep pdgId = 25",
                           "keep pdgId = 35",
                           "keep pdgId = 37",
                           "keep pdgId = 36"
                          ]
)


createGeneratedParticles(process,
                         'genTauCands',
                          [
                           "keep pdgId = {tau+} & mother.pdgId()= {Z0}",
                           "keep pdgId = {tau-} & mother.pdgId() = {Z0}"
                          ]
)


from UWAnalysis.Configuration.tools.ntupleToolsHTauTau_WIP import addMuTauEventTree
addMuTauEventTree(process,'muTauEventTree')
addMuTauEventTree(process,'muTauEventTreeFinal','muTausOS','diMuonsOSSorted')

from UWAnalysis.Configuration.tools.ntupleToolsHTauTau_WIP import addEleTauEventTree
addEleTauEventTree(process,'eleTauEventTree')
addEleTauEventTree(process,'eleTauEventTreeFinal','eleTausOS','diElectronsOSSorted')

addEventSummary(process,True,'MT','eventSelectionMT')
addEventSummary(process,True,'ET','eventSelectionET')

