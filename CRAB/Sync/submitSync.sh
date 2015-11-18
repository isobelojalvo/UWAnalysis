#!/bin/sh
voms-proxy-init --voms cms --valid 100:00


######HIGGS SAMPLES #############
farmoutAnalysisJobs  $1 --input-dir=root://cmsxrootd.fnal.gov/ --assume-input-files-exist --input-file-list=SUSY.txt  syncNtupleEle35 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/Sync/SUB-ELE.py
farmoutAnalysisJobs  $1 --input-dir=root://cmsxrootd.fnal.gov/ --assume-input-files-exist --input-file-list=SUSY.txt syncNtupleMu35 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/Sync/SUB-MU.py
