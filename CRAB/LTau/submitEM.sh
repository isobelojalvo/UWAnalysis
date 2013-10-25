#!/bin/sh
voms-proxy-init --voms cms --valid 100:00


farmoutAnalysisJobs  $1   --vsize-limit=8000  --shared-fs  --input-dir=/store/user/swanson/DoubleMu/StoreResults-Run2012A_22Jan2013_v1_PFembedded_trans1_tau115_ptelec1_20had1_18_v1-5ef1c0fd428eb740081f19333520fdc8     	 2012A      $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-ET-EM.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --shared-fs  --input-dir=/store/user/swanson/DoubleMuParked/StoreResults-Run2012B_22Jan2013_v1_PFembedded_trans1_tau115_ptelec1_20had1_18_v1-5ef1c0fd428eb740081f19333520fdc8 	 2012B      $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-ET-EM.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --shared-fs  --input-dir=/store/user/swanson/DoubleMuParked/StoreResults-Run2012C_22Jan2013_v1_PFembedded_trans1_tau115_ptelec1_20had1_18_v1-5ef1c0fd428eb740081f19333520fdc8 	 2012C      $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-ET-EM.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --shared-fs  --input-dir=/store/user/swanson/DoubleMuParked/StoreResults-Run2012D_22Jan2013_v1_PFembedded_trans1_tau115_ptelec1_20had1_18_v1-5ef1c0fd428eb740081f19333520fdc8    2012D      $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-ET-EM.py

farmoutAnalysisJobs  $1   --vsize-limit=8000  --shared-fs  --input-dir=/store/user/swanson/DoubleMu/StoreResults-Run2012A_22Jan2013_v1_PFembedded_trans1_tau116_ptmu1_16had1_18_v1-5ef1c0fd428eb740081f19333520fdc8       	 2012A      $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MT-EM.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --shared-fs  --input-dir=/store/user/swanson/DoubleMuParked/StoreResults-Run2012B_22Jan2013_v1_PFembedded_trans1_tau116_ptmu1_16had1_18_v1-5ef1c0fd428eb740081f19333520fdc8 	 2012B      $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MT-EM.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --shared-fs  --input-dir=/store/user/swanson/DoubleMuParked/StoreResults-Run2012C_22Jan2013_v1_PFembedded_trans1_tau116_ptmu1_16had1_18_v1-5ef1c0fd428eb740081f19333520fdc8 	 2012C      $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MT-EM.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --shared-fs  --input-dir=/store/user/swanson/DoubleMuParked/StoreResults-Run2012D_22Jan2013_v1_PFembedded_trans1_tau116_ptmu1_16had1_18_v1-5ef1c0fd428eb740081f19333520fdc8      2012D      $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MT-EM.py

