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

float mHTTID(float probe_pt, float probe_abseta, bool passingHTTIDICHEP=true, Variation variation=Variation::CENTRAL){
    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.969016;
    if ( variation == Variation::STAT_UP && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.978104;
    if ( variation == Variation::CENTRAL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.969041;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.007537;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.960727;
    if ( variation == Variation::EFF_MC && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.979202;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.001001;
    if ( variation == Variation::EFF_DATA && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.948887;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.979387;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.978300;
    if ( variation == Variation::STAT_UP && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.988826;
    if ( variation == Variation::CENTRAL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.979530;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.007421;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.970167;
    if ( variation == Variation::EFF_MC && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.969958;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.001662;
    if ( variation == Variation::EFF_DATA && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.950103;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.984986;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.980244;
    if ( variation == Variation::STAT_UP && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.987005;
    if ( variation == Variation::CENTRAL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.980487;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.005818;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.973933;
    if ( variation == Variation::EFF_MC && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.985079;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.000632;
    if ( variation == Variation::EFF_DATA && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.965858;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.982991;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.979140;
    if ( variation == Variation::STAT_UP && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.984349;
    if ( variation == Variation::CENTRAL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.979146;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.004544;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.973942;
    if ( variation == Variation::EFF_MC && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.984024;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.000589;
    if ( variation == Variation::EFF_DATA && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.963504;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.977181;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.985003;
    if ( variation == Variation::STAT_UP && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.994939;
    if ( variation == Variation::CENTRAL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.984906;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.008903;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.974776;
    if ( variation == Variation::EFF_MC && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.964251;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.000831;
    if ( variation == Variation::EFF_DATA && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.949697;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.975986;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.962365;
    if ( variation == Variation::STAT_UP && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.975285;
    if ( variation == Variation::CENTRAL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.964150;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.011797;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.949476;
    if ( variation == Variation::EFF_MC && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.966249;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.000698;
    if ( variation == Variation::EFF_DATA && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.931609;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.961146;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.970690;
    if ( variation == Variation::STAT_UP && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.981204;
    if ( variation == Variation::CENTRAL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.969884;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.010605;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.958573;
    if ( variation == Variation::EFF_MC && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.979781;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.000497;
    if ( variation == Variation::EFF_DATA && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.950274;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.965085;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.984147;
    if ( variation == Variation::STAT_UP && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.985348;
    if ( variation == Variation::CENTRAL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.984066;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.000976;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.982869;
    if ( variation == Variation::EFF_MC && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.990595;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.000256;
    if ( variation == Variation::EFF_DATA && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.974811;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.983506;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.974427;
    if ( variation == Variation::STAT_UP && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.978465;
    if ( variation == Variation::CENTRAL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.976814;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.001135;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.975190;
    if ( variation == Variation::EFF_MC && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.983233;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.000487;
    if ( variation == Variation::EFF_DATA && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.960435;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.974221;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.987333;
    if ( variation == Variation::STAT_UP && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.988218;
    if ( variation == Variation::CENTRAL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.987308;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.000740;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.986388;
    if ( variation == Variation::EFF_MC && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.993991;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.000172;
    if ( variation == Variation::EFF_DATA && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.981375;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.987090;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.990184;
    if ( variation == Variation::STAT_UP && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.990912;
    if ( variation == Variation::CENTRAL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.990206;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.000517;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.989505;
    if ( variation == Variation::EFF_MC && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.993656;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.000184;
    if ( variation == Variation::EFF_DATA && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.983924;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.989882;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.984828;
    if ( variation == Variation::STAT_UP && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.987288;
    if ( variation == Variation::CENTRAL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.984637;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.001515;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.983767;
    if ( variation == Variation::EFF_MC && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.990603;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.000232;
    if ( variation == Variation::EFF_DATA && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.975384;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.984925;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.991217;
    if ( variation == Variation::STAT_UP && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.992313;
    if ( variation == Variation::CENTRAL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.991209;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.000905;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.990109;
    if ( variation == Variation::EFF_MC && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.992266;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.000190;
    if ( variation == Variation::EFF_DATA && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.983543;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.990811;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.979298;
    if ( variation == Variation::STAT_UP && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.975373;
    if ( variation == Variation::CENTRAL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.974665;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.000565;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.973965;
    if ( variation == Variation::EFF_MC && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.995268;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.000139;
    if ( variation == Variation::EFF_DATA && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.970054;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.978978;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.983863;
    if ( variation == Variation::STAT_UP && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.984332;
    if ( variation == Variation::CENTRAL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.983874;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.000308;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.983416;
    if ( variation == Variation::EFF_MC && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.991421;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.000149;
    if ( variation == Variation::EFF_DATA && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.975434;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.983704;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.976289;
    if ( variation == Variation::STAT_UP && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.977385;
    if ( variation == Variation::CENTRAL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.976236;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.000781;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.975238;
    if ( variation == Variation::EFF_MC && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.984862;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.000282;
    if ( variation == Variation::EFF_DATA && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.961457;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.975833;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.989366;
    if ( variation == Variation::STAT_UP && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.989652;
    if ( variation == Variation::CENTRAL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.989367;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.000190;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.989084;
    if ( variation == Variation::EFF_MC && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.995339;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.000094;
    if ( variation == Variation::EFF_DATA && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.984755;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.989340;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.989561;
    if ( variation == Variation::STAT_UP && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.990010;
    if ( variation == Variation::CENTRAL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.989561;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.000350;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.989096;
    if ( variation == Variation::EFF_MC && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.994811;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.000106;
    if ( variation == Variation::EFF_DATA && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.984427;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.989456;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.987805;
    if ( variation == Variation::STAT_UP && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.988208;
    if ( variation == Variation::CENTRAL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.987779;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.000304;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.987353;
    if ( variation == Variation::EFF_MC && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.993995;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.000123;
    if ( variation == Variation::EFF_DATA && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.981847;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.987521;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.991970;
    if ( variation == Variation::STAT_UP && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.992295;
    if ( variation == Variation::CENTRAL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.991979;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.000211;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.991668;
    if ( variation == Variation::EFF_MC && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.995250;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.000102;
    if ( variation == Variation::EFF_DATA && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.987267;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.992166;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.987037;
    if ( variation == Variation::STAT_UP && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.984360;
    if ( variation == Variation::CENTRAL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.984029;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.000252;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.983701;
    if ( variation == Variation::EFF_MC && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.997031;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.000077;
    if ( variation == Variation::EFF_DATA && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.981108;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.986471;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.985869;
    if ( variation == Variation::STAT_UP && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.986150;
    if ( variation == Variation::CENTRAL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.985675;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.000324;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.985207;
    if ( variation == Variation::EFF_MC && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.991706;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.000145;
    if ( variation == Variation::EFF_DATA && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.977500;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.985546;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.976835;
    if ( variation == Variation::STAT_UP && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.977743;
    if ( variation == Variation::CENTRAL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.976825;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.000626;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.975915;
    if ( variation == Variation::EFF_MC && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.984532;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.000280;
    if ( variation == Variation::EFF_DATA && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.961715;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.976575;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.991078;
    if ( variation == Variation::STAT_UP && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.991375;
    if ( variation == Variation::CENTRAL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.991073;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.000212;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.990774;
    if ( variation == Variation::EFF_MC && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.995520;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.000088;
    if ( variation == Variation::EFF_DATA && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.986633;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.990694;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.990745;
    if ( variation == Variation::STAT_UP && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.991082;
    if ( variation == Variation::CENTRAL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.990746;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.000241;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.990409;
    if ( variation == Variation::EFF_MC && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.994909;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.000095;
    if ( variation == Variation::EFF_DATA && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.985702;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.990629;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.989003;
    if ( variation == Variation::STAT_UP && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.989338;
    if ( variation == Variation::CENTRAL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.988998;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.000238;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.988660;
    if ( variation == Variation::EFF_MC && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.994696;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.000100;
    if ( variation == Variation::EFF_DATA && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.983752;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.988757;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.992958;
    if ( variation == Variation::STAT_UP && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.995101;
    if ( variation == Variation::CENTRAL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.993052;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.001072;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.992791;
    if ( variation == Variation::EFF_MC && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.996209;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.000079;
    if ( variation == Variation::EFF_DATA && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.989288;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.992051;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.987105;
    if ( variation == Variation::STAT_UP && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.987478;
    if ( variation == Variation::CENTRAL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.987116;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.000298;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.986750;
    if ( variation == Variation::EFF_MC && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.997557;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.000066;
    if ( variation == Variation::EFF_DATA && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.984705;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.986837;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.987025;
    if ( variation == Variation::STAT_UP && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.990068;
    if ( variation == Variation::CENTRAL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.986896;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.002855;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.983817;
    if ( variation == Variation::EFF_MC && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.991219;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.000247;
    if ( variation == Variation::EFF_DATA && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.978231;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIDICHEP) ) return 0.986087;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.979385;
    if ( variation == Variation::STAT_UP && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.981105;
    if ( variation == Variation::CENTRAL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.979403;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.001208;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.977702;
    if ( variation == Variation::EFF_MC && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.983797;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.000475;
    if ( variation == Variation::EFF_DATA && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.963534;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIDICHEP) ) return 0.977661;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.991376;
    if ( variation == Variation::STAT_UP && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.992026;
    if ( variation == Variation::CENTRAL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.991370;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.000512;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.990708;
    if ( variation == Variation::EFF_MC && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.995495;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.000145;
    if ( variation == Variation::EFF_DATA && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.986905;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIDICHEP) ) return 0.990375;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.991374;
    if ( variation == Variation::STAT_UP && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.995248;
    if ( variation == Variation::CENTRAL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.991374;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.004801;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.985276;
    if ( variation == Variation::EFF_MC && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.994685;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.000160;
    if ( variation == Variation::EFF_DATA && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.986105;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIDICHEP) ) return 0.990202;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.985616;
    if ( variation == Variation::STAT_UP && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.986598;
    if ( variation == Variation::CENTRAL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.985619;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.000791;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.984637;
    if ( variation == Variation::EFF_MC && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.993164;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.000186;
    if ( variation == Variation::EFF_DATA && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.978881;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIDICHEP) ) return 0.984073;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.989874;
    if ( variation == Variation::STAT_UP && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.994097;
    if ( variation == Variation::CENTRAL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.988867;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.003071;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.987578;
    if ( variation == Variation::EFF_MC && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.993311;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.000169;
    if ( variation == Variation::EFF_DATA && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.982252;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIDICHEP) ) return 0.986269;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.986902;
    if ( variation == Variation::STAT_UP && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.985832;
    if ( variation == Variation::CENTRAL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.985184;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.000515;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.984542;
    if ( variation == Variation::EFF_MC && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.996403;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.000129;
    if ( variation == Variation::EFF_DATA && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.981640;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIDICHEP) ) return 0.983979;

    return 1.; // Default
} 

float mHTTISO(float probe_pt, float probe_abseta, bool passingHTTIso=true, bool passingHTTIDICHEP=true, Variation variation=Variation::CENTRAL) {
    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.961556;
    if ( variation == Variation::STAT_UP && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.978400;
    if ( variation == Variation::CENTRAL && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.961968;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.007515;
    if ( variation == Variation::STAT_DOWN && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.944644;
    if ( variation == Variation::EFF_MC && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.636121;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.003350;
    if ( variation == Variation::EFF_DATA && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.611927;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.961062;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.966686;
    if ( variation == Variation::STAT_UP && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 1.021869;
    if ( variation == Variation::CENTRAL && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.974899;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.016504;
    if ( variation == Variation::STAT_DOWN && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.956296;
    if ( variation == Variation::EFF_MC && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.643742;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.004652;
    if ( variation == Variation::EFF_DATA && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.627583;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.963092;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.957833;
    if ( variation == Variation::STAT_UP && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.972720;
    if ( variation == Variation::CENTRAL && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.959149;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.005802;
    if ( variation == Variation::STAT_DOWN && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.948818;
    if ( variation == Variation::EFF_MC && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.679493;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.002413;
    if ( variation == Variation::EFF_DATA && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.651735;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.959264;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.964851;
    if ( variation == Variation::STAT_UP && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.972117;
    if ( variation == Variation::CENTRAL && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.964778;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.003144;
    if ( variation == Variation::STAT_DOWN && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.957547;
    if ( variation == Variation::EFF_MC && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.711966;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.002117;
    if ( variation == Variation::EFF_DATA && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.686889;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.965011;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.971220;
    if ( variation == Variation::STAT_UP && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.979463;
    if ( variation == Variation::CENTRAL && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.971298;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.004048;
    if ( variation == Variation::STAT_DOWN && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.963043;
    if ( variation == Variation::EFF_MC && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.730605;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.002008;
    if ( variation == Variation::EFF_DATA && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.709635;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.973987;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.965878;
    if ( variation == Variation::STAT_UP && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.972708;
    if ( variation == Variation::CENTRAL && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.967538;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.002430;
    if ( variation == Variation::STAT_DOWN && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.962387;
    if ( variation == Variation::EFF_MC && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.776401;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.001629;
    if ( variation == Variation::EFF_DATA && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.751198;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.968906;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.967141;
    if ( variation == Variation::STAT_UP && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.971873;
    if ( variation == Variation::CENTRAL && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.967614;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.002079;
    if ( variation == Variation::STAT_DOWN && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.963397;
    if ( variation == Variation::EFF_MC && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.808520;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.001392;
    if ( variation == Variation::EFF_DATA && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.782335;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTIDICHEP && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.969061;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.977360;
    if ( variation == Variation::STAT_UP && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.978279;
    if ( variation == Variation::CENTRAL && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.969875;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.005973;
    if ( variation == Variation::STAT_DOWN && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.961500;
    if ( variation == Variation::EFF_MC && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.827353;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.000998;
    if ( variation == Variation::EFF_DATA && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.802429;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.977745;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.971826;
    if ( variation == Variation::STAT_UP && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.975937;
    if ( variation == Variation::CENTRAL && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.971824;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.002039;
    if ( variation == Variation::STAT_DOWN && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.967732;
    if ( variation == Variation::EFF_MC && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.832105;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.001415;
    if ( variation == Variation::EFF_DATA && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.808660;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.974557;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.974761;
    if ( variation == Variation::STAT_UP && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.977366;
    if ( variation == Variation::CENTRAL && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.975026;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.001163;
    if ( variation == Variation::STAT_DOWN && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.972700;
    if ( variation == Variation::EFF_MC && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.837696;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.000812;
    if ( variation == Variation::EFF_DATA && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.816775;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.976262;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.982912;
    if ( variation == Variation::STAT_UP && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.992662;
    if ( variation == Variation::CENTRAL && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.983350;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.007026;
    if ( variation == Variation::STAT_DOWN && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.974056;
    if ( variation == Variation::EFF_MC && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.843543;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.000835;
    if ( variation == Variation::EFF_DATA && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.829498;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.984978;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.990209;
    if ( variation == Variation::STAT_UP && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.992509;
    if ( variation == Variation::CENTRAL && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.990135;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.001176;
    if ( variation == Variation::STAT_DOWN && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.987776;
    if ( variation == Variation::EFF_MC && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.852415;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.000850;
    if ( variation == Variation::EFF_DATA && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.844006;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.979970;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.990057;
    if ( variation == Variation::STAT_UP && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.992809;
    if ( variation == Variation::CENTRAL && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.990166;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.001602;
    if ( variation == Variation::STAT_DOWN && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.987531;
    if ( variation == Variation::EFF_MC && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.874912;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.000714;
    if ( variation == Variation::EFF_DATA && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.866308;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.992096;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.987328;
    if ( variation == Variation::STAT_UP && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.990185;
    if ( variation == Variation::CENTRAL && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.987406;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.001915;
    if ( variation == Variation::STAT_DOWN && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.984632;
    if ( variation == Variation::EFF_MC && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.901956;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.000597;
    if ( variation == Variation::EFF_DATA && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.890596;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTIDICHEP && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.987492;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.983663;
    if ( variation == Variation::STAT_UP && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.984673;
    if ( variation == Variation::CENTRAL && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.983714;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.000487;
    if ( variation == Variation::STAT_DOWN && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.982759;
    if ( variation == Variation::EFF_MC && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.930577;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.000410;
    if ( variation == Variation::EFF_DATA && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.915422;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.984536;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.987432;
    if ( variation == Variation::STAT_UP && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.988724;
    if ( variation == Variation::CENTRAL && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.987216;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.000862;
    if ( variation == Variation::STAT_DOWN && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.985603;
    if ( variation == Variation::EFF_MC && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.929100;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.000595;
    if ( variation == Variation::EFF_DATA && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.917222;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.986730;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.987334;
    if ( variation == Variation::STAT_UP && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.988198;
    if ( variation == Variation::CENTRAL && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.987381;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.000620;
    if ( variation == Variation::STAT_DOWN && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.986131;
    if ( variation == Variation::EFF_MC && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.931301;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.000347;
    if ( variation == Variation::EFF_DATA && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.919549;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.987861;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.992559;
    if ( variation == Variation::STAT_UP && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.993605;
    if ( variation == Variation::CENTRAL && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.992518;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.000646;
    if ( variation == Variation::STAT_DOWN && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.991437;
    if ( variation == Variation::EFF_MC && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.932431;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.000367;
    if ( variation == Variation::EFF_DATA && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.925455;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.991978;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.995230;
    if ( variation == Variation::STAT_UP && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.996024;
    if ( variation == Variation::CENTRAL && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.995185;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.000391;
    if ( variation == Variation::STAT_DOWN && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.994351;
    if ( variation == Variation::EFF_MC && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.934064;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.000392;
    if ( variation == Variation::EFF_DATA && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.929567;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.995136;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.995525;
    if ( variation == Variation::STAT_UP && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.996319;
    if ( variation == Variation::CENTRAL && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.995319;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.000611;
    if ( variation == Variation::STAT_DOWN && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.994323;
    if ( variation == Variation::EFF_MC && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.945485;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.000334;
    if ( variation == Variation::EFF_DATA && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.941059;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.995181;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.995722;
    if ( variation == Variation::STAT_UP && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.996637;
    if ( variation == Variation::CENTRAL && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.995724;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.000499;
    if ( variation == Variation::STAT_DOWN && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.995007;
    if ( variation == Variation::EFF_MC && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.958113;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.000283;
    if ( variation == Variation::EFF_DATA && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.954016;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTIDICHEP && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.996084;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.990617;
    if ( variation == Variation::STAT_UP && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.991358;
    if ( variation == Variation::CENTRAL && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.990616;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.000452;
    if ( variation == Variation::STAT_DOWN && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.989877;
    if ( variation == Variation::EFF_MC && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.970831;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.000269;
    if ( variation == Variation::EFF_DATA && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.961721;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.989830;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.992881;
    if ( variation == Variation::STAT_UP && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.993941;
    if ( variation == Variation::CENTRAL && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.992955;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.000569;
    if ( variation == Variation::STAT_DOWN && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.991978;
    if ( variation == Variation::EFF_MC && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.970466;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.000386;
    if ( variation == Variation::EFF_DATA && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.963629;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.992973;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.992670;
    if ( variation == Variation::STAT_UP && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.993256;
    if ( variation == Variation::CENTRAL && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.992686;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.000344;
    if ( variation == Variation::STAT_DOWN && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.992116;
    if ( variation == Variation::EFF_MC && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.972941;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.000213;
    if ( variation == Variation::EFF_DATA && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.965824;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.992105;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.994606;
    if ( variation == Variation::STAT_UP && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.995338;
    if ( variation == Variation::CENTRAL && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.994784;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.000333;
    if ( variation == Variation::STAT_DOWN && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.994230;
    if ( variation == Variation::EFF_MC && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.974796;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.000209;
    if ( variation == Variation::EFF_DATA && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.969711;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.994321;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.996499;
    if ( variation == Variation::STAT_UP && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.997035;
    if ( variation == Variation::CENTRAL && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.996488;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.000325;
    if ( variation == Variation::STAT_DOWN && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.995943;
    if ( variation == Variation::EFF_MC && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.976656;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.000208;
    if ( variation == Variation::EFF_DATA && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.973227;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.996494;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.997492;
    if ( variation == Variation::STAT_UP && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.997984;
    if ( variation == Variation::CENTRAL && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.997504;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.000296;
    if ( variation == Variation::STAT_DOWN && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.997026;
    if ( variation == Variation::EFF_MC && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.981341;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.000174;
    if ( variation == Variation::EFF_DATA && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.978891;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.997340;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.997446;
    if ( variation == Variation::STAT_UP && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.997869;
    if ( variation == Variation::CENTRAL && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.997448;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.000262;
    if ( variation == Variation::STAT_DOWN && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.997017;
    if ( variation == Variation::EFF_MC && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.985348;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.000159;
    if ( variation == Variation::EFF_DATA && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.982833;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTIDICHEP && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.997043;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.995215;
    if ( variation == Variation::STAT_UP && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.996245;
    if ( variation == Variation::CENTRAL && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.995219;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.000650;
    if ( variation == Variation::STAT_DOWN && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.994189;
    if ( variation == Variation::EFF_MC && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.981076;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.000360;
    if ( variation == Variation::EFF_DATA && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.976385;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIso) ) return 0.995501;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.996586;
    if ( variation == Variation::STAT_UP && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.998206;
    if ( variation == Variation::CENTRAL && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.996477;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.002656;
    if ( variation == Variation::STAT_DOWN && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.991746;
    if ( variation == Variation::EFF_MC && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.981149;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.000515;
    if ( variation == Variation::EFF_DATA && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.977692;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIso) ) return 0.996787;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.995652;
    if ( variation == Variation::STAT_UP && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.996368;
    if ( variation == Variation::CENTRAL && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.995644;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.000425;
    if ( variation == Variation::STAT_DOWN && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.994928;
    if ( variation == Variation::EFF_MC && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.982403;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.000284;
    if ( variation == Variation::EFF_DATA && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.978124;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIso) ) return 0.995706;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.997797;
    if ( variation == Variation::STAT_UP && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.998588;
    if ( variation == Variation::CENTRAL && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.997792;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.000503;
    if ( variation == Variation::STAT_DOWN && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.996985;
    if ( variation == Variation::EFF_MC && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.982758;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.000285;
    if ( variation == Variation::EFF_DATA && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.980588;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIso) ) return 0.997554;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.998880;
    if ( variation == Variation::STAT_UP && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.999662;
    if ( variation == Variation::CENTRAL && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.998881;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.000498;
    if ( variation == Variation::STAT_DOWN && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.998080;
    if ( variation == Variation::EFF_MC && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.984158;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.000281;
    if ( variation == Variation::EFF_DATA && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.983057;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIso) ) return 0.999173;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.997989;
    if ( variation == Variation::STAT_UP && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.997471;
    if ( variation == Variation::CENTRAL && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.996849;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.000378;
    if ( variation == Variation::STAT_DOWN && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.996236;
    if ( variation == Variation::EFF_MC && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.987301;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.000232;
    if ( variation == Variation::EFF_DATA && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.984190;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIso) ) return 0.998239;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.998963;
    if ( variation == Variation::STAT_UP && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.998936;
    if ( variation == Variation::CENTRAL && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.998387;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.000325;
    if ( variation == Variation::STAT_DOWN && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.997842;
    if ( variation == Variation::EFF_MC && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.989615;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.000217;
    if ( variation == Variation::EFF_DATA && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.988018;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTIDICHEP && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIso) ) return 0.998912;

    return 1.; // Default
} 


float eHTTID(float probe_Ele_pt, float probe_Ele_abseta, bool passingHTTID=true, Variation variation=Variation::CENTRAL){
    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.990881;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 1.008074;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.990909;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.008966;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.974054;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.634372;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.001841;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.628605;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.991192;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.953314;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 1.025089;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.953357;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.042745;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.874248;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.592790;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.002068;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.565140;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 1.021939;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.799017;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.822702;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.798888;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.012486;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.775960;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.613695;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.002322;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.490274;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.878165;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.902026;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.925420;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.902263;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.009880;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.879775;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.533825;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.002552;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.481651;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.961596;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.973944;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.978335;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.973964;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.002728;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.969779;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.803944;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.000731;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.783012;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.973232;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.947263;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.956109;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.951812;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.002398;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.947529;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.765921;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.000933;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.729013;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.946085;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.872981;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.881264;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.872968;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.005285;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.864705;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.760884;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.001162;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.664228;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.872287;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.954450;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.960446;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.953543;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.003498;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.946658;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.700232;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.001394;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.667702;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.950989;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.976488;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.978384;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.976548;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.001187;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.974716;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.863448;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.000406;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.843198;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.976708;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.966769;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.969608;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.967494;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.001264;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.965386;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.836549;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.000519;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.809355;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.967476;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.934643;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.938299;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.934854;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.002269;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.931176;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.827481;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.000725;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.773574;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.931892;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.951994;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.956796;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.952181;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.002663;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.947504;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.765956;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.000941;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.729329;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.952920;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.981457;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.982729;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.981443;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.000797;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.980159;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.890909;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.000354;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.874376;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.981162;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.974457;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.976098;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.974432;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.001019;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.972773;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.872785;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.000443;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.850470;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.974609;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.954631;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.956634;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.954629;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.001117;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.952633;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.860995;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.000634;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.821931;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.953038;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.964115;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.969379;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.965427;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.002301;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.961491;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.801411;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.000890;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.773704;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.964566;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.984034;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.985495;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.983465;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.001281;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.981436;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.903384;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.000562;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.888446;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTID) ) return 0.984694;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.975841;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.978941;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.975836;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.002065;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.972729;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.886369;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.000705;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.864950;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTID) ) return 0.975779;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.967457;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.990877;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.968093;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.019747;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.943490;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.874520;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.001006;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.846617;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTID) ) return 0.968308;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.975791;
    if ( variation == Variation::STAT_UP && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.982350;
    if ( variation == Variation::CENTRAL && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.975825;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.004066;
    if ( variation == Variation::STAT_DOWN && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.968813;
    if ( variation == Variation::EFF_MC && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.813725;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.001478;
    if ( variation == Variation::EFF_DATA && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.794054;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTID) ) return 0.975172;

    return 1.; // Default
} 


float eHTTISO(float probe_Ele_pt, float probe_Ele_abseta, bool passingHTTISO=true, bool passingHTTID=true, Variation variation=Variation::CENTRAL) {
    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.985169;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.980497;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.971708;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.004618;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.962972;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.755979;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.002064;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.734591;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.984775;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.975972;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.988916;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.976956;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.006930;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.965098;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.770808;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.002302;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.753046;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.981885;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.988550;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 1.013567;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.988595;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.012600;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.975628;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.793722;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.002470;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.784669;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.994788;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.024284;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.039254;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.024222;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.008399;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.009248;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.763609;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.002984;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.782105;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=10 && probe_Ele_pt<20 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.023944;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.978465;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.981611;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.978906;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.001643;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.976216;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.864208;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.000703;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.845978;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.981484;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.990824;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.993246;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.990025;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.001934;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.986812;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.865664;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.000859;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.857029;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.988209;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.990438;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.994696;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.990369;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.002719;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.985993;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.866758;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.001063;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.858410;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.990980;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.007317;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.012558;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.007356;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.003204;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.002127;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.859144;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.001267;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.865464;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=20 && probe_Ele_pt<30 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.007174;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.990406;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.991683;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.990558;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.000735;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.989435;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.933670;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.000317;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.924854;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.990543;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.993437;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.995623;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.993425;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.001665;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.991232;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.932631;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.000385;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.926499;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.992652;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 1.004153;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 1.005552;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 1.004173;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.000696;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 1.002801;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.921247;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.000569;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.925091;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 1.003642;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.007701;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.010661;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.007487;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.002029;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.004751;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.920815;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.000687;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.927709;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=30 && probe_Ele_pt<40 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.007713;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.993523;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.994237;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.993521;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.000483;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.992804;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.968037;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.000212;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.961765;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.993394;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.996113;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.996898;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.996057;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.000562;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.995219;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.968001;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.000251;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.964184;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.995886;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.999910;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 1.001346;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 1.000058;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.000853;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.998773;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.960958;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.000384;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.961013;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 1.000065;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.000272;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.001999;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.000298;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.001138;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.998596;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.959324;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.000494;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.959609;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=40 && probe_Ele_pt<50 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.000156;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.997119;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 1.015409;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 1.015085;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.000021;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 1.014769;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.979081;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.000288;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.993850;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.0 && probe_Ele_abseta<0.8 && passingHTTISO) ) return 0.997010;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.997635;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.998818;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.997707;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.000752;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.996601;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.979619;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.000335;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.977373;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=0.8 && probe_Ele_abseta<1.479 && passingHTTISO) ) return 0.997445;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 1.000149;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 1.010822;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 1.000236;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.005827;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.997693;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.971219;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.000546;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 0.971448;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=1.479 && probe_Ele_abseta<2.0 && passingHTTISO) ) return 1.000030;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.001523;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.003775;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.001524;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.001586;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.999269;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.978432;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.000618;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 0.979923;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_Ele_pt>=50 && probe_Ele_pt<1000 && probe_Ele_abseta>=2.0 && probe_Ele_abseta<2.5 && passingHTTISO) ) return 1.001609;

    return 1.; // Default
}

