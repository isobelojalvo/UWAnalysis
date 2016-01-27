// -*- C++ -*-
//
// Package:    PATMuonTrackVetoSelector
// Class:      PATMuonTrackVetoSelector
// 
// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Tau.h"

#include "DataFormats/ParticleFlowCandidate/interface/PFCandidate.h"
#include "DataFormats/ParticleFlowCandidate/interface/PFCandidateFwd.h"

#include "Math/GenVector/VectorUtil.h"
//
// class decleration





template <class T>
class DiCandidateSorterByIso : public edm::EDProducer {
   public:
  explicit DiCandidateSorterByIso(const edm::ParameterSet& iConfig):
    src_(consumes<std::vector<T>>(iConfig.getParameter<edm::InputTag>("src")))
     {
       produces<std::vector<T> >();
     }

  ~DiCandidateSorterByIso() {}


   private:
  virtual void produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
  {
    using namespace edm;
    using namespace reco;
    
    std::vector<T> toBeSorted;
    Handle<std::vector<T> > cands;
    if(iEvent.getByToken(src_,cands)) {toBeSorted =  *cands;}

    if(toBeSorted.size()>0) {
      Sorter sorter;
      std::sort(toBeSorted.begin(),toBeSorted.end(),sorter);
    }
    else {std::cout<<"SorterSize==0!"<<std::endl;}

    std::auto_ptr<std::vector<T> > out(new std::vector<T>);
    for(unsigned int i=0;i<toBeSorted.size();++i)
      out->push_back(toBeSorted.at(i));
    
    iEvent.put(out);

  } 

  //  template<class T>
  class Sorter {
  public:
    Sorter() 
    {}
    ~Sorter()
    {}
    bool operator()(T t1,T t2)
    {
      if ((t1.leg1()->userFloat("dBRelIso03")) < (t2.leg1()->userFloat("dBRelIso03")))
         return true;
      else if(((t1.leg1()->userFloat("dBRelIso03")) == (t2.leg1()->userFloat("dBRelIso03")))&& ( (t1.leg1()->pt()) > (t2.leg1()->pt()) ) )
         return true;
      else if(((t1.leg1()->userFloat("dBRelIso03")) == (t2.leg1()->userFloat("dBRelIso03")))&&( (t1.leg1()->pt()) == (t2.leg1()->pt()) )&&((t1.leg2()->tauID("byCombinedIsolationDeltaBetaCorrRaw3Hits") < t2.leg2()->tauID("byCombinedIsolationDeltaBetaCorrRaw3Hits")) ) )
         return true;
      else if(((t1.leg1()->userFloat("dBRelIso03")) == (t2.leg1()->userFloat("dBRelIso03")))&&( (t1.leg1()->pt()) == (t2.leg1()->pt()) )&&((t1.leg2()->tauID("byCombinedIsolationDeltaBetaCorrRaw3Hits") == t2.leg2()->tauID("byCombinedIsolationDeltaBetaCorrRaw3Hits")) )&&((t1.leg2()->pt()) > (t2.leg2()->pt())))
	 return true; 
      else {return false;}

    } 
};

      // ----------member data ---------------------------
      edm::EDGetTokenT<std::vector<T>>  src_;



};
