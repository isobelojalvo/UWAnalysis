UWAnalysis
==========

H->tautau (+ many other) Final States! : )


Set Up instructions:

cmsrel CMSSW_7_2_3_patch1
cd CMSSW_7_2_3_patch1/src/
cmsenv
git cms-init 
git clone --recursive -b sl6_dev https://github.com/lmdodd/UWAnalysis.git   
#p.s. we should bring this into uwcms soon
cd UWAnalysis
source recipeSL6.sh

#AnalysisDataFormats/EWK and /TOP do not build in CMSSW_7_3_3 (These are old files)
#(EWK and TOP fail with this error message ~laura/tmpAnalysisDataFormats
# in recipe
#cp -r /cms/laura/UWAnalysis13/CMSSW_7_2_3_patch1/src/AnalysisDataFormats/ 

cd UWAnalysis
#stat tools should live in CMSSW_7_1_5 now, because higgs combine stuck in 7_1_5
rm -rf StatTools
