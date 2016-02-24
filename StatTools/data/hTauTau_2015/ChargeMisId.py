import ROOT
import os


wselection='mt_1>80'
sigSel='mt_1<40'
qcdselection='pt_1>23&&pt_2>20&&vertices>0&&diLeptons==0&&iso_1<0.5&tauIso<5&&tightElectrons<=1&&tightMuons==0&&tauIsoMedium>0.5'
#trigselection='pt_1>23' #only for MC
#trigselectiondata='pt_1>23' #only for Data
trigselection='lTrigger_25ns_sync' #only for MC now
trigselectiondata='lTrigger_25ns_23' #Data For Now
#relaxedSelection='pt1>23&&pt2>20&&vertices>0'
luminosity='2110' #pb
direc='/nfs_scratch/laura/ztt_weighted13/'
datadirec='/nfs_scratch/laura/ztt_unweighted14_Golden/'
zttScale='1.'
qcdfactor='0.0'
topSF='1.'
samesign='0'
#
os.system('mkdir eleTauNM1PlotsOSDM')
os.system('rm eleTauNM1PlotsOSDM/*')
zeroselections='pt_1>23&&pt_2>20&&vertices>0&&diLeptons==0&&tightElectrons<=1&&tightMuons==0&&againstMuonLoose3_2>0&&tauDecayMode!=5&&tauDecayMode!=6&&tauIsoMedium>0.5'
#zeroselections='pt_1>23&&pt_2>20&&vertices>0&&diLeptons==0&&iso_1<0.5&tauIso<5&&tightElectrons<=1&&tightMuons==0&&tauIsoMedium>0.5&&againstMuonLoose3_2>0'
selections=['tauElectronTightMVA5>0','pt_1>23','tauIso<1.5','iso_1<.1']
label=['NOtauElectronTight','ALL','NOtauIso','NOiso1']
variables=['m_vis','mt_1','LLmass']
bins=['bins=40 min=0 max=200','bins=40 min=0 max=200','bins=40 min=0 max=200']

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
        name=variable
        if variable=='mt_1':
           sigSel='mt_1>0'
        else:
           sigSel='mt_1<40' 
        command='MakeDataCardZTT_EventTree samesign='+samesign+' channel="eleTau" dataFile="'+direc+'eleDATA.root" qcdFile="'+direc+'emQCD.root" zttFile="'+direc+'ZJetsMerge.root"  zllFile="'+direc+'ZJetsMerge.root" wFile="'+direc+'WJetsMLM.root" vvFile="'+direc+'VV.root" topFile="'+direc+'TTJets.root" inclselection="'+selection+'" preselection="'+selection+'"  wselection="'+wselection+'" trigselection="'+trigselection+'" trigselection50ns="'+trigselectiondata+'"  signalselection="'+sigSel+'"   qcdselection="'+selection+'" luminosityErr=0.045 qcdfactor='+qcdfactor+' qcdfactorErr=0.02 vvErr=0.3   zttScale='+zttScale+' zttScaleErr=0.033    wFactorErr=0.06    zjfterr=0.1  zlfterr=0.24   topErr=0.075  topSF='+topSF+'        muID=1.00 muIDErr=0.01 eleID=0.0 eleIDErr=0.0 tauID=1.0 tauIDErr=0.06  dir='+direc+'  bID=1.0  bIDErr=0.10  bMisID=1.0  bMisIDErr=0.17    bitmask=1,0,0,0 weight="__WEIGHT__*GENWEIGHT"  luminosity='+luminosity+'  variable="'+variable+'" '+binz+' outputFile="eleTauNM1PlotsOSDM/eleTau_'+label[i]+'_'+name+'.root"  '    
        #print command
        os.system(command)

