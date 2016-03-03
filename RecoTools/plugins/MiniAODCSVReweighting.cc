/*
 * Embed PF Jet IDs (see https://twiki.cern.ch/twiki/bin/view/CMS/JetID)
 * into pat::Jets
 *
 * Author: Evan K. Friis, UW Madison
 */


#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/EDProducer.h"

#include "DataFormats/PatCandidates/interface/Jet.h"

#include "CondFormats/BTauObjects/interface/BTagCalibration.h"
#include "CondFormats/BTauObjects/interface/BTagCalibrationReader.h"

#include "UWAnalysis/RecoTools/plugins/BTagCalibrationStandalone.h"


class MiniAODCSVReweighting : public edm::EDProducer {
	public:
		MiniAODCSVReweighting(const edm::ParameterSet& pset);
		virtual ~MiniAODCSVReweighting(){}
		void produce(edm::Event& evt, const edm::EventSetup& es);
	private:
		edm::EDGetTokenT<pat::JetCollection> src_;

		BTagCalibration *calib;
		BTagCalibrationReader *reader;

};

MiniAODCSVReweighting::MiniAODCSVReweighting(const edm::ParameterSet& pset) {
	src_ = consumes<pat::JetCollection>(pset.getParameter<edm::InputTag>("src"));
	produces<pat::JetCollection>();
	calib=new BTagCalibration("CSVv2", std::string(std::getenv("CMSSW_BASE"))+"/src/UWAnalysis/Configuration/data/CSVv2_76.csv");
	reader=new BTagCalibrationReader(calib, BTagEntry::OP_RESHAPING, "iterativefit", "central");


}

void MiniAODCSVReweighting::produce(edm::Event& evt, const edm::EventSetup& es) {
	std::auto_ptr<pat::JetCollection> output(new pat::JetCollection);

	edm::Handle<pat::JetCollection> input;
	evt.getByToken(src_, input);

	output->reserve(input->size());
	for (size_t i = 0; i < input->size(); ++i) {
		pat::Jet jet = input->at(i);
		double pt = jet.pt();
		if (pt<20) {continue;}
		double eta = jet.eta();
		double csv = jet.bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags");
		int jetflavor =jet.partonFlavour();
		double SF =0,CSVnew=0;
		if (fabs(jetflavor) == 5) {                // real b-jet
			SF = reader->eval(BTagEntry::FLAV_B, eta, pt,csv );
		}
		else if (fabs(jetflavor) == 4) { 
			//cout<< "Flavor 4" <<endl;
			SF = reader->eval(BTagEntry::FLAV_C, eta, pt,csv );
		}  
		else {
			//cout<< "Flavor UDSG" <<endl;
			SF = reader->eval(BTagEntry::FLAV_UDSG, eta, pt ,csv );
		}
		CSVnew=SF*csv;
		/*std::cout<<"Jet CSV Reshaper"<<std::endl;
		std::cout<<"Jet Pt: "<<pt<<std::endl;
		std::cout<<"Jet Eta: "<<eta<<std::endl;
		std::cout<<"Jet CSV: "<<csv<<std::endl;
		std::cout<<"Jet Reader output: "<<SF<<std::endl;
		std::cout<<"Jet NEW CSV: "<<CSVnew<<std::endl;
		*/
	        if (CSVnew>1) {std::cout<<"NEW CSV greater than 1"<<std::endl;}	

		jet.addUserFloat("CSVv2_SF", SF);
		output->push_back(jet);
	}

	evt.put(output);
}

#include "FWCore/Framework/interface/MakerMacros.h"
DEFINE_FWK_MODULE(MiniAODCSVReweighting);
