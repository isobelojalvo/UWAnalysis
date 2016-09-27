#!/bin/sh
voms-proxy-init --voms cms --valid 100:00

#PromptREco
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1  --assume-input-files-exist --vsize-limit=8000    --input-files-per-job=1 --input-dbs-path=/SingleMuon/Run2016B-PromptReco-v2/MINIAOD SINGLEMUON2016B_SMHiggs_Sep15 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-JSON.py  
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1  --assume-input-files-exist --vsize-limit=8000    --input-files-per-job=1 --input-dbs-path=/SingleMuon/Run2016C-PromptReco-v2/MINIAOD SINGLEMUON2016C_SMHiggs_Sep15 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-JSON.py  
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1  --assume-input-files-exist --vsize-limit=8000    --input-files-per-job=1 --input-dbs-path=/SingleMuon/Run2016D-PromptReco-v2/MINIAOD SINGLEMUON2016D_SMHiggs_Sep15 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-JSON.py  
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1  --assume-input-files-exist --vsize-limit=8000    --input-files-per-job=1 --input-dbs-path=/SingleMuon/Run2016E-PromptReco-v2/MINIAOD SINGLEMUON2016E_SMHiggs_Sep15 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-JSON.py  
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1  --assume-input-files-exist --vsize-limit=8000    --input-files-per-job=1 --input-dbs-path=/SingleMuon/Run2016F-PromptReco-v1/MINIAOD SINGLEMUON2016F_SMHiggs_Sep15 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-JSON.py  

#/cms/sw/farmout/farmoutAnalysisJobs.fix  $1  --assume-input-files-exist --vsize-limit=8000    --input-files-per-job=1 --input-dbs-path=/SingleMuon/Run2016G-PromptReco-v1/MINIAOD SINGLEMUON2016G_SMHiggs_Sep15 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-JSON.py  

/cms/sw/farmout/farmoutAnalysisJobs.fix  $1  --assume-input-files-exist --vsize-limit=8000    --input-files-per-job=1 --input-dbs-path=/SingleElectron/Run2016B-PromptReco-v2/MINIAOD SINGLEELE2016B_SMHiggs_Sep15 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-JSON.py  
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1  --assume-input-files-exist --vsize-limit=8000    --input-files-per-job=1 --input-dbs-path=/SingleElectron/Run2016C-PromptReco-v2/MINIAOD SINGLEELE2016C_SMHiggs_Sep15 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-JSON.py  
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1  --assume-input-files-exist --vsize-limit=8000    --input-files-per-job=1 --input-dbs-path=/SingleElectron/Run2016D-PromptReco-v2/MINIAOD SINGLEELE2016D_SMHiggs_Sep15 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-JSON.py  
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1  --assume-input-files-exist --vsize-limit=8000    --input-files-per-job=1 --input-dbs-path=/SingleElectron/Run2016E-PromptReco-v2/MINIAOD SINGLEELE2016E_SMHiggs_Sep15 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-JSON.py  
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1  --assume-input-files-exist --vsize-limit=8000    --input-files-per-job=1 --input-dbs-path=/SingleElectron/Run2016F-PromptReco-v1/MINIAOD SINGLEELE2016F_SMHiggs_Sep15 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-JSON.py  

#/cms/sw/farmout/farmoutAnalysisJobs.fix  $1  --assume-input-files-exist --vsize-limit=8000    --input-files-per-job=1 --input-dbs-path=/Tau/Run2016B-PromptReco-v2/MINIAOD TAU2016B_SMHiggs_Sep15 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-JSON.py  
#/cms/sw/farmout/farmoutAnalysisJobs.fix  $1  --assume-input-files-exist --vsize-limit=8000    --input-files-per-job=1 --input-dbs-path=/Tau/Run2016C-PromptReco-v2/MINIAOD TAU2016C_SMHiggs_Sep15 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-JSON.py  
#/cms/sw/farmout/farmoutAnalysisJobs.fix  $1  --assume-input-files-exist --vsize-limit=8000    --input-files-per-job=1 --input-dbs-path=/Tau/Run2016D-PromptReco-v2/MINIAOD TAU2016D_SMHiggs_Sep15 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-JSON.py  

