
import FWCore.ParameterSet.Config as cms
from CommonTools.ParticleFlow.Isolation.tools_cfi import *


from PhysicsTools.PatAlgos.tools.jetTools import *
from PhysicsTools.PatAlgos.tools.helpers import *
from PhysicsTools.PatAlgos.tools.tauTools import *
from PhysicsTools.PatAlgos.tools.coreTools import *
from PhysicsTools.PatAlgos.tools.metTools import *
from PhysicsTools.PatAlgos.tools.pfTools import *
from PhysicsTools.PatAlgos.tools.trigTools import *
import sys

def defaultReconstructionMC(process,triggerProcess = 'HLT',triggerPaths = ['HLT_Mu9','HLT_Mu11_PFTau15_v1','HLT_Mu11_PFTau15_v1','HLT_Mu11_PFTau15_v2','HLT_Mu15_v1','HLT_Mu15_v2'],HLT = 'TriggerResults'):
  process.load("UWAnalysis.Configuration.startUpSequence_cff")
  process.load("Configuration.Geometry.GeometryIdeal_cff")
  process.load("Configuration.StandardSequences.MagneticField_cff")
  process.load("Configuration.StandardSequences.Services_cff")
  process.load("TrackingTools.TransientTrack.TransientTrackBuilder_cfi")
  process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")
  process.load("DQMServices.Core.DQM_cfg")
  process.load("DQMServices.Components.DQMEnvironment_cfi")

  #Make the TriggerPaths Global variable to be accesed by the ntuples
  global TriggerPaths
  TriggerPaths= triggerPaths
  process.analysisSequence = cms.Sequence()

  mvaMetMC(process)

  #Apply Tau Energy Scale Changes
  EScaledTaus(process,True)

  #Add trigger Matching
  muonTriggerMatchMiniAOD(process,triggerProcess,HLT)#NEW
  electronTriggerMatchMiniAOD(process,triggerProcess,HLT)#NEW
  tauTriggerMatchMiniAOD(process,triggerProcess,HLT)#NEW
  
  #Build good vertex collection
  goodVertexFilter(process)  
  tauOverloading(process,'triggeredPatTaus','primaryVertexFilter')
  
  triLeptons(process)
  renameJetColl(process)#currently does nothing--use to turn off jets
  jetOverloading(process,"slimmedJets")  
  #jetOverloading(process,"NewSelectedPatJets")  
  #turned off BDT
  #PATJetMVAEmbedder(process,"patOverloadedJets")  
  #Default selections for systematics
  applyDefaultSelectionsPT(process)

  #Build good vertex collection

  process.runAnalysisSequence = cms.Path(process.analysisSequence)



def renameJetColl(process): #change to CHS JETs
  process.load("RecoJets.JetProducers.ak4PFJets_cfi")
  process.ak4PFJets.src = cms.InputTag("packedPFCandidates")
  #process.load("PhysicsTools.PatAlgos.patSequences_cff")
  #process.NewSelectedPatJets = process.selectedPatJets.clone(
  #   src = cms.InputTag("ak4PFJets")
  #)
  process.NewSelectedPatJets=cms.Sequence(process.ak4PFJets)
  process.analysisSequence*=process.NewSelectedPatJets


def jetOverloading(process,jets):

  process.patOverloadedJets = cms.EDProducer('PATJetOverloader',
                                        src = cms.InputTag(jets),
                                        genJets = cms.InputTag("ak4GenJets")
  )                                        

  process.jetOverloading = cms.Sequence(process.patOverloadedJets)
  #process.createOverloadedJets=cms.Path(process.jetOverloading)
  process.analysisSequence*=process.jetOverloading

def PATJetMVAEmbedder(process,jets):

  process.patMVAEmbeddedJets = cms.EDProducer('PATJetMVAEmbedder',
                                        src = cms.InputTag(jets)
  )                                        

  process.jetMVAEmbedding = cms.Sequence(process.patMVAEmbeddedJets)
  process.analysisSequence*=process.jetMVAEmbedding
    
