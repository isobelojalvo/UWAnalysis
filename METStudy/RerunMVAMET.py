import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')

process.GlobalTag.globaltag = '76X_mcRun2_asymptotic_v13'



#added in etau and mutau triggers
#from UWAnalysis.Configuration.tools.analysisToolsZTauTauXSec import *
from UWAnalysis.Configuration.tools.analysisToolsHTauTau_WIP import *
defaultReconstructionMC(process,'HLT',
                      [
			'HLT_Ele22_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_v1',#etau
			'HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v2',#muTau
			'HLT_IsoMu18_v2',#singlemu
			'HLT_Ele22_eta2p1_WPLoose_Gsf_v3',#singleE
			'HLT_Ele23_WPLoose_Gsf_v2'#singleE
                      ])


                      

#EventSelection
process.load("UWAnalysis.Configuration.hTauTauSync_cff")

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
			 "keep pdgId = {tau+} & mother.pdgId()= {Z0}",
			 "keep pdgId = {tau+} & mother.pdgId()= {Z0}"
			 ]				 
			)

from UWAnalysis.Configuration.tools.ntupleToolsHTauTau_WIP import addMuTauEventTree
addMuTauEventTree(process,'muTauEventTree')

from UWAnalysis.Configuration.tools.ntupleToolsHTauTau_WIP import addEleTauEventTree
addEleTauEventTree(process,'eleTauEventTree')

addEventSummary(process,True,'MT','eventSelectionMT')
addEventSummary(process,True,'ET','eventSelectionET')

#Systematic Shifts 1sigma
process.eventSelectionMTTauUp    = createSystematics(process,process.selectionSequenceMT,'TauUp',1.0,1.0,1.03,0,1.0)
process.eventSelectionMTTauDown  = createSystematics(process,process.selectionSequenceMT,'TauDown',1.0,1.0,0.97,0,1.0)
process.eventSelectionMTJetUp    = createSystematics(process,process.selectionSequenceMT,'JetUp',1.0,1.0,1.0,1,1.0)
process.eventSelectionMTJetDown  = createSystematics(process,process.selectionSequenceMT,'JetDown',1.0,1.0,1.0,-1,1.0)

process.eventSelectionETTauUp    = createSystematics(process,process.selectionSequenceET,'TauUp',1.00,1.0,1.03,0,1.0)
process.eventSelectionETTauDown  = createSystematics(process,process.selectionSequenceET,'TauDown',1.0,1.0,0.97,0,1.0)
process.eventSelectionETJetUp    = createSystematics(process,process.selectionSequenceET,'JetUp',1.0,1.0,1.0,1,1.0)
process.eventSelectionETJetDown  = createSystematics(process,process.selectionSequenceET,'JetDown',1.0,1.0,1.0,-1,1.0)




#Final trees afor shapes after shifts
addMuTauEventTree(process,'muTauEventTreeTauUp','muTausSortedTauUp','osDiMuonsTauUp')
addMuTauEventTree(process,'muTauEventTreeTauDown','muTausSortedTauDown','osDiMuonsTauDown')
addMuTauEventTree(process,'muTauEventTreeJetUp','muTausSortedJetUp','osDiMuonsJetUp')
addMuTauEventTree(process,'muTauEventTreeJetDown','muTausSortedJetDown','osDiMuonsJetDown')

addEleTauEventTree(process,'eleTauEventTreeTauUp','eleTausSortedTauUp','osDiElectronsTauUp')
addEleTauEventTree(process,'eleTauEventTreeTauDown','eleTausSortedTauDown','osDiElectronsTauDown')
addEleTauEventTree(process,'eleTauEventTreeJetUp','eleTausSortedJetUp','osDiElectronsJetUp')
addEleTauEventTree(process,'eleTauEventTreeJetDown','eleTausSortedJetDown','osDiElectronsJetDown')

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
       $inputFileNames
		),
		inputCommands=cms.untracked.vstring(
						'keep *',
		)
)

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

#process.TFileService.fileName=cms.string("$outputFileName")
process.TFileService = cms.Service(
    "TFileService",
    fileName = cms.string("$outputFileName")
)
