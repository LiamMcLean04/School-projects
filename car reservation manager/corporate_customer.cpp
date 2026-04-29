//Liam McLean 40342966 Coen 244
#include "corprate_customer.h"

corporate_customer::corporate_customer():Customers() {
    affilate=new char[1];
    affilate[0]='\0';
}

corporate_customer::corporate_customer(const char * asscociate, const char* first,const char* last,const char* tele,const char* addynumb,const char* street,const char* postal,const char* city,const char* provorstate,const char* country,Date check, int numdays):Customers(first,last,tele,addynumb,street,postal,city,provorstate,country,check,numdays) {
    affilate=new char[strlen(asscociate)+1];
    strcpy(affilate,asscociate);
}
corporate_customer::corporate_customer(const char* asscociate,const char* first,const char* last,const char* tele, address& addy,const Date& checkin,const int& numdays):Customers(first,last,tele,addy,checkin,numdays) {
    this->checkinday= checkin;
    affilate=new char[strlen(asscociate)+1];
    strcpy(affilate,asscociate);
}

corporate_customer::corporate_customer(const corporate_customer & other):Customers(other) {
    affilate= new char[strlen(other.affilate)+1];
    strcpy(affilate,other.affilate);
}

corporate_customer::~corporate_customer() {
    delete[] affilate;
}

void corporate_customer::set_affilate(char* asscociate) {
    delete[] affilate;
    affilate=new char[strlen(asscociate)+1];
    strcpy(affilate,asscociate);
}
char* corporate_customer::get_affilate() {return affilate;}

void corporate_customer::print() const {
    std::cout<<"Customer info: "<<std::endl;
    std::cout<<"Customer id: " << customer_numb<<std::endl;
    std::cout<<"Customer name: "<<fname<<" " << lname <<std::endl;
    std::cout<<"Customer telephone number: "<<telenumb<<std::endl;
    spefaddress->print();
    std::cout<<"checkin date: ";
    checkinday.returndate();
    std::cout<< std::endl;
    std::cout<< "Number of days: " << numberodays<<std::endl;
    std::cout<< "Association: " << affilate<<std::endl;
}
