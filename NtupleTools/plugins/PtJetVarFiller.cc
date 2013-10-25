#include "FWCore/Framework/interface/MakerMacros.h"
#include "UWAnalysis/NtupleTools/plugins/PtJetVarFiller.h"
#include "Math/GenVector/VectorUtil.h" 

DEFINE_EDM_PLUGIN(NtupleFillerFactory, PATMuonNuPairPtJetVarFiller, "PATMuonNuPairPtJetVarFiller");
DEFINE_EDM_PLUGIN(NtupleFillerFactory, PATMuTauPairPtJetVarFiller, "PATMuTauPairPtJetVarFiller");
DEFINE_EDM_PLUGIN(NtupleFillerFactory, PATEleTauPairPtJetVarFiller, "PATEleTauPairPtJetVarFiller");
//DEFINE_EDM_PLUGIN(NtupleFillerFactory, PATMuJetPairPtJetVarFiller, "PATMuJetPairPtJetVarFiller");
//DEFINE_EDM_PLUGIN(NtupleFillerFactory, PATMuPairPtJetVarFiller, "PATMuPairPtJetVarFiller");
//DEFINE_EDM_PLUGIN(NtupleFillerFactory, PATEleMuPairPtJetVarFiller, "PATEleMuPairPtJetVarFiller");
//DEFINE_EDM_PLUGIN(NtupleFillerFactory, PATDiTauPairPtJetVarFiller, "PATDiTauPairPtJetVarFiller");



