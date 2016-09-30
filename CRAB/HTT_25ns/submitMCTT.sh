#!/bin/sh
#voms-proxy-init --voms cms --valid 100:00
#UWAnalysis/CRAB/HTT_25ns/SUB-TT.py
jobID=2016_Sep23

######HIGGS SAMPLES #############
#ggH
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --skip-existing-output --input-dbs-path=/GluGluHToTauTau_M125_13TeV_powheg_pythia8/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM  ${jobID}_ggHtautau_125 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py

farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --skip-existing-output --input-dbs-path=/VBFHToTauTau_M125_13TeV_powheg_pythia8/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM  ${jobID}_vbfHtautau_125 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py

########ZJETS SAMPLES#############
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0_ext1-v1/MINIAODSIM ${jobID}_ZJets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py  

farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/DY1JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM ${jobID}_Z1Jets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/DY2JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM ${jobID}_Z2Jets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/DY3JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM ${jobID}_Z3Jets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/DY4JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM ${jobID}_Z4Jets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py  

farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/DYJetsToLL_M-150_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM ${jobID}_ZJets_150 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py  

########TT SAMPLES################
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-files-per-job=1 --input-dbs-path=/TT_TuneCUETP8M1_13TeV-powheg-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0_ext4-v1/MINIAODSIM ${jobID}_TT $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py  
#farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-files-per-job=1 --input-dbs-path=/TT_TuneCUETP8M1_13TeV-powheg-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0_ext4-v1/MINIAODSIM ${jobID}_TT $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-files-per-job=1 --input-dbs-path=/TTJets_SingleLeptFromTbar_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM ${jobID}_TT_SLTbar $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-files-per-job=1 --input-dbs-path=/TTJets_SingleLeptFromT_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM ${jobID}_TT_SLT $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-files-per-job=1 --input-dbs-path=/TTJets_DiLept_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0_ext1-v1/MINIAODSIM  ${jobID}_TT_DL $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-files-per-job=1 --input-dbs-path=/TTJets_DiLept_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v2/MINIAODSIM  ${jobID}_TT_DL $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py  

##########WJETS SAMPLES#############
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-files-per-job=1 --input-dbs-path=/WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM ${jobID}_WJets_amc $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py  

farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=1 --input-dbs-path=/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v2/MINIAODSIM ${jobID}_WJets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py  

farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=1 --input-dbs-path=/W1JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v1/MINIAODSIM ${jobID}_W1Jets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=1 --input-dbs-path=/W2JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v1/MINIAODSIM ${jobID}_W2Jets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=1 --input-dbs-path=/W3JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v1/MINIAODSIM ${jobID}_W3Jets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=1 --input-dbs-path=/W4JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v1/MINIAODSIM ${jobID}_W4Jets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py  

###########WZ SAMPLES#############

farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-files-per-job=2 --input-dbs-path=/WZ_TuneCUETP8M1_13TeV-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM ${jobID}_WZ $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-files-per-job=2 --input-dbs-path=/WZTo1L3Nu_13TeV_amcatnloFXFX_madspin_pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  ${jobID}_WZTo1L3Nu $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-files-per-job=2 --input-dbs-path=/WZTo3LNu_TuneCUETP8M1_13TeV-powheg-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM ${jobID}_WZTo1L3Nu $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-files-per-job=2 --input-dbs-path=/WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM ${jobID}_WZTo1L1Nu2Q $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-files-per-job=2 --input-dbs-path=/WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM ${jobID}_WZTo2L2Q $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py  


##########SINGLE TOP SAMPLES############# delete the extra things if needed
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v1/MINIAODSIM ${jobID}_tBar_tW $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py  
#farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM ${jobID}_tBar_tW $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v1/MINIAODSIM ${jobID}_t_tW $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py  
#farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v2/MINIAODSIM ${jobID}_t_tW $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v1/MINIAODSIM ${jobID}_St_t_antitop $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py  
#farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ST_t-channel_antitop_4f_inclusiveDecays_13TeV-powhegV2-madspin-pythia8_TuneCUETP8M1/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM ${jobID}_St_t_antitop $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py  
#farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM ${jobID}_St_t_top $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIISpring16MiniAODv1-PUSpring16_80X_mcRun2_asymptotic_2016_v3-v1/MINIAODSIM ${jobID}_St_t_top $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py  


###########WW SAMPLES#############
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/WWTo2L2Nu_13TeV-powheg/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM --input-files-per-job=2  ${jobID}_WWTo2L2Q $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/WW_TuneCUETP8M1_13TeV-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM --input-files-per-job=2  ${jobID}_WW $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py  


###########ZZ SAMPLES#############

farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-files-per-job=2 --input-dbs-path=/ZZ_TuneCUETP8M1_13TeV-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM ${jobID}_ZZ $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-files-per-job=2 --input-dbs-path=/ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM ${jobID}_ZZTo2L2Q $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-files-per-job=2 --input-dbs-path=/ZZTo4L_13TeV_powheg_pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM ${jobID}_ZZTo4L $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py  

