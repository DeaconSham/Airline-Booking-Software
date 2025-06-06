#include "Airline.h"
#include <iostream>
#include <limits>

Airline::Airline() : numActualFlights(0) {
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        flightSlotUsed[i] = false;
    }
}

int Airline::getNumFlights() const {
    return numActualFlights;
}

void Airline::addFlight() {
    if (numActualFlights >= MAX_FLIGHTS) {
        std::cout << "Cannot add more flights. Maximum capacity (" << MAX_FLIGHTS << ") reached." << std::endl;
        return;
    }
    std::string fn;
    std::cout << "Enter new flight number: ";
    std::getline(std::cin, fn);
    if (fn.empty()) {
        std::cout << "Flight number cannot be empty. Please try again." << std::endl;
        return;
    }

    for (int i = 0; i < MAX_FLIGHTS; i++) {
        if (flightSlotUsed[i] && flights[i].getFlightNumber() == fn) {
            std::cout << "Error: Flight " << fn << " already exists." << std::endl;
            return;
        }
    }
    int slot = -1;
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        if (!flightSlotUsed[i]) {
            slot = i;
            break;
        }
    }
    if (slot != -1) {
        flights[slot] = Flight(fn);
        flightSlotUsed[slot] = true;
        numActualFlights++;
        std::cout << "Flight " << fn << " added successfully." << std::endl;
    } else {
        std::cout << "Error: system inconsistency. No availbale slot to add flight." << std::endl;
    }
}

Flight* Airline::findFlight(const std::string& fn) {
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        if (flightSlotUsed[i] && flights[i].getFlightNumber() == fn) {
            return &flights[i];
        }
    }
    return nullptr;
}

void Airline::listFlights() const {
    std::cout << "\n=== Available Flights ---" << std::endl;
    if (numActualFlights == 0) {
        std::cout << "No flights available in the system." << std::endl;
        return;
    }
    bool foundActiveFlight = false;
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        if (flightSlotUsed[i]) {
            foundActiveFlight = true;
            std::cout << "- " << flights[i].getFlightNumber() << " (" << flights[i].getNumReservedSeats() << "/" << MAX_SEATS_PER_FLIGHT << " seats reserved)" << " (" << flights[i].getAvailableSeatCountRecursive() << " available)" << std::endl;
        }
    }
    if (!foundActiveFlight && numActualFlights > 0) {
        std::cout << "System inconsistency: numActualFlights > 0 but no flights listed." << std::endl;
    }
    else if (!foundActiveFlight) {
        std::cout << "No flights currently in the system." << std::endl;
    }
}

void Airline::processFlightCancellation(Flight* flight) {
    if (!flight) {
        std::cout << "Error: Cannot process cancellation for a null flight." << std::endl;
        return;
    }
    std::cout << "\nWarning: Processing cancellation for flight " << flight->getFlightNumber() << "." << std::endl;
    std::cout << "The following passengers need to be contacted:" << std::endl;
    flight->printContactListForCancellation();
    char confirm;
    std::cout << "Do you want to clear all reservations for this flight now? [y/n]";
    std::cin >> confirm;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (confirm == 'y' || confirm == 'Y') {
        flight->clearAllReservations();
    } else {
        std::cout << "Reservations for flight " << flight->getFlightNumber() << " have not been cleared." << std::endl;
    }
}
