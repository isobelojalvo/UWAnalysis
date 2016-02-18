echo "#!/bin/sh" > submitSVfit.sh
for dir in SINGLEMUON2015D-SUB-JSON SINGLEELE2015D-SUB-JSON
do
    echo '========='
    echo $dir
    echo 'nfs_scratch:'
    ls -d /nfs_scratch/laura/$dir/*/ |wc -l
    var = $(ls -d /nfs_scratch/laura/$dir/*/ |wc -l)
    echo 'hdfs:'
    ls /hdfs/store/user/laura/$dir |wc -l
    varhdfs=$(ls /hdfs/store/user/laura/$dir |wc -l)
    if [ "$var" != "$varhdfs" ]
	then
	echo 'MISSING FILES IN ' $dir
    fi
    echo 'python scriptForDirectorySetup.py  --sampledir /hdfs/store/user/laura/'$dir' --jobName FEB17' >> submitSVfit.sh
done

for dir in ggHtautau_120  ggHtautau_125  ggHtautau_130  vbfHtautau_120 vbfHtautau_125 vbfHtautau_130 susyggHtautau_80   susyggHtautau_90   susyggHtautau_100  susyggHtautau_110  susyggHtautau_120  susyggHtautau_130  susyggHtautau_140  susyggHtautau_160  susyggHtautau_180  susyggHtautau_200  susyggHtautau_250  susyggHtautau_300  susyggHtautau_350  susyggHtautau_400  susyggHtautau_450  susyggHtautau_500  susyggHtautau_600  susyggHtautau_700  susyggHtautau_800  susyggHtautau_900  susyggHtautau_1000 susyggHtautau_1200 susyggHtautau_1400 susyggHtautau_1500 susyggHtautau_1600 susyggHtautau_1800 susyggHtautau_2000 susyggHtautau_2300 susyggHtautau_2600 susyggHtautau_2900 susyggHtautau_3200 ZJets  Z1Jets Z2Jets Z3Jets Z4Jets ZJets_1050  Z2Jets_1050 TTJets TT WJets WJetsHT100 WJetsHT200  WJetsHT400  WJetsHT600  WJetsHT800 WZ WZJets WTo1L3Nu tBar_tW t_tW St_t_top WW ZZ ZZTo4L
do
    echo '========='
    echo $dir
    echo 'nfs_scratch:'
    ls -d /nfs_scratch/laura/25ns_NoShapes$dir-SUB-MC/*/ |wc -l
    var=$(ls -d /nfs_scratch/laura/25ns_NoShapes$dir-SUB-MC/*/ |wc -l)
    echo 'hdfs:'
    ls /hdfs/store/user/laura/25ns_NoShapes$dir-SUB-MC |wc -l
    varhdfs=$(ls /hdfs/store/user/laura/25ns_NoShapes$dir-SUB-MC |wc -l)
    if [ "$var" != "$varhdfs" ]
	then
	echo '=============================MISSING FILES IN ' $dir
    fi
    echo 'python scriptForDirectorySetup.py  --sampledir /hdfs/store/user/laura/25ns_NoShapes'$dir'-SUB-MC --jobName FEB17' >> submitSVfit.sh
done
exit;
ggHtautau_120  ggHtautau_125  ggHtautau_130  vbfHtautau_120 vbfHtautau_125 vbfHtautau_130 25ns_susyggHtautau_80   25ns_susyggHtautau_90   25ns_susyggHtautau_100  25ns_susyggHtautau_110  25ns_susyggHtautau_120  25ns_susyggHtautau_130  25ns_susyggHtautau_140  25ns_susyggHtautau_160  25ns_susyggHtautau_180  25ns_susyggHtautau_200  25ns_susyggHtautau_250  25ns_susyggHtautau_300  25ns_susyggHtautau_350  25ns_susyggHtautau_400  25ns_susyggHtautau_450  25ns_susyggHtautau_500  25ns_susyggHtautau_600  25ns_susyggHtautau_700  25ns_susyggHtautau_800  25ns_susyggHtautau_900  25ns_susyggHtautau_1000 25ns_susyggHtautau_1200 25ns_susyggHtautau_1400 25ns_susyggHtautau_1500 25ns_susyggHtautau_1600 25ns_susyggHtautau_1800 25ns_susyggHtautau_2000 25ns_susyggHtautau_2300 25ns_susyggHtautau_2600 25ns_susyggHtautau_2900 25ns_susyggHtautau_3200 25ns_ZJets  25ns_Z1Jets 25ns_Z2Jets 25ns_Z3Jets 25ns_Z4Jets 25ns_ZJets_1050  25ns_Z2Jets_1050 25ns_TTJets 25ns_TT 25ns_WJets 25ns_WJetsHT100 25ns_WJetsHT200  25ns_WJetsHT400  25ns_WJetsHT600  25ns_WJetsHT800 25ns_WZ 25ns_WZJets 25ns_WTo1L3Nu 25ns_tBar_tW 25ns_t_tW 25ns_St_t_top 25ns_WW 25ns_ZZ 25ns_ZZTo4L

what about 25ns_WWToLNu2Q.txt