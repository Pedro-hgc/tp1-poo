#pragma once 
#include "Person.hpp"

class Passenger : public Person{
    protected:
        std :: string ticketNumber;
        std :: string cpf;
    public:
        Passenger(const std:: string& name, int age, const std::string& ticket, const std::string& cpf);
        ~Passenger() = default;

        std::string getCPF() const;
        std::string getTicket() const;

        void setCPF(const std::string cpf);
        void setTicket(const std::string ticket);
        
        void displayInfo() const override;
        std::string serializer() const;
        //Passenger-Specific methods
        void board() const;
        
};
