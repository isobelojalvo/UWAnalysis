import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")

process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.GlobalTag.globaltag = 'START53_V22::All'



from UWAnalysis.Configuration.tools.analysisToolsPT import *
defaultReconstructionMC(process,'HLT',
                      [
						"HLT_Ele22_eta2p1_WP90Rho_LooseIsoPFTau20",
						"HLT_IsoMu17_eta2p1_LooseIsoPFTau20",
						"HLT_IsoMu15_eta2p1_L1ETM20"
                      ])

                    
#EventSelection
process.load("UWAnalysis.Configuration.LepTauAnalysis_cff")

process.metCalibration.applyCalibration = cms.bool(True)
process.metCalibration.calibrationScheme = cms.string("Phil_Z")


process.eventSelectionMT = cms.Path(process.selectionSequenceMT)
process.eventSelectionET = cms.Path(process.selectionSequenceET)


#Systematic Shifts 1sigma
# process.eventSelectionMTTauUp    = createSystematics(process,process.selectionSequenceMT,'TauUp',1.0,1.0,1.03,0,1.0)
# process.eventSelectionMTTauDown  = createSystematics(process,process.selectionSequenceMT,'TauDown',1.0,1.0,0.97,0,1.0)
# process.eventSelectionMTJetUp    = createSystematics(process,process.selectionSequenceMT,'JetUp',1.0,1.0,1.0,1,1.0)
# process.eventSelectionMTJetDown  = createSystematics(process,process.selectionSequenceMT,'JetDown',1.0,1.0,1.0,-1,1.0)
# process.eventSelectionMTUncUp    = createSystematics(process,process.selectionSequenceMT,'UncUp',1.00,1.0,1.0,0,1.1)
# process.eventSelectionMTUncDown  = createSystematics(process,process.selectionSequenceMT,'UncDown',1.0,1.0,1.0,0,0.9)

# process.eventSelectionETTauUp    = createSystematics(process,process.selectionSequenceET,'TauUp',1.00,1.0,1.03,0,1.0)
# process.eventSelectionETTauDown  = createSystematics(process,process.selectionSequenceET,'TauDown',1.0,1.0,0.97,0,1.0)
# process.eventSelectionETJetUp    = createSystematics(process,process.selectionSequenceET,'JetUp',1.0,1.0,1.0,1,1.0)
# process.eventSelectionETJetDown  = createSystematics(process,process.selectionSequenceET,'JetDown',1.0,1.0,1.0,-1,1.0)
# process.eventSelectionETEleUp    = createSystematics(process,process.selectionSequenceET,'EleUp',1.01,1.0,1.03,0,1.0)
# process.eventSelectionETEleDown  = createSystematics(process,process.selectionSequenceET,'EleDown',0.99,1.0,0.97,0,1.0)


createGeneratedParticles(process,
                         'genDaughters',
                          [
                           "keep++ pdgId = {Z0}",
                           "keep pdgId = {tau+}",
                           "keep pdgId = {tau-}",
                           "keep pdgId = {mu+}",
                           "keep pdgId = {mu-}",
                           "keep pdgId = 11",
                           "keep pdgId = -11"
                          ]
)


createGeneratedParticles(process,
                         'genTauCands',
                          [
                           "keep pdgId = {tau+} & mother.pdgId()= {Z0}",
                           "keep pdgId = {tau-} & mother.pdgId() = {Z0}"
                          ]
)


from UWAnalysis.Configuration.tools.ntupleToolsLTau import addMuTauEventTree
addMuTauEventTree(process,'muTauEventTree')
addMuTauEventTree(process,'muTauEventTreeFinal','diTausOS','diMuonsSorted')

from UWAnalysis.Configuration.tools.ntupleToolsLTau import addEleTauEventTree
addEleTauEventTree(process,'eleTauEventTree')
addEleTauEventTree(process,'eleTauEventTreeFinal','eleTausOS','osDiElectrons')

addEventSummary(process,True,'MT','eventSelectionMT')
addEventSummary(process,True,'ET','eventSelectionET')


#Final trees afor shapes after shifts
# addMuTauEventTree(process,'muTauEventTreeTauUp','diTausSortedTauUp','diMuonsSortedTauUp')
# addMuTauEventTree(process,'muTauEventTreeTauDown','diTausSortedTauDown','diMuonsSortedTauDown')
# addMuTauEventTree(process,'muTauEventTreeFinalTauUp','diTausOSTauUp','diMuonsSortedTauUp')
# addMuTauEventTree(process,'muTauEventTreeFinalTauDown','diTausOSTauDown','diMuonsSortedTauDown')
# addMuTauEventTree(process,'muTauEventTreeJetUp','diTausSortedJetUp','diMuonsSortedJetUp')
# addMuTauEventTree(process,'muTauEventTreeJetDown','diTausSortedJetDown','diMuonsSortedJetDown')
# addMuTauEventTree(process,'muTauEventTreeFinalJetUp','diTausOSJetUp','diMuonsSortedJetUp')
# addMuTauEventTree(process,'muTauEventTreeFinalJetDown','diTausOSJetDown','diMuonsSortedJetDown')

# addEleTauEventTree(process,'eleTauEventTreeTauUp','eleTausSortedTauUp','osDiElectronsTauUp')
# addEleTauEventTree(process,'eleTauEventTreeTauDown','eleTausSortedTauDown','osDiElectronsTauDown')
# addEleTauEventTree(process,'eleTauEventTreeFinalTauUp','eleTausOSTauUp','osDiElectronsTauUp')
# addEleTauEventTree(process,'eleTauEventTreeFinalTauDown','eleTausOSTauDown','osDiElectronsTauDown')
# addEleTauEventTree(process,'eleTauEventTreeJetUp','eleTausSortedJetUp','osDiElectronsJetUp')
# addEleTauEventTree(process,'eleTauEventTreeJetDown','eleTausSortedJetDown','osDiElectronsJetDown')
# addEleTauEventTree(process,'eleTauEventTreeFinalJetUp','eleTausOSJetUp','osDiElectronsJetUp')
# addEleTauEventTree(process,'eleTauEventTreeFinalJetDown','eleTausOSJetDown','osDiElectronsJetDown')


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

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

process.TFileService.fileName=cms.string("$outputFileName")


