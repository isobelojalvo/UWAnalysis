#!/bin/sh
voms-proxy-init --voms cms --valid 100:00


farmoutAnalysisJobs  $1 --vsize-limit=8000 --input-files-per-job=1 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=Tau.txt --assume-input-files-exist  TAU2015B $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT/SUB-JSON_working.py  


