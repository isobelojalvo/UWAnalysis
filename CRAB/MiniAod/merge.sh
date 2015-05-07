#!/bin/sh

mkdir /nfs_scratch/$USER/ztautau
cd /nfs_scratch/$USER/ztautau

merge=1;
weight=0;

if [ $merge -eq 1 ]
    then
    /cms/sw/farmout/mergeFiles --reuse-cache-files ggH.root /hdfs/store/user/$USER/ggHtautau-SUB-MCH &
    /cms/sw/farmout/mergeFiles --reuse-cache-files vbfH.root /hdfs/store/user/$USER/vbfHtautau-SUB-MCH &
    /cms/sw/farmout/mergeFiles --reuse-cache-files QCD.root /hdfs/store/user/$USER/QCD_15to3000Flat-SUB-MC &
    /cms/sw/farmout/mergeFiles --reuse-cache-files ZTT.root /hdfs/store/user/$USER/dyJetsLL-SUB-MC &
    nohup /cms/sw/farmout/mergeFiles --reuse-cache-files TTJets.root /hdfs/store/user/$USER/TT_MSCKM-SUB-MC &
    nohup /cms/sw/farmout/mergeFiles --reuse-cache-files TT.root /hdfs/store/user/$USER/TT_Tune4C-SUB-MC &
    nohup /cms/sw/farmout/mergeFiles --reuse-cache-files WJets.root /hdfs/store/user/$USER/WJets-SUB-MC &
    nohup /cms/sw/farmout/mergeFiles --reuse-cache-files WZ.root /hdfs/store/user/$USER/WZJets-SUB-MC &
    nohup /cms/sw/farmout/mergeFiles --reuse-cache-files t.root /hdfs/store/user/$USER/t_tW-SUB-MC &
    nohup /cms/sw/farmout/mergeFiles --reuse-cache-files tBar.root /hdfs/store/user/$USER/tBar_tW-SUB-MC &
fi

if [ $weight -eq 1 ]
    then
#    EventWeightsForEfficiencyFast $1 outputFile='ggH.root'
    EventWeightsIterative outputFile='ggH.root'      doOneD=1   weight=43.9 type=6 histoName='MT/results'
    EventWeightsIterative outputFile='vbfH.root'      doOneD=1   weight=3.7 type=6 histoName='MT/results'
    EventWeightsIterative outputFile='QCD.root'      doOneD=1   weight=1 type=6 histoName='MT/results'
    EventWeightsIterative outputFile='ZTT.root'      doOneD=1   weight=6025 type=6 histoName='MT/results'
    EventWeightsIterative outputFile='TTJets.root'      doOneD=1   weight=832 type=6 histoName='MT/results'
    EventWeightsIterative outputFile='TT.root'      doOneD=1   weight=832 type=6 histoName='MT/results'
    EventWeightsIterative outputFile='WJets.root'      doOneD=1   weight=20509 type=6 histoName='MT/results'
    EventWeightsIterative outputFile='WZ.root'      doOneD=1   weight=1.634 type=6 histoName='MT/results'
    EventWeightsIterative outputFile='t.root'      doOneD=1   weight=35.6 type=6 histoName='MT/results'
    EventWeightsIterative outputFile='tBar.root'      doOneD=1   weight=35.6 type=6 histoName='MT/results'
fi


