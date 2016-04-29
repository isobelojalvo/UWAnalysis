#!/bin/sh
#mkdir /nfs_scratch/$USER/htt_weighted17
cp /nfs_scratch/$USER/htt_unweighted17/* /nfs_scratch/$USER/htt_weighted17/.
cd /nfs_scratch/$USER/htt_weighted17/


weight=0;
weightH=0;
weightZ=1;



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
    EventWeightsIterativeZJets    weight=1    histoName='MT/results' 
    hadd ZJETS.root ZJets_ext1.root Z1Jets.root Z2Jets.root Z3Jets.root Z4Jets.root
 
fi


if [ $weight -eq 1 ]
    then
    EventWeightsIterativeGen outputFile='TT.root'  weight=831.76     histoName='MT/results' sumHistoName='sumweights/genWeights'

    EventWeightsIterativeGen outputFile='WJetsMLM.root'   weight=61526.7   histoName='MT/results' sumHistoName='sumweights/genWeights'


    EventWeightsIterativeGen outputFile='WZJets.root'      weight=5.26  histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='WZTo1L1Nu2Q.root'      weight=10.71   histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='WZTo2L2Q.root'      weight=5.595   histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='WZTo1L3Nu.root'      weight=3.05   histoName='MT/results' sumHistoName='sumweights/genWeights'
#add m_ll>30

    EventWeightsIterativeGen outputFile='ZZTo2L2Q.root'      weight=3.22  histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='ZZTo4L.root'      weight=1.212  histoName='MT/results' sumHistoName='sumweights/genWeights'
    #EventWeightsIterativeGen outputFile='ZZTo4Q.root'      weight=1.256  histoName='MT/results' sumHistoName='sumweights/genWeights'

    #EventWeightsIterativeGen outputFile='WWTo2L2Nu.root'     weight=12.178    histoName='MT/results' sumHistoName='sumweights/genWeights'
    #EventWeightsIterativeGen outputFile='WWTo4Q.root'     weight=45.2    histoName='MT/results' sumHistoName='sumweights/genWeights'
    xventWeightsIterativeGen outputFile='WWToLNuQQ.root'     weight=49.997    histoName='MT/results' sumHistoName='sumweights/genWeights'

    EventWeightsIterativeGen outputFile='t_tW.root'       weight=35.6    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='tBar_tW.root'    weight=35.6    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='St_antitop.root'       weight=26.23    histoName='MT/results' sumHistoName='sumweights/genWeights' #80.59 pb * 3*.108
    EventWeightsIterativeGen outputFile='St_top.root'       weight=44.07    histoName='MT/results' sumHistoName='sumweights/genWeights' #136 * 3*.108

    hadd -f DiBoson.root WZJets.root WWTo* WZTo*root ZZTo*.root St_top.root t*_tW.root
    #hadd -f DiBoson.root WZJets.root ZZ*root WW*root St_*top.root t*_tW.root
    #hadd -f ZJetsMerge.root ZJets.root ZJets550.root
fi


