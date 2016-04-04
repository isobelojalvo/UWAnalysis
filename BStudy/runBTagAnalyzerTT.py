
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

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )


process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
 $inputFileNames
    )
)


process.TFileService = cms.Service('TFileService',
   fileName = cms.string("$outputFileName")
)


process.effi = cms.EDAnalyzer("BTaggingEffAnalyzer",
    TausTag = cms.InputTag("slimmedTaus"),
    JetsTag = cms.InputTag("slimmedJets"),
    DiscriminatorTag = cms.string("pfCombinedInclusiveSecondaryVertexV2BJetTags"),
    DiscriminatorValue = cms.double(0.46),
    PtNBins = cms.int32(10),
    PtMin = cms.double(20.0),
    PtMax = cms.double(670.0),
    EtaNBins = cms.int32(8),
    EtaMin = cms.double(-2.4),
    EtaMax = cms.double(2.4)
)


process.p = cms.Path(process.effi)
