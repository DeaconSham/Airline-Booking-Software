# Airline Booking Software

This is a straightforward airline booking software, as it's a console-based application written in C++ that allows users to manage flights and passenger reservations.

## Features

*   **Flight Management**: Add new flights and list all available flights with their occupancy.
*   **Seat Booking**: Book available seats on a flight for a customer by providing their name, address, and phone number.
*   **Reservation Cancellation**: Cancel a reservation by seat number or customer name.
*   **Passenger Manifests**: Print a list of passengers on a flight, sorted either by seat number or alphabetically by name.
*   **Seating Chart**: Display a visual representation of the seating chart for a flight, showing which seats are available and which are reserved.
*   **Full Flight Cancellation**: Cancel an entire flight, with an option to clear all reservations.
*   **Customizable Constants**: The maximum number of flights and seats per flight can be easily changed in the `Constants.h` file.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

You will need a C++ compiler to build the project. The g++ compiler is a common choice.

### Installation & Running

1.  **Compile the source code:**
    ```sh
    g++ -o airline_booking Main.cpp Airline.cpp Flight.cpp Customer.cpp Person.cpp Seat.cpp
    ```
2.  **Run the executable:**
    ```sh
    ./airline_booking
    ```

## How to Use

### Main Menu

*   `1`: **Add New Flight**: Prompts for a unique flight number to create a new flight.
*   `2`: **Select Flight to Manage**: Lists available flights and lets you choose one to manage.
*   `3`: **List All Flights**: Shows a summary of all flights and their occupancy.
*   `0`: **Exit Program**: Closes the application.

### Flight Management Menu

After selecting a flight, you can perform the following actions:

*   `1`: **Display Seating Chart**: Shows the seating plan with available seats marked as `[#]` and reserved seats as `[X]`.
*   `2`: **Book a Seat**: Allows you to book a seat by entering the seat number and customer details.
*   `3`: **Cancel a Reservation**: Lets you cancel a reservation by providing either the seat number or the customer's name.
*   `4`: **Print Passenger Manifest (by Seat)**: Lists all passengers on the flight, ordered by their seat number.
*   `5`: **Print Passenger Manifest (by Name)**: Lists all passengers on the flight, ordered alphabetically by name.
*   `6`: **Process Full Flight Cancellation**: Prints the passenger contact list and asks for confirmation before canceling the entire flight.
*   `0`: **Back to Main Menu**: Returns to the main menu.

## File Structure

*   **`Main.cpp`**: The main entry point for the application. It handles the main menu and user input.
*   **`Airline.h` / `Airline.cpp`**: Defines the `Airline` class, which manages all the flights in the system.
*   **`Flight.h` / `Flight.cpp`**: Defines the `Flight` class, responsible for managing a single flight, including its seating chart and passenger list.
*   **`Customer.h` / `Customer.cpp`**: Defines the `Customer` class, which holds information about a passenger.
*   **`Person.h` / `Person.cpp`**: A base class for `Customer`.
*   **`Seat.h` / `Seat.cpp`**: Defines the `Seat` class, representing a single seat on a flight.
*   **`Constants.h`**: A header file containing constants that can be modified, such as `MAX_FLIGHTS` and `MAX_SEATS`.
