#include "TH1F.h"
#include "TH2F.h"
#include "THStack.h"
#include "TTree.h"
#include "TChain.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TProfile.h"
#include <vector>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

std::string returnEEEECuts(std::string cutType="selection"){
	if (cutType=="selection") {
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&(z1l1CiCTight&1)==1&&(z1l2CiCTight&1)==1&&z1l1MissHits<2&&z1l2MissHits<2&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>7&&z2l2Pt>7&&z2Charge==0&&z2l2RelPFIsoDB<0.25&&z2l1RelPFIsoDB<0.25&&(z2l1CiCTight&1)==1&&(z2l2CiCTight&1)==1&&z2l1MissHits<2&&z2l2MissHits<2";
	} else if (cutType=="selectionEWK") {
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&(z1l1CiCTight&1)==1&&(z1l2CiCTight&1)==1&&z1l1MissHits<2&&z1l2MissHits<2&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>10&&z2l2Pt>10&&z2Charge==0&&z2l2RelPFIsoDB<0.25&&z2l1RelPFIsoDB<0.25&&(z2l1CiCTight&1)==1&&(z2l2CiCTight&1)==1&&z2l1MissHits<2&&z2l2MissHits<2&&(z2l1Pt+z2l2Pt)>20&&z2Mass>60&&z2Mass<120";
	} else if (cutType=="selectionNoIso"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&(z1l1CiCTight&1)==1&&(z1l2CiCTight&1)==1&&z1l1MissHits<2&&z1l2MissHits<2&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>7&&z2l2Pt>7&&z2Charge==0&&(z2l1CiCTight&1)==1&&(z2l2CiCTight&1)==1&&z2l1MissHits<2&&z2l2MissHits<2&&(z2l1Pt+z2l2Pt)>20&&z2Mass>12";
	} else if (cutType=="selectionAbs") {
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&(z1l1CiCTight&1)==1&&(z1l2CiCTight&1)==1&&z1l1MissHits<2&&z1l2MissHits<2&&((z1l1Pt>20&&z1l1RelPFIsoDB<0.25)||(z1l1Pt<20&&z1l1AbsPFIsoDB<5))&&((z1l2Pt>20&&z1l2RelPFIsoDB<0.25)||(z1l2Pt<20&&z1l2AbsPFIsoDB<5))&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>7&&z2l2Pt>7&&z2Charge==0&&((z2l2Pt>20&&z2l2RelPFIsoDB<0.25)||(z2l2Pt<20&&z2l2AbsPFIsoDB<5))&&((z2l1Pt>20&&z2l1RelPFIsoDB<0.25)||(z2l1Pt<20&&z2l1AbsPFIsoDB<5))&&(z2l1CiCTight&1)==1&&(z2l2CiCTight&1)==1&&z2l1MissHits<2&&z2l2MissHits<2&&(z2l1Pt+z2l2Pt)>20&&z2Mass>12";
	} else if (cutType=="selectionLoose4") {
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&(z1l1CiCTight&1)==1&&(z1l2CiCTight&1)==1&&z1l1MissHits<2&&z1l2MissHits<2&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>7&&z2l2Pt>7&&z2Charge==0&&z2l2RelPFIsoDB<0.25&&z2l1RelPFIsoDB<0.25&&(z2l1CiCTight&1)==1&&z2l2CiCLoose&1==1&&z2l1MissHits<2&&z2l2MissHits<2&&(z2l1Pt+z2l2Pt)>20&&z2Mass>12";
	} else if (cutType=="selectionLoose4Abs"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&(z1l1CiCTight&1)==1&&(z1l2CiCTight&1)==1&&z1l1MissHits<2&&z1l2MissHits<2&&((z1l1Pt>20&&z1l1RelPFIsoDB<0.25)||(z1l1Pt<20&&z1l1AbsPFIsoDB<5))&&((z1l2Pt>20&&z1l2RelPFIsoDB<0.25)||(z1l2Pt<20&&z1l2AbsPFIsoDB<5))&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>7&&z2l2Pt>7&&z2Charge==0&&((z2l2Pt>20&&z2l2RelPFIsoDB<0.25)||(z2l2Pt<20&&z2l2AbsPFIsoDB<5))&&((z2l1Pt>20&&z2l1RelPFIsoDB<0.25)||(z2l1Pt<20&&z2l1AbsPFIsoDB<5))&&(z2l1CiCTight&1)==1&&z2l2CiCLoose&1==1&&z2l1MissHits<2&&z2l2MissHits<2&&(z2l1Pt+z2l2Pt)>20&&z2Mass>12";
	} else if (cutType=="selectionLoose4") {
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&(z1l1CiCTight&1)==1&&(z1l2CiCTight&1)==1&&z1l1MissHits<2&&z1l2MissHits<2&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>7&&z2l2Pt>7&&z2Charge==0&&z2l2RelPFIsoDB<0.25&&z2l1RelPFIsoDB<0.25&&(z2l1CiCTight&1)==1&&z2l2CiCLoose&1==1&&z2l1MissHits<2&&z2l2MissHits<2&&(z2l1Pt+z2l2Pt)>20&&z2Mass>12";
	} else if (cutType=="selectionFake") {
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&(z1l1CiCTight&1)==1&&(z1l2CiCTight&1)==1&&z1l1MissHits<2&&z1l2MissHits<2&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>10&&z2l2Pt>10&&z2Charge==0&&z2l1RelPFIsoDB>0.25&&z2l2RelPFIsoDB>0.25&&(z2l1CiCTight&1)==1&&(z2l2CiCTight&1)==1";
	} else if (cutType=="selectionSS"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&(z1l1CiCTight&1)==1&&(z1l2CiCTight&1)==1&&z1l1MissHits<2&&z1l2MissHits<2&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>7&&z2l2Pt>7&&z2Charge!=0&&z2l2RelPFIsoDB<0.25&&z2l1RelPFIsoDB<0.25&&(z2l1CiCTight&1)==1&&(z2l2CiCTight&1)==1&&z2l1MissHits<2&&z2l2MissHits<2&&(z2l1Pt+z2l2Pt)>20&&z2Mass>12";
	}
	else {
		return returnEEEECuts();
		std::cout << "Not a valid cut type!" << std::endl;
	}
}

