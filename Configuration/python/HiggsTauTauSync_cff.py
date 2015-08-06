import FWCore.ParameterSet.Config as cms


#Import tool that creates the cut sequence
from UWAnalysis.Configuration.tools.CutSequenceProducer import *

###############################			Ele-Tau 		###################################
ETanalysisConfigurator = CutSequenceProducer(initialCounter  = 'initialEventsET',
                                  pyModuleName = __name__,
                                  pyNameSpace  = locals())

#ESTausID
ETanalysisConfigurator.addSmearing('patOverloadedTaus','miniAODMuonID','miniAODElectronVID','patOverloadedJets','slimmedMETs','ET')

#create dielectrons
ETanalysisConfigurator.addDiCandidateModule('diElectrons','PATElePairProducer','smearedElectronsET','smearedElectronsET','smearedMETET','','smearedJetsET',0,9999,text = '',leadingObjectsOnly = False,dR = 0.15,recoMode = "")
#ETanalysisConfigurator.addSelector('osDiElectrons','PATElePairSelector','abs(leg1.eta())<2.5&&abs(leg2.eta())<2.5&&abs(leg1.userFloat("ipDXY"))<0.045&&abs(leg2.userFloat("ipDXY"))<0.045&&abs(leg1.userFloat("dz"))<0.2&&abs(leg2.userFloat("dz"))<0.2&&leg1.pt()>15&&leg2.pt()>15&&charge==0&&leg2.userFloat("CBIDVeto")>0&&leg1.userFloat("CBIDVeto")>0&&leg1.userFloat("dBRelIso")<0.3&&leg2.userFloat("dBRelIso")<0.3','ZEEVEto',0,100)

#Make DiTaus
ETanalysisConfigurator.addDiCandidateModule('eleTaus','PATEleTauPairProducer','smearedElectronsET','smearedTausET','smearedMETET','smearedTausET','smearedJetsET',1,9999,text = 'AtLeastOneEleTau',leadingObjectsOnly = False,dR = 0.5,recoMode = "",genParticles='genDaughters')

ETanalysisConfigurator.addSelector('eleTausElePtEta','PATEleTauPairSelector','leg1.pt()>23&&abs(leg1.eta())<2.1','electronPtEta',1)
ETanalysisConfigurator.addSelector('eleTausEleID','PATEleTauPairSelector','leg1.userFloat("eleMVAIDnonTrig80")>0','ElectronID',1)
ETanalysisConfigurator.addSelector('eleTausEleVertices','PATEleTauPairSelector','abs(leg1.userFloat("dZ"))<0.2&&abs(leg1.userFloat("dXY"))<0.045','electronVertices',1)
ETanalysisConfigurator.addSelector('eleTausEleConvRej','PATEleTauPairSelector','leg1.userInt("eleConversion")==0','electronConvRej',1)
ETanalysisConfigurator.addSelector('eleTausTauPtEta','PATEleTauPairSelector','leg2.pt()>20&&abs(leg2.eta())<2.3','ETTauPtEta',1)
ETanalysisConfigurator.addSelector('eleTausDecayFound','PATEleTauPairSelector','abs(leg2.userFloat("dZ"))<0.2&&leg2.tauID("decayModeFindingNewDMs")>0.5','ETTauDecayFound',1)
#ETanalysisConfigurator.addSelector('eleTausDecayFound','PATEleTauPairSelector','abs(leg2.userFloat("dZ"))<0.2&&leg2.tauID("decayModeFindingNewDMs")>0.5','ETTauDecayFound',1)
#ETanalysisConfigurator.addEleTauSVFitSA('eleTausSVFit')
ETanalysisConfigurator.addSorter('eleTausSorted','PATEleTauPairSorterByIso')
#ETanalysisConfigurator.addSelector('eleTausEleTrigMatch','PATEleTauPairSelector','leg1.userFloat("hltOverlapFilterIsoEle22WP75GsfLooseIsoPFTau20")>0','ETEleTrigMatch',1)
#ETanalysisConfigurator.addSelector('eleTausTauTrigMatch','PATEleTauPairSelector','leg2.userFloat("hltOverlapFilterIsoEle22WP75GsfLooseIsoPFTau20")>0','ETTauTrigMatch',1)
#ETanalysisConfigurator.addSelector('eleTausOS','PATEleTauPairSelector','charge==0','ETOS',1)

