#pragma once 
#include "person.hpp"

class Passenger : public Person{
    protected:
        std :: string ticketNumber;
        std :: string seatAssignment;
    public:
        PassengetPassenger(const std:: string& name, int age,  const std::string& ticket, const std::string& cpf);
        virtual ~Passenger() = default;
        std::string serializer() const;
        
        std::string Passenger::getCPF() const;

        void Passenger::setCPF(const std::string cpf);
        
        
        //Passenger-Specific methods
        void board() const;
        virtual void displayInfo() const override;
};
