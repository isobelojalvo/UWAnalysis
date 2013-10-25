#!/bin/sh
voms-proxy-init --voms cms --valid 100:00


### Background Samples

farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/DYJets-SUB-MCZ  Z $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/Z1Jets-SUB-MCZ  Z1Jets $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/Z2Jets-SUB-MCZ  Z2Jets $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/Z3Jets-SUB-MCZ  Z3Jets $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/Z4Jets-SUB-MCZ  Z4Jets $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/WJets_v1-SUB-MCW  W_1 $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/W1Jets_1-SUB-MCW  W1Jets_1 $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/W2Jets_1-SUB-MCW  W2Jets_1 $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/W3Jets_1-SUB-MCW  W3Jets_1 $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/W4Jets-SUB-MCW    W4Jets $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/WJets_v2-SUB-MCW  W_2 $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/W1Jets_2-SUB-MCW  W1Jets_2 $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/W2Jets_2-SUB-MCW  W2Jets_2 $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/W3Jets_2-SUB-MCW  W3Jets_2 $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/TTBar_LL-SUB-MC  TT_LL $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/TTBar_HH-SUB-MC  TT_HH $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/TTBar_HL-SUB-MC  TT_HL $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/WZ3L-SUB-MC  WZ3L $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/WW2L-SUB-MC  WW2L $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/ZZ4L-SUB-MC  ZZ4L $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/WZ2L2Q-SUB-MC  WZ2L2Q $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/ZZ2L2Q-SUB-MC  ZZ2L2Q $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/t_tW-SUB-MC  tW $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/tBar_tW-SUB-MC  tBarW $CMSSW_BASE


### Data Samples

farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/2012A-SUB_JSON  Data2012A  $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/2012B-SUB_JSON  Data2012B  $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/2012C-SUB_JSON  Data2012C  $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/2012D-SUB_JSON  Data2012D  $CMSSW_BASE


### Embedded Samples

farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/2012A-SUB-ET-EM  ETEM2012A  $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/2012B-SUB-ET-EM  ETEM2012B  $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/2012C-SUB-ET-EM  ETEM2012C  $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/2012D-SUB-ET-EM  ETEM2012D  $CMSSW_BASE

farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/2012A-SUB-MT-EM  MTEM2012A  $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/2012B-SUB-MT-EM  MTEM2012B  $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/2012C-SUB-MT-EM  MTEM2012C  $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/2012D-SUB-MT-EM  MTEM2012D  $CMSSW_BASE


### SM Signal Samples

farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/SMGGH90-SUB-MCH   sm90   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/SMGGH95-SUB-MCH   sm95   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/SMGGH100-SUB-MCH   sm100   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/SMGGH105-SUB-MCH   sm105   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/SMGGH110-SUB-MCH   sm110   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/SMGGH115-SUB-MCH   sm115   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/SMGGH120-SUB-MCH   sm120   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/SMGGH125-SUB-MCH   sm125   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/SMGGH130-SUB-MCH   sm130   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/SMGGH135-SUB-MCH   sm135   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/SMGGH140-SUB-MCH   sm140   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/SMGGH145-SUB-MCH   sm145   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/SMGGH150-SUB-MCH   sm150   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/SMGGH155-SUB-MCH   sm155   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/SMGGH160-SUB-MCH   sm160   $CMSSW_BASE

farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/VBF90-SUB-MCH   vbf90   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/VBF95-SUB-MCH   vbf95   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/VBF100-SUB-MCH   vbf100   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/VBF105-SUB-MCH   vbf105   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/VBF110-SUB-MCH   vbf110   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/VBF115-SUB-MCH   vbf115   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/VBF120-SUB-MCH   vbf120   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/VBF125-SUB-MCH   vbf125   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/VBF130-SUB-MCH   vbf130   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/VBF135-SUB-MCH   vbf135   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/VBF140-SUB-MCH   vbf140   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/VBF145-SUB-MCH   vbf145   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/VBF150-SUB-MCH   vbf150   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/VBF155-SUB-MCH   vbf155   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/VBF160-SUB-MCH   vbf160   $CMSSW_BASE

farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/VH90-SUB-MCH   vh90   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/VH95-SUB-MCH   vh95   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/VH100-SUB-MCH   vh100   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/VH105-SUB-MCH   vh105   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/VH110-SUB-MCH   vh110   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/VH115-SUB-MCH   vh115   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/VH120-SUB-MCH   vh120   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/VH125-SUB-MCH   vh125   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/VH130-SUB-MCH   vh130   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/VH135-SUB-MCH   vh135   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/VH140-SUB-MCH   vh140   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/VH145-SUB-MCH   vh145   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/VH150-SUB-MCH   vh150   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/VH155-SUB-MCH   vh155   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/VH160-SUB-MCH   vh160   $CMSSW_BASE


### MSSM Signal Samples

farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/bbA90-SUB-MCH   bbA90   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/bbA100-SUB-MCH   bbA100   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/bbA120-SUB-MCH   bbA120   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/bbA130-SUB-MCH   bbA130   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/bbA140-SUB-MCH   bbA140   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/bbA160-SUB-MCH   bbA160   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/bbA180-SUB-MCH   bbA180   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/bbA200-SUB-MCH   bbA200   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/bbA250-SUB-MCH   bbA250   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/bbA300-SUB-MCH   bbA300   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/bbA350-SUB-MCH   bbA350   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/bbA400-SUB-MCH   bbA400   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/bbA450-SUB-MCH   bbA450   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/bbA500-SUB-MCH   bbA500   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/bbA600-SUB-MCH   bbA600   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/bbA700-SUB-MCH   bbA700   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/bbA800-SUB-MCH   bbA800   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/bbA900-SUB-MCH   bbA900   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/bbA1000-SUB-MCH   bbA1000   $CMSSW_BASE

#farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/ggH80-SUB-MCH   ggH80   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/ggH90-SUB-MCH   ggH90   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/ggH100-SUB-MCH   ggH100   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/ggH120-SUB-MCH   ggH120   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/ggH130-SUB-MCH   ggH130   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/ggH140-SUB-MCH   ggH140   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/ggH160-SUB-MCH   ggH160   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/ggH180-SUB-MCH   ggH180   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/ggH200-SUB-MCH   ggH200   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/ggH250-SUB-MCH   ggH250   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/ggH300-SUB-MCH   ggH300   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/ggH350-SUB-MCH   ggH350   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/ggH400-SUB-MCH   ggH400   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/ggH450-SUB-MCH   ggH450   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/ggH500-SUB-MCH   ggH500   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/ggH600-SUB-MCH   ggH600   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/ggH700-SUB-MCH   ggH700   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/ggH800-SUB-MCH   ggH800   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/ggH900-SUB-MCH   ggH900   $CMSSW_BASE
farmoutAnalysisJobs --merge  $1   --input-files-per-job=500 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/swanson/ggH1000-SUB-MCH   ggH1000   $CMSSW_BASE
