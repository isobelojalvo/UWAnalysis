#include "PhysicsTools/FWLite/interface/CommandLineParser.h" 
#include "TFile.h"
#include "TROOT.h"
#include "TLorentzVector.h"
#include "TKey.h"
#include "TTree.h"
#include "TH1F.h"
#include "TF1.h"
#include "TDirectory.h"
#include <math.h> 
#include "TMath.h" 
#include <limits>
#include "FWCore/ParameterSet/interface/FileInPath.h"

#include "TauAnalysis/SVfitStandalone/interface/SVfitStandaloneAlgorithm.h"

#include "TH1.h"

void readdir(TDirectory *dir, optutl::CommandLineParser parser, char TreeToUse[]) ;
//void readdir(TFile *f, optutl::CommandLineParser parser, char TreeToUse[]) ;

int main (int argc, char* argv[]) 
{
   optutl::CommandLineParser parser ("Sets Event Weights in the ntuple");
   parser.addOption("branch",optutl::CommandLineParser::kString,"Branch","svFit");
   parser.parseArguments (argc, argv);
   
   char TreeToUse[80]="Ntuple" ;
   
   TFile *f = new TFile(parser.stringValue("outputFile").c_str(),"UPDATE");
   readdir(f,parser,TreeToUse);
   f->Close();

} 


