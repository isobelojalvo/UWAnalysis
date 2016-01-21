// -*- C++ -*-
//
// Package:    PATMuonTrackVetoSelector
// Class:      PATMuonTrackVetoSelector
// 
/**\class PATMuonTrackVetoSelector PATMuonTrackVetoSelector.cc UWAnalysis/PATMuonTrackVetoSelector/src/PATMuonTrackVetoSelector.cc

 Description: <one line class summary>

 Implementation:
     <Notes on implementation>
*/
//
// Original Author:  Michail Bachtis
//         Created:  Sun Jan 31 15:04:57 CST 2010
// $Id: PATJetFilter.h,v 1.3 2013/10/25 21:01:55 ojalvo Exp $
//
//
#include "PhysicsTools/JetMCUtils/interface/JetMCTag.h"

// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/TauReco/interface/PFTau.h"
#include "DataFormats/MuonReco/interface/MuonSelectors.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/JetReco/interface/GenJetCollection.h"
#include "Math/GenVector/VectorUtil.h"
//
// class decleration
#include <boost/foreach.hpp>
#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/Math/interface/angle.h"

#include "DataFormats/PatCandidates/interface/PackedCandidate.h"

class PATJetFilter : public edm::EDProducer {
   public:
  
  
  //vector<reco::GenJet>                  "ak5GenJets" 
  explicit PATJetFilter(const edm::ParameterSet& iConfig):
    src_(consumes<pat::JetCollection>(iConfig.getParameter<edm::InputTag>("src")))
  {
    produces<pat::JetCollection>();
  }
  
  ~PATJetFilter() {}
   private:

  virtual void produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
  {
    //std::cout<<"===== PATJetFilter NAMESPACE ====="<<std::endl;
    using namespace edm;
    using namespace reco;
    using namespace std;
    //std::cout<<"===== PATJetFilter JetCollection ====="<<std::endl;
    std::auto_ptr<pat::JetCollection> jets(new pat::JetCollection);
    Handle<pat::JetCollection > cands;
    if(iEvent.getByToken(src_,cands)) 
      for(unsigned int  i=0;i!=cands->size();++i){
	pat::Jet jet = cands->at(i);
	if (jet.userFloat("idLoose")&&abs(jet.eta())<4.7) jets->push_back(jet);
      }  

    iEvent.put(jets);

  } 

  // ----------member data ---------------------------
  edm::EDGetTokenT<pat::JetCollection> src_;
};

