#!/bin/sh


#binning='binningHighStat=0.,5.,10.,15.,20.,25.,30.,35.,40.,45.,50.,55.,60.,65.,70.,75.,80.,85.,90.,95.,100.,105.,110.,115.,120.,125.,130.,135.,140.,145.,150.,155.,160.,165.,170.,175.,180.,185.,190.,195.,200.,210.,220.,230.,240.,250.,260.,270.,280.,290.,300.,310.,320.,330.,340.,350. binningLowStat=0.,20.,40.,60.,80.,100.,120.,140.,160.,180.,200.,250.,300.,350.' 

#binning='binningHighStat=0.,10.,20.,30.,40.,50.,60.,70.,80.,90.,100.,110.,120.,130.,140.,150.,160.,170.,180.,190.,200.,225.,250.,275.,300.,325.,350. binningLowStat=0.,20.,40.,60.,80.,100.,120.,140.,160.,180.,200.,250.,300.,350.' 

binning='binningHighStat=0.,10.,20.,30.,40.,50.,60.,70.,80.,90.,100.,110.,120.,130.,140.,150.,160.,170.,180.,190.,200.,225.,250.,275.,300.,325.,350. binningLowStat=0.,15.,30.,45.,60.,75.,90.,105.,120.,135.,150.,175.,200.,250.,300.,350.' 

MakeDataCard   catSplit="pt2>40"   outputFile='htt_mt.inputs-sm-7TeV.root'  channel='muTau'   energy="7TeV"   shifts='Tau'  dataFile='../inputs/ltau42X/DATA.root'  zEmbeddedSample='../inputs/ltau42X/MTEM.root'  zttFile='../inputs/ltau42X/ZJETS.root' zllFile='../inputs/ltau42X/ZJETS.root' wFile='../inputs/ltau42X/WJETS.root' vvFile='../inputs/ltau42X/VV.root' topFile='../inputs/ltau42X/TOP.root'  wThreeJetsFile='../inputs/ltau42X/WJETS.root' preselection='pt1>17&&pt2>20&&vertices>0&&diLeptons==0&&lPFIsoDB<0.1&&tauLooseIso>0&&tightElectrons==0&&tightMuons<=1'       wSelection='mt1>70'	       signalSelection='mt1<20'        qcdselection='pt1>17&&pt2>20&&tauLooseIso>0&&vertices>0&&diLeptons==0&&charge!=0&&mt1<20&&lPFIsoDB>0.2&&lTrigger>0&&tauTrigger>0'  luminosityErr=0.045 qcdfactor=1.06 qcdfactorErr=0.02 vvErr=0.3  zttScale=0.95 zttScaleErr=0.033   topSF=0.95  wFactorErr=0.06    zjfterr=0.1  zlftfactor=2.4  zlfterr=0.1   topErr=0.075 	muID=1.0 muIDErr=0.01 eleID=0.0 eleIDErr=0.0 tauID=1.0  tauIDHigh=1.0 tauIDErr=0.07 dir='../inputs/ltau42X/'  bID=1.0  bIDErr=0.10  bMisID=1.00  bMisIDErr=0.17    bitmask=0,0,1,0  vbfSelection0='(nJetsPt30<1&&btag==0)' vbfSelection1='(nJetsPt30>=1&&btag==0)' vbfSelection2='(nJetsPt30>=2&&vbfMass>500&&vbfDEta>3.5&&vbfNJetsGap30==0)'    vbfRelaxedSelection='(vbfMass>200&&vbfDEta>2)'  relaxedSelection='pt1>17&&pt2>20&&mt1<20&&lTrigger>0&&tauTrigger>0'   weight='__WEIGHT__*__CORR__' luminosity=4900.   variable='svMass'  $binning


