#include "UWAnalysis/RecoTools/plugins/PATCandidatePairNSVFitSA.h"

#include "FWCore/Framework/interface/MakerMacros.h"

#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Tau.h"


typedef PATCandidatePairNSVFitSA<pat::Muon, pat::Tau> PATMuTauNSVFitSA;
typedef PATCandidatePairNSVFitSA<pat::Electron, pat::Tau> PATElecTauNSVFitSA;
typedef PATCandidatePairNSVFitSA<pat::Electron, pat::Muon> PATElecMuNSVFitSA;
typedef PATCandidatePairNSVFitSA<pat::Muon, pat::Muon> PATMuMuNSVFitSA;



DEFINE_FWK_MODULE(PATMuTauNSVFitSA);
DEFINE_FWK_MODULE(PATElecTauNSVFitSA);
DEFINE_FWK_MODULE(PATElecMuNSVFitSA);
DEFINE_FWK_MODULE(PATMuMuNSVFitSA);
