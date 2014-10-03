#!/bin/sh
#voms-proxy-init --voms cms --valid 100:00

#cat LT.py > SUB_JSON.py
#cat CONDORPT.py >> SUB_JSON.py

farmoutAnalysisJobs   $1   --vsize-limit=8000  --input-dir=/store/user/ojalvo/TauPlusX/Run2012A-22Jan2013-v1/AOD/SL5-Aug-10/     2012A       $CMSSW_BASE   $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB_JSON.py
farmoutAnalysisJobs   $1   --vsize-limit=8000  --input-dir=/store/user/ojalvo/TauPlusX/Run2012B-22Jan2013-v1/AOD/SL5-Aug-10/     2012B       $CMSSW_BASE   $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB_JSON.py
farmoutAnalysisJobs   $1   --vsize-limit=8000  --input-dir=/store/user/ojalvo/TauPlusX/Run2012C-22Jan2013-v1/AOD/SL5-Aug-10/     2012C       $CMSSW_BASE   $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB_JSON.py
farmoutAnalysisJobs   $1   --vsize-limit=8000  --input-dir=/store/user/ojalvo/TauPlusX/Run2012D-22Jan2013-v1/AOD/SL5-Aug-10/     2012D       $CMSSW_BASE   $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB_JSON.py

#rm SUB_JSON.py

#/store/user/ojalvo/TauPlusX/Run2012A-22Jan2013-v1/AOD/SL5-Aug-10/