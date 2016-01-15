// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/EDProducer.h"

#include "DataFormats/Math/interface/Error.h"
#include <TTree.h>
#include <math.h>
#include "UWAnalysis/NtupleTools/interface/NtupleFillerBase.h"

//
// class decleration
//



class METSignificanceFiller : public NtupleFillerBase {
 public:
    METSignificanceFiller(){
    }


    METSignificanceFiller(const edm::ParameterSet& iConfig, TTree* t):
      src_(iConfig.getParameter<edm::InputTag>("src")),
      tag_(iConfig.getParameter<std::string>("tag"))
	{
	  value = new float[5];
	  t->Branch((tag_+"Sig").c_str(),&value[0],(tag_+"Sig/F").c_str());
	  t->Branch((tag_+"00").c_str(),&value[1],(tag_+"00/F").c_str());
	  t->Branch((tag_+"01").c_str(),&value[2],(tag_+"01/F").c_str());
	  t->Branch((tag_+"10").c_str(),&value[3],(tag_+"10/F").c_str());
	  t->Branch((tag_+"11").c_str(),&value[4],(tag_+"11/F").c_str());
	}


  ~METSignificanceFiller()
    { 

    }
       

  void fill(const edm::Event& iEvent, const edm::EventSetup& iSetup)
  {
    edm::Handle<double> significanceHandle;
    edm::Handle<math::Error<2>::type> covHandle;


    if(iEvent.getByLabel("METSignificance","METSignificance", significanceHandle)) {
	  value[0] = (float) (*significanceHandle); 
	}
    else
      {
          value[0] = -999;	
      }

    if (iEvent.getByLabel("METSignificance","METCovariance",covHandle)) {
     value[1] = (*covHandle)(0,0);
     value[3] = (*covHandle)(1,0);
     value[2] = value[3]; // (1,0) is the only one saved
     value[4] = (*covHandle)(1,1);
    }
     else
   { for (int i=1;i<5;i++) value[i] = -999;}

  }

 protected:
  edm::InputTag src_;
  std::string tag_;
  float* value;

};






