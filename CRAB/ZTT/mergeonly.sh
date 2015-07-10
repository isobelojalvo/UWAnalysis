#!/bin/sh

#nohup bash ./merge.sh >merge.log & 
#to see if finished running check 'top' and tail below
#tail -f merge.log

#MAKE SURE /scratch/$USER/ is empty!!!
mkdir /nfs_scratch/$USER/ztt_unweighted
cd /nfs_scratch/$USER/ztt_unweighted


merge=1;


if [ $merge -eq 1 ]
    then
    #uncomment below for Higgs samples
    #/cms/sw/farmout/mergeFiles --reuse-cache-files ggH.root /hdfs/store/user/$USER/ggHtautau-SUB-MCH &
    #/cms/sw/farmout/mergeFiles --reuse-cache-files vbfH.root /hdfs/store/user/$USER/vbfHtautau-SUB-MCH &
    #uncomment below for QCD
    #/cms/sw/farmout/mergeFiles --reuse-cache-files muQCD.root /hdfs/store/user/$USER/muQCD-SUB-MC &
    #/cms/sw/farmout/mergeFiles --reuse-cache-files em1520QCD.root /hdfs/store/user/$USER/1520QCD-SUB-MC &
    #/cms/sw/farmout/mergeFiles --reuse-cache-files em2030QCD.root /hdfs/store/user/$USER/2030QCD-SUB-MC &
    #/cms/sw/farmout/mergeFiles --reuse-cache-files em3050QCD.root /hdfs/store/user/$USER/3050QCD-SUB-MC &
    #/cms/sw/farmout/mergeFiles --reuse-cache-files em5080QCD.root /hdfs/store/user/$USER/5080QCD-SUB-MC &
    #/cms/sw/farmout/mergeFiles --reuse-cache-files em80120QCD.root /hdfs/store/user/$USER/80120QCD-SUB-MC &
    #/cms/sw/farmout/mergeFiles --reuse-cache-files em120170QCD.root /hdfs/store/user/$USER/120170QCD-SUB-MC &
    #/cms/sw/farmout/mergeFiles --reuse-cache-files em170300QCD.root /hdfs/store/user/$USER/170300QCD-SUB-MC &
    #/cms/sw/farmout/mergeFiles --reuse-cache-files em300infQCD.root /hdfs/store/user/$USER/em300infQCD-SUB-MC &
    #uncomment below for SM Backgorund sample
    /cms/sw/farmout/mergeFiles 		--reuse-cache-files ZJets.root	/hdfs/store/user/$USER/50ns_ZJets-SUB-MC 
    /cms/sw/farmout/mergeFiles 		--reuse-cache-files WW.root 	/hdfs/store/user/$USER/50ns_WW-SUB-MC 
    /cms/sw/farmout/mergeFiles 		--reuse-cache-files ZZ.root 	/hdfs/store/user/$USER/50ns_ZZ-SUB-MC 
    nohup /cms/sw/farmout/mergeFiles 	--reuse-cache-files TTJets.root /hdfs/store/user/$USER/50ns_TTJets-SUB-MC &
    #uncomment this line if TT_tune4C was run for more statistics. TTJets should be fine for now
    #nohup /cms/sw/farmout/mergeFiles 	--reuse-cache-files TT.root 	/hdfs/store/user/$USER/50ns_TT_Tune4C-SUB-MC & 
    nohup /cms/sw/farmout/mergeFiles 	--reuse-cache-files WJets.root 	/hdfs/store/user/$USER/50ns_WJets-SUB-MC &
    nohup /cms/sw/farmout/mergeFiles 	--reuse-cache-files WZ.root 	/hdfs/store/user/$USER/50ns_WZJets-SUB-MC &
    nohup /cms/sw/farmout/mergeFiles 	--reuse-cache-files t.root 	/hdfs/store/user/$USER/50ns_t_tW-SUB-MC &
    nohup /cms/sw/farmout/mergeFiles 	--reuse-cache-files tBar.root 	/hdfs/store/user/$USER/50ns_tBar_tW-SUB-MC &
fi

