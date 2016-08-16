import FWCore.ParameterSet.Config as cms


#Import tool that creates the cut sequence
from UWAnalysis.Configuration.tools.CutSequenceProducer import *

###############################			Ele-Tau 		###################################
ETanalysisConfigurator = CutSequenceProducer(initialCounter  = 'initialEventsET',
                                  pyModuleName = __name__,
                                  pyNameSpace  = locals())

#ETanalysisConfigurator.addSmearing('patOverloadedTaus','triggeredPatMuons','triggeredPatElectrons','filteredJets','MVAMET:MVAMET','ET')
ETanalysisConfigurator.addSmearing('patOverloadedTaus','triggeredPatMuons','triggeredPatElectrons','filteredJets','slimmedMETs','ET')
#ETanalysisConfigurator.addSmearing('patOverloadedTaus','miniAODMuonID','miniAODElectronVID','filteredJets','slimmedMETs','ET')

#create dielectrons
ETanalysisConfigurator.addDiCandidateModule('diElectrons','PATElePairProducer','smearedElectronsET','smearedElectronsET','slimmedMETs','','smearedJetsET',0,9999,text = '',leadingObjectsOnly = False,dR = 0.15,recoMode = "",genParticles='prunedGenParticles')
ETanalysisConfigurator.addSelector('diElectronsOS','PATElePairSelector','abs(leg1.eta())<2.5&&abs(leg2.eta())<2.5&&abs(leg1.userFloat("dXY"))<0.045&&abs(leg2.userFloat("dXY"))<0.045&&abs(leg1.userFloat("dZ"))<0.2&&abs(leg2.userFloat("dZ"))<0.2&&leg1.pt()>15&&leg2.pt()>15&&charge==0&&leg2.userFloat("CBIDVeto")>0&&leg1.userFloat("CBIDVeto")>0&&leg1.userFloat("dBRelIso03")<0.3&&leg2.userFloat("dBRelIso03")<0.3','DiElectronCreation',0,100)
ETanalysisConfigurator.addSorter('diElectronsOSSorted','PATElePairSorter')
#Make DiTaus
ETanalysisConfigurator.addDiCandidateModule('eleTaus','PATEleTauPairProducer','smearedElectronsET','smearedTausET','smearedMETET','smearedTausET','smearedJetsET',1,9999,text = 'AtLeastOneEleTau',leadingObjectsOnly = False,dR = 0.3,recoMode = "",genParticles='prunedGenParticles')
#ETanalysisConfigurator.addDiCandidateModule('eleTaus','PATEleTauPairProducer','smearedElectronsET','smearedTausET','smearedMETET','smearedTausET','smearedJetsET',1,9999,text = 'AtLeastOneEleTau',leadingObjectsOnly = False,dR = 0.5,recoMode = "",genParticles='prunedGenParticles')

