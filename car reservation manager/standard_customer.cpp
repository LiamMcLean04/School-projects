//Liam McLean 40342966 Coen 244
#include "standard_customer.h"

standard_customer::standard_customer():Customers() {
    desiredmilage=0;
}
standard_customer::standard_customer(const int& milagekm,const char* first, const char* last, const char* tele, address& addy,const Date& checkin,const int& numdays):Customers(first,last,tele,addy,checkin,numdays) {
    desiredmilage=milagekm;
}

standard_customer::standard_customer(const int & desiredmilleage,const char* first,const char* last,const char* tele,const char* addynumb,const char* street,const char* postal,const char* city,const char* provorstate,const char* country,Date check, int numdays):Customers(first,last,tele,addynumb,street,postal,city,provorstate,country,check,numdays),desiredmilage(desiredmilleage) {}

standard_customer::standard_customer(const standard_customer & other):Customers(other) {
    desiredmilage= other.desiredmilage;
}

standard_customer::~standard_customer() {}


int standard_customer::getdesiredmilage() const {return desiredmilage;}
void standard_customer::setdesiredmilage(int Desiredmilage) {desiredmilage=Desiredmilage;}
void standard_customer::print() const {
    std::cout<<"Customer info: "<<std::endl;
    std::cout<<"Customer id: " << customer_numb<<std::endl;
    std::cout<<"Customer name: "<<fname<<" " << lname <<std::endl;
    std::cout<<"Customer telephone number: "<<telenumb<<std::endl;
    spefaddress->print();
    std::cout<<"checkin date: ";
    checkinday.returndate();
    std::cout<< std::endl;
    std::cout<< "Number of days: " << numberodays<<std::endl;
    std::cout<<"desired millage: "<<desiredmilage<<std::endl;
}