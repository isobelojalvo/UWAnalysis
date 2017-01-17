#include "PhysicsTools/FWLite/interface/CommandLineParser.h" 
#include "PhysicsTools/Utilities/interface/Lumi3DReWeighting.h"
#include "PhysicsTools/Utilities/interface/LumiReWeighting.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h"

#include "boost/filesystem.hpp"
#include "TFile.h"
#include "TROOT.h"
#include "TKey.h"
#include "TTree.h"
#include "TH1F.h"
#include <iostream>

using std::cout;
using std::endl;

void readdir(TDirectory *dir,optutl::CommandLineParser parser,float ev); 


int main (int argc, char* argv[]) 
{
   optutl::CommandLineParser parser ("Sets Event Weights in the ntuple");
   parser.addOption("histoName",optutl::CommandLineParser::kString,"Counter Histogram Name","EventSummary");
   parser.addOption("weight",optutl::CommandLineParser::kDouble,"Weight to apply",1.0);
   parser.addOption("branch",optutl::CommandLineParser::kString,"Branch","__WEIGHT__");

   
   parser.parseArguments (argc, argv);
   

 
   TFile *g = new TFile(parser.stringValue("outputFile").c_str(),"UPDATE");

   //TH1F* evC  = (TH1F*)g->Get(parser.stringValue("histoName").c_str());
   //float ev = evC->GetBinContent(1);
   

   g->Close();
   
   //printf("Found  %f Events Counted\n",ev);
   
   TFile *f = new TFile(parser.stringValue("outputFile").c_str(),"UPDATE");   
   
   readdir(f,parser,1);

   f->Close();

} 


void readdir(TDirectory *dir,optutl::CommandLineParser parser,float ev) 
{
  //Initialize PU things
  edm::LumiReWeighting *LumiWeightsAll;
  edm::LumiReWeighting *LumiWeightsBCD;
  edm::LumiReWeighting *LumiWeightsEF;
  edm::LumiReWeighting *LumiWeightsG;
  edm::LumiReWeighting *LumiWeightsH;

  std::string base = std::getenv("CMSSW_BASE");
  std::string fPUMCname      = base+"/src/UWAnalysis/Configuration/data/puInfo/MC_Moriond17_PU25ns_V1.root";
  std::string fPUDATAnameAll = base+"/src/UWAnalysis/Configuration/data/puInfo/DataPUHistoAll.root";
  std::string fPUDATAnameBCD = base+"/src/UWAnalysis/Configuration/data/puInfo/DataPUHistoBCD.root";
  std::string fPUDATAnameEF  = base+"/src/UWAnalysis/Configuration/data/puInfo/DataPUHistoEF.root";
  std::string fPUDATAnameG   = base+"/src/UWAnalysis/Configuration/data/puInfo/DataPUHistoG.root";
  std::string fPUDATAnameH   = base+"/src/UWAnalysis/Configuration/data/puInfo/DataPUHistoH.root";

  bool fPUMCValid      = boost::filesystem::exists( fPUMCname   );
  bool fPUDataAllValid = boost::filesystem::exists( fPUDATAnameAll );
  bool fPUDataBCDValid = boost::filesystem::exists( fPUDATAnameBCD );
  bool fPUDataEFValid  = boost::filesystem::exists( fPUDATAnameEF  );
  bool fPUDataGValid   = boost::filesystem::exists( fPUDATAnameG   );
  bool fPUDataHValid   = boost::filesystem::exists( fPUDATAnameH   );

  if (fPUMCValid && fPUDataAllValid && fPUDataBCDValid && fPUDataEFValid && fPUDataGValid && fPUDataHValid){
    LumiWeightsAll = new edm::LumiReWeighting(fPUMCname,fPUDATAnameAll,"pileup","pileup");
    LumiWeightsBCD = new edm::LumiReWeighting(fPUMCname,fPUDATAnameBCD,"pileup","pileup");
    LumiWeightsEF  = new edm::LumiReWeighting(fPUMCname,fPUDATAnameEF, "pileup","pileup");
    LumiWeightsG   = new edm::LumiReWeighting(fPUMCname,fPUDATAnameG,  "pileup","pileup");
    LumiWeightsH   = new edm::LumiReWeighting(fPUMCname,fPUDATAnameH,  "pileup","pileup");

  }
  else{
    if(!fPUMCValid)
      std::cout<<"MC file is broken... exiting."<<std::endl;
    if(!fPUDataAllValid)
      std::cout<<"Data file All is broken... exiting."<<std::endl;
    if(!fPUDataBCDValid)
      std::cout<<"Data file BCD is broken... exiting."<<std::endl;
    if(!fPUDataEFValid)
      std::cout<<"Data file EF is broken... exiting."<<std::endl;
    if(!fPUDataGValid)
      std::cout<<"Data file G is broken... exiting."<<std::endl;
    if(!fPUDataHValid)
      std::cout<<"Data file H is broken... exiting."<<std::endl;
    return ;
  }

  TDirectory *dirsav = gDirectory;
  TIter next(dir->GetListOfKeys());
  TKey *key;
  while ((key = (TKey*)next())) {
    printf("Found key=%s \n",key->GetName());
    TString keyname = key->GetName();
    if (keyname=="CircJetID_puv2"||keyname=="sumweights"){
      printf("Skipping key %s . Not weighting. \n",key->GetName());
      continue;
    }
    std::cout<<"keyName "<<keyname<<std::endl;
    
    TObject *obj = key->ReadObj();
    
    if (obj->IsA()->InheritsFrom(TDirectory::Class())) {
      dir->cd(key->GetName());
      TDirectory *subdir = gDirectory;
      readdir(subdir,parser,ev);
      dirsav->cd();
    }
    else if(obj->IsA()->InheritsFrom(TTree::Class())) {
      float truePU;
      TTree *t = (TTree*)obj;
      t->SetBranchAddress("puTruth",&truePU);
      dirsav->cd();

      float weightAll = 1;
      float weightBCD = 1;
      float weightEF  = 1;
      float weightG   = 1;
      float weightH   = 1;
      
      TBranch *newBranchAll = t->Branch("puweightAll", &weightAll, "puweightAll/F");
      TBranch *newBranchBCD = t->Branch("puweightBCD", &weightBCD, "puweightBCD/F");
      TBranch *newBranchEF  = t->Branch("puweightEF",  &weightEF,  "puweightEF/F" );
      TBranch *newBranchG   = t->Branch("puweightG",   &weightG,   "puweightG/F"  );
      TBranch *newBranchH   = t->Branch("puweightH",   &weightH,   "puweightH/F"  );

      //puTruth
      printf("Found tree -> weighting\n");
      for(Int_t i=0;i<t->GetEntries();++i)
	{

	  t->GetEntry(i);
	  
	  weightAll = LumiWeightsAll->weight(truePU);
	  weightBCD = LumiWeightsBCD->weight(truePU);
	  weightEF  =  LumiWeightsEF->weight(truePU);
	  weightG   =   LumiWeightsG->weight(truePU);
	  weightH   =   LumiWeightsH->weight(truePU);

	  //std::cout<<"true PU "<<truePU<<" weightAll "<<weightAll<<std::endl;	  
	  dirsav->cd();
	  newBranchAll->Fill();
	  newBranchBCD->Fill();
	  newBranchEF->Fill();
	  newBranchG->Fill();
	  newBranchH->Fill();
	}
      std::cout<<"trying to save the tree"<<std::endl;
      dir->cd();
      t->Write("",TObject::kOverwrite);
    }//end else if object A
  }//end while key
}//end read directory