def EScaledTaus(process,smearing):  #second arg is bool

  process.ESTausID = cms.EDProducer("ESTauProducer",
                                    src = cms.InputTag("slimmedTaus"),
                                    module_label = cms.string("FROGS"),
                                    genParticles = cms.InputTag("genParticles"),
                                    smearConstituents = cms.bool(smearing),
                                    smearMCParticle = cms.bool(False),
                                    energyScale  = cms.double(1.0),
                                    energyScaleDB= cms.int32(0),
                                    deltaEta     = cms.double(0.0),
                                    deltaPhi     = cms.double(0.0),
                                    deltaPtB     = cms.double(0.0),
                                    deltaPtE     = cms.double(0.0)
                                    )
  
  process.EScaledTaus = cms.Sequence(process.ESTausID)
  process.analysisSequence*=process.EScaledTaus


def mvaMetMC(process):

  process.load("PhysicsTools.PatAlgos.producersLayer1.metProducer_cfi")
  process.load("RecoJets.JetProducers.ak4PFJets_cfi")
  process.ak4PFJets.src = cms.InputTag("packedPFCandidates")
  process.load("RecoJets.Configuration.RecoPFJets_cff")
  process.ak4PFJets.doAreaFastjet = True

  from JetMETCorrections.Configuration.DefaultJEC_cff import ak4PFJetsL1FastL2L3
 
  process.load("JetMETCorrections.Configuration.JetCorrectionServicesAllAlgos_cff")
  process.prefer("ak4PFL1FastL2L3") 

  process.load("RecoMET.METPUSubtraction.mvaPFMET_cff")
  #process.pfMVAMEt.srcLeptons = cms.VInputTag("slimmedElectrons")
  process.pfMVAMEt.srcPFCandidates = cms.InputTag("packedPFCandidates")
  process.pfMVAMEt.srcVertices = cms.InputTag("offlineSlimmedPrimaryVertices")

  process.puJetIdForPFMVAMEt.jec =  cms.string('AK4PF')
  #process.puJetIdForPFMVAMEt.jets = cms.InputTag("ak4PFJets")
  process.puJetIdForPFMVAMEt.vertexes = cms.InputTag("offlineSlimmedPrimaryVertices")
  process.puJetIdForPFMVAMEt.rho = cms.InputTag("fixedGridRhoFastjetAll")


  #process.calibratedAK4PFJetsForPFMVAMEt = cms.EDProducer('PFJetCorrectionProducer',
  #  src = cms.InputTag('ak4PFJets'),
  #  correctors = cms.vstring("ak4PFL1FastL2L3") # NOTE: use "ak5PFL1FastL2L3" for MC / "ak5PFL1FastL2L3Residual" for Data
  #)

  
  process.patMVAMet = process.patMETs.clone(
  	metSource = cms.InputTag('pfMVAMEt'),
  	addMuonCorrections = cms.bool(False),
  	addGenMET = cms.bool(False)
  )
  
  #calibrated ak4jets should be in pfMVAMetSequence
  process.analysisSequence = cms.Sequence(process.analysisSequence*process.ak4PFJets*process.pfMVAMEtSequence*process.patMVAMet)

def LHEFilter(process):

  process.LHEFilter = cms.EDFilter("GenFilterLHE",
       PartonMultiplicity=cms.untracked.int32(5),
  )
  
  process.analysisSequence*= process.LHEFilter

def triLeptons(process):

  process.TightElectrons = cms.EDFilter("PATElectronSelector",
  							src = cms.InputTag("slimmedElectrons"),
  							cut = cms.string('pt>10&&abs(eta)<2.5&&abs(userFloat("dz"))<0.2&&abs(userFloat("ipDXY"))<0.045'),
  							filter = cms.bool(False)
  						)
  						
  process.TightMuons = cms.EDFilter("PATMuonSelector",
  							src = cms.InputTag("slimmedMuons"),
  							cut = cms.string('pt>10&&abs(eta)<2.4&&abs(userFloat("dz"))<0.2&&abs(userFloat("ipDXY"))<0.045&&isLooseMuon&&(((isGlobalMuon&&globalTrack().normalizedChi2()<3&&combinedQuality().chi2LocalPosition<12&&combinedQuality().trkKink<20)&&(innerTrack().validFraction()>=0.8&&segmentCompatibility()>=0.303))||(!(isGlobalMuon&&globalTrack().normalizedChi2()<3&&combinedQuality().chi2LocalPosition<12&&combinedQuality().trkKink<20)&&(innerTrack().validFraction()>=0.8&&segmentCompatibility()>=0.451)))'),
  							filter = cms.bool(False)
  						)

  process.analysisSequence = cms.Sequence(process.analysisSequence*process.TightMuons*process.TightElectrons)
  						
   
