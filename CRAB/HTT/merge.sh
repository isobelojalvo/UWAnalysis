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
    /cms/sw/farmout/mergeFiles --reuse-cache-files muQCD.root /hdfs/store/user/$USER/muQCD-SUB-MC &
    /cms/sw/farmout/mergeFiles --reuse-cache-files em1520QCD.root /hdfs/store/user/$USER/1520QCD-SUB-MC &
    /cms/sw/farmout/mergeFiles --reuse-cache-files em2030QCD.root /hdfs/store/user/$USER/2030QCD-SUB-MC &
    /cms/sw/farmout/mergeFiles --reuse-cache-files em3050QCD.root /hdfs/store/user/$USER/3050QCD-SUB-MC &
    /cms/sw/farmout/mergeFiles --reuse-cache-files em5080QCD.root /hdfs/store/user/$USER/5080QCD-SUB-MC &
    /cms/sw/farmout/mergeFiles --reuse-cache-files em80120QCD.root /hdfs/store/user/$USER/80120QCD-SUB-MC &
    /cms/sw/farmout/mergeFiles --reuse-cache-files em120170QCD.root /hdfs/store/user/$USER/120170QCD-SUB-MC &
    /cms/sw/farmout/mergeFiles --reuse-cache-files em170300QCD.root /hdfs/store/user/$USER/170300QCD-SUB-MC &
    /cms/sw/farmout/mergeFiles --reuse-cache-files em300infQCD.root /hdfs/store/user/$USER/em300infQCD-SUB-MC &
    /cms/sw/farmout/mergeFiles --reuse-cache-files ZJets.root /hdfs/store/user/$USER/ZJets-SUB-MC &
    /cms/sw/farmout/mergeFiles --reuse-cache-files WW.root /hdfs/store/user/$USER/WW-SUB-MC 
    /cms/sw/farmout/mergeFiles --reuse-cache-files ZZ.root /hdfs/store/user/$USER/ZZ-SUB-MC 
    nohup /cms/sw/farmout/mergeFiles --reuse-cache-files TTJets.root /hdfs/store/user/$USER/TTJets-SUB-MC &
    #nohup /cms/sw/farmout/mergeFiles --reuse-cache-files TT.root /hdfs/store/user/$USER/TT_Tune4C-SUB-MC &
    nohup /cms/sw/farmout/mergeFiles --reuse-cache-files WJets.root /hdfs/store/user/$USER/WJets-SUB-MC &
    nohup /cms/sw/farmout/mergeFiles --reuse-cache-files WZ.root /hdfs/store/user/$USER/WZJets-SUB-MC &
    nohup /cms/sw/farmout/mergeFiles --reuse-cache-files t.root /hdfs/store/user/$USER/t_tW-SUB-MC &
    nohup /cms/sw/farmout/mergeFiles --reuse-cache-files tBar.root /hdfs/store/user/$USER/tBar_tW-SUB-MC &
fi

if [ $weight -eq 1 ]
    then
    #EventWeightsIterative outputFile='ggH.root'     weight=43.9    histoName='MT/results'
    #EventWeightsIterative outputFile='vbfH.root'    weight=3.7     histoName='MT/results'
    EventWeightsIterative outputFile='muQCD.root'   weight=720648000   histoName='MT/results'
    EventWeightsIterative outputFile='em1520QCD.root'     weight=1273000000   histoName='MT/results'
    EventWeightsIterative outputFile='em2030QCD.root'     weight=557600000   histoName='MT/results'
    EventWeightsIterative outputFile='em3050QCD.root'     weight=136000000   histoName='MT/results'
    EventWeightsIterative outputFile='em5080QCD.root'     weight=19800000   histoName='MT/results'
    EventWeightsIterative outputFile='em80120QCD.root'     weight=2800000   histoName='MT/results'
    EventWeightsIterative outputFile='em120170QCD.root'     weight=477000   histoName='MT/results'
    EventWeightsIterative outputFile='em170300QCD.root'     weight=114000   histoName='MT/results'
    EventWeightsIterative outputFile='em300infQCD.root'     weight=9000   histoName='MT/results'
    EventWeightsIterative outputFile='ZJets.root'     weight=6025    histoName='MT/results'
    EventWeightsIterative outputFile='TTJets.root'  weight=832     histoName='MT/results'
    #EventWeightsIterative outputFile='TT.root'      weight=832     histoName='MT/results'
    EventWeightsIterative outputFile='WJets.root'   weight=20509   histoName='MT/results'
    EventWeightsIterative outputFile='WZ.root'      weight=1.634   histoName='MT/results'
    EventWeightsIterative outputFile='ZZ.root'      weight=15.4   histoName='MT/results'
    EventWeightsIterative outputFile='t.root'       weight=35.6    histoName='MT/results'
    EventWeightsIterative outputFile='tBar.root'    weight=35.6    histoName='MT/results'
    EventWeightsIterative outputFile='WW.root'     weight=110.8    histoName='MT/results'
    hadd VV.root WZ.root WW.root ZZ.root t.root tBar.root
fi


