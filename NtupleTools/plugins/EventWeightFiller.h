// system include files
#include <memory>

// user include files

#include <TTree.h>

#include "UWAnalysis/NtupleTools/interface/NtupleFillerBase.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h"
#include "HTT-utilities/LepEffInterface/interface/ScaleFactor.h" //HTT Weights

#include "CommonTools/Utils/interface/StringObjectFunction.h"
#include "boost/filesystem.hpp"

//
// class decleration
//

template<typename T>
class EventWeightFiller : public NtupleFillerBase {
	public:
		EventWeightFiller(){
		}


		EventWeightFiller(const edm::ParameterSet& iConfig, TTree* t, edm::ConsumesCollector && iC ):
			src_(iC.consumes<std::vector<T> >(iConfig.getParameter<edm::InputTag>("src"))), 
			tag_(iConfig.getParameter<std::string>("tag")),
			isMu_(iConfig.getParameter<bool>("isMuon"))
	{
		value = new float[3];
		t->Branch("idisoweight_1",&value[0],"idisoweight_1/F");
		t->Branch("trigweight_1",&value[1],"trigweight_1/F");
		t->Branch((tag_+"EffWeight").c_str(),&value[2],(tag_+"EffWeight/F").c_str());
	}


		~EventWeightFiller()
		{ 
		}

		void fill(const edm::Event& iEvent, const edm::EventSetup& iSetup)
		{
			std::string base = std::getenv("CMSSW_BASE");
			std::string fMuonIsolation =   "/src/HTT-utilities/LepEffInterface/data/Muon/Muon_IdIso_eff_Spring16.root";
			std::string fMuonTrigger =   "/src/HTT-utilities/LepEffInterface/data/Muon/Muon_IsoMu20_eff_Spring16.root";
			std::string fEleIsolation =   "/src/HTT-utilities/LepEffInterface/data/Electron/Electron_IdIso_eff_Spring16.root";
			std::string fEleTrigger =   "/src/HTT-utilities/LepEffInterface/data/Electron/Electron_SingleEle23_eff_Spring16.root";
			std::string fileIso;
			std::string fileTrig;
			if (isMu_) {
				fileIso= base+fMuonIsolation;
				fileTrig= base+fMuonTrigger;
			}
			else {
				fileIso= base+fEleIsolation;
				fileTrig= base+fEleTrigger;
			}


			ScaleFactor *myScaleFactorIso = new ScaleFactor();
			ScaleFactor *myScaleFactorTrig = new ScaleFactor();

			myScaleFactorIso->init_ScaleFactor(fileIso);
			myScaleFactorTrig->init_ScaleFactor(fileTrig);

			float pt = 0;
			float eta = 0;

			//function_pt = new StringObjectFunction<T>("leg1.pt");
			//function_eta = new StringObjectFunction<T>("leg1.eta");
			edm::Handle<std::vector<T>> handle;
			if( iEvent.getByToken(src_,handle)){
				pt = handle->at(0).leg1()->pt();
				eta = handle->at(0).leg1()->eta();
			}

			//double efficiency_data = myScaleFactorIso->get_EfficiencyData(pt, eta);
			//double efficiency_MC = myScaleFactorIso->get_EfficiencyMC(pt,eta);
			double scaleFactorIso = myScaleFactorIso->get_ScaleFactor(pt,eta);
			double scaleFactorTrig = myScaleFactorTrig->get_EfficiencyData(pt,eta);

			value[0]=scaleFactorIso;
			value[1]=scaleFactorTrig;
			value[2]=(scaleFactorTrig*scaleFactorIso);
		}


	protected:
		edm::EDGetTokenT<std::vector<T> > src_;
		std::string tag_;
		bool isMu_;
		float* value;

};




#include "UWAnalysis/DataFormats/interface/CompositePtrCandidateT1T2MEt.h"
#include "UWAnalysis/DataFormats/interface/CompositePtrCandidateTMEt.h"

typedef EventWeightFiller<PATMuTauPair> PATMuTauPairWeightFiller;
typedef EventWeightFiller<PATElecTauPair> PATEleTauPairWeightFiller;



