#!/bin/sh
mkdir /nfs_scratch/$USER/80X_ztt_weighted1
cp /nfs_scratch/$USER/80X_ztt_unweighted1/* /nfs_scratch/$USER/80X_ztt_weighted1/.
cd /nfs_scratch/$USER/80X_ztt_weighted1/


weight=1;
weightH=0;
weightW=1;
weightZ=1;
weightTMP=0;


if [ $weightTMP -eq 1 ]
    then
    EventWeightsIterativeGen outputFile='WJets_amc.root'      weight=60781.5   histoName='MT/results' sumHistoName='sumweights/genWeights'
fi

if [ $weightH -eq 1 ]
    then
    EventWeightsIterativeGen outputFile='ggH120.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='ggH125.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='ggH130.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='vbfH120.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='vbfH125.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='vbfH130.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
fi

if [ $weightZ -eq 1 ]
    then
    #make sure Zpt root file is around!!!
    EventWeightsIterativeZJets    weight=1    histoName='MT/results' 
    hadd ZJETS.root ZJets.root Z1Jets.root Z2Jets.root Z3Jets.root ZJets_150.root
    EventWeightsIterativeZPt    weight=1    histoName='MT/results' 
     
fi

if [ $weightW -eq 1 ]
    then
    EventWeightsIterativeGen outputFile='WJets_amc.root'      weight=60781.5   histoName='MT/results' sumHistoName='sumweights/genWeights'
    #EventWeightsIterativeWJets    weight=1    histoName='MT/results' 
    #hadd WJETS.root WJetsMLM.root W1Jets.root W2Jets.root W3Jets.root W4Jets.root
 
fi



if [ $weight -eq 1 ]
    then
    EventWeightsIterativeGen outputFile='TT.root'  weight=831.76     histoName='MT/results' sumHistoName='sumweights/genWeights'
    #EventWeightsIterativeTT has top pt reweighting
    #EventWeightsIterativeTT outputFile='TT.root'  weight=831.76     histoName='MT/results' sumHistoName='sumweights/genWeights'


    EventWeightsIterativeGen outputFile='WZ.root'      weight=10.71   histoName='MT/results' sumHistoName='sumweights/genWeights'
#add m_ll>30

    EventWeightsIterativeGen outputFile='ZZTo2L2Q.root'      weight=3.22  histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='ZZTo4L.root'      weight=1.212  histoName='MT/results' sumHistoName='sumweights/genWeights'

    EventWeightsIterativeGen outputFile='tBar_tW.root'    weight=35.6    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='St_antitop.root'       weight=26.23    histoName='MT/results' sumHistoName='sumweights/genWeights' #80.59 pb * 3*.108

    hadd -f DiBoson.root WZ*root ZZTo*.root St_*.root t*tW.root 
    #hadd -f DiBoson.root WWTo*root WZ*root ZZTo*.root St_*.root t*tW.root VVTo*root
fi

