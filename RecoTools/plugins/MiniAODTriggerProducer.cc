#include "UWAnalysis/RecoTools/plugins/MiniAODTriggerProducer.h"
#include "FWCore/Framework/interface/MakerMacros.h"

typedef MiniAODTriggerProducer<pat::Muon> MuonTriggerMatcherMA;
typedef MiniAODTriggerProducer<pat::Tau> TauTriggerMatcherMA;
typedef MiniAODTriggerProducer<pat::Electron> ElectronTriggerMatcherMA;

//define this as a plug-in
DEFINE_FWK_MODULE(MuonTriggerMatcherMA);
DEFINE_FWK_MODULE(ElectronTriggerMatcherMA);
DEFINE_FWK_MODULE(TauTriggerMatcherMA);

