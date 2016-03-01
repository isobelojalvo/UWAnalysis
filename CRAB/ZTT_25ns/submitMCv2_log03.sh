#!/bin/sh
#voms-proxy-init --voms cms --valid 100:00



###########WZ SAMPLES#############
#farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=2 --input-dbs-path=/WZ_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_NoShapes_Feb28_WZ $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  

farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=2 --input-dbs-path=/WZJets_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_NoShapes_Feb28_WZJets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  

farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=2 --input-dbs-path=/WZTo1L3Nu_13TeV_amcatnloFXFX_madspin_pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_NoShapes_Feb28_WZTo1L3Nu $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  

farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=2 --input-dbs-path=/WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM 25ns_NoShapes_Feb28_WZTo1L1Nu2Q $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  

farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=2 --input-dbs-path=/WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM 25ns_NoShapes_Feb28_WZTo2L2Q $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  


##########SINGLE TOP SAMPLES#############
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM 25ns_NoShapes_Feb28_tBar_tW $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM 25ns_NoShapes_Feb28_t_tW $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM 25ns_NoShapes_Feb28_St_t_antitop $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM 25ns_NoShapes_Feb28_St_t_top $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  

###########WW SAMPLES#############
#farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=2 --input-dbs-path=/WW_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_NoShapes_Feb28_WW $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  

#farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=2 =WWTo2L2Nu.txt  25ns_NoShapes_Feb28_WWTo2L2Nu $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  
#farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=2 =WWTo4Q.txt  25ns_NoShapes_Feb28_WWTo4Q $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/WWTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM --input-files-per-job=2  25ns_NoShapes_Feb28_WWToLNu2Q $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  


###########ZZ SAMPLES#############
#farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=2 --input-dbs-path=/ZZ_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_NoShapes_Feb28_ZZ $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  

farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=2 --input-dbs-path=/ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM 25ns_NoShapes_Feb28_ZZTo2L2Q $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  
#farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=2 =ZZTo4Q.txt  25ns_NoShapes_Feb28_ZZTo4Q $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=2 --input-dbs-path=/ZZTo4L_13TeV-amcatnloFXFX-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM	 25ns_NoShapes_Feb28_ZZTo4L $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  

