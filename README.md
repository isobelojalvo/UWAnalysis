UWAnalysis
==========

H->tautau (+ many other) Final States! : )


#Set Up instructions:

```
cmsrel CMSSW_7_6_3 #for 2016 analysis
cd CMSSW_7_6_3/src/
cmsenv
git cms-init 
git clone --recursive -b 763X_dev https://github.com/lmdodd/UWAnalysis.git   
cd UWAnalysis
source recipe13TeV.sh
export USER_CXXFLAGS="-Wno-delete-non-virtual-dtor -Wno-error=unused-but-set-variable -Wno-error=unused-variable -Wno-error=sign-compare -Wno-error=reorder"
scram b -j 8
```
to run test

```
cd CRAB/ZTT_25/
cmsRun LT-MC.py
```

```
cd CRAB/ZTT_25ns/
source submitMCv2.sh
source submitDATA.sh
```

after jobs done

```
cd CRAB/ZTT_25ns
#to merge may need to use a non root6 area (?) like CMSSW_7_1_5 
nohup ./mergeonly_25ns.sh >merge.log & #turn on and off the samples you want to merge. scratch area should be clean
#wait until all files merges to weight
source weightonly.sh #in UWAnalysis directory
```

To plot please use https://github.com/lmdodd/UWAnalysis/tree/stattools and look at that readme




#Building comments

Critical: Go Through CheckMes and FixMes again. Check Good Vertices.

candidateAuxFunctions brought to MiniAod (Were in TauAnalysis, use again?)

Major Changes/Issues detailed in table

| Kind Of Issue  | Issue Detail |
| ------------- | ------------- |
| StatTools Not Included  | StatTools is left behind in 715X because HiggsCombine is stuck there. StatTools can be found https://github.com/lmdodd/UWAnalysis/tree/stattools.  |
| MVAMet qnd plain MET at same time | No solution yet. Needed for svFit. Include leptons and pairwise MVA MET |
| Efficiencies Application | Add Efficiencies into Ntuples, rather than computing afterwards !! TODO|
| Electron Efficiencies | Add Efficiencies into Ntuples, rather than computing afterwards !! TODO|
| Muon Efficiencies | Add Efficiencies into Ntuples, rather than computing afterwards !! TODO|
| Muon and Electron Scalings | Add Efficiencies into Ntuples, rather than computing afterwards !! TODO|
| ESscaling | Edited file to add pt2ES. |
| no particle embedding yet | TBC |
| TBC | TBC |

In general To see what needs to be fixed ``` grep -r FIXME *``` or ``` CHECKME```. 


