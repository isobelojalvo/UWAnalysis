import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')

process.GlobalTag.globaltag = '80X_mcRun2_asymptotic_2016_TrancheIV_v7'

process.options   = cms.untracked.PSet(wantSummary = cms.untracked.bool(False))
process.options.allowUnscheduled = cms.untracked.bool(True)

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(20000)
)



process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        'file:vbf125-missing.root'
        #'file:VBF_11_events_for_you.root'
        #'root://cmsxrootd.hep.wisc.edu//store/mc/RunIISummer16MiniAODv2/VBFHToTauTau_M125_13TeV_powheg_pythia8/MINIAODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/120000/D662E4EE-8DC8-E611-91C3-008CFA00317C.root'
        #'/store/mc/RunIISpring16MiniAODv1/GluGluHToTauTau_M125_13TeV_powheg_pythia8/MINIAODSIM/PUSpring16_80X_mcRun2_asymptotic_2016_v3-v1/10000/06A0B340-8025-E611-8262-B8CA3A708F98.root'
		),
		inputCommands=cms.untracked.vstring(
						'keep *',
						'keep *_l1extraParticles_*_*',
		)
)


from UWAnalysis.Configuration.tools.analysisToolsHTauTau_WIP import *
defaultReconstructionMC(process,'HLT',
                      [
			'HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_Reg_v',
                        'HLT_DoubleMediumCombinedIsoPFTau35_Trk1_eta2p1_Reg_v'
                      ])


#EventSelection
process.load("UWAnalysis.Configuration.hTauTauHadronicEmu_cff")


process.eventSelectionTT = cms.Path(process.selectionSequenceTT)
createGeneratedParticles(process,
                         'genDaughters',
                          [
                           "keep++ pdgId = {Z0}",
                           "keep pdgId = {tau+}",
                           "keep pdgId = {tau-}",
#                           "keep pdgId = {mu+}",
#                           "keep pdgId = {mu-}",
                           "keep pdgId = 6",
                           "keep pdgId = -6",
                           "keep pdgId = 11",
                           "keep pdgId = -11",
                           "keep pdgId = 25",
                           "keep pdgId = 35",
                           "keep abs(pdgId) = 36"
                          ]
)


createGeneratedParticles(process,
                         'genTauCands',
                          [
                           "keep pdgId = {tau+} ",
                           "keep pdgId = {tau-} "
                          ]
)


from UWAnalysis.Configuration.tools.ntupleToolsHTauTau_WIP import addDiTauEventTree

addDiTauEventTree(process,'diTauEventTree','diTausSync',triggerCollection='HLT')
addDiTauEventTree(process,'diTauEventTreeFinal','diTausSortedFinal',triggerCollection='HLT')

addEventSummary(process,True,'TT','eventSelectionTT')

#Systematic Shifts 1sigma
### mu, ele, tau, jet, unc, elecResb, elecRese, 1p, 1pPi0, 3p
### process,sequence,postfix, muScale, eScale, tauScale, jetScale, unclusteredScale, electronresb = 0.0, electronrese = 0.0, oneProngScale = 1.0,oneProngPi0Scale = 1.0, threeProngScale = 1.0
### mu, ele, tau, jet, unc, elecResb, elecRese, 1p, 1pPi0, 3p
process.eventSelectionTTTauUp  = createSystematics(process,process.selectionSequenceTT,'TauUp'  ,1.00, 1.00, 1.00, 0, 1.00, 0.00, 0.00, 0.988, 1.016, 1.01)
process.eventSelectionTTauDown = createSystematics(process,process.selectionSequenceTT,'TauDown',1.00, 1.00, 0.97, 0, 1.00, 0.00, 0.00, 0.976, 1.004, 0.98)
process.eventSelectionTTJetUp  = createSystematics(process,process.selectionSequenceTT,'JetUp'  ,1.00, 1.00, 1.00, 1, 1.00, 0.00, 0.00, 1.00,  1.00, 1.00)
process.eventSelectionTTJetDown= createSystematics(process,process.selectionSequenceTT,'JetDown',1.00, 1.00, 1.00,-1, 1.00, 0.00, 0.00, 1.00, 1.00, 1.00)

addDiTauEventTree(process,'diTauEventTreeTauUp','diTausSyncTauUp',triggerCollection='HLT')
addDiTauEventTree(process,'diTauEventTreeTauDown','diTausSyncTauDown',triggerCollection='HLT')
addDiTauEventTree(process,'diTauEventTreeJetUp','diTausSyncJetUp',triggerCollection='HLT')
addDiTauEventTree(process,'diTauEventTreeJetDown','diTausSyncJetDown',triggerCollection='HLT')


