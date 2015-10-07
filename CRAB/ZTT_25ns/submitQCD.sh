#!/bin/sh
voms-proxy-init --voms cms --valid 100:00




farmoutAnalysisJobs  $1 --input-files-per-job=1 --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=QCDBCtoE_30.txt --assume-input-files-exist  25ns_QCDBCtoE_30 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT/SUB-MC.py  
farmoutAnalysisJobs  $1 --input-files-per-job=1 --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=QCDBCtoE_80.txt --assume-input-files-exist  25ns_QCDBCtoE_80 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT/SUB-MC.py  
farmoutAnalysisJobs  $1 --input-files-per-job=1 --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=QCDBCtoE_170.txt --assume-input-files-exist  25ns_QCDBCtoE_170 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT/SUB-MC.py  
farmoutAnalysisJobs  $1 --input-files-per-job=1 --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=QCDBCtoE_250.txt --assume-input-files-exist  25ns_QCDBCtoE_250 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT/SUB-MC.py  


farmoutAnalysisJobs  $1 --input-files-per-job=1 --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=muQCD.txt --assume-input-files-exist  25ns_muQCD $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT/SUB-MC.py  
