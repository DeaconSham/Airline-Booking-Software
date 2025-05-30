#include "Person.h"
#include <iostream>

Person::Person() : name(""), address(""), phoneNumber("") {}

Person::Person(const std::string& n, const std::string& addr, const std::string& phone) : name(n), address(addr), phoneNumber(phone) {}

Person::~Person() {}

std::string Person::getName() const {
    return name;
}

std::string Person::getAddress() const {
    return address;
}

std::string Person::getPhoneNumber() const {
    return phoneNumber;
}

void Person::setName(const std::string& n) {name = n;}
void Person::setAddress(const std::string& addr) {address = addr;}
void Person::setPhoneNumber(const std::string& phone) {phoneNumber = phone;}

void Person::display() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "Phone: " << phoneNumber << std::endl;
}