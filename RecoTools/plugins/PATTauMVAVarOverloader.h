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

#include "UWAnalysis/RecoTools/interface/PATTauClusterVariables.h"

#include "DataFormats/TauReco/interface/PFTauTransverseImpactParameterAssociation.h"

#include "Math/GenVector/VectorUtil.h"
//
// class declaration
#include <boost/foreach.hpp>
#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/Math/interface/angle.h"


class PATTauMVAVarOverloader : public edm::EDProducer {
   public:
  

  explicit PATTauMVAVarOverloader(const edm::ParameterSet& iConfig):
  src_(consumes<pat::TauCollection>(iConfig.getParameter<edm::InputTag>("src"))),
  vtxSrc_(consumes<reco::VertexCollection>(iConfig.getParameter<edm::InputTag>("vtxSrc")))
  {
    produces<pat::TauCollection>();
  }
  
  ~PATTauMVAVarOverloader() {}
   private:


  virtual void produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
  {
    using namespace edm;
    using namespace reco;
    std::auto_ptr<pat::TauCollection> taus(new pat::TauCollection);
    Handle<pat::TauCollection > recTaus;
    
    edm::Handle<reco::VertexCollection> vertices;
    iEvent.getByToken(vtxSrc_, vertices);
    //const reco::Vertex& thePV = *vertices->begin();

  
    if(iEvent.getByToken(src_,recTaus)){
      size_t numRecTaus = recTaus->size();
    
      for ( size_t iRecTau = 0; iRecTau < numRecTaus; ++iRecTau ) {
	//for(unsigned int  i=0;i!=recTaus->size();++i){
	pat::Tau tau = recTaus->at(iRecTau);
	pat::TauRef recTau(recTaus, iRecTau);
	//std::cout<<"Tau : "<<i<<std::endl;
        //std::cout<<"   Tau  pt: "<<recTau->pt()<<" eta: "<<recTau->eta()<<" byCmbIso: "<<recTau->tauID("byCombinedIsolationDeltaBetaCorrRaw3Hits")<<std::endl;  

	//Tau shape variables
	int dm = recTau->decayMode();
	//float EMratio = recTau->emFraction();
        //std::cout<<"emfraction: "<<EMratio<<std::endl;
	float pt_weighted_dr_signal = tau_pt_weighted_dr_signal(tau,dm); 
	tau.addUserFloat("recTauPtWeightedDrSignal", pt_weighted_dr_signal);
	float pt_weighted_deta_strip = tau_pt_weighted_deta_strip(tau,dm);
	tau.addUserFloat("recTauPtWeightedDetaStrip", pt_weighted_deta_strip);
	float pt_weighted_dphi_strip = tau_pt_weighted_dphi_strip(tau,dm);
	tau.addUserFloat("recTauPtWeightedDphiStrip", pt_weighted_dphi_strip);
	float pt_weighted_dr_iso = tau_pt_weighted_dr_iso(tau,dm);
	tau.addUserFloat("recTauPtWeightedDrIsolation",pt_weighted_dr_iso);
	float n_photons_total = tau_n_photons_total(tau);
	tau.addUserFloat("n_photons_total",n_photons_total);
	
	//recTau   ##en,px,py,pz,m,eta,phi,pt of cand
	//recTauAlternate   ##en,px,py,pz,m,eta,phi,pt of cand
	//recTauVtxZ  
	//recJet   ##en,px,py,pz,m,eta,phi,pt of cand
	//recJetLooseId  
	//leadPFCand   ##en,px,py,pz,m,eta,phi,pt of cand
	//leadPFChargedHadrCand   ##en,px,py,pz,m,eta,phi,pt of cand
	//recImpactParamPCA  #XYZRMAG
	//recImpactParamPCA3D  #XYZRMAG
	//recDecayVertex  #XYZRMAG
	//recDecayVertexCov  #xx xy xz yy yz zz
	//recDecayDist  #XYZRMAG
	//recDecayDistCov  #xx xy xz yy yz zz

	//Impact Parameter Variables
	//typedef edm::AssociationVector<reco::PFTauRefProd, std::vector<reco::PFTauTransverseImpactParameterRef> > PFTauTIPAssociationByRef;
	//edm::Handle<PFTauTIPAssociationByRef> recTauLifetimeInfos;
	//iEvent.getByLabel(srcRecTauTransverseImpactParameters_, recTauLifetimeInfos);
	//const reco::PFTauTransverseImpactParameter& recTauLifetimeInfo = *(*recTauLifetimeInfos)[recTau];
	
	float recImpactParam = recTau->dxy();
	tau.addUserFloat("recImpactParam",recImpactParam);

	float recImpactParamSign = recTau->dxy_Sig();
	tau.addUserFloat("recImpactParamSign",recImpactParamSign);

	float recImpactParam3D = recTau->ip3d();
	tau.addUserFloat("recImpactParam3D",recImpactParam3D);

	float recImpactParamSign3D = recTau->ip3d_Sig();
	tau.addUserFloat("recImpactParamSign3D",recImpactParamSign3D);

	//Variables if has secondary vertex
	//GlobalVector direction(recTau->p4().px(), recTau->p4().py(), recTau->p4().pz());
	//const reco::VertexRef secVertex = recTauLifetimeInfo.secondaryVertex();
	//float recDecayDist2D     = -999;
	//float recDecayDistSign2D = -999;
	//if(recTauLifetimeInfo.hasSecondaryVertex()){
	///recDecayDist2D     = reco::SecondaryVertex::computeDist2d(*(recTauLifetimeInfo.primaryVertex()), *secVertex, direction, true).value();
	//recDecayDistSign2D = reco::SecondaryVertex::computeDist2d(*(recTauLifetimeInfo.primaryVertex()), *secVertex, direction, true).significance();
	//}
	//tau.addUserFloat("recDecayDist2D",recDecayDist2D);
	//tau.addUserFloat("recDecayDistSign2D",recDecayDistSign2D);

	//float recChi2DiffEvtVertex = -999;
	//if ( vertices->size() >= 1 ) {
	//recChi2DiffEvtVertex = (vertices->front().normalizedChi2() - recTauLifetimeInfo.primaryVertex()->normalizedChi2());
	//}
	//tau.addUserFloat("recChi2DiffEvtVertex",recChi2DiffEvtVertex);

	//float recImpactParamZ       = -999;
	//float recImpactParamSignZ   = -999;
	//float recDecayLengthTk1     = -999;
	//float recDecayLengthSignTk1 = -999;

	//edm::ESHandle<TransientTrackBuilder> transTrackBuilder;
	//es.get<TransientTrackRecord>().get("TransientTrackBuilder",transTrackBuilder);

	//if ( recTau->leadPFChargedHadrCand().isNonnull() && recTau->leadPFChargedHadrCand()->bestTrack() != 0){
	//const reco::Track* leadtrk = recTau->leadPFChargedHadrCand()->bestTrack();
	//reco::TransientTrack ttrk  = transTrackBuilder->build(&*leadtrk);
	//std::pair<bool,Measurement1D> ip_z   = STIP->zImpactParameter ( ttrk, direction, *(recTauLifetimeInfo.primaryVertex()) );
	//std::pair<bool,Measurement1D> dl_tk1 = IPTools::signedDecayLength3D(ttrk, direction, *(recTauLifetimeInfo.primaryVertex()) );
	//recImpactParamZ       = (!isnan(ip_z.second.value())) ? ip_z.second.value() : -899.;
	//recImpactParamSignZ   = (!isnan(ip_z.second.significance())) ? ip_z.second.significance() : -899.;
	//recDecayLengthTk1     = dl_tk1.second.value();
	//recDecayLengthSignTk1 = dl_tk1.second.significance();
	//}
	//tau.addUserFloat("recImpactParamZ",recImpactParamZ);
	//tau.addUserFloat("recImpactParamSignZ",recImpactParamSignZ);
	//tau.addUserFloat("recDecayLengthTk1",recDecayLengthTk1);
	//tau.addUserFloat("recDecayLengthSignTk1",recDecayLengthSignTk1);

	//float recImpactParamTk2       = -999;
	//float recImpactParamSignTk2   = -999;
	//float recImpactParam3DTk2     = -999;
	//float recImpactParamSign3DTk2 = -999;
	//float recImpactParamZTk2      = -999;
	//float recImpactParamSignZTk2  = -999;
	//float recDecayLengthTk2       = -999;
	//float recDecayLengthSignTk2   = -999;

	//if(recTau->signalPFChargedHadrCands().size() > 1){
	//const std::vector<reco::PFCandidatePtr> SigChCands = recTau->signalPFChargedHadrCands();
	//const reco::Track* leadtrk2 = SigChCands[1]->bestTrack();
	//if(leadtrk2){
	//reco::TransientTrack ttrk2 = transTrackBuilder->build(&*leadtrk2);
	//GlobalVector direction(recTau->p4().px(), recTau->p4().py(), recTau->p4().pz());
	//std::pair<bool,Measurement1D> ip_z   = STIP->zImpactParameter ( ttrk2, direction, *(recTauLifetimeInfo.primaryVertex()) );
	//std::pair<bool,Measurement1D> ip_xy  = IPTools::signedTransverseImpactParameter(ttrk2, direction, *(recTauLifetimeInfo.primaryVertex()) );
	//std::pair<bool,Measurement1D> ip_3d  = IPTools::signedImpactParameter3D(ttrk2, direction, *(recTauLifetimeInfo.primaryVertex()) );
	//std::pair<bool,Measurement1D> dl_tk2 = IPTools::signedDecayLength3D(ttrk2, direction, *(recTauLifetimeInfo.primaryVertex()) );
	//recImpactParamTk2       = ip_xy.second.value();
	//recImpactParamSignTk2   = (ip_xy.second.error() != 0) ? ip_xy.second.value()/ip_xy.second.error() : 0.;
	//recImpactParam3DTk2     = ip_3d.second.value();
	//recImpactParamSign3DTk2 = (ip_3d.second.error() != 0) ? ip_3d.second.value()/ip_3d.second.error() : 0.;
	//recImpactParamZTk2      = (!isnan(ip_z.second.value())) ? ip_z.second.value() : -899.;
	//recImpactParamSignZTk2  = (!isnan(ip_z.second.significance())) ? ip_z.second.significance() : -899.;
	//recDecayLengthTk2       = dl_tk2.second.value();
	//recDecayLengthSignTk2   = dl_tk2.second.significance();
	//}
	//}

	//tau.addUserFloat("recImpactParamTk2",recImpactParamTk2);
	//tau.addUserFloat("recImpactParamSignTk2",recImpactParamSignTk2);
	//tau.addUserFloat("recImpactParam3DTk2",recImpactParam3DTk2);
	//tau.addUserFloat("recImpactParamSign3DTk2",recImpactParamSign3DTk2);
	//tau.addUserFloat("recImpactParamZTk2",recImpactParamZTk2);
	//tau.addUserFloat("recImpactParamSignZTk2",recImpactParamSignZTk2);
	//tau.addUserFloat("recDecayLengthTk2",recDecayLengthTk2);
	//tau.addUserFloat("recDecayLengthSignTk2",recDecayLengthSignTk2);
	/*
	float recImpactParamTk3       = -999;
	float recImpactParamSignTk3   = -999;
	float recImpactParam3DTk3     = -999;
	float recImpactParamSign3DTk3 = -999;
	float recImpactParamZTk3      = -999;
	float recImpactParamSignZTk3  = -999;
	float recDecayLengthTk3       = -999;
	float recDecayLengthSignTk3   = -999;

	if(recTau->signalPFChargedHadrCands().size() > 2){
	  const std::vector<reco::PFCandidatePtr> SigChCands = recTau->signalPFChargedHadrCands();
	  const reco::Track* leadtrk3 = SigChCands[2]->bestTrack();
	  if(leadtrk3){
	    reco::TransientTrack ttrk3 = transTrackBuilder->build(&*leadtrk3);
	    GlobalVector direction(recTau->p4().px(), recTau->p4().py(), recTau->p4().pz());
	    std::pair<bool,Measurement1D> ip_z   = STIP->zImpactParameter ( ttrk3, direction, *(recTauLifetimeInfo.primaryVertex()) );
	    std::pair<bool,Measurement1D> ip_xy  = IPTools::signedTransverseImpactParameter(ttrk3, direction, *(recTauLifetimeInfo.primaryVertex()) );
	    std::pair<bool,Measurement1D> ip_3d  = IPTools::signedImpactParameter3D(ttrk3, direction, *(recTauLifetimeInfo.primaryVertex()) );
	    std::pair<bool,Measurement1D> dl_tk3 = IPTools::signedDecayLength3D(ttrk3, direction, *(recTauLifetimeInfo.primaryVertex()) );
	    recImpactParamTk3       = ip_xy.second.value();
	    recImpactParamSignTk3   = (ip_xy.second.error() != 0) ? ip_xy.second.value()/ip_xy.second.error() : 0.;
	    recImpactParam3DTk3     = ip_3d.second.value();
	    recImpactParamSign3DTk3 = (ip_3d.second.error() != 0) ? ip_3d.second.value()/ip_3d.second.error() : 0.;
	    recImpactParamZTk3      = (!isnan(ip_z.second.value())) ? ip_z.second.value() : -899.;
	    recImpactParamSignZTk3  = (!isnan(ip_z.second.significance())) ? ip_z.second.significance() : -899.;
	    recDecayLengthTk3       = dl_tk3.second.value();
	    recDecayLengthSignTk3   = dl_tk3.second.significance();
	  }
	}

	tau.addUserFloat("recImpactParamTk3",recImpactParamTk3);
	tau.addUserFloat("recImpactParamSignTk3",recImpactParamSignTk3);
	tau.addUserFloat("recImpactParam3DTk3",recImpactParam3DTk3);
	tau.addUserFloat("recImpactParamSign3DTk3",recImpactParamSign3DTk3);
	tau.addUserFloat("recImpactParamZTk3",recImpactParamZTk3);
	tau.addUserFloat("recImpactParamSignZTk3",recImpactParamSignZTk3);
	tau.addUserFloat("recDecayLengthTk3",recDecayLengthTk3);
	tau.addUserFloat("recDecayLengthSignTk3",recDecayLengthSignTk3);
	*/

	//hasRecDecayVertex        
	float hasRecDecayVertex = recTau->hasSecondaryVertex();
	tau.addUserFloat("hasRecDecayVertex",hasRecDecayVertex);
	
	//recDecayVertexChi2  
	float recDecayVertexChi2 = -999;
	const reco::VertexRef secVertex = recTau->secondaryVertex();
	if(secVertex.isNonnull())
	  recDecayVertexChi2 = recTau->secondaryVertex()->normalizedChi2();
	tau.addUserFloat("recDecayVertexChi2",recDecayVertexChi2);

	//recDecayDistSign
	float recDecayDistSign= recTau->flightLengthSig();
	tau.addUserFloat("recDecayDistSign",recDecayDistSign);
	
	//recTauPtWeightedDetaStrip   
	//float recTauPtWeightedDetaStrip = tau_pt_weighted_deta_strip(recTau,dm);   
	//tau.addUserFloat("recTauPtWeightedDetaStrip",recTauPtWeightedDetaStrip);
	
	//recTauPtWeightedDphiStrip   
	//float recTauPtWeightedDphiStrip =  tau_pt_weighted_dphi_strip(recTau,dm);   
	//tau.addUserFloat("recTauPtWeightedDphiStrip",recTauPtWeightedDetaStrip);

	//recTauPtWeightedDrSignal    
	//float recTauPtWeightedDrSignal = tau_pt_weighted_dr_signal(recTau,dm); 
	//tau.addUserFloat("recTauPtWeightedDrSignal",recTauPtWeightedDrSignal);

	//recTauPtWeightedDrIsolation 
	//float recTauPtWeightedDrIsolation = tau_pt_weighted_dr_iso(recTau,dm);
	//tau.addUserFloat("recTauPtWeightedDrIsolation",recTauPtWeightedDrIsolation);
	
	//recTauNphoton  		    
	float recTauNphoton = tau_n_photons_total(tau);
	tau.addUserFloat("recTauNphoton",recTauNphoton);

	//recTauEratio 
	float recTauEratio = returnEratio(*recTau);
	tau.addUserFloat("recTauEratio",recTauEratio);

	//recTauLeadingTrackChi2  
	float recTauLeadingTrackChi2 = recTau->leadingTrackNormChi2();
	tau.addUserFloat("recTauLeadingTrackChi2",recTauLeadingTrackChi2);

	//recTauNphotonSignal  	    
	float recTauNphotonSignal = recTau->signalPFGammaCands().size();
	tau.addUserFloat("recTauNphotonSignal",recTauNphotonSignal);

	//recTauNphotonIso  	    
	float recTauNphotonIso = recTau->isolationPFGammaCands().size();
	tau.addUserFloat("recTauNphotonIso",recTauNphotonIso);

	//recTauNphotonTotal  	    
	float recTauNphotonTotal = recTau->signalPFGammaCands().size()+recTau->isolationPFGammaCands().size();
	tau.addUserFloat("recTauNphotonTotal",recTauNphotonTotal);

	taus->push_back(tau);
      }
    }
    iEvent.put(taus);
  }

  

  float returnEratio(const pat::Tau& tau){

    Float_t total = tau.ecalEnergy() + tau.hcalEnergy();
    if(total==0) return -1;
    else return tau.ecalEnergy()/total;
  }
  
  // ----------member data ---------------------------
  edm::EDGetTokenT<pat::TauCollection> src_;
  edm::EDGetTokenT<reco::VertexCollection> vtxSrc_;


};

