#!/bin/sh
voms-proxy-init --voms cms --valid 100:00


######HIGGS SAMPLES #############
#farmoutAnalysisJobs  $1 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToBBHToTauTau_M-160_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM syncNtupleEleBB1 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/Sync/SUB-ELE.py
#farmoutAnalysisJobs  $1 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToBBHToTauTau_M-160_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM syncNtuple8uBB1 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/Sync/SUB-MU.py

farmoutAnalysisJobs  $1 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToHToTauTau_M-160_TuneCUETP8M1_13TeV-pythia8/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v1/MINIAODSIM syncNtupleEle8 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/Sync/SUB-ELE.py
farmoutAnalysisJobs  $1 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToHToTauTau_M-160_TuneCUETP8M1_13TeV-pythia8/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v1/MINIAODSIM syncNtupleMu8 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/Sync/SUB-MU.py