def kineWeightsEmbET(process):

  process.load('TauAnalysis/MCEmbeddingTools/embeddingKineReweight_cff')

  process.embeddingKineReweightRECembedding.inputFileName = cms.FileInPath('TauAnalysis/MCEmbeddingTools/data/embeddingKineReweight_ePtGt20tauPtGt18_recEmbedded.root')
  
  process.analysisSequence = cms.Sequence(process.analysisSequence*process.embeddingKineReweightSequenceRECembedding)
  
  
def kineWeightsEmbMT(process):

  process.load('TauAnalysis/MCEmbeddingTools/embeddingKineReweight_cff')

  process.embeddingKineReweightRECembedding.inputFileName = cms.FileInPath('TauAnalysis/MCEmbeddingTools/data/embeddingKineReweight_muPtGt16tauPtGt18_recEmbedded.root')
  
  process.analysisSequence = cms.Sequence(process.analysisSequence*process.embeddingKineReweightSequenceRECembedding)
  						

  						
def applyDefaultSelectionsPT(process):
  #DONT CHANGE THOSE HERE:: THEY ARE NOT USED FOR YOUR SELECTIONS!!!
  #ONLY FOR SYSTEMATICS . PLEASE CHANGE THEM in YOUR CFG FILE IF REALLY NEEDED
  process.selectedPatTaus = cms.EDFilter("PATTauSelector",
                                           src = cms.InputTag("ESTausID"),
                                           cut = cms.string('pt>15&&tauID("byCombinedIsolationDeltaBetaCorrRaw3Hits")<3&&tauID("againstElectronLoose")&&tauID("againstMuonLoose2")'),
                                           filter = cms.bool(False)
  										)  
  process.selectedPatElectrons = cms.EDFilter("PATElectronSelector",
                                           src = cms.InputTag("slimmedElectrons"),
                                           cut = cms.string('pt>10&&userFloat("wp95")>0&&(userIso(0)+max(photonIso+neutralHadronIso()-0.5*userIso(2),0.0))/pt()<0.3'),
                                           filter = cms.bool(False)
  										)
  process.selectedPatMuons = cms.EDFilter("PATMuonSelector",
                                           src = cms.InputTag("slimmedMuons"),
                                           cut = cms.string('pt>10&&userInt("tightID")&&(userIso(0)+max(photonIso+neutralHadronIso()-0.5*puChargedHadronIso,0.0))/pt()<0.3'),
                                           filter = cms.bool(False)
  										) 
  process.cleanPatJets = cms.EDProducer("PATJetCleaner",
                                           src = cms.InputTag("patOverloadedJets"),#"patMVAEmbeddedJets"
                                           #preselection = cms.string('abs(eta)<4.7&&userFloat("idLoose")>0&&pt>10&&userInt("fullIdLoose")>0'),
                                           preselection = cms.string('abs(eta)<4.7&&pt>10'),
                                           checkOverlaps = cms.PSet(),
                                           finalCut = cms.string('')
  										)								 									  
  process.selectedObjectsForSyst = cms.Sequence(process.selectedPatTaus+process.selectedPatElectrons+process.selectedPatMuons+process.cleanPatJets)
  process.analysisSequence = cms.Sequence(process.analysisSequence*process.selectedObjectsForSyst)

