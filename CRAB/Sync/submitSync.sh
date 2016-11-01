#!/bin/sh
voms-proxy-init --voms cms --valid 100:00


######HIGGS SAMPLES #############
farmoutAnalysisJobs  $1 --assume-input-files-exist --resubmit-failed-jobs --input-dbs-path=/SUSYGluGluToHToTauTau_M-160_TuneCUETP8M1_13TeV-pythia8/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM syncNtupleEle17 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/Sync/SUB-ELE.py
farmoutAnalysisJobs  $1 --assume-input-files-exist --input-dbs-path=/VBFHToTauTau_M125_13TeV_powheg_pythia8/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM syncNtupleEle17VBF $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/Sync/SUB-ELE.py
farmoutAnalysisJobs  $1 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToHToTauTau_M-160_TuneCUETP8M1_13TeV-pythia8/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM syncNtupleMu17 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/Sync/SUB-MU.py
farmoutAnalysisJobs  $1 --assume-input-files-exist --input-dbs-path=/VBFHToTauTau_M125_13TeV_powheg_pythia8/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM syncNtupleMu17VBF $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/Sync/SUB-MU.py
