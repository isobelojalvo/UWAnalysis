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
#include "CondTools/BTau/interface/BTagCalibrationReader.h"


class MiniAODCSVReweighting : public edm::EDProducer {
	public:
		MiniAODCSVReweighting(const edm::ParameterSet& pset);
		virtual ~MiniAODCSVReweighting(){}
		void produce(edm::Event& evt, const edm::EventSetup& es);
	private:
		edm::EDGetTokenT<pat::JetCollection> src_;

		BTagCalibration calib;
		BTagCalibrationReader reader;

};

MiniAODCSVReweighting::MiniAODCSVReweighting(const edm::ParameterSet& pset) {
	src_ = consumes<pat::JetCollection>(pset.getParameter<edm::InputTag>("src"));
	produces<pat::JetCollection>();
	calib=BTagCalibration("CSVv2", std::string(std::getenv("CMSSW_BASE"))+"/src/UWAnalysis/Configuration/data/CSVv2_4invfb_systJuly15.csv");
	reader=BTagCalibrationReader(BTagEntry::OP_RESHAPING, "central",{"up_jes","down_jes","up_hfstats1","down_hfstats1","up_hfstats2","down_hfstats2","up_hf","down_hf","up_lfstats1","down_lfstats1","up_lfstats2","down_lfstats2","up_cferr1","down_cferr1","up_cferr2","down_cferr2"});
	reader.load(calib, BTagEntry::FLAV_B, "iterativefit");
	reader.load(calib, BTagEntry::FLAV_C, "iterativefit");
	reader.load(calib, BTagEntry::FLAV_UDSG, "iterativefit");

}

void MiniAODCSVReweighting::produce(edm::Event& evt, const edm::EventSetup& es) {
	std::auto_ptr<pat::JetCollection> output(new pat::JetCollection);

	edm::Handle<pat::JetCollection> input;
	evt.getByToken(src_, input);

	output->reserve(input->size());
	for (size_t i = 0; i < input->size(); ++i) {
		pat::Jet jet = input->at(i);
		double pt = jet.pt();
		double eta = jet.eta();
		double csv = jet.bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags");
		int jetflavor =jet.partonFlavour();
		double SF =0,CSVnew=0;
		if (fabs(jetflavor) == 5) {                // real b-jet
			SF = reader.eval_auto_bounds("central",BTagEntry::FLAV_B, eta, pt,csv );
		}
		else if (fabs(jetflavor) == 4) { 
			//cout<< "Flavor 4" <<endl;
			SF = reader.eval_auto_bounds("central",BTagEntry::FLAV_C, eta, pt,csv );
		}  
		else {
			//cout<< "Flavor UDSG" <<endl;
			SF = reader.eval_auto_bounds("central",BTagEntry::FLAV_UDSG, eta, pt ,csv );
		}
		CSVnew=SF;
		/*std::cout<<"=======Jet CSV Reshaper========"<<std::endl;
		  std::cout<<"Jet Flavor: "<<fabs(jetflavor) <<std::endl;
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
