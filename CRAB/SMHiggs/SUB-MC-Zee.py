import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')

process.GlobalTag.globaltag = '80X_mcRun2_asymptotic_2016_miniAODv2_v1'


process.options   = cms.untracked.PSet(wantSummary = cms.untracked.bool(False))
process.options.allowUnscheduled = cms.untracked.bool(True)



#added in etau and mutau triggers
from UWAnalysis.Configuration.tools.analysisToolsHTauTau_WIP import *
defaultReconstructionMC(process,'HLT',
        [
            'HLT_IsoMu18_v', 
            'HLT_IsoMu20_v', 
            'HLT_IsoMu22_v', 
            'HLT_IsoMu22_eta2p1_v', 
            'HLT_IsoTkMu22_eta2p1_v',
            'HLT_IsoTkMu22_v',
            'HLT_IsoMu24_v', 
            'HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v',
            'HLT_IsoMu17_eta2p1_LooseIsoPFTau20_SingleL1_v',
            'HLT_IsoMu19_eta2p1_LooseIsoPFTau20_v',
            'HLT_IsoMu19_eta2p1_LooseIsoPFTau20_SingleL1_v',
            'HLT_IsoMu21_eta2p1_LooseIsoPFTau20_SingleL1_v',
            'HLT_Ele22_eta2p1_WPLoose_LooseIsoPFTau20_v',
            'HLT_Ele22_eta2p1_WPLoose_LooseIsoPFTau20_SingleL1_v',
            'HLT_Ele23_WPLoose_Gsf_v',
            'HLT_Ele24_eta2p1_WPLoose_Gsf_v',
            'HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_v',
            'HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_SingleL1_v',
            'HLT_Ele24_WPLoose_Gsf_v',
            'HLT_Ele25_eta2p1_WPLoose_Gsf_v',
            'HLT_Ele25_eta2p1_WPTight_Gsf_v',	
            'HLT_Ele27_WPLoose_Gsf_v',
            'HLT_Ele27_WPTight_Gsf_v',
            'HLT_Ele27_eta2p1_WPLoose_Gsf_v',
            'HLT_Ele27_eta2p1_WPTight_Gsf_v',
            'HLT_VLooseIsoPFTau140_Trk50_eta2p1_v',
            'HLT_VLooseIsoPFTau120_Trk50_eta2p1_v',
            'HLT_PFMET170_NoiseCleaned',
            'HLT_PFMET90_PFMHT90_IDTight',
            'HLT_CaloJet500_NoJetID',
            'HLT_ECALHT800'
            ])



        #EventSelection
process.load("UWAnalysis.Configuration.hTauTau_cff")

process.metCalibration.applyCalibration = cms.bool(False)

