import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")

process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.GlobalTag.globaltag = 'START53_V22::All'


process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(500)
)



process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
       'file:/hdfs/store/user/tapas/VBF_HToTauTau_M-125_8TeV-powheg-pythia6/Summer12_DR53X-PU_S10_START53_V7A-v1/AODSIM/2013-02-25-8TeV-53X-PatTuple_Master/patTuple_cfg-FEAB3DA0-88ED-E111-B40F-AC162DACC3F0.root'
       #'/store/user/swanson/W4JetsToLNu_TuneZ2Star_8TeV-madgraph/W4JetsToLNu_TuneZ2Star_8TeV-madgraph_WJets8TeV-9ec8fe3/740ed358d05978b21a4396481cacaca9/output_1001_3_BZc.root'
       #'/store/user/tapas/DYJetsToLL_M-50_TuneZ2Star_8TeV-madgraph-tarball/Summer12_DR53X-PU_S10_START53_V7A-v1/AODSIM/2013-02-25-8TeV-53X-PatTuple_Master/patTuple_cfg-FEFF0D8E-91D2-E111-9BEA-001E673976ED.root'

		),
		inputCommands=cms.untracked.vstring(
						'keep *',
						'drop *_finalState*_*_*',
						'drop *_patFinalStateEvent*_*_*'
		)
)


from UWAnalysis.Configuration.tools.analysisToolsPT import *
defaultReconstructionMC(process,'HLT',
                      [
						'HLT_Ele18_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_MediumIsoPFTau20',
						"HLT_IsoMu15_eta2p1_LooseIsoPFTau20"
                      ])

                      

#EventSelection
process.load("UWAnalysis.Configuration.LepTauAnalysis_cff")

process.metCalibration.applyCalibration = cms.bool(True)
process.metCalibration.calibrationScheme = cms.string("Phil_H")


process.eventSelectionMT = cms.Path(process.selectionSequenceMT)
process.eventSelectionET = cms.Path(process.selectionSequenceET)


#Systematic Shifts 1sigma
# process.eventSelectionMTTauUp    = createSystematics(process,process.selectionSequenceMT,'TauUp',1.0,1.0,1.03,0,1.0)
# process.eventSelectionMTTauDown  = createSystematics(process,process.selectionSequenceMT,'TauDown',1.0,1.0,0.97,0,1.0)
# process.eventSelectionMTJetUp    = createSystematics(process,process.selectionSequenceMT,'JetUp',1.0,1.0,1.0,1,1.0)
# process.eventSelectionMTJetDown  = createSystematics(process,process.selectionSequenceMT,'JetDown',1.0,1.0,1.0,-1,1.0)
# process.eventSelectionMTUncUp    = createSystematics(process,process.selectionSequenceMT,'UncUp',1.00,1.0,1.0,0,1.1)
# process.eventSelectionMTUncDown  = createSystematics(process,process.selectionSequenceMT,'UncDown',1.0,1.0,1.0,0,0.9)

# process.eventSelectionETTauUp    = createSystematics(process,process.selectionSequenceET,'TauUp',1.00,1.0,1.03,0,1.0)
# process.eventSelectionETTauDown  = createSystematics(process,process.selectionSequenceET,'TauDown',1.0,1.0,0.97,0,1.0)
# process.eventSelectionETJetUp    = createSystematics(process,process.selectionSequenceET,'JetUp',1.0,1.0,1.0,1,1.0)
# process.eventSelectionETJetDown  = createSystematics(process,process.selectionSequenceET,'JetDown',1.0,1.0,1.0,-1,1.0)
# process.eventSelectionETEleUp    = createSystematics(process,process.selectionSequenceET,'EleUp',1.01,1.0,1.03,0,1.0)
# process.eventSelectionETEleDown  = createSystematics(process,process.selectionSequenceET,'EleDown',0.99,1.0,0.97,0,1.0)


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
                           "keep pdgId = {tau-} & mother.pdgId() = {Z0}"
                          ]
)


