#include "Seat.h"
#include "Customer.h"
#include <iostream>
#include <iomanip>

Seat::Seat() : seatNumber(0), isReserved(false), customer(nullptr) {}

Seat::~Seat() {
    delete customer;
    customer = nullptr;
}

void Seat::initialize(int number) {
    seatNumber = number;
    isReserved = false;
    customer = nullptr;
}

int Seat::getSeatNumber() const {
    return seatNumber;
}

bool Seat::getIsReserved() const {
    return isReserved;
}

Customer* Seat::getCustomer() const {
    return customer;
}

bool Seat::reserve(Customer* cust) {
    if (!isReserved && cust != nullptr) { // to check for cust != nullptr
        customer = cust;
        isReserved = true;
        return true;
    }
    // If cust is nullptr or seat is reserved, don't take seat
    // Flight::bookSeat should delete cust if it's not used
    return false;
}

bool Seat::cancel() {
    if (isReserved) {
        delete customer;
        customer = nullptr;
        isReserved = false;
        return true;
    }
    return false;
}

void Seat::displayStatus() const {
    std::cout << "Seat " << std::setw(2) << seatNumber << ": ";
    if (isReserved && customer) {
        std::cout << "Reserved (by " << customer->getName() << ")";
    }
    else {
        std::cout << "Available";
    }
    std::cout << std::endl;
}