#include "UWAnalysis/RecoTools/plugins/GenEventSum.h"

GenEventSum::GenEventSum(const edm::ParameterSet& iConfig):
  name_(iConfig.getParameter<std::string>("name"))
{
     DQMStore* store = &*edm::Service<DQMStore>();
     evCount = store->bookFloat(name_.c_str());
   //  if(evCount)
    //   {
//	 evCount->Fill(0);
 //      }

}


GenEventSum::~GenEventSum()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called to produce the data  ------------
void
GenEventSum::produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;
   evCount->Fill(evCount->getFloatValue()+1.0);
}

#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/PluginManager/interface/ModuleDef.h"
DEFINE_FWK_MODULE(GenEventSum);
