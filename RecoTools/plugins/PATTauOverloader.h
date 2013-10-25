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
// $Id: PATTauOverloader.h,v 1.6 2013/09/13 16:59:06 ojalvo Exp $
//
//
#include "PhysicsTools/JetMCUtils/interface/JetMCTag.h"

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
#include "DataFormats/ParticleFlowCandidate/interface/PFCandidate.h"
#include "DataFormats/ParticleFlowCandidate/interface/PFCandidateFwd.h"
#include "DataFormats/MuonReco/interface/MuonSelectors.h"
#include "DataFormats/PatCandidates/interface/Tau.h"
#include "DataFormats/PatCandidates/interface/Muon.h"


#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/GsfTrackReco/interface/GsfTrackFwd.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/GsfTrackReco/interface/GsfTrack.h"
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


	//add new mva3 anti electron veto
	float cutsLoose[16]={0.835,0.831,0.849,0.859,0.873,0.823,0.85,0.855,0.816,0.861,0.862,0.847,0.893,0.82,0.845,0.851};
	float cutsMedium[16]={0.933,0.921,0.944,0.945,0.918,0.941,0.981,0.943,0.956,0.947,0.951,0.95,0.897,0.958,0.955,0.942};
	float cutsTight[16]={ 0.96,0.968,0.971,0.972,0.969,0.959,0.981,0.965,0.975,0.972,0.974,0.971,0.897,0.971,0.961,0.97};
	float cutsVeryTight[16]={0.978,0.98,0.982,0.985,0.977,0.974,0.989,0.977,0.986,0.983,0.984,0.983,0.971,0.987,0.977,0.981};
	
	int loose = 0;
	int medium = 0;
	int tight = 0;
	int veryTight = 0;
	
	int cat = tau.tauID("againstElectronMVA3category");
	float raw = tau.tauID("againstElectronMVA3raw");
	
    
    if( cat>15 ){
    	loose = 1;
    	medium = 1;
    	tight = 1; 
    	veryTight = 1;
    }
    else if( cat<0 ){
		loose = 0;
		medium = 0;
		tight = 0;
		veryTight = 0;   
    }
    else{
		if ( raw > cutsLoose[cat] ){
			loose = 1;
		}
		if ( raw > cutsMedium[cat] ){
			medium = 1;
		}
		if ( raw > cutsTight[cat] ){
			tight = 1;
		}
		if ( raw > cutsVeryTight[cat] ){
			veryTight = 1;
		}
    }
    
    
    tau.addUserInt("againstEleMVALoose",loose);
    tau.addUserInt("againstEleMVAMedium",medium);
    tau.addUserInt("againstEleMVATight",tight);
    tau.addUserInt("againstEleMVAVeryTight",veryTight);
    
    // add the fixed antimu discriminator
    int muTight = 0;
    
    if(tau.decayMode() == 0 && (tau.leadPFChargedHadrCand()->ecalEnergy()+tau.leadPFChargedHadrCand()->hcalEnergy())/tau.leadPFChargedHadrCand()->p() > 0.2 && tau.tauID("againstMuonTight") > 0){
    	muTight = 1;	
    }
    else if( tau.decayMode() !=0 && tau.tauID("againstMuonTight") > 0 ){
    	muTight = 1;
    }
    else{
    	muTight = 0;
    }
    
    tau.addUserInt("againstMuTightFixed",muTight);
    
	
	//add track Momentum
	if (tau.leadPFChargedHadrCand().isNonnull()) {
	  if(tau.leadPFChargedHadrCand()->trackRef().isNonnull())
	    tau.addUserFloat("leadingChargedKFP",tau.leadPFChargedHadrCand()->trackRef()->p());
	  else
	    tau.addUserFloat("leadingChargedKFP",-1.);
	  
	  if(tau.leadPFChargedHadrCand()->gsfTrackRef().isNonnull())
	    tau.addUserFloat("leadingChargedGSFP",tau.leadPFChargedHadrCand()->gsfTrackRef()->p());
	  else
	    tau.addUserFloat("leadingChargedGSFP",-1.);
	}

	if (tau.leadPFChargedHadrCand().isNonnull()) {
	  float eta = tau.leadPFChargedHadrCand()->positionAtECALEntrance().eta();

	  bool InCrack =  (eta < 0.018 ||
			       (eta>0.423 && eta<0.461) ||
			       (eta>0.770 && eta<0.806) ||
			       (eta>1.127 && eta<1.163) ||
			       (eta>1.460 && eta<1.558));

	  if(InCrack) {
	    tau.addUserFloat("crackVeto",0.);
	  }
	  else
	    {
	      tau.addUserFloat("crackVeto",1.);
	    }
	}
	else
	  {
	    tau.addUserFloat("crackVeto",0.);
	  }
      

	if(tau.leadPFCand().isNonnull()&&tau.leadPFCand()->trackRef().isNonnull()) {
	  tau.addUserFloat("leadingKFP",tau.leadPFCand()->trackRef()->p());
	}
	else {
	  tau.addUserFloat("leadingKFP",-1.);
	}


	if(tau.leadPFCand().isNonnull()&&tau.leadPFCand()->gsfTrackRef().isNonnull()) {
	  tau.addUserFloat("leadingGSFP",tau.leadPFCand()->gsfTrackRef()->p());
	}
	else {
	  tau.addUserFloat("leadingGSFP",-1.);
	}
	  
	  if(tau.leadPFCand().isNonnull()&&tau.leadPFCand()->charge()!=0) {
	    tau.addUserFloat("leadingMVA",tau.leadPFCand()->mva_e_pi());

	    if(tau.leadPFCand()->gsfTrackRef().isNonnull())
	      tau.addUserFloat("pixelHits",tau.leadPFCand()->gsfTrackRef()->trackerExpectedHitsInner().numberOfHits());
	    else
	      tau.addUserFloat("pixelHits",-1.);

	  }
	  else if(tau.leadPFChargedHadrCand().isNonnull()) {
	    tau.addUserFloat("leadingMVA",tau.leadPFChargedHadrCand()->mva_e_pi());

	    if(tau.leadPFChargedHadrCand()->gsfTrackRef().isNonnull())
	      tau.addUserFloat("pixelHits",tau.leadPFChargedHadrCand()->gsfTrackRef()->trackerExpectedHitsInner().numberOfHits());
	    else
	      tau.addUserFloat("pixelHits",-1.);
	  }
	//add brem strip
	float bremEnergy=0;
	float emEnergy=0;
	float refEta=0.0;
	
	if(tau.leadPFCand().isNonnull()&&tau.leadPFCand()->charge()!=0)
	  refEta=tau.leadPFCand()->eta();
	else if(tau.leadPFChargedHadrCand().isNonnull())
	  refEta=tau.leadPFChargedHadrCand()->eta();
	for(unsigned int Nc = 0 ;Nc < tau.signalPFGammaCands().size();++Nc)
	  {
	    PFCandidateRef cand = tau.signalPFGammaCands().at(Nc);
	    if(fabs(refEta-cand->eta())<0.03)
	      bremEnergy+=cand->energy();
	    emEnergy+=cand->energy();
	  }

	if(emEnergy>0)
	  tau.addUserFloat("bremEnergy",bremEnergy/emEnergy);
	else
	  tau.addUserFloat("bremEnergy",-1.);

	float nMatchedSegments = -1;
	float muonMatched = 0;
	float leadPFTrackPt = -1;
	float leadPFTrackPtErr = -1;
	float nIsoTracks=-1;
	//std::cout<<"Get's Here 1"<<std::endl;
	nIsoTracks = tau.isolationPFChargedHadrCands().size();
	//std::cout<<"Get's Here 2 nIsoTracks"<<nIsoTracks <<std::endl;

	if(tau.leadPFChargedHadrCand()->trackRef().isNonnull()){
	  leadPFTrackPtErr = tau.leadPFChargedHadrCand()->trackRef()->ptError();
	  leadPFTrackPt = tau.leadPFChargedHadrCand()->trackRef()->pt();
	  if(iEvent.getByLabel(muons_,muons)){
	    for(unsigned int k =0; k!=muons->size();k++){
	      if(ROOT::Math::VectorUtil::DeltaR(muons->at(k).p4(),tau.leadPFChargedHadrCand()->p4())<0.15){
		if(muons->at(k).numberOfMatches()>nMatchedSegments){
		  nMatchedSegments = muons->at(k).numberOfMatches();
		  //std::cout<<" matched muon N Seg: "<<nMatchedSegments<<std::endl;
		}
		muonMatched=1;
	      }
	    }
	    
	  }
	}
	//std::cout<<"Get's Here 3 leadPFTrackPT "<< leadPFTrackPt<<std::endl;

	tau.addUserFloat("nIsoTracks",nIsoTracks);
	tau.addUserFloat("leadPFTrackPt",leadPFTrackPt);
	tau.addUserFloat("leadPFTrackPtErr",leadPFTrackPtErr);
	
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

