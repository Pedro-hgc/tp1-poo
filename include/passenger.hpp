#pragma once 
#include "Person.hpp"

class Passenger : public Person{
    protected:
        std :: string ticketNumber;
        std :: string cpf;
    public:
        Passenger(const std:: string& name, const std::string& cpf, const std::string& ticket);
        virtual ~Passenger() = default;
        std::string serializer() const;
        
        std::string getCPF() const;
        std::string getTicket() const;

        void setCPF(const std::string cpf);
        void setTicket(const std::string ticket);
        
        virtual void displayInfo() const override;
        std::string serialize() const; 
        //Passenger-Specific methods
        void board() const;
        
};
