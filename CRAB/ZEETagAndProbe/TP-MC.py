
import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")

process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.GlobalTag.globaltag = 'START42_V17::All'

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(100)
)

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
    '/store/mc/Fall11/DYToEE_M-20_TuneZ2_7TeV-pythia6/AODSIM/Peak32PU_START42_V14B-v1/0000/22BF9B5B-D3E9-E011-B5A2-0025901D4D64.root',
       '/store/mc/Summer11/DYToEE_M-20_TuneZ2_7TeV-pythia6/AODSIM/PU_S3_START42_V11-v1/0000/FEFEAD74-1D77-E011-A8D3-003048F0E518.root',
       '/store/mc/Summer11/DYToEE_M-20_TuneZ2_7TeV-pythia6/AODSIM/PU_S3_START42_V11-v1/0000/FE946CEA-1B77-E011-9222-0025901D4C46.root',
       '/store/mc/Summer11/DYToEE_M-20_TuneZ2_7TeV-pythia6/AODSIM/PU_S3_START42_V11-v1/0000/FE8474CF-DF76-E011-AB3A-0025901D493C.root',
       '/store/mc/Summer11/DYToEE_M-20_TuneZ2_7TeV-pythia6/AODSIM/PU_S3_START42_V11-v1/0000/FE57E387-1C77-E011-B095-00266CF2E2C8.root',
       '/store/mc/Summer11/DYToEE_M-20_TuneZ2_7TeV-pythia6/AODSIM/PU_S3_START42_V11-v1/0000/FC74D3B9-1B77-E011-8A70-002481E15176.root',
       '/store/mc/Summer11/DYToEE_M-20_TuneZ2_7TeV-pythia6/AODSIM/PU_S3_START42_V11-v1/0000/FC2FF91F-2A77-E011-8DD3-003048F0EBBC.root',
       '/store/mc/Summer11/DYToEE_M-20_TuneZ2_7TeV-pythia6/AODSIM/PU_S3_START42_V11-v1/0000/FACC0CE1-0077-E011-9503-0025901D4B08.root',
       '/store/mc/Summer11/DYToEE_M-20_TuneZ2_7TeV-pythia6/AODSIM/PU_S3_START42_V11-v1/0000/FACAA8D4-EB76-E011-8F1C-003048F0E826.root',
       '/store/mc/Summer11/DYToEE_M-20_TuneZ2_7TeV-pythia6/AODSIM/PU_S3_START42_V11-v1/0000/FA8593A4-DF76-E011-BABD-003048D436EA.root',
       '/store/mc/Summer11/DYToEE_M-20_TuneZ2_7TeV-pythia6/AODSIM/PU_S3_START42_V11-v1/0000/F8AD8B3A-1777-E011-8D6F-0025901D4B08.root',
       '/store/mc/Summer11/DYToEE_M-20_TuneZ2_7TeV-pythia6/AODSIM/PU_S3_START42_V11-v1/0000/F885F000-1477-E011-A899-002481E94C7A.root',
       '/store/mc/Summer11/DYToEE_M-20_TuneZ2_7TeV-pythia6/AODSIM/PU_S3_START42_V11-v1/0000/F6A13982-1177-E011-B323-00266CF330B8.root',
       '/store/mc/Summer11/DYToEE_M-20_TuneZ2_7TeV-pythia6/AODSIM/PU_S3_START42_V11-v1/0000/F69B9443-7377-E011-8AE2-0025901D4D76.root',
       '/store/mc/Summer11/DYToEE_M-20_TuneZ2_7TeV-pythia6/AODSIM/PU_S3_START42_V11-v1/0000/F696B312-2677-E011-B38D-003048F02CBE.root',
       '/store/mc/Summer11/DYToEE_M-20_TuneZ2_7TeV-pythia6/AODSIM/PU_S3_START42_V11-v1/0000/F4FD36E1-0077-E011-8614-003048D4DEA6.root',
       '/store/mc/Summer11/DYToEE_M-20_TuneZ2_7TeV-pythia6/AODSIM/PU_S3_START42_V11-v1/0000/F430289E-1577-E011-9248-0025901D481E.root',
       
        )
)

