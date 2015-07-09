#!/bin/bash

pushd $CMSSW_BASE/src

git clone git@github.com:veelken/SVFit_standalone.git TauAnalysis/SVfitStandalone
cd TauAnalysis/SVfitStandalone
git checkout svFit_2015Apr03
pushd $CMSSW_BASE/src

#cp /cms/ojalvo/mssm8TeV/CMSSW_5_3_7/src/UWAnalysis/Configuration/data/factoryJetRegNewGenJets* UWAnalysis/Configuration/data/.

#MVA MET
git cms-addpkg RecoMET/METPUSubtraction

#MVA Ele Id
git cms-merge-topic ikrav:egm_id_74X_v2




pushd $CMSSW_BASE/src
