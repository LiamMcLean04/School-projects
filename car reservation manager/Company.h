//Liam McLean 40342966 Coen 244
#ifndef COMPANY_H
#define COMPANY_H
#include "standard_customer.h"
#include "corprate_customer.h"
#include "LuxuryCar.h"
#include "StandardCar.h"
// For my company class I will not need any constructors other than a default as all
class Company {
private:
    static const int maxnumber=1000;
    Car* inventory[maxnumber];
    Customers* customers[maxnumber];
    int carsininventory;
    int customerinsystem;

    public:
    //constructor/deconstructor
    Company();
    ~Company();
    //member functions
    void addcar(const LuxuryCar&);
    void addcar(const standardCar&);
    void removecarbyid(int);
    void addcustomer(const standard_customer&);
    void addcustomer(const corporate_customer&);
    void removecustomerbyid(int);
    void rent(int carid ,int customerid);
    void removerental(int carid);
    void getcustomerdetailsbyid(int) const;
    void getcardetailsbyid(int) const;
    void getcarbyplace(int)const;



};
#endif