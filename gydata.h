#ifndef GYDATA
#define GYDATA

struct GYData{
    int ac_v;
    float dc_v;
    float dc_i;

    unsigned short faultBit1;
    unsigned short faultBit2;

    GYData():ac_v(0), dc_v(0.0), dc_i(0.0), faultBit1(0), faultBit2(0){}
};

#endif // GYDATA