std::string returnEEMMCuts(std::string cutType="selection"){
	if (cutType=="selection") {
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&(z1l1CiCTight&1)==1&&(z1l2CiCTight&1)==1&&z1l1MissHits<2&&z1l2MissHits<2&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>5&&z2l2Pt>5&&z2Charge==0&&z2l2RelPFIsoDB<0.25&&z2l1RelPFIsoDB<0.25";
	} else if (cutType=="selectionEWK") {
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&(z1l1CiCTight&1)==1&&(z1l2CiCTight&1)==1&&z1l1MissHits<2&&z1l2MissHits<2&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>10&&z2l2Pt>10&&z2Charge==0&&z2l2RelPFIsoDB<0.25&&z2l1RelPFIsoDB<0.25&&(z2l1Pt+z2l2Pt)>20&&z2Mass>60&&z2Mass<120";
	} else if (cutType=="selectionNoIso"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&(z1l1CiCTight&1)==1&&(z1l2CiCTight&1)==1&&z1l1MissHits<2&&z1l2MissHits<2&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>5&&z2l2Pt>5&&z2Charge==0&&(z2l1Pt+z2l2Pt)>20&&z2Mass>12";
	} else if (cutType=="selectionAbs"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&(z1l1CiCTight&1)==1&&(z1l2CiCTight&1)==1&&z1l1MissHits<2&&z1l2MissHits<2&&((z1l1Pt>20&&z1l1RelPFIsoDB<0.25)||(z1l1Pt<20&&z1l1AbsPFIsoDB<5))&&((z1l2Pt>20&&z1l2RelPFIsoDB<0.25)||(z1l2Pt<20&&z1l2AbsPFIsoDB<5))&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>5&&z2l2Pt>5&&z2Charge==0&&((z2l2Pt>20&&z2l2RelPFIsoDB<0.25)||(z2l2Pt<20&&z2l2AbsPFIsoDB<5))&&((z2l1Pt>20&&z2l1RelPFIsoDB<0.25)||(z2l1Pt<20&&z2l1AbsPFIsoDB<5))&&(z2l1Pt+z2l2Pt)>20&&z2Mass>12";
	} else if (cutType=="selectionSS"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&(z1l1CiCTight&1)==1&&(z1l2CiCTight&1)==1&&z1l1MissHits<2&&z1l2MissHits<2&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>5&&z2l2Pt>5&&z2Charge!=0&&z2l2RelPFIsoDB<0.25&&z2l1RelPFIsoDB<0.25&&(z2l1Pt+z2l2Pt)>20&&z2Mass>12";
	}
	else{
		return reuturnEEMMCuts();
		std::cout << "Not a valid cut type!" << std::endl;
	}
}

