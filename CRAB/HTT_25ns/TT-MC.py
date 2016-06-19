import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')

process.GlobalTag.globaltag = '76X_mcRun2_asymptotic_v12'


process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(20000)
)



process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
'file:/data/ojalvo/RAW-MINI-FILES/1prongTaus-RAW-MINI.root'
		),
		inputCommands=cms.untracked.vstring(
						'keep *',
						'keep *_l1extraParticles_*_*',
		)
)


#from UWAnalysis.Configuration.tools.analysisToolsZTauTauXSec import *
from UWAnalysis.Configuration.tools.analysisToolsHTauTauSync import *
defaultReconstructionMC(process,'HLT',
                      [
			'HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_Reg_v2',#tauTau
                      ])


                      

#EventSelection
process.load("UWAnalysis.Configuration.hTauTauHadronicEmu_cff")

#process.metCalibration.applyCalibration = cms.bool(False)

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


from UWAnalysis.Configuration.tools.ntupleToolsZTauTauXSec import addDiTauEventTree
addDiTauEventTree(process,'diTauEventTree')

addEventSummary(process,True,'TT','eventSelectionTT')

#Systematic Shifts 1sigma
process.eventSelectionTTTauUp    = createSystematics(process,process.selectionSequenceTT,'TauUp',1.00,1.0,1.03,0,1.0)
process.eventSelectionTTauDown  = createSystematics(process,process.selectionSequenceTT,'TauDown',1.0,1.0,0.97,0,1.0)
process.eventSelectionTTJetUp    = createSystematics(process,process.selectionSequenceTT,'JetUp',1.0,1.0,1.0,1,1.0)
process.eventSelectionTTJetDown  = createSystematics(process,process.selectionSequenceTT,'JetDown',1.0,1.0,1.0,-1,1.0)

