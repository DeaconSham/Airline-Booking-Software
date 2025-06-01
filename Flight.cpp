#include "Flight.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

Flight::Flight() : flightNumber(""), numReservedSeats(0) {
    for (int i = 0; i < MAX_SEATS_PER_FLIGHT; i++) {
        seats[i].initialize(i + 1); //Seats numbers
    }
}

Flight::Flight(const std::string& fn) : flightNumber(fn), numReservedSeats(0) {
    for (int i = 0; i < MAX_SEATS_PER_FLIGHT; i++) {
        seats[i].initialize(i + 1);
    }
}
//Destructor for Flight is defined and will call destructors for Seat members

std::string Flight::getFlightNumber() const {return flightNumber;}
int Flight::getNumReservedSeats() const {return numReservedSeats;}
bool Flight::isSeatAvailable(int seatNum) const {
    if (seatNum < 1 || seatNum > MAX_SEATS_PER_FLIGHT) {
        return false; // Invalid seat number
    }
    return !seats[seatNum - 1].getIsReserved();
}

int Flight::countAvailableRecursiveHelper(int index) const {
    int count;
    if (index < 0) {
        return 0;
    }
    if (seats[index].getIsReserved()) {
        count = 0;
    } else {
        count = 1;
    }
    return count + countAvailableRecursiveHelper(index - 1);
}

int Flight::getAvailableSeatCountRecursive() const {
    return countAvailableRecursiveHelper(MAX_SEATS_PER_FLIGHT - 1);
}

void Flight::displaySeatingChart() const {
    std::cout << "\n--- Seating Chart for Flight " << flightNumber << " ---" << std::endl;
    for (int i = 0; i < MAX_SEATS_PER_FLIGHT; i++) {
        std::cout << "Seat " <<std::setw(2) << seats[i].getSeatNumber() << ": [";
        if (seats[i].getIsReserved()) {
            std::cout << " X ";
        } else {
            std::cout << std::setw(3) << seats[i].getSeatNumber();
        }
        std::cout << "] ";
        if ((i + 1) % 5 == 0) {
            std::cout << std::endl;
        }
    }
    if (MAX_SEATS_PER_FLIGHT % 5 != 0) std::cout << std:: endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "X = Reserved, Number = Available Seat Number" << std:: endl;
}

bool Flight::bookSeat(int seatNum, Customer* cust) {
    if (!cust) { // To prevent booking with a null customer
        std::cout << "Error: Cannot book seat with null customer information." << std::endl;
        return false; //cust is not deleted here, caller should manage if it was newed
    }
    if (seatNum < 1 || seatNum > MAX_SEATS_PER_FLIGHT) {
        std::cout << "Error: Invalid seat number." << std::endl;
        delete cust; //Clean up customer object as it will not be used here
        return false;
    }
    if (seats[seatNum - 1].reserve(cust)) { //Seat::reserve now takes ownership
        numReservedSeats++;
        std::cout << "Seat " << seatNum << " booked successfully for " << cust->getName() << "." << std::endl;
        return true;
    } else {
        std::cout << "Error: Seat " << " is already reserved or booking failed." << std::endl;
        delete cust;
        return false;
    }
}

bool Flight::cancelReservationBySeat(int seatNum) {
    if (seatNum < 1 || seatNum > MAX_SEATS_PER_FLIGHT) {
        std::cout << "Error: Invalid seat number." << std::endl;
        return false;
    }
    if (seats[seatNum - 1].getIsReserved()) {
        //Get customer name before cancelling for the message
        std::string custName = "Unknown (Error)";
        if (seats[seatNum - 1].getCustomer()) {
            custName = seats[seatNum - 1].getCustomer()->getName();
        }
        std::cout << "Cancelling reservation for seat " << seatNum << " held by " << custName << "." << std::endl;
        if (seats[seatNum - 1].cancel()) { //Seat::cancel deletes the Customer object
            numReservedSeats--;
            std::cout << "Reservation for seat " << seatNum << " cancelled successfully." << std::endl;
            return true;
        } else {
            std::cout << "Error: Could not cancel reservation for seat " << seatNum << "." << std::endl;
            return false;
        }
    } else {
        std::cout << "Error: Seat " << seatNum << " is not currently reserved." << std::endl;
        return false;
    }
}

