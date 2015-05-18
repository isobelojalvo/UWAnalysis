#!/bin/sh
voms-proxy-init --voms cms --valid 100:00


######TTJets SAMPLES #############
farmoutAnalysisJobs  $1 --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=TT_MSCKM.txt --assume-input-files-exist TT_MSCKM $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/MiniAod/SUB-MC.py  