ETanalysisConfigurator.addSelector('eleTausElePtEta','PATEleTauPairSelector','leg1.pt()>25&&abs(leg1.eta())<2.1','ETelectronPtEta',1)
ETanalysisConfigurator.addSelector('eleTausTauPtEta','PATEleTauPairSelector','leg2.pt()>20&&abs(leg2.eta())<2.3','ETTauPtEta',1)
ETanalysisConfigurator.addSelector('eleTausEleID','PATEleTauPairSelector','leg1.userFloat("eleMVAIDnonTrig80")>0','ElectronID',1)
ETanalysisConfigurator.addSelector('eleTausEleConvRej','PATEleTauPairSelector','leg1.userInt("eleConversion")==0','ETelectronConvRej',1)
ETanalysisConfigurator.addSelector('eleTausEleVertices','PATEleTauPairSelector','abs(leg1.userFloat("dZ"))<0.2&&abs(leg1.userFloat("dXY"))<0.045','ETelectronVertices',1)
ETanalysisConfigurator.addSelector('eleTausDecayFound','PATEleTauPairSelector','leg2.tauID("decayModeFinding")>0.5','ETTauDecayFound',1)
ETanalysisConfigurator.addSelector('eleTausDecayVertex','PATEleTauPairSelector','abs(leg2.userFloat("taudZ"))<0.2','ETTauVertexFound',1)
ETanalysisConfigurator.addSelector('eleTausTauLooseIsolation','PATEleTauPairSelector','(leg2.tauID("chargedIsoPtSumdR03"))/(leg2.pt()) < 0.3','ETTauLooseIso',1)
#ETanalysisConfigurator.addSelector('eleTausTauLooseIsolation','PATEleTauPairSelector','leg2.tauID("byLooseIsolationMVArun2v1DBoldDMwLT") > 0.5','ETTauLooseIso',1)
ETanalysisConfigurator.addSelector('eleTausChargeNot2','PATEleTauPairSelector','abs(leg2.charge())==1','ETChargeIsABS1',1)
ETanalysisConfigurator.addEleTauLVeto('eleTausLVeto','TightElectrons','TightMuons')
ETanalysisConfigurator.addSelector('eleTausEleVeto','PATEleTauPairSelector','lVeto==0','ETelectronVeto',1)
ETanalysisConfigurator.addSorter('eleTausSorted','PATEleTauPairSorter')
#ETanalysisConfigurator.addSelector('eleTausTauIsolation','PATEleTauPairSelector','leg2.tauID("byTightIsolationMVArun2v1DBoldDMwLT") > 0.5','ETTauMediumIso',1)
ETanalysisConfigurator.addSelector('eleTausTauIsolation','PATEleTauPairSelector','(leg2.tauID("chargedIsoPtSumdR03"))/(leg2.pt()) < 0.15','ETTauMediumIso',1)
ETanalysisConfigurator.addSelector('eleTausTauMuonVeto','PATEleTauPairSelector','leg2.tauID("againstMuonLoose3")','ETAgainstMuon',1)
ETanalysisConfigurator.addSelector('eleTausTauElectronVeto','PATEleTauPairSelector','leg2.tauID("againstElectronTightMVA6")>0','ETAgainstElectron',1)
ETanalysisConfigurator.addSelector('eleTausEleIsolation','PATEleTauPairSelector','leg1.userFloat("dBRelIso03")<0.1','ETelectronIsolation',1)
ETanalysisConfigurator.addSelector('eleTausOS','PATEleTauPairSelector','charge==0','ETOS',1)

#create the sequence
selectionSequenceET =ETanalysisConfigurator.returnSequence()

################################		Mu-Tau			###################################

MTanalysisConfigurator = CutSequenceProducer(initialCounter  = 'initialEventsMT',
                                  pyModuleName = __name__,
                                  pyNameSpace  = locals())

#Add smearing
#MTanalysisConfigurator.addSmearing('patOverloadedTaus','triggeredPatMuons','triggeredPatElectrons','filteredJets','MVAMET:MVAMET','MT')
MTanalysisConfigurator.addSmearing('patOverloadedTaus','triggeredPatMuons','triggeredPatElectrons','filteredJets','slimmedMETs','MT')
#MTanalysisConfigurator.addSmearing('patOverloadedTaus','miniAODMuonID','miniAODElectronVID','filteredJets','slimmedMETs','MT')
#Create di muon pairs for veto purposes
MTanalysisConfigurator.addDiCandidateModule('diMuons','PATMuPairProducer','smearedMuonsMT','smearedMuonsMT','slimmedMETs','','smearedJetsMT',0,9999,text = '',leadingObjectsOnly = False,dR = 0.15,recoMode = "",genParticles='prunedGenParticles')
MTanalysisConfigurator.addSelector('diMuonsOS','PATMuPairSelector','leg1.isPFMuon&&leg2.isPFMuon&&abs(leg1.eta())<2.4&&abs(leg2.eta())<2.4&&abs(leg1.userFloat("dZ"))<0.2&&abs(leg2.userFloat("dZ"))<0.2&&abs(leg2.userFloat("dXY"))<0.045&&abs(leg2.userFloat("dXY"))<0.045&&charge==0&&leg1.isTrackerMuon&&leg2.isTrackerMuon&&leg1.isGlobalMuon&&leg2.isGlobalMuon&&leg1.pt()>15&&leg2.pt()>15&&leg1.userFloat("dBRelIso")<0.3 &&leg2.userFloat("dBRelIso")<0.3','DiMuonCreation',0,100)
MTanalysisConfigurator.addSorter('diMuonsOSSorted','PATMuPairSorter')

