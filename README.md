UWAnalysis
==========

H->tautau (+ many other) Final States! : )


#Set Up instructions:

```
cmsrel CMSSW_7_4_14 #for 2015D 05Oct
cd CMSSW_7_4_14/src/
cmsenv
git cms-init 
git clone --recursive -b 7414 https://github.com/lmdodd/UWAnalysis.git   
cd UWAnalysis
source recipe13TeV.sh
export USER_CXXFLAGS="-Wno-delete-non-virtual-dtor -Wno-error=unused-but-set-variable -Wno-error=unused-variable -Wno-error=sign-compare -Wno-error=reorder"
scram b -j 8
```
to run test

```
cd CRAB/ZTT/
cmsRun LT-MC.py
```

or

```
cd CRAB/ZTT_25ns/
source submitMC.sh
source submitQCD.sh #submits QCD files
source submitDATA.sh
```

after jobs done

```
cd CRAB/ZTT_25ns
nohup ./mergeonly_25ns.sh >merge.log & #turn on and off the samples you want to merge. scratch area should be clean
#wait until all firles merges to weight
source weightonly.sh 
```

To plot please use https://github.com/lmdodd/UWAnalysis/tree/stattools and look at that readme




#Building comments

Critical: Go Through CheckMes and FixMes again. Check Good Vertices.

candidateAuxFunctions brought to MiniAod (Were in TauAnalysis, use again?)

Major Changes/Issues detailed in table

| Kind Of Issue  | Issue Detail |
| ------------- | ------------- |
| StatTools Not Included  | StatTools is left behind in 715X because HiggsCombine is stuck there. StatTools can be found https://github.com/lmdodd/UWAnalysis/tree/stattools.  |
| MVAMet Overcorrects | No solution yet. Needed for svFit. Include lepton. |
| Efficiencies Application | Add Efficiencies into Ntuples, rather than computing afterwards !! TODO|
| ESscaling | Edited file to add pt2ES. This energy scle confuses me. userFloat(ESpt) was never getting filled. Now filled in TauESProducer. This should be checked. Currently output zero? |
| relIso | use Dr=0.3 | 
| no particle embedding yet | TBC |
| TBC | TBC |

In general To see what needs to be fixed ``` grep -r FIXME *``` or ``` CHECKME```. 


