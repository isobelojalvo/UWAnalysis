#!/bin/sh
voms-proxy-init --voms cms --valid 100:00

#Submit the reprocessed Data
farmoutAnalysisJobs  $1 --vsize-limit=8000 --input-files-per-job=1 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=SingleMuon2015D-05Oct.txt --assume-input-files-exist  SINGLEMUON2015D_Golden-METNoHF05Oct $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-JSON-05Oct-METNoHF.py  

farmoutAnalysisJobs  $1 --vsize-limit=8000 --input-files-per-job=1 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=SingleElectron2015D-05Oct.txt --assume-input-files-exist  SINGLEELE2015D_Golden-METNoHF05Oct $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-JSON-05Oct-METNoHF.py  

farmoutAnalysisJobs  $1 --vsize-limit=8000 --input-files-per-job=1 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=SingleMuon2015D-PRv4.txt --assume-input-files-exist  SINGLEMUON2015D_Golden-METNoHFPRv4 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-JSON-PRv4-METNoHF.py  


farmoutAnalysisJobs  $1 --vsize-limit=8000 --input-files-per-job=1 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=SingleElectron2015D-PRv4.txt --assume-input-files-exist  SINGLEELE2015D_Golden-METNoHFPRv4 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-JSON-PRv4-METNoHF.py  


