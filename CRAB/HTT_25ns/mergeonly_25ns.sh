B0;95;c#!/bin/sh

#nohup bash ./merge.sh >merge.log & 
#to see if finished running check 'top' and tail below
#tail -f merge.log

#MAKE SURE /scratch/$USER/ is empty!!!
mkdir /scratch/$USER/ztt_unweighted17
cd /scratch/$USER/ztt_unweighted17
jobID='2016_Sep23'

#exit;

mergedata=0;
mergemc=0;
mergeqcd=0;
mergeW=0;
mergeZ=0;
mergehiggs=1;

if [ $mergedata -eq 1 ]
    then
    hadd -f tauDATA-B.root 	/hdfs/store/user/$USER/${jobID}_TAU2016B_Jul21-SUB-TT-JSON/*
    hadd -f tauDATA-C.root 	/hdfs/store/user/$USER/${jobID}_TAU2016C_Jul21-SUB-TT-JSON/*
    hadd -f tauDATA-D.root 	/hdfs/store/user/$USER/${jobID}_TAU2016D_Jul21-SUB-TT-JSON/*
    hadd -f tauDATA-E.root 	/hdfs/store/user/$USER/${jobID}_TAU2016E_Jul21-SUB-TT-JSON/*
    hadd -f tauDATA-F.root 	/hdfs/store/user/$USER/${jobID}_TAU2016F_Jul21-SUB-TT-JSON/*
    
    hadd -f tauDATA.root tauDATA-B.root tauDATA-C.root tauDATA-D.root tauDATA-E.root tauDATA-F.root
fi

if [ $mergehiggs -eq 1 ]
    then #ggHtautau_125
    hadd -f  ggH125.root /hdfs/store/user/$USER/${jobID}_ggHtautau_125-SUB-TT/* 
    hadd -f  vbfH125.root /hdfs/store/user/$USER/${jobID}_vbfHtautau_125-SUB-TT/* 
#/hdfs/store/user/ojalvo/2016_Sep23_vbfHtautau_125-SUB-TT
fi 

if [ $mergeW -eq 1 ]
    then
    hadd -f  WJets.root /hdfs/store/user/$USER/${jobID}_WJets-SUB-TT/*  
    hadd -f  W1Jets.root /hdfs/store/user/$USER/${jobID}_W1Jets-SUB-TT/*  
    hadd -f  W2Jets.root /hdfs/store/user/$USER/${jobID}_W2Jets-SUB-TT/*  
    hadd -f  W3Jets.root /hdfs/store/user/$USER/${jobID}_W3Jets-SUB-TT/*  
    hadd -f  W4Jets.root /hdfs/store/user/$USER/${jobID}_W4Jets-SUB-TT/*  
    hadd -f   WJets.root /hdfs/store/user/$USER/${jobID}_WJets_amc-SUB-TT/*  
fi 

if [ $mergeZ -eq 1 ]
    then
    hadd -f  ZJets_ext1.root /hdfs/store/user/$USER/${jobID}_ZJets-SUB-TT/*  
    hadd -f  ZJets_150.root /hdfs/store/user/$USER/${jobID}_ZJets_150-SUB-TT/*  
    hadd -f  Z1Jets.root /hdfs/store/user/$USER/${jobID}_Z1Jets-SUB-TT/*  
    hadd -f  Z2Jets.root /hdfs/store/user/$USER/${jobID}_Z2Jets-SUB-TT/*  
    hadd -f  Z3Jets.root /hdfs/store/user/$USER/${jobID}_Z3Jets-SUB-TT/*  
    hadd -f  Z4Jets.root /hdfs/store/user/$USER/${jobID}_Z4Jets-SUB-TT/*  
fi 

if [ $mergemc -eq 1 ]
    then
    #uncomment below for SM Backgorund sample 2016_Sep23_TT-SUB-TT
    hadd -f   TT.root           /hdfs/store/user/$USER/${jobID}_TT-SUB-TT/*  
    hadd -f   WW.root           /hdfs/store/user/$USER/${jobID}_WW-SUB-TT/*  
    hadd -f   WWTo2L2Q.root     /hdfs/store/user/$USER/${jobID}_WWTo2L2Q-SUB-TT/*  
    hadd -f   WZ.root 	        /hdfs/store/user/$USER/${jobID}_WZ-SUB-TT/* 
    hadd -f   WZTo1L3Nu.root    /hdfs/store/user/$USER/${jobID}_WZTo1L3Nu-SUB-TT/*  
    #hadd -f   WZTo1L1Nu2Q.root  /hdfs/store/user/$USER/${jobID}_WZTo1L1Nu2Q-SUB-TT/*  
    hadd -f   ZZ.root           /hdfs/store/user/$USER/${jobID}_ZZ-SUB-TT/*  
    hadd -f   ZZTo2L2Q.root     /hdfs/store/user/$USER/${jobID}_ZZTo2L2Q-SUB-TT/*  
    hadd -f   ZZTo4L.root       /hdfs/store/user/$USER/${jobID}_ZZTo4L-SUB-TT/*  
    hadd -f   St_tBar.root 	/hdfs/store/user/$USER/${jobID}_St_t_antitop-SUB-TT/* 
    hadd -f   St_t.root 	/hdfs/store/user/$USER/${jobID}_St_t_top-SUB-TT/*  
    hadd -f   tBar_tW.root 	/hdfs/store/user/$USER/${jobID}_tBar_tW-SUB-TT/* 
    hadd -f   t_tW.root 	/hdfs/store/user/$USER/${jobID}_t_tW-SUB-TT/*  
    hadd -f   TT_DL.root 	/hdfs/store/user/$USER/${jobID}_TT_DL-SUB-TT/*  
    hadd -f   TT_SLT.root 	/hdfs/store/user/$USER/${jobID}_TT_SLT-SUB-TT/*  
    hadd -f   TT_SLTbar.root 	/hdfs/store/user/$USER/${jobID}_TT_SLTbar-SUB-TT/*  

    #hadd     	--reuse-cache-files ZJets1050.root	/hdfs/store/user/$USER/${jobID}_ZJets1050-SUB-MC 
    #hadd 	--reuse-cache-files WWTo2L2Nu.root 	/hdfs/store/user/$USER/${jobID}_WWTo2L2Nu-SUB-MC 
    #hadd 	--reuse-cache-files WWTo4Q.root 	/hdfs/store/user/$USER/${jobID}_WWTo4Q-SUB-MC 
    #hadd 	--reuse-cache-files WWToLNuQQ.root 	/hdfs/store/user/$USER/${jobID}_WWToLNuQQ-SUB-MC 
    #hadd 	--reuse-cache-files ZZTo2L2Q.root 	/hdfs/store/user/$USER/${jobID}_ZZTo2L2Q-SUB-MC 
    #hadd 	--reuse-cache-files ZZTo4Q.root 	/hdfs/store/user/$USER/${jobID}_ZZTo4Q-SUB-MC 
    #nohup hadd 	--reuse-cache-files TT.root 	        /hdfs/store/user/$USER/${jobID}_TT-SUB-MC  
    #nohup hadd 	--reuse-cache-files WJetsMLM.root 	/hdfs/store/user/$USER/${jobID}_WJetsMLM-SUB-MC 
    #nohup hadd 	--reuse-cache-files t_s.root 	        /hdfs/store/user/$USER/${jobID}_t_s-SUB-MC 
    #nohup hadd 	--reuse-cache-files t_s_Ext.root 	/hdfs/store/user/$USER/${jobID}_t_Ext-SUB-MC 
fi

