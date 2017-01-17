#!/bin/sh
mkdir /scratch/$USER/muTau_weighted_Jan16
cp /scratch/$USER/muTau_unweighted_Jan16/* /scratch/$USER/muTau_weighted_Jan16/.
cd /scratch/$USER/muTau_weighted_Jan16/


weight=1;
weightTT=1;
weightH=0;
weightW=1;
weightZ=1;



if [ $weightH -eq 1 ]
    then
    echo 'weight higgs to 1 pb'
    EventWeightsIterativeGen outputFile='ggH120.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='ggH125.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='ggH130.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='vbfH120.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='vbfH125.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='vbfH130.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
fi

if [ $weightZ -eq 1 ]
    then
    cp /scratch/ojalvo/zpt_weights.root .
    #Zpt histogram not cureently used in Zpt reweighting 
    #EventWeightsIterativeZJets    weight=1    histoName='MT/results' 
    hadd -f ZJETS.root ZJets_ext1.root Z1Jets.root Z2Jets.root Z3Jets.root Z4Jets.root 
    EventWeightsIterativeZPt    weight=1    histoName='MT/results' 
     
fi

if [ $weightW -eq 1 ]
    then
    #EventWeightsIterativeGen outputFile='WJetsAMC.root'      weight=61526.7   histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeWJets    weight=1    histoName='MT/results'  
    hadd WJETS.root WJetsMLM.root W1Jets.root W2Jets.root W3Jets.root W4Jets.root
 
fi


if [ $weightTT -eq 1 ]
    then
    echo 'Weight TT'
    #EventWeightsIterativeTT outputFile='TTJets.root'  weight=831.76     histoName='MT/results' sumHistoName='sumweights/genWeights'
    nohup EventWeightsIterativeTT outputFile='TT.root'  weight=831.76     histoName='MT/results' sumHistoName='sumweights/genWeights' &
    #EventWeightsIterativeTT has top pt reweighting
    #EventWeightsIterativeTT outputFile='TT.root'  weight=831.76     histoName='MT/results' sumHistoName='sumweights/genWeights'

fi

if [ $weight -eq 1 ]
    then

    #echo 'Weight WAMC'
    echo 'Weight ZZ'
    nohup EventWeightsIterativeGen outputFile='ZZTo2L2Q.root'      weight=3.22  histoName='MT/results' sumHistoName='sumweights/genWeights' &
    #EventWeightsIterativeGen outputFile='ZZTo4L.root'      weight=1.212  histoName='MT/results' sumHistoName='sumweights/genWeights'


    echo 'Weight WZ 1L1NuQQ'
    nohup EventWeightsIterativeGen outputFile='WZTo1L1Nu2Q.root'      weight=10.71   histoName='MT/results' sumHistoName='sumweights/genWeights' &
    echo 'Weight WZ 2L2Q'
    nohup EventWeightsIterativeGen outputFile='WZTo2L2Q.root'      weight=5.595   histoName='MT/results' sumHistoName='sumweights/genWeights' &
    echo 'Weight WZ 1L3Nu'
    nohup EventWeightsIterativeGen outputFile='WZTo1L3Nu.root'      weight=3.05   histoName='MT/results' sumHistoName='sumweights/genWeights' &
    #EventWeightsIterativeGen outputFile='WZJTo1L3Nu.root'      weight=4.708   histoName='MT/results' sumHistoName='sumweights/genWeights'
#add m_ll>30

    ####echo 'Weight WW to L1Nu QQ'
    ####nohup EventWeightsIterativeGen outputFile='WWTo1L1Nu2Q.root'     weight=1.212     histoName='MT/results' sumHistoName='sumweights/genWeights' &
    #EventWeightsIterativeGen outputFile='WWTo2L2Q.root'     weight=49.997    histoName='MT/results' sumHistoName='sumweights/genWeights'

    echo 'Weight VV to 2L2Nu'
    nohup  EventWeightsIterativeGen outputFile='VVTo2L2Nu.root'      weight=11.95    histoName='MT/results' sumHistoName='sumweights/genWeights' &

    echo 'Weight t_tW'
    nohup EventWeightsIterativeGen outputFile='ST_tW_top.root'       weight=35.6    histoName='MT/results' sumHistoName='sumweights/genWeights' &
    echo 'Weight tBar_tW'
    nohup EventWeightsIterativeGen outputFile='ST_tW_antitop.root'   weight=35.6    histoName='MT/results' sumHistoName='sumweights/genWeights' &
    echo 'Weight St_antitop'
    nohup EventWeightsIterativeGen outputFile='ST_t_antitop.root'    weight=80.95    histoName='MT/results' sumHistoName='sumweights/genWeights' & #80.59 pb * 3*.108
    echo 'Weight St_top'
    nohup EventWeightsIterativeGen outputFile='ST_t_top.root'        weight=136.02     histoName='MT/results' sumHistoName='sumweights/genWeights' & #136 * 3*.108

    hadd -f DiBoson.root  WZTo*root ZZTo*.root ST_*.root  VVTo*root
fi



