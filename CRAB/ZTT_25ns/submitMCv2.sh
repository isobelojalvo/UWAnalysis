#!/bin/sh
voms-proxy-init --voms cms --valid 100:00


######HIGGS SAMPLES #############
farmoutAnalysisJobs  $1 --assume-input-files-exist --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=GGHTT.txt  25ns_ggHtautau $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py

farmoutAnalysisJobs  $1 --assume-input-files-exist --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=VBFHTT.txt  25ns_vbfHtautau $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py



########ZJETS SAMPLES#############
farmoutAnalysisJobs $1 --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=ZJets.txt --assume-input-files-exist 25ns_ZJets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  

farmoutAnalysisJobs $1 --vsize-limit=8000  --input-files-per-job=1 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=ZJets1050.txt --assume-input-files-exist 25ns_ZJets1050 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  


########TT SAMPLES################
farmoutAnalysisJobs $1 --vsize-limit=8000  --input-files-per-job=1 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=TTJets.txt --assume-input-files-exist  25ns_TTJets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  

farmoutAnalysisJobs $1 --vsize-limit=8000  --input-files-per-job=1 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=TT.txt --assume-input-files-exist  25ns_TT $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  


##########WJETS SAMPLES#############
farmoutAnalysisJobs $1 --vsize-limit=8000  --input-files-per-job=1 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=WJetsLNu.txt --assume-input-files-exist  25ns_WJets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  

farmoutAnalysisJobs $1 --vsize-limit=8000  --input-files-per-job=1 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=WJetsMLM.txt --assume-input-files-exist  25ns_WJetsMLM $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  

farmoutAnalysisJobs $1 --vsize-limit=8000 --input-files-per-job=2 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=WZJets.txt --assume-input-files-exist  25ns_WZJets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  


##########SINGLE TOP SAMPLES#############
farmoutAnalysisJobs $1 --vsize-limit=8000  --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=tBar_tW.txt --assume-input-files-exist 25ns_tBar_tW $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000  --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=t_tW.txt --assume-input-files-exist 25ns_t_tW $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000  --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=t_s.txt --assume-input-files-exist 25ns_t_s $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000  --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=t_s_Ext.txt --assume-input-files-exist 25ns_t_Ext $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  

###########WW SAMPLES#############
farmoutAnalysisJobs $1 --vsize-limit=8000 --input-files-per-job=2 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=WWTo2L2Nu.txt --assume-input-files-exist  25ns_WWTo2L2Nu $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --input-files-per-job=2 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=WWTo4Q.txt --assume-input-files-exist  25ns_WWTo4Q $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --input-files-per-job=2 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=WWToLNuQQ.txt --assume-input-files-exist  25ns_WWToLNuQQ $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  


###########ZZ SAMPLES#############
farmoutAnalysisJobs $1 --vsize-limit=8000 --input-files-per-job=2 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=ZZTo2L2Q.txt --assume-input-files-exist  25ns_ZZTo2L2Q $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --input-files-per-job=2 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=ZZ2Q2Nu.txt --assume-input-files-exist  25ns_ZZ2Q2Nu $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --input-files-per-job=2 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=ZZTo4Q.txt --assume-input-files-exist  25ns_ZZTo4Q $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  