#Make DiTaus   
MTanalysisConfigurator.addDiCandidateModule('muTaus','PATMuTauPairProducer','smearedMuonsMT','smearedTausMT','smearedMETMT','smearedTausMT','smearedJetsMT',1,9999,text='AtLeastOneDiTau',leadingObjectsOnly = False,dR = 0.3,recoMode ="",genParticles='prunedGenParticles')
MTanalysisConfigurator.addSelector('muTausMuonPtEta','PATMuTauPairSelector','leg1.pt()>24&&abs(leg1.eta())<2.1','MTMuonPtEta',1)
MTanalysisConfigurator.addSelector('muTausTauPtEta','PATMuTauPairSelector','leg2.pt()>20&&abs(leg2.eta())<2.3','MTTauPtEta',1)
MTanalysisConfigurator.addSelector('muTausMuonMediumID','PATMuTauPairSelector','leg1.userInt("mediumID")>0','MTMuonMediumID',1)
#MTanalysisConfigurator.addSelector('muTausMuonMediumID','PATMuTauPairSelector','leg1.isMediumMuon()','MTMuonMediumID',1)
MTanalysisConfigurator.addSelector('muTausMuonVertices','PATMuTauPairSelector','abs(leg1.userFloat("dZ"))<0.2&&abs(leg1.userFloat("dXY"))<0.045','MTMuonVertices',1)
MTanalysisConfigurator.addSelector('muTausDecayFound','PATMuTauPairSelector','leg2.tauID("decayModeFinding")>0.5','MTTauDecayFound',1)
MTanalysisConfigurator.addSelector('muTausDecayVertex','PATMuTauPairSelector','abs(leg2.userFloat("taudZ"))<0.2','MTTauVertex',1)
MTanalysisConfigurator.addSelector('muTausTauLooseID','PATMuTauPairSelector','(leg2.tauID("chargedIsoPtSumdR03"))/(leg2.pt()) < 0.3','MTTauLooseID',1)
#MTanalysisConfigurator.addSelector('muTausTauLooseID','PATMuTauPairSelector','leg2.tauID("byLooseIsolationMVArun2v1DBoldDMwLT")>0.5','MTTauLooseID',1)
MTanalysisConfigurator.addMuTauLVeto('muTausLVeto','TightElectrons','TightMuons')
MTanalysisConfigurator.addSelector('muTausMuonVeto','PATMuTauPairSelector','lVeto==0','MTMuonVeto',1)
MTanalysisConfigurator.addSelector('muTausChargeNot2','PATMuTauPairSelector','abs(leg2.charge())==1','MTChargeIsABS1',1)
MTanalysisConfigurator.addSorter('muTausSorted','PATMuTauPairSorter')
MTanalysisConfigurator.addSelector('muTausMuonIsolation','PATMuTauPairSelector','leg1.userFloat("dBRelIso")<0.15','MTMuonIsolation',1)
MTanalysisConfigurator.addSelector('muTausTauID','PATMuTauPairSelector','(leg2.tauID("chargedIsoPtSumdR03"))/(leg2.pt()) < 0.15','MTTauID',1)
#MTanalysisConfigurator.addSelector('muTausTauID','PATMuTauPairSelector','leg2.tauID("byTightIsolationMVArun2v1DBoldDMwLT")>0.5','MTTauID',1)
MTanalysisConfigurator.addSelector('muTausTauElectronVeto','PATMuTauPairSelector','leg2.tauID("againstElectronVLooseMVA6")>0.5','MTAgainstElectron',1)
MTanalysisConfigurator.addSelector('muTausTauMuonVeto','PATMuTauPairSelector','leg2.tauID("againstMuonTight3")>0','MTAgainstMuon',1)
MTanalysisConfigurator.addSelector('muTausOS','PATMuTauPairSelector','charge==0','MTOS',1)


#create the sequence
selectionSequenceMT =MTanalysisConfigurator.returnSequence()


###############################			Tau-Tau 		###################################
TTanalysisConfigurator = CutSequenceProducer(initialCounter  = 'initialEventsTT',
                                  pyModuleName = __name__,
                                  pyNameSpace  = locals())