int Flight::findSeatByCustomerName(const std::string& custName) const {
    for (int i = 0; i < MAX_SEATS_PER_FLIGHT; i++) {
        if (seats[i].getIsReserved() && seats[i].getCustomer() && seats[i].getCustomer()->getName() == custName) {
            return seats[i].getSeatNumber();
        }
    }
    return -1; //Not found otherwise
}

void Flight::printPassengerManifest() const {
    std::cout << "\n--- Passenger Manifest for Flight " << flightNumber << " (by Seat) ---" << std::endl;
    bool anyPassengers = false;
    for (int i = 0; i < MAX_SEATS_PER_FLIGHT; i++) {
        if (seats[i].getIsReserved() && seats[i].getCustomer()) {
            anyPassengers = true;
            std::cout << "Seat " << std::setw(2) << seats[i].getSeatNumber() << ": ";
            seats[i].getCustomer()->display();
            std::cout << "--------------------" << std::endl;
        }
    }
    if (!anyPassengers) {
        std::cout << "No passengers on this flight." << std::endl;
    }
}

void Flight::printPassengerManifestSortedByName() const {
    std::cout << "\n--- Passenger manifest for Flight " << flightNumber << " (Sorted by Name) ---" << std::endl;
    if (numReservedSeats == 0) {
        std::cout << "No passengers on this flight." << std::endl;
        return;
    }
    //Create an array of pointers to Customer objects who are passengers
    Customer* passengerPointers[MAX_SEATS_PER_FLIGHT];
    int passengerCount = 0;
    for (int i = 0; i < MAX_SEATS_PER_FLIGHT; i++) {
        if (seats[i].getIsReserved() && seats[i].getCustomer()) {
            passengerPointers[passengerCount++] = seats[i].getCustomer();
        }
    }
    //Bubble sort!
    for (int i = 0; i < passengerCount - 1; i++) {
        for (int j = 0; j < passengerCount - i - 1; j++) {
            if (passengerPointers[j]->getName() > passengerPointers[j + 1]->getName()) {
                Customer* temp = passengerPointers[j];
                passengerPointers[j] = passengerPointers[j + 1];
                passengerPointers[j + 1] = temp;
            }
        }
    }
    //Print list
    for (int i = 0; i < passengerCount; i++) {
        //Find the seat for this customer
        int seatNum = -1;
        for (int s = 0; s < MAX_SEATS_PER_FLIGHT; s++) {
            if (seats[s].getCustomer() == passengerPointers[i]) {
                seatNum = seats[s].getSeatNumber();
                break;
            }
        }
        std::cout << "Seat " << std::setw(2) << seatNum << ": ";
        passengerPointers[i]->display();
        std::cout << "--------------------" << std::endl;
    }
}

void Flight::printContactListForCancellation() const {
    std::cout << "\n--- Constact List for Potentially Cancelled Flight " << flightNumber << " ---" << std::endl;
    bool anyPassengers = false;
    for (int i = 0; i < MAX_SEATS_PER_FLIGHT; i++) {
        if (seats[i].getIsReserved() && seats[i].getCustomer()) {
            anyPassengers = true;
            std::cout << "Contact for Seat " << seats[i].getSeatNumber() << ":" << std::endl;
            seats[i].getCustomer()->display();
            std::cout << "--------------------" << std::endl;
        }
    }
    if (!anyPassengers) {
        std::cout << "No passengers were booked on this flight." << std::endl;
    }
}

void Flight::clearAllReservations() {
    for (int i = 0; i < MAX_SEATS_PER_FLIGHT; i++) {
        if (seats[i].getIsReserved()) {
            seats[i].cancel();
        }
    }
    numReservedSeats = 0;
    std::cout << "All reservations for flight " << flightNumber << " have been cleared." << std::endl;
}
