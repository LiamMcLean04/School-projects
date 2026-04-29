//Liam McLean 40342966 Coen 244
#include "Company.h"

int main() {
    //car stuff
    LuxuryCar luxuryCar("matted leather", "converible", "Mercades");
    standardCar StandardCar(70, "Hatch Back", "Chevorley");
    //customer stuff
    address ban("123","seasme street","h87 k19","detroit","quebec","canada");
    address poke("765","mos","h87 95t","bananaville","texas","United Kingdom");
    Date l(9,7,2004);
    Date p(6,23,2006);
    standard_customer look(986,"joe","mcboe","598-672-856",ban,l,12);
    corporate_customer bak("blackrock", "Randal","the evil","74985-imevil",poke,p,3);
    Company CoenCars;
    CoenCars.addcar(luxuryCar);
    CoenCars.addcar(StandardCar);
    CoenCars.addcustomer(look);
    CoenCars.addcustomer(bak);
    CoenCars.getcarbyplace(1);
    CoenCars.getcarbyplace(2);
    CoenCars.getcustomerdetailsbyid(1);
    CoenCars.getcustomerdetailsbyid(2);
    CoenCars.rent(3,1);
    CoenCars.rent(4,1);
    CoenCars.getcarbyplace(1);
    CoenCars.getcarbyplace(2);
    CoenCars.rent(4,2);
    CoenCars.removecustomerbyid(1);
    CoenCars.rent(4,2);
    CoenCars.getcardetailsbyid(4);

    return 0;

}