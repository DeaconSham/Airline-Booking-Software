#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
//Base class representing a person with common contact information.
class Person {
    protected: //Protected members are accessible by this class and derived classes.
        std::string name; //Person's name.
        std::string address; //Person's address.
        std::string phoneNumber; //Person's phone number.
    public: //Public interface for the Person class.
        Person(); //Default constructor.
        Person(const std::string& n, const std::string& addr, const std::string& phone); //Constructor: Initializes Person with name (n), address (addr), and phone.
        virtual ~Person(); //Virtual destructor: Ensures proper cleanup for derived classes.
        //Getter methods for accessing person's details.
        std::string getName() const;
        std::string getAddress() const;
        std::string getPhoneNumber() const;
        //Setter methods for modifying person's details.
        void setName(const std::string& n); //Corrected 'std:: string' to 'std::string'
        void setAddress(const std::string& addr);
        void setPhoneNumber(const std::string& phone);
        virtual void display() const; //Virtual method to display person's information; can be overridden by derived classes.
};

#endif
