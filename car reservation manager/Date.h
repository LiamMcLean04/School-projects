//Liam Mclean 40342966

#ifndef DATE_H
#define DATE_H


#include <iostream>

class Date {
private:
    int month;
    int day;
    int year;

public:
    // Constructors
    Date();
    Date(const int m,const int d,const int y);
    Date(const Date& other);

    // Destructor
    ~Date();

    // Setters
    void setMonth(int m);
    void setDay(int d);
    void setYear(int y);

    // Getters
    int getMonth() const;
    int getDay() const;
    int getYear() const;

    //logical operators
    bool InRange(const Date&,const Date&);
    int getdifference(const Date&);
    Date adddays(const size_t);

    // Print function
    void print() const;
    void returndate () const;

    //operator overload (not used in this assigment, was made to learn)
    Date& operator=(const Date& other);
};

#endif