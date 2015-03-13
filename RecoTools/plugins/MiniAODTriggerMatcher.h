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

#include "UWAnalysis/DataFormats/interface/CompositePtrCandidateT1T2MEtFwd.h"
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
class MiniAODTriggerMatcher : public edm::EDProducer {

	public:
		explicit MiniAODTriggerMatcher (const edm::ParameterSet& iConfig):
			src_(iConfig.getParameter<edm::InputTag>("src")),
			//triggerEvent_(iConfig.getParameter<edm::InputTag>("trigEvent")),
			filters_(iConfig.getParameter<std::vector<std::string> >("filters")),
			triggerBits_(consumes<edm::TriggerResults>(iConfig.getParameter<edm::InputTag>("bits"))),
			triggerObjects_(consumes<pat::TriggerObjectStandAloneCollection>(iConfig.getParameter<edm::InputTag>("objects"))),
			triggerPrescales_(consumes<pat::PackedTriggerPrescales>(iConfig.getParameter<edm::InputTag>("prescales"))),
			pdgId_(iConfig.getParameter<int>("pdgId"))
	{
		produces<std::vector<T> >();
	}

		~MiniAODTriggerMatcher ()
		{

		}

	private:
		edm::EDGetTokenT<edm::TriggerResults> triggerBits_;
		edm::EDGetTokenT<pat::TriggerObjectStandAloneCollection> triggerObjects_;
		edm::EDGetTokenT<pat::PackedTriggerPrescales> triggerPrescales_;

		edm::InputTag src_;
		edm::InputTag triggerEvent_;
		std::vector<std::string> filters_;
		int pdgId_;


		virtual void produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
		{
			using namespace reco;
			using namespace trigger;
			using namespace edm;

			typedef reco::Candidate::LorentzVector LV;
			edm::Handle<edm::TriggerResults> triggerBits;
			edm::Handle<pat::TriggerObjectStandAloneCollection> triggerObjects;
			edm::Handle<pat::PackedTriggerPrescales> triggerPrescales;

			iEvent.getByToken(triggerBits_, triggerBits);
			iEvent.getByToken(triggerObjects_, triggerObjects);
			iEvent.getByToken(triggerPrescales_, triggerPrescales);

			//Read the shallow clones of a candidate and save the SECOND Clone
			std::auto_ptr<std::vector<T> > out(new std::vector<T> );
			edm::Handle<std::vector<T> > src;

			edm::Handle<TriggerEvent> trigEv;
			iEvent.getByLabel(triggerEvent_,trigEv);

			/*  	  for(unsigned int i=0;i<trigEv->sizeFilters();++i)  */
			/*  	    printf("%s\n",trigEv->filterTag(i).label().c_str());   */
			const edm::TriggerNames &names = iEvent.triggerNames(*triggerBits);

		//	std::cout << "\n === TRIGGER OBJECTS === " << std::endl;
		//	for (pat::TriggerObjectStandAlone obj : *triggerObjects) { // note: not "const &" since we want to call unpackPathNames
	//			obj.unpackPathNames(names);
//				for (unsigned h = 0; h < obj.filterLabels().size(); ++h) {
//					std::cout<<"FilterLabel: "<<obj.filterLabels()<<std::endl;
//					std::string FilterLabel = obj.filterLabels();
//					for(unsigned int i=0;i<filters_.size();++i) {
//						if (filters_[i]==FiltersLabel){
//						}
//					}//end input filters_
//				}//end filterlabels
//			}//end for

			if(iEvent.getByLabel(src_,src))
				for(unsigned int k=0;k<src->size();++k) {
					T pat = src->at(k);

					//loop the filters
					for(unsigned int i=0;i<filters_.size();++i) {
						//size_t INDEX =trigEv->filterIndex(filters_[i]);
						//std::vector<LV> trigObjects = getFilterCollection(INDEX,pdgId_,*trigEv);
						std::vector<LV> trigObjects = getFilterCollectionMiniAOD(pdgId_,filters_[i],*triggerObjects);
						bool match = false;

						for(unsigned int j=0;j<trigObjects.size();++j) 
							if(deltaR(trigObjects.at(j),pat)<0.5) {
							        std::cout << "\n === TRIGGER OBJECT DeltaR Calculation === " << std::endl;
								match=true;
								break;
							}

						if(match){
							pat.addUserFloat(filters_[i],1.0);
							std::cout << "\n === TRIGGER OBJECT MATCHED === " << std::endl;
						}
						else{
							pat.addUserFloat(filters_[i],0.0);
							std::cout << "\n === TRIGGER OBJECT UNMATCHED === " << std::endl;
						}
					}


					out->push_back(pat);
				}

			iEvent.put(out);
		}

		virtual void endJob() { }

		//MiniAod 
		std::vector<reco::Candidate::LorentzVector> 
			getFilterCollectionMiniAOD(int id,std::string filter,pat::TriggerObjectStandAloneCollection triggerObjects)
			{
                               //const edm::TriggerNames &names = iEvent.triggerNames(*triggerBits);

				//Create output Collection
				std::vector<reco::Candidate::LorentzVector>  out;
				//get All the final trigger objects
				for (pat::TriggerObjectStandAlone obj : triggerObjects) { // note: not "const &" since we want to call unpackPathNames
					//obj.unpackPathNames(names);
					reco::Candidate::LorentzVector a(obj.px(),obj.py(),obj.pz(),sqrt(obj.px()*obj.px()+obj.py()*obj.py()+obj.pz()*obj.pz()));
					for (unsigned h = 0; h < obj.filterLabels().size(); ++h){

					        //std::cout<<"=====Before Filter====="<<std::endl;
					        //std::cout<<"Filter Label :"<<obj.filterLabels()[h]<<std::endl;
					        //std::cout<<"Given Filter :"<<filter<<std::endl;
						//if (obj.filterIds()[h]==id && obj.filter(filter)){
						if (obj.filter(filter)){
							out.push_back(a);
							std::cout<<"=====After Filter====="<<std::endl;
							std::cout<<"Filter Label :"<<obj.filterLabels()[h]<<std::endl;
							std::cout<<"Given Filter :"<<filter<<std::endl;

						}//end filterlabels
					}//end id
					}

					return out;
				}



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


			};
