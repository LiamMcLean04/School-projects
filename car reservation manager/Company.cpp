//Liam McLean 40342966 Coen 244
#include "Company.h"

Company::Company():inventory{},customers{},carsininventory(0),customerinsystem(0) {}

void Company::addcar(const LuxuryCar & banana) {
    inventory[carsininventory]= new LuxuryCar(banana);
    carsininventory++;
}

void Company::addcar(const standardCar & banana) {
    inventory[carsininventory]= new standardCar(banana);
    carsininventory++;
}
void Company:: rent(int carid ,int customerid) {
    if (carid<=0||customerid<=0) {
        std::cout<<"invalid id";
        return;
    }
    for (int i=0;i<carsininventory;i++) {
        if (inventory[i]==nullptr) {
            std::cout << "invalid car id";
            return;
        }else if (inventory[i]->getCaridNumb()==carid) {
            if (inventory[i]->getAvailability()==true) {
                for (int j=0;j<customerinsystem;j++){
                    if (customers[j]==nullptr) {
                        std::cout << "invalid customer id";
                        return;
                    }
                    if (customers[j]->getCustomerNumb()==customerid) {
                        inventory[i]->setAvailable(false);
                        inventory[i]->SetCheckInDate(customers[j]->getCheckInDate());
                        inventory[i]->SetCheckOutDate(customers[j]->getCheckInDate().adddays(customers[j]->getNumberofdays()-1));
                        inventory[i]->SetCustomerId(customerid);
                    }
                }
            }else {
                std::cout << "car not available"<<std::endl;
                return;
            }
        }
    }
}
void Company::removecarbyid(int kill) {
        for (int i=0;i<carsininventory;i++) {
            if (inventory[i]==nullptr) {
                break;
            }
            if (inventory[i]->getCaridNumb()==kill) {
                delete inventory[i];
                for (int j=i+1;j<carsininventory;j++) {
                    inventory[j-1]=inventory[j];
                }
                carsininventory--;
                inventory[carsininventory]= nullptr;
                std::cout<<"Removed car: "<<kill<<std::endl;
                return;
            }
        }
        std::cout<<"not found, therefore not removed."<<std::endl;
    }
void Company::addcustomer(const corporate_customer & banana) {
    customers[customerinsystem]=new corporate_customer(banana);
    customerinsystem++;
}

void Company::addcustomer(const standard_customer & banana) {
    customers[customerinsystem]= new standard_customer(banana);
    customerinsystem++;
}
void Company::removecustomerbyid(int kill) {
    for (int i=0;i<carsininventory;i++) {
        if (inventory[i]==nullptr) {
            break;
        }
        if (inventory[i]->GetCustomerId()==kill) {
            inventory[i]->setAvailable(true);
            inventory[i]->SetCheckInDate(Date(0,0,0));
            inventory[i]->SetCheckOutDate(Date(0,0,0));
            inventory[i]->SetCustomerId(0);
        }
    }
    for (int i=0;i<customerinsystem;i++) {
        if (customers[i]->getCustomerNumb()==kill) {
            delete customers[i];
            for (int j=i;j< customerinsystem-1;j++) {
                customers[j]=customers[j+1];
            }
            customerinsystem--;
            customers[customerinsystem]= nullptr;
            std::cout<<"Removed customer: "<<kill<<std::endl;
            return;
        }
    }
    std::cout<<"not found, therefore not removed."<<std::endl;
}
void Company::getcardetailsbyid(int banana) const{
    for (int i=0;i<carsininventory;i++) {
        if (inventory[i]==nullptr) {
            break;
        }
        if (inventory[i]->getCaridNumb()==banana) {
            inventory[i]->printbasicdetails();
            return;
        }
        }
    std::cout<< "id not found"<<std::endl;
    }


void Company::getcustomerdetailsbyid(int banana) const {
    for (int i=0;i<customerinsystem;i++) {
        if (customers[i]==nullptr) {
            break;
        }
        if (customers[i]->getCustomerNumb()==banana) {
            customers[i]->print();
            return;
        }
    }
    std::cout<<"id not found";
}
void Company::getcarbyplace(int kill) const {
    if (inventory[kill-1]==nullptr||kill<0||kill>=maxnumber) {
        std::cout<<"invalid object";
        return;
    }
    if (inventory[kill-1]!=nullptr) {
        inventory[kill-1]->printbasicdetails();
    }
}
void Company::removerental(int carid) {
    for (int i=0;i<carsininventory;i++) {
        if (inventory[i]==nullptr) {
            break;
        }
        if (inventory[i]->GetCustomerId()==carid) {
            inventory[i]->setAvailable(true);
            inventory[i]->SetCheckInDate(Date(0,0,0));
            inventory[i]->SetCheckOutDate(Date(0,0,0));
            inventory[i]->SetCustomerId(0);
            std::cout<< "customer rental removed.";
        }
    }
    std::cout<<"id not found"<<std::endl;
}


Company::~Company() {
    for (int i=0;i<carsininventory;i++) {
        if (inventory[i]==nullptr) {
            break;
        }
        delete inventory[i];
        inventory[i]= nullptr;
    }
    for (int i=0;i<customerinsystem;i++) {
        if (customers[i]==nullptr) {
            break;
        }
        delete customers[i];
        customers[i]= nullptr;
    }
}

