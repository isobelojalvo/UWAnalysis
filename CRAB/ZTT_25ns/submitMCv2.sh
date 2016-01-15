#!/bin/sh
voms-proxy-init --voms cms --valid 100:00


######HIGGS SAMPLES #############
farmoutAnalysisJobs  $1 --assume-input-files-exist --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=GGHTT.txt  25ns_ggHtautau $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py

farmoutAnalysisJobs  $1 --assume-input-files-exist --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=VBFHTT.txt  25ns_vbfHtautau $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py

########ZJETS SAMPLES#############
farmoutAnalysisJobs $1 --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=ZJets.txt --assume-input-files-exist 25ns_ZJets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  

farmoutAnalysisJobs $1 --vsize-limit=8000  --input-files-per-job=1 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=ZJets550.txt --assume-input-files-exist 25ns_ZJets550 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  


########TT SAMPLES################
farmoutAnalysisJobs $1 --vsize-limit=8000  --input-files-per-job=1 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=TTJets.txt --assume-input-files-exist  25ns_TTJets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  

farmoutAnalysisJobs $1 --vsize-limit=8000  --input-files-per-job=1 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=TT.txt --assume-input-files-exist  25ns_TT $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  


##########WJETS SAMPLES#############
farmoutAnalysisJobs $1 --vsize-limit=8000  --input-files-per-job=1 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=WJetsLNu.txt --assume-input-files-exist  25ns_WJets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  

farmoutAnalysisJobs $1 --vsize-limit=8000  --input-files-per-job=1 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=WJetsMLM.txt --assume-input-files-exist  25ns_WJetsMLM $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  


###########VV SAMPLES#############
farmoutAnalysisJobs $1 --vsize-limit=8000 --input-files-per-job=2 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=VV.txt --assume-input-files-exist  25ns_VV $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  


###########WZ SAMPLES#############
farmoutAnalysisJobs $1 --vsize-limit=8000 --input-files-per-job=2 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=WZJets.txt --assume-input-files-exist  25ns_WZJets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --input-files-per-job=2 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=WZ1L1Nu2Q.txt --assume-input-files-exist  25ns_WZTo1L1Nu2Q $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --input-files-per-job=2 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=WZTo1L3Nu.txt --assume-input-files-exist  25ns_WZTo1L3Nu $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --input-files-per-job=2 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=WZTo2L2Q.txt --assume-input-files-exist  25ns_WZTo2L2Q $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  


##########SINGLE TOP SAMPLES#############
farmoutAnalysisJobs $1 --vsize-limit=8000  --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=ST_tW_antitop.txt --assume-input-files-exist 25ns_tBar_tW $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000  --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=ST_tW_top.txt --assume-input-files-exist 25ns_t_tW $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000  --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=ST_t_antitop.txt --assume-input-files-exist 25ns_St_t_antitop $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000  --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=ST_t_top.txt --assume-input-files-exist 25ns_St_t_top $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  

###########WW SAMPLES#############
farmoutAnalysisJobs $1 --vsize-limit=8000 --input-files-per-job=2 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=WWTo2L2Nu.txt --assume-input-files-exist  25ns_WWTo2L2Nu $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --input-files-per-job=2 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=WWTo4Q.txt --assume-input-files-exist  25ns_WWTo4Q $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --input-files-per-job=2 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=WWTo1L1Nu2Q.txt --assume-input-files-exist  25ns_WWToLNu2Q.txt $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  


###########ZZ SAMPLES#############
farmoutAnalysisJobs $1 --vsize-limit=8000 --input-files-per-job=2 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=ZZTo2L2Q.txt --assume-input-files-exist  25ns_ZZTo2L2Q $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --input-files-per-job=2 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=ZZTo4Q.txt --assume-input-files-exist  25ns_ZZTo4Q $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --input-files-per-job=2 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=ZZTo4L.txt --assume-input-files-exist  25ns_ZZTo4L $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  

