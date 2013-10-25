
#include "UWAnalysis/StatTools/interface/DataCardCreator.h"
#include "PhysicsTools/FWLite/interface/CommandLineParser.h" 


int main (int argc, char* argv[]) 
{


   optutl::CommandLineParser parser ("Background subtrcation ");

   //Input Files-------------------
   parser.addOption("channel",optutl::CommandLineParser::kString,"Channel  ","mutau");
   parser.addOption("shifts",optutl::CommandLineParser::kStringVector,"Systematic Shifts(Supported Tau,Jet,Unc and whatever else in the tree) ");
   parser.addOption("dataFile",optutl::CommandLineParser::kString,"File with the data","DATA.root");
   parser.addOption("zttFile",optutl::CommandLineParser::kString,"File with the ZTT","ZTT.root");
   parser.addOption("zEmbeddedSample",optutl::CommandLineParser::kString,"File with the ZTT+2jets","");
   parser.addOption("wThreeJetsFile",optutl::CommandLineParser::kString,"File with the W+3jets","");
   parser.addOption("zllFile",optutl::CommandLineParser::kString,"File with the ZLL","ZLL.root");
   parser.addOption("wFile",optutl::CommandLineParser::kString,"File with the W","W.root");
   parser.addOption("vvFile",optutl::CommandLineParser::kString,"File with the VV","VV.root");
   parser.addOption("topFile",optutl::CommandLineParser::kString,"File with the TOP","TOP.root");
   parser.addOption("W42File",optutl::CommandLineParser::kString,"File for WJets from 42X","../inputs/ltau/W42.root");
   parser.addOption("preselection",optutl::CommandLineParser::kString,"preselection","");
   parser.addOption("signalSelection",optutl::CommandLineParser::kString," Signal ","mt1<30");
   parser.addOption("wSelection",optutl::CommandLineParser::kString,"W sideband defintion ","mt1>70");
   parser.addOption("qcdSelection",optutl::CommandLineParser::kString,"QCD Shape definition");
   parser.addOption("relaxedSelection",optutl::CommandLineParser::kString,"Relaxed Selection");
   parser.addOption("bSelection",optutl::CommandLineParser::kString,"Btagging Requirement for MSSM ","(nJetsBTag3Pt20>0&&nJetsPt30<2)");
   parser.addOption("antibSelection",optutl::CommandLineParser::kString,"Anti Btagging requirement for MSSM","(nJetsBTag3Pt20==0&&nJetsPt30<2)");
   parser.addOption("btagSelection",optutl::CommandLineParser::kString,"btagSelection","btag>0");
   parser.addOption("bTagSF",optutl::CommandLineParser::kString,"bTagSF","1");
   parser.addOption("vbfSelection0",optutl::CommandLineParser::kString,"SM Category 0 ","");
   parser.addOption("vbfSelection1",optutl::CommandLineParser::kString,"SM category 1","");
   parser.addOption("vbfSelection2",optutl::CommandLineParser::kString,"SM Category 2","");
   parser.addOption("vbfSelection3",optutl::CommandLineParser::kString,"SM Category 3","");
   parser.addOption("vbfSelection4",optutl::CommandLineParser::kString,"SM Category 4","");
   parser.addOption("vbfRelaxedSelection",optutl::CommandLineParser::kString,"VBF Relaxed Selection","");
   parser.addOption("btagRelaxedSelection",optutl::CommandLineParser::kString,"bTag Relaxed Selection","");
   parser.addOption("vbfWSelection",optutl::CommandLineParser::kString,"VBF W Shape Selection","");
   parser.addOption("trigSelection",optutl::CommandLineParser::kString,"Trigger Selection","lTrigger>0&&tauTrigger>0");
   parser.addOption("vbfTightSplit",optutl::CommandLineParser::kString,"VBF Tight Cut","");
   parser.addOption("blinding",optutl::CommandLineParser::kString,"Blinding","(svMass>0)");
   parser.addOption("luminosity",optutl::CommandLineParser::kDouble,"Luminosity",189.);
   parser.addOption("luminosityErr",optutl::CommandLineParser::kDouble,"LuminosityErr",0.04);
   parser.addOption("variable",optutl::CommandLineParser::kString,"Shape variable ","mass");
   parser.addOption("weight",optutl::CommandLineParser::kString,"Weight for MC (Multiply Weight Factors here for efficiencies)","__WEIGHT__*__CORR__");
   parser.addOption("embWeight",optutl::CommandLineParser::kString,"Weight for Embedded","__CORR__");
   parser.addOption("min",optutl::CommandLineParser::kDouble,"Minimum value",0.);
   parser.addOption("max",optutl::CommandLineParser::kDouble,"Maximum Value ",500.);
   parser.addOption("bins",optutl::CommandLineParser::kInteger,"Number of Bins",50);
   parser.addOption("verbose",optutl::CommandLineParser::kInteger,"verbose",0);
   parser.addOption("binningHighStat",optutl::CommandLineParser::kDoubleVector,"Define Custom Variable Binning");
   parser.addOption("binningLowStat",optutl::CommandLineParser::kDoubleVector,"Define Custom Variable Binning");
   parser.addOption("binningVBFTight",optutl::CommandLineParser::kDoubleVector,"Define Custom Variable Binning");
   //   parser.addOption("binningBoost",optutl::CommandLineParser::kDoubleVector,"Define Custom Variable Binning");
   parser.addOption("topSF",optutl::CommandLineParser::kDouble,"TTBar Scale Factor",1.0);
   parser.addOption("topErr",optutl::CommandLineParser::kDouble,"TTBar Relative Error",0.075);
   parser.addOption("vvErr",optutl::CommandLineParser::kDouble,"DiBoson RelativeError",0.3);   
   parser.addOption("zLFTErr",optutl::CommandLineParser::kDouble,"Z Muon fakes tau error",0.25);
   parser.addOption("zLFTFactor",optutl::CommandLineParser::kDouble,"Z Muon fakes tau error",1.0);
   parser.addOption("zJFTErr",optutl::CommandLineParser::kDouble,"Z Jet fakes tau Error",0.2);
   parser.addOption("zttScale",optutl::CommandLineParser::kDouble,"Z tau tau scale",1.00);
   parser.addOption("zttScaleErr",optutl::CommandLineParser::kDouble,"Z tau tau scale error",0.033);
   parser.addOption("muID",optutl::CommandLineParser::kDouble,"Mu ID",1.0);
   parser.addOption("muIDErr",optutl::CommandLineParser::kDouble,"MuIDErr",0.02);
   parser.addOption("bID",optutl::CommandLineParser::kDouble,"B ID",0.94);
   parser.addOption("bIDErr",optutl::CommandLineParser::kDouble,"BIDErr",0.10);
   parser.addOption("bmisID",optutl::CommandLineParser::kDouble,"B MISID",1.21);
   parser.addOption("bmisIDErr",optutl::CommandLineParser::kDouble,"BMISIDErr",0.17);
   parser.addOption("eleID",optutl::CommandLineParser::kDouble,"Ele ID",0.0);
   parser.addOption("eleIDErr",optutl::CommandLineParser::kDouble,"Ele IDErr",0.00);
   parser.addOption("tauID",optutl::CommandLineParser::kDouble,"Tau ID",1.0);
   parser.addOption("tauIDHigh",optutl::CommandLineParser::kDouble,"Tau ID Pt>40",1.0);
   parser.addOption("tauIDErr",optutl::CommandLineParser::kDouble,"Tau IDErr",0.06);
   parser.addOption("qcdFactor",optutl::CommandLineParser::kDouble,"qcs OSLS Ratio",1.06);
   parser.addOption("qcdFactorErr",optutl::CommandLineParser::kDouble,"qcs OSLS Ratio Error",0.02);
   parser.addOption("wFactorErr",optutl::CommandLineParser::kDouble,"W factor error ",0.06);
   parser.addOption("bFactorZ",optutl::CommandLineParser::kDouble,"B factor Z",1.0);
   parser.addOption("bFactorW",optutl::CommandLineParser::kDouble,"B Factor W",1.0);
   parser.addOption("bFactorZErr",optutl::CommandLineParser::kDouble,"Probability of Z +1 b Error",0.011);
   parser.addOption("bFactorWErr",optutl::CommandLineParser::kDouble,"Probability of W+ 1 b Error",0.05);
   parser.addOption("vbfFactorZ",optutl::CommandLineParser::kDouble,"VBF factor for Z",1.);
   parser.addOption("vbfFactorW",optutl::CommandLineParser::kDouble,"VBF Factor for W",1.);
   parser.addOption("vbfFactorZErr",optutl::CommandLineParser::kDouble,"VBF factor for Z Error",0.1);
   parser.addOption("vbfFactorWErr",optutl::CommandLineParser::kDouble,"VBF factor for WError",0.1);
   parser.addOption("boostFactorZ",optutl::CommandLineParser::kDouble,"Boost factor for Z",1.);
   parser.addOption("boostFactorW",optutl::CommandLineParser::kDouble,"Boost Factor for W",1.);
   parser.addOption("boostFactorZErr",optutl::CommandLineParser::kDouble,"Boost factor for ZErr",0.15);
   parser.addOption("boostFactorWErr",optutl::CommandLineParser::kDouble,"Boost  factor for W Error",0.15);
   parser.addOption("vhFactorZ",optutl::CommandLineParser::kDouble,"VH factor for Z",0.93);
   parser.addOption("vhFactorW",optutl::CommandLineParser::kDouble,"VH Factor for W",0.93);
   parser.addOption("vhFactorZErr",optutl::CommandLineParser::kDouble,"VH factor for ZErr",0.01);
   parser.addOption("vhFactorWErr",optutl::CommandLineParser::kDouble,"VH  factor for W Error",0.01);
   parser.addOption("catSplit",optutl::CommandLineParser::kString,"High/Low category split","pt2>45");
   parser.addOption("energy",optutl::CommandLineParser::kString,"Center of Mass Energy","8TeV");


   parser.addOption("dir",optutl::CommandLineParser::kString,"dir","../inputs/mutau");
   parser.addOption("bitmask",optutl::CommandLineParser::kIntegerVector,"Choose what to run");
   parser.addOption("scaleUp",optutl::CommandLineParser::kDouble,"scale up for extrapolation to higher lumi",1.0);

   parser.parseArguments (argc, argv);
   std::vector<int> bitmask = parser.integerVector("bitMask");
   DataCardCreator creator(parser);

   printf("Binning HighSTat has %d entries ,LowStat has %d entries\n",(int)parser.doubleVector("binningHighStat").size(),(int)parser.doubleVector("binningLowStat").size());


     //Inclusive
     //setHighStat Binning
     creator.setBinning(parser.doubleVector("binningHighStat"));
     
     printf("INCLUSIVE-------------------------------------\n");
     
	 BkgOutput output = creator.runOSLSMT(parser.stringValue("preselection"),"_inclusive",parser.stringValue("zEmbeddedSample"),parser.doubleValue("topSF"));

       creator.makeHeavyHiggsShape(parser.stringValue("preselection"),"_inclusive");

     if(bitmask[3]==4){	 
	creator.setBinning(parser.doubleVector("binningLowStat"));
       std::string MSSM1 = parser.stringValue("btagSelection"); 
       std::string bTagSF1 = parser.stringValue("bTagSF");

       creator.makeHeavyHiggsShape(parser.stringValue("preselection")+"&&"+MSSM1,"_1btag");
       
       BkgOutput outputMSSM1L = creator.runFullExtrapolationBTag(parser.stringValue("preselection"),MSSM1,"_1btag",output,
								 parser.doubleValue("bFactorZ"),
								 parser.doubleValue("bFactorZErr"),
								 parser.doubleValue("bFactorW"),
								 parser.doubleValue("bFactorWErr"),
								 parser.doubleValue("topSF"),
								 parser.doubleValue("bIDErr"),
								 parser.stringValue("zEmbeddedSample"),
								 bTagSF1
								 //parser.stringValue("embWeight")
								 );

       //creator.makeSMLTauDataCardNoVBF(outputSM0L,"_0jet_low",parser.stringValue("energy"));

       //creator.makeHiggsShapesMSSM(parser.stringValue("preselection")+"&&"+MSSM1,"_MSSM1"); //mssmSelection1
       
     }
   
     if(bitmask[1]==1|| bitmask[1]>6) {
     
       creator.setBinning(parser.doubleVector("binningHighStat"));
       printf("0 Jet Low Pt-------------------------------------\n");
       std::string SM0Low = parser.stringValue("vbfSelection0")+"&&pt2<30";
       BkgOutput outputSM0L = creator.runMinimalExtrapolation(parser.stringValue("preselection"),SM0Low,"_0jet_low",1.0,0.0,parser.doubleValue("topSF"),0.0,output,parser.stringValue("zEmbeddedSample"));
	
       creator.makeHiggsShapesSM(parser.stringValue("preselection")+"&&"+SM0Low,"_0jet_low");
       //creator.makeSMLTauDataCardNoVBF(outputSM0L,"_0jet_low",parser.stringValue("energy"));

	}
	
	if(bitmask[1]==2 || bitmask[1]>6) {
	
       printf("0 Jet Med Pt-------------------------------------\n");
       std::string SM0Med = parser.stringValue("vbfSelection0")+"&&(!("+parser.stringValue("catSplit")+"))&&pt2>30";
       BkgOutput outputSM0M = creator.runMinimalExtrapolation(parser.stringValue("preselection"),SM0Med,"_0jet_medium",1.0,0.0,parser.doubleValue("topSF"),0.0,output,parser.stringValue("zEmbeddedSample"));


       creator.makeHiggsShapesSM(parser.stringValue("preselection")+"&&"+SM0Med,"_0jet_medium");
       //creator.makeSMLTauDataCardNoVBF(outputSM0M,"_0jet_low",parser.stringValue("energy"));
    }
     
    if(bitmask[1]==3 || bitmask[1]>6) {
    
       printf("0 Jet High Pt-------------------------------------\n");
       std::string SM0High = parser.stringValue("vbfSelection0")+"&&("+parser.stringValue("catSplit")+")";
       BkgOutput outputSM0H = creator.runMinimalExtrapolation(parser.stringValue("preselection"),SM0High,"_0jet_high",1.0,0.0,parser.doubleValue("topSF"),0.0,output,parser.stringValue("zEmbeddedSample"));


       creator.makeHiggsShapesSM(parser.stringValue("preselection")+"&&"+SM0High,"_0jet_high");
       //creator.makeSMLTauDataCardNoVBF(outputSM0H,"_0jet_high",parser.stringValue("energy"));

	}
	
	if(bitmask[1]==4 || bitmask[1]>6) {
	
       printf("1 Jet Med Pt-------------------------------------\n");
       std::string SM1Low = parser.stringValue("vbfSelection1")+"&&(!("+parser.stringValue("catSplit")+"))&&pt2>30&&(!("+parser.stringValue("vbfSelection2")+"))&&(!("+parser.stringValue("vbfSelection3")+"))";


       BkgOutput outputSM1L = creator.runMinimalExtrapolation(parser.stringValue("preselection"),SM1Low,"_1jet_medium",1.0,0.0,parser.doubleValue("topSF"),0.0,output,parser.stringValue("zEmbeddedSample"));
       
       creator.makeHiggsShapesSM(parser.stringValue("preselection")+"&&"+SM1Low,"_1jet_medium");
       //creator.makeSMLTauDataCardNoVBF(outputSM1L,"_boost_low",parser.stringValue("energy"));

	}
	 
	if(bitmask[1]==5 || bitmask[1]>6) {    
	                       
       printf("1 Jet High Pt-------------------------------------\n");
       std::string  SM1High = parser.stringValue("vbfSelection1")+"&&("+parser.stringValue("catSplit")+"&&fullPt<100)"+"&&(!("+parser.stringValue("vbfSelection2")+"))"+"&&(!("+parser.stringValue("vbfSelection3")+"))";

       BkgOutput outputSM1H = creator.runMinimalExtrapolation(parser.stringValue("preselection"),SM1High,"_1jet_high_lowhiggs",1.0,0.0,parser.doubleValue("topSF"),0.0,output,parser.stringValue("zEmbeddedSample"));
       
       creator.makeHiggsShapesSM(parser.stringValue("preselection")+"&&"+SM1High,"_1jet_high_lowhiggs");
       //creator.makeSMLTauDataCardNoVBF(outputSM1H,"_boost_high",parser.stringValue("energy"));
    
    }
       
    if(bitmask[1]==6 || bitmask[1]>6) {  
       
       printf("Boost-------------------------------------\n");

       std::string  BOOST = parser.stringValue("vbfSelection1")+"&&("+parser.stringValue("catSplit")+"&&fullPt>100)"+"&&(!("+parser.stringValue("vbfSelection2")+"))"+"&&(!("+parser.stringValue("vbfSelection3")+"))";

       BkgOutput outputBOOST = creator.runBoost(parser.stringValue("preselection"),BOOST,"_1jet_high_mediumhiggs",output,
								  parser.doubleValue("vbfFactorZ"),
								  parser.doubleValue("vbfFactorZErr"),
								  parser.doubleValue("vbfFactorW"),
								  parser.doubleValue("vbfFactorWErr"),
								  parser.doubleValue("topSF"),
								  0.0,
								  parser.stringValue("zEmbeddedSample"),
								  parser.stringValue("wThreeJetsFile")
							  
								  );
								  
       creator.makeHiggsShapesSM(parser.stringValue("preselection")+"&&"+BOOST,"_1jet_high_mediumhiggs");
       //creator.makeSMLTauDataCardNoVBF(outputBOOST,"_boost_high",parser.stringValue("energy"));

     }
 
     
 

	creator.setBinning(parser.doubleVector("binningLowStat"));

	if(parser.stringValue("energy")=="7TeV") {
	
		if(bitmask[2]==1) {
		   printf("VBF-------------------------------------\n");
	   
		   BkgOutput outputSM2 = creator.runVBFLoose(parser.stringValue("preselection"),parser.stringValue("vbfSelection2"),"_vbf_loose",output,
								  parser.doubleValue("vbfFactorZ"),
								  parser.doubleValue("vbfFactorZErr"),
								  parser.doubleValue("vbfFactorW"),
								  parser.doubleValue("vbfFactorWErr"),
								  parser.doubleValue("topSF"),
								  0.0,
								  parser.stringValue("zEmbeddedSample"),
								  parser.stringValue("wThreeJetsFile")
						  
								  );
		   creator.makeHiggsShapesSM(parser.stringValue("preselection")+"&&"+parser.stringValue("vbfSelection2"),"_vbf_loose");
		   //creator.makeSMLTauDataCardVBF(outputSM2,"_vbf",parser.stringValue("energy"));
		}
   
	}
	else{

		if(bitmask[2]==1 || bitmask[2]>2) {	

		   printf("VBF Loose-------------------------------------\n");
   
		   std::string SM3L = parser.stringValue("vbfSelection3")+"&&(!("+parser.stringValue("vbfSelection2")+"))";
   
		   BkgOutput outputSM3L = creator.runVBFLoose(parser.stringValue("preselection"),SM3L,"_vbf_loose",output,
								  parser.doubleValue("vbfFactorZ"),
								  parser.doubleValue("vbfFactorZErr"),
								  parser.doubleValue("vbfFactorW"),
								  parser.doubleValue("vbfFactorWErr"),
								  parser.doubleValue("topSF"),
								  0.0,
								  parser.stringValue("zEmbeddedSample"),
								  parser.stringValue("wThreeJetsFile")
						  
								  );
		   creator.makeHiggsShapesSM(parser.stringValue("preselection")+"&&"+SM3L,"_vbf_loose");
		   //creator.makeSMLTauDataCardVBF(outputSM3L,"_2jet",parser.stringValue("energy"));		

		   creator.setBinning(parser.doubleVector("binningVBFTight"));

		}

		if(bitmask[2]==2 || bitmask[2]>2) {	
			   
		   printf("VBF Tight-------------------------------------\n");
   
		   BkgOutput outputSM2 = creator.runVBFTight(parser.stringValue("preselection"),parser.stringValue("vbfSelection2"),"_vbf_tight",output,
								  parser.doubleValue("vbfFactorZ"),
								  parser.doubleValue("vbfFactorZErr"),
								  parser.doubleValue("vbfFactorW"),
								  parser.doubleValue("vbfFactorWErr"),
								  parser.doubleValue("topSF"),
								  0.0,
								  parser.stringValue("zEmbeddedSample"),
								  parser.stringValue("wThreeJetsFile")
						  
								  );
		   creator.makeHiggsShapesSM(parser.stringValue("preselection")+"&&"+parser.stringValue("vbfSelection2"),"_vbf_tight");
		   //creator.makeSMLTauDataCardVBF(outputSM2,"_vbf",parser.stringValue("energy"));
		}
					
	}



     

     if(bitmask.size()<4||bitmask[3]==1) {
       creator.setBinning(parser.doubleVector("binningHighStat"));
       printf("Z -> tau tau cross section-------------------------------------\n");
       BkgOutput outputZTT = creator.runOSLSMT(parser.stringValue("preselection"),"_ZTT",parser.stringValue("zEmbeddedSample"),parser.doubleValue("topSF"));
       creator.makeZTTLTauDataCard(output,"_ZTT");
     }



     creator.close();
}