std::string returnMMEECuts(std::string cutType="selection"){
	if (cutType=="selection") {
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>7&&z2l2Pt>7&&z2Charge==0&&z2l2RelPFIsoDB<0.25&&z2l1RelPFIsoDB<0.25&&(z2l1CiCTight&1)==1&&(z2l2CiCTight&1)==1&&z2l1MissHits<2&&z2l2MissHits<2";
	} else if (cutType=="selectionEWK") {
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>10&&z2l2Pt>10&&z2Charge==0&&z2l2RelPFIsoDB<0.25&&z2l1RelPFIsoDB<0.25&&(z2l1CiCTight&1)==1&&(z2l2CiCTight&1)==1&&z2l1MissHits<2&&z2l2MissHits<2&&(z2l1Pt+z2l2Pt)>20&&z2Mass>60&&z2Mass<120";
	} else if (cutType=="selectionNoIso"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>7&&z2l2Pt>7&&z2Charge==0&&(z2l1CiCTight&1)==1&&(z2l2CiCTight&1)==1&&z2l1MissHits<2&&z2l2MissHits<2&&(z2l1Pt+z2l2Pt)>20&&z2Mass>12";
	} else if (cutType=="selectionAbs"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&((z1l1Pt>20&&z1l1RelPFIsoDB<0.25)||(z1l1Pt<20&&z1l1AbsPFIsoDB<5))&&((z1l2Pt>20&&z1l2RelPFIsoDB<0.25)||(z1l2Pt<20&&z1l2AbsPFIsoDB<5))&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>7&&z2l2Pt>7&&z2Charge==0&&((z2l2Pt>20&&z2l2RelPFIsoDB<0.25)||(z2l2Pt<20&&z2l2AbsPFIsoDB<5))&&((z2l1Pt>20&&z2l1RelPFIsoDB<0.25)||(z2l1Pt<20&&z2l1AbsPFIsoDB<5))&&(z2l1CiCTight&1)==1&&(z2l2CiCTight&1)==1&&z2l1MissHits<2&&z2l2MissHits<2&&(z2l1Pt+z2l2Pt)>20&&z2Mass>12";
	} else if (cutType=="selectionFake"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>10&&z2l2Pt>10&&z2Charge==0&&z2l1RelPFIsoDB>0.25&&z2l2RelPFIsoDB>0.25&&(z2l1CiCTight&1)==1&&(z2l2CiCTight&1)==1";
	} else if (cutType=="selectionSS"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>7&&z2l2Pt>7&&z2Charge!=0&&z2l2RelPFIsoDB<0.25&&z2l1RelPFIsoDB<0.25&&(z2l1CiCTight&1)==1&&(z2l2CiCTight&1)==1&&z2l1MissHits<2&&z2l2MissHits<2&&(z2l1Pt+z2l2Pt)>20&&z2Mass>12";
	}
	else{
		return returnMMEECuts();
		std::cout << "Not a valid cut type!" << std::endl;
	}
}

