#ifndef GYDATA
#define GYDATA

struct GYData{
    int ac_v;
    float dc_v;
    float dc_i;
    float t;

    unsigned short faultBit;
    unsigned short warnBit;

    GYData():ac_v(0), dc_v(0.0), dc_i(0.0), faultBit(0), warnBit(0){}

    bool isFault() const{
        if(ac_v<200 || ac_v>230){
            return true;
        }

        return false;
    }

    bool isWarn() const{
        if(dc_v<600 || dc_v>720 || dc_i>3 || t>60){
            return true;
        }

        return false;
    }
};

#endif // GYDATA

