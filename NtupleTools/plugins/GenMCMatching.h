// system include files
#include <memory>

// user include files

#include <TTree.h>

#include "UWAnalysis/NtupleTools/interface/NtupleFillerBase.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "HTT-utilities/LepEffInterface/interface/ScaleFactor.h" //HTT Weights

#include "CommonTools/Utils/interface/StringObjectFunction.h"
#include "boost/filesystem.hpp"

//
// class decleration
//

template<typename T>
class GenMCMatching : public NtupleFillerBase {
	public:
		GenMCMatching(){
		}


		GenMCMatching(const edm::ParameterSet& iConfig, TTree* t, edm::ConsumesCollector && iC ):
			src_(iC.consumes<std::vector<T> >(iConfig.getParameter<edm::InputTag>("src"))) 
	{
		value = new float[3];
		t->Branch("gen_match_1",&value[0],"gen_match_1/F");
		t->Branch("gen_match_2",&value[1],"gen_match_2/F");
	}


		~GenMCMatching()
		{ 
		}

		void fill(const edm::Event& iEvent, const edm::EventSetup& iSetup)
		{
 			float genMatch1=0;
			float genMatch2=0;

			edm::Handle<std::vector<T>> handle;
			if( iEvent.getByToken(src_,handle)){
                                //std::cout<<"pdg1: "<<abs(handle->at(0).genPdg1())<<std::endl;
                                //std::cout<<"isPrompt1: "<<handle->at(0).isPrompt1()<<std::endl;
                                //std::cout<<"isTauDecay: "<<handle->at(0).isDirectPromptTauDecayProduct1()<<std::endl;
                                //std::cout<<"1 P4: "<<handle->at(0).p4Leg1gen().pt()<<std::endl;

                                //std::cout<<"pdg2: "<<abs(handle->at(0).genPdg2())<<std::endl;
                                //std::cout<<"isPrompt2: "<<handle->at(0).isPrompt2()<<std::endl;
                                //std::cout<<"2 P4: "<<handle->at(0).p4Leg2gen().pt()<<std::endl;
                                //std::cout<<"2 P4Vis: "<<handle->at(0).p4VisLeg2gen().pt()<<std::endl;

				if (abs(handle->at(0).genPdg1())==11&&handle->at(0).isPrompt1()&&handle->at(0).p4Leg1gen().pt()>8){genMatch1=1;}
				else if (abs(handle->at(0).genPdg1())==13&&handle->at(0).isPrompt1()&&handle->at(0).p4Leg1gen().pt()>8){genMatch1=2;}
				else if (abs(handle->at(0).genPdg1())==11&&handle->at(0).isDirectPromptTauDecayProduct1()&&handle->at(0).p4Leg1gen().pt()>8){genMatch1=3;}
				else if (abs(handle->at(0).genPdg1())==13&&handle->at(0).isDirectPromptTauDecayProduct1()&&handle->at(0).p4Leg1gen().pt()>8){genMatch1=4;}
				else if (handle->at(0).isPrompt1()&&handle->at(0).p4VisLeg1gen().pt()>15){genMatch1=5;}
				//else if (abs(handle->at(0).genPdg1())==15&&handle->at(0).p4VisLeg1gen().pt()>15){genMatch1=5;}
				else {genMatch1=6;}


				if (abs(handle->at(0).genPdg2())==11&&handle->at(0).isPrompt2()&&handle->at(0).p4Leg2gen().pt()>8){genMatch2=1;}
				else if (abs(handle->at(0).genPdg2())==13&&handle->at(0).isPrompt2()&&handle->at(0).p4Leg2gen().pt()>8){genMatch2=2;}
				else if (abs(handle->at(0).genPdg2())==11&&handle->at(0).isDirectPromptTauDecayProduct2()&&handle->at(0).p4Leg2gen().pt()>8){genMatch2=3;}
				else if (abs(handle->at(0).genPdg2())==13&&handle->at(0).isDirectPromptTauDecayProduct2()&&handle->at(0).p4Leg2gen().pt()>8){genMatch2=4;}
				else if (handle->at(0).isPrompt2()&&handle->at(0).p4VisLeg2gen().pt()>15){genMatch2=5;}
				//else if (abs(handle->at(0).genPdg2())==15&&handle->at(0).p4VisLeg1gen().pt>15){genMatch2=5;}//FIXME to GenVis
				else {genMatch2=6;}

				//std::cout<<" gen_match_1: "<<genMatch1<<std::endl;
				//std::cout<<" gen_match_2: "<<genMatch2<<std::endl;

			}
			value[0]=genMatch1;
			value[1]=genMatch2;



		}




protected:
edm::EDGetTokenT<std::vector<T> > src_;
float* value;

};


#include "UWAnalysis/DataFormats/interface/CompositePtrCandidateT1T2MEt.h"
#include "UWAnalysis/DataFormats/interface/CompositePtrCandidateTMEt.h"

typedef GenMCMatching<PATMuTauPair> PATMuTauPairGenMCMatching;
typedef GenMCMatching<PATElecTauPair> PATEleTauPairGenMCMatching;



