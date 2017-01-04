#!/bin/sh
cd /cms/ojalvo/HTT_80X/laura-working-area/CMSSW_8_0_20/src/UWAnalysis/CRAB/SMHiggs
eval `scramv1 runtime -sh`
bash submitDATAReReco.sh --resubmit-failed-jobs