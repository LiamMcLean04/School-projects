//Liam McLean 40342966 Coen 244
#ifndef CORPRATE_CUSTOMER_H
#define CORPRATE_CUSTOMER_H
#include "Customers.h"
class corporate_customer: public Customers{
    private:
    char* affilate;

    public:
    //constructs and deconstructs
    corporate_customer();
    corporate_customer(const char* asscociate,const char* first,const char* last,const char* tele, address& addy,const Date& checkin,const int& numdays);
    corporate_customer(const char*,const char*,const char*,const char*,const char*,const char*,const char*,const char*,const char*,const char*,Date,int);
    corporate_customer(const corporate_customer&);
    virtual ~corporate_customer();
    //gets and sets
    void set_affilate(char*);
    char* get_affilate();
    //abstr overide
    virtual void print()const override;
};
#endif