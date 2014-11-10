#!/bin/sh
voms-proxy-init --voms cms --valid 100:00

#cat LT.py > SUB_JSON.py
#cat CONDORPT.py >> SUB_JSON.py

#farmoutAnalysisJobs   $1   --vsize-limit=8000   --skip-existing-output --input-dir=/store/user/laura/TauPlusX/Run2012A-22Jan2013-v1/AOD/SL5-Oct-22/     2012A       $CMSSW_BASE   $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB_JSON.py
#farmoutAnalysisJobs   $1   --vsize-limit=8000   --skip-existing-output --input-dir=/store/user/laura/TauPlusX/Run2012B-22Jan2013-v1/AOD/SL5-Oct-22/     2012B       $CMSSW_BASE   $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB_JSON.py
farmoutAnalysisJobs   $1   --vsize-limit=8000  --input-dir=/store/user/laura/TauPlusX/Run2012C-22Jan2013-v1/AOD/SL5-Oct-22/     2012C_lumicheck       $CMSSW_BASE   $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB_JSON.py
farmoutAnalysisJobs   $1   --vsize-limit=8000  --input-dir=/store/user/laura/TauPlusX/Run2012D-22Jan2013-v1/AOD/SL5-Oct-22/     2012D_lumicheck       $CMSSW_BASE   $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB_JSON.py

#rm SUB_JSON.py

#/store/user/laura/TauPlusX/Run2012A-22Jan2013-v1/AOD/SL5-Oct-22/
