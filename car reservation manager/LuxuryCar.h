//Liam McLean 40342966 Coen 244
#ifndef LUXURYCAR_H
#define LUXURYCAR_H
#include "car.h"
class LuxuryCar: public Car{
    private:
    //unique attribute
        char* interior;

    public:
        LuxuryCar();
        LuxuryCar(const char*,const char*, const char*);
        LuxuryCar(const LuxuryCar&);
        virtual ~LuxuryCar();

        void setInterior(const char*&);
        char* getInterior() const;
        //virtual override
        virtual void printbasicdetails() const override;
};
#endif