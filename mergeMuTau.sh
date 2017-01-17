mkdir /scratch/ojalvo/muTau_unweighted_Jan16
cd /scratch/ojalvo/muTau_unweighted_Jan16

jobID="mutau_2016_Jan6"
hadd -f muDataB.root /hdfs/store/user/ojalvo/${jobID}_SINGLEMUON2016B-SUB-JSON/*
hadd -f muDataC.root /hdfs/store/user/ojalvo/${jobID}_SINGLEMUON2016C-SUB-JSON/*
hadd -f muDataD.root /hdfs/store/user/ojalvo/${jobID}_SINGLEMUON2016D-SUB-JSON/*
hadd -f muDataE.root /hdfs/store/user/ojalvo/${jobID}_SINGLEMUON2016E-SUB-JSON/*
hadd -f muDataF.root /hdfs/store/user/ojalvo/${jobID}_SINGLEMUON2016F-SUB-JSON/*
hadd -f muDataG.root /hdfs/store/user/ojalvo/${jobID}_SINGLEMUON2016G-SUB-JSON/*

hadd -f WJetsMLM.root          /hdfs/store/user/ojalvo/${jobID}_WJets*/*
hadd -f W1Jets.root         /hdfs/store/user/ojalvo/${jobID}_W1Jets*/*
hadd -f W2Jets.root         /hdfs/store/user/ojalvo/${jobID}_W2Jets*/*
hadd -f W3Jets.root         /hdfs/store/user/ojalvo/${jobID}_W3Jets*/*
hadd -f W4Jets.root         /hdfs/store/user/ojalvo/${jobID}_W4Jets*/*
hadd -f W4Jets-ext2.root    /hdfs/store/user/ojalvo/${jobID}_W4Jets-ext2*/*    #duplicates the one below
hadd -f ZJets_ext1.root          /hdfs/store/user/ojalvo/${jobID}_ZJets*/*
hadd -f Z1Jets.root         /hdfs/store/user/ojalvo/${jobID}_Z1Jets*/*
hadd -f Z2Jets.root         /hdfs/store/user/ojalvo/${jobID}_Z2Jets*/*
hadd -f Z3Jets.root         /hdfs/store/user/ojalvo/${jobID}_Z3Jets*/*
hadd -f Z4Jets.root         /hdfs/store/user/ojalvo/${jobID}_Z4Jets*/*
hadd -f WZTo3LNu.root       /hdfs/store/user/ojalvo/${jobID}_WZTo3LNu*/*
hadd -f VVTo2L2Nu.root      /hdfs/store/user/ojalvo/${jobID}_VVTo2L2Nu*/*     # duplicates the one below. 
hadd -f VVTo2L2Nu-ext1.root /hdfs/store/user/ojalvo/${jobID}_VVTo2L2Nu-ext1*/*
hadd -f ZZTo2L2Q.root       /hdfs/store/user/ojalvo/${jobID}_ZZTo2L2Q*/*
hadd -f WZTo1L3Nu.root      /hdfs/store/user/ojalvo/${jobID}_WZTo1L3Nu*/*
hadd -f WZTo1L1Nu2Q.root    /hdfs/store/user/ojalvo/${jobID}_WZTo1L1Nu2Q*/*
hadd -f t_s_top.root        /hdfs/store/user/ojalvo/${jobID}_t_s_top*/*
hadd -f ST_t_antitop.root   /hdfs/store/user/ojalvo/${jobID}_ST_t_antitop*/*
hadd -f ST_t_top.root       /hdfs/store/user/ojalvo/${jobID}_ST_t_top*/*
hadd -f ST_tW_antitop.root  /hdfs/store/user/ojalvo/${jobID}_ST_tW_antitop*/*
hadd -f ST_tW_top.root      /hdfs/store/user/ojalvo/${jobID}_ST_tW_top*/*
hadd -f TT.root             /hdfs/store/user/ojalvo/${jobID}_TT*/*

cd /cms/ojalvo/HTT_80X/laura-working-area/CMSSW_8_0_21/src/UWAnalysis
nohup bash weight80X.sh >logWeight80X &
nohup bash weight80XPUTall.sh >logWeight80XPUTall &