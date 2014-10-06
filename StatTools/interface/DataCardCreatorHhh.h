#include "TCanvas.h"
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TH1.h"
#include "TF1.h"
#include "PhysicsTools/FWLite/interface/CommandLineParser.h" 
#include <math.h>
#include <boost/algorithm/string.hpp>
#include "HiggsAnalysis/CombinedLimit/interface/th1fmorph.h"
#include "HiggsAnalysis/CombinedLimit/interface/TH1Keys.h"
#include <TEfficiency.h>
#include <TMath.h>
#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>
//#include "FineBins.h"

struct BkgOutput {
  float DATA;
  float W, dW;
  float WF, dWF;
  float WSS, dWSS, WSDB;
  float QCD, dQCD, QCDSDB;
  float ZLFT, dZLFT;
  float ZJFT, dZJFT;
  float ZLFTSS, dZLFTSS;
  float ZJFTSS, dZJFTSS;
  float TOP, dTOP;
  float VV, dVV;
  float ZTT, dZTT;
  float WCORR, dWCORR;
  float WSSCORR, dWSSCORR;
  float ZTTCORR, dZTTCORR;

  BkgOutput(){};

  BkgOutput(float i) {
    // This assumes that a-d are all of the same type and all in order
    std::fill(&DATA, &dZTTCORR+1, i);
  }

};



class DataCardCreatorHhh {
 public:

  DataCardCreatorHhh(optutl::CommandLineParser parser) {
    channel_ = parser.stringValue("channel");
    shifts_  = parser.stringVector("shifts");
    energy_ = parser.stringValue("energy");

    //create the name you need to add to the histograms 
    //in the root file 
    for(unsigned int i=0;i<shifts_.size();++i) {
      std::string shiftL = shifts_.at(i);
      shiftL.resize(1);
      boost::to_lower(shiftL);
      std::string chan = "mutau";
      //Change Me
      if(channel_=="eleTau") chan = "etau";
      shiftsPostFix_.push_back("CMS_scale_"+shiftL+"_"+chan+"_"+energy_);
    }
      
    //read input files
    zttFile_  = parser.stringValue("zttFile");
    zllFile_  = parser.stringValue("zllFile");
    wFile_    = parser.stringValue("wFile");
    vvFile_   = parser.stringValue("vvFile");
    topFile_  = parser.stringValue("topFile");
    dataFile_ = parser.stringValue("dataFile");
    //wFile42_  = parser.stringValue("W42File");

    //read control and signal regions
    preSelection_ = parser.stringValue("preselection");

    signalSelection_      = parser.stringValue("signalSelection");
    wSelection_           = parser.stringValue("wSelection");
    qcdSelection_         = parser.stringValue("qcdSelection");
    relaxedSelection_     = parser.stringValue("relaxedSelection");
    bSelection_           = parser.stringValue("bSelection");
    antibSelection_       = parser.stringValue("antibSelection");
    relaxedSelection_     = parser.stringValue("relaxedSelection");
    btagRelaxedSelection_ = parser.stringValue("btagRelaxedSelection");
    trigSelection_        = parser.stringValue("trigSelection");
    blinding_             = parser.stringValue("blinding");
    charge_               = parser.stringValue("charge");

    ZTT_genTauSel_        = "(genTaus>0&&genVisPt2>18&&( !((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)) ) )"; //Zttyield
    ZTTLL_genTauReject_   = "(genTaus>0&&((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))"; /// zTT_LL
    ZJFT_genLReject_      = "(!((genTaus==0&&abs(pdg2)==13&&genPt2>8)||(genTaus==0&&abs(pdg2)==11&&genPt2>8)||(genTaus>0&&genVisPt2>18)))"; //ZJ
    ZLFT_genLSel_         = "(genTaus==0&&((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))";///zl

    dataSelection_        = "EVENT>0";

    osSignalSelection_    = signalSelection_+"&&"+charge_;
    ssSignalSelection_    = signalSelection_+"&&charge!=0";
    osWSelection_         = wSelection_+"&&charge==0";
    ssWSelection_         = wSelection_+"&&charge!=0";
    verbose_              = parser.integerValue("verbose");
    
    //read systematic uncertainties 
    luminosity_    = parser.doubleValue("luminosity");
    luminosityErr_ = parser.doubleValue("luminosityErr");
    muID_          = parser.doubleValue("muID");
    muIDErr_       = parser.doubleValue("muIDErr");
    bID_           = parser.doubleValue("bID");
    bIDErr_        = parser.doubleValue("bIDErr");
    bMisID_        = parser.doubleValue("bMisID");
    bMisIDErr_     = parser.doubleValue("bMisIDErr");
    eleID_         = parser.doubleValue("eleID");
    eleIDErr_      = parser.doubleValue("eleIDErr");
    tauID_         = parser.doubleValue("tauID");
    tauIDHigh_     = parser.doubleValue("tauIDHigh");
    tauIDErr_      = parser.doubleValue("tauIDErr");
    zttScale_      = parser.doubleValue("zttScale");
    zttScaleErr_   = parser.doubleValue("zttScaleErr");

    //read the basic varibale you will put in the histogram
    variable_      = parser.stringValue("variable");

    //read the event weight for MC and embedded
    weight_        = parser.stringValue("weight");
    embWeight_     = parser.stringValue("embWeight");

    //define the histogram binning
    bins_ = parser.integerValue("bins");
    min_  = parser.doubleValue("min");
    max_  = parser.doubleValue("max");


    //Define background uncertainty Errors
    topErr_     = parser.doubleValue("topErr");
    vvErr_      = parser.doubleValue("vvErr");
    zlftErr_    = parser.doubleValue("zlftErr");
    zlftFactor_ = parser.doubleValue("zlftFactor");

    zjftErr_      = parser.doubleValue("zjftErr");
    wFactorErr_   = parser.doubleValue("wFactorErr");
    qcdFactor_    = parser.doubleValue("qcdFactor");
    qcdFactorErr_ = parser.doubleValue("qcdFactorErr");
    bFactorZ_     = parser.doubleValue("bFactorZ");
    bFactorZErr_  = parser.doubleValue("bFactorZErr");
    bFactorW_     = parser.doubleValue("bFactorW");
    bFactorWErr_  = parser.doubleValue("bFactorWErr");

    dir_ = parser.stringValue("dir");


    //predefine te masses you are going to make 
    mssmMasses_ = {"80","90","100","120","130","140","160","180","200","250",
		   "300","350","400","450","500","600","700","800","900","1000"};    

    smMasses_ = {"90","95","100","105","110","115","120","125","130",
			      "135","140","145","150","155","160"};
    smMassesDC_ = smMasses_;
    

    for(int i = 1; i<16; i++)
      smSigma_.push_back(1.0);

    for(int i = 1; i<16; i++)
      vbfSigma_.push_back(1.0);

    for(int i = 1; i<16; i++)
      vhSigma_.push_back(1.0);

    mssmBBFraction_.push_back(0.5180);
    mssmBBFraction_.push_back(0.5661);
    mssmBBFraction_.push_back(0.6481);
    mssmBBFraction_.push_back(0.6497);
    mssmBBFraction_.push_back(0.6852);
    mssmBBFraction_.push_back(0.7399);
    mssmBBFraction_.push_back(0.7779);
    mssmBBFraction_.push_back(0.8047);
    mssmBBFraction_.push_back(0.8587);
    mssmBBFraction_.push_back(0.8916);
    mssmBBFraction_.push_back(0.9108);
    mssmBBFraction_.push_back(0.9216);
    mssmBBFraction_.push_back(0.9327);
    mssmBBFraction_.push_back(0.9415);

    scaleUp_ = parser.doubleValue("scaleUp");

    fout_ = new TFile(parser.stringValue("outputfile").c_str(),"RECREATE");

  }