def tauTriggerMatchMiniAOD(process,triggerProcess,HLT):
   strTrig=''
   for i in TriggerPaths:
    if i==TriggerPaths[0]:
      strTrig+='path(\"'+i+'\")'
    else:  
      strTrig+='|| path(\"'+i+'\")'


   #Match With The triggers
   process.preTriggeredPatTaus = cms.EDProducer("TauTriggerMatcherMiniAOD",
                                            src = cms.InputTag("ESTausID"),#cleanPatTaus
                                            trigEvent = cms.InputTag(HLT),
                                            filters = cms.vstring(
                                                'hltL1sMu16erTauJet20er',
                                                'hltOverlapFilterIsoMu17LooseIsoPFTau20',
                                                'hltL1sL1IsoEG20erTauJet20er',
                                                'hltOverlapFilterIsoEle22WP85GsfLooseIsoPFTau20'
                                            ),
                                            bits = cms.InputTag("TriggerResults","","HLT"),
                                            prescales = cms.InputTag("patTrigger"),
                                            objects = cms.InputTag("selectedPatTrigger"),
                                            pdgId = cms.int32(0)
   )

   process.triggeredPatTaus = cms.EDProducer("TauTriggerMatcherMiniAOD",
                                            src = cms.InputTag("preTriggeredPatTaus"),
                                            trigEvent = cms.InputTag(HLT),
                                            filters = cms.vstring(
                                                'hltL1sMu16erTauJet20er',
                                                'hltOverlapFilterIsoMu17LooseIsoPFTau20',
                                                'hltL1sL1IsoEG20erTauJet20er',
                                                'hltOverlapFilterIsoEle22WP85GsfLooseIsoPFTau20'
                                            ),
                                            bits = cms.InputTag("TriggerResults","","HLT"),
                                            prescales = cms.InputTag("patTrigger"),
                                            objects = cms.InputTag("selectedPatTrigger"),
                                            pdgId = cms.int32(15)
   )
                                            
   process.analysisSequence=cms.Sequence(process.analysisSequence*process.preTriggeredPatTaus*process.triggeredPatTaus)

def muonTriggerMatchMiniAOD(process,triggerProcess,HLT):

   process.triggeredPatMuons = cms.EDProducer("MuonTriggerMatcherMiniAOD",
                                            src = cms.InputTag("slimmedMuons"),
                                            trigEvent = cms.InputTag(HLT),
                                            filters = cms.vstring(
                                                'hltL1Mu12EG7L3IsoMuFiltered23',#emu filters
                                                'hltL1sL1Mu5EG20ORL1Mu5IsoEG18L3IsoFiltered8',#emu filters
                                                'hltOverlapFilterIsoMu17LooseIsoPFTau20',#mutau filter
                                                'hltL3crIsoL1sMu20Eta2p1L1f0L2f20QL3f24QL3crIsoRhoFiltered0p15IterTrk02',#mutaufilter
                                            ),
                                            bits = cms.InputTag("TriggerResults","","HLT"),
                                            prescales = cms.InputTag("patTrigger"),
                                            objects = cms.InputTag("selectedPatTrigger"),
                                            pdgId = cms.int32(13)
   )
  
   process.analysisSequence*= process.triggeredPatMuons

def electronTriggerMatchMiniAOD(process,triggerProcess,HLT):

   process.triggeredPatElectrons = cms.EDProducer("ElectronTriggerMatcherMiniAOD",
                                            src = cms.InputTag("slimmedElectrons"),
                                            trigEvent = cms.InputTag(HLT),
                                            filters = cms.vstring(
                                                'hltMu23Ele12GsfTrackIsoLegEle12GsfCaloIdTrackIdIsoMediumWPFilter',#emu filters
                                                'hltMu8Ele23GsfTrackIsoLegEle23GsfCaloIdTrackIdIsoMediumWPFilter',#emu filters
                                                'hltOverlapFilterIsoEle22WP85GsfLooseIsoPFTau20',#etau filter
                                                'hltEle27WP85GsfTrackIsoFilter',#etaufilter
                                            ),
                                            bits = cms.InputTag("TriggerResults","","HLT"),
                                            prescales = cms.InputTag("patTrigger"),
                                            objects = cms.InputTag("selectedPatTrigger"),
                                            pdgId = cms.int32(11)
   )
  
   process.analysisSequence*= process.triggeredPatElectrons


def tauOverloading(process,src,vtxSrc):


  process.patOverloadedTaus = cms.EDProducer('PATTauOverloader',
                                        src = cms.InputTag(src),
                                        muons = cms.InputTag('slimmedMuons'),
                                        vtxSrc = cms.InputTag(vtxSrc)
  )                                        

  process.analysisSequence=cms.Sequence(process.analysisSequence*process.patOverloadedTaus)


