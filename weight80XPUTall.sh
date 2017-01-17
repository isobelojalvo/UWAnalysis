#!/bin/sh

mkdir /scratch/$USER/muTau_weighted_Jan16_corr/
for dir in WJETS.root ZJETS.root TT.root DiBoson.root muDATA.root
do
    cp /scratch/$USER/muTau_weighted_Jan16/* /scratch/$USER/muTau_weighted_Jan16_corr/.
done
cd /scratch/$USER/muTau_weighted_Jan16_corr/


weight=1;
weightTT=1;
weightH=0;
weightW=1;
weightZ=1;

if [ $weightH -eq 1 ]
    then
    echo 'weight higgs to 1 pb'
    EventWeightsIterativeEra outputFile='ggH120.root'   
    EventWeightsIterativeEra outputFile='ggH125.root'   
    EventWeightsIterativeEra outputFile='ggH130.root'   
    EventWeightsIterativeEra outputFile='vbfH120.root'  
    EventWeightsIterativeEra outputFile='vbfH125.root'  
    EventWeightsIterativeEra outputFile='vbfH130.root'  
fi

if [ $weightZ -eq 1 ]
    then
    #Zpt histogram not cureently used in Zpt reweighting 
    EventWeightsIterativeEra outputFile='ZJETS.root'
fi

if [ $weightW -eq 1 ]
    then
    EventWeightsIterativeEra outputFile='WJETS.root'
fi


if [ $weightTT -eq 1 ]
    then
    echo 'Weight TT'
    EventWeightsIterativeEra outputFile="TT.root"
fi

if [ $weight -eq 1 ]
    then
    EventWeightsIterativeEra outputFile="DiBoson.root"
fi



