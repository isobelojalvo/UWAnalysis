#!/bin/sh
voms-proxy-init --voms cms --valid 100:00

farmoutAnalysisJobs  $1   --vsize-limit=8000 --input-dir=/store/mc/Phys14DR/GluGluToHToTauTau_M-125_13TeV-powheg-pythia6/MINIAODSIM/PU20bx25_tsg_PHYS14_25_V1-v1 ggHtautau $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/MiniAod/SUB-MCH.py  

#farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/hdfs/store/mc/Phys14DR/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/MINIAODSIM/PU20bx25_tsg_PHYS14_25_V1-v2 vbfHtautau $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/MiniAod/SUB-MCH.py  

#farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/mc/Phys14DR/DYJetsToLL_M-50_13TeV-madgraph-pythia8/MINIAODSIM/PU20bx25_PHYS14_25_V1-v1 dyJetsLL $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/MiniAod/SUB-MC.py  