std::string returnMMMMCuts(std::string cutType="selection"){
	if (cutType=="selection"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>5&&z2l2Pt>5&&z2Charge==0&&z2l2RelPFIsoDB<0.25&&z2l1RelPFIsoDB<0.25";
	} else if (cutType=="selectionEWK"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>10&&z2l2Pt>10&&z2Charge==0&&z2l2RelPFIsoDB<0.25&&z2l1RelPFIsoDB<0.25&&(z2l1Pt+z2l2Pt)>20&&z2Mass>60&&z2Mass<120";
	} else if (cutType=="selectionAbs"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&((z1l1Pt>20&&z1l1RelPFIsoDB<0.25)||(z1l1Pt<20&&z1l1AbsPFIsoDB<5))&&((z1l2Pt>20&&z1l2RelPFIsoDB<0.25)||(z1l2Pt<20&&z1l2AbsPFIsoDB<5))&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>5&&z2l2Pt>5&&z2Charge==0&&((z2l2Pt>20&&z2l2RelPFIsoDB<0.25)||(z2l2Pt<20&&z2l2AbsPFIsoDB<5))&&((z2l1Pt>20&&z2l1RelPFIsoDB<0.25)||(z2l1Pt<20&&z2l1AbsPFIsoDB<5))&&(z2l1Pt+z2l2Pt)>20&&z2Mass>12";
	} else if (cutType=="selectionFake"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>10&&z2l2Pt>10&&z2Charge==0&&z2l2RelPFIsoDB>0.25&&z2l1RelPFIsoDB>0.25";
	} else if (cutType=="selectionSS"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>5&&z2l2Pt>5&&z2Charge!=0&&z2l2RelPFIsoDB<0.25&&z2l1RelPFIsoDB<0.25&&(z2l1Pt+z2l2Pt)>20&&z2Mass>12";
	} else{
		return returnMMMMCuts();
		std::cout << "Not a valid cut type!" << std::endl;
	}
}

std::string returnEEETCuts(std::string cutType="selection"){
	if (cutType=="selection"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&(z1l1CiCTight&1)==1&&(z1l2CiCTight&1)==1&&z1l1MissHits<2&&z1l2MissHits<2&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l2EleVeto&&(z2l1CiCTight&1)==1&&z2l2LooseIsoCombDB&&z2l2Pt>20&&z2l1Pt>10&&z2l1RelPFIsoDB<0.1&&z2l1MissHits==0&&z2l2MuVeto&&z2Charge==0&&z2Mass>30&&z2Mass<80";
	} else if (cutType=="selectionNoIso"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&(z1l1CiCTight&1)==1&&(z1l2CiCTight&1)==1&&z1l1MissHits<2&&z1l2MissHits<2&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l2EleVeto&&z2l1CiCSuperTight&1==1&&z2l2Pt>20&&z2l1Pt>10&&z2l1MissHits==0&&z2l2MuVeto&&z2Charge==0&&z2Mass>30&&z2Mass<80";
	} else if (cutType=="selectionFake"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&(z1l1CiCTight&1)==1&&(z1l2CiCTight&1)==1&&z1l1MissHits<2&&z1l2MissHits<2&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l2EleVeto&&(z2l1CiCTight&1)==1&&!z2l2LooseIsoCombDB&&z2l2Pt>20&&z2l1Pt>10&&z2l1RelPFIsoDB<0.10&&z2l1MissHits==0&&z2l2MuVeto&&z2Charge==0&&z2Mass>30&&z2Mass<80";
	} else if (cutType=="selectionSS"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&(z1l1CiCTight&1)==1&&(z1l2CiCTight&1)==1&&z1l1MissHits<2&&z1l2MissHits<2&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l2EleVeto&&(z2l1CiCTight&1)==1&&z2l2LooseIsoCombDB&&z2l2Pt>15&&z2l1Pt>10&&z2l1RelPFIsoDB<0.1&&z2l1MissHits==0&&z2l2MuVeto&&z2Charge!=0";
	}
	else {
		return returnEEETCuts();
		std::cout << "Not a valid cut type!" << std::endl;
	}
}