process.load("PhysicsTools.PatAlgos.patSequences_cff")


from UWAnalysis.Configuration.tools.analysisTools import *
defaultReconstructionMC(process,'HLT',[
    'HLT_Ele17_CaloIdVT_CaloIsoVT_TrkIdT_TrkIsoVT_SC8_Mass30',
    'HLT_Ele17_CaloIdVT_CaloIsoVT_TrkIdT_TrkIsoVT_Ele8_Mass30',
    'HLT_Ele32_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT'
    ])



#tagAndProbe 

process.load("UWAnalysis.Configuration.zEETagAndProbe_cff")


process.tagAndProbe = cms.Path(process.tagAndProbeSequence)

from UWAnalysis.Configuration.tools.ntupleTools import *

addTagAndProbePlotter(process,'ElectronSCTagAndProbePlotter',
                              'electronHtt15',
                              'convRejElectrons',
                              'selectedTagAndProbeEleSCs',
                              ['WWID','ISO'],
                              ['userFloat("WWID")>0','(chargedHadronIso+max(0.0,neutralHadronIso+photonIso-0.5*particleIso))/pt()<0.1'],
                              ['hltEle17CaloIdVTCaloIsoVTTrkIdTTrkIsoVTSC8TrackIsolFilter','hltEle17CaloIdVTCaloIsoVTTrkIdTTrkIsoVTEle8TrackIsolFilter'],
                              ['hltEle15CaloIdVTTrkIdTCaloIsoTTrkIsoTTrackIsolFilter']


)
addTagAndProbePlotter(process,'ElectronSCTagAndProbePlotter',
                              'electron2l2t17L',
                              'convRejElectrons',
                              'selectedTagAndProbeEleSCs',
                              ['CIC','ISO'],
                              ['gsfTrack().trackerExpectedHitsInner().numberOfHits()<2&&(electronID("cicTight")==1||electronID("cicTight")==3||electronID("cicTight")==5||electronID("cicTight")==7||electronID("cicTight")==9||electronID("cicTight")==11||electronID("cicTight")==13||electronID("cicTight")==15)','(chargedHadronIso+max(0.0,neutralHadronIso+photonIso-0.5*particleIso))/pt()<0.25'],
                              ['hltEle17CaloIdVTCaloIsoVTTrkIdTTrkIsoVTSC8TrackIsolFilter','hltEle17CaloIdVTCaloIsoVTTrkIdTTrkIsoVTEle8TrackIsolFilter'],
                              ['hltEle17CaloIdLCaloIsoVLPixelMatchFilterDoubleEG125','hltEle17CaloIdLCaloIsoVLPixelMatchFilter']
                                                            
)
addTagAndProbePlotter(process,'ElectronSCTagAndProbePlotter',
                              'electron2l2t8L',
                              'convRejElectrons',
                              'selectedTagAndProbeEleSCs',
                              ['CIC','ISO'],
                              ['gsfTrack().trackerExpectedHitsInner().numberOfHits()<2&&(electronID("cicTight")==1||electronID("cicTight")==3||electronID("cicTight")==5||electronID("cicTight")==7||electronID("cicTight")==9||electronID("cicTight")==11||electronID("cicTight")==13||electronID("cicTight")==15)','(chargedHadronIso+max(0.0,neutralHadronIso+photonIso-0.5*particleIso))/pt()<0.25'],
                              ['hltEle17CaloIdVTCaloIsoVTTrkIdTTrkIsoVTSC8TrackIsolFilter','hltEle17CaloIdVTCaloIsoVTTrkIdTTrkIsoVTEle8TrackIsolFilter'],
                              ['hltEle17CaloIdIsoEle8CaloIdIsoPixelMatchDoubleFilter','hltEle8CaloIdLCaloIsoVLPixelMatchFilter']
                                                            
)



