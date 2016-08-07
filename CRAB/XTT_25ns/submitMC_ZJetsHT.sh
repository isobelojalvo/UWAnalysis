#!/bin/sh
voms-proxy-init --voms cms --valid 100:00



farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-files-per-job=1 --input-dbs-path=/DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0_ext1-v1/MINIAODSIM 20160803_80X_ZJetsHT200_ext $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-files-per-job=1 --input-dbs-path=/DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0_ext1-v1/MINIAODSIM 20160803_80X_ZJetsHT400_ext $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-files-per-job=1 --input-dbs-path=/DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0_ext1-v1/MINIAODSIM 20160803_80X_ZJetsHT600_ext $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-files-per-job=1 --input-dbs-path=/DYJetsToLL_M-50_HT-600toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0_ext1-v1/MINIAODSIM 20160803_80X_ZJetsHTInf_ext $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  
