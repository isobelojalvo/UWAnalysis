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
git checkout svFit_2015Apr03
pushd $CMSSW_BASE/src

#cp -r /cms/laura/UWAnalysis13/CMSSW_7_3_3/src/AnalysisDataFormats/ .
cp /cms/ojalvo/mssm8TeV/CMSSW_5_3_7/src/UWAnalysis/Configuration/data/factoryJetRegNewGenJets* UWAnalysis/Configuration/data/.

#set +o errexit
#echo "Applying pat trigger matching speedup"
#git cms-addpkg DataFormats/PatCandidates
#git apply UWAnalysis/recipeFSA/patches/DataFormats_PatCandidates_TriggerEvent.cc.patch
#set -o errexit


#cutbased ID
git cms-merge-topic ikrav:egm_id_74X_v0


#MVA MET
git cms-addpkg RecoMET/METPUSubtraction


pushd $CMSSW_BASE/src
