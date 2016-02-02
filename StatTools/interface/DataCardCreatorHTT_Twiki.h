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
	float QCD, dQCD;
	float ZLFT, dZLFT;
	float ZJFT, dZJFT;
	float TOP, dTOP;
	float VV, dVV;
	float ZTT, dZTT;

	BkgOutput(){};

	BkgOutput(float i) {
		// This assumes that a-d are all of the same type and all in order
		std::fill(&DATA, &dZTT+1, i);
	}

};



class DataCardCreatorHTT_Twiki {
	public:

		DataCardCreatorHTT_Twiki(optutl::CommandLineParser parser) {
			channel_ = parser.stringValue("channel");
			shifts_  = parser.stringVector("shifts");
			energy_ = parser.stringValue("energy");
			samesign_ = parser.doubleValue("samesign");


                        std::string name_=channel_;
                        if (channel_=="eleTau") filelabel_="et";
                        if (channel_=="muTau") filelabel_="mt";


			//create the name you need to add to the histograms 
			//in the root file 
			for(unsigned int i=0;i<shifts_.size();++i) {
				std::string shiftL = shifts_.at(i);
				shiftL.resize(1);
				boost::to_lower(shiftL);
				std::cout<<"shiftL: "<<shiftL<<std::endl;
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
			qcdFile_  = parser.stringValue("qcdFile");
			dataFile_  = parser.stringValue("dataFile");

			//read control and signal regions
			preSelection_ = parser.stringValue("preselection");
			inclSelection_ = parser.stringValue("inclSelection");

			signalSelection_      = parser.stringValue("signalSelection");
			wSelection_           = parser.stringValue("wSelection");
			qcdSelection_         = parser.stringValue("qcdSelection");
			relaxedSelection_     = parser.stringValue("relaxedSelection");
			bSelection_           = parser.stringValue("bSelection");
			antibSelection_       = parser.stringValue("antibSelection");
			btagRelaxedSelection_ = parser.stringValue("btagRelaxedSelection");
			trigSelection_        = parser.stringValue("trigSelection");
			trigSelection50ns_        = parser.stringValue("trigSelection50ns");
			trigSelection25ns_        = parser.stringValue("trigSelection25ns");
			blinding_             = parser.stringValue("blinding");
			charge_               = parser.stringValue("charge");
                        if (samesign_) charge_="abs(charge)==2";
   
                  
			//ZTT_genTauSel_        = "(genVisPt1>18&&genTaus>1&&genVisPt2>18&&!((abs(pdg2)==13||abs(pdg2)==11)&&genPt2>8))"; //Zttyield
			//ZTT_genTauSel_        = "pt_1>18"; //Zttyield
			ZTT_genTauSel_        = "isTauDecay1>0"; //Zttyield
			ZLFT_genLSel_         = "isTauDecay1==0&&(abs(pdg2)==11||abs(pdg2)==13)"; //Zttyield
			//ZLFT_genLSel_         = "isTauDecay==0&&(isPrompt>0||isPromptFS>0)&&genPt2>8&&(abs(pdg2)==11||abs(pdg2)==13)"; //Zttyield
			ZJFT_genLReject_        = "isTauDecay1==0&&!(abs(pdg2)==11||abs(pdg2)==13)"; //Zttyield
			//ZTTLL_genTauReject_   = "(genVisPt1>18&&genTaus>1&&((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))"; /// zTT_LL
			//ZJFT_genLReject_      = "(!((genTaus==0&&abs(pdg2)==13&&genPt2>8)||(genTaus==0&&abs(pdg2)==11&&genPt2>8)||(genTaus>0&&genVisPt2>18)))"; //ZJ
			//ZLFT_genLSel_         = "(genTaus==0&&((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))";///zl

			//
			if(samesign_>0)
			  osSignalSelection_    = signalSelection_+"&&abs(charge)==2";
			else
			  osSignalSelection_    = signalSelection_+"&&charge==0";

			ssSignalSelection_    = signalSelection_+"&&abs(charge)==2";
			if(samesign_>0)
			  osWSelection_         = wSelection_+"&&abs(charge)==2";
			else
			  osWSelection_         = wSelection_+"&&charge==0";

			ssWSelection_         = wSelection_+"&&abs(charge)==2";
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
			qcdErr_     = parser.doubleValue("qcdErr");
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

			scaleUp_ = parser.doubleValue("scaleUp");

			fout_ = new TFile(parser.stringValue("outputfile").c_str(),"RECREATE");

		}


		void makeHiggsShape(std::string preselection, std::string categoryselection, std::string prefix) {

			std::pair<float,float> tmp;
			float legCorr=1.0;

			if(muID_!=0&&eleID_!=0) {legCorr*=muID_*eleID_;}
			if(muID_!=0&&eleID_==0) {legCorr*=muID_*tauID_;}
			if(muID_==0&&eleID_!=0) {legCorr*=eleID_*tauID_;}
                        std::cout<<"Make Higgs Shape"<<std::endl;
			tmp= createHistogramAndShifts(dir_+"ggH125.root","ggH125",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"vbfH125.root","qqH125",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
                        std::cout<<"susyggH"<<std::endl;
			tmp= createHistogramAndShifts(dir_+"susyggH_80.root","ggH80",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susyggH_90.root","ggH90",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susyggH_100.root","ggH100",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susyggH_110.root","ggH110",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susyggH_120.root","ggH120",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susyggH_130.root","ggH130",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susyggH_140.root","ggH140",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susyggH_160.root","ggH160",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susyggH_180.root","ggH180",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susyggH_200.root","ggH200",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susyggH_250.root","ggH250",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susyggH_400.root","ggH400",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susyggH_450.root","ggH450",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susyggH_500.root","ggH500",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susyggH_600.root","ggH600",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susyggH_700.root","ggH700",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susyggH_800.root","ggH800",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susyggH_900.root","ggH900",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susyggH_1000.root","ggH1000",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susyggH_1200.root","ggH1200",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susyggH_1400.root","ggH1400",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susyggH_1500.root","ggH1500",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susyggH_1600.root","ggH1600",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susyggH_1800.root","ggH1800",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susyggH_2000.root","ggH2000",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susyggH_2300.root","ggH2300",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susyggH_2600.root","ggH2600",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susyggH_2900.root","ggH2900",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susyggH_3200.root","ggH3200",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);


                        std::cout<<"susybbH"<<std::endl;

			tmp= createHistogramAndShifts(dir_+"susybbH_80.root","bbH80",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susybbH_90.root","bbH90",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susybbH_100.root","bbH100",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susybbH_110.root","bbH110",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susybbH_120.root","bbH120",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susybbH_130.root","bbH130",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susybbH_140.root","bbH140",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susybbH_160.root","bbH160",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susybbH_180.root","bbH180",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			//tmp= createHistogramAndShifts(dir_+"susybbH_200.root","bbH200",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susybbH_250.root","bbH250",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susybbH_300.root","bbH300",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susybbH_350.root","bbH350",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susybbH_400.root","bbH400",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susybbH_450.root","bbH450",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susybbH_500.root","bbH500",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susybbH_600.root","bbH600",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susybbH_700.root","bbH700",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			//tmp= createHistogramAndShifts(dir_+"susybbH_800.root","bbH800",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susybbH_900.root","bbH900",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susybbH_1000.root","bbH1000",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susybbH_1200.root","bbH1200",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			//tmp= createHistogramAndShifts(dir_+"susybbH_1400.root","bbH1400",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susybbH_1500.root","bbH1500",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susybbH_1600.root","bbH1600",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susybbH_1800.root","bbH1800",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susybbH_2000.root","bbH2000",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			//tmp= createHistogramAndShifts(dir_+"susybbH_2300.root","bbH2300",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susybbH_2600.root","bbH2600",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susybbH_2900.root","bbH2900",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);
			tmp= createHistogramAndShifts(dir_+"susybbH_3200.root","bbH3200",("("+preselection+"&&"+categoryselection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*legCorr,prefix);



                        std::cout<<"Made Higgs Shape"<<std::endl;
		}


		/*-------------Create Histograms------------------*/

		BkgOutput runOSLSMT(std::string preSelection,std::string prefix,std::string zShape, float topExtrap) {
                        std::cout<<"runOSLSMT"<<std::endl;

			BkgOutput output(0);    

			float leg1Corr=1.0;
			if(muID_!=0) leg1Corr*=muID_;
			if(eleID_!=0) leg1Corr*=eleID_;

			printf("Tau ID Scale Factor is %.3f \n",tauID_);

                        std::cout<<"Create Data"<<std::endl;
			std::cout<<"      Data Selection: "<<preSelection<<"&&"<<osSignalSelection_<<std::endl;


			std::pair<float,float> dataY         = createHistogramAndShifts(dataFile_,"data_obs","("+preSelection+"&&"+trigSelection50ns_+"&&"+osSignalSelection_+"&&"+blinding_+")",scaleUp_,prefix);
			output.DATA = dataY.first;


                        std::cout<<"Create Top"<<std::endl;
			//Create ttbar
			std::pair<float,float> topYield      = createHistogramAndShifts(topFile_,"TT",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*leg1Corr*tauID_*topExtrap,prefix);
			std::pair<float,float> topInflYield  = inflateError(topYield,topErr_);
			printf("      TTbar events in signal region = %f + %f \n",topInflYield.first,topInflYield.second);
			output.TOP  = topInflYield.first;
			output.dTOP = topInflYield.second;

                        std::cout<<"Create VV"<<std::endl;
			//Create Diboson
			std::pair<float,float> vvYield      = createHistogramAndShifts(vvFile_,"VV",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+")*"+weight_),luminosity_*leg1Corr*tauID_,prefix);
			printf("      Diboson events before inflation = %f + %f \n",vvYield.first,vvYield.second);
			std::pair<float,float> vvInflYield  = inflateError(vvYield,vvErr_);
			printf("      Diboson events in signal region = %f + %f \n",vvInflYield.first,vvInflYield.second);
			output.VV  = vvInflYield.first;
			output.dVV = vvInflYield.second;


                        std::cout<<"Create ZLFT"<<std::endl;
                        std::cout<<"      Factor ZLFT: "<<zlftFactor_<<std::endl;
			//Create ZL and ZJ
			std::pair<float,float> zlftYield   = createHistogramAndShifts(zllFile_,"ZL",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+ZLFT_genLSel_+")*"+weight_),luminosity_*leg1Corr*zlftFactor_*zttScale_,prefix,false);
			//std::pair<float,float> zlftYield   = createHistogramAndShifts(zllFile_,"ZL",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&genTaus==0&&((abs(pdg2)==13&&genPt2>8)||(abs(pdg2)==11&&genPt2>8)))*"+weight_),luminosity_*leg1Corr*zlftFactor_*zttScale_,prefix,false);
			std::pair<float,float> zlftInflYield  = inflateError(zlftYield,zlftErr_);
			printf("      Z (l->tau) in signal region = %f + %f \n",zlftInflYield.first,zlftInflYield.second);
			output.ZLFT  = zlftInflYield.first;
			output.dZLFT = zlftInflYield.second;


                        std::cout<<"Create ZJFT"<<std::endl;
			std::pair<float,float> zjftYield      = createHistogramAndShifts(zllFile_,"ZJ",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+ZJFT_genLReject_+")*"+weight_),luminosity_*leg1Corr*zttScale_,prefix);    
			//std::pair<float,float> zjftYield      = createHistogramAndShifts(zllFile_,"ZJ",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&(!((genTaus==0&&abs(pdg2)==13&&genPt2>8)||(genTaus==0&&abs(pdg2)==11&&genPt2>8)||(genTaus>0&&genVisPt2>18))))*"+weight_),luminosity_*leg1Corr*zttScale_,prefix);    
			std::pair<float,float> zjftInflYield  = inflateError(zjftYield,zjftErr_);
			printf("      Z (j->tau) in signal region = %f + %f \n",zjftInflYield.first,zjftInflYield.second);
			output.ZJFT  = zjftInflYield.first;
			output.dZJFT = zjftInflYield.second;

                        std::cout<<"Create ZTT"<<std::endl;
			//Create Z-->tautau
			if(!runZTT(preSelection, prefix, zShape, topExtrap, output,inclSelection_)){
				std::cout<<"Error Creating Ztt"<<std::endl;
				return output;
			}


			//Create W 
			//In principle osSignalSelection should work as a dummy variable
			std::cout<<"Create W"<<std::endl;
			if(!runW(preSelection, prefix, zShape, topExtrap, output, "pt_1>-100", "pt_1>-100",wSelection_)){
				std::cout<<"Error Creating W"<<std::endl;
				return output;
			}

                        std::cout<<"Create QCD"<<std::endl;
			//Create QCD
			if(!runQCD(preSelection, prefix, zShape, topExtrap, output, "pt_1>-100", relaxedSelection_)){
				std::cout<<"Error Creating QCD"<<std::endl;
				return output;
			}


			std::cout<<"=============Data Yields============="<<std::endl;
			std::cout<<"DATA: "<< output.DATA<<std::endl;
			std::cout<<std::endl;
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
			fout_->cd((filelabel_+prefix).c_str());
			err->Write();

			return output;      
		}

		/*
		 * Run the full extrapolation in the Btag category
		 * Needed: BtagSF, categorySelection
		 *
		 */

		BkgOutput runFullExtrapBtag(std::string relaxedSelection, std::string wSel, std::string preSelection, std::string categorySelection_, std::string prefix, std::string zShape, float topExtrap, float zExtrap, float zExtrapErr, std::string bTagSF) {

			std::cout<<"======================"<<std::endl;
                        std::cout<<"Run Full Extrapolation"<<std::endl;
			std::cout<<"categorySelection: "<<categorySelection_<<std::endl;
			//TODO: Fix this category seleciton business, should be more elegant
			std::string categorySelection = categorySelection_;
			std::string dummySelection_   = osSignalSelection_;

			weight_ = weight_+"*"+bTagSF;

			BkgOutput output;    

			float leg1Corr=1.0;
			if(muID_!=0) leg1Corr*=muID_;
			if(eleID_!=0) leg1Corr*=eleID_;

			printf("Tau ID Scale Factor is %.3f \n",tauID_);

			std::cout<<"Select DATA"<<std::endl;
			std::pair<float,float> dataY         = createHistogramAndShifts(dataFile_,"data_obs","("+preSelection+"&&"+trigSelection50ns_+"&&"+osSignalSelection_+"&&"+categorySelection+")",scaleUp_,prefix);
			//std::pair<float,float> dataY         = createHistogramAndShifts(dataFile_,"data_obs","("+preSelection+"&&"+osSignalSelection_+"&&"+categorySelection+")",scaleUp_,prefix);
			output.DATA = dataY.first;
			std::cout<<"      DATA Yield: "<< output.DATA<<std::endl;



                        std::cout<<"Create DiBoson"<<std::endl;
			//Create Diboson
			//stopped here!
			std::pair<float,float> vvYield      = createHistogramAndShifts(vvFile_,"VV",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+")*"+weight_),luminosity_*leg1Corr*tauID_,prefix);
			std::cout<<"      VV before error inflation: "<<vvYield.first<<std::endl;
			std::pair<float,float> vvInflYield  = inflateError(vvYield,vvErr_);
			printf("      Diboson events in signal region = %f + %f \n",vvInflYield.first,vvInflYield.second);
			std::cout<<"      VV after error inflation: "<<vvInflYield.first<<std::endl;
			output.VV  = vvInflYield.first;
			output.dVV = vvInflYield.second;

			//Create ZL and ZJ

                        std::cout<<"Create ZLFT"<<std::endl;
			//ZL Yield
			std::pair<float,float> zlftYield   = createHistogramAndShifts(zllFile_,"ZLTmp",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection_+"&&"+ZLFT_genLSel_+")*"+weight_),luminosity_*leg1Corr*zlftFactor_*zttScale_,prefix,false);
			//ZLShape
			std::pair<float,float> zlftShape   = createHistogramAndShifts(zllFile_,"ZL",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+relaxedSelection+"&&"+ZLFT_genLSel_+")*"+weight_),luminosity_*leg1Corr*zlftFactor_*zttScale_,prefix,false);

			std::pair<float,float> zlftInflYield  = inflateError(zlftYield,zlftErr_);
			printf("      Z (l->tau) in signal region = %f + %f \n",zlftInflYield.first,zlftInflYield.second);

			renormalizeHistogram(filelabel_+prefix,"ZL",zlftInflYield.first);
			output.ZLFT  = zlftInflYield.first;
			output.dZLFT  = zlftInflYield.second;

			if(shifts_.size()>0&&channel_=="eleTau"){
				std::pair<float,float> zlShiftUp      = createHistogramShifted(zllFile_,"ZL_CMS_htt_ZLScale_etau_13TeVUp",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection_+"&&abs(pdg2)==11&&"+ZLFT_genLSel_+")*"+weight_),"1.02",luminosity_*leg1Corr*zlftFactor_*zttScale_*zExtrap,prefix);
				std::pair<float,float> zlShiftDown     = createHistogramShifted(zllFile_,"ZL_CMS_htt_ZLScale_etau_13TeVDown",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection_+"&&abs(pdg2)==11"+ZLFT_genLSel_+")*"+weight_),"0.98",luminosity_*leg1Corr*zlftFactor_*zttScale_*zExtrap,prefix);
			}
			else if(shifts_.size()>0&&channel_=="muTau"){
				std::pair<float,float> zlShiftUp      = createHistogramShifted(zllFile_,"ZL_CMS_htt_ZLScale_mutau_13TeVUp",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection_+"&&abs(pdg2)==13&&"+ZLFT_genLSel_+")*"+weight_),"1.02",luminosity_*leg1Corr*zlftFactor_*zttScale_*zExtrap,prefix);
				std::pair<float,float> zlShiftDown     = createHistogramShifted(zllFile_,"ZL_CMS_htt_ZLScale_mutau_13TeVDown",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection_+"&&abs(pdg2)==13&&"+ZLFT_genLSel_+")*"+weight_),"0.98",luminosity_*leg1Corr*zlftFactor_*zttScale_*zExtrap,prefix);
			}

                        std::cout<<"Create ZJFT"<<std::endl;
			//ZJ Yield
			std::pair<float,float> zjftYield      = createHistogramAndShifts(zllFile_,"ZJTmp",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection_+"&&"+ZJFT_genLReject_+")*"+weight_),luminosity_*leg1Corr*zttScale_,prefix);    

			//ZJ Shape
			std::pair<float,float> zjftShape      = createHistogramAndShifts(zllFile_,"ZJ",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+relaxedSelection+"&&"+ZJFT_genLReject_+")*"+weight_),luminosity_*leg1Corr*zttScale_,prefix);    

			std::pair<float,float> zjftInflYield  = inflateError(zjftYield,zjftErr_);
			printf("      Z (j->tau) in signal region = %f + %f \n",zjftInflYield.first,zjftInflYield.second);
			renormalizeHistogram(filelabel_+prefix,"ZJ",zjftInflYield.first);
			output.ZJFT  = zjftInflYield.first;
			output.dZJFT = zjftInflYield.second;

                        std::cout<<"Create ZTT"<<std::endl;
			//TODO: Check me, previous Btag ZTT shape correction had a special normalization method
			if(!runZTT(preSelection, prefix, zShape, topExtrap, output, categorySelection)){
				std::cout<<"Error Creating Ztt"<<std::endl;
				return output;
			}

                        std::cout<<"Create TOP"<<std::endl;
			//Create ttbar
			//Last argument is a dummy argument
			if(!runTOP(preSelection, prefix, zShape, topExtrap, output, categorySelection, relaxedSelection)){
				std::cout<<"Error Creating TOP"<<std::endl;
				return output;
			}


                        std::cout<<"Create W"<<std::endl;
			//Create W
			if(!runW(preSelection, prefix, zShape, topExtrap, output, categorySelection, relaxedSelection, wSel)){
				std::cout<<"Error Creating W"<<std::endl;
				return output;
			}

                        std::cout<<"Create QCD"<<std::endl;
			//Create QCD
			if(!runQCD(preSelection, prefix, zShape, topExtrap, output, categorySelection, relaxedSelection)){
				std::cout<<"Error Creating QCD"<<std::endl;
				return output;
			}



			std::cout<<std::endl;
			std::cout<<"=============Data Yields============="<<std::endl;
			std::cout<<"DATA: "<< output.DATA<<std::endl;
			std::cout<<std::endl;
	

			std::cout<<std::endl;
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
			fout_->cd((filelabel_+prefix).c_str());
			err->Write();

			return output;

		}


		/*
		 * For Inclusive take the Ztt normalization directly from MC (zttFile_)
		 * For a category the Ztt normalization is as follows,
		 * ZttCategoryYield = ZttMCInclusiveYield * (ZttEmbedded_Category) / *Ztt(
		 */

		bool runZTT(std::string preSelection,std::string prefix,std::string zShape, float topExtrap, BkgOutput &output,
				std::string categorySelection = "pt_1>-100", std::string relaxedSelection = "pt_1>-100"){

			float leg1Corr=1.0;
			if(muID_!=0) leg1Corr*=muID_;
			if(eleID_!=0) leg1Corr*=eleID_;


			std::pair<float,float> ztt  = createHistogramAndShifts(zttFile_,"ZTT",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+"&&"+ZTT_genTauSel_+")*"+weight_),luminosity_*zttScale_*leg1Corr*tauID_,prefix);

			std::cout<<"      ZTT Selection: "<<preSelection<<"&&"<<trigSelection_<<"&&"<<osSignalSelection_<<"&&"<<categorySelection<<std::endl;
			output.ZTT  = ztt.first;
			output.dZTT = ztt.second;

			printf("      Selection ZTT events in signal region = %f + %f \n",ztt.first,ztt.second);
			return true;
		}


		bool runTOP( std::string preSelection, std::string prefix, std::string zShape, float topExtrap, BkgOutput &output, 
				std::string categorySelection, std::string relaxedSelection ) {


			float leg1Corr=1.0;
			if(muID_!=0) leg1Corr*=muID_;
			if(eleID_!=0) leg1Corr*=eleID_;

			std::pair<float,float> topShape      = createHistogramAndShifts(topFile_,"TT",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+")*"+weight_), luminosity_*leg1Corr*tauID_*topExtrap, prefix);

			std::pair<float,float> topYield      = createHistogramAndShifts(topFile_,"TTYield",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+")*"+weight_), luminosity_*leg1Corr*tauID_*topExtrap, prefix);

			//renormalizeHistogram(filelabel_+prefix,"TT",topYield.first);

			std::pair<float,float> topInflYield  = inflateError(topYield,topErr_);

			output.TOP  = topInflYield.first;
			output.dTOP = topInflYield.second;

			//Subtract the ztt ttbar overlap of 1.5% from the ttbar yield
			//not used for 2014 MSSM
			//output.TOP = output.TOP-(output.ZTT*0.015);   //only for  
			renormalizeHistogram(filelabel_+prefix,"TT",output.TOP);

			printf("      TTbar events in signal region = %f + %f \n",topInflYield.first,topInflYield.second);

			return true;}
		



		bool runQCD(std::string preSelection, std::string prefix, std::string zShape, float topExtrap, BkgOutput &output, std::string categorySelection, std::string relaxedSelection) 
		{
			float leg1Corr=1.0;
			if(muID_!=0) leg1Corr*=muID_;
			if(eleID_!=0) leg1Corr*=eleID_;



			std::pair<float,float> dataQCD = createHistogramAndShifts(dataFile_,"QCD","("+preSelection_+"&&"+trigSelection50ns_+"&&"+ssSignalSelection_+"&&"+categorySelection+")",scaleUp_,prefix); 
			printf("      Data events in SS Signal QCD sideband region = %f + %f \n",dataQCD.first,dataQCD.second);
			std::pair<float,float> ZQCD = createHistogramAndShifts(zttFile_,"ZQCD","("+preSelection_+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+categorySelection+")*"+weight_,luminosity_,prefix); 
			printf("      Z events in SS Signal QCD sideband region = %f + %f \n",ZQCD.first,ZQCD.second);
			std::pair<float,float> TopQCD = createHistogramAndShifts(topFile_,"TopQCD","("+preSelection_+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+categorySelection+")*"+weight_,luminosity_,prefix); 
			printf("      TOP events in SS Signal QCD sideband region = %f + %f \n",TopQCD.first,TopQCD.second);
			std::pair<float,float> VVQCD       = createHistogramAndShifts(vvFile_,"VVQCD",("("+preSelection_+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+categorySelection+")*"+weight_),luminosity_,prefix,false);
			printf("      VV events in SS Signal QCD sideband region = %f + %f \n",VVQCD.first,VVQCD.second);

			std::pair<float,float> ssWLow       = createHistogramAndShifts(wFile_,"WQCD",("("+preSelection_+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+categorySelection+")*"+weight_),luminosity_*leg1Corr,prefix,false);
			printf("      (MonteCarlo) W events in SS region = %f + %f \n",ssWLow.first,ssWLow.second);

			//Now subtracting off bkgd shapes from data ss shape
			subtractHistogram(filelabel_+prefix,"QCD","ZQCD");
			subtractHistogram(filelabel_+prefix,"QCD","VVQCD");
			subtractHistogram(filelabel_+prefix,"QCD","TopQCD");
			subtractHistogram(filelabel_+prefix,"QCD","WQCD");

                        std::pair<float,float> ssQCD = std::make_pair(TMath::Nint(dataQCD.first
                                                -ssWLow.first
                                                -TopQCD.first
                                                -VVQCD.first
                                                -ZQCD.first),
                                        sqrt(dataQCD.second*dataQCD.second
                                                +ssWLow.second*ssWLow.second
                                                +TopQCD.second*TopQCD.second
                                                +VVQCD.second*VVQCD.second
                                                +ZQCD.second*ZQCD.second));


			if(ssQCD.first<0) {
				ssQCD.first=0.0000001;
				ssQCD.second=1.8;
			}

			printf("SS QCD in  core  =%f -%f -%f -%f -%f= %f +- %f \n",
					dataQCD.first,
					ssWLow.first,
					TopQCD.first,
					ZQCD.first,
					VVQCD.first,
					ssQCD.first,
					ssQCD.second);


			printf("5. Extrapolate SS QCD -> OS QCD \n");
			std::pair<float,float> osQCD = std::make_pair(ssQCD.first*qcdFactor_,
					sqrt(ssQCD.second*ssQCD.second*qcdFactor_*qcdFactor_
						+qcdFactorErr_*qcdFactorErr_*ssQCD.first*ssQCD.first));

			//Now Renormalize
			renormalizeHistogram(filelabel_+prefix,"QCD",osQCD.first);

			printf("OS QCD in  core  =%f *%f = %f +- %f \n",ssQCD.first,qcdFactor_,osQCD.first,osQCD.second);

			output.QCD  = osQCD.first;    
			output.dQCD = osQCD.second;

			if(shifts_.size()>0){
				qcdSyst(filelabel_, prefix, "QCD", 1.1, 0.1);
			}

			return true;


/*
			std::pair<float,float> wShapeSS       = createHistogramAndShifts(wFile_,"WQCD",("("+qcdSelection_+"&&"+trigSelection_+"&&"+ssSignalSelection_+"&&"+relaxedSelection+")*"+weight_),luminosity_*leg1Corr,prefix,false);

			//create same sign W side band yields
			std::pair<float,float> dataSSYSdb = createHistogramAndShifts(dataFile_,"data_obs_ss_sdb","("+preSelection+"&&"+trigSelection50ns_+"&&"+ssWSelection_+"&&"+categorySelection+")",scaleUp_,prefix);
			std::pair<float,float> dataSSYieldSdb = convertToPoisson(dataSSYSdb);

			printf("Data events in SS W sideband region = %f + %f \n",dataSSYieldSdb.first,dataSSYieldSdb.second);

			std::pair<float,float> topSSYieldSdb    = createHistogramAndShifts(topFile_,"TTSS_SDB",("("+preSelection+"&&"+trigSelection_+"&&"+ssWSelection_+"&&"+categorySelection+")*"+weight_),luminosity_*leg1Corr*tauID_*topExtrap,prefix);
			std::pair<float,float> topInflSSYieldSdb  = inflateError(topSSYieldSdb,topErr_);
			printf("TTbar events in SS W sideband region = %f + %f \n",topSSYieldSdb.first,topInflSSYieldSdb.second);

			std::pair<float,float> zSSYieldSdb    = createHistogramAndShifts(zllFile_,"ZSS_SDB",("("+preSelection+"&&"+trigSelection_+"&&"+ssWSelection_+"&&"+categorySelection+")*"+weight_),luminosity_*leg1Corr*tauID_,prefix);      
			printf("Z events in SS sideband region = %f + %f \n",zSSYieldSdb.first,zSSYieldSdb.second);

			std::pair<float,float> vvSSYieldSdb   = createHistogramAndShifts(vvFile_,"VVSS_SDB",("("+preSelection+"&&"+trigSelection_+"&&"+ssWSelection_+"&&"+categorySelection+")*"+weight_),luminosity_*leg1Corr*tauID_,prefix);
			printf("VV events in SS sideband region = %f + %f \n",vvSSYieldSdb.first,vvSSYieldSdb.second);

			//std::pair<float,float> wFactor = extractWFactor(wFile_,preSelection+"&&"+trigSelection_+"&&"+categorySelection,prefix,osWSelection_,osSignalSelection_);
			std::cout<<"QCD preSelection: "<<preSelection<<std::endl;
			std::cout<<"QCD CategorySelection: "<<categorySelection<<std::endl;
			std::cout<<"QCD SSWSelection: "<<ssWSelection_<<std::endl;
			std::cout<<"QCD SSSigSelection: "<<ssSignalSelection_<<std::endl;
			std::pair<float,float> wFactor = extractWFactor(wFile_,preSelection+"&&"+trigSelection_+"&&"+categorySelection,prefix,ssWSelection_,ssSignalSelection_);
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
			renormalizeHistogram(filelabel_+prefix,"WQCD",ssWLow.first);
*/
		}



		bool runW(std::string preSelection,std::string prefix,std::string zShape, float topExtrap, BkgOutput &output, std::string categorySelection, std::string relaxedSelection, std::string wSel) {

			std::cout<<"WSelection: "<<preSelection+"&&"<<trigSelection_<<"&&"<<categorySelection<<"&&"<<charge_<<"&&"<<wSel<<std::endl; 
			float leg1Corr=1.0;
			if(muID_!=0) leg1Corr*=muID_;
			if(eleID_!=0) leg1Corr*=eleID_;

			//std::pair<float,float> wShape         = createHistogramAndShifts(wFile_,"W",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+relaxedSelection+")*"+weight_),luminosity_*leg1Corr,prefix,false);
			std::pair<float,float> wYield         = createHistogramAndShifts(wFile_,"W",("("+preSelection+"&&"+trigSelection_+"&&"+osSignalSelection_+"&&"+categorySelection+")*"+weight_),luminosity_*leg1Corr,prefix,false);


			printf("          OS W  in MC = %f \n",wYield.first);


			output.W = wYield.first;
			output.dW = wYield.second;

			return true;
		}


		//-------------Helper Functions------------------

		void addHistogramZTT(std::string folder, std::string histo1, std::string histo2)
		{
			std::cout<<"In AddHistogramZTT"<<std::endl;
			addHistogram(folder,histo1,histo2);
			for(unsigned int i=0;i<shifts_.size();++i) {
				TH1F * h1 =(TH1F*) fout_->Get((folder+"/"+histo1+"_"+shiftsPostFix_[i]+"Up").c_str());
				if(h1!=0) 
				{
					addHistogram(folder,(histo1+"_"+shiftsPostFix_[i]+"Up").c_str(),histo2);
				}
				else
				{
					printf("Shift not found = %s\n",(folder+"/"+histo1+"_"+shiftsPostFix_[i]+"Up").c_str());
				}
				TH1F * h2 =(TH1F*) fout_->Get((folder+"/"+histo1+"_"+shiftsPostFix_[i]+"Down").c_str());
				if(h2!=0)
				{
					addHistogram(folder,(histo1+"_"+shiftsPostFix_[i]+"Down").c_str(),histo2);
				}		
				else
				{
					printf("Shift not found = %s\n",(folder+"/"+histo1+"_"+shiftsPostFix_[i]+"Down").c_str());
				}
			}//end for


		}//end addHistogram ZTT

		std::pair<float,float> createHistogramAndShifts(std::string file,std::string name, std::string cut,float scaleFactor = 1, std::string postfix = "",bool normUC  = true, bool keys=false,bool ShapeUncertainty=true) {
			TFile *f  = new TFile(file.c_str());
			if(f==0) printf("Not file Found\n");
			//get the nominal tree first
			TTree *t= (TTree*)f->Get((channel_+"EventTree/eventTree").c_str());
			if(t==0) printf("Not Tree Found in file %s\n",file.c_str());
			std::pair<float,float> yield;

			if(!keys)
				yield =makeHistogram(t,filelabel_+postfix,name,cut,scaleFactor);
			else
				yield =makeTHKeys(t,filelabel_+postfix,name,cut,scaleFactor);

			//now the shifts
			std::pair<float,float> tmpYield;
			for(unsigned int i=0;i<shifts_.size();++i) {

				TTree *ts= (TTree*)f->Get((channel_+"EventTree"+shifts_[i]+"Up/eventTree").c_str());
				if(ts!=0) {
					if(!keys)
						tmpYield = makeHistogram(ts,filelabel_+postfix,name+"_"+shiftsPostFix_[i]+"Up",cut,scaleFactor);
					else
						tmpYield = makeTHKeys(ts,filelabel_+postfix,name+"_"+shiftsPostFix_[i]+"Up",cut,scaleFactor);

					if(!normUC)
						scaleHistogram(filelabel_+postfix,name+"_"+shiftsPostFix_[i]+"Up",yield.first/tmpYield.first);

				}
				TTree *td= (TTree*)f->Get((channel_+"EventTree"+shifts_[i]+"Down/eventTree").c_str());
				if(td!=0) {
					if(!keys)
						tmpYield = makeHistogram(td,filelabel_+postfix,name+"_"+shiftsPostFix_[i]+"Down",cut,scaleFactor);
					else
						tmpYield = makeTHKeys(td,filelabel_+postfix,name+"_"+shiftsPostFix_[i]+"Down",cut,scaleFactor);

					if(!normUC)
						scaleHistogram(filelabel_+postfix,name+"_"+shiftsPostFix_[i]+"Down",yield.first/tmpYield.first);

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
				yield =makeHistogram(t,filelabel_+postfix,name,cut,scaleFactor);
			else
				yield =makeTHKeys(t,filelabel_+postfix,name,cut,scaleFactor);

			//now the shifts
			std::pair<float,float> tmpYield;
			for(unsigned int i=0;i<shifts_.size();++i) {

				TTree *ts= (TTree*)f->Get((channel_+"EventTreeFinal"+shifts_[i]+"Up/eventTree").c_str());
				if(ts!=0) {
					if(!keys)
						tmpYield = makeHistogram(ts,filelabel_+postfix,name+"_"+shiftsPostFix_[i]+"Up",cut,scaleFactor);
					else
						tmpYield = makeTHKeys(ts,filelabel_+postfix,name+"_"+shiftsPostFix_[i]+"Up",cut,scaleFactor);

					if(!normUC)
						scaleHistogram(filelabel_+postfix,name+"_"+shiftsPostFix_[i]+"Up",yield.first/tmpYield.first);

				}
				TTree *td= (TTree*)f->Get((channel_+"EventTreeFinal"+shifts_[i]+"Down/eventTree").c_str());
				if(td!=0) {
					if(!keys)
						tmpYield = makeHistogram(td,filelabel_+postfix,name+"_"+shiftsPostFix_[i]+"Down",cut,scaleFactor);
					else
						tmpYield = makeTHKeys(td,filelabel_+postfix,name+"_"+shiftsPostFix_[i]+"Down",cut,scaleFactor);

					if(!normUC)
						scaleHistogram(filelabel_+postfix,name+"_"+shiftsPostFix_[i]+"Down",yield.first/tmpYield.first);

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
				variable_="pt_2";
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
			//LD
			float yield = h->IntegralAndError(1,h->GetNbinsX(),error,"");
			//float yield = h->IntegralAndError(0,h->GetNbinsX()+1,error,"");
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

			yield =makeHistogramShifted(t,filelabel_+postfix,name,cut,shift,scaleFactor);

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
			high = makeHistogram(t,filelabel_+postfix,"W_High",("("+preselection+"&&"+wSelection_+")*"+weight_+"*"+Wweight).c_str());
			low = makeHistogram(t,filelabel_+postfix,"W_Low",("("+preselection+"&&"+signalSelection_+")*"+weight_+"*"+Wweight).c_str());

			std::cout<<"W + Jets High: "<< high.first<<" Low: "<< low.first<<std::endl;

			float factor = low.first/high.first;
			float factorerrStat = sqrt(low.second*low.second + high.second*high.second);
			float factorerrSyst = factor*wFactorErr_;
			float factorErr = sqrt(factorerrStat*factorerrStat+factorerrSyst*factorerrSyst);

			if(high.first==0.){ 
				factor=0.;
				factorErr=0.;
			}
			return std::make_pair(factor,factorErr);   

		}

		std::pair<float,float> extractWFactorFinal(std::string file,std::string preselection,std::string postfix, std::string Wweight = "1") {
			TFile *f  = new TFile (file.c_str());
			TTree *t = (TTree*)f->Get((channel_+"EventTreeFinal/eventTree").c_str());

			std::pair<float,float> high;
			std::pair<float,float> low;

			high = makeHistogram(t,filelabel_+postfix,"W_High",("("+preselection+"&&"+wSelection_+")*"+weight_+"*"+Wweight).c_str());
			low = makeHistogram(t,filelabel_+postfix,"W_Low",("("+preselection+"&&"+signalSelection_+")*"+weight_+"*"+Wweight).c_str());

			std::cout<<"W + Jets High: "<< high.first<<" Low: "<< low.first<<std::endl;

			float factor = low.first/high.first;
			float factorerrStat = sqrt(low.second*low.second + high.second*high.second);
			float factorerrSyst = factor*wFactorErr_;
			float factorErr = sqrt(factorerrStat*factorerrStat+factorerrSyst*factorerrSyst);
			if(high.first==0.){
				factor=0.;
				factorErr=0.;
			}
			return std::make_pair(factor,factorErr);   

		}

		std::pair<float,float> extractWFactor(std::string file, std::string preselection, std::string postfix, std::string wSel, std::string sigSel) {
			TFile *f  = new TFile (file.c_str());
			TTree *t = (TTree*)f->Get((channel_+"EventTree/eventTree").c_str());
			//TTree *t = (TTree*)f->Get((channel_+"EventTreeFinal/eventTree").c_str());

			std::pair<float,float> high;
			std::pair<float,float> low;


			high = makeHistogram(t,filelabel_+postfix,"W_High",("("+preselection+"&&"+wSel+")*"+weight_).c_str(),luminosity_);
			low = makeHistogram(t,filelabel_+postfix,"W_Low",("("+preselection+"&&"+sigSel+")*"+weight_).c_str(),luminosity_);

			std::cout<<"      Cuts in extract WFactor "<<"      OS W Mt>70: "<<high.first<<"      OS W Mt Low: "<<low.first<<std::endl;
			std::cout<<"      Extract WFactor Second"<<"      OS W Mt>70: "<<high.second<<"      OS W Mt Low: "<<low.second<<std::endl;
			float factor = low.first/high.first;
			float factorerrStat = sqrt(low.second*low.second + high.second*high.second);
			float factorerrSyst = factor*wFactorErr_;
			float factorErr = sqrt(factorerrStat*factorerrStat+factorerrSyst*factorerrSyst);
                        
   
			std::cout<<"      WFactor Stat Error "<<"      factor: "<<factor<<"      StatError: "<<factorerrStat<<std::endl;
			std::cout<<"      WFactor Syst Error "<<"      factor*wFactorErr_: "<<factor<<"*"<<wFactorErr_<<" = "<<factorerrSyst<<std::endl; 
			std::cout<<"      WFactor Error "<<"      factorError = sqrt(Syst Error^2+Stat Error^2)= "<<factorErr<<std::endl; 
			if(high.first==0.){
				factor=0.;
				factorErr=0.;
			}
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

			std::string chan = "mt";
			if(channel == "eleTau")
				chan = "et";

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

			TH1F * hh =(TH1F*) fout_->Get((folder+"/"+histo+"_CMS_scale_t_etau_13TeVUp").c_str());
			TH1F * hhh =(TH1F*) fout_->Get((folder+"/"+histo+"_CMS_scale_t_etau_13TeVDown").c_str());

			if(hh!=0){
				TH1F * hUp = (TH1F*)hh->Clone(TString(histo+std::string("_CMS_htt_ZEEShape_etau_13TeVUp")));
				hUp->Write(hUp->GetName(),TObject::kOverwrite);
			}
			else{
				printf("Shift not found = %s\n",(folder+"/"+histo+"_CMS_scale_t_etau_13TeVUp").c_str());
			}
			if(hhh!=0){
				TH1F * hDown = (TH1F*)hhh->Clone(TString(histo+std::string("_CMS_htt_ZEEShape_etau_13TeVDown")));
				hDown->Write(hDown->GetName(),TObject::kOverwrite);
			}
			else{
				printf("Shift not found = %s\n",(folder+"/"+histo+"_CMS_scale_t_etau_13TeVDown").c_str());
			}

		}


	private:
		std::string channel_;
		std::string filelabel_;
		std::vector<std::string> shifts_;
		std::vector<std::string> shiftsPostFix_;
		std::string energy_;
		int samesign_;

		//files
		TFile *fout_;
		int verbose_;
		std::string zttFile_;
		std::string zllFile_;
		std::string wFile_;
		std::string vvFile_;
		std::string topFile_;
		std::string qcdFile_;
		std::string dataFile_;
		///////////////////////

		//selections of regions
		std::string preSelection_;
		std::string inclSelection_;
		std::string osSignalSelection_;
		std::string ssSignalSelection_;
		std::string signalSelection_;
		std::string osWSelection_;
		std::string ssWSelection_;
		std::string wSelection_;
		std::string qcdSelection_;
		std::string bSelection_;
		std::string antibSelection_;
		std::string relaxedSelection_;
		std::string btagRelaxedSelection_;
		std::string trigSelection_;
		std::string trigSelection50ns_;
		std::string trigSelection25ns_;
		std::string blinding_;
		std::string charge_;
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
		float qcdErr_;//tmp
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
