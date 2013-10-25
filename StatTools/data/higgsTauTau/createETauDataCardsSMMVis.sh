#!/bin/sh


binning='binningHighStat=0.,10.,20.,30.,40.,50.,60.,70.,80.,90.,100.,110.,120.,130.,140.,150.,160.,170.,180.,190.,200.,225.,250.,275.,300.,325.,350. binningLowStat=0.,20.,40.,60.,80.,100.,120.,140.,160.,180.,200.,250.,300.,350.' 



MakeDataCard   channel='eleTau'  shifts='Tau'  dataFile='../inputs/ltau/DATA.root'   zEmbeddedSample='../inputs/ltau/ETEM.root'   zttFile='../inputs/ltau/ZJETS.root' zllFile='../inputs/ltau/ZJETS.root' wFile='../inputs/ltau/WJETS.root' vvFile='../inputs/ltau/VV.root' topFile='../inputs/ltau/TOP.root'  wThreeJetsFile='../inputs/ltau/WJETS.root' preselection='pt1>24&&pt2>20&&vertices>0&&diLeptons==0&&lPFIsoDB<0.1&tauLooseMVAIso>0&&tauElectronTightMVAPass>0&&tightElectrons<=1&&tightMuons==0'       wSelection='mt1>70'	       signalSelection='mt1<20'         qcdselection='pt1>24&&pt2>20&&vertices>0&&tauLooseMVAIso>0&&diLeptons==0&&charge!=0&&mt1<20&&lPFIsoDB>0.2&&lTrigger>0&&tauTrigger>0'  luminosityErr=0.045 qcdfactor=1.06 qcdfactorErr=0.02 vvErr=0.3  zttScale=1.0 zttScaleErr=0.033    wFactorErr=0.06    zjfterr=0.1  zlfterr=0.1   topErr=0.075 	muID=0.0 muIDErr=0.0 eleID=1.0 eleIDErr=0.01 tauID=1.0 tauIDErr=0.07 outputFile='htt_et.inputs-sm-8TeV-mvis.root' dir='../inputs/ltau/'  bID=1.0  bIDErr=0.10  bMisID=1.0  bMisIDErr=0.17    bitmask=0,0,1,0  vbfSelection0='(nJetsPt30<1&&btag==0)' vbfSelection1='(met>30&&nJetsPt30>=1&&btag==0&&(!(nJetsPt30>=2&&vbfMass>500&&vbfDEta>3.5&&vbfNJetsGap30==0)))' vbfSelection2='(nJetsPt30>=2&&vbfMass>500&&vbfDEta>3.5&&vbfNJetsGap30==0)'  vbfRelaxedSelection='(vbfNJetsGap30==0&&vbfMass>200&&vbfDEta>2)'   relaxedSelection='pt1>24&&pt2>20&&mt1<20&&lTrigger>0&&tauTrigger>0'   weight='__CORR__*__WEIGHT__' luminosity=19300.   variable='mass'  $binning

#blinding='(!(mass>60&&mass<120))'