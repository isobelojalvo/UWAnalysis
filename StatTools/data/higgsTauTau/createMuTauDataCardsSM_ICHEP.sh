#!/bin/sh


binning='binningHighStat=0.,10.,20.,30.,40.,50.,60.,70.,80.,90.,100.,110.,120.,130.,140.,150.,160.,170.,180.,190.,200.,225.,250.,275.,300.,325.,350. binningLowStat=0.,20.,40.,60.,80.,100.,120.,140.,160.,180.,200.,250.,300.,350.' 



MakeDataCard      channel='muTau'    shifts='Tau'  dataFile='../inputs/ltau_ichep/DATA.root'  zEmbeddedSample='../inputs/ltau_ichep/MTEM.root'  zttFile='../inputs/ltau_ichep/ZJETS.root' zllFile='../inputs/ltau_ichep/ZJETS.root' wFile='../inputs/ltau_ichep/WJETS.root' vvFile='../inputs/ltau_ichep/VV.root' topFile='../inputs/ltau_ichep/TOP.root'  wThreeJetsFile='../inputs/ltau_ichep/WJETS.root' preselection='pt1>20&&pt2>20&&vertices>0&&diLeptons==0&&lPFIsoDB<0.1&&tauLooseMVAIso>0&&tightElectrons==0&&tightMuons<=1'       wSelection='mt1>70'	       signalSelection='mt1<20'        qcdselection='pt1>20&&pt2>20&&tauLooseMVAIso>0&&vertices>0&&diLeptons==0&&charge!=0&&mt1<20&&lPFIsoDB>0.2&&lTrigger>0&&tauTrigger>0'  luminosityErr=0.045 qcdfactor=1.06 qcdfactorErr=0.02 vvErr=0.3  zttScale=1.011 zttScaleErr=0.033    wFactorErr=0.06    zjfterr=0.1  zlfterr=0.1   topErr=0.075 	muID=1.0 muIDErr=0.01 eleID=0.0 eleIDErr=0.0 tauID=1.0 tauIDErr=0.07 outputFile='htt_mt.inputs-sm-8TeV_ICHEP.root' dir='../inputs/ltau_ichep/'  bID=1.0  bIDErr=0.10  bMisID=1.00  bMisIDErr=0.17    bitmask=0,0,1,0  vbfSelection0='(nJetsPt30<1&&btag==0)' vbfSelection1='(nJetsPt30>=1&&btag==0&&(!(nJetsPt30>=2&&vbfMass>500&&vbfDEta>3.5&&vbfNJetsGap30==0)))' vbfSelection2='(nJetsPt30>=2&&vbfMass>500&&vbfDEta>3.5&&vbfNJetsGap30==0)'  vbfRelaxedSelection='(vbfNJetsGap30==0&&vbfMass>200&&vbfDEta>2)'  relaxedSelection='pt1>20&&pt2>20&&mt1<20&&lTrigger>0&&tauTrigger>0'   weight='__WEIGHT__*__CORR__' luminosity=5200.   variable='svMass'  $binning


#blinding='(!(svMass>100&&svMass<160))'
