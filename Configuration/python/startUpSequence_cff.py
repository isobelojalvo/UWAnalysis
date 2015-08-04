import FWCore.ParameterSet.Config as cms


from DQMServices.Core.DQM_cfg import *
from DQMServices.Components.DQMEnvironment_cfi import *
from DQMServices.Components.MEtoEDMConverter_cfi import *
from DQMServices.Components.EDMtoMEConverter_cfi import *


saveHistos = cms.Sequence(MEtoEDMConverter)
loadHistos = cms.Sequence(EDMtoMEConverter)


initialCounter = cms.EDProducer('EventCounter',
                         name = cms.string("initialEvents")
)

initialCounterGenWeights = cms.EDProducer('GenEventSum',
                         name = cms.string("GenWeightSum")
)

startupSequence = cms.Sequence(initialCounter+initialCounterGenWeights)


startupSequenceFromSkim = cms.Sequence(loadHistos)

