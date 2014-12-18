#!/bin/sh
#mkdir /nfs_scratch/laura/LTau_Oct27
cd /nfs_scratch/laura/LTau_Oct27/

#/cms/sw/farmout/mergeFiles  Data2012A.root /hdfs/store/user/laura/2012A-SUB_JSON 
#/cms/sw/farmout/mergeFiles  Data2012B.root /hdfs/store/user/laura/2012B-SUB_JSON 
#/cms/sw/farmout/mergeFiles  Data2012C.root /hdfs/store/user/laura/2012C-SUB_JSON 
#/cms/sw/farmout/mergeFiles  Data2012D.root /hdfs/store/user/laura/2012D-SUB_JSON 

hadd DATA.root Data2012A.root Data2012B.root Data2012C.root Data2012D.root
