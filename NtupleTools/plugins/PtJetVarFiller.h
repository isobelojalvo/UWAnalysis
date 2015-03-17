// system include files
#include <memory>

// user include files
#include "CommonTools/Utils/interface/StringObjectFunction.h"
#include "DataFormats/PatCandidates/interface/LookupTableRecord.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "Math/GenVector/VectorUtil.h" 
#include "TMath.h"

#include <TTree.h>

#include "UWAnalysis/NtupleTools/interface/NtupleFillerBase.h"

//
// class decleration
//
template<typename T>
class PtJetVarFiller : public NtupleFillerBase {
 public:
    PtJetVarFiller(){
    }


    PtJetVarFiller(const edm::ParameterSet& iConfig, TTree* t):
      NtupleFillerBase(iConfig,t),
      src_(iConfig.getParameter<edm::InputTag>("src")),
      var_(iConfig.getParameter<std::string>("method")),
      tag_(iConfig.getParameter<std::string>("tag")),
      rank_(iConfig.getUntrackedParameter<double>("rank",1.))
      // matchDR_(iConfig.getUntrackedParameter<double>("MatchDR",0.15))
	{

	  singleValue=0.;
	  function = new StringObjectFunction<pat::Jet>(var_);
	  vbranch = t->Branch(tag_.c_str(),&singleValue,(tag_+"/F").c_str());
	  //bool rank_;
	}


  ~PtJetVarFiller()
    { 
      if(function!=0) delete function;
    }
       

  void fill(const edm::Event& iEvent, const edm::EventSetup& iSetup)
  {
    edm::Handle<std::vector<T> > handle;

    //edm::Handle<std::vector<T> > handleT;
    singleValue=-1;
    /*
    float minPt=0.0;
    float secondPt=0.0;
    float thirdPt = 0.0;
    float firsteta = 0.0;
    float firstphi = 0.0;
    float secondeta = 0.0;
    float secondphi = 0.0;
    */ 
     //printf("first\n");
    if(iEvent.getByLabel(src_,handle)) {
      //if(rank__== "first"){
      singleValue = 0;
      if(handle->size()>0){
	if(handle->at(0).jets().size()>rank_){
	  //printf("nJets: %i\n",(int)handle->at(0).jets().size());
	  //printf("%i th pt: %f\n",(int)rank_,handle->at(0).jets().at((int)rank_)->pt());
	  singleValue = (*function)(*(handle->at(0).jets().at((int) rank_)));
	}
      }
    }
  }

 protected:
  edm::InputTag src_;
  std::string var_;
  std::string tag_;
  float rank_;
  float singleValue;
  StringObjectFunction<pat::Jet>*function;
  TBranch *vbranch;

};


#include "UWAnalysis/DataFormats/interface/CompositePtrCandidateT1T2MEt.h"
#include "UWAnalysis/DataFormats/interface/CompositePtrCandidateTMEt.h"
typedef PtJetVarFiller<PATMuonNuPair> PATMuonNuPairPtJetVarFiller;
typedef PtJetVarFiller<PATMuTauPair> PATMuTauPairPtJetVarFiller;
typedef PtJetVarFiller<PATElecTauPair> PATEleTauPairPtJetVarFiller;
//typedef PtJetVarFiller<PATMuJetPair> PATMuJetPairPtJetVarFiller;
//typedef PtJetVarFiller<PATMuPair> PATMuPairPtJetVarFiller;
//typedef PtJetVarFiller<PATElecMuPair> PATEleMuPairPtJetVarFiller;
//typedef PtJetVarFiller<PATElecMuPair> PATDiTauPairPtJetVarFiller;





