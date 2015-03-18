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

Major Changes/Issues detailed in table

| Kind Of Issue  | Issue Detail |
| ------------- | ------------- |
| Removal of CVS Files  | Removal of CVS Files  |
| StatTools Not Included  | StatTools is left behind in 715X because HiggsCombine is stuck there. Will have to add back in StatTools as a later date.  |
| Had to change method names  | Unable to find effect of this change. In 'UWAnalysis/DataFormats/CompositePtrCandidateTMet.h' pt,px,py,mt become Pt,Px,Py,Mt. Required in order to build because functions in LeafCandidate had been declared GCC11_FINAL.   |
| Track Pt Error ntuple | FIX the track Pt Error-- unsure how to get trackref in miniaod. Cannot get the ptError() of the leadChargedHadrCand. Current;y this is 0 in the ntuple. The pt from the track is currently replaced by pt of the leadChargedHadrCand. (Do we need this ptError?) Nevertheless my strategy is wait longer for more code to get up on github. |
| MVAMet Overcorrects | No solution yet |
| PileupJetID | Trained on 53X, probably not optimal. May want to switch |
| CSV change | CHANGE in 72X : combinedSecondaryVertexBJetTags is no longer included. The new default is combinedInclusiveSecondaryVertexV2BJetTags. See https://hypernews.cern.ch/HyperNews/CMS/get/physTools/3265/1.html ... Will we need to rerun the CSV since the HTT twiki sticks with old? |
| Efficiencies Application | Add Efficiencies into Ntuples, rather than computing afterwards |
| SVFit | Using legacy SVFit, (NSVFit?) need to switch to standalone as requested by Twiki |
| Jet Id | Need a new loose pf id -- POG_PFID_LOOSE  as show here: https://github.com/CERN-PH-CMG/cmg-cmssw/blob/v7.0.1-from-CMSSW_7_2_3/PhysicsTools/Heppy/python/physicsobjects/Jet.py#L67|
| ESscaling | Edited file to add pt2ES. The naming convention of pt*2*ES confuses me. userFloat(ESpt was never getting filled. Now filled in TauESProducer. This shoupld be checked.  |
| relIso | use only PF-charged instead of all-charged... I will need to change to this. |
| TBC | TBC |

In general To see what needs to be fixed ``` grep -r FIXME *```

To see what variables are empty look in 'Configuration/python/tools/ntupleToolsMiniAOD.py.' FIXMEs denote empty/to be fixed. CHECKMEs denote checking. '#WTF' meant I didn't know what that variable did.
