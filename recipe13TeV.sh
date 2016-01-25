#!/bin/bash

pushd $CMSSW_BASE/src

git clone git@github.com:veelken/SVFit_standalone.git TauAnalysis/SVfitStandalone
cd TauAnalysis/SVfitStandalone
git checkout svFit_2015Apr03
pushd $CMSSW_BASE/src


#MVA MET
git cms-addpkg RecoMET/METPUSubtraction
cd RecoMET/METPUSubtraction/
git clone https://github.com/rfriese/RecoMET-METPUSubtraction data -b 74X-13TeV-Summer15-July2015

#
# Edit mvaPFMet_cff.py to have the following:
#

pushd $CMSSW_BASE/src

git clone https://github.com/CMS-HTT/LeptonEff-interface.git HTT-utilities 
cd HTT-utilities/LepEffInterface/
git clone https://github.com/CMS-HTT/LeptonEfficiencies.git data 


pushd $CMSSW_BASE/src

#METSignificance
git cms-addpkg RecoMET/METProducers


#Electron corrections
git cms-merge-topic -u matteosan1:smearer_76X



