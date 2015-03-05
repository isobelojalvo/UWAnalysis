import FWCore.ParameterSet.Config as cms


#Import tool that creates the cut sequence
from UWAnalysis.Configuration.tools.CutSequenceProducer import *

###############################			Ele-Tau 		###################################
ETanalysisConfigurator = CutSequenceProducer(initialCounter  = 'initialEventsET',
                                  pyModuleName = __name__,
                                  pyNameSpace  = locals())

#ESTausID
ETanalysisConfigurator.addSmearing('patOverloadedTaus','triggeredPatMuons','triggeredPatElectrons','cleanPatJets','patMVAMet','ET')

#create dielectrons
ETanalysisConfigurator.addDiCandidateModule('diElectrons','PATElePairProducer','smearedElectronsET','smearedElectronsET','smearedMETET','','smearedJetsET',0,9999,text = '',leadingObjectsOnly = False,dR = 0.15,recoMode = "")
ETanalysisConfigurator.addSelector('osDiElectrons','PATElePairSelector','abs(leg1.eta())<2.5&&abs(leg2.eta())<2.5&&abs(leg1.userFloat("ipDXY"))<0.045&&abs(leg2.userFloat("ipDXY"))<0.045&&abs(leg1.userFloat("dz"))<0.2&&abs(leg2.userFloat("dz"))<0.2&&leg1.pt()>15&&leg2.pt()>15&&charge==0&&leg2.userFloat("wp95V")>0&&leg1.userFloat("wp95V")>0&&(leg1.userIso(0)+max(leg1.userIso(1)+leg1.neutralHadronIso()-0.5*leg1.userIso(2),0.0))/leg1.pt()<0.3&&(leg2.userIso(0)+max(leg2.userIso(1)+leg2.neutralHadronIso()-0.5*leg2.userIso(2),0.0))/leg2.pt()<0.3','ZEEVEto',0,100)

#Make DiTaus
ETanalysisConfigurator.addDiCandidateModule('eleTaus','PATEleTauPairProducer','smearedElectronsET','smearedTausET','patMVAMet','smearedTausET','smearedJetsET',1,9999,text = 'AtLeastOneEleTau',leadingObjectsOnly = False,dR = 0.5,recoMode = "",genParticles='genDaughters')

