#!/bin/sh
#voms-proxy-init --voms cms --valid 100:00

#Submit the reprocessed Data
farmoutAnalysisJobs  $1 --assume-input-files-exist --vsize-limit=8000 --skip-existing-output  --input-files-per-job=1 --input-dbs-path=/SingleMuon/Run2016B-PromptReco-v2/MINIAOD SINGLEMUON2016B_Jul31 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-JSON.py  

farmoutAnalysisJobs  $1  --assume-input-files-exist --vsize-limit=8000 --skip-existing-output   --input-files-per-job=1 --input-dbs-path=/SingleMuon/Run2016C-PromptReco-v2/MINIAOD SINGLEMUON2016C_Jul31 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-JSON.py  
farmoutAnalysisJobs  $1  --assume-input-files-exist --vsize-limit=8000 --skip-existing-output   --input-files-per-job=1 --input-dbs-path=/SingleMuon/Run2016D-PromptReco-v2/MINIAOD SINGLEMUON2016D_Jul31 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-JSON.py  

farmoutAnalysisJobs  $1  --assume-input-files-exist --vsize-limit=8000 --skip-existing-output   --input-files-per-job=1 --input-dbs-path=/SingleElectron/Run2016B-PromptReco-v2/MINIAOD SINGLEELE2016B_Jul31 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-JSON.py  
farmoutAnalysisJobs  $1  --assume-input-files-exist --vsize-limit=8000 --skip-existing-output   --input-files-per-job=1 --input-dbs-path=/SingleElectron/Run2016C-PromptReco-v2/MINIAOD SINGLEELE2016C_Jul31 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-JSON.py  
farmoutAnalysisJobs  $1  --assume-input-files-exist --vsize-limit=8000 --skip-existing-output   --input-files-per-job=1 --input-dbs-path=/SingleElectron/Run2016D-PromptReco-v2/MINIAOD SINGLEELE2016D_Jul31 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-JSON.py  

farmoutAnalysisJobs  $1  --assume-input-files-exist --vsize-limit=8000 --skip-existing-output   --input-files-per-job=1 --input-dbs-path=/Tau/Run2016B-PromptReco-v2/MINIAOD TAU2016B_Jul31 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-JSON.py  
farmoutAnalysisJobs  $1  --assume-input-files-exist --vsize-limit=8000 --skip-existing-output   --input-files-per-job=1 --input-dbs-path=/Tau/Run2016C-PromptReco-v2/MINIAOD TAU2016C_Jul31 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-JSON.py  
farmoutAnalysisJobs  $1  --assume-input-files-exist --vsize-limit=8000 --skip-existing-output   --input-files-per-job=1 --input-dbs-path=/Tau/Run2016D-PromptReco-v2/MINIAOD TAU2016D_Jul31 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-JSON.py  

