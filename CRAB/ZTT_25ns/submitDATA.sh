#!/bin/sh
#voms-proxy-init --voms cms --valid 100:00

#Submit the reprocessed Data
farmoutAnalysisJobs  $1 --assume-input-files-exist --vsize-limit=8000  --input-files-per-job=1 --input-file-list=SingleMuon2016B.txt SINGLEMUON2016B_Jul20 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-JSON.py  


farmoutAnalysisJobs  $1  --assume-input-files-exist --vsize-limit=8000   --input-files-per-job=1 --input-file-list=SingleElectron2016B.txt SINGLEELE2016B_Jul20 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-JSON.py  

