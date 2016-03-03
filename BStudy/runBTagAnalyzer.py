
from FWCore.ParameterSet.VarParsing import VarParsing

options = VarParsing('python')

options.register('outFilename',
    'bTaggingEfficiency.root',
    VarParsing.multiplicity.singleton,
    VarParsing.varType.string,
    'output file name'
)

options.register('reportEvery',
    1000,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.int,
    'Report every N events (default is N=1000)'
)

options.parseArguments()

import FWCore.ParameterSet.Config as cms
process = cms.Process("Effi")


process.load('FWCore.MessageService.MessageLogger_cfi')
process.MessageLogger.cerr.FwkReport.reportEvery = options.reportEvery

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(500000) )


process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
'/store/mc/RunIIFall15MiniAODv2/SUSYGluGluToBBHToTauTau_M-160_TuneCUETP8M1_13TeV-pythia8/MINIAODSIM/PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/10000/0228BA78-4EB8-E511-9B0D-003048F3511E.root',
'/store/mc/RunIIFall15MiniAODv2/SUSYGluGluToBBHToTauTau_M-160_TuneCUETP8M1_13TeV-pythia8/MINIAODSIM/PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/10000/06446D08-50B8-E511-B74F-001E67247CC9.root',
'/store/mc/RunIIFall15MiniAODv2/SUSYGluGluToBBHToTauTau_M-160_TuneCUETP8M1_13TeV-pythia8/MINIAODSIM/PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/10000/1C786EA9-4FB8-E511-B4CA-001E672489F3.root',
'/store/mc/RunIIFall15MiniAODv2/SUSYGluGluToBBHToTauTau_M-160_TuneCUETP8M1_13TeV-pythia8/MINIAODSIM/PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/10000/24753C78-4EB8-E511-98DB-001E67247CC9.root',
'/store/mc/RunIIFall15MiniAODv2/SUSYGluGluToBBHToTauTau_M-160_TuneCUETP8M1_13TeV-pythia8/MINIAODSIM/PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/10000/4AA16CFF-4EB8-E511-A8B8-001E672486E2.root',
'/store/mc/RunIIFall15MiniAODv2/SUSYGluGluToBBHToTauTau_M-160_TuneCUETP8M1_13TeV-pythia8/MINIAODSIM/PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/10000/541D66C0-4FB8-E511-80E6-001E672480BB.root',
'/store/mc/RunIIFall15MiniAODv2/SUSYGluGluToBBHToTauTau_M-160_TuneCUETP8M1_13TeV-pythia8/MINIAODSIM/PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/10000/6E89C6AC-4FB8-E511-B0A4-001E67247ECC.root',
'/store/mc/RunIIFall15MiniAODv2/SUSYGluGluToBBHToTauTau_M-160_TuneCUETP8M1_13TeV-pythia8/MINIAODSIM/PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/10000/8442C609-51B8-E511-A4A1-003048895D34.root',
'/store/mc/RunIIFall15MiniAODv2/SUSYGluGluToBBHToTauTau_M-160_TuneCUETP8M1_13TeV-pythia8/MINIAODSIM/PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/10000/C2E55CEE-4EB8-E511-A494-001E67248296.root',
'/store/mc/RunIIFall15MiniAODv2/SUSYGluGluToBBHToTauTau_M-160_TuneCUETP8M1_13TeV-pythia8/MINIAODSIM/PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/10000/CA76330F-50B8-E511-AFAC-001E674613C3.root',
'/store/mc/RunIIFall15MiniAODv2/SUSYGluGluToBBHToTauTau_M-160_TuneCUETP8M1_13TeV-pythia8/MINIAODSIM/PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/10000/CEC68C9E-4FB8-E511-ACF8-001E672485DE.root',
'/store/mc/RunIIFall15MiniAODv2/SUSYGluGluToBBHToTauTau_M-160_TuneCUETP8M1_13TeV-pythia8/MINIAODSIM/PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/10000/D4E1D0CB-4EB8-E511-9B95-001E672486AB.root'
    )
)


process.TFileService = cms.Service('TFileService',
   fileName = cms.string(options.outFilename)
)


process.effi = cms.EDAnalyzer("BTaggingEffAnalyzer",
    TausTag = cms.InputTag("slimmedTaus"),
    JetsTag = cms.InputTag("slimmedJets"),
    DiscriminatorTag = cms.string("pfCombinedInclusiveSecondaryVertexV2BJetTags"),
    DiscriminatorValue = cms.double(0.80),
    PtNBins = cms.int32(8),
    PtMin = cms.double(30.0),
    PtMax = cms.double(670.0),
    EtaNBins = cms.int32(8),
    EtaMin = cms.double(-2.4),
    EtaMax = cms.double(2.4)
)


process.p = cms.Path(process.effi)
