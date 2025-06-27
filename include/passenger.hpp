#pragma once 
#include "person.hpp"

class Passenger : public Person{
    protected:
        std :: string ticketNumber;
        std :: string seatAssignment;
    public:
        Passenger(const std:: string& name, int age, const std::string& ticket, string seatAssignment);
        virtual ~Passenger() = default;

        //Passenger-Specific methods
        void board() const;
        virtual void displayInfo() const override;
};
