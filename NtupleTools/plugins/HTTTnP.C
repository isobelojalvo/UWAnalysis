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

float mHTTID(float probe_pt, float probe_abseta, bool passingHTTID=true, Variation variation=Variation::CENTRAL){
    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.898696;
    if ( variation == Variation::STAT_UP && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.916568;
    if ( variation == Variation::CENTRAL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.898657;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.016374;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.881042;
    if ( variation == Variation::EFF_MC && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.977777;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.001106;
    if ( variation == Variation::EFF_DATA && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.878686;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.903317;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.919550;
    if ( variation == Variation::STAT_UP && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.936701;
    if ( variation == Variation::CENTRAL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.919588;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.015089;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.902298;
    if ( variation == Variation::EFF_MC && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.970943;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.001753;
    if ( variation == Variation::EFF_DATA && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.892867;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.932773;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.921903;
    if ( variation == Variation::STAT_UP && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.933481;
    if ( variation == Variation::CENTRAL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.921971;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.010790;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.910320;
    if ( variation == Variation::EFF_MC && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.985214;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.000672;
    if ( variation == Variation::EFF_DATA && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.908340;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.923439;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.956134;
    if ( variation == Variation::STAT_UP && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.965110;
    if ( variation == Variation::CENTRAL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.956224;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.008182;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.947268;
    if ( variation == Variation::EFF_MC && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.984250;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.000627;
    if ( variation == Variation::EFF_DATA && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.941164;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.953995;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.941311;
    if ( variation == Variation::STAT_UP && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.957660;
    if ( variation == Variation::CENTRAL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.941318;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.015281;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.924310;
    if ( variation == Variation::EFF_MC && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.965605;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.000871;
    if ( variation == Variation::EFF_DATA && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.908941;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.938500;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.921887;
    if ( variation == Variation::STAT_UP && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.941958;
    if ( variation == Variation::CENTRAL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.921581;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.017838;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.903759;
    if ( variation == Variation::EFF_MC && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.968710;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.000719;
    if ( variation == Variation::EFF_DATA && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.892744;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.945886;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.860243;
    if ( variation == Variation::STAT_UP && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.880218;
    if ( variation == Variation::CENTRAL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.860217;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.018837;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.841042;
    if ( variation == Variation::EFF_MC && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.983142;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.000488;
    if ( variation == Variation::EFF_DATA && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.845715;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.873923;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.837467;
    if ( variation == Variation::STAT_UP && (probe_pt>=10 && probe_pt<20 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.851162;
    if ( variation == Variation::CENTRAL && (probe_pt>=10 && probe_pt<20 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.837401;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.012434;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=10 && probe_pt<20 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.823991;
    if ( variation == Variation::EFF_MC && (probe_pt>=10 && probe_pt<20 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.968802;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=10 && probe_pt<20 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.000869;
    if ( variation == Variation::EFF_DATA && (probe_pt>=10 && probe_pt<20 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.811275;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=10 && probe_pt<20 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.839463;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.937158;
    if ( variation == Variation::STAT_UP && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.941471;
    if ( variation == Variation::CENTRAL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.937018;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.004013;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.932759;
    if ( variation == Variation::EFF_MC && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.987902;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.000310;
    if ( variation == Variation::EFF_DATA && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.925682;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.935389;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.935932;
    if ( variation == Variation::STAT_UP && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.940092;
    if ( variation == Variation::CENTRAL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.935944;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.003569;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.931826;
    if ( variation == Variation::EFF_MC && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.982812;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.000527;
    if ( variation == Variation::EFF_DATA && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.919858;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.933549;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.953746;
    if ( variation == Variation::STAT_UP && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.956413;
    if ( variation == Variation::CENTRAL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.954877;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.001342;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.953346;
    if ( variation == Variation::EFF_MC && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.993473;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.000191;
    if ( variation == Variation::EFF_DATA && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.948644;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.952976;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.962634;
    if ( variation == Variation::STAT_UP && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.964586;
    if ( variation == Variation::CENTRAL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.962610;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.001758;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.960637;
    if ( variation == Variation::EFF_MC && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.992763;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.000210;
    if ( variation == Variation::EFF_DATA && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.955644;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.962426;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.961731;
    if ( variation == Variation::STAT_UP && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.964220;
    if ( variation == Variation::CENTRAL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.961781;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.002132;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.959421;
    if ( variation == Variation::EFF_MC && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.990178;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.000254;
    if ( variation == Variation::EFF_DATA && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.952334;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.961229;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.980603;
    if ( variation == Variation::STAT_UP && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.982571;
    if ( variation == Variation::CENTRAL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.980616;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.001754;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.978634;
    if ( variation == Variation::EFF_MC && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.992289;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.000203;
    if ( variation == Variation::EFF_DATA && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.973054;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.980094;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.953890;
    if ( variation == Variation::STAT_UP && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.956340;
    if ( variation == Variation::CENTRAL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.953898;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.002237;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.951564;
    if ( variation == Variation::EFF_MC && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.995358;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.000147;
    if ( variation == Variation::EFF_DATA && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.949470;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.953365;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.908093;
    if ( variation == Variation::STAT_UP && (probe_pt>=20 && probe_pt<30 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.911968;
    if ( variation == Variation::CENTRAL && (probe_pt>=20 && probe_pt<30 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.908098;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.004022;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=20 && probe_pt<30 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.903024;
    if ( variation == Variation::EFF_MC && (probe_pt>=20 && probe_pt<30 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.980497;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=20 && probe_pt<30 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.000400;
    if ( variation == Variation::EFF_DATA && (probe_pt>=20 && probe_pt<30 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.890387;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=20 && probe_pt<30 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.906333;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.937358;
    if ( variation == Variation::STAT_UP && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.938443;
    if ( variation == Variation::CENTRAL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.937235;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.001027;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.936027;
    if ( variation == Variation::EFF_MC && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.989123;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.000179;
    if ( variation == Variation::EFF_DATA && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.927041;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.937152;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.938806;
    if ( variation == Variation::STAT_UP && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.941032;
    if ( variation == Variation::CENTRAL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.939223;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.001493;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.937420;
    if ( variation == Variation::EFF_MC && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.984649;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.000304;
    if ( variation == Variation::EFF_DATA && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.924805;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.938572;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.954238;
    if ( variation == Variation::STAT_UP && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.955099;
    if ( variation == Variation::CENTRAL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.954249;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.000744;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.953400;
    if ( variation == Variation::EFF_MC && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.994856;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.000105;
    if ( variation == Variation::EFF_DATA && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.949340;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.954172;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.965208;
    if ( variation == Variation::STAT_UP && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.966129;
    if ( variation == Variation::CENTRAL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.965153;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.000850;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.964183;
    if ( variation == Variation::EFF_MC && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.994033;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.000121;
    if ( variation == Variation::EFF_DATA && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.959393;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.965045;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.965817;
    if ( variation == Variation::STAT_UP && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.967282;
    if ( variation == Variation::CENTRAL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.966768;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.000374;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.966257;
    if ( variation == Variation::EFF_MC && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.993218;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.000139;
    if ( variation == Variation::EFF_DATA && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.960211;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.965183;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.985225;
    if ( variation == Variation::STAT_UP && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.984460;
    if ( variation == Variation::CENTRAL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.983789;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.000555;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.983121;
    if ( variation == Variation::EFF_MC && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.994786;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.000114;
    if ( variation == Variation::EFF_DATA && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.978660;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.985221;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.962074;
    if ( variation == Variation::STAT_UP && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.962456;
    if ( variation == Variation::CENTRAL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.962081;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.000627;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.961039;
    if ( variation == Variation::EFF_MC && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.997065;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.000082;
    if ( variation == Variation::EFF_DATA && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.959258;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.961360;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.919248;
    if ( variation == Variation::STAT_UP && (probe_pt>=30 && probe_pt<40 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.921933;
    if ( variation == Variation::CENTRAL && (probe_pt>=30 && probe_pt<40 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.918830;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.002132;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=30 && probe_pt<40 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.917122;
    if ( variation == Variation::EFF_MC && (probe_pt>=30 && probe_pt<40 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.984506;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=30 && probe_pt<40 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.000257;
    if ( variation == Variation::EFF_DATA && (probe_pt>=30 && probe_pt<40 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.904593;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=30 && probe_pt<40 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.919331;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.939709;
    if ( variation == Variation::STAT_UP && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.940706;
    if ( variation == Variation::CENTRAL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.939790;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.000744;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.938873;
    if ( variation == Variation::EFF_MC && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.989591;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.000173;
    if ( variation == Variation::EFF_DATA && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.930008;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.939596;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.940822;
    if ( variation == Variation::STAT_UP && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.942658;
    if ( variation == Variation::CENTRAL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.940820;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.001528;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.938977;
    if ( variation == Variation::EFF_MC && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.984238;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.000301;
    if ( variation == Variation::EFF_DATA && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.925991;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.940723;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.957570;
    if ( variation == Variation::STAT_UP && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.958267;
    if ( variation == Variation::CENTRAL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.957496;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.000675;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.956724;
    if ( variation == Variation::EFF_MC && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.995178;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.000097;
    if ( variation == Variation::EFF_DATA && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.952879;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.956935;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.967106;
    if ( variation == Variation::STAT_UP && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.967850;
    if ( variation == Variation::CENTRAL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.967140;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.000776;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.966079;
    if ( variation == Variation::EFF_MC && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.994252;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.000108;
    if ( variation == Variation::EFF_DATA && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.961581;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.966903;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.969432;
    if ( variation == Variation::STAT_UP && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.971079;
    if ( variation == Variation::CENTRAL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.969452;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.001095;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.968652;
    if ( variation == Variation::EFF_MC && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.993892;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.000115;
    if ( variation == Variation::EFF_DATA && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.963531;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.969247;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.985784;
    if ( variation == Variation::STAT_UP && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.986384;
    if ( variation == Variation::CENTRAL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.985794;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.000530;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.985144;
    if ( variation == Variation::EFF_MC && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.995772;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.000089;
    if ( variation == Variation::EFF_DATA && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.981625;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.984565;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.968251;
    if ( variation == Variation::STAT_UP && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.969058;
    if ( variation == Variation::CENTRAL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.968298;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.000706;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.967507;
    if ( variation == Variation::EFF_MC && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.997535;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.000070;
    if ( variation == Variation::EFF_DATA && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.965911;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.966861;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.922951;
    if ( variation == Variation::STAT_UP && (probe_pt>=40 && probe_pt<50 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.927560;
    if ( variation == Variation::CENTRAL && (probe_pt>=40 && probe_pt<50 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.923098;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.004354;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=40 && probe_pt<50 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.918259;
    if ( variation == Variation::EFF_MC && (probe_pt>=40 && probe_pt<50 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.986469;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=40 && probe_pt<50 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.000253;
    if ( variation == Variation::EFF_DATA && (probe_pt>=40 && probe_pt<50 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.910608;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=40 && probe_pt<50 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.920645;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.945635;
    if ( variation == Variation::STAT_UP && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.950932;
    if ( variation == Variation::CENTRAL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.945392;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.003441;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.943396;
    if ( variation == Variation::EFF_MC && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.988528;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.000300;
    if ( variation == Variation::EFF_DATA && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.934547;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTID) ) return 0.941829;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.945100;
    if ( variation == Variation::STAT_UP && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.948741;
    if ( variation == Variation::CENTRAL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.944979;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.003207;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.941229;
    if ( variation == Variation::EFF_MC && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.983304;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.000515;
    if ( variation == Variation::EFF_DATA && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.929202;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTID) ) return 0.941474;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.954424;
    if ( variation == Variation::STAT_UP && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.956040;
    if ( variation == Variation::CENTRAL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.954420;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.001469;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.952780;
    if ( variation == Variation::EFF_MC && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.995189;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.000160;
    if ( variation == Variation::EFF_DATA && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.949828;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTID) ) return 0.952463;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.968299;
    if ( variation == Variation::STAT_UP && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.970417;
    if ( variation == Variation::CENTRAL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.969135;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.001094;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.967861;
    if ( variation == Variation::EFF_MC && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.993989;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.000182;
    if ( variation == Variation::EFF_DATA && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.963309;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTID) ) return 0.965974;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.959678;
    if ( variation == Variation::STAT_UP && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.961159;
    if ( variation == Variation::CENTRAL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.959682;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.001285;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.958173;
    if ( variation == Variation::EFF_MC && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.992632;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.000206;
    if ( variation == Variation::EFF_DATA && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.952611;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTID) ) return 0.958461;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.977823;
    if ( variation == Variation::STAT_UP && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.976015;
    if ( variation == Variation::CENTRAL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.974842;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.000985;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.973678;
    if ( variation == Variation::EFF_MC && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.993310;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.000181;
    if ( variation == Variation::EFF_DATA && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.968320;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTID) ) return 0.975752;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.966153;
    if ( variation == Variation::STAT_UP && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.967985;
    if ( variation == Variation::CENTRAL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.966171;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.001853;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.964006;
    if ( variation == Variation::EFF_MC && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.996606;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.000134;
    if ( variation == Variation::EFF_DATA && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.962891;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTID) ) return 0.960304;

    if ( variation == Variation::SYST_ALT_TEMPL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.928669;
    if ( variation == Variation::STAT_UP && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.934422;
    if ( variation == Variation::CENTRAL && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.929006;
    if ( variation == Variation::EFF_DATA_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.004408;
    if ( variation == Variation::STAT_DOWN && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.924550;
    if ( variation == Variation::EFF_MC && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.982765;
    if ( variation == Variation::EFF_MC_ERRSYM && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.000476;
    if ( variation == Variation::EFF_DATA && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.912995;
    if ( variation == Variation::SYST_CMSSHAPE && (probe_pt>=50 && probe_pt<1000 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTID) ) return 0.914240;

    return 1.; // Default
} 


float mHTTISO(float probe_pt, float probe_abseta, bool passingHTTIsoTight=true, bool passingHTTID=true, Variation variation=Variation::CENTRAL){
    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.969137;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.994507;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.968888;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.012950;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.945347;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.665660;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.003517;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.644951;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.965594;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.972640;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 1.008604;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.974493;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.018140;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.941189;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.678596;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.004853;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.661286;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.969525;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.956748;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.973381;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.956768;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.008959;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.941172;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.705838;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.002516;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.675323;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.959896;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.977875;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 1.002179;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.979001;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.016318;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.951865;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.734402;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.002209;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.718980;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.979592;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.976904;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.989341;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.976871;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.007308;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.964497;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.752193;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.002084;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.734795;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.976643;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.973843;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.983455;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.973847;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.005931;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.964400;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.794626;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.001683;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.773845;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.974285;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.974352;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.982243;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.974452;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.005586;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.965367;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.827272;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.001432;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.806137;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.979826;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.955596;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.965130;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.955742;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.006283;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.946370;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.852109;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.001789;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.814396;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=10 && probe_pt<20 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.957624;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.980056;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.977218;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.972902;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.002586;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.968598;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.836126;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.001045;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.813468;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.979178;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.960308;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.967378;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.960425;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.004297;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.953778;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.840974;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.001479;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.807693;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.961908;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.977381;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.992731;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.977409;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.007778;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.972310;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.843861;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.000853;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.824798;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.979809;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.989829;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.994578;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.989740;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.003018;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.985408;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.848546;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.000881;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.839840;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.990722;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.986812;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.991617;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.986690;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.002891;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.982824;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.858058;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.000893;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.846638;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.987439;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.986465;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.986487;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.983478;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.001932;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.980438;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.881278;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.000746;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.866717;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.986590;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.986064;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.989333;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.986184;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.002320;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.982866;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.907354;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.000623;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.894818;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.987198;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.982424;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.985019;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.981998;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.002014;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.979004;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.922812;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.000775;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.906199;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=20 && probe_pt<30 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.983846;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.983214;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.984968;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.983172;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.001224;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.981381;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.927675;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.000447;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.912065;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.983873;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.987474;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.990093;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.987463;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.001805;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.984826;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.926997;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.000645;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.915375;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.986292;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.987718;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.990905;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.987712;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.002588;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.984523;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.928129;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.000378;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.916723;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.988333;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.993244;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.995004;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.993252;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.001289;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.991365;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.928546;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.000403;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.922280;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.993169;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.994839;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.996635;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.995012;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.001094;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.993370;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.931063;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.000428;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.926420;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.995226;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.995278;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.996987;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.995290;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.001239;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.993595;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.943483;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.000363;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.939040;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.994875;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.996321;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.997430;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.996322;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.000749;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.995218;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.955907;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.000310;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.952391;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.996722;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.992201;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.993772;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.992340;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.001012;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.990903;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.966413;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.000377;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.959010;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=30 && probe_pt<40 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.992110;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.990302;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.991573;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.990356;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.000885;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.989105;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.966037;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.000310;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.956721;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.989129;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.991750;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.993576;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.991751;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.001335;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.989908;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.966051;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.000440;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.958082;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.991677;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.992308;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.993257;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.992284;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.000695;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.991316;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.967936;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.000247;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.960467;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.991884;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.992924;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.993951;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.993067;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.000614;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.992188;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.970037;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.000243;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.963312;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.992763;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.994836;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.996039;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.994634;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.000870;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.993751;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.971992;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.000243;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.966777;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.994494;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.996606;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.997333;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.996597;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.000518;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.995862;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.977984;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.000201;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.974656;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.996520;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.997502;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.998428;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.997536;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.000692;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.996647;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.982705;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.000184;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.980284;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.997069;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.996643;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.997698;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.996656;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.000758;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.995626;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.985488;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.000263;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.982193;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=40 && probe_pt<50 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.996561;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.993374;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.995160;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.993400;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.001325;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.991620;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.978557;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.000409;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.972098;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.0 && probe_abseta<0.2 && passingHTTIsoTight) ) return 0.992100;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.994250;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.996311;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.994134;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.001513;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.991991;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.977399;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.000601;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.971666;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.2 && probe_abseta<0.3 && passingHTTIsoTight) ) return 0.993616;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.995072;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.996413;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.995075;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.000992;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.993725;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.979580;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.000326;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.974756;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.3 && probe_abseta<0.6 && passingHTTIsoTight) ) return 0.994605;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.997059;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.998614;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.997195;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.001055;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.995789;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.979799;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.000330;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.977050;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.6 && probe_abseta<0.9 && passingHTTIsoTight) ) return 0.996574;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.996903;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.999643;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.997601;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.002585;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.993721;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.981688;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.000322;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.979333;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=0.9 && probe_abseta<1.2 && passingHTTIsoTight) ) return 0.996716;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.997769;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.998953;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.997770;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.000912;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.996563;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.985358;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.000266;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.983161;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.2 && probe_abseta<1.6 && passingHTTIsoTight) ) return 0.997501;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.997883;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.998548;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.997640;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.000645;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.996739;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.988042;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.000249;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.985710;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=1.6 && probe_abseta<2.1 && passingHTTIsoTight) ) return 0.998000;

    if ( variation == Variation::SYST_ALT_TEMPL && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.998721;
    if ( variation == Variation::STAT_UP && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 1.000467;
    if ( variation == Variation::CENTRAL && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.998752;
    if ( variation == Variation::EFF_DATA_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.001330;
    if ( variation == Variation::STAT_DOWN && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.997016;
    if ( variation == Variation::EFF_MC && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.989455;
    if ( variation == Variation::EFF_MC_ERRSYM && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.000378;
    if ( variation == Variation::EFF_DATA && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.988220;
    if ( variation == Variation::SYST_CMSSHAPE && (passingHTTID && probe_pt>=50 && probe_pt<1000 && probe_abseta>=2.1 && probe_abseta<2.4 && passingHTTIsoTight) ) return 0.998102;

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

