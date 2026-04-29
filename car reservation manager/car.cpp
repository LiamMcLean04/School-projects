//Liam McLean 40342966 Coen 244
#include "car.h"

int Car::NumberCarsCreated=0;
Car::Car(const char* category,const char* model){
    type= new char[strlen(category)+1];
    strcpy(type, category);
    name= new char[strlen(model)+1];
    strcpy(name, model);
    NumberCarsCreated++;
    CaridNumb= NumberCarsCreated;
    available = true;
    customerid=0;
}
Car::Car() {
    type= new char[1];
    name= new char[1];
    NumberCarsCreated++;
    CaridNumb= NumberCarsCreated;
    available = true;
    customerid=0;
}
Car::~Car() {
    delete[] type;
    delete[] name;
}
//assumed that original car would be the prototype(i.e. first instance of unique object)
//Therefore on subsequent copies would be replicas and not the original hence the increment of car id
Car::Car(const Car& car){
    type= new char[strlen(car.type)+1];
    strcpy(type, car.type);
    name= new char[strlen(car.name)+1];
    strcpy(name, car.name);
    available= true;
    NumberCarsCreated++;
    CaridNumb= NumberCarsCreated;
    customerid=0;
}

char* Car::getName() const {return name;}
bool Car::getAvailability() const {return available;}
int Car::getCaridNumb() const {return CaridNumb;}
char *Car::GetType() const {return type;}
Date Car::GetCheckInDate() const {return CheckInDate;}
Date Car::GetCheckOutDate() const {return CheckOutDate;}
int Car::GetCustomerId() const {return customerid;}

void Car::SetType(const char*& newType) {
    delete[] type;
    type= new char[strlen(newType)+1];
    strcpy(type,newType);
}
void Car::setName(const char*& model) {
    delete[] name;
    name= new char[strlen(model)+1];

}
void Car::setAvailable(const bool& availability) {available= availability;}
void Car::SetCustomerId(const int& customerId) {customerid= customerId;}
void Car::SetCheckInDate(const Date& checkInDate) {CheckInDate=checkInDate;}
void Car::SetCheckOutDate(const Date & checkOutDate) {CheckOutDate=checkOutDate;}
