#!/bin/sh
voms-proxy-init --voms cms --valid 100:00

#Submit the reprocessed Data
farmoutAnalysisJobs  $1 --assume-input-files-exist --skip-existing-output --vsize-limit=8000 --input-files-per-job=1 --input-dbs-path=/SingleMuon/Run2016B-PromptReco-v2/MINIAOD SINGLEMUON2016B_Jun2 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-JSON.py  


farmoutAnalysisJobs  $1 --assume-input-files-exist --skip-existing-output --vsize-limit=8000 --input-files-per-job=1 --input-dbs-path=/SingleElectron/Run2016B-PromptReco-v2/MINIAOD SINGLEELE2016B_Jun2 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-JSON.py  

