#!/bin/sh
voms-proxy-init --voms cms --valid 100:00

farmoutAnalysisJobs  $1 --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=QCD.txt --assume-input-files-exist  QCD $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT/SUB-MC.py  