from UWAnalysis.Configuration.tools.ntupleToolsLTau import addMuTauEventTree
addMuTauEventTree(process,'muTauEventTree')
addMuTauEventTree(process,'muTauEventTreeFinal','diTausOS','diMuonsSorted')

from UWAnalysis.Configuration.tools.ntupleToolsLTau import addEleTauEventTree
addEleTauEventTree(process,'eleTauEventTree')
addEleTauEventTree(process,'eleTauEventTreeFinal','eleTausOS','osDiElectrons')

addEventSummary(process,True,'MT','eventSelectionMT')
addEventSummary(process,True,'ET','eventSelectionET')


#Final trees afor shapes after shifts
# addMuTauEventTree(process,'muTauEventTreeTauUp','diTausSortedTauUp','diMuonsSortedTauUp')
# addMuTauEventTree(process,'muTauEventTreeTauDown','diTausSortedTauDown','diMuonsSortedTauDown')
# addMuTauEventTree(process,'muTauEventTreeSyncTauUp','diTausOSTauUp','diMuonsSortedTauUp')
# addMuTauEventTree(process,'muTauEventTreeSyncTauDown','diTausOSTauDown','diMuonsSortedTauDown')
# addMuTauEventTree(process,'muTauEventTreeFinalTauUp','diTausOSTauUp','diMuonsSortedTauUp')
# addMuTauEventTree(process,'muTauEventTreeFinalTauDown','diTausOSTauDown','diMuonsSortedTauDown')
# addMuTauEventTree(process,'muTauEventTreeJetUp','diTausSortedJetUp','diMuonsSortedJetUp')
# addMuTauEventTree(process,'muTauEventTreeJetDown','diTausSortedJetDown','diMuonsSortedJetDown')
# addMuTauEventTree(process,'muTauEventTreeFinalJetUp','diTausOSJetUp','diMuonsSortedJetUp')
# addMuTauEventTree(process,'muTauEventTreeFinalJetDown','diTausOSJetDown','diMuonsSortedJetDown')
# addMuTauEventTree(process,'muTauEventTreeUncUp','diTausTauMuonVetoUncUp','diMuonsSortedUncUp')
# addMuTauEventTree(process,'muTauEventTreeUncDown','diTausTauMuonVetoUncDown','diMuonsSortedUncDown')

# addEleTauEventTree(process,'eleTauEventTreeTauUp','eleTausSortedTauUp','osDiElectronsTauUp')
# addEleTauEventTree(process,'eleTauEventTreeTauDown','eleTausSortedTauDown','osDiElectronsTauDown')
# addEleTauEventTree(process,'eleTauEventTreeSyncTauUp','eleTausOSTauUp','osDiElectronsTauUp')
# addEleTauEventTree(process,'eleTauEventTreeSyncTauDown','eleTausOSTauDown','osDiElectronsTauDown')
# addEleTauEventTree(process,'eleTauEventTreeFinalTauUp','eleTausOSTauUp','osDiElectronsTauUp')
# addEleTauEventTree(process,'eleTauEventTreeFinalTauDown','eleTausOSTauDown','osDiElectronsTauDown')
# addEleTauEventTree(process,'eleTauEventTreeJetUp','eleTausSortedJetUp','osDiElectronsJetUp')
# addEleTauEventTree(process,'eleTauEventTreeJetDown','eleTausSortedJetDown','osDiElectronsJetDown')
# addEleTauEventTree(process,'eleTauEventTreeFinalJetUp','eleTausOSJetUp','osDiElectronsJetUp')
# addEleTauEventTree(process,'eleTauEventTreeFinalJetDown','eleTausOSJetDown','osDiElectronsJetDown')
# addEleTauEventTree(process,'eleTauEventTreeEleUp','eleTausSortedEleUp','osDiElectronsEleUp')
# addEleTauEventTree(process,'eleTauEventTreeEleDown','eleTausSortedEleDown','osDiElectronsEleDown')


#dump_file = open('dump.py','w')
#dump_file.write(process.dumpPython())
