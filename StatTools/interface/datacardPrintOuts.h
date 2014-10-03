#include "DataCardCreator.h"

void makeMSSMLTauDataCard(BkgOutput out,std::string postfix) {
  for(unsigned int m = 0;m<mssmMasses_.size();++m) {
    FILE *pfile = fopen(("datacards/"+channel_+postfix+"_mA"+mssmMasses_[m]+".txt").c_str(),"w");
    fprintf(pfile,"imax 1\n");
    fprintf(pfile,"jmax *\n");
    fprintf(pfile,"kmax *\n");
    fprintf(pfile,"shapes *  *    %s  $CHANNEL/$PROCESS $CHANNEL/$PROCESS_$SYSTEMATIC \n",(channel_+".root").c_str());
    fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
    fprintf(pfile,"observation %d\n",(int)out.DATA);
    fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
    std::string ch = channel_+postfix;
    fprintf(pfile,"bin            %s            %s            %s            %s            %s            %s            %s            %s            %s\n",ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str());
    fprintf(pfile,"process        GGH%s        BBH%s        ZTT           QCD           W             ZJ            ZL            TT            VV\n",mssmMasses_[m].c_str(),mssmMasses_[m].c_str());
    fprintf(pfile,"process        -1            0             1             2             3             4             5             6             7\n");
    fprintf(pfile,"rate           %.3f          %.3f          %.3f          %.3f          %.3f          %.3f          %.3f          %.3f          %.3f\n",
	    getYield("GGH"+mssmMasses_[m],postfix),getYield("BBH"+mssmMasses_[m],postfix),out.ZTT,out.QCD,out.W,out.ZJFT,out.ZLFT,out.TOP,out.VV);
    fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
    if(luminosityErr_!=0)
      fprintf(pfile,"lumi     lnN   %.3f          %.3f          -             -             -             -             -             -             -          luminosity\n",
	      1+luminosityErr_,1+luminosityErr_);
    if(muID_!=0)
      fprintf(pfile,"CMS_eff_m     lnN   %.3f          %.3f          %.3f          -             -             %.3f          %.3f          %.3f          %.3f       muon ID /HLT\n",
	      1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_);
    if(tauID_!=0)
      fprintf(pfile,"CMS_eff_t    lnN   %.3f          %.3f          %.3f          -             -             -             -             %.3f          %.3f        Tau IDf\n",
	      1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_);
    if(eleID_!=0)
      fprintf(pfile,"CMS_eff_e    lnN   %.3f          %.3f          %.3f          -             -             %.3f          %.3f          %.3f           %.3f      Electron ID\n",
	      1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_);
    if(zttScale_!=0)
      fprintf(pfile,"CMS_htt_zttNorm lnN   -             -             %.3f          -             -             %.3f          %.3f          -              -         ZTT Scale  \n",
	      1+zttScaleErr_/zttScale_,1+zttScaleErr_/zttScale_,1+zttScaleErr_/zttScale_);
    fprintf(pfile,"CMS_htt_ttbarNorm  lnN      -             -             -             -             -             -             -              %.3f           -      TTbar background  \n",1+out.dTOP/out.TOP);
    fprintf(pfile,"CMS_htt_DiBosonNorm  lnN      -             -             -             -             -             -             -              -              %.3f   DiBoson background \n",1+out.dVV/out.VV);
    fprintf(pfile,"CMS_htt_%s_WNorm lnN      -             -             -             -             %.3f          -             -              -              -      W Backghround \n",(channel_+postfix).c_str(),1+out.dW/out.W);
    fprintf(pfile,"CMS_htt_%s_ZJFTNorm  lnN      -             -             -             -             -             %.3f          -              -              -      Z(jet->tau) background\n",(channel_+postfix).c_str(),1+out.dZJFT/out.ZJFT);
    fprintf(pfile,"CMS_htt_%s_ZLFTNorm  lnN      -             -             -             -             -             -             %.3f           -              -      Z(l->tau)   background\n",(channel_+postfix).c_str(),1+out.dZLFT/out.ZLFT);
    fprintf(pfile,"CMS_htt_%s_QCDNorm gmN   %d   -             -             -             %.3f          -             -             -              -              -      QCD Background\n",(channel_+postfix).c_str(),(int)out.QCDSDB,qcdFactor_);
    fprintf(pfile,"CMS_htt_%s_QCDSyst lnN        -             -             -             %.3f          -             -             -              -              -      QCD Background Systematics\n",(channel_).c_str(),1.+qcdFactorErr_/qcdFactor_);
    
    for(unsigned int j=0;j<shifts_.size();++j)
      fprintf(pfile,"%s    shape    1             1             1             -             -             -             -              -              -      shape\n",shiftsPostFix_[j].c_str());

    fprintf(pfile,"CMS_scale_met lnN  1.05          1.05          -             -             -             -             -              1.02          1.03      MET Scale\n");
    fprintf(pfile,"CMS_scale_j   lnN  1.05          1.05          -             -             -             -             -              1.02          1.03      Jet Scale\n");


    fclose(pfile);
    }
}


  void makeMSSMEMuDataCard(BkgOutput out,std::string postfix) {
    for(unsigned int m = 0;m<mssmMasses_.size();++m) {
      FILE *pfile = fopen(("datacards/"+channel_+postfix+"_mA"+mssmMasses_[m]+".txt").c_str(),"w");
      fprintf(pfile,"imax 1\n");
      fprintf(pfile,"jmax *\n");
      fprintf(pfile,"kmax *\n");
      fprintf(pfile,"shapes *  *    %s  $CHANNEL/$PROCESS $CHANNEL/$PROCESS_$SYSTEMATIC \n",(channel_+".root").c_str());
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      fprintf(pfile,"observation %d\n",(int)out.DATA);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      std::string ch = channel_+postfix;
      fprintf(pfile,"bin            %s            %s            %s            %s            %s            %s   \n",ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str());
      fprintf(pfile,"process        GGH%s        BBH%s        ZTT         FAKES            TT            VV\n",mssmMasses_[m].c_str(),mssmMasses_[m].c_str());
      fprintf(pfile,"process        -1            0             1             2             3             4          \n");
      fprintf(pfile,"rate           %.3f          %.3f          %.3f          %.3f          %.3f          %.3f       \n",
	     getYield("GGH"+mssmMasses_[m],postfix),getYield("BBH"+mssmMasses_[m],postfix),out.ZTT,out.QCD,out.TOP,out.VV);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      if(luminosityErr_!=0)
	fprintf(pfile,"lumi     lnN   %.3f          %.3f          -             -             -             -           luminosity\n",
	   1+luminosityErr_,1+luminosityErr_);
      if(muID_!=0)
	fprintf(pfile,"CMS_eff_m     lnN   %.3f          %.3f          %.3f          -        %.3f          %.3f          muon ID /HLT\n",
	       1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_);
      if(eleID_!=0)
	fprintf(pfile,"CMS_eff_e    lnN   %.3f          %.3f          %.3f          -         %.3f          %.3f         Electron ID\n",
	     1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_);
    if(zttScale_!=0)
      fprintf(pfile,"CMS_htt_zttNorm lnN   -             -             %.3f          -             -          -         ZTT Scale  \n",1+zttScaleErr_/zttScale_);
    fprintf(pfile,"CMS_htt_ttbarNorm  lnN      -             -             -             -           %.3f     -    TTbar background  \n",1+out.dTOP/out.TOP);
    fprintf(pfile,"CMS_htt_DiBosonNorm  lnN      -             -             -             -             -     %.3f   DiBoson background \n",1+out.dVV/out.VV);
    fprintf(pfile,"CMS_htt_%s_FAKENorm lnN        -             -             -             %.3f          -             -       FAKE Background Systematics\n",(channel_).c_str(),1.+out.dQCD/out.QCD);
    for(unsigned int j=0;j<shifts_.size();++j)
      fprintf(pfile,"%s    shape    1             1             1             -             -             -      shape\n",shiftsPostFix_[j].c_str());

    fprintf(pfile,"CMS_scale_met lnN  1.05          1.05          -             -           1.02          1.03      MET Scale\n");
    fprintf(pfile,"CMS_scale_j   lnN  1.05          1.05          -             -           1.02          1.03      Jet Scale\n");


    fclose(pfile);
    }
  }



  void makeMSSMLTauDataCardNoBTag(BkgOutput out,std::string postfix) {
    for(unsigned int m = 0;m<mssmMasses_.size();++m) {
      FILE *pfile = fopen(("datacards/"+channel_+postfix+"_mA"+mssmMasses_[m]+".txt").c_str(),"w");

      fprintf(pfile,"imax 1\n");
      fprintf(pfile,"jmax *\n");
      fprintf(pfile,"kmax *\n");
      fprintf(pfile,"shapes *  *    %s  $CHANNEL/$PROCESS $CHANNEL/$PROCESS_$SYSTEMATIC \n",(channel_+".root").c_str());
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      fprintf(pfile,"observation %d\n",(int)out.DATA);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      std::string ch = channel_+postfix;
      fprintf(pfile,"bin            %s            %s             %s            %s             %s                 %s            %s            %s             %s           %s            %s              %s\n",ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str());
      fprintf(pfile,"process        GGHNoJet%s   GGHJet%s        BBHNoJet%s     BBHJet%s     BBHBJet%s           ZTT           QCD           W             ZJ            ZL            TT            VV\n",mssmMasses_[m].c_str(),mssmMasses_[m].c_str(),mssmMasses_[m].c_str(),mssmMasses_[m].c_str(),mssmMasses_[m].c_str());
      fprintf(pfile,"process        -4              -3           -2              -1            0                 1             2             3             4             5            6             7  \n");
      fprintf(pfile,"rate           %.3f            %.3f          %.3f         %.3f          %.3f             %.3f          %.3f          %.3f          %.3f          %.3f          %.3f            %.3f\n",
	      getYield("GGHNoJet"+mssmMasses_[m],postfix),getYield("GGHJet"+mssmMasses_[m],postfix),getYield("BBHNoJet"+mssmMasses_[m],postfix),getYield("BBHJet"+mssmMasses_[m],postfix),getYield("BBHBJet"+mssmMasses_[m],postfix),out.ZTT,out.QCD,out.W,out.ZJFT,out.ZLFT,out.TOP,out.VV);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      if(luminosityErr_!=0)
	fprintf(pfile,"lumi     lnN %.3f           %.3f          %.3f           %.3f           %.3f              -             -             -             -             -             -             -          luminosity\n",
		1+luminosityErr_,1+luminosityErr_,1+luminosityErr_,1+luminosityErr_,1+luminosityErr_);
      
      if(muID_!=0)
	fprintf(pfile,"CMS_eff_m     lnN   %.3f          %.3f          %.3f          %.3f           %.3f             %.3f          -             -             %.3f          %.3f          %.3f          %.3f       muon ID /HLT\n",
	        1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_);
      if(tauID_!=0)
	fprintf(pfile,"CMS_eff_t    lnN   %.3f          %.3f          %.3f          %.3f          %.3f          %.3f          -             -             -             -             %.3f          %.3f        Tau IDf\n",
	       1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_);
    if(eleID_!=0)
      fprintf(pfile,"CMS_eff_e    lnN   %.3f          %.3f          %.3f          %.3f          %.3f          %.3f             -             -             %.3f          %.3f          %.3f           %.3f      Electron ID\n",
	     1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_);
    if(zttScale_!=0)
      fprintf(pfile,"CMS_htt_zttNorm lnN   -             -             -               -            -             %.3f          -             -             %.3f          %.3f          -              -         ZTT Scale  \n",
	     1+zttScaleErr_/zttScale_,1+zttScaleErr_/zttScale_,1+zttScaleErr_/zttScale_);
      fprintf(pfile,"CMS_htt_zttExtrap_nob  lnN   -             -             -               -            -             %.8f          -             -             -          -          -              -         ZTT Scale  \n",
	     1+out.dZTTCORR/out.ZTTCORR);

    for(unsigned int j=0;j<shifts_.size();++j)
	fprintf(pfile,"%s    shape    1.0             1.0             1.0             1.0             1.0             1.0             -             -             -             -              -              -      shape\n",shiftsPostFix_[j].c_str());


    fprintf(pfile,"CMS_htt_%s_QCDNorm gmN %d      -             -             -             -             -             -             %.3f          -             -             -              -              -      QCD Background\n",(channel_+postfix).c_str(),(int)out.QCDSDB,qcdFactor_);
    fprintf(pfile,"CMS_htt_%s_QCDSyst lnN        -             -             -             -          -                      -          %.3f        -              -              -            -           -      QCD Background Systematics\n",(channel_).c_str(),1.+qcdFactorErr_/qcdFactor_);
    fprintf(pfile,"CMS_htt_ttbarNorm  lnN      -             -            -             -              -              -             -             -             -             -              %.3f           -      TTbar background  \n",1+out.dTOP/out.TOP);
    fprintf(pfile,"CMS_htt_DiBosonNorm  lnN      -             -             -             -             -              -             -             -             -             -              -              %.3f   DiBoson background \n",1+out.dVV/out.VV);
    fprintf(pfile,"CMS_htt_%s_WNorm   lnN        -             -             -             -             -             -             -             %.3f          -             -              -              -      W Backghround \n",(channel_+postfix).c_str(),(int)1+out.dW/out.W);
    fprintf(pfile,"CMS_htt_%s_ZJFTNorm  lnN      -            -             -             -              -             -             -             -             %.3f          -              -              -      Z(jet->tau) background\n",(channel_+postfix).c_str(),1+out.dZJFT/out.ZJFT);
    fprintf(pfile,"CMS_htt_%s_ZLFTNorm  lnN      -             -            -            -               -             -             -             -             -             %.3f           -              -      Z(l->tau)   background\n",(channel_+postfix).c_str(),1+out.dZLFT/out.ZLFT);

    fprintf(pfile,"CMS_eff_b      lnN      -             -             -             -             %.3f          -             -              -              -             -              %.3f           -    BTag efficiency \n",1-bIDErr_/bID_,1-bIDErr_/bID_);
    fprintf(pfile,"CMS_fake_b   lnN      -             %.3f          -             %.3f           -             -             -             -             -             -              -              -     BTag MisTag \n",1-bMisIDErr_/bMisID_,1-bMisIDErr_/bMisID_);


    fprintf(pfile,"CMS_scale_j      lnN      0.98            0.98             0.98             0.98             0.98          -             -              -            -                -             0.93              0.97      Jet Scale \n");
    fprintf(pfile,"CMS_scale_met      lnN      -             -             -             -             -          -             -              -              -             -            1.03          1.04   MET scale \n");

    fclose(pfile);
    }
  
 

  }



  void makeMSSMEMuDataCardNoBTag(BkgOutput out,std::string postfix) {
    for(unsigned int m = 0;m<mssmMasses_.size();++m) {
      FILE *pfile = fopen(("datacards/"+channel_+postfix+"_mA"+mssmMasses_[m]+".txt").c_str(),"w");

      fprintf(pfile,"imax 1\n");
      fprintf(pfile,"jmax *\n");
      fprintf(pfile,"kmax *\n");
      fprintf(pfile,"shapes *  *    %s  $CHANNEL/$PROCESS $CHANNEL/$PROCESS_$SYSTEMATIC \n",(channel_+".root").c_str());
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      fprintf(pfile,"observation %d\n",(int)out.DATA);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      std::string ch = channel_+postfix;
      fprintf(pfile,"bin            %s            %s             %s            %s             %s                 %s            %s            %s            %s\n",ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str());
      fprintf(pfile,"process        GGHNoJet%s   GGHJet%s        BBHNoJet%s     BBHJet%s     BBHBJet%s           ZTT           FAKES           TT            VV\n",mssmMasses_[m].c_str(),mssmMasses_[m].c_str(),mssmMasses_[m].c_str(),mssmMasses_[m].c_str(),mssmMasses_[m].c_str());
      fprintf(pfile,"process        -4              -3           -2              -1            0                 1             2             3             4\n");
      fprintf(pfile,"rate           %.3f            %.3f          %.3f         %.3f          %.3f             %.3f          %.3f          %.3f             %.3f\n",
	      getYield("GGHNoJet"+mssmMasses_[m],postfix),getYield("GGHJet"+mssmMasses_[m],postfix),getYield("BBHNoJet"+mssmMasses_[m],postfix),getYield("BBHJet"+mssmMasses_[m],postfix),getYield("BBHBJet"+mssmMasses_[m],postfix),out.ZTT,out.QCD,out.TOP,out.VV);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      if(luminosityErr_!=0)
	fprintf(pfile,"lumi     lnN %.3f           %.3f          %.3f           %.3f           %.3f              -             -             -             -             -             -             -          luminosity\n",
		1+luminosityErr_,1+luminosityErr_,1+luminosityErr_,1+luminosityErr_,1+luminosityErr_);
      
      if(muID_!=0)
	fprintf(pfile,"CMS_eff_m     lnN   %.3f          %.3f          %.3f          %.3f           %.3f             %.3f          -                 %.3f          %.3f       muon ID /HLT\n",
	        1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_);
      if(eleID_!=0)
	fprintf(pfile,"CMS_eff_e    lnN   %.3f          %.3f          %.3f          %.3f          %.3f          %.3f             -             %.3f           %.3f      Electron ID\n",
	     1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_);
    if(zttScale_!=0)
      fprintf(pfile,"CMS_htt_zttNorm lnN   -             -             -               -            -             %.3f          -             -                -         ZTT Scale  \n",
	     1+zttScaleErr_/zttScale_);
      fprintf(pfile,"CMS_htt_zttExtrap_nob lnN   -             -             -               -            -             %.3f          -             -                -         ZTT Scale  \n",
	     1+out.dZTTCORR/out.ZTTCORR);
    for(unsigned int j=0;j<shifts_.size();++j)
      fprintf(pfile,"%s    shape    1.0             1.0             1.0             1.0             1.0             1.0            -             -           shape\n",shiftsPostFix_[j].c_str());
    fprintf(pfile,"CMS_htt_%s_FakeNorm lnN          -               -               -                -                -       -     %.3f           -              -               QCD Background Systematics\n",(channel_).c_str(),1.+qcdFactorErr_/qcdFactor_);

    fprintf(pfile,"CMS_htt_ttbarNorm  lnN      -             -            -             -              -              -             -             %.3f           -      TTbar background  \n",1+out.dTOP/out.TOP);
    fprintf(pfile,"CMS_htt_DiBosonNorm  lnN      -             -             -             -             -              -             -             -           %.3f   DiBoson background \n",1+out.dVV/out.VV);
    fprintf(pfile,"CMS_eff_b      lnN            -             -             -             -             %.3f          -             -              %.3f           -    BTag efficiency \n",1-bIDErr_/bID_,1-bIDErr_/bID_);
    fprintf(pfile,"CMS_fake_b   lnN              -             %.3f          -             %.3f           -            -             -              -              -     BTag MisTag \n",1-bMisIDErr_/bMisID_,1-bMisIDErr_/bMisID_);



    fprintf(pfile,"CMS_scale_j      lnN      0.98            0.98             0.98             0.98             0.98          -             -                 0.93              0.97      Jet Scale \n");
    fprintf(pfile,"CMS_scale_met      lnN      -             -                -                -                 -            -             -                 1.03          1.04   MET scale \n");

    fclose(pfile);
    }
  
 

  }



  void makeZTTLTauDataCard(BkgOutput out,std::string postfix) {
      FILE *pfile = fopen(("datacards/"+channel_+postfix+".txt").c_str(),"w");
      fprintf(pfile,"imax 1\n");
      fprintf(pfile,"jmax *\n");
      fprintf(pfile,"kmax *\n");
      fprintf(pfile,"shapes *  *    %s  $CHANNEL/$PROCESS $CHANNEL/$PROCESS_$SYSTEMATIC \n",(channel_+".root").c_str());
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      fprintf(pfile,"observation %d\n",(int)out.DATA);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      std::string ch = channel_+postfix;
      fprintf(pfile,"bin             %s            %s            %s            %s            %s            %s            %s\n",ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str());
      fprintf(pfile,"process         ZTT           QCD           W             ZJ            ZL            TT            VV\n");
      fprintf(pfile,"process          0             1             2             3             4             5             6\n");
      fprintf(pfile,"rate           %.3f          %.3f          %.3f          %.3f          %.3f          %.3f           %.3f\n",
	     out.ZTT,out.QCD,out.W,out.ZJFT,out.ZLFT,out.TOP,out.VV);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      if(muID_!=0)
	fprintf(pfile,"CMS_eff_m     lnN    %.3f          -             -             %.3f          %.3f          %.3f          %.3f       muon ID /HLT\n",
	       1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_);
      if(tauID_!=0)
	fprintf(pfile,"CMS_eff_t    lnN     %.3f          -             -             -             -             %.3f          %.3f        Tau IDf\n",
	       1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_);
      if(eleID_!=0)
	fprintf(pfile,"CMS_eff_e    lnN       %.3f          -             -             %.3f          %.3f          %.3f           %.3f      Electron ID\n",
	     1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_);
      fprintf(pfile,"CMS_htt_ttbarNorm  lnN       -             -             -             -             -              %.3f           -      TTbar background  \n",1+out.dTOP/out.TOP);
      fprintf(pfile,"CMS_htt_DiBosonNorm  lnN    -             -             -             -             -              -              %.3f   DiBoson background \n",1+out.dVV/out.VV);

    for(unsigned int j=0;j<shifts_.size();++j)
      fprintf(pfile,"%s    shape            1             -             -             -             -              -              -      shape\n",shiftsPostFix_[j].c_str());
    fprintf(pfile,"CMS_htt_%s_QCDNorm gmN   %d   -            %.3f          -             -             -              -              -      QCD Background\n",(channel_+postfix).c_str(),(int)out.QCDSDB,qcdFactor_);
    fprintf(pfile,"CMS_htt_%s_QCDSyst lnN        -             %.3f          -             -             -              -              -      QCD Background Systematics\n",(channel_).c_str(),1.+qcdFactorErr_/qcdFactor_);
    fprintf(pfile,"CMS_htt_%s_WNorm     lnN      -             -             %.3f          -             -              -              -      W Backghround \n",(channel_+postfix).c_str(),1+out.dW/out.W);
    fprintf(pfile,"CMS_htt_%s_ZJetFakeTau  lnN  -             -             -             %.3f          -              -              -      Z(jet->tau) background\n",(channel_+postfix).c_str(),1+out.dZJFT/out.ZJFT);
    fprintf(pfile,"CMS_htt_%s_ZLeptonFakeTau  lnN -             -             -             -             %.3f           -              -      Z(l->tau)   background\n",(channel_+postfix).c_str(),1+out.dZLFT/out.ZLFT);
    fclose(pfile);

  }


  void makeSMLTauDataCardNoVBF(BkgOutput out,std::string postfix, std::string rootS) {
    for(unsigned int m = 0;m<smMassesDC_.size();++m) {
      FILE *pfile = fopen(("datacards/"+channel_+postfix+"_mH"+smMassesDC_[m]+".txt").c_str(),"w");

      fprintf(pfile,"imax 1\n");
      fprintf(pfile,"jmax *\n");
      fprintf(pfile,"kmax *\n");
      fprintf(pfile,"shapes *  *    %s  $CHANNEL/$PROCESS $CHANNEL/$PROCESS_$SYSTEMATIC \n",(channel_+"SM.root").c_str());
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      fprintf(pfile,"observation %d\n",(int)out.DATA);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      std::string ch = channel_+postfix;
      fprintf(pfile,"bin       %s        %s            %s            %s            %s            %s            %s            %s            %s            %s\n",ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str());
      fprintf(pfile,"process   VH%s     ggH%s        qqH%s        ZTT           QCD           W             ZJ            ZL            TT            VV\n",smMassesDC_[m].c_str(),smMassesDC_[m].c_str(),smMassesDC_[m].c_str());
      fprintf(pfile,"process   -2     -1            0             1             2             3             4             5             6             7\n");
      fprintf(pfile,"rate      %.3f     %.3f          %.3f          %.3f          %.3f          %.3f          %.3f          %.3f          %.3f          %.3f\n",
	      getYield("VH"+smMassesDC_[m],postfix),getYield("ggH"+smMassesDC_[m],postfix),getYield("qqH"+smMassesDC_[m],postfix),out.ZTT,out.QCD,out.W,out.ZJFT,out.ZLFT,out.TOP,out.VV);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      if(luminosityErr_!=0)
	fprintf(pfile,"lumi_%s     lnN    %.3f        %.3f          %.3f          -             -             -             -             -             -             -          luminosity\n",
		rootS.c_str(),1+luminosityErr_,1+luminosityErr_,1+luminosityErr_);      
      if(muID_!=0)
	fprintf(pfile,"CMS_eff_m     lnN   %.3f     %.3f          %.3f          %.3f          -             -             %.3f          %.3f          %.3f          %.3f       muon ID /HLT\n",
		1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_);
      if(tauID_!=0)
	fprintf(pfile,"CMS_eff_t    lnN    %.3f      %.3f          %.3f          %.3f          -             -             -             -             %.3f          %.3f        Tau IDf\n",
		1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_);
    if(eleID_!=0)
      fprintf(pfile,"CMS_eff_e    lnN      %.3f       %.3f          %.3f          %.3f          -             -             %.3f          %.3f          %.3f           %.3f      Electron ID\n",
	      1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_);
    if(zttScale_!=0)
      fprintf(pfile,"CMS_htt_zttNorm_%s lnN   -         -             -             %.3f          -             -             %.3f          %.3f          -              -         ZTT Scale  \n",
	     rootS.c_str(),1+zttScaleErr_/zttScale_,1+zttScaleErr_/zttScale_,1+zttScaleErr_/zttScale_);
    fprintf(pfile,"CMS_htt_ttbarNorm_%s      lnN    -       -             -             -             -             -             -             -              %.3f           -      TTbar background  \n",rootS.c_str(),1+out.dTOP/out.TOP);
    fprintf(pfile,"CMS_htt_DiBosonNorm_%s     lnN  -           -             -             -             -             -             -             -              -              %.3f   DiBoson background \n",rootS.c_str(),1+out.dVV/out.VV);
    fprintf(pfile,"CMS_htt_%s_WNorm_%s       lnN      -        -             -             -             -             %.3f          -             -              -              -      W Background \n",channel_.c_str(),rootS.c_str(),1+out.dW/out.W);
    fprintf(pfile,"CMS_htt_%s_QCDNorm_%s gmN     %d   -        -             -             -             %.3f          -             -             -              -              -      QCD Background\n",(channel_+postfix).c_str(),rootS.c_str(),(int)out.QCDSDB,qcdFactor_);
    fprintf(pfile,"CMS_htt_%s_QCDSyst_%s lnN          -       -             -             -             %.3f          -             -             -              -              -      QCD Background\n",(channel_+postfix).c_str(),rootS.c_str(),1+qcdFactorErr_/qcdFactor_);
    fprintf(pfile,"CMS_htt_%s_ZJetFakeTau_%s lnN      -        -             -             -             -             -             %.3f          -              -              -      Z(jet->tau) background\n",(channel_+postfix).c_str(),rootS.c_str(),1+out.dZJFT/out.ZJFT);
    fprintf(pfile,"CMS_htt_%s_ZLeptonFakeTau_%s   lnN  -        -             -             -             -             -             -             %.3f           -              -      Z(l->tau)   background\n",(channel_+postfix).c_str(),rootS.c_str(),1+out.dZLFT/out.ZLFT);

       for(unsigned int j=0;j<shifts_.size();++j)
	     fprintf(pfile,"%s_%s    shape    1             1             1             1             -             -             -             -              -             -   -      shape\n",shiftsPostFix_[j].c_str(),rootS.c_str());

    fprintf(pfile,"CMS_scale_j_%s           lnN  0.96        0.99          0.92          -            -              -        -         -          0.94            0.97    Jet scale\n",rootS.c_str());
    fprintf(pfile,"CMS_scale_met_%s           lnN  1.05        1.05          1.05          -            -             -     1.05      1.05          1.02            1.06    Met scale\n",rootS.c_str());
       
    fprintf(pfile,"pdf_qqbar            lnN  -        -          1.08          -            -              -        -         -          -            -    PDF VBF\n");
    fprintf(pfile,"pdf_vh               lnN  1.08     -            -           -            -              -        -         -          -            -    PDF VBF\n");
    fprintf(pfile,"pdf_gg               lnN  -    1.08       -             -            -              -        -         -          -            -    PDF VBF\n");
    fprintf(pfile,"QCDscale_ggH         lnN  -    1.12       -             -            -              -        -         -          -            -    PDF VBF\n");
    fprintf(pfile,"QCDscale_qqH         lnN  -    -          1.035         -            -              -        -         -          -            -    PDF VBF\n");
    fprintf(pfile,"UEPS                 lnN  0.96    0.96       0.96          -            -              -        -         -          -            -    PDF VBF\n");


    fclose(pfile);
    }
  
  }



  void makeSMEMuDataCardNoVBF(BkgOutput out,std::string postfix) {
    for(unsigned int m = 0;m<smMassesDC_.size();++m) {
      FILE *pfile = fopen(("datacards/"+channel_+postfix+"_mH"+smMassesDC_[m]+".txt").c_str(),"w");

      fprintf(pfile,"imax 1\n");
      fprintf(pfile,"jmax *\n");
      fprintf(pfile,"kmax *\n");
      fprintf(pfile,"shapes *  *    %s  $CHANNEL/$PROCESS $CHANNEL/$PROCESS_$SYSTEMATIC \n",(channel_+"SM.root").c_str());
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      fprintf(pfile,"observation %d\n",(int)out.DATA);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      std::string ch = channel_+postfix;
      fprintf(pfile,"bin       %s     %s            %s            %s            %s         %s           %s\n",ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str());
      fprintf(pfile,"process   VH%s     ggH%s        qqH%s          ZTT           FAKES        TT            VV\n",smMassesDC_[m].c_str(),smMassesDC_[m].c_str(),smMassesDC_[m].c_str());
      fprintf(pfile,"process   -2      -1            0             1             2             3            4\n");
      fprintf(pfile,"rate      %.3f     %.3f          %.3f          %.3f          %.3f          %.3f          %.3f\n",
	      getYield("VH"+smMassesDC_[m],postfix),getYield("ggH"+smMassesDC_[m],postfix),getYield("qqH"+smMassesDC_[m],postfix),out.ZTT,out.QCD,out.TOP,out.VV);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      if(luminosityErr_!=0)
	fprintf(pfile,"lumi     lnN    %.3f    %.3f          %.3f          -             -             -             -             -             -             -          luminosity\n",
		1+luminosityErr_,1+luminosityErr_,1+luminosityErr_);      
      if(muID_!=0)
	fprintf(pfile,"CMS_eff_m     lnN   %.3f   %.3f          %.3f          %.3f          -         %.3f          %.3f       muon ID /HLT\n",
	       1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_);
      if(eleID_!=0)
	fprintf(pfile,"CMS_eff_e    lnN    %.3f      %.3f          %.3f          %.3f          -           %.3f          %.3f       Electron ID\n",
	     1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_);
    if(zttScale_!=0)
      fprintf(pfile,"CMS_htt_zttNorm lnN   -         -             -             %.3f          -             -         -         ZTT Scale  \n",
	     1+zttScaleErr_/zttScale_);
      fprintf(pfile,"CMS_htt_zttExtrap_sm0 lnN   -         -             -             %.3f          -             -         -         ZTT Scale  \n",
	     1+out.dZTTCORR/out.ZTTCORR);
    fprintf(pfile,"CMS_htt_ttbarNorm      lnN  -         -             -             -             -              %.3f           -      TTbar background  \n",1+out.dTOP/out.TOP);
    fprintf(pfile,"CMS_htt_DiBosonNorm     lnN -         -             -             -             -           -              %.3f   DiBoson background \n",1+out.dVV/out.VV);
    fprintf(pfile,"CMS_htt_%s_FakeNorm    lnN  -         -             -             -             %.3f          -             -      QCD Background\n",(channel_+postfix).c_str(),1+out.dQCD/out.QCD);
       for(unsigned int j=0;j<shifts_.size();++j)
	   fprintf(pfile,"%s    shape    1             1             1               1             -             -             -        shape\n",shiftsPostFix_[j].c_str());

//    fprintf(pfile,"CMS_scale_j           lnN  0.96        0.99          0.92          -            -              0.94            0.97    Jet scale\n");
    fprintf(pfile,"CMS_scale_met           lnN  1.05        1.05          1.05          -            -              1.02            1.06    Met scale\n");
    fprintf(pfile,"pdf_qqbar            lnN  -    -          1.08          -            -              -            -    PDF VBF\n");
    fprintf(pfile,"pdf_vh               lnN  1.08    -       -          -            -              -            -    PDF VBF\n");
    fprintf(pfile,"pdf_gg               lnN  -    1.08       -             -            -              -            -    PDF VBF\n");
    fprintf(pfile,"QCDscale_ggH         lnN  -    1.12       -             -            -              -            -    PDF VBF\n");
    fprintf(pfile,"QCDscale_qqH         lnN  -    -          1.035         -            -              -            -    PDF VBF\n");
    fprintf(pfile,"UEPS                 lnN  0.96    0.96       0.96          -            -              -            -    PDF VBF\n");
    fclose(pfile);
    }
  

  }



  void makeSMLTauDataCardVBF(BkgOutput out,std::string postfix, std::string rootS) {
    for(unsigned int m = 0;m<smMassesDC_.size();++m) {
      FILE *pfile = fopen(("datacards/"+channel_+postfix+"_mH"+smMassesDC_[m]+".txt").c_str(),"w");

      fprintf(pfile,"imax 1\n");
      fprintf(pfile,"jmax *\n");
      fprintf(pfile,"kmax *\n");
      fprintf(pfile,"shapes *  *    %s  $CHANNEL/$PROCESS $CHANNEL/$PROCESS_$SYSTEMATIC \n",(channel_+"SM.root").c_str());
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      fprintf(pfile,"observation %d\n",(int)out.DATA);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      std::string ch = channel_+postfix;
      fprintf(pfile,"bin            %s           %s            %s            %s            %s            %s            %s            %s            %s\n",ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str());
      fprintf(pfile,"process        VH%s        ggH%s        qqH%s        ZTT           QCD           W             ZLL             TT            VV\n",smMassesDC_[m].c_str(),smMassesDC_[m].c_str(),smMassesDC_[m].c_str());
      fprintf(pfile,"process        -2           -1            0            1             2           3             4             5             6  \n");
      fprintf(pfile,"rate           %.3f        %.3f          %.3f          %.3f          %.3f          %.3f          %.3f          %.3f          %.3f\n",
	     getYield("VH"+smMassesDC_[m],postfix),getYield("ggH"+smMassesDC_[m],postfix),getYield("qqH"+smMassesDC_[m],postfix),out.ZTT,out.QCD,out.W,out.ZLFT,out.TOP,out.VV);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      if(luminosityErr_!=0)
	fprintf(pfile,"lumi_%s     lnN   %.3f     %.3f          %.3f          -             -             -             -            -             -          luminosity\n",
		rootS.c_str(),1+luminosityErr_,1+luminosityErr_,1+luminosityErr_);
      for(unsigned int j=0;j<shifts_.size();++j)
	  fprintf(pfile,"%s_%s    shape    1   1     1       1         -           -          -         -        -                 shape(Ignore small ones that cause instabilities)\n",shiftsPostFix_[j].c_str(),rootS.c_str());
	  
      if(muID_!=0)
	fprintf(pfile,"CMS_eff_m     lnN   %.3f  %.3f          %.3f          %.3f          -             -             %.3f            %.3f          %.3f       muon ID /HLT\n",
		1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_);
      if(tauID_!=0)
	fprintf(pfile,"CMS_eff_t     lnN   %.3f   %.3f          %.3f          %.3f          -             -             -                     %.3f          %.3f        Tau IDf\n",
		1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_);
      if(eleID_!=0)
	fprintf(pfile,"CMS_eff_e       lnN %.3f   %.3f          %.3f          %.3f          -             -             %.3f               %.3f           %.3f      Electron ID\n",
		1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_);
      if(zttScale_!=0)
	fprintf(pfile,"CMS_htt_zttNorm_%s lnN   -             -             -             %.3f          -             -             %.3f                    -              -         ZTT Scale  \n",
		rootS.c_str(),1+zttScaleErr_/zttScale_,1+zttScaleErr_/zttScale_);

    /////////FIXPOINT
      fprintf(pfile,"CMS_htt_ztt_extrap_vbf_%s lnN   -                 -             -             %.3f          -             -                %.3f          -              -         ZTT Extrapolation  \n",
	      rootS.c_str(),1+out.dZTTCORR/out.ZTTCORR,1+vbfFactorZErr_/vbfFactorZ_);
    fprintf(pfile,"CMS_htt_ttbarNorm_%s          lnN   -   -             -             -             -             -             -                           %.3f           -      TTbar background  \n",rootS.c_str(),1+out.dTOP/out.TOP);
    fprintf(pfile,"CMS_htt_DiBosonNorm_%s        lnN    -  -             -             -             -             -             -                           -              %.3f   DiBoson background \n",rootS.c_str(),1+out.dVV/out.VV);
    fprintf(pfile,"CMS_htt_%s_QCDSyst_%s             lnN -       -             -             -             %.3f          -             -             -                            -      QCD Background\n",(channel_+postfix).c_str(),rootS.c_str(),1+out.dQCD/out.QCD);
    fprintf(pfile,"CMS_htt_W_extrap_vbf_%s           lnN  -    -             -             -             -             %.3f          -             -                            -      W Extrapolation \n",rootS.c_str(),1+vbfFactorWErr_/vbfFactorW_);
    fprintf(pfile,"CMS_htt_%s_WNorm_%s                  lnN   -   -             -             -             -             %.3f          -             -              -              -      W Background \n",channel_.c_str(),rootS.c_str(),1+out.dWCORR/out.WCORR);
    fprintf(pfile,"CMS_htt_ZLLNorm_%s                  lnN   -   -             -             -             -             -          %.3f           -              -      Z(l->tau)   background\n",rootS.c_str(),1+out.dZLFT/out.ZLFT);

    fprintf(pfile,"CMS_scale_j_%s         lnN  1.20        1.03          1.08          -            -              -         -          1.15            1.10    Jet scale\n", rootS.c_str());
    fprintf(pfile,"CMS_scale_met_%s       lnN  1.05        1.05          1.05          -            -              -      1.05       1.10            1.10    Met scale\n", rootS.c_str());

    fprintf(pfile,"pdf_qqbar            lnN -     -          1.08          -            -              -        -         -          -            -    PDF VBF\n");
    fprintf(pfile,"pdf_gg               lnN -     1.08       -             -            -              -        -         -          -            -    PDF GGH\n");
    fprintf(pfile,"pdf_vh               lnN 1.08   -         -             -            -              -        -         -          -            -    PDF GGH\n");
    fprintf(pfile,"QCDscale_ggH2in      lnN  -   1.30        -         -            -              -        -         -          -            -    QCD scale \n");
    fprintf(pfile,"QCDscale_qqH         lnN  -    -          1.04         -            -              -        -         -          -            -    QCD scale VBF\n");
    fprintf(pfile,"UEPS                 lnN  1.04    1.04       1.04          -            -              -        -         -          -            -    UEPS VBF\n");
    fclose(pfile);
    }
  
 

  }




  void makeSMEMuDataCardVBF(BkgOutput out,std::string postfix) {
    for(unsigned int m = 0;m<smMassesDC_.size();++m) {
      FILE *pfile = fopen(("datacards/"+channel_+postfix+"_mH"+smMassesDC_[m]+".txt").c_str(),"w");

      fprintf(pfile,"imax 1\n");
      fprintf(pfile,"jmax *\n");
      fprintf(pfile,"kmax *\n");
      fprintf(pfile,"shapes *  *    %s  $CHANNEL/$PROCESS $CHANNEL/$PROCESS_$SYSTEMATIC \n",(channel_+"SM.root").c_str());
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      fprintf(pfile,"observation %d\n",(int)out.DATA);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      std::string ch = channel_+postfix;
      fprintf(pfile,"bin            %s           %s            %s            %s            %s            %s            %s        \n",ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str());
      fprintf(pfile,"process   VH%s     ggH%s        qqH%s        ZTT           FAKES         TT            VV\n",smMassesDC_[m].c_str(),smMassesDC_[m].c_str(),smMassesDC_[m].c_str());
      fprintf(pfile,"process   -2     -1            0            1             2           3             4\n");
      fprintf(pfile,"rate      %.3f     %.3f          %.3f         %.3f          %.3f          %.3f       %.3f\n",
	     getYield("VH"+smMassesDC_[m],postfix),getYield("ggH"+smMassesDC_[m],postfix),getYield("qqH"+smMassesDC_[m],postfix),out.ZTT,out.QCD,out.TOP,out.VV);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      if(luminosityErr_!=0)
	fprintf(pfile,"lumi     lnN   %.3f    %.3f          %.3f          -             -             -             -          luminosity\n",
	   1+luminosityErr_,1+luminosityErr_,1+luminosityErr_);
      for(unsigned int j=0;j<shifts_.size();++j)
	fprintf(pfile,"%s    shape    1      1     1       1         -               -        -     -            shape(Ignore small ones that cause instabilities)\n",shiftsPostFix_[j].c_str());

      if(muID_!=0)
	fprintf(pfile,"CMS_eff_m     lnN   %.3f   %.3f          %.3f          %.3f          -             %.3f          %.3f       muon ID /HLT\n",
		1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_);
      if(tauID_!=0)
	fprintf(pfile,"CMS_eff_t     lnN   %.3f  %.3f          %.3f          %.3f          -             %.3f          %.3f        Tau IDf\n",
	       1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_);
      if(eleID_!=0)
	fprintf(pfile,"CMS_eff_e     lnN   %.3f   %.3f          %.3f          %.3f          -            %.3f           %.3f      Electron ID\n",
		1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_);
      if(zttScale_!=0)
	fprintf(pfile,"CMS_htt_zttNorm lnN   -  -             -             %.3f          -              -              -         ZTT Scale  \n",
		1+zttScaleErr_/zttScale_);
    /////////FIXPOINT
      fprintf(pfile,"CMS_htt_ztt_extrap_vbf lnN  -     -          -             %.3f          -            -              -         ZTT Extrapolation  \n",
	      1+out.dZTTCORR/out.ZTTCORR);
    fprintf(pfile,"CMS_htt_ttbarNorm          lnN   -   -             -             -             -         %.3f           -      TTbar background  \n",1+out.dTOP/out.TOP);
    fprintf(pfile,"CMS_htt_DiBosonNorm        lnN   -   -             -             -             -          -              %.3f   DiBoson background \n",1+out.dVV/out.VV);
    fprintf(pfile,"CMS_htt_%s_FakeNorm        lnN   -   -             -             -             %.3f          -             -       FAKE Background\n",(channel_+postfix).c_str(),1+out.dQCD/out.QCD);

    fprintf(pfile,"CMS_scale_j         lnN  1.20        1.03          1.08          -            -              1.15            1.10    Jet scale\n");
    fprintf(pfile,"CMS_scale_met       lnN  1.05        1.05          1.05          -            -              1.10            1.10    Met scale\n");


    fprintf(pfile,"pdf_qqbar            lnN   -   -          1.08          -            -              -        -       PDF VBF\n");
    fprintf(pfile,"pdf_gg               lnN   -   1.08       -             -            -              -        -       PDF GGH\n");
    fprintf(pfile,"pdf_vh               lnN   1.08 -         -             -            -              -        -       PDF GGH\n");
    fprintf(pfile,"QCDscale_ggH2in      lnN   -   1.30       -         -            -              -        -           QCD scale \n");
    fprintf(pfile,"QCDscale_qqH         lnN   -   -          1.04         -            -              -        -        QCD scale VBF\n");
    fprintf(pfile,"UEPS                 lnN   1.04   1.04       1.04          -            -              -        -       UEPS VBF\n");
    fclose(pfile);
    }
  
 

  }







  void makeSMLTauDataCardBoost(BkgOutput out,std::string postfix) {
    for(unsigned int m = 0;m<smMassesDC_.size();++m) {
      FILE *pfile = fopen(("datacards/"+channel_+postfix+"_mH"+smMassesDC_[m]+".txt").c_str(),"w");

      fprintf(pfile,"imax 1\n");
      fprintf(pfile,"jmax *\n");
      fprintf(pfile,"kmax *\n");
      fprintf(pfile,"shapes *  *    %s  $CHANNEL/$PROCESS $CHANNEL/$PROCESS_$SYSTEMATIC \n",(channel_+"SM.root").c_str());
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      fprintf(pfile,"observation %d\n",(int)out.DATA);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      std::string ch = channel_+postfix;
      fprintf(pfile,"bin          %s             %s            %s            %s            %s            %s            %s            %s            %s\n",ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str());
      fprintf(pfile,"process   VH%s      ggH%s        qqH%s        ZTT           QCD           W             ZLL             TT            VV\n",smMassesDC_[m].c_str(),smMassesDC_[m].c_str(),smMassesDC_[m].c_str());
      fprintf(pfile,"process    -2       -1            0            1             2           3             4             5             6  \n");
      fprintf(pfile,"rate       %.3f    %.3f          %.3f          %.3f          %.3f          %.3f          %.3f          %.3f          %.3f\n",
	 getYield("VH"+smMassesDC_[m],postfix),getYield("ggH"+smMassesDC_[m],postfix),getYield("qqH"+smMassesDC_[m],postfix),out.ZTT,out.QCD,out.W,out.ZLFT,out.TOP,out.VV);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      if(luminosityErr_!=0)
	fprintf(pfile,"lumi     lnN   %.3f   %.3f          %.3f          -             -             -             -            -             -          luminosity\n",
	   1+luminosityErr_,1+luminosityErr_,1+luminosityErr_);

      for(unsigned int j=0;j<shifts_.size();++j)
	  fprintf(pfile,"%s    shape    1     1     1       1         -           -          -         -        -                 shape(Ignore small ones that cause instabilities)\n",shiftsPostFix_[j].c_str());

      if(muID_!=0)
	fprintf(pfile,"CMS_eff_m     lnN   %.3f    %.3f          %.3f          %.3f          -             -             %.3f            %.3f          %.3f       muon ID /HLT\n",
		1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_);
      if(tauID_!=0)
	fprintf(pfile,"CMS_eff_t     lnN   %.3f   %.3f          %.3f          %.3f          -             -             -                     %.3f          %.3f        Tau IDf\n",
	       1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_);
      if(eleID_!=0)
	fprintf(pfile,"CMS_eff_e       lnN %.3f    %.3f          %.3f          %.3f          -             -             %.3f               %.3f           %.3f      Electron ID\n",
		1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_);
      if(zttScale_!=0)
	fprintf(pfile,"CMS_htt_zttNorm lnN   -     -             -             %.3f          -             -             %.3f                    -              -         ZTT Scale  \n",
		1+zttScaleErr_/zttScale_,1+zttScaleErr_/zttScale_);

    /////////FIXPOINT
      fprintf(pfile,"CMS_htt_ztt_extrap_boost lnN    - -             -             %.3f          -             -                %.3f          -              -         ZTT Extrapolation  \n",
	      1+out.dZTTCORR/out.ZTTCORR,1+boostFactorZErr_/boostFactorZ_);
    fprintf(pfile,"CMS_htt_ttbarNorm          lnN   -   -             -             -             -             -             -                           %.3f           -      TTbar background  \n",1+out.dTOP/out.TOP);
    fprintf(pfile,"CMS_htt_DiBosonNorm        lnN    -  -             -             -             -             -             -                           -              %.3f   DiBoson background \n",1+out.dVV/out.VV);
    fprintf(pfile,"CMS_htt_%s_QCDSyst             lnN -       -             -             -             %.3f          -             -             -                            -      QCD Background\n",channel_.c_str(),1+out.dQCD/out.QCD);
    fprintf(pfile,"CMS_htt_W_extrap_boost           lnN -      -             -             -             -             %.3f          -             -                            -      W Extrapolation \n",1+boostFactorWErr_/boostFactorW_);
    fprintf(pfile,"CMS_htt_%s_WNorm                  lnN  -    -             -             -             -             %.3f          -             -              -              -      W Background \n",channel_.c_str(),1+out.dWCORR/out.WCORR);
    fprintf(pfile,"CMS_htt_ZLL                  lnN    -  -             -             -             -             -          %.3f           -              -      Z(l->tau)   background\n",1+out.dZLFT/out.ZLFT);

    fprintf(pfile,"CMS_scale_j         lnN  1.02        1.02          1.05          -            -              -         -          1.03            1.08    Jet scale\n");
    fprintf(pfile,"CMS_scale_met       lnN  1.05        1.05          1.05          -            -              -      1.05       1.07            1.06    Met scale\n");
    fprintf(pfile,"pdf_qqbar            lnN      -         -          1.08          -            -              -        -         -          -            -    PDF VBF\n");
    fprintf(pfile,"pdf_gg               lnN      -       1.08       -             -            -              -        -         -          -            -    PDF GGH\n");
    fprintf(pfile,"pdf_vh               lnN      1.08    -          -             -            -              -        -         -          -            -    PDF GGH\n");
    fprintf(pfile,"QCDscale_ggH1in      lnN     -        1.25       -         -            -              -        -         -          -            -    QCD scale \n");
    fprintf(pfile,"QCDscale_qqH         lnN      -        -          1.04         -            -              -        -         -          -            -    QCD scale VBF\n");
    fprintf(pfile,"UEPS                 lnN      1.04     1.04       1.04          -            -              -        -         -          -            -    UEPS VBF\n");
    fclose(pfile);
    }
  
 

  }






  void makeSMLTauDataCardVH(BkgOutput out,std::string postfix) {
    for(unsigned int m = 0;m<smMassesDC_.size();++m) {
      FILE *pfile = fopen(("datacards/"+channel_+postfix+"_mH"+smMassesDC_[m]+".txt").c_str(),"w");

      fprintf(pfile,"imax 1\n");
      fprintf(pfile,"jmax *\n");
      fprintf(pfile,"kmax *\n");
      fprintf(pfile,"shapes *  *    %s  $CHANNEL/$PROCESS $CHANNEL/$PROCESS_$SYSTEMATIC \n",(channel_+"SM.root").c_str());
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      fprintf(pfile,"observation %d\n",(int)out.DATA);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      std::string ch = channel_+postfix;
      fprintf(pfile,"bin          %s             %s            %s            %s            %s            %s            %s            %s            %s\n",ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str());
      fprintf(pfile,"process   VH%s      ggH%s        qqH%s        ZTT           QCD           W             ZLL             TT            VV\n",smMassesDC_[m].c_str(),smMassesDC_[m].c_str(),smMassesDC_[m].c_str());
      fprintf(pfile,"process    -2       -1            0            1             2           3             4             5             6  \n");
      fprintf(pfile,"rate       %.3f    %.3f          %.3f          %.3f          %.3f          %.3f          %.3f          %.3f          %.3f\n",
	 getYield("VH"+smMassesDC_[m],postfix),getYield("ggH"+smMassesDC_[m],postfix),getYield("qqH"+smMassesDC_[m],postfix),out.ZTT,out.QCD,out.W,out.ZLFT,out.TOP,out.VV);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      if(luminosityErr_!=0)
	fprintf(pfile,"lumi     lnN   %.3f   %.3f          %.3f          -             -             -             -            -             -          luminosity\n",
	   1+luminosityErr_,1+luminosityErr_,1+luminosityErr_);

      for(unsigned int j=0;j<shifts_.size();++j)
	  fprintf(pfile,"%s    shape    1     1     1       1         -           -          -         -        -                 shape(Ignore small ones that cause instabilities)\n",shiftsPostFix_[j].c_str());
      if(muID_!=0)
	fprintf(pfile,"CMS_eff_m     lnN   %.3f    %.3f          %.3f          %.3f          -             -             %.3f            %.3f          %.3f       muon ID /HLT\n",
		1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_);
      if(tauID_!=0)
	fprintf(pfile,"CMS_eff_t     lnN   %.3f   %.3f          %.3f          %.3f          -             -             -                     %.3f          %.3f        Tau IDf\n",
	       1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_);
      if(eleID_!=0)
	fprintf(pfile,"CMS_eff_e       lnN %.3f    %.3f          %.3f          %.3f          -             -             %.3f               %.3f           %.3f      Electron ID\n",
		1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_);
      if(zttScale_!=0)
	fprintf(pfile,"CMS_htt_zttNorm lnN   -     -             -             %.3f          -             -             %.3f                    -              -         ZTT Scale  \n",
		1+zttScaleErr_/zttScale_,1+zttScaleErr_/zttScale_);

    /////////FIXPOINT
      fprintf(pfile,"CMS_htt_ztt_extrap_vh lnN    - -             -             %.3f          -             -                %.3f          -              -         ZTT Extrapolation  \n",
	      1+out.dZTTCORR/out.ZTTCORR,1+vhFactorZErr_/vhFactorZ_);
    fprintf(pfile,"CMS_htt_ttbarNorm          lnN   -   -             -             -             -             -             -                           %.3f           -      TTbar background  \n",1+out.dTOP/out.TOP);
    fprintf(pfile,"CMS_htt_DiBosonNorm        lnN    -  -             -             -             -             -             -                           -              %.3f   DiBoson background \n",1+out.dVV/out.VV);
    fprintf(pfile,"CMS_htt_%s_QCDSyst             lnN -       -             -             -             %.3f          -             -             -                            -      QCD Background\n",channel_.c_str(),1+out.dQCD/out.QCD);
    fprintf(pfile,"CMS_htt_W_extrap_boost           lnN -      -             -             -             -             %.3f          -             -                            -      W Extrapolation \n",1+vhFactorWErr_/vhFactorW_);
    fprintf(pfile,"CMS_htt_%s_WNorm                  lnN  -    -             -             -             -             %.3f          -             -              -              -      W Background \n",channel_.c_str(),1+out.dWCORR/out.WCORR);
    fprintf(pfile,"CMS_htt_ZLL                  lnN    -  -             -             -             -             -          %.3f           -              -      Z(l->tau)   background\n",1+out.dZLFT/out.ZLFT);

    fprintf(pfile,"CMS_scale_j         lnN  1.04        1.07          1.04          -            -              -         -          1.02            1.02    Jet scale\n");
    fprintf(pfile,"CMS_scale_met       lnN  1.05        1.05          1.05          -            -              -      1.05       1.06            1.04    Met scale\n");
    fprintf(pfile,"pdf_qqbar            lnN      -         -          1.08          -            -              -        -         -          -            -    PDF VBF\n");
    fprintf(pfile,"pdf_gg               lnN      -       1.08       -             -            -              -        -         -          -            -    PDF GGH\n");
    fprintf(pfile,"pdf_vh               lnN      1.08    -          -             -            -              -        -         -          -            -    PDF GGH\n");
    fprintf(pfile,"QCDscale_ggH1in      lnN     -        1.25       -         -            -              -        -         -          -            -    QCD scale \n");
    fprintf(pfile,"QCDscale_qqH         lnN      -        -          1.04         -            -              -        -         -          -            -    QCD scale VBF\n");
    fprintf(pfile,"UEPS                 lnN      1.04     1.04       1.04          -            -              -        -         -          -            -    UEPS VBF\n");
    fclose(pfile);
    }
  
 

  }




  void makeSMEMuDataCardBoost(BkgOutput out,std::string postfix) {
    for(unsigned int m = 0;m<smMassesDC_.size();++m) {
      FILE *pfile = fopen(("datacards/"+channel_+postfix+"_mH"+smMassesDC_[m]+".txt").c_str(),"w");

      fprintf(pfile,"imax 1\n");
      fprintf(pfile,"jmax *\n");
      fprintf(pfile,"kmax *\n");
      fprintf(pfile,"shapes *  *    %s  $CHANNEL/$PROCESS $CHANNEL/$PROCESS_$SYSTEMATIC \n",(channel_+"SM.root").c_str());
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      fprintf(pfile,"observation %d\n",(int)out.DATA);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      std::string ch = channel_+postfix;
      fprintf(pfile,"bin            %s               %s            %s            %s            %s            %s            %s\n",ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str());
      fprintf(pfile,"process        VH%s           ggH%s        qqH%s        ZTT           FAKES         TT            VV\n",smMassesDC_[m].c_str(),smMassesDC_[m].c_str(),smMassesDC_[m].c_str());
      fprintf(pfile,"process        -2              -1            0            1             2           3             4       \n");
      fprintf(pfile,"rate           %.3f            %.3f          %.3f          %.3f          %.3f          %.3f          %.3f\n",
	     getYield("VH"+smMassesDC_[m],postfix),getYield("ggH"+smMassesDC_[m],postfix),getYield("qqH"+smMassesDC_[m],postfix),out.ZTT,out.QCD,out.TOP,out.VV);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      if(luminosityErr_!=0)
	fprintf(pfile,"lumi     lnN   %.3f     %.3f          %.3f          -             -             -             -     luminosity\n",
	   1+luminosityErr_,1+luminosityErr_,1+luminosityErr_);
      for(unsigned int j=0;j<shifts_.size();++j)
	fprintf(pfile,"%s    shape    1    1     1       -         -           -    -                shape(Ignore small ones that cause instabilities)\n",shiftsPostFix_[j].c_str());

      if(muID_!=0)
	fprintf(pfile,"CMS_eff_m     lnN   %.3f    %.3f          %.3f          %.3f          -                 %.3f          %.3f       muon ID /HLT\n",
		1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_);
      if(eleID_!=0)
	fprintf(pfile,"CMS_eff_e       lnN   %.3f   %.3f          %.3f          %.3f          -               %.3f           %.3f      Electron ID\n",
		1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_);
      if(zttScale_!=0)
	fprintf(pfile,"CMS_htt_zttNorm lnN   -      -             -             %.3f          -                      -              -         ZTT Scale  \n",
		1+zttScaleErr_/zttScale_);

    fprintf(pfile,"CMS_scale_j         lnN  1.02        1.02          1.05          -            -              1.03            1.08    Jet scale\n");
    fprintf(pfile,"CMS_scale_met       lnN  1.05        1.05          1.05          -            -              1.07            1.06    Met scale\n");

    /////////FIXPOINT
      fprintf(pfile,"CMS_htt_ztt_extrap_boost lnN   -    -             -             %.3f          -               -              -         ZTT Extrapolation  \n",
	      1+out.dZTTCORR/out.ZTTCORR);
    fprintf(pfile,"CMS_htt_ttbarNorm          lnN   -   -             -             -             -            %.3f           -      TTbar background  \n",1+out.dTOP/out.TOP);
    fprintf(pfile,"CMS_htt_DiBosonNorm        lnN   -   -             -             -             -             -              %.3f   DiBoson background \n",1+out.dVV/out.VV);
    fprintf(pfile,"CMS_htt_%s_FakeNorm        lnN  -     -             -             -             %.3f          -             -     Fake  Background\n",channel_.c_str(),1+qcdFactorErr_/qcdFactor_);
    fprintf(pfile,"pdf_qqbar            lnN     -   -          1.08          -            -             -            -    PDF VBF\n");
    fprintf(pfile,"pdf_gg               lnN    -    1.08       -             -            -             -            -    PDF GGH\n");
    fprintf(pfile,"pdf_vh               lnN    1.08 -          -             -            -             -            -    PDF GGH\n");
    fprintf(pfile,"QCDscale_ggH1in      lnN   -    1.25       -         -            -                 -            -    QCD scale \n");
    fprintf(pfile,"QCDscale_qqH         lnN   -     -          1.04         -            -              -            -    QCD scale VBF\n");
    fprintf(pfile,"UEPS                 lnN   1.04   1.04       1.04          -            -             -            -    UEPS VBF\n");
    fclose(pfile);
    }
  
 

  }







  void makeSMEMuDataCardVH(BkgOutput out,std::string postfix) {
    for(unsigned int m = 0;m<smMassesDC_.size();++m) {
      FILE *pfile = fopen(("datacards/"+channel_+postfix+"_mH"+smMassesDC_[m]+".txt").c_str(),"w");

      fprintf(pfile,"imax 1\n");
      fprintf(pfile,"jmax *\n");
      fprintf(pfile,"kmax *\n");
      fprintf(pfile,"shapes *  *    %s  $CHANNEL/$PROCESS $CHANNEL/$PROCESS_$SYSTEMATIC \n",(channel_+"SM.root").c_str());
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      fprintf(pfile,"observation %d\n",(int)out.DATA);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      std::string ch = channel_+postfix;
      fprintf(pfile,"bin            %s               %s            %s            %s            %s            %s            %s\n",ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str());
      fprintf(pfile,"process        VH%s           ggH%s        qqH%s        ZTT           FAKES         TT            VV\n",smMassesDC_[m].c_str(),smMassesDC_[m].c_str(),smMassesDC_[m].c_str());
      fprintf(pfile,"process        -2              -1            0            1             2           3             4       \n");
      fprintf(pfile,"rate           %.3f            %.3f          %.3f          %.3f          %.3f          %.3f          %.3f\n",
	     getYield("VH"+smMassesDC_[m],postfix),getYield("ggH"+smMassesDC_[m],postfix),getYield("qqH"+smMassesDC_[m],postfix),out.ZTT,out.QCD,out.TOP,out.VV);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      if(luminosityErr_!=0)
	fprintf(pfile,"lumi     lnN   %.3f     %.3f          %.3f          -             -             -             -     luminosity\n",
	   1+luminosityErr_,1+luminosityErr_,1+luminosityErr_);
      for(unsigned int j=0;j<shifts_.size();++j)
	fprintf(pfile,"%s    shape    1    1     1       -         -           -    -                shape(Ignore small ones that cause instabilities)\n",shiftsPostFix_[j].c_str());

      if(muID_!=0)
	fprintf(pfile,"CMS_eff_m     lnN   %.3f    %.3f          %.3f          %.3f          -                 %.3f          %.3f       muon ID /HLT\n",
		1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_);
      if(eleID_!=0)
	fprintf(pfile,"CMS_eff_e       lnN   %.3f   %.3f          %.3f          %.3f          -               %.3f           %.3f      Electron ID\n",
		1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_);
      if(zttScale_!=0)
	fprintf(pfile,"CMS_htt_zttNorm lnN   -      -             -             %.3f          -                      -              -         ZTT Scale  \n",
		1+zttScaleErr_/zttScale_);

    /////////FIXPOINT
      fprintf(pfile,"CMS_htt_ztt_extrap_vh lnN   -    -             -             %.3f          -               -              -         ZTT Extrapolation  \n",
	      1+out.dZTTCORR/out.ZTTCORR);
    fprintf(pfile,"CMS_htt_ttbarNorm          lnN   -   -             -             -             -            %.3f           -      TTbar background  \n",1+out.dTOP/out.TOP);
    fprintf(pfile,"CMS_htt_DiBosonNorm        lnN   -   -             -             -             -             -              %.3f   DiBoson background \n",1+out.dVV/out.VV);
    fprintf(pfile,"CMS_htt_%s_FakeNorm        lnN  -     -             -             -             %.3f          -             -     Fake  Background\n",channel_.c_str(),1+qcdFactorErr_/qcdFactor_);


    fprintf(pfile,"CMS_scale_j         lnN  1.04        1.07          1.04          -            -             1.02            1.02    Jet scale\n");
    fprintf(pfile,"CMS_scale_met       lnN  1.05        1.05          1.05          -            -             1.06            1.04    Met scale\n");

    fprintf(pfile,"pdf_qqbar            lnN     -   -          1.08          -            -             -            -    PDF VBF\n");
    fprintf(pfile,"pdf_gg               lnN    -    1.08       -             -            -             -            -    PDF GGH\n");
    fprintf(pfile,"pdf_vh               lnN    1.08 -          -             -            -             -            -    PDF GGH\n");
    fprintf(pfile,"QCDscale_ggH1in      lnN   -    1.25       -         -            -                 -            -    QCD scale \n");
    fprintf(pfile,"QCDscale_qqH         lnN   -     -          1.04         -            -              -            -    QCD scale VBF\n");
    fprintf(pfile,"UEPS                 lnN   1.04   1.04       1.04          -            -             -            -    UEPS VBF\n");
    fclose(pfile);
    }
  
 

  }




  void makeMSSMLTauDataCardBTagged(BkgOutput out,std::string postfix) {
    for(unsigned int m = 0;m<mssmMasses_.size();++m) {
      FILE *pfile = fopen(("datacards/"+channel_+postfix+"_mA"+mssmMasses_[m]+".txt").c_str(),"w");

      fprintf(pfile,"imax 1\n");
      fprintf(pfile,"jmax *\n");
      fprintf(pfile,"kmax *\n");
      fprintf(pfile,"shapes *  *    %s  $CHANNEL/$PROCESS $CHANNEL/$PROCESS_$SYSTEMATIC \n",(channel_+".root").c_str());
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      fprintf(pfile,"observation %d\n",(int)out.DATA);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      std::string ch = channel_+postfix;
      fprintf(pfile,"bin            %s            %s            %s            %s            %s            %s             %s            %s\n",ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str());
      fprintf(pfile,"process        GGH%s        BBH%s        ZTT           QCD           W             ZLL             TT            VV\n",mssmMasses_[m].c_str(),mssmMasses_[m].c_str());
      fprintf(pfile,"process        -1            0             1             2             3             4             5              6\n");
      fprintf(pfile,"rate           %.3f          %.3f          %.3f          %.3f          %.3f          %.3f          %.3f          %.3f\n",
	      getYield("GGH"+mssmMasses_[m],postfix),getYield("BBH"+mssmMasses_[m],postfix),out.ZTT,out.QCD,out.W,out.ZLFT,out.TOP,out.VV);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      if(luminosityErr_!=0)
	fprintf(pfile,"lumi     lnN   %.3f          %.3f          -             -             -             -             -              -          luminosity\n",
	   1+luminosityErr_,1+luminosityErr_);
      
      if(muID_!=0)
	fprintf(pfile,"CMS_eff_m     lnN   %.3f          %.3f          %.3f          -             -             %.3f          %.3f          %.3f       muon ID /HLT\n",
	       1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_);
      if(tauID_!=0)
	fprintf(pfile,"CMS_eff_t    lnN   %.3f          %.3f          %.3f          -             -             -             -             %.3f        Tau IDf\n",
	       1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_,1+tauIDErr_/tauID_);
    if(eleID_!=0)
      fprintf(pfile,"CMS_eff_e    lnN   %.3f          %.3f          %.3f          -             -             %.3f          %.3f          %.3f                 Electron ID\n",
	     1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_);
    if(zttScale_!=0)
      fprintf(pfile,"CMS_htt_zttNorm lnN   -             -             %.3f          -             -             %.3f          %.3f          -                 ZTT Scale  \n",
	     1+zttScaleErr_/zttScale_,1+zttScaleErr_/zttScale_,1+zttScaleErr_/zttScale_);
    //FIXPOINTTTT
    fprintf(pfile,"CMS_htt_ztt_extrap_btag lnN   -             -             %.3f          -             -             %.3f        -          -         ZTT Extrapolation\n", 1+out.dZTTCORR/out.ZTTCORR,1+bFactorZErr_/bFactorZ_);
    fprintf(pfile,"CMS_htt_w_extrap_btag lnN   -             -                -             -            %.3f          -             -          -       W Extrapolation\n", 1+bFactorWErr_/bFactorW_);
    fprintf(pfile,"CMS_htt_ttbarNorm  lnN      -             -             -             -             -             -             %.3f           -      TTbar background  \n",1+out.dTOP/out.TOP);
    fprintf(pfile,"CMS_htt_DiBosonNorm  lnN      -             -             -             -             -             -             -            %.3f   DiBoson background \n",1+out.dVV/out.VV);
    fprintf(pfile,"CMS_htt_%s_ZLLTNorm  lnN      -             -             -             -             -               %.3f           -              -      Z(l->tau)   background\n",(channel_+postfix).c_str(),1+out.dZLFT/out.ZLFT);

    for(unsigned int j=0;j<shifts_.size();++j)
      fprintf(pfile,"%s    shape    1             1             1            -             -             -             -              -      shape\n",shiftsPostFix_[j].c_str());

    fprintf(pfile,"CMS_htt_%s_QCDNorm  lnN         -             -             -             %.3f          -             -             -                          -      QCD Background\n",(channel_+postfix).c_str(),1+out.dQCD/out.QCD);
    fprintf(pfile,"CMS_htt_%s_WNorm    lnN      -             -             -             -             %.3f          -             -                         -      W Backghround \n",channel_.c_str(),1+out.dWCORR/out.WCORR);

    fprintf(pfile,"CMS_eff_b      lnN      -             %.3f          -             -             -             -                         %.3f           -     BTag efficiency \n",1+bIDErr_/bID_,1+bIDErr_/bID_);
    fprintf(pfile,"CMS_fake_b      lnN      %.3f          -             -             -             -             -                       -              -     BTag MisTag \n",1+bMisIDErr_/bMisID_);


    fprintf(pfile,"CMS_scale_j      lnN     1.04           1.02             -             -             -             -                       1.10              1.03     Jet Scale \n");
    fprintf(pfile,"CMS_scale_met    lnN     1.05           1.05             -             -             -             -                       1.01              1.03     MET SCale \n");

    fclose(pfile);
    }

  }




  void makeMSSMEMuDataCardBTagged(BkgOutput out,std::string postfix) {
    for(unsigned int m = 0;m<mssmMasses_.size();++m) {
      FILE *pfile = fopen(("datacards/"+channel_+postfix+"_mA"+mssmMasses_[m]+".txt").c_str(),"w");

      fprintf(pfile,"imax 1\n");
      fprintf(pfile,"jmax *\n");
      fprintf(pfile,"kmax *\n");
      fprintf(pfile,"shapes *  *    %s  $CHANNEL/$PROCESS $CHANNEL/$PROCESS_$SYSTEMATIC \n",(channel_+".root").c_str());
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      fprintf(pfile,"observation %d\n",(int)out.DATA);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      std::string ch = channel_+postfix;
      fprintf(pfile,"bin            %s            %s            %s            %s            %s            %s\n",ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str(),ch.c_str());
      fprintf(pfile,"process        GGH%s        BBH%s        ZTT           FAKES           TT            VV\n",mssmMasses_[m].c_str(),mssmMasses_[m].c_str());
      fprintf(pfile,"process        -1            0             1             2             3             4 \n");
      fprintf(pfile,"rate           %.3f          %.3f          %.3f          %.3f          %.3f          %.3f\n",
	      getYield("GGH"+mssmMasses_[m],postfix),getYield("BBH"+mssmMasses_[m],postfix),out.ZTT,out.QCD,out.TOP,out.VV);
      fprintf(pfile,"------------------------------------------------------------------------------------------------------------------------------------\n");
      if(luminosityErr_!=0)
	fprintf(pfile,"lumi     lnN   %.3f          %.3f          -             -             -             -             -              -          luminosity\n",
	   1+luminosityErr_,1+luminosityErr_);
      
      if(muID_!=0)
	fprintf(pfile,"CMS_eff_m     lnN   %.3f          %.3f          %.3f          -             %.3f          %.3f     muon ID /HLT\n",
	       1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_,1+muIDErr_/muID_);
      if(eleID_!=0)
	fprintf(pfile,"CMS_eff_e    lnN   %.3f          %.3f          %.3f          -              %.3f          %.3f              Electron ID\n",
	     1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_,1+eleIDErr_/eleID_);
    if(zttScale_!=0)
      fprintf(pfile,"CMS_htt_zttNorm lnN   -             -             %.3f          -             %.3f          %.3f     ZTT Scale  \n",
	     1+zttScaleErr_/zttScale_,1+zttScaleErr_/zttScale_,1+zttScaleErr_/zttScale_);
    //FIXPOINTTTT
    fprintf(pfile,"CMS_htt_ztt_extrap_btag lnN   -             -             %.3f          -       -          -         ZTT Extrapolation\n", 1+out.dZTTCORR/out.ZTTCORR);
    fprintf(pfile,"CMS_htt_ttbarNorm  lnN      -             -             -             -         %.3f           -      TTbar background  \n",1+out.dTOP/out.TOP);
    fprintf(pfile,"CMS_htt_DiBosonNorm  lnN     -             -             -             -             -         %.3f   DiBoson background \n",1+out.dVV/out.VV);
    for(unsigned int j=0;j<shifts_.size();++j)
      fprintf(pfile,"%s    shape    1             1             1             -             -             -       shape\n",shiftsPostFix_[j].c_str());
    fprintf(pfile,"CMS_htt_%s_FakeNorm  lnN        -             -            -             %.3f          -             -          QCD Background\n",(channel_+postfix).c_str(),1+out.dQCD/out.QCD);
    fprintf(pfile,"CMS_eff_b      lnN      -             %.3f          -             -                 %.3f           -     BTag efficiency \n",1+bIDErr_/bID_,1+bIDErr_/bID_);
    fprintf(pfile,"CMS_fake_b      lnN      %.3f          -             -             -             -             -      BTag MisTag \n",1+bMisIDErr_/bMisID_);

    fprintf(pfile,"CMS_scale_j      lnN     1.04           1.02             -             -            1.10              1.03     Jet Scale \n");
    fprintf(pfile,"CMS_scale_met    lnN     1.05           1.05             -             -            1.01              1.03     MET SCale \n");


    fclose(pfile);
    }

  }




