#!/bin/sh
voms-proxy-init --voms cms --valid 100:00


######HIGGS SAMPLES #############
farmoutAnalysisJobs  $1 --input-dir=/store/mc/RunIISpring15DR74/SUSYGluGluToHToTauTau_M-160_TuneCUETP8M1_13TeV-pythia8/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1 syncNtuple4 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/Sync/SUB-MCH.py
#farmoutAnalysisJobs  $1 --vsize-limit=8000 --input-dir=/store/mc/RunIISpring15DR74/SUSYGluGluToHToTauTau_M-160_TuneCUETP8M1_13TeV-pythia8/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1 syncNtuple $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/Sync/SUB-MCH.py
