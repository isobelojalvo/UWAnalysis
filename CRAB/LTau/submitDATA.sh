#!/bin/sh
voms-proxy-init --voms cms --valid 100:00


farmoutAnalysisJobs   $1   --vsize-limit=8000  --shared-fs  --input-dir=/store/user/tapas/TauPlusX/Run2012A-22Jan2013-v1     2012A       $CMSSW_BASE   $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB_JSON.py
farmoutAnalysisJobs   $1   --vsize-limit=8000  --shared-fs  --input-dir=/store/user/tapas/TauPlusX/Run2012B-22Jan2013-v1     2012B       $CMSSW_BASE   $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB_JSON.py
farmoutAnalysisJobs   $1   --vsize-limit=8000  --shared-fs  --input-dir=/store/user/tapas/TauPlusX/Run2012C-22Jan2013-v1     2012C       $CMSSW_BASE   $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB_JSON.py
farmoutAnalysisJobs   $1   --vsize-limit=8000  --shared-fs  --input-dir=/store/user/tapas/TauPlusX/Run2012D-22Jan2013-v1     2012D       $CMSSW_BASE   $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB_JSON.py
