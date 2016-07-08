#!/bin/sh
voms-proxy-init --voms cms --valid 100:00

#Submit the reprocessed Data
farmoutAnalysisJobs  $1 --assume-input-files-exist --vsize-limit=8000  --input-files-per-job=1 --input-file-list=SingleMuon.txt SINGLEMUON2016B_Jun23 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-JSON.py  


farmoutAnalysisJobs  $1 --assume-input-files-exist --vsize-limit=8000   --input-files-per-job=1 --input-file-list=SingleElectron.txt SINGLEELE2016B_Jun26 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-JSON.py  

