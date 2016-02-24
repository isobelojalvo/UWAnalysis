import ROOT
import os


preselection='pt_1>23&&pt_2>20&&vertices>0&&diLeptons==0&&iso_1<0.5&tauIso<5&&tightElectrons<=1&&tightMuons==0'
inclselection='pt_1>23&&pt_2>20&&vertices>0&&diLeptons==0&&iso_1<0.5&&tauIso<5&&tightElectrons<=1&&tightMuons==0'
wselection='mt_1>80'
sigSel='mt_1<40'
#qcdselection='pt_1>23&&pt_2>20&&vertices>0&&diLeptons==0&&iso_1<0.9&&tauIso<10'
qcdselection='pt_1>18&&pt_2>20&&vertices>0&&diLeptons==0&&iso_1<.1&&tauIso<5&&tightElectrons<=1&&tightMuons==0&&againstMuonLoose3_2&&tauElectronTightMVA5'
#trigselection='pt_1>23' #only for MC
#trigselectiondata='pt_1>23' #only for Data
trigselection='(crossTrigger>0||(lTrigger>0&&pt_1>33))' #only for MC
trigselectiondata='(crossTrigger_25ns>0||(lTrigger_25ns>0&&pt_1>33))' #only for Data
#relaxedSelection='pt1>23&&pt2>20&&vertices>0'
luminosity='1280' #pb
direc='/nfs_scratch/laura/ztt_weighted11/'
zttScale='1.'
qcdfactor='0.0'
topSF='1.'
samesign='1'
#
os.system('mkdir eleTauNM1PlotsSSDM')
os.system('rm eleTauNM1PlotsSSDM/*')
zeroselections='pt_1>23&&pt_2>20&&vertices>0&&diLeptons==0&&tightElectrons<=1&&tightMuons==0'
selections=['pt_1>23','tauIso<1.5','iso_1<.1','iso04_1<0.1','againstMuonLoose3_2>0','tauElectronTightMVA5>0','tauDecayMode!=5&&tauDecayMode!=6']
label=['ALL','NOtauIso','NOiso1','NOiso04','NOagainstMuonLoose3','NOtauElectronTight','NOdecayM56']
variables=['mt_1','iso_1','iso04_1','tauIso','tauElectronTightMVA5','againstMuonLoose3_2','m_vis','tauDecayMode','(neutralIsoPtSum_2+chargedIsoPtSum_2)/pt_2','chargedIsoPtSum_2','neutralIsoPtSum_2','againstElectronMediumMVA5_2','tauIsoTight','tauIsoLoose']
bins=['bins=40 min=0 max=200','bins=50 min=0 max=.5','bins=50 min=0 max=.5','bins=100 min=0 max=10','bins=2 min=-0.5 max=1.5','bins=2 min=-0.5 max=1.5','bins=40 min=0 max=200','bins=12 min=0 max=12','bins=60 min=0 max=1.5','bins=40 min=0 max=2','bins=60 min=0 max=6','bins=2 min=-0.5 max=1.5','bins=2 min=-0.5 max=1.5','bins=2 min=-0.5 max=1.5']

l=len(selections)
for i in range(0,l):
    selection=zeroselections
    for j in range(0,l):
        if i!=j:
           selection=selection+'&&'+selections[j]   
    print selection
    for v in range(0,len(variables)):
        variable=variables[v]
        binz=bins[v]
        if variable=='(neutralIsoPtSum_2+chargedIsoPtSum_2)/pt_2':
           name='relIso'
        else:
           name=variable
        if variable=='mt_1':
           sigSel='mt_1>0'
        else:
           sigSel='mt_1<40' 
        command='MakeDataCardZTT_EventTree samesign='+samesign+' channel="eleTau" dataFile="'+direc+'eleDATA.root" qcdFile="'+direc+'emQCD.root" zttFile="'+direc+'ZJetsMerge.root"  zllFile="'+direc+'ZJetsMerge.root" wFile="'+direc+'WJets.root" vvFile="'+direc+'VV.root" topFile="'+direc+'TTJets.root" inclselection="'+selection+'" preselection="'+selection+'"  wselection="'+wselection+'" trigselection="'+trigselection+'" trigselection50ns="'+trigselectiondata+'"  signalselection="'+sigSel+'"   qcdselection="'+selection+'" luminosityErr=0.045 qcdfactor='+qcdfactor+' qcdfactorErr=0.02 vvErr=0.3   zttScale='+zttScale+' zttScaleErr=0.033    wFactorErr=0.06    zjfterr=0.1  zlfterr=0.24   topErr=0.075  topSF='+topSF+'        muID=1.00 muIDErr=0.01 eleID=0.0 eleIDErr=0.0 tauID=1.0 tauIDErr=0.06  dir='+direc+'  bID=1.0  bIDErr=0.10  bMisID=1.0  bMisIDErr=0.17    bitmask=1,0,0,0 weight="__WEIGHT__*GENWEIGHT"  luminosity='+luminosity+'  variable="'+variable+'" '+binz+' outputFile="eleTauNM1PlotsSSDM/eleTau_'+label[i]+'_'+name+'.root"  '    
        #print command
        os.system(command)

