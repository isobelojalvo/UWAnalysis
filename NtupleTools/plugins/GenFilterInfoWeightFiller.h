// system include files
#include <memory>

// user include files
#include <TTree.h>
#include "SimDataFormats/GeneratorProducts/interface/GenFilterInfo.h"

#include "UWAnalysis/NtupleTools/interface/NtupleFillerBase.h"

//
// class decleration
//

class GenFilterInfoWeightFiller : public NtupleFillerBase {
  public:
    GenFilterInfoWeightFiller(){
    }


    GenFilterInfoWeightFiller(const edm::ParameterSet& iConfig, TTree* t):
      src_(iConfig.getParameter<edm::InputTag>("src")),
      tag_(iConfig.getParameter<std::string>("tag"))
  {
    value = 0;
    t->Branch(tag_.c_str(),&value,(tag_+"/F").c_str());
  }


    ~GenFilterInfoWeightFiller()
    {

    }


    void fill(const edm::Event& iEvent, const edm::EventSetup& iSetup)
    {
      edm::Handle<GenFilterInfo> handle;
      value=0;
      if(iEvent.getByLabel(src_,handle)) {
        value = handle->filterEfficiency();
      }
    }


  protected:
    edm::InputTag src_;
    std::string tag_;
    float value;


};







