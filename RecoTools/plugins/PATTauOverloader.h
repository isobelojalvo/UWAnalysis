// -*- C++ -*-
//
//
// Original Author:  Michail Bachtis
//         Created:  Sun Jan 31 15:04:57 CST 2010
// $Id: PATTauOverloader.h,v 1.6 2013/09/13 16:59:06 ojalvo Exp $
//
//
//#include "PhysicsTools/JetMCUtils/interface/JetMCTag.h"

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
// class decleration
#include <boost/foreach.hpp>
#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/Math/interface/angle.h"


class PATTauOverloader : public edm::EDProducer {
   public:
  
  

  explicit PATTauOverloader(const edm::ParameterSet& iConfig):
  src_(iConfig.getParameter<edm::InputTag>("src")),
  muons_(iConfig.getParameter<edm::InputTag>("muons")),
  vtxSrc_(iConfig.getParameter<edm::InputTag>("vtxSrc"))
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
    iEvent.getByLabel(vtxSrc_, vertices);
    const reco::Vertex& thePV = *vertices->begin();
  
    if(iEvent.getByLabel(src_,cands)) 
      for(unsigned int  i=0;i!=cands->size();++i){
	pat::Tau tau = cands->at(i);
	
	float dZ = fabs(tau.vz()-thePV.z());
	tau.addUserFloat("dZ",dZ);

	float z_2 = tau.vz() + (130. / tan(tau.theta()));
	tau.addUserFloat("zIP",z_2);


        //Against Electron 
        tau.addUserInt("againstElectronVLooseMVA5",tau.tauID("againstElectronVLooseMVA5"));
        tau.addUserInt("againstElectronTightMVA",tau.tauID("againstElectronTightMVA5"));
    
        //Against Muon 
        tau.addUserInt("againstMuTightFixed",tau.tauID("againstMuonTight3"));
        tau.addUserInt("againstMuLooseFixed",tau.tauID("againstMuonLoose3"));




        float nMatchedSegments = -1;
        float muonMatched = 0;
        float leadChargedHadrTrackPt = -1;
        float leadChargedHadrTrackPtErr = -1;
        float nIsoTracks=-1;
        nIsoTracks = tau.isolationChargedHadrCands().size();

        if(tau.leadChargedHadrCand().isNonnull()){
                //std::cout<<"====IN TAU TRACK LOOP ======"<<std::endl;
                //FIXME
	        //leadChargedHadrTrackPtErr = tau.leadChargedHadrCand()->innerTrack()->ptError();
                //std::cout<<" leadPFTrackPtErr: "<<leadChargedHadrTrackPtErr<<std::endl;
	        leadChargedHadrTrackPt = tau.leadChargedHadrCand()->pt();
                //std::cout<<" leadChargedHadrTrackPt: "<<leadChargedHadrTrackPt<<std::endl;
	        if(iEvent.getByLabel(muons_,muons)){
		    for(unsigned int k =0; k!=muons->size();k++){
			    if(ROOT::Math::VectorUtil::DeltaR(muons->at(k).p4(),tau.leadChargedHadrCand()->p4())<0.15){
				    if(muons->at(k).numberOfMatches()>nMatchedSegments){
					    nMatchedSegments = muons->at(k).numberOfMatches();
					    //std::cout<<" matched muon N Seg: "<<nMatchedSegments<<std::endl;
				    }
				    muonMatched=1;
			    }
		    }
	        }
        }

        tau.addUserFloat("nIsoTracks",nIsoTracks);
        tau.addUserFloat("leadChargedHadrTrackPt",leadChargedHadrTrackPt);
        //FIXME
        tau.addUserFloat("leadChargedHadrTrackPtErr",leadChargedHadrTrackPtErr);
        tau.addUserFloat("muonNMatchedSeg",nMatchedSegments);
        tau.addUserFloat("muonTauHadMatched",muonMatched);

        taus->push_back(tau);
      }

    iEvent.put(taus);
  } 

  // ----------member data ---------------------------
  edm::InputTag src_;
  edm::InputTag vtxSrc_;
  edm::InputTag muons_;

};

