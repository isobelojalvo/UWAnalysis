#!/bin/sh

mkdir $1

###### Data

hadd $1/DATA.root /hdfs/store/user/swanson/Data2012*-mergeFilesJob/*.root

###### Embedded

hadd $1/ETEM.root /hdfs/store/user/swanson/ETEM2012*-mergeFilesJob/*.root
hadd $1/MTEM.root /hdfs/store/user/swanson/MTEM2012*-mergeFilesJob/*.root

###### Background

hadd $1/Z.root /hdfs/store/user/swanson/Z-mergeFilesJob/*.root
hadd $1/Z1JETS.root /hdfs/store/user/swanson/Z1Jets-mergeFilesJob/*.root
hadd $1/Z2JETS.root /hdfs/store/user/swanson/Z2Jets-mergeFilesJob/*.root
hadd $1/Z3JETS.root /hdfs/store/user/swanson/Z3Jets-mergeFilesJob/*.root
hadd $1/Z4JETS.root /hdfs/store/user/swanson/Z4Jets-mergeFilesJob/*.root
hadd $1/W.root /hdfs/store/user/swanson/W_*-mergeFilesJob/*.root
hadd $1/W1JETS.root /hdfs/store/user/swanson/W1Jets_*-mergeFilesJob/*.root
hadd $1/W2JETS.root /hdfs/store/user/swanson/W2Jets_*-mergeFilesJob/*.root
hadd $1/W3JETS.root /hdfs/store/user/swanson/W3Jets_*-mergeFilesJob/*.root
hadd $1/W4JETS.root /hdfs/store/user/swanson/W4Jets-mergeFilesJob/*.root
hadd $1/TT_LL.root /hdfs/store/user/swanson/TT_LL-mergeFilesJob/*.root
hadd $1/TT_HH.root /hdfs/store/user/swanson/TT_HH-mergeFilesJob/*.root
hadd $1/TT_HL.root /hdfs/store/user/swanson/TT_HL-mergeFilesJob/*.root
hadd $1/WZ-3L.root /hdfs/store/user/swanson/WZ3L-mergeFilesJob/*.root
hadd $1/WW-2L.root /hdfs/store/user/swanson/WW2L-mergeFilesJob/*.root
hadd $1/ZZ-4L.root /hdfs/store/user/swanson/ZZ4L-mergeFilesJob/*.root
hadd $1/WZ-LLQQ.root /hdfs/store/user/swanson/WZ2L2Q-mergeFilesJob/*.root
hadd $1/ZZ-LLQQ.root /hdfs/store/user/swanson/ZZ2L2Q-mergeFilesJob/*.root
hadd $1/tW.root /hdfs/store/user/swanson/tW-mergeFilesJob/*.root
hadd $1/tBarW.root /hdfs/store/user/swanson/tBarW-mergeFilesJob/*.root

###### SM Signal

hadd $1/sm90.root /hdfs/store/user/swanson/sm90-mergeFilesJob/*.root
hadd $1/sm95.root /hdfs/store/user/swanson/sm95-mergeFilesJob/*.root
hadd $1/sm100.root /hdfs/store/user/swanson/sm100-mergeFilesJob/*.root
hadd $1/sm105.root /hdfs/store/user/swanson/sm105-mergeFilesJob/*.root
hadd $1/sm110.root /hdfs/store/user/swanson/sm110-mergeFilesJob/*.root
hadd $1/sm115.root /hdfs/store/user/swanson/sm115-mergeFilesJob/*.root
hadd $1/sm120.root /hdfs/store/user/swanson/sm120-mergeFilesJob/*.root
hadd $1/sm125.root /hdfs/store/user/swanson/sm125-mergeFilesJob/*.root
hadd $1/sm130.root /hdfs/store/user/swanson/sm130-mergeFilesJob/*.root
hadd $1/sm135.root /hdfs/store/user/swanson/sm135-mergeFilesJob/*.root
hadd $1/sm140.root /hdfs/store/user/swanson/sm140-mergeFilesJob/*.root
hadd $1/sm145.root /hdfs/store/user/swanson/sm145-mergeFilesJob/*.root
hadd $1/sm150.root /hdfs/store/user/swanson/sm150-mergeFilesJob/*.root
hadd $1/sm155.root /hdfs/store/user/swanson/sm155-mergeFilesJob/*.root
hadd $1/sm160.root /hdfs/store/user/swanson/sm160-mergeFilesJob/*.root

hadd $1/vbf90.root /hdfs/store/user/swanson/vbf90-mergeFilesJob/*.root
hadd $1/vbf95.root /hdfs/store/user/swanson/vbf95-mergeFilesJob/*.root
hadd $1/vbf100.root /hdfs/store/user/swanson/vbf100-mergeFilesJob/*.root
hadd $1/vbf105.root /hdfs/store/user/swanson/vbf105-mergeFilesJob/*.root
hadd $1/vbf110.root /hdfs/store/user/swanson/vbf110-mergeFilesJob/*.root
hadd $1/vbf115.root /hdfs/store/user/swanson/vbf115-mergeFilesJob/*.root
hadd $1/vbf120.root /hdfs/store/user/swanson/vbf120-mergeFilesJob/*.root
hadd $1/vbf125.root /hdfs/store/user/swanson/vbf125-mergeFilesJob/*.root
hadd $1/vbf130.root /hdfs/store/user/swanson/vbf130-mergeFilesJob/*.root
hadd $1/vbf135.root /hdfs/store/user/swanson/vbf135-mergeFilesJob/*.root
hadd $1/vbf140.root /hdfs/store/user/swanson/vbf140-mergeFilesJob/*.root
hadd $1/vbf145.root /hdfs/store/user/swanson/vbf145-mergeFilesJob/*.root
hadd $1/vbf150.root /hdfs/store/user/swanson/vbf150-mergeFilesJob/*.root
hadd $1/vbf155.root /hdfs/store/user/swanson/vbf155-mergeFilesJob/*.root
hadd $1/vbf160.root /hdfs/store/user/swanson/vbf160-mergeFilesJob/*.root

hadd $1/vh90.root /hdfs/store/user/swanson/vh90-mergeFilesJob/*.root
hadd $1/vh95.root /hdfs/store/user/swanson/vh95-mergeFilesJob/*.root
hadd $1/vh100.root /hdfs/store/user/swanson/vh100-mergeFilesJob/*.root
hadd $1/vh105.root /hdfs/store/user/swanson/vh105-mergeFilesJob/*.root
hadd $1/vh110.root /hdfs/store/user/swanson/vh110-mergeFilesJob/*.root
hadd $1/vh115.root /hdfs/store/user/swanson/vh115-mergeFilesJob/*.root
hadd $1/vh120.root /hdfs/store/user/swanson/vh120-mergeFilesJob/*.root
hadd $1/vh125.root /hdfs/store/user/swanson/vh125-mergeFilesJob/*.root
hadd $1/vh130.root /hdfs/store/user/swanson/vh130-mergeFilesJob/*.root
hadd $1/vh135.root /hdfs/store/user/swanson/vh135-mergeFilesJob/*.root
hadd $1/vh140.root /hdfs/store/user/swanson/vh140-mergeFilesJob/*.root
hadd $1/vh145.root /hdfs/store/user/swanson/vh145-mergeFilesJob/*.root
hadd $1/vh150.root /hdfs/store/user/swanson/vh150-mergeFilesJob/*.root
hadd $1/vh155.root /hdfs/store/user/swanson/vh155-mergeFilesJob/*.root
hadd $1/vh160.root /hdfs/store/user/swanson/vh160-mergeFilesJob/*.root

##### MSSM Signal

#hadd $1/bbA80.root /hdfs/store/user/swanson/bbA80-mergeFilesJob/*.root
hadd $1/bbA90.root /hdfs/store/user/swanson/bbA90-mergeFilesJob/*.root
hadd $1/bbA100.root /hdfs/store/user/swanson/bbA100-mergeFilesJob/*.root
hadd $1/bbA120.root /hdfs/store/user/swanson/bbA120-mergeFilesJob/*.root
hadd $1/bbA130.root /hdfs/store/user/swanson/bbA130-mergeFilesJob/*.root
hadd $1/bbA140.root /hdfs/store/user/swanson/bbA140-mergeFilesJob/*.root
hadd $1/bbA160.root /hdfs/store/user/swanson/bbA160-mergeFilesJob/*.root
hadd $1/bbA180.root /hdfs/store/user/swanson/bbA180-mergeFilesJob/*.root
hadd $1/bbA200.root /hdfs/store/user/swanson/bbA200-mergeFilesJob/*.root
hadd $1/bbA250.root /hdfs/store/user/swanson/bbA250-mergeFilesJob/*.root
hadd $1/bbA300.root /hdfs/store/user/swanson/bbA300-mergeFilesJob/*.root
hadd $1/bbA350.root /hdfs/store/user/swanson/bbA350-mergeFilesJob/*.root
hadd $1/bbA400.root /hdfs/store/user/swanson/bbA400-mergeFilesJob/*.root
hadd $1/bbA450.root /hdfs/store/user/swanson/bbA450-mergeFilesJob/*.root
hadd $1/bbA500.root /hdfs/store/user/swanson/bbA500-mergeFilesJob/*.root
hadd $1/bbA600.root /hdfs/store/user/swanson/bbA600-mergeFilesJob/*.root
hadd $1/bbA700.root /hdfs/store/user/swanson/bbA700-mergeFilesJob/*.root
hadd $1/bbA800.root /hdfs/store/user/swanson/bbA800-mergeFilesJob/*.root
hadd $1/bbA900.root /hdfs/store/user/swanson/bbA900-mergeFilesJob/*.root
hadd $1/bbA1000.root /hdfs/store/user/swanson/bbA1000-mergeFilesJob/*.root

#hadd $1/ggH80.root /hdfs/store/user/swanson/ggH80-mergeFilesJob/*.root
hadd $1/ggH90.root /hdfs/store/user/swanson/ggH90-mergeFilesJob/*.root
hadd $1/ggH100.root /hdfs/store/user/swanson/ggH100-mergeFilesJob/*.root
hadd $1/ggH120.root /hdfs/store/user/swanson/ggH120-mergeFilesJob/*.root
hadd $1/ggH130.root /hdfs/store/user/swanson/ggH130-mergeFilesJob/*.root
hadd $1/ggH140.root /hdfs/store/user/swanson/ggH140-mergeFilesJob/*.root
hadd $1/ggH160.root /hdfs/store/user/swanson/ggH160-mergeFilesJob/*.root
hadd $1/ggH180.root /hdfs/store/user/swanson/ggH180-mergeFilesJob/*.root
hadd $1/ggH200.root /hdfs/store/user/swanson/ggH200-mergeFilesJob/*.root
hadd $1/ggH250.root /hdfs/store/user/swanson/ggH250-mergeFilesJob/*.root
hadd $1/ggH300.root /hdfs/store/user/swanson/ggH300-mergeFilesJob/*.root
hadd $1/ggH350.root /hdfs/store/user/swanson/ggH350-mergeFilesJob/*.root
hadd $1/ggH400.root /hdfs/store/user/swanson/ggH400-mergeFilesJob/*.root
hadd $1/ggH450.root /hdfs/store/user/swanson/ggH450-mergeFilesJob/*.root
hadd $1/ggH500.root /hdfs/store/user/swanson/ggH500-mergeFilesJob/*.root
hadd $1/ggH600.root /hdfs/store/user/swanson/ggH600-mergeFilesJob/*.root
hadd $1/ggH700.root /hdfs/store/user/swanson/ggH700-mergeFilesJob/*.root
hadd $1/ggH800.root /hdfs/store/user/swanson/ggH800-mergeFilesJob/*.root
hadd $1/ggH900.root /hdfs/store/user/swanson/ggH900-mergeFilesJob/*.root
hadd $1/ggH1000.root /hdfs/store/user/swanson/ggH1000-mergeFilesJob/*.root
