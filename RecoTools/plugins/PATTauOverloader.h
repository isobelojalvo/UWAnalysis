// -*- C++ -*-
//
//

// system include files
#include <memory>
#include <iostream>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/TauReco/interface/PFTau.h"
#include "DataFormats/PatCandidates/interface/Tau.h"
#include "DataFormats/PatCandidates/interface/Muon.h"

#include "DataFormats/PatCandidates/interface/PackedCandidate.h"
#include "DataFormats/Candidate/interface/Candidate.h"

#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/GsfTrackReco/interface/GsfTrackFwd.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"


#include "Math/GenVector/VectorUtil.h"
//
// class declaration
#include <boost/foreach.hpp>
#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/Math/interface/angle.h"


class PATTauOverloader : public edm::EDProducer {
   public:
  
  

  explicit PATTauOverloader(const edm::ParameterSet& iConfig):
  src_(consumes<pat::TauCollection>(iConfig.getParameter<edm::InputTag>("src"))),
  muons_(consumes<pat::MuonCollection>(iConfig.getParameter<edm::InputTag>("muons"))),
  vtxSrc_(consumes<reco::VertexCollection>(iConfig.getParameter<edm::InputTag>("vtxSrc")))
  {
    produces<pat::TauCollection>();
  }
  
  ~PATTauOverloader() {}
   private:


  virtual void produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
  {
    using namespace edm;
    using namespace reco;
    std::auto_ptr<pat::TauCollection> taus(new pat::TauCollection);
    Handle<pat::TauCollection > cands;
    Handle<pat::MuonCollection > muons;
    
    edm::Handle<reco::VertexCollection> vertices;
    iEvent.getByToken(vtxSrc_, vertices);
    //const reco::Vertex& thePV = *vertices->begin();

  
    if(iEvent.getByToken(src_,cands)) 
      for(unsigned int  i=0;i!=cands->size();++i){
	pat::Tau tau = cands->at(i);

        float dZ=-999;
        float dXY=-999;
        float z_2=-999;
 
        if(vertices->size()){z_2 = tau.vz() + (130. / tan(tau.theta()));}
        else std::cout<<"VERTICES NULL"<<std::endl;

	tau.addUserFloat("zIP",z_2);

        //Against Electron 
        //NOw use tau.tauID("") to access everything!!!
        //tau.addUserInt("againstElectronVLooseMVA5",tau.tauID("againstElectronVLooseMVA5"));
        //tau.addUserInt("againstElectronVLooseMVA6",tau.tauID("againstElectronVLooseMVA6"));
        //tau.addUserInt("againstElectronTightMVA5",tau.tauID("againstElectronTightMVA5"));
        //tau.addUserInt("againstElectronTightMVA6",tau.tauID("againstElectronTightMVA6"));
    
        //Against Muon 
        //tau.addUserInt("againstMuTight3",tau.tauID("againstMuonTight3"));
        //tau.addUserInt("againstMuTight4",tau.tauID("againstMuonTight4"));
        //tau.addUserInt("againstMuLoose3",tau.tauID("againstMuonLoose3"));


        float nMatchedSegments = -1;
        float muonMatched = 0;
        float leadChargedHadrTrackPt = -1;
        float leadChargedHadrTrackPtErr = -1;
        float nIsoTracks=-1;
        nIsoTracks = tau.isolationChargedHadrCands().size();

        pat::PackedCandidate const* packedLeadTauCand = dynamic_cast<pat::PackedCandidate const*>(tau.leadChargedHadrCand().get());

        if(tau.leadChargedHadrCand().isNonnull()){
	        leadChargedHadrTrackPt = tau.leadChargedHadrCand()->pt();
	        //leadChargedHadrTrackPtErr = tau.leadChargedHadrCand()->ptError();
	        dZ = packedLeadTauCand->dz();
	        dXY = packedLeadTauCand->dxy();
                //std::cout<<"Sync Tau dZ is "<<dZ<<std::endl; 
	        if(iEvent.getByToken(muons_,muons)){
		    for(unsigned int k =0; k!=muons->size();k++){
			    if(ROOT::Math::VectorUtil::DeltaR(muons->at(k).p4(),tau.leadChargedHadrCand()->p4())<0.15){
				    if(muons->at(k).numberOfMatches()>nMatchedSegments){
					    nMatchedSegments = muons->at(k).numberOfMatches();
                                            //std::cout<<"====IN MUON LOOP: Matched Segments ======"<<std::endl;
					    //std::cout<<" matched muon N Seg: "<<nMatchedSegments<<std::endl;
				    }
				    muonMatched=1;
			    }
		    }
	        }
        }


        tau.addUserFloat("nIsoTracks",nIsoTracks);
        tau.addUserFloat("leadChargedHadrTrackPt",leadChargedHadrTrackPt);
        tau.addUserFloat("leadChargedHadrTrackPtErr",leadChargedHadrTrackPtErr);
	tau.addUserFloat("taudZ",dZ);
	tau.addUserFloat("taudXY",dXY);
        tau.addUserFloat("muonNMatchedSeg",nMatchedSegments);
        tau.addUserFloat("muonTauHadMatched",muonMatched);

        taus->push_back(tau);
      }
    iEvent.put(taus);
  } 

  // ----------member data ---------------------------
  edm::EDGetTokenT<pat::TauCollection> src_;
  edm::EDGetTokenT<pat::MuonCollection> muons_;
  edm::EDGetTokenT<reco::VertexCollection> vtxSrc_;


};

