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
class CSVJetVarFiller : public NtupleFillerBase {
 public:
    CSVJetVarFiller(){
    }


    CSVJetVarFiller(const edm::ParameterSet& iConfig, TTree* t):
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


  ~CSVJetVarFiller()
    { 
      if(function!=0) delete function;
    }
       

  void fill(const edm::Event& iEvent, const edm::EventSetup& iSetup)
  {
    edm::Handle<std::vector<T> > handle;

    //edm::Handle<std::vector<T> > handleT;
    singleValue=-1;

     //printf("first\n");
    if(iEvent.getByLabel(src_,handle)) {
      singleValue = 0;
      if(handle->size()>0){
	if(handle->at(0).jets().size()>rank_){
	  std::vector<edm::Ptr<pat::Jet> > cleanedJetsCSVsorted ;//= handle->at(0).jets();

	  for(int i=0;i<(int)handle->at(0).jets().size();i++)
	    cleanedJetsCSVsorted.push_back(handle->at(0).jets().at(i));

	  sortRefVectorByCSV(cleanedJetsCSVsorted);
	  
	  if(cleanedJetsCSVsorted.at((int)rank_)->bDiscriminator("combinedSecondaryVertexBJetTags")>-20)
	    singleValue = (*function)(*(handle->at(0).jets().at((int) rank_)));
	  //printf("nJets: %i\n",(int)handle->at(0).jets().size());
	  //printf("%i th pt: %f\n",(int)rank_,handle->at(0).jets().at((int)rank_)->pt());
	}
      }
    }
  }

  void sortRefVectorByCSV(std::vector<edm::Ptr<pat::Jet> >& vec)
  {
    std::vector<size_t> indices;
    indices.reserve(vec.size());

    for(unsigned int i=0;i<vec.size();++i)
      indices.push_back(i);
    
    refVectorCSVSorter sorter(vec);
    std::sort(indices.begin(),indices.end(),sorter);
        
    std::vector<edm::Ptr<pat::Jet> > sorted;
    sorted.reserve(vec.size());
    
    for(unsigned int i=0;i<indices.size();++i)
      sorted.push_back(vec.at(indices.at(i)));

    vec = sorted;
  }

  class refVectorCSVSorter {
  public:
    refVectorCSVSorter(const std::vector<edm::Ptr<pat::Jet> > vec)
      {
	vec_ = vec;
      }
    refVectorCSVSorter()
      {
      }
    ~refVectorCSVSorter()
      {}

    bool operator()(size_t a , size_t b) {
      return (vec_.at(a)->bDiscriminator("combinedSecondaryVertexBJetTags") > vec_.at(b)->bDiscriminator("combinedSecondaryVertexBJetTags"));
    }
  private:
    std::vector<edm::Ptr<pat::Jet> > vec_;
  };

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
typedef CSVJetVarFiller<PATMuonNuPair> PATMuonNuPairCSVJetVarFiller;
typedef CSVJetVarFiller<PATMuTauPair> PATMuTauPairCSVJetVarFiller;
typedef CSVJetVarFiller<PATElecTauPair> PATEleTauPairCSVJetVarFiller;
//typedef CSVJetVarFiller<PATMuJetPair> PATMuJetPairCSVJetVarFiller;
//typedef CSVJetVarFiller<PATMuPair> PATMuPairCSVJetVarFiller;
//typedef CSVJetVarFiller<PATElecMuPair> PATEleMuPairCSVJetVarFiller;
//typedef CSVJetVarFiller<PATElecMuPair> PATDiTauPairCSVJetVarFiller;





