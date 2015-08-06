#!/bin/bash

pushd $CMSSW_BASE/src

git clone git@github.com:veelken/SVFit_standalone.git TauAnalysis/SVfitStandalone
cd TauAnalysis/SVfitStandalone
git checkout svFit_2015Apr03
pushd $CMSSW_BASE/src

#cp /cms/ojalvo/mssm8TeV/CMSSW_5_3_7/src/UWAnalysis/Configuration/data/factoryJetRegNewGenJets* UWAnalysis/Configuration/data/.

#MVA MET
git cms-addpkg RecoMET/METPUSubtraction




pushd $CMSSW_BASE/src
