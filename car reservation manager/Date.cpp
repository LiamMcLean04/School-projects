//Liam Mclean 40342966

#include <iostream>
#include "Date.h"

using namespace std;

// Default constructor
Date::Date() {
    month = 1;
    day = 1;
    year = 2001;
}

// Parameterized constructor
Date::Date(const int m,const int d,const int y):month(m),day(d),year(y) {}

// Copy constructor
Date::Date(const Date& other)
    : month(other.month), day(other.day), year(other.year) {
}


// Destructor
Date::~Date() {

}

// Setters
void Date::setMonth(int m) {
    month = m;
}

void Date::setDay(int d) {
    day = d;
}

void Date::setYear(int y) {
    year = y;
}

// Getters
int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

int Date::getYear() const {
    return year;
}

// Print function
void Date::print() const {
    cout << "Month: " << month << endl;
    cout << "Day: " << day << endl;
    cout << "Year: " << year << endl;
}
void Date::returndate() const{
    cout << year<<"/"<<month<<"/"<<day;
}

bool Date:: InRange(const Date& a,const Date& b){
    if (a.getYear()==year || b.getYear()==year){
        if(a.getMonth() == month || b.getMonth() == month){
            if (a.getDay() <= day && b.getDay() >=day){
                return true;
            }
        }     
    }else
        return false;
}
int Date:: getdifference(const Date& a){
    //date a must be greater than date the function is being used on being differed 
    //6 cases for finding number of days
    if (a.getYear()!= year){
        return a.getDay()-(day-32);
    }else
    if(a.getMonth()>month){
        if(month==1||month==3||month==5||month==7||month==8||month==10){
            return a.getDay()-(day-32);
        }else if (month==4||month==6||month==9||month==11){
            return a.getDay()-(day-31);
        }else if(year%4==0){
        return a.getDay()-(day-30);
        }else 
        return a.getDay()-(day-29);
    }else
    return a.getDay()-day+1;
}
Date Date::adddays(const size_t b){
    //int is days<31
    //if cases are for diferent edge cases
    int tempmonth,tempyear,tempday;
    if (day+b>31 && month==12){
        tempday= (day-31)+b;
        tempmonth=1;
        tempyear=year+1;
        return Date(tempmonth,tempday,tempyear);
    }else if (day+b>31 && (month==1||month==3||month==5||month==7||month==8||month==10)){
        tempday= (day-31)+b;
        tempmonth=month+1;
        tempyear=year;
        return Date(tempmonth,tempday,tempyear);
    }else if (day+b>31 && (month==4||month==6||month==9||month==11)){
        tempday= (day-31)+b;
        tempmonth=month+1;
        tempyear=year;
        return Date(tempmonth,tempday,tempyear);
    }else if (day+b>29 && year%4==0 && month==2){
        tempday= (day-29)+b;
        tempmonth=month+1;
        tempyear=year;
        return Date(tempmonth,tempday,tempyear);
    }else if (day+b>29 && year%4==0 && month==2){
        tempday= (day-29)+b;
        tempmonth=month+1;
        tempyear=year;
        return Date(tempmonth,tempday,tempyear);
    }else if (day+b>28 && month==2){
        tempday= (day-28)+b;
        tempmonth=month+1;
        tempyear=year;
        return Date(tempmonth,tempday,tempyear);
    }else 
    tempday= day+b;
    tempmonth=month;
    tempyear=year;
    return Date(tempmonth,tempday,tempyear);
}
Date& Date::operator=(const Date& other) {
    if (this==&other) {
        return *this;
    }
    this->year=other.year;
    this->month=other.month;
    this->day=other.day;
    return *this;

}