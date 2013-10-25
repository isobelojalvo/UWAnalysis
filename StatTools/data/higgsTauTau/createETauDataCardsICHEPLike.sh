#!/bin/sh


#binning='binningHighStat=0.,5.,10.,15.,20.,25.,30.,35.,40.,45.,50.,55.,60.,65.,70.,75.,80.,85.,90.,95.,100.,105.,110.,115.,120.,125.,130.,135.,140.,145.,150.,155.,160.,165.,170.,175.,180.,185.,190.,195.,200.,210.,220.,230.,240.,250.,260.,270.,280.,290.,300.,310.,320.,330.,340.,350. binningLowStat=0.,20.,40.,60.,80.,100.,120.,140.,160.,180.,200.,250.,300.,350.' 

binning='binningHighStat=0.,20.,40.,60.,80.,100.,120.,140.,160.,180.,200.,250.,300.,350. binningLowStat=0.,20.,40.,60.,80.,100.,120.,140.,160.,180.,200.,250.,300.,350.' 



MakeDataCard      channel='eleTau'  shifts='Tau'  dataFile='../inputs/ltauIchepLike/DATA.root'   zEmbeddedSample='../inputs/ltauIchepLike/ETEM.root'   zttFile='../inputs/ltauIchepLike/ZJETS.root' zllFile='../inputs/ltauIchepLike/ZJETS.root' wFile='../inputs/ltauIchepLike/WJETS.root' vvFile='../inputs/ltauIchepLike/VV.root' topFile='../inputs/ltauIchepLike/TOP.root'  wThreeJetsFile='../inputs/ltauIchepLike/WJETS.root' preselection='pt1>24&&pt2>20&&vertices>0&&diLeptons==0&&lPFIsoDB<0.1&&tauLooseMVAIso>0&&RUN<=196531'       wSelection='mt1>70'	       signalSelection='mt1<40'         qcdselection='pt1>24&&pt2>20&&vertices>0&&tauLooseMVAIso>0&&diLeptons==0&&charge!=0&&mt1<40&&lPFIsoDB>0.2&&lTrigger>0&&tauTrigger>0&&RUN<=196531'  luminosityErr=0.045 qcdfactor=1.06 qcdfactorErr=0.02 vvErr=0.3  zttScale=1.011 zttScaleErr=0.033    wFactorErr=0.06    zjfterr=0.1  zlfterr=0.1   topErr=0.075 	muID=0.0 muIDErr=0.0 eleID=1.0 eleIDErr=0.01 tauID=1.0 tauIDErr=0.07 outputFile='htt_et.inputs-sm-8TeV-ichep-on-hcp.root' dir='../inputs/ltauIchepLike/'  bID=1.0  bIDErr=0.10  bMisID=1.0  bMisIDErr=0.17    bitmask=0,0,1,0  vbfSelection0='(nJetsPt30<1&&btag==0&&met>30)' vbfSelection1='(nJetsPt30>=1&&btag==0&&met>30&&(!(nJetsPt30>=2&&vbfMVA>0.5&&vbfNJetsGap30==0)))' vbfSelection2='(nJetsPt30>=2&&vbfMVA>0.5&&vbfNJetsGap30==0)'  vbfRelaxedSelection='(vbfNJetsGap30==0&&vbfMVA>0)'  relaxedSelection='pt1>24&&pt2>20&&mt1<40&&lTrigger>0&&tauTrigger>0&&RUN<=196531'   weight='__CORR__*__WEIGHT__' luminosity=5200.   variable='svMass'  $binning

#blinding='(!(svMass>100&&svMass<160))'