#include "UWAnalysis/RecoTools/plugins/ESTauProducer.h"

/*
Decay mode Tau Momentum scaling vs Tau pT
1-prong no-pi0 no correction
1-prong 1-pi0 p4' = p4 * (1.015 + 0.001 * TMath::Min(TMath::Max(pT-45.,0.),10.)
3-prong p4' = p4 * (1.012 + 0.001 * TMath::Min(TMath::Max(pT-32.,0.),18.) 
	  */

ESTauProducer::ESTauProducer(const edm::ParameterSet& iConfig):
    src_(iConfig.getParameter<edm::InputTag>("src")),  
    smearConstituents_(iConfig.getParameter<bool>("smearConstituents")),
    genParticles_(iConfig.getParameter<edm::InputTag>("genParticles"))
    {
      smearingModule = new SmearedParticleMaker<pat::Tau,GenJetRetriever<pat::Tau> >(iConfig);
      produces<std::vector<pat::Tau> >();
    }


ESTauProducer::~ESTauProducer()
{}

void 
ESTauProducer::produce(edm::Event& iEvent, const edm::EventSetup& iSetup) {
  std::cout<<"Here 1"<<std::endl;
  //std::cout << "<ESTauProducer::produce>:" << std::endl;
    //std::cout << "(label = " << moduleLabel_ << ")" << std::endl;

    using namespace edm;
    using namespace reco;

    std::auto_ptr<std::vector<pat::Tau> > out(new std::vector<pat::Tau> );
    edm::Handle<pat::TauCollection > srcH;

    edm::Handle<reco::GenParticleCollection> genParticleCollection;

    bool tauPresent = false;    
    bool genParticlesPresent = false;     
      
    if(iEvent.getByLabel(genParticles_,genParticleCollection)){
      ////first check if there is a tau somewhere in the collection
      genParticlesPresent=true;
      for(unsigned int j=0; j < genParticleCollection->size();j++){
	if(abs(genParticleCollection->at(j).pdgId())==15){
	  tauPresent=true;
	  break;
	}
      }
    }

    if(iEvent.getByLabel(src_,srcH)) 
    unsigned int i = 0 ;
    for(unsigned int i=0;i<srcH->size();++i) {
      
      pat::Tau object = srcH->at(i);
      //std::std::cout << " original object(" << i << "): Pt = " << object.pt(); 
      //	    << " eta = " << object.eta() << ", phi = " << object.phi() << std::endl;
	
      smearingModule->smear(object);
      float initialpt = object.pt();
      float initialpx = object.px();
      float initialpy = object.py();
      float initialpz = object.pz();
      float initialeta = object.eta();
      float initialphi = object.phi();
      float initialMass = object.mass();
      object.addUserFloat("preESMass",initialMass);
      object.addUserFloat("preESpt",initialpt);
      object.addUserFloat("preESpx",initialpx);
      object.addUserFloat("preESpy",initialpy);
      object.addUserFloat("preESpz",initialpz);
      object.addUserFloat("preESeta",initialeta);
      object.addUserFloat("preESphi",initialphi);
      
      
      math::XYZTLorentzVector finalP4 = object.p4();
      if(genParticlesPresent) {
	
	if(object.decayMode()==1||object.decayMode()==2||object.decayMode()==10){
	  if(object.decayMode()==1||object.decayMode()==2){
	    finalP4 = (object.p4())* (1.012);
	  }
	  else if(object.decayMode()==10){
	    finalP4 = (object.p4())* (1.012);
	    
	  }
	  
	  object.addUserFloat("ESmass",finalP4.mass());
	  }
	
	if(smearConstituents_&&tauPresent) {
	  object.setP4(finalP4);
	}
      }
      
      //std::cout << "smeared object(" << i << ") : decay mode = " << object.decayMode() <<" : Pt = " << object.pt() << std::endl ;  
      //<< " eta = " << object.eta() << ", phi = " << object.phi() << std::endl;
	
      
      out->push_back(object);
      i++;
    }
    iEvent.put(out);
}




#include "FWCore/Framework/interface/MakerMacros.h"
DEFINE_FWK_MODULE(ESTauProducer);
