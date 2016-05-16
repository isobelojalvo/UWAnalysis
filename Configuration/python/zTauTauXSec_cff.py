import FWCore.ParameterSet.Config as cms


#Import tool that creates the cut sequence
from UWAnalysis.Configuration.tools.CutSequenceProducer import *

###############################			Ele-Tau 		###################################
ETanalysisConfigurator = CutSequenceProducer(initialCounter  = 'initialEventsET',
                                  pyModuleName = __name__,
                                  pyNameSpace  = locals())

ETanalysisConfigurator.addSmearing('patOverloadedTaus','triggeredPatMuons','triggeredPatElectrons','filteredJets','slimmedMETs','ET')

#create dielectrons
ETanalysisConfigurator.addDiCandidateModule('diElectrons','PATElePairProducer','smearedElectronsET','smearedElectronsET','slimmedMETs','','smearedJetsET',0,9999,text = '',leadingObjectsOnly = False,dR = 0.15,recoMode = "",genParticles='prunedGenParticles')
ETanalysisConfigurator.addSelector('diElectronsOS','PATElePairSelector','abs(leg1.eta())<2.5&&abs(leg2.eta())<2.5&&abs(leg1.userFloat("dXY"))<0.045&&abs(leg2.userFloat("dXY"))<0.045&&abs(leg1.userFloat("dZ"))<0.2&&abs(leg2.userFloat("dZ"))<0.2&&leg1.pt()>15&&leg2.pt()>15&&charge==0&&leg2.userFloat("CBIDVeto")>0&&leg1.userFloat("CBIDVeto")>0&&leg1.userFloat("dBRelIso03")<0.3&&leg2.userFloat("dBRelIso03")<0.3','DiElectronCreation',0,100)
ETanalysisConfigurator.addSorter('diElectronsOSSorted','PATElePairSorter')
#Make DiTaus
ETanalysisConfigurator.addDiCandidateModule('eleTaus','PATEleTauPairProducer','smearedElectronsET','smearedTausET','smearedMETET','smearedTausET','smearedJetsET',1,9999,text = 'AtLeastOneEleTau',leadingObjectsOnly = False,dR = 0.5,recoMode = "",genParticles='prunedGenParticles')

ETanalysisConfigurator.addSelector('eleTausEleTrigMatch','PATEleTauPairSelector','leg1.userFloat("hltEle23WPLooseGsfTrackIsoFilter")>0','ETEleTrigMatch',1)
ETanalysisConfigurator.addSelector('eleTausElePtEta','PATEleTauPairSelector','leg1.pt()>24&&abs(leg1.eta())<2.1','ETelectronPtEta',1)
ETanalysisConfigurator.addSelector('eleTausTauPtEta','PATEleTauPairSelector','leg2.pt()>20&&abs(leg2.eta())<2.3','ETTauPtEta',1)
ETanalysisConfigurator.addSelector('eleTausEleID','PATEleTauPairSelector','leg1.userFloat("eleMVAIDnonTrig80")>0','ElectronID',1)
ETanalysisConfigurator.addSelector('eleTausEleConvRej','PATEleTauPairSelector','leg1.userInt("eleConversion")==0','ETelectronConvRej',1)
ETanalysisConfigurator.addSelector('eleTausEleVertices','PATEleTauPairSelector','abs(leg1.userFloat("dZ"))<0.2&&abs(leg1.userFloat("dXY"))<0.045','ETelectronVertices',1)
ETanalysisConfigurator.addSelector('eleTausDecayFound','PATEleTauPairSelector','abs(leg2.userFloat("taudZ"))<0.2&&leg2.tauID("decayModeFinding")>0.5','ETTauDecayFound',1)
ETanalysisConfigurator.addSelector('eleTausTauLooseIsolation','PATEleTauPairSelector','leg2.tauID("byLooseIsolationMVArun2v1DBoldDMwLT") > 0.5','ETTauLooseIso',1)
ETanalysisConfigurator.addSelector('eleTausChargeNot2','PATEleTauPairSelector','abs(leg2.charge())==1','ETChargeIsABS1',1)
ETanalysisConfigurator.addEleTauLVeto('eleTausLVeto','TightElectrons','TightMuons')
ETanalysisConfigurator.addSelector('eleTausEleVeto','PATEleTauPairSelector','lVeto==0','ETelectronVeto',1)
#ETanalysisConfigurator.addEleTauSVFitSA('eleTausSVFit')
ETanalysisConfigurator.addSorter('eleTausSorted','PATEleTauPairSorterByIso')
ETanalysisConfigurator.addSelector('eleTausTauIsolation','PATEleTauPairSelector','leg2.tauID("byTightIsolationMVArun2v1DBoldDMwLT") > 0.5','ETTauMediumIso',1)
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
MTanalysisConfigurator.addSmearing('patOverloadedTaus','triggeredPatMuons','triggeredPatElectrons','filteredJets','slimmedMETs','MT')

