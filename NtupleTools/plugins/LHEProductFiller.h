// system include files
#include <memory>

// user include files
#include <TTree.h>
#include "SimDataFormats/GeneratorProducts/interface/LHEEventProduct.h"

#include "UWAnalysis/NtupleTools/interface/NtupleFillerBase.h"

//
// class decleration
//

class LHEProductFiller : public NtupleFillerBase {
	public:
		LHEProductFiller(){
		}


		LHEProductFiller(const edm::ParameterSet& iConfig, TTree* t,edm::ConsumesCollector && iC):
			src_(iC.consumes<LHEEventProduct>(iConfig.getParameter<edm::InputTag> ("src"))),
			tag_(iConfig.getParameter<std::string>("tag"))
	{
		value1 = 0;
//		value2 = 0;
		t->Branch((tag_+"njet").c_str(),&value1,(tag_+"njet/I").c_str());
//		t->Branch((tag_+"_mll").c_str(),&value2,(tag_+"_mll/I").c_str());
	}


		~LHEProductFiller()
		{

		}


		void fill(const edm::Event& iEvent, const edm::EventSetup& iSetup)
		{
			edm::Handle<LHEEventProduct> lheeventinfo;
			value1=0;
			int NParton=0;
			//TLorentzVector l;
			if(iEvent.getByToken(src_,lheeventinfo)) {
				int nup = lheeventinfo->hepeup().NUP;
				for (int i = 0; i < nup ; ++i) {
					if (lheeventinfo->hepeup().ISTUP[i] == 1 && (abs(lheeventinfo->hepeup().IDUP[i])<6||lheeventinfo->hepeup().IDUP[i]==21 )) {
						++NParton;	
					}
					// if (lheeventinfo->hepeup().ISTUP[i] == 1 && (abs(lheeventinfo->hepeup().IDUP[i])==11||lheeventinfo->hepeup().IDUP[i]==13||lheeventinfo->hepeup().IDUP[i]==13 )) {
					//TLorentzVector mom = lheeventinfo->hepeup().PUP[i];
					//l += TLorentzVector(mom.x[0], mom.x[1], mom.x[2], mom.x[3]);	   
					//    }

				}
			}


			value1 = NParton;
		}


	protected:
		edm::EDGetTokenT<LHEEventProduct> src_;
		std::string tag_;
		int value1;
		//int value2;


};







