#include <iostream>
#include <string> 
#include <limits> 
#include <iomanip>
#include <cstdlib>
#include "Airline.h" //Includes definition for the Airline class and classes called by Airline

void clearScreen() {
//Preprocessor directives to select the correct clear command based on the operating system.
#if defined(_WIN32) || defined(_WIN64) //Check if compiling on a Windows system
    std::system("cls"); //Windows command to clear screen
#elif defined(__APPLE__) //Check if compiling macOS
    std::system("clear"); //macOS command to clear screen
#else
    // Fallback for unknown systems: print many newlines to simulate a clear.
    for (int i = 0; i < 50; ++i)  {
        std::cout << std::endl;
    }
#endif
}

//Function to pause execution and wait for the user to press Enter.
void pressEnterToContinue() {
    std::cout << "\nPress Enter to continue...";
    std::cin.get(); //Reads a single character (waits for Enter if buffer is empty)
//Assumes the input buffer was cleared by previous input functions (getIntInput/getStringInput)
}

//Function to reliably get integer input from the user.
//Handles invalid input and prompts again.
int getIntInput(const std::string& prompt) {
    int choice; //Variable to store the user's integer input
    while (true) { //Loop indefinitely until valid input is received
        std::cout << prompt; //Display the provided prompt message
        std::cin >> choice;  //Attempt to read an integer
        if (std::cin.good()) { //Check if the input operation was successful (no errors)
            //Clear any leftover characters in the input buffer (e.g., the newline after entering the number)
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            return choice; //Return the valid integer
        } else {
            std::cout << "Invalid input. Please enter a whole number." << std::endl;
            std::cin.clear(); //Clear error flags on std::cin
            //Discard the invalid input from the buffer to prevent infinite loop on next cin attempt
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        }
    }
}

//Function to reliably get string input from the user.
std::string getStringInput(const std::string& prompt, bool allowEmpty = false) {
    std::string input; // Variable to store the user's string input
    while(true) { // Loop indefinitely until valid input is received (or empty if allowed)
        std::cout << prompt; // Display the provided prompt message
        std::getline(std::cin, input); // Read an entire line of text, including spaces
        if (!input.empty() || allowEmpty) { // Check if input is not empty, or if empty input is allowed
            return input; // Return the valid string
        }
        // If input is empty and empty strings are not allowed
        std::cout << "Input cannot be empty. Please try again." << std::endl; 
    }
}

// Function to manage operations for a specific flight.
// Takes a pointer to a Flight object and a reference to the Airline object.
void flightMenu(Flight* flight, Airline& airline) {
    // Check if the provided flight pointer is valid
    if (!flight) {
        std::cout << "Error: No flight selected or flight is invalid." << std::endl;
        pressEnterToContinue();
        return; // Exit the function
    }
    int choice; // Variable for user's menu choice
    do { // Loop for the flight menu until user chooses to go back
        clearScreen(); // Clear the console for a fresh menu display
        // Display flight-specific information and menu options
        std::cout << "\n--- Flight " << flight->getFlightNumber() << " Menu (" 
                  << flight->getNumReservedSeats() << "/" << MAX_SEATS_PER_FLIGHT << " seats) ---" << std::endl;
        std::cout << "1. Display Seating Chart" << std::endl;
        std::cout << "2. Book a Seat" << std::endl;
        std::cout << "3. Cancel a Reservation" << std::endl;
        std::cout << "4. Print Passenger Manifest (by Seat)" << std::endl;
        std::cout << "5. Print Passenger Manifest (by Name)" << std::endl;
        std::cout << "6. Process Full Flight Cancellation (Print Contacts & Optionally Clear)" << std::endl;
        std::cout << "0. Back to Main Menu" << std::endl;
        choice = getIntInput("Enter your choice: "); 
        clearScreen();
        switch (choice) { //Process the user's choice
            case 1: //Display Seating Chart
                std::cout << "--- Displaying Seating Chart ---" << std::endl;
                flight->displaySeatingChart(); //Call flight method to display chart
                pressEnterToContinue();
                break;
            case 2: { //Book a Seat
                std::cout << "--- Booking a Seat ---" << std::endl;
                flight->displaySeatingChart(); // how seating chart first for reference
                // Check if the flight is already full
                if (flight->getNumReservedSeats() >= MAX_SEATS_PER_FLIGHT) {
                    std::cout << "Sorry, this flight is fully booked." << std::endl;
                } else {
                    //Get desired seat number from user
                    int seatNum = getIntInput("Enter seat number to book (1-" + std::to_string(MAX_SEATS_PER_FLIGHT) + "): ");
                    //Check if the chosen seat is available
                    if (flight->isSeatAvailable(seatNum)) {
                        std::cout << "Seat " << seatNum << " is available." << std::endl;
                        //Get customer details
                        std::string name = getStringInput("Enter customer name: ");
                        std::string addr = getStringInput("Enter customer address: ");
                        std::string phone = getStringInput("Enter customer phone: ");
                        //Create a new Customer object dynamically
                        Customer* newCust = new Customer(name, addr, phone); 
                        //Attempt to book the seat; Flight::bookSeat handles newCust's memory
                        if (!flight->bookSeat(seatNum, newCust)) {
                            //If booking fails, bookSeat should have printed an error and managed newCust memory
                            std::cout << "Booking failed. Please check messages above." << std::endl;
                        }
                    } else {
                        std::cout << "Seat " << seatNum << " is not available or invalid." << std::endl;
                    }
                }
                pressEnterToContinue();
                break;
            }
            case 3: {//Cancel a Reservation
                std::cout << "--- Cancelling a Reservation ---" << std::endl;
                //Check if there are any reservations to cancel
                if (flight->getNumReservedSeats() == 0) {
                    std::cout << "No reservations on this flight to cancel." << std::endl;
                } else {
                    int cancelChoice; //Choice for cancellation method (by seat or by name)
                    std::cout << "Cancel by: 1. Seat Number | 2. Customer Name: ";
                    cancelChoice = getIntInput(""); 
                    if (cancelChoice == 1) { //Cancel by seat number
                        int seatNum = getIntInput("Enter seat number to cancel: ");
                        flight->cancelReservationBySeat(seatNum);
                    } else if (cancelChoice == 2) { //Cancel by customer name
                        std::string custName = getStringInput("Enter customer name to cancel reservation for: ");
                        int seatNum = flight->findSeatByCustomerName(custName); //Find seat by name
                        if (seatNum != -1) { //If customer found
                            flight->cancelReservationBySeat(seatNum); //Cancel by the found seat number
                        } else {
                            std::cout << "Customer '" << custName << "' not found on this flight." << std::endl;
                        }
                    } else {
                        std::cout << "Invalid choice for cancellation method." << std::endl;
                    }
                }
                pressEnterToContinue();
                break;
            }
            case 4: //Print Passenger Manifest (by Seat)
                std::cout << "--- Printing Passenger Manifest (by Seat) ---" << std::endl;
                flight->printPassengerManifest();
                pressEnterToContinue();
                break;
            case 5: //Print Passenger Manifest (by Name)
                std::cout << "--- Printing Passenger Manifest (by Name) ---" << std::endl;
                flight->printPassengerManifestSortedByName();
                pressEnterToContinue();
                break;
            case 6: //Process Full Flight Cancellation
                std::cout << "--- Processing Full Flight Cancellation ---" << std::endl;
                airline.processFlightCancellation(flight);
                pressEnterToContinue();
                break;
            case 0: // Back to Main Menu
                std::cout << "Returning to Main Menu..." << std::endl;
                break;
            default: //Invalid choice
                std::cout << "Invalid choice. Please try again." << std::endl;
                pressEnterToContinue();
        }
    } while (choice != 0); //Loop continues as long as choice is not 0
}

