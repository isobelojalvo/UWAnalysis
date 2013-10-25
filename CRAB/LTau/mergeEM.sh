#!/bin/sh

mkdir sandbox
cd sandbox

mergeFiles --copy-timeout=90 ETEM_2012A.root /hdfs/store/user/swanson/2012A-SUB-ET-EM
mergeFiles --copy-timeout=90 ETEM_2012B.root /hdfs/store/user/swanson/2012B-SUB-ET-EM
mergeFiles --copy-timeout=90 ETEM_2012C.root /hdfs/store/user/swanson/2012C-SUB-ET-EM
mergeFiles --copy-timeout=90 ETEM_2012D.root /hdfs/store/user/swanson/2012D-SUB-ET-EM
mergeFiles --copy-timeout=90 MTEM_2012A.root /hdfs/store/user/swanson/2012A-SUB-MT-EM
mergeFiles --copy-timeout=90 MTEM_2012B.root /hdfs/store/user/swanson/2012B-SUB-MT-EM
mergeFiles --copy-timeout=90 MTEM_2012C.root /hdfs/store/user/swanson/2012C-SUB-MT-EM
mergeFiles --copy-timeout=90 MTEM_2012D.root /hdfs/store/user/swanson/2012D-SUB-MT-EM





 