std::string returnEEEMCuts(std::string cutType="selection"){
	if (cutType=="selection"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&(z1l1CiCTight&1)==1&&(z1l2CiCTight&1)==1&&z1l1MissHits<2&&z1l2MissHits<2&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>10&&z2l2Pt>10&&(z2l1CiCTight&1)==1&&z2l1MissHits<2&&z2Charge==0&&z2l1RelPFIsoDB<0.25&&z2l2RelPFIsoDB<0.25&&z2Mass<90";
	} else if (cutType=="selectionNoIso"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&(z1l1CiCTight&1)==1&&(z1l2CiCTight&1)==1&&z1l1MissHits<2&&z1l2MissHits<2&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>10&&z2l2Pt>10&&(z2l1CiCTight&1)==1&&z2l1MissHits<2&&z2Charge==0&&z2Mass>30&&z2Mass<80"; 
	} else if (cutType=="selectionFake"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&(z1l1CiCTight&1)==1&&(z1l2CiCTight&1)==1&&z1l1MissHits<2&&z1l2MissHits<2&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>10&&z2l2Pt>10&&z2l1MissHits<2&&z2Charge==0&&z2l1RelPFIsoDB>0.25&&z2l2RelPFIsoDB>0.25&&z2Mass<90"; 
	} else if (cutType=="selectionSS"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&(z1l1CiCTight&1)==1&&(z1l2CiCTight&1)==1&&z1l1MissHits<2&&z1l2MissHits<2&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>10&&z2l2Pt>10&&(z2l1CiCTight&1)==1&&z2l1MissHits<2&&z2Charge!=0&&z2l1RelPFIsoDB<0.25&&z2l2RelPFIsoDB<0.25&&z2Mass<90";
	}
	else{
		return returnEEEMCuts();
		std::cout << "Not a valid cut type!" << std::endl;
	}
}

std::string returnEEMTCuts(std::string cutType="selection"){
	if (cutType=="selection"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&(z1l1CiCTight&1)==1&&(z1l2CiCTight&1)==1&&z1l1MissHits<2&&z1l2MissHits<2&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l2EleVeto&&z2l2LooseIsoCombDB&&z2l2MuVetoTight&&z2l1RelPFIsoDB<0.15&&z2l2Pt>20&&z2l1Pt>10&&z2Charge==0&&z2Mass>30&&z2Mass<80";
	} else if (cutType=="selectionNoIso"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&(z1l1CiCTight&1)==1&&(z1l2CiCTight&1)==1&&z1l1MissHits<2&&z1l2MissHits<2&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l2EleVeto&&z2l2MuVetoTight&&z2l2Pt>20&&z2l1Pt>10&&z2Charge==0";
	} else if (cutType=="selectionFake"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&(z1l1CiCTight&1)==1&&(z1l2CiCTight&1)==1&&z1l1MissHits<2&&z1l2MissHits<2&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l2EleVeto&&!z2l2LooseIsoCombDB&&z2l2MuVetoTight&&z2l1RelPFIsoDB<0.15&&z2l2Pt>20&&z2l1Pt>10&&z2Charge==0&&z2Mass>30&&z2Mass<80";
	} else if (cutType=="selectionSS"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&(z1l1CiCTight&1)==1&&(z1l2CiCTight&1)==1&&z1l1MissHits<2&&z1l2MissHits<2&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l2EleVeto&&z2l2LooseIsoCombDB&&z2l2MuVetoTight&&z2l1RelPFIsoDB<0.15&&z2l2Pt>20&&z2l1Pt>10&&z2Charge!=0&&z2Mass>30&&z2Mass<80";
	}
	else{
		return returnMMETCuts();
		std::cout << "Not a valid cut type!" << std::endl;
	}
}

