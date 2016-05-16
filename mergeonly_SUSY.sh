#!/bin/sh

# bash ./merge.sh >merge.log  
#to see if finished running check 'top' and tail below
#tail -f merge.log

#MAKE SURE /scratch/$USER/SVfitSubmit_Apr28/ is empty!!!
mkdir /nfs_scratch/$USER/htt_unweighted18_susy
cd /nfs_scratch/$USER/htt_unweighted18_susy


mergeGGA=1;
mergeBBA=1;

if [ $mergeGGA -eq 1 ]
    then
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susyggH_80.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susyggHtautau_80-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susyggH_90.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susyggHtautau_90-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susyggH_100.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susyggHtautau_100-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susyggH_110.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susyggHtautau_110-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susyggH_120.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susyggHtautau_120-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susyggH_140.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susyggHtautau_140-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susyggH_160.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susyggHtautau_160-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susyggH_180.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susyggHtautau_180-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susyggH_200.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susyggHtautau_200-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susyggH_250.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susyggHtautau_250-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susyggH_400.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susyggHtautau_400-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susyggH_450.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susyggHtautau_450-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susyggH_500.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susyggHtautau_500-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susyggH_600.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susyggHtautau_600-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susyggH_700.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susyggHtautau_700-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susyggH_800.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susyggHtautau_800-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susyggH_900.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susyggHtautau_900-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susyggH_1000.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susyggHtautau_1000-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susyggH_1200.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susyggHtautau_1200-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susyggH_1400.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susyggHtautau_1400-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susyggH_1600.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susyggHtautau_1600-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susyggH_1800.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susyggHtautau_1800-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susyggH_2000.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susyggHtautau_2000-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susyggH_2300.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susyggHtautau_2300-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susyggH_2600.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susyggHtautau_2600-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susyggH_2900.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susyggHtautau_2900-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susyggH_3200.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susyggHtautau_3200-SUB-MC/ 
fi



if [ $mergeBBA -eq 1 ]
    then
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susybbH_80.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susybbHtautau_80-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susybbH_90.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susybbHtautau_90-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susybbH_100.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susybbHtautau_100-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susybbH_110.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susybbHtautau_110-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susybbH_120.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susybbHtautau_120-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susybbH_140.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susybbHtautau_140-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susybbH_160.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susybbHtautau_160-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susybbH_180.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susybbHtautau_180-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susybbH_200.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susybbHtautau_200-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susybbH_250.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susybbHtautau_250-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susybbH_300.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susybbHtautau_300-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susybbH_350.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susybbHtautau_350-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susybbH_400.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susybbHtautau_400-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susybbH_450.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susybbHtautau_450-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susybbH_500.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susybbHtautau_500-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susybbH_600.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susybbHtautau_600-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susybbH_700.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susybbHtautau_700-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susybbH_800.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susybbHtautau_800-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susybbH_900.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susybbHtautau_900-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susybbH_1000.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susybbHtautau_1000-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susybbH_1200.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susybbHtautau_1200-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susybbH_1600.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susybbHtautau_1600-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susybbH_1800.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susybbHtautau_1800-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susybbH_2000.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susybbHtautau_2000-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susybbH_2300.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susybbHtautau_2300-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susybbH_2600.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susybbHtautau_2600-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susybbH_2900.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susybbHtautau_2900-SUB-MC/ 
     /cms/sw/farmout/mergeFiles 		--reuse-cache-files susybbH_3200.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_susybbHtautau_3200-SUB-MC/ 
fi



