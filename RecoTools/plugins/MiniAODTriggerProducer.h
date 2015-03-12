//Ovserloads the lepton with the rho factor


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/RecoCandidate/interface/RecoChargedCandidate.h"
#include "Math/GenVector/VectorUtil.h"

#include "UWAnalysis/DataFormats/interface/CompositePtrCandidateT1T2MEt.h"
#include "UWAnalysis/DataFormats/interface/CompositePtrCandidateT1T2MEtFwd.h"
#include "UWAnalysis/DataFormats/interface/CompositePtrCandidateTMEt.h"
#include "UWAnalysis/DataFormats/interface/CompositePtrCandidateTMEtFwd.h"

#include "DataFormats/HLTReco/interface/TriggerEvent.h"
#include "DataFormats/HLTReco/interface/TriggerRefsCollections.h"
#include "DataFormats/HLTReco/interface/TriggerObject.h"
#include "DataFormats/Math/interface/deltaR.h"
#include "FWCore/Common/interface/TriggerNames.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/PatCandidates/interface/TriggerObjectStandAlone.h"
#include "DataFormats/PatCandidates/interface/PackedTriggerPrescales.h"

// class decleration
//
template <typename T> 
class MiniAODTriggerProducer : public edm::EDProducer {

	public:
		explicit MiniAODTriggerProducer (const edm::ParameterSet& iConfig):
			src_(iConfig.getParameter<edm::InputTag>("src")),
			triggerEvent_(iConfig.getParameter<edm::InputTag>("trigEvent")),
			filters_(iConfig.getParameter<std::vector<edm::InputTag> >("filters")),
			pdgId_(iConfig.getParameter<int>("pdgId")),
			triggerBits_(consumes<edm::TriggerResults>(iConfig.getParameter<edm::InputTag>("bits"))),
			triggerObjects_(consumes<pat::TriggerObjectStandAloneCollection>(iConfig.getParameter<edm::InputTag>("objects"))),
			triggerPrescales_(consumes<pat::PackedTriggerPrescales>(iConfig.getParameter<edm::InputTag>("prescales")))

	{
		produces<std::vector<T> >();
	}

		~MiniAODTriggerProducer ()
		{

		}

	private:


		virtual void produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
		{
			using namespace reco;
			using namespace trigger;

			typedef reco::Candidate::LorentzVector LV;

			//Read the shallow clones of a candidate and save the SECOND Clone
			std::auto_ptr<std::vector<T> > out(new std::vector<T> );
			edm::Handle<std::vector<T> > src;

			edm::Handle<TriggerEvent> trigEv;
			iEvent.getByLabel(triggerEvent_,trigEv);

			edm::Handle<edm::TriggerResults> triggerBits;
			edm::Handle<pat::TriggerObjectStandAloneCollection> triggerObjects;
			edm::Handle<pat::PackedTriggerPrescales> triggerPrescales;
			iEvent.getByToken(triggerBits_, triggerBits);
			iEvent.getByToken(triggerObjects_, triggerObjects);
			iEvent.getByToken(triggerPrescales_, triggerPrescales);


			if(iEvent.getByLabel(src_,src))
				for(unsigned int i=0;i<src->size();++i) {
					T obj = src->at(i); //slimmed muons e.g.

					//loop the filters
					for(unsigned int i=0;i<filters_.size();++i) {
						size_t INDEX =trigEv->filterIndex(filters_[i]);

						std::vector<LV> trigObjects = getFilterCollection(INDEX,pdgId_,*trigEv);
						bool match = false;

						for(unsigned int j=0;j<trigObjects.size();++j) 
							if(deltaR(trigObjects.at(j),obj)<0.5) {
								match=true;
								break;
							}




						if(match)
							obj.addUserFloat(filters_[i].label(),1.0);
						else
							obj.addUserFloat(filters_[i].label(),0.0);
					}


					out->push_back(obj);
				}

			iEvent.put(out);



		}

		virtual void endJob() { }



		std::vector<reco::Candidate::LorentzVector> 
			getFilterCollection(size_t index,int id,const trigger::TriggerEvent& trigEv)
			{
				//Create output Collection
				std::vector<reco::Candidate::LorentzVector>  out;
				//get All the final trigger objects
				const trigger::TriggerObjectCollection& TOC(trigEv.getObjects());
				//filter index
				if(index!=trigEv.sizeFilters())

				{
					const trigger::Keys& KEYS = trigEv.filterKeys(index);
					for(size_t i = 0;i<KEYS.size();++i)
					{
						const trigger::TriggerObject& TO(TOC[KEYS[i]]);
						reco::Candidate::LorentzVector a(TO.px(),TO.py(),TO.pz(),sqrt(TO.px()*TO.px()+TO.py()*TO.py()+TO.pz()*TO.pz()));
						if(abs(TO.id()) == id)
							out.push_back(a);
					}
				}

				return out;
			}


		edm::EDGetTokenT<edm::TriggerResults> triggerBits_;
		edm::EDGetTokenT<pat::TriggerObjectStandAloneCollection> triggerObjects_;
		edm::EDGetTokenT<pat::PackedTriggerPrescales> triggerPrescales_;
		edm::InputTag src_;
		edm::InputTag triggerEvent_;
		std::vector<edm::InputTag> filters_;
		int pdgId_;

};
