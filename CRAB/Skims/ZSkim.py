import FWCore.ParameterSet.Config as cms
import sys


process = cms.Process("SKIM")

process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.GlobalTag.globaltag = 'START42_V13::All'

process.load("DQMServices.Core.DQM_cfg")
process.load("DQMServices.Components.DQMEnvironment_cfi")



process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(5000)
)

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
'/store/mc/Fall11/VBF_HToTauTau_M-160_7TeV-powheg-pythia6-tauola/AODSIM/PU_S6_START42_V14B-v1/0000/00EB5690-D3F9-E011-A63D-20CF305B04DA.root' 
        )
)




############# Z -> mumu ###############
#######################################

process.muonsTight = cms.EDFilter("MuonRefSelector",
                                 src = cms.InputTag("muons"),
                                 cut = cms.string('pt>25&&abs(eta)<2.1&&isGlobalMuon&&isTrackerMuon&&numberOfMatches()>1&&(isolationR03.sumPt+isolationR03.emEt+isolationR03.hadEt)/pt<0.15'),
                                 filter = cms.bool(True)  
                             )

process.muonsLoose = cms.EDFilter("MuonRefSelector",
                                 src = cms.InputTag("muons"),
                                 cut = cms.string('pt>15&&abs(eta)<2.1&&isGlobalMuon&&isTrackerMuon'),
                                 filter = cms.bool(True)  
                             )

process.muonFilter = cms.EDFilter("CandViewCountFilter",
                               src = cms.InputTag("muonsLoose"),
                               minNumber = cms.uint32(2),
                             )
 
process.zMuMuSkim = cms.EDProducer("CandViewShallowCloneCombiner",
                                     decay = cms.string('muonsLoose@+ muonsLoose@-'),
                                     cut = cms.string('50 < mass < 120'),
                                 )
                                                                                       
process.skimZMM = cms.Path(
    process.muonsTight*
    process.muonsLoose*
    process.muonFilter*
    process.zMuMuSkim
)    


############# Z -> ee ###############
#######################################


process.electronsTight = cms.EDFilter("GsfElectronSelector",
                                 src = cms.InputTag("gsfElectrons"),
                                 cut = cms.string('pt>25&&abs(eta)<2.5&&((isEB()&&abs(deltaEtaSuperClusterTrackAtVtx())<0.004&&abs(deltaPhiSuperClusterTrackAtVtx())<0.06&&hcalOverEcal()<0.04&&abs(sigmaIetaIeta())<0.01)||(isEE()&&abs(deltaEtaSuperClusterTrackAtVtx())<0.007&&abs(deltaPhiSuperClusterTrackAtVtx())<0.03&&hcalOverEcal()<0.025&&abs(sigmaIetaIeta())<0.03))&&(pfIsolationVariables().chargedHadronIso()+pfIsolationVariables().photonIso()+pfIsolationVariables().neutralHadronIso())/pt()<0.15'),
                                 filter = cms.bool(True)  
                             )

process.electronsLoose = cms.EDFilter("GsfElectronSelector",
                                 src = cms.InputTag("gsfElectrons"),
                                 cut = cms.string('pt>15&&abs(eta)<2.5'),
                                 filter = cms.bool(True)  
                             )

process.electronFilter = cms.EDFilter("CandViewCountFilter",
                               src = cms.InputTag("electronsLoose"),
                               minNumber = cms.uint32(2),
                             )
 
process.zEESkim = cms.EDProducer("CandViewShallowCloneCombiner",
                                     decay = cms.string('electronsLoose@+ electronsLoose@-'),
                                     cut = cms.string('50 < mass < 120'),
                                 )


process.skimZEE = cms.Path(
    process.electronsTight*
    process.electronsLoose*
    process.electronFilter*
    process.zEESkim
)    




#Counter
process.counter  = cms.EDProducer("EventCounter",
                          name=cms.string("processedEvents"),
)                          

process.countPath = cms.Path(process.counter)



process.out = cms.OutputModule("PoolOutputModule",
                                   fileName = cms.untracked.string('skim.root'),
                                   outputCommands = cms.untracked.vstring('keep *_*_*_*',
                                                                          'drop *_*_*_SKIM',
                                                                          'keep *_MEtoEDMConverter*_*_SKIM'),
                                   SelectEvents = cms.untracked.PSet(
                                      SelectEvents=cms.vstring("skimZMM","skimZEE")
                                   )
                                  )


process.MEtoEDMConverter = cms.EDProducer("MEtoEDMConverter",
                                          Name = cms.untracked.string('MEtoEDMConverter'),
                                          Verbosity = cms.untracked.int32(0), # 0 provides no output
                                          # 1 provides basic output
                                          # 2 provide more detailed output
                                          Frequency = cms.untracked.int32(50),
                                          MEPathToSave = cms.untracked.string(''),
                                          deleteAfterCopy = cms.untracked.bool(True)
)



process.e = cms.EndPath(process.MEtoEDMConverter*process.out)


process.options = cms.untracked.PSet(
    wantSummary = cms.untracked.bool(True)

    )











