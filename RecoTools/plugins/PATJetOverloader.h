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
// $Id: PATJetOverloader.h,v 1.3 2013/10/25 21:01:55 ojalvo Exp $
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


class PATJetOverloader : public edm::EDProducer {
   public:
  
  
  //vector<reco::GenJet>                  "ak5GenJets" 
  explicit PATJetOverloader(const edm::ParameterSet& iConfig):
    src_(iConfig.getParameter<edm::InputTag>("src")),
    genJets_(iConfig.getParameter<edm::InputTag>("genJets"))
  {
    produces<pat::JetCollection>();
  }
  
  ~PATJetOverloader() {}
   private:

  virtual void produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
  {
    using namespace edm;
    using namespace reco;
    using namespace std;
    std::auto_ptr<pat::JetCollection> jets(new pat::JetCollection);
    Handle<pat::JetCollection > cands;
    Handle<reco::GenJetCollection > genJets;
    if(iEvent.getByLabel(src_,cands)) 
      for(unsigned int  i=0;i!=cands->size();++i){
	pat::Jet jet = cands->at(i);
	float pt=0.0;
	float sumPt=0.0;
	float sumPt2=0.0;
	for(unsigned int j=0;j<jet.getPFConstituents().size();++j) {
	  pt = jet.getPFConstituents().at(j)->pt();
	  sumPt+=pt;
	  sumPt2+=pt*pt;
	}

	float genJetPt =-10;
	float genJetEta =-10;
	float genJetPhi =-10;
	float DRMin = 0.5;
	float Vtx3dL = -10;
	float Vtx3deL = -10;
	float VtxPt = -10;
	float uncorrectedPt= -10;
	uncorrectedPt = jet.correctedP4(0).pt();

	if(iEvent.getByLabel(genJets_,genJets))
	  for(unsigned int k=0;k!=genJets->size();k++){
	    if(ROOT::Math::VectorUtil::DeltaR(genJets->at(k).p4(),jet.p4())<DRMin){
	      DRMin = ROOT::Math::VectorUtil::DeltaR(genJets->at(k).p4(),jet.p4());
	      genJetPt=genJets->at(k).pt();
	      genJetEta=genJets->at(k).eta();
	      genJetPhi=genJets->at(k).phi();
	    }
	  }

	const reco::SecondaryVertexTagInfo* secInfo = jet.tagInfoSecondaryVertex("secondaryVertex");
	if(secInfo && secInfo->vertexTracks().size()>0){
	  const reco::Vertex&sv= secInfo->secondaryVertex(0);
	  //jetVtxPt = sv.pt();
	  Vtx3dL = (secInfo->flightDistance(0).value());
	  Vtx3deL = (secInfo->flightDistance(0).error());
	  reco::Candidate::LorentzVector sumP4(0,0,0,0);
	  if ( sv.tracksSize()>1){
	    for(reco::Vertex::trackRef_iterator track = sv.tracks_begin(); track!= sv.tracks_end(); ++track)
	      for(unsigned int pfj=0;pfj<jet.getPFConstituents().size();++pfj) {
		pfcand = jet.getPFConstituents().at(pfj);
		if(pfcand.isNonnull())
		  //if(abs(pfcand->pdgId())==211&&pfcand->pt()>0.25&&pfcand->charge()!=0) ///create charged particle collection
		  if((*track).key() == pfcand->trackRef().key())
		    sumP4+=pfcand->p4();
	      }
	  }
	  /*
	  for (unsigned int h=0; h<secInfo->vertexTracks().size(); h++) {
	    //sumP4=(secInfo->vertexTracks()[h]->px(),0,0,0);
	    float pt=secInfo->track(h).pt();
	    }*/
	  VtxPt=sumP4.pt();
	}
	

	jet.addUserFloat("PtUncorr",uncorrectedPt);
	jet.addUserFloat("VtxPt",VtxPt);
	jet.addUserFloat("Vtx3dL",Vtx3dL);
	jet.addUserFloat("Vtx3deL",Vtx3deL);
	jet.addUserFloat("genJetEta",genJetEta);
	jet.addUserFloat("genJetPhi",genJetPhi);
	jet.addUserFloat("genJetPt",genJetPt);
	jet.addUserFloat("ptRMS",sqrt(sumPt2/(sumPt*sumPt)));
	jets->push_back(jet);

      }  
    
    iEvent.put(jets);

  } 

      // ----------member data ---------------------------
  edm::InputTag src_;
  edm::InputTag genJets_;
  reco::PFCandidatePtr pfcand;
};

