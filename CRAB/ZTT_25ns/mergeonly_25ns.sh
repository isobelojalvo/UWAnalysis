#!/bin/sh

#nohup bash ./merge.sh >merge.log & 
#to see if finished running check 'top' and tail below
#tail -f merge.log

#MAKE SURE /scratch/$USER/ is empty!!!
mkdir /nfs_scratch/$USER/ztt_unweighted10
cd /nfs_scratch/$USER/ztt_unweighted10
cd /nfs_scratch/$USER/ztt_unweighted10


mergedata=0;
mergemc=0;
mergeqcd=0;
mergeW=0;
mergehiggs=0;


if [ $mergedata -eq 1 ]
    then
    /cms/sw/farmout/mergeFiles 		--reuse-cache-files muDATA.root 	/hdfs/store/user/$USER/SINGLEMUON2015D-SUB-JSON
    /cms/sw/farmout/mergeFiles 		--reuse-cache-files eleDATA.root 	/hdfs/store/user/$USER/SINGLEELE2015D-SUB-JSON 
fi

if [ $mergeqcd -eq 1 ]
    then
    /cms/sw/farmout/mergeFiles 		--reuse-cache-files muQCD.root /hdfs/store/user/$USER/25ns_muQCD-SUB-MC 
    /cms/sw/farmout/mergeFiles 		--reuse-cache-files emQCD.root /hdfs/store/user/$USER/25ns_emQCD-SUB-MC 
fi 

if [ $mergehiggs -eq 1 ]
    then
    /cms/sw/farmout/mergeFiles --reuse-cache-files ggH.root /hdfs/store/user/$USER/25ns_ggHtautau-SUB-MC 
    /cms/sw/farmout/mergeFiles --reuse-cache-files vbfH.root /hdfs/store/user/$USER/25ns_vbfHtautau-SUB-MC 
fi 

if [ $mergeW -eq 1 ]
    then
    /cms/sw/farmout/mergeFiles --reuse-cache-files WJetsHT100.root /hdfs/store/user/$USER/25ns_WJetsHT100-SUB-MC 
    /cms/sw/farmout/mergeFiles --reuse-cache-files WJetsHT200.root /hdfs/store/user/$USER/25ns_WJetsHT200-SUB-MC 
    /cms/sw/farmout/mergeFiles --reuse-cache-files WJetsHT400.root /hdfs/store/user/$USER/25ns_WJetsHT400-SUB-MC 
    /cms/sw/farmout/mergeFiles --reuse-cache-files WJetsHT600.root /hdfs/store/user/$USER/25ns_WJetsHT600-SUB-MC 
fi 



if [ $mergemc -eq 1 ]
    then
    #uncomment below for SM Backgorund sample
    /cms/sw/farmout/mergeFiles 		--reuse-cache-files ZJets.root	/hdfs/store/user/$USER/25ns_ZJets-SUB-MC 
    /cms/sw/farmout/mergeFiles 		--reuse-cache-files ZJets1050.root	/hdfs/store/user/$USER/25ns_ZJets1050-SUB-MC 
    /cms/sw/farmout/mergeFiles 		--reuse-cache-files WW.root 	/hdfs/store/user/$USER/25ns_WW-SUB-MC 
    /cms/sw/farmout/mergeFiles 		--reuse-cache-files ZZ.root 	/hdfs/store/user/$USER/25ns_ZZ-SUB-MC 
    nohup /cms/sw/farmout/mergeFiles 	--reuse-cache-files TTJets.root /hdfs/store/user/$USER/25ns_TTJets-SUB-MC &
    #uncomment this line if TT_tune4C was run for more statistics. TTJets should be fine for now?
    nohup /cms/sw/farmout/mergeFiles 	--reuse-cache-files TT.root 	/hdfs/store/user/$USER/25ns_TT-SUB-MC & 
    nohup /cms/sw/farmout/mergeFiles 	--reuse-cache-files WJets.root 	/hdfs/store/user/$USER/25ns_WJets-SUB-MC &
    nohup /cms/sw/farmout/mergeFiles 	--reuse-cache-files WZ.root 	/hdfs/store/user/$USER/25ns_WZJets-SUB-MC &
    nohup /cms/sw/farmout/mergeFiles 	--reuse-cache-files t.root 	/hdfs/store/user/$USER/25ns_t_tW-SUB-MC &
    nohup /cms/sw/farmout/mergeFiles 	--reuse-cache-files tBar.root 	/hdfs/store/user/$USER/25ns_tBar_tW-SUB-MC &
fi

