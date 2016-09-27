import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')

process.GlobalTag.globaltag = '80X_mcRun2_asymptotic_2016_miniAODv2_v1'


process.options   = cms.untracked.PSet(wantSummary = cms.untracked.bool(True))
process.options.allowUnscheduled = cms.untracked.bool(True)

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(10000)
)



process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
'/store/mc/RunIISpring16MiniAODv2/SUSYGluGluToHToTauTau_M-160_TuneCUETP8M1_13TeV-pythia8/MINIAODSIM/PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/90000/66445A95-3151-E611-AA07-0090FAA579F0.root'
		),
		inputCommands=cms.untracked.vstring(
						'keep *',
						'keep *_l1extraParticles_*_*',
		)
)


#added in etau and mutau triggers
from UWAnalysis.Configuration.tools.analysisToolsHTauTauSync import *
defaultReconstructionMC(process,'HLT2',
                      [
			'HLT_Ele22_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_v1',#etau
			'HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v2',#muTau
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

from UWAnalysis.Configuration.tools.ntupleToolsSync import addMuTauEventTree
addMuTauEventTree(process,'muTauEventTree')

from UWAnalysis.Configuration.tools.ntupleToolsSync import addEleTauEventTree
addEleTauEventTree(process,'eleTauEventTree')

addEventSummary(process,True,'MT','eventSelectionMT')
addEventSummary(process,True,'ET','eventSelectionET')

dump_file = open('dump.py','w')
dump_file.write(process.dumpPython())