TTanalysisConfigurator.addSmearing('patOverloadedTaus','triggeredPatMuons','triggeredPatElectrons','filteredJets','slimmedMETs','TT')

#Make DiTaus
TTanalysisConfigurator.addDiCandidateModule('diTaus','PATDiTauPairProducer','smearedTausTT','smearedTausTT','smearedMETTT','smearedTausTT','smearedJetsTT',1,9999,text = 'AtLeastOneDiTau',leadingObjectsOnly = False,dR = 0.3,recoMode = "",genParticles='prunedGenParticles')

TTanalysisConfigurator.addSelector('diTausTau1PtEta','PATDiTauPairSelector','leg1.pt()>35&&abs(leg1.eta())<2.1','TTTau1PtEta',1)
TTanalysisConfigurator.addSelector('diTausTau2PtEta','PATDiTauPairSelector','leg2.pt()>35&&abs(leg2.eta())<2.1','TTTau2PtEta',1)
TTanalysisConfigurator.addSelector('diTaus1DecayFound','PATDiTauPairSelector','leg1.tauID("decayModeFinding")>0.5','TTTau1DecayFound',1)
TTanalysisConfigurator.addSelector('diTaus2DecayFound','PATDiTauPairSelector','leg2.tauID("decayModeFinding")>0.5','TTTau2DecayFound',1)
TTanalysisConfigurator.addSelector('diTaus1DecayVertex','PATDiTauPairSelector','abs(leg1.userFloat("taudZ"))<0.2','TTTau1VertexFound',1)
TTanalysisConfigurator.addSelector('diTaus2DecayVertex','PATDiTauPairSelector','abs(leg2.userFloat("taudZ"))<0.2','TTTau2VertexFound',1)
TTanalysisConfigurator.addSelector('diTaus1TauLooseIsolation','PATDiTauPairSelector','(leg1.tauID("chargedIsoPtSumdR03"))/(leg1.pt()) < 0.3','TTTauLooseIso1',1)
TTanalysisConfigurator.addSelector('diTaus2TauLooseIsolation','PATDiTauPairSelector','(leg2.tauID("chargedIsoPtSumdR03"))/(leg1.pt()) < 0.3','TTTauLooseIso2',1)
TTanalysisConfigurator.addSelector('diTausChargeNot2','PATDiTauPairSelector','abs(leg1.charge())==1&&abs(leg2.charge())==1','TTChargeIsABS1',1)
TTanalysisConfigurator.addDiTauLVeto('diTausLVeto','TightElectrons','TightMuons')
TTanalysisConfigurator.addSelector('diTausLeptVeto','PATDiTauPairSelector','lVeto==0','TTLVeto',1)
TTanalysisConfigurator.addSorter('diTausSorted','PATDiTauPairSorter')

TTanalysisConfigurator.addSelector('diTausTau1Isolation','PATDiTauPairSelector','(leg1.tauID("chargedIsoPtSumdR03"))/(leg2.pt()) < 0.15','TTTauMediumIso1',1)
TTanalysisConfigurator.addSelector('diTausTau2Isolation','PATDiTauPairSelector','(leg2.tauID("chargedIsoPtSumdR03"))/(leg2.pt()) < 0.15','TTTauMediumIso2',1)
TTanalysisConfigurator.addSelector('diTausTau1MuonVeto','PATDiTauPairSelector','leg1.tauID("againstMuonLoose3")','TTAgainstMuon1',1)
TTanalysisConfigurator.addSelector('diTausTau2MuonVeto','PATDiTauPairSelector','leg2.tauID("againstMuonLoose3")','TTAgainstMuon2',1)
TTanalysisConfigurator.addSelector('diTausTau1ElectronVeto','PATDiTauPairSelector','leg1.tauID("againstElectronVLooseMVA6")>0','TTAgainstElectron1',1)
TTanalysisConfigurator.addSelector('diTausTau2ElectronVeto','PATDiTauPairSelector','leg2.tauID("againstElectronVLooseMVA6")>0','TTAgainstElectron2',1)
TTanalysisConfigurator.addSelector('diTausOS','PATDiTauPairSelector','charge==0','TTOS',1)

#create the sequence
selectionSequenceTT =TTanalysisConfigurator.returnSequence()

#



