#!/bin/bash


#source environment.sh
set -o errexit
set -o nounset


#cd ../
#git clone https://github.com/cms-analysis/TauAnalysis-CandidateTools.git TauAnalysis/CandidateTools
#pushd $CMSSW_BASE/src/TauAnalysis/CandidateTools
#git checkout TauAnalysis-CandidateTools-V00-01-04s
#pushd $CMSSW_BASE/src

git clone git@github.com:veelken/SVFit_standalone.git TauAnalysis/SVfitStandalone
cd TauAnalysis/SVfitStandalone
git checkout tags/2015Feb10
pushd $CMSSW_BASE/src

#cp -r /cms/laura/UWAnalysis13/CMSSW_7_3_3/src/AnalysisDataFormats/ .
cp /cms/ojalvo/mssm8TeV/CMSSW_5_3_7/src/UWAnalysis/Configuration/data/factoryJetRegNewGenJets* UWAnalysis/Configuration/data/.

#set +o errexit
#echo "Applying pat trigger matching speedup"
#git cms-addpkg DataFormats/PatCandidates
#git apply UWAnalysis/recipeFSA/patches/DataFormats_PatCandidates_TriggerEvent.cc.patch
#set -o errexit

#Get Electron PHYS14 Ids
#git cms-merge-topic HuguesBrun:trigElecIdInCommonIsoSelection720


#get MVA MET updated as of JAn30
#PAT Recipe (https://twiki.cern.ch/twiki/bin/view/CMSPublic/SWGuidePATReleaseNotes72X)
#git cms-addpkg PhysicsTools/PatAlgos
#git cms-addpkg FWCore/Version
#MET Recipe ()

#MVA & No-PU MET Recipe
#git-cms-merge-topic -u cms-met:72X-13TeV-Training-30Jan15
#get new JEC trainings
#cd RecoMET/METPUSubtraction/
#git clone https://github.com/rfriese/RecoMET-METPUSubtraction data -b 72X-13TeV-Phys14_25_V4-26Mar15


pushd $CMSSW_BASE/src
