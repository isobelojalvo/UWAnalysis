#!/bin/bash

pushd $CMSSW_BASE/src

git clone git@github.com:veelken/SVFit_standalone.git TauAnalysis/SVfitStandalone
cd TauAnalysis/SVfitStandalone
git checkout dd7cf43e3f930040959f7d700cef976307d7cec3
pushd $CMSSW_BASE/src


#MVA MET
#git cms-addpkg RecoMET/METPUSubtraction
cd RecoMET/METPUSubtraction/
git cms-addpkg RecoMET/METPUSubtraction
git cms-addpkg DataFormats/METReco
git remote add -f mvamet https://github.com/rfriese/cmssw.git
git checkout MVAMET2_beta_0.6 -b mvamet

pushd $CMSSW_BASE/src

git clone https://github.com/CMS-HTT/LeptonEff-interface.git HTT-utilities 
cd HTT-utilities/LepEffInterface/
git clone https://github.com/CMS-HTT/LeptonEfficiencies.git data 


pushd $CMSSW_BASE/src

#METSignificance
git cms-addpkg RecoMET/METProducers


#Electron corrections USE?
#git cms-merge-topic -u matteosan1:smearer_76X



