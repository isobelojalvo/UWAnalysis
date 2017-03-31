#!/bin/sh
#voms-proxy-init --voms cms --valid 100:00
#UWAnalysis/CRAB/HTT_25ns/SUB-TT.py
jobID=2017_Mar31

jobOptions="--vsize-limit=8000  --input-files-per-job=1 --assume-input-files-exist"
tailOptions="  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/SUB-TT.py"
######HIGGS SAMPLES #############
#ggH
##missing samples commented
submitmc=1;
submitW=1;
submitZ=1;
submithiggs=1;

#submit these Feb22 9:35am
#farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/GluGluHToTauTau_M110_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM              ${jobID}_ggHtautau_110  $tailOptions
#farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/GluGluHToTauTau_M120_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1/MINIAODSIM         ${jobID}_ggHtautau_120  $tailOptions
#farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/GluGluHToTauTau_M130_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1/MINIAODSIM         ${jobID}_ggHtautau_130  $tailOptions
#farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/GluGluHToTauTau_M140_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM              ${jobID}_ggHtautau_140  $tailOptions
#farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/VBFHToTauTau_M110_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM                 ${jobID}_vbfHtautau_110  $tailOptions
#farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/VBFHToTauTau_M120_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1/MINIAODSIM            ${jobID}_vbfHtautau_120  $tailOptions
#farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/VBFHToTauTau_M130_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1/MINIAODSIM             ${jobID}_vbfHtautau_130  $tailOptions
#farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/VBFHToTauTau_M140_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM                 ${jobID}_vbfHtautau_140  $tailOptions
#farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v2/MINIAODSIM ${jobID}_ZJets      $tailOptions
#farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/ttHJetToTT_M125_13TeV_amcatnloFXFX_madspin_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext4-v1/MINIAODSIM  ${jobID}_ttHtautau_125  $tailOptions

if [ $submithiggs -eq 1 ]
then
    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/GluGluHToTauTau_M110_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM              ${jobID}_ggHtautau_110  $tailOptions
    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/GluGluHToTauTau_M120_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1/MINIAODSIM         ${jobID}_ggHtautau_120  $tailOptions
    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/GluGluHToTauTau_M125_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM              ${jobID}_ggHtautau_125  $tailOptions
    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/GluGluHToTauTau_M130_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1/MINIAODSIM         ${jobID}_ggHtautau_130  $tailOptions
    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/GluGluHToTauTau_M140_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM              ${jobID}_ggHtautau_140  $tailOptions
    
    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/VBFHToTauTau_M110_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM                 ${jobID}_vbfHtautau_110  $tailOptions
    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/VBFHToTauTau_M120_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1/MINIAODSIM            ${jobID}_vbfHtautau_120  $tailOptions
    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/VBFHToTauTau_M125_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM                 ${jobID}_vbfHtautau_125  $tailOptions
    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/VBFHToTauTau_M130_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1/MINIAODSIM            ${jobID}_vbfHtautau_130  $tailOptions
    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/VBFHToTauTau_M140_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM                 ${jobID}_vbfHtautau_140  $tailOptions
    
    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/WplusHToTauTau_M120_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM           ${jobID}_WpHtautau_120  $tailOptions
    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/WplusHToTauTau_M125_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM           ${jobID}_WpHtautau_125  $tailOptions
    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/WplusHToTauTau_M130_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM           ${jobID}_WpHtautau_130  $tailOptions
    
    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/WminusHToTauTau_M120_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM          ${jobID}_WmHtautau_120  $tailOptions
    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/WminusHToTauTau_M125_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM          ${jobID}_WmHtautau_125  $tailOptions
    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/WminusHToTauTau_M130_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM          ${jobID}_WmHtautau_130  $tailOptions
    
    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/ZHToTauTau_M120_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM               ${jobID}_ZHtautau_120  $tailOptions
    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/ZHToTauTau_M125_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM               ${jobID}_ZHtautau_125  $tailOptions
    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/ZHToTauTau_M130_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM               ${jobID}_ZHtautau_130  $tailOptions
    
    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/ttHJetToTT_M120_13TeV_amcatnloFXFX_madspin_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM       ${jobID}_ttHtautau_120  $tailOptions
    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/ttHJetToTT_M125_13TeV_amcatnloFXFX_madspin_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext4-v1/MINIAODSIM  ${jobID}_ttHtautau_125  $tailOptions
    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/ttHJetToTT_M130_13TeV_amcatnloFXFX_madspin_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM       ${jobID}_ttHtautau_130  $tailOptions
fi

########ZJETS SAMPLES#############
if [ $submitZ -eq 1 ]
then
    farmoutAnalysisJobs  $1  $jobOptions --input-dbs-path=/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v2/MINIAODSIM ${jobID}_ZJets      $tailOptions
    farmoutAnalysisJobs  $1  $jobOptions --input-file-list=files/ZJets-ext.txt ${jobID}_ZJets-ext  $tailOptions

    farmoutAnalysisJobs  $1  $jobOptions --input-dbs-path=/DY1JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM     ${jobID}_Z1Jets     $tailOptions
    farmoutAnalysisJobs  $1  $jobOptions --input-dbs-path=/DY2JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM     ${jobID}_Z2Jets     $tailOptions
    farmoutAnalysisJobs  $1  $jobOptions --input-dbs-path=/DY3JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM     ${jobID}_Z3Jets     $tailOptions
    farmoutAnalysisJobs  $1  $jobOptions --input-dbs-path=/DY4JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM     ${jobID}_Z4Jets     $tailOptions
##Need me
#farmoutAnalysisJobs $1 $jobOptions --input-dbs-path=/DYJetsToLL_M-150_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM     ${jobID}_ZJets_150 $tailOptions  
fi

