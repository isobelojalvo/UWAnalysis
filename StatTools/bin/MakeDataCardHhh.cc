
#include "UWAnalysis/StatTools/interface/DataCardCreatorHhh.h"
#include "PhysicsTools/FWLite/interface/CommandLineParser.h" 


int main (int argc, char* argv[]) 
{

   optutl::CommandLineParser parser ("Background subtraction ");

   //Input Files
   parser.addOption("channel",optutl::CommandLineParser::kString,"Channel  ","mutau");
   parser.addOption("shifts",optutl::CommandLineParser::kStringVector,"Systematic Shifts(Supported Tau,Jet,Unc and whatever else in the tree) ");
   parser.addOption("dataFile",optutl::CommandLineParser::kString,"File with the data","DATA.root");
   parser.addOption("zttFile",optutl::CommandLineParser::kString,"File with the ZTT","ZTT.root");
   parser.addOption("zEmbeddedSample",optutl::CommandLineParser::kString,"File with the ZTT+2jets","");
   parser.addOption("zllFile",optutl::CommandLineParser::kString,"File with the ZLL","ZLL.root");
   parser.addOption("wFile",optutl::CommandLineParser::kString,"File with the W","W.root");
   parser.addOption("vvFile",optutl::CommandLineParser::kString,"File with the VV","VV.root");
   parser.addOption("topFile",optutl::CommandLineParser::kString,"File with the TOP","TOP.root");

   //Input Selections
   parser.addOption("preselection",optutl::CommandLineParser::kString,"preselection","");
   parser.addOption("signalSelection",optutl::CommandLineParser::kString," Signal ","mt1<30");
   parser.addOption("wSelection",optutl::CommandLineParser::kString,"W sideband defintion ","mt1>70");
   parser.addOption("qcdSelection",optutl::CommandLineParser::kString,"QCD Shape definition");
   parser.addOption("relaxedSelection",optutl::CommandLineParser::kString,"Relaxed Selection");
   parser.addOption("bSelection",optutl::CommandLineParser::kString,"Btagging Requirement for MSSM ","(nJetsBTag3Pt20>0&&nJetsPt30<2)");
   parser.addOption("antibSelection",optutl::CommandLineParser::kString,"Anti Btagging requirement for MSSM","(nJetsBTag3Pt20==0&&nJetsPt30<2)");
   parser.addOption("btagSelection",optutl::CommandLineParser::kString,"btagSelection","btag>0");
   parser.addOption("btagSelection2",optutl::CommandLineParser::kString,"btagSelection","btag>0");
   parser.addOption("bTagSF",optutl::CommandLineParser::kString,"bTagSF","1");
   parser.addOption("bTagSF2",optutl::CommandLineParser::kString,"bTagSF","1");
//breaks without this currently
   parser.addOption("btagRelaxedSelection",optutl::CommandLineParser::kString,"bTag Relaxed Selection","");
   parser.addOption("btagRelaxedSelection2",optutl::CommandLineParser::kString,"2 bTag Relaxed Selection","");
   parser.addOption("trigSelection",optutl::CommandLineParser::kString,"Trigger Selection","lTrigger>0&&tauTrigger>0");
   parser.addOption("blinding",optutl::CommandLineParser::kString,"Blinding","(svMass>0)");
   parser.addOption("charge",optutl::CommandLineParser::kString,"charge","charge==0");
   parser.addOption("catSplit",optutl::CommandLineParser::kString,"High/Low category split","pt2>45");

   //Other Options
   parser.addOption("luminosity",optutl::CommandLineParser::kDouble,"Luminosity",189.);
   parser.addOption("luminosityErr",optutl::CommandLineParser::kDouble,"LuminosityErr",0.04);
   parser.addOption("variable",optutl::CommandLineParser::kString,"Shape variable ","mass");
   parser.addOption("weight",optutl::CommandLineParser::kString,"Weight for MC (Multiply Weight Factors here for efficiencies)","__WEIGHT__*__CORR__");
   parser.addOption("embWeight",optutl::CommandLineParser::kString,"Weight for Embedded","__CORR__");
   parser.addOption("min",optutl::CommandLineParser::kDouble,"Minimum value",0.);
   parser.addOption("max",optutl::CommandLineParser::kDouble,"Maximum Value ",500.);
   parser.addOption("bins",optutl::CommandLineParser::kInteger,"Number of Bins",50);
   parser.addOption("verbose",optutl::CommandLineParser::kInteger,"verbose",0);
   parser.addOption("binningKinFit",optutl::CommandLineParser::kDoubleVector,"Define Custom Variable Binning");
   parser.addOption("binningHighStat",optutl::CommandLineParser::kDoubleVector,"Define Custom Variable Binning");
   parser.addOption("binningLowStat",optutl::CommandLineParser::kDoubleVector,"Define Custom Variable Binning");


   //Input Scale Factors
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
   parser.addOption("energy",optutl::CommandLineParser::kString,"Center of Mass Energy","8TeV");

   parser.addOption("dir",optutl::CommandLineParser::kString,"dir","../inputs/mutau");
   parser.addOption("bitmask",optutl::CommandLineParser::kIntegerVector,"Choose what to run");
   parser.addOption("scaleUp",optutl::CommandLineParser::kDouble,"scale up for extrapolation to higher lumi",1.0);

        //category options

   parser.addOption("1jet0tag",optutl::CommandLineParser::kString,"Requirement for MSSM Categories 1","J1PtCSVSort>20&&J1EtaCSVSort<2.4&&J1EtaCSVSort>-2.4&&nJetsBTagCSVTPt20==0&&(!(J2PtCSVSort>20&&J2EtaCSVSort<2.4&&J2EtaCSVSort>-2.4))&&mJJ>70&&mJJ<150&&svMass>90&&svMass<150");
   parser.addOption("1jet1tag",optutl::CommandLineParser::kString,"Requirement for MSSM Categories 2","J1PtCSVSort>20&&J1EtaCSVSort<2.4&&J1EtaCSVSort>-2.4&&nJetsBTagCSVTPt20==1&&(!(J2PtCSVSort>20&&J2EtaCSVSort<2.4&&J2EtaCSVSort>-2.4))&&mJJ>70&&mJJ<150&&svMass>90&&svMass<150");
   parser.addOption("2jet0tag",optutl::CommandLineParser::kString,"Requirement for MSSM Categories 3","J1PtCSVSort>20&&J1EtaCSVSort<2.4&&J1EtaCSVSort>-2.4&&J2PtCSVSort>20&&J2EtaCSVSort<2.4&&J2EtaCSVSort>-2.4&&nJetsBTagCSVMPt20==0&&mJJ>70&&mJJ<150&&svMass>90&&svMass<150");
   parser.addOption("2jet1tag",optutl::CommandLineParser::kString,"Requirement for MSSM Categories 4","J1PtCSVSort>20&&J1EtaCSVSort<2.4&&J1EtaCSVSort>-2.4&&J2PtCSVSort>20&&J2EtaCSVSort<2.4&&J2EtaCSVSort>-2.4&&nJetsBTagCSVMPt20==1&&mJJ>70&&mJJ<150&&svMass>90&&svMass<150");
   parser.addOption("2jet2tag",optutl::CommandLineParser::kString,"Requirement for MSSM Categories 5","J1PtCSVSort>20&&J1EtaCSVSort<2.4&&J1EtaCSVSort>-2.4&&J2PtCSVSort>20&&J2EtaCSVSort<2.4&&J2EtaCSVSort>-2.4&&nJetsBTagCSVMPt20>1&&mJJ>70&&mJJ<150&&svMass>90&&svMass<150");




   parser.parseArguments (argc, argv);
   std::vector<int> bitmask = parser.integerVector("bitMask");
   DataCardCreatorHhh creator(parser);

   printf("Binning KinFit has %d entries, HighStat has %d entries ,LowStat has %d entries\n",(int)parser.doubleVector("binningKinFit").size(),(int)parser.doubleVector("binningHighStat").size(),(int)parser.doubleVector("binningLowStat").size());

     //Inclusive
     //setHighStat Binning
     creator.setBinning(parser.doubleVector("binningKinFit"));
     
     printf("INCLUSIVE-------------------------------------\n");
     
     BkgOutput output = creator.runOSLSMT(parser.stringValue("preselection"),"_inclusive",parser.stringValue("zEmbeddedSample"),parser.doubleValue("topSF"));

     creator.makeHeavyHiggsShape(parser.stringValue("preselection"),parser.stringValue("preselection"),"_inclusive");

     
     if(bitmask[0]==1){	 
       creator.setBinning(parser.doubleVector("binningKinFit"));
       std::string MSSM1 = parser.stringValue("btagSelection"); 
       std::string bTagSF1 = parser.stringValue("bTagSF");
       //std::string MSSM2 = parser.stringValue("btagSelection"); 
       //std::string bTagSF2 = parser.stringValue("bTagSF");
       
       creator.makeHeavyHiggsShape(parser.stringValue("preselection"),MSSM1,"_1btag");
       std::cout<<std::endl;
       std::cout<<"========Running 1 btag selection========"<<std::endl;
       BkgOutput outputMSSM1btag = creator.runFullExtrapBtag(parser.stringValue("btagRelaxedSelection"),parser.stringValue("preselection"),MSSM1,"_1btag",parser.stringValue("zEmbeddedSample"),parser.doubleValue("topSF"),
							     1,//parser.doubleValue("zExtrap"),
							     1,//parser.doubleValue("zExtrapErr"),
							     bTagSF1
							     );
       std::string MSSM2 = parser.stringValue("btagSelection2"); 
       std::string bTagSF2 = parser.stringValue("bTagSF2");							     

       creator.makeHeavyHiggsShape(parser.stringValue("preselection"),MSSM2,"_2btag");
       std::cout<<std::endl;
       std::cout<<"========Running 2 btag selection========"<<std::endl;
       BkgOutput outputMSSM2btag = creator.runFullExtrapBtag(parser.stringValue("btagRelaxedSelection"),parser.stringValue("preselection"),MSSM2,"_2btag",parser.stringValue("zEmbeddedSample"),parser.doubleValue("topSF"),
							     1,//parser.doubleValue("zExtrap"),
							     1,//parser.doubleValue("zExtrapErr"),
							     bTagSF2
							     );
       /*
       BkgOutput outputMSSM2btag = creator.runFullExtrapolationBTag(parser.stringValue("preselection"),MSSM2,"_2btag",output,
								 parser.doubleValue("bFactorZ"),
								 parser.doubleValue("bFactorZErr"),
								 parser.doubleValue("bFactorW"),
								 parser.doubleValue("bFactorWErr"),
								 parser.doubleValue("topSF"),
								 parser.doubleValue("bIDErr"),
								 parser.stringValue("zEmbeddedSample"),
								 bTagSF2
								 );
       */
     }//end btag selection
 	//run limit categories
	if(bitmask[1]==1){


		creator.setBinning(parser.doubleVector("binningKinFit"));

		std::cout<<"========Running 1 jet 0 tag selection========"<<std::endl;
		std::string MSSM1 = parser.stringValue("1jet0tag"); 
		std::string bTagSF1 = parser.stringValue("bTagSF");


		creator.makeHeavyHiggsShape(parser.stringValue("preselection"),MSSM1,"_1jet0tag");

		BkgOutput outputMSSM1jet0tag = creator.runFullExtrapBtag(parser.stringValue("btagRelaxedSelection"),parser.stringValue("preselection"),MSSM1,"_1jet0tag", parser.stringValue("zEmbeddedSample"),parser.doubleValue("topSF"),
				1,//parser.doubleValue("zExtrap"),
				1,//parser.doubleValue("zExtrapErr"),
				bTagSF1
				);


		std::cout<<"========Running 1 jet 1 tag selection========"<<std::endl;
		std::string MSSM2 = parser.stringValue("1jet1tag"); 
		std::string bTagSF2 = parser.stringValue("bTagSF");							     

		creator.makeHeavyHiggsShape(parser.stringValue("preselection"),MSSM2,"_1jet1tag");
		BkgOutput outputMSSM1jet1tag = creator.runFullExtrapBtag(parser.stringValue("btagRelaxedSelection"),parser.stringValue("preselection"),MSSM2,"_1jet1tag",parser.stringValue("zEmbeddedSample"),parser.doubleValue("topSF"),
				1,//parser.doubleValue("zExtrap"),
				1,//parser.doubleValue("zExtrapErr"),
				bTagSF2
				);

		creator.setBinning(parser.doubleVector("binningKinFit"));
		std::cout<<"========Running 2 jet 0 tag selection========"<<std::endl;
		std::string MSSM3 = parser.stringValue("2jet0tag"); 
		std::string bTagSF3 = parser.stringValue("bTagSF");					 

		creator.makeHeavyHiggsShape(parser.stringValue("preselection"),MSSM3,"_2jet0tag");
		BkgOutput outputMSSM2jet0tag = creator.runFullExtrapBtag(parser.stringValue("relaxedSelection"),parser.stringValue("preselection"),MSSM3,"_2jet0tag",parser.stringValue("zEmbeddedSample"),parser.doubleValue("topSF"),
				1,//parser.doubleValue("zExtrap"),
				1,//parser.doubleValue("zExtrapErr"),
				bTagSF3
				);


		std::cout<<"========Running 2 jet 1 tag selection========"<<std::endl;
		std::string MSSM4 = parser.stringValue("2jet1tag"); 
		std::string bTagSF4 = parser.stringValue("bTagSF");							     

		creator.makeHeavyHiggsShape(parser.stringValue("preselection"),MSSM4,"_2jet1tag");
		BkgOutput outputMSSM2jet1tag = creator.runFullExtrapBtag(parser.stringValue("btagRelaxedSelection"),parser.stringValue("preselection"),MSSM4,"_2jet1tag",parser.stringValue("zEmbeddedSample"),parser.doubleValue("topSF"),
				1,//parser.doubleValue("zExtrap"),     	
				1,//parser.doubleValue("zExtrapErr"),
				bTagSF4
				);

		creator.setBinning(parser.doubleVector("binningKinFit"));
		std::cout<<"========Running 2 jet 2 tag selection========"<<std::endl;
		std::string MSSM5 = parser.stringValue("2jet2tag"); 
		std::string bTagSF5 = parser.stringValue("bTagSF2");							     

		creator.makeHeavyHiggsShape(parser.stringValue("preselection"),MSSM5,"_2jet2tag");
		BkgOutput outputMSSM2jet2tag = creator.runFullExtrapBtag(parser.stringValue("btagRelaxedSelection2"),parser.stringValue("preselection"),MSSM5,"_2jet2tag",parser.stringValue("zEmbeddedSample"),parser.doubleValue("topSF"),
				1,//parser.doubleValue("zExtrap"),
				1,//parser.doubleValue("zExtrapErr"),
				bTagSF5
				);
	}//end if 
	if(bitmask[1]==2){

		creator.setBinning(parser.doubleVector("binningKinFit"));
		std::cout<<"========Running 2 jet 0 tag selection========"<<std::endl;
		std::string MSSM3 = parser.stringValue("2jet0tag"); 
		std::string bTagSF3 = parser.stringValue("bTagSF");					 

		creator.makeHeavyHiggsShape(parser.stringValue("preselection"),MSSM3,"_2jet0tag");
		BkgOutput outputMSSM2jet0tag = creator.runFullExtrapBtag(parser.stringValue("relaxedSelection"),parser.stringValue("preselection"),MSSM3,"_2jet0tag",parser.stringValue("zEmbeddedSample"),parser.doubleValue("topSF"),
				1,//parser.doubleValue("zExtrap"),
				1,//parser.doubleValue("zExtrapErr"),
				bTagSF3
				);


		std::cout<<"========Running 2 jet 1 tag selection========"<<std::endl;
		std::string MSSM4 = parser.stringValue("2jet1tag"); 
		std::string bTagSF4 = parser.stringValue("bTagSF");							     

		creator.makeHeavyHiggsShape(parser.stringValue("preselection"),MSSM4,"_2jet1tag");
		BkgOutput outputMSSM2jet1tag = creator.runFullExtrapBtag(parser.stringValue("btagRelaxedSelection"),parser.stringValue("preselection"),MSSM4,"_2jet1tag",parser.stringValue("zEmbeddedSample"),parser.doubleValue("topSF"),
				1,//parser.doubleValue("zExtrap"),     	
				1,//parser.doubleValue("zExtrapErr"),
				bTagSF4
				);

		creator.setBinning(parser.doubleVector("binningKinFit"));
		std::cout<<"========Running 2 jet 2 tag selection========"<<std::endl;
		std::string MSSM5 = parser.stringValue("2jet2tag"); 
		std::string bTagSF5 = parser.stringValue("bTagSF2");							     

		creator.makeHeavyHiggsShape(parser.stringValue("preselection"),MSSM5,"_2jet2tag");
		BkgOutput outputMSSM2jet2tag = creator.runFullExtrapBtag(parser.stringValue("btagRelaxedSelection2"),parser.stringValue("preselection"),MSSM5,"_2jet2tag",parser.stringValue("zEmbeddedSample"),parser.doubleValue("topSF"),
				1,//parser.doubleValue("zExtrap"),
				1,//parser.doubleValue("zExtrapErr"),
				bTagSF5
				);
	}//end if 






     creator.close();
}


