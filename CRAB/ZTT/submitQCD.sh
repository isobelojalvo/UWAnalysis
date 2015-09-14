#!/bin/sh
voms-proxy-init --voms cms --valid 100:00


farmoutAnalysisJobs  $1 --input-files-per-job=1 --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=50ns_muQCD.txt --assume-input-files-exist  50ns_muQCD $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT/SUB-MC.py  

farmoutAnalysisJobs  $1  --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=DoubleEMQCD.txt --assume-input-files-exist  50ns_emQCD $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT/SUB-MC.py  

