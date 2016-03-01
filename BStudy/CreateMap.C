#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
void CreateMap(){
	TFile *f_TTEffMap = new TFile("TTBar.root","READ");
	//TFile *f_ZJetsEffMap = new TFile("ZJets.root","READ");
	TFile *f_ZJetsEffMap = new TFile("ZJets_ext.root","READ");

	std::cout<<"Get TT Histos "<<std::endl;
	TH2D *h2_B_TT    = (TH2D*)f_TTEffMap->Get("effi/h2_BTaggingEff_Num_b");
	TH2D *h2_Denom_B_TT    = (TH2D*)f_TTEffMap->Get("effi/h2_BTaggingEff_Denom_b");
	TH2D *h2_C_TT    = (TH2D*)f_TTEffMap->Get("effi/h2_BTaggingEff_Num_c");
	TH2D *h2_Denom_C_TT    = (TH2D*)f_TTEffMap->Get("effi/h2_BTaggingEff_Denom_c");
	TH2D *h2_UDSG_TT = (TH2D*)f_TTEffMap->Get("effi/h2_BTaggingEff_Num_udsg");
	TH2D *h2_Denom_UDSG_TT = (TH2D*)f_TTEffMap->Get("effi/h2_BTaggingEff_Denom_udsg");


	std::cout<<"Get ZJets Histos "<<std::endl;
	TH2D *h2_B_ZJets    = (TH2D*)f_ZJetsEffMap->Get("effi/h2_BTaggingEff_Num_b");
	TH2D *h2_Denom_B_ZJets    = (TH2D*)f_ZJetsEffMap->Get("effi/h2_BTaggingEff_Denom_b");
	TH2D *h2_C_ZJets    = (TH2D*)f_ZJetsEffMap->Get("effi/h2_BTaggingEff_Num_c");
	TH2D *h2_Denom_C_ZJets    = (TH2D*)f_ZJetsEffMap->Get("effi/h2_BTaggingEff_Denom_c");
	TH2D *h2_UDSG_ZJets = (TH2D*)f_ZJetsEffMap->Get("effi/h2_BTaggingEff_Num_udsg");
	TH2D *h2_Denom_UDSG_ZJets = (TH2D*)f_ZJetsEffMap->Get("effi/h2_BTaggingEff_Denom_udsg");

	std::cout<<"Make New File Histos"<<std::endl;
	h2_B_TT->Divide(h2_Denom_B_TT);
	h2_C_TT->Divide(h2_Denom_C_TT);
	h2_UDSG_TT->Divide(h2_Denom_UDSG_TT);
	h2_B_ZJets->Divide(h2_Denom_B_ZJets);
	h2_C_ZJets->Divide(h2_Denom_C_ZJets);
	h2_UDSG_ZJets->Divide(h2_Denom_UDSG_ZJets);
	
	TFile f_Output("efficiency.root","RECREATE");
	f_Output.mkdir("TT_effi");
	f_Output.cd("TT_effi");
	h2_B_TT->Write("efficiency_b",TObject::kOverwrite);
	h2_C_TT->Write("efficiency_c",TObject::kOverwrite);
	h2_UDSG_TT->Write("efficiency_udsg",TObject::kOverwrite);

	f_Output.mkdir("ZJets_effi");
	f_Output.cd("ZJets_effi");
	h2_B_ZJets->Write("efficiency_b",TObject::kOverwrite);
	h2_C_ZJets->Write("efficiency_c",TObject::kOverwrite);
	h2_UDSG_ZJets->Write("efficiency_udsg",TObject::kOverwrite);

}
