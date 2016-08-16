#ifndef UWAnalysis_RecoTools_PATCandSVFitSA_h
#define UWAnalysis_RecoTools_PATCandSVFitSA_h

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"

#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/InputTag.h"

#include "DataFormats/Common/interface/View.h"

#include "DataFormats/Math/interface/deltaR.h"

#include "UWAnalysis/RecoTools/interface/FetchCollection.h"

#include "UWAnalysis/DataFormats/interface/CompositePtrCandidateT1T2MEt.h"
#include "UWAnalysis/DataFormats/interface/CompositePtrCandidateT1T2MEtFwd.h"

#include "UWAnalysis/RecoTools/interface/candidateAuxFunctions.h"
#include "UWAnalysis/RecoTools/interface/generalAuxFunctions.h"

template<typename T1, typename T2>
class MiniAODLeptonVeto : public edm::EDProducer
{
  typedef edm::Ptr<T1> T1Ptr;
  typedef edm::Ptr<T2> T2Ptr;
  typedef std::vector<edm::Ptr<pat::Jet> > JetPtrVector;
  typedef std::vector<CompositePtrCandidateT1T2MEt<T1,T2> > CompositePtrCandidateCollection;

 public:

  explicit MiniAODLeptonVeto(const edm::ParameterSet& cfg)
  {
    src_     = consumes<std::vector<CompositePtrCandidateT1T2MEt<T1,T2> > >(cfg.getParameter<edm::InputTag>("src"));
    srcM_    = consumes<std::vector<pat::Muon>>(cfg.getParameter<edm::InputTag>("srcM"));//Tight Muons
    srcE_    = consumes<std::vector<pat::Electron>>(cfg.getParameter<edm::InputTag>("srcE"));//Tight Electron
    mu_      = cfg.getParameter<bool>("hasMu");
    ele_      = cfg.getParameter<bool>("hasEle");


    produces<CompositePtrCandidateCollection>();
  }

  ~MiniAODLeptonVeto(){}

  void beginJob()
  {

  }


  void produce(edm::Event& evt, const edm::EventSetup& es) {
    std::auto_ptr<CompositePtrCandidateCollection> out(new CompositePtrCandidateCollection);


    edm::Handle<std::vector<CompositePtrCandidateT1T2MEt<T1,T2> > > cands;

    if(evt.getByToken(src_,cands)) {

      for (unsigned int i=0;i<cands->size();++i) {

	      CompositePtrCandidateT1T2MEt<T1,T2> compositePtrCandidate = cands->at(i);
	      //reco::Candidate::LorentzVector theMETP4_ = compositePtrCandidate.calibratedMET();
	      edm::Handle<std::vector<pat::Muon>> muonsCollection;
	      evt.getByToken(srcM_ , muonsCollection);
	      edm::Handle<std::vector<pat::Electron>> elesCollection;
	      evt.getByToken(srcE_ , elesCollection);

	      int veto =0;
	      unsigned int maxMu=0;
	      unsigned int maxEle=0;
	      if (mu_){	maxMu=1;}
          else if(ele_) { maxEle=1;}

	      if (elesCollection->size()>maxEle) veto=1;
	      if (muonsCollection->size()>maxMu) veto=1;
	      compositePtrCandidate.setLVeto(veto);
	      out->push_back(compositePtrCandidate);

      }
    }

    evt.put(out);
  }

 private:
  edm::EDGetTokenT<std::vector<CompositePtrCandidateT1T2MEt<T1,T2> > > src_;
  edm::EDGetTokenT<std::vector<pat::Muon>> srcM_;
  edm::EDGetTokenT<std::vector<pat::Electron>> srcE_;
  //edm::InputTag src_;
  bool mu_;
  bool ele_;

};


#endif