process.eventSelectionMT = cms.Path(process.selectionSequenceMT)
process.eventSelectionET = cms.Path(process.selectionSequenceET)
#Systematic Shifts 1sigma
process.eventSelectionMTTauUp    = createSystematics(process,process.selectionSequenceMT,'TauUp',1.0,1.0,1.06,0,1.0)
process.eventSelectionMTTauDown  = createSystematics(process,process.selectionSequenceMT,'TauDown',1.0,1.0,0.94,0,1.0)
#process.eventSelectionMTZmmUp    = createSystematics(process,process.selectionSequenceMT,'ZmmUp',1.0,1.0,1.1,0,1.0)
#process.eventSelectionMTZmmUp1    = createSystematics(process,process.selectionSequenceMT,'1ZmmUp',1.0,1.0,1.09,0,1.0)
#process.eventSelectionMTZmmUp2    = createSystematics(process,process.selectionSequenceMT,'2ZmmUp',1.0,1.0,1.08,0,1.0)
#process.eventSelectionMTZmmUp3    = createSystematics(process,process.selectionSequenceMT,'3ZmmUp',1.0,1.0,1.07,0,1.0)
#process.eventSelectionMTZmmUp4    = createSystematics(process,process.selectionSequenceMT,'4ZmmUp',1.0,1.0,1.06,0,1.0)
#process.eventSelectionMTZmmUp5    = createSystematics(process,process.selectionSequenceMT,'5ZmmUp',1.0,1.0,1.05,0,1.0)
#process.eventSelectionMTZmmUp6    = createSystematics(process,process.selectionSequenceMT,'6ZmmUp',1.0,1.0,1.04,0,1.0)
#process.eventSelectionMTZmmUp7    = createSystematics(process,process.selectionSequenceMT,'7ZmmUp',1.0,1.0,1.03,0,1.0)
#process.eventSelectionMTZmmUp8    = createSystematics(process,process.selectionSequenceMT,'8ZmmUp',1.0,1.0,1.02,0,1.0)
#process.eventSelectionMTZmmUp9    = createSystematics(process,process.selectionSequenceMT,'9ZmmUp',1.0,1.0,1.01,0,1.0)
#process.eventSelectionMTZmmDown  = createSystematics(process,process.selectionSequenceMT,'ZmmDown',1.0,1.0,0.9,0,1.0)
#process.eventSelectionMTZmmDown1  = createSystematics(process,process.selectionSequenceMT,'1ZmmDown',1.0,1.0,0.91,0,1.0)
#process.eventSelectionMTZmmDown2  = createSystematics(process,process.selectionSequenceMT,'2ZmmDown',1.0,1.0,0.92,0,1.0)
#process.eventSelectionMTZmmDown3  = createSystematics(process,process.selectionSequenceMT,'3ZmmDown',1.0,1.0,0.93,0,1.0)
#process.eventSelectionMTZmmDown4  = createSystematics(process,process.selectionSequenceMT,'4ZmmDown',1.0,1.0,0.94,0,1.0)
#process.eventSelectionMTZmmDown5  = createSystematics(process,process.selectionSequenceMT,'5ZmmDown',1.0,1.0,0.95,0,1.0)
#process.eventSelectionMTZmmDown6  = createSystematics(process,process.selectionSequenceMT,'6ZmmDown',1.0,1.0,0.96,0,1.0)
#process.eventSelectionMTZmmDown7  = createSystematics(process,process.selectionSequenceMT,'7ZmmDown',1.0,1.0,0.97,0,1.0)
#process.eventSelectionMTZmmDown8  = createSystematics(process,process.selectionSequenceMT,'8ZmmDown',1.0,1.0,0.98,0,1.0)
#process.eventSelectionMTZmmDown9  = createSystematics(process,process.selectionSequenceMT,'9ZmmDown',1.0,1.0,0.99,0,1.0)
#
process.eventSelectionETTauUp    = createSystematics(process,process.selectionSequenceET,'TauUp',1.00,1.0,1.06,0,1.0)
process.eventSelectionETTauDown  = createSystematics(process,process.selectionSequenceET,'TauDown',1.0,1.0,0.94,0,1.0)
process.eventSelectionETZeeUp    = createSystematics(process,process.selectionSequenceET,'ZeeUp',1.0,1.0,1.1,0,1.0)
process.eventSelectionETZeeUp1    = createSystematics(process,process.selectionSequenceET,'1ZeeUp',1.0,1.0,1.09,0,1.0)
process.eventSelectionETZeeUp2    = createSystematics(process,process.selectionSequenceET,'2ZeeUp',1.0,1.0,1.08,0,1.0)
process.eventSelectionETZeeUp3    = createSystematics(process,process.selectionSequenceET,'3ZeeUp',1.0,1.0,1.07,0,1.0)
process.eventSelectionETZeeUp4    = createSystematics(process,process.selectionSequenceET,'4ZeeUp',1.0,1.0,1.06,0,1.0)
process.eventSelectionETZeeUp5    = createSystematics(process,process.selectionSequenceET,'5ZeeUp',1.0,1.0,1.05,0,1.0)
process.eventSelectionETZeeUp6    = createSystematics(process,process.selectionSequenceET,'6ZeeUp',1.0,1.0,1.04,0,1.0)
process.eventSelectionETZeeUp7    = createSystematics(process,process.selectionSequenceET,'7ZeeUp',1.0,1.0,1.03,0,1.0)
process.eventSelectionETZeeUp8    = createSystematics(process,process.selectionSequenceET,'8ZeeUp',1.0,1.0,1.02,0,1.0)
process.eventSelectionETZeeUp9    = createSystematics(process,process.selectionSequenceET,'9ZeeUp',1.0,1.0,1.01,0,1.0)
process.eventSelectionETZeeDown  = createSystematics(process,process.selectionSequenceET,'ZeeDown',1.0,1.0,0.9,0,1.0)
process.eventSelectionETZeeDown1  = createSystematics(process,process.selectionSequenceET,'1ZeeDown',1.0,1.0,0.91,0,1.0)
process.eventSelectionETZeeDown2  = createSystematics(process,process.selectionSequenceET,'2ZeeDown',1.0,1.0,0.92,0,1.0)
process.eventSelectionETZeeDown3  = createSystematics(process,process.selectionSequenceET,'3ZeeDown',1.0,1.0,0.93,0,1.0)
process.eventSelectionETZeeDown4  = createSystematics(process,process.selectionSequenceET,'4ZeeDown',1.0,1.0,0.94,0,1.0)
process.eventSelectionETZeeDown5  = createSystematics(process,process.selectionSequenceET,'5ZeeDown',1.0,1.0,0.95,0,1.0)
process.eventSelectionETZeeDown6  = createSystematics(process,process.selectionSequenceET,'6ZeeDown',1.0,1.0,0.96,0,1.0)
process.eventSelectionETZeeDown7  = createSystematics(process,process.selectionSequenceET,'7ZeeDown',1.0,1.0,0.97,0,1.0)
process.eventSelectionETZeeDown8  = createSystematics(process,process.selectionSequenceET,'8ZeeDown',1.0,1.0,0.98,0,1.0)
process.eventSelectionETZeeDown9  = createSystematics(process,process.selectionSequenceET,'9ZeeDown',1.0,1.0,0.99,0,1.0)



