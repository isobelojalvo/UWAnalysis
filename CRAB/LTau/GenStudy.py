import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")

process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.GlobalTag.globaltag = 'START53_V22::All'


process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(10000)
)




process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
    '/store/user/tapas/CMSFastSimPatTuple/MSSM_Htohh_mH300_tanB5_Filt_2TauPT10/MSSM_Htohh_mH300_tanB5_Filt_2TauPT10_316_patTuple.root ',
    '/store/user/tapas/CMSFastSimPatTuple/MSSM_Htohh_mH300_tanB5_Filt_2TauPT10/MSSM_Htohh_mH300_tanB5_Filt_2TauPT10_317_patTuple.root ',
    '/store/user/tapas/CMSFastSimPatTuple/MSSM_Htohh_mH300_tanB5_Filt_2TauPT10/MSSM_Htohh_mH300_tanB5_Filt_2TauPT10_318_patTuple.root ',
    '/store/user/tapas/CMSFastSimPatTuple/MSSM_Htohh_mH300_tanB5_Filt_2TauPT10/MSSM_Htohh_mH300_tanB5_Filt_2TauPT10_319_patTuple.root ',
    '/store/user/tapas/CMSFastSimPatTuple/MSSM_Htohh_mH300_tanB5_Filt_2TauPT10/MSSM_Htohh_mH300_tanB5_Filt_2TauPT10_31_patTuple.root  ',
    '/store/user/tapas/CMSFastSimPatTuple/MSSM_Htohh_mH300_tanB5_Filt_2TauPT10/MSSM_Htohh_mH300_tanB5_Filt_2TauPT10_320_patTuple.root ',
    '/store/user/tapas/CMSFastSimPatTuple/MSSM_Htohh_mH300_tanB5_Filt_2TauPT10/MSSM_Htohh_mH300_tanB5_Filt_2TauPT10_321_patTuple.root ',
    '/store/user/tapas/CMSFastSimPatTuple/MSSM_Htohh_mH300_tanB5_Filt_2TauPT10/MSSM_Htohh_mH300_tanB5_Filt_2TauPT10_322_patTuple.root ',
    '/store/user/tapas/CMSFastSimPatTuple/MSSM_Htohh_mH300_tanB5_Filt_2TauPT10/MSSM_Htohh_mH300_tanB5_Filt_2TauPT10_98_patTuple.root ',
    '/store/user/tapas/CMSFastSimPatTuple/MSSM_Htohh_mH300_tanB5_Filt_2TauPT10/MSSM_Htohh_mH300_tanB5_Filt_2TauPT10_99_patTuple.root ',
    '/store/user/tapas/CMSFastSimPatTuple/MSSM_Htohh_mH300_tanB5_Filt_2TauPT10/MSSM_Htohh_mH300_tanB5_Filt_2TauPT10_9_patTuple.root  '
    


    #'/store/user/tapas/VBF_HToTauTau_M-125_8TeV-powheg-pythia6/Summer12_DR53X-PU_S10_START53_V7A-v1/AODSIM/2013-02-25-8TeV-53X-PatTuple_Master/patTuple_cfg-867B0457-86ED-E111-A480-0025B326D182.root'
    #'file:patTuple_A-Zh-mmtt-PU025.root'
    #'file:myTestFile.root'
    #'file:/hdfs/store/user/tapas/DYJetsToLL_M-50_TuneZ2Star_8TeV-madgraph-tarball/Summer12_DR53X-PU_S10_START53_V7A-v1/AODSIM/2013-02-25-8TeV-53X-PatTuple_Master/patTuple_cfg-888F1C6B-EAD3-E111-AE1E-0025B3E05CDE.root',
    #'/store/user/tapas/CMSFastSimPatTuple/MSSM_Htohh_mH300_tanB5_2TauFilter/MSSM_Htohh_mH300_tanB5_2TauFilter_213_patTuple.root',
    #'/store/user/tapas/CMSFastSimPatTuple/H-hh-ttbb-MA300-TB5-PU025/H-hh-ttbb-MA300-TB5-PU025-0099_patTuple.root'

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
process.load("UWAnalysis.Configuration.LepTauAnalysisGenStudies_cff")

process.metCalibration.applyCalibration = cms.bool(True)
process.metCalibration.calibrationScheme = cms.string("Phil_H")


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
                           "keep abs(pdgId) = 36",
                           "keep abs(pdgId) = 6"
                          ]
)




createGeneratedParticles(process,
                         'genTauCands',
                          [
                           "keep pdgId = {tau+} & mother.pdgId()= {Z0}",
                           "keep pdgId = {tau-} & mother.pdgId() = {Z0}"
                          ]
)

createGeneratedParticles(process,
                         'genBs',
                          [
                           "keep abs(pdgId) = 5 & mother.pdgId()= {H0}"
                          ]
)


from UWAnalysis.Configuration.tools.ntupleToolsLTauGen import addMuTauEventTreeGen
addMuTauEventTreeGen(process,'muTauEventTree')
addMuTauEventTreeGen(process,'muTauEventTreeFinal','diTausOS','diMuonsSorted')

#from UWAnalysis.Configuration.tools.ntupleToolsLTau import addEleTauEventTree
#addEleTauEventTree(process,'eleTauEventTree')
#addEleTauEventTree(process,'eleTauEventTreeFinal','eletausOS','osDiElectrons')

addEventSummary(process,True,'MT','eventSelectionMT')
#addEventSummary(process,True,'ET','eventSelectionET')




#dump_file = open('dump.py','w')
#dump_file.write(process.dumpPython())
