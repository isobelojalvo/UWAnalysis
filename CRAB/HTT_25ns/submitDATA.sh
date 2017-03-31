#!/bin/sh
#voms-proxy-init --voms cms --valid 100:00
jobID="2017_Mar31"
header="--assume-input-files-exist --vsize-limit=8000  --input-files-per-job=1"
#PromptREco
farmoutAnalysisJobs  $1  $header --input-dbs-path=/Tau/Run2016B-03Feb2017_ver2-v2/MINIAOD ${jobID}_TAU2016B    $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT-JSON.py

farmoutAnalysisJobs  $1  $header --input-dbs-path=/Tau/Run2016C-03Feb2017-v1/MINIAOD      ${jobID}_TAU2016C    $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT-JSON.py
farmoutAnalysisJobs  $1  $header --input-dbs-path=/Tau/Run2016D-03Feb2017-v1/MINIAOD      ${jobID}_TAU2016D    $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT-JSON.py
farmoutAnalysisJobs  $1  $header --input-dbs-path=/Tau/Run2016E-03Feb2017-v1/MINIAOD      ${jobID}_TAU2016E    $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT-JSON.py
farmoutAnalysisJobs  $1  $header --input-dbs-path=/Tau/Run2016F-03Feb2017-v1/MINIAOD      ${jobID}_TAU2016F    $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT-JSON.py
farmoutAnalysisJobs  $1  $header --input-dbs-path=/Tau/Run2016G-03Feb2017-v1/MINIAOD      ${jobID}_TAU2016G    $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT-JSON.py
farmoutAnalysisJobs  $1  $header --input-dbs-path=/Tau/Run2016H-03Feb2017_ver2-v1/MINIAOD ${jobID}_TAU2016H-v2 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT-JSON.py
farmoutAnalysisJobs  $1  $header --input-dbs-path=/Tau/Run2016H-03Feb2017_ver3-v1/MINIAOD ${jobID}_TAU2016H-v3 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT-JSON.py


