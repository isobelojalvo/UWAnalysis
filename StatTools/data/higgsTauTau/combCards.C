{

gROOT->ProcessLine(".L renameDataCard.C");

renameDataCard("htt_et.0JetLow.root","htt_et.inputs-sm-8TeV.root","eleTau_inclusive","eleTau_inclusive");
renameDataCard("htt_et.0JetLow.root","htt_et.inputs-sm-8TeV.root","eleTau_0jet_low","eleTau_0jet_low");
renameDataCard("htt_et.0JetMed.root","htt_et.inputs-sm-8TeV.root","eleTau_0jet_medium","eleTau_0jet_medium");
renameDataCard("htt_et.0JetHigh.root","htt_et.inputs-sm-8TeV.root","eleTau_0jet_high","eleTau_0jet_high");
renameDataCard("htt_et.1JetLow.root","htt_et.inputs-sm-8TeV.root","eleTau_1jet_medium","eleTau_1jet_medium");
renameDataCard("htt_et.1JetHigh.root","htt_et.inputs-sm-8TeV.root","eleTau_1jet_high_lowhiggs","eleTau_1jet_high_lowhiggs");
renameDataCard("htt_et.boost.root","htt_et.inputs-sm-8TeV.root","eleTau_1jet_high_mediumhiggs","eleTau_1jet_high_mediumhiggs");
renameDataCard("htt_et.vbfLoose.root","htt_et.inputs-sm-8TeV.root","eleTau_vbf_loose","eleTau_vbf_loose");
renameDataCard("htt_et.vbfTight.root","htt_et.inputs-sm-8TeV.root","eleTau_vbf_tight","eleTau_vbf_tight");

renameDataCard("htt_mt.0JetLow.root","htt_mt.inputs-sm-8TeV.root","muTau_inclusive","muTau_inclusive");
renameDataCard("htt_mt.0JetLow.root","htt_mt.inputs-sm-8TeV.root","muTau_0jet_low","muTau_0jet_low");
renameDataCard("htt_mt.0JetMed.root","htt_mt.inputs-sm-8TeV.root","muTau_0jet_medium","muTau_0jet_medium");
renameDataCard("htt_mt.0JetHigh.root","htt_mt.inputs-sm-8TeV.root","muTau_0jet_high","muTau_0jet_high");
renameDataCard("htt_mt.1JetLow.root","htt_mt.inputs-sm-8TeV.root","muTau_1jet_medium","muTau_1jet_medium");
renameDataCard("htt_mt.1JetHigh.root","htt_mt.inputs-sm-8TeV.root","muTau_1jet_high_lowhiggs","muTau_1jet_high_lowhiggs");
renameDataCard("htt_mt.boost.root","htt_mt.inputs-sm-8TeV.root","muTau_1jet_high_mediumhiggs","muTau_1jet_high_mediumhiggs");
renameDataCard("htt_mt.vbfLoose.root","htt_mt.inputs-sm-8TeV.root","muTau_vbf_loose","muTau_vbf_loose");
renameDataCard("htt_mt.vbfTight.root","htt_mt.inputs-sm-8TeV.root","muTau_vbf_tight","muTau_vbf_tight");

}
