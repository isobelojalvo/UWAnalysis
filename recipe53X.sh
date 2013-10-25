cd ../

cvs co -r   METPU_5_3_X_v9 JetMETCorrections/METPUSubtraction
cd JetMETCorrections/METPUSubtraction/test/
./setup.sh
cd ../../../
scramv1 b -j 20


cvs co -r bMinimalSVfit-08-03-11 AnalysisDataFormats/TauAnalysis
cvs co -r V05-00-16      DataFormats/JetReco
cvs co -r V06-05-06-03   DataFormats/PatCandidates
cvs co -r V02-01-00      HiggsAnalysis/CombinedLimit
cvs co -r METPU_5_3_X_v9 JetMETCorrections/METPUSubtraction
cvs co -r V08-09-52      PhysicsTools/PatAlgos
cvs co -r V08-03-19      PhysicsTools/Utilities
cvs co -r METPU_5_3_X_v4 RecoJets/JetProducers
cvs co -r V04-01-03      RecoLuminosity/LumiDB
cvs co -r V03-04-07      RecoMET/METAlgorithms
cvs co -r V01-05-06      RecoTauTag/RecoTau
cvs co -r V00-02-01s     TauAnalysis/CandidateTools
cvs co -r b5_3_X_cvMEtCorr_2013Feb22 DataFormats/METReco

###these files don't compile and aren't needed                                                                                                                                         
rm PhysicsTools/PatAlgos/plugins/PATMHTProducer.*
rm JetMETCorrections/METPUSubtraction/plugins/NoPileUpPFMEtProducer.cc
cp /cms/ojalvo/mssm3/CMSSW_5_3_7/src/JetMETCorrections/METPUSubtraction/src/PFMETAlgorithmMVA.cc JetMETCorrections/METPUSubtraction/src/.


### These need to be copied from my area                                                                                                                                                                                                  
cp /cms/ojalvo/mssm3/CMSSW_5_3_7/src/JetMETCorrections/METPUSubtraction/python/mvaPFMET_leptons_data_cff.py JetMETCorrections/METPUSubtraction/python/mvaPFMET_leptons_data_cff.py
cp /cms/ojalvo/mssm3/CMSSW_5_3_7/src/JetMETCorrections/METPUSubtraction/python/mvaPFMET_leptons_cff.py JetMETCorrections/METPUSubtraction/python/mvaPFMET_leptons_cff.py
cp /cms/ojalvo/mssm3/CMSSW_5_3_7/src/JetMETCorrections/METPUSubtraction/python/mvaPFMET_leptons_PAT_cfi.py JetMETCorrections/METPUSubtraction/python/mvaPFMET_leptons_PAT_cfi.py

scramv1 b -j 20