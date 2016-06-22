#include "PhysicsTools/FWLite/interface/CommandLineParser.h" 
#include "TFile.h"
#include "TROOT.h"
#include "TKey.h"
#include "TTree.h"
#include "TH1F.h"
#include "TF1.h"
#include "TH2F.h"
#include <math.h> 
#include "TMath.h" 
#include <limits>

enum Variation {
    CENTRAL,
    STAT_UP,
    STAT_DOWN,
    SYST_TAG_PT30,
    SYST_CMSSHAPE,
    EFF_DATA,
    EFF_DATA_ERRSYM,
    EFF_MC,
    EFF_MC_ERRSYM,
};
float HTTID(float probe_pt, float probe_abseta, bool passingHTTID, Variation variation) {
    if ( variation == Variation::STAT_UP && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.923392;
    if ( variation == Variation::CENTRAL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.916341;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.006293;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.909545;
    if ( variation == Variation::EFF_MC && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.979078;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.000530;
    if ( variation == Variation::EFF_DATA && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.897170;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.918259;

    if ( variation == Variation::STAT_UP && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.952154;
    if ( variation == Variation::CENTRAL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.932361;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.018679;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.910640;
    if ( variation == Variation::EFF_MC && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.953344;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.001192;
    if ( variation == Variation::EFF_DATA && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.888860;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.930342;

    if ( variation == Variation::STAT_UP && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.872391;
    if ( variation == Variation::CENTRAL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.869055;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.002730;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.865733;
    if ( variation == Variation::EFF_MC && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.968614;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.000569;
    if ( variation == Variation::EFF_DATA && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.841780;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.891601;

    if ( variation == Variation::STAT_UP && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.948041;
    if ( variation == Variation::CENTRAL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.946662;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.001216;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.945285;
    if ( variation == Variation::EFF_MC && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.990367;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.000157;
    if ( variation == Variation::EFF_DATA && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.937543;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.946331;

    if ( variation == Variation::STAT_UP && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.961475;
    if ( variation == Variation::CENTRAL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.958808;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.002325;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.956124;
    if ( variation == Variation::EFF_MC && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.987806;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.000332;
    if ( variation == Variation::EFF_DATA && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.947116;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.958904;

    if ( variation == Variation::STAT_UP && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.963871;
    if ( variation == Variation::CENTRAL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.962136;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.001576;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.960388;
    if ( variation == Variation::EFF_MC && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.992669;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.000158;
    if ( variation == Variation::EFF_DATA && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.955083;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.962357;

    if ( variation == Variation::STAT_UP && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.951828;
    if ( variation == Variation::CENTRAL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.951176;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.000560;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.950524;
    if ( variation == Variation::EFF_MC && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.991616;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.000091;
    if ( variation == Variation::EFF_DATA && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.943201;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.950938;

    if ( variation == Variation::STAT_UP && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.966431;
    if ( variation == Variation::CENTRAL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.965249;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.001030;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.964016;
    if ( variation == Variation::EFF_MC && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.992330;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.000174;
    if ( variation == Variation::EFF_DATA && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.957845;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.963467;

    if ( variation == Variation::STAT_UP && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.971716;
    if ( variation == Variation::CENTRAL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.970952;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.000673;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.970191;
    if ( variation == Variation::EFF_MC && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.995195;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.000089;
    if ( variation == Variation::EFF_DATA && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.966287;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.970596;

    if ( variation == Variation::STAT_UP && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.954444;
    if ( variation == Variation::CENTRAL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.953936;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.000423;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.953430;
    if ( variation == Variation::EFF_MC && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.992108;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.000084;
    if ( variation == Variation::EFF_DATA && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.946408;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.953805;

    if ( variation == Variation::STAT_UP && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.970528;
    if ( variation == Variation::CENTRAL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.969743;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.000639;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.968962;
    if ( variation == Variation::EFF_MC && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.993127;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.000143;
    if ( variation == Variation::EFF_DATA && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.963078;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.969593;

    if ( variation == Variation::STAT_UP && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.977632;
    if ( variation == Variation::CENTRAL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.977127;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.000430;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.976624;
    if ( variation == Variation::EFF_MC && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.995905;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.000074;
    if ( variation == Variation::EFF_DATA && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.973126;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.976753;

    if ( variation == Variation::STAT_UP && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.954821;
    if ( variation == Variation::CENTRAL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.952847;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.001733;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.951050;
    if ( variation == Variation::EFF_MC && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.991572;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.000143;
    if ( variation == Variation::EFF_DATA && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.944816;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTID) ) return 0.950470;

    if ( variation == Variation::STAT_UP && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.963099;
    if ( variation == Variation::CENTRAL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.961507;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.001326;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.959900;
    if ( variation == Variation::EFF_MC && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.990833;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.000269;
    if ( variation == Variation::EFF_DATA && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.952693;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.960150;

    if ( variation == Variation::STAT_UP && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.969182;
    if ( variation == Variation::CENTRAL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.968070;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.000952;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.966962;
    if ( variation == Variation::EFF_MC && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.993026;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.000155;
    if ( variation == Variation::EFF_DATA && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.961319;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTID) ) return 0.967778;

    return 1.; // Default
}

float HTTISO(float probe_pt, float probe_abseta, bool passingHTTIsoTight, bool passingHTTID, Variation variation) {
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.988846;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.974635;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.006932;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.964570;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.706992;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.001689;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.689059;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.974593;

    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.994681;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.981458;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.007507;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.968132;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.749629;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.002491;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.735729;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.980981;

    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.982065;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.975729;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.003899;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.969421;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.814677;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.001283;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.794904;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.977055;

    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.980594;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.978439;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.001234;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.976288;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.840330;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.000588;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.822211;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.985173;

    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 1.009009;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.985279;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.015099;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.971276;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.855957;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.001060;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.843357;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.992538;

    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.988148;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.986202;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.001182;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.984261;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.895197;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.000566;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.882844;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.987847;

    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.992288;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.991271;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.000680;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.990256;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.925477;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.000262;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.917399;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.991195;

    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 1.000093;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.998428;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.001033;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.996769;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.928704;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.000511;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.927245;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.998955;

    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.997490;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.996413;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.000744;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.995338;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.949775;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.000279;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.946368;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.996117;

    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.994396;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.993744;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.000458;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.993093;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.966123;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.000172;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.960079;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.993391;

    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.996271;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.995338;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.000616;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.994408;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.971121;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.000290;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.966593;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.995225;

    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.998255;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.997734;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.000348;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.997214;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.979736;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.000163;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.977516;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.997707;

    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.996686;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.995806;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.000636;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.994920;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.978202;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.000229;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.974100;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.994569;

    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.998476;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.997115;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.000967;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.995730;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.981362;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.000382;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.978531;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.997258;

    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.999450;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.998601;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.000625;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.997746;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.986424;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.000216;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.985044;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.998446;

    return 1.; // Default
}



void readdir(TDirectory *dir,optutl::CommandLineParser parser, TH2F* hist); 



int main (int argc, char* argv[]) 
{
   optutl::CommandLineParser parser ("Sets Event Weights in the ntuple");
   parser.addOption("branch",optutl::CommandLineParser::kString,"Trigger Branch","__TRIGGER__");
   parser.addOption("IDISObranch",optutl::CommandLineParser::kString,"Branch ID/ISO weights","__ISO__");
   parser.addOption("mutrigfile",optutl::CommandLineParser::kString,"File","IsoMu20.root");
   parser.addOption("eletrigfile",optutl::CommandLineParser::kString,"File","IsoMu20.root");
   parser.addOption("eta",optutl::CommandLineParser::kString,"eta variable","eta_1");
   parser.addOption("pt",optutl::CommandLineParser::kString,"pt variable","pt_1");
   parser.parseArguments (argc, argv);
  
   TFile *fTrig    = new TFile(parser.stringValue("mutrigfile").c_str(),"UPDATE");
   TH2F* hTrig = 0;
   if(fTrig!=0 && fTrig->IsOpen()) {
     hTrig = (TH2F*)fTrig->Get("probe_abseta_probe_pt_PLOT");;
     printf("ENABLING TRIG WEIGHTING USING HISTOGRAM\n");
   }
   else{
     printf("ERROR!!! WEIGHT FILE NOT FOUND!!! EXITING!!!\n");
     return 0;
   }
 
 
  
   TFile *f = new TFile(parser.stringValue("outputFile").c_str(),"UPDATE");
   readdir(f,parser,hTrig);
   f->Close();

   if(fTrig!=0 && fTrig->IsOpen())
     fTrig->Close();


} 


void readdir(TDirectory *dir,optutl::CommandLineParser parser, TH2F* hist) 
{
  TDirectory *dirsav = gDirectory;
  TIter next(dir->GetListOfKeys());
  TKey *key;
  while ((key = (TKey*)next())) {
    printf("Found key=%s \n",key->GetName());
    TObject *obj = key->ReadObj();

    if (obj->IsA()->InheritsFrom(TDirectory::Class())) {
      dir->cd(key->GetName());
      TDirectory *subdir = gDirectory;
      readdir(subdir,parser,hist);
      dirsav->cd();
    }
    else if(obj->IsA()->InheritsFrom(TTree::Class())) {
      TTree *t = (TTree*)obj;
      float weight = 1.0;
      float IDISOweight = 1.0;
      TBranch *newBranch = t->Branch(parser.stringValue("branch").c_str(),&weight,(parser.stringValue("branch")+"/F").c_str());
      TBranch *newIDISOBranch = t->Branch(parser.stringValue("IDISObranch").c_str(),&IDISOweight,(parser.stringValue("IDISObranch")+"/F").c_str());

      float pt;
      float eta;


      t->SetBranchAddress(parser.stringValue("eta").c_str(),&eta);
      t->SetBranchAddress(parser.stringValue("pt").c_str(),&pt);
	
      printf("Found tree -> weighting\n");
      for(Int_t i=0;i<t->GetEntries();++i)
	{
	  t->GetEntry(i);
	  weight=0.0;
	  IDISOweight=0.0;
	  float p=pt;
          float abseta = std::abs(eta);
	  if(p>200.) p=201.;

          IDISOweight = HTTID(p, abseta, true, Variation::CENTRAL) * HTTISO(p, abseta, true, true, Variation::CENTRAL);
          //printf ("ISOWEIGHT: %0.2f \n" , IDISOweight);
          //printf ("Getting eta: %0.2f pt: %0.2f in hist \n",abseta,p);
	  weight = hist->GetBinContent(hist->GetXaxis()->FindBin(abseta),hist->GetYaxis()->FindBin(p));
          //printf ("TRIG WEIGHT: %0.2f \n" , weight);
	  newBranch->Fill();
	  newIDISOBranch->Fill();
	}

      t->Write("",TObject::kOverwrite);
    }
  }
}

