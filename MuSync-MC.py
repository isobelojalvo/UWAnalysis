import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')

process.GlobalTag.globaltag = '76X_mcRun2_asymptotic_v13'


process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(1000)
)



process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
'/store/mc/RunIIFall15MiniAODv2/SUSYGluGluToHToTauTau_M-160_TuneCUETP8M1_13TeV-pythia8/MINIAODSIM/PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/50000/B2FF8F77-3DB8-E511-B743-001E6757F1D4.root'
#'file:/hdfs/store/mc/RunIIFall15MiniAODv2/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/MINIAODSIM/PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/70000/C0BD1DB7-D5B8-E511-A52D-0025907253B6.root'
     
		),
		inputCommands=cms.untracked.vstring(
						'keep *',
		)
)


#added in etau and mutau triggers
#from UWAnalysis.Configuration.tools.analysisToolsZTauTauXSec import *
from UWAnalysis.Configuration.tools.analysisToolsHTauTauSync import *
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

from UWAnalysis.Configuration.tools.ntupleToolsSync import addMuTauEventTree
addMuTauEventTree(process,'muTauEventTree')


addEventSummary(process,True,'MT','eventSelectionMT')

#Systematic Shifts 1sigma
process.eventSelectionMTTauUp    = createSystematics(process,process.selectionSequenceMT,'TauUp',1.0,1.0,1.03,0,1.0)
process.eventSelectionMTTauDown  = createSystematics(process,process.selectionSequenceMT,'TauDown',1.0,1.0,0.97,0,1.0)
process.eventSelectionMTJetUp    = createSystematics(process,process.selectionSequenceMT,'JetUp',1.0,1.0,1.0,1,1.0)
process.eventSelectionMTJetDown  = createSystematics(process,process.selectionSequenceMT,'JetDown',1.0,1.0,1.0,-1,1.0)





#Final trees afor shapes after shifts
#addMuTauEventTree(process,'muTauEventTreeTauUp','muTausSortedTauUp','osDiMuonsTauUp')
#addMuTauEventTree(process,'muTauEventTreeTauDown','muTausSortedTauDown','osDiMuonsTauDown')
#addMuTauEventTree(process,'muTauEventTreeFinalTauUp','muTausOSTauUp','osDiMuonsTauUp')
#addMuTauEventTree(process,'muTauEventTreeFinalTauDown','muTausOSTauDown','osDiMuonsTauDown')
#addMuTauEventTree(process,'muTauEventTreeJetUp','muTausSortedJetUp','osDiMuonsJetUp')
#addMuTauEventTree(process,'muTauEventTreeJetDown','muTausSortedJetDown','osDiMuonsJetDown')
#addMuTauEventTree(process,'muTauEventTreeFinalJetUp','muTausOSJetUp','osDiMuonsJetUp')
#addMuTauEventTree(process,'muTauEventTreeFinalJetDown','muTausOSJetDown','osDiMuonsJetDown')

#addEleTauEventTree(process,'eleTauEventTreeTauUp','eleTausSortedTauUp','osDiElectronsTauUp')
#addEleTauEventTree(process,'eleTauEventTreeTauDown','eleTausSortedTauDown','osDiElectronsTauDown')
#addEleTauEventTree(process,'eleTauEventTreeFinalTauUp','eleTausOSTauUp','osDiElectronsTauUp')
#addEleTauEventTree(process,'eleTauEventTreeFinalTauDown','eleTausOSTauDown','osDiElectronsTauDown')
#addEleTauEventTree(process,'eleTauEventTreeJetUp','eleTausSortedJetUp','osDiElectronsJetUp')
#addEleTauEventTree(process,'eleTauEventTreeJetDown','eleTausSortedJetDown','osDiElectronsJetDown')
#addEleTauEventTree(process,'eleTauEventTreeFinalJetUp','eleTausOSJetUp','osDiElectronsJetUp')
#addEleTauEventTree(process,'eleTauEventTreeFinalJetDown','eleTausOSJetDown','osDiElectronsJetDown')

#
