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
    value = 0;
    t->Branch(tag_.c_str(),&value,(tag_+"/I").c_str());
  }


    ~LHEProductFiller()
    {

    }


    void fill(const edm::Event& iEvent, const edm::EventSetup& iSetup)
    {
      edm::Handle<LHEEventProduct> handle;
      value=0;
      if(iEvent.getByToken(src_,handle)) {
        value = handle->hepeup().NUP;
      }
    }


  protected:
    edm::EDGetTokenT<LHEEventProduct> src_;
    std::string tag_;
    int value;


};







