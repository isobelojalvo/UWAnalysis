#!/bin/sh
mkdir /nfs_scratch/$USER/80X_ztt_weighted7
cp /nfs_scratch/$USER/80X_ztt_unweighted7/* /nfs_scratch/$USER/80X_ztt_weighted7/.
cd /nfs_scratch/$USER/80X_ztt_weighted7/


weight=1;
weightH=1;
weightW=1;
weightZ=1;



if [ $weightH -eq 1 ]
    then
    #EventWeightsIterativeGen outputFile='ggH120.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    echo 'weight higgs'
    EventWeightsIterativeGen outputFile='ggH125.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    #EventWeightsIterativeGen outputFile='ggH130.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    #EventWeightsIterativeGen outputFile='vbfH120.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    #EventWeightsIterativeGen outputFile='vbfH125.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    #EventWeightsIterativeGen outputFile='vbfH130.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
fi

if [ $weightZ -eq 1 ]
    then
    #make sure Zpt root file is around!!!
    EventWeightsIterativeZJets    weight=1    histoName='MT/results' 
    hadd ZJETS.root ZJets_ext1.root Z1Jets.root Z2Jets.root Z3Jets.root ZJets_150.root
    #EventWeightsIterativeZPt    weight=1    histoName='MT/results' 
     
fi

if [ $weightW -eq 1 ]
    then
    EventWeightsIterativeGen outputFile='WJetsAMC.root'      weight=61526.7   histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeWJets    weight=1    histoName='MT/results' 
    hadd WJETS.root WJetsMLM.root W1Jets.root W2Jets.root W3Jets.root W4Jets.root
 
fi



if [ $weight -eq 1 ]
    then
    echo 'Weight TT'
    EventWeightsIterativeGen outputFile='TTJets.root'  weight=831.76     histoName='MT/results' sumHistoName='sumweights/genWeights'
    #EventWeightsIterativeTT has top pt reweighting
    #EventWeightsIterativeTT outputFile='TT.root'  weight=831.76     histoName='MT/results' sumHistoName='sumweights/genWeights'


    #echo 'Weight WAMC'
    #EventWeightsIterativeGen outputFile='WJetsAMC.root'      weight=61526.7   histoName='MT/results' sumHistoName='sumweights/genWeights'
    echo 'Weight ZZ'
    EventWeightsIterativeGen outputFile='ZZTo2L2Q.root'      weight=3.22  histoName='MT/results' sumHistoName='sumweights/genWeights'
    #EventWeightsIterativeGen outputFile='ZZTo4L.root'      weight=1.212  histoName='MT/results' sumHistoName='sumweights/genWeights'


    echo 'Weight WZ 1L1NuQQ'
    EventWeightsIterativeGen outputFile='WZTo1L1Nu2Q.root'      weight=10.71   histoName='MT/results' sumHistoName='sumweights/genWeights'
    echo 'Weight WZ 2L2Q'
    EventWeightsIterativeGen outputFile='WZTo2L2Q.root'      weight=5.595   histoName='MT/results' sumHistoName='sumweights/genWeights'
    echo 'Weight WZ 1L3Nu'
    EventWeightsIterativeGen outputFile='WZTo1L3Nu.root'      weight=3.05   histoName='MT/results' sumHistoName='sumweights/genWeights'
    #EventWeightsIterativeGen outputFile='WZJTo1L3Nu.root'      weight=4.708   histoName='MT/results' sumHistoName='sumweights/genWeights'
#add m_ll>30

    echo 'Weight WW to L1Nu QQ'
    #EventWeightsIterativeGen outputFile='WWToLNuQQ.root'     weight=49.997    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='WWTo2L2Q.root'     weight=49.997    histoName='MT/results' sumHistoName='sumweights/genWeights'

    echo 'Weight VV to 2L2Nu'
    EventWeightsIterativeGen outputFile='VVTo2L2Nu.root'     weight=11.95    histoName='MT/results' sumHistoName='sumweights/genWeights'

    echo 'Weight t_tW'
    EventWeightsIterativeGen outputFile='t_tW.root'       weight=35.6    histoName='MT/results' sumHistoName='sumweights/genWeights'
    echo 'Weight tBar_tW'
    EventWeightsIterativeGen outputFile='tBar_tW.root'    weight=35.6    histoName='MT/results' sumHistoName='sumweights/genWeights'
    echo 'Weight St_antitop'
    EventWeightsIterativeGen outputFile='St_antitop.root'       weight=26.23    histoName='MT/results' sumHistoName='sumweights/genWeights' #80.59 pb * 3*.108
    echo 'Weight St_top'
    EventWeightsIterativeGen outputFile='St_top.root'       weight=44.07    histoName='MT/results' sumHistoName='sumweights/genWeights' #136 * 3*.108

    hadd -f DiBoson.root WWTo*root WZTo*root ZZTo*.root St_*.root t*tW.root VVTo*root
fi



