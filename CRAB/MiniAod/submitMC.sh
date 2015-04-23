#!/bin/sh
voms-proxy-init --voms cms --valid 100:00



#farmoutAnalysisJobs  $1 --job-count=  --vsize-limit=8000 --input-dir=/store/mc/Phys14DR/GluGluToHToTauTau_M-125_13TeV-powheg-pythia6/MINIAODSIM/PU20bx25_tsg_PHYS14_25_V1-v1 ggHtautau $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/MiniAod/SUB-MCH.py

#farmoutAnalysisJobs  $1 --job-count=10 --input-files-per-job=2 --vsize-limit=8000 --input-dir=/store/mc/Phys14DR/DYJetsToLL_M-50_13TeV-madgraph-pythia8/MINIAODSIM/PU20bx25_PHYS14_25_V1-v1 dyJetsLL $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/MiniAod/SUB-MC.py  

#farmoutAnalysisJobs  $1 --job-count=10 --input-files-per-job=2 --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=WJetsLNu.txt --assume-input-files-exist  WJets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/MiniAod/SUB-MC.py  

farmoutAnalysisJobs  $1 --job-count=3 --vsize-limit=8000 --input-dir=/store/mc/Phys14DR/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/MINIAODSIM/PU4bx50_PHYS14_25_V1-v1 TT_MSCKM $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/MiniAod/SUB-MC.py  

farmoutAnalysisJobs  $1 --job-count=3 --vsize-limit=8000 --input-dir=/store/mc/Phys14DR/TT_Tune4C_13TeV-pythia8-tauola/MINIAODSIM/PU20bx25_tsg_PHYS14_25_V1-v1/ TT_Tune4C $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/MiniAod/SUB-MC.py  

#farmoutAnalysisJobs  $1 --job-count=10 --input-files-per-job=2 --vsize-limit=8000 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=WZJets.txt --assume-input-files-exist  WZJets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/MiniAod/SUB-MC.py  

#farmoutAnalysisJobs  $1 --job-count=3 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=tBar_tW.txt --assume-input-files-exist tBar_tW $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/MiniAod/SUB-MC.py  

#farmoutAnalysisJobs  $1 --job-count=3 --input-dir=root://cmsxrootd.fnal.gov/ --input-file-list=t_tW.txt --assume-input-files-exist t_tW $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/MiniAod/SUB-MC.py  
