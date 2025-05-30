# Airline-Booking-Software

## Description
This is a summative project for ICS4U, demonstrating an airline booking software.

## User Manual

Fly-By-Night Airlines - Seat Management System

Welcome! This guide will help you use the seat management software.

1. Main Menu:
   When you start the program, you'll see the main menu:
   - "1. Add New Flight": Use this to create a new flight schedule in the system, and you'll be prompted for a unique flight number
   - "2. Select Flight to Manage": Choose this to work with an existing flight, and you'll be asked to enter the flight number.
   - "3. List All Flights": Displays all flights currently in the system along with their occupancy.
   - "0. Exit Program": Closes the application.

2. Managing a Selected Flight:
   After selecting a flight (option 2 from Main Menu), you'll get a new menu:
   - "1. Display Seating Chart": Shows a visual layout of the 10 seats where 'X' means a seat is reserved. A number indicates the seat is available.
   - "2. Book a Seat":
     - The seating chart will be displayed.
     - Enter the seat number the customer wants.
     - If the seat is available, you'll be prompted to enter the customer's:
       - Name
       - Address
       - Phone Number
     - The system will confirm the booking.
   - "3. Cancel a Reservation":
     - You can cancel by:
       - Seat Number: Enter the seat number exactly as it appears.
       - Customer Name: Enter the customer's name. The system will find their seat.
     - The system will confirm the cancellation, and the seat will become available.
   - "4. Print Passenger Manifest (by Seat)":
     - Displays a list of all passengers on the flight, ordered by their seat number.
     - Includes their name and contact information.
   - "5. Print Passenger Manifest (by Name)":
     - Displays a list of all passengers on the flight, sorted alphabetically by name.
     - Includes their seat number and contact information.
   - "6. Process Full Flight Cancellation (Print Contacts)":
     - IMPORTANT: You can use this if the entire flight needs to be cancelled.
     - The system will print the contact information (name, address, phone) for
       ALL passengers booked on this flight.
     You will need to contact these passengers manually to inform them.
     - This option *does not* automatically remove the flight or clear its reservations.
       It's for information retrieval before manual cancellation processing.
   - "0. Back to Main Menu": Returns you to the main program menu.

3. Inputting Data:
   - When asked for a number (such as a menu choice or seat number), type the number and press Enter.
   - When asked for text (like name, address, flight number), type the text and press Enter.

4. Error Handling:
   - If you enter invalid input (e.g., text where a number is expected, or an out-of-range seat),
     the system will usually prompt you to try again.
   - Pay attention to messages like "Flight not found" or "Seat already reserved."

Tips:
- Always verify the flight number before managing it.
- Double-check customer information before confirming a booking.
- When cancelling a flight (option 6 in the flight menu), ensure you have a process
  to follow up with affected customers.
