//Liam McLean 40342966 Coen 244
#include "StandardCar.h"

standardCar::standardCar(): Car() {kmperliter=0;}
standardCar::standardCar(int a, const char * category, const char * model): Car(category,model) {kmperliter= a;}

standardCar::standardCar(const standardCar & Standardcar):Car(Standardcar),kmperliter(Standardcar.kmperliter) {}

standardCar::~standardCar() {}
void standardCar::printbasicdetails() const {
    std::cout << "Standard Car Name: " << name << std::endl;
    std::cout << "Category: " << type<< std::endl;
    std::cout << "Car id: " <<  CaridNumb<< std::endl;
    std:: cout << "Availability: " << available << std::endl;
    std::cout << "Check in date: "; CheckInDate.returndate();std:: cout <<std::endl;
    std::cout << "Check out date: "; CheckOutDate.returndate();std:: cout <<std::endl;
    std::cout << "Customer renting id: "<< customerid<<std::endl;
    std:: cout << "Fuel efficiency in Km/l: " <<kmperliter<< std::endl;
}
int standardCar::getkmperliter() const {return kmperliter;}
void standardCar::setkmperliter(int a) {kmperliter = a;}