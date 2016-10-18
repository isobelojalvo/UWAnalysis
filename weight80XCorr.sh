#!/bin/sh
infilename=ztt_weighted22
filename=ztt_weighted22Corr3
mkdir /data/$USER/$filename
cp /data/$USER/$infilename/* /data/$USER/$filename/.
cd /data/$USER/$filename/


#EventWeightsForEfficiencyTrigger2016 outputFile='ZJETS.root'
#EventWeightsForEfficiencyTrigger2016 outputFile='WJETS.root'
#EventWeightsForEfficiencyTrigger2016 outputFile='TT.root'
#EventWeightsForEfficiencyTrigger2016 outputFile='DiBoson.root'

EventWeightsForEfficiencyTrigger2016 outputFile='ggH120.root'
EventWeightsForEfficiencyTrigger2016 outputFile='ggH125.root'
EventWeightsForEfficiencyTrigger2016 outputFile='ggH130.root'
EventWeightsForEfficiencyTrigger2016 outputFile='vbfH120.root'
EventWeightsForEfficiencyTrigger2016 outputFile='vbfH125.root'
EventWeightsForEfficiencyTrigger2016 outputFile='vbfH130.root'
EventWeightsForEfficiencyTrigger2016 outputFile='ZH120.root'
EventWeightsForEfficiencyTrigger2016 outputFile='ZH125.root'
EventWeightsForEfficiencyTrigger2016 outputFile='ZH130.root'
EventWeightsForEfficiencyTrigger2016 outputFile='WpH120.root'
EventWeightsForEfficiencyTrigger2016 outputFile='WpH125.root'
EventWeightsForEfficiencyTrigger2016 outputFile='WpH130.root'
EventWeightsForEfficiencyTrigger2016 outputFile='WmH120.root'
EventWeightsForEfficiencyTrigger2016 outputFile='WmH125.root'
EventWeightsForEfficiencyTrigger2016 outputFile='WmH130.root'
EventWeightsForEfficiencyTrigger2016 outputFile='ttH120.root'
EventWeightsForEfficiencyTrigger2016 outputFile='ttH125.root'
EventWeightsForEfficiencyTrigger2016 outputFile='ttH130.root'
