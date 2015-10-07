#!/bin/sh

#nohup bash ./merge.sh >merge.log & 
#to see if finished running check 'top' and tail below
#tail -f merge.log

#MAKE SURE /scratch/$USER/ is empty!!!
#mkdir /nfs_scratch/$USER/ztt_unweighted9
cd /nfs_scratch/$USER/ztt_unweighted9


mergedata=0;
mergemc=0;
mergeqcd=0;


if [ $mergedata -eq 1 ]
    then
    /cms/sw/farmout/mergeFiles 		--reuse-cache-files muDATA.root 	/hdfs/store/user/$USER/SINGLEMUON2015B-SUB-JSON
    /cms/sw/farmout/mergeFiles 		--reuse-cache-files eleDATA.root 	/hdfs/store/user/$USER/SINGLEELE2015B-SUB-JSON 
fi

if [ $mergeqcd -eq 1 ]
    then
    /cms/sw/farmout/mergeFiles --reuse-cache-files 50ns_QCDBCtoE_30.root /hdfs/store/user/$USER/50ns_QCDBCtoE_30-SUB-MC  
    /cms/sw/farmout/mergeFiles --reuse-cache-files 50ns_QCDBCtoE_80.root /hdfs/store/user/$USER/50ns_QCDBCtoE_80-SUB-MC  
    /cms/sw/farmout/mergeFiles --reuse-cache-files 50ns_QCDBCtoE_170.root /hdfs/store/user/$USER/50ns_QCDBCtoE_170-SUB-MC  
    /cms/sw/farmout/mergeFiles --reuse-cache-files 50ns_QCDBCtoE_250.root /hdfs/store/user/$USER/50ns_QCDBCtoE_250-SUB-MC  
fi 

if [ $mergemc -eq 1 ]
    then
    #uncomment below for Higgs samples
    /cms/sw/farmout/mergeFiles --reuse-cache-files ggH.root /hdfs/store/user/$USER/50ns_ggHtautau-SUB-MCH 
    /cms/sw/farmout/mergeFiles --reuse-cache-files vbfH.root /hdfs/store/user/$USER/50ns_vbfHtautau-SUB-MCH &
    #uncomment below for SM Backgorund sample
    /cms/sw/farmout/mergeFiles 		--reuse-cache-files muQCD.root /hdfs/store/user/$USER/50ns_muQCD-SUB-MC 
    /cms/sw/farmout/mergeFiles 		--reuse-cache-files emQCD.root /hdfs/store/user/$USER/50ns_emQCD-SUB-MC 
    /cms/sw/farmout/mergeFiles 		--reuse-cache-files ZJets.root	/hdfs/store/user/$USER/50ns_ZJets-SUB-MC 
    /cms/sw/farmout/mergeFiles 		--reuse-cache-files ZJets1050.root	/hdfs/store/user/$USER/50ns_ZJets1050-SUB-MC 
    /cms/sw/farmout/mergeFiles 		--reuse-cache-files WW.root 	/hdfs/store/user/$USER/50ns_WW-SUB-MC 
    /cms/sw/farmout/mergeFiles 		--reuse-cache-files ZZ.root 	/hdfs/store/user/$USER/50ns_ZZ-SUB-MC 
    nohup /cms/sw/farmout/mergeFiles 	--reuse-cache-files TTJets.root /hdfs/store/user/$USER/50ns_TTJets-SUB-MC &
    #uncomment this line if TT_tune4C was run for more statistics. TTJets should be fine for now?
    nohup /cms/sw/farmout/mergeFiles 	--reuse-cache-files TT.root 	/hdfs/store/user/$USER/50ns_TT-SUB-MC & 
    nohup /cms/sw/farmout/mergeFiles 	--reuse-cache-files WJets.root 	/hdfs/store/user/$USER/50ns_WJets-SUB-MC &
    nohup /cms/sw/farmout/mergeFiles 	--reuse-cache-files WZ.root 	/hdfs/store/user/$USER/50ns_WZJets-SUB-MC &
    nohup /cms/sw/farmout/mergeFiles 	--reuse-cache-files t.root 	/hdfs/store/user/$USER/50ns_t_tW-SUB-MC &
    nohup /cms/sw/farmout/mergeFiles 	--reuse-cache-files tBar.root 	/hdfs/store/user/$USER/50ns_tBar_tW-SUB-MC &
fi

