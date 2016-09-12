#!/bin/sh
voms-proxy-init --voms cms --valid 100:00


#Submit the reprocessed Data
#/cms/sw/farmout/farmoutAnalysisJobs.fix  $1  --assume-input-files-exist --skip-existing-output --vsize-limit=8000    --input-files-per-job=1 --input-dbs-path=/SingleMuon/Run2016B-01Jul2016-v2/MINIAOD SINGLEMUON2016BJul01_SMHiggs_Aug26 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-JSON.py  
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1  --assume-input-files-exist --skip-existing-output --vsize-limit=8000    --input-files-per-job=1 --input-dbs-path=/SingleMuon/Run2016B-29Jul2016-v1/MINIAOD SINGLEMUON2016BJul29_SMHiggs_Aug26 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-JSON.py  
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1  --assume-input-files-exist --skip-existing-output --vsize-limit=8000    --input-files-per-job=1 --input-dbs-path=/SingleMuon/Run2016E-29Jul2016-v1/MINIAOD SINGLEMUON2016EJul29_SMHiggs_Aug26 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-JSON.py  

/cms/sw/farmout/farmoutAnalysisJobs.fix  $1  --assume-input-files-exist --skip-existing-output --vsize-limit=8000    --input-files-per-job=1 --input-dbs-path=/SingleMuon/Run2016G-PromptReco-v1/MINIAOD SINGLEMUON2016G_SMHiggs_Aug26 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-JSON.py  


