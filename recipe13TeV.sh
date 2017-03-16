#!/bin/bash

pushd $CMSSW_BASE/src

git clone git@github.com:veelken/SVFit_standalone.git TauAnalysis/SVfitStandalone
cd TauAnalysis/SVfitStandalone
git checkout HIG-16-006 
pushd $CMSSW_BASE/src


#MVA MET
#git cms-addpkg RecoMET/METPUSubtraction
#git cms-addpkg DataFormats/METReco
#git remote add -f mvamet https://github.com/rfriese/cmssw.git
#git checkout mvamet/mvamet80 -b mvamet
#mkdir RecoMET/METPUSubtraction/data
#cd RecoMET/METPUSubtraction/data
#wget https://github.com/rfriese/cmssw/raw/MVAMET2_beta_0.6/RecoMET/METPUSubtraction/data/weightfile.root

#git checkout MVAMET2_beta_0.6 -b mvamet

pushd $CMSSW_BASE/src
git clone https://github.com/CMS-HTT/LeptonEff-interface.git HTT-utilities 
cd HTT-utilities/LepEffInterface/
git clone https://github.com/CMS-HTT/LeptonEfficiencies.git data 

pushd $CMSSW_BASE/src
git clone https://github.com/CMS-HTT/RecoilCorrections.git  HTT-utilities/RecoilCorrections 

pushd $CMSSW_BASE/src

git cms-merge-topic ikrav:egm_id_80X_v2
git cms-merge-topic cms-met:METRecipe_8020
git cms-merge-topic gpetruc:badMuonFilters_80X

git cms-merge-topic -u cms-met:fromCMSSW_8_0_20_postICHEPfilter


git cms-addpkg DataFormats/PatCandidates
git cms-addpkg RecoTauTag/RecoTau
git cms-addpkg RecoTauTag/Configuration
git cms-addpkg RecoTauTag/RecoTau
git cms-merge-topic cms-tau-pog:CMSSW_8_0_X_tau-pog_miniAOD-backport-tauID
#METSignificance
#git cms-addpkg RecoMET/METProducers