void readdir(TDirectory *dir, optutl::CommandLineParser parser, char TreeToUse[]) 
//void readdir(TFile *f, optutl::CommandLineParser parser, char TreeToUse[]) 
{
  TDirectory *dirsav = gDirectory;
  TIter next(dir->GetListOfKeys());
  //TIter next(f->GetListOfKeys());
  TKey *key;
  char stringA[80]="Ntuple";
  edm::FileInPath inputFileName_visPtResolution("TauAnalysis/SVfitStandalone/data/svFitVisMassAndPtResolutionPDF.root");
  TH1::AddDirectory(false);  
  TFile* inputFile_visPtResolution = new TFile(inputFileName_visPtResolution.fullPath().data());  

  while ((key = (TKey*)next())) {
    
    printf("Found key=%s \n",key->GetName());
    //if(!strcmp(stringA,TreeToUse)) 
    //printf("Strings %s %s \n",TreeToUse,stringA);
    TObject *obj = key->ReadObj();
    std::cout << &obj << "  " << obj << std::endl;
    if (obj->IsFolder()) std::cout << "Is A Folder!" <<std::endl;
    
    if (obj->IsA()->InheritsFrom(TDirectory::Class())) {
      dir->cd(key->GetName());
      //f->cd(key->GetName());
      TDirectory *subdir = gDirectory;
      sprintf(TreeToUse,"%s",key->GetName());
      readdir(subdir,parser,TreeToUse);
      dirsav->cd();
      std::cout << "Found a save directory: " << dirsav << std::endl;
    }
    else if (obj->IsA()->InheritsFrom(TDirectoryFile::Class())) {
      dir->cd(key->GetName());
      //f->cd(key->GetName());
      TDirectory *subdir = gDirectory;
      sprintf(TreeToUse,"%s",key->GetName());
      readdir(subdir,parser,TreeToUse);
      dirsav->cd();
      std::cout << "Found a save directory file: " << dirsav << std::endl;
    }
    else if(obj->IsA()->InheritsFrom(TTree::Class())) {
      std::cout<<"Object inherits from TTree Class Tree to use: "<<TreeToUse<<std::endl;

      TTree *t = (TTree*)obj;

      float svFitMass = -10;
      float svFitPt = -10;
      float svFitEta = -10;
      float svFitPhi = -10;
      float svFitMET = -10;
      //TBranch *newBranch = t->Branch(parser.stringValue("branch").c_str(),&svFitMass,(parser.stringValue("branch")+"/F").c_str());
      TBranch *newBranch1 = t->Branch("m_sv", &svFitMass, "m_sv/F");
      TBranch *newBranch2 = t->Branch("pt_sv", &svFitPt, "pt_sv/F");
      TBranch *newBranch3 = t->Branch("eta_sv", &svFitEta, "eta_sv/F");
      TBranch *newBranch4 = t->Branch("phi_sv", &svFitPhi, "phi_sv/F");
      TBranch *newBranch5 = t->Branch("met_sv", &svFitMET, "met_sv/F");
      float pt1;
      float eta1;
      float phi1;
      float pt2;
      float eta2;
      float phi2;
      float decayMode;
      float decayMode2;
      float covMatrix00;
      float covMatrix10;
      float covMatrix01;
      float covMatrix11;
      // define MET
      double measuredMETx;
      double measuredMETy;
      float met;
      float metphi;
      TLorentzVector TMet(0,0,0,0);
      // define MET covariance
      TMatrixD covMET(2, 2);
      //double mass;
      //ele/mu variables
      svFitStandalone::kDecayType decayType1 = svFitStandalone::kUndefinedDecayType; //svFitStandalone::kTauToElecDecay
      svFitStandalone::kDecayType decayType2 = svFitStandalone::kUndefinedDecayType; //svFitStandalone::kTauToElecDecay
      //svFitStandalone::kDecayType decayType2 = svFitStandalone::kTauToHadDecay; //svFitStandalone::kTauToElecDecay
      float mass1 = 0.0;
      //Should mass2 depend on hadronic tau decay mode?
      float mass2 = 0.139;
      //determine if electron or muon
      std::string channel = "x";
      if(std::string(TreeToUse).find("muTauEvent")!= std::string::npos){
	decayType1 = svFitStandalone::kTauToMuDecay;
    decayType2 = svFitStandalone::kTauToHadDecay; //svFitStandalone::kTauToElecDecay
	mass1 = 105.658e-3;
    channel = "mt";
      }
      else if(std::string(TreeToUse).find("eleTauEvent")!= std::string::npos){
	decayType1 = svFitStandalone::kTauToElecDecay;
    decayType2 = svFitStandalone::kTauToHadDecay; //svFitStandalone::kTauToElecDecay
	mass1 = 0.51100e-3;
    channel = "et";
      }
      else if(parser.stringValue("outputFile").find("_em.root") != std::string::npos){
        //std::cout<< parser.stringValue("outputFile").c_str() << std::endl;
        std::cout<< "EMu sample" <<std::endl;
	decayType1 = svFitStandalone::kTauToElecDecay;
	decayType2 = svFitStandalone::kTauToMuDecay;
	mass1 = 0.51100e-3;
	mass2 = 105.658e-3;
    channel = "em";
      }
      else if(parser.stringValue("outputFile").find("_tt.root") != std::string::npos){
        //std::cout<< parser.stringValue("outputFile").c_str() << std::endl;
        std::cout<< "Double Hadronic sample" <<std::endl;
    decayType1 = svFitStandalone::kTauToHadDecay; //svFitStandalone::kTauToElecDecay
    decayType2 = svFitStandalone::kTauToHadDecay; //svFitStandalone::kTauToElecDecay
    channel = "tt";
      }
      else{
	std::cout<<"TreeToUse "<< std::string(TreeToUse)<<" does not match muTauEvent or eleTauEvent... Skipping!!"<<std::endl;
	continue;
      }
      
      //MET, MET Covariance, lepton objects,
      t->SetBranchAddress("pt_1",&pt1);
      t->SetBranchAddress("eta_1",&eta1);
      t->SetBranchAddress("phi_1",&phi1);
      t->SetBranchAddress("pt_2",&pt2);
      t->SetBranchAddress("eta_2",&eta2);
      t->SetBranchAddress("phi_2",&phi2);
      t->SetBranchAddress("covMatrix00",&covMatrix00);
      t->SetBranchAddress("covMatrix01",&covMatrix01);
      t->SetBranchAddress("covMatrix10",&covMatrix10);
      t->SetBranchAddress("covMatrix11",&covMatrix11);
      t->SetBranchAddress("mvamet",&met);
      t->SetBranchAddress("mvametphi",&metphi);
      if (channel == "et" || channel == "mt") {
      t->SetBranchAddress("tauDecayMode",&decayMode);}
      if (channel == "tt") {
      t->SetBranchAddress("t1decayMode",&decayMode);
      t->SetBranchAddress("t2decayMode",&decayMode2);}
      
      //printf("Found tree -> weighting\n");
      for(Int_t i=0;i<t->GetEntries();++i)
	{
	  t->GetEntry(i);

	  TMet.SetPtEtaPhiM(met,0,metphi,0);
	  
	  measuredMETx = met*TMath::Cos(metphi);
	  measuredMETy = met*TMath::Sin(metphi);
	  /*
	  if(measuredMETx<0.0001){
	    std::cout<<"something seems funny with measuredMETx closing"<<std::endl;
	    std::cout<<"measuredMETx "<<measuredMETx<<" measuredMETy "<<measuredMETy<<" met "<< met<<" metphi "<< metphi<<std::endl;
	    std::cout<<"TLorentz MetX "<<TMet.Px() <<std::endl;
	    std::cout<<"TLorentz MetY "<<TMet.Py() <<std::endl;
	    return;
	    }*/
      if(channel=="et" || channel=="mt"){
	    if(decayMode==0)
	      mass2 = 0.13957;
	    else if(decayMode==1)
	      mass2 = 0.13957*2;
	    else if(decayMode==3)
	      mass2 = 0.13957*3;}
      if(channel=="tt"){
	    if(decayMode==0)
	      mass1 = 0.13957;
	    else if(decayMode==1)
	      mass1 = 0.13957*2;
	    else if(decayMode==3)
	      mass1 = 0.13957*3;
	    if(decayMode2==0)
	      mass2 = 0.13957;
	    else if(decayMode2==1)
	      mass2 = 0.13957*2;
	    else if(decayMode2==3)
	      mass2 = 0.13957*3;}

	  covMET[0][0] =  covMatrix00;
	  covMET[1][0] =  covMatrix10;
	  covMET[0][1] =  covMatrix01;
	  covMET[1][1] =  covMatrix11;
	  ///comment me out 
	  //covMET[0][0] =  787.352;
	  //covMET[1][0] = -178.63;
	  //covMET[0][1] = -178.63;
	  //covMET[1][1] =  179.545;
	  /// to here once we have real covMET... 0's cause SVFit to SegFault.

	  if((decayMode==0||decayMode==1||decayMode==10)&&(channel=="et"||channel=="mt")){
	    // define lepton four vectors
	    std::vector<svFitStandalone::MeasuredTauLepton> measuredTauLeptons;
	    // check if electron or muon
	    measuredTauLeptons.push_back(
		  svFitStandalone::MeasuredTauLepton(decayType1, pt1, eta1,  phi1, mass1)
		  			 ); // tau -> electron decay (Pt, eta, phi, mass)
	    
	    measuredTauLeptons.push_back(
	  	  svFitStandalone::MeasuredTauLepton(decayType2,  pt2, eta2, phi2,  mass2, decayMode)
	  				 ); // tau -> 1prong0pi0 hadronic decay (Pt, eta, phi, mass, pat::Tau.decayMode())
        
	    //std::cout<<"Here 0"<<std::endl;
	    SVfitStandaloneAlgorithm algo(measuredTauLeptons, measuredMETx, measuredMETy, covMET, 1);
	    //std::cout<<"Here 1"<<std::endl;
	    algo.addLogM(false);  
	    //std::cout<<"Here 2"<<std::endl;
	    algo.shiftVisPt(true, inputFile_visPtResolution);
	    //std::cout<<"Here 3"<<std::endl;
	    algo.integrateMarkovChain();
	    //std::cout<<"Here 4"<<std::endl;
	    svFitMass = algo.getMass(); // return value is in units of GeV
	    svFitPt = algo.pt();
	    svFitEta = algo.eta();
	    svFitPhi = algo.phi();
	    svFitMET = algo.fittedMET().Rho();
	    //std::cout<<"Here 5"<<std::endl;
	    if ( algo.isValidSolution() ) {
	      std::cout << "found mass = " << svFitMass << std::endl;
        }
	    else {
	      std::cout << "sorry -- status of NLL is not valid [" << algo.isValidSolution() << "]" << std::endl;
	    }
      } // eTau / muTau

	  else if(channel=="em"){
	    // define lepton four vectors
	    std::vector<svFitStandalone::MeasuredTauLepton> measuredTauLeptons;
	    // check if electron or muon
	      measuredTauLeptons.push_back(
		   svFitStandalone::MeasuredTauLepton(decayType1, pt1, eta1,  phi1, mass1)
		  			 ); // tau -> electron decay (Pt, eta, phi, mass)
	    
	      measuredTauLeptons.push_back(
		   svFitStandalone::MeasuredTauLepton(decayType2,  pt2, eta2, phi2, mass2)
					 ); // tau -> 1prong0pi0 hadronic decay (Pt, eta, phi, mass, pat::Tau.decayMode())

	    //std::cout<<"Here 0"<<std::endl;
	    SVfitStandaloneAlgorithm algo(measuredTauLeptons, measuredMETx, measuredMETy, covMET, 1);
	    //std::cout<<"Here 1"<<std::endl;
	    algo.addLogM(false);  
	    //std::cout<<"Here 2"<<std::endl;
	    algo.shiftVisPt(true, inputFile_visPtResolution);
	    //std::cout<<"Here 3"<<std::endl;
	    algo.integrateMarkovChain();
	    //std::cout<<"Here 4"<<std::endl;
	    svFitMass = algo.getMass(); // return value is in units of GeV
	    svFitPt = algo.pt();
	    svFitEta = algo.eta();
	    svFitPhi = algo.phi();
	    svFitMET = algo.fittedMET().Rho();
	    //std::cout<<"Here 5"<<std::endl;
	    if ( algo.isValidSolution() ) {
	      std::cout << "found mass = " << svFitMass << std::endl;
        }
	    else {
	      std::cout << "sorry -- status of NLL is not valid [" << algo.isValidSolution() << "]" << std::endl;
	    }
      } // eMu


	  else if((decayMode==0||decayMode==1||decayMode==10)&&(decayMode2==0||decayMode2==1||decayMode2==10)&&channel=="tt"){
	    // define lepton four vectors
	    std::vector<svFitStandalone::MeasuredTauLepton> measuredTauLeptons;
	    // check if electron or muon
	      measuredTauLeptons.push_back(
		   svFitStandalone::MeasuredTauLepton(decayType1, pt1, eta1,  phi1, mass1, decayMode)
		  			 ); // tau -> electron decay (Pt, eta, phi, mass)
	    
	      measuredTauLeptons.push_back(
	  	   svFitStandalone::MeasuredTauLepton(decayType2,  pt2, eta2, phi2,  mass2, decayMode2)
	  				 ); // tau -> 1prong0pi0 hadronic decay (Pt, eta, phi, mass, pat::Tau.decayMode())

	    //std::cout<<"Here 0"<<std::endl;
	    SVfitStandaloneAlgorithm algo(measuredTauLeptons, measuredMETx, measuredMETy, covMET, 1);
	    //std::cout<<"Here 1"<<std::endl;
	    algo.addLogM(false);  
	    //std::cout<<"Here 2"<<std::endl;
	    algo.shiftVisPt(true, inputFile_visPtResolution);
	    //std::cout<<"Here 3"<<std::endl;
	    algo.integrateMarkovChain();
	    //std::cout<<"Here 4"<<std::endl;
	    svFitMass = algo.getMass(); // return value is in units of GeV
	    svFitPt = algo.pt();
	    svFitEta = algo.eta();
	    svFitPhi = algo.phi();
	    svFitMET = algo.fittedMET().Rho();
	    //std::cout<<"Here 5"<<std::endl;
	    if ( algo.isValidSolution() ) {
	      std::cout << "found mass = " << svFitMass << std::endl;
        }
	    else {
	      std::cout << "sorry -- status of NLL is not valid [" << algo.isValidSolution() << "]" << std::endl;
	    }
      } // Double Hadronic (TT)

	  else
	    svFitMass = 0;
	  
      std::cout << "Mass: " << svFitMass << " Pt: " << svFitPt << " Eta: " << svFitEta;
      std::cout << " Phi: " << svFitPhi << " MET: " << svFitMET << std::endl;
	  newBranch1->Fill();
	  newBranch2->Fill();
	  newBranch3->Fill();
	  newBranch4->Fill();
	  newBranch5->Fill();
	  //dir->Fill();
      svFitMass = -100;
      svFitPt = -100;
      svFitEta = -100;
      svFitPhi = -100;
      svFitMET = -100;
	}
    
    inputFile_visPtResolution->Close(); 
	//f->Write("",TObject::kOverwrite);
	dir->cd();
	t->Write("",TObject::kOverwrite);
	//return;
	//strcpy(TreeToUse,stringA) ;
	//delete inputFile_visPtResolution;
    }
  
  }
  return;
}