if [ $submitW -eq 1 ]
then
##########WJETS SAMPLES#############
    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM       ${jobID}_WJets   $tailOptions
    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/W1JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM      ${jobID}_W1Jets  $tailOptions
    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/W2JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM      ${jobID}_W2Jets  $tailOptions
    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/W3JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM      ${jobID}_W3Jets  $tailOptions
    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/W4JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM      ${jobID}_W4Jets  $tailOptions
    farmoutAnalysisJobs  $1 $jobOptions --input-file-list=files/W4Jets-ext.txt ${jobID}_W4Jets-ext2  $tailOptions
    
    farmoutAnalysisJobs $1 $jobOptions --input-dbs-path=/WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM   ${jobID}_WJets_amc $tailOptions  
fi

if [ $submitmc -eq 1 ]
########TT SAMPLES################
then
    #farmoutAnalysisJobs  $1  $jobOptions --input-dbs-path=/TT_TuneCUETP8M2T4_13TeV-powheg-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM                            ${jobID}_TT        $tailOptions
    farmoutAnalysisJobs  $1  $jobOptions --input-file-list=$CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/files/TTJets.txt                            ${jobID}_TT        $tailOptions
#farmoutAnalysisJobs $1 $jobOptions --input-dbs-path=/TTJets_SingleLeptFromTbar_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM ${jobID}_TT_SLTbar $tailOptions  
#farmoutAnalysisJobs $1 $jobOptions --input-dbs-path=/TTJets_SingleLeptFromT_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM    ${jobID}_TT_SLT    $tailOptions  
#farmoutAnalysisJobs $1 $jobOptions --input-dbs-path=/TTJets_DiLept_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0_ext1-v1/MINIAODSIM        ${jobID}_TT_DL     $tailOptions  
    
###########WZ SAMPLES#############
    
#WZ
    farmoutAnalysisJobs  $1  $jobOptions --input-file-list=$CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/files/WZTo3LNu.txt      ${jobID}_WZTo3L1Nu       $1 $tailOptions
    farmoutAnalysisJobs  $1  $jobOptions --input-file-list=$CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/files/WZTo1L3Nu.txt     ${jobID}_WZTo1L3Nu      $1 $tailOptions
    farmoutAnalysisJobs  $1  $jobOptions --input-file-list=$CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/files/WZTo1L1Nu2Q.txt   ${jobID}_WZTo1L1Nu2Q    $1 $tailOptions
    farmoutAnalysisJobs  $1  $jobOptions --input-file-list=$CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/files/WZJToLLLNu.txt    ${jobID}_WZJTo3L1Nu  $tailOptions  
    
#need these ones
#farmoutAnalysisJobs $1 $jobOptions  --input-file-list=$CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/files//WZ_TuneCUETP8M1_13TeV-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM                               ${jobID}_WZ          $tailOptions  
#farmoutAnalysisJobs $1 $jobOptions  --input-file-list=$CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/files//WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM                 ${jobID}_WZTo2L2Q    $tailOptions
    
##########SINGLE TOP SAMPLES############# 
    farmoutAnalysisJobs  $1  $jobOptions --input-file-list=$CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/files/ST_tW_antitop_5f.txt         ${jobID}_tBar_tW       $tailOptions
    farmoutAnalysisJobs  $1  $jobOptions --input-file-list=$CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/files/ST_tW_top_5f.txt             ${jobID}_t_tW          $tailOptions
    farmoutAnalysisJobs  $1  $jobOptions --input-file-list=$CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/files/ST_t-channel_antitop_4f.txt  ${jobID}_ST_t_antitop  $tailOptions
    farmoutAnalysisJobs  $1  $jobOptions --input-file-list=$CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/files/ST_t-channel_top_4f.txt      ${jobID}_ST_t_top      $tailOptions
    
###########WW SAMPLES#############
##need these samples
    farmoutAnalysisJobs $1 $jobOptions --input-file-list=$CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/files/WW.txt           ${jobID}_WW           $tailOptions  
    farmoutAnalysisJobs $1 $jobOptions --input-file-list=$CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/files/WWTo1L1Nu2Q.txt  ${jobID}_WWTo1L1Nu2Q  $tailOptions  
    
###########ZZ SAMPLES#############
    farmoutAnalysisJobs  $1  $jobOptions --input-file-list=$CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/files/VVTo2L2Nu.txt      ${jobID}_VVTo2L2Nu       $tailOptions
    farmoutAnalysisJobs  $1  $jobOptions --input-file-list=$CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/files/VVTo2L2Nu-ext.txt  ${jobID}_VVTo2L2Nu-ext1  $tailOptions
    farmoutAnalysisJobs  $1  $jobOptions --input-file-list=$CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/files/ZZTo2L2Q.txt       ${jobID}_ZZTo2L2Q        $tailOptions
    farmoutAnalysisJobs  $1  $jobOptions --input-file-list=$CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/files/ZZTo4L.txt         ${jobID}_ZZTo4L          $tailOptions  
    
##Need me
#farmoutAnalysisJobs $1 $jobOptions  --input-file-list=$CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/files//ZZ_TuneCUETP8M1_13TeV-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM                               ${jobID}_ZZ           $tailOptions  
    
##########TriBoson SAMPLES#######
##need me
    farmoutAnalysisJobs $1 $jobOptions  --input-file-list=$CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/files/WWW.txt               ${jobID}_WWW    $tailOptions  
    farmoutAnalysisJobs $1 $jobOptions  --input-file-list=$CMSSW_BASE/src/UWAnalysis/CRAB/HTT_25ns/files/ZZZ.txt               ${jobID}_ZZZ    $tailOptions  
fi
