pileupCalc.py -i json_all.txt --inputLumiJSON pileup_latest.txt  --calcMode true --minBiasXsec 69200 --maxPileupBin 90 --numPileupBins 90 DataPUHistoAll.root
pileupCalc.py -i json_BCD.txt --inputLumiJSON pileup_latest.txt  --calcMode true --minBiasXsec 69200 --maxPileupBin 90 --numPileupBins 90 DataPUHistoBCD.root
pileupCalc.py -i json_EF.txt  --inputLumiJSON pileup_latest.txt  --calcMode true --minBiasXsec 69200 --maxPileupBin 90 --numPileupBins 90 DataPUHistoEF.root
pileupCalc.py -i json_G.txt   --inputLumiJSON pileup_latest.txt  --calcMode true --minBiasXsec 69200 --maxPileupBin 90 --numPileupBins 90 DataPUHistoG.root
pileupCalc.py -i json_H.txt   --inputLumiJSON pileup_latest.txt  --calcMode true --minBiasXsec 69200 --maxPileupBin 90 --numPileupBins 90 DataPUHistoH.root
exit;

lumiCalc2.py lumibylsXing --xingMinLum 0.1 -b stable -i json_BCD.txt -o lumi_BCD.csv
estimatePileup_makeJSON.py --csvInput lumi_BCD.csv pileup_JSON_BCD.txt

#pileupCalc.py -i MyAnalysisJSON.txt --inputLumiJSON pileup_latest.txt  --calcMode true --minBiasXsec 69200 --maxPileupBin 50 --numPileupBins 50  MyDataPileupHistogram.root
