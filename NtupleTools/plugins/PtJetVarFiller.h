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

	/*
	for(unsigned int i=0;i<handle->at(0).jets().size();++i){
	  printf("%i th pt: %f\n",i,handle->at(0).jets().at(i)->pt());
	}

	for(unsigned int i=0;i<handle->at(0).jets().size();++i){
	  if(handle->at(0).jets().at(i)->userInt("fullIdLoose")<1){printf("FailsJetID!!!\n");}
	  if((ROOT::Math::VectorUtil::DeltaR(handle->at(0).lepton()->p4(),handle->at(0).jets().at(i)->p4()))<0.5){printf("JetFailsMuon Cross Cleaning!!! DeltaR:%f Pt:%f\n",(ROOT::Math::VectorUtil::DeltaR(handle->at(0).lepton()->p4(),handle->at(0).jets().at(i)->p4())),handle->at(0).jets().at(i)->pt());}

	  if(handle->at(0).jets().at(i)->pt()>minPt){ //add muon jet cross cleaning!!
	    minPt = handle->at(0).jets().at(i)->pt();
	    singleValue = (*function)(*(handle->at(0).jets().at(i)));
	    firsteta = handle->at(0).jets().at(i)->eta();
	    firstphi = handle->at(0).jets().at(i)->phi();
	  }
	}
      }
	//printf("first jet pt: %f \n",minPt);
	//}

      if(rank_== 2||rank_ == 3){
	//printf("checking second jet \n");
	singleValue = 0;
	if(handle->at(0).jets().size()>1){
	  for(unsigned int i=0;i<handle->at(0).jets().size();++i){
	    if(minPt>handle->at(0).jets().at(i)->pt()&&handle->at(0).jets().at(i)->pt()>secondPt&&handle->at(0).jets().at(i)->userInt("fullIdLoose")>0&&(ROOT::Math::VectorUtil::DeltaR(handle->at(0).lepton()->p4(),handle->at(0).jets().at(i)->p4())>0.5)) {//cross clean jets!!
	      secondPt = handle->at(0).jets().at(i)->pt();
	      //printf("second jet pt: %f \n",handle->at(0).jets().at(i)->pt());
	      singleValue = (*function)(*(handle->at(0).jets().at(i)));
	      secondeta = handle->at(0).jets().at(i)->eta();
	      secondphi = handle->at(0).jets().at(i)->phi();
	    }
	  }
	}

	//printf("second jet pt: %f \n",secondPt);
      }

      if(rank_ == 3){
	singleValue = 0;//(*function)(*(handle->at(0).jets().at(i)));
	if(handle->at(0).jets().size()>2){
	  for(unsigned int i=0;i<handle->at(0).jets().size();++i){
	    if(secondPt>handle->at(0).jets().at(i)->pt()&&handle->at(0).jets().at(i)->pt()>thirdPt&&handle->at(0).jets().at(i)->userInt("fullIdLoose")>0&&(ROOT::Math::VectorUtil::DeltaR(handle->at(0).lepton()->p4(),handle->at(0).jets().at(i)->p4())>0.5)) {
	      thirdPt = handle->at(0).jets().at(i)->pt();
	      singleValue = (*function)(*(handle->at(0).jets().at(i)));
	    }
	  }
	}
	//printf("third jet pt: %f \n",thirdPt);
      }
    }
    else
      {
	printf("Obj not found \n");
      }
    //    vbranch->Fill();

  }

	*/  

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





