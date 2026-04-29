//Liam McLean 40342966 Coen 244
#ifndef car_H
#define car_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include "Date.h"
//assumed car created would be available company will change status and dates
class Car {
    protected:
    //car deats
        char* type;
        char* name;
        int CaridNumb;
    //customer accessable members
        bool available;
        static int NumberCarsCreated;
        Date CheckInDate;
        Date CheckOutDate;
        int customerid;

    public:
    //constructs and deconstructs
    Car(const char*, const char*);
    Car();
    Car(const Car&);
    virtual ~Car();
    //abstract virtual print
    virtual void printbasicdetails () const = 0;
    //set
    void setName(const char*&);
    void setAvailable(const bool&);
    void SetType(const char*&);
    void SetCustomerId(const int&);
    void SetCheckInDate(const Date&);
    void SetCheckOutDate(const Date&);
    //gets
    bool getAvailability() const;
    char* getName() const;
    int getCaridNumb() const;
    char* GetType() const;
    Date GetCheckInDate() const;
    Date GetCheckOutDate() const;
    int GetCustomerId() const;

};
#endif