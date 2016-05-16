#!/bin/sh

#nohup bash ./merge.sh >merge.log & 
#to see if finished running check 'top' and tail below
#tail -f merge.log

#MAKE SURE /scratch/$USER is empty!!!
mkdir /nfs_scratch/$USER/htt_unweighted18
cd /nfs_scratch/$USER/htt_unweighted18


mergedata=1;
mergemc=1;
mergeZ=1;
mergeW=1;
mergehiggs=1;


if [ $mergedata -eq 1 ]
    then
    nohup /cms/sw/farmout/mergeFiles 		--reuse-cache-files muDATA.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/SINGLEMUON2015D_Apr25-SUB-JSON &
    nohup /cms/sw/farmout/mergeFiles 		--reuse-cache-files eleDATA.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/SINGLEELE2015D_Apr25-SUB-JSON &
fi


if [ $mergehiggs -eq 1 ]
    then
    /cms/sw/farmout/mergeFiles --reuse-cache-files ggH120.root /hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_ggHtautau_120-SUB-MC 
    /cms/sw/farmout/mergeFiles --reuse-cache-files ggH125.root /hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_ggHtautau_125-SUB-MC 
    /cms/sw/farmout/mergeFiles --reuse-cache-files ggH130.root /hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_ggHtautau_130-SUB-MC 
    /cms/sw/farmout/mergeFiles --reuse-cache-files vbfH120.root /hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_vbfHtautau_120-SUB-MC 
    /cms/sw/farmout/mergeFiles --reuse-cache-files vbfH125.root /hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_vbfHtautau_125-SUB-MC 
    /cms/sw/farmout/mergeFiles --reuse-cache-files vbfH130.root /hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_vbfHtautau_130-SUB-MC 
fi 

if [ $mergeZ -eq 1 ]
    then
    nohup /cms/sw/farmout/mergeFiles 		--reuse-cache-files ZJets_150.root	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr30_ZJets_150-SUB-MC & 
    nohup /cms/sw/farmout/mergeFiles 		--reuse-cache-files ZJets_ext1.root	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr30_ZJets_ext1-SUB-MC & 
    nohup /cms/sw/farmout/mergeFiles --reuse-cache-files Z1Jets.root /hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr30_Z1Jets-SUB-MC & 
    nohup /cms/sw/farmout/mergeFiles --reuse-cache-files Z2Jets.root /hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr30_Z2Jets-SUB-MC &
    nohup /cms/sw/farmout/mergeFiles --reuse-cache-files Z3Jets.root /hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr30_Z3Jets-SUB-MC &
    nohup /cms/sw/farmout/mergeFiles --reuse-cache-files Z4Jets.root /hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr30_Z4Jets-SUB-MC &
fi 

if [ $mergeW -eq 1 ]
    then
    nohup /cms/sw/farmout/mergeFiles 	--reuse-cache-files WJetsMLM.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_WJets_MLM-SUB-MC &
    nohup /cms/sw/farmout/mergeFiles --reuse-cache-files W1Jets.root /hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_W1Jets-SUB-MC & 
    nohup /cms/sw/farmout/mergeFiles --reuse-cache-files W2Jets.root /hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_W2Jets-SUB-MC &
    nohup /cms/sw/farmout/mergeFiles --reuse-cache-files W3Jets.root /hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_W3Jets-SUB-MC &
    nohup /cms/sw/farmout/mergeFiles --reuse-cache-files W4Jets.root /hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_W4Jets-SUB-MC &
fi 




if [ $mergemc -eq 1 ]
    then

    nohup /cms/sw/farmout/mergeFiles 	--reuse-cache-files TT_ext4.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_TT_ext4-SUB-MC & 

    nohup /cms/sw/farmout/mergeFiles 		--reuse-cache-files WWToLNuQQ.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_WWToLNu2Q-SUB-MC & 

    nohup /cms/sw/farmout/mergeFiles 		--reuse-cache-files VVTo2L2Nu.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_VVTo2L2Nu-SUB-MC & 

    nohup /cms/sw/farmout/mergeFiles 		--reuse-cache-files ZZTo4L.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_ZZTo4L-SUB-MC & 
    nohup /cms/sw/farmout/mergeFiles 		--reuse-cache-files ZZTo2L2Q.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_ZZTo2L2Q-SUB-MC & 

    nohup /cms/sw/farmout/mergeFiles 	--reuse-cache-files WZTo1L1Nu2Q.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_WZTo1L1Nu2Q-SUB-MC &
    nohup /cms/sw/farmout/mergeFiles 	--reuse-cache-files WZTo1L3Nu.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_WZTo1L3Nu-SUB-MC &
    nohup /cms/sw/farmout/mergeFiles 	--reuse-cache-files WZTo2L2Q.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_WZTo2L2Q-SUB-MC &
    nohup /cms/sw/farmout/mergeFiles 	--reuse-cache-files WZJTo1L3Nu.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_WZJTo1L3Nu-SUB-MC &

    nohup /cms/sw/farmout/mergeFiles 	--reuse-cache-files t_tW.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_t_tW-SUB-MC &
    nohup /cms/sw/farmout/mergeFiles 	--reuse-cache-files tBar_tW.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_tBar_tW-SUB-MC &
    nohup /cms/sw/farmout/mergeFiles 	--reuse-cache-files St_top.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_St_t_top-SUB-MC &
    nohup /cms/sw/farmout/mergeFiles 	--reuse-cache-files St_antitop.root 	/hdfs/store/user/$USER/SVfitSubmit_Apr28/25ns_Apr25_St_t_antitop-SUB-MC &
fi