#Create di muon pairs for veto purposes
MTanalysisConfigurator.addDiCandidateModule('diMuons','PATMuPairProducer','smearedMuonsMT','smearedMuonsMT','slimmedMETs','','smearedJetsMT',0,9999,text = '',leadingObjectsOnly = False,dR = 0.15,recoMode = "",genParticles='prunedGenParticles')
MTanalysisConfigurator.addSelector('diMuonsOS','PATMuPairSelector','leg1.isPFMuon&&leg2.isPFMuon&&abs(leg1.eta())<2.4&&abs(leg2.eta())<2.4&&abs(leg1.userFloat("dZ"))<0.2&&abs(leg2.userFloat("dZ"))<0.2&&abs(leg2.userFloat("dXY"))<0.045&&abs(leg2.userFloat("dXY"))<0.045&&charge==0&&leg1.isTrackerMuon&&leg2.isTrackerMuon&&leg1.isGlobalMuon&&leg2.isGlobalMuon&&leg1.pt()>15&&leg2.pt()>15&&leg1.userFloat("dBRelIso03")<0.3 &&leg2.userFloat("dBRelIso03")<0.3','DiMuonCreation',0,100)
MTanalysisConfigurator.addSorter('diMuonsOSSorted','PATMuPairSorter')

#Make DiTaus   
MTanalysisConfigurator.addDiCandidateModule('muTaus','PATMuTauPairProducer','smearedMuonsMT','smearedTausMT','smearedMETMT','smearedTausMT','smearedJetsMT',1,9999,text='AtLeastOneDiTau',leadingObjectsOnly = False,dR = 0.5,recoMode ="",genParticles='prunedGenParticles')
MTanalysisConfigurator.addSelector('muTausTausMuTrigMatch','PATMuTauPairSelector','leg1.userFloat("hltL3crIsoL1sMu16L1f0L2f10QL3f18QL3trkIsoFiltered0p09")>0','MTMuTrigMatch',1)
MTanalysisConfigurator.addSelector('muTausMuonPtEta','PATMuTauPairSelector','leg1.pt()>19&&abs(leg1.eta())<2.1','MTMuonPtEta',1)
MTanalysisConfigurator.addSelector('muTausMuonMediumID','PATMuTauPairSelector','leg1.isMediumMuon()','MTMuonMediumID',1)
MTanalysisConfigurator.addSelector('muTausMuonVertices','PATMuTauPairSelector','abs(leg1.userFloat("dZ"))<0.2&&abs(leg1.userFloat("dXY"))<0.045','MTMuonVertices',1)
MTanalysisConfigurator.addSelector('muTausTauPtEta','PATMuTauPairSelector','leg2.pt()>20&&abs(leg2.eta())<2.3','MTTauPtEta',1)
MTanalysisConfigurator.addSelector('muTausDecayFound','PATMuTauPairSelector','abs(leg2.userFloat("taudZ"))<0.2&&leg2.tauID("decayModeFinding")>0.5','MTTauDecayFound',1)
MTanalysisConfigurator.addSelector('muTausTauLooseID','PATMuTauPairSelector','leg2.tauID("byLooseIsolationMVArun2v1DBoldDMwLT")>0.5','MTTauLooseID',1)
MTanalysisConfigurator.addMuTauLVeto('muTausLVeto','TightElectrons','TightMuons')
MTanalysisConfigurator.addSelector('muTausMuonVeto','PATMuTauPairSelector','lVeto==0','MTMuonVeto',1)
MTanalysisConfigurator.addSelector('muTausChargeNot2','PATMuTauPairSelector','abs(leg2.charge())==1','MTChargeIsABS1',1)
#MTanalysisConfigurator.addMuTauSVFitSA('muTausSVFit')
MTanalysisConfigurator.addSorter('muTausSorted','PATMuTauPairSorterByIso')
MTanalysisConfigurator.addSelector('muTausMuonIsolation','PATMuTauPairSelector','leg1.userFloat("dBRelIso03")<0.1','MTMuonIsolation',1)
MTanalysisConfigurator.addSelector('muTausTauID','PATMuTauPairSelector','leg2.tauID("byTightIsolationMVArun2v1DBoldDMwLT")>0.5','MTTauID',1)
MTanalysisConfigurator.addSelector('muTausTauElectronVeto','PATMuTauPairSelector','leg2.tauID("againstElectronVLooseMVA6")>0.5','MTAgainstElectron',1)
MTanalysisConfigurator.addSelector('muTausTauMuonVeto','PATMuTauPairSelector','leg2.tauID("againstMuonTight3")>0','MTAgainstMuon',1)
MTanalysisConfigurator.addSelector('muTausOS','PATMuTauPairSelector','charge==0','MTOS',1)


#create the sequence
selectionSequenceMT =MTanalysisConfigurator.returnSequence()