  void makeHeavyHiggsShape(std::string preselection, std::string categoryselection, std::string prefix) {

    std::pair<float,float> tmp;
    float legCorr=1.0;

    if(muID_!=0&&eleID_!=0) {legCorr*=muID_*eleID_;}
    if(muID_!=0&&eleID_==0) {legCorr*=muID_*tauID_;}
    if(muID_==0&&eleID_!=0) {legCorr*=eleID_*tauID_;}

    tmp= createHistogramAndShiftsFinal(dir_+"ggHhh260.root","ggHTohhTo2Tau2B260",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
    tmp= createHistogramAndShiftsFinal(dir_+"ggHhh300.root","ggHTohhTo2Tau2B300",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
    tmp= createHistogramAndShiftsFinal(dir_+"ggHhh350.root","ggHTohhTo2Tau2B350",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);

  }


  /*-------------Create Histograms------------------*/

  BkgOutput runOSLSMT(std::string preSelection,std::string prefix,std::string zShape, float topExtrap) {

    BkgOutput output(0);    

    float leg1Corr=1.0;
    if(muID_!=0) leg1Corr*=muID_;
    if(eleID_!=0) leg1Corr*=eleID_;

    printf("Tau ID Scale Factor is %.3f \n",tauID_);

    //Create Z-->tautau
    if(!runZTT(preSelection, prefix, zShape, topExtrap, output)){
      std::cout<<"Error Creating Ztt"<<std::endl;
      return output;
    }

    //Create ttbar
    std::pair<float,float> topYield      = createHistogramAndShiftsFinal(topFile_,"TT",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*leg1Corr*tauID_*topExtrap,prefix);
    std::pair<float,float> topInflYield  = inflateError(topYield,topErr_);
    printf("TTbar events in signal region = %f + %f \n",topInflYield.first,topInflYield.second);
    output.TOP  = topInflYield.first;
    output.dTOP = topInflYield.second;

    //Create Diboson
    std::pair<float,float> vvYield      = createHistogramAndShiftsFinal(vvFile_,"VV",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*leg1Corr*tauID_,prefix);
    std::pair<float,float> vvInflYield  = inflateError(vvYield,vvErr_);
    printf("Diboson events in signal region = %f + %f \n",vvInflYield.first,vvInflYield.second);
    output.VV  = vvInflYield.first;
    output.dVV = vvInflYield.second;


    //Create ZL and ZJ
    std::pair<float,float> zlftYield   = createHistogramAndShiftsFinal(zllFile_,"ZL",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&genTaus==0&&((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zlftFactor_*zttScale_,prefix,false);
    std::pair<float,float> zlftInflYield  = inflateError(zlftYield,zlftErr_);
    printf("Z (l->tau) in signal region = %f + %f \n",zlftInflYield.first,zlftInflYield.second);
    output.ZLFT  = zlftInflYield.first;
    output.dZLFT = zlftInflYield.second;


    std::pair<float,float> zjftYield      = createHistogramAndShiftsFinal(zllFile_,"ZJ",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&(!((genTaus==0&&abs(pdg2)==13&&genPt2>8)||(genTaus==0&&abs(pdg2)==11&&genPt2>8)||(genTaus>0&&genVisPt2>18))))*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zttScale_,prefix);    
    std::pair<float,float> zjftInflYield  = inflateError(zjftYield,zjftErr_);
    printf("Z (j->tau) in signal region = %f + %f \n",zjftInflYield.first,zjftInflYield.second);
    output.ZJFT  = zjftInflYield.first;
    output.dZJFT = zjftInflYield.second;

    //Create W 
    //In principle osSignalSelection should work as a dummy variable
    if(!runW(preSelection, prefix, zShape, topExtrap, output, "pt1>-100", "pt1>-100")){
      std::cout<<"Error Creating W"<<std::endl;
      return output;
    }

    //Create QCD
    if(!runQCD(preSelection, prefix, zShape, topExtrap, output, "pt1>-100", "pt1>-100")){
      std::cout<<"Error Creating QCD"<<std::endl;
      return output;
    }

    //Create Data
    std::pair<float,float> dataY         = createHistogramAndShiftsFinal(dataFile_,"data_obs","("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+blinding_+")",scaleUp_,prefix);
    std::pair<float,float> dataYRounded  = std::make_pair(rintf(dataY.first),dataY.second);
    renormalizeHistogram(channel_+prefix,"data_obs",dataYRounded.first);
    output.DATA = dataY.first;

    std::cout<<endl;
    std::cout<<"Total Data: "<<output.DATA<<std::endl;
    std::cout<<"BKGD Yields "<<std::endl;
    std::cout<<"QCD: "<< output.QCD<<std::endl;
    std::cout<<"W: "<< output.W<<std::endl;
    std::cout<<"TOP: "<< output.TOP<<std::endl;
    std::cout<<"VV: "<< output.VV<<std::endl;
    std::cout<<"ZLFT: "<< output.ZLFT<<std::endl;
    std::cout<<"ZJFT: "<< output.ZJFT<<std::endl;
    std::cout<<"ZTT: "<< output.ZTT<<std::endl;

    //TODO: Check that this outputs the correct values
    float background    = output.QCD  + output.W  + output.TOP  + output.VV  + output.ZLFT  + output.ZJFT  + output.ZTT;
    float backgroundErr = sqrt( pow(output.dQCD,2) + pow(output.dW,2) + pow(output.dTOP,2) + pow(output.dVV,2) + pow(output.dZLFT,2) + pow(output.dZJFT,2) + pow(output.dZTT,2));

    printf("BACKGROUND=%f +-%f \n",background,backgroundErr);


    ///LATEX->Here since we want it for the note add all errors , even those that will go separate in the datacard
    /*
    printf("LATEX ------------------------------------\n");
    printf("Total & %.2f & %.2f & %.2f & %.2f \\\\ \n", dataYield.first, dataYieldSdb.first, dataSSYield.first, dataSSYieldSdb.first);
    printf("Di-Boson & %.2f $\\pm$ %.2f & %.2f $\\pm$ %.2f & - & - \\\\ \n", vvInflYield.first, quadrature(vvInflYield.first,vvInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_), vvInflYieldSdb.first, quadrature(vvInflYieldSdb.first,vvInflYieldSdb.second,muIDErr_,eleIDErr_,tauIDErr_));
    printf("$t\\bar{t}$ & %.2f $\\pm$ %.2f & %.2f $\\pm$ %.2f & - & - \\\\ \n", topInflYield.first,quadrature(topInflYield.first,topInflYield.second,muIDErr_,eleIDErr_,tauIDErr_), topInflYieldSdb.first, quadrature(topInflYieldSdb.first,topInflYield.second,muIDErr_,eleIDErr_,tauIDErr_));
    printf("$Z^{l+jet}$ & %.2f $\\pm$ %.2f & - & %.2f $\\pm$ %.2f & - \\\\ \n", zjftInflYield.first, quadrature(zjftInflYield.first,zjftInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_), zjftInflSSYield.first,quadrature(zjftInflSSYield.first,zjftInflSSYield.second,muIDErr_,eleIDErr_,zttScaleErr_));
    printf("$Z^{ll}$ & %.2f $\\pm$ %.2f & - & %.2f $\\pm$ %.2f & - \\\\ \n", zlftInflYield.first, quadrature(zlftInflYield.first,zlftInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_),zlftInflSSYield.first,quadrature(zlftInflSSYield.first,zlftInflSSYield.second,muIDErr_,eleIDErr_,zttScaleErr_));
    printf("$W+jets$ & %.2f $\\pm$ %.2f & %.2f $\\pm$ %.2f & %.2f $\\pm$ %.2f & %.2f $\\pm$ %.2f  \\\\ \n", osWLow.first, osWLow.second, osWHigh.first, osWHigh.second, ssWLow.first, ssWLow.second, dataSSYieldSdb.first, dataSSYieldSdb.second);
    printf("QCD & %.2f $\\pm$ %.2f & - & %.2f $\\pm$ %.2f & - \\\\ \n", osQCD.first, osQCD.second, ssQCD.first, ssQCD.second);
    printf("$Z\\rightarrow\\tau\\tau$ & %.2f $\\pm$ %.2f & - & - & - \\\\ \n", zttYield.first,quadrature(zttYield.first,zttYield.second,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_));
    */

    float fullBackgroundErr = sqrt(pow(quadrature(output.VV,output.dVV,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_),2)
				   +pow(quadrature(output.TOP,output.dTOP,muIDErr_,eleIDErr_,tauIDErr_),2)
				   +pow(quadrature(output.ZJFT,output.dZJFT,muIDErr_,eleIDErr_,zttScaleErr_),2)
				   +pow(quadrature(output.ZLFT,output.dZLFT,muIDErr_,eleIDErr_,zttScaleErr_),2)
				   +pow(output.dQCD,2)
				   +pow(output.dW,2)
				   +pow(quadrature(output.ZTT,output.dZTT,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_),2));
    
    printf("Total Background & %.2f $\\pm$ %.2f & - & - & - \\\\ \n",background,sqrt(pow(quadrature(output.VV,    output.dVV,   muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_),2)
										     +pow(quadrature(output.TOP,  output.dTOP,  muIDErr_,eleIDErr_,tauIDErr_),2)
										     +pow(quadrature(output.ZJFT, output.dZJFT, muIDErr_,eleIDErr_,zttScaleErr_),2)
										     +pow(quadrature(output.ZLFT, output.dZLFT, muIDErr_,eleIDErr_,zttScaleErr_),2)
										     +pow(output.dQCD,2)
										     +pow(output.dW,2)
										     +pow(quadrature(output.ZTT,output.dZTT,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_),2)));
    
    
    
    //create a histogram with the error for plotting reasons and only
    TH1F *err = new TH1F("BKGErr","",1,0,1);
    err->SetBinContent(1,fullBackgroundErr/background);
    fout_->cd((channel_+prefix).c_str());
    err->Write();

    return output;      
  }

  /*
   * Run the full extrapolation in the Btag category
   * Needed: BtagSF, categorySelection
   *
   */
  
  BkgOutput runFullExtrapBtag(std::string relaxedSelection, std::string preSelection, std::string categorySelection_, std::string prefix, std::string zShape, float topExtrap, float zExtrap, float zExtrapErr, std::string bTagSF) {

    //TODO: Fix this category seleciton business, should be more elegant
    std::string categorySelection = categorySelection_;
    std::string dummySelection_   = osSignalSelection_;

    weight_ = weight_+"*"+bTagSF;

    BkgOutput output;    
    output.ZTTCORR=zExtrap;    
    output.dZTTCORR=zExtrapErr;

    float leg1Corr=1.0;
    if(muID_!=0) leg1Corr*=muID_;
    if(eleID_!=0) leg1Corr*=eleID_;

    printf("Tau ID Scale Factor is %.3f \n",tauID_);

    //Create Z-->tautau
    //TODO: Check me, previous Btag ZTT shape correction had a special normalization method
    if(!runZTT(preSelection, prefix, zShape, topExtrap, output, categorySelection)){
      std::cout<<"Error Creating Ztt"<<std::endl;
      return output;
    }

    //Create ttbar
    //Last argument is a dummy argument
    if(!runTOP(preSelection, prefix, zShape, topExtrap, output, categorySelection, relaxedSelection)){
      std::cout<<"Error Creating TOP"<<std::endl;
      return output;
    }


    //Create Diboson
    //stopped here!
    std::pair<float,float> vvYield      = createHistogramAndShiftsFinal(vvFile_,"VV",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection_+")*"+weight_),luminosity_*leg1Corr*tauID_,prefix);
    std::pair<float,float> vvInflYield  = inflateError(vvYield,vvErr_);
    printf("Diboson events in signal region = %f + %f \n",vvInflYield.first,vvInflYield.second);
    output.VV  = vvInflYield.first;
    output.dVV = vvInflYield.second;


    //Create ZL and ZJ
    std::pair<float,float> zlftYield   = createHistogramAndShiftsFinal(zllFile_,"ZL",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection_+"&&"+ZLFT_genLSel_+")*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zlftFactor_*zttScale_,prefix,false);
    std::pair<float,float> zlftInflYield  = inflateError(zlftYield,zlftErr_);
    printf("Z (l->tau) in signal region = %f + %f \n",zlftInflYield.first,zlftInflYield.second);
    output.ZLFT  = zlftInflYield.first;
    output.dZLFT = zlftInflYield.second;

    if(shifts_.size()>0){
      std::pair<float,float> zlShiftUp      = createHistogramShifted(zllFile_,"ZL_CMS_htt_ZLScale_mutau_8TeVUp",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&genTaus==0&& ((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))*ZeFakeTau*"+weight_),"1.02",luminosity_*leg1Corr*zlftFactor_*zttScale_*zExtrap,prefix);
      std::pair<float,float> zlShiftDown     = createHistogramShifted(zllFile_,"ZL_CMS_htt_ZLScale_mutau_8TeVDown",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&genTaus==0&& ((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))*ZeFakeTau*"+weight_),"0.98",luminosity_*leg1Corr*zlftFactor_*zttScale_*zExtrap,prefix);
      
    }

    std::pair<float,float> zjftYield      = createHistogramAndShiftsFinal(zllFile_,"ZJ",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection_+"&&"+ZJFT_genLReject_+")*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zttScale_,prefix);    
    std::pair<float,float> zjftInflYield  = inflateError(zjftYield,zjftErr_);
    printf("Z (j->tau) in signal region = %f + %f \n",zjftInflYield.first,zjftInflYield.second);
    output.ZJFT  = zjftInflYield.first;
    output.dZJFT = zjftInflYield.second;

    //Create W
    if(!runW(preSelection, prefix, zShape, topExtrap, output, categorySelection, relaxedSelection)){
      std::cout<<"Error Creating W"<<std::endl;
      return output;
    }

    //Create QCD
    if(!runQCD(preSelection, prefix, zShape, topExtrap, output, categorySelection, relaxedSelection)){
      std::cout<<"Error Creating QCD"<<std::endl;
      return output;
    }

    //Create Data
    std::pair<float,float> dataY         = createHistogramAndShiftsFinal(dataFile_,"data_obs","("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&"+blinding_+")",scaleUp_,prefix);
    std::pair<float,float> dataYRounded  = std::make_pair(rintf(dataY.first),dataY.second);
    renormalizeHistogram(channel_+prefix,"data_obs",dataYRounded.first);
    output.DATA = dataY.first;

    std::cout<<endl;
    std::cout<<"Total Data: "<<output.DATA<<std::endl;
    std::cout<<"BKGD Yields "<<std::endl;
    std::cout<<"QCD: "<< output.QCD<<std::endl;
    std::cout<<"W: "<< output.W<<std::endl;
    std::cout<<"TOP: "<< output.TOP<<std::endl;
    std::cout<<"VV: "<< output.VV<<std::endl;
    std::cout<<"ZLFT: "<< output.ZLFT<<std::endl;
    std::cout<<"ZJFT: "<< output.ZJFT<<std::endl;
    std::cout<<"ZTT: "<< output.ZTT<<std::endl;


    float background    = output.QCD  + output.W  + output.TOP  + output.VV  + output.ZLFT  + output.ZJFT  + output.ZTT;
    float backgroundErr = sqrt( pow(output.dQCD,2) + pow(output.dW,2) + pow(output.dTOP,2) + pow(output.dVV,2) + pow(output.dZLFT,2) + pow(output.dZJFT,2) + pow(output.dZTT,2));
    printf("BACKGROUND=%f +-%f \n",background,backgroundErr);

    ///LATEX->Here since we want it for the note add all errors , even those that will go separate in the datacard
    
    //printf("LATEX ------------------------------------\n");
    //printf("Total & %.2f & %.2f & %.2f & %.2f \\\\ \n", dataYield.first, dataYieldSdb.first, dataSSYield.first, dataSSYieldSdb.first);
    //printf("Di-Boson & %.2f $\\pm$ %.2f & %.2f $\\pm$ %.2f & - & - \\\\ \n", vvInflYield.first, quadrature(vvInflYield.first,vvInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_), vvInflYieldSdb.first, quadrature(vvInflYieldSdb.first,vvInflYieldSdb.second,muIDErr_,eleIDErr_,tauIDErr_));
    //printf("$t\\bar{t}$ & %.2f $\\pm$ %.2f & %.2f $\\pm$ %.2f & - & - \\\\ \n", topInflYield.first,quadrature(topInflYield.first,topInflYield.second,muIDErr_,eleIDErr_,tauIDErr_), topInflYieldSdb.first, quadrature(topInflYieldSdb.first,topInflYield.second,muIDErr_,eleIDErr_,tauIDErr_));
    //printf("$Z^{l+jet}$ & %.2f $\\pm$ %.2f & - & %.2f $\\pm$ %.2f & - \\\\ \n", zjftInflYield.first, quadrature(zjftInflYield.first,zjftInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_), zjftInflSSYield.first,quadrature(zjftInflSSYield.first,zjftInflSSYield.second,muIDErr_,eleIDErr_,zttScaleErr_));
    //printf("$Z^{ll}$ & %.2f $\\pm$ %.2f & - & %.2f $\\pm$ %.2f & - \\\\ \n", zlftInflYield.first, quadrature(zlftInflYield.first,zlftInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_),zlftInflSSYield.first,quadrature(zlftInflSSYield.first,zlftInflSSYield.second,muIDErr_,eleIDErr_,zttScaleErr_));
    //printf("$W+jets$ & %.2f $\\pm$ %.2f & %.2f $\\pm$ %.2f & %.2f $\\pm$ %.2f & %.2f $\\pm$ %.2f  \\\\ \n", osWLow.first, osWLow.second, osWHigh.first, osWHigh.second, ssWLow.first, ssWLow.second, dataSSYieldSdb.first, dataSSYieldSdb.second);
    //printf("QCD & %.2f $\\pm$ %.2f & - & %.2f $\\pm$ %.2f & - \\\\ \n", osQCD.first, osQCD.second, ssQCD.first, ssQCD.second);
    //printf("$Z\\rightarrow\\tau\\tau$ & %.2f $\\pm$ %.2f & - & - & - \\\\ \n", zttYield.first,quadrature(zttYield.first,zttYield.second,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_));
    

    float fullBackgroundErr = sqrt(pow(quadrature(output.VV,output.dVV,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_),2)
				   +pow(quadrature(output.TOP,output.dTOP,muIDErr_,eleIDErr_,tauIDErr_),2)
				   +pow(quadrature(output.ZJFT,output.dZJFT,muIDErr_,eleIDErr_,zttScaleErr_),2)
				   +pow(quadrature(output.ZLFT,output.dZLFT,muIDErr_,eleIDErr_,zttScaleErr_),2)
				   +pow(output.dQCD,2)
				   +pow(output.dW,2)
				   +pow(quadrature(output.ZTT,output.dZTT,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_),2));
    
    printf("Total Background & %.2f $\\pm$ %.2f & - & - & - \\\\ \n",background,sqrt(pow(quadrature(output.VV,    output.dVV,   muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_),2)
										     +pow(quadrature(output.TOP,  output.dTOP,  muIDErr_,eleIDErr_,tauIDErr_),2)
										     +pow(quadrature(output.ZJFT, output.dZJFT, muIDErr_,eleIDErr_,zttScaleErr_),2)
										     +pow(quadrature(output.ZLFT, output.dZLFT, muIDErr_,eleIDErr_,zttScaleErr_),2)
										     +pow(output.dQCD,2)
										     +pow(output.dW,2)
										     +pow(quadrature(output.ZTT,output.dZTT,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_),2)));
    
    
    
    //create a histogram with the error for plotting reasons and only
    TH1F *err = new TH1F("BKGErr","",1,0,1);
    err->SetBinContent(1,fullBackgroundErr/background);
    fout_->cd((channel_+prefix).c_str());
    err->Write();

    return output;

  }


   /*
    * For Inclusive take the Ztt normalization directly from MC (zttFile_)
    * For a category the Ztt normalization is as follows,
    * ZttCategoryYield = ZttMCInclusiveYield * (ZttEmbedded_Category) / *Ztt(
    */

  bool runZTT(std::string preSelection,std::string prefix,std::string zShape, float topExtrap, BkgOutput &output,
	      std::string categorySelection = "pt1>-100", std::string relaxedSelection = "pt1>-100"){

    float leg1Corr=1.0;
    if(muID_!=0) leg1Corr*=muID_;
    if(eleID_!=0) leg1Corr*=eleID_;

    //TODO: make the pdg selection cleaner Check if we are using pdg selection for fullExtrapolation

    std::pair<float,float> zttYield    = createHistogramAndShiftsFinal(zttFile_,"ZTTTMP",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+ZTT_genTauSel_
											  +")"+"*"+weight_),luminosity_*zttScale_*leg1Corr*tauID_,prefix);
    std::pair<float,float> ztt_ll      = createHistogramAndShiftsFinal(zttFile_,"ZTT_LL",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&"+ZTTLL_genTauReject_+")"+"*"+weight_),luminosity_*zttScale_*leg1Corr*tauID_,prefix);
    
    if(zShape.size()==0) {
      std::pair<float,float> zttShape  = createHistogramAndShiftsFinal(zttFile_,"ZTT",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&genTaus>0&&genVisPt2>18)*"+weight_),luminosity_*zttScale_*leg1Corr*tauID_,prefix);
    }
    else{
      //create correction factor for MT and Pzeta cuts
      std::pair<float,float> dataWCut_Before  = createHistogramAndShifts(zShape,"ZTTWCut",("("+preSelection+"&&"+osSignalSelection_+"&&genFullMass>50&&genVisPt2>18)*"+embWeight_),1.0,prefix);
      std::pair<float,float> zttShape       = createHistogramAndShifts(zShape,"ZTT",("("+preSelection+"&&"+osSignalSelection_+"&&"+categorySelection+"&&genFullMass>50&&genVisPt2>18)*"+embWeight_),1.0,prefix);

      //std::pair<float,float> mcWCut_Before    = createHistogramAndShiftsFinal(zttFile_,"ZTTWCutMC",("("+preSelection+"&&"+categorySelection+"&&"+trigSelection_+"&&genTaus>0&&genVisPt2>18&&(!((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8))))*"+weight_),luminosity_*zttScale_*leg1Corr*tauID_,prefix);

      //float corrector = (zttShape.first/dataWCut_Before.first) / (zttYield.first/mcWCut_Before.first);

      //Efficiency to go from the inclusive selection to the category selection
      float corrector = zttShape.first/dataWCut_Before.first;
      
      printf("W Cut Correction = %f \n",corrector); 
      printf("emb before events = %f \n", dataWCut_Before.first);
      printf("emb inclusive events = %f \n", zttShape.first);
      //printf("mc before events = %f \n", mcWCut_Before.first);
      printf("mc inclusive events = %f \n", zttYield.first);
      zttYield = std::make_pair(zttYield.first*corrector,zttYield.second*corrector);
      renormalizeHistogram(channel_+prefix,"ZTT",zttYield.first);
      addHistogramZTT(channel_+prefix, "ZTT", "ZTT_LL");
    }
    
    output.ZTT  = zttYield.first;
    output.dZTT = zttYield.second;

    return true;

  }


  /*
   * For now running ttbar selection is still basic control region, might change as b-tag studies progress
   */
  
  bool runTOP( std::string preSelection, std::string prefix, std::string zShape, float topExtrap, BkgOutput &output, 
	       std::string categorySelection, std::string relaxedSelection ) {

    float leg1Corr=1.0;
    if(muID_!=0) leg1Corr*=muID_;
    if(eleID_!=0) leg1Corr*=eleID_;
    
    std::pair<float,float> topShape      = createHistogramAndShiftsFinal(topFile_,"TT",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+relaxedSelection+")*"+weight_),
									 luminosity_*leg1Corr*tauID_*topExtrap,
									 prefix);

    std::pair<float,float> topYield      = createHistogramAndShiftsFinal(topFile_,"TTYield",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+")*"+weight_),
									 luminosity_*leg1Corr*tauID_*topExtrap,
									 prefix);

    renormalizeHistogram(channel_+prefix,"TT",topYield.first);

    std::pair<float,float> topInflYield  = inflateError(topYield,topErr_);

    output.TOP  = topInflYield.first;
    output.dTOP = topInflYield.second;

    //Subtract the ztt ttbar overlap of 1.5% from the ttbar yield
    output.TOP = output.TOP-(output.ZTT*0.015);    
    renormalizeHistogram(channel_+prefix,"TT",output.TOP);

    printf("TTbar events in signal region = %f + %f \n",topInflYield.first,topInflYield.second);

    return true;
  }
  

  //Create ttbar
  //bool runTTBAR(std::string preSelection,std::string prefix,std::string zShape, float topExtrap, BkgOutput &output) {
    //create TTbar
    //std::pair<float,float> topYield       = createHistogramAndShiftsFinal(topFile_,"TT",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*leg1Corr*tauID_*topExtrap,prefix);

    //return true;
  //}
  

  /*
   * To run QCD we take the shape and yield from the Same-Sign Control region, 
   * where the lepton and tau are required to be like signs, this gives a control 
   * region which is orthogonal to the signal region. We first create the QCD shape
   * and subtract off the largest contributors of background from that shape. Next
   * the yield estimation is performed. This yield estimate should be more stringent
   * about subtracting off of backgrounds. It also uses the High MT SS region to
   * estimate the W Yield contribution this high mt region does need to have the MC 
   * bkgds subtracted off as well. 
   * 
   * Note: QCD distribution in SS control region does not entirely match the 
   *       distribution in the signal region, see SM studies from Jan and Yuta.
   *       This requires a QCD shape systematic.
   *	   A factor of 1.06 is applied when going from the SS to OS
   */
  
  bool runQCD(std::string preSelection, std::string prefix, std::string zShape, float topExtrap, BkgOutput &output, std::string categorySelection, std::string relaxedSelection) 
  {
    float leg1Corr=1.0;
    if(muID_!=0) leg1Corr*=muID_;
    if(eleID_!=0) leg1Corr*=eleID_;

    //create QCD shape from data and subtract off major contributors
    std::pair<float,float> dataQCDControl = createHistogramAndShifts(dataFile_,"QCD","("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+categorySelection+")",scaleUp_,prefix);
    std::pair<float,float> zllQCDControl  = createHistogramAndShifts(zllFile_,"ZLLQCD","("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+categorySelection+")*ZeFakeTau*"+weight_,luminosity_*leg1Corr*zttScale_,prefix);
    std::pair<float,float> ttQCDControl   = createHistogramAndShifts(topFile_,"TOPQCD","("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+categorySelection+")*"+weight_,luminosity_*leg1Corr*tauID_*topExtrap,prefix);
    std::pair<float,float> wShapeSS       = createHistogramAndShifts(wFile_,"WQCD",("("+preSelection+"&&"+ssSignalSelection_+"&&"+categorySelection+")*"+weight_),luminosity_*leg1Corr,prefix,false);

    //create same sign W side band yields
    std::pair<float,float> dataSSYSdb = createHistogramAndShifts(dataFile_,"data_obs_ss_sdb","("+preSelection+"&&"+trigSelection_+"&&"+ssWSelection_+"&&"+categorySelection+")",scaleUp_,prefix);
    std::pair<float,float> dataSSYieldSdb = convertToPoisson(dataSSYSdb);
    printf("Data events in SS sideband region = %f + %f \n",dataSSYieldSdb.first,dataSSYieldSdb.second);

    std::pair<float,float> topSSYieldSdb    = createHistogramAndShifts(topFile_,"TTSS_SDB",("("+preSelection+"&&"+trigSelection_+"&&"+ssWSelection_+"&&"+categorySelection+")*"+weight_),luminosity_*leg1Corr*tauID_*topExtrap,prefix);
    std::pair<float,float> topInflSSYieldSdb  = inflateError(topSSYieldSdb,topErr_);
    printf("TTbar events in SS sideband region = %f + %f \n",topSSYieldSdb.first,topInflSSYieldSdb.second);
  
    std::pair<float,float> zSSYieldSdb    = createHistogramAndShifts(zllFile_,"ZSS_SDB",("("+preSelection+"&&"+trigSelection_+"&&"+ssWSelection_+"&&"+categorySelection+")*ZeFakeTau*"+weight_),luminosity_*leg1Corr*tauID_,prefix);      
    printf("Z events in SS sideband region = %f + %f \n",zSSYieldSdb.first,zSSYieldSdb.second);

    std::pair<float,float> vvSSYieldSdb   = createHistogramAndShifts(vvFile_,"VVSS_SDB",("("+preSelection+"&&"+trigSelection_+"&&"+ssWSelection_+"&&"+categorySelection+")*"+weight_),luminosity_*leg1Corr*tauID_,prefix);
    printf("VV events in SS sideband region = %f + %f \n",vvSSYieldSdb.first,vvSSYieldSdb.second);

    std::pair<float,float> wFactor = extractWFactor(wFile_,preSelection+"&&"+trigSelection_+"&&"+categorySelection,prefix,osWSelection_,osSignalSelection_);
    printf("W extrapolation factor as measured in corrected MC = %f +- %f\n",wFactor.first,wFactor.second);

    printf("3. Repeat W estimation for SS : first subtract ttbar, Z and vv from data\n");

    std::pair<float,float> ssWHigh = std::make_pair(TMath::Nint(dataSSYieldSdb.first
								-topInflSSYieldSdb.first
								-zSSYieldSdb.first
								-vvSSYieldSdb.first),
						      sqrt(dataSSYieldSdb.second*dataSSYieldSdb.second
							   +topInflSSYieldSdb.second*topInflSSYieldSdb.second
							   +zSSYieldSdb.second*zSSYieldSdb.second
							   +vvSSYieldSdb.second*vvSSYieldSdb.second));

    std::pair<float,float> ssWLow = std::make_pair(ssWHigh.first*wFactor.first,
						   sqrt(ssWHigh.second*ssWHigh.second*wFactor.first*wFactor.first+wFactor.second*wFactor.second*ssWHigh.first*ssWHigh.first));
  
    printf("W events in SS region = %f + %f \n",ssWLow.first,ssWLow.second);
    renormalizeHistogram(channel_+prefix,"WQCD",ssWLow.first);

   //Now subtracting off bkgd shapes from data ss shape
    subtractHistogram(channel_+prefix,"QCD","ZLLQCD");
    subtractHistogram(channel_+prefix,"QCD","TOPQCD");
    subtractHistogram(channel_+prefix,"QCD","WQCD");

    //SS Yield Estimate
    std::pair<float,float> dataSSY         = createHistogramAndShifts(dataFile_,"data_obs_ss","("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+categorySelection+")",scaleUp_,prefix);
    std::pair<float,float> dataSSYield     = convertToPoisson(dataSSY);

    std::pair<float,float> zlftSSYield     = createHistogramAndShifts(zllFile_,"ZL_SS",("("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+categorySelection+"&&"+ZLFT_genLSel_+")*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zttScale_,prefix);
    std::pair<float,float> zlftInflSSYield = inflateError(zlftSSYield,zlftErr_);
    printf("Z (l->tau) in SS region = %f + %f \n",zlftInflSSYield.first,zlftInflSSYield.second);

    std::pair<float,float> zjftSSYield     = createHistogramAndShifts(zllFile_,"ZJ_SS",("("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+categorySelection+"&&"+ZJFT_genLReject_+")*"+weight_),luminosity_*leg1Corr*zttScale_,prefix,false);    
    std::pair<float,float> zjftInflSSYield = inflateError(zjftSSYield,zjftErr_);
    printf("Z (j->tau) in SS region = %f + %f \n",zjftInflSSYield.first,zjftInflSSYield.second);

    std::pair<float,float> topSSYield      = createHistogramAndShifts(topFile_,"TTSS",("("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+categorySelection+")*"+weight_),luminosity_*leg1Corr*tauID_*topExtrap,prefix);
    std::pair<float,float> topInflSSYield  = inflateError(topSSYield,topErr_);
    printf("TTbar events in SS signal region = %f + %f \n",topInflSSYield.first,topInflSSYield.second);

    //TODO:Check me, genpt selection?
    std::pair<float,float> zttSS   	   = createHistogramAndShifts(zttFile_,"ZTT_SS",("("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+categorySelection+"&&"+ZTT_genTauSel_+")*"+weight_),luminosity_*zttScale_*leg1Corr*tauID_,prefix);
    //std::pair<float,float> zttSS   	   = createHistogramAndShifts(zttFile_,"ZTT_SS",("("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&genTaus>0&&genVisPt2>18)*"+weight_),luminosity_*zttScale_*leg1Corr*tauID_,prefix);
    printf("Z-->tautau events in SS signal region = %f + %f \n",zttSS.first,zttSS.second);
  
    std::pair<float,float> vvYieldSS       = createHistogramAndShifts(vvFile_,"VV_SS",("("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+categorySelection+")*"+weight_),luminosity_*leg1Corr*tauID_,prefix);
    printf("VV events in SS signal region = %f + %f \n",vvYieldSS.first,vvYieldSS.second);

    printf("4. From all SS events subtract W and Z jet fakes tau/TTbar to get QCD \n");

    std::pair<float,float> ssQCD = std::make_pair(TMath::Nint(dataSSYield.first
							      -ssWLow.first
							      -zlftInflSSYield.first
							      -zjftInflSSYield.first
							      -topInflSSYield.first
							      -zttSS.first
							      -vvYieldSS.first),
						  sqrt(dataSSYield.second*dataSSYield.second
						       +ssWLow.second*ssWLow.second
						       +zlftInflSSYield.second*zlftInflSSYield.second
						       +zjftInflSSYield.second*zjftInflSSYield.second
						       +topInflSSYield.second*topInflSSYield.second
						       +zttSS.second*zttSS.second
						       +vvYieldSS.second*vvYieldSS.second));

    // In case the yield is less than 0 set to 0 so that there is no 'negative' contribution in datacards

    if(ssQCD.first<0) {
      ssQCD.first=0.0000001;
      ssQCD.second=1.8;
    }
      
    printf("SS QCD in  core  =%f -%f -%f -%f -%f -%f -%f= %f +- %f \n",
	   dataSSYield.first,
	   ssWLow.first,
	   zjftInflSSYield.first,
	   zlftInflSSYield.first,
	   topInflSSYield.first,
	   zttSS.first,
	   vvYieldSS.first,
	   ssQCD.first,
	   ssQCD.second);
    
    printf("5. Extrapolate SS QCD -> OS QCD \n");
    std::pair<float,float> osQCD = std::make_pair(ssQCD.first*qcdFactor_,
						  sqrt(ssQCD.second*ssQCD.second*qcdFactor_*qcdFactor_
						       +qcdFactorErr_*qcdFactorErr_*ssQCD.first*ssQCD.first));

    //Now Renormalize
    renormalizeHistogram(channel_+prefix,"QCD",osQCD.first);

    printf("OS QCD in  core  =%f *%f = %f +- %f \n",ssQCD.first,qcdFactor_,osQCD.first,osQCD.second);

    output.QCD  = osQCD.first;    
    output.dQCD = osQCD.second;

    if(shifts_.size()>0){
      qcdSyst(channel_, prefix, "QCD", 1.1, 0.1);
    }

    return true;
  }
  


  bool runW(std::string preSelection,std::string prefix,std::string zShape, float topExtrap, BkgOutput &output, std::string categorySelection, std::string relaxedSelection) {

    float leg1Corr=1.0;
    if(muID_!=0) leg1Corr*=muID_;
    if(eleID_!=0) leg1Corr*=eleID_;

    //make shape
    //TODO: Check need wextrap factor???? 
    std::pair<float,float> wShape         = createHistogramAndShiftsFinal(wFile_,"W",("("+preSelection+"&&"+osSignalSelection_+"&&"+categorySelection+")*"+weight_),luminosity_*leg1Corr,prefix,false);
    if(shifts_.size()>0){
      std::pair<float,float> wShapeUp = createHistogramAndShiftsFinal(wFile_,"WShapeUp",("("+preSelection+"&&"+osSignalSelection_+"&&"+btagRelaxedSelection_+")*__WEIGHT__*__CORR__*WWeightUp"),luminosity_*leg1Corr,prefix,false,false);
      std::pair<float,float> wShapeDown = createHistogramAndShiftsFinal(wFile_,"WShapeDown",("("+preSelection+"&&"+osSignalSelection_+"&&"+btagRelaxedSelection_+")*__WEIGHT__*__CORR__*WWeightDown"),luminosity_*leg1Corr,prefix,false,false);
    }

    //First get data in Sideband
    std::pair<float,float> dataYSdb     = createHistogramAndShiftsFinal(dataFile_,"data_obs_sdb","("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+osWSelection_+")",scaleUp_,prefix);
    std::pair<float,float> dataYieldSdb = convertToPoisson(dataYSdb);

    //then get ttbar in sideband
    std::pair<float,float> topYieldSdb      = createHistogramAndShiftsFinal(topFile_,"TT_SDB",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+osWSelection_+")*"+weight_),luminosity_*leg1Corr*tauID_*topExtrap,prefix);
    std::pair<float,float> topInflYieldSdb  = inflateError(topYieldSdb,topErr_);
    printf("TTbar events in sideband region = %f + %f \n",topYieldSdb.first,topInflYieldSdb.second);

    //Next get Diboson in sideband
    std::pair<float,float> vvYieldSdb      = createHistogramAndShiftsFinal(vvFile_,"VV_SDB",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+osWSelection_+")*"+weight_),luminosity_*leg1Corr*tauID_,prefix);
    std::pair<float,float> vvInflYieldSdb  = inflateError(vvYieldSdb,vvErr_);
    printf("Diboson events in sideband region = %f + %f \n",vvYieldSdb.first,vvInflYieldSdb.second);

    //finally get Z in sideband
    std::pair<float,float> zSDB    	   = createHistogramAndShiftsFinal(zttFile_,"Z_SDB",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+osWSelection_+")*"+weight_),luminosity_*zttScale_*leg1Corr*tauID_,prefix);
    printf("Z events in sideband region = %f + %f \n",zSDB.first,zSDB.second);

    //Run OS+LS + MT method
    printf("1. Subtract TTbar and diboson from sideband");
    std::pair<float,float> osWHigh = std::make_pair(TMath::Nint(dataYieldSdb.first
								-topInflYieldSdb.first
								-vvInflYieldSdb.first
								-zSDB.first),
						    sqrt(dataYieldSdb.second*dataYieldSdb.second
							 +topInflYieldSdb.second*topInflYieldSdb.second
							 +vvInflYieldSdb.second*vvInflYieldSdb.second
							 +zSDB.second*zSDB.second));

    printf("OS W in sideband  =%f -%f -%f -%f  = %f +- %f \n",dataYieldSdb.first,topInflYieldSdb.first,vvInflYieldSdb.first,zSDB.first,osWHigh.first,osWHigh.second);

    std::pair<float,float> wFactor = extractWFactor(wFile_,preSelection+"&&"+trigSelection_+"&&"+categorySelection,prefix,osWSelection_,osSignalSelection_);
    printf("W extrapolation factor as measured in corrected MC = %f +- %f\n",wFactor.first,wFactor.second);

    std::pair<float,float> wFactorUp = extractWFactor(wFile_,preSelection+"&&"+trigSelection_+"&&charge==0&&"+btagRelaxedSelection_+"",prefix,"WWeightUp");
    std::pair<float,float> wFactorDown = extractWFactor(wFile_,preSelection+"&&"+trigSelection_+"&&charge==0&&"+btagRelaxedSelection_+"",prefix,"WWeightDown");
     
    printf("2. Extrapolate W in the low MT region\n");
    std::pair<float,float> osWLow = std::make_pair(osWHigh.first*wFactor.first,
						     sqrt(osWHigh.first*osWHigh.first*wFactor.second*wFactor.second+osWHigh.second*osWHigh.second*wFactor.first*wFactor.first));
      
    printf("OS W  in core  =%f *%f  = %f +- %f \n",osWHigh.first,wFactor.first,osWLow.first,osWLow.second);
    renormalizeHistogram(channel_+prefix,"W",osWLow.first);

    std::pair<float,float> wMCYield       = createHistogramAndShiftsFinal(wFile_,"WTMP",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+")*"+weight_),luminosity_*leg1Corr,prefix,false);

    if(shifts_.size()>0){

      std::string chan = "mutau";
      if(channel_=="eleTau") chan = "etau";

      std::pair<float,float> wYieldUp;
      std::pair<float,float> wYieldDown;
      wYieldUp = std::make_pair(osWHigh.first*wFactorUp.first,
				sqrt(osWHigh.first*osWHigh.first*wFactor.second*wFactor.second+osWHigh.second*osWHigh.second*wFactor.first*wFactor.first));
      wYieldDown = std::make_pair(osWHigh.first*wFactorDown.first,
				  sqrt(osWHigh.first*osWHigh.first*wFactor.second*wFactor.second+osWHigh.second*osWHigh.second*wFactor.first*wFactor.first));
      renormalizeHistogram(channel_+prefix,"WShapeUp",wYieldUp.first);
      renameHist(channel_+prefix,"W_CMS_htt_WShape_"+chan+prefix+"_8TeVUp","WShapeUp");
      renormalizeHistogram(channel_+prefix,"WShapeDown",wYieldDown.first);   
      renameHist(channel_+prefix,"W_CMS_htt_WShape_"+chan+prefix+"_8TeVDown","WShapeDown");
    }

    output.W  = osWLow.first;
    output.dW = osWLow.second;

    return true;
  }


  //-------------Helper Functions------------------


  //TODO:Add in other helper functions

  void addHistogramZTT(std::string folder, std::string histo1, std::string histo2)
  {
		addHistogram(folder,histo1,histo2);
		for(unsigned int i=0;i<shifts_.size();++i) {
			addHistogram(folder,(histo1+"_"+shiftsPostFix_[i]+"Up").c_str(),histo2);
			addHistogram(folder,(histo1+"_"+shiftsPostFix_[i]+"Down").c_str(),histo2);
		}		
  }

  std::pair<float,float> createHistogramAndShifts(std::string file,std::string name, std::string cut,float scaleFactor = 1, std::string postfix = "",bool normUC  = true, bool keys=false,bool ShapeUncertainty=true) {
    TFile *f  = new TFile(file.c_str());
    if(f==0) printf("Not file Found\n");
    //get the nominal tree first
    TTree *t= (TTree*)f->Get((channel_+"EventTree/eventTree").c_str());
    if(t==0) printf("Not Tree Found in file %s\n",file.c_str());

    std::pair<float,float> yield;

    if(!keys)
      yield =makeHistogram(t,channel_+postfix,name,cut,scaleFactor);
    else
      yield =makeTHKeys(t,channel_+postfix,name,cut,scaleFactor);

    //now the shifts
    std::pair<float,float> tmpYield;
    for(unsigned int i=0;i<shifts_.size();++i) {

      TTree *ts= (TTree*)f->Get((channel_+"EventTree"+shifts_[i]+"Up/eventTree").c_str());
      if(ts!=0) {
	if(!keys)
	  tmpYield = makeHistogram(ts,channel_+postfix,name+"_"+shiftsPostFix_[i]+"Up",cut,scaleFactor);
	else
	  tmpYield = makeTHKeys(ts,channel_+postfix,name+"_"+shiftsPostFix_[i]+"Up",cut,scaleFactor);

	if(!normUC)
	  scaleHistogram(channel_+postfix,name+"_"+shiftsPostFix_[i]+"Up",yield.first/tmpYield.first);

      }
      TTree *td= (TTree*)f->Get((channel_+"EventTree"+shifts_[i]+"Down/eventTree").c_str());
      if(td!=0) {
	if(!keys)
	  tmpYield = makeHistogram(td,channel_+postfix,name+"_"+shiftsPostFix_[i]+"Down",cut,scaleFactor);
	else
	  tmpYield = makeTHKeys(td,channel_+postfix,name+"_"+shiftsPostFix_[i]+"Down",cut,scaleFactor);

	if(!normUC)
	  scaleHistogram(channel_+postfix,name+"_"+shiftsPostFix_[i]+"Down",yield.first/tmpYield.first);

      }
    }
    f->Close();
    return yield;
  }
  

  std::pair<float,float> createHistogramAndShiftsFinal(std::string file,std::string name, std::string cut,float scaleFactor = 1, std::string postfix = "",bool normUC  = true, bool keys=false,bool ShapeUncertainty=true) {
    TFile *f  = new TFile(file.c_str());
    if(f==0) printf("Not file Found\n");
    //get the nominal tree first
    TTree *t= (TTree*)f->Get((channel_+"EventTreeFinal/eventTree").c_str());
    if(t==0) printf("Not Tree Found in file %s\n",file.c_str());

    std::pair<float,float> yield;

    if(!keys)
      yield =makeHistogram(t,channel_+postfix,name,cut,scaleFactor);
    else
      yield =makeTHKeys(t,channel_+postfix,name,cut,scaleFactor);

    //now the shifts
    std::pair<float,float> tmpYield;
    for(unsigned int i=0;i<shifts_.size();++i) {

      TTree *ts= (TTree*)f->Get((channel_+"EventTreeFinal"+shifts_[i]+"Up/eventTree").c_str());
      if(ts!=0) {
	if(!keys)
	  tmpYield = makeHistogram(ts,channel_+postfix,name+"_"+shiftsPostFix_[i]+"Up",cut,scaleFactor);
	else
	  tmpYield = makeTHKeys(ts,channel_+postfix,name+"_"+shiftsPostFix_[i]+"Up",cut,scaleFactor);

	if(!normUC)
	  scaleHistogram(channel_+postfix,name+"_"+shiftsPostFix_[i]+"Up",yield.first/tmpYield.first);

      }
      TTree *td= (TTree*)f->Get((channel_+"EventTreeFinal"+shifts_[i]+"Down/eventTree").c_str());
      if(td!=0) {
	if(!keys)
	  tmpYield = makeHistogram(td,channel_+postfix,name+"_"+shiftsPostFix_[i]+"Down",cut,scaleFactor);
	else
	  tmpYield = makeTHKeys(td,channel_+postfix,name+"_"+shiftsPostFix_[i]+"Down",cut,scaleFactor);

	if(!normUC)
	  scaleHistogram(channel_+postfix,name+"_"+shiftsPostFix_[i]+"Down",yield.first/tmpYield.first);

      }
    }
    f->Close();
    return yield;
  }


  void setBinning(const std::vector<double>& binning) {
    binning_ = binning;
  }

  std::pair<float,float> inflateError(std::pair<float,float> input,float error, float error2 =0.0, float error3 = 0.0 ) {
      float value = input.first;
      float err = sqrt(input.second*input.second+(input.first*error)*(input.first*error)+(input.first*error2)*(input.first*error2)+(input.first*error3)*(input.first*error3));
      
      if(err>value) {
	err=0.99*value;
	printf("Found error above value -> Setting error to value\n");
      }

      return std::make_pair(value,err);
    }

  void renormalizeHistogram(std::string folder, std::string histo, float yield)
  {
    
    TH1F * h =(TH1F*) fout_->Get((folder+"/"+histo).c_str());
    double scaleFactor = yield/h->Integral();


    h->Scale(scaleFactor);
    fout_->cd(folder.c_str());
    h->Write(h->GetName(),TObject::kOverwrite);

    for(unsigned int i=0;i<shifts_.size();++i) {
      TH1F * hh =(TH1F*) fout_->Get((folder+"/"+histo+"_"+shiftsPostFix_[i]+"Up").c_str());
      if(hh!=0) {
	hh->Scale(scaleFactor);
	fout_->cd(folder.c_str());
	hh->Write(hh->GetName(),TObject::kOverwrite);
      }
      else
	{
	  printf("Shift not found = %s\n",(folder+"/"+histo+"_"+shiftsPostFix_[i]+"Up").c_str());
	}


      TH1F * hhh =(TH1F*) fout_->Get((folder+"/"+histo+"_"+shiftsPostFix_[i]+"Down").c_str());
      if(hhh!=0) {
	hhh->Scale(scaleFactor);
	fout_->cd(folder.c_str());
	hhh->Write(hhh->GetName(),TObject::kOverwrite);
      }
      else
	{
	  printf("Shift not found\n");
	  }
    }
  }

  float quadrature(float value, float error, float e0 = 0.0, float e1 = 0.0 ,float e2 = 0.0, float e3 = 0.0 ,float e4 = 0.0, float e5 = 0.0 ){
    float returnValue = sqrt(error*error+(e0*e0+e1*e1+e2*e2+e3*e3+e4*e4+e5*e5)*value*value);
    return returnValue;
  }

std::pair<float,float> makeHistogram(TTree* tree,std::string folder,std::string name,std::string cut,float scaleFactor = 1.) {

   if(fout_->Get(folder.c_str())==0)
     fout_->mkdir(folder.c_str());
     TH1F *h=0;

     TString variableOld_=variable_;
     if((name=="data_obs"||name=="data_obs_ss"||name=="data_obs_sdb"||name=="data_obs_ss_sdb"||name=="QCD")&&variable_=="pt2ES"){
       variable_="pt2";
     }


     if(binning_.size()==0)
       h= new TH1F(name.c_str(),name.c_str(),bins_,min_,max_);
     else 
       h = new TH1F(name.c_str(),name.c_str(),binning_.size()-1,&binning_[0]);
     h->Sumw2();

     tree->Draw((variable_+">>"+name).c_str(),cut.c_str());

     variable_=variableOld_;//

     h->Scale(scaleFactor);

     if(verbose_>0)
       std::cout<< " " <<name<<": "<<h->Integral()<<std::endl;

     //     printf("Created Histogram %s with entries=%f\n",name.c_str(),h->Integral());
    fout_->cd(folder.c_str());

     Double_t error=0.0;
     float yield = h->IntegralAndError(1,h->GetNbinsX(),error,"");
     if(yield == 0){
     	h->SetBinContent(1,0.00001);
     }
     h->Write(h->GetName(),TObject::kOverwrite);

     return std::make_pair(yield,error);
  }


  void close() {
    fout_->Close();
  }


  std::pair<float,float> makeTHKeys(TTree* tree,std::string folder,std::string name,std::string cut,float scaleFactor = 1.) {

   if(fout_->Get(folder.c_str())==0)
     fout_->mkdir(folder.c_str());

     TH1Keys *h=0;

     if(binning_.size()==0)
       h= new TH1Keys("tmp","tmp",bins_,min_,max_,"a",0.5);
     else 
       h = new TH1Keys("tmp","tmp",binning_.size()-1,&binning_[0],"a",0.5);
     tree->Draw((variable_+">>tmp").c_str(),cut.c_str());
     
     if(h->Integral()==0.000) {
       printf("Keys for %s failed, retrying\n",name.c_str());
       delete h;
     if(binning_.size()==0)
       h= new TH1Keys("tmp","tmp",bins_,min_,max_,"a",0.5);
     else 
       h = new TH1Keys("tmp","tmp",binning_.size()-1,&binning_[0],"a",0.5);
     tree->Draw((variable_+">>tmp").c_str(),cut.c_str());

     if(h->Integral()==0.0) {
       printf("KEYS FAILED AGAIN \n");
       
     }
     }

     //now get the yield
     TH1F *hh=0;
     if(binning_.size()==0)
       hh= new TH1F("tmp2",name.c_str(),bins_,min_,max_);
     else 
       hh = new TH1F("tmp2",name.c_str(),binning_.size()-1,&binning_[0]);
     tree->Draw((variable_+">>tmp2").c_str(),cut.c_str());
     hh->Scale(scaleFactor);
     Double_t error=0.0;
     float yield = hh->IntegralAndError(1,hh->GetNbinsX(),error,"");
     
     fout_->cd(folder.c_str());
     TH1F * histo =(TH1F*) h->GetHisto();
     histo->Scale(yield/histo->Integral());
     histo->SetName(name.c_str());
     histo->Write();


     delete h;
     delete hh;

     return std::make_pair(yield,error);
  }

  std::pair<float,float> createHistogramShifted(std::string file,std::string name, std::string cut,std::string shift,float scaleFactor = 1, std::string postfix = "") {
    TFile *f  = new TFile(file.c_str());
    if(f==0) printf("Not file Found\n");
    //get the nominal tree first
    TTree *t= (TTree*)f->Get((channel_+"EventTreeFinal/eventTree").c_str());
    if(t==0) printf("Not Tree Found in file %s\n",file.c_str());

    std::pair<float,float> yield;

    yield =makeHistogramShifted(t,channel_+postfix,name,cut,shift,scaleFactor);

    f->Close();
    return yield;
  }

  std::pair<float,float> makeHistogramShifted(TTree* tree,std::string folder,std::string name,std::string cut, std::string shift,float scaleFactor = 1.) {

   if(fout_->Get(folder.c_str())==0)
     fout_->mkdir(folder.c_str());
     TH1F *h=0;

     if(binning_.size()==0)
       h= new TH1F(name.c_str(),name.c_str(),bins_,min_,max_);
     else 
       h = new TH1F(name.c_str(),name.c_str(),binning_.size()-1,&binning_[0]);
     h->Sumw2();


     tree->Draw((variable_+"*"+shift+">>"+name).c_str(),cut.c_str());

     h->Scale(scaleFactor);
     //     printf("Created Histogram %s with entries=%f\n",name.c_str(),h->Integral());
    fout_->cd(folder.c_str());

     Double_t error=0.0;
     float yield = h->IntegralAndError(1,h->GetNbinsX(),error,"");
     if(yield == 0){
     	h->SetBinContent(1,0.00001);
     }
     h->Write(h->GetName(),TObject::kOverwrite);

     return std::make_pair(yield,error);
  }

  void scaleHistogram(std::string folder, std::string histo, float scaleFactor)
  {
    TH1F * h =(TH1F*) fout_->Get((folder+"/"+histo).c_str());
    h->Scale(scaleFactor);
    fout_->cd(folder.c_str());
    h->Write(h->GetName(),TObject::kOverwrite);
    fout_->cd();

    for(unsigned int i=0;i<shifts_.size();++i) {
      TH1F * hh =(TH1F*) fout_->Get((folder+"/"+histo+"_"+shiftsPostFix_[i]+"Up").c_str());
      if(hh!=0) {
	hh->Scale(scaleFactor);
	fout_->cd(folder.c_str());
	hh->Write(hh->GetName(),TObject::kOverwrite);
	fout_->cd();
      }

      TH1F * hhh =(TH1F*) fout_->Get((folder+"/"+histo+"_"+shiftsPostFix_[i]+"Down").c_str());
      if(hhh!=0) {
	hhh->Scale(scaleFactor);
	fout_->cd(folder.c_str());
	hhh->Write(hhh->GetName(),TObject::kOverwrite);
	fout_->cd();
      }
      
    }
  }
  

  
  std::pair<float,float> extractWFactor(std::string file,std::string preselection,std::string postfix, std::string Wweight = "1") {
    TFile *f  = new TFile (file.c_str());
    TTree *t = (TTree*)f->Get((channel_+"EventTree/eventTree").c_str());

	std::pair<float,float> high;
	std::pair<float,float> low;
	
	high = makeHistogram(t,channel_+postfix,"W_High",("("+preselection+"&&"+wSelection_+")*"+weight_+"*"+Wweight).c_str());
	low = makeHistogram(t,channel_+postfix,"W_Low",("("+preselection+"&&"+signalSelection_+")*"+weight_+"*"+Wweight).c_str());

    float factor = low.first/high.first;
    float factorerrStat = sqrt(low.second*low.second + high.second*high.second);
    float factorerrSyst = factor*wFactorErr_;
    float factorErr = sqrt(factorerrStat*factorerrStat+factorerrSyst*factorerrSyst);

    return std::make_pair(factor,factorErr);   

  }

  std::pair<float,float> extractWFactorFinal(std::string file,std::string preselection,std::string postfix, std::string Wweight = "1") {
    TFile *f  = new TFile (file.c_str());
    TTree *t = (TTree*)f->Get((channel_+"EventTreeFinal/eventTree").c_str());

	std::pair<float,float> high;
	std::pair<float,float> low;
	
	high = makeHistogram(t,channel_+postfix,"W_High",("("+preselection+"&&"+wSelection_+")*"+weight_+"*"+Wweight).c_str());
	low = makeHistogram(t,channel_+postfix,"W_Low",("("+preselection+"&&"+signalSelection_+")*"+weight_+"*"+Wweight).c_str());

    float factor = low.first/high.first;
    float factorerrStat = sqrt(low.second*low.second + high.second*high.second);
    float factorerrSyst = factor*wFactorErr_;
    float factorErr = sqrt(factorerrStat*factorerrStat+factorerrSyst*factorerrSyst);

    return std::make_pair(factor,factorErr);   

  }
  
  std::pair<float,float> extractWFactor(std::string file, std::string preselection, std::string postfix, std::string wSel, std::string sigSel) {
    TFile *f  = new TFile (file.c_str());
    TTree *t = (TTree*)f->Get((channel_+"EventTree/eventTree").c_str());

	std::pair<float,float> high;
	std::pair<float,float> low;
	
	high = makeHistogram(t,channel_+postfix,"W_High",("("+preselection+"&&"+wSel+")*"+weight_).c_str());
	low = makeHistogram(t,channel_+postfix,"W_Low",("("+preselection+"&&"+sigSel+")*"+weight_).c_str());

    float factor = low.first/high.first;
    float factorerrStat = sqrt(low.second*low.second + high.second*high.second);
    float factorerrSyst = factor*wFactorErr_;
    float factorErr = sqrt(factorerrStat*factorerrStat+factorerrSyst*factorerrSyst);

    return std::make_pair(factor,factorErr);   

  }

  void mergeHistogram(std::string folder, std::string histo1, std::string histo2, std::string newName)
  {
    TH1F * h1 =(TH1F*) fout_->Get((folder+"/"+histo1).c_str());
    TH1F * h2 =(TH1F*) fout_->Get((folder+"/"+histo2).c_str());
  	TH1F *hNew =(TH1F*) h1->Clone(TString(newName));
    hNew->Add(h2,1.);

    for(int i=1;i<h1->GetNbinsX();++i){
      if(h1->GetBinContent(i)<0){
		h1->SetBinContent(i,0.00001);
		h1->SetBinError(i,1.0);
	  }
	}

    fout_->cd(folder.c_str());
    hNew->Write(TString(newName),TObject::kOverwrite);
  }
  
   std::pair<float,float> convertToPoisson(std::pair<float,float> measurement) {
    float yield = measurement.first;
    float CLHi = TMath::ChisquareQuantile(1-0.32/2,2*yield+2)/2.;
    float CLLo = TMath::ChisquareQuantile(0.32/2,2*yield)/2.;
    printf("Yield =%f Lo=%f Hi=%f\n",measurement.first,CLLo,CLHi);
    return std::make_pair(measurement.first,(CLHi-CLLo)/2.);

  }
  	
  void subtractHistogram(std::string folder, std::string histo1, std::string histo2)
  {
    TH1F * h1 =(TH1F*) fout_->Get((folder+"/"+histo1).c_str());
    TH1F * h2 =(TH1F*) fout_->Get((folder+"/"+histo2).c_str());
    h1->Add(h2,-1.);

    for(int i=1;i<h1->GetNbinsX();++i){
      if(h1->GetBinContent(i)<0){
		h1->SetBinContent(i,0.00001);
		h1->SetBinError(i,1.0);
	  }
	}

    fout_->cd(folder.c_str());
    h1->Write(h1->GetName(),TObject::kOverwrite);
  }
  
  void addHistogram(std::string folder, std::string histo1, std::string histo2)
  {
    TH1F * h1 =(TH1F*) fout_->Get((folder+"/"+histo1).c_str());
    TH1F * h2 =(TH1F*) fout_->Get((folder+"/"+histo2).c_str());
    h1->Add(h2,1.);

    fout_->cd(folder.c_str());
    h1->Write(h1->GetName(),TObject::kOverwrite);
  }

  void renameHist(std::string folder, std::string name ,std::string histo1)///folder, new name, old name
  {
    TH1F * h1 =(TH1F*) fout_->Get((folder+"/"+histo1).c_str());
    TH1F * h2 = (TH1F*) h1->Clone(TString(name));

    h2->Write(h2->GetName(),TObject::kOverwrite);
  }


  void FixNegativeBins(std::string folder, std::string histo, bool is_qcd, bool verbose=false) {
  
  	 TH1F * hist =(TH1F*) fout_->Get((folder+"/"+histo).c_str());
	 unsigned bins = hist->GetNbinsX();
	 for (unsigned i = 1; i <= bins; ++i) {
	   if (hist->GetBinContent(i) < 0.){
	     hist->SetBinContent(i,0);
	     if(verbose)
	       std::cout<<"Bin "<< i << " is negative, setting to 0"<<std::endl;
	   }
	 }
	 hist->Write(hist->GetName(),TObject::kOverwrite);
  }

  void FixNegativeBinsMC(std::string folder, std::string histo, bool is_qcd, bool verbose=false){
  		
  		FixNegativeBins(folder, histo, is_qcd, verbose);
  		
  		for(unsigned int i=0;i<shifts_.size();++i) {
		  TH1F * hh =(TH1F*) fout_->Get((folder+"/"+histo+"_"+shiftsPostFix_[i]+"Up").c_str());
		  if(hh!=0) {
		    FixNegativeBins(folder, (histo+"_"+shiftsPostFix_[i]+"Up").c_str(), is_qcd, verbose);
		  }
		  
		  TH1F * hhh =(TH1F*) fout_->Get((folder+"/"+histo+"_"+shiftsPostFix_[i]+"Down").c_str());
		  if(hhh!=0) {
		  FixNegativeBins(folder, (histo+"_"+shiftsPostFix_[i]+"Down").c_str(), is_qcd, verbose);
		  }
		  
  		}
  }

  
  void FixEmptyBins(std::string folder, std::string histo, bool is_qcd, bool verbose=false) {
  
  	 TH1F * hist =(TH1F*) fout_->Get((folder+"/"+histo).c_str());
	 unsigned bins = hist->GetNbinsX();
	 unsigned first_populated = 0;
	 unsigned last_populated = 0;
	 for (unsigned i = 1; i <= bins; ++i) {
	   if (hist->GetBinContent(i) > 0. && first_populated == 0) first_populated = i;
	   if (hist->GetBinContent(bins-(i-1)) > 0. && last_populated == 0) last_populated = bins-(i-1);
	 }
	 if (last_populated <= first_populated) {
	   if (verbose) std::cout << "Cannot correct this distribution!" << std::endl;
	   return;
	 }
	 if (verbose) std::cout << "First populated bin: " << first_populated << std::endl;
	 if (verbose) std::cout << "Last populated bin: " << last_populated << std::endl;
	 double av_weight = ( hist->Integral() / double(hist->GetEntries()));
	 if (!is_qcd) {
	   if (verbose) std::cout << "Integral: " << hist->Integral() << std::endl;
	   if (verbose) std::cout << "Entries: " << hist->GetEntries() << std::endl;
	   if (verbose) std::cout << "Av. Weight: " << av_weight << std::endl;
	 }
	 for (unsigned i = first_populated+1; i < last_populated; ++i) {
	   if (hist->GetBinContent(i) == 0.) {
		 if (verbose) std::cout << "Bin " << i << " is empty!" << std::endl;
		 if (is_qcd) {
		   hist->SetBinError(i, 1.0);
		 } else {
		   if (verbose) std::cout << "Set weight to 1.0 * av_weight = " << (1.0 * av_weight) << std::endl;
		   hist->SetBinError(i, av_weight);    
		 }
	   }
	 }
	 hist->Write(hist->GetName(),TObject::kOverwrite);
  }


  bool qcdSyst(std::string channel, std::string prefix, std::string histo1, float corr, float unc)
  {

  std:string chan = "mutau";
    if(channel == "eleTau")
      chan = "etau";
    
    TH1F * h1 =(TH1F*) fout_->Get((channel+prefix+"/"+histo1).c_str());
    TH1F * h2 = (TH1F*)h1->Clone(TString(histo1+std::string("_CMS_htt_QCDShape_"+chan+prefix+"_"+energy_+"Up")));
    TH1F * h3 = (TH1F*)h1->Clone(TString(histo1+std::string("_CMS_htt_QCDShape_"+chan+prefix+"_"+energy_+"Down")));
    std::cout << "Channel label is " << chan << std::endl;
    float x,y;
    float cUp = corr+unc;
    float cDown = corr-unc;
    //printf("Creating QCD Shape Systematic \n");
    float scale = h1->Integral();
    for(int i=1;i<h1->GetNbinsX();++i){
      x = h1->GetXaxis()->GetBinCenter(i);
      if(x<50){
	y = h1->GetBinContent(i);
	h1->SetBinContent(i,y*corr);
	h2->SetBinContent(i,y*cUp);
	h3->SetBinContent(i,y*cDown);
      }
		    	
    }
    h1->Scale(scale/h1->Integral());
    h2->Scale(scale/h2->Integral());
    h3->Scale(scale/h3->Integral());
    h1->Write(h1->GetName(),TObject::kOverwrite);
    h2->Write(h2->GetName(),TObject::kOverwrite);
    h3->Write(h3->GetName(),TObject::kOverwrite);        

    return true;
  }
 
  void zeeShapeSyst(std::string folder, std::string histo){
		
		TH1F * hh =(TH1F*) fout_->Get((folder+"/"+histo+"_CMS_scale_t_etau_8TeVUp").c_str());
		TH1F * hhh =(TH1F*) fout_->Get((folder+"/"+histo+"_CMS_scale_t_etau_8TeVDown").c_str());
		
		if(hh!=0){
			TH1F * hUp = (TH1F*)hh->Clone(TString(histo+std::string("_CMS_htt_ZEEShape_etau_8TeVUp")));
			hUp->Write(hUp->GetName(),TObject::kOverwrite);
		}
		else{
			printf("Shift not found = %s\n",(folder+"/"+histo+"_CMS_scale_t_etau_8TeVUp").c_str());
		}
		if(hhh!=0){
			TH1F * hDown = (TH1F*)hhh->Clone(TString(histo+std::string("_CMS_htt_ZEEShape_etau_8TeVDown")));
			hDown->Write(hDown->GetName(),TObject::kOverwrite);
		}
		else{
			printf("Shift not found = %s\n",(folder+"/"+histo+"_CMS_scale_t_etau_8TeVDown").c_str());
		}
		
  }
  

 private:
  std::string channel_;
  std::vector<std::string> shifts_;
  std::vector<std::string> shiftsPostFix_;
  std::string energy_;

  //files
  TFile *fout_;
  int verbose_;
  std::string zttFile_;
  std::string zllFile_;
  std::string wFile_;
  std::string vvFile_;
  std::string topFile_;
  std::string dataFile_;
  std::string wFile42_;
  ///////////////////////

  //selections of regions
  std::string preSelection_;
  std::string osSignalSelection_;
  std::string ssSignalSelection_;
  std::string signalSelection_;
  std::string osWSelection_;
  std::string ssWSelection_;
  std::string wSelection_;
  std::string qcdSelection_;
  std::string bSelection_;
  std::string antibSelection_;
  std::string vbfSelection0_;
  std::string vbfSelection1_;
  std::string vbfSelection2_;
  std::string relaxedSelection_;
  std::string vbfRelaxedSelection_;
  std::string btagRelaxedSelection_;
  std::string trigSelection_;
  std::string vbfWSelection_;
  std::string blinding_;
  std::string charge_;
  std::string vbfTightS_;
  std::string ZTTLL_genTauReject_;
  std::string ZTT_genTauSel_;
  std::string ZJFT_genLReject_;
  std::string ZLFT_genLSel_;
  std::string dataSelection_;

  //Luminosity and efficiency corrections
  float luminosity_;
  float luminosityErr_;
  float  muID_   ;      
  float muIDErr_;      
  float eleID_ ;       
  float eleIDErr_;     
  float tauID_  ;
  float tauIDHigh_;      
  float tauIDErr_;     
  float zttScale_;     
  float zttScaleErr_;  

  float scaleUp_;

  //histogram options
  std::string variable_;
  int bins_;
  float min_;
  float max_;
  std::vector<double> binning_;
  std::string weight_;
  std::string embWeight_;

  //external parameters
  float topErr_;
  float vvErr_;
  float zlftErr_;
  float zlftFactor_;
  float zjftErr_;
  float wFactorErr_;
  float qcdFactor_;
  float qcdFactorErr_;


  float bFactorZ_;
  float bFactorZErr_;
  float bFactorW_;
  float bFactorWErr_;

  float vbfFactorZ_;
  float vbfFactorZErr_;
  float vbfFactorW_;
  float vbfFactorWErr_;


  float boostFactorZ_;
  float boostFactorZErr_;
  float boostFactorW_;
  float boostFactorWErr_;

  float vhFactorZ_;
  float vhFactorZErr_;
  float vhFactorW_;
  float vhFactorWErr_;


  float bID_;
  float bIDErr_;
  float bMisID_;
  float bMisIDErr_;

  std::vector<std::string> mssmMasses_;
  std::vector<std::string> smMasses_;
  std::vector<std::string> smMassesDC_;
  
  std::vector<float> mssmBBFraction_;
  std::vector<float> smSigma_;
  std::vector<float> vbfSigma_;
  std::vector<float> vhSigma_;
  
  std::string dir_;
  

};