createGeneratedParticles(process,
        'genDaughters',
        [
            "keep++ pdgId = {Z0}",
            "keep pdgId = {tau+}",
            "keep pdgId = {tau-}",
            "keep pdgId = {mu+}",
            "keep pdgId = {mu-}",
            "keep pdgId = 6",
            "keep pdgId = -6",
            "keep pdgId = 11",
            "keep pdgId = -11",
            ]
        )


createGeneratedParticles(process,
        'genTauCands',
        [
            "keep pdgId = {tau+}",
            "keep pdgId = {tau-}"
            ]
        )


from UWAnalysis.Configuration.tools.ntupleToolsHTauTau_WIP import addMuTauEventTree
addMuTauEventTree(process,'muTauEventTree')
addMuTauEventTree(process,'muTauEventTreeFinal','muTausOS','diMuonsOSSorted')


from UWAnalysis.Configuration.tools.ntupleToolsHTauTau_WIP import addEleTauEventTree
addEleTauEventTree(process,'eleTauEventTree')
addEleTauEventTree(process,'eleTauEventTreeFinal','eleTausOS','diElectronsOSSorted')

addEventSummary(process,True,'MT','eventSelectionMT')
addEventSummary(process,True,'ET','eventSelectionET')


#Final trees afor shapes after shifts
addMuTauEventTree(process,'muTauEventTreeTauUp','muTausSortedTauUp','diMuonsOSTauUp')
addMuTauEventTree(process,'muTauEventTreeTauDown','muTausSortedTauDown','diMuonsOSTauDown')
addMuTauEventTree(process,'muTauEventTreeFinalTauUp','muTausOSTauUp','diMuonsOSTauUp')
addMuTauEventTree(process,'muTauEventTreeFinalTauDown','muTausOSTauDown','diMuonsOSTauDown')