ETanalysisConfigurator.addSelector('eleTausEleID','PATEleTauPairSelector','(abs(leg1.superCluster().eta())<0.8&&leg1.electronID("mvaNonTrigV0")>0.925)||(abs(leg1.superCluster().eta())<1.479&&leg1.electronID("mvaNonTrigV0")>0.975)||(leg1.electronID("mvaNonTrigV0")>0.985)','ElectronID',1)
ETanalysisConfigurator.addSelector('eleTausEleConvRej','PATEleTauPairSelector','leg1.userInt("missingHits")==0&&!(leg1.userInt("HasMatchedConversion")>0)','electronConvRej',1)
ETanalysisConfigurator.addSelector('eleTausElePtEta','PATEleTauPairSelector','leg1.pt()>20&&abs(leg1.eta())<2.1&&abs(leg1.userFloat("dz"))<0.2&&abs(leg1.userFloat("ipDXY"))<0.045','electronPtEta',1)
ETanalysisConfigurator.addSelector('eleTausEleIsolationLoose','PATEleTauPairSelector','(leg1.userIso(0)+max(leg1.userIso(1)+leg1.neutralHadronIso()-0.5*leg1.userIso(2),0.0))/leg1.pt()<0.5','electronIsolationLoose',1)
ETanalysisConfigurator.addSelector('eleTausTauPtEta','PATEleTauPairSelector','leg2.pt()>17&&abs(leg2.eta())<2.3','ETTauPtEta',1)
ETanalysisConfigurator.addSelector('eleTausDecayFound','PATEleTauPairSelector','abs(leg2.userFloat("dZ"))<0.2&&leg2.tauID("decayModeFinding")','ETTauDecayFound',1)
ETanalysisConfigurator.addSelector('eleTausVLooseIsolation','PATEleTauPairSelector','leg2.tauID("byCombinedIsolationDeltaBetaCorrRaw3Hits")<10','ETTauVLooseMVAIso',1)
ETanalysisConfigurator.addSelector('eleTausTauMuonVeto','PATEleTauPairSelector','leg2.tauID("againstMuonLoose2")','ETAgainstMuon',1)
ETanalysisConfigurator.addSelector('eleTausTauElectronVeto','PATEleTauPairSelector','leg2.userInt("againstEleMVALoose")>0&&(!(leg2.userFloat("zIP")>-1.5&&leg2.userFloat("zIP")<0.5))','ETAgainstElectron',1)
ETanalysisConfigurator.addEleTauSVFitSA('eleTausSVFit')
ETanalysisConfigurator.addSorter('eleTausSorted','PATEleTauPairSorter')
ETanalysisConfigurator.addSelector('eleTausTauElectronVetoM','PATEleTauPairSelector','leg2.userInt("againstEleMVAMedium")>0','ETAgainstElectronM',1)
ETanalysisConfigurator.addSelector('eleTausEleIsolation','PATEleTauPairSelector','(leg1.userIso(0)+max(leg1.userIso(1)+leg1.neutralHadronIso()-0.5*leg1.userIso(2),0.0))/leg1.pt()<0.1','electronIsolation',1)
ETanalysisConfigurator.addSelector('eleTausLooseIsolation','PATEleTauPairSelector','leg2.tauID("byCombinedIsolationDeltaBetaCorrRaw3Hits")<1.5','ETTauLooseIso',1)
ETanalysisConfigurator.addSelector('eleTausEleTrigMatch','PATEleTauPairSelector','leg1.userFloat("hltOverlapFilterIsoEle20LooseIsoPFTau20")>0||leg1.userFloat("hltOverlapFilterIsoEle20WP90LooseIsoPFTau20")>0','ETEleTrigMatch',1)
ETanalysisConfigurator.addSelector('eleTausTauTrigMatch','PATEleTauPairSelector','leg2.userFloat("hltOverlapFilterIsoEle20LooseIsoPFTau20")>0||leg2.userFloat("hltOverlapFilterIsoEle20WP90LooseIsoPFTau20")>0','ETTauTrigMatch',1)
#ETanalysisConfigurator.addSelector('eleTausWRej','PATEleTauPairSelector','mt1MET<40||pZeta-1.5*pZetaVis>-20','ETWRejection',1)
ETanalysisConfigurator.addSelector('eleTausOS','PATEleTauPairSelector','charge==0','ETOS',1)

#create the sequence
selectionSequenceET =ETanalysisConfigurator.returnSequence()

################################		Mu-Tau			###################################

MTanalysisConfigurator = CutSequenceProducer(initialCounter  = 'initialEventsMT',
                                  pyModuleName = __name__,
                                  pyNameSpace  = locals())

#Add smearing
MTanalysisConfigurator.addSmearing('patOverloadedTaus','triggeredPatMuons','triggeredPatElectrons','cleanPatJets','patMVAMet','MT')

#Create di muon pairs for veto purposes
MTanalysisConfigurator.addDiCandidateModule('diMuons','PATMuPairProducer','smearedMuonsMT','smearedMuonsMT','smearedMETMT','','smearedJetsMT',0,9999,text = '',leadingObjectsOnly = False,dR = 0.15,recoMode = "")

MTanalysisConfigurator.addSelector('osDiMuons','PATMuPairSelector','abs(leg1.eta())<2.4&&abs(leg2.eta())<2.4&&abs(leg1.userFloat("ipDXY"))<0.045&&abs(leg2.userFloat("ipDXY"))<0.045&&abs(leg1.userFloat("dz"))<0.2&&abs(leg2.userFloat("dz"))<0.2&&charge==0&&(!leg1.pfCandidateRef().isNull())&&(!leg2.pfCandidateRef().isNull())&&leg1.isTrackerMuon&&leg2.isTrackerMuon&&leg1.isGlobalMuon&&leg2.isGlobalMuon&&leg1.pt()>15&&leg2.pt()>15&& (leg1.userIso(0)+max(leg1.photonIso+leg1.neutralHadronIso()-0.5*leg1.puChargedHadronIso,0.0))/leg1.pt()<0.3 &&(leg2.userIso(0)+max(leg2.photonIso+leg2.neutralHadronIso()-0.5*leg2.puChargedHadronIso,0.0))/leg2.pt()<0.3','DiMuonCreation',0,100)
MTanalysisConfigurator.addSorter('diMuonsSorted','PATMuPairSorter')

