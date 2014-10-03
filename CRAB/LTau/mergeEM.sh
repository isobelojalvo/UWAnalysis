#!/bin/sh
mkdir /nfs_scratch/ojalvo/LTau_Aug15
cd /nfs_scratch/ojalvo/LTau_Aug15

/cms/sw/farmout/mergeFiles  MTEM_2012A.root /hdfs/store/user/$USER/2012A-SUB-MT-EM
/cms/sw/farmout/mergeFiles  MTEM_2012B.root /hdfs/store/user/$USER/2012B-SUB-MT-EM
/cms/sw/farmout/mergeFiles  MTEM_2012C.root /hdfs/store/user/$USER/2012C-SUB-MT-EM
/cms/sw/farmout/mergeFiles  MTEM_2012D.root /hdfs/store/user/$USER/2012D-SUB-MT-EM
hadd MTEM.root MTEM_2012A.root MTEM_2012B.root MTEM_2012C.root MTEM_2012D.root 

EventWeightsForEfficiencyFastEM $1 outputFile='MTEM.root'

/cms/sw/farmout/mergeFiles  ETEM_2012A.root /hdfs/store/user/$USER/2012A-SUB-ET-EM
/cms/sw/farmout/mergeFiles  ETEM_2012B.root /hdfs/store/user/$USER/2012B-SUB-ET-EM
/cms/sw/farmout/mergeFiles  ETEM_2012C.root /hdfs/store/user/$USER/2012C-SUB-ET-EM
/cms/sw/farmout/mergeFiles  ETEM_2012D.root /hdfs/store/user/$USER/2012D-SUB-ET-EM

hadd ETEM.root ETEM_2012A.root ETEM_2012B.root ETEM_2012C.root ETEM_2012D.root 

EventWeightsForEfficiencyFastEM $1 outputFile='ETEM.root'