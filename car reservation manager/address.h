//Liam McLean 40342966 Coen 244
#ifndef ADDRESS_H
#define ADDRESS_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
// for simplicity's sake assumed not an apartment as would not change functionality
// but add a ton of tedious work that does not demo understanding, rather repetition.
class address {
    private:
        char* Street;
        char* City;
        char* Country;
        char* ProvOrState;
        char* AddNumber;
        char* PostalCode;

    public:
        //constructs and decontructs
        address(const char* addynum,const char* street,const char* postal,const char* city,const char* provorstate,const char* country);
        address();
        address(const address&);
        ~address();
        //gets
        char* getStreet()const;
        char* getCity()const;
        char* getCountry()const;
        char* getPostalCode()const;
        char* getAddNumber()const;
        char* getProvOrState()const;
        //sets
        void setStreet(char*);
        void setCity(char*);
        void setCountry(char*);
        void setPostalCode(char*);
        void setAddNumber(char*);
        void setProvOrState(char*);
        //print
        void print()const;
};

#endif