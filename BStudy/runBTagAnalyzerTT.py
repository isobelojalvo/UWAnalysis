
from FWCore.ParameterSet.VarParsing import VarParsing

options = VarParsing('python')

options.register('outFilename',
    'bTaggingEfficiency_TT.root',
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
'/store/mc/RunIIFall15MiniAODv2/TT_TuneCUETP8M1_13TeV-amcatnlo-pythia8/MINIAODSIM/PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/00000/04D51FB4-B2B8-E511-A399-047D7B881D6A.root',
'/store/mc/RunIIFall15MiniAODv2/TT_TuneCUETP8M1_13TeV-amcatnlo-pythia8/MINIAODSIM/PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/00000/081F15FB-AFB8-E511-B272-0025907DCA0C.root',
'/store/mc/RunIIFall15MiniAODv2/TT_TuneCUETP8M1_13TeV-amcatnlo-pythia8/MINIAODSIM/PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/00000/08FCA2E3-56B9-E511-B065-D8D385B0EE2E.root',
'/store/mc/RunIIFall15MiniAODv2/TT_TuneCUETP8M1_13TeV-amcatnlo-pythia8/MINIAODSIM/PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/00000/0AD4CD69-3FB9-E511-BC5D-B499BAAC0270.root',
'/store/mc/RunIIFall15MiniAODv2/TT_TuneCUETP8M1_13TeV-amcatnlo-pythia8/MINIAODSIM/PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/00000/1446ACE9-69B9-E511-B274-001CC4C0B0DC.root',
'/store/mc/RunIIFall15MiniAODv2/TT_TuneCUETP8M1_13TeV-amcatnlo-pythia8/MINIAODSIM/PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/00000/146E1641-A8B9-E511-8AF6-E41D2D08DDD0.root',
'/store/mc/RunIIFall15MiniAODv2/TT_TuneCUETP8M1_13TeV-amcatnlo-pythia8/MINIAODSIM/PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/00000/14D2B4EA-C0B8-E511-B0EB-002590DB920C.root',
'/store/mc/RunIIFall15MiniAODv2/TT_TuneCUETP8M1_13TeV-amcatnlo-pythia8/MINIAODSIM/PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/00000/14DD6E6A-95B8-E511-A61C-009C029C1160.root',
'/store/mc/RunIIFall15MiniAODv2/TT_TuneCUETP8M1_13TeV-amcatnlo-pythia8/MINIAODSIM/PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/00000/1669E165-99B8-E511-BECD-6C3BE5B594A8.root',
'/store/mc/RunIIFall15MiniAODv2/TT_TuneCUETP8M1_13TeV-amcatnlo-pythia8/MINIAODSIM/PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/00000/1E9C9C11-BBB8-E511-8304-047D7BD6DD9A.root',
'/store/mc/RunIIFall15MiniAODv2/TT_TuneCUETP8M1_13TeV-amcatnlo-pythia8/MINIAODSIM/PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/00000/2084B532-C9B8-E511-874B-FACADE0000B5.root',
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
    PtNBins = cms.int32(10),
    PtMin = cms.double(30.0),
    PtMax = cms.double(670.0),
    EtaNBins = cms.int32(8),
    EtaMin = cms.double(-2.4),
    EtaMax = cms.double(2.4)
)


process.p = cms.Path(process.effi)
