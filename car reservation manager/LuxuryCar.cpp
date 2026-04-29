//Liam McLean 40342966 Coen 244
#include "LuxuryCar.h"

LuxuryCar::LuxuryCar(): Car() {
    interior= new char[1];
    interior[0]= '\0';
}

LuxuryCar::LuxuryCar(const char* inside, const char * category, const char * model): Car(category, model) {
    interior= new char[strlen(inside) + 1];
    strcpy(interior, inside);
}

LuxuryCar::LuxuryCar(const LuxuryCar & luxury_car):Car(luxury_car){
interior= new char[strlen(luxury_car.interior) + 1];
strcpy(interior, luxury_car.interior);
}

LuxuryCar::~LuxuryCar() {
    delete[] interior;
}

void LuxuryCar::setInterior(const char *& insde) {
    delete[] interior;
    interior= new char[strlen(insde) + 1];
    strcpy(interior, insde);
}

char* LuxuryCar::getInterior() const {return interior;}

void LuxuryCar::printbasicdetails() const {
    std::cout << "Luxury Car Name: " << name << std::endl;
    std::cout << "Category: " << type<< std::endl;
    std::cout << "Car id: " <<  CaridNumb<< std::endl;
    std::cout << "Availability: " << available << std::endl;
    std::cout << "Check in date: "; CheckInDate.returndate();std:: cout <<std::endl;
    std::cout << "Checkout date: "; CheckOutDate.returndate();std:: cout <<std::endl;
    std::cout << "Customer renting id: "<< customerid<<std::endl;
    std::cout << "Interior material: " << interior << std::endl;
}
