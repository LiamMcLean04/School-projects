//Liam McLean 40342966 Coen 244
#ifndef ASSIGMENT_2_STANDARDCAR_H
#define ASSIGMENT_2_STANDARDCAR_H
#include "car.h"

class standardCar: public Car {
    private:
    //unique attribute
    int kmperliter;
    public:
    //constructs and deconstructs
    standardCar();
    standardCar(int,const char*, const char*);
    standardCar(const standardCar&);
    virtual ~standardCar();
    //virt
    virtual void printbasicdetails() const override;
    //gets and sets
    int getkmperliter() const;
    void setkmperliter(int);

};
#endif //ASSIGMENT_2_STANDARDCAR_H