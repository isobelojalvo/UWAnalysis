#!/bin/sh

mkdir sandbox
cd sandbox

mergeFiles --copy-timeout=90 sm90.root /hdfs/store/user/swanson/SMGGH90-SUB-MCH
mergeFiles --copy-timeout=90 sm95.root /hdfs/store/user/swanson/SMGGH95-SUB-MCH
mergeFiles --copy-timeout=90 sm100.root /hdfs/store/user/swanson/SMGGH100-SUB-MCH
mergeFiles --copy-timeout=90 sm105.root /hdfs/store/user/swanson/SMGGH105-SUB-MCH
mergeFiles --copy-timeout=90 sm110.root /hdfs/store/user/swanson/SMGGH110-SUB-MCH
mergeFiles --copy-timeout=90 sm115.root /hdfs/store/user/swanson/SMGGH115-SUB-MCH
mergeFiles --copy-timeout=90 sm120.root /hdfs/store/user/swanson/SMGGH120-SUB-MCH
mergeFiles --copy-timeout=90 sm125.root /hdfs/store/user/swanson/SMGGH125-SUB-MCH
mergeFiles --copy-timeout=90 sm130.root /hdfs/store/user/swanson/SMGGH130-SUB-MCH
mergeFiles --copy-timeout=90 sm135.root /hdfs/store/user/swanson/SMGGH135-SUB-MCH
mergeFiles --copy-timeout=90 sm140.root /hdfs/store/user/swanson/SMGGH140-SUB-MCH
mergeFiles --copy-timeout=90 sm145.root /hdfs/store/user/swanson/SMGGH145-SUB-MCH
mergeFiles --copy-timeout=90 sm150.root /hdfs/store/user/swanson/SMGGH150-SUB-MCH
mergeFiles --copy-timeout=90 sm155.root /hdfs/store/user/swanson/SMGGH155-SUB-MCH
mergeFiles --copy-timeout=90 sm160.root /hdfs/store/user/swanson/SMGGH160-SUB-MCH

mergeFiles --copy-timeout=90 vbf90.root /hdfs/store/user/swanson/VBF90-SUB-MCH
mergeFiles --copy-timeout=90 vbf95.root /hdfs/store/user/swanson/VBF95-SUB-MCH
mergeFiles --copy-timeout=90 vbf100.root /hdfs/store/user/swanson/VBF100-SUB-MCH
mergeFiles --copy-timeout=90 vbf105.root /hdfs/store/user/swanson/VBF105-SUB-MCH
mergeFiles --copy-timeout=90 vbf110.root /hdfs/store/user/swanson/VBF110-SUB-MCH
mergeFiles --copy-timeout=90 vbf115.root /hdfs/store/user/swanson/VBF115-SUB-MCH
mergeFiles --copy-timeout=90 vbf120.root /hdfs/store/user/swanson/VBF120-SUB-MCH
mergeFiles --copy-timeout=90 vbf125.root /hdfs/store/user/swanson/VBF125-SUB-MCH
mergeFiles --copy-timeout=90 vbf130.root /hdfs/store/user/swanson/VBF130-SUB-MCH
mergeFiles --copy-timeout=90 vbf135.root /hdfs/store/user/swanson/VBF135-SUB-MCH
mergeFiles --copy-timeout=90 vbf140.root /hdfs/store/user/swanson/VBF140-SUB-MCH
mergeFiles --copy-timeout=90 vbf145.root /hdfs/store/user/swanson/VBF145-SUB-MCH
mergeFiles --copy-timeout=90 vbf150.root /hdfs/store/user/swanson/VBF150-SUB-MCH
mergeFiles --copy-timeout=90 vbf155.root /hdfs/store/user/swanson/VBF155-SUB-MCH
mergeFiles --copy-timeout=90 vbf160.root /hdfs/store/user/swanson/VBF160-SUB-MCH

mergeFiles --copy-timeout=90 vh90.root /hdfs/store/user/swanson/VH90-SUB-MCH
mergeFiles --copy-timeout=90 vh95.root /hdfs/store/user/swanson/VH95-SUB-MCH
mergeFiles --copy-timeout=90 vh100.root /hdfs/store/user/swanson/VH100-SUB-MCH
mergeFiles --copy-timeout=90 vh105.root /hdfs/store/user/swanson/VH105-SUB-MCH
mergeFiles --copy-timeout=90 vh110.root /hdfs/store/user/swanson/VH110-SUB-MCH
mergeFiles --copy-timeout=90 vh115.root /hdfs/store/user/swanson/VH115-SUB-MCH
mergeFiles --copy-timeout=90 vh120.root /hdfs/store/user/swanson/VH120-SUB-MCH
mergeFiles --copy-timeout=90 vh125.root /hdfs/store/user/swanson/VH125-SUB-MCH
mergeFiles --copy-timeout=90 vh130.root /hdfs/store/user/swanson/VH130-SUB-MCH
mergeFiles --copy-timeout=90 vh135.root /hdfs/store/user/swanson/VH135-SUB-MCH
mergeFiles --copy-timeout=90 vh140.root /hdfs/store/user/swanson/VH140-SUB-MCH
mergeFiles --copy-timeout=90 vh145.root /hdfs/store/user/swanson/VH145-SUB-MCH
mergeFiles --copy-timeout=90 vh150.root /hdfs/store/user/swanson/VH150-SUB-MCH
mergeFiles --copy-timeout=90 vh155.root /hdfs/store/user/swanson/VH155-SUB-MCH
mergeFiles --copy-timeout=90 vh160.root /hdfs/store/user/swanson/VH160-SUB-MCH

EventWeightsIterative outputFile='sm90.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='sm95.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='sm100.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='sm105.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='sm110.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='sm115.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='sm120.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='sm125.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='sm130.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='sm135.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='sm140.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='sm145.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='sm150.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='sm155.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='sm160.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 


EventWeightsIterative outputFile='vbf90.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='vbf95.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='vbf100.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='vbf105.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='vbf110.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='vbf115.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='vbf120.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='vbf125.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='vbf130.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='vbf135.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='vbf140.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='vbf145.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='vbf150.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='vbf155.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='vbf160.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 


EventWeightsIterative outputFile='vh90.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='vh95.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='vh100.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='vh105.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='vh110.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='vh115.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='vh120.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='vh125.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='vh130.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='vh135.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='vh140.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='vh145.root'    doOneD=1     weight=1    type=7 histoName='MT/results'
EventWeightsIterative outputFile='vh150.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='vh155.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 
EventWeightsIterative outputFile='vh160.root'    doOneD=1     weight=1    type=7 histoName='MT/results' 

 









