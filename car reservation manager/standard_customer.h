//Liam McLean 40342966 Coen 244
#ifndef STANDARD_CUSTOMER_H
#define STANDARD_CUSTOMER_H
#include "Customers.h"

class standard_customer: public Customers {
    private:
    int desiredmilage;
    public:
    //constructors/deconstructor
    standard_customer();
    standard_customer(const int& milagekm,const char* first, const char* last, const char* tele, address& addy,const Date& checkin,const int& numdays);
    standard_customer(const int&,const char*,const char*,const char*,const char*,const char*,const char*,const char*,const char*,const char*,Date,int);
    standard_customer(const standard_customer&);
    virtual ~standard_customer();
    //gets and sets
    int getdesiredmilage() const;
    void setdesiredmilage(int);
    //virt override
    virtual void print() const override;

};

#endif