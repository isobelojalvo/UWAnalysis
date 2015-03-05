import FWCore.ParameterSet.Config as cms
import sys



process = cms.Process("ANALYSIS")




process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.GlobalTag.globaltag = 'START52_V5::All'


process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(1000)
)

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
 '/store/relval/CMSSW_5_2_0/RelValQQH1352T_Tauola/GEN-SIM-RECO/START52_V4A-v1/0248/78414E2F-1869-E111-A8D3-003048FFD71E.root',
                    '/store/relval/CMSSW_5_2_0/RelValQQH1352T_Tauola/GEN-SIM-RECO/START52_V4A-v1/0248/FE46A52E-1869-E111-9A74-003048FFD728.root',
                    '/store/relval/CMSSW_5_2_0/RelValQQH1352T_Tauola/GEN-SIM-RECO/START52_V4A-v1/0249/26D2512F-F869-E111-A184-0018F3D096E6.root'


        )
)

process.load("PhysicsTools.PatAlgos.patSequences_cff")


from UWAnalysis.Configuration.tools.analysisTools import *

defaultReconstructionMC(process,'HLT',['HLT_IsoMu15_LooseIsoPFTau15'])



#EventSelection
process.load("UWAnalysis.Configuration.zMuTauAnalysis_cff")

process.metCalibration.applyCalibration = cms.bool(True)


process.eventSelection = cms.Path(process.selectionSequence) ##changing to multiples see below


#Systematic Shifts 1sigma
process.eventSelectionTauUp    = createSystematics(process,process.selectionSequence,'TauUp',1.00,1.0,1.03,0,1.0)
process.eventSelectionTauDown  = createSystematics(process,process.selectionSequence,'TauDown',1.0,1.0,0.97,0,1.0)
process.eventSelectionJetUp    = createSystematics(process,process.selectionSequence,'JetUp',1.00,1.0,1.0,1,1.0)
process.eventSelectionJetDown  = createSystematics(process,process.selectionSequence,'JetDown',1.0,1.0,1.0,-1,1.0)
process.eventSelectionUncUp    = createSystematics(process,process.selectionSequence,'UncUp',1.00,1.0,1.0,0,1.1)
process.eventSelectionUncDown  = createSystematics(process,process.selectionSequence,'UncDown',1.0,1.0,1.0,0,0.9)




createGeneratedParticles(process,
                         'genDaughters',
                          [
                           "keep++ pdgId = {Z0}",
                           "keep pdgId = {tau+}",
                           "keep pdgId = {tau-}",
                           "keep pdgId = {mu+}",
                           "keep pdgId = {mu-}",
                           "drop pdgId = 11",
                           "drop pdgId = -11"
                          ]
)


createGeneratedParticles(process,
                         'genTauCands',
                          [
                           "keep pdgId = {tau+} & mother.pdgId()= {Z0}",
                           "keep pdgId = {tau-} & mother.pdgId() = {Z0}"
                          ]
)


#Add event counter
addEventSummary(process)

#ntupleization

from UWAnalysis.Configuration.tools.ntupleTools import addMuTauEventTree

addMuTauEventTree(process,'muTauEventTree')
addMuTauEventTree(process,'muTauEventTreeFinal','diTausOS','diMuonsSorted')


#Final trees afor shapes after shifts
addMuTauEventTree(process,'muTauEventTreeTauUp','diTausTauMuonVetoTauUp','diMuonsSortedTauUp')
addMuTauEventTree(process,'muTauEventTreeTauDown','diTausTauMuonVetoTauDown','diMuonsSortedTauDown')
addMuTauEventTree(process,'muTauEventTreeJetUp','diTausTauMuonVetoJetUp','diMuonsSortedJetUp')
addMuTauEventTree(process,'muTauEventTreeJetDown','diTausTauMuonVetoJetDown','diMuonsSortedJetDown')
addMuTauEventTree(process,'muTauEventTreeUncUp','diTausTauMuonVetoUncUp','diMuonsSortedUncUp')
addMuTauEventTree(process,'muTauEventTreeUncDown','diTausTauMuonVetoUncDown','diMuonsSortedUncDown')