#addMuTauEventTree(process,'muTauEventTreeZmmUp','muTausSortedZmmUp','diMuonsOSZmmUp')
#addMuTauEventTree(process,'muTauEventTree1ZmmUp','muTausSorted1ZmmUp','diMuonsOS1ZmmUp')
#addMuTauEventTree(process,'muTauEventTree2ZmmUp','muTausSorted2ZmmUp','diMuonsOS2ZmmUp')
#addMuTauEventTree(process,'muTauEventTree3ZmmUp','muTausSorted3ZmmUp','diMuonsOS3ZmmUp')
#addMuTauEventTree(process,'muTauEventTree4ZmmUp','muTausSorted4ZmmUp','diMuonsOS4ZmmUp')
#addMuTauEventTree(process,'muTauEventTree5ZmmUp','muTausSorted5ZmmUp','diMuonsOS5ZmmUp')
#addMuTauEventTree(process,'muTauEventTree6ZmmUp','muTausSorted6ZmmUp','diMuonsOS6ZmmUp')
#addMuTauEventTree(process,'muTauEventTree7ZmmUp','muTausSorted7ZmmUp','diMuonsOS7ZmmUp')
#addMuTauEventTree(process,'muTauEventTree8ZmmUp','muTausSorted8ZmmUp','diMuonsOS8ZmmUp')
#addMuTauEventTree(process,'muTauEventTree9ZmmUp','muTausSorted9ZmmUp','diMuonsOS9ZmmUp')
#addMuTauEventTree(process,'muTauEventTreeZmmDown','muTausSortedZmmDown','diMuonsOSZmmDown')
#addMuTauEventTree(process,'muTauEventTree1ZmmDown','muTausSorted1ZmmDown','diMuonsOS1ZmmDown')
#addMuTauEventTree(process,'muTauEventTree2ZmmDown','muTausSorted2ZmmDown','diMuonsOS2ZmmDown')
#addMuTauEventTree(process,'muTauEventTree3ZmmDown','muTausSorted3ZmmDown','diMuonsOS3ZmmDown')
#addMuTauEventTree(process,'muTauEventTree4ZmmDown','muTausSorted4ZmmDown','diMuonsOS4ZmmDown')
#addMuTauEventTree(process,'muTauEventTree5ZmmDown','muTausSorted5ZmmDown','diMuonsOS5ZmmDown')
#addMuTauEventTree(process,'muTauEventTree6ZmmDown','muTausSorted6ZmmDown','diMuonsOS6ZmmDown')
#addMuTauEventTree(process,'muTauEventTree7ZmmDown','muTausSorted7ZmmDown','diMuonsOS7ZmmDown')
#addMuTauEventTree(process,'muTauEventTree8ZmmDown','muTausSorted8ZmmDown','diMuonsOS8ZmmDown')
#addMuTauEventTree(process,'muTauEventTree9ZmmDown','muTausSorted9ZmmDown','diMuonsOS9ZmmDown')
#addMuTauEventTree(process,'muTauEventTreeFinalZmmUp','muTausOSZmmUp','diMuonsOSZmmUp')
#addMuTauEventTree(process,'muTauEventTreeFinal1ZmmUp','muTausOS1ZmmUp','diMuonsOS1ZmmUp')
#addMuTauEventTree(process,'muTauEventTreeFinal2ZmmUp','muTausOS2ZmmUp','diMuonsOS2ZmmUp')
#addMuTauEventTree(process,'muTauEventTreeFinal3ZmmUp','muTausOS3ZmmUp','diMuonsOS3ZmmUp')
#addMuTauEventTree(process,'muTauEventTreeFinal4ZmmUp','muTausOS4ZmmUp','diMuonsOS4ZmmUp')
#addMuTauEventTree(process,'muTauEventTreeFinal5ZmmUp','muTausOS5ZmmUp','diMuonsOS5ZmmUp')
#addMuTauEventTree(process,'muTauEventTreeFinal6ZmmUp','muTausOS6ZmmUp','diMuonsOS6ZmmUp')
#addMuTauEventTree(process,'muTauEventTreeFinal7ZmmUp','muTausOS7ZmmUp','diMuonsOS7ZmmUp')
#addMuTauEventTree(process,'muTauEventTreeFinal8ZmmUp','muTausOS8ZmmUp','diMuonsOS8ZmmUp')
#addMuTauEventTree(process,'muTauEventTreeFinal9ZmmUp','muTausOS9ZmmUp','diMuonsOS9ZmmUp')
#addMuTauEventTree(process,'muTauEventTreeFinalZmmDown','muTausOSZmmDown','diMuonsOSZmmDown')
#addMuTauEventTree(process,'muTauEventTreeFinal1ZmmDown','muTausOS1ZmmDown','diMuonsOS1ZmmDown')
#addMuTauEventTree(process,'muTauEventTreeFinal2ZmmDown','muTausOS2ZmmDown','diMuonsOS2ZmmDown')
#addMuTauEventTree(process,'muTauEventTreeFinal3ZmmDown','muTausOS3ZmmDown','diMuonsOS3ZmmDown')
#addMuTauEventTree(process,'muTauEventTreeFinal4ZmmDown','muTausOS4ZmmDown','diMuonsOS4ZmmDown')
#addMuTauEventTree(process,'muTauEventTreeFinal5ZmmDown','muTausOS5ZmmDown','diMuonsOS5ZmmDown')
#addMuTauEventTree(process,'muTauEventTreeFinal6ZmmDown','muTausOS6ZmmDown','diMuonsOS6ZmmDown')
#addMuTauEventTree(process,'muTauEventTreeFinal7ZmmDown','muTausOS7ZmmDown','diMuonsOS7ZmmDown')
#addMuTauEventTree(process,'muTauEventTreeFinal8ZmmDown','muTausOS8ZmmDown','diMuonsOS8ZmmDown')
#addMuTauEventTree(process,'muTauEventTreeFinal9ZmmDown','muTausOS9ZmmDown','diMuonsOS9ZmmDown')
##
addEleTauEventTree(process,'eleTauEventTreeTauUp','eleTausSortedTauUp','diElectronsOSTauUp')
addEleTauEventTree(process,'eleTauEventTreeTauDown','eleTausSortedTauDown','diElectronsOSTauDown')
addEleTauEventTree(process,'eleTauEventTreeFinalTauUp','eleTausOSTauUp','diElectronsOSTauUp')
addEleTauEventTree(process,'eleTauEventTreeFinalTauDown','eleTausOSTauDown','diElectronsOSTauDown')

