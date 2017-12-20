#ifndef GYDATA
#define GYDATA

struct GYData{
    int ac_v;
    float dc_v;
    float dc_i;

    unsigned short faultBit;
    unsigned short warnBit;

    GYData():ac_v(0), dc_v(0.0), dc_i(0.0), faultBit(0), warnBit(0){}
};

#endif // GYDATA

