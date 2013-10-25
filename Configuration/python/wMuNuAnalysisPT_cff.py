import FWCore.ParameterSet.Config as cms



#Import tool that creates the cut sequence
from UWAnalysis.Configuration.tools.CutSequenceProducer import *


analysisConfigurator = CutSequenceProducer(initialCounter  = 'initialEvents',
                                  pyModuleName = __name__,
                                  pyNameSpace  = locals())


DiMuonPreSel='leg1.isGlobalMuon && leg1.isTrackerMuon && leg2.isGlobalMuon && leg2.isTrackerMuon && leg1.pt()>20 && leg2.pt()>20'
DiMuonPreSel2='(leg1.isolationR03().sumPt+leg1.isolationR03().emEt+leg1.isolationR03().hadEt)/leg1.pt()<0.15 '
DiMuonPreSel3='(leg2.isolationR03().sumPt+leg2.isolationR03().emEt+leg2.isolationR03().hadEt)/leg2.pt()<0.15 '


#Make Di Muons to VETO DY
analysisConfigurator.addDiCandidateModule('diMuons','PATMuPairProducer', 'cleanPatMuons','cleanPatMuons','systematicsMET','cleanPatJets',0,9999,text = '',leadingObjectsOnly = True,dR = 0.15,recoMode = "")
analysisConfigurator.addSelector('diMuonsSel','PATMuPairSelector',DiMuonPreSel+'&&'+DiMuonPreSel2+'&&'+DiMuonPreSel3,'diMuonSel',0,999)
analysisConfigurator.addSorter('diMuonsSorted','PATMuPairSorter')


#Make Muons+MET
analysisConfigurator.addCandidateMETModule('wCands','PATMuonNuPairProducer','cleanPatMuons','systematicsMET','cleanPatJets',1,9999,'AtLeastOneWCandidate',genParticles="genDaughters")
#analysisConfigurator.addCandidateMETModule('wGenCands','PATCandNuPairProducer','genMuons','genNeutrinos','cleanPatJets',0,9999,'')

analysisConfigurator.addSelector('wCandsKIN','PATMuonNuPairSelector','lepton.pt()>25 && abs(lepton.eta())<2.1','wCandsKIN',1)
analysisConfigurator.addSelector('wCandsJets','PATMuonNuPairSelector','lepton.userInt("WWID2011")==1','wCandsSel',1)
#analysisConfigurator.addGeneric('wCandsJetFetch','MuonNuPairJetFetcher')
#analysisConfigurator.addSelector('wCandsJetSel','PATMuonNuPairSelector','pt>20&&abs(eta)<2.5&&nConstituents>1&&neutralHadronEnergyFraction<0.99&&neutralEmEnergyFraction<0.99&&chargedMultiplicity>0&&chargedHadronEnergyFraction>0.0&&chargedEmEnergyFraction<0.99','wCandsJets',1)
#analysisConfigurator.addSelector('wCandsJets','PATMuonNuPairSelector','nJets>1','wCandsJets',1)

#
#make Gen Ws


#analysisConfigurator.addSelector('wCandsGoodMuon','PATMuonNuPairSelector','lepton.pt()>20&&abs(lepton.eta())<2.4','OneLeptonInAcceptance',1)

selectionSequence =analysisConfigurator.returnSequence()
#selectionSequence =analysisConfigurator.returnSequence()




