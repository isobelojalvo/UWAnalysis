#!/bin/sh
voms-proxy-init --voms cms --valid 100:00


######HIGGS SAMPLES #############
farmoutAnalysisJobs $1 --vsize-limit=8000  --input-files-per-job=1 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=WJetsHT100.txt --assume-input-files-exist  25ns_WJetsHT100 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000  --input-files-per-job=1 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=WJetsHT200.txt --assume-input-files-exist  25ns_WJetsHT200 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000  --input-files-per-job=1 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=WJetsHT400.txt --assume-input-files-exist  25ns_WJetsHT400 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000  --input-files-per-job=1 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=WJetsHT600.txt --assume-input-files-exist  25ns_WJetsHT600 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  

