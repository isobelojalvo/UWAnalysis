Higgs Combine is lagging in 715. Using 715 to plot

```
cmsrel CMSSW_7_1_5
cd CMSSW_7_1_5/src/
cmsenv
git cms-init
git clone --recursive -b stattools https://github.com/lmdodd/UWAnalysis.git
git clone https://github.com/cms-analysis/HiggsAnalysis-CombinedLimit.git HiggsAnalysis/CombinedLimit
export USER_CXXFLAGS="-Wno-delete-non-virtual-dtor -Wno-error=unused-but-set-variable -Wno-error=unused-variable -Wno-error=sign-compare -Wno-error=reorder -Wno-error=maybe-uninitialized"
scram b
```

To plot 

```
cd UWAnalysis/StatTools/data/hTauTau_2015/
./makeMuTauPlots
./makeETauPlots
root -l -b -q makeTemplatePlotsMuTau.C
root -l -b -q makeTemplatePlotsETau.C
```

To plot using HTTTwiki categories
```
cd UWAnalysis/StatTools/data/hTauTau_2015/
./makeMuTauPlots_Twiki
./makeETauPlots_Twiki
root -l -b -q makeTemplatePlotsMuTau.C
root -l -b -q makeTemplatePlotsETau.C
```
editing makeTemplatePlotsMuTau.C as necessary for wanted branch.
