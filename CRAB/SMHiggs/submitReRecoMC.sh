#!/bin/sh

#voms-proxy-init --voms cms --valid 100:00
jobID="mutau_2016_Jan15"
header="--assume-input-files-exist --vsize-limit=8000 --skip-existing-output  --input-files-per-job=1"
tailOptions="  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC.py"

#farmoutAnalysisJobs  $1  $header --input-dbs-path=     ${jobID}_ZJets_150 $1 $tailOptions

farmoutAnalysisJobs  $1 $header --input-dbs-path=/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM       ${jobID}_WJets  $1 $tailOptions
farmoutAnalysisJobs  $1 $header --input-dbs-path=/W1JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM      ${jobID}_W1Jets $1 $tailOptions
farmoutAnalysisJobs  $1 $header --input-dbs-path=/W2JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM      ${jobID}_W2Jets $1 $tailOptions
farmoutAnalysisJobs  $1 $header --input-dbs-path=/W3JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM      ${jobID}_W3Jets $1 $tailOptions
farmoutAnalysisJobs  $1 $header --input-dbs-path=/W4JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM      ${jobID}_W4Jets $1 $tailOptions
farmoutAnalysisJobs  $1 $header --input-dbs-path=/W4JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext2-v1/MINIAODSIM ${jobID}_W4Jets-ext2 $1 $tailOptions

#ZJETS 
farmoutAnalysisJobs  $1  $header --input-dbs-path=/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v2/MINIAODSIM ${jobID}_ZJets $1 $tailOptions
#farmoutAnalysisJobs  $1  $header --input-dbs-path=/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM
farmoutAnalysisJobs  $1  $header --input-dbs-path=/DY1JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM     ${jobID}_Z1Jets $1 $tailOptions
farmoutAnalysisJobs  $1  $header --input-dbs-path=/DY2JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM     ${jobID}_Z2Jets $1 $tailOptions
farmoutAnalysisJobs  $1  $header --input-dbs-path=/DY3JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM     ${jobID}_Z3Jets $1 $tailOptions
farmoutAnalysisJobs  $1  $header --input-dbs-path=/DY4JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM     ${jobID}_Z4Jets $1 $tailOptions
#WZ
farmoutAnalysisJobs  $1  $header --input-dbs-path=/WZTo3LNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM   ${jobID}_WZTo3LNu       $1 $tailOptions
farmoutAnalysisJobs  $1  $header --input-dbs-path=/VVTo2L2Nu_13TeV_amcatnloFXFX_madspin_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM       ${jobID}_VVTo2L2Nu      $1 $tailOptions
farmoutAnalysisJobs  $1  $header --input-dbs-path=/VVTo2L2Nu_13TeV_amcatnloFXFX_madspin_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1/MINIAODSIM  ${jobID}_VVTo2L2Nu-ext1 $1 $tailOptions
farmoutAnalysisJobs  $1  $header --input-dbs-path=/ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM        ${jobID}_ZZTo2L2Q       $1 $tailOptions
farmoutAnalysisJobs  $1  $header --input-dbs-path=/WZTo1L3Nu_13TeV_amcatnloFXFX_madspin_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM       ${jobID}_WZTo1L3Nu      $1 $tailOptions
farmoutAnalysisJobs  $1  $header --input-dbs-path=/WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v3/MINIAODSIM     ${jobID}_WZTo1L1Nu2Q    $1 $tailOptions

farmoutAnalysisJobs  $1  $header --input-dbs-path=/T_s-channel_4f_leptonDecays_13TeV-amcatnlo-pythia8_TuneCUETP8M1/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM                      ${jobID}_t_s_top       $tailOptions
farmoutAnalysisJobs  $1  $header --input-dbs-path=/ST_t-channel_antitop_4f_inclusiveDecays_13TeV-powhegV2-madspin-pythia8_TuneCUETP8M1/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_ST_t_antitop  $tailOptions
farmoutAnalysisJobs  $1  $header --input-dbs-path=/ST_t-channel_top_4f_inclusiveDecays_13TeV-powhegV2-madspin-pythia8_TuneCUETP8M1/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM      ${jobID}_ST_t_top      $tailOptions
farmoutAnalysisJobs  $1  $header --input-dbs-path=/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1/MINIAODSIM              ${jobID}_ST_tW_antitop $tailOptions
farmoutAnalysisJobs  $1  $header --input-dbs-path=/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1/MINIAODSIM                  ${jobID}_ST_tW_top     $tailOptions

farmoutAnalysisJobs  $1  $header --input-dbs-path=/TT_TuneCUETP8M2T4_13TeV-powheg-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM                                 ${jobID}_TT              $tailOptions  

#farmoutAnalysisJobs  $1  $header --input-dbs-path=/TTGJets_TuneCUETP8M1_13TeV-amcatnloFXFX-madspin-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM               ${jobID}_TTGJets         $tailOptions
#farmoutAnalysisJobs  $1  $header --input-dbs-path=/TTJets_DiLept_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM                  ${jobID}_TTJets_DiLep    $tailOptions
#farmoutAnalysisJobs  $1  $header --input-dbs-path=/TTJets_SingleLeptFromT_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM         ${jobID}_TTJets_Tlep     $tailOptions
#farmoutAnalysisJobs  $1  $header --input-dbs-path=/TTJets_SingleLeptFromTbar_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1/MINIAODSIM ${jobID}_TTJets_TbarLep  $tailOptions

