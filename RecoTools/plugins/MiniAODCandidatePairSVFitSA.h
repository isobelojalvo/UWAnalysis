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

#include "TauAnalysis/SVfitStandalone/interface/SVfitStandaloneAlgorithm.h"


#include "UWAnalysis/RecoTools/interface/candidateAuxFunctions.h"
#include "UWAnalysis/RecoTools/interface/generalAuxFunctions.h"

template<typename T1, typename T2>
class MiniAODCandidatePairSVFitSA : public edm::EDProducer
{
  typedef edm::Ptr<T1> T1Ptr;
  typedef edm::Ptr<T2> T2Ptr;
  typedef std::vector<edm::Ptr<pat::Jet> > JetPtrVector;
  typedef std::vector<CompositePtrCandidateT1T2MEt<T1,T2> > CompositePtrCandidateCollection;

 public:

  explicit MiniAODCandidatePairSVFitSA(const edm::ParameterSet& cfg)
  {
    src_     = cfg.getParameter<edm::InputTag>("src");


    produces<CompositePtrCandidateCollection>();
  }

  ~MiniAODCandidatePairSVFitSA(){}

  void beginJob()
  {

  }


  void produce(edm::Event& evt, const edm::EventSetup& es) {
    std::auto_ptr<CompositePtrCandidateCollection> out(new CompositePtrCandidateCollection);


    edm::Handle<std::vector<CompositePtrCandidateT1T2MEt<T1,T2> > > cands;

    if(evt.getByLabel(src_,cands)) {

      for (unsigned int i=0;i<cands->size();++i) {

        CompositePtrCandidateT1T2MEt<T1,T2> compositePtrCandidate = cands->at(i);
		reco::Candidate::LorentzVector theMETP4_ = compositePtrCandidate.calibratedMET();
		TMatrixD covMatrix_ = compositePtrCandidate.covMatrix();
		
	    std::vector<svFitStandalone::MeasuredTauLepton> measuredTauLeptons;
	    //std::cout<<"ID :"<<compositePtrCandidate.leg1()->pdgId()<<std::endl;
	    if (abs(compositePtrCandidate.leg1()->pdgId())==11)
	    {
		    measuredTauLeptons.push_back(svFitStandalone::MeasuredTauLepton(svFitStandalone::kTauToElecDecay, compositePtrCandidate.leg1()->pt(),compositePtrCandidate.leg1()->eta(),compositePtrCandidate.leg1()->phi(),compositePtrCandidate.leg1()->mass()));
	    }
	    else {
		    measuredTauLeptons.push_back(svFitStandalone::MeasuredTauLepton(svFitStandalone::kTauToMuDecay, compositePtrCandidate.leg1()->pt(),compositePtrCandidate.leg1()->eta(),compositePtrCandidate.leg1()->phi(),compositePtrCandidate.leg1()->mass()));
	    }
	    measuredTauLeptons.push_back(svFitStandalone::MeasuredTauLepton(svFitStandalone::kTauToHadDecay, compositePtrCandidate.leg2()->pt(),compositePtrCandidate.leg2()->eta(),compositePtrCandidate.leg2()->phi(),compositePtrCandidate.leg2()->mass(),compositePtrCandidate.leg2()->decayMode()));
	    SVfitStandaloneAlgorithm algo(measuredTauLeptons, theMETP4_.px(), theMETP4_.py(), covMatrix_, 0);
	    algo.addLogM(false);
	    algo.integrate();
	    double mass = algo.getMass();
	    //double massErr = algo.massUncert(); 
	    double pt = 0;//algo.pt(); 
	    //double ptErr = algo.ptUncert();

	    compositePtrCandidate.setSVMass(mass);
	    compositePtrCandidate.setSVPt(pt);
	    out->push_back(compositePtrCandidate);

      }
    }

    evt.put(out);
  }

 private:
  edm::InputTag src_;
  std::string label_;
  typedef std::vector<int> vint;

};


#endif

