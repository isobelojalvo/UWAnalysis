#!/bin/sh
voms-proxy-init --voms cms --valid 100:00


######HIGGS SAMPLES #############
#farmoutAnalysisJobs  $1 --vsize-limit=8000 --input-dir=/store/mc/Phys14DR/GluGluToHToTauTau_M-125_13TeV-powheg-pythia6/MINIAODSIM/PU20bx25_tsg_PHYS14_25_V1-v1 ggHtautau $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT/SUB-MCH.py

#farmoutAnalysisJobs  $1 --vsize-limit=8000 --input-dir=/store/mc/Phys14DR/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/MINIAODSIM/PU20bx25_tsg_PHYS14_25_V1-v2 vbfHtautau $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT/SUB-MCH.py  

farmoutAnalysisJobs  $1 --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=ZJets.txt --assume-input-files-exist  ZJets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT/SUB-MC.py  

farmoutAnalysisJobs  $1 --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=TTJets.txt --assume-input-files-exist  TTJets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT/SUB-MC.py  

farmoutAnalysisJobs  $1 --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=tBar_tW.txt --assume-input-files-exist tBar_tW $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT/SUB-MC.py  

farmoutAnalysisJobs  $1 --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=t_tW.txt --assume-input-files-exist t_tW $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT/SUB-MC.py  

farmoutAnalysisJobs  $1 --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=WJetsLNu.txt --assume-input-files-exist  WJets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT/SUB-MC.py  
farmoutAnalysisJobs  $1 --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=WW.txt --assume-input-files-exist  WW $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT/SUB-MC.py  
farmoutAnalysisJobs  $1 --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=WZJets.txt --assume-input-files-exist  WZJets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT/SUB-MC.py  
farmoutAnalysisJobs  $1 --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=ZZ.txt --assume-input-files-exist  ZZ $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT/SUB-MC.py  

#farmoutAnalysisJobs  $1 --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=QCD.txt --assume-input-files-exist  QCD $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT/SUB-MC.py  

