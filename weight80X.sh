#!/bin/sh
mkdir /scratch/$USER/ztt_weighted17
cp /scratch/$USER/ztt_unweighted17/* /scratch/$USER/ztt_weighted17/.
cd /scratch/$USER/ztt_weighted17/
exit

weight=1;
weightH=1;
weightW=1;
weight=0;
weightZ=1;



if [ $weightH -eq 1 ]
    then
    #EventWeightsIterativeGen outputFile='ggH120.root'     weight=1    histoName='TT/results' sumHistoName='sumweights/genWeights'
    echo 'weight higgs'
    #mv ggH.root ggH125.root
    #mv vbfH.root vbfH125.root
    EventWeightsIterativeGen outputFile='ggH125.root'     weight=1    histoName='TT/results' sumHistoName='sumweights/genWeights'
    #EventWeightsIterativeGen outputFile='ggH130.root'     weight=1    histoName='TT/results' sumHistoName='sumweights/genWeights'
    #EventWeightsIterativeGen outputFile='vbfH120.root'     weight=1    histoName='TT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='vbfH125.root'     weight=1    histoName='TT/results' sumHistoName='sumweights/genWeights'
    #EventWeightsIterativeGen outputFile='vbfH130.root'     weight=1    histoName='TT/results' sumHistoName='sumweights/genWeights'
fi

if [ $weightZ -eq 1 ]
    then
    #make sure Zpt root file is around!!!
    EventWeightsIterativeZJets    weight=1    histoName='TT/results' 
    hadd -f ZJETS.root ZJets_ext1.root Z1Jets.root Z2Jets.root Z3Jets.root ZJets_150.root
     
fi

if [ $weightW -eq 1 ]
    then
    cp WJets.root WJetsMLM.root
    EventWeightsIterativeGen outputFile='WJets.root'      weight=61526.7   histoName='TT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeWJets    weight=1    histoName='TT/results' 
    hadd WJETS.root WJetsMLM.root W1Jets.root W2Jets.root W3Jets.root W4Jets.root
 
fi



if [ $weight -eq 1 ]
    then
    echo 'Weight TT'
    EventWeightsIterativeGen outputFile='TTJets.root'  weight=831.76     histoName='TT/results' sumHistoName='sumweights/genWeights'
    #EventWeightsIterativeTT has top pt reweighting
    #EventWeightsIterativeTT outputFile='TT.root'  weight=831.76     histoName='TT/results' sumHistoName='sumweights/genWeights'


    #echo 'Weight WAMC'
    #EventWeightsIterativeGen outputFile='WJetsAMC.root'      weight=61526.7   histoName='TT/results' sumHistoName='sumweights/genWeights'
    echo 'Weight ZZ'
    EventWeightsIterativeGen outputFile='ZZTo2L2Q.root'      weight=3.22  histoName='TT/results' sumHistoName='sumweights/genWeights'
    #EventWeightsIterativeGen outputFile='ZZTo4L.root'      weight=1.212  histoName='TT/results' sumHistoName='sumweights/genWeights'


    echo 'Weight WZ 1L1NuQQ'
    EventWeightsIterativeGen outputFile='WZTo1L1Nu2Q.root'      weight=10.71   histoName='TT/results' sumHistoName='sumweights/genWeights'
    echo 'Weight WZ 2L2Q'
    EventWeightsIterativeGen outputFile='WZTo2L2Q.root'      weight=5.595   histoName='TT/results' sumHistoName='sumweights/genWeights'
    echo 'Weight WZ 1L3Nu'
    EventWeightsIterativeGen outputFile='WZTo1L3Nu.root'      weight=3.05   histoName='TT/results' sumHistoName='sumweights/genWeights'
    #EventWeightsIterativeGen outputFile='WZJTo1L3Nu.root'      weight=4.708   histoName='TT/results' sumHistoName='sumweights/genWeights'
#add m_ll>30

    echo 'Weight WW to L1Nu QQ'
    #EventWeightsIterativeGen outputFile='WWToLNuQQ.root'     weight=49.997    histoName='TT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='WWTo2L2Q.root'     weight=49.997    histoName='TT/results' sumHistoName='sumweights/genWeights'

    echo 'Weight VV to 2L2Nu'
    EventWeightsIterativeGen outputFile='VVTo2L2Nu.root'     weight=11.95    histoName='TT/results' sumHistoName='sumweights/genWeights'
    echo 'Weight t_tW'
    EventWeightsIterativeGen outputFile='t_tW.root'       weight=35.6    histoName='TT/results' sumHistoName='sumweights/genWeights'
    echo 'Weight tBar_tW'
    EventWeightsIterativeGen outputFile='tBar_tW.root'    weight=35.6    histoName='TT/results' sumHistoName='sumweights/genWeights'
    echo 'Weight St_antitop'
    EventWeightsIterativeGen outputFile='St_antitop.root'       weight=26.23    histoName='TT/results' sumHistoName='sumweights/genWeights' #80.59 pb * 3*.108
    echo 'Weight St_top'
    EventWeightsIterativeGen outputFile='St_top.root'       weight=44.07    histoName='TT/results' sumHistoName='sumweights/genWeights' #136 * 3*.108

    hadd -f DiBoson.root WWTo*root WZTo*root ZZTo*.root St_*.root t*tW.root #VVTo*root
fi



