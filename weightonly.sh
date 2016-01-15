#!/bin/sh
mkdir /nfs_scratch/$USER/ztt_weighted17_NoHF
cp /nfs_scratch/$USER/ztt_unweighted17_NoHF/* /nfs_scratch/$USER/ztt_weighted17_NoHF/.
cd /nfs_scratch/$USER/ztt_unweighted17_Golden/


weight=1;
weightH=1;
weightW=0;
weightEMStitchQCD=0;
weightBCtoE=0;



if [ $weightH -eq 1 ]
    then
    EventWeightsIterativeGenPU outputFile='ggH.root'     weight=2.7757    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenPU outputFile='vbfH.root'     weight=0.2368    histoName='MT/results' sumHistoName='sumweights/genWeights'
fi

if [ $weightW -eq 1 ]
    then
    EventWeightsIterativeGenPU outputFile='WJetsHT100.root'     weight=1347    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenPU outputFile='WJetsHT200.root'     weight=360    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenPU outputFile='WJetsHT400.root'     weight=48.98    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenPU outputFile='WJetsHT600.root'     weight=18.77    histoName='MT/results' sumHistoName='sumweights/genWeights'
    hadd WJetsHTStitched.root WJetsHT*
fi


if [ $weight -eq 1 ]
    then
    #This Includes the filter efficiency-> 0.00042*720648000
    #EventWeightsIterativeGenPU outputFile='muQCD.root'   weight=302672   histoName='MT/results' sumHistoName='sumweights/genWeights'
    #EventWeightsIterativeGenPU outputFile='emQCD.root'   weight=259296   histoName='MT/results' sumHistoName='sumweights/genWeights' #162060000*0.0016 = 259296

    EventWeightsIterativeGenPU outputFile='ZJets.root'     weight=6025.2    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenPU outputFile='ZJets550.root'     weight=71310    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenPU outputFile='TTJets.root'  weight=831.76     histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenPU outputFile='TT.root'  weight=831.76     histoName='MT/results' sumHistoName='sumweights/genWeights'

    EventWeightsIterativeGenPU outputFile='WJets.root'   weight=61526.7   histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenPU outputFile='WJetsMLM.root'   weight=61526.7   histoName='MT/results' sumHistoName='sumweights/genWeights'

    EventWeightsIterativeGenPU outputFile='VV.root'      weight=11.95   histoName='MT/results' sumHistoName='sumweights/genWeights'

    EventWeightsIterativeGenPU outputFile='WZ.root'      weight=5.26  histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenPU outputFile='WZTo1L1Nu2Q.root'      weight=10.71   histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenPU outputFile='WZTo2L2Q.root'      weight=5.26   histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenPU outputFile='WZTo1L3Nu.root'      weight=3.05   histoName='MT/results' sumHistoName='sumweights/genWeights'

    EventWeightsIterativeGenPU outputFile='ZZTo2L2Q.root'      weight=3.22  histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenPU outputFile='ZZTo4Q.root'      weight=1.256  histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenPU outputFile='ZZTo4L.root'      weight=1.212  histoName='MT/results' sumHistoName='sumweights/genWeights'

    EventWeightsIterativeGenPU outputFile='WWTo2L2Nu.root'     weight=12.178    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenPU outputFile='WWTo4Q.root'     weight=45.2    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenPU outputFile='WWToLNu2Q.root'     weight=49.997    histoName='MT/results' sumHistoName='sumweights/genWeights'

    EventWeightsIterativeGenPU outputFile='t_tW.root'       weight=35.6    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenPU outputFile='tBar_tW.root'    weight=35.6    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenPU outputFile='St_antitop.root'       weight=26.23    histoName='MT/results' sumHistoName='sumweights/genWeights' #80.59 pb * 3*.108
    EventWeightsIterativeGenPU outputFile='St_top.root'       weight=44.07    histoName='MT/results' sumHistoName='sumweights/genWeights' #136 * 3*.108

    hadd -f DiBoson.root VV.root WZ*root ZZ*root WW*root St_*top.root t*_tW.root
    hadd -f ZJetsMerge.root ZJets.root ZJets550.root
fi



if [ $weightBCtoE -eq 1 ]
    then
    EventWeightsIterativeGenPU outputFile='QCDBCtoE_30.root'  weight=40718.4     histoName='MT/results' sumHistoName='sumweights/genWeights' #159068000*.00255
    EventWeightsIterativeGenPU outputFile='QCDBCtoE_80.root'  weight=38104.4     histoName='MT/results' sumHistoName='sumweights/genWeights' #3221000*.01183
    EventWeightsIterativeGenPU outputFile='QCDBCtoE_170.root'  weight=2635.8     histoName='MT/results' sumHistoName='sumweights/genWeights' #105771*.02492
    EventWeightsIterativeGenPU outputFile='QCDBCtoE_250.root'  weight=711.9     histoName='MT/results' sumHistoName='sumweights/genWeights' #21094*.03375
    hadd BCtoE.root QCDBCtoE_*root
fi


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



