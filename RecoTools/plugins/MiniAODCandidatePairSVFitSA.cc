#include "UWAnalysis/RecoTools/plugins/MiniAODCandidatePairSVFitSA.h"

#include "FWCore/Framework/interface/MakerMacros.h"

#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Tau.h"


typedef MiniAODCandidatePairSVFitSA<pat::Muon, pat::Tau> PATMuTauSVFitSA;
typedef MiniAODCandidatePairSVFitSA<pat::Electron, pat::Tau> PATElecTauSVFitSA;



DEFINE_FWK_MODULE(PATMuTauSVFitSA);
DEFINE_FWK_MODULE(PATElecTauSVFitSA);

