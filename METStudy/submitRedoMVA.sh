#!/bin/sh
voms-proxy-init --voms cms --valid 100:00


######HIGGS SAMPLES #############
farmoutAnalysisJobs  $1 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToHToTauTau_M-160_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM RerunMVAMet_Standard $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/METStudy/RerunMVAMET.py