#create the sequence
selectionSequenceET =ETanalysisConfigurator.returnSequence()

################################		Mu-Tau			###################################

MTanalysisConfigurator = CutSequenceProducer(initialCounter  = 'initialEventsMT',
                                  pyModuleName = __name__,
                                  pyNameSpace  = locals())

#Add smearing
MTanalysisConfigurator.addSmearing('patOverloadedTaus','miniAODMuonID','miniAODElectronVID','patOverloadedJets','slimmedMETs','MT')

#Create di muon pairs for veto purposes
MTanalysisConfigurator.addDiCandidateModule('diMuons','PATMuPairProducer','smearedMuonsMT','smearedMuonsMT','smearedMETMT','','smearedJetsMT',0,9999,text = '',leadingObjectsOnly = False,dR = 0.15,recoMode = "")
#veto possible second zpeak
#MTanalysisConfigurator.addSelector('osDiMuons','PATMuPairSelector','leg1.userFloat("isPFMuon")>0&&leg2.userFloat("isPFMuon")&&abs(leg1.eta())<2.4&&abs(leg2.eta())<2.4&&abs(leg1.userFloat("dz"))<0.2&&abs(leg2.userFloat("dz"))<0.2&&abs(leg2.userFloat("ipDXY"))<0.045&&abs(leg2.userFloat("ipDXY"))<0.045&&charge==0&&(!leg1.pfCandidateRef().isNull())&&(!leg2.pfCandidateRef().isNull())&&leg1.isTrackerMuon&&leg2.isTrackerMuon&&leg1.isGlobalMuon&&leg2.isGlobalMuon&&leg1.pt()>15&&leg2.pt()>15&&leg1.userFloat("dBRelIso")<0.3 &&leg2.userFloat("dBRelIso")<0.3&&leg1.userInt("mediumId")&&leg2.userInt("mediumID")','DiMuonCreation',0,100)
MTanalysisConfigurator.addSorter('diMuonsSorted','PATMuPairSorter')

#Make DiTaus   
MTanalysisConfigurator.addDiCandidateModule('diTaus','PATMuTauPairProducer','smearedMuonsMT','smearedTausMT','smearedMETMT','smearedTausMT','smearedJetsMT',1,9999,text='AtLeastOneDiTau',leadingObjectsOnly = False,dR = 0.5,recoMode ="",genParticles='genDaughters')
MTanalysisConfigurator.addSelector('diTausMuonVertices','PATMuTauPairSelector','abs(leg1.userFloat("dZ"))<0.2&&abs(leg1.userFloat("dXY"))<0.045','MuonVertices',1)
#tightMuonSelectionForNow
MTanalysisConfigurator.addSelector('diTausMuonMediumID','PATMuTauPairSelector','leg1.userInt("mediumID")','MuonMediumID',1)
MTanalysisConfigurator.addSelector('diTausMuonPtEta','PATMuTauPairSelector','leg1.pt()>18&&abs(leg1.eta())<2.1','MuonPtEta',1)
MTanalysisConfigurator.addSelector('diTausTauPtEta','PATMuTauPairSelector','leg2.pt()>20&&abs(leg2.eta())<2.3','MTTauPtEta',1)
#MTanalysisConfigurator.addSelector('diTausDecayFound','PATMuTauPairSelector','abs(leg2.userFloat("dZ"))<0.2&&leg2.tauID("decayModeFindingNewDMs")>0.5','MTTauDecayFound',1)
MTanalysisConfigurator.addSorter('diTausSorted','PATMuTauPairSorterByIso')
#MTanalysisConfigurator.addSelector('MuTausMuTrigMatch','PATMuTauPairSelector','leg1.userFloat("hltOverlapFilterIsoMu17LooseIsoPFTau20")>0','MTMuTrigMatch',1)
#MTanalysisConfigurator.addSelector('MuTausTauTrigMatch','PATMuTauPairSelector','leg2.userFloat("hltOverlapFilterIsoMu17LooseIsoPFTau20")>0','MTTauTrigMatch',1)

#create the sequence
selectionSequenceMT =MTanalysisConfigurator.returnSequence()
