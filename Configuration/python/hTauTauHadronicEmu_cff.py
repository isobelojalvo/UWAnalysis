import FWCore.ParameterSet.Config as cms


#Import tool that creates the cut sequence
from UWAnalysis.Configuration.tools.CutSequenceProducer import *

###############################			Ele-Tau 		###################################
TTanalysisConfigurator = CutSequenceProducer(initialCounter  = 'initialEventsTT',
                                  pyModuleName = __name__,
                                  pyNameSpace  = locals())

TTanalysisConfigurator.addSmearing('patOverloadedTaus','miniAODMuonID','miniAODElectronVID','filteredJets','slimmedMETs','TT')

#Make DiTaus
#TTanalysisConfigurator.addDiCandidateModule('diTaus','PATDiTauPairProducer','smearedElectronsTT','smearedTausTT','smearedMETTT','smearedTausTT','smearedJetsTT',1,9999,text = 'AtLeastOneEleTau',leadingObjectsOnly = False,dR = 0.5,recoMode = "",genParticles='prunedGenParticles')
TTanalysisConfigurator.addDiCandidateModule('diTaus','PATDiTauPairProducer','patOverloadedTaus','patOverloadedTaus','slimmedMETs','patOverloadedTaus','slimmedJets',1,9999,text = 'AtLeastOneEleTau',leadingObjectsOnly = False,dR = 0.5,recoMode = "",genParticles='prunedGenParticles')
TTanalysisConfigurator.addSelector('diTausElePtEta','PATDiTauPairSelector','leg1.pt()>40&&abs(leg1.eta())<2.1&&leg2.pt()>40&&abs(leg2.eta())<2.1','TTTauPtEta',1)
TTanalysisConfigurator.addSelector('diTausDecayFound','PATDiTauPairSelector','abs(leg1.userFloat("taudZ"))<0.2&&leg1.tauID("decayModeFinding")>0.5&&abs(leg2.userFloat("taudZ"))<0.2&&leg2.tauID("decayModeFinding")>0.5','TTTauDecayFound',1)
TTanalysisConfigurator.addSelector('diTausStdDecaySel','PATDiTauPairSelector','abs(leg1.charge())==1&&abs(leg2.charge())==1','TTTauStandardDecayFound',1)
TTanalysisConfigurator.addSelector('diTausDRSel','PATDiTauPairSelector','dR12>0.5','TTTauDRSel',1)
TTanalysisConfigurator.addSorter('diTausSorted','PATDiTauPairSorter')
TTanalysisConfigurator.addSelector('diTausOS','PATDiTauPairSelector','charge==0','TTOS',1)

#create the sequence
selectionSequenceTT =TTanalysisConfigurator.returnSequence()

