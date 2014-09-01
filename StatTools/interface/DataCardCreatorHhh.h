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

enum type{
  OSLSMT;
  FULLEXTRAP;
  BTAG;

}

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

};



class DataCardCreator {
 public:

  DataCardCreator(optutl::CommandLineParser parser) {
    channel_ = parser.stringValue("channel");
    shifts_  = parser.stringVector("shifts");
    energy_ = parser.stringValue("energy");

    //create the name you need to add to the hisdtograms 
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
    wFile42_  = parser.stringValue("W42File");

    //read control and signal regions
    preSelection_ = parser.stringValue("preSelection");

    signalSelection_      = parser.stringValue("signalSelection");
    wSelection_           = parser.stringValue("wSelection");
    qcdSelection_         = parser.stringValue("qcdSelection");
    relaxedSelection_     = parser.stringValue("relaxedSelection");
    bSelection_           = parser.stringValue("bSelection");
    antibSelection_       = parser.stringValue("antibSelection");
    vbfSelection0_        = parser.stringValue("vbfSelection0");
    vbfSelection1_        = parser.stringValue("vbfSelection1");
    vbfSelection2_        = parser.stringValue("vbfSelection2");
    vbfRelaxedSelection_  = parser.stringValue("vbfRelaxedSelection");
    btagRelaxedSelection_ = parser.stringValue("btagRelaxedSelection");
    trigSelection_        = parser.stringValue("trigSelection");
    vbfWSelection_        = parser.stringValue("vbfWSelection");
    blinding_             = parser.stringValue("blinding");

    ZTT_genTauSel_        = "(genTaus>0&&genVisPt2>18&&(!((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8))))"; //Zttyield
    ZTTLL_genTauReject_   = "(genTaus>0&&((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))"; /// zTT_LL
    ZJFT_genLReject_      = "(!((genTaus==0&&abs(pdg2)==13&&genPt2>8)||(genTaus==0&&abs(pdg2)==11&&genPt2>8)||(genTaus>0&&genVisPt2>18)))"; //ZJ
    ZLFT_genLSel_         = "(genTaus==0&&((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))";///zl

    dataSelection_        = "EVENT>0";

    vbfTightS_            = parser.stringValue("vbfTightSplit");
    osSignalSelection_    = signalSelection_+"&&charge==0";
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

    vbfFactorZ_    = parser.doubleValue("vbfFactorZ");
    vbfFactorZErr_ = parser.doubleValue("vbfFactorZErr");
    vbfFactorW_    = parser.doubleValue("vbfFactorW");
    vbfFactorWErr_ = parser.doubleValue("vbfFactorWErr");

    boostFactorZ_    = parser.doubleValue("boostFactorZ");
    boostFactorZErr_ = parser.doubleValue("boostFactorZErr");
    boostFactorW_    = parser.doubleValue("boostFactorW");
    boostFactorWErr_ = parser.doubleValue("boostFactorWErr");

    vhFactorZ_    = parser.doubleValue("vhFactorZ");
    vhFactorZErr_ = parser.doubleValue("vhFactorZErr");
    vhFactorW_    = parser.doubleValue("vhFactorW");
    vhFactorWErr_ = parser.doubleValue("vhFactorWErr");

    dir_ = parser.stringValue("dir");


    //predefine te masses you are going to make 
    //First as an array then as a vector
    std::string mssmMasses[20]=["80","90","100","120","130","140","160","180","200","250",
				"300","350","400","450","500","600","700","800","900","1000"];
    mssmMasses_ = mssmMasses;
    
    std::string smMasses[15]=["90","95","100","105","110","115","120","125","130",
			      "135","140","145","150","155","160"];
    smMasses_   = smMasses;
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


  void makeHeavyHiggsShape(std::string preselection,std::string prefix) {

    std::pair<float,float> tmp;
    float legCorr=1.0;

    if(muID_!=0&&eleID_!=0) {legCorr*=muID_*eleID_;}
    if(muID_!=0&&eleID_==0) {legCorr*=muID_*tauID_;}
    if(muID_==0&&eleID_!=0) {legCorr*=eleID_*tauID_;}

    tmp= createHistogramAndShiftsFinal(dir_+"Hhhttbb260.root","Hhh260",("("+preselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
    tmp= createHistogramAndShiftsFinal(dir_+"Hhhttbb300.root","Hhh300",("("+preselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
    tmp= createHistogramAndShiftsFinal(dir_+"Hhhttbb350.root","Hhh350",("("+preselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);

  }


  /*-------------Create Histograms------------------*/

  BkgOutput runOSLSMT(std::string preSelection,std::string prefix,std::string zShape, float topExtrap) {

    BkgOutput output;    

    float leg1Corr=1.0;
    if(muID_!=0) leg1Corr*=muID_;
    if(eleID_!=0) leg1Corr*=eleID_;

    printf("Tau ID Scale Factor is %.3f \n",tauID_);

    //Create Z-->tautau
    if(!runZtt(preSelection, prefix, zShape, topExtrap, output)){
      std::cout<<"Error Creating Ztt"<<std::endl;
      return false;
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
    if(!runW(preSelection, prefix, zShape, topExtrap, output)){
      std::cout<<"Error Creating W"<<std::endl;
      return false;
    }

    //Create QCD
    if(!runQCD(preSelection, prefix, zShape, topExtrap, output)){
      std::cout<<"Error Creating QCD"<<std::endl;
      return false;
    }

    //Create Data
    std::pair<float,float> dataY         = createHistogramAndShiftsFinal(dataFile_,"data_obs","("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+")",scaleUp_,prefix);
    std::pair<float,float> dataYRounded  = std::make_pair(rintf(dataY.first),dataY.second);
    renormalizeHistogram(channel_+prefix,"data_obs",dataYRounded.first);

    float background    = output.QCD  + output.W  + output.TOP  + output.VV  + output.ZLFT  + output.ZJFT  + output.ZTT;
    float backgroundErr = sqrt( pow(output.dQCD,2) + pow(output.dW,2) + pow(output.dTOP,2) + pow(output.dVV,2) + pow(output.dZLFT,2) + pow(output.dZJFT,2) + pow(output.dZTT,2));

    //float background    = osQCD.first+osWLow.first+topInflYield.first+vvInflYield.first+zlftInflYield.first+zjftInflYield.first+zttYield.first;
    //float backgroundErr = sqrt(osQCD.second*osQCD.second+osWLow.second*osWLow.second+topInflYield.second*topInflYield.second+vvInflYield.second*vvInflYield.second+zlftInflYield.second*zlftInflYield.second+zjftInflYield.second*zjftInflYield.second+zttYield.second*zttYield.second);
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

  BkgOutput runFullExtrapBtag(std::string preSelection,std::string prefix,std::string zShape, float topExtrap) {

    categorySelection = categorySelection_;
    relaxedSelection = relaxedSelection_;

    BkgOutput output;    
    output.ZTTCORR=zExtrap;    
    output.dZTTCORR=zExtrapErr;

    float leg1Corr=1.0;
    if(muID_!=0) leg1Corr*=muID_;
    if(eleID_!=0) leg1Corr*=eleID_;

    printf("Tau ID Scale Factor is %.3f \n",tauID_);

    //Create Z-->tautau
    //TODO: Check me, previous Btag ZTT shape correction had a special normalization method
    if(!runZtt(preSelection, prefix, zShape, topExtrap, output, categorySelection)){
      std::cout<<"Error Creating Ztt"<<std::endl;
      return false;
    }

    //Create ttbar
    if(!runTOP(preSelection, prefix, zShape, topExtrap, output, categorySelection, "pt1>-100")){
      std::cout<<"Error Creating TOP"<<std::endl;
      return false;
    }

    //Subtract the ztt ttbar overlap of 1.5% from the ttbar yield
    output.TOP = output.TOP-(output.ZTT*0.015);    
    renormalizeHistogram(channel_+prefix,"TT",output.TOP);


    //Create Diboson
    //stopped here!
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
    if(!runW(preSelection, prefix, zShape, topExtrap, output, categorySelection, relaxedSelection)){
      std::cout<<"Error Creating W"<<std::endl;
      return false;
    }

    //Create QCD
    if(!runQCD(preSelection, prefix, zShape, topExtrap, output, categorySelection, relaxedSelection)){
      std::cout<<"Error Creating QCD"<<std::endl;
      return false;
    }

    //Create Data
    std::pair<float,float> dataY         = createHistogramAndShiftsFinal(dataFile_,"data_obs","("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+")",scaleUp_,prefix);
    std::pair<float,float> dataYRounded  = std::make_pair(rintf(dataY.first),dataY.second);
    renormalizeHistogram(channel_+prefix,"data_obs",dataYRounded.first);

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

    return true;      

  }

  /*
   * For now running ttbar selection is still basic control region, might change as b-tag studies progress
   */

  bool runTOP(std::string preSelection,std::string prefix,std::string zShape, float topExtrap, BkgOutput output, 
	      std::string categorySelection = "pt1>-100", std::string relaxedSelection = "pt1>-100") {

    std::pair<float,float> topYield      = createHistogramAndShiftsFinal(topFile_,"TT",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection")*"+weight_),luminosity_*leg1Corr*tauID_*topExtrap,prefix);
    std::pair<float,float> topInflYield  = inflateError(topYield,topErr_);
    printf("TTbar events in signal region = %f + %f \n",topInflYield.first,topInflYield.second);
    output.TOP  = topInflYield.first;
    output.dTOP = topInflYield.second;

    return true;
  }

  /*
   * To run QCD we take the shape and yield from the Same-Sign Control region, 
   * where the lepton and tau are required to be like signs, this gives a control 
   * region which is orthogonal to the signal region. We fist create the QCD shape
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
  
  bool runQCD(std::string preSelection,std::string prefix,std::string zShape, float topExtrap, BkgOutput output) {
    //create QCD shape from data and subtract off major contributors
    std::pair<float,float> dataQCDControl = createHistogramAndShifts(dataFile_,"QCD","("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+")",scaleUp_,prefix);
    std::pair<float,float> zllQCDControl  = createHistogramAndShifts(zllFile_,"ZLLQCD","("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+")*ZeFakeTau*"+weight_,luminosity_*leg1Corr*zttScale_,prefix);
    std::pair<float,float> ttQCDControl   = createHistogramAndShifts(topFile_,"TOPQCD","("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+")*"+weight_,luminosity_*leg1Corr*tauID_*topExtrap,prefix);
    std::pair<float,float> wShapeSS       = createHistogramAndShifts(wFile_,"WQCD",("("+preSelection+"&&"+ssSignalSelection_+")*"+weight_),luminosity_*leg1Corr,prefix,false);
	
    //create same sign W side band yields
    std::pair<float,float> dataSSYSdb = createHistogramAndShifts(dataFile_,"data_obs_ss_sdb","("+preSelection+"&&"+trigSelection_+"&&"+ssWSelection_+")",scaleUp_,prefix);
    std::pair<float,float> dataSSYieldSdb = convertToPoisson(dataSSYSdb);
    printf("Data events in SS sideband region = %f + %f \n",dataSSYieldSdb.first,dataSSYieldSdb.second);

    std::pair<float,float> topSSYieldSdb    = createHistogramAndShifts(topFile_,"TTSS_SDB",("("+preSelection+"&&"+trigSelection_+"&&"+ssWSelection_+")*"+weight_),luminosity_*leg1Corr*tauID_*topExtrap,prefix);
    std::pair<float,float> topInflSSYieldSdb  = inflateError(topSSYieldSdb,topErr_);
    printf("TTbar events in SS sideband region = %f + %f \n",topSSYieldSdb.first,topInflSSYieldSdb.second);

    std::pair<float,float> zSSYieldSdb    = createHistogramAndShifts(zllFile_,"ZSS_SDB",("("+preSelection+"&&"+trigSelection_+"&&"+ssWSelection_+")*ZeFakeTau*"+weight_),luminosity_*leg1Corr*tauID_,prefix);      
    std::pair<float,float> vvSSYieldSdb   = createHistogramAndShifts(vvFile_,"VVSS_SDB",("("+preSelection+"&&"+trigSelection_+"&&"+ssWSelection_+")*"+weight_),luminosity_*leg1Corr*tauID_,prefix);

    printf("3. Repeat W estimation for SS : first subtract TTbar W\n");
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

    renormalizeHistogram(channel_+prefix,"WQCD",ssWLow.first);
 
   //Now subtracting off bkgd shapes from data ss shape
    subtractHistogram(channel_+prefix,"QCD","ZLLQCD");
    subtractHistogram(channel_+prefix,"QCD","TOPQCD");
    subtractHistogram(channel_+prefix,"QCD","WQCD");

    //SS Yield Estimate
    std::pair<float,float> dataSSY         = createHistogramAndShifts(dataFile_,"data_obs_ss","("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+")",scaleUp_,prefix);
    std::pair<float,float> dataSSYield     = convertToPoisson(dataSSY);

    std::pair<float,float> zlftSSYield     = createHistogramAndShifts(zllFile_,"ZL_SS",("("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+ZLFT_genLSel_+"*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zttScale_,prefix);
    std::pair<float,float> zlftInflSSYield = inflateError(zlftSSYield,zlftErr_);
    printf("Z (l->tau) in SS region = %f + %f \n",zlftInflSSYield.first,zlftInflSSYield.second);

    std::pair<float,float> zjftSSYield     = createHistogramAndShifts(zllFile_,"ZJ_SS",("("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&ZJFT_genLReject_*"+weight_),luminosity_*leg1Corr*zttScale_,prefix,false);    
    std::pair<float,float> zjftInflSSYield = inflateError(zjftSSYield,zjftErr_);
    printf("Z (j->tau) in SS region = %f + %f \n",zjftInflSSYield.first,zjftInflSSYield.second);

    std::pair<float,float> topSSYield      = createHistogramAndShifts(topFile_,"TTSS",("("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+")*"+weight_),luminosity_*leg1Corr*tauID_*topExtrap,prefix);
    std::pair<float,float> topInflSSYield  = inflateError(topSSYield,topErr_);
    printf("TTbar events in SS signal region = %f + %f \n",topInflSSYield.first,topInflSSYield.second);

    //TODO:Check me, genpt selection?
    std::pair<float,float> zttSS   	   = createHistogramAndShifts(zttFile_,"ZTT_SS",("("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&genTaus>0&&genVisPt2>18)*"+weight_),luminosity_*zttScale_*leg1Corr*tauID_,prefix);
    printf("Z-->tautau events in SS signal region = %f + %f \n",zttSSYield.first,zttSSYield.second);

    std::pair<float,float> vvYieldSS       = createHistogramAndShifts(vvFile_,"VV_SS",("("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+")*"+weight_),luminosity_*leg1Corr*tauID_,prefix);
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

    printf("OS QCD in  core  =%f *%f = %f +- %f \n",ssQCD.first,qcdFactor_,osQCD.first,osQCD.second);

    output.QCD  = osQCD.first;    
    output.dQCD = osQCD.second;
    
    return true;
  }

  bool runW(std::string preSelection,std::string prefix,std::string zShape, float topExtrap, BkgOutput output) {

    //First get data in Sideband
    std::pair<float,float> dataYSdb     = createHistogramAndShiftsFinal(dataFile_,"data_obs_sdb","("+preSelection+"&&"+trigSelection_+"&&"+osWSelection_+")",scaleUp_,prefix);
    std::pair<float,float> dataYieldSdb = convertToPoisson(dataYSdb);

    //then get ttbar in sideband
    std::pair<float,float> topYieldSdb      = createHistogramAndShiftsFinal(topFile_,"TT_SDB",("("+preSelection+"&&"+trigSelection_+"&&"+osWSelection_+")*"+weight_),luminosity_*leg1Corr*tauID_*topExtrap,prefix);
    std::pair<float,float> topInflYieldSdb  = inflateError(topYieldSdb,topErr_);
    printf("TTbar events in sideband region = %f + %f \n",topYieldSdb.first,topInflYieldSdb.second);

    //Next get Diboson in sideband
    std::pair<float,float> vvYieldSdb      = createHistogramAndShiftsFinal(vvFile_,"VV_SDB",("("+preSelection+"&&"+trigSelection_+"&&"+osWSelection_+")*"+weight_),luminosity_*leg1Corr*tauID_,prefix);
    std::pair<float,float> vvInflYieldSdb  = inflateError(vvYieldSdb,vvErr_);
    printf("Diboson events in sideband region = %f + %f \n",vvYieldSdb.first,vvInflYieldSdb.second);

    //finally get Z in sideband
    std::pair<float,float> zSDB    	   = createHistogramAndShiftsFinal(zttFile_,"Z_SDB",("("+preSelection+"&&"+trigSelection_+"&&"+osWSelection_+")*"+weight_),luminosity_*zttScale_*leg1Corr*tauID_,prefix);
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
     
    printf("2. Extrapolate W in the low MT region\n");
    std::pair<float,float> osWLow = std::make_pair(osWHigh.first*wFactor.first,
						     sqrt(osWHigh.first*osWHigh.first*wFactor.second*wFactor.second+osWHigh.second*osWHigh.second*wFactor.first*wFactor.first));
      
    printf("OS W  in core  =%f *%f  = %f +- %f \n",osWHigh.first,wFactor.first,osWLow.first,osWLow.second);
    renormalizeHistogram(channel_+prefix,"W",osWLow.first);

    std::pair<float,float> wMCYield       = createHistogramAndShiftsFinal(wFile_,"WTMP",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*leg1Corr,prefix,false);

    output.W  = osWLow.first;
    output.dW = osWLow.second;

    return true;
  }

  bool runZTT(std::string preSelection,std::string prefix,std::string zShape, float topExtrap, BkgOutput &output,
	      std::string categorySelection = "pt1>-100", std::string relaxedSelection = "pt1>-100") {) {

    //TODO: make the pdg selection cleaner Check if we are using pdg selection for fullExtrapolation
    std::pair<float,float> zttYield    = createHistogramAndShiftsFinal(zttFile_,"ZTTTMP",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&"+ZTT_genTauSel_+"*"+weight_),luminosity_*zttScale_*leg1Corr*tauID_,prefix);
    std::pair<float,float> ztt_ll      = createHistogramAndShiftsFinal(zttFile_,"ZTT_LL",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&"+ZTTLL_genTauReject_+"*"+weight_),luminosity_*zttScale_*leg1Corr*tauID_,prefix);
    
    if(zShape.size()==0) {
      std::pair<float,float> zttShape  = createHistogramAndShiftsFinal(zttFile_,"ZTT",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&"+"&&genTaus>0&&genVisPt2>18)*"+weight_),luminosity_*zttScale_*leg1Corr*tauID_,prefix);
      
    }
    else{
      //create correction factor for MT and Pzeta cuts
      std::pair<float,float> dataWCut_Before  = createHistogramAndShifts(zShape,"ZTTWCut",("("+preSelection+"&&"+categorySelection+"&&charge==0&&genFullMass>50&&genVisPt2>18)*"+embWeight_),1.0,prefix);
      std::pair<float,float> zttShape         = createHistogramAndShifts(zShape,"ZTT",("("+preSelection+"&&"+categorySelection+"&&"+osSignalSelection_+"&&genFullMass>50&&genVisPt2>18)*"+embWeight_),1.0,prefix);
      
      std::pair<float,float> mcWCut_Before    = createHistogramAndShiftsFinal(zttFile_,"ZTTWCutMC",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+trigSelection_+"&&genTaus>0&&genVisPt2>18&&(!((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8))))*"+weight_),luminosity_*zttScale_*leg1Corr*tauID_,prefix);
      float corrector = (zttShape.first/dataWCut_Before.first) / (zttYield.first/mcWCut_Before.first);
      
      printf("W Cut Correction = %f \n",corrector); 
      printf("emb before events = %f \n", dataWCut_Before.first);
      printf("emb inclusive events = %f \n", zttShape.first);
      printf("mc before events = %f \n", mcWCut_Before.first);
      printf("mc inclusive events = %f \n", zttYield.first);
      zttYield = std::make_pair(zttYield.first*corrector,zttYield.second*corrector);
      renormalizeHistogram(channel_+prefix,"ZTT",zttYield.first);
      addHistogramZTT(channel_+prefix, "ZTT", "ZTT_LL");
    }

    output.ZTT  = zttYield.first;
    output.dZTT = zttYield.second;

    return true;

  }

  //Create ttbar
  bool runTTBAR(std::string preSelection,std::string prefix,std::string zShape, float topExtrap, BkgOutput output) {
    //create TTbar
    std::pair<float,float> topYield       = createHistogramAndShiftsFinal(topFile_,"TT",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*leg1Corr*tauID_*topExtrap,prefix);

    return true;
  }

  /*-------------Helper Functions------------------*/


  //TODO:Add in other helper functions
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



}
