//Liam McLean 40342966 Coen 244
#ifndef CUSTOMERS_H
#define CUSTOMERS_H
#include "address.h"
#include "Date.h"
class Customers{
    protected:
        int customer_numb;
        char* fname;
        char* lname;
        char* telenumb;
        address* spefaddress;
        static int numberofcustomers;
        Date checkinday;
        int numberodays;

    public:
        //constructors
        Customers();
        Customers(const char*, const char*, const char*,address&,const Date&,const int&);
        Customers(const char*,const char*,const char*,const char*,const char*,const char*,const char*,const char*,const char*,const Date&,int);
        Customers(const Customers&);
        virtual ~Customers();
        //getter
        int getCustomerNumb()const;
        char* getLname()const;
        char* getTelenum()const;
        char* getFname()const;
        address* getSpefAddress()const;
        Date getCheckInDate()const;
        int getNumberofdays()const;
        //setter
        void setLname(const char*);
        void setTelenum(const char*);
        void setFname(const char*);
        void setSpefAddress(address&);
        //abstract member function
        virtual void print()const =0;
};

#endif