addTagAndProbePlotter(process,'ElectronSCTagAndProbePlotter',
                              'electronNuJetISOPF',
                              'convRejElectrons',
                              'selectedTagAndProbeEleSCs',
                              ['IDL','ISOPF'],
                              ['((isEB &&sigmaIetaIeta<0.01&&abs(deltaPhiSuperClusterTrackAtVtx)<0.03&& abs(deltaEtaSuperClusterTrackAtVtx)<0.004 ) || (isEE &&sigmaIetaIeta<0.03&&abs(deltaPhiSuperClusterTrackAtVtx)<0.02 && abs(deltaEtaSuperClusterTrackAtVtx)<0.005))&& hcalOverEcal()<0.025 && abs(dB())<0.02 && (gsfTrack.trackerExpectedHitsInner.numberOfHits==0 && !(-0.02<convDist<0.02 && -0.02<convDcot<0.02)) ','(chargedHadronIso()+max(photonIso()+neutralHadronIso()-userFloat("rho")*3.14*0.4*0.4,0.0))/pt()<0.05'],
                      # This ID is equivalent to wp70, but it is not configured in the default analysisTools,
                              ['hltEle17CaloIdVTCaloIsoVTTrkIdTTrkIsoVTSC8TrackIsolFilter','hltEle17CaloIdVTCaloIsoVTTrkIdTTrkIsoVTEle8TrackIsolFilter'],
                              ['hltEle32WP70PFMT50PFMTFilter','hltEle27WP80PFMT50PFMTFilter','hltEle27WP80PFMT50PFMTFilter','hltEle32WP80PFMT50PFMTFilter']
)


addTagAndProbePlotter(process,'ElectronSCTagAndProbePlotter',
                              'electronNuJetISORel',
                              'convRejElectrons',
                              'selectedTagAndProbeEleSCs',
                              ['IDL','ISOPF'],
                              ['((isEB &&sigmaIetaIeta<0.01&&abs(deltaPhiSuperClusterTrackAtVtx)<0.03&& abs(deltaEtaSuperClusterTrackAtVtx)<0.004 ) || (isEE &&sigmaIetaIeta<0.03&&abs(deltaPhiSuperClusterTrackAtVtx)<0.02 && abs(deltaEtaSuperClusterTrackAtVtx)<0.005))&& hcalOverEcal()<0.025 && abs(dB())<0.02 && (gsfTrack.trackerExpectedHitsInner.numberOfHits==0 && !(-0.02<convDist<0.02 && -0.02<convDcot<0.02)) ','(dr03TkSumPt()+max(0,dr03EcalRecHitSumEt()+dr03HcalTowerSumEt()-userFloat("rho")*3.14*0.3*0.3))/pt()<0.05'],
                      # This ID is equivalent to wp70, but it is not configured in the default analysisTools,
                              ['hltEle17CaloIdVTCaloIsoVTTrkIdTTrkIsoVTSC8TrackIsolFilter','hltEle17CaloIdVTCaloIsoVTTrkIdTTrkIsoVTEle8TrackIsolFilter'],
                              ['hltEle32WP70PFMT50PFMTFilter','hltEle27WP80PFMT50PFMTFilter','hltEle27WP80PFMT50PFMTFilter','hltEle32WP80PFMT50PFMTFilter']
)


# addTagAndProbePlotter(process,'ElectronMisIDTagAndProbePlotter',
#                               'TauMisID',
#                               'patOverloadedTaus',
#                               'selectedTagAndProbeEleTracks',
#                               ['DM','ISO','ELEVETO'],
#                               ['tauID("decayModeFinding")>0.5','tauID("byLooseIsolation")>0.5','tauID("againstElectronTight")>0.5'],
#                               ['hltEle17CaloIdVTCaloIsoVTTrkIdTTrkIsoVTSC8TrackIsolFilter','hltEle32CaloIdTCaloIsoTTrkIdTTrkIsoTTrackIsoFilter'],
#                               ['hltOverlapFilterIsoEle15IsoPFTau15','hltOverlapFilterIsoEle18IsoPFTau20']
# 
# )








addEventSummary(process,False,'summary','tagAndProbe')











