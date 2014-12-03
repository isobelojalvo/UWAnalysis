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

//Adding in Kin Fitter Kludge

#include "UWAnalysis/HHKinFit/include/HHKinFitMaster.h"
//#include "UWAnalysis/HHKinFit/src/HHKinFitMaster.cpp"
//#include "UWAnalysis/HHKinFit/interface/HHEventRecord.h"
//#include "UWAnalysis/HHKinFit/interface/HHKinFit.h"
//#include "UWAnalysis/HHKinFit/interface/HHParticleList.h"
//#include "UWAnalysis/HHKinFit/interface/HHPID.h"
//#include "UWAnalysis/HHKinFit/interface/HHV4Vector.h"


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
				/* SV Fitter */
				CompositePtrCandidateT1T2MEt<T1,T2> compositePtrCandidate = cands->at(i);
				reco::Candidate::LorentzVector theMETP4_ = compositePtrCandidate.calibratedMET();
				TMatrixD covMatrix_ = compositePtrCandidate.covMatrix();

				std::vector<NSVfitStandalone::MeasuredTauLepton> measuredTauLeptons;
				measuredTauLeptons.push_back(NSVfitStandalone::MeasuredTauLepton(NSVfitStandalone::kLepDecay, compositePtrCandidate.leg1()->p4()));
				measuredTauLeptons.push_back(NSVfitStandalone::MeasuredTauLepton(NSVfitStandalone::kHadDecay, compositePtrCandidate.leg2()->p4()));
				NSVfitStandaloneAlgorithm algo(measuredTauLeptons, theMETP4_.Vect(), covMatrix_, 0);
				algo.addLogM(false);
				algo.integrateMarkovChain();
				//algo.integrateVEGAS();
				double mass = algo.getMass();
				//double massErr = algo.massUncert(); 
				double pt = algo.pt(); 
				double eta = algo.eta(); 
				double phi = algo.phi(); 
				//double energy = algo.E(); 
				//double ptErr = algo.ptUncert();

				compositePtrCandidate.setSVMass(mass);
				compositePtrCandidate.setSVPt(pt);
				compositePtrCandidate.setSVEta(eta);
				compositePtrCandidate.setSVPhi(phi);
				//compositePtrCandidate.setSVEnergy(energy);
				/* END SV Fitter */

				/* Kinematic Fitter 
					Requirements: Two Jets with b-Tag > 0, PT>20
				 */


				TLorentzVector b1;      
				TLorentzVector b2;
				TLorentzVector tau1vis;
				TLorentzVector tau2vis;

				if(compositePtrCandidate.CSVSize()>1 && compositePtrCandidate.CSVSize()<100 ){
					//define the test hypotheses
				//if(compositePtrCandidate.J1CSVSortP4().pt()>20&&compositePtrCandidate.J2CSVSortP4().pt()>20){
				  //std::cout<<"CSVSize: "<<compositePtrCandidate.CSVSize()<<std::endl;
					std::vector<Int_t> hypo_mh1;
					hypo_mh1.push_back(125);
					std::vector<Int_t> hypo_mh2;
					hypo_mh2.push_back(125);
					//std::cout<<"Set TLorentz vector b1"<<std::endl;
					//std::cout<<"compositePtrCandidate J1CSVSortP4().energy(): "<<compositePtrCandidate.J1CSVSortP4().energy()<<std::endl;
					b1.SetPxPyPzE(compositePtrCandidate.J1CSVSortP4().px(),
							compositePtrCandidate.J1CSVSortP4().py(),
							compositePtrCandidate.J1CSVSortP4().pz(),
							compositePtrCandidate.J1CSVSortP4().energy()
						     ); //TLorentzVector(b1_px,b1_py,b1_pz,b1_E);

					//std::cout<<"TLorentz vector b1 Pt: "<<b1.Pt()<<std::endl;

					//std::cout<<"Set TLorentz vector b2"<<std::endl;
					b2.SetPxPyPzE(compositePtrCandidate.J2CSVSortP4().px(),	  
							compositePtrCandidate.J2CSVSortP4().py(),	  
							compositePtrCandidate.J2CSVSortP4().pz(),	  
							compositePtrCandidate.J2CSVSortP4().energy()
						     ); //TLorentzVector(b2_px,b2_py,b2_pz,b2_E);

					//std::cout<<"TLorentz vector b2 Pt: "<<b2.Pt()<<std::endl;

					//	std::cout<<"Set TLorentz vector tau1vis"<<std::endl;
					tau1vis.SetPxPyPzE(compositePtrCandidate.leg1()->px(),
							compositePtrCandidate.leg1()->py(),
							compositePtrCandidate.leg1()->pz(),
							compositePtrCandidate.leg1()->energy()
							);

					//std::cout<<"TLorentz vector tau1vis Pt: "<<tau1vis.Pt()<<std::endl;
					//std::cout<<"Set TLorentz vector tau2vis"<<std::endl;

					tau2vis.SetPxPyPzE(compositePtrCandidate.leg2()->px(),
							compositePtrCandidate.leg2()->py(),
							compositePtrCandidate.leg2()->pz(),
							compositePtrCandidate.leg2()->energy()
							);
					//std::cout<<"TLorentz vector tau2vis Pt: "<<tau2vis.Pt()<<std::endl;

					TLorentzVector ptmiss;
					ptmiss.SetPxPyPzE(compositePtrCandidate.met()->px(),
							  compositePtrCandidate.met()->py(),
							  compositePtrCandidate.met()->pz(),
							  compositePtrCandidate.met()->energy()
							  );

					//std::cout<<"TLorentz vector ptMiss: "<<ptmiss.Pt() <<std::endl;

					TMatrixD metcov= compositePtrCandidate.covMatrix();
					HHKinFitMaster kinFits = HHKinFitMaster(&b1,&b2,&tau1vis,&tau2vis,false,NULL);

					kinFits.setAdvancedBalance(&ptmiss,metcov);
					//kinFits.setSimpleBalance(ptmiss.Pt(),10); //alternative which uses only the absolute value of ptmiss in the fit
					kinFits.addMh1Hypothesis(hypo_mh1);
					kinFits.addMh2Hypothesis(hypo_mh2);
					kinFits.doFullFit();

					//std::cout<<"Do KinFit hypotheses"<<std::endl;
					//obtain results from different hypotheses
					Double_t chi2_best = kinFits.getBestChi2FullFit();
					Double_t mh_best   = kinFits.getBestMHFullFit();

					std::pair<Int_t, Int_t> bestHypo = kinFits.getBestHypoFullFit();
					std::map< std::pair<Int_t, Int_t>, Double_t> fit_results_chi2 = kinFits.getChi2FullFit();
					std::map< std::pair<Int_t, Int_t>, Double_t> fit_results_fitprob = kinFits.getFitProbFullFit();
					std::map< std::pair<Int_t, Int_t>, Double_t> fit_results_mH = kinFits.getMHFullFit();
					std::map< std::pair<Int_t, Int_t>, Double_t> fit_results_pull_b1 = kinFits.getPullB1FullFit();
					std::map< std::pair<Int_t, Int_t>, Double_t> fit_results_pull_b2 = kinFits.getPullB2FullFit();
					std::map< std::pair<Int_t, Int_t>, Double_t> fit_results_pull_balance = kinFits.getPullBalanceFullFit();
					std::map< std::pair<Int_t, Int_t>, Int_t> fit_convergence = kinFits.getConvergenceFullFit();

					/*
					std::cout << "#############################" << std::endl;
					std::cout << "EVENT" << i << std::endl;
					std::cout << "#############################" << std::endl;
					std::cout << "=====================================" << std::endl;
					//std::cout << "njets:           " << njets << std::endl;
					//std::cout << "event:           " << i << std::endl;
					std::cout << "best chi2:       " << chi2_best << std::endl;
					std::cout << "best hypothesis: " << bestHypo.first << " " << bestHypo.second << std::endl;
					std::cout << "best mH=         " << mh_best << std::endl;
					std::cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
					*/
					std::pair< Int_t, Int_t >hypo = std::make_pair(*hypo_mh1.begin(),*hypo_mh2.begin());

					//check if fit failed, if so, then change mh_best and set chi2 best to -1
					if(mh_best < 20){

					  mh_best = (ptmiss+b1+b2+tau1vis+tau2vis).M();

					  std::cout<< "Convergence failed. mh_best: " << mh_best<<std::endl;
					  chi2_best = -12;
					}
					//chi2
					compositePtrCandidate.setKinHchi2(chi2_best);
					//best mH
					compositePtrCandidate.setKinHMass(mh_best);
					//best hypothesis
					compositePtrCandidate.setKinHypo1(bestHypo.first);
					compositePtrCandidate.setKinHypo2(bestHypo.second);
					//fit probability
					compositePtrCandidate.setKinProb(fit_results_fitprob.at(hypo));
					//pull b1
					compositePtrCandidate.setKinB1(fit_results_pull_b1.at(hypo));
					//pull b2
					compositePtrCandidate.setKinB2(fit_results_pull_b2.at(hypo));
					//pull balance
					compositePtrCandidate.setKinBalance(fit_results_pull_balance.at(hypo));
				}//end if

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
