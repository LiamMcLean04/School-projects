//Liam McLean 40342966 Coen 244
#include "Customers.h"
int Customers::numberofcustomers=0;
Customers::Customers():checkinday() {
    numberofcustomers++;
    customer_numb=numberofcustomers;
    fname=new char[1];
    lname=new char[1];
    telenumb=new char[1];
    spefaddress=new address;
    numberodays=0;
}

Customers::Customers(const char* first,const char* last,const  char* tele, address& addy, const Date& checkin,const int& numdays):checkinday(checkin){
    fname= new char[strlen(first)+1];
    strcpy(fname,first);
    lname= new char[strlen(last)+1];
    strcpy(lname,last);
    telenumb= new char[strlen(tele)+1];
    strcpy(telenumb,tele);
    spefaddress=new address(addy);
    numberofcustomers++;
    customer_numb=numberofcustomers;
    numberodays= numdays;
    checkinday.returndate();std::cout <<std::endl;
}
Customers::Customers(const char* first,const char* last,const char* tele,const char* addynumb,const char* street,const char* postal,const char* city,const char* provorstate,const char* country,const Date& check, int numdays):checkinday(check){
    fname= new char[strlen(first)+1];
    strcpy(fname,first);
    lname= new char[strlen(last)+1];
    strcpy(lname,last);
    telenumb= new char[strlen(tele)+1];
    strcpy(telenumb,tele);
    spefaddress= new address(addynumb,street,postal,city,provorstate,country);
    numberofcustomers++;
    customer_numb=numberofcustomers;
    numberodays= numdays;
}
// assuming that each person is unqiue and not a clone of another with identacal charecteristics, so no increment of id
//on copy
Customers::Customers(const Customers& banana):checkinday(banana.checkinday){
    customer_numb=banana.customer_numb;
    fname= new char[strlen(banana.fname)+1];
    strcpy(fname,banana.fname);
    lname= new char[strlen(banana.lname)+1];
    strcpy(lname,banana.lname);
    telenumb=new char[strlen(banana.telenumb)+1];
    strcpy(telenumb,banana.telenumb);
    spefaddress=new address(*(banana.spefaddress));
    numberodays= banana.numberodays;
}
int Customers::getCustomerNumb()const {return customer_numb;}
char* Customers::getFname()const {return fname;}
char* Customers::getLname()const {return lname;}
char* Customers::getTelenum()const {return telenumb;}
address* Customers::getSpefAddress()const {return spefaddress;}
Date Customers::getCheckInDate()const {return checkinday;}
int Customers::getNumberofdays() const {return numberodays;}

void Customers::setSpefAddress(address& spef) {spefaddress=&spef;}

void Customers::setLname(const char* Lname) {
    delete [] lname;
    lname=new char[strlen(Lname)+1];
    strcpy(lname,Lname);
}
void Customers::setTelenum(const char* tele) {
    delete [] telenumb;
    telenumb=new char[strlen(tele)+1];
    strcpy(telenumb,tele);
}
void Customers::setFname(const char * Fname) {
    delete [] fname;
    fname=new char[strlen(Fname)+1];
    strcpy(fname,Fname);
}
Customers::~Customers() {
    delete[] fname;
    delete[] lname;
    delete[] telenumb;
    delete spefaddress;
}
