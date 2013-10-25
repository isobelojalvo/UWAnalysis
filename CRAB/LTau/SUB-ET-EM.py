import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")

process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.GlobalTag.globaltag = 'FT_53_V21_AN4::All'



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
addEleTauEventTree(process,'eleTauEventTree','eleTausLooseIsolation','osDiElectrons')
#addEleTauEventTree(process,'eleTauEventTreeFinal','eleTausOS','osDiElectrons')

addEventSummary(process,True,'ET','eventSelectionET')


addEleTauEventTree(process,'eleTauEventTreeTauUp','eleTausLooseIsolationTauUp','osDiElectronsTauUp')
addEleTauEventTree(process,'eleTauEventTreeTauDown','eleTausLooseIsolationTauDown','osDiElectronsTauDown')
#addEleTauEventTree(process,'eleTauEventTreeFinalTauUp','eleTausOSTauUp','osDiElectronsTauUp')
#addEleTauEventTree(process,'eleTauEventTreeFinalTauDown','eleTausOSTauDown','osDiElectronsTauDown')


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