std::string returnEETTCuts(std::string cutType="selection"){
	if (cutType=="selection") {
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&(z1l1CiCTight&1)==1&&(z1l2CiCTight&1)==1&&z1l1MissHits<2&&z1l2MissHits<2&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>20&&z2l2Pt>20&&z2l1EleVeto&&z2l2EleVeto&&z2l1MediumIsoCombDB&&z2l2MediumIsoCombDB&&z2l1MuVeto&&z2l2MuVeto&&z2Charge==0&&z2Mass>30&&z2Mass<80";
	} else if (cutType=="selectionNoIso"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&(z1l1CiCTight&1)==1&&(z1l2CiCTight&1)==1&&z1l1MissHits<2&&z1l2MissHits<2&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>20&&z2l2Pt>20&&z2l1EleVeto&&z2l2EleVeto&&z2l1MuVeto&&z2l2MuVeto&&z2Charge==0&&z2Mass>30&&z2Mass<80";
	} else if (cutType=="selectionFake"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&(z1l1CiCTight&1)==1&&(z1l2CiCTight&1)==1&&z1l1MissHits<2&&z1l2MissHits<2&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>20&&z2l2Pt>20&&z2l1EleVeto&&z2l2EleVeto&&!z2l1MediumIsoCombDB&&!z2l2MediumIsoCombDB&&z2l1MuVeto&&z2l2MuVeto&&z2Charge==0&&z2Mass>30&&z2Mass<80";
	} else if (cutType=="selectionFake2"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&(z1l1CiCTight&1)==1&&(z1l2CiCTight&1)==1&&z1l1MissHits<2&&z1l2MissHits<2&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>15&&z2l2Pt>15&&z2l1EleVeto&&z2l2EleVeto&&z2l1LooseIsoCombDB&&z2l2LooseIsoCombDB&&z2l1MuVeto&&z2l2MuVeto&&z2Charge!=0";
	} else if (cutType=="selectionSS"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&(z1l1CiCTight&1)==1&&(z1l2CiCTight&1)==1&&z1l1MissHits<2&&z1l2MissHits<2&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>15&&z2l2Pt>15&&z2l1EleVeto&&z2l2EleVeto&&z2l1LooseIsoCombDB&&z2l2LooseIsoCombDB&&z2l1MuVeto&&z2l2MuVeto&&z2Charge!=0";
	}
	else {
		return returnEETTCuts();
		std::cout << "Not a valid cut type!" << std::endl;
	}
}

std::string returnMMETCuts(std::string cutType="selection"){
	if (cutType=="selection") {
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l2EleVeto&&(z2l1CiCTight&1)==1&&z2l2LooseIsoCombDB&&z2l2Pt>20&&z2l1Pt>10&&z2l1RelPFIsoDB<0.1&&z2l1MissHits==0&&z2l2MuVeto&&z2Charge==0&&z2Mass>30&&z2Mass<80&&EVENT!=286336207";
	} else if (cutType=="selectionNoIso"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l2EleVeto&&z2l1CiCSuperTight&1==1&&z2l2Pt>20&&z2l1Pt>10&&z2l1MissHits==0&&z2l2MuVeto&&z2Charge==0&&z2Mass>30&&z2Mass<80";
	} else if (cutType=="selectionFake"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l2EleVeto&&(z2l1CiCTight&1)==1&&!z2l2LooseIsoCombDB&&z2l2Pt>20&&z2l1Pt>10&&z2l1RelPFIsoDB<0.10&&z2l1MissHits==0&&z2l2MuVeto&&z2Charge==0&&z2Mass>30&&z2Mass<80";
	} else if (cutType=="selectionSS"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l2EleVeto&&(z2l1CiCTight&1)==1&&z2l2LooseIsoCombDB&&z2l2Pt>20&&z2l1Pt>10&&z2l1RelPFIsoDB<0.1&&z2l1MissHits==0&&z2l2MuVeto&&z2Charge!=0&&&EVENT!=286336207";
	}
	else{
		return returnMMETCuts();
		std::cout << "Not a valid cut type!" << std::endl;
	}
}

