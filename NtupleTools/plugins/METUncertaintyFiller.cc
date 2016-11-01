#include "FWCore/Framework/interface/MakerMacros.h"
#include "UWAnalysis/NtupleTools/plugins/METUncertaintyFiller.h"

DEFINE_EDM_PLUGIN(NtupleFillerFactory, PATMuTauPairMETUncertaintyFiller, "PATMuTauPairMETUncertaintyFiller");
DEFINE_EDM_PLUGIN(NtupleFillerFactory, PATEleTauPairMETUncertaintyFiller, "PATEleTauPairMETUncertaintyFiller");
DEFINE_EDM_PLUGIN(NtupleFillerFactory, PATDiTauPairMETUncertaintyFiller, "PATDiTauPairMETUncertaintyFiller");
