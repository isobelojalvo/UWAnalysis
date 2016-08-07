#!/bin/sh
voms-proxy-init --voms cms --valid 100:00

##########WJETS SAMPLES#############
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-files-per-job=1 --input-dbs-path=/WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0_ext1-v1/MINIAODSIM 20160803_80X_WJetsHT200_ext $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-files-per-job=1 --input-dbs-path=/WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0_ext1-v1/MINIAODSIM 20160803_80X_WJetsHT400_ext $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-files-per-job=1 --input-dbs-path=/WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0_ext1-v1/MINIAODSIM 20160803_80X_WJetsHT600_ext $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-files-per-job=1 --input-dbs-path=/WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0_ext1-v1/MINIAODSIM 20160803_80X_WJetsHT800_ext $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-files-per-job=1 --input-dbs-path=/WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0_ext1-v1/MINIAODSIM 20160803_80X_WJetsHT1200_ext $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-files-per-job=1 --input-dbs-path=/WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0_ext1-v1/MINIAODSIM 20160803_80X_WJetsHT2500_ext $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-files-per-job=1 --input-dbs-path=/WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0_ext1-v1/MINIAODSIM 20160803_80X_WJetsHTInf_ext $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  




