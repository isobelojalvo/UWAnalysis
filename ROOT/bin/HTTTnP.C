/*
 * float weightMuTau(float pt1,float eta1) {
 *   return muHTTID(pt1,eta1)*muHTTISO(pt1,eta1);
 *
 *   }
 *
 *
 *
 *   float weightETau(float pt1,float eta1) {
 *     return eHTTID(pt1,eta1)*eHTTISO(pt1,eta1);
 *     }
 *
 *    //float eHTTID(float probe_Ele_pt, float probe_Ele_abseta, bool passingHTTID=true, Variation variation=Variation::CENTRAL) {
 */

enum Variation {
    CENTRAL,
    STAT_UP,
    STAT_DOWN,
    SYST_ALT_TEMPL,
    SYST_TAG_PT30,
    SYST_CMSSHAPE,
    EFF_DATA,
    EFF_DATA_ERRSYM,
    EFF_MC,
    EFF_MC_ERRSYM,
};

float mHTTID(float probe_pt, float probe_abseta, bool passingHTTID=true, Variation variation=Variation::CENTRAL) {
    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.888279;
    if ( variation == Variation::STAT_UP && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.907861;
    if ( variation == Variation::CENTRAL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.888359;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.017717;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.868988;
    if ( variation == Variation::EFF_MC && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.974755;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.001382;
    if ( variation == Variation::EFF_DATA && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.865932;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.893198;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.911156;
    if ( variation == Variation::STAT_UP && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.929724;
    if ( variation == Variation::CENTRAL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.910957;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.016211;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.892086;
    if ( variation == Variation::EFF_MC && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.967349;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.002187;
    if ( variation == Variation::EFF_DATA && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.881214;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.925989;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.907482;
    if ( variation == Variation::STAT_UP && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.927093;
    if ( variation == Variation::CENTRAL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.917166;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.018516;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.887822;
    if ( variation == Variation::EFF_MC && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.982687;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.000859;
    if ( variation == Variation::EFF_DATA && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.901287;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.907442;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.956626;
    if ( variation == Variation::STAT_UP && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.968999;
    if ( variation == Variation::CENTRAL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.956632;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.012347;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.942246;
    if ( variation == Variation::EFF_MC && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.980894;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.000809;
    if ( variation == Variation::EFF_DATA && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.938355;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.954890;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.931486;
    if ( variation == Variation::STAT_UP && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.952154;
    if ( variation == Variation::CENTRAL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.932361;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.018679;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.910640;
    if ( variation == Variation::EFF_MC && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.953344;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.001192;
    if ( variation == Variation::EFF_DATA && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.888860;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.930342;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.944985;
    if ( variation == Variation::STAT_UP && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.969056;
    if ( variation == Variation::CENTRAL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.945169;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.021309;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.922640;
    if ( variation == Variation::EFF_MC && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.957912;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.000975;
    if ( variation == Variation::EFF_DATA && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.905389;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.966123;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.901416;
    if ( variation == Variation::STAT_UP && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.905248;
    if ( variation == Variation::CENTRAL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.900450;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.004085;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.895677;
    if ( variation == Variation::EFF_MC && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.977558;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.000659;
    if ( variation == Variation::EFF_DATA && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.880242;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.901293;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.832959;
    if ( variation == Variation::STAT_UP && (probe_pt>=10 && probe_pt<20 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.847615;
    if ( variation == Variation::CENTRAL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.832737;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.013064;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=10 && probe_pt<20 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.818546;
    if ( variation == Variation::EFF_MC && (probe_pt>=10 && probe_pt<20 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.962734;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.001114;
    if ( variation == Variation::EFF_DATA && (probe_pt>=10 && probe_pt<20 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.801704;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=10 && probe_pt<20 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.838489;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.937763;
    if ( variation == Variation::STAT_UP && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.940681;
    if ( variation == Variation::CENTRAL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.938406;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.001895;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.936142;
    if ( variation == Variation::EFF_MC && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.987582;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.000369;
    if ( variation == Variation::EFF_DATA && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.926752;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.935529;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.933283;
    if ( variation == Variation::STAT_UP && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.937668;
    if ( variation == Variation::CENTRAL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.933296;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.003730;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.928874;
    if ( variation == Variation::EFF_MC && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.982118;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.000631;
    if ( variation == Variation::EFF_DATA && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.916606;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.932482;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.950816;
    if ( variation == Variation::STAT_UP && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.953020;
    if ( variation == Variation::CENTRAL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.950816;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.001991;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.948571;
    if ( variation == Variation::EFF_MC && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.993158;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.000230;
    if ( variation == Variation::EFF_DATA && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.944311;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.949871;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.959030;
    if ( variation == Variation::STAT_UP && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.961181;
    if ( variation == Variation::CENTRAL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.959033;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.001900;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.956868;
    if ( variation == Variation::EFF_MC && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.992534;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.000251;
    if ( variation == Variation::EFF_DATA && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.951872;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.958310;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.958807;
    if ( variation == Variation::STAT_UP && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.961475;
    if ( variation == Variation::CENTRAL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.958808;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.002325;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.956124;
    if ( variation == Variation::EFF_MC && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.987806;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.000332;
    if ( variation == Variation::EFF_DATA && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.947116;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.958904;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.979636;
    if ( variation == Variation::STAT_UP && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.978819;
    if ( variation == Variation::CENTRAL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.977442;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.001100;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.976073;
    if ( variation == Variation::EFF_MC && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.990398;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.000266;
    if ( variation == Variation::EFF_DATA && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.968056;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.979408;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.950794;
    if ( variation == Variation::STAT_UP && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.953113;
    if ( variation == Variation::CENTRAL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.950786;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.002134;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.948466;
    if ( variation == Variation::EFF_MC && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.994630;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.000186;
    if ( variation == Variation::EFF_DATA && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.945680;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.951430;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.905227;
    if ( variation == Variation::STAT_UP && (probe_pt>=20 && probe_pt<30 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.909771;
    if ( variation == Variation::CENTRAL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.905297;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.003898;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=20 && probe_pt<30 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.900890;
    if ( variation == Variation::EFF_MC && (probe_pt>=20 && probe_pt<30 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.978471;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.000494;
    if ( variation == Variation::EFF_DATA && (probe_pt>=20 && probe_pt<30 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.885807;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=20 && probe_pt<30 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.903340;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.937945;
    if ( variation == Variation::STAT_UP && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.939180;
    if ( variation == Variation::CENTRAL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.937908;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.001054;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.936641;
    if ( variation == Variation::EFF_MC && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.988665;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.000215;
    if ( variation == Variation::EFF_DATA && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.927276;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.937737;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.939533;
    if ( variation == Variation::STAT_UP && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.941650;
    if ( variation == Variation::CENTRAL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.939510;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.001777;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.937346;
    if ( variation == Variation::EFF_MC && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.984138;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.000363;
    if ( variation == Variation::EFF_DATA && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.924607;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.939043;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.953342;
    if ( variation == Variation::STAT_UP && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.954379;
    if ( variation == Variation::CENTRAL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.953320;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.000929;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.952264;
    if ( variation == Variation::EFF_MC && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.994457;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.000128;
    if ( variation == Variation::EFF_DATA && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.948036;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.953252;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.964527;
    if ( variation == Variation::STAT_UP && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.965383;
    if ( variation == Variation::CENTRAL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.964500;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.000736;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.963621;
    if ( variation == Variation::EFF_MC && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.993831;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.000144;
    if ( variation == Variation::EFF_DATA && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.958551;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.964370;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.965211;
    if ( variation == Variation::STAT_UP && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.966431;
    if ( variation == Variation::CENTRAL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.965249;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.001030;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.964016;
    if ( variation == Variation::EFF_MC && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.992330;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.000174;
    if ( variation == Variation::EFF_DATA && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.957845;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.963467;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.984553;
    if ( variation == Variation::STAT_UP && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.985539;
    if ( variation == Variation::CENTRAL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.984560;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.000853;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.983534;
    if ( variation == Variation::EFF_MC && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.993837;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.000145;
    if ( variation == Variation::EFF_DATA && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.978492;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.984146;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.959069;
    if ( variation == Variation::STAT_UP && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.960232;
    if ( variation == Variation::CENTRAL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.959408;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.000718;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.958587;
    if ( variation == Variation::EFF_MC && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.996447;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.000106;
    if ( variation == Variation::EFF_DATA && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.955999;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.959560;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.917806;
    if ( variation == Variation::STAT_UP && (probe_pt>=30 && probe_pt<40 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.920797;
    if ( variation == Variation::CENTRAL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.918363;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.002507;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=30 && probe_pt<40 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.915111;
    if ( variation == Variation::EFF_MC && (probe_pt>=30 && probe_pt<40 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.983290;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.000314;
    if ( variation == Variation::EFF_DATA && (probe_pt>=30 && probe_pt<40 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.903017;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=30 && probe_pt<40 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.918582;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.939468;
    if ( variation == Variation::STAT_UP && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.940811;
    if ( variation == Variation::CENTRAL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.939452;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.001106;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.938184;
    if ( variation == Variation::EFF_MC && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.989386;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.000205;
    if ( variation == Variation::EFF_DATA && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.929481;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.939422;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.940166;
    if ( variation == Variation::STAT_UP && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.943462;
    if ( variation == Variation::CENTRAL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.940117;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.002943;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.936800;
    if ( variation == Variation::EFF_MC && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.984087;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.000356;
    if ( variation == Variation::EFF_DATA && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.925157;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.940295;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.957034;
    if ( variation == Variation::STAT_UP && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.958269;
    if ( variation == Variation::CENTRAL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.957458;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.000693;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.956650;
    if ( variation == Variation::EFF_MC && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.994933;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.000117;
    if ( variation == Variation::EFF_DATA && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.952606;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.956621;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.966762;
    if ( variation == Variation::STAT_UP && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.967632;
    if ( variation == Variation::CENTRAL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.966814;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.000685;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.965999;
    if ( variation == Variation::EFF_MC && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.993872;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.000131;
    if ( variation == Variation::EFF_DATA && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.960889;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.966775;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.969784;
    if ( variation == Variation::STAT_UP && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.970528;
    if ( variation == Variation::CENTRAL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.969743;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.000639;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.968962;
    if ( variation == Variation::EFF_MC && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.993127;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.000143;
    if ( variation == Variation::EFF_DATA && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.963078;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.969593;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.986108;
    if ( variation == Variation::STAT_UP && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.986707;
    if ( variation == Variation::CENTRAL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.986105;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.000516;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.985440;
    if ( variation == Variation::EFF_MC && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.994804;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.000116;
    if ( variation == Variation::EFF_DATA && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.980981;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.985772;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.967710;
    if ( variation == Variation::STAT_UP && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.968482;
    if ( variation == Variation::CENTRAL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.967705;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.000707;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.966888;
    if ( variation == Variation::EFF_MC && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.997067;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.000090;
    if ( variation == Variation::EFF_DATA && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.964867;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.967362;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.920617;
    if ( variation == Variation::STAT_UP && (probe_pt>=40 && probe_pt<50 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.921926;
    if ( variation == Variation::CENTRAL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.920525;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.001097;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=40 && probe_pt<50 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.919131;
    if ( variation == Variation::EFF_MC && (probe_pt>=40 && probe_pt<50 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.985777;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.000305;
    if ( variation == Variation::EFF_DATA && (probe_pt>=40 && probe_pt<50 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.907433;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=40 && probe_pt<50 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.918055;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.942913;
    if ( variation == Variation::STAT_UP && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.945396;
    if ( variation == Variation::CENTRAL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.942924;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.002118;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.940435;
    if ( variation == Variation::EFF_MC && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.988524;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.000354;
    if ( variation == Variation::EFF_DATA && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.932103;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.939325;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.942523;
    if ( variation == Variation::STAT_UP && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.946156;
    if ( variation == Variation::CENTRAL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.942522;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.003017;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.938851;
    if ( variation == Variation::EFF_MC && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.983042;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.000609;
    if ( variation == Variation::EFF_DATA && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.926538;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.939113;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.950594;
    if ( variation == Variation::STAT_UP && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.952767;
    if ( variation == Variation::CENTRAL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.951370;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.001199;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.949981;
    if ( variation == Variation::EFF_MC && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.994745;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.000197;
    if ( variation == Variation::EFF_DATA && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.946371;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.950061;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.967608;
    if ( variation == Variation::STAT_UP && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.969333;
    if ( variation == Variation::CENTRAL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.967607;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.001519;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.965838;
    if ( variation == Variation::EFF_MC && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.993321;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.000225;
    if ( variation == Variation::EFF_DATA && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.961145;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.965549;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.961511;
    if ( variation == Variation::STAT_UP && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.963099;
    if ( variation == Variation::CENTRAL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.961507;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.001326;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.959900;
    if ( variation == Variation::EFF_MC && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.990833;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.000269;
    if ( variation == Variation::EFF_DATA && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.952693;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.960150;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.977301;
    if ( variation == Variation::STAT_UP && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.980231;
    if ( variation == Variation::CENTRAL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.977275;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.001914;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.975879;
    if ( variation == Variation::EFF_MC && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.990831;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.000247;
    if ( variation == Variation::EFF_DATA && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.968315;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.977783;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.955910;
    if ( variation == Variation::STAT_UP && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.958249;
    if ( variation == Variation::CENTRAL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.955905;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.001806;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.954269;
    if ( variation == Variation::EFF_MC && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.995395;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.000183;
    if ( variation == Variation::EFF_DATA && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.951503;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.954685;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.921912;
    if ( variation == Variation::STAT_UP && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.927549;
    if ( variation == Variation::CENTRAL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.921851;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.005079;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.916109;
    if ( variation == Variation::EFF_MC && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.981492;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.000581;
    if ( variation == Variation::EFF_DATA && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.904789;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.907525;

    return 1.; // Default
}


float mHTTISO(float probe_pt, float probe_abseta, bool passingHTTIsoTight=true, bool passingHTTID=true, Variation variation=Variation::CENTRAL) {
    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.970015;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.997043;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.970665;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.013244;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.945605;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.670475;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.004118;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.650807;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.969509;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.987027;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 1.048407;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.986968;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.035228;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.926606;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.671799;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.005755;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.663044;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.980381;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.967537;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.985004;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.967540;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.009345;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.950305;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.704704;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.002977;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.681829;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.967063;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.978742;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.993081;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.978795;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.007927;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.964530;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.733621;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.002601;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.718065;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.980676;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.981230;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.994681;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.981458;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.007507;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.968132;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.749629;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.002491;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.735729;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.980981;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.976726;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.986953;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.976973;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.005989;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.967027;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.795995;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.001987;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.777665;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.976557;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.975086;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.981420;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.974917;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.003746;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.968456;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.829974;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.001675;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.809156;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.978763;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.955379;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.965120;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.955407;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.006274;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.945655;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.852147;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.002113;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.814147;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.957660;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.981419;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.976728;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.972100;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.002650;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.967495;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.834177;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.001235;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.810903;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.980892;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.967952;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.971592;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.963603;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.004730;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.956256;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.837276;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.001753;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.806802;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.969563;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.987221;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.992450;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.987565;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.006489;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.974638;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.840274;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.001011;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.829826;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.987429;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.993567;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.998587;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.994808;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.002154;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.991046;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.846185;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.001042;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.841792;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.994067;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.991559;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 1.009009;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.985279;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.015099;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.971276;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.855957;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.001060;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.843357;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.992538;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.983241;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.986443;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.983222;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.001982;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.979989;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.881633;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.000878;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.866841;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.983480;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.987845;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.990639;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.987700;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.001914;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.984822;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.906861;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.000733;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.895706;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.985768;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.983499;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.985975;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.982571;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.002248;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.979142;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.921928;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.000918;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.905860;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.983972;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.987468;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.989231;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.987612;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.000964;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.985998;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.924056;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.000537;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.912609;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.986325;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.990972;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.993766;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.990992;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.001423;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.989026;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.923739;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.000772;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.915418;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.991170;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.990194;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.991938;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.990187;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.001175;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.988440;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.926190;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.000450;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.917101;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.990981;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.995485;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.997278;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.995440;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.001224;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.993607;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.926525;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.000479;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.922300;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.995042;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.998587;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 1.000093;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.998428;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.001033;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.996769;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.928704;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.000511;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.927245;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.998955;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.996673;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.998576;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.996656;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.001381;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.994740;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.942830;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.000429;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.939677;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.996483;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.996051;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.996986;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.996036;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.000672;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.994827;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.956157;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.000362;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.952367;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.996294;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.992137;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.993648;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.992128;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.001022;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.990615;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.966078;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.000446;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.958473;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.992070;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.992246;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.993474;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.992227;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.000828;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.990985;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.963799;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.000375;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.956308;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.991213;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.994022;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.995770;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.994000;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.001170;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.992242;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.963905;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.000534;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.958122;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.994158;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.994278;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.994959;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.993992;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.000637;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.993029;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.966126;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.000298;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.960322;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.993888;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.994680;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.995896;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.994620;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.000941;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.993354;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.968493;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.000292;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.963283;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.994305;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.995454;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.996271;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.995338;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.000616;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.994408;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.971121;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.000290;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.966593;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.995225;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.997675;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.998504;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.997685;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.000558;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.996868;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.977087;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.000241;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.974824;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.997596;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.997819;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.998461;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.997816;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.000415;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.997175;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.982526;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.000217;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.980381;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.997124;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.996796;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.997738;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.996777;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.000636;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.995822;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.985619;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.000309;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.982442;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.996479;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.995268;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.997104;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.995250;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.001336;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.993345;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.976651;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.000502;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.972012;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.995852;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.995242;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.997815;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.995471;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.001563;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.993152;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.976609;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.000717;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.972186;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.993865;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.995276;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.996798;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.995292;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.001692;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.992546;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.978644;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.000391;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.974037;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.994028;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.997993;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.999433;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.997987;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.001040;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.996513;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.979349;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.000391;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.977377;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.997324;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.997207;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.998476;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.997115;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.000967;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.995730;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.981362;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.000382;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.978531;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.997258;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.998216;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.999485;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.998212;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.000936;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.996948;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.985178;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.000314;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.983416;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.997853;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.998790;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.999708;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.998743;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.000653;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.997786;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.987763;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.000296;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.986522;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.998703;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.998723;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 1.000504;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.998721;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.001362;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.996879;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.990090;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.000433;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.988823;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.997982;

    return 1.; // Default
}


float eHTTID(float probe_Ele_pt, float probe_Ele_abseta, bool passingHTTID=true, Variation variation=Variation::CENTRAL) {
    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 1.034864;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 1.058047;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 1.038856;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.007451;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 1.019950;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.616908;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.004138;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.640879;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 1.041375;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.965536;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.997524;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.974611;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.008688;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.952087;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.582330;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.004659;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.567545;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 1.052077;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.820961;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.842689;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.820997;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.008490;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.799712;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.594649;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.005221;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.488205;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.863027;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.906064;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.943503;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.905905;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.025096;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.826266;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.513848;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.005679;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.465498;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.982097;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.999515;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 1.006575;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.999514;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.003955;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.992495;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.796028;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.001650;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.795641;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.998480;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.979331;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.989262;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.979332;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.005421;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.969474;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.756081;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.002103;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.740455;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.979429;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.856943;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.892329;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.863694;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.013473;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.850310;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.750276;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.002628;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.648009;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.859226;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.936421;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.951000;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.936716;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.006767;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.922716;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.686964;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.003147;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.643490;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.937727;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.992061;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.996599;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.993868;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.001419;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.991148;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.857124;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.000922;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.851868;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.992123;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.978432;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.982266;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.978419;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.002141;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.974339;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.830022;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.001174;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.812109;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.978815;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.924698;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.932305;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.927033;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.002783;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.921796;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.820000;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.001646;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.760167;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.923741;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.956794;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.964603;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.956792;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.004449;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.947444;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.755052;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.002122;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.722428;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.957505;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.994524;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.999522;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.994537;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.002501;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.992056;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.885150;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.000806;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.880314;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.994011;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.982278;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.985213;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.982280;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.001607;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.979230;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.867716;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.001007;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.852340;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.982854;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.942643;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.947415;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.942676;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.003019;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.937148;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.854190;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.001450;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.805224;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.942864;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.960613;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.967390;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.960619;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.003444;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.953874;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.795811;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.002013;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.764471;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.960771;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.994142;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.997202;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.993750;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.001836;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.990324;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.900314;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.001268;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.894687;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.995896;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.985544;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.990665;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.985525;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.002970;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.980382;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.882942;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.001593;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.870161;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.985358;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.960047;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.968139;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.960072;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.004799;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.952030;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.869581;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.002297;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.834860;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.960827;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.985647;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.997736;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.985713;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.006317;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.973741;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.803196;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.003367;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.791721;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.984402;

    return 1.; // Default
}


float eHTTISO(float probe_Ele_pt, float probe_Ele_abseta, bool passingHTTISO=true, bool passingHTTID=true, Variation variation=Variation::CENTRAL) {
    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 1.016278;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 1.045015;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 1.014193;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.013050;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.996916;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.744134;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.004746;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.754696;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 1.016808;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.978369;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.997724;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.978429;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.009684;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.959483;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.773183;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.005210;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.756505;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.975863;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.996125;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 1.032011;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 1.013351;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.008909;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.995096;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.791980;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.005632;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.802554;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 1.002796;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.054272;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.080570;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.058204;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.009603;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.036415;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.761302;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.006805;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.805612;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.048127;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.987963;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.991519;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.986911;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.002411;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.982336;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.863937;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.001576;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.852629;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.989247;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 1.002905;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 1.003535;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.998044;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.002776;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.992604;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.862753;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.001942;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.861066;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 1.003774;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.997951;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 1.004525;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.997517;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.003677;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.990590;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.868283;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.002378;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.866128;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.997638;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.025983;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.035685;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.025956;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.005275;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.016320;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.853183;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.002910;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.875328;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.023805;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.995816;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 1.004992;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.995168;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.004828;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.993082;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.931504;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.000720;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.927003;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.995719;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 1.000368;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 1.002626;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 1.000383;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.001206;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.998156;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.930710;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.000874;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.931067;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.999460;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 1.006956;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 1.019182;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 1.006923;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.010041;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.994663;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.922974;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.001265;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.929363;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 1.006572;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.016357;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.020461;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.016361;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.002131;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.012305;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.916285;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.001580;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.931276;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.016295;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.996064;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.997624;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.996062;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.001021;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.994508;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.966346;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.000487;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.962540;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.995961;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.999722;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 1.001453;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.999735;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.001106;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.997988;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.967242;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.000570;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.966986;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.999408;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 1.002347;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 1.004669;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 1.002359;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.001378;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 1.000016;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.961775;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.000857;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.964043;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 1.002067;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.006582;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.009554;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.006548;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.001707;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.003532;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.955500;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.001163;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.961756;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.006313;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 1.001405;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 1.002995;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 1.001388;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.000905;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.999803;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.978264;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.000656;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.979622;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 1.001224;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 1.000680;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 1.007600;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 1.000833;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.003393;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.999037;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.977526;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.000789;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.978340;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 1.000791;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 1.001619;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 1.005026;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 1.001630;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.002132;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.998182;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.973218;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.001196;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.974805;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 1.001874;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.004669;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.008461;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.004672;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.002270;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.000871;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.977452;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.001433;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.982019;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.004402;

    return 1.; // Default
}

