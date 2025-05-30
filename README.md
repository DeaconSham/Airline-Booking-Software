## Airline-Booking-Software
This is a summative project for ICS4U, demonstrating an airline booking software.

## User Guide

# Starting Up
1.  Run the `airplane` (or similarly named) program from your terminal.
2.  The **Main Menu** will appear.
# Navigation
*   **Menus:** Type the number of your choice and press `Enter`.
*   **Prompts:** Type the requested information and press `Enter`.
*   **Continue:** After information is shown, press `Enter` to go back to the menu.

# Main Menu Actions

1.  **Add New Flight:**
    *   Enter `1`.
    *   Type a unique **Flight Number** and press `Enter`.
    *   Press `Enter` to return.

2.  **Select Flight to Manage:**
    *   Enter `2`.
    *   Available flights will be listed.
    *   Type the **Flight Number** to manage or `0` to go back, then press `Enter`.
    *   This takes you to the **Flight Management Menu**.

3.  **List All Flights:**
    *   Enter `3`.
    *   A summary of all flights and their occupancy is shown.
    *   Press `Enter` to return.

0.  **Exit Program:**
    *   Enter `0` to close the application.

# Flight Management Menu Actions
(Accessed after selecting a flight from the Main Menu)

1.  **Display Seating Chart:**
    *   Enter `1`.
    *   View the 10 seats: `[X]` = Reserved, `[#]` = Available Seat #.
    *   Press `Enter` to return.

2.  **Book a Seat:**
    *   Enter `2`. Seating chart displays.
    *   Enter the desired **Seat Number** (1-10).
    *   If available, enter customer's **Name**, **Address**, and **Phone**.
    *   Press `Enter` to return.

3.  **Cancel a Reservation:**
    *   Enter `3`.
    *   Choose to cancel by `1` (Seat Number) or `2` (Customer Name).
    *   Enter the requested seat number or customer name.
    *   Press `Enter` to return.

4.  **Print Passenger Manifest (by Seat):**
    *   Enter `4`.
    *   Lists passengers by seat number with contact details.
    *   Press `Enter` to return.

5.  **Print Passenger Manifest (by Name):**
    *   Enter `5`.
    *   Lists passengers alphabetically by name with seat and contact details.
    *   Press `Enter` to return.

6.  **Process Full Flight Cancellation:**
    *   Enter `6`.
    *   **The passenger contact list will be printed.**
    *   You'll be asked: `Do you want to clear all reservations for this flight now? [y/n]`
    *   Enter `y` (yes) or `n` (no).
    *   Press `Enter` to return.

0.  **Back to Main Menu:**
    *   Enter `0` to return to the Main Menu.
