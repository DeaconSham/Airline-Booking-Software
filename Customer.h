#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Person.h" //For Person base class (inheritance).
#include <iostream>
#include <string>

//Represents a customer, inheriting details from Person.
class Customer : public Person {
    public:
        Customer(const std::string& n, const std::string& addr, const std::string& phone); ///Constructor: Initializes Customer with name (n), address (addr), and phone.
        ~Customer(); //Destructor: Handles Customer cleanup (if any specific).
        void display() const override; //Displays customer information; overrides Person's display method.
};

#endif