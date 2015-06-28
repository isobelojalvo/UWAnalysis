#!/bin/sh

mkdir /nfs_scratch/$USER/ztt_74X
cd /nfs_scratch/$USER/ztt_74X


#only run merge or weight. Do not set both to 1.
merge=1;
weight=0;


if [ $merge -eq 1 ]
    then
    #/cms/sw/farmout/mergeFiles --reuse-cache-files ggH.root /hdfs/store/user/$USER/ggHtautau-SUB-MCH &
    #/cms/sw/farmout/mergeFiles --reuse-cache-files vbfH.root /hdfs/store/user/$USER/vbfHtautau-SUB-MCH &
    /cms/sw/farmout/mergeFiles --reuse-cache-files QCD.root /hdfs/store/user/$USER/QCD-SUB-MC &
    /cms/sw/farmout/mergeFiles --reuse-cache-files ZJets.root /hdfs/store/user/$USER/ZJets-SUB-MC &
    /cms/sw/farmout/mergeFiles --reuse-cache-files WW.root /hdfs/store/user/$USER/WW-SUB-MC 
    nohup /cms/sw/farmout/mergeFiles --reuse-cache-files TTJets.root /hdfs/store/user/$USER/TTJets-SUB-MC &
    nohup /cms/sw/farmout/mergeFiles --reuse-cache-files TT.root /hdfs/store/user/$USER/TT_Tune4C-SUB-MC &
    nohup /cms/sw/farmout/mergeFiles --reuse-cache-files WJets.root /hdfs/store/user/$USER/WJets-SUB-MC &
    nohup /cms/sw/farmout/mergeFiles --reuse-cache-files WZ.root /hdfs/store/user/$USER/WZJets-SUB-MC &
    nohup /cms/sw/farmout/mergeFiles --reuse-cache-files t.root /hdfs/store/user/$USER/t_tW-SUB-MC &
    nohup /cms/sw/farmout/mergeFiles --reuse-cache-files tBar.root /hdfs/store/user/$USER/tBar_tW-SUB-MC &
fi

if [ $weight -eq 1 ]
    then
    #EventWeightsIterative outputFile='ggH.root'     weight=43.9    histoName='MT/results'
    #EventWeightsIterative outputFile='vbfH.root'    weight=3.7     histoName='MT/results'
    EventWeightsIterative outputFile='QCD.root'     weight=125000000000   histoName='MT/results'
    EventWeightsIterative outputFile='ZTT.root'     weight=6025    histoName='MT/results'
    EventWeightsIterative outputFile='TTJets.root'  weight=832     histoName='MT/results'
    EventWeightsIterative outputFile='TT.root'      weight=832     histoName='MT/results'
    EventWeightsIterative outputFile='WJets.root'   weight=20509   histoName='MT/results'
    EventWeightsIterative outputFile='WZ.root'      weight=1.634   histoName='MT/results'
    EventWeightsIterative outputFile='t.root'       weight=35.6    histoName='MT/results'
    EventWeightsIterative outputFile='tBar.root'    weight=35.6    histoName='MT/results'
    EventWeightsIterative outputFile='WW.root'     weight=110.8    histoName='MT/results'
    hadd VV.root WZ.root t.root tBar.root
fi


