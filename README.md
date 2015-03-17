UWAnalysis
==========

H->tautau (+ many other) Final States! : )


#Set Up instructions:

```
cmsrel CMSSW_7_2_3_patch1
cd CMSSW_7_2_3_patch1/src/
cmsenv
git cms-init 
git clone --recursive -b sl6_dev https://github.com/lmdodd/UWAnalysis.git   
cd UWAnalysis
source recipeSL6.sh
export USER_CXXFLAGS="-Wno-delete-non-virtual-dtor -Wno-error=unused-but-set-variable -Wno-error=unused-variable -Wno-error=sign-compare -Wno-error=reorder"
scram b -j 8
```
to run

```
cd CRAB/MiniAod
cmsRun LT-MC.py
```

#Building comments
| First Header  | Second Header |
| ------------- | ------------- |
| Content Cell  | Content Cell  |
| Content Cell  | Content Cell  |

stattools is left behind in 715X because HiggsCombine is stuck there. Will have to add back in StatTools as a later date.

'UWAnalysis/DataFormats/CompositePtrCandidateTMet.h' file had method names changed 

FIX the track Pt Error-- unsure who to get trackref in miniaod.

Currently unable to access any btagging

To see what needs to be fixed "grep -r FIXME" 

To see what variables are empty look in 'Configuration/python/tools/ntupleToolsMiniAOD.py.' FIXMEs denote empty/to be fixed. CHECKMEs denote checking. '#WTF' meant I didn't know what did.
