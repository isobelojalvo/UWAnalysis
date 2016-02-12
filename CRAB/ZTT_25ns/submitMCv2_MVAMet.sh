#!/bin/sh
voms-proxy-init --voms cms --valid 100:00


######HIGGS SAMPLES #############
#ggH
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/GluGluHToTauTau_M120_13TeV_powheg_pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_ggHtautau_120 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/GluGluHToTauTau_M125_13TeV_powheg_pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_ggHtautau_125 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/GluGluHToTauTau_M130_13TeV_powheg_pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_ggHtautau_130 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py

#vbf
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/VBFHToTauTau_M120_13TeV_powheg_pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_vbfHtautau_120 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/VBFHToTauTau_M125_13TeV_powheg_pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_vbfHtautau_125 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/VBFHToTauTau_M130_13TeV_powheg_pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_vbfHtautau_130 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py


#MSSM
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToHToTauTau_M-80_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_susyggHtautau_80 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToHToTauTau_M-90_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_susyggHtautau_90 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToHToTauTau_M-100_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_susyggHtautau_100 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToHToTauTau_M-110_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_susyggHtautau_110 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToHToTauTau_M-120_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_susyggHtautau_120 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToHToTauTau_M-130_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_susyggHtautau_130 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToHToTauTau_M-140_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_susyggHtautau_140 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToHToTauTau_M-160_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_susyggHtautau_160 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToHToTauTau_M-180_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_susyggHtautau_180 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToHToTauTau_M-200_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_susyggHtautau_200 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToHToTauTau_M-250_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_susyggHtautau_250 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToHToTauTau_M-300_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_susyggHtautau_300 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToHToTauTau_M-350_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_susyggHtautau_350 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToHToTauTau_M-400_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_susyggHtautau_400 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToHToTauTau_M-450_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_susyggHtautau_450 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToHToTauTau_M-500_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_susyggHtautau_500 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToHToTauTau_M-600_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_susyggHtautau_600 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToHToTauTau_M-700_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_susyggHtautau_700 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToHToTauTau_M-800_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_susyggHtautau_800 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToHToTauTau_M-900_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_susyggHtautau_900 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToHToTauTau_M-1000_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_susyggHtautau_1000 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToHToTauTau_M-1200_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_susyggHtautau_1200 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToHToTauTau_M-1400_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_susyggHtautau_1400 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToHToTauTau_M-1500_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_susyggHtautau_1500 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToHToTauTau_M-1600_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_susyggHtautau_1600 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToHToTauTau_M-1800_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_susyggHtautau_1800 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToHToTauTau_M-2000_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_susyggHtautau_2000 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToHToTauTau_M-2300_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_susyggHtautau_2300 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToHToTauTau_M-2600_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_susyggHtautau_2600 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToHToTauTau_M-2900_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_susyggHtautau_2900 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/SUSYGluGluToHToTauTau_M-3200_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_susyggHtautau_3200 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py


########ZJETS SAMPLES#############
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM 25ns_MVAMet_ZJets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/DY2JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM 25ns_MVAMet_Z2Jets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/DY3JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM 25ns_MVAMet_Z3Jets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/DY4JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM 25ns_MVAMet_Z4Jets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py  

#######Low Mass ZJets##########
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM 25ns_MVAMet_ZJets_1050 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/DY2JetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM 25ns_MVAMet_Z2Jets_1050 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py  

########TT SAMPLES################
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=1 --input-dbs-path=/TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM   25ns_MVAMet_TTJets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py  

farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=1 --input-dbs-path=/TT_TuneCUETP8M1_13TeV-amcatnlo-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_TT $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py  

##########WJETS SAMPLES#############
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=1 --input-dbs-path=/WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_WJets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py  

###########VV SAMPLES#############
#farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=2 =VV.txt  25ns_MVAMet_VV $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py  


###########WZ SAMPLES#############
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=2 --input-dbs-path=/WZ_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_WZ $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=2 --input-dbs-path=/WZJets_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_WZJets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py  


##########SINGLE TOP SAMPLES#############
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM 25ns_MVAMet_tBar_tW $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM 25ns_MVAMet_t_tW $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py  
#farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path= =ST_t_antitop.txt 25ns_MVAMet_St_t_antitop $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM 25ns_MVAMet_St_t_top $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py  

###########WW SAMPLES#############
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=2 --input-dbs-path=/WW_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_WW $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py  
#farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=2 =WWTo2L2Nu.txt  25ns_MVAMet_WWTo2L2Nu $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py  
#farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=2 =WWTo4Q.txt  25ns_MVAMet_WWTo4Q $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py  
#farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=2 =WWTo1L1Nu2Q.txt  25ns_MVAMet_WWToLNu2Q.txt $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py  


###########ZZ SAMPLES#############
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=2 --input-dbs-path=/ZZ_TuneCUETP8M1_13TeV-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_MVAMet_ZZ $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py  
#farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=2 =ZZTo2L2Q.txt  25ns_MVAMet_ZZTo2L2Q $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py  
#farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=2 =ZZTo4Q.txt  25ns_MVAMet_ZZTo4Q $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py  
#farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=2 =ZZTo4L.txt  25ns_MVAMet_ZZTo4L $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC-MVAMet.py  

