cd ../

git cms-cvs-history import V06-05-06-10 DataFormats/PatCandidates
git cms-cvs-history import V08-09-58  PhysicsTools/PatAlgos
git cms-cvs-history import  V03-09-28 PhysicsTools/PatUtils

git cms-cvs-history import V00-02-14 DataFormats/StdDictionaries
git cms-cvs-history import V00-03-16 CommonTools/ParticleFlow

  git cms-cvs-history import V04-06-09 JetMETCorrections/Type1MET
  git cms-cvs-history import V01-08-00 RecoBTag/SecondaryVertex
  git cms-cvs-history import V02-02-00 RecoVertex/AdaptiveVertexFinder

git clone https://github.com/cms-analysis/TauAnalysis-CandidateTools.git TauAnalysis/CandidateTools
pushd $CMSSW_BASE/src/TauAnalysis/CandidateTools
git checkout TauAnalysis-CandidateTools-V00-01-04s
pushd $CMSSW_BASE/src

#  git cms-cvs-history import V01-04-25 RecoTauTag/RecoTau
#  git cms-cvs-history import V01-04-13 RecoTauTag/Configuration
#  git cms-cvs-history import V00-04-00 CondFormats/EgammaObjects

git cms-addpkg RecoTauTag/RecoTau  # recipe from christian, the merge topic complained in 539, it will probably work in 5314
  # to be checked
git cms-merge-topic -u cms-tau-pog:CMSSW_5_3_X

mkdir $CMSSW_BASE/src/RecoMET

cp -r /cms/ojalvo/HhhFSA4/CMSSW_5_3_14/src/RecoMET/METPUSubtraction RecoMET
cp /cms/ojalvo/HhhFSA4//RecoMET/METPUSubtraction/python/mvaPFMET_leptons_cff.py $CMSSW_BASE/src/RecoMET/METPUSubtraction/python/

cp /afs/cern.ch/user/p/pharris/public/MVAMetUpdate/*Sep*.root $CMSSW_BASE/src/RecoMET/METPUSubtraction/data/
                                                                                                                    
#cp /cms/ojalvo/mssm3/CMSSW_5_3_7/src/JetMETCorrections/METPUSubtraction/python/mvaPFMET_leptons_data_cff.py JetMETCorrections/METPUSubtraction/python/mvaPFMET_leptons_data_cff.py
#cp /cms/ojalvo/mssm3/CMSSW_5_3_7/src/JetMETCorrections/METPUSubtraction/python/mvaPFMET_leptons_cff.py JetMETCorrections/METPUSubtraction/python/mvaPFMET_leptons_cff.py
#cp /cms/ojalvo/mssm3/CMSSW_5_3_7/src/JetMETCorrections/METPUSubtraction/python/mvaPFMET_leptons_PAT_cfi.py JetMETCorrections/METPUSubtraction/python/mvaPFMET_leptons_PAT_cfi.py

scramv1 b -j 20