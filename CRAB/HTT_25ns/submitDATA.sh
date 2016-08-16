#!/bin/sh
#voms-proxy-init --voms cms --valid 100:00

#Submit the reprocessed Data


farmoutAnalysisJobs  $1  --assume-input-files-exist --skip-existing-output --vsize-limit=8000   --input-files-per-job=1 --input-dbs-path=/Tau/Run2016B-PromptReco-v2/MINIAOD TAU2016B_Jul21 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT-JSON.py
farmoutAnalysisJobs  $1  --assume-input-files-exist --skip-existing-output --vsize-limit=8000   --input-files-per-job=1 --input-dbs-path=/Tau/Run2016C-PromptReco-v2/MINIAOD TAU2016C_Jul21 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT-JSON.py
farmoutAnalysisJobs  $1  --assume-input-files-exist --skip-existing-output --vsize-limit=8000   --input-files-per-job=1 --input-dbs-path=/Tau/Run2016E-PromptReco-v2/MINIAOD TAU2016E_Jul21 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT-JSON.py
farmoutAnalysisJobs  $1  --assume-input-files-exist --skip-existing-output --vsize-limit=8000   --input-files-per-job=1 --input-dbs-path=/Tau/Run2016F-PromptReco-v1/MINIAOD TAU2016F_Jul21 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT-JSON.py

#/Tau/Run2016B-PromptReco-v2/MINIAOD
#/Tau/Run2016C-PromptReco-v2/MINIAOD
#/Tau/Run2016E-PromptReco-v2/MINIAOD
#/Tau/Run2016F-PromptReco-v1/MINIAOD
