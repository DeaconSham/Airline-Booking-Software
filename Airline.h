#ifndef AIRLINE_H
#define AIRLINE_H
#include "Flight.h" //For Flight class definition.
#include "Constants.h" //For constants
#include <string>

//Manages a collection of flights for the airline.
class Airline {
    private:
        Flight flights[MAX_FLIGHTS]; //Array storing all possible Flight objects.
        int numActualFlights; //Current count of active flights.
        bool flightSlotUsed[MAX_FLIGHTS]; //Tracks if a slot in 'flights' array is occupied.

    public:
        Airline(); //Constructor: Initializes airline data.
        //Destructor is implicit; Flight objects handle their own cleanup.
        void addFlight(); //Adds a new flight to the system.
        Flight* findFlight(const std::string& fn); //Finds a flight by its number; returns pointer or nullptr.
        void listFlights() const; //Displays all active flights.
        int getNumFlights() const; //Returns the number of active flights.
        void processFlightCancellation(Flight* flight); //Handles airline-side cancellation of a flight (e.g., prints contacts).
};

#endif