def getAllEventCounters(process,path,onSkim = False):
        stringList = []
        if onSkim:
          stringList.append('processedEvents')

        modules = listModules(path)
    
        for mod in modules:
            if(hasattr(mod,'label')):
                if mod.label().find('Counter') !=-1 :
                    stringList.append(mod.name.value())
        print 'List Of Filters'        
        print stringList
        
        return cms.untracked.vstring(stringList)

def addEventSummary(process,onSkim = False,name = 'summary',path = 'eventSelection'):
    
   process.TFileService = cms.Service("TFileService", fileName = cms.string("analysis.root") )

   summary = cms.EDAnalyzer('EventSummary',
                            src =getAllEventCounters(process,getattr(process,path),onSkim)
   )

   setattr(process,name,summary)
   if onSkim:
        process.EDMtoMEConverter = cms.EDAnalyzer("EDMtoMEConverter",
                                                  Name = cms.untracked.string('EDMtoMEConverter'),
                                                  Verbosity = cms.untracked.int32(1), # 0 provides no output
                                                  # 1 provides basic output
                                                  Frequency = cms.untracked.int32(50),
                                                  convertOnEndLumi = cms.untracked.bool(True),
                                                  convertOnEndRun = cms.untracked.bool(True),
                                                  runInputTag = cms.InputTag('MEtoEDMConverter', 'MEtoEDMConverterRun'),
                                                  lumiInputTag = cms.InputTag('MEtoEDMConverter', 'MEtoEDMConverterLumi')
                                               )
        eventSummaryPath=cms.EndPath(process.EDMtoMEConverter+getattr(process,name))
        setattr(process,name+"Path",eventSummaryPath)
   else:
        eventSummaryPath=cms.EndPath(getattr(process,name))
        setattr(process,name+"Path",eventSummaryPath)



def createGeneratedParticles(process,name,commands):


  refObjects = cms.EDProducer("GenParticlePruner",
    src = cms.InputTag("prunedGenParticles"),
    select = cms.vstring(
    "drop  *  " 
    )
   )
  refObjects.select.extend(commands)
  setattr(process,name,refObjects)
  process.analysisSequence*= getattr(process,name)

def createGeneratedParticles2(process,name,commands):


  refObjects = cms.EDProducer("GenParticlePruner",
    src = cms.InputTag("prunedGenParticles"),
    select = cms.vstring(
    "drop  *  " 
    )
   )
  refObjects.select.extend(commands)
  setattr(process,name,refObjects)
  #process.analysisSequence*= getattr(process,name)



def createGeneratedTaus(process,decayMode,fiducialCuts):
  process.generatedTaus = cms.EDFilter("TauGenJetDecayModeSelector",
                                       src = cms.InputTag("tauGenJets"),
                                       select = cms.vstring(decayMode),
                                       filter = cms.bool(False)
                                       )
  process.generatedTausInAcceptance = cms.EDFilter("GenJetSelector",
                                           src = cms.InputTag("generatedTaus"),
                                           cut = cms.string(fiducialCuts),
                                           filter = cms.bool(False)
                                           )

  process.analysisSequence*= process.generatedTaus
  process.analysisSequence*= process.generatedTausInAcceptance


def goodVertexFilter(process):

  process.primaryVertexFilter = cms.EDFilter("VertexSelector",
                                        src = cms.InputTag('offlineSlimmedPrimaryVertices'),
                                        cut = cms.string('ndof()>4&&position().rho()<2&&abs(z())<24'),
                                        filter = cms.bool(False)
  )   
  process.analysisSequence*= process.primaryVertexFilter  


def cloneAndReplaceInputTag(process,sequence,oldValue,newValue,postfix):
  #First Clone the sequence
  p = cloneProcessingSnippet(process, sequence, postfix)
  massSearchReplaceAnyInputTag(p,oldValue,newValue )
  modules = listModules(p)

  #Change the labels of the counters
  for mod in modules:
    if(hasattr(mod,'label')):
      if mod.label().find('Counter') !=-1 :
        if(hasattr(mod,'name')):
          newValue = mod.name.value()+postfix
          mod.name=cms.string(newValue)
  return p