#Make DiTaus   
MTanalysisConfigurator.addDiCandidateModule('diTaus','PATMuTauPairProducer','smearedMuonsMT','smearedTausMT','smearedMETMT','triggeredPatTaus','smearedJetsMT',1,9999,text='AtLeastOneDiTau',leadingObjectsOnly = False,dR = 0.5,recoMode ="",genParticles='genDaughters')
MTanalysisConfigurator.addSelector('diTausMuonID','PATMuTauPairSelector','leg1.userInt("tightID")>0&&abs(leg1.userFloat("dz"))<0.2&&abs(leg1.userFloat("ipDXY"))<0.045&&leg1.isTrackerMuon','MuonID',1)
MTanalysisConfigurator.addSelector('diTausMuonPtEta','PATMuTauPairSelector','leg1.pt()>17&&abs(leg1.eta())<2.1','MuonPtEta',1)
MTanalysisConfigurator.addSelector('diTausMuonIsolationLoose','PATMuTauPairSelector','(leg1.userIso(0)+max(leg1.photonIso+leg1.neutralHadronIso()-0.5*leg1.puChargedHadronIso,0.0))/leg1.pt()<0.5','MuonIsolationLoose',1)
MTanalysisConfigurator.addSelector('diTausTauPtEta','PATMuTauPairSelector','leg2.pt()>17&&abs(leg2.eta())<2.3','MTTauPtEta',1)
MTanalysisConfigurator.addSelector('diTausDecayFound','PATMuTauPairSelector','abs(leg2.userFloat("dZ"))<0.2&&leg2.tauID("decayModeFinding")>0','MTTauDecayFound',1)
MTanalysisConfigurator.addSelector('diTausVLooseTauIsolation','PATMuTauPairSelector','leg2.tauID("byCombinedIsolationDeltaBetaCorrRaw3Hits")<10','MTTauVLooseMVAIso',1)
MTanalysisConfigurator.addSelector('diTausTauElectronVeto','PATMuTauPairSelector','leg2.tauID("againstElectronLoose")','MTAgainstElectron',1)
MTanalysisConfigurator.addSelector('diTausTauMuonVeto','PATMuTauPairSelector','leg2.userInt("againstMuTightFixed")>0','MTAgainstMuon',1)
MTanalysisConfigurator.addMuTauSVFitSA('muTausSVFit')
MTanalysisConfigurator.addSorter('diTausSorted','PATMuTauPairSorter')
MTanalysisConfigurator.addSelector('diTausMuonIsolation','PATMuTauPairSelector','(leg1.userIso(0)+max(leg1.photonIso+leg1.neutralHadronIso()-0.5*leg1.puChargedHadronIso,0.0))/leg1.pt()<0.1','MuonIsolation',1)
MTanalysisConfigurator.addSelector('diTausLooseTauIsolation','PATMuTauPairSelector','leg2.tauID("byCombinedIsolationDeltaBetaCorrRaw3Hits")<1.5','MTTauLooseIso',1)
MTanalysisConfigurator.addSelector('MuTausMuTrigMatch','PATMuTauPairSelector','leg1.userFloat("hltOverlapFilterIsoMu18LooseIsoPFTau20")>0||leg1.userFloat("hltOverlapFilterIsoMu17LooseIsoPFTau20")>0','MTMuTrigMatch',1)
MTanalysisConfigurator.addSelector('MuTausTauTrigMatch','PATMuTauPairSelector','leg2.userFloat("hltOverlapFilterIsoMu18LooseIsoPFTau20")>0||leg2.userFloat("hltOverlapFilterIsoMu17LooseIsoPFTau20")>0','MTTauTrigMatch',1)
#MTanalysisConfigurator.addSelector('diTausWRej','PATMuTauPairSelector','mt1MET<40||pZeta-1.5*pZetaVis>-20','MTWRejection',1)
MTanalysisConfigurator.addSelector('diTausOS','PATMuTauPairSelector','charge==0','MTOS',1)

#create the sequence
selectionSequenceMT =MTanalysisConfigurator.returnSequence()
