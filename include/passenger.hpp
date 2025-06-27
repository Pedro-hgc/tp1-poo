#pragma once 
#include "person.hpp"

class Passenger : public Person{
    private:
        std :: string ticketNumber;
        std :: string seatAssignment;
    public:
        Passenger(const std:: string& name, int age, cont std::string& ticket, std::string& seat);
        virtual ~Person() = default;

        //Passenger-Specific methods
        void board() const;
        virtual void displayInfo() const override;
};