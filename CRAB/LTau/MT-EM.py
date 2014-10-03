import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")

process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.GlobalTag.globaltag = 'FT_53_V21_AN4::All'



process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(2000)
)

#process.load("UWAnalysis/Configuration/json_cfi")
#import FWCore.PythonUtilities.LumiList as LumiList


process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
    #'/store/user/swanson/DoubleMu/StoreResults-Run2012A_22Jan2013_v1_PFembedded_trans1_tau116_ptmu1_16had1_18_v1-5ef1c0fd428eb740081f19333520fdc8/USER/PFEmbedded/patTuple_cfg-940DDD5F-A3E4-E211-BD84-0023AEFDEBD4.root'
    'file:pick.root'
		),
		inputCommands=cms.untracked.vstring(
						'keep *',
						'drop *_finalState*_*_*',
						'drop *_patFinalStateEvent*_*_*'
		)
)


from UWAnalysis.Configuration.tools.analysisToolsPT import *
defaultReconstructionEMBMT(process,'HLT',
                      [
						"HLT_Mu17_Mu8"
                      ])

                      
#EventSelection
process.load("UWAnalysis.Configuration.LepTauAnalysis_cff")

process.metCalibration.applyCalibration = cms.bool(False)

process.eventSelectionMT = cms.Path(process.selectionSequenceMT)


#Systematic Shifts 1sigma
process.eventSelectionMTTauUp    = createSystematics(process,process.selectionSequenceMT,'TauUp',1.00,1.0,1.03,0,1.0)
process.eventSelectionMTTauDown  = createSystematics(process,process.selectionSequenceMT,'TauDown',1.0,1.0,0.97,0,1.0)
# process.eventSelectionMTJetUp    = createSystematics(process,process.selectionSequenceMT,'JetUp',1.00,1.0,1.0,1,1.0)
# process.eventSelectionMTJetDown  = createSystematics(process,process.selectionSequenceMT,'JetDown',1.0,1.0,1.0,-1,1.0)
# process.eventSelectionMTUncUp    = createSystematics(process,process.selectionSequenceMT,'UncUp',1.00,1.0,1.0,0,1.1)
# process.eventSelectionMTUncDown  = createSystematics(process,process.selectionSequenceMT,'UncDown',1.0,1.0,1.0,0,0.9)


createGeneratedParticles(process,
                         'genDaughters',
                          [
                           "keep++ pdgId = {Z0}",
                           "keep pdgId = 15",
                           "keep pdgId = -15",
                           "keep pdgId = 25",
                           "keep pdgId = 35",
                           "keep abs(pdgId) = 36"                           
                          ]
)


from UWAnalysis.Configuration.tools.ntupleToolsLTau import addMuTauEventTree
addMuTauEventTree(process,'muTauEventTree','diTausLooseTauIsolation','diMuonsSorted')
#addMuTauEventTree(process,'muTauEventTreeFinal','diTausLooseTauIsolation','diMuonsSorted')

addEventSummary(process,True,'MT','eventSelectionMT')


#Final trees afor shapes after shifts
addMuTauEventTree(process,'muTauEventTreeTauUp','diTausLooseTauIsolationTauUp','diMuonsSortedTauUp')
addMuTauEventTree(process,'muTauEventTreeTauDown','diTausLooseTauIsolationTauDown','diMuonsSortedTauDown')
#addMuTauEventTree(process,'muTauEventTreeFinalTauUp','diTausOSTauUp','diMuonsSortedTauUp')
#addMuTauEventTree(process,'muTauEventTreeFinalTauDown','diTausOSTauDown','diMuonsSortedTauDown')






