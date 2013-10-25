import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")

process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.GlobalTag.globaltag = 'GR_P_V42_AN3::All'

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(1000)
)



process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
       'file:/hdfs/store/user/swanson/DoubleMu/StoreResults-DoubleMu_2012D_PromptReco_v1_embedded_trans1_tau116_ptmu1_13had1_17_v1-f456bdbb960236e5c696adfe9b04eaae/USER/2012DEmbFarmout/patTuple_cfg-FEEBE829-EE4E-E211-9AF5-008CFA064858.root'
		),
		inputCommands=cms.untracked.vstring(
						'keep *',
						'drop *_finalState*_*_*',
						'drop *_patFinalStateEvent*_*_*'
		)
)


from UWAnalysis.Configuration.tools.analysisToolsPT import *
defaultReconstructionEMB(process,'EmbeddedRECO',
                      [
						"HLT_IsoMu18_eta2p1_LooseIsoPFTau20",
						"HLT_IsoMu15_eta2p1_L1ETM20"
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
                           "keep pdgId = 15",
                           "keep pdgId = -15"
                          ]
)


from UWAnalysis.Configuration.tools.ntupleToolsLTau import addMuTauEventTree
addMuTauEventTree(process,'muTauEventTree')
addMuTauEventTree(process,'muTauEventTreeFinal','diTausLooseTauIsolation','diMuonsSorted')

addEventSummary(process,True,'MT','eventSelectionMT')



#Final trees afor shapes after shifts
addMuTauEventTree(process,'muTauEventTreeTauUp','diTausSortedTauUp','diMuonsSortedTauUp')
addMuTauEventTree(process,'muTauEventTreeTauDown','diTausSortedTauDown','diMuonsSortedTauDown')
addMuTauEventTree(process,'muTauEventTreeSyncTauUp','diTausOSTauUp','diMuonsSortedTauUp')
addMuTauEventTree(process,'muTauEventTreeSyncTauDown','diTausOSTauDown','diMuonsSortedTauDown')
# addMuTauEventTree(process,'muTauEventTreeJetUp','diTausTauMuonVetoJetUp','diMuonsSortedJetUp')
# addMuTauEventTree(process,'muTauEventTreeJetDown','diTausTauMuonVetoJetDown','diMuonsSortedJetDown')
# addMuTauEventTree(process,'muTauEventTreeUncUp','diTausTauMuonVetoUncUp','diMuonsSortedUncUp')
# addMuTauEventTree(process,'muTauEventTreeUncDown','diTausTauMuonVetoUncDown','diMuonsSortedUncDown')
