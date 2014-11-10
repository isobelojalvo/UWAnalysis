#!/bin/sh
voms-proxy-init --voms cms --valid 100:00

farmoutAnalysisJobs  $1   --vsize-limit=8000   --input-dir=/store/user/laura/SUSYBBHTohhTo2Tau2B_mH-260_mh-125_8TeV-pythia6-tauola/Summer12_DR53X-PU_S10_START53_V19-v1/ bbHhh260 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py
farmoutAnalysisJobs  $1   --vsize-limit=8000   --input-dir=/store/user/laura/SUSYBBHTohhTo2Tau2B_mH-300_mh-125_8TeV-pythia6-tauola/Summer12_DR53X-PU_S10_START53_V19-v1/ bbHhh300 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py
farmoutAnalysisJobs  $1   --vsize-limit=8000   --input-dir=/store/user/laura/SUSYBBHTohhTo2Tau2B_mH-350_mh-125_8TeV-pythia6-tauola/Summer12_DR53X-PU_S10_START53_V19-v1/ bbHhh350 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCH.py

############################################################################################################################################
