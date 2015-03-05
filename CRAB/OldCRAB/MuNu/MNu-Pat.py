import FWCore.ParameterSet.Config as cms
import sys
sys.setrecursionlimit(10000)



process = cms.Process("ANALYSIS")

#

process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.GlobalTag.globaltag = 'GR_R_42_V23::All'

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

process.load("UWAnalysis/Configuration/Cert_160404_173692_7TeV_PromptReco_Collisions11_JSON_cfi")

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
                   # $inputFileNames
 'root://cmsxrootd.hep.wisc.edu//store/user/cepeda/SingleMu/data_SingleMu_Run2011B_PromptReco_v1_2012-05-29-7TeV-PatTuple-67c1f94/fa6d9233416d07023dc202376bb19f23/output_455_1_vnV.root'
#'root://cmsxrootd.hep.wisc.edu//store/user/ojalvo/W-WlnuSKIM/1/WlnuSKIM-6A304A54-1EF3-E011-993E-002618943920.root'
#'root://cmsxrootd.hep.wisc.edu//store/user/ojalvo/W-WlnuSKIM/1/WlnuSKIM-16096E47-BFF2-E011-BC13-0018F3D0961A.root',
      
        
        ),
        inputCommands=cms.untracked.vstring(
						'keep *',
						'drop *_finalState*_*_*',
						'drop *_patFinalStateEvent*_*_*'
		)
)

process.load("PhysicsTools.PatAlgos.patSequences_cff")
from UWAnalysis.Configuration.tools.analysisToolsPT import *
defaultReconstructionPT(process,'HLT',['HLT_IsoMu12_v',
                                        'HLT_IsoMu17_v',
                                        'HLT_IsoMu20_v',
                                        'HLT_IsoMu24_v',
                                        'HLT_IsoMu30_eta2p1_v'
    #'HLT_IsoMu24'
    #'HLT_IsoMu20_v','HLT_IsoMu17_v','HLT_Mu17_v','HLT_Mu24_v','HLT_IsoMu24_v','HLT_IsoMu30_v','HLT_IsoMu24_eta2p1_v'
                                    ])


global metCalibration



process.metCalibration = cms.PSet(
                   applyCalibration = cms.bool(True),
                   calibrationScheme = cms.string("OneLeg"),
                   responseU1   = cms.string("1.33223-0.917782*x"),
                   responseU2   = cms.string("-0.013"),
                   resolutionU1 = cms.string("11.1566+0.0654529*x+0.000124436*x*x"),
                   resolutionU2 = cms.string("11.1235+0.0449872*x-6.39822e-5*x*x"),
                   responseMCU1   = cms.string("1.26247-0.950094*x"),
                   responseMCU2   = cms.string("-0.00544907"),
                   resolutionMCU1 = cms.string("10.6449+0.0436475*x+3.07554e-5*x*x"),
                   resolutionMCU2 = cms.string("10.5649+0.0225853*x-5.81371e-5*x*x")
)


process.metCalibration.applyCalibration = cms.bool(True)
process.metCalibration.calibrationScheme = cms.string("OneLeg")


#EventSelection

process.load("UWAnalysis.Configuration.wMuNuAnalysisPT_cff")
process.eventSelection = cms.Path(process.selectionSequence) ##changing to multiples see below




from UWAnalysis.Configuration.tools.ntupleToolsPT import *

#import FWCore.ParameterSet.Config as cms
#import PhysicsTools.PythonAnalysis.LumiList as LumiList
#myLumis = LumiList.LumiList(filename = 'goodList.json').getCMSSWString().split(',')
#process.source.lumisToProcess = cms.untracked.VLuminosityBlockRange()
#process.source.lumisToProcess.extend(myLumis)



addMuNuEventTreePt(process,'muNuEventTreePt')
addEventSummary(process,True)


#process.TFileService.fileName=cms.string("$outputFileName")

