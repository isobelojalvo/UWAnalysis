#!/bin/sh
voms-proxy-init --voms cms --valid 100:00

farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/swanson/GluGluToHToTauTau_M-90_8TeV-powheg-pythia6  SMGGH90  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py  
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/swanson/GluGluToHToTauTau_M-95_8TeV-powheg-pythia6  SMGGH95  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py  
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/GluGluToHToTauTau_M-100_8TeV-powheg-pythia6  SMGGH100  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py  
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/GluGluToHToTauTau_M-105_8TeV-powheg-pythia6  SMGGH105  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py  
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/GluGluToHToTauTau_M-110_8TeV-powheg-pythia6  SMGGH110  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py  
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/GluGluToHToTauTau_M-115_8TeV-powheg-pythia6  SMGGH115  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py 
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/GluGluToHToTauTau_M-120_8TeV-powheg-pythia6  SMGGH120  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py 
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/GluGluToHToTauTau_M-125_8TeV-powheg-pythia6  SMGGH125  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py 
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/GluGluToHToTauTau_M-130_8TeV-powheg-pythia6  SMGGH130  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py 
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/GluGluToHToTauTau_M-135_8TeV-powheg-pythia6  SMGGH135  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py 
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/GluGluToHToTauTau_M-140_8TeV-powheg-pythia6  SMGGH140  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py 
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/GluGluToHToTauTau_M-145_8TeV-powheg-pythia6  SMGGH145  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py 
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/GluGluToHToTauTau_M-150_8TeV-powheg-pythia6  SMGGH150  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py 
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/GluGluToHToTauTau_M-155_8TeV-powheg-pythia6  SMGGH155  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/GluGluToHToTauTau_M-160_8TeV-powheg-pythia6  SMGGH160  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py 

############################################################################################################################################

farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/swanson/VBFHToTauTau_M-90_8TeV-powheg-pythia6  VBF90  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py 
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/swanson/VBFHToTauTau_M-95_8TeV-powheg-pythia6  VBF95  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py 
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/swanson/VBFHToTauTau_M-100_8TeV-powheg-pythia6  VBF100  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py 
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/swanson/VBFHToTauTau_M-105_8TeV-powheg-pythia6  VBF105  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py 
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/VBF_HToTauTau_M-110_8TeV-powheg-pythia6  VBF110  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py 
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/VBF_HToTauTau_M-115_8TeV-powheg-pythia6  VBF115  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/VBF_HToTauTau_M-120_8TeV-powheg-pythia6  VBF120  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/VBF_HToTauTau_M-125_8TeV-powheg-pythia6  VBF125  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/VBF_HToTauTau_M-130_8TeV-powheg-pythia6  VBF130  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/VBF_HToTauTau_M-135_8TeV-powheg-pythia6  VBF135  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/VBF_HToTauTau_M-140_8TeV-powheg-pythia6  VBF140  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/VBF_HToTauTau_M-145_8TeV-powheg-pythia6  VBF145  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/VBF_HToTauTau_M-150_8TeV-powheg-pythia6  VBF150  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/VBF_HToTauTau_M-155_8TeV-powheg-pythia6  VBF155  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/VBF_HToTauTau_M-160_8TeV-powheg-pythia6  VBF160  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py

############################################################################################################################################

farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/swanson/WH_ZH_TTH_HToTauTau_M-90_8TeV-pythia6-tauola  VH90  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py 
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/swanson/WH_ZH_TTH_HToTauTau_M-95_8TeV-pythia6-tauola  VH95  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py 
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/WH_ZH_TTH_HToTauTau_M-100_8TeV-pythia6-tauola  VH100  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py 
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/WH_ZH_TTH_HToTauTau_M-105_8TeV-pythia6-tauola  VH105  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py 
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/WH_ZH_TTH_HToTauTau_M-110_8TeV-pythia6-tauola  VH110  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py 
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/WH_ZH_TTH_HToTauTau_M-115_8TeV-pythia6-tauola  VH115  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/WH_ZH_TTH_HToTauTau_M-120_8TeV-pythia6-tauola  VH120  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/WH_ZH_TTH_HToTauTau_M-125_8TeV-pythia6-tauola  VH125  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/WH_ZH_TTH_HToTauTau_M-130_8TeV-pythia6-tauola  VH130  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/WH_ZH_TTH_HToTauTau_M-135_8TeV-pythia6-tauola  VH135  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/WH_ZH_TTH_HToTauTau_M-140_8TeV-pythia6-tauola  VH140  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/WH_ZH_TTH_HToTauTau_M-145_8TeV-pythia6-tauola  VH145  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/WH_ZH_TTH_HToTauTau_M-150_8TeV-pythia6-tauola  VH150  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/WH_ZH_TTH_HToTauTau_M-155_8TeV-pythia6-tauola  VH155  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/WH_ZH_TTH_HToTauTau_M-160_8TeV-pythia6-tauola  VH160  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py

