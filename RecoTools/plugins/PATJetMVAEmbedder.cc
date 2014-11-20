#include "UWAnalysis/RecoTools/plugins/PATJetMVAEmbedder.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/PluginManager/interface/ModuleDef.h"

#include "CondFormats/EgammaObjects/interface/GBRForest.h"

#include <TFile.h>
#include <TMath.h>

#include <assert.h>

DEFINE_FWK_MODULE(PATJetMVAEmbedder);

