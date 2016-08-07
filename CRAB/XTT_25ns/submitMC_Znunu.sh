#!/bin/sh
voms-proxy-init --voms cms --valid 100:00

########ZJETS SAMPLES#############

farmoutAnalysisJobs $1 --vsize-limit=8000 --skip-existing-output --assume-input-files-exist --input-dbs-path=/ZJetsToNuNu_HT-100To200_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM 20160803_80X_ZNuNuJets_HT200 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --skip-existing-output --assume-input-files-exist --input-dbs-path=/ZJetsToNuNu_HT-200To400_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM 20160803_80X_ZNuNuJets_HT400 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --skip-existing-output --assume-input-files-exist --input-dbs-path=/ZJetsToNuNu_HT-400To600_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM 20160803_80X_ZNuNuJets_HT600 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --skip-existing-output --assume-input-files-exist --input-dbs-path=/ZJetsToNuNu_HT-600To800_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM 20160803_80X_ZNuNuJets_HT800 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --skip-existing-output --assume-input-files-exist --input-dbs-path=/ZJetsToNuNu_HT-800To1200_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM 20160803_80X_ZNuNuJets_HT1200 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --skip-existing-output --assume-input-files-exist --input-dbs-path=/ZJetsToNuNu_HT-1200To2500_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM 20160803_80X_ZNuNuJets_HT2500 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --skip-existing-output --assume-input-files-exist --input-dbs-path=/ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM 20160803_80X_ZNuNuJets_HTInf $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  


