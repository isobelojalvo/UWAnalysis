import FWCore.ParameterSet.Config as cms


#Import tool that creates the cut sequence
from UWAnalysis.Configuration.tools.CutSequenceProducer import *

###############################			Ele-Tau 		###################################
TTanalysisConfigurator = CutSequenceProducer(initialCounter  = 'initialEventsTT',
                                  pyModuleName = __name__,
                                  pyNameSpace  = locals())

TTanalysisConfigurator.addSmearing('patOverloadedTaus','miniAODMuonID','miniAODElectronVID','filteredJets','slimmedMETs','TT')

#Make DiTaus
TTanalysisConfigurator.addDiCandidateModule('tauTaus','PATDiTauPairProducer','smearedElectronsTT','smearedTausTT','smearedMETTT','smearedTausTT','smearedJetsTT',1,9999,text = 'AtLeastOneEleTau',leadingObjectsOnly = False,dR = 0.5,recoMode = "",genParticles='prunedGenParticles')

TTanalysisConfigurator.addSelector('tauTausElePtEta','PATDiTauPairSelector','leg1.pt()>25&&abs(leg1.eta())<2.1','TTelectronPtEta',1)
TTanalysisConfigurator.addSelector('tauTausTauPtEta','PATDiTauPairSelector','leg2.pt()>20&&abs(leg2.eta())<2.1','TTTauPtEta',1)
TTanalysisConfigurator.addSelector('tauTausDecayFound','PATDiTauPairSelector','abs(leg1.userFloat("taudZ"))<0.2&&leg1.tauID("decayModeFinding")>0.5','TTTauDecayFound',1)
TTanalysisConfigurator.addSelector('tauTausDecayFound','PATDiTauPairSelector','abs(leg2.userFloat("taudZ"))<0.2&&leg2.tauID("decayModeFinding")>0.5','TTTauDecayFound',1)
TTanalysisConfigurator.addSelector('tauTausTauLooseIsolation','PATDiTauPairSelector','leg1.tauID("byLooseIsolationMVArun2v1DBoldDMwLT") > 0.5','TTTauLooseIso',1)
TTanalysisConfigurator.addSelector('tauTausTauLooseIsolation','PATDiTauPairSelector','leg2.tauID("byLooseIsolationMVArun2v1DBoldDMwLT") > 0.5','TTTauLooseIso',1)
#TTanalysisConfigurator.addEleTauLVeto('tauTausLVeto','TightElectrons','TightMuons')
TTanalysisConfigurator.addSorter('tauTausSorted','PATDiTauPairSorter')
TTanalysisConfigurator.addSelector('tauTausTauIsolation','PATDiTauPairSelector','leg1.tauID("byTightIsolationMVArun2v1DBoldDMwLT") > 0.5','TTTauMediumIso',1)
TTanalysisConfigurator.addSelector('tauTausTauIsolation','PATDiTauPairSelector','leg2.tauID("byTightIsolationMVArun2v1DBoldDMwLT") > 0.5','TTTauMediumIso',1)
TTanalysisConfigurator.addSelector('tauTausTauMuonVeto','PATDiTauPairSelector','leg1.tauID("againstMuonLoose3")','TTAgainstMuon',1)
TTanalysisConfigurator.addSelector('tauTausTauMuonVeto','PATDiTauPairSelector','leg2.tauID("againstMuonLoose3")','TTAgainstMuon',1)
TTanalysisConfigurator.addSelector('tauTausTauElectronVeto','PATDiTauPairSelector','leg1.tauID("againstElectronTightMVA6")>0','TTAgainstElectron',1)
TTanalysisConfigurator.addSelector('tauTausTauElectronVeto','PATDiTauPairSelector','leg2.tauID("againstElectronTightMVA6")>0','TTAgainstElectron',1)
TTanalysisConfigurator.addSelector('tauTausOS','PATDiTauPairSelector','charge==0','TTOS',1)

#create the sequence
selectionSequenceTT =TTanalysisConfigurator.returnSequence()

