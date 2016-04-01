import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')

process.GlobalTag.globaltag = '76X_mcRun2_asymptotic_RunIIFall15DR76_v1'


process.options   = cms.untracked.PSet(wantSummary = cms.untracked.bool(True))
process.options.allowUnscheduled = cms.untracked.bool(True)

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(30)
)



process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
'/store/mc/RunIIFall15MiniAODv2/SUSYGluGluToHToTauTau_M-160_TuneCUETP8M1_13TeV-pythia8/MINIAODSIM/PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/60000/98ACE26B-05BC-E511-8AA4-001EC9ADCD7A.root'
#'/store/mc/RunIIFall15MiniAODv2/SUSYGluGluToBBHToTauTau_M-160_TuneCUETP8M1_13TeV-pythia8/MINIAODSIM/PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/10000/0228BA78-4EB8-E511-9B0D-003048F3511E.root'
#'/store/mc/RunIIFall15MiniAODv2/SUSYGluGluToHToTauTau_M-160_TuneCUETP8M1_13TeV-pythia8/MINIAODSIM/PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/50000/B2FF8F77-3DB8-E511-B743-001E6757F1D4.root'
#'file:/hdfs/store/mc/RunIIFall15MiniAODv2/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/MINIAODSIM/PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/70000/C0BD1DB7-D5B8-E511-A52D-0025907253B6.root'
     
		),
		#firstEvent=cms.untracked.uint32(0),
		inputCommands=cms.untracked.vstring(
						'keep *',
						'keep *_l1extraParticles_*_*',
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
#process.recoildCorrections.applyCorrectinos = cms.bool(True)

process.eventSelectionMT = cms.Path(process.selectionSequenceMT)
#process.eventSelectionET = cms.Path(process.selectionSequenceET)

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

#from UWAnalysis.Configuration.tools.ntupleToolsSync import addEleTauEventTree
#addEleTauEventTree(process,'eleTauEventTree')

addEventSummary(process,True,'MT','eventSelectionMT')
#addEventSummary(process,True,'ET','eventSelectionET')

dump_file = open('dump.py','w')
dump_file.write(process.dumpPython())
