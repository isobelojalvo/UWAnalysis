import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')

process.GlobalTag.globaltag = '80X_mcRun2_asymptotic_2016_miniAODv2_v1'


process.options   = cms.untracked.PSet(wantSummary = cms.untracked.bool(False))
process.options.allowUnscheduled = cms.untracked.bool(True)



#added in etau and mutau triggers
from UWAnalysis.Configuration.tools.analysisToolsHTauTau_WIP import *
defaultReconstructionMC(process,'HLT2',
        [
            'HLT_IsoMu18_v', 
            'HLT_IsoMu20_v', 
            'HLT_IsoMu22_v', 
            'HLT_IsoMu22_eta2p1_v', 
            'HLT_IsoTkMu22_v',
            'HLT_IsoTkMu22_eta2p1_v',
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
process.eventSelectionMTTauUp    = createSystematics(process,process.selectionSequenceMT,'TauUp',1.0,1.0,1.03,0,1.0)
process.eventSelectionMTTauDown  = createSystematics(process,process.selectionSequenceMT,'TauDown',1.0,1.0,0.97,0,1.0)
process.eventSelectionMTJetUp    = createSystematics(process,process.selectionSequenceMT,'JetUp',1.0,1.0,1.0,1,1.0)
process.eventSelectionMTJetDown  = createSystematics(process,process.selectionSequenceMT,'JetDown',1.0,1.0,1.0,-1,1.0)


process.eventSelectionETTauUp    = createSystematics(process,process.selectionSequenceET,'TauUp',1.00,1.0,1.03,0,1.0)
process.eventSelectionETTauDown  = createSystematics(process,process.selectionSequenceET,'TauDown',1.0,1.0,0.97,0,1.0)
process.eventSelectionETJetUp    = createSystematics(process,process.selectionSequenceET,'JetUp',1.0,1.0,1.0,1,1.0)
process.eventSelectionETJetDown  = createSystematics(process,process.selectionSequenceET,'JetDown',1.0,1.0,1.0,-1,1.0)


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


from UWAnalysis.Configuration.tools.ntupleToolsHTauTau_WIP import addMuTauShortEventTree
from UWAnalysis.Configuration.tools.ntupleToolsHTauTau_WIP import addEleTauShortEventTree
#Final trees afor shapes after shifts
addMuTauShortEventTree(process,'muTauEventTreeTauUp','muTausSortedTauUp','diMuonsOSTauUp')
addMuTauShortEventTree(process,'muTauEventTreeTauDown','muTausSortedTauDown','diMuonsOSTauDown')
addMuTauShortEventTree(process,'muTauEventTreeFinalTauUp','muTausOSTauUp','diMuonsOSTauUp')
addMuTauShortEventTree(process,'muTauEventTreeFinalTauDown','muTausOSTauDown','diMuonsOSTauDown')
addMuTauShortEventTree(process,'muTauEventTreeJetUp','muTausSortedJetUp','diMuonsOSJetUp')
addMuTauShortEventTree(process,'muTauEventTreeJetDown','muTausSortedJetDown','diMuonsOSJetDown')
addMuTauShortEventTree(process,'muTauEventTreeFinalJetUp','muTausOSJetUp','diMuonsOSJetUp')
addMuTauShortEventTree(process,'muTauEventTreeFinalJetDown','muTausOSJetDown','diMuonsOSJetDown')
#
addEleTauShortEventTree(process,'eleTauEventTreeTauUp','eleTausSortedTauUp','diElectronsOSTauUp')
addEleTauShortEventTree(process,'eleTauEventTreeTauDown','eleTausSortedTauDown','diElectronsOSTauDown')
addEleTauShortEventTree(process,'eleTauEventTreeFinalTauUp','eleTausOSTauUp','diElectronsOSTauUp')
addEleTauShortEventTree(process,'eleTauEventTreeFinalTauDown','eleTausOSTauDown','diElectronsOSTauDown')
addEleTauShortEventTree(process,'eleTauEventTreeJetUp','eleTausSortedJetUp','diElectronsOSJetUp')
addEleTauShortEventTree(process,'eleTauEventTreeJetDown','eleTausSortedJetDown','diElectronsOSJetDown')
addEleTauShortEventTree(process,'eleTauEventTreeFinalJetUp','eleTausOSJetUp','diElectronsOSJetUp')
addEleTauShortEventTree(process,'eleTauEventTreeFinalJetDown','eleTausOSJetDown','diElectronsOSJetDown')
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
