//Liam McLean 40342966 Coen 244
#include "address.h"

address::address(const char* addynum,const char* street,const char* postal,const char* city,const char* provorstate,const char* country) {
    AddNumber=new char[strlen(addynum)+1];
    strcpy(AddNumber, addynum);
    Street= new char[strlen(street)+1];
    strcpy(Street, street);
    PostalCode= new char[strlen(postal)+1];
    strcpy(PostalCode, postal);
    City= new char[strlen(city)+1];
    strcpy(City, city);
    ProvOrState= new char[strlen(provorstate)+1];
    strcpy(ProvOrState, provorstate);
    Country= new char[strlen(country)+1];
    strcpy(Country, country);
}
address::address() {
    AddNumber=new char[1];
    Street=new char[1];
    PostalCode=new char[1];
    City=new char[1];
    ProvOrState=new char[1];
    Country=new char[1];
}

address::address( const address& banana) {
    Street= new char[strlen(banana.getStreet())+1];
    strcpy (Street, banana.getStreet());
    AddNumber=new char[strlen(banana.getAddNumber())+1];
    strcpy (AddNumber, banana.getAddNumber());
    PostalCode= new char[strlen(banana.getPostalCode())+1];
    strcpy (PostalCode, banana.getPostalCode());
    City= new char[strlen(banana.getCity())+1];
    strcpy (City, banana.getCity());
    ProvOrState= new char[strlen(banana.getProvOrState())+1];
    strcpy (ProvOrState, banana.getProvOrState());
    Country= new char[strlen(banana.getCountry())+1];
    strcpy (Country, banana.getCountry());
}

address::~address() {
    delete[] AddNumber;
    delete[] Street;
    delete[] PostalCode;
    delete[] City;
    delete[] ProvOrState;
    delete[] Country;
}
char* address::getAddNumber()const {return AddNumber;}
char* address::getStreet()const {return Street;}
char* address::getPostalCode()const {return PostalCode;}
char* address::getCity()const {return City;}
char* address::getProvOrState()const {return ProvOrState;}
char* address::getCountry()const {return Country;}

void address::setAddNumber(char * number) {
    delete[] AddNumber;
    AddNumber=new char[strlen(number)+1];
    strcpy(AddNumber, number);
}
void address::setStreet(char* street) {
    delete[] Street;
    Street=new char[strlen(street)+1];
    strcpy(Street, street);
}
void address::setPostalCode(char* postal) {
    delete[] PostalCode;
    PostalCode=new char[strlen(postal)+1];
    strcpy(PostalCode, postal);
}
void address::setCity(char* city) {
    delete[] City;
    City=new char[strlen(city)+1];
    strcpy(City, city);
}
void address::setProvOrState(char* provorstate) {
    delete[] ProvOrState;
    ProvOrState=new char[strlen(provorstate)+1];
    strcpy(ProvOrState, provorstate);
}
void address::setCountry(char* country) {
    delete[] Country;
    Country=new char[strlen(country)+1];
    strcpy(Country, country);
}
void address::print() const {
    std::cout << "The Address is: " << AddNumber  <<" "<< Street <<" "<< City << ", "<< ProvOrState <<", "<< PostalCode<<", "<< Country<< std::endl;
}