std::string returnMMEMCuts(std::string cutType="selection"){
	if (cutType=="selection") {
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>10&&z2l2Pt>10&&(z2l1CiCTight&1)==1&&z2l1MissHits<2&&z2Charge==0&&z2l1RelPFIsoDB<0.25&&z2l2RelPFIsoDB<0.25&&z2Mass<90";
	} else if (cutType=="selectionNoIso"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>10&&z2l2Pt>10&&(z2l1CiCTight&1)==1&&z2l1MissHits<2&&z2Charge==0&&z2Mass>30&&z2Mass<80";
	} else if (cutType=="selectionFake"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>10&&z2l2Pt>10&&z2l1MissHits<2&&z2Charge==0&&z2l1RelPFIsoDB>0.25&&z2l2RelPFIsoDB>0.25&&z2Mass<90";
	} else if (cutType=="selectionSS"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>10&&z2l2Pt>10&&(z2l1CiCTight&1)==1&&z2l1MissHits<2&&z2Charge!=0&&z2l1RelPFIsoDB<0.25&&z2l2RelPFIsoDB<0.25&&z2Mass<90";
	}
	else{
		return returnMMEMCuts();
		std::cout << "Not a valid cut type!" << std::endl;
	}
}

std::string returnMMMTCuts(std::string cutType="selection"){
	if (cutType=="selection") {
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l2EleVeto&&z2l2LooseIsoCombDB&&z2l2MuVetoTight&&z2l1RelPFIsoDB<0.15&&z2l2Pt>20&&z2l1Pt>10&&z2Charge==0&&z2Mass>30&&z2Mass<80";
	} else if (cutType=="selectionNoIso"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l2EleVeto&&z2l2MuVetoTight&&z2l2Pt>20&&z2l1Pt>10&&z2Charge==0&&z2Mass>30&&z2Mass<80";
	} else if (cutType=="selectionFake"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l2EleVeto&&!z2l2LooseIsoCombDB&&z2l2MuVetoTight&&z2l1RelPFIsoDB<0.15&&z2l2Pt>20&&z2l1Pt>10&&z2Charge==0&&z2Mass>30&&z2Mass<80";
	} else if (cutType=="selectionSS"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l2EleVeto&&z2l2LooseIsoCombDB&&z2l2MuVetoTight&&z2l1RelPFIsoDB<0.15&&z2l2Pt>20&&z2l1Pt>10&&z2Charge!=0&&z2Mass>30&&z2Mass<80";
	}
	else{
		return returnMMMTCuts();
		std::cout << "Not a valid cut type!" << std::endl;
	}
}