def createSystematics(process,sequence,postfix,muScale,eScale,tauScale,jetScale,unclusteredScale,electronresb = 0.0, electronrese = 0.0):

  #First Clone the sequence
  p = cloneProcessingSnippet(process, sequence, postfix)
  modules = listModules(p)

  #Change the labels of the counters and the smearign modules
  for mod in modules:
    if(hasattr(mod,'label')):
      if mod.label().find('Counter') !=-1 :
        if(hasattr(mod,'name')):
          newValue = mod.name.value()+postfix
          mod.name=cms.string(newValue)
      if mod.label().find('smearedMuons') !=-1 :
          mod.energyScale = cms.double(muScale)
      if mod.label().find('smearedTaus') !=-1 :
          mod.energyScale = cms.double(tauScale)
      if mod.label().find('smearedElectrons') !=-1 :
          mod.energyScale = cms.double(eScale)
          mod.deltaPtB = cms.double(electronresb)
          mod.deltaPtE = cms.double(electronrese)
      if mod.label().find('smearedJets') !=-1 :
          mod.energyScaleDB = cms.int32(jetScale)
      if mod.label().find('smearedMET') !=-1 :
          mod.unclusteredScale= cms.double(unclusteredScale)
  return cms.Path(p) 





def createRecoilSystematics(process,sequence,postfix,metScale,metResolution):

  #First Clone the sequence
  p = cloneProcessingSnippet(process, sequence, postfix)
  modules = listModules(p)

  #Change the labels of the counters and the smearign modules
  for mod in modules:
    if(hasattr(mod,'label')):
      if mod.label().find('Counter') !=-1 :
        if(hasattr(mod,'name')):
          newValue = mod.name.value()+postfix
          mod.name=cms.string(newValue)
    if(hasattr(mod,'metCalibration')):
          mod.metCalibration.shiftScale = cms.untracked.double(metScale)
          mod.metCalibration.shiftRes   = cms.untracked.double(metResolution)
      
  return cms.Path(p) 




def pfMetWithSignficance(process):

    # Get PFMET w/ significance
    process.load("TauAnalysis.CandidateTools.PFMETSignCovMatrixEmbedder_cfi")

    process.metWithSig = process.patMETSignEmbedder.clone(
        src = cms.InputTag("systematicsMET"),
        srcCov = cms.InputTag("pfMEtSignCovMatrix")
    )


    process.analysisSequence = cms.Sequence(
        process.analysisSequence *
        process.metWithSig
    )
 
#def pfMetWithSignficance(process):

    # Get PFMET w/ significance
    # 
#    process.load("UWAnalysis.Configuration.tools.pfMetCovariance_cfi")
#    process.load("TauAnalysis.CandidateTools.PFMETSignCovMatrixEmbedder_cfi")
#
#
#    process.metWithSig = process.patMETSignEmbedder.clone(
#        src = cms.InputTag("systematicsMET"),
#        srcCov = cms.InputTag("pfMEtSignCovMatrix")
#    )


#    process.analysisSequence = cms.Sequence(
#        process.analysisSequence *
#        process.metSignficanceSequence *
#        process.metWithSig
#    )
   

# stephane's addition
def addTagAndProbePlotter(process,type,name,src,ref,selections,methods,triggers,triggersProbe):

  process.TFileService = cms.Service("TFileService", fileName = cms.string("analysis.root") )
  muonAnalysis = cms.EDAnalyzer(type,
                                src=cms.InputTag(src),
                                vertices=cms.InputTag("primaryVertexFilter"),
                                ref=cms.InputTag(ref),
                                patTrigger = cms.InputTag("patTrigger"),
                                id= cms.vstring(selections),
                                methods= cms.vstring(methods),
                                triggers = cms.vstring(triggers),
                                triggersProbe = cms.vstring(triggersProbe),
  )                                
  
  setattr(process,'tagAndProbe'+name,muonAnalysis)
  p = cms.EndPath(getattr(process,'tagAndProbe'+name))
  setattr(process,'tagAndProbePath'+name,p)   


