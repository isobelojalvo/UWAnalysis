#!/bin/sh
voms-proxy-init --voms cms --valid 100:00


#farmoutAnalysisJobs  $1 --vsize-limit=8000 --input-files-per-job=1 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=Tau.txt --assume-input-files-exist  TAU2015B_filter $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT/SUB-JSON.py  
farmoutAnalysisJobs  $1 --vsize-limit=8000 --input-files-per-job=1 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=SingleMu.txt --assume-input-files-exist  SINGLEMUON2015B $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT/SUB-JSON.py  
farmoutAnalysisJobs  $1 --vsize-limit=8000 --input-files-per-job=1 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=SingleElectron.txt --assume-input-files-exist  SINGLEELE2015B $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT/SUB-JSON.py  


