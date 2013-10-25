import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")

process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.GlobalTag.globaltag = 'FT_53_V21_AN4::All'


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


process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

import FWCore.PythonUtilities.LumiList as LumiList


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

process.source.lumisToProcess = LumiList.LumiList(filename = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions12/8TeV/Reprocessing/Cert_190456-208686_8TeV_22Jan2013ReReco_Collisions12_JSON.txt').getVLuminosityBlockRange()


process.TFileService.fileName=cms.string("$outputFileName")

