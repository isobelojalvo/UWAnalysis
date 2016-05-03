#!/bin/sh
#mkdir /nfs_scratch/$USER/htt_weighted18
cp /nfs_scratch/$USER/htt_unweighted18_susy/* /nfs_scratch/$USER/htt_weighted18/.
cd /nfs_scratch/$USER/htt_weighted18/


weightGGA=1;
weightBBA=1;



if [ $weightGGA -eq 1 ]
    then
    EventWeightsIterativeGenTauPt outputFile='susyggH_80.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susyggH_90.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susyggH_100.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susyggH_110.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susyggH_120.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susyggH_130.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susyggH_140.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susyggH_160.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susyggH_180.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susyggH_200.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susyggH_250.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susyggH_400.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susyggH_450.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susyggH_500.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susyggH_600.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susyggH_700.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susyggH_800.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susyggH_900.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susyggH_1000.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susyggH_1200.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susyggH_1400.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susyggH_1600.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susyggH_1800.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susyggH_2000.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susyggH_2300.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susyggH_2600.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susyggH_2900.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susyggH_3200.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
fi



if [ $weightBBA -eq 1 ]
    then
    EventWeightsIterativeGenTauPt outputFile='susybbH_80.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susybbH_90.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susybbH_100.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susybbH_110.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susybbH_120.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susybbH_130.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susybbH_140.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susybbH_160.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susybbH_180.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susybbH_200.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susybbH_250.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susybbH_300.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susybbH_350.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susybbH_400.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susybbH_450.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susybbH_500.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susybbH_600.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susybbH_700.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susybbH_800.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susybbH_900.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susybbH_1000.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susybbH_1200.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susybbH_1400.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susybbH_1600.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susybbH_1800.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susybbH_2000.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susybbH_2300.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susybbH_2600.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susybbH_2900.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGenTauPt outputFile='susybbH_3200.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
fi
