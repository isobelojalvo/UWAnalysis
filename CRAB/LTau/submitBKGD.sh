#!/bin/sh
voms-proxy-init --voms cms --valid 100:00


farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/DYJetsToLL_M-50_TuneZ2Star_8TeV-madgraph-tarball/Summer12_DR53X-PU_S10_START53_V7A-v1/AODSIM/2013-02-25-8TeV-53X-PatTuple_Master   		DYJets    $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCZ.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/swanson/DY1JetsToLL_M-50_TuneZ2Star_8TeV-madgraph   		Z1Jets    $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCZ.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/swanson/DY2JetsToLL_M-50_TuneZ2Star_8TeV-madgraph   		Z2Jets    $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCZ.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/swanson/DY3JetsToLL_M-50_TuneZ2Star_8TeV-madgraph   		Z3Jets    $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCZ.py
farmoutAnalysisJobs  $1   --vsize-limit=20000  --input-dir=/store/user/swanson/DY4JetsToLL_M-50_TuneZ2Star_8TeV-madgraph   		Z4Jets    $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCZ.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/swanson/WJetsToLNu_TuneZ2Star_8TeV-madgraph-tarball/WJetsToLNu_TuneZ2Star_8TeV-madgraph-tarball_v1_WJets8TeV-9ec8fe3/	 	    WJets_v1  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCW.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/swanson/WJetsToLNu_TuneZ2Star_8TeV-madgraph-tarball/Summer12_DR53X-PU_S10_START53_V7A-v2	 	    WJets_v2  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCW.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/swanson/W1JetsToLNu_TuneZ2Star_8TeV-madgraph	 	    		W1Jets_1    $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCW.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/swanson/W2JetsToLNu_TuneZ2Star_8TeV-madgraph	 	    		W2Jets_1    $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCW.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/swanson/W3JetsToLNu_TuneZ2Star_8TeV-madgraph/W3JetsToLNu_TuneZ2Star_8TeV-madgraph_WJets8TeV-9ec8fe3	 	    		W3Jets_1    $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCW.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/W1JetsToLNu_TuneZ2Star_8TeV-madgraph/Summer12_DR53X-PU_S10_START53_V19-v1	 	    		W1Jets_2    $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCW.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/W2JetsToLNu_TuneZ2Star_8TeV-madgraph/Summer12_DR53X-PU_S10_START53_V19-v1	 	    		W2Jets_2    $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCW.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/swanson/W3JetsToLNu_TuneZ2Star_8TeV-madgraph/Summer12_DR53X-PU_S10_START53_V19-v1	 	    		W3Jets_2    $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCW.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/swanson/W4JetsToLNu_TuneZ2Star_8TeV-madgraph	 	    		W4Jets    $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MCW.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/swanson/TTJets_FullLeptMGDecays_8TeV-madgraph-tauola	    TTBar_LL     $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MC.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/swanson/TTJets_HadronicMGDecays_8TeV-madgraph         	TTBar_HH     $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MC.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/swanson/TTJets_SemiLeptMGDecays_8TeV-madgraph-tauola  	TTBar_HL     $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MC.py
# farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/TTJets_MassiveBinDECAY_TuneZ2star_8TeV-madgraph-tauola 	TTBar     $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MC.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/WWJetsTo2L2Nu_TuneZ2star_8TeV-madgraph-tauola	 	    WW2L      $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MC.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/WZJetsTo3LNu_TuneZ2_8TeV-madgraph-tauola		        WZ3L      $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MC.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/WZJetsTo2L2Q_TuneZ2star_8TeV-madgraph-tauola		    WZ2L2Q    $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MC.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/ZZJetsTo4L_TuneZ2star_8TeV-madgraph-tauola		        ZZ4L	  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MC.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/ZZJetsTo2L2Q_TuneZ2star_8TeV-madgraph-tauola		    ZZ2L2Q	  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MC.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/T_tW-channel-DR_TuneZ2star_8TeV-powheg-tauola		    t_tW	  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MC.py
farmoutAnalysisJobs  $1   --vsize-limit=8000  --input-dir=/store/user/tapas/Tbar_tW-channel-DR_TuneZ2star_8TeV-powheg-tauola		tBar_tW	  $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/LTau/SUB-MC.py



