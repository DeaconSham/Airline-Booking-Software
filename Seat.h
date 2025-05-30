#ifndef SEAT_H
#define SEAT_H
#include "Customer.h" //For Customer class definition, as Seat holds a Customer pointer.

//Represents a single seat on a flight, managing its reservation status and passenger.
class Seat {
    private:
        int seatNumber; //Identifier for the seat.
        bool isReserved; //True if the seat is currently reserved, false otherwise.
        Customer* customer; //Pointer to the Customer object occupying this seat; nullptr if vacant.
    public:
        Seat(); //Default constructor.
        ~Seat(); //Destructor: Cleans up dynamically allocated Customer object if any.
        void initialize(int number); //Initializes seat number and reservation status.
        //Getter methods.
        int getSeatNumber() const;
        bool getIsReserved() const;
        Customer* getCustomer() const; //Returns pointer to the customer, or nullptr.
        bool reserve(Customer* cust); //Reserves the seat for a given customer; takes ownership of the Customer pointer on success.
        bool cancel(); //Cancels the reservation, making the seat available and deleting the associated Customer.
        void displayStatus() const; //Displays the current status of the seat.
};

#endif //SEAT_H