addEleTauEventTree(process,'eleTauEventTreeZeeUp','eleTausSortedZeeUp','diElectronsOSZeeUp')
addEleTauEventTree(process,'eleTauEventTreeZeeDown','eleTausSortedZeeDown','diElectronsOSZeeDown')
addEleTauEventTree(process,'eleTauEventTreeFinalZeeUp','eleTausOSZeeUp','diElectronsOSZeeUp')
addEleTauEventTree(process,'eleTauEventTreeFinalZeeDown','eleTausOSZeeDown','diElectronsOSZeeDown')

addEleTauEventTree(process,'eleTauEventTree1ZeeUp','eleTausSorted1ZeeUp','diMuonsOS1ZeeUp')
addEleTauEventTree(process,'eleTauEventTree2ZeeUp','eleTausSorted2ZeeUp','diMuonsOS2ZeeUp')
addEleTauEventTree(process,'eleTauEventTree3ZeeUp','eleTausSorted3ZeeUp','diMuonsOS3ZeeUp')
addEleTauEventTree(process,'eleTauEventTree4ZeeUp','eleTausSorted4ZeeUp','diMuonsOS4ZeeUp')
addEleTauEventTree(process,'eleTauEventTree5ZeeUp','eleTausSorted5ZeeUp','diMuonsOS5ZeeUp')
addEleTauEventTree(process,'eleTauEventTree6ZeeUp','eleTausSorted6ZeeUp','diMuonsOS6ZeeUp')
addEleTauEventTree(process,'eleTauEventTree7ZeeUp','eleTausSorted7ZeeUp','diMuonsOS7ZeeUp')
addEleTauEventTree(process,'eleTauEventTree8ZeeUp','eleTausSorted8ZeeUp','diMuonsOS8ZeeUp')
addEleTauEventTree(process,'eleTauEventTree9ZeeUp','eleTausSorted9ZeeUp','diMuonsOS9ZeeUp')
addEleTauEventTree(process,'eleTauEventTree1ZeeDown','eleTausSorted1ZeeDown','diMuonsOS1ZeeDown')
addEleTauEventTree(process,'eleTauEventTree2ZeeDown','eleTausSorted2ZeeDown','diMuonsOS2ZeeDown')
addEleTauEventTree(process,'eleTauEventTree3ZeeDown','eleTausSorted3ZeeDown','diMuonsOS3ZeeDown')
addEleTauEventTree(process,'eleTauEventTree4ZeeDown','eleTausSorted4ZeeDown','diMuonsOS4ZeeDown')
addEleTauEventTree(process,'eleTauEventTree5ZeeDown','eleTausSorted5ZeeDown','diMuonsOS5ZeeDown')
addEleTauEventTree(process,'eleTauEventTree6ZeeDown','eleTausSorted6ZeeDown','diMuonsOS6ZeeDown')
addEleTauEventTree(process,'eleTauEventTree7ZeeDown','eleTausSorted7ZeeDown','diMuonsOS7ZeeDown')
addEleTauEventTree(process,'eleTauEventTree8ZeeDown','eleTausSorted8ZeeDown','diMuonsOS8ZeeDown')
addEleTauEventTree(process,'eleTauEventTree9ZeeDown','eleTausSorted9ZeeDown','diMuonsOS9ZeeDown')
addEleTauEventTree(process,'eleTauEventTreeFinal1ZeeUp','eleTausOS1ZeeUp','diMuonsOS1ZeeUp')
addEleTauEventTree(process,'eleTauEventTreeFinal2ZeeUp','eleTausOS2ZeeUp','diMuonsOS2ZeeUp')
addEleTauEventTree(process,'eleTauEventTreeFinal3ZeeUp','eleTausOS3ZeeUp','diMuonsOS3ZeeUp')
addEleTauEventTree(process,'eleTauEventTreeFinal4ZeeUp','eleTausOS4ZeeUp','diMuonsOS4ZeeUp')
addEleTauEventTree(process,'eleTauEventTreeFinal5ZeeUp','eleTausOS5ZeeUp','diMuonsOS5ZeeUp')
addEleTauEventTree(process,'eleTauEventTreeFinal6ZeeUp','eleTausOS6ZeeUp','diMuonsOS6ZeeUp')
addEleTauEventTree(process,'eleTauEventTreeFinal7ZeeUp','eleTausOS7ZeeUp','diMuonsOS7ZeeUp')
addEleTauEventTree(process,'eleTauEventTreeFinal8ZeeUp','eleTausOS8ZeeUp','diMuonsOS8ZeeUp')
addEleTauEventTree(process,'eleTauEventTreeFinal9ZeeUp','eleTausOS9ZeeUp','diMuonsOS9ZeeUp')
addEleTauEventTree(process,'eleTauEventTreeFinal1ZeeDown','eleTausOS1ZeeDown','diMuonsOS1ZeeDown')
addEleTauEventTree(process,'eleTauEventTreeFinal2ZeeDown','eleTausOS2ZeeDown','diMuonsOS2ZeeDown')
addEleTauEventTree(process,'eleTauEventTreeFinal3ZeeDown','eleTausOS3ZeeDown','diMuonsOS3ZeeDown')
addEleTauEventTree(process,'eleTauEventTreeFinal4ZeeDown','eleTausOS4ZeeDown','diMuonsOS4ZeeDown')
addEleTauEventTree(process,'eleTauEventTreeFinal5ZeeDown','eleTausOS5ZeeDown','diMuonsOS5ZeeDown')
addEleTauEventTree(process,'eleTauEventTreeFinal6ZeeDown','eleTausOS6ZeeDown','diMuonsOS6ZeeDown')
addEleTauEventTree(process,'eleTauEventTreeFinal7ZeeDown','eleTausOS7ZeeDown','diMuonsOS7ZeeDown')
addEleTauEventTree(process,'eleTauEventTreeFinal8ZeeDown','eleTausOS8ZeeDown','diMuonsOS8ZeeDown')
addEleTauEventTree(process,'eleTauEventTreeFinal9ZeeDown','eleTausOS9ZeeDown','diMuonsOS9ZeeDown')
#
#
#

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
