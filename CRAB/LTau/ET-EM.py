import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")

process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.GlobalTag.globaltag = 'FT_53_V21_AN4::All'

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(5000)
)



process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
       '/store/user/tapas/DoubleMuParked/StoreResults-Run2012D_22Jan2013_v1_RHembedded_trans1_tau115_ptelec1_20had1_18_v1-f456bdbb960236e5c696adfe9b04eaae/USER/2013-06-11-8TeV-53X-PatTuple_Master/patTuple_cfg-FE6FF2EA-B5B0-E211-83D7-00266CFCCB44.root'
		),
		inputCommands=cms.untracked.vstring(
						'keep *',
						'drop *_finalState*_*_*',
						'drop *_patFinalStateEvent*_*_*'
		)
)


from UWAnalysis.Configuration.tools.analysisToolsPT import *
defaultReconstructionEMBET(process,'HLT',
                      [
						"HLT_Mu17_Mu8",

                      ])
                       

#EventSelection
process.load("UWAnalysis.Configuration.LepTauAnalysis_cff")

process.metCalibration.applyCalibration = cms.bool(False)

process.eventSelectionET = cms.Path(process.selectionSequenceET)


#Systematic Shifts 1sigma
process.eventSelectionETTauUp    = createSystematics(process,process.selectionSequenceET,'TauUp',1.00,1.0,1.03,0,1.0)
process.eventSelectionETTauDown  = createSystematics(process,process.selectionSequenceET,'TauDown',1.0,1.0,0.97,0,1.0)
# process.eventSelectionETEleUp    = createSystematics(process,process.selectionSequenceET,'EleUp',1.01,1.0,1.03,0,1.0)
# process.eventSelectionETEleDown  = createSystematics(process,process.selectionSequenceET,'EleDown',0.99,1.0,0.97,0,1.0)


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





from UWAnalysis.Configuration.tools.ntupleToolsLTau import addEleTauEventTree
addEleTauEventTree(process,'eleTauEventTree')
addEleTauEventTree(process,'eleTauEventTreeFinal','eleTausOS','osDiElectrons')

addEventSummary(process,True,'ET','eventSelectionET')


addEleTauEventTree(process,'eleTauEventTreeTauUp','eleTausSortedTauUp','osDiElectronsTauUp')
addEleTauEventTree(process,'eleTauEventTreeTauDown','eleTausSortedTauDown','osDiElectronsTauDown')
addEleTauEventTree(process,'eleTauEventTreeFinalTauUp','eleTausOSTauUp','osDiElectronsTauUp')
addEleTauEventTree(process,'eleTauEventTreeFinalTauDown','eleTausOSTauDown','osDiElectronsTauDown')
