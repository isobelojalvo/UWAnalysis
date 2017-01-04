#!/bin/sh
#voms-proxy-init --voms cms --valid 100:00
jobID="mutau_2016_Dec14"
header="--assume-input-files-exist --vsize-limit=8000 --skip-existing-output  --input-files-per-job=1"
#PromptREco
farmoutAnalysisJobs  $1  $header --input-dbs-path=/SingleMuon/Run2016B-23Sep2016-v3/MINIAOD ${jobID}_SINGLEMUON2016B $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-JSON.py  
farmoutAnalysisJobs  $1  $header --input-dbs-path=/SingleMuon/Run2016C-23Sep2016-v1/MINIAOD ${jobID}_SINGLEMUON2016C $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-JSON.py  
farmoutAnalysisJobs  $1  $header --input-dbs-path=/SingleMuon/Run2016D-23Sep2016-v1/MINIAOD ${jobID}_SINGLEMUON2016D $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-JSON.py  
farmoutAnalysisJobs  $1  $header --input-dbs-path=/SingleMuon/Run2016E-23Sep2016-v1/MINIAOD ${jobID}_SINGLEMUON2016E $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-JSON.py  
farmoutAnalysisJobs  $1  $header --input-dbs-path=/SingleMuon/Run2016F-23Sep2016-v1/MINIAOD ${jobID}_SINGLEMUON2016F $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-JSON.py  
farmoutAnalysisJobs  $1  $header --input-dbs-path=/SingleMuon/Run2016G-23Sep2016-v1/MINIAOD ${jobID}_SINGLEMUON2016G $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-JSON.py  






