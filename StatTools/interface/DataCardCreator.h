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

  float W;
  float dW;

  float WF;
  float dWF;


  float WSS;
  float dWSS;
  float WSDB;

  float QCD;
  float dQCD;

  float QCDSDB;


  float ZLFT;
  float dZLFT;

  float ZJFT;
  float dZJFT;

  float ZLFTSS;
  float dZLFTSS;

  float ZJFTSS;
  float dZJFTSS;
  float TOP;
  float dTOP;

  float VV;
  float dVV;

  float ZTT;
  float dZTT;


  float WCORR;
  float dWCORR;

  float WSSCORR;
  float dWSSCORR;

  float ZTTCORR;
  float dZTTCORR;


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
      if(channel_=="eleTau") chan = "etau";
      shiftsPostFix_.push_back("CMS_scale_"+shiftL+"_"+chan+"_"+energy_);
    }
      

    //read input files
    zttFile_ = parser.stringValue("zttFile");
    zllFile_ = parser.stringValue("zllFile");
    wFile_ = parser.stringValue("wFile");
    vvFile_ = parser.stringValue("vvFile");
    topFile_ = parser.stringValue("topFile");
    dataFile_ = parser.stringValue("dataFile");
    wFile42_ = parser.stringValue("W42File");


    //read control and signal regions
    preSelection_ = parser.stringValue("preSelection");

    signalSelection_ = parser.stringValue("signalSelection");
    wSelection_ = parser.stringValue("wSelection");
    qcdSelection_ = parser.stringValue("qcdSelection");
    relaxedSelection_ = parser.stringValue("relaxedSelection");
    bSelection_ = parser.stringValue("bSelection");
    antibSelection_ = parser.stringValue("antibSelection");
    vbfSelection0_ = parser.stringValue("vbfSelection0");
    vbfSelection1_ = parser.stringValue("vbfSelection1");
    vbfSelection2_ = parser.stringValue("vbfSelection2");
    vbfRelaxedSelection_ = parser.stringValue("vbfRelaxedSelection");
    btagRelaxedSelection_ = parser.stringValue("btagRelaxedSelection");
    trigSelection_ = parser.stringValue("trigSelection");
    vbfWSelection_ = parser.stringValue("vbfWSelection");
    blinding_ = parser.stringValue("blinding");
    genTauReject_ = "(genTaus>0&&((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))"; /// zTT_LL
    genTauSel_ = "(genTaus>0&&genVisPt2>18&&(!((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8))))"; //Zttyield
    genLReject_ = " (!((genTaus==0&&abs(pdg2)==13&&genPt2>8)||(genTaus==0&&abs(pdg2)==11&&genPt2>8)||(genTaus>0&&genVisPt2>18)))"; //ZJ
    genLSel_ = "(genTaus==0&&((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))";///zl
    dataSelection_ = "EVENT>0";

    vbfTightS_ = parser.stringValue("vbfTightSplit");

    osSignalSelection_ = signalSelection_+"&&charge==0";
    ssSignalSelection_ = signalSelection_+"&&charge!=0";
    osWSelection_ = wSelection_+"&&charge==0";
    ssWSelection_ = wSelection_+"&&charge!=0";
    verbose_ = parser.integerValue("verbose");
    
    //read systematic uncertainties 
    luminosity_ = parser.doubleValue("luminosity");
    luminosityErr_ = parser.doubleValue("luminosityErr");
    muID_ = parser.doubleValue("muID");
    muIDErr_ = parser.doubleValue("muIDErr");
    bID_ = parser.doubleValue("bID");
    bIDErr_ = parser.doubleValue("bIDErr");
    bMisID_ = parser.doubleValue("bMisID");
    bMisIDErr_ = parser.doubleValue("bMisIDErr");
    eleID_ = parser.doubleValue("eleID");
    eleIDErr_ = parser.doubleValue("eleIDErr");
    tauID_ = parser.doubleValue("tauID");
    tauIDHigh_ = parser.doubleValue("tauIDHigh");
    tauIDErr_ = parser.doubleValue("tauIDErr");
    zttScale_ = parser.doubleValue("zttScale");
    zttScaleErr_ = parser.doubleValue("zttScaleErr");

    //read the basic varibale you will put in the histogram
    variable_ = parser.stringValue("variable");

    //read the event weight for MC and embedded
    weight_ = parser.stringValue("weight");
    embWeight_ = parser.stringValue("embWeight");

    //define the histogram binning
    bins_ = parser.integerValue("bins");
    min_ = parser.doubleValue("min");
    max_ = parser.doubleValue("max");




    //Define background uncertainty Errors
    topErr_ = parser.doubleValue("topErr");
    vvErr_ = parser.doubleValue("vvErr");
    zlftErr_ = parser.doubleValue("zlftErr");
    zlftFactor_ = parser.doubleValue("zlftFactor");

    zjftErr_ = parser.doubleValue("zjftErr");
    wFactorErr_ = parser.doubleValue("wFactorErr");
    qcdFactor_ = parser.doubleValue("qcdFactor");
    qcdFactorErr_ = parser.doubleValue("qcdFactorErr");
    bFactorZ_ = parser.doubleValue("bFactorZ");
    bFactorZErr_ = parser.doubleValue("bFactorZErr");
    bFactorW_ = parser.doubleValue("bFactorW");
    bFactorWErr_ = parser.doubleValue("bFactorWErr");

    vbfFactorZ_ = parser.doubleValue("vbfFactorZ");
    vbfFactorZErr_ = parser.doubleValue("vbfFactorZErr");
    vbfFactorW_ = parser.doubleValue("vbfFactorW");
    vbfFactorWErr_ = parser.doubleValue("vbfFactorWErr");

    boostFactorZ_ = parser.doubleValue("boostFactorZ");
    boostFactorZErr_ = parser.doubleValue("boostFactorZErr");
    boostFactorW_ = parser.doubleValue("boostFactorW");
    boostFactorWErr_ = parser.doubleValue("boostFactorWErr");

    vhFactorZ_ = parser.doubleValue("vhFactorZ");
    vhFactorZErr_ = parser.doubleValue("vhFactorZErr");
    vhFactorW_ = parser.doubleValue("vhFactorW");
    vhFactorWErr_ = parser.doubleValue("vhFactorWErr");


    dir_ = parser.stringValue("dir");


    //predefine te masses you are going to make 
    mssmMasses_.push_back("80");
    mssmMasses_.push_back("90");
    mssmMasses_.push_back("100");
    mssmMasses_.push_back("120");
    mssmMasses_.push_back("130");
    mssmMasses_.push_back("140");
    mssmMasses_.push_back("160");
    mssmMasses_.push_back("180");
    mssmMasses_.push_back("200");
    mssmMasses_.push_back("250");
    mssmMasses_.push_back("300");
    mssmMasses_.push_back("350");
    mssmMasses_.push_back("400");
    mssmMasses_.push_back("450");
    mssmMasses_.push_back("500");
    mssmMasses_.push_back("600");
    mssmMasses_.push_back("700");
    mssmMasses_.push_back("800");
    mssmMasses_.push_back("900");
    mssmMasses_.push_back("1000");    
    
     smMasses_.push_back("90");
     smMasses_.push_back("95");
     smMasses_.push_back("100");
     smMasses_.push_back("105");
     smMasses_.push_back("110");
     smMasses_.push_back("115");
     smMasses_.push_back("120");
     smMasses_.push_back("125");
     smMasses_.push_back("130");
     smMasses_.push_back("135");
     smMasses_.push_back("140");
     smMasses_.push_back("145");
	if(energy_ == "8TeV"){
     smMasses_.push_back("150");
     smMasses_.push_back("155");
     smMasses_.push_back("160");
	}
	
	smMassesDC_ = smMasses_;

//     for(unsigned int i=110;i<=160;++i)
//       smMassesDC_.push_back(boost::lexical_cast<std::string>(i));



    smSigma_.push_back(1.0);//1.234);
    smSigma_.push_back(1.0);
    smSigma_.push_back(1.0);
    smSigma_.push_back(1.0);
    smSigma_.push_back(1.0);
    smSigma_.push_back(1.0);
    smSigma_.push_back(1.0);
    smSigma_.push_back(1.0);
    smSigma_.push_back(1.0);
    smSigma_.push_back(1.0);
    smSigma_.push_back(1.0);
    smSigma_.push_back(1.0);
    smSigma_.push_back(1.0);
    smSigma_.push_back(1.0);
    smSigma_.push_back(1.0);


    vbfSigma_.push_back(1.0);//0.0997);
    vbfSigma_.push_back(1.0);
    vbfSigma_.push_back(1.0);
    vbfSigma_.push_back(1.0);
    vbfSigma_.push_back(1.0);
    vbfSigma_.push_back(1.0);
    vbfSigma_.push_back(1.0);
    vbfSigma_.push_back(1.0);
    vbfSigma_.push_back(1.0);
    vbfSigma_.push_back(1.0);
    vbfSigma_.push_back(1.0);
    vbfSigma_.push_back(1.0);
    vbfSigma_.push_back(1.0);
    vbfSigma_.push_back(1.0);
    vbfSigma_.push_back(1.0);



    vhSigma_.push_back(1.0);//0.0772);
    vhSigma_.push_back(1.0);
    vhSigma_.push_back(1.0);
    vhSigma_.push_back(1.0);
    vhSigma_.push_back(1.0);
    vhSigma_.push_back(1.0);
    vhSigma_.push_back(1.0);
    vhSigma_.push_back(1.0);
    vhSigma_.push_back(1.0);
    vhSigma_.push_back(1.0);
    vhSigma_.push_back(1.0);
    vhSigma_.push_back(1.0);
    vhSigma_.push_back(1.0);
    vhSigma_.push_back(1.0);
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


  void makeMSSMLTauDataCard(BkgOutput out,std::string postfix) {
    for(unsigned int m = 0;m<mssmMasses_.size();++m) {
      FILE *pfile = fopen(("datacards/"+channel_+postfix+"_mA"+mssmMasses_[m]+".txt").c_str(),"w");
      fprintf(pfile,"imax 1\n");
      fprintf(pfile,"jmax *\n");
      fprintf(pfile,"kmax *\n");
      fprintf(pfile,"shapes *  *    %s  $CHANNEL/$PROCESS $CHANNEL/$PROCESS_$SYSTEMATIC \n",(channel_+".root").c_str());
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      fprintf(pfile,"observation %d\n",(int)out.DATA);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      std::string ch = channel_+postfix;
      fprintf(pfile,"bin            %s            %s            %s            %s            %s            %s            %s            %s            %s\n",ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str());
      fprintf(pfile,"process        GGH%s        BBH%s        ZTT           QCD           W             ZJ            ZL            TT            VV\n",mssmMasses_[m].c_str(),mssmMasses_[m].c_str());
      fprintf(pfile,"process        -1            0             1             2             3             4             5             6             7\n");
      fprintf(pfile,"rate           %.3f          %.3f          %.3f          %.3f          %.3f          %.3f          %.3f          %.3f          %.3f\n",
	     getYield("GGH"+mssmMasses_[m],postfix),getYield("BBH"+mssmMasses_[m],postfix),out.ZTT,out.QCD,out.W,out.ZJFT,out.ZLFT,out.TOP,out.VV);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      if(luminosityErr_!=0)
	fprintf(pfile,"lumi     lnN   %.3f          %.3f          -             -             -             -             -             -             -          luminosity\n",
	   1+luminosityErr_,1+luminosityErr_);
      if(muID_!=0)
	fprintf(pfile,"CMS_eff_m     lnN   %.3f          %.3f          %.3f          -             -             %.3f          %.3f          %.3f          %.3f       muon ID /HLT\n",
	       1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_);
      if(tauID_!=0)
	fprintf(pfile,"CMS_eff_t    lnN   %.3f          %.3f          %.3f          -             -             -             -             %.3f          %.3f        Tau IDf\n",
	       1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_);
    if(eleID_!=0)
      fprintf(pfile,"CMS_eff_e    lnN   %.3f          %.3f          %.3f          -             -             %.3f          %.3f          %.3f           %.3f      Electron ID\n",
	     1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_);
    if(zttScale_!=0)
      fprintf(pfile,"CMS_htt_zttNorm lnN   -             -             %.3f          -             -             %.3f          %.3f          -              -         ZTT Scale  \n",
	     1+zttScaleErr_/zttScale_,1+zttScaleErr_/zttScale_,1+zttScaleErr_/zttScale_);
    fprintf(pfile,"CMS_htt_ttbarNorm  lnN      -             -             -             -             -             -             -              %.3f           -      TTbar background  \n",1+out.dTOP/out.TOP);
    fprintf(pfile,"CMS_htt_DiBosonNorm  lnN      -             -             -             -             -             -             -              -              %.3f   DiBoson background \n",1+out.dVV/out.VV);
    fprintf(pfile,"CMS_htt_%s_WNorm lnN      -             -             -             -             %.3f          -             -              -              -      W Backghround \n",(channel_+postfix).c_str(),1+out.dW/out.W);
    fprintf(pfile,"CMS_htt_%s_ZJFTNorm  lnN      -             -             -             -             -             %.3f          -              -              -      Z(jet->tau) background\n",(channel_+postfix).c_str(),1+out.dZJFT/out.ZJFT);
    fprintf(pfile,"CMS_htt_%s_ZLFTNorm  lnN      -             -             -             -             -             -             %.3f           -              -      Z(l->tau)   background\n",(channel_+postfix).c_str(),1+out.dZLFT/out.ZLFT);
    fprintf(pfile,"CMS_htt_%s_QCDNorm gmN   %d   -             -             -             %.3f          -             -             -              -              -      QCD Background\n",(channel_+postfix).c_str(),(int)out.QCDSDB,qcdFactor_);
    fprintf(pfile,"CMS_htt_%s_QCDSyst lnN        -             -             -             %.3f          -             -             -              -              -      QCD Background Systematics\n",(channel_).c_str(),1.+qcdFactorErr_/qcdFactor_);

    for(unsigned int j=0;j<shifts_.size();++j)
	fprintf(pfile,"%s    shape    1             1             1             -             -             -             -              -              -      shape\n",shiftsPostFix_[j].c_str());

    fprintf(pfile,"CMS_scale_met lnN  1.05          1.05          -             -             -             -             -              1.02          1.03      MET Scale\n");
    fprintf(pfile,"CMS_scale_j   lnN  1.05          1.05          -             -             -             -             -              1.02          1.03      Jet Scale\n");


    fclose(pfile);
    }
  
 

  }



  void makeMSSMEMuDataCard(BkgOutput out,std::string postfix) {
    for(unsigned int m = 0;m<mssmMasses_.size();++m) {
      FILE *pfile = fopen(("datacards/"+channel_+postfix+"_mA"+mssmMasses_[m]+".txt").c_str(),"w");
      fprintf(pfile,"imax 1\n");
      fprintf(pfile,"jmax *\n");
      fprintf(pfile,"kmax *\n");
      fprintf(pfile,"shapes *  *    %s  $CHANNEL/$PROCESS $CHANNEL/$PROCESS_$SYSTEMATIC \n",(channel_+".root").c_str());
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      fprintf(pfile,"observation %d\n",(int)out.DATA);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      std::string ch = channel_+postfix;
      fprintf(pfile,"bin            %s            %s            %s            %s            %s            %s   \n",ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str());
      fprintf(pfile,"process        GGH%s        BBH%s        ZTT         FAKES            TT            VV\n",mssmMasses_[m].c_str(),mssmMasses_[m].c_str());
      fprintf(pfile,"process        -1            0             1             2             3             4          \n");
      fprintf(pfile,"rate           %.3f          %.3f          %.3f          %.3f          %.3f          %.3f       \n",
	     getYield("GGH"+mssmMasses_[m],postfix),getYield("BBH"+mssmMasses_[m],postfix),out.ZTT,out.QCD,out.TOP,out.VV);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      if(luminosityErr_!=0)
	fprintf(pfile,"lumi     lnN   %.3f          %.3f          -             -             -             -           luminosity\n",
	   1+luminosityErr_,1+luminosityErr_);
      if(muID_!=0)
	fprintf(pfile,"CMS_eff_m     lnN   %.3f          %.3f          %.3f          -        %.3f          %.3f          muon ID /HLT\n",
	       1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_);
      if(eleID_!=0)
	fprintf(pfile,"CMS_eff_e    lnN   %.3f          %.3f          %.3f          -         %.3f          %.3f         Electron ID\n",
	     1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_);
    if(zttScale_!=0)
      fprintf(pfile,"CMS_htt_zttNorm lnN   -             -             %.3f          -             -          -         ZTT Scale  \n",1+zttScaleErr_/zttScale_);
    fprintf(pfile,"CMS_htt_ttbarNorm  lnN      -             -             -             -           %.3f     -    TTbar background  \n",1+out.dTOP/out.TOP);
    fprintf(pfile,"CMS_htt_DiBosonNorm  lnN      -             -             -             -             -     %.3f   DiBoson background \n",1+out.dVV/out.VV);
    fprintf(pfile,"CMS_htt_%s_FAKENorm lnN        -             -             -             %.3f          -             -       FAKE Background Systematics\n",(channel_).c_str(),1.+out.dQCD/out.QCD);
    for(unsigned int j=0;j<shifts_.size();++j)
      fprintf(pfile,"%s    shape    1             1             1             -             -             -      shape\n",shiftsPostFix_[j].c_str());

    fprintf(pfile,"CMS_scale_met lnN  1.05          1.05          -             -           1.02          1.03      MET Scale\n");
    fprintf(pfile,"CMS_scale_j   lnN  1.05          1.05          -             -           1.02          1.03      Jet Scale\n");


    fclose(pfile);
    }
  }



  void makeMSSMLTauDataCardNoBTag(BkgOutput out,std::string postfix) {
    for(unsigned int m = 0;m<mssmMasses_.size();++m) {
      FILE *pfile = fopen(("datacards/"+channel_+postfix+"_mA"+mssmMasses_[m]+".txt").c_str(),"w");

      fprintf(pfile,"imax 1\n");
      fprintf(pfile,"jmax *\n");
      fprintf(pfile,"kmax *\n");
      fprintf(pfile,"shapes *  *    %s  $CHANNEL/$PROCESS $CHANNEL/$PROCESS_$SYSTEMATIC \n",(channel_+".root").c_str());
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      fprintf(pfile,"observation %d\n",(int)out.DATA);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      std::string ch = channel_+postfix;
      fprintf(pfile,"bin            %s            %s             %s            %s             %s                 %s            %s            %s             %s           %s            %s              %s\n",ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str());
      fprintf(pfile,"process        GGHNoJet%s   GGHJet%s        BBHNoJet%s     BBHJet%s     BBHBJet%s           ZTT           QCD           W             ZJ            ZL            TT            VV\n",mssmMasses_[m].c_str(),mssmMasses_[m].c_str(),mssmMasses_[m].c_str(),mssmMasses_[m].c_str(),mssmMasses_[m].c_str());
      fprintf(pfile,"process        -4              -3           -2              -1            0                 1             2             3             4             5            6             7  \n");
      fprintf(pfile,"rate           %.3f            %.3f          %.3f         %.3f          %.3f             %.3f          %.3f          %.3f          %.3f          %.3f          %.3f            %.3f\n",
	      getYield("GGHNoJet"+mssmMasses_[m],postfix),getYield("GGHJet"+mssmMasses_[m],postfix),getYield("BBHNoJet"+mssmMasses_[m],postfix),getYield("BBHJet"+mssmMasses_[m],postfix),getYield("BBHBJet"+mssmMasses_[m],postfix),out.ZTT,out.QCD,out.W,out.ZJFT,out.ZLFT,out.TOP,out.VV);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      if(luminosityErr_!=0)
	fprintf(pfile,"lumi     lnN %.3f           %.3f          %.3f           %.3f           %.3f              -             -             -             -             -             -             -          luminosity\n",
		1+luminosityErr_,1+luminosityErr_,1+luminosityErr_,1+luminosityErr_,1+luminosityErr_);
      
      if(muID_!=0)
	fprintf(pfile,"CMS_eff_m     lnN   %.3f          %.3f          %.3f          %.3f           %.3f             %.3f          -             -             %.3f          %.3f          %.3f          %.3f       muon ID /HLT\n",
	        1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_);
      if(tauID_!=0)
	fprintf(pfile,"CMS_eff_t    lnN   %.3f          %.3f          %.3f          %.3f          %.3f          %.3f          -             -             -             -             %.3f          %.3f        Tau IDf\n",
	       1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_);
    if(eleID_!=0)
      fprintf(pfile,"CMS_eff_e    lnN   %.3f          %.3f          %.3f          %.3f          %.3f          %.3f             -             -             %.3f          %.3f          %.3f           %.3f      Electron ID\n",
	     1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_);
    if(zttScale_!=0)
      fprintf(pfile,"CMS_htt_zttNorm lnN   -             -             -               -            -             %.3f          -             -             %.3f          %.3f          -              -         ZTT Scale  \n",
	     1+zttScaleErr_/zttScale_,1+zttScaleErr_/zttScale_,1+zttScaleErr_/zttScale_);
      fprintf(pfile,"CMS_htt_zttExtrap_nob  lnN   -             -             -               -            -             %.8f          -             -             -          -          -              -         ZTT Scale  \n",
	     1+out.dZTTCORR/out.ZTTCORR);

    for(unsigned int j=0;j<shifts_.size();++j)
	fprintf(pfile,"%s    shape    1.0             1.0             1.0             1.0             1.0             1.0             -             -             -             -              -              -      shape\n",shiftsPostFix_[j].c_str());


    fprintf(pfile,"CMS_htt_%s_QCDNorm gmN %d      -             -             -             -             -             -             %.3f          -             -             -              -              -      QCD Background\n",(channel_+postfix).c_str(),(int)out.QCDSDB,qcdFactor_);
    fprintf(pfile,"CMS_htt_%s_QCDSyst lnN        -             -             -             -          -                      -          %.3f        -              -              -            -           -      QCD Background Systematics\n",(channel_).c_str(),1.+qcdFactorErr_/qcdFactor_);
    fprintf(pfile,"CMS_htt_ttbarNorm  lnN      -             -            -             -              -              -             -             -             -             -              %.3f           -      TTbar background  \n",1+out.dTOP/out.TOP);
    fprintf(pfile,"CMS_htt_DiBosonNorm  lnN      -             -             -             -             -              -             -             -             -             -              -              %.3f   DiBoson background \n",1+out.dVV/out.VV);
    fprintf(pfile,"CMS_htt_%s_WNorm   lnN        -             -             -             -             -             -             -             %.3f          -             -              -              -      W Backghround \n",(channel_+postfix).c_str(),(int)1+out.dW/out.W);
    fprintf(pfile,"CMS_htt_%s_ZJFTNorm  lnN      -            -             -             -              -             -             -             -             %.3f          -              -              -      Z(jet->tau) background\n",(channel_+postfix).c_str(),1+out.dZJFT/out.ZJFT);
    fprintf(pfile,"CMS_htt_%s_ZLFTNorm  lnN      -             -            -            -               -             -             -             -             -             %.3f           -              -      Z(l->tau)   background\n",(channel_+postfix).c_str(),1+out.dZLFT/out.ZLFT);

    fprintf(pfile,"CMS_eff_b      lnN      -             -             -             -             %.3f          -             -              -              -             -              %.3f           -    BTag efficiency \n",1-bIDErr_/bID_,1-bIDErr_/bID_);
    fprintf(pfile,"CMS_fake_b   lnN      -             %.3f          -             %.3f           -             -             -             -             -             -              -              -     BTag MisTag \n",1-bMisIDErr_/bMisID_,1-bMisIDErr_/bMisID_);


    fprintf(pfile,"CMS_scale_j      lnN      0.98            0.98             0.98             0.98             0.98          -             -              -            -                -             0.93              0.97      Jet Scale \n");
    fprintf(pfile,"CMS_scale_met      lnN      -             -             -             -             -          -             -              -              -             -            1.03          1.04   MET scale \n");

    fclose(pfile);
    }
  
 

  }



  void makeMSSMEMuDataCardNoBTag(BkgOutput out,std::string postfix) {
    for(unsigned int m = 0;m<mssmMasses_.size();++m) {
      FILE *pfile = fopen(("datacards/"+channel_+postfix+"_mA"+mssmMasses_[m]+".txt").c_str(),"w");

      fprintf(pfile,"imax 1\n");
      fprintf(pfile,"jmax *\n");
      fprintf(pfile,"kmax *\n");
      fprintf(pfile,"shapes *  *    %s  $CHANNEL/$PROCESS $CHANNEL/$PROCESS_$SYSTEMATIC \n",(channel_+".root").c_str());
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      fprintf(pfile,"observation %d\n",(int)out.DATA);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      std::string ch = channel_+postfix;
      fprintf(pfile,"bin            %s            %s             %s            %s             %s                 %s            %s            %s            %s\n",ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str());
      fprintf(pfile,"process        GGHNoJet%s   GGHJet%s        BBHNoJet%s     BBHJet%s     BBHBJet%s           ZTT           FAKES           TT            VV\n",mssmMasses_[m].c_str(),mssmMasses_[m].c_str(),mssmMasses_[m].c_str(),mssmMasses_[m].c_str(),mssmMasses_[m].c_str());
      fprintf(pfile,"process        -4              -3           -2              -1            0                 1             2             3             4\n");
      fprintf(pfile,"rate           %.3f            %.3f          %.3f         %.3f          %.3f             %.3f          %.3f          %.3f             %.3f\n",
	      getYield("GGHNoJet"+mssmMasses_[m],postfix),getYield("GGHJet"+mssmMasses_[m],postfix),getYield("BBHNoJet"+mssmMasses_[m],postfix),getYield("BBHJet"+mssmMasses_[m],postfix),getYield("BBHBJet"+mssmMasses_[m],postfix),out.ZTT,out.QCD,out.TOP,out.VV);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      if(luminosityErr_!=0)
	fprintf(pfile,"lumi     lnN %.3f           %.3f          %.3f           %.3f           %.3f              -             -             -             -             -             -             -          luminosity\n",
		1+luminosityErr_,1+luminosityErr_,1+luminosityErr_,1+luminosityErr_,1+luminosityErr_);
      
      if(muID_!=0)
	fprintf(pfile,"CMS_eff_m     lnN   %.3f          %.3f          %.3f          %.3f           %.3f             %.3f          -                 %.3f          %.3f       muon ID /HLT\n",
	        1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_);
      if(eleID_!=0)
	fprintf(pfile,"CMS_eff_e    lnN   %.3f          %.3f          %.3f          %.3f          %.3f          %.3f             -             %.3f           %.3f      Electron ID\n",
	     1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_);
    if(zttScale_!=0)
      fprintf(pfile,"CMS_htt_zttNorm lnN   -             -             -               -            -             %.3f          -             -                -         ZTT Scale  \n",
	     1+zttScaleErr_/zttScale_);
      fprintf(pfile,"CMS_htt_zttExtrap_nob lnN   -             -             -               -            -             %.3f          -             -                -         ZTT Scale  \n",
	     1+out.dZTTCORR/out.ZTTCORR);
    for(unsigned int j=0;j<shifts_.size();++j)
      fprintf(pfile,"%s    shape    1.0             1.0             1.0             1.0             1.0             1.0            -             -           shape\n",shiftsPostFix_[j].c_str());
    fprintf(pfile,"CMS_htt_%s_FakeNorm lnN          -               -               -                -                -       -     %.3f           -              -               QCD Background Systematics\n",(channel_).c_str(),1.+qcdFactorErr_/qcdFactor_);

    fprintf(pfile,"CMS_htt_ttbarNorm  lnN      -             -            -             -              -              -             -             %.3f           -      TTbar background  \n",1+out.dTOP/out.TOP);
    fprintf(pfile,"CMS_htt_DiBosonNorm  lnN      -             -             -             -             -              -             -             -           %.3f   DiBoson background \n",1+out.dVV/out.VV);
    fprintf(pfile,"CMS_eff_b      lnN            -             -             -             -             %.3f          -             -              %.3f           -    BTag efficiency \n",1-bIDErr_/bID_,1-bIDErr_/bID_);
    fprintf(pfile,"CMS_fake_b   lnN              -             %.3f          -             %.3f           -            -             -              -              -     BTag MisTag \n",1-bMisIDErr_/bMisID_,1-bMisIDErr_/bMisID_);



    fprintf(pfile,"CMS_scale_j      lnN      0.98            0.98             0.98             0.98             0.98          -             -                 0.93              0.97      Jet Scale \n");
    fprintf(pfile,"CMS_scale_met      lnN      -             -                -                -                 -            -             -                 1.03          1.04   MET scale \n");

    fclose(pfile);
    }
  
 

  }



  void makeZTTLTauDataCard(BkgOutput out,std::string postfix) {
      FILE *pfile = fopen(("datacards/"+channel_+postfix+".txt").c_str(),"w");
      fprintf(pfile,"imax 1\n");
      fprintf(pfile,"jmax *\n");
      fprintf(pfile,"kmax *\n");
      fprintf(pfile,"shapes *  *    %s  $CHANNEL/$PROCESS $CHANNEL/$PROCESS_$SYSTEMATIC \n",(channel_+".root").c_str());
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      fprintf(pfile,"observation %d\n",(int)out.DATA);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      std::string ch = channel_+postfix;
      fprintf(pfile,"bin             %s            %s            %s            %s            %s            %s            %s\n",ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str());
      fprintf(pfile,"process         ZTT           QCD           W             ZJ            ZL            TT            VV\n");
      fprintf(pfile,"process          0             1             2             3             4             5             6\n");
      fprintf(pfile,"rate           %.3f          %.3f          %.3f          %.3f          %.3f          %.3f           %.3f\n",
	     out.ZTT,out.QCD,out.W,out.ZJFT,out.ZLFT,out.TOP,out.VV);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      if(muID_!=0)
	fprintf(pfile,"CMS_eff_m     lnN    %.3f          -             -             %.3f          %.3f          %.3f          %.3f       muon ID /HLT\n",
	       1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_);
      if(tauID_!=0)
	fprintf(pfile,"CMS_eff_t    lnN     %.3f          -             -             -             -             %.3f          %.3f        Tau IDf\n",
	       1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_);
      if(eleID_!=0)
	fprintf(pfile,"CMS_eff_e    lnN       %.3f          -             -             %.3f          %.3f          %.3f           %.3f      Electron ID\n",
	     1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_);
      fprintf(pfile,"CMS_htt_ttbarNorm  lnN       -             -             -             -             -              %.3f           -      TTbar background  \n",1+out.dTOP/out.TOP);
      fprintf(pfile,"CMS_htt_DiBosonNorm  lnN    -             -             -             -             -              -              %.3f   DiBoson background \n",1+out.dVV/out.VV);

    for(unsigned int j=0;j<shifts_.size();++j)
      fprintf(pfile,"%s    shape            1             -             -             -             -              -              -      shape\n",shiftsPostFix_[j].c_str());
    fprintf(pfile,"CMS_htt_%s_QCDNorm gmN   %d   -            %.3f          -             -             -              -              -      QCD Background\n",(channel_+postfix).c_str(),(int)out.QCDSDB,qcdFactor_);
    fprintf(pfile,"CMS_htt_%s_QCDSyst lnN        -             %.3f          -             -             -              -              -      QCD Background Systematics\n",(channel_).c_str(),1.+qcdFactorErr_/qcdFactor_);
    fprintf(pfile,"CMS_htt_%s_WNorm     lnN      -             -             %.3f          -             -              -              -      W Backghround \n",(channel_+postfix).c_str(),1+out.dW/out.W);
    fprintf(pfile,"CMS_htt_%s_ZJetFakeTau  lnN  -             -             -             %.3f          -              -              -      Z(jet->tau) background\n",(channel_+postfix).c_str(),1+out.dZJFT/out.ZJFT);
    fprintf(pfile,"CMS_htt_%s_ZLeptonFakeTau  lnN -             -             -             -             %.3f           -              -      Z(l->tau)   background\n",(channel_+postfix).c_str(),1+out.dZLFT/out.ZLFT);
    fclose(pfile);

  }


  void makeSMLTauDataCardNoVBF(BkgOutput out,std::string postfix, std::string rootS) {
    for(unsigned int m = 0;m<smMassesDC_.size();++m) {
      FILE *pfile = fopen(("datacards/"+channel_+postfix+"_mH"+smMassesDC_[m]+".txt").c_str(),"w");

      fprintf(pfile,"imax 1\n");
      fprintf(pfile,"jmax *\n");
      fprintf(pfile,"kmax *\n");
      fprintf(pfile,"shapes *  *    %s  $CHANNEL/$PROCESS $CHANNEL/$PROCESS_$SYSTEMATIC \n",(channel_+"SM.root").c_str());
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      fprintf(pfile,"observation %d\n",(int)out.DATA);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      std::string ch = channel_+postfix;
      fprintf(pfile,"bin       %s        %s            %s            %s            %s            %s            %s            %s            %s            %s\n",ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str());
      fprintf(pfile,"process   VH%s     ggH%s        qqH%s        ZTT           QCD           W             ZJ            ZL            TT            VV\n",smMassesDC_[m].c_str(),smMassesDC_[m].c_str(),smMassesDC_[m].c_str());
      fprintf(pfile,"process   -2     -1            0             1             2             3             4             5             6             7\n");
      fprintf(pfile,"rate      %.3f     %.3f          %.3f          %.3f          %.3f          %.3f          %.3f          %.3f          %.3f          %.3f\n",
	      getYield("VH"+smMassesDC_[m],postfix),getYield("ggH"+smMassesDC_[m],postfix),getYield("qqH"+smMassesDC_[m],postfix),out.ZTT,out.QCD,out.W,out.ZJFT,out.ZLFT,out.TOP,out.VV);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      if(luminosityErr_!=0)
	fprintf(pfile,"lumi_%s     lnN    %.3f        %.3f          %.3f          -             -             -             -             -             -             -          luminosity\n",
		rootS.c_str(),1+luminosityErr_,1+luminosityErr_,1+luminosityErr_);      
      if(muID_!=0)
	fprintf(pfile,"CMS_eff_m     lnN   %.3f     %.3f          %.3f          %.3f          -             -             %.3f          %.3f          %.3f          %.3f       muon ID /HLT\n",
		1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_);
      if(tauID_!=0)
	fprintf(pfile,"CMS_eff_t    lnN    %.3f      %.3f          %.3f          %.3f          -             -             -             -             %.3f          %.3f        Tau IDf\n",
		1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_);
    if(eleID_!=0)
      fprintf(pfile,"CMS_eff_e    lnN      %.3f       %.3f          %.3f          %.3f          -             -             %.3f          %.3f          %.3f           %.3f      Electron ID\n",
	      1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_);
    if(zttScale_!=0)
      fprintf(pfile,"CMS_htt_zttNorm_%s lnN   -         -             -             %.3f          -             -             %.3f          %.3f          -              -         ZTT Scale  \n",
	     rootS.c_str(),1+zttScaleErr_/zttScale_,1+zttScaleErr_/zttScale_,1+zttScaleErr_/zttScale_);
    fprintf(pfile,"CMS_htt_ttbarNorm_%s      lnN    -       -             -             -             -             -             -             -              %.3f           -      TTbar background  \n",rootS.c_str(),1+out.dTOP/out.TOP);
    fprintf(pfile,"CMS_htt_DiBosonNorm_%s     lnN  -           -             -             -             -             -             -             -              -              %.3f   DiBoson background \n",rootS.c_str(),1+out.dVV/out.VV);
    fprintf(pfile,"CMS_htt_%s_WNorm_%s       lnN      -        -             -             -             -             %.3f          -             -              -              -      W Background \n",channel_.c_str(),rootS.c_str(),1+out.dW/out.W);
    fprintf(pfile,"CMS_htt_%s_QCDNorm_%s gmN     %d   -        -             -             -             %.3f          -             -             -              -              -      QCD Background\n",(channel_+postfix).c_str(),rootS.c_str(),(int)out.QCDSDB,qcdFactor_);
    fprintf(pfile,"CMS_htt_%s_QCDSyst_%s lnN          -       -             -             -             %.3f          -             -             -              -              -      QCD Background\n",(channel_+postfix).c_str(),rootS.c_str(),1+qcdFactorErr_/qcdFactor_);
    fprintf(pfile,"CMS_htt_%s_ZJetFakeTau_%s lnN      -        -             -             -             -             -             %.3f          -              -              -      Z(jet->tau) background\n",(channel_+postfix).c_str(),rootS.c_str(),1+out.dZJFT/out.ZJFT);
    fprintf(pfile,"CMS_htt_%s_ZLeptonFakeTau_%s   lnN  -        -             -             -             -             -             -             %.3f           -              -      Z(l->tau)   background\n",(channel_+postfix).c_str(),rootS.c_str(),1+out.dZLFT/out.ZLFT);

       for(unsigned int j=0;j<shifts_.size();++j)
	     fprintf(pfile,"%s_%s    shape    1             1             1             1             -             -             -             -              -             -   -      shape\n",shiftsPostFix_[j].c_str(),rootS.c_str());

    fprintf(pfile,"CMS_scale_j_%s           lnN  0.96        0.99          0.92          -            -              -        -         -          0.94            0.97    Jet scale\n",rootS.c_str());
    fprintf(pfile,"CMS_scale_met_%s           lnN  1.05        1.05          1.05          -            -             -     1.05      1.05          1.02            1.06    Met scale\n",rootS.c_str());
       
    fprintf(pfile,"pdf_qqbar            lnN  -        -          1.08          -            -              -        -         -          -            -    PDF VBF\n");
    fprintf(pfile,"pdf_vh               lnN  1.08     -            -           -            -              -        -         -          -            -    PDF VBF\n");
    fprintf(pfile,"pdf_gg               lnN  -    1.08       -             -            -              -        -         -          -            -    PDF VBF\n");
    fprintf(pfile,"QCDscale_ggH         lnN  -    1.12       -             -            -              -        -         -          -            -    PDF VBF\n");
    fprintf(pfile,"QCDscale_qqH         lnN  -    -          1.035         -            -              -        -         -          -            -    PDF VBF\n");
    fprintf(pfile,"UEPS                 lnN  0.96    0.96       0.96          -            -              -        -         -          -            -    PDF VBF\n");


    fclose(pfile);
    }
  
  }



  void makeSMEMuDataCardNoVBF(BkgOutput out,std::string postfix) {
    for(unsigned int m = 0;m<smMassesDC_.size();++m) {
      FILE *pfile = fopen(("datacards/"+channel_+postfix+"_mH"+smMassesDC_[m]+".txt").c_str(),"w");

      fprintf(pfile,"imax 1\n");
      fprintf(pfile,"jmax *\n");
      fprintf(pfile,"kmax *\n");
      fprintf(pfile,"shapes *  *    %s  $CHANNEL/$PROCESS $CHANNEL/$PROCESS_$SYSTEMATIC \n",(channel_+"SM.root").c_str());
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      fprintf(pfile,"observation %d\n",(int)out.DATA);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      std::string ch = channel_+postfix;
      fprintf(pfile,"bin       %s     %s            %s            %s            %s         %s           %s\n",ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str());
      fprintf(pfile,"process   VH%s     ggH%s        qqH%s          ZTT           FAKES        TT            VV\n",smMassesDC_[m].c_str(),smMassesDC_[m].c_str(),smMassesDC_[m].c_str());
      fprintf(pfile,"process   -2      -1            0             1             2             3            4\n");
      fprintf(pfile,"rate      %.3f     %.3f          %.3f          %.3f          %.3f          %.3f          %.3f\n",
	      getYield("VH"+smMassesDC_[m],postfix),getYield("ggH"+smMassesDC_[m],postfix),getYield("qqH"+smMassesDC_[m],postfix),out.ZTT,out.QCD,out.TOP,out.VV);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      if(luminosityErr_!=0)
	fprintf(pfile,"lumi     lnN    %.3f    %.3f          %.3f          -             -             -             -             -             -             -          luminosity\n",
		1+luminosityErr_,1+luminosityErr_,1+luminosityErr_);      
      if(muID_!=0)
	fprintf(pfile,"CMS_eff_m     lnN   %.3f   %.3f          %.3f          %.3f          -         %.3f          %.3f       muon ID /HLT\n",
	       1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_);
      if(eleID_!=0)
	fprintf(pfile,"CMS_eff_e    lnN    %.3f      %.3f          %.3f          %.3f          -           %.3f          %.3f       Electron ID\n",
	     1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_);
    if(zttScale_!=0)
      fprintf(pfile,"CMS_htt_zttNorm lnN   -         -             -             %.3f          -             -         -         ZTT Scale  \n",
	     1+zttScaleErr_/zttScale_);
      fprintf(pfile,"CMS_htt_zttExtrap_sm0 lnN   -         -             -             %.3f          -             -         -         ZTT Scale  \n",
	     1+out.dZTTCORR/out.ZTTCORR);
    fprintf(pfile,"CMS_htt_ttbarNorm      lnN  -         -             -             -             -              %.3f           -      TTbar background  \n",1+out.dTOP/out.TOP);
    fprintf(pfile,"CMS_htt_DiBosonNorm     lnN -         -             -             -             -           -              %.3f   DiBoson background \n",1+out.dVV/out.VV);
    fprintf(pfile,"CMS_htt_%s_FakeNorm    lnN  -         -             -             -             %.3f          -             -      QCD Background\n",(channel_+postfix).c_str(),1+out.dQCD/out.QCD);
       for(unsigned int j=0;j<shifts_.size();++j)
	   fprintf(pfile,"%s    shape    1             1             1               1             -             -             -        shape\n",shiftsPostFix_[j].c_str());

//    fprintf(pfile,"CMS_scale_j           lnN  0.96        0.99          0.92          -            -              0.94            0.97    Jet scale\n");
    fprintf(pfile,"CMS_scale_met           lnN  1.05        1.05          1.05          -            -              1.02            1.06    Met scale\n");
    fprintf(pfile,"pdf_qqbar            lnN  -    -          1.08          -            -              -            -    PDF VBF\n");
    fprintf(pfile,"pdf_vh               lnN  1.08    -       -          -            -              -            -    PDF VBF\n");
    fprintf(pfile,"pdf_gg               lnN  -    1.08       -             -            -              -            -    PDF VBF\n");
    fprintf(pfile,"QCDscale_ggH         lnN  -    1.12       -             -            -              -            -    PDF VBF\n");
    fprintf(pfile,"QCDscale_qqH         lnN  -    -          1.035         -            -              -            -    PDF VBF\n");
    fprintf(pfile,"UEPS                 lnN  0.96    0.96       0.96          -            -              -            -    PDF VBF\n");
    fclose(pfile);
    }
  

  }



  void makeSMLTauDataCardVBF(BkgOutput out,std::string postfix, std::string rootS) {
    for(unsigned int m = 0;m<smMassesDC_.size();++m) {
      FILE *pfile = fopen(("datacards/"+channel_+postfix+"_mH"+smMassesDC_[m]+".txt").c_str(),"w");

      fprintf(pfile,"imax 1\n");
      fprintf(pfile,"jmax *\n");
      fprintf(pfile,"kmax *\n");
      fprintf(pfile,"shapes *  *    %s  $CHANNEL/$PROCESS $CHANNEL/$PROCESS_$SYSTEMATIC \n",(channel_+"SM.root").c_str());
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      fprintf(pfile,"observation %d\n",(int)out.DATA);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      std::string ch = channel_+postfix;
      fprintf(pfile,"bin            %s           %s            %s            %s            %s            %s            %s            %s            %s\n",ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str());
      fprintf(pfile,"process        VH%s        ggH%s        qqH%s        ZTT           QCD           W             ZLL             TT            VV\n",smMassesDC_[m].c_str(),smMassesDC_[m].c_str(),smMassesDC_[m].c_str());
      fprintf(pfile,"process        -2           -1            0            1             2           3             4             5             6  \n");
      fprintf(pfile,"rate           %.3f        %.3f          %.3f          %.3f          %.3f          %.3f          %.3f          %.3f          %.3f\n",
	     getYield("VH"+smMassesDC_[m],postfix),getYield("ggH"+smMassesDC_[m],postfix),getYield("qqH"+smMassesDC_[m],postfix),out.ZTT,out.QCD,out.W,out.ZLFT,out.TOP,out.VV);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      if(luminosityErr_!=0)
	fprintf(pfile,"lumi_%s     lnN   %.3f     %.3f          %.3f          -             -             -             -            -             -          luminosity\n",
		rootS.c_str(),1+luminosityErr_,1+luminosityErr_,1+luminosityErr_);
      for(unsigned int j=0;j<shifts_.size();++j)
	  fprintf(pfile,"%s_%s    shape    1   1     1       1         -           -          -         -        -                 shape(Ignore small ones that cause instabilities)\n",shiftsPostFix_[j].c_str(),rootS.c_str());
	  
      if(muID_!=0)
	fprintf(pfile,"CMS_eff_m     lnN   %.3f  %.3f          %.3f          %.3f          -             -             %.3f            %.3f          %.3f       muon ID /HLT\n",
		1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_);
      if(tauID_!=0)
	fprintf(pfile,"CMS_eff_t     lnN   %.3f   %.3f          %.3f          %.3f          -             -             -                     %.3f          %.3f        Tau IDf\n",
		1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_);
      if(eleID_!=0)
	fprintf(pfile,"CMS_eff_e       lnN %.3f   %.3f          %.3f          %.3f          -             -             %.3f               %.3f           %.3f      Electron ID\n",
		1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_);
      if(zttScale_!=0)
	fprintf(pfile,"CMS_htt_zttNorm_%s lnN   -             -             -             %.3f          -             -             %.3f                    -              -         ZTT Scale  \n",
		rootS.c_str(),1+zttScaleErr_/zttScale_,1+zttScaleErr_/zttScale_);

    /////////FIXPOINT
      fprintf(pfile,"CMS_htt_ztt_extrap_vbf_%s lnN   -                 -             -             %.3f          -             -                %.3f          -              -         ZTT Extrapolation  \n",
	      rootS.c_str(),1+out.dZTTCORR/out.ZTTCORR,1+vbfFactorZErr_/vbfFactorZ_);
    fprintf(pfile,"CMS_htt_ttbarNorm_%s          lnN   -   -             -             -             -             -             -                           %.3f           -      TTbar background  \n",rootS.c_str(),1+out.dTOP/out.TOP);
    fprintf(pfile,"CMS_htt_DiBosonNorm_%s        lnN    -  -             -             -             -             -             -                           -              %.3f   DiBoson background \n",rootS.c_str(),1+out.dVV/out.VV);
    fprintf(pfile,"CMS_htt_%s_QCDSyst_%s             lnN -       -             -             -             %.3f          -             -             -                            -      QCD Background\n",(channel_+postfix).c_str(),rootS.c_str(),1+out.dQCD/out.QCD);
    fprintf(pfile,"CMS_htt_W_extrap_vbf_%s           lnN  -    -             -             -             -             %.3f          -             -                            -      W Extrapolation \n",rootS.c_str(),1+vbfFactorWErr_/vbfFactorW_);
    fprintf(pfile,"CMS_htt_%s_WNorm_%s                  lnN   -   -             -             -             -             %.3f          -             -              -              -      W Background \n",channel_.c_str(),rootS.c_str(),1+out.dWCORR/out.WCORR);
    fprintf(pfile,"CMS_htt_ZLLNorm_%s                  lnN   -   -             -             -             -             -          %.3f           -              -      Z(l->tau)   background\n",rootS.c_str(),1+out.dZLFT/out.ZLFT);

    fprintf(pfile,"CMS_scale_j_%s         lnN  1.20        1.03          1.08          -            -              -         -          1.15            1.10    Jet scale\n", rootS.c_str());
    fprintf(pfile,"CMS_scale_met_%s       lnN  1.05        1.05          1.05          -            -              -      1.05       1.10            1.10    Met scale\n", rootS.c_str());

    fprintf(pfile,"pdf_qqbar            lnN -     -          1.08          -            -              -        -         -          -            -    PDF VBF\n");
    fprintf(pfile,"pdf_gg               lnN -     1.08       -             -            -              -        -         -          -            -    PDF GGH\n");
    fprintf(pfile,"pdf_vh               lnN 1.08   -         -             -            -              -        -         -          -            -    PDF GGH\n");
    fprintf(pfile,"QCDscale_ggH2in      lnN  -   1.30        -         -            -              -        -         -          -            -    QCD scale \n");
    fprintf(pfile,"QCDscale_qqH         lnN  -    -          1.04         -            -              -        -         -          -            -    QCD scale VBF\n");
    fprintf(pfile,"UEPS                 lnN  1.04    1.04       1.04          -            -              -        -         -          -            -    UEPS VBF\n");
    fclose(pfile);
    }
  
 

  }




  void makeSMEMuDataCardVBF(BkgOutput out,std::string postfix) {
    for(unsigned int m = 0;m<smMassesDC_.size();++m) {
      FILE *pfile = fopen(("datacards/"+channel_+postfix+"_mH"+smMassesDC_[m]+".txt").c_str(),"w");

      fprintf(pfile,"imax 1\n");
      fprintf(pfile,"jmax *\n");
      fprintf(pfile,"kmax *\n");
      fprintf(pfile,"shapes *  *    %s  $CHANNEL/$PROCESS $CHANNEL/$PROCESS_$SYSTEMATIC \n",(channel_+"SM.root").c_str());
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      fprintf(pfile,"observation %d\n",(int)out.DATA);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      std::string ch = channel_+postfix;
      fprintf(pfile,"bin            %s           %s            %s            %s            %s            %s            %s        \n",ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str());
      fprintf(pfile,"process   VH%s     ggH%s        qqH%s        ZTT           FAKES         TT            VV\n",smMassesDC_[m].c_str(),smMassesDC_[m].c_str(),smMassesDC_[m].c_str());
      fprintf(pfile,"process   -2     -1            0            1             2           3             4\n");
      fprintf(pfile,"rate      %.3f     %.3f          %.3f         %.3f          %.3f          %.3f       %.3f\n",
	     getYield("VH"+smMassesDC_[m],postfix),getYield("ggH"+smMassesDC_[m],postfix),getYield("qqH"+smMassesDC_[m],postfix),out.ZTT,out.QCD,out.TOP,out.VV);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      if(luminosityErr_!=0)
	fprintf(pfile,"lumi     lnN   %.3f    %.3f          %.3f          -             -             -             -          luminosity\n",
	   1+luminosityErr_,1+luminosityErr_,1+luminosityErr_);
      for(unsigned int j=0;j<shifts_.size();++j)
	fprintf(pfile,"%s    shape    1      1     1       1         -               -        -     -            shape(Ignore small ones that cause instabilities)\n",shiftsPostFix_[j].c_str());

      if(muID_!=0)
	fprintf(pfile,"CMS_eff_m     lnN   %.3f   %.3f          %.3f          %.3f          -             %.3f          %.3f       muon ID /HLT\n",
		1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_);
      if(tauID_!=0)
	fprintf(pfile,"CMS_eff_t     lnN   %.3f  %.3f          %.3f          %.3f          -             %.3f          %.3f        Tau IDf\n",
	       1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_);
      if(eleID_!=0)
	fprintf(pfile,"CMS_eff_e     lnN   %.3f   %.3f          %.3f          %.3f          -            %.3f           %.3f      Electron ID\n",
		1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_);
      if(zttScale_!=0)
	fprintf(pfile,"CMS_htt_zttNorm lnN   -  -             -             %.3f          -              -              -         ZTT Scale  \n",
		1+zttScaleErr_/zttScale_);
    /////////FIXPOINT
      fprintf(pfile,"CMS_htt_ztt_extrap_vbf lnN  -     -          -             %.3f          -            -              -         ZTT Extrapolation  \n",
	      1+out.dZTTCORR/out.ZTTCORR);
    fprintf(pfile,"CMS_htt_ttbarNorm          lnN   -   -             -             -             -         %.3f           -      TTbar background  \n",1+out.dTOP/out.TOP);
    fprintf(pfile,"CMS_htt_DiBosonNorm        lnN   -   -             -             -             -          -              %.3f   DiBoson background \n",1+out.dVV/out.VV);
    fprintf(pfile,"CMS_htt_%s_FakeNorm        lnN   -   -             -             -             %.3f          -             -       FAKE Background\n",(channel_+postfix).c_str(),1+out.dQCD/out.QCD);

    fprintf(pfile,"CMS_scale_j         lnN  1.20        1.03          1.08          -            -              1.15            1.10    Jet scale\n");
    fprintf(pfile,"CMS_scale_met       lnN  1.05        1.05          1.05          -            -              1.10            1.10    Met scale\n");


    fprintf(pfile,"pdf_qqbar            lnN   -   -          1.08          -            -              -        -       PDF VBF\n");
    fprintf(pfile,"pdf_gg               lnN   -   1.08       -             -            -              -        -       PDF GGH\n");
    fprintf(pfile,"pdf_vh               lnN   1.08 -         -             -            -              -        -       PDF GGH\n");
    fprintf(pfile,"QCDscale_ggH2in      lnN   -   1.30       -         -            -              -        -           QCD scale \n");
    fprintf(pfile,"QCDscale_qqH         lnN   -   -          1.04         -            -              -        -        QCD scale VBF\n");
    fprintf(pfile,"UEPS                 lnN   1.04   1.04       1.04          -            -              -        -       UEPS VBF\n");
    fclose(pfile);
    }
  
 

  }







  void makeSMLTauDataCardBoost(BkgOutput out,std::string postfix) {
    for(unsigned int m = 0;m<smMassesDC_.size();++m) {
      FILE *pfile = fopen(("datacards/"+channel_+postfix+"_mH"+smMassesDC_[m]+".txt").c_str(),"w");

      fprintf(pfile,"imax 1\n");
      fprintf(pfile,"jmax *\n");
      fprintf(pfile,"kmax *\n");
      fprintf(pfile,"shapes *  *    %s  $CHANNEL/$PROCESS $CHANNEL/$PROCESS_$SYSTEMATIC \n",(channel_+"SM.root").c_str());
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      fprintf(pfile,"observation %d\n",(int)out.DATA);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      std::string ch = channel_+postfix;
      fprintf(pfile,"bin          %s             %s            %s            %s            %s            %s            %s            %s            %s\n",ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str());
      fprintf(pfile,"process   VH%s      ggH%s        qqH%s        ZTT           QCD           W             ZLL             TT            VV\n",smMassesDC_[m].c_str(),smMassesDC_[m].c_str(),smMassesDC_[m].c_str());
      fprintf(pfile,"process    -2       -1            0            1             2           3             4             5             6  \n");
      fprintf(pfile,"rate       %.3f    %.3f          %.3f          %.3f          %.3f          %.3f          %.3f          %.3f          %.3f\n",
	 getYield("VH"+smMassesDC_[m],postfix),getYield("ggH"+smMassesDC_[m],postfix),getYield("qqH"+smMassesDC_[m],postfix),out.ZTT,out.QCD,out.W,out.ZLFT,out.TOP,out.VV);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      if(luminosityErr_!=0)
	fprintf(pfile,"lumi     lnN   %.3f   %.3f          %.3f          -             -             -             -            -             -          luminosity\n",
	   1+luminosityErr_,1+luminosityErr_,1+luminosityErr_);

      for(unsigned int j=0;j<shifts_.size();++j)
	  fprintf(pfile,"%s    shape    1     1     1       1         -           -          -         -        -                 shape(Ignore small ones that cause instabilities)\n",shiftsPostFix_[j].c_str());

      if(muID_!=0)
	fprintf(pfile,"CMS_eff_m     lnN   %.3f    %.3f          %.3f          %.3f          -             -             %.3f            %.3f          %.3f       muon ID /HLT\n",
		1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_);
      if(tauID_!=0)
	fprintf(pfile,"CMS_eff_t     lnN   %.3f   %.3f          %.3f          %.3f          -             -             -                     %.3f          %.3f        Tau IDf\n",
	       1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_);
      if(eleID_!=0)
	fprintf(pfile,"CMS_eff_e       lnN %.3f    %.3f          %.3f          %.3f          -             -             %.3f               %.3f           %.3f      Electron ID\n",
		1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_);
      if(zttScale_!=0)
	fprintf(pfile,"CMS_htt_zttNorm lnN   -     -             -             %.3f          -             -             %.3f                    -              -         ZTT Scale  \n",
		1+zttScaleErr_/zttScale_,1+zttScaleErr_/zttScale_);

    /////////FIXPOINT
      fprintf(pfile,"CMS_htt_ztt_extrap_boost lnN    - -             -             %.3f          -             -                %.3f          -              -         ZTT Extrapolation  \n",
	      1+out.dZTTCORR/out.ZTTCORR,1+boostFactorZErr_/boostFactorZ_);
    fprintf(pfile,"CMS_htt_ttbarNorm          lnN   -   -             -             -             -             -             -                           %.3f           -      TTbar background  \n",1+out.dTOP/out.TOP);
    fprintf(pfile,"CMS_htt_DiBosonNorm        lnN    -  -             -             -             -             -             -                           -              %.3f   DiBoson background \n",1+out.dVV/out.VV);
    fprintf(pfile,"CMS_htt_%s_QCDSyst             lnN -       -             -             -             %.3f          -             -             -                            -      QCD Background\n",channel_.c_str(),1+out.dQCD/out.QCD);
    fprintf(pfile,"CMS_htt_W_extrap_boost           lnN -      -             -             -             -             %.3f          -             -                            -      W Extrapolation \n",1+boostFactorWErr_/boostFactorW_);
    fprintf(pfile,"CMS_htt_%s_WNorm                  lnN  -    -             -             -             -             %.3f          -             -              -              -      W Background \n",channel_.c_str(),1+out.dWCORR/out.WCORR);
    fprintf(pfile,"CMS_htt_ZLL                  lnN    -  -             -             -             -             -          %.3f           -              -      Z(l->tau)   background\n",1+out.dZLFT/out.ZLFT);

    fprintf(pfile,"CMS_scale_j         lnN  1.02        1.02          1.05          -            -              -         -          1.03            1.08    Jet scale\n");
    fprintf(pfile,"CMS_scale_met       lnN  1.05        1.05          1.05          -            -              -      1.05       1.07            1.06    Met scale\n");
    fprintf(pfile,"pdf_qqbar            lnN      -         -          1.08          -            -              -        -         -          -            -    PDF VBF\n");
    fprintf(pfile,"pdf_gg               lnN      -       1.08       -             -            -              -        -         -          -            -    PDF GGH\n");
    fprintf(pfile,"pdf_vh               lnN      1.08    -          -             -            -              -        -         -          -            -    PDF GGH\n");
    fprintf(pfile,"QCDscale_ggH1in      lnN     -        1.25       -         -            -              -        -         -          -            -    QCD scale \n");
    fprintf(pfile,"QCDscale_qqH         lnN      -        -          1.04         -            -              -        -         -          -            -    QCD scale VBF\n");
    fprintf(pfile,"UEPS                 lnN      1.04     1.04       1.04          -            -              -        -         -          -            -    UEPS VBF\n");
    fclose(pfile);
    }
  
 

  }






  void makeSMLTauDataCardVH(BkgOutput out,std::string postfix) {
    for(unsigned int m = 0;m<smMassesDC_.size();++m) {
      FILE *pfile = fopen(("datacards/"+channel_+postfix+"_mH"+smMassesDC_[m]+".txt").c_str(),"w");

      fprintf(pfile,"imax 1\n");
      fprintf(pfile,"jmax *\n");
      fprintf(pfile,"kmax *\n");
      fprintf(pfile,"shapes *  *    %s  $CHANNEL/$PROCESS $CHANNEL/$PROCESS_$SYSTEMATIC \n",(channel_+"SM.root").c_str());
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      fprintf(pfile,"observation %d\n",(int)out.DATA);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      std::string ch = channel_+postfix;
      fprintf(pfile,"bin          %s             %s            %s            %s            %s            %s            %s            %s            %s\n",ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str());
      fprintf(pfile,"process   VH%s      ggH%s        qqH%s        ZTT           QCD           W             ZLL             TT            VV\n",smMassesDC_[m].c_str(),smMassesDC_[m].c_str(),smMassesDC_[m].c_str());
      fprintf(pfile,"process    -2       -1            0            1             2           3             4             5             6  \n");
      fprintf(pfile,"rate       %.3f    %.3f          %.3f          %.3f          %.3f          %.3f          %.3f          %.3f          %.3f\n",
	 getYield("VH"+smMassesDC_[m],postfix),getYield("ggH"+smMassesDC_[m],postfix),getYield("qqH"+smMassesDC_[m],postfix),out.ZTT,out.QCD,out.W,out.ZLFT,out.TOP,out.VV);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      if(luminosityErr_!=0)
	fprintf(pfile,"lumi     lnN   %.3f   %.3f          %.3f          -             -             -             -            -             -          luminosity\n",
	   1+luminosityErr_,1+luminosityErr_,1+luminosityErr_);

      for(unsigned int j=0;j<shifts_.size();++j)
	  fprintf(pfile,"%s    shape    1     1     1       1         -           -          -         -        -                 shape(Ignore small ones that cause instabilities)\n",shiftsPostFix_[j].c_str());
      if(muID_!=0)
	fprintf(pfile,"CMS_eff_m     lnN   %.3f    %.3f          %.3f          %.3f          -             -             %.3f            %.3f          %.3f       muon ID /HLT\n",
		1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_);
      if(tauID_!=0)
	fprintf(pfile,"CMS_eff_t     lnN   %.3f   %.3f          %.3f          %.3f          -             -             -                     %.3f          %.3f        Tau IDf\n",
	       1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_);
      if(eleID_!=0)
	fprintf(pfile,"CMS_eff_e       lnN %.3f    %.3f          %.3f          %.3f          -             -             %.3f               %.3f           %.3f      Electron ID\n",
		1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_);
      if(zttScale_!=0)
	fprintf(pfile,"CMS_htt_zttNorm lnN   -     -             -             %.3f          -             -             %.3f                    -              -         ZTT Scale  \n",
		1+zttScaleErr_/zttScale_,1+zttScaleErr_/zttScale_);

    /////////FIXPOINT
      fprintf(pfile,"CMS_htt_ztt_extrap_vh lnN    - -             -             %.3f          -             -                %.3f          -              -         ZTT Extrapolation  \n",
	      1+out.dZTTCORR/out.ZTTCORR,1+vhFactorZErr_/vhFactorZ_);
    fprintf(pfile,"CMS_htt_ttbarNorm          lnN   -   -             -             -             -             -             -                           %.3f           -      TTbar background  \n",1+out.dTOP/out.TOP);
    fprintf(pfile,"CMS_htt_DiBosonNorm        lnN    -  -             -             -             -             -             -                           -              %.3f   DiBoson background \n",1+out.dVV/out.VV);
    fprintf(pfile,"CMS_htt_%s_QCDSyst             lnN -       -             -             -             %.3f          -             -             -                            -      QCD Background\n",channel_.c_str(),1+out.dQCD/out.QCD);
    fprintf(pfile,"CMS_htt_W_extrap_boost           lnN -      -             -             -             -             %.3f          -             -                            -      W Extrapolation \n",1+vhFactorWErr_/vhFactorW_);
    fprintf(pfile,"CMS_htt_%s_WNorm                  lnN  -    -             -             -             -             %.3f          -             -              -              -      W Background \n",channel_.c_str(),1+out.dWCORR/out.WCORR);
    fprintf(pfile,"CMS_htt_ZLL                  lnN    -  -             -             -             -             -          %.3f           -              -      Z(l->tau)   background\n",1+out.dZLFT/out.ZLFT);

    fprintf(pfile,"CMS_scale_j         lnN  1.04        1.07          1.04          -            -              -         -          1.02            1.02    Jet scale\n");
    fprintf(pfile,"CMS_scale_met       lnN  1.05        1.05          1.05          -            -              -      1.05       1.06            1.04    Met scale\n");
    fprintf(pfile,"pdf_qqbar            lnN      -         -          1.08          -            -              -        -         -          -            -    PDF VBF\n");
    fprintf(pfile,"pdf_gg               lnN      -       1.08       -             -            -              -        -         -          -            -    PDF GGH\n");
    fprintf(pfile,"pdf_vh               lnN      1.08    -          -             -            -              -        -         -          -            -    PDF GGH\n");
    fprintf(pfile,"QCDscale_ggH1in      lnN     -        1.25       -         -            -              -        -         -          -            -    QCD scale \n");
    fprintf(pfile,"QCDscale_qqH         lnN      -        -          1.04         -            -              -        -         -          -            -    QCD scale VBF\n");
    fprintf(pfile,"UEPS                 lnN      1.04     1.04       1.04          -            -              -        -         -          -            -    UEPS VBF\n");
    fclose(pfile);
    }
  
 

  }




  void makeSMEMuDataCardBoost(BkgOutput out,std::string postfix) {
    for(unsigned int m = 0;m<smMassesDC_.size();++m) {
      FILE *pfile = fopen(("datacards/"+channel_+postfix+"_mH"+smMassesDC_[m]+".txt").c_str(),"w");

      fprintf(pfile,"imax 1\n");
      fprintf(pfile,"jmax *\n");
      fprintf(pfile,"kmax *\n");
      fprintf(pfile,"shapes *  *    %s  $CHANNEL/$PROCESS $CHANNEL/$PROCESS_$SYSTEMATIC \n",(channel_+"SM.root").c_str());
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      fprintf(pfile,"observation %d\n",(int)out.DATA);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      std::string ch = channel_+postfix;
      fprintf(pfile,"bin            %s               %s            %s            %s            %s            %s            %s\n",ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str());
      fprintf(pfile,"process        VH%s           ggH%s        qqH%s        ZTT           FAKES         TT            VV\n",smMassesDC_[m].c_str(),smMassesDC_[m].c_str(),smMassesDC_[m].c_str());
      fprintf(pfile,"process        -2              -1            0            1             2           3             4       \n");
      fprintf(pfile,"rate           %.3f            %.3f          %.3f          %.3f          %.3f          %.3f          %.3f\n",
	     getYield("VH"+smMassesDC_[m],postfix),getYield("ggH"+smMassesDC_[m],postfix),getYield("qqH"+smMassesDC_[m],postfix),out.ZTT,out.QCD,out.TOP,out.VV);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      if(luminosityErr_!=0)
	fprintf(pfile,"lumi     lnN   %.3f     %.3f          %.3f          -             -             -             -     luminosity\n",
	   1+luminosityErr_,1+luminosityErr_,1+luminosityErr_);
      for(unsigned int j=0;j<shifts_.size();++j)
	fprintf(pfile,"%s    shape    1    1     1       -         -           -    -                shape(Ignore small ones that cause instabilities)\n",shiftsPostFix_[j].c_str());

      if(muID_!=0)
	fprintf(pfile,"CMS_eff_m     lnN   %.3f    %.3f          %.3f          %.3f          -                 %.3f          %.3f       muon ID /HLT\n",
		1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_);
      if(eleID_!=0)
	fprintf(pfile,"CMS_eff_e       lnN   %.3f   %.3f          %.3f          %.3f          -               %.3f           %.3f      Electron ID\n",
		1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_);
      if(zttScale_!=0)
	fprintf(pfile,"CMS_htt_zttNorm lnN   -      -             -             %.3f          -                      -              -         ZTT Scale  \n",
		1+zttScaleErr_/zttScale_);

    fprintf(pfile,"CMS_scale_j         lnN  1.02        1.02          1.05          -            -              1.03            1.08    Jet scale\n");
    fprintf(pfile,"CMS_scale_met       lnN  1.05        1.05          1.05          -            -              1.07            1.06    Met scale\n");

    /////////FIXPOINT
      fprintf(pfile,"CMS_htt_ztt_extrap_boost lnN   -    -             -             %.3f          -               -              -         ZTT Extrapolation  \n",
	      1+out.dZTTCORR/out.ZTTCORR);
    fprintf(pfile,"CMS_htt_ttbarNorm          lnN   -   -             -             -             -            %.3f           -      TTbar background  \n",1+out.dTOP/out.TOP);
    fprintf(pfile,"CMS_htt_DiBosonNorm        lnN   -   -             -             -             -             -              %.3f   DiBoson background \n",1+out.dVV/out.VV);
    fprintf(pfile,"CMS_htt_%s_FakeNorm        lnN  -     -             -             -             %.3f          -             -     Fake  Background\n",channel_.c_str(),1+qcdFactorErr_/qcdFactor_);
    fprintf(pfile,"pdf_qqbar            lnN     -   -          1.08          -            -             -            -    PDF VBF\n");
    fprintf(pfile,"pdf_gg               lnN    -    1.08       -             -            -             -            -    PDF GGH\n");
    fprintf(pfile,"pdf_vh               lnN    1.08 -          -             -            -             -            -    PDF GGH\n");
    fprintf(pfile,"QCDscale_ggH1in      lnN   -    1.25       -         -            -                 -            -    QCD scale \n");
    fprintf(pfile,"QCDscale_qqH         lnN   -     -          1.04         -            -              -            -    QCD scale VBF\n");
    fprintf(pfile,"UEPS                 lnN   1.04   1.04       1.04          -            -             -            -    UEPS VBF\n");
    fclose(pfile);
    }
  
 

  }







  void makeSMEMuDataCardVH(BkgOutput out,std::string postfix) {
    for(unsigned int m = 0;m<smMassesDC_.size();++m) {
      FILE *pfile = fopen(("datacards/"+channel_+postfix+"_mH"+smMassesDC_[m]+".txt").c_str(),"w");

      fprintf(pfile,"imax 1\n");
      fprintf(pfile,"jmax *\n");
      fprintf(pfile,"kmax *\n");
      fprintf(pfile,"shapes *  *    %s  $CHANNEL/$PROCESS $CHANNEL/$PROCESS_$SYSTEMATIC \n",(channel_+"SM.root").c_str());
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      fprintf(pfile,"observation %d\n",(int)out.DATA);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      std::string ch = channel_+postfix;
      fprintf(pfile,"bin            %s               %s            %s            %s            %s            %s            %s\n",ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str());
      fprintf(pfile,"process        VH%s           ggH%s        qqH%s        ZTT           FAKES         TT            VV\n",smMassesDC_[m].c_str(),smMassesDC_[m].c_str(),smMassesDC_[m].c_str());
      fprintf(pfile,"process        -2              -1            0            1             2           3             4       \n");
      fprintf(pfile,"rate           %.3f            %.3f          %.3f          %.3f          %.3f          %.3f          %.3f\n",
	     getYield("VH"+smMassesDC_[m],postfix),getYield("ggH"+smMassesDC_[m],postfix),getYield("qqH"+smMassesDC_[m],postfix),out.ZTT,out.QCD,out.TOP,out.VV);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      if(luminosityErr_!=0)
	fprintf(pfile,"lumi     lnN   %.3f     %.3f          %.3f          -             -             -             -     luminosity\n",
	   1+luminosityErr_,1+luminosityErr_,1+luminosityErr_);
      for(unsigned int j=0;j<shifts_.size();++j)
	fprintf(pfile,"%s    shape    1    1     1       -         -           -    -                shape(Ignore small ones that cause instabilities)\n",shiftsPostFix_[j].c_str());

      if(muID_!=0)
	fprintf(pfile,"CMS_eff_m     lnN   %.3f    %.3f          %.3f          %.3f          -                 %.3f          %.3f       muon ID /HLT\n",
		1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_);
      if(eleID_!=0)
	fprintf(pfile,"CMS_eff_e       lnN   %.3f   %.3f          %.3f          %.3f          -               %.3f           %.3f      Electron ID\n",
		1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_);
      if(zttScale_!=0)
	fprintf(pfile,"CMS_htt_zttNorm lnN   -      -             -             %.3f          -                      -              -         ZTT Scale  \n",
		1+zttScaleErr_/zttScale_);

    /////////FIXPOINT
      fprintf(pfile,"CMS_htt_ztt_extrap_vh lnN   -    -             -             %.3f          -               -              -         ZTT Extrapolation  \n",
	      1+out.dZTTCORR/out.ZTTCORR);
    fprintf(pfile,"CMS_htt_ttbarNorm          lnN   -   -             -             -             -            %.3f           -      TTbar background  \n",1+out.dTOP/out.TOP);
    fprintf(pfile,"CMS_htt_DiBosonNorm        lnN   -   -             -             -             -             -              %.3f   DiBoson background \n",1+out.dVV/out.VV);
    fprintf(pfile,"CMS_htt_%s_FakeNorm        lnN  -     -             -             -             %.3f          -             -     Fake  Background\n",channel_.c_str(),1+qcdFactorErr_/qcdFactor_);


    fprintf(pfile,"CMS_scale_j         lnN  1.04        1.07          1.04          -            -             1.02            1.02    Jet scale\n");
    fprintf(pfile,"CMS_scale_met       lnN  1.05        1.05          1.05          -            -             1.06            1.04    Met scale\n");

    fprintf(pfile,"pdf_qqbar            lnN     -   -          1.08          -            -             -            -    PDF VBF\n");
    fprintf(pfile,"pdf_gg               lnN    -    1.08       -             -            -             -            -    PDF GGH\n");
    fprintf(pfile,"pdf_vh               lnN    1.08 -          -             -            -             -            -    PDF GGH\n");
    fprintf(pfile,"QCDscale_ggH1in      lnN   -    1.25       -         -            -                 -            -    QCD scale \n");
    fprintf(pfile,"QCDscale_qqH         lnN   -     -          1.04         -            -              -            -    QCD scale VBF\n");
    fprintf(pfile,"UEPS                 lnN   1.04   1.04       1.04          -            -             -            -    UEPS VBF\n");
    fclose(pfile);
    }
  
 

  }




  void makeMSSMLTauDataCardBTagged(BkgOutput out,std::string postfix) {
    for(unsigned int m = 0;m<mssmMasses_.size();++m) {
      FILE *pfile = fopen(("datacards/"+channel_+postfix+"_mA"+mssmMasses_[m]+".txt").c_str(),"w");

      fprintf(pfile,"imax 1\n");
      fprintf(pfile,"jmax *\n");
      fprintf(pfile,"kmax *\n");
      fprintf(pfile,"shapes *  *    %s  $CHANNEL/$PROCESS $CHANNEL/$PROCESS_$SYSTEMATIC \n",(channel_+".root").c_str());
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      fprintf(pfile,"observation %d\n",(int)out.DATA);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      std::string ch = channel_+postfix;
      fprintf(pfile,"bin            %s            %s            %s            %s            %s            %s             %s            %s\n",ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str());
      fprintf(pfile,"process        GGH%s        BBH%s        ZTT           QCD           W             ZLL             TT            VV\n",mssmMasses_[m].c_str(),mssmMasses_[m].c_str());
      fprintf(pfile,"process        -1            0             1             2             3             4             5              6\n");
      fprintf(pfile,"rate           %.3f          %.3f          %.3f          %.3f          %.3f          %.3f          %.3f          %.3f\n",
	      getYield("GGH"+mssmMasses_[m],postfix),getYield("BBH"+mssmMasses_[m],postfix),out.ZTT,out.QCD,out.W,out.ZLFT,out.TOP,out.VV);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      if(luminosityErr_!=0)
	fprintf(pfile,"lumi     lnN   %.3f          %.3f          -             -             -             -             -              -          luminosity\n",
	   1+luminosityErr_,1+luminosityErr_);
      
      if(muID_!=0)
	fprintf(pfile,"CMS_eff_m     lnN   %.3f          %.3f          %.3f          -             -             %.3f          %.3f          %.3f       muon ID /HLT\n",
	       1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_);
      if(tauID_!=0)
	fprintf(pfile,"CMS_eff_t    lnN   %.3f          %.3f          %.3f          -             -             -             -             %.3f        Tau IDf\n",
	       1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_);
    if(eleID_!=0)
      fprintf(pfile,"CMS_eff_e    lnN   %.3f          %.3f          %.3f          -             -             %.3f          %.3f          %.3f                 Electron ID\n",
	     1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_);
    if(zttScale_!=0)
      fprintf(pfile,"CMS_htt_zttNorm lnN   -             -             %.3f          -             -             %.3f          %.3f          -                 ZTT Scale  \n",
	     1+zttScaleErr_/zttScale_,1+zttScaleErr_/zttScale_,1+zttScaleErr_/zttScale_);
    //FIXPOINTTTT
    fprintf(pfile,"CMS_htt_ztt_extrap_btag lnN   -             -             %.3f          -             -             %.3f        -          -         ZTT Extrapolation\n", 1+out.dZTTCORR/out.ZTTCORR,1+bFactorZErr_/bFactorZ_);
    fprintf(pfile,"CMS_htt_w_extrap_btag lnN   -             -                -             -            %.3f          -             -          -       W Extrapolation\n", 1+bFactorWErr_/bFactorW_);
    fprintf(pfile,"CMS_htt_ttbarNorm  lnN      -             -             -             -             -             -             %.3f           -      TTbar background  \n",1+out.dTOP/out.TOP);
    fprintf(pfile,"CMS_htt_DiBosonNorm  lnN      -             -             -             -             -             -             -            %.3f   DiBoson background \n",1+out.dVV/out.VV);
    fprintf(pfile,"CMS_htt_%s_ZLLTNorm  lnN      -             -             -             -             -               %.3f           -              -      Z(l->tau)   background\n",(channel_+postfix).c_str(),1+out.dZLFT/out.ZLFT);

    for(unsigned int j=0;j<shifts_.size();++j)
      fprintf(pfile,"%s    shape    1             1             1            -             -             -             -              -      shape\n",shiftsPostFix_[j].c_str());

    fprintf(pfile,"CMS_htt_%s_QCDNorm  lnN         -             -             -             %.3f          -             -             -                          -      QCD Background\n",(channel_+postfix).c_str(),1+out.dQCD/out.QCD);
    fprintf(pfile,"CMS_htt_%s_WNorm    lnN      -             -             -             -             %.3f          -             -                         -      W Backghround \n",channel_.c_str(),1+out.dWCORR/out.WCORR);

    fprintf(pfile,"CMS_eff_b      lnN      -             %.3f          -             -             -             -                         %.3f           -     BTag efficiency \n",1+bIDErr_/bID_,1+bIDErr_/bID_);
    fprintf(pfile,"CMS_fake_b      lnN      %.3f          -             -             -             -             -                       -              -     BTag MisTag \n",1+bMisIDErr_/bMisID_);


    fprintf(pfile,"CMS_scale_j      lnN     1.04           1.02             -             -             -             -                       1.10              1.03     Jet Scale \n");
    fprintf(pfile,"CMS_scale_met    lnN     1.05           1.05             -             -             -             -                       1.01              1.03     MET SCale \n");

    fclose(pfile);
    }

  }




  void makeMSSMEMuDataCardBTagged(BkgOutput out,std::string postfix) {
    for(unsigned int m = 0;m<mssmMasses_.size();++m) {
      FILE *pfile = fopen(("datacards/"+channel_+postfix+"_mA"+mssmMasses_[m]+".txt").c_str(),"w");

      fprintf(pfile,"imax 1\n");
      fprintf(pfile,"jmax *\n");
      fprintf(pfile,"kmax *\n");
      fprintf(pfile,"shapes *  *    %s  $CHANNEL/$PROCESS $CHANNEL/$PROCESS_$SYSTEMATIC \n",(channel_+".root").c_str());
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      fprintf(pfile,"observation %d\n",(int)out.DATA);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      std::string ch = channel_+postfix;
      fprintf(pfile,"bin            %s            %s            %s            %s            %s            %s\n",ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str());
      fprintf(pfile,"process        GGH%s        BBH%s        ZTT           FAKES           TT            VV\n",mssmMasses_[m].c_str(),mssmMasses_[m].c_str());
      fprintf(pfile,"process        -1            0             1             2             3             4 \n");
      fprintf(pfile,"rate           %.3f          %.3f          %.3f          %.3f          %.3f          %.3f\n",
	      getYield("GGH"+mssmMasses_[m],postfix),getYield("BBH"+mssmMasses_[m],postfix),out.ZTT,out.QCD,out.TOP,out.VV);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      if(luminosityErr_!=0)
	fprintf(pfile,"lumi     lnN   %.3f          %.3f          -             -             -             -             -              -          luminosity\n",
	   1+luminosityErr_,1+luminosityErr_);
      
      if(muID_!=0)
	fprintf(pfile,"CMS_eff_m     lnN   %.3f          %.3f          %.3f          -             %.3f          %.3f     muon ID /HLT\n",
	       1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_);
      if(eleID_!=0)
	fprintf(pfile,"CMS_eff_e    lnN   %.3f          %.3f          %.3f          -              %.3f          %.3f              Electron ID\n",
	     1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_);
    if(zttScale_!=0)
      fprintf(pfile,"CMS_htt_zttNorm lnN   -             -             %.3f          -             %.3f          %.3f     ZTT Scale  \n",
	     1+zttScaleErr_/zttScale_,1+zttScaleErr_/zttScale_,1+zttScaleErr_/zttScale_);
    //FIXPOINTTTT
    fprintf(pfile,"CMS_htt_ztt_extrap_btag lnN   -             -             %.3f          -       -          -         ZTT Extrapolation\n", 1+out.dZTTCORR/out.ZTTCORR);
    fprintf(pfile,"CMS_htt_ttbarNorm  lnN      -             -             -             -         %.3f           -      TTbar background  \n",1+out.dTOP/out.TOP);
    fprintf(pfile,"CMS_htt_DiBosonNorm  lnN     -             -             -             -             -         %.3f   DiBoson background \n",1+out.dVV/out.VV);
    for(unsigned int j=0;j<shifts_.size();++j)
      fprintf(pfile,"%s    shape    1             1             1             -             -             -       shape\n",shiftsPostFix_[j].c_str());
    fprintf(pfile,"CMS_htt_%s_FakeNorm  lnN        -             -            -             %.3f          -             -          QCD Background\n",(channel_+postfix).c_str(),1+out.dQCD/out.QCD);
    fprintf(pfile,"CMS_eff_b      lnN      -             %.3f          -             -                 %.3f           -     BTag efficiency \n",1+bIDErr_/bID_,1+bIDErr_/bID_);
    fprintf(pfile,"CMS_fake_b      lnN      %.3f          -             -             -             -             -      BTag MisTag \n",1+bMisIDErr_/bMisID_);

    fprintf(pfile,"CMS_scale_j      lnN     1.04           1.02             -             -            1.10              1.03     Jet Scale \n");
    fprintf(pfile,"CMS_scale_met    lnN     1.05           1.05             -             -            1.01              1.03     MET SCale \n");


    fclose(pfile);
    }

  }





  void makeHiggsShapesAll(std::string preselection,std::string prefix) {
    std::pair<float,float> tmp;
    float legCorr=1.0;

    if(muID_!=0&&eleID_!=0) {legCorr*=muID_*eleID_;}
    if(muID_!=0&&eleID_==0) {legCorr*=muID_*tauID_;}
    if(muID_==0&&eleID_!=0) {legCorr*=eleID_*tauID_;}


    for(unsigned int i=0;i<mssmMasses_.size();++i) {
      tmp= createHistogramAndShiftsFinal(dir_+"bbA"+mssmMasses_[i]+".root","BBH"+mssmMasses_[i],("("+preselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
      tmp= createHistogramAndShiftsFinal(dir_+"ggH"+mssmMasses_[i]+".root","GGH"+mssmMasses_[i],("("+preselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
    }

    for(unsigned int i=0;i<smMasses_.size();++i) {
      tmp= createHistogramAndShiftsFinal(dir_+"sm"+smMasses_[i]+".root","ggH"+smMasses_[i],("("+preselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr*smSigma_[i],prefix);
      tmp= createHistogramAndShiftsFinal(dir_+"vbf"+smMasses_[i]+".root","qqH"+smMasses_[i],("("+preselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr*vbfSigma_[i],prefix);
      tmp= createHistogramAndShiftsFinal(dir_+"vh"+smMasses_[i]+".root","VH"+smMasses_[i],("("+preselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr*vhSigma_[i],prefix);


    }
    //interpolateHistogramAndShifts(prefix);

  }


  void makeHiggsShapesSM(std::string preselection,std::string prefix) {
    std::pair<float,float> tmp;

    float legCorr=1.0;

    if(muID_!=0&&eleID_!=0) {legCorr*=muID_*eleID_;}
    if(muID_!=0&&eleID_==0) {

    	float tauID = 1.0;
    	if(prefix=="_vbf"||prefix=="_2jet")
    		tauID = tauID_ - (1.0 - tauIDHigh_)/2 ;    		
    	else if(prefix=="_0jet_high"||prefix=="_boost_high")
    		tauID = tauID_ - (1-tauIDHigh_);
    	else
    		tauID = tauID_;
    
    	legCorr*=muID_*tauID;    
    	printf("Tau ID Scale Factor is %.3f \n",tauID);
    		
    }
    if(muID_==0&&eleID_!=0) {

    	float tauID = 1.0;
    	if(prefix=="_vbf"||prefix=="_2jet")
    		tauID = tauID_ - (1.0 - tauIDHigh_)/2 ;    		
    	else if(prefix=="_0jet_high"||prefix=="_boost_high")
    		tauID = tauID_ - (1-tauIDHigh_);
    	else
    		tauID = tauID_;
    
    	printf("Tau ID Scale Factor is %.3f \n",tauID);        
    	legCorr*=eleID_*tauID;
    }

	
    for(unsigned int i=0;i<smMasses_.size();++i) {



		tmp= createHistogramAndShiftsFinal(dir_+"sm"+smMasses_[i]+".root","ggH"+smMasses_[i],("("+preselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*__HPT__*"+weight_),luminosity_*legCorr*smSigma_[i],prefix);
		tmp= createHistogramAndShiftsFinal(dir_+"sm"+smMasses_[i]+".root","ggH"+smMasses_[i]+"_QCDscale_ggH1inUp",("("+preselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*__HPTUp__*"+weight_),luminosity_*legCorr*smSigma_[i],prefix);
		tmp= createHistogramAndShiftsFinal(dir_+"sm"+smMasses_[i]+".root","ggH"+smMasses_[i]+"_QCDscale_ggH1inDown",("("+preselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*__HPTDown__*"+weight_),luminosity_*legCorr*smSigma_[i],prefix);
		tmp= createHistogramAndShiftsFinal(dir_+"vbf"+smMasses_[i]+".root","qqH"+smMasses_[i],("("+preselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr*vbfSigma_[i],prefix);
		tmp= createHistogramAndShiftsFinal(dir_+"vh"+smMasses_[i]+".root","VH"+smMasses_[i],("("+preselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr*vhSigma_[i],prefix);
		

    }
    CheckFirstFourBins(channel_,prefix); 
    //interpolateHistogramAndShifts(prefix);

  }


  void makeHiggsShapesBTag(std::string preselection,std::string prefix) {
    std::pair<float,float> tmp;

    float legCorr=1.0;

    if(muID_!=0&&eleID_!=0) {legCorr*=muID_*eleID_;}
    if(muID_!=0&&eleID_==0) {legCorr*=muID_*tauID_;}
    if(muID_==0&&eleID_!=0) {legCorr*=eleID_*tauID_;}


    for(unsigned int i=0;i<mssmMasses_.size();++i) {
      std::string genMassCut = "genFullMass > 0.7*"+mssmMasses_[i]+" && genFullMass < 1.3*"+mssmMasses_[i];
      tmp= createHistogramAndShiftsFinal(dir_+"bbA"+mssmMasses_[i]+".root","bbH"+mssmMasses_[i],("("+preselection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+genMassCut+")*"+weight_),luminosity_*legCorr*bID_,prefix);
      tmp= createHistogramAndShiftsFinal(dir_+"ggH"+mssmMasses_[i]+".root","ggH"+mssmMasses_[i],("("+preselection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+genMassCut+")*"+weight_),luminosity_*legCorr*bMisID_,prefix);
    }
  }

  void makeHiggsShapesMSSM(std::string preselection,std::string prefix) {
    std::pair<float,float> tmp;

    float legCorr=1.0;

    if(muID_!=0&&eleID_!=0) {legCorr*=muID_*eleID_;}
    if(muID_!=0&&eleID_==0) {legCorr*=muID_*tauID_;}
    if(muID_==0&&eleID_!=0) {legCorr*=eleID_*tauID_;}

    for(unsigned int i=0;i<mssmMasses_.size();++i) {
	  std::string genMassCut = "genFullMass > 0.7*"+mssmMasses_[i]+" && genFullMass < 1.3*"+mssmMasses_[i];   
      tmp= createHistogramAndShiftsFinal(dir_+"bbA"+mssmMasses_[i]+".root","bbH"+mssmMasses_[i],("("+preselection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+genMassCut+")*"+weight_),luminosity_*legCorr,prefix);
      tmp= createHistogramAndShiftsFinal(dir_+"ggH"+mssmMasses_[i]+".root","ggH"+mssmMasses_[i],("("+preselection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+genMassCut+")*"+weight_),luminosity_*legCorr,prefix);
    }
  }

  void makeHeavyHiggsShape(std::string preselection,std::string prefix) {
    std::pair<float,float> tmp;

    float legCorr=1.0;

    if(muID_!=0&&eleID_!=0) {legCorr*=muID_*eleID_;}
    if(muID_!=0&&eleID_==0) {legCorr*=muID_*tauID_;}
    if(muID_==0&&eleID_!=0) {legCorr*=eleID_*tauID_;}


    tmp= createHistogramAndShiftsFinal(dir_+"Hhhttbb300.root","Hhh300",("("+preselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
    tmp= createHistogramAndShiftsFinal(dir_+"Hhhttbb300.root","Hhh300NoSel",("(pt1>0)*"+weight_),luminosity_*legCorr,prefix);

  }

  
  void makeHiggsShapesNoBTag(std::string preselection,std::string prefix) {
    std::pair<float,float> tmp;

    float legCorr=1.0;
    if(muID_!=0&&eleID_!=0) {legCorr*=muID_*eleID_;}
    if(muID_!=0&&eleID_==0) {legCorr*=muID_*tauID_;}
    if(muID_==0&&eleID_!=0) {legCorr*=eleID_*tauID_;}


    for(unsigned int i=0;i<mssmMasses_.size();++i) {
      tmp= createHistogramAndShiftsFinal(dir_+"bbA"+mssmMasses_[i]+".root","BBHNoJet"+mssmMasses_[i],("("+preselection+"&&"+trigSelection_+"&&nTaggableJetsPt20==0&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
      tmp= createHistogramAndShiftsFinal(dir_+"bbA"+mssmMasses_[i]+".root","BBHBJet"+mssmMasses_[i],("("+preselection+"&&"+trigSelection_+"&&nTaggableJetsPt20Matched>0&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr*(1/bID_),prefix);
      tmp= createHistogramAndShiftsFinal(dir_+"bbA"+mssmMasses_[i]+".root","BBHJet"+mssmMasses_[i],("("+preselection+"&&"+trigSelection_+"&&nTaggableJetsPt20NotMatched>0&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr*bMisID_,prefix);

      tmp= createHistogramAndShiftsFinal(dir_+"ggH"+mssmMasses_[i]+".root","GGHNoJet"+mssmMasses_[i],("("+preselection+"&&"+trigSelection_+"&&nTaggableJetsPt20==0&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
      tmp= createHistogramAndShiftsFinal(dir_+"ggH"+mssmMasses_[i]+".root","GGHJet"+mssmMasses_[i],("("+preselection+"&&"+trigSelection_+"&&nTaggableJetsPt20>0&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr*bMisID_,prefix);

    }
  }



  BkgOutput runOSLSMT(std::string preSelection,std::string prefix,std::string zShape, float topExtrap) {

    float leg1Corr=1.0;
    if(muID_!=0) leg1Corr*=muID_;
    if(eleID_!=0) leg1Corr*=eleID_;


	printf("Tau ID Scale Factor is %.3f \n",tauID_);
	
    //create Z->tautau 
	std::pair<float,float> zttYield       = createHistogramAndShiftsFinal(zttFile_,"ZTTTMP",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&genTaus>0&&genVisPt2>18&&(!((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8))))*"+weight_),luminosity_*zttScale_*leg1Corr*tauID_,prefix);
	std::pair<float,float> ztt_ll       = createHistogramAndShiftsFinal(zttFile_,"ZTT_LL",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&genTaus>0&&((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))*"+weight_),luminosity_*zttScale_*leg1Corr*tauID_,prefix);
	std::pair<float,float> zSDB    		  = createHistogramAndShiftsFinal(zttFile_,"Z_SDB",("("+preSelection+"&&"+trigSelection_+"&&"+osWSelection_+")*"+weight_),luminosity_*zttScale_*leg1Corr*tauID_,prefix);
	std::pair<float,float> zttSS   		  = createHistogramAndShifts(zttFile_,"ZTT_SS",("("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&genTaus>0&&genVisPt2>18)*"+weight_),luminosity_*zttScale_*leg1Corr*tauID_,prefix);
	;
	
	if(zShape.size()==0) {
	  std::pair<float,float> zttShape       = createHistogramAndShiftsFinal(zttFile_,"ZTT",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&genTaus>0&&genVisPt2>18)*"+weight_),luminosity_*zttScale_*leg1Corr*tauID_,prefix);
	  
	}
	else{
	  //create correction factor for MT and Pzeta cuts
	  std::pair<float,float> dataWCut_Before       = createHistogramAndShifts(zShape,"ZTTWCut",("("+preSelection+"&&charge==0&&genFullMass>50&&genVisPt2>18)*"+embWeight_),1.0,prefix);
	  std::pair<float,float> zttShape       = createHistogramAndShifts(zShape,"ZTT",("("+preSelection+"&&"+osSignalSelection_+"&&genFullMass>50&&genVisPt2>18)*"+embWeight_),1.0,prefix);
	  
	  std::pair<float,float> mcWCut_Before    = createHistogramAndShiftsFinal(zttFile_,"ZTTWCutMC",("("+preSelection+"&&"+trigSelection_+"&&genTaus>0&&genVisPt2>18&&(!((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8))))*"+weight_),luminosity_*zttScale_*leg1Corr*tauID_,prefix);
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
	
    //create TTbar
    std::pair<float,float> topYield       = createHistogramAndShiftsFinal(topFile_,"TT",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*leg1Corr*tauID_*topExtrap,prefix);
    //Create TTbar in Sideband
    std::pair<float,float> topYieldSdb    = createHistogramAndShiftsFinal(topFile_,"TT_SDB",("("+preSelection+"&&"+trigSelection_+"&&"+osWSelection_+")*"+weight_),luminosity_*leg1Corr*tauID_*topExtrap,prefix);

    std::pair<float,float> topSSYield       = createHistogramAndShifts(topFile_,"TTSS",("("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+")*"+weight_),luminosity_*leg1Corr*tauID_*topExtrap,prefix);
    //Create TTbar in Sideband
    std::pair<float,float> topSSYieldSdb    = createHistogramAndShifts(topFile_,"TTSS_SDB",("("+preSelection+"&&"+trigSelection_+"&&"+ssWSelection_+")*"+weight_),luminosity_*leg1Corr*tauID_*topExtrap,prefix);
    std::pair<float,float> zSSYieldSdb    = createHistogramAndShifts(zllFile_,"ZSS_SDB",("("+preSelection+"&&"+trigSelection_+"&&"+ssWSelection_+")*ZeFakeTau*"+weight_),luminosity_*leg1Corr*tauID_,prefix);
    std::pair<float,float> vvSSYieldSdb    = createHistogramAndShifts(vvFile_,"VVSS_SDB",("("+preSelection+"&&"+trigSelection_+"&&"+ssWSelection_+")*"+weight_),luminosity_*leg1Corr*tauID_,prefix);

    //create Diboson
    std::pair<float,float> vvYield        = createHistogramAndShiftsFinal(vvFile_,"VV",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*leg1Corr*tauID_,prefix);
    //create Diboson in sideband
    std::pair<float,float> vvYieldSdb     = createHistogramAndShiftsFinal(vvFile_,"VV_SDB",("("+preSelection+"&&"+trigSelection_+"&&"+osWSelection_+")*"+weight_),luminosity_*leg1Corr*tauID_,prefix);
    std::pair<float,float> vvYieldSS        = createHistogramAndShifts(vvFile_,"VV_SS",("("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+")*"+weight_),luminosity_*leg1Corr*tauID_,prefix);

    std::pair<float,float> zlftYield   = createHistogramAndShiftsFinal(zllFile_,"ZL",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&genTaus==0&&((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zlftFactor_*zttScale_,prefix,false);

    std::pair<float,float> zjftYield      = createHistogramAndShiftsFinal(zllFile_,"ZJ",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&(!((genTaus==0&&abs(pdg2)==13&&genPt2>8)||(genTaus==0&&abs(pdg2)==11&&genPt2>8)||(genTaus>0&&genVisPt2>18))))*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zttScale_,prefix);
    std::pair<float,float> zlftSSYield    = createHistogramAndShifts(zllFile_,"ZL_SS",("("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&genTaus==0&& ((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zttScale_,prefix);
    std::pair<float,float> zjftSSYield    = createHistogramAndShifts(zllFile_,"ZJ_SS",("("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&(!((genTaus==0&&abs(pdg2)==13&&genPt2>8)||(genTaus==0&&abs(pdg2)==11&&genPt2>8)||(genTaus>0&&genVisPt2>18))))*"+weight_),luminosity_*leg1Corr*zttScale_,prefix,false);
    std::pair<float,float> wShape         = createHistogramAndShiftsFinal(wFile_,"W",("("+preSelection+"&&"+osSignalSelection_+")*"+weight_),luminosity_*leg1Corr,prefix,false);
    std::pair<float,float> wMCYield       = createHistogramAndShiftsFinal(wFile_,"WTMP",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*leg1Corr,prefix,false);
    std::pair<float,float> wMCSSYield       = createHistogramAndShifts(wFile_,"WSS",("("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+")*"+weight_),luminosity_*leg1Corr,prefix);
    std::pair<float,float> dataY         = createHistogramAndShiftsFinal(dataFile_,"data_obs","("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+")",scaleUp_,prefix);
    std::pair<float,float> dataYRounded  = std::make_pair(rintf(dataY.first),dataY.second);
    renormalizeHistogram(channel_+prefix,"data_obs",dataYRounded.first);
    std::pair<float,float> dataYield      = convertToPoisson(dataYRounded);
 
    std::pair<float,float> dataSSY          = createHistogramAndShifts(dataFile_,"data_obs_ss","("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+")",scaleUp_,prefix);
    std::pair<float,float> dataSSYield      = convertToPoisson(dataSSY);

    std::pair<float,float> dataYSdb     = createHistogramAndShiftsFinal(dataFile_,"data_obs_sdb","("+preSelection+"&&"+trigSelection_+"&&"+osWSelection_+")",scaleUp_,prefix);
    std::pair<float,float> dataYieldSdb      = convertToPoisson(dataYSdb);

    std::pair<float,float> dataSSYSdb = createHistogramAndShifts(dataFile_,"data_obs_ss_sdb","("+preSelection+"&&"+trigSelection_+"&&"+ssWSelection_+")",scaleUp_,prefix);
    std::pair<float,float> dataSSYieldSdb = convertToPoisson(dataSSYSdb);


    //shape creation for QCD ==== SUBTRACT THE BAD GUYS!
    std::pair<float,float> dataQCDControl = createHistogramAndShifts(dataFile_,"QCD","("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+")",scaleUp_,prefix);
    std::pair<float,float> zllQCDControl = createHistogramAndShifts(zllFile_,"ZLLQCD","("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+")*ZeFakeTau*"+weight_,luminosity_*leg1Corr*zttScale_,prefix);
    std::pair<float,float> ttQCDControl = createHistogramAndShifts(topFile_,"TOPQCD","("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+")*"+weight_,luminosity_*leg1Corr*tauID_*topExtrap,prefix);
//     subtractHistogram(channel_+prefix,"QCD","ZLLQCD");
//     subtractHistogram(channel_+prefix,"QCD","TOPQCD");

    //Inflate the errors(note that currently there are only statistical on templates+ Add here the background estimates)
    std::pair<float,float> topInflYield  = inflateError(topYield,topErr_);
    printf("TTbar events in signal region = %f + %f \n",topInflYield.first,topInflYield.second);

    std::pair<float,float> topInflSSYield  = inflateError(topSSYield,topErr_);
    printf("TTbar events in SS signal region = %f + %f \n",topInflSSYield.first,topInflSSYield.second);

    std::pair<float,float> topInflYieldSdb  = inflateError(topYieldSdb,topErr_);
    printf("TTbar events in sideband region = %f + %f \n",topYieldSdb.first,topInflYieldSdb.second);

    std::pair<float,float> topInflSSYieldSdb  = inflateError(topSSYieldSdb,topErr_);
    printf("TTbar events in SS sideband region = %f + %f \n",topSSYieldSdb.first,topInflSSYieldSdb.second);

    std::pair<float,float> vvInflYield  = inflateError(vvYield,vvErr_);
    printf("Diboson events in signal region = %f + %f \n",vvInflYield.first,vvInflYield.second);

    std::pair<float,float> vvInflYieldSdb  = inflateError(vvYieldSdb,vvErr_);
    printf("Diboson events in sideband region = %f + %f \n",vvYieldSdb.first,vvInflYieldSdb.second);
    
    std::pair<float,float> zlftInflYield  = inflateError(zlftYield,zlftErr_);
    printf("Z (l->tau) in signal region = %f + %f \n",zlftInflYield.first,zlftInflYield.second);
    
    std::pair<float,float> zjftInflYield  = inflateError(zjftYield,zjftErr_);
    printf("Z (j->tau) in signal region = %f + %f \n",zjftInflYield.first,zjftInflYield.second);
    
    std::pair<float,float> zlftInflSSYield  = inflateError(zlftSSYield,zlftErr_);
    printf("Z (l->tau) in SS region = %f + %f \n",zlftInflSSYield.first,zlftInflSSYield.second);
    
    std::pair<float,float> zjftInflSSYield  = inflateError(zjftSSYield,zjftErr_);
    printf("Z (j->tau) in SS region = %f + %f \n",zjftInflSSYield.first,zjftInflSSYield.second);


    //Measure W factor from your corrected MC 
    std::pair<float,float> wFactor = extractWFactor(wFile_,preSelection+"&&"+trigSelection_,prefix,osWSelection_,osSignalSelection_);
    printf("W extrapolation factor as measured in corrected MC = %f +- %f\n",wFactor.first,wFactor.second);
   

    //Runi OS+LS + MT method
    printf("1. Subtract TTbar and diboson from sideband");
    std::pair<float,float> osWHigh = std::make_pair(TMath::Nint(dataYieldSdb.first-topInflYieldSdb.first-vvInflYieldSdb.first-zSDB.first),
						      sqrt(dataYieldSdb.second*dataYieldSdb.second+topInflYieldSdb.second*topInflYieldSdb.second+vvInflYieldSdb.second*vvInflYieldSdb.second+zSDB.second*zSDB.second));
    printf("OS W in sideband  =%f -%f -%f -%f  = %f +- %f \n",dataYieldSdb.first,topInflYieldSdb.first,vvInflYieldSdb.first,zSDB.first,osWHigh.first,osWHigh.second);
     
    printf("2. Extrapolate W in the low MT region\n");
    std::pair<float,float> osWLow = std::make_pair(osWHigh.first*wFactor.first,
						     sqrt(osWHigh.first*osWHigh.first*wFactor.second*wFactor.second+osWHigh.second*osWHigh.second*wFactor.first*wFactor.first));
      
    printf("OS W  in core  =%f *%f  = %f +- %f \n",osWHigh.first,wFactor.first,osWLow.first,osWLow.second);
      
    printf("3. Repeat for SS : first subtract TTbar W\n");
    std::pair<float,float> ssWHigh = std::make_pair(TMath::Nint(dataSSYieldSdb.first-topInflSSYieldSdb.first-zSSYieldSdb.first-vvSSYieldSdb.first),
						      sqrt(dataSSYieldSdb.second*dataSSYieldSdb.second+topInflSSYieldSdb.second*topInflSSYieldSdb.second+zSSYieldSdb.second*zSSYieldSdb.second+vvSSYieldSdb.second*vvSSYieldSdb.second));

    std::pair<float,float> ssWLow = std::make_pair(ssWHigh.first*wFactor.first,
						   sqrt(ssWHigh.second*ssWHigh.second*wFactor.first*wFactor.first+wFactor.second*wFactor.second*ssWHigh.first*ssWHigh.first));

    std::pair<float,float> wShapeSS      = createHistogramAndShifts(wFile_,"WQCD",("("+preSelection+"&&"+ssSignalSelection_+")*"+weight_),luminosity_*leg1Corr,prefix,false);
	
    renormalizeHistogram(channel_+prefix,"WQCD",ssWLow.first);
    subtractHistogram(channel_+prefix,"QCD","ZLLQCD");
    subtractHistogram(channel_+prefix,"QCD","TOPQCD");
	subtractHistogram(channel_+prefix,"QCD","WQCD");
         
    printf("4. From all SS events subtract W and Z jet fakes tau/TTbar to get QCD \n");
    std::pair<float,float> ssQCD = std::make_pair(TMath::Nint(dataSSYield.first-ssWLow.first-zlftInflSSYield.first-zjftInflSSYield.first-topInflSSYield.first-zttSS.first-vvYieldSS.first),
						  sqrt(dataSSYield.second*dataSSYield.second+ssWLow.second*ssWLow.second+zlftInflSSYield.second*zlftInflSSYield.second+zjftInflSSYield.second*zjftInflSSYield.second+topInflSSYield.second*topInflSSYield.second+zttSS.second*zttSS.second+vvYieldSS.second*vvYieldSS.second));

      if(ssQCD.first<0) {
	ssQCD.first=0.0000001;
	ssQCD.second=1.8;
      }
      
      printf("SS QCD in  core  =%f -%f -%f -%f -%f -%f -%f= %f +- %f \n",dataSSYield.first,ssWLow.first,zjftInflSSYield.first,zlftInflSSYield.first,topInflSSYield.first,zttSS.first,vvYieldSS.first,ssQCD.first,ssQCD.second);
      
      printf("5. Extrapolate SS QCD -> OS QCD \n");
      std::pair<float,float> osQCD = std::make_pair(ssQCD.first*qcdFactor_,sqrt(ssQCD.second*ssQCD.second*qcdFactor_*qcdFactor_+qcdFactorErr_*qcdFactorErr_*ssQCD.first*ssQCD.first));
      printf("OS QCD in  core  =%f *%f = %f +- %f \n",ssQCD.first,qcdFactor_,osQCD.first,osQCD.second);
           
      float background    = osQCD.first+osWLow.first+topInflYield.first+vvInflYield.first+zlftInflYield.first+zjftInflYield.first+zttYield.first;
      float backgroundErr = sqrt(osQCD.second*osQCD.second+osWLow.second*osWLow.second+topInflYield.second*topInflYield.second+vvInflYield.second*vvInflYield.second+zlftInflYield.second*zlftInflYield.second+zjftInflYield.second*zjftInflYield.second+zttYield.second*zttYield.second);
      printf("BACKGROUND=%f +-%f \n",background,backgroundErr);


      ///LATEX->Here since we want it for the note add all errors , even those that will go separate in the datacard
      printf("LATEX ------------------------------------\n");
      printf("Total & %.2f & %.2f & %.2f & %.2f \\\\ \n", dataYield.first, dataYieldSdb.first, dataSSYield.first, dataSSYieldSdb.first);
      printf("Di-Boson & %.2f $\\pm$ %.2f & %.2f $\\pm$ %.2f & - & - \\\\ \n", vvInflYield.first, quadrature(vvInflYield.first,vvInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_), vvInflYieldSdb.first, quadrature(vvInflYieldSdb.first,vvInflYieldSdb.second,muIDErr_,eleIDErr_,tauIDErr_));
      printf("$t\\bar{t}$ & %.2f $\\pm$ %.2f & %.2f $\\pm$ %.2f & - & - \\\\ \n", topInflYield.first,quadrature(topInflYield.first,topInflYield.second,muIDErr_,eleIDErr_,tauIDErr_), topInflYieldSdb.first, quadrature(topInflYieldSdb.first,topInflYield.second,muIDErr_,eleIDErr_,tauIDErr_));
      printf("$Z^{l+jet}$ & %.2f $\\pm$ %.2f & - & %.2f $\\pm$ %.2f & - \\\\ \n", zjftInflYield.first, quadrature(zjftInflYield.first,zjftInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_), zjftInflSSYield.first,quadrature(zjftInflSSYield.first,zjftInflSSYield.second,muIDErr_,eleIDErr_,zttScaleErr_));
      printf("$Z^{ll}$ & %.2f $\\pm$ %.2f & - & %.2f $\\pm$ %.2f & - \\\\ \n", zlftInflYield.first, quadrature(zlftInflYield.first,zlftInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_),zlftInflSSYield.first,quadrature(zlftInflSSYield.first,zlftInflSSYield.second,muIDErr_,eleIDErr_,zttScaleErr_));
      printf("$W+jets$ & %.2f $\\pm$ %.2f & %.2f $\\pm$ %.2f & %.2f $\\pm$ %.2f & %.2f $\\pm$ %.2f  \\\\ \n", osWLow.first, osWLow.second, osWHigh.first, osWHigh.second, ssWLow.first, ssWLow.second, dataSSYieldSdb.first, dataSSYieldSdb.second);
      printf("QCD & %.2f $\\pm$ %.2f & - & %.2f $\\pm$ %.2f & - \\\\ \n", osQCD.first, osQCD.second, ssQCD.first, ssQCD.second);
      printf("$Z\\rightarrow\\tau\\tau$ & %.2f $\\pm$ %.2f & - & - & - \\\\ \n", zttYield.first,quadrature(zttYield.first,zttYield.second,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_));

      float fullBackgroundErr = sqrt(pow(quadrature(vvInflYield.first,vvInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_),2)+
				       pow(quadrature(topInflYield.first,topInflYield.second,muIDErr_,eleIDErr_,tauIDErr_),2)+
				       pow(quadrature(zjftInflYield.first,zjftInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_),2)+
				       pow(quadrature(zlftInflYield.first,zlftInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_),2)+
				       pow(osQCD.second,2)+
				       pow(osWLow.second,2)+
				       pow(quadrature(zttYield.first,zttYield.second,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_),2));

      printf("Total Background & %.2f $\\pm$ %.2f & - & - & - \\\\ \n",background,sqrt(pow(quadrature(vvInflYield.first,vvInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_),2)+
										       pow(quadrature(topInflYield.first,topInflYield.second,muIDErr_,eleIDErr_,tauIDErr_),2)+
										       pow(quadrature(zjftInflYield.first,zjftInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_),2)+
										       pow(quadrature(zlftInflYield.first,zlftInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_),2)+
										       pow(osQCD.second,2)+
										       pow(osWLow.second,2)+
										       pow(quadrature(zttYield.first,zttYield.second,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_),2)));



      //create a histogram with the error for plotting reasons and only
      TH1F *err = new TH1F("BKGErr","",1,0,1);
      err->SetBinContent(1,fullBackgroundErr/background);
      fout_->cd((channel_+prefix).c_str());
      err->Write();

      BkgOutput output;
      output.DATA = dataYield.first;
      output.W = osWLow.first;
      output.dW = osWLow.second;
      output.WSDB = osWHigh.first;
     
      output.WCORR = output.W/wMCYield.first;
      output.dWCORR = output.dW/wMCYield.first;
      printf("W correction factor =  %f +-%f\n",output.WCORR,output.dWCORR);

      output.WSS = ssWLow.first;
      output.dWSS = ssWLow.second;

      output.WSSCORR = output.WSS/wMCSSYield.first;
      output.dWSSCORR = output.dWSS/wMCSSYield.first;
      printf("W correction factor =  %f +-%f\n",output.WSSCORR,output.dWSSCORR);
      
      output.QCD = osQCD.first;
      output.dQCD = osQCD.second;
      output.QCDSDB = ssQCD.first;

      output.ZLFT = zlftInflYield.first;
      output.dZLFT =zlftInflYield.second;
      output.ZLFTSS = zlftInflSSYield.first;
      output.dZLFTSS =zlftInflSSYield.second;

      output.ZJFT = zjftInflYield.first;
      output.dZJFT =zjftInflYield.second;
      output.ZJFTSS = zjftInflSSYield.first;
      output.dZJFTSS =zjftInflSSYield.second;
      output.TOP = topInflYield.first;
      output.dTOP = topInflYield.second;

      output.VV = vvInflYield.first;
      output.dVV = vvInflYield.second;

      output.ZTT = zttYield.first;
      output.dZTT = zttYield.second;
      
      output.WF = wFactor.first;
      output.dWF = wFactor.second;

      //now renormalize the histograms that you extracted from OS/LS+MT Method

      renormalizeHistogram(channel_+prefix,"QCD",osQCD.first);
      renormalizeHistogram(channel_+prefix,"W",osWLow.first);
      
//       if(channel_=="eleTau"){
//       	zeeShapeSyst(channel_+prefix, "ZL");
// 	  }
	
      return output;
  }







  BkgOutput runMinimalExtrapolation(std::string preSelection,std::string categorySelection,std::string prefix,float zExtrap_, float zExtrapErr_,float topExtrap,float topExtrapErr,BkgOutput inclusive, std::string zShape) {

    float leg1Corr=1.0;
    if(muID_!=0) leg1Corr*=muID_;
    if(eleID_!=0) leg1Corr*=eleID_;

	float tauID = 1.0;
	if(prefix=="_0jet_high"||prefix=="_boost_high")
		tauID = tauID_ - (1-tauIDHigh_);
	else
		tauID = tauID_;

	printf("Tau ID Scale Factor is %.3f \n",tauID);
    float zExtrap = zExtrap_;
    float zExtrapErr = zExtrapErr_;

      BkgOutput output;


      output.ZTTCORR=zExtrap;
      output.dZTTCORR=zExtrapErr;


    //create Z->tautau 
	std::pair<float,float> zSDB    = createHistogramAndShiftsFinal(zttFile_,"Z_SDB",("("+preSelection+"&&"+trigSelection_+"&&"+osWSelection_+"&&"+categorySelection+")*"+weight_),luminosity_*zttScale_*leg1Corr*tauID,prefix);
    std::pair<float,float> zttSS   = createHistogramAndShifts(zttFile_,"ZTT_SS",("("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+categorySelection+"&&genTaus>0&&genVisPt2>18)*"+weight_),luminosity_*zttScale_*leg1Corr*tauID,prefix);

    
    std::pair<float,float> zttYield       = createHistogramAndShiftsFinal(zttFile_,"ZTTTMP",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&genTaus>0&&genVisPt2>18&&(!((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)||(genTaus>0&&genVisPt2>18))))*"+weight_),luminosity_*zttScale_*zExtrap*leg1Corr*tauID,prefix);
    std::pair<float,float> ztt_ll       = createHistogramAndShiftsFinal(zttFile_,"ZTT_LL",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&genTaus>0&&((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))*"+weight_),luminosity_*zttScale_*zExtrap*leg1Corr*tauID,prefix);
	
    if(zShape.size()==0) {
      	std::pair<float,float> zttShape       = createHistogramAndShiftsFinal(zttFile_,"ZTT",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&genTaus>0&&genVisPt2>18)*"+weight_),luminosity_*zttScale_*zExtrap*leg1Corr*tauID,prefix);
    }
    else{
		printf("You have embedded samples.Calculating corrections on the fly overidding the crappy ones you gave me!\n");
		std::pair<float,float> zttShape       = createHistogramAndShifts(zShape,"ZTT",("("+preSelection+"&&"+categorySelection+"&&"+osSignalSelection_+"&&genFullMass>50&&genVisPt2>18)*"+embWeight_),leg1Corr*tauID,prefix,true);
		std::pair<float,float> zttShapePre    = createHistogramAndShifts(zShape,"ZTTPre",("("+preSelection+"&&"+osSignalSelection_+"&&genFullMass>50&&genVisPt2>18)*"+embWeight_),leg1Corr*tauID,prefix,true);
	
		printf("Inclusive Ztt Yield =%f\n",inclusive.ZTT);
		printf("ztt Yield =%f\n",zttYield.first);
		float corr = zttShape.first/zttShapePre.first;
		printf("emb category events = %f \n", zttShape.first);
		printf("emb inclusive events = %f \n", zttShapePre.first);
		printf("Efficiency for embedding =%f\n",corr);
		printf("Efficiency for MC        =%f\n",zttYield.first/inclusive.ZTT);

		zttYield = std::make_pair(inclusive.ZTT*corr,inclusive.dZTT*corr);

		renormalizeHistogram(channel_+prefix,"ZTT",zttYield.first);
		
		addHistogramZTT(channel_+prefix, "ZTT", "ZTT_LL");

	}
	
	
    std::pair<float,float> topShape       = createHistogramAndShiftsFinal(topFile_,"TT",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+")*"+weight_),luminosity_*leg1Corr*tauID*topExtrap,prefix);      
    //create TTbar
    std::pair<float,float> topYield       = createHistogramAndShiftsFinal(topFile_,"TTTMP",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+")*"+weight_),luminosity_*leg1Corr*tauID*topExtrap,prefix);
    //Create TTbar in Sideband
    std::pair<float,float> topYieldSdb    = createHistogramAndShiftsFinal(topFile_,"TT_SDB",("("+preSelection+"&&"+trigSelection_+"&&"+osWSelection_+"&&"+categorySelection+")*"+weight_),luminosity_*leg1Corr*tauID*topExtrap,prefix);

    std::pair<float,float> topSSYield       = createHistogramAndShifts(topFile_,"TTSS",("("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+categorySelection+")*"+weight_),luminosity_*leg1Corr*tauID*topExtrap,prefix);
    //Create TTbar in Sideband
    std::pair<float,float> topSSYieldSdb    = createHistogramAndShifts(topFile_,"TTSS_SDB",("("+preSelection+"&&"+trigSelection_+"&&"+ssWSelection_+"&&"+categorySelection+")*"+weight_),luminosity_*leg1Corr*tauID*topExtrap,prefix);
    std::pair<float,float> zSSYieldSdb    = createHistogramAndShifts(zllFile_,"ZSS_SDB",("("+preSelection+"&&"+trigSelection_+"&&"+ssWSelection_+"&&"+categorySelection+")*ZeFakeTau*"+weight_),luminosity_*leg1Corr*tauID,prefix);
    std::pair<float,float> vvSSYieldSdb    = createHistogramAndShifts(vvFile_,"VVSS_SDB",("("+preSelection+"&&"+trigSelection_+"&&"+ssWSelection_+"&&"+categorySelection+")*"+weight_),luminosity_*leg1Corr*tauID,prefix);

	renormalizeHistogram(channel_+prefix,"TT",topYield.first);
	
    //create Diboson
    std::pair<float,float> vvYield        = createHistogramAndShiftsFinal(vvFile_,"VV",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+")*"+weight_),luminosity_*leg1Corr*tauID,prefix);
    //create Diboson in sideband
    std::pair<float,float> vvYieldSdb     = createHistogramAndShiftsFinal(vvFile_,"VV_SDB",("("+preSelection+"&&"+trigSelection_+"&&"+osWSelection_+"&&"+categorySelection+")*"+weight_),luminosity_*leg1Corr*tauID,prefix);
    std::pair<float,float> vvYieldSS        = createHistogramAndShifts(vvFile_,"VV_SS",("("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+categorySelection+")*"+weight_),luminosity_*leg1Corr*tauID,prefix);

//    std::pair<float,float> zlftYield;
//     if(channel_=="eleTau"&&prefix=="_boost_high"){
//       std::pair<float,float> zlftShape      = createHistogramAndShiftsFinal(zllFile_,"ZL",("("+relaxedSelection_+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&genTaus==0&&genPt2>1)*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zlftFactor_*zttScale_*zExtrap,prefix);
//       zlftYield      = createHistogramAndShiftsFinal(zllFile_,"ZLTMP",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&genTaus==0&&genPt2>1)*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zlftFactor_*zttScale_*zExtrap,prefix);
//       renormalizeHistogram(channel_+prefix,"ZL",zlftYield.first);
//     }  
//     else{

      std::pair<float,float> zlftYield      = createHistogramAndShiftsFinal(zllFile_,"ZL",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&genTaus==0&& ((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zlftFactor_*zttScale_*zExtrap,prefix);
	if(channel_=="eleTau"){
      std::pair<float,float> zlShiftUp      = createHistogramShifted(zllFile_,"ZL_CMS_htt_ZLScale_etau_"+energy_+"Up",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&genTaus==0&& ((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))*ZeFakeTau*"+weight_),"1.02",luminosity_*leg1Corr*zlftFactor_*zttScale_*zExtrap,prefix);
      std::pair<float,float> zlShifDown     = createHistogramShifted(zllFile_,"ZL_CMS_htt_ZLScale_etau_"+energy_+"Down",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&genTaus==0&& ((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))*ZeFakeTau*"+weight_),"0.98",luminosity_*leg1Corr*zlftFactor_*zttScale_*zExtrap,prefix);
	}
	else{
	  std::pair<float,float> zlShiftUp      = createHistogramShifted(zllFile_,"ZL_CMS_htt_ZLScale_mutau_"+energy_+"Up",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&genTaus==0&& ((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))*ZeFakeTau*"+weight_),"1.02",luminosity_*leg1Corr*zlftFactor_*zttScale_*zExtrap,prefix);
      std::pair<float,float> zlShifDown     = createHistogramShifted(zllFile_,"ZL_CMS_htt_ZLScale_mutau_"+energy_+"Down",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&genTaus==0&& ((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))*ZeFakeTau*"+weight_),"0.98",luminosity_*leg1Corr*zlftFactor_*zttScale_*zExtrap,prefix);
	}
//	}
	
    std::pair<float,float> zjftYield      = createHistogramAndShiftsFinal(zllFile_,"ZJ",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&(!((genTaus==0&&abs(pdg2)==13&&genPt2>8)||(genTaus==0&&abs(pdg2)==11&&genPt2>8)||(genTaus>0&&genVisPt2>18))))*"+weight_),luminosity_*leg1Corr*zttScale_*zExtrap,prefix);


    std::pair<float,float> zlftSSYield    = createHistogramAndShifts(zllFile_,"ZL_SS",("("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+categorySelection+"&&genTaus==0&& ((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zttScale_*zExtrap,prefix,false);
    std::pair<float,float> zjftSSYield    = createHistogramAndShifts(zllFile_,"ZJ_SS",("("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+categorySelection+"&&(!((genTaus==0&&abs(pdg2)==13&&genPt2>8)||(genTaus==0&&abs(pdg2)==11&&genPt2>8)||(genTaus>0&&genVisPt2>18))))*"+weight_),luminosity_*leg1Corr*zttScale_*zExtrap,prefix);
    std::pair<float,float> wMCYield       = createHistogramAndShiftsFinal(wFile_,"WMC",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+")*"+weight_),luminosity_*leg1Corr,prefix);
    std::pair<float,float> wShape;
	if(prefix=="_1jet_high_lowhiggs"||prefix=="_1jet_medium"){
    	wShape       = createHistogramAndShifts(wFile_,"W",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+signalSelection_+")*"+weight_),luminosity_*leg1Corr,prefix,false);
	}
	else{
        wShape       = createHistogramAndShiftsFinal(wFile_,"W",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+osSignalSelection_+")*"+weight_),luminosity_*leg1Corr,prefix,false);
	}
	
    std::pair<float,float> wMCSSYield       = createHistogramAndShifts(wFile_,"WSS",("("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+categorySelection+")*"+weight_),luminosity_*leg1Corr,prefix);
    std::pair<float,float> dataY         = createHistogramAndShiftsFinal(dataFile_,"data_obs","("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&"+blinding_+")",scaleUp_,prefix);
    std::pair<float,float> dataYRounded  = std::make_pair(rintf(dataY.first),dataY.second);
    renormalizeHistogram(channel_+prefix,"data_obs",dataYRounded.first);
    std::pair<float,float> dataYield      = convertToPoisson(dataYRounded);
 
    std::pair<float,float> dataSSY          = createHistogramAndShifts(dataFile_,"data_obs_ss","("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+categorySelection+")",scaleUp_,prefix);
    std::pair<float,float> dataSSYield      = convertToPoisson(dataSSY);

    std::pair<float,float> dataYSdb     = createHistogramAndShiftsFinal(dataFile_,"data_obs_sdb","("+preSelection+"&&"+trigSelection_+"&&"+osWSelection_+"&&"+categorySelection+")",scaleUp_,prefix);
    std::pair<float,float> dataYieldSdb      = convertToPoisson(dataYSdb);

    std::pair<float,float> dataSSYSdb = createHistogramAndShifts(dataFile_,"data_obs_ss_sdb","("+preSelection+"&&"+trigSelection_+"&&"+ssWSelection_+"&&"+categorySelection+")",scaleUp_,prefix);
    std::pair<float,float> dataSSYieldSdb = convertToPoisson(dataSSYSdb);

	if(prefix!="_0jet_low"&&prefix!="_nobtag"&&(!(prefix=="_1jet_medium"&&channel_=="eleTau"))){
		//shape creation for QCD ==== SUBTRACT THE BAD GUYS!
		std::pair<float,float> dataQCDControl = createHistogramAndShifts(dataFile_,"QCD",qcdSelection_+"&&"+categorySelection,scaleUp_,prefix);
	}

    //Inflate the errors(note that currently there are only statistical on templates+ Add here the background estimates)
    std::pair<float,float> topInflYield  = inflateError(topYield,topErr_);
    printf("TTbar events in signal region = %f + %f \n",topInflYield.first,topInflYield.second);

    std::pair<float,float> topInflSSYield  = inflateError(topSSYield,topErr_);
    printf("TTbar events in SS signal region = %f + %f \n",topInflSSYield.first,topInflSSYield.second);

    std::pair<float,float> topInflYieldSdb  = inflateError(topYieldSdb,topErr_,topExtrapErr);
    printf("TTbar events in sideband region = %f + %f \n",topYieldSdb.first,topInflYieldSdb.second);

    std::pair<float,float> topInflSSYieldSdb  = inflateError(topSSYieldSdb,topErr_,topExtrapErr);
    printf("TTbar events in SS sideband region = %f + %f \n",topSSYieldSdb.first,topInflSSYieldSdb.second);

    std::pair<float,float> vvInflYield  = inflateError(vvYield,vvErr_);
    printf("Diboson events in signal region = %f + %f \n",vvInflYield.first,vvInflYield.second);

    std::pair<float,float> vvInflYieldSdb  = inflateError(vvYieldSdb,vvErr_);
    printf("Diboson events in sideband region = %f + %f \n",vvYieldSdb.first,vvInflYieldSdb.second);
    
    std::pair<float,float> zlftInflYield  = inflateError(zlftYield,zlftErr_);
    printf("Z (l->tau) in signal region = %f + %f \n",zlftInflYield.first,zlftInflYield.second);
    
    std::pair<float,float> zjftInflYield  = inflateError(zjftYield,zjftErr_);
    printf("Z (j->tau) in signal region = %f + %f \n",zjftInflYield.first,zjftInflYield.second);
    
    std::pair<float,float> zlftInflSSYield  = inflateError(zlftSSYield,zlftErr_,zExtrapErr);
    printf("Z (l->tau) in SS region = %f + %f \n",zlftInflSSYield.first,zlftInflSSYield.second);
    
    std::pair<float,float> zjftInflSSYield  = inflateError(zjftSSYield,zjftErr_,zExtrapErr);
    printf("Z (j->tau) in SS region = %f + %f \n",zjftInflSSYield.first,zjftInflSSYield.second);


    //Measure W factor from your corrected MC 
    std::pair<float,float> wFactor = extractWFactor(wFile_,preSelection+"&&"+trigSelection_+"&&"+categorySelection,prefix,osWSelection_,osSignalSelection_);
    printf("W extrapolation factor as measured in corrected MC = %f +- %f\n",wFactor.first,wFactor.second);
   

    //Run OS+LS + MT method
    printf("1. Subtract TTbar and diboson from sideband");
    std::pair<float,float> osWHigh = std::make_pair(TMath::Nint(dataYieldSdb.first-topInflYieldSdb.first-vvInflYieldSdb.first-zSDB.first),
						      sqrt(dataYieldSdb.second*dataYieldSdb.second+topInflYieldSdb.second*topInflYieldSdb.second+vvInflYieldSdb.second*vvInflYieldSdb.second+zSDB.second*zSDB.second));
    printf("OS W in sideband  =%f (data) -%f (TT) -%f (VV) -%f (Z) = %f +- %f \n",dataYieldSdb.first,topInflYieldSdb.first,vvInflYieldSdb.first,zSDB.first,osWHigh.first,osWHigh.second);
     
    printf("2. Extrapolate W in the low MT region\n");
    std::pair<float,float> osWLow = std::make_pair(osWHigh.first*wFactor.first,
						     sqrt(osWHigh.first*osWHigh.first*wFactor.second*wFactor.second+osWHigh.second*osWHigh.second*wFactor.first*wFactor.first));
      
    printf("OS W  in core  =%f *%f  = %f +- %f \n",osWHigh.first,wFactor.first,osWLow.first,osWLow.second);
      
    printf("3. Repeat for SS : first subtract TTbar W\n");
    std::pair<float,float> ssWHigh = std::make_pair(TMath::Nint(dataSSYieldSdb.first-topInflSSYieldSdb.first-zSSYieldSdb.first-vvSSYieldSdb.first),
						      sqrt(dataSSYieldSdb.second*dataSSYieldSdb.second+topInflSSYieldSdb.second*topInflSSYieldSdb.second+zSSYieldSdb.second*zSSYieldSdb.second+vvSSYieldSdb.second*vvSSYieldSdb.second));

    printf("SS W High = %f (data) - %f (TT) - %f (Z) - %f (VV) = %f\n", dataSSYieldSdb.first,topInflSSYieldSdb.first,zSSYieldSdb.first,vvSSYieldSdb.first,ssWHigh.first);

	std::pair<float,float> wFactorSS = extractWFactor(wFile_,preSelection+"&&"+trigSelection_+"&&"+categorySelection,prefix,ssWSelection_,ssSignalSelection_);
	
    std::pair<float,float> ssWLow = std::make_pair(ssWHigh.first*wFactorSS.first,
						   sqrt(ssWHigh.second*ssWHigh.second*wFactor.first*wFactor.first+wFactor.second*wFactor.second*ssWHigh.first*ssWHigh.first));

	printf("SS W Low = %f * %f = %f\n", ssWHigh.first,wFactorSS.first,ssWLow.first);
	
    if(prefix=="_0jet_low"||prefix=="_nobtag"||(prefix=="_1jet_medium"&&channel_=="eleTau")){
		std::pair<float,float> dataQCDControl = createHistogramAndShifts(dataFile_,"QCD","("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+categorySelection+")",scaleUp_,prefix);
		std::pair<float,float> zllQCDControl = createHistogramAndShifts(zllFile_,"ZLLQCD","("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+categorySelection+")*"+weight_,luminosity_*leg1Corr*zExtrap*zttScale_,prefix);
		subtractHistogram(channel_+prefix,"QCD","ZLLQCD");
		subtractHistogram(channel_+prefix,"QCD","TOPQCD");
		renormalizeHistogram(channel_+prefix,"WSS",ssWLow.first);
		subtractHistogram(channel_+prefix,"QCD","WSS");
    }
          
    printf("4. From all SS events subtract W and Z jet fakes tau/TTbar to get QCD \n");
    std::pair<float,float> ssQCD = std::make_pair(TMath::Nint(dataSSYield.first-ssWLow.first-zlftInflSSYield.first-zjftInflSSYield.first-topInflSSYield.first-zttSS.first-vvYieldSS.first),
						  sqrt(dataSSYield.second*dataSSYield.second+ssWLow.second*ssWLow.second+zlftInflSSYield.second*zlftInflSSYield.second+zjftInflSSYield.second*zjftInflSSYield.second+topInflSSYield.second*topInflSSYield.second+zttSS.second*zttSS.second+vvYieldSS.second*vvYieldSS.second));

      if(ssQCD.first<0) {
	ssQCD.first=0.0000001;
	ssQCD.second=1.8;
      }
      
      printf("SS QCD in  core  =%f (data) -%f (W) -%f (ZJ) -%f (ZL) -%f (TT) -%f (ZTT) -%f (VV)= %f +- %f \n",dataSSYield.first,ssWLow.first,zjftInflSSYield.first,zlftInflSSYield.first,topInflSSYield.first,zttSS.first,vvYieldSS.first,ssQCD.first,ssQCD.second);
      
      printf("5. Extrapolate SS QCD -> OS QCD \n");
      std::pair<float,float> osQCD = std::make_pair(ssQCD.first*qcdFactor_,sqrt(ssQCD.second*ssQCD.second*qcdFactor_*qcdFactor_+qcdFactorErr_*qcdFactorErr_*ssQCD.first*ssQCD.first));
      printf("OS QCD in  core  =%f *%f = %f +- %f \n",ssQCD.first,qcdFactor_,osQCD.first,osQCD.second);
           
      float background    = osQCD.first+osWLow.first+topInflYield.first+vvInflYield.first+zlftInflYield.first+zjftInflYield.first+zttYield.first;
      float backgroundErr = sqrt(osQCD.second*osQCD.second+osWLow.second*osWLow.second+topInflYield.second*topInflYield.second+vvInflYield.second*vvInflYield.second+zlftInflYield.second*zlftInflYield.second+zjftInflYield.second*zjftInflYield.second+zttYield.second*zttYield.second);
      printf("BACKGROUND=%f +-%f \n",background,backgroundErr);


      ///LATEX->Here since we want it for the note add all errors , even those that will go separate in the datacard
      printf("LATEX ------------------------------------\n");
      printf("Total & %.2f & %.2f & %.2f & %.2f \\\\ \n", dataYield.first, dataYieldSdb.first, dataSSYield.first, dataSSYieldSdb.first);
      printf("Di-Boson & %.2f $\\pm$ %.2f & %.2f $\\pm$ %.2f & - & - \\\\ \n", vvInflYield.first, quadrature(vvInflYield.first,vvInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_), vvInflYieldSdb.first, quadrature(vvInflYieldSdb.first,vvInflYieldSdb.second,muIDErr_,eleIDErr_,tauIDErr_));
      printf("$t\\bar{t}$ & %.2f $\\pm$ %.2f & %.2f $\\pm$ %.2f & - & - \\\\ \n", topInflYield.first,quadrature(topInflYield.first,topInflYield.second,muIDErr_,eleIDErr_,tauIDErr_,topExtrapErr), topInflYieldSdb.first, quadrature(topInflYieldSdb.first,topInflYield.second,muIDErr_,eleIDErr_,tauIDErr_,topExtrapErr));
      printf("$Z^{l+jet}$ & %.2f $\\pm$ %.2f & - & %.2f $\\pm$ %.2f & - \\\\ \n", zjftInflYield.first, quadrature(zjftInflYield.first,zjftInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_,zExtrapErr), zjftInflSSYield.first,quadrature(zjftInflSSYield.first,zjftInflSSYield.second,muIDErr_,eleIDErr_,zttScaleErr_,zExtrapErr));
      printf("$Z^{ll}$ & %.2f $\\pm$ %.2f & - & %.2f $\\pm$ %.2f & - \\\\ \n", zlftInflYield.first, quadrature(zlftInflYield.first,zlftInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_,zExtrapErr),zlftInflSSYield.first,quadrature(zlftInflSSYield.first,zlftInflSSYield.second,muIDErr_,eleIDErr_,zttScaleErr_,zExtrapErr));
      printf("$W+jets$ & %.2f $\\pm$ %.2f & %.2f $\\pm$ %.2f & %.2f $\\pm$ %.2f & %.2f $\\pm$ %.2f  \\\\ \n", osWLow.first, osWLow.second, osWHigh.first, osWHigh.second, ssWLow.first, ssWLow.second, dataSSYieldSdb.first, dataSSYieldSdb.second);
      printf("QCD & %.2f $\\pm$ %.2f & - & %.2f $\\pm$ %.2f & - \\\\ \n", osQCD.first, osQCD.second, ssQCD.first, ssQCD.second);
      printf("$Z\\rightarrow\\tau\\tau$ & %.2f $\\pm$ %.2f & - & - & - \\\\ \n", zttYield.first,quadrature(zttYield.first,zttYield.second,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_,zExtrapErr));
      float fullBackgroundErr = sqrt(pow(quadrature(vvInflYield.first,vvInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_),2)+
										       pow(quadrature(topInflYield.first,topInflYield.second,muIDErr_,eleIDErr_,tauIDErr_,topExtrapErr),2)+
										       pow(quadrature(zjftInflYield.first,zjftInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_,zExtrapErr),2)+
										       pow(quadrature(zlftInflYield.first,zlftInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_,zExtrapErr),2)+
										       pow(osQCD.second,2)+
										       pow(osWLow.second,2)+
				     pow(quadrature(zttYield.first,zttYield.second,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_,zExtrapErr),2));
      printf("Total Background & %.2f $\\pm$ %.2f & - & - & - \\\\ \n",background,fullBackgroundErr);



      //create a histogram with the error for plotting reasons and only
      TH1F *err = new TH1F("BKGErr","",1,0,1);
      err->SetBinContent(1,fullBackgroundErr/background);
      fout_->cd((channel_+prefix).c_str());
      err->Write();



      output.DATA = dataYield.first;
      output.W = osWLow.first;
      output.dW = osWLow.second;
      output.WSDB = osWHigh.first;
     
      output.WCORR = output.W/wMCYield.first;
      output.dWCORR = output.dW/wMCYield.first;
      printf("W correction factor =  %f +-%f\n",output.WCORR,output.dWCORR);

      output.WSS = ssWLow.first;
      output.dWSS = ssWLow.second;

      output.WSSCORR = output.WSS/wMCSSYield.first;
      output.dWSSCORR = output.dWSS/wMCSSYield.first;
      printf("W correction factor =  %f +-%f\n",output.WSSCORR,output.dWSSCORR);
      
      output.QCD = osQCD.first;
      output.dQCD = osQCD.second;
      output.QCDSDB = ssQCD.first;

      output.ZLFT = zlftInflYield.first;
      output.dZLFT =zlftInflYield.second;
      output.ZLFTSS = zlftInflSSYield.first;
      output.dZLFTSS =zlftInflSSYield.second;

      output.ZJFT = zjftInflYield.first;
      output.dZJFT =zjftInflYield.second;
      output.ZJFTSS = zjftInflSSYield.first;
      output.dZJFTSS =zjftInflSSYield.second;
      output.TOP = topInflYield.first;
      output.dTOP = topInflYield.second;

      output.VV = vvInflYield.first;
      output.dVV = vvInflYield.second;

      output.ZTT = zttYield.first;
      output.dZTT = zttYield.second;
      
      output.WF = wFactor.first;
      output.dWF = wFactor.second;

      

      //now renormalize the histograms that you extracted from OS/LS+MT Method
      
      FixEmptyBins(channel_+prefix,"QCD",true);
      
      if((prefix=="_1jet_medium"||prefix=="_1jet_high_lowhiggs") && (variable_=="svMass"||variable_=="mass") && channel_=="muTau"){ 
      	renormalizeHistogram(channel_+prefix,"QCD",osQCD.first);      
	  	qcdSyst(channel_, prefix, "QCD", 1.10, 0.1);
	  }
	  else if((variable_=="svMass"||variable_=="mass")){
	  	renormalizeHistogram(channel_+prefix,"QCD",osQCD.first);
      	qcdSyst(channel_, prefix, "QCD", 1.0, 0.1);
	  }
	  else{
	    renormalizeHistogram(channel_+prefix,"QCD",osQCD.first);
	  }
	  

      renormalizeHistogram(channel_+prefix,"W",osWLow.first);
      
      FixEmptyBinsMC(channel_+prefix,"W",false);
      if(channel_=="eleTau"){
      	FixEmptyBinsMC(channel_+prefix,"ZL",false);
      	FixEmptyBinsMC(channel_+prefix,"ZJ",false);
      }
      
//       if(channel_=="muTau"&&prefix=="_0jet_high"){
//       	superSmooth(channel_+prefix, "W");
//       }
      
      
      
//       if(channel_=="eleTau"){
//       	if(prefix=="_0jet_low"){
//       		superSmooth(channel_+prefix, "ZJ");
//       		superSmooth(channel_+prefix, "W");
//       	}
//       	if(prefix=="_boost_low"){
//       		superSmooth(channel_+prefix, "TT");
//       		superSmooth(channel_+prefix, "ZL");
//       		superSmooth(channel_+prefix, "VV");
//       		superSmooth(channel_+prefix, "QCD");
//       		superSmooth(channel_+prefix, "W");
//       	}
//       	if(prefix=="_0jet_high"){
//       		superSmooth(channel_+prefix, "W");
//       		superSmooth(channel_+prefix, "QCD");
//       	}
//       	if(prefix=="_boost_high"){
//       		superSmooth(channel_+prefix, "ZL");
//       		superSmooth(channel_+prefix, "W");
//       	}
//       }
      		
      
//       if(channel_=="eleTau"){
//       	zeeShapeSyst(channel_+prefix, "ZL");
// 	  }


      return output;
  }





  BkgOutput runABCD(std::string preSelection,std::string catSelection,std::string prefix,float zExtrap,float zExtrapErr,float topExtrap,float topExtrapErr,std::string zShape = "") {
    BkgOutput output;


    //create Z->tautau 
    std::pair<float,float> zttYield       = createHistogramAndShifts(zttFile_,"ZTTTMP",("("+preSelection+"&&"+trigSelection_+"&&"+catSelection+"&&"+osSignalSelection_+"&&genTaus>0&&genVisPt2>18)*"+weight_),luminosity_*zttScale_*muID_*zExtrap*eleID_,prefix);

    if(zShape.size()==0) {
      std::pair<float,float> zttShape     = createHistogramAndShifts(zttFile_,"ZTT",("("+preSelection+"&&"+trigSelection_+"&&"+catSelection+"&&"+osSignalSelection_+"&&genTaus>0&&genVisPt2>18)*"+weight_),luminosity_*zttScale_*muID_*zExtrap*eleID_,prefix);
	output.ZTTCORR=zExtrap;
	output.dZTTCORR=zExtrapErr;
    }
    else {
	printf("You have embedded samples.Calculating corrections on the fly overidding the crappy ones you gave me!\n");
	std::pair<float,float> zttPreMC     = createHistogramAndShifts(zttFile_,"ZTTMCPre",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&genTaus>0&&genVisPt2>18)*"+weight_),luminosity_*zttScale_*muID_*eleID_,prefix);
	std::pair<float,float> zttPreYield  = createHistogramAndShifts(zShape,"ZTTTMPInc",("("+preSelection+"&&"+osSignalSelection_+")*embeddedWeight"),muID_*eleID_,prefix);
	std::pair<float,float> zttShape       = createHistogramAndShifts(zShape,"ZTTTMPPRE",("("+preSelection+"&&"+catSelection+"&&"+osSignalSelection_+")*embeddedWeight"),muID_*eleID_,prefix);
	std::pair<float,float> zttHisto       = createHistogramAndShifts(zShape,"ZTT",("("+preSelection+"&&"+catSelection+"&&"+osSignalSelection_+")*embeddedWeight"),muID_*eleID_,prefix);

	//creating Correction Factor on the fly:
	double corr = zttShape.first/zttPreYield.first;
	double corrErr =max(TEfficiency::ClopperPearson((int)zttPreYield.first,(int)zttShape.first,0.68,true)-corr,corr-TEfficiency::ClopperPearson((int)zttPreYield.first,(int)zttShape.first,0.68,false));
	  
	zttYield = std::make_pair(zttPreMC.first*corr,sqrt(zttPreMC.second*zttPreMC.second*corr*corr+zttPreMC.first*zttPreMC.first*corrErr*corrErr));

	printf("New Correction factor = %f +- %f\n",corr,corrErr);
	renormalizeHistogram(channel_+prefix,"ZTT",zttPreMC.first*corr);
	  
	output.ZTTCORR=corr;
	output.dZTTCORR=corrErr;
    }

    //create TTbar
    std::pair<float,float> topYield       = createHistogramAndShifts(topFile_,"TT",("("+preSelection+"&&"+trigSelection_+"&&"+catSelection+"&&"+osSignalSelection_+")*"+weight_),luminosity_*muID_*eleID_*topExtrap,prefix);
    //Create TTbar in Sideband
    std::pair<float,float> topSSYield       = createHistogramAndShifts(topFile_,"TTSS",("("+preSelection+"&&"+trigSelection_+"&&"+catSelection+"&&"+ssSignalSelection_+")*"+weight_),luminosity_*muID_*eleID_*topExtrap,prefix);
    //create Diboson
    std::pair<float,float> vvYield        = createHistogramAndShifts(vvFile_,"VV",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+catSelection+")*"+weight_),luminosity_*muID_*eleID_,prefix);
    std::pair<float,float> vvSSYield        = createHistogramAndShifts(vvFile_,"VVSS",("("+preSelection+"&&"+trigSelection_+"&&"+catSelection+"&&"+ssSignalSelection_+")*"+weight_),luminosity_*muID_*eleID_,prefix);

    //create VJets
    std::pair<float,float> wYield       = createHistogramAndShifts(wFile_,"W",("("+preSelection+"&&"+trigSelection_+"&&"+catSelection+"&&"+osSignalSelection_+")*"+weight_),luminosity_*(muID_+eleID_)*topExtrap/2.,prefix);
    std::pair<float,float> wSSYield       = createHistogramAndShifts(wFile_,"WSS",("("+preSelection+"&&"+trigSelection_+"&&"+catSelection+"&&"+ssSignalSelection_+")*"+weight_),luminosity_*(muID_+eleID_)/2*topExtrap,prefix);
    std::pair<float,float> zYield       = createHistogramAndShifts(zllFile_,"Z",("("+preSelection+"&&"+trigSelection_+"&&"+catSelection+"&&"+osSignalSelection_+"&&genTaus==0)*"+weight_),luminosity_*(muID_+eleID_)*topExtrap/2.,prefix);
    std::pair<float,float> zSSYield       = createHistogramAndShifts(zllFile_,"ZSS",("("+preSelection+"&&"+trigSelection_+"&&"+catSelection+"&&"+ssSignalSelection_+"&&genTaus==0)*"+weight_),luminosity_*(muID_+eleID_)/2*topExtrap,prefix);
    //Add them
    std::pair<float,float> vYield = std::make_pair(wYield.first+zYield.first,quadrature(wYield.first+zYield.first,sqrt(wYield.second*wYield.second+zYield.second*zYield.second),zjftErr_));
    std::pair<float,float> vSSYield = std::make_pair(wSSYield.first+zSSYield.first,quadrature(wSSYield.first+zSSYield.first,sqrt(wSSYield.second*wSSYield.second+zSSYield.second*zSSYield.second),zjftErr_));



    //oooook Now create the four regions:


    // OS+Isolated
    std::pair<float,float> dataY         = createHistogramAndShifts(dataFile_,"data_obs","("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+catSelection+")",scaleUp_,prefix);
    std::pair<float,float> dataYRounded  = std::make_pair(rintf(dataY.first),dataY.second);
    renormalizeHistogram(channel_+prefix,"data_obs",dataYRounded.first);
    std::pair<float,float> dataYield      = convertToPoisson(dataYRounded);

    // OS+NonIsolated
    std::pair<float,float> dataYSdb       = createHistogramAndShifts(dataFile_,"data_sdb","("+preSelection+"&&"+trigSelection_+"&&"+osWSelection_+"&&"+catSelection+")",scaleUp_,prefix);
    std::pair<float,float> dataYieldSdb      = convertToPoisson(dataYSdb);

    //SS+Isolated
    //    std::pair<float,float> dataSSY        = createHistogramAndShifts(dataFile_,"data_sdb","("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+catSelection+")",scaleUp_,prefix);
    std::pair<float,float> dataSSY        = createHistogramAndShifts(dataFile_,"data_sdb","("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+")",scaleUp_,prefix);
    std::pair<float,float> dataSSYield    = convertToPoisson(dataSSY);

    //SS+NonIsolated
    //    std::pair<float,float> dataSSYSdb        = createHistogramAndShifts(dataFile_,"data_sdb","("+preSelection+"&&"+trigSelection_+"&&"+ssWSelection_+"&&"+catSelection+")",scaleUp_,prefix);
    std::pair<float,float> dataSSYSdb        = createHistogramAndShifts(dataFile_,"data_sdb","("+preSelection+"&&"+trigSelection_+"&&"+ssWSelection_+")",scaleUp_,prefix);


    std::pair<float,float> dataSSYieldSdb = convertToPoisson(dataSSYSdb);


    //shape creation for Fakes
    std::pair<float,float> dataFAKEControl = createHistogramAndShifts(dataFile_,"FAKES",qcdSelection_,scaleUp_,prefix);
    std::pair<float,float> ttFAKEControl = createHistogramAndShifts(topFile_,"TOPFAKES","("+qcdSelection_+"&&"+catSelection+")*"+weight_,luminosity_*muID_*eleID_,prefix);
    subtractHistogram(channel_+prefix,"FAKES","TOPFAKES");



    //Inflate the errors(note that currently there are only statistical on templates+ Add here the background estimates)
    std::pair<float,float> topInflYield  = inflateError(topYield,topErr_);
    printf("TTbar events in signal region = %f + %f \n",topInflYield.first,topInflYield.second);

    std::pair<float,float> topInflSSYield  = inflateError(topSSYield,topErr_);
    printf("TTbar events in SS signal region = %f + %f \n",topInflSSYield.first,topInflSSYield.second);

    std::pair<float,float> vvInflYield  = inflateError(vvYield,vvErr_);
    printf("Diboson events in signal region = %f + %f \n",vvInflYield.first,vvInflYield.second);

    std::pair<float,float> vvInflSSYield  = inflateError(vvSSYield,vvErr_);
    printf("Diboson events in SS region = %f + %f \n",vvInflSSYield.first,vvInflSSYield.second);
    
    //Run ABCD Method
    printf("1. Subtract TTbar ,V+Jets and diboson from SS region");
    std::pair<float,float> C = std::make_pair(TMath::Nint(dataSSYield.first-topInflSSYield.first-vvInflSSYield.first-vSSYield.first),
						      sqrt(dataSSYield.second*dataSSYield.second+topInflSSYield.second*topInflSSYield.second+vvInflSSYield.second*vvInflSSYield.second+vSSYield.second*vSSYield.second));
    printf("SS FAKES  =%f -%f -%f  = %f +- %f \n",dataSSYield.first,topInflSSYield.first,vvInflSSYield.first,C.first,C.second);

    printf("ABCD Method---------------\n");
    printf("B: OS Anti-isolated = %f +- %f\n",dataYieldSdb.first,dataYieldSdb.second);
    printf("C: SS Isolated      = %f +- %f \n",C.first,C.second);
    printf("D: SS Anti-isolated  = %f +- %f \n",dataSSYieldSdb.first,dataSSYieldSdb.second);

    
    std::pair<float,float> A = std::make_pair((dataYieldSdb.first*C.first/dataSSYieldSdb.first),sqrt(pow(C.first*dataYieldSdb.second/dataSSYieldSdb.first,2)+
												     pow(dataYieldSdb.first*C.second/dataSSYieldSdb.first,2)+
												     pow(dataYieldSdb.first*C.first*dataSSYieldSdb.second/(dataSSYieldSdb.first*dataSSYieldSdb.first),2)));

    

    printf("QCD in Signal region = %f +- %f\n",A.first,A.second);

    printf("Add the other fakes from MC\n");
    std::pair<float,float> Fakes = std::make_pair(A.first+vYield.first+0.0001,sqrt(A.second*A.second+vYield.second*vYield.second));
    printf("Fakes in Signal region = %f +- %f\n",Fakes.first,Fakes.second);
    


      ///LATEX->Here since we want it for the note add all errors , even those that will go separate in the datacard
      printf("LATEX ------------------------------------\n");
      printf("Total & %.2f & %.2f  \\\\ \n", dataYield.first,  dataSSYieldSdb.first);
      printf("Di-Boson & %.2f $\\pm$ %.2f & %.2f $\\pm$ %.2f  \\\\ \n", vvInflYield.first, quadrature(vvInflYield.first,vvInflYield.second,muIDErr_,eleIDErr_), vvInflSSYield.first, quadrature(vvInflSSYield.first,vvInflSSYield.second,muIDErr_,eleIDErr_));
      printf("$t\\bar{t}$ & %.2f $\\pm$ %.2f & %.2f $\\pm$ %.2f \\\\ \n", topInflYield.first,quadrature(topInflYield.first,topInflYield.second,muIDErr_,eleIDErr_,topExtrapErr), topInflSSYield.first, quadrature(topInflSSYield.first,topInflSSYield.second,muIDErr_,eleIDErr_*topExtrapErr));
      printf("Fakes & %.2f $\\pm$ %.2f &  %.2f $\\pm$ %.2f \\\\ \n", Fakes.first, Fakes.second, C.first, C.second);
      printf("$Z\\rightarrow\\tau\\tau$ & %.2f $\\pm$ %.2f & - \\\\ \n", zttYield.first,quadrature(zttYield.first,zttYield.second,muIDErr_,eleIDErr_,zttScaleErr_,zExtrapErr));
      printf("Total Background & %.2f $\\pm$ %.2f &  - \\\\ \n",vvInflYield.first+topInflYield.first+Fakes.first+zttYield.first,sqrt(pow(quadrature(vvInflYield.first,vvInflYield.second,muIDErr_,eleIDErr_),2)+
										       pow(quadrature(topInflYield.first,topInflYield.second,muIDErr_,eleIDErr_,topExtrapErr),2)+
										       pow(Fakes.second,2)+
										       pow(quadrature(zttYield.first,zttYield.second,muIDErr_,eleIDErr_,zttScaleErr_,zExtrapErr),2)));

      output.DATA = dataYield.first;

      output.QCD = Fakes.first;
      output.dQCD = Fakes.second;

      output.TOP = topInflYield.first;
      output.dTOP = topInflYield.second;

      output.VV = vvInflYield.first;
      output.dVV = vvInflYield.second;


      output.ZTT = zttYield.first;
      output.dZTT = zttYield.second;
      

	  if(channel_=="eleTau"){
      	renormalizeHistogram(channel_+prefix,"FAKES",Fakes.first);
	  }


      return output;
  }


  BkgOutput runFullExtrapolationBTag(std::string preSelection,
				     std::string categorySelection, 
				     std::string prefix, 
				     BkgOutput inclusive,
				     float zExtrap,
				     float zExtrapErr,
				     float wExtrap,
				     float wExtrapErr,
				     float topExtrap,
				     float topExtrapErr,
				     std::string zShape_="",
				     std::string wShape_="",
				     std::string btagSF="1"){
    //std::string embeddedWeight ="1") {
    //bool RunBTagUnc=false;  
    bool finebins = false;

    /*
    fakeRateFile << " creating b-tagging FakeRates for: " << prefix << "\n \n";
    fakeRateFile << "\tInclusive \t MeanMatch \t MeanNotMatch \t Match1 \t Match2 \t Match3 \t Fake1 \t Fake2 \t Fake3 \n";
    std::cout<< "      number of bins: "<< bins_ <<std::endl;
    std::cout << " WEIGHT:  " <<weight_ << std::endl;
    */
    weight_=weight_+"*"+btagSF;

    float leg1Corr=1.0;
    if(muID_!=0) leg1Corr*=muID_;
    if(eleID_!=0) leg1Corr*=eleID_;

    float tauID = 1.0;
    tauID = tauID_; 
    
    printf("Tau ID Scale Factor is %.3f \n",tauID);		
    
    BkgOutput output;
    
    output.ZTTCORR=zExtrap;
    output.dZTTCORR=zExtrapErr;

    std::string defaultSelection= preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+osSignalSelection_;    
    
    std::pair<float,float> zttYield  = createHistogramAndShiftsFinal(zttFile_,"ZTTTMP",("("+defaultSelection+"&&"+genTauSel_+")*"+weight_),luminosity_*zttScale_*leg1Corr*tauID,prefix);
    std::pair<float,float> ztt_ll    = createHistogramAndShiftsFinal(zttFile_,"ZTT_LL",("("+defaultSelection+"&&"+genTauReject_+")*"+weight_),luminosity_*zttScale_*leg1Corr*tauID,prefix);

    float corr = 1.0;
    float corrZee = 1.0;
   
    if(zShape_.size()==0) {
      std::pair<float,float> zttShape       = createHistogramAndShiftsFinal(zttFile_,"ZTT",("("+defaultSelection+"&&genTaus>0)*"+weight_),luminosity_*zttScale_*leg1Corr*tauID*zExtrap,prefix,true);
      
    }
    else
      {
	
	printf("You have embedded samples.Calculating corrections on the fly overidding the ones you gave me!\n");
	std::pair<float,float> zttShape      = createHistogramAndShifts(zShape_,"ZTT",("("+preSelection+"&&"+categorySelection+"&&"+osSignalSelection_+"&&"+dataSelection_+"&&genFullMass>50&&genVisPt2>18)*"+embWeight_),leg1Corr*tauID,prefix,true);
  	std::pair<float,float> zttEmbYield   = createHistogramAndShifts(zShape_,"ZTTTMP",("("+preSelection+"&&"+categorySelection+"&&"+osSignalSelection_+"&&"+dataSelection_+"&&genFullMass>50&&genVisPt2>18)*"+embWeight_),leg1Corr*tauID,prefix,true);
	
	std::pair<float,float> zttShapePre   = createHistogramAndShifts(zShape_,"ZTTPre",("("+preSelection+"&&"+osSignalSelection_+"&&"+dataSelection_+"&&genFullMass>50&&genVisPt2>18)*"+embWeight_),leg1Corr*tauID,prefix,true);
	  
	corr = zttEmbYield.first/zttShapePre.first;
	printf("zttEMYield: %f zttShapePre: %f -------\n",zttEmbYield.first,zttShapePre.first);
	printf("Efficiency for embedding =%f\n",corr);	
	
	double corrErr = corr*sqrt(1/zttEmbYield.first + 1/zttShapePre.first);;
	zttYield = std::make_pair(inclusive.ZTT*corr,inclusive.dZTT*corrErr);
	renormalizeHistogram(channel_+prefix,"ZTT",inclusive.ZTT*corr);
	output.ZTTCORR=corr;
	output.dZTTCORR=corrErr;
	addHistogramZTT(channel_+prefix, "ZTT", "ZTT_LL");
	}

    //////// Produce ttbar ////////
    std::pair<float,float> topYield     = createHistogramAndShiftsFinal(topFile_,"TT",("("+defaultSelection+")*"+weight_),luminosity_*leg1Corr*tauID*topExtrap,prefix);
    if(finebins)std::pair<float,float> topFineBins     = createHistogramAndShiftsFinalFineBins(topFile_,"TT",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+osSignalSelection_+")*"+weight_),luminosity_*leg1Corr*tauID*topExtrap,prefix);
    /////subtract ztt contribution from ttbar
    topYield = std::make_pair(topYield.first-(zttYield.first*0.015), topYield.second);
    
    renormalizeHistogram(channel_+prefix,"TT",topYield.first);
    //renormalizeHistogram(channel_+prefix,"TT_fine_binning",topYield.first);
    
    //////// Produce VV ////////
    std::pair<float,float> vvYield        = createHistogramAndShiftsFinal(vvFile_,"VV",("("+defaultSelection+")*"+weight_),luminosity_*leg1Corr*tauID,prefix,true,false);
    
    ///////// Estimate ZLL ////////////    
    std::pair<float,float> zllShape;
    std::pair<float,float> zllYield;	
    std::pair<float,float> zlYield;
    std::pair<float,float> zjYield;
    

    std::pair<float,float> zlShape      = createHistogramAndShiftsFinal(zttFile_,"ZL",("("+defaultSelection+"&&"+genLSel_+")*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zttScale_,prefix,false,false);    
    std::pair<float,float> zjShape      = createHistogramAndShiftsFinal(zttFile_,"ZJ",("("+defaultSelection+"&&"+genLReject_+")*"+weight_),luminosity_*leg1Corr*zttScale_,prefix,false,false);

    zlYield      = createHistogramAndShiftsFinal(zttFile_,"ZLTMP",("("+defaultSelection+"&&"+genLSel_+")*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zttScale_,prefix,false);
    zjYield      = createHistogramAndShiftsFinal(zttFile_,"ZJTMP",("("+defaultSelection+"&&"+genLReject_+")*"+weight_),luminosity_*leg1Corr*zttScale_,prefix,false);
    
    zllYield.first = zlYield.first+zjYield.first;
    zllYield.second = sqrt(zlYield.second*zlYield.second+zjYield.second*zjYield.second);


    if(channel_=="eleTau"&&shifts_.size()>0){
      std::pair<float,float> zlShiftUp      = createHistogramShifted(zttFile_,"ZL_CMS_htt_ZLScale_etau_"+energy_+"Up",("("+defaultSelection+"&&"+genLSel_+")*ZeFakeTau*"+weight_),"1.02",luminosity_*leg1Corr*zlftFactor_*zttScale_*zExtrap,prefix);
      std::pair<float,float> zlShiftDown     = createHistogramShifted(zttFile_,"ZL_CMS_htt_ZLScale_etau_"+energy_+"Down",("("+defaultSelection+"&&"+genLSel_+")*ZeFakeTau*"+weight_),"0.98",luminosity_*leg1Corr*zlftFactor_*zttScale_*zExtrap,prefix);
      
      renormalizeHistogram(channel_+prefix,"ZL_CMS_htt_ZLScale_etau_"+energy_+"Up",zlYield.first);
      renormalizeHistogram(channel_+prefix,"ZL_CMS_htt_ZLScale_etau_"+energy_+"Down",zlYield.first);
      
    }
    else if(shifts_.size()>0){
      std::pair<float,float> zlShiftUp      = createHistogramShifted(zttFile_,"ZL_CMS_htt_ZLScale_mutau_"+energy_+"Up",("("+defaultSelection+"&&"+genLSel_+")*ZeFakeTau*"+weight_),"1.02",luminosity_*leg1Corr*zlftFactor_*zttScale_*zExtrap,prefix);
      std::pair<float,float> zlShiftDown    = createHistogramShifted(zttFile_,"ZL_CMS_htt_ZLScale_mutau_"+energy_+"Down",("("+defaultSelection+"&&"+genLSel_+")*ZeFakeTau*"+weight_),"0.98",luminosity_*leg1Corr*zlftFactor_*zttScale_*zExtrap,prefix);
      renormalizeHistogram(channel_+prefix,"ZL_CMS_htt_ZLScale_mutau_"+energy_+"Up",zlYield.first);
      renormalizeHistogram(channel_+prefix,"ZL_CMS_htt_ZLScale_mutau_"+energy_+"Down",zlYield.first);

	}
    
    renormalizeHistogram(channel_+prefix,"ZL",zlYield.first);
    renormalizeHistogram(channel_+prefix,"ZJ",zjYield.first);
    mergeHistogram(channel_+prefix,"ZL","ZJ","ZLL");

    std::pair<float,float> zllSSYield    = createHistogramAndShifts(zttFile_,"ZLL_SS",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+ssSignalSelection_+"&&genTaus==0)*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zExtrap*zttScale_,prefix,false);

    ///////////////////////// W Background /////////////////////////////
    std::pair<float,float> wYield;
  
    std::pair<float,float> wShape      = createHistogramAndShiftsFinal(wFile_,"W",("("+preSelection+"&&"+osSignalSelection_+"&&"+btagRelaxedSelection_+")*__WEIGHT__*__CORR__"),luminosity_*leg1Corr*wExtrap,prefix,false,false);
    //std::pair<float,float> wShape      = createHistogramAndShiftsFinal(wFile_,"W",("("+preSelection+"&&"+osSignalSelection_+"&&"+btagRelaxedSelection_+")*__WEIGHT__*__CORR__*WWeight"),luminosity_*leg1Corr*wExtrap,prefix,false,false);
    if(shifts_.size()>0){
      std::pair<float,float> wShapeUp = createHistogramAndShiftsFinal(wFile_,"WShapeUp",("("+preSelection+"&&"+osSignalSelection_+"&&"+btagRelaxedSelection_+")*__WEIGHT__*__CORR__*WWeightUp"),luminosity_*leg1Corr*wExtrap,prefix,false,false);
      std::pair<float,float> wShapeDown = createHistogramAndShiftsFinal(wFile_,"WShapeDown",("("+preSelection+"&&"+osSignalSelection_+"&&"+btagRelaxedSelection_+")*__WEIGHT__*__CORR__*WWeightDown"),luminosity_*leg1Corr*wExtrap,prefix,false,false);
    }
    if(finebins) std::pair<float,float> wShapeFineBins = createHistogramAndShiftsFinalFineBins(wFile_,"W",("("+preSelection+"&&"+osSignalSelection_+"&&"+btagRelaxedSelection_+")*__WEIGHT__*__CORR__*WWeight"),luminosity_*leg1Corr*wExtrap,prefix,false,false);    
    if(finebins) std::pair<float,float> wShapeFineBinsUp = createHistogramAndShiftsFinalFineBins(wFile_,"WShapeUp",("("+preSelection+"&&"+osSignalSelection_+"&&"+btagRelaxedSelection_+")*__WEIGHT__*__CORR__*WWeightUp"),luminosity_*leg1Corr*wExtrap,prefix,false,false);    
    if(finebins) std::pair<float,float> wShapeFineBinsDown = createHistogramAndShiftsFinalFineBins(wFile_,"WShapeDown",("("+preSelection+"&&"+osSignalSelection_+"&&"+btagRelaxedSelection_+")*__WEIGHT__*__CORR__*WWeightDown"),luminosity_*leg1Corr*wExtrap,prefix,false,false);

    ///////W Yield/////////
    std::pair<float,float> dataYWSDB   = createHistogramAndShiftsFinal(dataFile_,"dataWSDB","("+preSelection+"&&"+categorySelection+"&&"+osWSelection_+"&&"+trigSelection_+"&&"+dataSelection_+")",scaleUp_,prefix);
    std::pair<float,float> vvYieldSDB  = createHistogramAndShiftsFinal(vvFile_,"VVSDB",("("+preSelection+"&&"+categorySelection+"&&"+osWSelection_+"&&"+trigSelection_+")*"+weight_),luminosity_*leg1Corr*tauID,prefix,true,false);
    std::pair<float,float> topYieldSDB = createHistogramAndShiftsFinal(topFile_,"TTSDB",("("+preSelection+"&&"+categorySelection+"&&"+osWSelection_+"&&"+trigSelection_+")*"+weight_),luminosity_*leg1Corr*tauID*topExtrap,prefix);
    std::pair<float,float> zYieldSDB   = createHistogramAndShiftsFinal(zttFile_,"ZSDB",("("+preSelection+"&&"+categorySelection+"&&"+osWSelection_+"&&"+trigSelection_+")*ZeFakeTau*"+weight_),luminosity_*leg1Corr*tauID,prefix);

    std::pair<float,float> wFactor = extractWFactor(wFile_,preSelection+"&&"+trigSelection_+"&&charge==0&&"+btagRelaxedSelection_+"",prefix,"WWeight");
    std::pair<float,float> wFactorUp = extractWFactor(wFile_,preSelection+"&&"+trigSelection_+"&&charge==0&&"+btagRelaxedSelection_+"",prefix,"WWeightUp");
    std::pair<float,float> wFactorDown = extractWFactor(wFile_,preSelection+"&&"+trigSelection_+"&&charge==0&&"+btagRelaxedSelection_+"",prefix,"WWeightDown");
    

    std::pair<float,float> osWHigh = std::make_pair((TMath::Nint(dataYWSDB.first-topYieldSDB.first-vvYieldSDB.first-zYieldSDB.first)),
						    sqrt(dataYWSDB.second*dataYWSDB.second+topYieldSDB.second*topYieldSDB.second+vvYieldSDB.second*vvYieldSDB.second+zYieldSDB.second*zYieldSDB.second));	  

    printf("OS W in sideband  =%f -%f -%f -%f = %f +- %f \n",dataYWSDB.first,topYieldSDB.first,vvYieldSDB.first,zYieldSDB.first,osWHigh.first,osWHigh.second);

    wYield = std::make_pair(osWHigh.first*wFactor.first,
			      sqrt(osWHigh.first*osWHigh.first*wFactor.second*wFactor.second+osWHigh.second*osWHigh.second*wFactor.first*wFactor.first));

    printf("W Yield = %f * %f = %f\n", osWHigh.first, wFactor.first, wYield.first);

    std::pair<float,float> wYieldUp;
    std::pair<float,float> wYieldDown;
    if(shifts_.size()>0){
      wYieldUp = std::make_pair(osWHigh.first*wFactorUp.first,
				sqrt(osWHigh.first*osWHigh.first*wFactor.second*wFactor.second+osWHigh.second*osWHigh.second*wFactor.first*wFactor.first));
      
      wYieldDown = std::make_pair(osWHigh.first*wFactorDown.first,
				  sqrt(osWHigh.first*osWHigh.first*wFactor.second*wFactor.second+osWHigh.second*osWHigh.second*wFactor.first*wFactor.first));
    }
    
    renormalizeHistogram(channel_+prefix,"W",wYield.first);   
    if(finebins)renormalizeHistogram(channel_+prefix,"W_fine_binning",wYield.first);   

    if(shifts_.size()>0){
      renormalizeHistogram(channel_+prefix,"WShapeUp",wYieldUp.first);   
      renormalizeHistogram(channel_+prefix,"WShapeUp_fine_binning",wYieldUp.first);   
      
      renormalizeHistogram(channel_+prefix,"WShapeDown",wYieldDown.first);   
      renormalizeHistogram(channel_+prefix,"WShapeDown_fine_binning",wYieldDown.first);   
    }

    /////// start QCD estimation
    /*
    std::pair<float,float> dataYWSDBL   = createHistogramAndShiftsFinal(dataFile_,"dataWSDBL","("+preSelection+"&&"+btagRelaxedSelection_+"&&"+osWSelection_+"&&"+trigSelection_+"&&"+dataSelection_+")",scaleUp_,prefix);
    std::pair<float,float> vvYieldSDBL  = createHistogramAndShiftsFinal(vvFile_,"VVSDBL",("("+preSelection+"&&"+btagRelaxedSelection_+"&&"+osWSelection_+"&&"+trigSelection_+")*"+weight_),luminosity_*leg1Corr*tauID,prefix,true,false);
    std::pair<float,float> topYieldSDBL = createHistogramAndShiftsFinal(topFile_,"TTSDBL",("("+preSelection+"&&"+btagRelaxedSelection_+"&&"+osWSelection_+"&&"+trigSelection_+")*"+weight_),luminosity_*leg1Corr*tauID*topExtrap,prefix);
    std::pair<float,float> zYieldSDBL = createHistogramAndShiftsFinal(zttFile_,"ZSDBL",("("+preSelection+"&&"+btagRelaxedSelection_+"&&"+osWSelection_+"&&"+trigSelection_+")*ZeFakeTau*"+weight_),luminosity_*leg1Corr*tauID*topExtrap,prefix);
    //std::pair<float,float> wFactorL = extractWFactor(wFile_,preSelection+"&&"+categorySelection,prefix);
    std::pair<float,float> wFactorL = extractWFactor(wFile_,preSelection+"&&"+btagRelaxedSelection_+"",prefix);
    std::pair<float,float> osWHighL = std::make_pair(TMath::Nint(dataYWSDBL.first-topYieldSDBL.first-vvYieldSDBL.first-zYieldSDBL.first),
						    sqrt(dataYWSDBL.second*dataYWSDBL.second+topYieldSDBL.second*topYieldSDBL.second+vvYieldSDBL.second*vvYieldSDBL.second+zYieldSDBL.second*zYieldSDBL.second));	  
    
    std::pair<float,float> wYieldL = std::make_pair(osWHighL.first*wFactorL.first,
			      sqrt(osWHighL.first*osWHighL.first*wFactorL.second*wFactorL.second+osWHighL.second*osWHighL.second*wFactorL.first*wFactorL.first));
    */
    //std::pair<float,float> wSSYield = std::make_pair(wYield.first*inclusive.WSS/inclusive.W,wYield.second*inclusive.WSS/inclusive.W);
    
    std::pair<float,float> dataY         = createHistogramAndShiftsFinal(dataFile_,"data_obs","("+defaultSelection+"&&"+blinding_+"&&"+dataSelection_+")",scaleUp_,prefix);
    if(finebins) std::pair<float,float> dataYFineBins = createHistogramAndShiftsFinalFineBins(dataFile_,"data_obs","("+defaultSelection+"&&"+blinding_+"&&"+dataSelection_+")",scaleUp_,prefix);

    std::pair<float,float> dataYRounded  = std::make_pair(rintf(dataY.first),dataY.second);

    renormalizeHistogram(channel_+prefix,"data_obs",dataYRounded.first);

    std::pair<float,float> dataYield      = convertToPoisson(dataYRounded);
    std::pair<float,float> dataSSY          = createHistogramAndShifts(dataFile_,"data_obs_ss","("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+ssSignalSelection_+")",scaleUp_,prefix);
    std::pair<float,float> dataSSYield      = convertToPoisson(dataSSY);
    
    float qcdPass;
    float qcdAll;
    std::pair<float,float> dataQCDShape;
    float qcdFactor;
    float qcdFactorErr;
    std::pair<float,float> osQCD;
    std::pair<float,float> ssQCD;


    ////////////////// QCD ESTIMATION!!!!!!! ///////////////////
    ///// QCD Shape
    std::pair<float,float> dataQCDYield = createHistogramAndShifts(dataFile_,"QCDYield","("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+categorySelection+")",scaleUp_,prefix);

    std::pair<float,float> zllQCDShape = createHistogramAndShifts(zllFile_,"ZLLQCDShape","("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+btagRelaxedSelection_+"&&genTaus==0)*ZeFakeTau*"+weight_,luminosity_*leg1Corr*zttScale_,prefix);
    std::pair<float,float> dataQCDShape1= createHistogramAndShifts(dataFile_,"QCD","("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+btagRelaxedSelection_+")",scaleUp_,prefix);
    std::pair<float,float> topYieldQCD = createHistogramAndShifts(topFile_,"TTQCD",("("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+btagRelaxedSelection_+")*"+weight_),luminosity_*leg1Corr*tauID*topExtrap,prefix);
    ////// QCD YIELD
    std::pair<float,float> wShapeSS = createHistogramAndShifts(wFile_,"WQCD",("("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+btagRelaxedSelection_+")*"+weight_),luminosity_*leg1Corr,prefix,false);       
    std::pair<float,float> wSSYield = std::make_pair(wYield.first*inclusive.WSS/inclusive.W,wYield.second*inclusive.WSS/inclusive.W);
   
    std::pair<float,float> vvYieldSS  = createHistogramAndShifts(vvFile_,"VVSS",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+ssSignalSelection_+")*"+weight_),luminosity_*leg1Corr*tauID,prefix,true,false);
    std::pair<float,float> topSSYield       = createHistogramAndShifts(topFile_,"TTSS",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+ssSignalSelection_+")*"+weight_),luminosity_*leg1Corr*tauID*topExtrap,prefix);
    std::pair<float,float> zYieldSS    = createHistogramAndShifts(zttFile_,"ZSS",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+ssSignalSelection_+")*"+weight_),luminosity_*leg1Corr*tauID,prefix);
    std::pair<float,float> zllQCDYield = createHistogramAndShifts(zllFile_,"ZLLQCD","("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+categorySelection+"&&genTaus==0)*ZeFakeTau*"+weight_,luminosity_*leg1Corr*zttScale_,prefix);    
    /*
    std::pair<float,float> zlftSSYield = createHistogramAndShifts(zllFile_,"ZL_SS",("("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+categorySelection+"&&genTaus==0&&genPt2>8)*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zttScale_*zExtrap,prefix,false);
    std::pair<float,float> zjftSSYield = createHistogramAndShifts(zllFile_,"ZJ_SS",("("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+categorySelection+"&&genTaus==0&&genPt2<8)*"+weight_),luminosity_*leg1Corr*zttScale_*zExtrap,prefix);     */
    std::pair<float,float> wMCSSYield  = createHistogramAndShifts(wFile_,"WSS",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+ssSignalSelection_+")*"+weight_),luminosity_*leg1Corr,prefix);      
    
    //renormalizeHistogram(channel_+prefix,"TTSS",topYieldSS.first-zYieldSS.first*0.15);
    renormalizeHistogram(channel_+prefix,"TTSS",topSSYield.first);
    
      ////////////////////////////Make fine binned QCD shape
    if(finebins){
      std::pair<float,float> dataQCDShapeFineBins= createHistogramAndShiftsFineBins(dataFile_,"QCD","("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+btagRelaxedSelection_+")",scaleUp_,prefix);
      std::pair<float,float> wShapeSSFineBins = createHistogramAndShiftsFineBins(wFile_,"WQCD",("("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+btagRelaxedSelection_+")*"+weight_),luminosity_*leg1Corr,prefix,false); 
      std::pair<float,float> zllQCDFineBins = createHistogramAndShiftsFineBins(zllFile_,"ZLLQCD","("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+btagRelaxedSelection_+"&&genTaus==0)*ZeFakeTau*"+weight_,luminosity_*leg1Corr*zttScale_,prefix);
      std::pair<float,float> topYieldQCDFineBins = createHistogramAndShiftsFineBins(topFile_,"TTQCD",("("+preSelection+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+btagRelaxedSelection_+")*"+weight_),luminosity_*leg1Corr*tauID*topExtrap,prefix);
      renormalizeHistogram(channel_+prefix,"TTQCD_fine_binning",topSSYield.first-zYieldSS.first*0.15);
    }
      ////////////////////////////Finish Fine binned qcd shapes
      renormalizeHistogram(channel_+prefix,"QCD",dataQCDYield.first);
      renormalizeHistogram(channel_+prefix,"WQCD",wSSYield.first);
      renormalizeHistogram(channel_+prefix,"ZLLQCD",zllQCDYield.first);

      if(finebins){
	renormalizeHistogram(channel_+prefix,"QCD_fine_binning",dataQCDYield.first);
	renormalizeHistogram(channel_+prefix,"WQCD_fine_binning",wSSYield.first);
	renormalizeHistogram(channel_+prefix,"ZLLQCD_fine_binning",zllQCDYield.first);
      }

      subtractHistogram(channel_+prefix,"QCD","ZLLQCD");
      subtractHistogram(channel_+prefix,"QCD","TTQCD");
      subtractHistogram(channel_+prefix,"QCD","WQCD");
      if(finebins){
	subtractHistogram(channel_+prefix,"QCD_fine_binning","ZLLQCD_fine_binning");
	subtractHistogram(channel_+prefix,"QCD_fine_binning","TTQCD_fine_binning");
	subtractHistogram(channel_+prefix,"QCD_fine_binning","WQCD_fine_binning");
      }


      ssQCD = std::make_pair(TMath::Nint(dataSSYield.first-
					 wSSYield.first-
					 zllQCDYield.first-
					 topSSYield.first-
					 zYieldSS.first-
					 vvYieldSS.first),
			     sqrt(dataSSYield.second*dataSSYield.second+wSSYield.second*wSSYield.second+zYieldSS.second*zYieldSS.second+vvYieldSS.second*vvYieldSS.second));
      

      printf("SS QCD in  core  = (data) %f - (wSS)%f -(zllSS)%f -(topSS) %f - (zYieldSS) %f - (vvYieldSS) %f= %f +- %f \n",
	     dataSSYield.first,
	     wSSYield.first,
	     zllQCDYield.first,
	     topSSYield.first,
	     zYieldSS.first,////
	     vvYieldSS.first,
	     ssQCD.first,
	     ssQCD.second); 

    if(ssQCD.first<0) {
      ssQCD.first=0.0000001;
      ssQCD.second=1.8;
    }

    osQCD = std::make_pair(ssQCD.first*qcdFactor_,sqrt(ssQCD.second*ssQCD.second*qcdFactor_*qcdFactor_+qcdFactorErr_*qcdFactorErr_*ssQCD.first*ssQCD.first));

    renormalizeHistogram(channel_+prefix,"QCD",osQCD.first);
    if(finebins)renormalizeHistogram(channel_+prefix,"QCD_fine_binning",osQCD.first);
    
    std::pair<float,float> topInflYield  = inflateError(topYield,topErr_);
    printf("TTbar events in signal region = %f + %f \n",topInflYield.first,topInflYield.second);

    std::pair<float,float> topInflSSYield  = inflateError(topSSYield,topErr_,topExtrapErr);
    printf("TTbar events in SS region = %f + %f \n",topInflSSYield.first,topInflSSYield.second);

    std::pair<float,float> vvInflYield  = inflateError(vvYield,vvErr_);
    printf("Diboson events in signal region = %f + %f \n",vvInflYield.first,vvInflYield.second);
    
    std::pair<float,float> zllInflYield  = inflateError(zllYield,zlftErr_,zjftErr_);
    printf("Z ->ll in signal region = %f + %f \n",zllInflYield.first,zllInflYield.second);

    std::pair<float,float> zllInflSSYield  = inflateError(zllSSYield,zjftErr_);
    printf("Z ->ll in SS region = %f + %f \n",zllInflSSYield.first,zllInflSSYield.second);

    std::pair<float,float> wInflYield  = inflateError(wYield,inclusive.dWCORR);
    printf("W in signal region = %f + %f \n",wInflYield.first,wInflYield.second);

    std::pair<float,float> wInflSSYield  = inflateError(wSSYield,inclusive.dWSSCORR,wExtrapErr);
    printf("W in SS region = %f + %f \n",wInflSSYield.first,wInflSSYield.second);


    float background    = osQCD.first+wInflYield.first+topInflYield.first+vvInflYield.first+zllInflYield.first+zttYield.first;
    float backgroundErr = sqrt(osQCD.second*osQCD.second+wInflYield.second*wInflYield.second+topInflYield.second*topInflYield.second+vvInflYield.second*vvInflYield.second+zllInflYield.second*zllInflYield.second+zttYield.second*zttYield.second);
    printf("BACKGROUND=%f +-%f \n",background,backgroundErr);
    
    
    ///LATEX
    printf("LATEX ------------------------------------\n");
    printf("Total & %.2f  \\\\ \n", dataYield.first);
    printf("Di-Boson & %.2f $\\pm$ %.2f  \\\\ \n", vvInflYield.first, quadrature(vvInflYield.first,vvInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_));
    printf("$t\\bar{t}$ & %.2f $\\pm$ %.2f \\\\ \n", topInflYield.first,quadrature(topInflYield.first,topInflYield.second,muIDErr_,eleIDErr_,tauIDErr_,topExtrapErr));
    printf("$Zll & %.2f $\\pm$ %.2f  \\\\ \n", zllInflYield.first, quadrature(zllInflYield.first,zllInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_,zExtrapErr));
    printf("$W+jets$ & %.2f $\\pm$ %.2f   \\\\ \n", wInflYield.first, quadrature(wInflYield.first,wInflYield.second,wExtrapErr));
    printf("QCD & %.2f $\\pm$ %.2f \\\\ \n", osQCD.first, osQCD.second);
    printf("$Z\\rightarrow\\tau\\tau$ & %.2f $\\pm$ %.2f & - & - & - \\\\ \n", zttYield.first,quadrature(zttYield.first,zttYield.second,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_,zExtrapErr));
    float fullBackgroundErr = sqrt(pow(quadrature(vvInflYield.first,vvInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_),2)+
				   pow(quadrature(topInflYield.first,topInflYield.second,muIDErr_,eleIDErr_,tauIDErr_),2)+
				   pow(quadrature(zllInflYield.first,zllInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_,zExtrapErr),2)+
				   pow(osQCD.second,2)+
				   pow(quadrature(wInflYield.first,wInflYield.second,wExtrapErr),2)+
				   pow(quadrature(zttYield.first,zttYield.second,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_,zExtrapErr),2));
    printf("Total Background & %.2f $\\pm$ %.2f & - & - & - \\\\ \n",background,fullBackgroundErr);
    
    //create a histogram with the error for plotting reasons and only
    TH1F *err = new TH1F("BKGErr","",1,0,1);
    err->SetBinContent(1,fullBackgroundErr/background);
    fout_->cd((channel_+prefix).c_str());
    err->Write();
    
    output.DATA = dataYield.first;
    output.W = wInflYield.first;
    output.dW = wInflYield.second;
    
    output.WSS = wInflSSYield.first;
    output.dWSS =wInflYield.second;
    
    output.QCD = osQCD.first;
    output.dQCD = osQCD.second;
    
    output.ZLFT = zllInflYield.first;
    output.dZLFT =zllInflYield.second;
    
    output.ZLFTSS = zllInflSSYield.first;
    output.dZLFTSS =zllInflSSYield.second;
    
    output.TOP = topInflYield.first;
    output.dTOP = topInflYield.second;
    
    output.VV = vvInflYield.first;
    output.dVV = vvInflYield.second;
    
    output.ZTT = zttYield.first;
    output.dZTT = zttYield.second;
    
    output.WCORR = inclusive.WCORR;
    output.dWCORR = inclusive.dWCORR;


    //now renormalize the data driven histograms
    FixEmptyBins(channel_+prefix,"QCD",true); ///// took this out for x-checks
    FixEmptyBinsMC(channel_+prefix,"W",false);
    
    FixEmptyBinsMC(channel_+prefix,"ZTT",false);
    
    if(channel_=="eleTau"){
      FixEmptyBinsMC(channel_+prefix,"ZLL",false);
      FixEmptyBinsMC(channel_+prefix,"ZL",false);
      FixEmptyBinsMC(channel_+prefix,"ZJ",false);      	
    }
    
  

    if(finebins)FixNegativeBinsMC(channel_+prefix, "QCD_fine_binning", true,false);
    ///////qcdSyst take qcd add 10% uncertainty from x= 0 to x=60
    qcdSystWithLimits(channel_+prefix, prefix, "QCD", 1., 0.1, 0, 40);
    if(finebins)qcdSystFine(channel_+prefix, prefix, "QCD_fine_binning", 1., 0.1, 0, 40,true);

    
    std::string chan = "mutau";
    if(channel_=="eleTau") chan = "etau";

    if(shifts_.size()>0)renameHist(channel_+prefix,"W_CMS_htt_WShape_"+chan+prefix+"_"+energy_+"Down","WShapeDown");
    if(finebins)renameHist(channel_+prefix,"W_CMS_htt_WShape_"+chan+prefix+"_"+energy_+"Down_fine_binning","WShapeDown_fine_binning");
    std::cout<<"W_CMS_htt_WShape_"+chan+prefix+"_"+energy_+"Down_fine_binning"<<std::endl;
    if(shifts_.size()>0)renameHist(channel_+prefix,"W_CMS_htt_WShape_"+chan+prefix+"_"+energy_+"Up","WShapeUp");
    if(finebins)renameHist(channel_+prefix,"W_CMS_htt_WShape_"+chan+prefix+"_"+energy_+"Up_fine_binning","WShapeUp_fine_binning");



    /////////////Output Signal Efficiency and Significance to file ///////////////// This is a temporary method!!!!!!
    std::pair<float,float> signalYield = createHistogramAndShiftsFinal(dir_+"Hhhttbb300.root","sigtemp","("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+")*"+weight_,luminosity_*leg1Corr,prefix);
    std::pair<float,float> signalYieldNoWeight = createHistogramAndShiftsFinal(dir_+"Hhhttbb300.root","sigtempNoWeight","("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+")",leg1Corr,prefix);
    std::pair<float,float> signalYieldNoSel = createHistogramAndShiftsFinal(dir_+"Hhhttbb300.root","sigtemp1","(pt1>0)*"+weight_,luminosity_*leg1Corr,prefix);

    //float signalYield = getYield("Hhh300",prefix);
    //float signalYieldNoSel = getYield("Hhh300NoSel",prefix);
    FILE *pfile = fopen("datacards/SignalSignificance.txt","a");
    fprintf(pfile,"%s  --> Hhh: %f  Efficiency: %f  Significance: %f S/B: %f\n",categorySelection.c_str(),signalYield.first,signalYield.first/signalYieldNoSel.first,signalYield.first/sqrt(background+signalYield.first),signalYield.first/background);

    float sigUnc = sqrt((signalYield.second*signalYield.second)/(signalYield.first*signalYield.first)+(fullBackgroundErr)/(background))*(signalYield.first/sqrt(background+signalYield.first));

    float effUnc = sqrt((signalYield.second*signalYield.second)/(signalYield.first*signalYield.first)+(signalYieldNoSel.second*signalYieldNoSel.second)/(signalYieldNoSel.first*signalYieldNoSel.first))*(signalYield.first/signalYieldNoSel.first);
    fprintf(pfile,"%.3f $\pm$ %.3f & %.3f $\pm$ %.3f & %.3f \n\n",
	    signalYield.first/(signalYieldNoSel.first),
	    effUnc,
	    signalYield.first/sqrt(background+signalYield.first),
	    sigUnc,
	    signalYield.first/background);
    fprintf(pfile,"Yield from file %.3f Eff %.3f $\pm$ %.3f & %.3f $\pm$ %.3f & %.3f \n\n",
	    signalYieldNoWeight.first,
	    signalYieldNoWeight.first/(1*10^6),
	    effUnc,
	    signalYield.first/sqrt(background+signalYield.first),
	    sigUnc,
	    signalYield.first/background);
    // printf("Total Background & %.2f $\\pm$ %.2f & - & - & - \\\\ \n",background,fullBackgroundErr);
    //std::cout<<" Hhh 300" << signalYield<< " Total Background "
    fclose(pfile);
    ///////////////////////////////////
    
      return output;
  }


//   BkgOutput runFullExtrapolation(std::string preSelection,std::string categorySelection, std::string prefix, BkgOutput inclusive,float zExtrap,float zExtrapErr,float wExtrap,float wExtrapErr,float topExtrap,float topExtrapErr,std::string zShape_="",std::string wShape_="") {
// 
//     float leg1Corr=1.0;
//     if(muID_!=0) leg1Corr*=muID_;
//     if(eleID_!=0) leg1Corr*=eleID_;
// 
// 	float tauID = 1.0;
// 	if(prefix=="_vbf"||prefix=="_2jet")
// 		tauID = tauID_ - (1.-tauIDHigh_)/2. ;
// 	else
// 		tauID = tauID_; 
// 
// 	printf("Tau ID Scale Factor is %.3f \n",tauID);		
// 
//       BkgOutput output;
// 
//       output.ZTTCORR=zExtrap;
//       output.dZTTCORR=zExtrapErr;
// 
// 
//     std::pair<float,float> zttYield       = createHistogramAndShiftsFinal(zttFile_,"ZTTTMP",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+osSignalSelection_+"&&genTaus>0&&genVisPt2>18)*"+weight_),luminosity_*zttScale_*leg1Corr*tauID*zExtrap,prefix,true);
// 	float corr = 1.0;
// 	float corrZee = 1.0;
// 
// 	
//     if(zShape_.size()==0) {
//       std::pair<float,float> zttShape       = createHistogramAndShiftsFinal(zttFile_,"ZTT",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+osSignalSelection_+"&&genTaus>0&&genVisPt2>18)*"+weight_),luminosity_*zttScale_*leg1Corr*tauID*zExtrap,prefix,true);
// 
//     }
//     else
//       {
// 
// 	printf("You have embedded samples.Calculating corrections on the fly overidding the crappy ones you gave me!\n");
// 
// 	std::pair<float,float> zttShape       = createHistogramAndShifts(zShape_,"ZTT",("("+preSelection+"&&"+categorySelection+"&&"+osSignalSelection_+"&&genFullMass>50&&genVisPt2>18)*embeddedWeight*__CORR__"),leg1Corr*tauID,prefix,true);
// 	
// 	std::pair<float,float> zttEmbYield    = createHistogramAndShifts(zShape_,"ZTTTMP",("("+preSelection+"&&"+categorySelection+"&&"+osSignalSelection_+"&&genFullMass>50&&genVisPt2>18)*embeddedWeight*__CORR__"),leg1Corr*tauID,prefix,true);
// 
// 	std::pair<float,float> zttShapePre    = createHistogramAndShifts(zShape_,"ZTTPre",("("+preSelection+"&&"+osSignalSelection_+"&&genFullMass>50&&genVisPt2>18)*embeddedWeight*__CORR__"),leg1Corr*tauID,prefix,true);
// 	std::pair<float,float> zttShape2Jet;
// 	if(prefix=="_vbf"&&channel_=="eleTau"&&energy_=="8TeV")
// 		zttShape2Jet    = createHistogramAndShifts(zShape_,"ZTT2J",("("+preSelection+"&&"+osSignalSelection_+"&&"+vbfTightS_+"&&nJetsPt30>=2&&genFullMass>50&&genVisPt2>18)*embeddedWeight*__CORR__"),leg1Corr*tauID,prefix,true);
// 	else if(prefix=="_vbf"&&channel_=="muTau"&&energy_=="8TeV")
// 		zttShape2Jet    = createHistogramAndShifts(zShape_,"ZTT2J",("("+preSelection+"&&"+osSignalSelection_+"&&"+vbfTightS_+"&&nJetsPt30>=2&&genFullMass>50&&genVisPt2>18)*embeddedWeight*__CORR__"),leg1Corr*tauID,prefix,true);
// 	else
// 		zttShape2Jet    = createHistogramAndShifts(zShape_,"ZTT2J",("("+preSelection+"&&"+osSignalSelection_+"&&nJetsPt30>=2&&genFullMass>50&&genVisPt2>18)*embeddedWeight*__CORR__"),leg1Corr*tauID,prefix,true);
// 			
// 	std::pair<float,float> zttYieldWCut   = createHistogramAndShiftsFinal(zttFile_,"ZTTTMP",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&genTaus>0&&genVisPt2>18)*"+weight_),luminosity_*zttScale_*leg1Corr*tauID,prefix,false);
// 
// 	
// 	corr = zttEmbYield.first/zttShapePre.first;
// 	corrZee = zttEmbYield.first/zttShape2Jet.first;
// 	printf("Efficiency for embedding =%f\n",corr);	
// 	printf("Efficiency for embedding 2Jet to VBF =%f\n",corrZee);		
// 	double corrErr = corr*sqrt(1/zttEmbYield.first + 1/zttShapePre.first);;
// 	zttYield = std::make_pair(inclusive.ZTT*corr,inclusive.dZTT*corrErr);
// 	renormalizeHistogram(channel_+prefix,"ZTT",inclusive.ZTT*corr);
// 	output.ZTTCORR=corr;
// 	output.dZTTCORR=corrErr;
//       }
// 
//     if(prefix=="_vbf")
//       std::pair<float,float> topShape       = createHistogramAndShifts(topFile_,"TT",("("+preSelection+"&&"+trigSelection_+"&&"+vbfRelaxedSelection_+"&&"+signalSelection_+"&&nJetsPt30>=2)*"+weight_),luminosity_*leg1Corr*tauID,prefix,true,false);
//     else if(prefix=="_2jet")
//       std::pair<float,float> topShape       = createHistogramAndShifts(topFile_,"TT",("("+preSelection+"&&"+trigSelection_+"&&vbfMass>200&&vbfDEta>2&&"+signalSelection_+"&&nJetsPt30>=2)*"+weight_),luminosity_*leg1Corr*tauID,prefix,true,false);
//     else if(prefix=="_btag_low" || prefix=="_btag_high" || prefix=="_btag")
// 	  std::pair<float,float> topShape       = createHistogramAndShifts(topFile_,"TT",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+")*"+weight_),luminosity_*leg1Corr*tauID,prefix,true,false);  
// 	else
// 	  std::pair<float,float> topShape       = createHistogramAndShifts(topFile_,"TT",("("+relaxedSelection_+"&&"+categorySelection+")*"+weight_),luminosity_*leg1Corr*tauID,prefix,true,false);    	
//   	
// 
//     std::pair<float,float> topYield       = createHistogramAndShiftsFinal(topFile_,"TTTMP",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+osSignalSelection_+")*"+weight_),luminosity_*leg1Corr*tauID*topExtrap,prefix);
//     renormalizeHistogram(channel_+prefix,"TT",topYield.first);
// 
//     std::pair<float,float> topSSYield       = createHistogramAndShifts(topFile_,"TTSS",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+ssSignalSelection_+")*"+weight_),luminosity_*leg1Corr*tauID*topExtrap,prefix);
// 	if(prefix=="_vbf")
// 		std::pair<float,float> vvShape        = createHistogramAndShiftsFinal(vvFile_,"VV",("("+preSelection+"&&"+trigSelection_+"&&"+vbfRelaxedSelection_+"&&"+osSignalSelection_+"&&nJetsPt30>=2)*"+weight_),luminosity_*leg1Corr*tauID,prefix,true,false);
// 	if(prefix=="_2jet")
// 		std::pair<float,float> vvShape        = createHistogramAndShiftsFinal(vvFile_,"VV",("("+preSelection+"&&"+trigSelection_+"&&vbfMass>200&&vbfDEta>2&&"+osSignalSelection_+"&&nJetsPt30>=2)*"+weight_),luminosity_*leg1Corr*tauID,prefix,true,false);
//     else if(prefix=="_btag_low" || prefix=="_btag_high" || prefix=="_btag")
// 		std::pair<float,float> vvShape        = createHistogramAndShiftsFinal(vvFile_,"VV",("("+relaxedSelection_+"&&"+osSignalSelection_+"&&nJetsPt20==1)*"+weight_),luminosity_*leg1Corr*tauID,prefix,true,false);
//     else
// 		std::pair<float,float> vvShape        = createHistogramAndShiftsFinal(vvFile_,"VV",("("+relaxedSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*leg1Corr*tauID,prefix,true,false);
//     
//     std::pair<float,float> vvYield        = createHistogramAndShiftsFinal(vvFile_,"VVTMP",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+osSignalSelection_+")*"+weight_),luminosity_*leg1Corr*tauID,prefix,true,false);
//     renormalizeHistogram(channel_+prefix,"VV",vvYield.first);
//     
// 	std::pair<float,float> zllShape;
// 	
// 	if(prefix=="_vbf"){
// 		if(channel_=="eleTau")
//       		std::pair<float,float> zlShape      = createHistogramAndShiftsFinal(zttFile_,"ZL",("("+relaxedSelection_+"&&"+osSignalSelection_+"&&"+trigSelection_+"&&"+vbfRelaxedSelection_+"&&nJetsPt20>=2&&genTaus==0&&genPt2>1)*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zttScale_,prefix,false,false);
//       	else
//       		std::pair<float,float> zlShape      = createHistogramAndShiftsFinal(zttFile_,"ZL",("("+preSelection+"&&"+osSignalSelection_+"&&"+trigSelection_+"&&"+vbfRelaxedSelection_+"&&nJetsPt20>=2&&genTaus==0&&genPt2>1)*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zttScale_,prefix,false,false);
//       		std::pair<float,float> zjShape      = createHistogramAndShiftsFinal(zttFile_,"ZJ",("("+preSelection+"&&"+osSignalSelection_+"&&"+trigSelection_+"&&"+vbfRelaxedSelection_+"&&nJetsPt20>=2&&genTaus==0&&genPt2<1)*"+weight_),luminosity_*leg1Corr*zttScale_,prefix,false,false);
// 	}
// 	else if(prefix=="_2jet"){
// 		if(channel_=="eleTau")
//       		std::pair<float,float> zlShape      = createHistogramAndShiftsFinal(zttFile_,"ZL",("("+relaxedSelection_+"&&"+osSignalSelection_+"&&"+trigSelection_+"&&vbfMass>200&&vbfDEta>2&&nJetsPt20>=2&&genTaus==0&&genPt2>1)*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zttScale_,prefix,false,false);
//       	else
//       		std::pair<float,float> zlShape      = createHistogramAndShiftsFinal(zttFile_,"ZL",("("+preSelection+"&&"+osSignalSelection_+"&&"+trigSelection_+"&&vbfMass>200&&vbfDEta>2&&nJetsPt20>=2&&genTaus==0&&genPt2>1)*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zttScale_,prefix,false,false);
//       		std::pair<float,float> zjShape      = createHistogramAndShiftsFinal(zttFile_,"ZJ",("("+preSelection+"&&"+osSignalSelection_+"&&"+trigSelection_+"&&vbfMass>200&&vbfDEta>2&&nJetsPt20>=2&&genTaus==0&&genPt2<1)*"+weight_),luminosity_*leg1Corr*zttScale_,prefix,false,false);
// 	}
// 	else if(prefix=="_btag_low"){
//       zllShape      = createHistogramAndShiftsFinal(zttFile_,"ZLL",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&genTaus==0&&nJetsPt20>=1&&pt2<40)*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zttScale_,prefix,false,false);
// 	}
// 	else if(prefix=="_btag_high"){
//       zllShape      = createHistogramAndShiftsFinal(zttFile_,"ZLL",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&genTaus==0&&nJetsPt20>=1&&pt2>40)*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zttScale_,prefix,false,false);
// 	}
// 	else if(prefix=="_btag"){
//       zllShape      = createHistogramAndShiftsFinal(zttFile_,"ZLL",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&genTaus==0&&nJetsPt20>=1)*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zttScale_,prefix,false,false);
// 	}
// 	else{
//       zllShape      = createHistogramAndShiftsFinal(zttFile_,"ZLL",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&genTaus==0)*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zttScale_,prefix,false,false);
// 	}
// 	
// 	std::pair<float,float> zllYield;	
// 	std::pair<float,float> zlYield;
// 	std::pair<float,float> zjYield;
// 	std::pair<float,float> zj2Jet;
// 	std::pair<float,float> zl2Jet;
// 	if(zShape_.size()==0){
// 	    zlYield      = createHistogramAndShiftsFinal(zttFile_,"ZLTMP",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&genTaus==0&&genPt2>1)*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zExtrap*zttScale_,prefix,false);
// 	    zjYield      = createHistogramAndShiftsFinal(zttFile_,"ZJTMP",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&genTaus==0&&genPt2<1)*"+weight_),luminosity_*leg1Corr*zExtrap*zttScale_,prefix,false);
// 	}
// 	else{
// 		if(prefix=="_vbf"&&channel_=="eleTau"&&energy_=="8TeV")
// 	    	zlYield      = createHistogramAndShiftsFinal(zttFile_,"ZLTMP",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+vbfTightS_+"&&nJetsPt30>=2&&genTaus==0&&genPt2>1)*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zExtrap*zttScale_*corrZee,prefix,false);
// 		else if(prefix=="_vbf"&&channel_=="muTau"&&energy_=="8TeV")
// 	    	zlYield      = createHistogramAndShiftsFinal(zttFile_,"ZLTMP",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+vbfTightS_+"&&nJetsPt30>=2&&genTaus==0&&genPt2>1)*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zExtrap*zttScale_*corrZee,prefix,false);
// 		else if(prefix=="_2jet"||prefix=="_vbf")
// 	    	zlYield      = createHistogramAndShiftsFinal(zttFile_,"ZLTMP",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&nJetsPt30>=2&&genTaus==0&&genPt2>1)*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zExtrap*zttScale_*corrZee,prefix,false);
// 	    else
// 	    	zlYield      = createHistogramAndShiftsFinal(zttFile_,"ZLTMP",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&genTaus==0&&genPt2>1)*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zExtrap*zttScale_*corr,prefix,false);
// 
// 	    zjYield      = createHistogramAndShiftsFinal(zttFile_,"ZJTMP",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&genTaus==0&&genPt2<1)*"+weight_),luminosity_*leg1Corr*zExtrap*zttScale_,prefix,false);
// 	    
// 	    if(prefix=="_vbf"&&energy_=="8TeV"){
// 	    
// // 	    	zj2Jet  =  createHistogramAndShiftsFinal(zttFile_,"ZJ2Jet",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&nJetsPt30>=1&&genTaus==0&&genPt2<1)*"+weight_),luminosity_*leg1Corr*zExtrap*zttScale_,prefix,false);
// // 	    	zl2Jet  =  createHistogramAndShiftsFinal(zttFile_,"ZL2Jet",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&nJetsPt30>=1&&genTaus==0&&genPt2>1)*"+weight_),luminosity_*leg1Corr*zExtrap*zttScale_,prefix,false);
// // 			zjYield.first = zlYield.first*zj2Jet.first/zl2Jet.first;
// 	        zlYield      = createHistogramAndShiftsFinal(zttFile_,"ZLTMP",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&genTaus==0&&genPt2>1)*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zExtrap*zttScale_,prefix,false);
// 	        zjYield      = createHistogramAndShiftsFinal(zttFile_,"ZJTMP",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&genTaus==0&&genPt2<1)*"+weight_),luminosity_*leg1Corr*zExtrap*zttScale_,prefix,false);
// 			
// 		}	    	
// 	}
// 	
// 	zllYield.first = zlYield.first+zjYield.first;
// 	zllYield.second = sqrt(zlYield.second*zlYield.second+zjYield.second*zjYield.second);
// 	if(prefix=="_vbf"||prefix=="_2jet"){
//     	renormalizeHistogram(channel_+prefix,"ZL",zlYield.first);
//     	renormalizeHistogram(channel_+prefix,"ZJ",zjYield.first);
//     	mergeHistogram(channel_+prefix,"ZL","ZJ","ZLL");
//     }
//     else{
//     	renormalizeHistogram(channel_+prefix,"ZLL",zlYield.first);
//     	renormalizeHistogram(channel_+prefix,"ZJ",zjYield.first);    	
//     	addHistogram(channel_+prefix,"ZLL","ZJ");
//     }
// 
//     std::pair<float,float> zllSSYield    = createHistogramAndShifts(zttFile_,"ZL_SS",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+ssSignalSelection_+"&&genTaus==0)*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zExtrap*zttScale_,prefix,false);
// 
// 	std::pair<float,float> wYield;
//     
// 
//      if(prefix=="_btag_low"){
//      
//      //Renormalize TT for contamination of the sample in embedded
// 	  renormalizeHistogram(channel_+prefix,"TT",topYield.first-0.015*zttYield.first);				     
// 
//       std::pair<float,float> wShape      = createHistogramAndShiftsFinal(wFile_,"W",("("+preSelection+"&&"+osSignalSelection_+"&&"+btagRelaxedSelection_+"&&pt2<40)*"+weight_),luminosity_*leg1Corr*wExtrap,prefix,false,false);
//       std::pair<float,float> dataYWSDB   = createHistogramAndShiftsFinal(dataFile_,"dataWSDB","("+preSelection+"&&"+categorySelection+"&&"+osWSelection_+"&&"+trigSelection_+")",scaleUp_,prefix);
//    	  std::pair<float,float> vvYieldSDB  = createHistogramAndShiftsFinal(vvFile_,"VVSDB",("("+preSelection+"&&"+categorySelection+"&&"+osWSelection_+"&&"+trigSelection_+")*"+weight_),luminosity_*leg1Corr*tauID,prefix,true,false);
// 	  std::pair<float,float> topYieldSDB = createHistogramAndShiftsFinal(topFile_,"TTSDB",("("+preSelection+"&&"+categorySelection+"&&"+osWSelection_+"&&"+trigSelection_+")*"+weight_),luminosity_*leg1Corr*tauID*topExtrap,prefix);
// 	  std::pair<float,float> zYieldSDB = createHistogramAndShiftsFinal(zttFile_,"ZSDB",("("+preSelection+"&&"+categorySelection+"&&"+osWSelection_+"&&"+trigSelection_+")*ZeFakeTau*"+weight_),luminosity_*leg1Corr*tauID*topExtrap,prefix);
// 
//       std::pair<float,float> wFactor = extractWFactor(wFile_,preSelection+"&&"+btagRelaxedSelection_+"&&pt2<40",prefix);
// 	  
// 
//       std::pair<float,float> osWHigh = std::make_pair(TMath::Nint(dataYWSDB.first-topYieldSDB.first-vvYieldSDB.first-zYieldSDB.first),
// 						      sqrt(dataYWSDB.second*dataYWSDB.second+topYieldSDB.second*topYieldSDB.second+vvYieldSDB.second*vvYieldSDB.second+zYieldSDB.second*zYieldSDB.second));	  
// 
//       wYield = std::make_pair(osWHigh.first*wFactor.first,
// 						     sqrt(osWHigh.first*osWHigh.first*wFactor.second*wFactor.second+osWHigh.second*osWHigh.second*wFactor.first*wFactor.first));
// 	   renormalizeHistogram(channel_+prefix,"W",wYield.first);   
// 	     
//      }
//      else if(prefix=="_btag"){
//      
//      //Renormalize TT for contamination of the sample in embedded
// 	  renormalizeHistogram(channel_+prefix,"TT",topYield.first-0.015*zttYield.first);				     
// 
//       std::pair<float,float> wShape      = createHistogramAndShiftsFinal(wFile_,"W",("("+preSelection+"&&"+osSignalSelection_+"&&"+btagRelaxedSelection_+")*"+weight_),luminosity_*leg1Corr*wExtrap,prefix,false,false);
//       std::pair<float,float> dataYWSDB   = createHistogramAndShiftsFinal(dataFile_,"dataWSDB","("+preSelection+"&&"+categorySelection+"&&"+osWSelection_+"&&"+trigSelection_+")",scaleUp_,prefix);
//    	  std::pair<float,float> vvYieldSDB  = createHistogramAndShiftsFinal(vvFile_,"VVSDB",("("+preSelection+"&&"+categorySelection+"&&"+osWSelection_+"&&"+trigSelection_+")*"+weight_),luminosity_*leg1Corr*tauID,prefix,true,false);
// 	  std::pair<float,float> topYieldSDB = createHistogramAndShiftsFinal(topFile_,"TTSDB",("("+preSelection+"&&"+categorySelection+"&&"+osWSelection_+"&&"+trigSelection_+")*"+weight_),luminosity_*leg1Corr*tauID*topExtrap,prefix);
// 	  std::pair<float,float> zYieldSDB = createHistogramAndShiftsFinal(zttFile_,"ZSDB",("("+preSelection+"&&"+categorySelection+"&&"+osWSelection_+"&&"+trigSelection_+")*ZeFakeTau*"+weight_),luminosity_*leg1Corr*tauID*topExtrap,prefix);
// 
//       std::pair<float,float> wFactor = extractWFactor(wFile_,preSelection+"&&"+btagRelaxedSelection_+"",prefix);
// 	  
// 
//       std::pair<float,float> osWHigh = std::make_pair(TMath::Nint(dataYWSDB.first-topYieldSDB.first-vvYieldSDB.first-zYieldSDB.first),
// 						      sqrt(dataYWSDB.second*dataYWSDB.second+topYieldSDB.second*topYieldSDB.second+vvYieldSDB.second*vvYieldSDB.second+zYieldSDB.second*zYieldSDB.second));	  
// 
//       wYield = std::make_pair(osWHigh.first*wFactor.first,
// 						     sqrt(osWHigh.first*osWHigh.first*wFactor.second*wFactor.second+osWHigh.second*osWHigh.second*wFactor.first*wFactor.first));
// 	   renormalizeHistogram(channel_+prefix,"W",wYield.first);   
// 	     
//      }
//      else if(prefix=="_btag_high"){
//      
// 	  renormalizeHistogram(channel_+prefix,"TT",topYield.first-0.053*zttYield.first);				     
// 
//       std::pair<float,float> wShape      = createHistogramAndShiftsFinal(wFile_,"W",("("+preSelection+"&&"+osSignalSelection_+"&&"+btagRelaxedSelection_+"&&pt2>40)*"+weight_),luminosity_*leg1Corr*wExtrap,prefix,false,false);
//       std::pair<float,float> dataYWSDB   = createHistogramAndShiftsFinal(dataFile_,"dataWSDB","("+preSelection+"&&"+categorySelection+"&&"+osWSelection_+"&&"+trigSelection_+")",scaleUp_,prefix);
//    	  std::pair<float,float> vvYieldSDB  = createHistogramAndShiftsFinal(vvFile_,"VVSDB",("("+preSelection+"&&"+categorySelection+"&&"+osWSelection_+"&&"+trigSelection_+")*"+weight_),luminosity_*leg1Corr*tauID,prefix,true,false);
// 	  std::pair<float,float> topYieldSDB = createHistogramAndShiftsFinal(topFile_,"TTSDB",("("+preSelection+"&&"+categorySelection+"&&"+osWSelection_+"&&"+trigSelection_+")*"+weight_),luminosity_*leg1Corr*tauID*topExtrap,prefix);
// 	  std::pair<float,float> zYieldSDB = createHistogramAndShiftsFinal(zttFile_,"ZSDB",("("+preSelection+"&&"+categorySelection+"&&"+osWSelection_+"&&"+trigSelection_+")*ZeFakeTau*"+weight_),luminosity_*leg1Corr*tauID*topExtrap,prefix);
// 
//       std::pair<float,float> wFactor = extractWFactor(wFile_,preSelection+"&&nJetsBTagCSVLPt20>=1&&nJetsPt30<2&&pt2>40",prefix);
// 	  
// 
//       std::pair<float,float> osWHigh = std::make_pair(TMath::Nint(dataYWSDB.first-topYieldSDB.first-vvYieldSDB.first-zYieldSDB.first),
// 						      sqrt(dataYWSDB.second*dataYWSDB.second+topYieldSDB.second*topYieldSDB.second+vvYieldSDB.second*vvYieldSDB.second+zYieldSDB.second*zYieldSDB.second));	  
// 
//       wYield = std::make_pair(osWHigh.first*wFactor.first,
// 						     sqrt(osWHigh.first*osWHigh.first*wFactor.second*wFactor.second+osWHigh.second*osWHigh.second*wFactor.first*wFactor.first));
// 	   renormalizeHistogram(channel_+prefix,"W",wYield.first);   
// 	     
//      }
//      else if(prefix=="_vbf" || prefix=="_2jet"){
//       wSelection_="mt1>60&&mt1<120";
//       osWSelection_="mt1>60&&mt1<120&&charge==0";
// 
//       if(prefix=="_vbf")
// 	  	std::pair<float,float> wShape      = createHistogramAndShiftsFinal(wFile_,"W",("("+preSelection+"&&"+trigSelection_+"&&"+vbfRelaxedSelection_+"&&"+signalSelection_+")*"+weight_),luminosity_*leg1Corr,prefix,false,false);
//       else if(prefix=="_2jet")
// 	  	std::pair<float,float> wShape      = createHistogramAndShiftsFinal(wFile_,"W",("("+preSelection+"&&"+trigSelection_+"&&vbfMass>200&&vbfDEta>2&&nJetsPt20>=2&&"+signalSelection_+")*"+weight_),luminosity_*leg1Corr,prefix,false,false);
// 
//       std::pair<float,float> dataYWSDB   = createHistogramAndShiftsFinal(dataFile_,"dataWSDB","("+preSelection+"&&"+categorySelection+"&&"+osWSelection_+"&&"+trigSelection_+")",scaleUp_,prefix);
//    	  std::pair<float,float> vvYieldSDB  = createHistogramAndShiftsFinal(vvFile_,"VVSDB",("("+preSelection+"&&"+categorySelection+"&&"+osWSelection_+"&&"+trigSelection_+")*"+weight_),luminosity_*leg1Corr*tauID,prefix,true,false);
// 	  std::pair<float,float> topYieldSDB = createHistogramAndShiftsFinal(topFile_,"TTSDB",("("+preSelection+"&&"+categorySelection+"&&"+osWSelection_+"&&"+trigSelection_+")*"+weight_),luminosity_*leg1Corr*tauID*topExtrap,prefix);
// 	  std::pair<float,float> zYieldSDB = createHistogramAndShiftsFinal(zttFile_,"ZSDB",("("+preSelection+"&&"+categorySelection+"&&"+osWSelection_+"&&"+trigSelection_+")*ZeFakeTau*"+weight_),luminosity_*leg1Corr*tauID,prefix);
// 
//       std::pair<float,float> wFactor = extractWFactor(wShape_,"nJetsPt30>=2&&"+vbfRelaxedSelection_+"&&"+preSelection+"&&"+trigSelection_,prefix);
// 	  
// 
//       std::pair<float,float> osWHigh = std::make_pair((dataYWSDB.first-topYieldSDB.first-vvYieldSDB.first-zYieldSDB.first),
// 						      sqrt(dataYWSDB.second*dataYWSDB.second+topYieldSDB.second*topYieldSDB.second+vvYieldSDB.second*vvYieldSDB.second+zYieldSDB.second*zYieldSDB.second));	  
// 
//       printf("OS W in sideband  =%f -%f -%f -%f = %f +- %f \n",dataYWSDB.first,topYieldSDB.first,vvYieldSDB.first,zYieldSDB.first,osWHigh.first,osWHigh.second);
//       
// 
//       wYield = std::make_pair(osWHigh.first*wFactor.first,
// 						     sqrt(osWHigh.first*osWHigh.first*wFactor.second*wFactor.second+osWHigh.second*osWHigh.second*wFactor.first*wFactor.first));
// 
//       printf("W Yield = %f * %f = %f\n", osWHigh.first, wFactor.first, wYield.first);
// 		     
// 	  renormalizeHistogram(channel_+prefix,"W",wYield.first);				     
// 	  				     
// 	}
// 	else{
//        std::pair<float,float> wShape      = createHistogramAndShifts(wFile_,"W",("("+relaxedSelection_+"&&"+categorySelection+")*"+weight_),luminosity_*leg1Corr*wExtrap*inclusive.WCORR,prefix,false,false);
//        wYield      = createHistogramAndShiftsFinal(wFile_,"WTMP",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+osSignalSelection_+")*"+weight_),luminosity_*leg1Corr*wExtrap*inclusive.WCORR,prefix,false);
// 	   renormalizeHistogram(channel_+prefix,"W",wYield.first);
// 	   
//     }
// 
// 
// 
//     //Trick:For W_SS yield use the OS/SS ratio as measured in inclusive for W
//     std::pair<float,float> wSSYield = std::make_pair(wYield.first*inclusive.WSS/inclusive.W,wYield.second*inclusive.WSS/inclusive.W);
//     //    std::pair<float,float> wSSYield     = createHistogramAndShifts(wFile_,"WSSTMP",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+ssSignalSelection_+")*"+weight_),luminosity_*leg1Corr*wExtrap*inclusive.WSSCORR,prefix);
//     
// 
//     std::pair<float,float> dataY         = createHistogramAndShiftsFinal(dataFile_,"data_obs","("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+osSignalSelection_+"&&"+blinding_+")",scaleUp_,prefix);
//     std::pair<float,float> dataYRounded  = std::make_pair(rintf(dataY.first),dataY.second);
//     renormalizeHistogram(channel_+prefix,"data_obs",dataYRounded.first);
//     std::pair<float,float> dataYield      = convertToPoisson(dataYRounded);
//  
//     std::pair<float,float> dataSSY          = createHistogramAndShifts(dataFile_,"data_obs_ss","("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+ssSignalSelection_+")",scaleUp_,prefix);
//     std::pair<float,float> dataSSYield      = convertToPoisson(dataSSY);
// 
// 	float qcdPass;
//     float qcdAll;
//     std::pair<float,float> dataQCDShape;
//     float qcdFactor;
//     float qcdFactorErr;
//     std::pair<float,float> osQCD;
//      
//     
// 	if(prefix=="_btag_low"){
// 	
// 	  dataQCDShape = createHistogramAndShifts(dataFile_,"QCD",qcdSelection_+"&&nJetsBTagCSVLPt20>=1&&nJetsPt30<2&&pt2<40",scaleUp_,prefix,false,false);
// 	  std::pair<float,float> topYieldQCD = createHistogramAndShifts(topFile_,"TTQCD",("("+qcdSelection_+"&&nJetsBTagCSVLPt20>=1&&nJetsPt30<2&&pt2<40)*"+weight_),luminosity_*leg1Corr*tauID*topExtrap,prefix);
//       subtractHistogram(channel_+prefix,"QCD","TTQCD");
//       
//    	  std::pair<float,float> vvYieldSS  = createHistogramAndShifts(vvFile_,"VVSS",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+ssSignalSelection_+")*"+weight_),luminosity_*leg1Corr*tauID,prefix,true,false);
// 	  std::pair<float,float> topYieldSS = createHistogramAndShifts(topFile_,"TTSS",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+ssSignalSelection_+")*"+weight_),luminosity_*leg1Corr*tauID*topExtrap,prefix);
// 	  std::pair<float,float> zYieldSS = createHistogramAndShifts(zttFile_,"ZSS",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+ssSignalSelection_+")*ZeFakeTau*"+weight_),luminosity_*leg1Corr*tauID,prefix);
//       
//       std::pair<float,float> ssQCD = std::make_pair(TMath::Nint(dataSSYield.first-wSSYield.first-zYieldSS.first-topYieldSS.first-vvYieldSS.first),
// 						  sqrt(dataSSYield.second*dataSSYield.second+wSSYield.second*wSSYield.second+zYieldSS.second*zYieldSS.second+vvYieldSS.second*vvYieldSS.second));
// 
//       if(ssQCD.first<0) {
// 	   ssQCD.first=0.0000001;
// 	   ssQCD.second=1.8;
//       }
// 
//       osQCD = std::make_pair(ssQCD.first*qcdFactor_,sqrt(ssQCD.second*ssQCD.second*qcdFactor_*qcdFactor_+qcdFactorErr_*qcdFactorErr_*ssQCD.first*ssQCD.first));
//         		
// 		
// 	}
// 	else if(prefix=="_btag"){
// 	
// 	  dataQCDShape = createHistogramAndShifts(dataFile_,"QCD",qcdSelection_+"&&nJetsBTagCSVLPt20>=1&&nJetsPt30<2",scaleUp_,prefix,false,false);
// 	  std::pair<float,float> topYieldQCD = createHistogramAndShifts(topFile_,"TTQCD",("("+qcdSelection_+"&&nJetsBTagCSVLPt20>=1&&nJetsPt30<2)*"+weight_),luminosity_*leg1Corr*tauID*topExtrap,prefix);
//       subtractHistogram(channel_+prefix,"QCD","TTQCD");
//       
//    	  std::pair<float,float> vvYieldSS  = createHistogramAndShifts(vvFile_,"VVSS",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+ssSignalSelection_+")*"+weight_),luminosity_*leg1Corr*tauID,prefix,true,false);
// 	  std::pair<float,float> topYieldSS = createHistogramAndShifts(topFile_,"TTSS",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+ssSignalSelection_+")*"+weight_),luminosity_*leg1Corr*tauID*topExtrap,prefix);
// 	  std::pair<float,float> zYieldSS = createHistogramAndShifts(zttFile_,"ZSS",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+ssSignalSelection_+")*ZeFakeTau*"+weight_),luminosity_*leg1Corr*tauID,prefix);
//       
//       std::pair<float,float> ssQCD = std::make_pair(TMath::Nint(dataSSYield.first-wSSYield.first-zYieldSS.first-topYieldSS.first-vvYieldSS.first),
// 						  sqrt(dataSSYield.second*dataSSYield.second+wSSYield.second*wSSYield.second+zYieldSS.second*zYieldSS.second+vvYieldSS.second*vvYieldSS.second));
// 
//       if(ssQCD.first<0) {
// 	   ssQCD.first=0.0000001;
// 	   ssQCD.second=1.8;
//       }
// 
//       osQCD = std::make_pair(ssQCD.first*qcdFactor_,sqrt(ssQCD.second*ssQCD.second*qcdFactor_*qcdFactor_+qcdFactorErr_*qcdFactorErr_*ssQCD.first*ssQCD.first));
//         		
// 		
// 	}
// 	else if(prefix=="_btag_high"){
// 	
// 	  dataQCDShape = createHistogramAndShifts(dataFile_,"QCD",qcdSelection_+"&&nJetsBTagCSVLPt20>=1&&nJetsPt30<2&&pt2>40",scaleUp_,prefix,false,false);
// 	  std::pair<float,float> topYieldQCD    = createHistogramAndShifts(topFile_,"TTQCD",("("+qcdSelection_+"&&nJetsBTagCSVLPt20>=1&&nJetsPt30<2&&pt2>40)*"+weight_),luminosity_*leg1Corr*tauID*topExtrap,prefix);
//       subtractHistogram(channel_+prefix,"QCD","TTQCD");
// 
// 	  std::pair<float,float> dataQCDControl = createHistogramAndShifts(dataFile_,"QCDC1",qcdSelection_+"&&"+categorySelection,scaleUp_,prefix,false,false);
// 	  std::pair<float,float> dataQCDControlInc = createHistogramAndShifts(dataFile_,"QCDC2",qcdSelection_,scaleUp_,prefix,false,false);	
// 
//       qcdPass=dataQCDControl.first;
//       qcdAll=dataQCDControlInc.first;		
//       
// 	}
// 	else if(prefix=="_vbf" || prefix=="_2jet"){
// 	
// 		if(prefix=="_vbf"){
// 			dataQCDShape = createHistogramAndShifts(dataFile_,"QCD","vertices>0&&diLeptons==0&&charge!=0&&lPFIsoDB>0.2&&nJetsPt20>=2&&"+vbfRelaxedSelection_+"&&"+signalSelection_,scaleUp_,prefix,false,false);
// 		}
// 		else if(prefix=="_2jet"){
// 			dataQCDShape = createHistogramAndShifts(dataFile_,"QCD","vertices>0&&diLeptons==0&&charge!=0&&lPFIsoDB>0.2&&nJetsPt20>=2&&vbfMass>200&&vbfDEta>2",scaleUp_,prefix,false,false);
// 		}
// 			
// 		std::pair<float,float> dataQCDControl = createHistogramAndShifts(dataFile_,"QCDC1","vertices>0&&diLeptons==0&&charge!=0&&lPFIsoDB>0.2&&"+categorySelection+"&&"+signalSelection_,scaleUp_,prefix,false,false);
// 		std::pair<float,float> dataQCDControlInc = createHistogramAndShifts(dataFile_,"QCDC2","vertices>0&&diLeptons==0&&charge!=0&&lPFIsoDB>0.2&&"+signalSelection_,scaleUp_,prefix,false,false);	
// 
//     	qcdPass=dataQCDControl.first;
//     	qcdAll=dataQCDControlInc.first;		
// 	}
// 	else if(prefix=="_vh"){
// 	
// 		dataQCDShape = createHistogramAndShifts(dataFile_,"QCD",qcdSelection_+"&&nJetsPt20>=2&&vbfMass>75",scaleUp_,prefix,false,false);
// 		std::pair<float,float> dataQCDControl = createHistogramAndShifts(dataFile_,"QCDC1",qcdSelection_+"&&"+categorySelection,scaleUp_,prefix,false,false);
// 		std::pair<float,float> dataQCDControlInc = createHistogramAndShifts(dataFile_,"QCDC2",qcdSelection_,scaleUp_,prefix,false,false);	
// 
//     	qcdPass=dataQCDControl.first;
//     	qcdAll=dataQCDControlInc.first;		
// 	}
// 	else{
// 	
// 		dataQCDShape = createHistogramAndShifts(dataFile_,"QCD",qcdSelection_+"&&"+categorySelection,scaleUp_,prefix,false,false);
// 		std::pair<float,float> dataQCDControl = createHistogramAndShifts(dataFile_,"QCDC1",qcdSelection_+"&&"+categorySelection,scaleUp_,prefix,false,false);
// 		std::pair<float,float> dataQCDControlInc = createHistogramAndShifts(dataFile_,"QCDC2",qcdSelection_,scaleUp_,prefix,false,false);
// 
//     	qcdPass=dataQCDControl.first;
//     	qcdAll=dataQCDControlInc.first;
// 	}
//     
// 
//     //Estimate QCD extrapolation factor
//    
// 	if(prefix!="_btag_low"&&prefix!="_btag"){
// 	
// 		qcdFactor = qcdPass/qcdAll;
// 		qcdFactorErr = TEfficiency::ClopperPearson(qcdAll,qcdPass,0.68,true)-qcdFactor; 
// 	
// 		osQCD = std::make_pair(inclusive.QCD*qcdFactor,sqrt(inclusive.QCD*inclusive.QCD*qcdFactorErr*qcdFactorErr+qcdFactor*qcdFactor*inclusive.dQCD*inclusive.dQCD));
// 		
// 		printf("osQCD = %f * %f = %f\n", inclusive.QCD, qcdFactor, osQCD.first);
// 
// 	}
// 	
//     //Inflate the errors
//     std::pair<float,float> topInflYield  = inflateError(topYield,topErr_);
//     printf("TTbar events in signal region = %f + %f \n",topInflYield.first,topInflYield.second);
// 
//     std::pair<float,float> topInflSSYield  = inflateError(topSSYield,topErr_,topExtrapErr);
//     printf("TTbar events in SS region = %f + %f \n",topInflSSYield.first,topInflSSYield.second);
// 
//     std::pair<float,float> vvInflYield  = inflateError(vvYield,vvErr_);
//     printf("Diboson events in signal region = %f + %f \n",vvInflYield.first,vvInflYield.second);
//     
//     std::pair<float,float> zllInflYield  = inflateError(zllYield,zlftErr_,zjftErr_);
//     printf("Z ->ll in signal region = %f + %f \n",zllInflYield.first,zllInflYield.second);
// 
//     std::pair<float,float> zllInflSSYield  = inflateError(zllSSYield,zjftErr_);
//     printf("Z ->ll in SS region = %f + %f \n",zllInflSSYield.first,zllInflSSYield.second);
// 
//     std::pair<float,float> wInflYield  = inflateError(wYield,inclusive.dWCORR);
//     printf("W in signal region = %f + %f \n",wInflYield.first,wInflYield.second);
// 
//     std::pair<float,float> wInflSSYield  = inflateError(wSSYield,inclusive.dWSSCORR,wExtrapErr);
//     printf("W in SS region = %f + %f \n",wInflSSYield.first,wInflSSYield.second);
// 
// 
//     //Estimate QCD!
//       printf("OS QCD in  core  =%f *%f = %f +- %f \n",inclusive.QCD,qcdFactor,osQCD.first,osQCD.second);
//            
//       float background    = osQCD.first+wInflYield.first+topInflYield.first+vvInflYield.first+zllInflYield.first+zttYield.first;
//       float backgroundErr = sqrt(osQCD.second*osQCD.second+wInflYield.second*wInflYield.second+topInflYield.second*topInflYield.second+vvInflYield.second*vvInflYield.second+zllInflYield.second*zllInflYield.second+zttYield.second*zttYield.second);
//       printf("BACKGROUND=%f +-%f \n",background,backgroundErr);
// 
// 
//       ///LATEX
//       printf("LATEX ------------------------------------\n");
// 
//       printf("Total & %.2f  \\\\ \n", dataYield.first);
//       printf("Di-Boson & %.2f $\\pm$ %.2f  \\\\ \n", vvInflYield.first, quadrature(vvInflYield.first,vvInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_));
//       printf("$t\\bar{t}$ & %.2f $\\pm$ %.2f \\\\ \n", topInflYield.first,quadrature(topInflYield.first,topInflYield.second,muIDErr_,eleIDErr_,tauIDErr_,topExtrapErr));
//       printf("$Zll & %.2f $\\pm$ %.2f  \\\\ \n", zllInflYield.first, quadrature(zllInflYield.first,zllInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_,zExtrapErr));
//       printf("$W+jets$ & %.2f $\\pm$ %.2f   \\\\ \n", wInflYield.first, quadrature(wInflYield.first,wInflYield.second,wExtrapErr));
//       printf("QCD & %.2f $\\pm$ %.2f \\\\ \n", osQCD.first, osQCD.second);
//       printf("$Z\\rightarrow\\tau\\tau$ & %.2f $\\pm$ %.2f & - & - & - \\\\ \n", zttYield.first,quadrature(zttYield.first,zttYield.second,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_,zExtrapErr));
//       float fullBackgroundErr = sqrt(pow(quadrature(vvInflYield.first,vvInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_),2)+
// 										       pow(quadrature(topInflYield.first,topInflYield.second,muIDErr_,eleIDErr_,tauIDErr_),2)+
// 										       pow(quadrature(zllInflYield.first,zllInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_,zExtrapErr),2)+
// 										       pow(osQCD.second,2)+
// 										       pow(quadrature(wInflYield.first,wInflYield.second,wExtrapErr),2)+
// 				                                                       pow(quadrature(zttYield.first,zttYield.second,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_,zExtrapErr),2));
//       printf("Total Background & %.2f $\\pm$ %.2f & - & - & - \\\\ \n",background,fullBackgroundErr);
// 
// 
// 
//       //create a histogram with the error for plotting reasons and only
//       TH1F *err = new TH1F("BKGErr","",1,0,1);
//       err->SetBinContent(1,fullBackgroundErr/background);
//       fout_->cd((channel_+prefix).c_str());
//       err->Write();
// 
// 
// 
//       output.DATA = dataYield.first;
//       output.W = wInflYield.first;
//       output.dW = wInflYield.second;
//       
//       output.WSS = wInflSSYield.first;
//       output.dWSS =wInflYield.second;
//       
//       output.QCD = osQCD.first;
//       output.dQCD = osQCD.second;
// 
//       output.ZLFT = zllInflYield.first;
//       output.dZLFT =zllInflYield.second;
//       output.ZLFTSS = zllInflSSYield.first;
//       output.dZLFTSS =zllInflSSYield.second;
// 
//       output.TOP = topInflYield.first;
//       output.dTOP = topInflYield.second;
//       output.VV = vvInflYield.first;
//       output.dVV = vvInflYield.second;
//       output.ZTT = zttYield.first;
//       output.dZTT = zttYield.second;
//       
//       output.WCORR = inclusive.WCORR;
//       output.dWCORR = inclusive.dWCORR;
//       
//       //now renormalize the data driven histograms
//       FixEmptyBins(channel_+prefix,"QCD",true);
//       FixEmptyBinsMC(channel_+prefix,"W",false);
//       FixEmptyBinsMC(channel_+prefix,"ZTT",false);
//       if(channel_=="eleTau"){
//       	FixEmptyBinsMC(channel_+prefix,"ZLL",false);
//       	FixEmptyBinsMC(channel_+prefix,"ZL",false);
//       	FixEmptyBinsMC(channel_+prefix,"ZJ",false);      	
//       }
//       
// //       if(channel_=="muTau"&&prefix=="_vbf"){
// //       	superSmooth(channel_+prefix,"ZLL");
// //       }
// 
//       renormalizeHistogram(channel_+prefix,"QCD",osQCD.first);
//       //zeeShapeSyst(channel_+prefix, "ZLL");
//       
// 
//       return output;
//   }

  BkgOutput runBoost(std::string preSelection,std::string categorySelection, std::string prefix, BkgOutput inclusive,float zExtrap,float zExtrapErr,float wExtrap,float wExtrapErr,float topExtrap,float topExtrapErr,std::string zShape_="",std::string wShape_="") {

    float leg1Corr=1.0;
    if(muID_!=0) leg1Corr*=muID_;
    if(eleID_!=0) leg1Corr*=eleID_;

	float tauID = 1.0;
	tauID = tauIDHigh_;
	printf("Tau ID Scale Factor is %.3f \n",tauID);		

    BkgOutput output;

    output.ZTTCORR=zExtrap;
    output.dZTTCORR=zExtrapErr;

    ////////////// Estimate Z--> ττ ///////////////
    std::pair<float,float> zttYield       = createHistogramAndShiftsFinal(zttFile_,"ZTTTMP",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&genTaus>0&&genVisPt2>18&&(!((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)||(genTaus>0&&genVisPt2>18))))*"+weight_),luminosity_*zttScale_*zExtrap*leg1Corr*tauID,prefix);
    std::pair<float,float> ztt_ll       = createHistogramAndShiftsFinal(zttFile_,"ZTT_LL",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&genTaus>0&&((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))*"+weight_),luminosity_*zttScale_*zExtrap*leg1Corr*tauID,prefix);

	float corr = 1.0;
	
    if(zShape_.size()==0) {
    
        std::pair<float,float> zttShape       = createHistogramAndShiftsFinal(zttFile_,"ZTT",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+osSignalSelection_+"&&genTaus>0&&genVisPt2>18)*"+weight_),luminosity_*zttScale_*leg1Corr*tauID*zExtrap,prefix,true);

    }
    else{

		printf("You have embedded samples.Calculating corrections on the fly overidding the crappy ones you gave me!\n");

		std::pair<float,float> zttShape       = createHistogramAndShifts(zShape_,"ZTT",("("+preSelection+"&&"+categorySelection+"&&"+osSignalSelection_+"&&genFullMass>50&&genVisPt2>18)*"+embWeight_),leg1Corr*tauID,prefix,true);	
		std::pair<float,float> zttEmbYield    = createHistogramAndShifts(zShape_,"ZTTTMP",("("+preSelection+"&&"+categorySelection+"&&"+osSignalSelection_+"&&genFullMass>50&&genVisPt2>18)*"+embWeight_),leg1Corr*tauID,prefix,true);
		std::pair<float,float> zttShapePre    = createHistogramAndShifts(zShape_,"ZTTPre",("("+preSelection+"&&"+osSignalSelection_+"&&genFullMass>50&&genVisPt2>18)*"+embWeight_),leg1Corr*tauID,prefix,true);

	
		corr = zttEmbYield.first/zttShapePre.first;
		printf("Efficiency for embedding =%f\n",corr);	
		double corrErr = corr*sqrt(1/zttEmbYield.first + 1/zttShapePre.first);;
		zttYield = std::make_pair(inclusive.ZTT*corr,inclusive.dZTT*corrErr);
		renormalizeHistogram(channel_+prefix,"ZTT",inclusive.ZTT*corr);
		output.ZTTCORR=corr;
		output.dZTTCORR=corrErr;
		
		addHistogramZTT(channel_+prefix, "ZTT", "ZTT_LL");
    }

	//////////////// Estimate ttbar ///////////////
	
    std::pair<float,float> topShape       = createHistogramAndShifts(topFile_,"TT",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+signalSelection_+")*"+weight_),luminosity_*leg1Corr*tauID,prefix,true,false);
    std::pair<float,float> topYield       = createHistogramAndShiftsFinal(topFile_,"TTTMP",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+osSignalSelection_+")*"+weight_),luminosity_*leg1Corr*tauID*topExtrap,prefix);
    renormalizeHistogram(channel_+prefix,"TT",topYield.first);

    std::pair<float,float> topSSYield       = createHistogramAndShifts(topFile_,"TTSS",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+ssSignalSelection_+")*"+weight_),luminosity_*leg1Corr*tauID*topExtrap,prefix);
	
    //////////////// Estimate VV   ////////////////
    
    std::pair<float,float> vvShape        = createHistogramAndShiftsFinal(vvFile_,"VV",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+osSignalSelection_+")*"+weight_),luminosity_*leg1Corr*tauID,prefix,true,false);
    std::pair<float,float> vvYield        = createHistogramAndShiftsFinal(vvFile_,"VVTMP",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+osSignalSelection_+")*"+weight_),luminosity_*leg1Corr*tauID,prefix,true,false);
    renormalizeHistogram(channel_+prefix,"VV",vvYield.first);
	

	//////////////// Estimate ZLL  ////////////////
	    
	std::pair<float,float> zlShape      = createHistogramAndShiftsFinal(zttFile_,"ZL",("("+preSelection+"&&"+osSignalSelection_+"&&"+categorySelection+"&&genTaus==0&& ((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zttScale_,prefix,false,false);
	std::pair<float,float> zjShape      = createHistogramAndShiftsFinal(zttFile_,"ZJ",("("+preSelection+"&&"+osSignalSelection_+"&&"+categorySelection+"&&(!((genTaus==0&&abs(pdg2)==13&&genPt2>8)||(genTaus==0&&abs(pdg2)==11&&genPt2>8)||(genTaus>0&&genVisPt2>18))))*"+weight_),luminosity_*leg1Corr*zttScale_,prefix,false,false);
	
	std::pair<float,float> zlYield      = createHistogramAndShiftsFinal(zttFile_,"ZLTMP",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&genTaus==0&& ((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zExtrap*zttScale_,prefix,false);
	std::pair<float,float> zjYield      = createHistogramAndShiftsFinal(zttFile_,"ZJTMP",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&(!((genTaus==0&&abs(pdg2)==13&&genPt2>8)||(genTaus==0&&abs(pdg2)==11&&genPt2>8)||(genTaus>0&&genVisPt2>18))))*"+weight_),luminosity_*leg1Corr*zExtrap*zttScale_,prefix,false);
	
	std::pair<float,float> zllYield;
	zllYield.first = zlYield.first+zjYield.first;
	zllYield.second = sqrt(zlYield.second*zlYield.second+zjYield.second*zjYield.second);
	renormalizeHistogram(channel_+prefix,"ZL",zlYield.first);
	renormalizeHistogram(channel_+prefix,"ZJ",zjYield.first);

	if(channel_=="eleTau"){
		std::pair<float,float> zlShiftUp      = createHistogramShifted(zllFile_,"ZL_CMS_htt_ZLScale_etau_"+energy_+"Up",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&genTaus==0&& ((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))*ZeFakeTau*"+weight_),"1.02",luminosity_*leg1Corr*zlftFactor_*zttScale_*zExtrap,prefix);
		std::pair<float,float> zlShiftDown     = createHistogramShifted(zllFile_,"ZL_CMS_htt_ZLScale_etau_"+energy_+"Down",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&genTaus==0&& ((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))*ZeFakeTau*"+weight_),"0.98",luminosity_*leg1Corr*zlftFactor_*zttScale_*zExtrap,prefix);
	}
	else{
		std::pair<float,float> zlShiftUp      = createHistogramShifted(zllFile_,"ZL_CMS_htt_ZLScale_mutau_"+energy_+"Up",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&genTaus==0&& ((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))*ZeFakeTau*"+weight_),"1.02",luminosity_*leg1Corr*zlftFactor_*zttScale_*zExtrap,prefix);
		std::pair<float,float> zlShiftDown     = createHistogramShifted(zllFile_,"ZL_CMS_htt_ZLScale_mutau_"+energy_+"Down",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&genTaus==0&& ((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))*ZeFakeTau*"+weight_),"0.98",luminosity_*leg1Corr*zlftFactor_*zttScale_*zExtrap,prefix);	
	}

	std::pair<float,float> zllSSYield    = createHistogramAndShifts(zttFile_,"ZL_SS",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+ssSignalSelection_+"&&genTaus==0)*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zExtrap*zttScale_,prefix,false);


	///////////////// W Background estimate ///////////////////

	std::pair<float,float> wShape;
	if(channel_=="eleTau"){
	  wShape      = createHistogramAndShifts(wFile_,"W",("(diLeptons==0&&lPFIsoDB<0.1&&(tightElectrons+tightMuons)<=1&&tauEleMedium>0&&"+trigSelection_+"&&"+categorySelection+"&&"+signalSelection_+")*"+weight_),luminosity_*leg1Corr,prefix,false,false);
	}
	else{
	  wShape      = createHistogramAndShifts(wFile_,"W",("(diLeptons==0&&lPFIsoDB<0.1&&(tightElectrons+tightMuons)<=1&&"+trigSelection_+"&&"+categorySelection+"&&"+signalSelection_+")*"+weight_),luminosity_*leg1Corr,prefix,false,false);	
	}
	  std::pair<float,float> dataYWSDB   = createHistogramAndShiftsFinal(dataFile_,"dataWSDB","("+preSelection+"&&"+categorySelection+"&&"+osWSelection_+"&&"+trigSelection_+")",scaleUp_,prefix);
	  std::pair<float,float> vvYieldSDB  = createHistogramAndShiftsFinal(vvFile_,"VVSDB",("("+preSelection+"&&"+categorySelection+"&&"+osWSelection_+"&&"+trigSelection_+")*"+weight_),luminosity_*leg1Corr*tauID,prefix,true,false);
	  std::pair<float,float> topYieldSDB = createHistogramAndShiftsFinal(topFile_,"TTSDB",("("+preSelection+"&&"+categorySelection+"&&"+osWSelection_+"&&"+trigSelection_+")*"+weight_),luminosity_*leg1Corr*tauID*topExtrap,prefix);
	  std::pair<float,float> zYieldSDB = createHistogramAndShiftsFinal(zttFile_,"ZSDB",("("+preSelection+"&&"+categorySelection+"&&"+osWSelection_+"&&"+trigSelection_+")*ZeFakeTau*"+weight_),luminosity_*leg1Corr*tauID,prefix);

	  std::pair<float,float> wFactor = extractWFactor(wShape_,categorySelection+"&&"+preSelection+"&&"+trigSelection_,prefix,osWSelection_,osSignalSelection_);
  

	  std::pair<float,float> osWHigh = std::make_pair((dataYWSDB.first-topYieldSDB.first-vvYieldSDB.first-zYieldSDB.first),
							  sqrt(dataYWSDB.second*dataYWSDB.second+topYieldSDB.second*topYieldSDB.second+vvYieldSDB.second*vvYieldSDB.second+zYieldSDB.second*zYieldSDB.second));	  

	  printf("OS W in sideband  =%f -%f -%f -%f = %f +- %f \n",dataYWSDB.first,topYieldSDB.first,vvYieldSDB.first,zYieldSDB.first,osWHigh.first,osWHigh.second);
  

	  std::pair<float,float> wYield = std::make_pair(osWHigh.first*wFactor.first,
							 sqrt(osWHigh.first*osWHigh.first*wFactor.second*wFactor.second+osWHigh.second*osWHigh.second*wFactor.first*wFactor.first));

	  printf("W Yield = %f * %f = %f\n", osWHigh.first, wFactor.first, wYield.first);
		 
	  renormalizeHistogram(channel_+prefix,"W",wYield.first);				     
					 

    //Trick:For W_SS yield use the OS/SS ratio as measured in inclusive for W
    std::pair<float,float> wSSYield = std::make_pair(wYield.first*inclusive.WSS/inclusive.W,wYield.second*inclusive.WSS/inclusive.W);   

    std::pair<float,float> dataY         = createHistogramAndShiftsFinal(dataFile_,"data_obs","("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+osSignalSelection_+"&&"+blinding_+")",scaleUp_,prefix);
    std::pair<float,float> dataYRounded  = std::make_pair(rintf(dataY.first),dataY.second);
    renormalizeHistogram(channel_+prefix,"data_obs",dataYRounded.first);
    std::pair<float,float> dataYield      = convertToPoisson(dataYRounded);
 
    std::pair<float,float> dataSSY          = createHistogramAndShifts(dataFile_,"data_obs_ss","("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+ssSignalSelection_+")",scaleUp_,prefix);
    std::pair<float,float> dataSSYield      = convertToPoisson(dataSSY);


	////////// QCD Estimate ///////////////
	
	std::pair<float,float> dataQCDShape = createHistogramAndShifts(dataFile_,"QCD","charge!=0&&vertices>0&&diLeptons==0&&lPFIsoDB>0.2&&(tightElectrons+tightMuons)<1&&"+categorySelection+"&&"+trigSelection_+"&&"+relaxedSelection_,scaleUp_,prefix,false,false);
	std::pair<float,float> dataQCDControl = createHistogramAndShifts(dataFile_,"QCDC1","charge!=0&&vertices>0&&diLeptons==0&&lPFIsoDB>0.2&&(tightElectrons+tightMuons)<1&&"+categorySelection+"&&"+relaxedSelection_,scaleUp_,prefix,false,false);
	std::pair<float,float> dataQCDControlInc = createHistogramAndShifts(dataFile_,"QCDC2","charge!=0&&vertices>0&&diLeptons==0&&lPFIsoDB>0.2&&(tightElectrons+tightMuons)<1&&"+relaxedSelection_,scaleUp_,prefix,false,false);	

	float qcdFactor = dataQCDControl.first/dataQCDControlInc.first;
	float qcdFactorErr = TEfficiency::ClopperPearson(dataQCDControlInc.first,dataQCDControl.first,0.68,true)-qcdFactor; 

	std::pair<float,float> osQCD = std::make_pair(inclusive.QCD*qcdFactor,sqrt(inclusive.QCD*inclusive.QCD*qcdFactorErr*qcdFactorErr+qcdFactor*qcdFactor*inclusive.dQCD*inclusive.dQCD));
	
	////////// Output ////////////////////
	printf("qcdFactor = %f / %f = %f\n", dataQCDControl.first, dataQCDControlInc.first, qcdFactor);	
	printf("osQCD = %f * %f = %f\n", inclusive.QCD, qcdFactor, osQCD.first);

    //Inflate the errors
    std::pair<float,float> topInflYield  = inflateError(topYield,topErr_);
    printf("TTbar events in signal region = %f + %f \n",topInflYield.first,topInflYield.second);

    std::pair<float,float> topInflSSYield  = inflateError(topSSYield,topErr_,topExtrapErr);
    printf("TTbar events in SS region = %f + %f \n",topInflSSYield.first,topInflSSYield.second);

    std::pair<float,float> vvInflYield  = inflateError(vvYield,vvErr_);
    printf("Diboson events in signal region = %f + %f \n",vvInflYield.first,vvInflYield.second);
    
    std::pair<float,float> zllInflYield  = inflateError(zllYield,zlftErr_,zjftErr_);
    printf("Z ->ll in signal region = %f + %f \n",zllInflYield.first,zllInflYield.second);

    std::pair<float,float> zllInflSSYield  = inflateError(zllSSYield,zjftErr_);
    printf("Z ->ll in SS region = %f + %f \n",zllInflSSYield.first,zllInflSSYield.second);

    std::pair<float,float> wInflYield  = inflateError(wYield,inclusive.dWCORR);
    printf("W in signal region = %f + %f \n",wInflYield.first,wInflYield.second);

    std::pair<float,float> wInflSSYield  = inflateError(wSSYield,inclusive.dWSSCORR,wExtrapErr);
    printf("W in SS region = %f + %f \n",wInflSSYield.first,wInflSSYield.second);


	  printf("OS QCD in  core  =%f *%f = %f +- %f \n",inclusive.QCD,qcdFactor,osQCD.first,osQCD.second);
	   
	  float background    = osQCD.first+wInflYield.first+topInflYield.first+vvInflYield.first+zllInflYield.first+zttYield.first;
	  float backgroundErr = sqrt(osQCD.second*osQCD.second+wInflYield.second*wInflYield.second+topInflYield.second*topInflYield.second+vvInflYield.second*vvInflYield.second+zllInflYield.second*zllInflYield.second+zttYield.second*zttYield.second);
	  printf("BACKGROUND=%f +-%f \n",background,backgroundErr);


	  ///LATEX
	  printf("LATEX ------------------------------------\n");

	  printf("Total & %.2f  \\\\ \n", dataYield.first);
	  printf("Di-Boson & %.2f $\\pm$ %.2f  \\\\ \n", vvInflYield.first, quadrature(vvInflYield.first,vvInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_));
	  printf("$t\\bar{t}$ & %.2f $\\pm$ %.2f \\\\ \n", topInflYield.first,quadrature(topInflYield.first,topInflYield.second,muIDErr_,eleIDErr_,tauIDErr_,topExtrapErr));
      printf("$Z^{l+jet}$ & %.2f $\\pm$ %.2f & - & - $\\pm$ - & - \\\\ \n", zjYield.first, quadrature(zjYield.first,zjYield.second,muIDErr_,eleIDErr_,zttScaleErr_,zExtrapErr));
      printf("$Z^{ll}$ & %.2f $\\pm$ %.2f & - & - $\\pm$ - & - \\\\ \n", zlYield.first, quadrature(zlYield.first,zlYield.second,muIDErr_,eleIDErr_,zttScaleErr_,zExtrapErr));
	  printf("$W+jets$ & %.2f $\\pm$ %.2f   \\\\ \n", wInflYield.first, quadrature(wInflYield.first,wInflYield.second,wExtrapErr));
	  printf("QCD & %.2f $\\pm$ %.2f \\\\ \n", osQCD.first, osQCD.second);
	  printf("$Z\\rightarrow\\tau\\tau$ & %.2f $\\pm$ %.2f & - & - & - \\\\ \n", zttYield.first,quadrature(zttYield.first,zttYield.second,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_,zExtrapErr));
	  float fullBackgroundErr = sqrt(pow(quadrature(vvInflYield.first,vvInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_),2)+
											   pow(quadrature(topInflYield.first,topInflYield.second,muIDErr_,eleIDErr_,tauIDErr_),2)+
											   pow(quadrature(zllInflYield.first,zllInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_,zExtrapErr),2)+
											   pow(osQCD.second,2)+
											   pow(quadrature(wInflYield.first,wInflYield.second,wExtrapErr),2)+
																	   pow(quadrature(zttYield.first,zttYield.second,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_,zExtrapErr),2));
	  printf("Total Background & %.2f $\\pm$ %.2f & - & - & - \\\\ \n",background,fullBackgroundErr);



	  //create a histogram with the error for plotting reasons and only
	  TH1F *err = new TH1F("BKGErr","",1,0,1);
	  err->SetBinContent(1,fullBackgroundErr/background);
	  fout_->cd((channel_+prefix).c_str());
	  err->Write();

	  output.DATA = dataYield.first;
	  output.W = wInflYield.first;
	  output.dW = wInflYield.second;
  
	  output.WSS = wInflSSYield.first;
	  output.dWSS =wInflYield.second;
  
	  output.QCD = osQCD.first;
	  output.dQCD = osQCD.second;

	  output.ZLFT = zllInflYield.first;
	  output.dZLFT =zllInflYield.second;
	  output.ZLFTSS = zllInflSSYield.first;
	  output.dZLFTSS =zllInflSSYield.second;

	  output.TOP = topInflYield.first;
	  output.dTOP = topInflYield.second;
	  output.VV = vvInflYield.first;
	  output.dVV = vvInflYield.second;
	  output.ZTT = zttYield.first;
	  output.dZTT = zttYield.second;
  
	  output.WCORR = inclusive.WCORR;
	  output.dWCORR = inclusive.dWCORR;
  
  
	  /////////////// post processing fixes ////////////////
  
	  //now renormalize the data driven histograms
	  FixEmptyBins(channel_+prefix,"QCD",true);
	  FixEmptyBinsMC(channel_+prefix,"W",false);
	  FixEmptyBinsMC(channel_+prefix,"ZTT",false);
	  if(channel_=="eleTau"){
		FixEmptyBinsMC(channel_+prefix,"ZL",false);
		FixEmptyBinsMC(channel_+prefix,"ZJ",false);      	
	  }

	  renormalizeHistogram(channel_+prefix,"QCD",osQCD.first);
      qcdSyst(channel_, prefix, "QCD", 1.0, 0.1);


	  return output;

  }


  BkgOutput runVBFLoose(std::string preSelection,std::string categorySelection, std::string prefix, BkgOutput inclusive,float zExtrap,float zExtrapErr,float wExtrap,float wExtrapErr,float topExtrap,float topExtrapErr,std::string zShape_="",std::string wShape_="") {

    float leg1Corr=1.0;
    if(muID_!=0) leg1Corr*=muID_;
    if(eleID_!=0) leg1Corr*=eleID_;

	float tauID = 1.0;
	tauID = tauID_ - (1.-tauIDHigh_)/2. ;
	printf("Tau ID Scale Factor is %.3f \n",tauID);		

    BkgOutput output;

    output.ZTTCORR=zExtrap;
    output.dZTTCORR=zExtrapErr;
    

    ////////////// Estimate Z--> ττ ///////////////
    std::pair<float,float> zttYield       = createHistogramAndShiftsFinal(zttFile_,"ZTTTMP",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&genTaus>0&&genVisPt2>18&&(!((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)||(genTaus>0&&genVisPt2>18))))*"+weight_),luminosity_*zttScale_*zExtrap*leg1Corr*tauID,prefix);
    std::pair<float,float> ztt_ll       = createHistogramAndShiftsFinal(zttFile_,"ZTT_LL",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&genTaus>0&&((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))*"+weight_),luminosity_*zttScale_*zExtrap*leg1Corr*tauID,prefix);
	float corr = 1.0;
	
    if(zShape_.size()==0) {
    
        std::pair<float,float> zttShape       = createHistogramAndShiftsFinal(zttFile_,"ZTT",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+osSignalSelection_+"&&genTaus>0&&genVisPt2>18)*"+weight_),luminosity_*zttScale_*leg1Corr*tauID*zExtrap,prefix,true);

    }
    else{

		printf("You have embedded samples.Calculating corrections on the fly overidding the crappy ones you gave me!\n");

		std::pair<float,float> zttShape       = createHistogramAndShifts(zShape_,"ZTT",("("+preSelection+"&&"+categorySelection+"&&"+osSignalSelection_+"&&genFullMass>50&&genVisPt2>18&&genPt2>8)*"+embWeight_),leg1Corr*tauID,prefix,true);	
		std::pair<float,float> zttEmbYield    = createHistogramAndShifts(zShape_,"ZTTTMP",("("+preSelection+"&&"+categorySelection+"&&"+osSignalSelection_+"&&genFullMass>50&&genVisPt2>18)*"+embWeight_),leg1Corr*tauID,prefix,true);
		std::pair<float,float> zttShapePre    = createHistogramAndShifts(zShape_,"ZTTPre",("("+preSelection+"&&"+osSignalSelection_+"&&genFullMass>50&&genVisPt2>18)*"+embWeight_),leg1Corr*tauID,prefix,true);
		std::pair<float,float> ztt2Jet       = createHistogramAndShifts(zShape_,"ZTT_2Jet",("("+preSelection+"&&nJetsPt30>=2&&"+osSignalSelection_+"&&genFullMass>50&&genVisPt2>18&&genPt2>8)*"+embWeight_),leg1Corr*tauID,prefix,true);	

		double Ratio = zttShape.first/ztt2Jet.first;
		std::cout << "Embedded Ratio full/2jet = " << Ratio << " +/- " << ztt2Jet.second/ztt2Jet.first*Ratio << std::endl;
	
		corr = zttEmbYield.first/zttShapePre.first;
		printf("Efficiency for embedding =%f\n",corr);	
		double corrErr = corr*sqrt(1/zttEmbYield.first + 1/zttShapePre.first);;
		zttYield = std::make_pair(inclusive.ZTT*corr,inclusive.dZTT*corrErr);
		renormalizeHistogram(channel_+prefix,"ZTT",inclusive.ZTT*corr);
		output.ZTTCORR=corr;
		output.dZTTCORR=corrErr;
		
		addHistogramZTT(channel_+prefix, "ZTT", "ZTT_LL");
    }

	//////////////// Estimate ttbar ///////////////
	
    std::pair<float,float> topShape       = createHistogramAndShifts(topFile_,"TT",("("+preSelection+"&&"+trigSelection_+"&&"+vbfRelaxedSelection_+"&&"+signalSelection_+"&&nJetsPt30>=2)*"+weight_),luminosity_*leg1Corr*tauID,prefix,true,false);

    std::pair<float,float> topYield       = createHistogramAndShiftsFinal(topFile_,"TTTMP",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+osSignalSelection_+")*"+weight_),luminosity_*leg1Corr*tauID*topExtrap,prefix);
    renormalizeHistogram(channel_+prefix,"TT",topYield.first);

    std::pair<float,float> topSSYield       = createHistogramAndShifts(topFile_,"TTSS",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+ssSignalSelection_+")*"+weight_),luminosity_*leg1Corr*tauID*topExtrap,prefix);
	
	//////////////// Estimate VV   ////////////////
	
	std::pair<float,float> vvShape        = createHistogramAndShiftsFinal(vvFile_,"VV",("("+preSelection+"&&"+trigSelection_+"&&"+vbfRelaxedSelection_+"&&"+osSignalSelection_+"&&nJetsPt30>=2)*"+weight_),luminosity_*leg1Corr*tauID,prefix,true,false);
    
    std::pair<float,float> vvYield        = createHistogramAndShiftsFinal(vvFile_,"VVTMP",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+osSignalSelection_+")*"+weight_),luminosity_*leg1Corr*tauID,prefix,true,false);
    renormalizeHistogram(channel_+prefix,"VV",vvYield.first);


	//////////////// Estimate ZLL  ////////////////
	    
	std::pair<float,float> zlShape      = createHistogramAndShiftsFinal(zttFile_,"ZL",("("+osSignalSelection_+"&&"+vbfRelaxedSelection_+"&&nJetsPt20>=2&&genTaus==0&& ((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zttScale_,prefix,false,false);
	std::pair<float,float> zjShape      = createHistogramAndShiftsFinal(zttFile_,"ZJ",("("+osSignalSelection_+"&&"+vbfRelaxedSelection_+"&&nJetsPt30>=2&&(!((genTaus==0&&abs(pdg2)==13&&genPt2>8)||(genTaus==0&&abs(pdg2)==11&&genPt2>8)||(genTaus>0&&genVisPt2>18))))*"+weight_),luminosity_*leg1Corr*zttScale_,prefix,false,false);
	
	std::pair<float,float> zlYield      = createHistogramAndShiftsFinal(zttFile_,"ZLTMP",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&genTaus==0&& ((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zExtrap*zttScale_,prefix,false);
	std::pair<float,float> zjYield      = createHistogramAndShiftsFinal(zttFile_,"ZJTMP",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&(!((genTaus==0&&abs(pdg2)==13&&genPt2>8)||(genTaus==0&&abs(pdg2)==11&&genPt2>8)||(genTaus>0&&genVisPt2>18))))*"+weight_),luminosity_*leg1Corr*zExtrap*zttScale_,prefix,false);
	
	std::pair<float,float> zllYield;
	zllYield.first = zlYield.first+zjYield.first;
	zllYield.second = sqrt(zlYield.second*zlYield.second+zjYield.second*zjYield.second);
	renormalizeHistogram(channel_+prefix,"ZL",zlYield.first);
	renormalizeHistogram(channel_+prefix,"ZJ",zjYield.first);
	mergeHistogram(channel_+prefix,"ZL","ZJ","ZLL");

	if(channel_=="eleTau"){
		std::pair<float,float> zlShiftUp      = createHistogramShifted(zllFile_,"ZL_CMS_htt_ZLScale_etau_"+energy_+"Up",("("+osSignalSelection_+"&&"+vbfRelaxedSelection_+"&&nJetsPt20>=2&&genTaus==0&& ((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))*ZeFakeTau*"+weight_),"1.02",luminosity_*leg1Corr*zlftFactor_*zttScale_*zExtrap,prefix);
		std::pair<float,float> zlShifDown     = createHistogramShifted(zllFile_,"ZL_CMS_htt_ZLScale_etau_"+energy_+"Down",("("+osSignalSelection_+"&&"+vbfRelaxedSelection_+"&&nJetsPt20>=2&&genTaus==0&& ((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))*ZeFakeTau*"+weight_),"0.98",luminosity_*leg1Corr*zlftFactor_*zttScale_*zExtrap,prefix);
		renormalizeHistogram(channel_+prefix,"ZL_CMS_htt_ZLScale_etau_"+energy_+"Up",zlYield.first);
		renormalizeHistogram(channel_+prefix,"ZL_CMS_htt_ZLScale_etau_"+energy_+"Down",zlYield.first);
		mergeHistogram(channel_+prefix,"ZL_CMS_htt_ZLScale_etau_"+energy_+"Up","ZJ","ZLL_CMS_htt_ZLScale_etau_"+energy_+"Up");
		mergeHistogram(channel_+prefix,"ZL_CMS_htt_ZLScale_etau_"+energy_+"Down","ZJ","ZLL_CMS_htt_ZLScale_etau_"+energy_+"Down");
	}
	else{
		std::pair<float,float> zlShiftUp      = createHistogramShifted(zllFile_,"ZL_CMS_htt_ZLScale_mutau_"+energy_+"Up",("("+osSignalSelection_+"&&"+vbfRelaxedSelection_+"&&nJetsPt20>=2&&genTaus==0&& ((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))*ZeFakeTau*"+weight_),"1.02",luminosity_*leg1Corr*zlftFactor_*zttScale_*zExtrap,prefix);
		std::pair<float,float> zlShifDown     = createHistogramShifted(zllFile_,"ZL_CMS_htt_ZLScale_mutau_"+energy_+"Down",("("+osSignalSelection_+"&&"+vbfRelaxedSelection_+"&&nJetsPt20>=2&&genTaus==0&& ((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))*ZeFakeTau*"+weight_),"0.98",luminosity_*leg1Corr*zlftFactor_*zttScale_*zExtrap,prefix);
		renormalizeHistogram(channel_+prefix,"ZL_CMS_htt_ZLScale_mutau_"+energy_+"Up",zlYield.first);
		renormalizeHistogram(channel_+prefix,"ZL_CMS_htt_ZLScale_mutau_"+energy_+"Down",zlYield.first);
		mergeHistogram(channel_+prefix,"ZL_CMS_htt_ZLScale_mutau_"+energy_+"Up","ZJ","ZLL_CMS_htt_ZLScale_mutau_"+energy_+"Up");
		mergeHistogram(channel_+prefix,"ZL_CMS_htt_ZLScale_mutau_"+energy_+"Down","ZJ","ZLL_CMS_htt_ZLScale_mutau_"+energy_+"Down");	
	}
    std::pair<float,float> zllSSYield    = createHistogramAndShifts(zttFile_,"ZL_SS",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+ssSignalSelection_+"&&genTaus==0)*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zExtrap*zttScale_,prefix,false);


	///////////////// W Background estimate ///////////////////
  
	  wSelection_="mt1>60&&mt1<120";
	  osWSelection_="mt1>60&&mt1<120&&charge==0";
	  std::pair<float,float> wShape      = createHistogramAndShiftsFinal(wFile_,"W",("("+preSelection+"&&"+vbfRelaxedSelection_+"&&"+signalSelection_+"&&nJetsPt30>=2)*"+weight_),luminosity_*leg1Corr,prefix,false,false);

	  std::pair<float,float> dataYWSDB   = createHistogramAndShiftsFinal(dataFile_,"dataWSDB","("+preSelection+"&&"+categorySelection+"&&"+osWSelection_+"&&"+trigSelection_+")",scaleUp_,prefix);
	  std::pair<float,float> vvYieldSDB  = createHistogramAndShiftsFinal(vvFile_,"VVSDB",("("+preSelection+"&&"+categorySelection+"&&"+osWSelection_+"&&"+trigSelection_+")*"+weight_),luminosity_*leg1Corr*tauID,prefix,true,false);
	  std::pair<float,float> topYieldSDB = createHistogramAndShiftsFinal(topFile_,"TTSDB",("("+preSelection+"&&"+categorySelection+"&&"+osWSelection_+"&&"+trigSelection_+")*"+weight_),luminosity_*leg1Corr*tauID*topExtrap,prefix);
	  std::pair<float,float> zYieldSDB = createHistogramAndShiftsFinal(zttFile_,"ZSDB",("("+preSelection+"&&"+categorySelection+"&&"+osWSelection_+"&&"+trigSelection_+")*ZeFakeTau*"+weight_),luminosity_*leg1Corr*tauID,prefix);

	  std::pair<float,float> wFactor = extractWFactor(wShape_,"nJetsPt30>=2&&"+vbfRelaxedSelection_+"&&"+preSelection+"&&"+trigSelection_,prefix,wSelection_,signalSelection_);
  

	  std::pair<float,float> osWHigh = std::make_pair((dataYWSDB.first-topYieldSDB.first-vvYieldSDB.first-zYieldSDB.first),
							  sqrt(dataYWSDB.second*dataYWSDB.second+topYieldSDB.second*topYieldSDB.second+vvYieldSDB.second*vvYieldSDB.second+zYieldSDB.second*zYieldSDB.second));	  

	  printf("OS W in sideband  =%f -%f -%f -%f = %f +- %f \n",dataYWSDB.first,topYieldSDB.first,vvYieldSDB.first,zYieldSDB.first,osWHigh.first,osWHigh.second);
  

	  std::pair<float,float> wYield = std::make_pair(osWHigh.first*wFactor.first,
							 sqrt(osWHigh.first*osWHigh.first*wFactor.second*wFactor.second+osWHigh.second*osWHigh.second*wFactor.first*wFactor.first));

	  printf("W Yield = %f * %f = %f\n", osWHigh.first, wFactor.first, wYield.first);
		 
	  renormalizeHistogram(channel_+prefix,"W",wYield.first);				     
					 

    //Trick:For W_SS yield use the OS/SS ratio as measured in inclusive for W
    std::pair<float,float> wSSYield = std::make_pair(wYield.first*inclusive.WSS/inclusive.W,wYield.second*inclusive.WSS/inclusive.W);   

    std::pair<float,float> dataY         = createHistogramAndShiftsFinal(dataFile_,"data_obs","("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+osSignalSelection_+"&&"+blinding_+")",scaleUp_,prefix);
    std::pair<float,float> dataYRounded  = std::make_pair(rintf(dataY.first),dataY.second);
    renormalizeHistogram(channel_+prefix,"data_obs",dataYRounded.first);
    std::pair<float,float> dataYield      = convertToPoisson(dataYRounded);
 
    std::pair<float,float> dataSSY          = createHistogramAndShifts(dataFile_,"data_obs_ss","("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+ssSignalSelection_+")",scaleUp_,prefix);
    std::pair<float,float> dataSSYield      = convertToPoisson(dataSSY);


	////////// QCD Estimate ///////////////
	
	std::pair<float,float> dataQCDShape = createHistogramAndShifts(dataFile_,"QCD","nJetsPt20>=2&&"+vbfRelaxedSelection_+"&&"+qcdSelection_,scaleUp_,prefix,false,false);
	std::pair<float,float> dataQCDControl = createHistogramAndShifts(dataFile_,"QCDC1",categorySelection+"&&"+qcdSelection_,scaleUp_,prefix,false,false);
	std::pair<float,float> dataQCDControlInc = createHistogramAndShifts(dataFile_,"QCDC2",qcdSelection_,scaleUp_,prefix,false,false);	

	float qcdFactor = dataQCDControl.first/dataQCDControlInc.first;
	float qcdFactorErr = TEfficiency::ClopperPearson(dataQCDControlInc.first,dataQCDControl.first,0.68,true)-qcdFactor; 

	std::pair<float,float> osQCD = std::make_pair(inclusive.QCD*qcdFactor,sqrt(inclusive.QCD*inclusive.QCD*qcdFactorErr*qcdFactorErr+qcdFactor*qcdFactor*inclusive.dQCD*inclusive.dQCD));
	
	////////// Output ////////////////////
	
	
	printf("qcdFactor = %f / %f = %f\n", dataQCDControl.first, dataQCDControlInc.first, qcdFactor);
	printf("osQCD = %f * %f = %f\n", inclusive.QCD, qcdFactor, osQCD.first);

    //Inflate the errors
    std::pair<float,float> topInflYield  = inflateError(topYield,topErr_);
    printf("TTbar events in signal region = %f + %f \n",topInflYield.first,topInflYield.second);

    std::pair<float,float> topInflSSYield  = inflateError(topSSYield,topErr_,topExtrapErr);
    printf("TTbar events in SS region = %f + %f \n",topInflSSYield.first,topInflSSYield.second);

    std::pair<float,float> vvInflYield  = inflateError(vvYield,vvErr_);
    printf("Diboson events in signal region = %f + %f \n",vvInflYield.first,vvInflYield.second);
    
    std::pair<float,float> zllInflYield  = inflateError(zllYield,zlftErr_,zjftErr_);
    printf("Z ->ll in signal region = %f + %f \n",zllInflYield.first,zllInflYield.second);

    std::pair<float,float> zllInflSSYield  = inflateError(zllSSYield,zjftErr_);
    printf("Z ->ll in SS region = %f + %f \n",zllInflSSYield.first,zllInflSSYield.second);

    std::pair<float,float> wInflYield  = inflateError(wYield,inclusive.dWCORR);
    printf("W in signal region = %f + %f \n",wInflYield.first,wInflYield.second);

    std::pair<float,float> wInflSSYield  = inflateError(wSSYield,inclusive.dWSSCORR,wExtrapErr);
    printf("W in SS region = %f + %f \n",wInflSSYield.first,wInflSSYield.second);


	  printf("OS QCD in  core  =%f *%f = %f +- %f \n",inclusive.QCD,qcdFactor,osQCD.first,osQCD.second);
	   
	  float background    = osQCD.first+wInflYield.first+topInflYield.first+vvInflYield.first+zllInflYield.first+zttYield.first;
	  float backgroundErr = sqrt(osQCD.second*osQCD.second+wInflYield.second*wInflYield.second+topInflYield.second*topInflYield.second+vvInflYield.second*vvInflYield.second+zllInflYield.second*zllInflYield.second+zttYield.second*zttYield.second);
	  printf("BACKGROUND=%f +-%f \n",background,backgroundErr);


	  ///LATEX
	  printf("LATEX ------------------------------------\n");

	  printf("Total & %.2f  \\\\ \n", dataYield.first);
	  printf("Di-Boson & %.2f $\\pm$ %.2f  \\\\ \n", vvInflYield.first, quadrature(vvInflYield.first,vvInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_));
	  printf("$t\\bar{t}$ & %.2f $\\pm$ %.2f \\\\ \n", topInflYield.first,quadrature(topInflYield.first,topInflYield.second,muIDErr_,eleIDErr_,tauIDErr_,topExtrapErr));
      printf("$Z^{l+jet}$ & %.2f $\\pm$ %.2f & - & - $\\pm$ - & - \\\\ \n", zjYield.first, quadrature(zjYield.first,zjYield.second,muIDErr_,eleIDErr_,zttScaleErr_,zExtrapErr));
      printf("$Z^{ll}$ & %.2f $\\pm$ %.2f & - & - $\\pm$ - & - \\\\ \n", zlYield.first, quadrature(zlYield.first,zlYield.second,muIDErr_,eleIDErr_,zttScaleErr_,zExtrapErr));
	  printf("$W+jets$ & %.2f $\\pm$ %.2f   \\\\ \n", wInflYield.first, quadrature(wInflYield.first,wInflYield.second,wExtrapErr));
	  printf("QCD & %.2f $\\pm$ %.2f \\\\ \n", osQCD.first, osQCD.second);
	  printf("$Z\\rightarrow\\tau\\tau$ & %.2f $\\pm$ %.2f & - & - & - \\\\ \n", zttYield.first,quadrature(zttYield.first,zttYield.second,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_,zExtrapErr));
	  float fullBackgroundErr = sqrt(pow(quadrature(vvInflYield.first,vvInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_),2)+
											   pow(quadrature(topInflYield.first,topInflYield.second,muIDErr_,eleIDErr_,tauIDErr_),2)+
											   pow(quadrature(zllInflYield.first,zllInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_,zExtrapErr),2)+
											   pow(osQCD.second,2)+
											   pow(quadrature(wInflYield.first,wInflYield.second,wExtrapErr),2)+
																	   pow(quadrature(zttYield.first,zttYield.second,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_,zExtrapErr),2));
	  printf("Total Background & %.2f $\\pm$ %.2f & - & - & - \\\\ \n",background,fullBackgroundErr);



	  //create a histogram with the error for plotting reasons and only
	  TH1F *err = new TH1F("BKGErr","",1,0,1);
	  err->SetBinContent(1,fullBackgroundErr/background);
	  fout_->cd((channel_+prefix).c_str());
	  err->Write();

	  output.DATA = dataYield.first;
	  output.W = wInflYield.first;
	  output.dW = wInflYield.second;
  
	  output.WSS = wInflSSYield.first;
	  output.dWSS =wInflYield.second;
  
	  output.QCD = osQCD.first;
	  output.dQCD = osQCD.second;

	  output.ZLFT = zllInflYield.first;
	  output.dZLFT =zllInflYield.second;
	  output.ZLFTSS = zllInflSSYield.first;
	  output.dZLFTSS =zllInflSSYield.second;

	  output.TOP = topInflYield.first;
	  output.dTOP = topInflYield.second;
	  output.VV = vvInflYield.first;
	  output.dVV = vvInflYield.second;
	  output.ZTT = zttYield.first;
	  output.dZTT = zttYield.second;
  
	  output.WCORR = inclusive.WCORR;
	  output.dWCORR = inclusive.dWCORR;
  
  
	  /////////////// post processing fixes ////////////////
  
	  //now renormalize the data driven histograms
	  FixEmptyBins(channel_+prefix,"QCD",true);
	  FixEmptyBinsMC(channel_+prefix,"W",false);
	  FixEmptyBinsMC(channel_+prefix,"ZTT",false);
	  if(channel_=="eleTau"){
		FixEmptyBinsMC(channel_+prefix,"ZLL",false);
		FixEmptyBinsMC(channel_+prefix,"ZL",false);
		FixEmptyBinsMC(channel_+prefix,"ZJ",false);      	
	  }

	  renormalizeHistogram(channel_+prefix,"QCD",osQCD.first);
      qcdSyst(channel_, prefix, "QCD", 1.0, 0.1);
 
 	  return output;

  }



  BkgOutput runVBFTight(std::string preSelection,std::string categorySelection, std::string prefix, BkgOutput inclusive,float zExtrap,float zExtrapErr,float wExtrap,float wExtrapErr,float topExtrap,float topExtrapErr,std::string zShape_="",std::string wShape_="") {

    float leg1Corr=1.0;
    if(muID_!=0) leg1Corr*=muID_;
    if(eleID_!=0) leg1Corr*=eleID_;

	float tauID = 1.0;
	tauID = tauID_ - (1.-tauIDHigh_)/2. ;
	printf("Tau ID Scale Factor is %.3f \n",tauID);		

    BkgOutput output;

    output.ZTTCORR=zExtrap;
    output.dZTTCORR=zExtrapErr;

    ////////////// Estimate Z--> ττ ///////////////
    std::pair<float,float> zttYield       = createHistogramAndShiftsFinal(zttFile_,"ZTTTMP",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&genTaus>0&&genVisPt2>18&&(!((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)||(genTaus>0&&genVisPt2>18))))*"+weight_),luminosity_*zttScale_*zExtrap*leg1Corr*tauID,prefix);
    std::pair<float,float> ztt_ll       = createHistogramAndShiftsFinal(zttFile_,"ZTT_LL",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&genTaus>0&&((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))*"+weight_),luminosity_*zttScale_*zExtrap*leg1Corr*tauID,prefix);
	float corr = 1.0;
	
    if(zShape_.size()==0) {
    
        std::pair<float,float> zttShape       = createHistogramAndShiftsFinal(zttFile_,"ZTT",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+osSignalSelection_+"&&genTaus>0&&genVisPt2>18)*"+weight_),luminosity_*zttScale_*leg1Corr*tauID*zExtrap,prefix,true);

    }
    else{

		printf("You have embedded samples.Calculating corrections on the fly overidding the crappy ones you gave me!\n");

		std::pair<float,float> zttShape       = createHistogramAndShifts(zShape_,"ZTT",("("+preSelection+"&&"+categorySelection+"&&"+osSignalSelection_+"&&genFullMass>50&&genVisPt2>18)*"+embWeight_),leg1Corr*tauID,prefix,true);	
		std::pair<float,float> zttEmbYield    = createHistogramAndShifts(zShape_,"ZTTTMP",("("+preSelection+"&&"+categorySelection+"&&"+osSignalSelection_+"&&genFullMass>50&&genVisPt2>18)*"+embWeight_),leg1Corr*tauID,prefix,true);
		std::pair<float,float> zttShapePre    = createHistogramAndShifts(zShape_,"ZTTPre",("("+preSelection+"&&"+osSignalSelection_+"&&genFullMass>50&&genVisPt2>18)*"+embWeight_),leg1Corr*tauID,prefix,true);

	
		corr = zttEmbYield.first/zttShapePre.first;
		printf("Efficiency for embedding =%f\n",corr);	
		double corrErr = corr*sqrt(1/zttEmbYield.first + 1/zttShapePre.first);;
		zttYield = std::make_pair(inclusive.ZTT*corr,inclusive.dZTT*corrErr);
		renormalizeHistogram(channel_+prefix,"ZTT",inclusive.ZTT*corr);
		output.ZTTCORR=corr;
		output.dZTTCORR=corrErr;
		
		addHistogramZTT(channel_+prefix, "ZTT", "ZTT_LL");

    }

	//////////////// Estimate ttbar ///////////////
	
    std::pair<float,float> topShape       = createHistogramAndShifts(topFile_,"TT",("("+preSelection+"&&"+trigSelection_+"&&"+vbfRelaxedSelection_+"&&"+vbfTightS_+"&&"+signalSelection_+"&&nJetsPt30>=2)*"+weight_),luminosity_*leg1Corr*tauID,prefix,true,false);

    std::pair<float,float> topYield       = createHistogramAndShiftsFinal(topFile_,"TTTMP",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+osSignalSelection_+")*"+weight_),luminosity_*leg1Corr*tauID*topExtrap,prefix);
    renormalizeHistogram(channel_+prefix,"TT",topYield.first);

    std::pair<float,float> topSSYield       = createHistogramAndShifts(topFile_,"TTSS",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+ssSignalSelection_+")*"+weight_),luminosity_*leg1Corr*tauID*topExtrap,prefix);
	
	//////////////// Estimate VV   ////////////////
	
	std::pair<float,float> vvShape        = createHistogramAndShiftsFinal(vvFile_,"VV",("("+preSelection+"&&"+trigSelection_+"&&"+vbfRelaxedSelection_+"&&"+vbfTightS_+"&&"+osSignalSelection_+"&&nJetsPt30>=2)*"+weight_),luminosity_*leg1Corr*tauID,prefix,true,false);
    
    std::pair<float,float> vvYield        = createHistogramAndShiftsFinal(vvFile_,"VVTMP",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+osSignalSelection_+")*"+weight_),luminosity_*leg1Corr*tauID,prefix,true,false);
    renormalizeHistogram(channel_+prefix,"VV",vvYield.first);


	//////////////// Estimate ZLL  ////////////////
	    
	std::pair<float,float> zlShape      = createHistogramAndShiftsFinal(zttFile_,"ZL",("("+osSignalSelection_+"&&"+vbfRelaxedSelection_+"&&"+vbfTightS_+"&&nJetsPt20>=2&&genTaus==0&& ((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zttScale_,prefix,false,false);
	std::pair<float,float> zjShape      = createHistogramAndShiftsFinal(zttFile_,"ZJ",("("+osSignalSelection_+"&&"+vbfRelaxedSelection_+"&&"+vbfTightS_+"&&nJetsPt30>=2&&(!((genTaus==0&&abs(pdg2)==13&&genPt2>8)||(genTaus==0&&abs(pdg2)==11&&genPt2>8)||(genTaus>0&&genVisPt2>18))))*"+weight_),luminosity_*leg1Corr*zttScale_,prefix,false,false);
	
	std::pair<float,float> zlYield      = createHistogramAndShiftsFinal(zttFile_,"ZLTMP",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&genTaus==0&& ((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zExtrap*zttScale_,prefix,false);
	std::pair<float,float> zjYield      = createHistogramAndShiftsFinal(zttFile_,"ZJTMP",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&(!((genTaus==0&&abs(pdg2)==13&&genPt2>8)||(genTaus==0&&abs(pdg2)==11&&genPt2>8)||(genTaus>0&&genVisPt2>18))))*"+weight_),luminosity_*leg1Corr*zExtrap*zttScale_,prefix,false);
	
	std::pair<float,float> zllYield;
	zllYield.first = zlYield.first+zjYield.first;
	zllYield.second = sqrt(zlYield.second*zlYield.second+zjYield.second*zjYield.second);
	renormalizeHistogram(channel_+prefix,"ZL",zlYield.first);
	renormalizeHistogram(channel_+prefix,"ZJ",zjYield.first);
	mergeHistogram(channel_+prefix,"ZL","ZJ","ZLL");

	if(channel_=="eleTau"){
		std::pair<float,float> zlShiftUp      = createHistogramShifted(zllFile_,"ZL_CMS_htt_ZLScale_etau_"+energy_+"Up",("("+osSignalSelection_+"&&"+vbfRelaxedSelection_+"&&"+vbfTightS_+"&&nJetsPt20>=2&&genTaus==0&& ((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))*ZeFakeTau*"+weight_),"1.02",luminosity_*leg1Corr*zlftFactor_*zttScale_*zExtrap,prefix);
		std::pair<float,float> zlShifDown     = createHistogramShifted(zllFile_,"ZL_CMS_htt_ZLScale_etau_"+energy_+"Down",("("+osSignalSelection_+"&&"+vbfRelaxedSelection_+"&&"+vbfTightS_+"&&nJetsPt20>=2&&genTaus==0&& ((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))*ZeFakeTau*"+weight_),"0.98",luminosity_*leg1Corr*zlftFactor_*zttScale_*zExtrap,prefix);
		renormalizeHistogram(channel_+prefix,"ZL_CMS_htt_ZLScale_etau_"+energy_+"Up",zlYield.first);
		renormalizeHistogram(channel_+prefix,"ZL_CMS_htt_ZLScale_etau_"+energy_+"Down",zlYield.first);
		mergeHistogram(channel_+prefix,"ZL_CMS_htt_ZLScale_etau_"+energy_+"Up","ZJ","ZLL_CMS_htt_ZLScale_etau_"+energy_+"Up");
		mergeHistogram(channel_+prefix,"ZL_CMS_htt_ZLScale_etau_"+energy_+"Down","ZJ","ZLL_CMS_htt_ZLScale_etau_"+energy_+"Down");
	}
	else{
		std::pair<float,float> zlShiftUp      = createHistogramShifted(zllFile_,"ZL_CMS_htt_ZLScale_mutau_"+energy_+"Up",("("+osSignalSelection_+"&&"+vbfRelaxedSelection_+"&&"+vbfTightS_+"&&nJetsPt20>=2&&genTaus==0&& ((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))*ZeFakeTau*"+weight_),"1.02",luminosity_*leg1Corr*zlftFactor_*zttScale_*zExtrap,prefix);
		std::pair<float,float> zlShifDown     = createHistogramShifted(zllFile_,"ZL_CMS_htt_ZLScale_mutau_"+energy_+"Down",("("+osSignalSelection_+"&&"+vbfRelaxedSelection_+"&&"+vbfTightS_+"&&nJetsPt20>=2&&genTaus==0&& ((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))*ZeFakeTau*"+weight_),"0.98",luminosity_*leg1Corr*zlftFactor_*zttScale_*zExtrap,prefix);
		renormalizeHistogram(channel_+prefix,"ZL_CMS_htt_ZLScale_mutau_"+energy_+"Up",zlYield.first);
		renormalizeHistogram(channel_+prefix,"ZL_CMS_htt_ZLScale_mutau_"+energy_+"Down",zlYield.first);
		mergeHistogram(channel_+prefix,"ZL_CMS_htt_ZLScale_mutau_"+energy_+"Up","ZJ","ZLL_CMS_htt_ZLScale_mutau_"+energy_+"Up");
		mergeHistogram(channel_+prefix,"ZL_CMS_htt_ZLScale_mutau_"+energy_+"Down","ZJ","ZLL_CMS_htt_ZLScale_mutau_"+energy_+"Down");	
	}

    std::pair<float,float> zllSSYield    = createHistogramAndShifts(zttFile_,"ZL_SS",("("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+ssSignalSelection_+"&&genTaus==0)*ZeFakeTau*"+weight_),luminosity_*leg1Corr*zExtrap*zttScale_,prefix,false);


	///////////////// W Background estimate ///////////////////
  
	  wSelection_="mt1>60&&mt1<120";
	  osWSelection_="mt1>60&&mt1<120&&charge==0";
	  std::pair<float,float> wShape      = createHistogramAndShifts(wFile_,"W",("(diLeptons==0&&lPFIsoDB<0.1&&(tightElectrons+tightMuons)<=1&&"+trigSelection_+"&&"+relaxedSelection_+"&&"+categorySelection+")*"+weight_),luminosity_*leg1Corr,prefix,false,false);

	  std::pair<float,float> dataYWSDB   = createHistogramAndShiftsFinal(dataFile_,"dataWSDB","("+preSelection+"&&"+categorySelection+"&&"+osWSelection_+"&&"+trigSelection_+")",scaleUp_,prefix);
	  std::pair<float,float> vvYieldSDB  = createHistogramAndShiftsFinal(vvFile_,"VVSDB",("("+preSelection+"&&"+categorySelection+"&&"+osWSelection_+"&&"+trigSelection_+")*"+weight_),luminosity_*leg1Corr*tauID,prefix,true,false);
	  std::pair<float,float> topYieldSDB = createHistogramAndShiftsFinal(topFile_,"TTSDB",("("+preSelection+"&&"+categorySelection+"&&"+osWSelection_+"&&"+trigSelection_+")*"+weight_),luminosity_*leg1Corr*tauID*topExtrap,prefix);
	  std::pair<float,float> zYieldSDB = createHistogramAndShiftsFinal(zttFile_,"ZSDB",("("+preSelection+"&&"+categorySelection+"&&"+osWSelection_+"&&"+trigSelection_+")*ZeFakeTau*"+weight_),luminosity_*leg1Corr*tauID,prefix);

	  std::pair<float,float> wFactor = extractWFactor(wShape_,"nJetsPt30>=2&&"+vbfRelaxedSelection_+"&&"+vbfTightS_+"&&"+preSelection+"&&"+trigSelection_,prefix,wSelection_,signalSelection_);
  

	  std::pair<float,float> osWHigh = std::make_pair((dataYWSDB.first-topYieldSDB.first-vvYieldSDB.first-zYieldSDB.first),
							  sqrt(dataYWSDB.second*dataYWSDB.second+topYieldSDB.second*topYieldSDB.second+vvYieldSDB.second*vvYieldSDB.second+zYieldSDB.second*zYieldSDB.second));	  

	  printf("OS W in sideband  =%f -%f -%f -%f = %f +- %f \n",dataYWSDB.first,topYieldSDB.first,vvYieldSDB.first,zYieldSDB.first,osWHigh.first,osWHigh.second);
  

	  std::pair<float,float> wYield = std::make_pair(osWHigh.first*wFactor.first,
							 sqrt(osWHigh.first*osWHigh.first*wFactor.second*wFactor.second+osWHigh.second*osWHigh.second*wFactor.first*wFactor.first));

	  printf("W Yield = %f * %f = %f\n", osWHigh.first, wFactor.first, wYield.first);
		 
	  renormalizeHistogram(channel_+prefix,"W",wYield.first);				     
					 

    //Trick:For W_SS yield use the OS/SS ratio as measured in inclusive for W
    std::pair<float,float> wSSYield = std::make_pair(wYield.first*inclusive.WSS/inclusive.W,wYield.second*inclusive.WSS/inclusive.W);   

    std::pair<float,float> dataY         = createHistogramAndShiftsFinal(dataFile_,"data_obs","("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+osSignalSelection_+"&&"+blinding_+")",scaleUp_,prefix);
    std::pair<float,float> dataYRounded  = std::make_pair(rintf(dataY.first),dataY.second);
    renormalizeHistogram(channel_+prefix,"data_obs",dataYRounded.first);
    std::pair<float,float> dataYield      = convertToPoisson(dataYRounded);
 
    std::pair<float,float> dataSSY          = createHistogramAndShifts(dataFile_,"data_obs_ss","("+preSelection+"&&"+trigSelection_+"&&"+categorySelection+"&&"+ssSignalSelection_+")",scaleUp_,prefix);
    std::pair<float,float> dataSSYield      = convertToPoisson(dataSSY);


	////////// QCD Estimate ///////////////
	
	std::pair<float,float> dataQCDShape = createHistogramAndShifts(dataFile_,"QCD","charge!=0&&diLeptons==0&&lPFIsoDB>0.2&&nJetsPt20>=2&&(tightElectrons+tightMuons)<1&&"+trigSelection_+"&&"+vbfRelaxedSelection_+"&&"+vbfTightS_+"&&"+relaxedSelection_,scaleUp_,prefix,false,false);
	std::pair<float,float> dataQCDControl = createHistogramAndShifts(dataFile_,"QCDC1","diLeptons==0&&lPFIsoDB>0.2&&(tightElectrons+tightMuons)<1&&"+categorySelection+"&&"+ssSignalSelection_,scaleUp_,prefix,false,false);
	std::pair<float,float> dataQCDControlInc = createHistogramAndShifts(dataFile_,"QCDC2","diLeptons==0&&lPFIsoDB>0.2&&(tightElectrons+tightMuons)<1&&"+ssSignalSelection_,scaleUp_,prefix,false,false);	

	float qcdFactor = dataQCDControl.first/dataQCDControlInc.first;
	float qcdFactorErr = TEfficiency::ClopperPearson(dataQCDControlInc.first,dataQCDControl.first,0.68,true)-qcdFactor; 

	std::pair<float,float> osQCD = std::make_pair(inclusive.QCD*qcdFactor,sqrt(inclusive.QCD*inclusive.QCD*qcdFactorErr*qcdFactorErr+qcdFactor*qcdFactor*inclusive.dQCD*inclusive.dQCD));
	
	////////// Output ////////////////////
	
	printf("osQCD = %f * %f = %f\n", inclusive.QCD, qcdFactor, osQCD.first);

    //Inflate the errors
    std::pair<float,float> topInflYield  = inflateError(topYield,topErr_);
    printf("TTbar events in signal region = %f + %f \n",topInflYield.first,topInflYield.second);

    std::pair<float,float> topInflSSYield  = inflateError(topSSYield,topErr_,topExtrapErr);
    printf("TTbar events in SS region = %f + %f \n",topInflSSYield.first,topInflSSYield.second);

    std::pair<float,float> vvInflYield  = inflateError(vvYield,vvErr_);
    printf("Diboson events in signal region = %f + %f \n",vvInflYield.first,vvInflYield.second);
    
    std::pair<float,float> zllInflYield  = inflateError(zllYield,zlftErr_,zjftErr_);
    printf("Z ->ll in signal region = %f + %f \n",zllInflYield.first,zllInflYield.second);

    std::pair<float,float> zllInflSSYield  = inflateError(zllSSYield,zjftErr_);
    printf("Z ->ll in SS region = %f + %f \n",zllInflSSYield.first,zllInflSSYield.second);

    std::pair<float,float> wInflYield  = inflateError(wYield,inclusive.dWCORR);
    printf("W in signal region = %f + %f \n",wInflYield.first,wInflYield.second);

    std::pair<float,float> wInflSSYield  = inflateError(wSSYield,inclusive.dWSSCORR,wExtrapErr);
    printf("W in SS region = %f + %f \n",wInflSSYield.first,wInflSSYield.second);


	  printf("OS QCD in  core  =%f *%f = %f +- %f \n",inclusive.QCD,qcdFactor,osQCD.first,osQCD.second);
	   
	  float background    = osQCD.first+wInflYield.first+topInflYield.first+vvInflYield.first+zllInflYield.first+zttYield.first;
	  float backgroundErr = sqrt(osQCD.second*osQCD.second+wInflYield.second*wInflYield.second+topInflYield.second*topInflYield.second+vvInflYield.second*vvInflYield.second+zllInflYield.second*zllInflYield.second+zttYield.second*zttYield.second);
	  printf("BACKGROUND=%f +-%f \n",background,backgroundErr);


	  ///LATEX
	  printf("LATEX ------------------------------------\n");

	  printf("Total & %.2f  \\\\ \n", dataYield.first);
	  printf("Di-Boson & %.2f $\\pm$ %.2f  \\\\ \n", vvInflYield.first, quadrature(vvInflYield.first,vvInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_));
	  printf("$t\\bar{t}$ & %.2f $\\pm$ %.2f \\\\ \n", topInflYield.first,quadrature(topInflYield.first,topInflYield.second,muIDErr_,eleIDErr_,tauIDErr_,topExtrapErr));
      printf("$Z^{l+jet}$ & %.2f $\\pm$ %.2f & - & - $\\pm$ - & - \\\\ \n", zjYield.first, quadrature(zjYield.first,zjYield.second,muIDErr_,eleIDErr_,zttScaleErr_,zExtrapErr));
      printf("$Z^{ll}$ & %.2f $\\pm$ %.2f & - & - $\\pm$ - & - \\\\ \n", zlYield.first, quadrature(zlYield.first,zlYield.second,muIDErr_,eleIDErr_,zttScaleErr_,zExtrapErr));
	  printf("$W+jets$ & %.2f $\\pm$ %.2f   \\\\ \n", wInflYield.first, quadrature(wInflYield.first,wInflYield.second,wExtrapErr));
	  printf("QCD & %.2f $\\pm$ %.2f \\\\ \n", osQCD.first, osQCD.second);
	  printf("$Z\\rightarrow\\tau\\tau$ & %.2f $\\pm$ %.2f & - & - & - \\\\ \n", zttYield.first,quadrature(zttYield.first,zttYield.second,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_,zExtrapErr));
	  float fullBackgroundErr = sqrt(pow(quadrature(vvInflYield.first,vvInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_),2)+
											   pow(quadrature(topInflYield.first,topInflYield.second,muIDErr_,eleIDErr_,tauIDErr_),2)+
											   pow(quadrature(zllInflYield.first,zllInflYield.second,muIDErr_,eleIDErr_,zttScaleErr_,zExtrapErr),2)+
											   pow(osQCD.second,2)+
											   pow(quadrature(wInflYield.first,wInflYield.second,wExtrapErr),2)+
																	   pow(quadrature(zttYield.first,zttYield.second,muIDErr_,eleIDErr_,zttScaleErr_,tauIDErr_,zExtrapErr),2));
	  printf("Total Background & %.2f $\\pm$ %.2f & - & - & - \\\\ \n",background,fullBackgroundErr);



	  //create a histogram with the error for plotting reasons and only
	  TH1F *err = new TH1F("BKGErr","",1,0,1);
	  err->SetBinContent(1,fullBackgroundErr/background);
	  fout_->cd((channel_+prefix).c_str());
	  err->Write();

	  output.DATA = dataYield.first;
	  output.W = wInflYield.first;
	  output.dW = wInflYield.second;
  
	  output.WSS = wInflSSYield.first;
	  output.dWSS =wInflYield.second;
  
	  output.QCD = osQCD.first;
	  output.dQCD = osQCD.second;

	  output.ZLFT = zllInflYield.first;
	  output.dZLFT =zllInflYield.second;
	  output.ZLFTSS = zllInflSSYield.first;
	  output.dZLFTSS =zllInflSSYield.second;

	  output.TOP = topInflYield.first;
	  output.dTOP = topInflYield.second;
	  output.VV = vvInflYield.first;
	  output.dVV = vvInflYield.second;
	  output.ZTT = zttYield.first;
	  output.dZTT = zttYield.second;
  
	  output.WCORR = inclusive.WCORR;
	  output.dWCORR = inclusive.dWCORR;
  
  
	  /////////////// post processing fixes ////////////////
  
	  //now renormalize the data driven histograms
	  FixEmptyBins(channel_+prefix,"QCD",true);
	  FixEmptyBinsMC(channel_+prefix,"W",false);
	  FixEmptyBinsMC(channel_+prefix,"ZTT",false);
	  if(channel_=="eleTau"){
		FixEmptyBinsMC(channel_+prefix,"ZLL",false);
		FixEmptyBinsMC(channel_+prefix,"ZL",false);
		FixEmptyBinsMC(channel_+prefix,"ZJ",false);      	
	  }
	  
	  renormalizeHistogram(channel_+prefix,"QCD",osQCD.first);

      qcdSyst(channel_, prefix, "QCD", 1.0, 0.1);

	  return output;

  }
  
  
  
  void convertToCutAndCount(std::string dir,std::string histogram) {
    TH1F * h = (TH1F*) fout_->Get((dir+"/"+histogram).c_str());
    
     Double_t error=0.0;
     float yield = h->IntegralAndError(1,h->GetNbinsX(),error,"");

     for( int i=1;i<h->GetNbinsX();++i) {
       h->SetBinContent(i,10000.);
     }

     h->Scale(yield/h->Integral());

     fout_->cd(dir.c_str());
     h->Write("",TObject::kOverwrite);

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



    std::pair<float,float> makeHistogram(TTree* tree,std::string folder,std::string name,std::string cut,float scaleFactor = 1.) {

   if(fout_->Get(folder.c_str())==0)
     fout_->mkdir(folder.c_str());
     TH1F *h=0;

     TString variableOld_=variable_;
     if((name=="data_obs"||name=="data_obs_ss"||name=="data_obs_sdb"||name=="data_obs_ss_sdb"||name=="QCD")&&variable_=="pt2ES"){
       variable_="pt2";
     }

     if(verbose_>0)
       std::cout<< " " <<name<<std::endl;

     if(binning_.size()==0)
       h= new TH1F(name.c_str(),name.c_str(),bins_,min_,max_);
     else 
       h = new TH1F(name.c_str(),name.c_str(),binning_.size()-1,&binning_[0]);
     h->Sumw2();

     tree->Draw((variable_+">>"+name).c_str(),cut.c_str());

     variable_=variableOld_;//

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
  
  
  void superSmooth(std::string folder, std::string histo, bool verbose=false){
  
  	if(verbose) std::cout << ">>>>>>>>>>>>> SUPER SMOOTH >>>>>>>>>>>>>>>" << std::endl;
    TH1F * h =(TH1F*) fout_->Get((folder+"/"+histo).c_str());
    Double_t yield =  h->Integral();
    for(int i = 0; i < h->GetNbinsX()+1; i++){
		h->SetBinContent(i,h->GetBinContent(i)/h->GetBinWidth(i));
	}
	h->Smooth();
    for(int i = 0; i < h->GetNbinsX()+1; i++){
    	if(h->GetBinError(i)==0){
    		if(verbose)
    			std::cout << "Removing newly created bin " << h->GetXaxis()->GetBinCenter(i) << std::endl;
    		h->SetBinContent(i,0);
    	}
    	else{
    		h->SetBinContent(i,h->GetBinContent(i)*h->GetBinWidth(i));
    	}
    }
    h->Scale(yield/h->Integral());	
    h->Write(h->GetName(),TObject::kOverwrite);
    
  }

  void CheckFirstFourBins(std::string channel, std::string prefix){
    TH1F * data =(TH1F*) fout_->Get((channel+prefix+"/data_obs").c_str());
    float y = 0;
    for(int i=1; i<12; i++){
      y = data->GetBinContent(i);
      if(y>0){
	for(unsigned int i=0;i<smMasses_.size();++i) {
	  TH1F * sm =(TH1F*) fout_->Get((channel+prefix+"/ggH"+smMasses_[i]).c_str());
	  TH1F * vbf =(TH1F*) fout_->Get((channel+prefix+"/qqH"+smMasses_[i]).c_str());
	  TH1F * vh =(TH1F*) fout_->Get((channel+prefix+"/VH"+smMasses_[i]).c_str());
	  float prune = 0;
	  if(sm->GetBinContent(i)>0){
	    prune = 0;
	    prune = CheckBackgrounds(channel,prefix,i,("ggH"+smMasses_[i]).c_str(),sm->GetBinContent(i));
	    if(prune>0)
	      sm->SetBinContent(i,0);
	  }
	  
	  if(vbf->GetBinContent(i)>0){
	    prune = 0;
	    prune = CheckBackgrounds(channel,prefix,i,("qqH"+smMasses_[i]).c_str(),vbf->GetBinContent(i));
	    if(prune>0)
	      vbf->SetBinContent(i,0);
	  }
	  
	  if(vh->GetBinContent(i)>0){
	    prune = 0;
	    prune = CheckBackgrounds(channel,prefix,i,("VH"+smMasses_[i]).c_str(),vh->GetBinContent(i));
	  }
	  if(prune>0){
	    vh->SetBinContent(i,0);
	  }
	}
      }

    }

  }

  float CheckBackgrounds(std::string channel, std::string prefix, int i,TString signal, float signalYield){
    TH1F * QCD =(TH1F*) fout_->Get((channel+prefix+"/QCD").c_str());
    float qcd = QCD->GetBinContent(i);
    TH1F * WJets =(TH1F*) fout_->Get((channel+prefix+"/W").c_str());
    float w = WJets->GetBinContent(i);
    TH1F * ZTT =(TH1F*) fout_->Get((channel+prefix+"/ZTT").c_str());
    float ztt = ZTT->GetBinContent(i);

    if(ztt==0&&w==0&&qcd==0){
      std::cout<<signal <<" " <<signalYield <<" ALL BACKGROUNDS 0 KILLING SIGNAL BIN CONTENT"<<std::endl;
      return 1;
    }
    else
      return 0;

  }

  void qcdSyst(std::string channel, std::string prefix, std::string histo1, float corr, float unc){

	std:string chan = "mutau";
	if(channel == "eleTau")
		chan = "etau";
	
    TH1F * h1 =(TH1F*) fout_->Get((channel+prefix+"/"+histo1).c_str());
	TH1F * h2 = (TH1F*)h1->Clone(TString(histo1+std::string("_CMS_htt_QCDShape_"+chan+prefix+"_"+energy_+"Up")));
	TH1F * h3 = (TH1F*)h1->Clone(TString(histo1+std::string("_CMS_htt_QCDShape_"+chan+prefix+"_"+energy_+"Down")));
	std::cout << "Channel label is " << chan << std::endl;
	float x;
    float y;
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
  }

  void FixEmptyBinsMC(std::string folder, std::string histo, bool is_qcd, bool verbose=false){
  		
  		FixEmptyBins(folder, histo, is_qcd, verbose);
  		
  		for(unsigned int i=0;i<shifts_.size();++i) {
      		TH1F * hh =(TH1F*) fout_->Get((folder+"/"+histo+"_"+shiftsPostFix_[i]+"Up").c_str());
      		if(hh!=0) {
				FixEmptyBins(folder, (histo+"_"+shiftsPostFix_[i]+"Up").c_str(), is_qcd, verbose);
      		}

      		TH1F * hhh =(TH1F*) fout_->Get((folder+"/"+histo+"_"+shiftsPostFix_[i]+"Down").c_str());
      		if(hhh!=0) {
				FixEmptyBins(folder, (histo+"_"+shiftsPostFix_[i]+"Down").c_str(), is_qcd, verbose);
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


  void addHistogramZTT(std::string folder, std::string histo1, std::string histo2)
  {
		addHistogram(folder,histo1,histo2);
		for(unsigned int i=0;i<shifts_.size();++i) {
			addHistogram(folder,(histo1+"_"+shiftsPostFix_[i]+"Up").c_str(),histo2);
			addHistogram(folder,(histo1+"_"+shiftsPostFix_[i]+"Down").c_str(),histo2);
		}		
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

  std::pair<float,float> convertToPoisson(std::pair<float,float> measurement) {
    float yield = measurement.first;
    float CLHi = TMath::ChisquareQuantile(1-0.32/2,2*yield+2)/2.;
    float CLLo = TMath::ChisquareQuantile(0.32/2,2*yield)/2.;
    printf("Yield =%f Lo=%f Hi=%f\n",measurement.first,CLLo,CLHi);
    return std::make_pair(measurement.first,(CLHi-CLLo)/2.);

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


  void interpolate(std::string name1,std::string name2,std::string shiftFix,std::string postfix) {
    std::string sf;
    if(shiftFix.size()>0)
      sf="_"+shiftFix;
    else
      sf="";

    TH1F *f1 =(TH1F*) fout_->Get((channel_+postfix+"/ggH"+name1+sf).c_str());
    TH1F *f2 =(TH1F*) fout_->Get((channel_+postfix+"/ggH"+name2+sf).c_str());
    TH1F *f3 =(TH1F*) fout_->Get((channel_+postfix+"/qqH"+name1+sf).c_str());
    TH1F *f4 =(TH1F*) fout_->Get((channel_+postfix+"/qqH"+name2+sf).c_str());
    TH1F *f5 =(TH1F*) fout_->Get((channel_+postfix+"/VH"+name1+sf).c_str());
    TH1F *f6 =(TH1F*) fout_->Get((channel_+postfix+"/VH"+name2+sf).c_str());


      for(unsigned int j=1;j<5;++j) 
	{

	  double m1= boost::lexical_cast<double>(name1);
	  double m2= boost::lexical_cast<double>(name2);
	  int mint = boost::lexical_cast<int>(name1);


	  //interpolate yield
	  float yield1 =f1->Integral()+ (f2->Integral()-f1->Integral())*((float)(mint+j)-m1)/(m2-m1);
	  float yield2 =f3->Integral()+ (f4->Integral()-f3->Integral())*((float)(mint+j)-m1)/(m2-m1);
	  float yield3 =f5->Integral()+ (f6->Integral()-f5->Integral())*((float)(mint+j)-m1)/(m2-m1);

	  TH1F *ff1;
	  TH1F *ff2;
	  TH1F *ff3;

	  fout_->cd(TString::Format("%s",(channel_+postfix).c_str()));

	  
	  ff1 = th1fmorph(TString::Format("ggH%d%s_temp",mint+j,sf.c_str()),"",f1,f2, m1,m2,m1+(float)j,yield1,0);
	  ff2 = th1fmorph(TString::Format("qqH%d%s_temp",mint+j,sf.c_str()),"",f3,f4,m1,m2,m1+(float)j,yield2,0);
	  ff3 = th1fmorph(TString::Format("VH%d%s_temp",mint+j,sf.c_str()),"",f5,f6,m1,m2,m1+(float)j,yield3,0);

	  TH1F * fff1;
  	  if(binning_.size()==0)
	    fff1= new TH1F(TString::Format("ggH%d%s",mint+j,sf.c_str()),"",bins_,min_,max_);
	  else 
	    fff1 = new TH1F(TString::Format("ggH%d%s",mint+j,sf.c_str()),"",binning_.size()-1,&binning_[0]);
	  fff1->Sumw2();

	  TH1F * fff2;
  
	  if(binning_.size()==0)
	    fff2= new TH1F(TString::Format("qqH%d%s",mint+j,sf.c_str()),"",bins_,min_,max_);
	  else 
	    fff2 = new TH1F(TString::Format("qqH%d%s",mint+j,sf.c_str()),"",binning_.size()-1,&binning_[0]);
	  fff2->Sumw2();

	  TH1F * fff3;
  
	  if(binning_.size()==0)
	    fff3= new TH1F(TString::Format("VH%d%s",mint+j,sf.c_str()),"",bins_,min_,max_);
	  else 
	    fff3 = new TH1F(TString::Format("VH%d%s",mint+j,sf.c_str()),"",binning_.size()-1,&binning_[0]);
	  fff3->Sumw2();


	  for(int k=1;k<=ff1->GetNbinsX();++k)
	    fff1->SetBinContent(k,ff1->GetBinContent(k));

	  for(int k=1;k<=ff2->GetNbinsX();++k)
	    fff2->SetBinContent(k,ff2->GetBinContent(k));

	  for(int k=1;k<=ff3->GetNbinsX();++k)
	    fff3->SetBinContent(k,ff3->GetBinContent(k));


	  fout_->cd((channel_+postfix).c_str());
	  fff1->Write(TString::Format("ggH%d%s",mint+j,sf.c_str()));
 	  fff2->Write(TString::Format("qqH%d%s",mint+j,sf.c_str()));
 	  fff3->Write(TString::Format("VH%d%s",mint+j,sf.c_str()));
	  
	  fout_->cd();

	}

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


  void interpolateHistogramAndShifts(std::string postfix = "") {
    for(unsigned int i=0;i<smMasses_.size()-1;++i) {
	interpolate(smMasses_[i],smMasses_[i+1],"",postfix);
	printf("Nominal interpolated\n");
	for(unsigned int j=0;j<shifts_.size();++j) {
	
	    interpolate(smMasses_[i],smMasses_[i+1],shiftsPostFix_[j]+"Up",postfix);
	    interpolate(smMasses_[i],smMasses_[i+1],shiftsPostFix_[j]+"Down",postfix);

	}
    }
  }

  void interpolateHistogramsAndShiftsVH105(std::string postfix = "") {
	interpolateVH105("100","110","",postfix);
	printf("Interpolating VH105\n");
	for(unsigned int j=0;j<shifts_.size();++j) {
	
	    interpolateVH105("100","110",shiftsPostFix_[j]+"Up",postfix);
	    interpolateVH105("100","110",shiftsPostFix_[j]+"Down",postfix);

	}
  }

  void close() {
    fout_->Close();
  }


  void interpolateVH105(std::string name1,std::string name2,std::string shiftFix,std::string postfix) {
    std::string sf;
    if(shiftFix.size()>0)
      sf="_"+shiftFix;
    else
      sf="";

    TH1F *f5 =(TH1F*) fout_->Get((channel_+postfix+"/VH"+name1+sf).c_str());
    TH1F *f6 =(TH1F*) fout_->Get((channel_+postfix+"/VH"+name2+sf).c_str());



	  double m1= boost::lexical_cast<double>(name1);
	  double m2= boost::lexical_cast<double>(name2);


	if(f5!=0 && f6!=0){
	  //interpolate yield
	  float yield3 =f5->Integral()+ (f6->Integral()-f5->Integral())*5.0/(m2-m1);
	  TH1F *ff3;

	  fout_->cd(TString::Format("%s",(channel_+postfix).c_str()));

	  ff3 = th1fmorph(TString::Format("VH%d%s_temp",105,sf.c_str()),"",f5,f6,m1,m2,105,yield3,0);

	  TH1F * fff3;
  
	  if(binning_.size()==0)
	    fff3= new TH1F(TString::Format("VH%d%s",105,sf.c_str()),"",bins_,min_,max_);
	  else 
	    fff3 = new TH1F(TString::Format("VH%d%s",105,sf.c_str()),"",binning_.size()-1,&binning_[0]);
	  fff3->Sumw2();


	  for(int k=1;k<=ff3->GetNbinsX();++k)
	    fff3->SetBinContent(k,ff3->GetBinContent(k));


	  fout_->cd((channel_+postfix).c_str());
 	  fff3->Write(TString::Format("VH%d%s",105,sf.c_str()));
	  
	  fout_->cd();
	}
	else{
		std::cout << "Missing VH histogram needed for interpolation" << std::endl;
	}

  }

  void extrapolateHistogramsAndShiftsSM150(std::string postfix = "") {
	extrapolateSM150("140","145","",postfix);
	printf("Extrapolating ggH150\n");
	for(unsigned int j=0;j<shifts_.size();++j) {
	
	    extrapolateSM150("140","145",shiftsPostFix_[j]+"Up",postfix);
	    extrapolateSM150("140","145",shiftsPostFix_[j]+"Down",postfix);

	}
  }


  void extrapolateSM150(std::string name1,std::string name2,std::string shiftFix,std::string postfix) {
    std::string sf;
    if(shiftFix.size()>0)
      sf="_"+shiftFix;
    else
      sf="";

    TH1F *f5 =(TH1F*) fout_->Get((channel_+postfix+"/ggH"+name1+sf).c_str());
    TH1F *f6 =(TH1F*) fout_->Get((channel_+postfix+"/ggH"+name2+sf).c_str());



	  double m1= boost::lexical_cast<double>(name1);
	  double m2= boost::lexical_cast<double>(name2);


	if(f5!=0 && f6!=0){
	  //interpolate yield
	  float yield3 =f6->Integral()+ (f6->Integral()-f5->Integral());
	  TH1F *ff3;

	  fout_->cd(TString::Format("%s",(channel_+postfix).c_str()));

	  ff3 = th1fmorph(TString::Format("ggH%d%s_temp",150,sf.c_str()),"",f5,f6,m1,m2,150,yield3,0);

	  TH1F * fff3;
  
	  if(binning_.size()==0)
	    fff3= new TH1F(TString::Format("ggH%d%s",150,sf.c_str()),"",bins_,min_,max_);
	  else 
	    fff3 = new TH1F(TString::Format("ggH%d%s",150,sf.c_str()),"",binning_.size()-1,&binning_[0]);
	  fff3->Sumw2();


	  for(int k=1;k<=ff3->GetNbinsX();++k)
	    fff3->SetBinContent(k,ff3->GetBinContent(k));


	  fout_->cd((channel_+postfix).c_str());
 	  fff3->Write(TString::Format("ggH%d%s",150,sf.c_str()));
	  
	  fout_->cd();
	}
	else{
		std::cout << "Missing ggH histogram needed for extrapolation" << std::endl;
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
  

  float quadrature(float value, float error, float e0 = 0.0, float e1 = 0.0 ,float e2 = 0.0, float e3 = 0.0 ,float e4 = 0.0, float e5 = 0.0 ) {
    return sqrt(error*error+(e0*e0+e1*e1+e2*e2+e3*e3+e4*e4+e5*e5)*value*value);
  }

  float getYield(std::string name,std::string postFix) {
    TH1F *h = (TH1F*)fout_->Get((channel_+postFix+"/"+name).c_str());
    return h->Integral();
  }
  
  
  void copyHistogram(std::string folderSrc,std::string name,std::string folderDest) {
   if(fout_->Get(folderDest.c_str())==0)
     fout_->mkdir(folderDest.c_str());
   //check if it exists
   
   TH1F * h = (TH1F*)fout_->Get((folderSrc+"/"+name).c_str());
   if(h!=0) {
     TH1F *hC =(TH1F*) h->Clone();
     fout_->cd(folderDest.c_str());
     hC->Write();
   }
  }

  void copyHistograms(std::string folderSrc,std::string name,std::string folderDest) {
    copyHistogram(folderSrc,name,folderDest);
    for(unsigned int i=0;i<shifts_.size();++i) {
      copyHistogram(folderSrc,name+"_"+shiftsPostFix_[i]+"Up",folderDest);
      copyHistogram(folderSrc,name+"_"+shiftsPostFix_[i]+"Down",folderDest);
    }
  }

  std::pair<float,float> scaleYield(float value, float error , float factor, float factorErr) {
    float output = value*factor;
    float outputErr = sqrt(value*value*factorErr*factorErr+factor*factor*error*error);
    return std::make_pair(output,outputErr);
  }



  std::pair<float,float> makeHistogramFineBins(TTree* tree,std::string folder,std::string name,std::string cut,float scaleFactor = 1.) {
        
    if(fout_->Get(folder.c_str())==0)
      fout_->mkdir(folder.c_str());
    TH1F *h=0;
    
    //////5GeV binning!
    int bins = rintf((max_-min_)/5);
    //std::cout<<" nbints "<< bins << std::endl;

    name=name+"_fine_binning";

    h= new TH1F(name.c_str(),name.c_str(),bins,min_,max_);

    h->Sumw2();
    
    tree->Draw((variable_+">>"+name).c_str(),cut.c_str());

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
  



  std::pair<float,float> createHistogramAndShiftsFineBins(std::string file,std::string name, std::string cut,float scaleFactor = 1, std::string postfix = "",bool normUC  = true, bool keys=false,bool ShapeUncertainty=true) {
    TFile *f  = new TFile(file.c_str());
    if(f==0) printf("No file Found\n");
    //get the nominal tree first
    TTree *t= (TTree*)f->Get((channel_+"EventTree/eventTree").c_str());
    if(t==0) printf("No Tree Found in file %s\n",file.c_str());

    std::pair<float,float> yield;

    yield =makeHistogramFineBins(t,channel_+postfix,name,cut,scaleFactor);

    f->Close();
    return yield;
  }

  std::pair<float,float> createHistogramAndShiftsFinalFineBins(std::string file,std::string name, std::string cut,float scaleFactor = 1, std::string postfix = "",bool normUC  = true, bool keys=false,bool ShapeUncertainty=true) {
    TFile *f  = new TFile(file.c_str());
    if(f==0) printf("No file Found\n");
    //get the nominal tree first
    TTree *t= (TTree*)f->Get((channel_+"EventTreeFinal/eventTree").c_str());
    if(t==0) printf("No Tree Found in file %s\n",file.c_str());

    std::pair<float,float> yield;

    yield =makeHistogramFineBins(t,channel_+postfix,name,cut,scaleFactor);

    f->Close();
    return yield;
  }

  void qcdSystWithLimits(std::string folder, std::string prefix, std::string histo1, float scale = 1, float Unc = 1 , float min=0, float max=60, bool finebinning = false){
    ////////
    TH1F * h1 =(TH1F*) fout_->Get((folder+"/"+histo1).c_str());

    std::string chan = "mutau";
    if(channel_=="eleTau") chan = "etau";

    TString histoUp= TString(histo1+std::string("_CMS_htt_QCDShape_"+chan+prefix+"_"+energy_+"Up"));
    TString histoDown = TString(histo1+std::string("_CMS_htt_QCDShape_"+chan+prefix+"_"+energy_+"Down"));
    
    if(finebinning){
      TString histoUp= TString(std::string("QCD_CMS_htt_QCDShape_"+chan+prefix+"_"+energy_+"Up_fine_binning"));
      TString histoDown = TString(std::string("QCD_CMS_htt_QCDShape_"+chan+prefix+"_"+energy_+"Down_fine_binning"));
    printf("FINE BINNING NAMES \n");
    std::cout<<"QCD_CMS_htt_QCDShape_"<<chan<<prefix<<"_"<<energy_<<"Down_fine_binning"<<std::endl;
    }

    TH1F * h2 = (TH1F*)h1->Clone(histoUp);
    TH1F * h3 = (TH1F*)h1->Clone(histoDown);
    
    printf("Creating QCD Shape Systematic \n");

    int maxbinscale = h1->FindBin(max); /// find the bin corresponding to 60GeV 
    int minbinscale = h1->FindBin(min);

    float yield = h1->Integral();
    ////first the primary bins
    int y =0; 
    for(int i=1;i<maxbinscale;++i){
      if(i>=minbinscale){
	y = h1->GetBinContent(i);
	h1->SetBinContent(i,y*scale);
      }
    }

    ////next the syst uncertainties
    y=0;
    for(int i=1;i<maxbinscale;++i){
      if(i>=minbinscale){
	y = h1->GetBinContent(i);
	h2->SetBinContent(i,y*(1.1));
	h3->SetBinContent(i,y*(0.9));
      }
    }

    h1->Scale(yield/h1->Integral());
    h2->Scale(yield/h2->Integral());
    h3->Scale(yield/h3->Integral());

    h1->Write(h1->GetName(),TObject::kOverwrite);
    h2->Write(h2->GetName(),TObject::kOverwrite);
    h3->Write(h3->GetName(),TObject::kOverwrite);        
  }

  void qcdSystFine(std::string folder, std::string prefix, std::string histo1, float scale = 1, float Unc = 1 , float min=0, float max=60, bool finebinning = false){
    ////////
    TH1F * h1 =(TH1F*) fout_->Get((folder+"/"+histo1).c_str());


    std::string chan = "mutau";
    if(channel_=="eleTau") chan = "etau";


    TString histoUp= TString(std::string("QCD_CMS_htt_QCDShape_"+chan+prefix+"_"+energy_+"Up_fine_binning"));
    TString histoDown = TString(std::string("QCD_CMS_htt_QCDShape_"+chan+prefix+"_"+energy_+"Down_fine_binning"));
    printf("FINE BINNING NAMES \n");
    std::cout<<"QCD_CMS_htt_QCDShape_"<<chan<<prefix<<"_"<<energy_<<"Down_fine_binning"<<std::endl;
    

    TH1F * h2 = (TH1F*)h1->Clone(histoUp);
    TH1F * h3 = (TH1F*)h1->Clone(histoDown);
    
    printf("Creating QCD Shape Systematic \n");

    int maxbinscale = h1->FindBin(max); /// find the bin corresponding to 60GeV 
    int minbinscale = h1->FindBin(min);

    float yield = h1->Integral();
    ////first the primary bins
    int y =0; 
    for(int i=1;i<maxbinscale;++i){
      if(i>=minbinscale){
	y = h1->GetBinContent(i);
	h1->SetBinContent(i,y*scale);
      }
    }

    ////next the syst uncertainties
    y=0;
    for(int i=1;i<maxbinscale;++i){
      if(i>=minbinscale){
	y = h1->GetBinContent(i);
	h2->SetBinContent(i,y*(1.1));
	h3->SetBinContent(i,y*(0.9));
      }
    }
    h1->Scale(yield/h1->Integral());
    h2->Scale(yield/h2->Integral());
    h3->Scale(yield/h3->Integral());

    h1->Write(h1->GetName(),TObject::kOverwrite);
    h2->Write(h2->GetName(),TObject::kOverwrite);
    h3->Write(h3->GetName(),TObject::kOverwrite);        
  }




  void printSignalEfficiency() {
    for(unsigned int i=0;i<mssmMasses_.size();++i) {
      //    printf("InclusiveGGH%s = %f\n",mssmMasses_[i].c_str(),getYield("GGH"+mssmMasses_[i],"_X")/((1-mssmBBFraction_[i])*luminosity_));
      //    printf("InclusiveBBH%s = %f\n",mssmMasses_[i].c_str(),getYield("BBH"+mssmMasses_[i],"_X")/((mssmBBFraction_[i])*luminosity_));

    printf("NoB  GGH%s = %f\n",mssmMasses_[i].c_str(),(getYield("GGHNoJet"+mssmMasses_[i],"_NoB")+getYield("GGHJet"+mssmMasses_[i],"_NoB"))/((1-mssmBBFraction_[i])*luminosity_));
    printf("NoB  BBH%s = %f\n",mssmMasses_[i].c_str(),(getYield("BBHNoJet"+mssmMasses_[i],"_NoB")+getYield("BBHJet"+mssmMasses_[i],"_NoB")+getYield("BBHBJet"+mssmMasses_[i],"_NoB"))/((mssmBBFraction_[i])*luminosity_));

    printf("B  GGH%s = %f\n",mssmMasses_[i].c_str(),(getYield("GGH"+mssmMasses_[i],"_B")+getYield("GGH"+mssmMasses_[i],"_B"))/((1-mssmBBFraction_[i])*luminosity_));
    printf("B  BBH%s = %f\n",mssmMasses_[i].c_str(),(getYield("BBH"+mssmMasses_[i],"_B")+getYield("BBH"+mssmMasses_[i],"_B"))/((mssmBBFraction_[i])*luminosity_));

  }

    //    printf("Standard Model-----------------------------\n");
    //  for(unsigned int i=0;i<smMasses_.size();++i) {
    //    printf("Inclusive GGH%s = %f\n",smMasses_[i].c_str(),getYield("SM"+smMasses_[i],"_X")/((smSigma_[i])*luminosity_));
    //    printf("Inclusive qqH%s = %f\n",smMasses_[i].c_str(),getYield("qqH"+smMasses_[i],"_X")/((qqHSigma_[i])*luminosity_));


    //    printf("No VBF GGH%s = %f\n",smMasses_[i].c_str(),getYield("SM"+smMasses_[i],"_SM0")/((smSigma_[i])*luminosity_));
    //    printf("No VBF VBF%s = %f\n",smMasses_[i].c_str(),getYield("qqH"+smMasses_[i],"_SM0")/((vbfSigma_[i])*luminosity_));
    //
    //    printf("VBF GGH%s = %f\n",smMasses_[i].c_str(),getYield("SM"+smMasses_[i],"_SM2")/((smSigma_[i])*luminosity_));
    //    printf(" VBF VBF%s = %f\n",smMasses_[i].c_str(),getYield("VBF"+smMasses_[i],"_SM2")/((vbfSigma_[i])*luminosity_));
    //  }
}



  void setBinning(const std::vector<double>& binning) {
    binning_ = binning;
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
  std::string vbfTightS_;
  std::string genTauReject_;
  std::string genTauSel_;
  std::string genLReject_;
  std::string genLSel_;
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




