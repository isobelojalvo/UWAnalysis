#include "UWAnalysis/RecoTools/plugins/PATTauMatchSelector.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/PluginManager/interface/ModuleDef.h"
#include "UWAnalysis/DataFormats/interface/CompositePtrCandidateT1T2MEt.h"
#include "UWAnalysis/DataFormats/interface/CompositePtrCandidateT1T2MEtFwd.h"
#include "UWAnalysis/RecoTools/plugins/DiCandidateSorterByIsoDiTau.h"

typedef DiCandidateSorterByIsoDiTau<PATMuTauPair> PATMuTauPairSorterByIsoDiTau;
typedef DiCandidateSorterByIsoDiTau<PATElecTauPair> PATEleTauPairSorterByIsoDiTau;
typedef DiCandidateSorterByIsoDiTau<PATDiTauPair> PATDiTauPairSorterByIsoDiTau;

DEFINE_FWK_MODULE(PATMuTauPairSorterByIsoDiTau);
DEFINE_FWK_MODULE(PATEleTauPairSorterByIsoDiTau);
DEFINE_FWK_MODULE(PATDiTauPairSorterByIsoDiTau);
