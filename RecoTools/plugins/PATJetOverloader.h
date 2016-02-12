// -*- C++ -*-
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

#include "DataFormats/PatCandidates/interface/PackedCandidate.h"

class PATJetOverloader : public edm::EDProducer {
   public:
  
  
  //vector<reco::GenJet>                  "ak5GenJets" 
  explicit PATJetOverloader(const edm::ParameterSet& iConfig):
    src_(consumes<pat::JetCollection>(iConfig.getParameter<edm::InputTag>("src"))),
    genJets_(consumes<reco::GenJetCollection>(iConfig.getParameter<edm::InputTag>("genJets")))
  {
    produces<pat::JetCollection>();
  }
  
  ~PATJetOverloader() {}
   private:

  virtual void produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
  {
    //std::cout<<"===== PATJetOverloader NAMESPACE ====="<<std::endl;
    using namespace edm;
    using namespace reco;
    using namespace std;
    //std::cout<<"===== PATJetOverloader JetCollection ====="<<std::endl;
    std::auto_ptr<pat::JetCollection> jets(new pat::JetCollection);
    Handle<pat::JetCollection > cands;
    Handle<reco::GenJetCollection > genJets;
    if(iEvent.getByToken(src_,cands)) 
      for(unsigned int  i=0;i!=cands->size();++i){
	pat::Jet jet = cands->at(i);
	float pt=0.0;
	float sumPt=0.0;
	float sumPt2=0.0;
	//std::cout<<"===== PATJetOverloader Jet Number of Daughters ====="<<std::endl;
	//std::cout<<"numberOfDaughters(Constituents): "<<jet.numberOfDaughters()<<std::endl;
	std::vector<reco::CandidatePtr> daus(jet.daughterPtrVector());
	std::sort(daus.begin(), daus.end(), [](const reco::CandidatePtr &p1, const reco::CandidatePtr &p2) { return p1->pt() > p2->pt(); }); // the joys of C++11
	for (unsigned int i2 = 0, n = daus.size(); i2 < n; ++i2) {
		const pat::PackedCandidate &cand = dynamic_cast<const pat::PackedCandidate &>(*daus[i2]);
		pt=cand.pt();
		//std::cout<<"Constituent Pt: "<<pt<<std::endl;
		sumPt+=pt;
		sumPt2+=pt*pt;
	}
	//std::cout<<"Constituent SumPt: "<<sumPt<<std::endl;
	//std::cout<<"Constituent SumPt^2: "<<sumPt2<<std::endl;

	bool loose = true;
	bool medium = true; //tightLep veto
	bool tight = true;
	if (std::abs(jet.eta()) <= 3.0){
		if (jet.neutralHadronEnergyFraction() >= 0.99)
			loose = false;
		if (jet.neutralHadronEnergyFraction() >= 0.90)
			tight = false;
			medium = false;
		if (jet.neutralEmEnergyFraction() >= 0.99)
			loose = false;
		if (jet.neutralEmEnergyFraction() >= 0.90)
			tight = false;
		if ((jet.chargedMultiplicity()+jet.neutralMultiplicity()) <= 1) { //getPFConstitutents broken in miniAOD
			loose = false;
			medium = false;
			tight = false;
		}
		if (jet.muonEnergyFraction() >= 0.8){
			medium = false;
		}

		if (std::abs(jet.eta()) <= 2.4) {
			if (jet.chargedHadronEnergyFraction() == 0) {
				loose = false;
				medium = false;
				tight = false;
			}
			if (jet.chargedHadronMultiplicity() == 0) {
				loose = false;
				medium = false;
				tight = false;
			}
			if (jet.chargedEmEnergyFraction() >= 0.99) {
				loose = false;
				medium = false;
				tight = false;
			}
		}
	}
	else if (std::abs(jet.eta()) > 3.0) {
		if (jet.neutralEmEnergyFraction() >= 0.90) {
			loose = false;
			medium = false;
			tight = false;
		}
		if (jet.neutralMultiplicity() <= 10) {
			loose = false;
			medium = false;
			tight = false;
		}
	}
	jet.addUserFloat("idLoose", loose);
	jet.addUserFloat("idTightLepVeto", medium);
	jet.addUserFloat("idTight", tight);



	// Pileup discriminant
	bool passPU = true;
	float jpumva = jet.userFloat("pileupJetId:fullDiscriminant");
	if(jet.pt() > 20)
	{
		if(fabs(jet.eta()) > 3.)
		{
			if(jpumva <= -0.45) passPU = false;
		}
		else if(fabs(jet.eta()) > 2.75)
		{
			if(jpumva <= -0.55) passPU = false;
		}
		else if(fabs(jet.eta()) > 2.5)
		{
			if(jpumva <= -0.6) passPU = false;
		}
		else if(jpumva <= -0.63) passPU = false;
	}
	else
	{
		if(fabs(jet.eta()) > 3.)
		{
			if(jpumva <= -0.95) passPU = false;
		}
		else if(fabs(jet.eta()) > 2.75)
		{
			if(jpumva <= -0.94) passPU = false;
		}
		else if(fabs(jet.eta()) > 2.5)
		{
			if(jpumva <= -0.96) passPU = false;
		}
		else if(jpumva <= -0.95) passPU = false;
	}

	jet.addUserFloat("puID", float(passPU));



	float genJetPt =-10;
	float genJetEta =-10;
	float genJetPhi =-10;
	float DRMin = 0.5;
	float Vtx3dL = -10;
	float Vtx3deL = -10;
	float VtxPt = -10;
	float uncorrectedPt= -10;
	//std::cout<<"===== PATJetOverloader UncorrectedPt ====="<<std::endl;
	uncorrectedPt = jet.correctedP4(0).pt();
	//CHECKME
	//std::cout<<"'Uncorrected' jet pt: "<<uncorrectedPt<<std::endl;

	//std::cout<<"===== PATJetOverloader GenJet ====="<<std::endl;
	if(iEvent.getByToken(genJets_,genJets))
		for(unsigned int k=0;k!=genJets->size();k++){
			if(ROOT::Math::VectorUtil::DeltaR(genJets->at(k).p4(),jet.p4())<DRMin){
				DRMin = ROOT::Math::VectorUtil::DeltaR(genJets->at(k).p4(),jet.p4());
				genJetPt=genJets->at(k).pt();
				genJetEta=genJets->at(k).eta();
				genJetPhi=genJets->at(k).phi();
			}
		}

	//std::cout<<"===== PATJetOverloader Secondary Vertex ====="<<std::endl;
	const reco::SecondaryVertexTagInfo* secInfo = jet.tagInfoSecondaryVertex("secondaryVertex");
	if(secInfo && secInfo->vertexTracks().size()>0){
		const reco::Vertex&sv= secInfo->secondaryVertex(0);
		//jetVtxPt = sv.pt();
		Vtx3dL = (secInfo->flightDistance(0).value());
		Vtx3deL = (secInfo->flightDistance(0).error());
		reco::Candidate::LorentzVector sumP4(0,0,0,0);
		//FIXME
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
  edm::EDGetTokenT<pat::JetCollection> src_;
  edm::EDGetTokenT<reco::GenJetCollection> genJets_;
  reco::PFCandidatePtr pfcand;
};

