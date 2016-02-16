
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
process = cms.Process("Demo")


process.load('FWCore.MessageService.MessageLogger_cfi')
process.MessageLogger.cerr.FwkReport.reportEvery = options.reportEvery

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(100000) )


process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        '/store/mc/RunIIFall15MiniAODv2/SUSYGluGluToHToTauTau_M-160_TuneCUETP8M1_13TeV-pythia8/MINIAODSIM/PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/50000/B2FF8F77-3DB8-E511-B743-001E6757F1D4.root'
    )
)


process.TFileService = cms.Service('TFileService',
   fileName = cms.string(options.outFilename)
)


process.demo = cms.EDAnalyzer("BTaggingEffAnalyzer",
    JetsTag = cms.InputTag("slimmedJets"),
    DiscriminatorTag = cms.string("pfCombinedInclusiveSecondaryVertexV2BJetTags"),
    DiscriminatorValue = cms.double(0.80),
    PtNBins = cms.int32(16),
    PtMin = cms.double(20.0),
    PtMax = cms.double(800.0),
    EtaNBins = cms.int32(4),
    EtaMin = cms.double(-2.4),
    EtaMax = cms.double(2.4)
)


process.p = cms.Path(process.demo)
