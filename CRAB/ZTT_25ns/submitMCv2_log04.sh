#!/bin/sh
#voms-proxy-init --voms cms --valid 100:00


########TT SAMPLES################

farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=1 --input-dbs-path=/TT_TuneCUETP8M1_13TeV-powheg-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12_ext4-v1/MINIAODSIM 25ns_Apr25_TT_ext4 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py 

##########WJETS SAMPLES#############

farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=1 --input-dbs-path=/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_Apr25_WJets_MLM $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  

farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=1 --input-dbs-path=/W1JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM 25ns_Apr25_W1Jets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=1 --input-dbs-path=/W2JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM 25ns_Apr25_W2Jets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=1 --input-dbs-path=/W3JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM 25ns_Apr25_W3Jets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=1 --input-dbs-path=/W4JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM 25ns_Apr25_W4Jets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  


