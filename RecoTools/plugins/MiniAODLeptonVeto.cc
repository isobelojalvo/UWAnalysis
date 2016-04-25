#include "UWAnalysis/RecoTools/plugins/MiniAODLeptonVeto.h"

#include "FWCore/Framework/interface/MakerMacros.h"

#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Tau.h"


typedef MiniAODLeptonVeto<pat::Muon, pat::Tau> PATMuTauLVeto;
typedef MiniAODLeptonVeto<pat::Electron, pat::Tau> PATElecTauLVeto;



DEFINE_FWK_MODULE(PATMuTauLVeto);
DEFINE_FWK_MODULE(PATElecTauLVeto);

