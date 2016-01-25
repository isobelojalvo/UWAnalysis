#!/bin/sh
mkdir /nfs_scratch/$USER/ztt_weighted2
#/nfs_scratch/$USER/ztt_weighted2/
cp /nfs_scratch/$USER/ztt_unweighted2/* /nfs_scratch/$USER/ztt_weighted2/.
cd /nfs_scratch/$USER/ztt_weighted2/


weight=1;

if [ $weight -eq 1 ]
    then
    #uncomment below if higgs
    #EventWeightsIterative outputFile='ggH.root'     weight=43.9    histoName='MT/results'
    #EventWeightsIterative outputFile='vbfH.root'    weight=3.7     histoName='MT/results'
    #1273000000*0.0002
    #EventWeightsIterative outputFile='em1520QCD.root'     weight=254600   histoName='MT/results'#1273000000.0002
    #EventWeightsIterative outputFile='em2030QCD.root'     weight=5352960   histoName='MT/results'#557600000*.0096
    #EventWeightsIterative outputFile='em3050QCD.root'     weight=9928000   histoName='MT/results' #0.073
    #EventWeightsIterative outputFile='em5080QCD.root'     weight=2890800   histoName='MT/results'#19800000*.146
    #EventWeightsIterative outputFile='em80120QCD.root'     weight=350000   histoName='MT/results' #2800000*.125
    #EventWeightsIterative outputFile='em120170QCD.root'     weight=62964   histoName='MT/results' #477000*.132
    #!EventWeightsIterative outputFile='em170300QCD.root'     weight=18810   histoName='MT/results'#114000*.165
    #EventWeightsIterative outputFile='em300infQCD.root'     weight=1350   histoName='MT/results' #9000*.15        
    #hadd emQCD.root em*QCD.root

    #This Includes the filter efficiency-> 0.00042*720648000
    #EventWeightsIterative outputFile='muQCD.root'   weight=302672   histoName='MT/results'
    EventWeightsIterative outputFile='ZJets.root'     weight=6025    histoName='MT/results'
    EventWeightsIterative outputFile='TTJets.root'  weight=832     histoName='MT/results'
    EventWeightsIterative outputFile='WJets.root'   weight=20509   histoName='MT/results'
    EventWeightsIterative outputFile='WZ.root'      weight=22.82   histoName='MT/results'
    EventWeightsIterative outputFile='ZZ.root'      weight=10.32  histoName='MT/results'
    EventWeightsIterative outputFile='WW.root'     weight=63.21    histoName='MT/results'
    EventWeightsIterative outputFile='t.root'       weight=35.6    histoName='MT/results'
    #EventWeightsIterative outputFile='tBar.root'    weight=35.6    histoName='MT/results'
    hadd -f VV.root WZ.root WW.root ZZ.root t.root tBar.root
fi


