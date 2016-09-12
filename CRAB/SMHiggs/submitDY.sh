#!/bin/sh
#voms-proxy-init --voms cms --valid 100:00
/cms/sw/farmout/farmoutAnalysisJobs.fix $1 --vsize-limit=8000  --skip-existing-output --assume-input-files-exist --input-dbs-path=/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_80X_mcRun2_asymptotic_2016_miniAODv2_v0_ext1-v1/MINIAODSIM 20160829_SMHiggs_ZJets_ext $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC-Zee.py  

/cms/sw/farmout/farmoutAnalysisJobs.fix $1 --vsize-limit=8000    --skip-existing-output --assume-input-files-exist --input-dbs-path=/DY1JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM 20160829_SMHiggs_Z1Jets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC-Zee.py  
/cms/sw/farmout/farmoutAnalysisJobs.fix $1 --vsize-limit=8000    --skip-existing-output --assume-input-files-exist --input-dbs-path=/DY2JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM 20160829_SMHiggs_Z2Jets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC-Zee.py  
/cms/sw/farmout/farmoutAnalysisJobs.fix $1 --vsize-limit=8000   --skip-existing-output  --assume-input-files-exist --input-dbs-path=/DY3JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM 20160829_SMHiggs_Z3Jets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC-Zee.py  
/cms/sw/farmout/farmoutAnalysisJobs.fix $1 --vsize-limit=8000  --skip-existing-output   --assume-input-files-exist --input-dbs-path=/DY4JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM 20160829_SMHiggs_Z4Jets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC-Zee.py  

/cms/sw/farmout/farmoutAnalysisJobs.fix $1 --vsize-limit=8000  --skip-existing-output   --assume-input-files-exist --input-dbs-path=/DYJetsToLL_M-150_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM 20160829_SMHiggs_ZJets_150 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC-Zee.py  


