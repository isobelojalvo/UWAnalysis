#!/bin/sh
#voms-proxy-init --voms cms --valid 100:00


######HIGGS SAMPLES #############
#ggH
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/GluGluHToTauTau_M125_13TeV_powheg_pythia8/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v1/MINIAODSIM  20160620_80X_ggHtautau_125 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py

########ZJETS SAMPLES#############
#farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v1/MINIAODSIM 20160620_80X_ZJets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3_ext1-v1/MINIAODSIM 20160620_80X_ZJets_ext $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  

farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/DY1JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v1/MINIAODSIM 20160620_80X_Z1Jets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/DY2JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v1/MINIAODSIM 20160620_80X_Z2Jets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/DY3JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v1/MINIAODSIM 20160620_80X_Z3Jets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/DY4JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v1/MINIAODSIM 20160620_80X_Z4Jets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  

farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/DYJetsToLL_M-150_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v1/MINIAODSIM 20160620_80X_ZJets_150 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  

########TT SAMPLES################
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=1 --input-dbs-path=/TTJets_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v3/MINIAODSIM 20160620_80X_TT $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  
#farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=1 --input-dbs-path=/TT_TuneCUETP8M1_13TeV-powheg-pythia8/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3_ext4-v1/MINIAODSIM 20160620_80X_TT $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  

##########WJETS SAMPLES#############

farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=1 --input-dbs-path=/WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v1/MINIAODSIM 20160620_80X_WJetsAMC $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  

farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=1 --input-dbs-path=/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v2/MINIAODSIM 20160620_80X_WJets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  

farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=1 --input-dbs-path=/W1JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v1/MINIAODSIM 20160620_80X_W1Jets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=1 --input-dbs-path=/W2JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v1/MINIAODSIM 20160620_80X_W2Jets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=1 --input-dbs-path=/W3JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v1/MINIAODSIM 20160620_80X_W3Jets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=1 --input-dbs-path=/W4JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v1/MINIAODSIM 20160620_80X_W4Jets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  

###########WZ SAMPLES#############

farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=2 --input-dbs-path=/WZTo1L3Nu_13TeV_amcatnloFXFX_madspin_pythia8/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v1/MINIAODSIM  20160620_80X_WZTo1L3Nu $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=2 --input-dbs-path=/WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v1/MINIAODSIM 20160620_80X_WZTo1L1Nu2Q $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=2 --input-dbs-path=/WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v1/MINIAODSIM 20160620_80X_WZTo2L2Q $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  


##########SINGLE TOP SAMPLES#############

farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v1/MINIAODSIM 20160620_80X_tBar_tW $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v1/MINIAODSIM 20160620_80X_t_tW $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v1/MINIAODSIM 20160620_80X_St_t_antitop $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v1/MINIAODSIM 20160620_80X_St_t_top $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  

###########WW SAMPLES#############
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist  --input-files-per-job=2 --input-dbs-path=/WWTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v1/MINIAODSIM  20160620_80X_WWTo2L2Q $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  


###########ZZ SAMPLES#############

farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=2 --input-dbs-path=/ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v1/MINIAODSIM 20160620_80X_ZZTo2L2Q $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  

###########VV SAMPLES#############
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=2 --input-dbs-path=/VVTo2L2Nu_13TeV_amcatnloFXFX_madspin_pythia8/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v1/MINIAODSIM 20160620_80X_VVTo2L2Nu $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py  