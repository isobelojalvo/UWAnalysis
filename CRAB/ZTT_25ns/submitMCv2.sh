#!/bin/sh
voms-proxy-init --voms cms --valid 100:00


######HIGGS SAMPLES #############
farmoutAnalysisJobs  $1 --assume-input-files-exist --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=GGHTT.txt  25ns_ggHtautau $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py

farmoutAnalysisJobs  $1 --assume-input-files-exist --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=VBFHTT.txt  25ns_vbfHtautau $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py

farmoutAnalysisJobs $1 --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=ZJets.txt --assume-input-files-exist 25ns_ZJets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  

farmoutAnalysisJobs $1 --vsize-limit=8000  --input-files-per-job=1 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=ZJets1050.txt --assume-input-files-exist 25ns_ZJets1050 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  

farmoutAnalysisJobs $1 --vsize-limit=8000  --input-files-per-job=1 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=TTJets.txt --assume-input-files-exist  25ns_TTJets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  

farmoutAnalysisJobs $1 --vsize-limit=8000  --input-files-per-job=1 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=TT.txt --assume-input-files-exist  25ns_TT $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  

farmoutAnalysisJobs $1 --vsize-limit=8000  --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=tBar_tW.txt --assume-input-files-exist 25ns_tBar_tW $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  

#farmoutAnalysisJobs $1 --vsize-limit=8000  --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=t_tW.txt --assume-input-files-exist 25ns_t_tW $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  

farmoutAnalysisJobs $1 --vsize-limit=8000  --input-files-per-job=1 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=WJetsLNu.txt --assume-input-files-exist  25ns_WJets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  

#farmoutAnalysisJobs $1 --vsize-limit=8000 --input-files-per-job=2 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=WW.txt --assume-input-files-exist  25ns_WW $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  

farmoutAnalysisJobs $1 --vsize-limit=8000 --input-files-per-job=2 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=WZJets.txt --assume-input-files-exist  25ns_WZJets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  

#farmoutAnalysisJobs $1 --vsize-limit=8000 --input-files-per-job=2 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=ZZ.txt --assume-input-files-exist  25ns_ZZ $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  

