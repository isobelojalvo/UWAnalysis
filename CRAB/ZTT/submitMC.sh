#!/bin/sh
voms-proxy-init --voms cms --valid 100:00


######HIGGS SAMPLES #############
#farmoutAnalysisJobs  $1 --vsize-limit=8000 --input-dir=/store/mc/Phys14DR/GluGluToHToTauTau_M-125_13TeV-powheg-pythia6/MINIAODSIM/PU20bx25_tsg_PHYS14_25_V1-v1 ggHtautau $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT/SUB-MCH.py

#farmoutAnalysisJobs  $1 --vsize-limit=8000 --input-dir=/store/mc/Phys14DR/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/MINIAODSIM/PU20bx25_tsg_PHYS14_25_V1-v2 vbfHtautau $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT/SUB-MCH.py  

farmoutAnalysisJobs $1 --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=ZJets.txt --assume-input-files-exist 50ns_ZJets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT/SUB-MC.py  

farmoutAnalysisJobs $1 --vsize-limit=8000 --input-files-per-job=2 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=ZJets1050.txt --assume-input-files-exist 50ns_ZJets1050 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT/SUB-MC.py  

farmoutAnalysisJobs $1 --vsize-limit=8000  --input-files-per-job=2 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=TTJets.txt --assume-input-files-exist  50ns_TTJets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT/SUB-MC.py  

farmoutAnalysisJobs $1 --vsize-limit=8000  --input-files-per-job=2 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=TT.txt --assume-input-files-exist  50ns_TT $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT/SUB-MC.py  

farmoutAnalysisJobs $1 --vsize-limit=8000  --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=tBar_tW.txt --assume-input-files-exist 50ns_tBar_tW $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT/SUB-MC.py  

farmoutAnalysisJobs $1 --vsize-limit=8000  --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=t_tW.txt --assume-input-files-exist 50ns_t_tW $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT/SUB-MC.py  

farmoutAnalysisJobs $1 --vsize-limit=8000  --input-files-per-job=1 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=WJetsLNu.txt --assume-input-files-exist  50ns_WJets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT/SUB-MC.py  

farmoutAnalysisJobs $1 --vsize-limit=8000 --input-files-per-job=2 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=WW.txt --assume-input-files-exist  50ns_WW $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT/SUB-MC.py  

farmoutAnalysisJobs $1 --vsize-limit=8000 --input-files-per-job=2 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=WZJets.txt --assume-input-files-exist  50ns_WZJets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT/SUB-MC.py  

farmoutAnalysisJobs $1 --vsize-limit=8000 --input-files-per-job=2 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=ZZ.txt --assume-input-files-exist  50ns_ZZ $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT/SUB-MC.py  

