#!/bin/sh
voms-proxy-init --voms cms --valid 100:00


farmoutAnalysisJobs  $1  --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=em1520QCD.txt --assume-input-files-exist  em1520QCD $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT/SUB-MC.py  
farmoutAnalysisJobs  $1  --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=em2030QCD.txt --assume-input-files-exist  em2030QCD $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT/SUB-MC.py  
farmoutAnalysisJobs  $1  --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=em3050QCD.txt --assume-input-files-exist  em3050QCD $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT/SUB-MC.py  

farmoutAnalysisJobs  $1  --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=em5080QCD.txt --assume-input-files-exist  em5080QCD $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT/SUB-MC.py  
farmoutAnalysisJobs  $1  --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=em80120QCD.txt --assume-input-files-exist  em80120QCD $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT/SUB-MC.py  
farmoutAnalysisJobs  $1  --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=em120170QCD.txt --assume-input-files-exist  em120170QCD $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT/SUB-MC.py  
farmoutAnalysisJobs  $1  --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=em170300QCD.txt --assume-input-files-exist  em170300QCD $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT/SUB-MC.py  
farmoutAnalysisJobs  $1  --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=em300infQCD.txt --assume-input-files-exist  em300infQCD $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT/SUB-MC.py  
farmoutAnalysisJobs  $1 --input-files-per-job=1 --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=50ns_muQCD.txt --assume-input-files-exist  50ns_muQCD $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT/SUB-MC.py  

