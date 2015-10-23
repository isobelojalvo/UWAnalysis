#!/bin/sh
mkdir /nfs_scratch/$USER/ztt_weighted11
cp /nfs_scratch/$USER/ztt_unweighted11/* /nfs_scratch/$USER/ztt_weighted11/.
cd /nfs_scratch/$USER/ztt_weighted11/


weight=0;
weightH=0;
weightW=0;
weightEMStitchQCD=0;
weightBCtoE=0;



if [ $weightBCtoE -eq 1 ]
    then
    EventWeightsIterativeGen outputFile='QCDBCtoE_30.root'  weight=40718.4     histoName='MT/results' sumHistoName='sumweights/genWeights' #159068000*.00255
    EventWeightsIterativeGen outputFile='QCDBCtoE_80.root'  weight=38104.4     histoName='MT/results' sumHistoName='sumweights/genWeights' #3221000*.01183
    EventWeightsIterativeGen outputFile='QCDBCtoE_170.root'  weight=2635.8     histoName='MT/results' sumHistoName='sumweights/genWeights' #105771*.02492
    EventWeightsIterativeGen outputFile='QCDBCtoE_250.root'  weight=711.9     histoName='MT/results' sumHistoName='sumweights/genWeights' #21094*.03375
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

if [ $weightH -eq 1 ]
    then
    EventWeightsIterativeGen outputFile='ggH.root'     weight=2.7757    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='vbfH.root'     weight=0.2368    histoName='MT/results' sumHistoName='sumweights/genWeights'
fi

if [ $weightW -eq 1 ]
    then
    EventWeightsIterativeGen outputFile='WJetsHT100.root'     weight=1347    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='WJetsHT200.root'     weight=360    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='WJetsHT400.root'     weight=48.98    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='WJetsHT600.root'     weight=18.77    histoName='MT/results' sumHistoName='sumweights/genWeights'
    hadd WJetsHTStitched.root WJetsHT*
fi


if [ $weight -eq 1 ]
    then
    #This Includes the filter efficiency-> 0.00042*720648000
    #EventWeightsIterativeGen outputFile='muQCD.root'   weight=302672   histoName='MT/results' sumHistoName='sumweights/genWeights'
    #EventWeightsIterativeGen outputFile='emQCD.root'   weight=259296   histoName='MT/results' sumHistoName='sumweights/genWeights' #162060000*0.0016 = 259296
    EventWeightsIterativeGen outputFile='ZJets.root'     weight=6025    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='ZJets1050.root'     weight=18610    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='TTJets.root'  weight=832     histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='TT.root'  weight=832     histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='WJets.root'   weight=61526.7   histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='WJetsMLM.root'   weight=61526.7   histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='WZ.root'      weight=22.82   histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='ZZTo2L2Q.root'      weight=10.96  histoName='MT/results' sumHistoName='sumweights/genWeights'
    #This did not get created last time. Find out why.
    #EventWeightsIterativeGen outputFile='ZZTo2Q2Nu.root'      weight=10.96  histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='ZZTo4Q.root'      weight=1.256  histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='WWTo2L2Nu.root'     weight=10.481    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='WWTo4Q.root'     weight=45.2    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='WWToLNuQQ.root'     weight=43.53    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='t.root'       weight=35.6    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='tBar.root'    weight=35.6    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='t_s.root'       weight=103.02    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='t_s_Ext.root'       weight=80.95    histoName='MT/results' sumHistoName='sumweights/genWeights'
    hadd -f VV.root WZ.root WWTo*.root ZZTo*.root t.root tBar.root t_s*.root 
    hadd -f ZJetsMerge.root ZJets.root ZJets1050.root
fi


