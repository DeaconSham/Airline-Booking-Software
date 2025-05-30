#ifndef FLIGHT_H
#define FLIGHT_H
#include "Seat.h" //For Seat class definition.
#include "Customer.h" //For Customer class definition (used in booking/manifests).
#include "Constants.h" //For constants.
#include <string>

//Manages information and operations for a single flight, including its seats and passengers.
class Flight {
    private:
        std::string flightNumber; //Unique identifier for the flight.
        Seat seats[MAX_SEATS_PER_FLIGHT]; //Array of Seat objects for this flight.
        int numReservedSeats; //Current count of reserved seats.
        int countAvailableRecursiveHelper(int index) const; //Recursive helper to count available seats.
    public:
        Flight(); //Default constructor.
        Flight(const std::string& fn); //Constructor with flight number.
        //Destructor is implicit; Seat objects manage Customer memory.
        std::string getFlightNumber() const; //Returns the flight number.
        int getNumReservedSeats() const; //Returns the count of reserved seats.
        bool isSeatAvailable(int seatNum) const; //Checks if a specific seat is available.
        void displaySeatingChart() const; //Displays the current seating arrangement.
        bool bookSeat(int seatNum, Customer* cust); //Books a seat for a customer.
        bool cancelReservationBySeat(int seatNum); //Cancels a reservation for a given seat.
        int findSeatByCustomerName(const std::string& custName) const; //Finds a customer's seat by name.
        void printPassengerManifest() const; //Prints passenger list ordered by seat.
        void printPassengerManifestSortedByName() const; //Prints passenger list sorted by name.
        void printContactListForCancellation() const; //Prints contact info for all passengers (for flight cancellation).
        void clearAllReservations(); //Clears all reservations on this flight.
        int getAvailableSeatCountRecursive() const; //Returns count of available seats (using recursion).
};

#endif //FLIGHT_H