// Function to manage the main airline operations.
void mainMenu(Airline& airline) {
    int choice; //Variable for user's menu choice
    do { //Loop for the main menu until user chooses to exit
        clearScreen();
        std::cout << "\n===== Fly-By-Night Airlines Main Menu =====" << std::endl;
        std::cout << "1. Add New Flight" << std::endl;
        std::cout << "2. Select Flight to Manage" << std::endl;
        std::cout << "3. List All Flights" << std::endl;
        std::cout << "0. Exit Program" << std::endl;
        choice = getIntInput("Enter your choice: ");
        clearScreen();
        switch (choice) { // Process the user's choice
            case 1: //Add New Flight
                std::cout << "--- Adding New Flight ---" << std::endl;
                airline.addFlight(); // Call airline method to add a flight
                pressEnterToContinue();
                break;
            case 2: { //Select Flight to Manage
                std::cout << "--- Selecting Flight to Manage ---" << std::endl;
                // Check if any flights exist in the system
                if (airline.getNumFlights() == 0) {
                    std::cout << "No flights in the system to manage. Please add a flight first." << std::endl;
                    pressEnterToContinue();
                } else {
                    airline.listFlights(); //Display available flights
                    // Get flight number from user, or 0 to go back
                    std::string fn = getStringInput("Enter flight number to manage (or type 0 to go back): ");
                    if (fn == "0") {
                        break;
                    }
                    Flight* selectedFlight = airline.findFlight(fn); //Attempt to find the flight
                    if (selectedFlight) { // If flight found
                        flightMenu(selectedFlight, airline);
                    } else {
                        std::cout << "Flight '" << fn << "' not found." << std::endl;
                        pressEnterToContinue();
                    }
                }
                break;
            }
            case 3: //List All Flights
                std::cout << "--- Listing All Flights ---" << std::endl;
                airline.listFlights(); //Call airline method to list flights
                pressEnterToContinue();
                break;
            case 0: //Exit Program
                std::cout << "Exiting Fly-By-Night Airlines System. Goodbye!" << std::endl;
                break;
            default: //Invalid choice
                std::cout << "Invalid choice. Please try again." << std::endl;
                pressEnterToContinue();
        }
    } while (choice != 0); //Loop continues as long as choice is not 0
}

//Main function
int main() {
    Airline flyByNight; //Create an Airline object
    mainMenu(flyByNight); //Start the main menu interaction
    return 0;
}