std::string returnMMTTCuts(std::string cutType="selection"){
	if (cutType=="selection") {
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>20&&z2l2Pt>20&&z2l1EleVeto&&z2l2EleVeto&&z2l1MediumIsoCombDB&&z2l2MediumIsoCombDB&&z2l1MuVeto&&z2l2MuVeto&&z2Charge==0&&z2Mass>30&&z2Mass<80";
	} else if (cutType=="selectionNoIso"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>20&&z2l2Pt>20&&z2l1EleVeto&&z2l2EleVeto&&z2l1MuVeto&&z2l2MuVeto&&z2Charge==0&&z2Mass>30&&z2Mass<80"; 
	} else if (cutType=="selectionFake"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>20&&z2l2Pt>20&&z2l1EleVeto&&z2l2EleVeto&&!z2l1MediumIsoCombDB&&!z2l2MediumIsoCombDB&&z2l1MuVeto&&z2l2MuVeto&&z2Charge==0&&z2Mass>30&&z2Mass<80"; 
	} else if (cutType=="selectionFake2"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>15&&z2l2Pt>15&&z2l1EleVeto&&z2l2EleVeto&&z2l1LooseIsoCombDB&&z2l2LooseIsoCombDB&&z2l1MuVeto&&z2l2MuVeto&&z2Charge!=0"; 
	} else if (cutType=="selectionSS"){
		return "dZ12<0.10&&dZ13<0.10&&dZ14<0.10&&HLT_Any&&z1Mass>50&&z1Mass<120&&z1l1RelPFIsoDB<0.25&&z1l2RelPFIsoDB<0.25&&z1l1Pt>20&&z1l2Pt>10&&z2l1Pt>15&&z2l2Pt>15&&z2l1EleVeto&&z2l2EleVeto&&z2l1LooseIsoCombDB&&z2l2LooseIsoCombDB&&z2l1MuVeto&&z2l2MuVeto&&z2Charge!=0";
	}
	else{
		return returnMMTTCuts();
		printf("Not a valid cut type!");
		std::cout << "Not a valid cut type!" << std::endl;
	}
}

std::string z1l1MixedIso(){
	return "((z1l1Pt>20&&z1l1RelPFIsoDB<0.25)||(z1l1Pt<20&&z1l1RelPFIsoDB<0.25))";//*z1l1Pt<5))";
}
std::string z1l2MixedIso(){
	return "((z1l2Pt>20&&z1l2RelPFIsoDB<0.25)||(z1l2Pt<20&&z1l2RelPFIsoDB<0.25))";//*z1l2Pt<5))";
}
std::string z2l1MixedIso(){
	return "((z2l1Pt>20&&z2l1RelPFIsoDB<0.25)||(z2l1Pt<20&&z2l1RelPFIsoDB<0.25))";//*z2l1Pt<5))";
}
std::string z2l2MixedIso(){
	return "((z2l2Pt>20&&z2l2RelPFIsoDB<0.25)||(z2l2Pt<20&&z2l2RelPFIsoDB<0.25))";//*z2l2Pt<5))";
}

std::string returnCuts(TString channel, std::string  sel = ""){
	std::cout << "Selection type: " << sel << std::endl;
	if (channel=="eleEleEleTau") return returnEEETCuts(sel);
	else if (channel=="eleEleTauTau") return returnEETTCuts(sel);
	else if (channel=="eleEleEleMu") return returnEEEMCuts(sel);
	else if (channel=="eleEleMuTau") return returnEEMTCuts(sel);
	else if (channel=="muMuEleTau") return returnMMETCuts(sel);
	else if (channel=="muMuTauTau") return returnMMTTCuts(sel);
	else if (channel=="muMuEleMu") return returnMMEMCuts(sel);
	else if (channel=="muMuMuTau") return returnMMMTCuts(sel);
	else if (channel=="muMuMuMu") return returnMMMMCuts(sel);
	else if (channel=="muMuEleEle") return returnMMEECuts(sel);
	else if (channel=="eleEleMuMu") return returnEEMMCuts(sel);
	else if (channel=="eleEleEleEle") return returnEEEECuts(sel);
	else return "0";
}

std::string lZee(){
	return "...";
}
std::string lZmm(){
	return "...";
}
std::string sZee(){
	return "...";
}
std::string sZmm(){
	return  "...";
}
std::string sZem(){
	return "...";
}
std::string sZet(){
	return "...";
}
std::string sZtt(){
	return "...";
}
std::string sZmt(){
	return "...";
}
