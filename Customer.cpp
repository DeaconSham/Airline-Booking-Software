#include "Customer.h"
#include <iostream>

Customer::Customer(const std::string& n, const std::string& addr, const std::string& phone) : Person(n, addr, phone) {}

Customer::~Customer() {}

void Customer::display() const {
    Person::display();
}