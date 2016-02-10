#!/bin/sh
mkdir /nfs_scratch/$USER/ztt_weighted
cp /nfs_scratch/$USER/ztt_unweighted/* /nfs_scratch/$USER/ztt_weighted/.
cd /nfs_scratch/$USER/ztt_weighted/


weight=0;
weightH=1;
weightEMStitchQCD=0;

if [ $weightEMStitchQCD -eq 1 ]
    then
    #1273000000*0.0002
    EventWeightsIterative outputFile='em1520QCD.root'     weight=254600   histoName='MT/results' #1273000000.0002
    EventWeightsIterative outputFile='em2030QCD.root'     weight=5352960   histoName='MT/results' #557600000*.0096
    EventWeightsIterative outputFile='em3050QCD.root'     weight=9928000   histoName='MT/results' #0.073
    EventWeightsIterative outputFile='em5080QCD.root'     weight=2890800   histoName='MT/results' #19800000*.146
    EventWeightsIterative outputFile='em80120QCD.root'     weight=350000   histoName='MT/results' #2800000*.125
    EventWeightsIterative outputFile='em120170QCD.root'     weight=62964   histoName='MT/results' #477000*.132
    EventWeightsIterative outputFile='em170300QCD.root'     weight=18810   histoName='MT/results' #114000*.165
    EventWeightsIterative outputFile='em300infQCD.root'     weight=1350   histoName='MT/results' #9000*.15        
    hadd emQCD.root em*QCD.root
fi

if [ $weightH -eq 1 ]
    then
    EventWeightsIterativeGen outputFile='ggH.root'     weight=2.7757    histoName='MT/results' sumHistoName='sumweights/genWeights'
fi

if [ $weight -eq 1 ]
    then
    #EventWeightsIterative outputFile='vbfH.root'    weight=3.7     histoName='MT/results'
    #This Includes the filter efficiency-> 0.00042*720648000
    EventWeightsIterativeGen outputFile='muQCD.root'   weight=302672   histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='emQCD.root'   weight=259296   histoName='MT/results' sumHistoName='sumweights/genWeights' #162060000*0.0016 = 259296
    EventWeightsIterativeGen outputFile='ZJets.root'     weight=6025    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='ZJets1050.root'     weight=18610    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='TTJets.root'  weight=832     histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='WJets.root'   weight=61526.7   histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='WZ.root'      weight=22.82   histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='ZZ.root'      weight=10.32  histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='WW.root'     weight=63.21    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='t.root'       weight=35.6    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='tBar.root'    weight=35.6    histoName='MT/results' sumHistoName='sumweights/genWeights'
    hadd -f VV.root WZ.root WW.root ZZ.root t.root tBar.root
fi


