#!/bin/bash

# This a very very unfortunate recipe. :(

cd ../

git cms-addpkg PhysicsTools/PatAlgos
git cms-cvs-history import V04-06-09 JetMETCorrections/Type1MET
git cms-cvs-history import V01-08-00 RecoBTag/SecondaryVertex
git cms-cvs-history import V02-02-00 RecoVertex/AdaptiveVertexFinder

git clone https://github.com/cms-analysis/TauAnalysis-CandidateTools.git TauAnalysis/CandidateTools
pushd $CMSSW_BASE/src/TauAnalysis/CandidateTools
git checkout TauAnalysis-CandidateTools-V00-01-04s
pushd $CMSSW_BASE/src

git cms-addpkg RecoTauTag/RecoTau  # recipe from christian, the merge topic complained in 539, it will probably work in 5314
git cms-merge-topic -u cms-tau-pog:CMSSW_5_3_X #remove?
git cms-merge-topic -u vadler:53X-useNewTau

mkdir $CMSSW_BASE/src/RecoMET


cp -r /cms/ojalvo/HhhFSA4/CMSSW_5_3_14/src/AnalysisDataFormats/ .                                                    

git cms-merge-topic cms-analysis-tools:5_3_14-updateSelectorUtils
git-cms-cvs-history import V05-00-16      DataFormats/JetReco 
git cms-merge-topic -u cms-tau-pog:CMSSW_5_3_X_boostedTaus_2013Dec17

git checkout merge-attempt

git branch none
git checkout none
git cms-merge-topic -u cms-met:53X-MVaNoPuMET-20131217-01
git checkout -f merge-attempt
git checkout none
git cms-merge-topic -u cms-met:53X-MVaNoPuMET-20131217-01

git cms-merge-topic -u TaiSakuma:53X-met-131120-01

rm -r Fireworks

git branch 
git checkout none
git cms-merge-topic -u cms-tau-pog:CMSSW_5_3_X_boostedTaus_2013Dec17
git cms-merge-topic -u cms-met:53X-MVaNoPuMET-20131217-01



git cms-merge-topic -u cms-met:53X-MVaNoPuMET-20131217-01
git fetch . +HEAD:merge-attempt
git checkout -f cms-met/53X-MVaNoPuMET-20131217-01
git cms-merge-topic -u vadler:53X-useNewTau
git cms-merge-topic -u cms-tau-pog:CMSSW_5_3_X_boostedTaus_2013Dec17

cp /cms/ojalvo/HhhFSA4/CMSSW_5_3_14/src/UWAnalysis/Configuration/data/factoryJetRegNewGenJetsAll_BDT* ../../Configuration/data/.
cp /cms/ojalvo/HhhFSA4/RecoMET/METPUSubtraction/python/mvaPFMET_leptons_cff.py $CMSSW_BASE/src/RecoMET/METPUSubtraction/python/
cp /afs/cern.ch/user/p/pharris/public/MVAMetUpdate/*Sep*.root $CMSSW_BASE/src/RecoMET/METPUSubtraction/data/
cp -r /cms/ojalvo/HhhFSA4/CMSSW_5_3_14/src/RecoMET/METPUSubtraction $CMSSW_BASE/RecoMET/.

scramv1 b -j 20