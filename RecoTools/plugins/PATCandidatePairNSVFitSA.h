#ifndef UWAnalysis_RecoTools_PATCandNSVFitSA_h
#define UWAnalysis_RecoTools_PATCandNSVFitSA_h

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

//#include "TauAnalysis/CandidateTools/plugins/NSVfitStandaloneTestAnalyzer.h"
//#include "TauAnalysis/CandidateTools/interface/PFMEtSignInterface.h"
#include "TauAnalysis/CandidateTools/interface/NSVfitStandaloneAlgorithm.h"


#include "UWAnalysis/RecoTools/interface/candidateAuxFunctions.h"
#include "UWAnalysis/RecoTools/interface/generalAuxFunctions.h"

template<typename T1, typename T2>
class PATCandidatePairNSVFitSA : public edm::EDProducer
{
  typedef edm::Ptr<T1> T1Ptr;
  typedef edm::Ptr<T2> T2Ptr;
  typedef std::vector<edm::Ptr<pat::Jet> > JetPtrVector;
  typedef std::vector<CompositePtrCandidateT1T2MEt<T1,T2> > CompositePtrCandidateCollection;

 public:

  explicit PATCandidatePairNSVFitSA(const edm::ParameterSet& cfg)
  {
    src_     = cfg.getParameter<edm::InputTag>("src");
    srcPV_       =  cfg.getParameter<edm::InputTag>("srcPrimaryVertex") ;

//     label_ = cfg.getParameter<std::string>("resultLabel");
// 
//     printf("Will use NSV FIt\n");
//     edm::ParameterSet cfg_config = cfg.getParameter<edm::ParameterSet>("config");
//     edm::ParameterSet cfg_event = cfg_config.getParameter<edm::ParameterSet>("event");

    //edm::ParameterSet cfg_algorithm = cfg.getParameter<edm::ParameterSet>("algorithm");
    //cfg_algorithm.addParameter<edm::ParameterSet>("event", cfg_event);
    //std::string pluginType = cfg_algorithm.getParameter<std::string>("pluginType");
    //algorithm_ = NSVfitAlgorithmPluginFactory::get()->create(pluginType, cfg_algorithm);

    produces<CompositePtrCandidateCollection>();
  }

  ~PATCandidatePairNSVFitSA(){}

  void beginJob()
  {

  }


  void produce(edm::Event& evt, const edm::EventSetup& es) {
    std::auto_ptr<CompositePtrCandidateCollection> out(new CompositePtrCandidateCollection);

    // Get primary vertex
//     const reco::Vertex* pv = NULL;
//     if ( srcPV_.label() != "" ) {
//        edm::Handle<reco::VertexCollection> pvs;
//        pf::fetchCollection(pvs, srcPV_, evt);
//        pv = &((*pvs)[0]);
//     }


    edm::Handle<std::vector<CompositePtrCandidateT1T2MEt<T1,T2> > > cands;

    if(evt.getByLabel(src_,cands)) {

      for (unsigned int i=0;i<cands->size();++i) {

        CompositePtrCandidateT1T2MEt<T1,T2> compositePtrCandidate = cands->at(i);
		reco::Candidate::LorentzVector theMETP4_ = compositePtrCandidate.calibratedMET();
		TMatrixD covMatrix_ = compositePtrCandidate.covMatrix();
		
	    std::vector<NSVfitStandalone::MeasuredTauLepton> measuredTauLeptons;
	    measuredTauLeptons.push_back(NSVfitStandalone::MeasuredTauLepton(NSVfitStandalone::kLepDecay, compositePtrCandidate.leg1()->p4()));
	    measuredTauLeptons.push_back(NSVfitStandalone::MeasuredTauLepton(NSVfitStandalone::kHadDecay, compositePtrCandidate.leg2()->p4()));
	    NSVfitStandaloneAlgorithm algo(measuredTauLeptons, theMETP4_.Vect(), covMatrix_, 0);
	    algo.addLogM(false);
	    //algo.integrateMarkovChain();
	    algo.integrateVEGAS();
	    double mass = algo.getMass();
		//double massErr = algo.massUncert(); 
		double pt = algo.pt(); 
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
  edm::InputTag srcPV_;
  std::string label_;
  typedef std::vector<int> vint;

};


#endif
