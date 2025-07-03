#include <iostream>
#include <sstream>
#include "../include/Person.hpp"
#include "../include/Passenger.hpp"

using namespace std;

Passenger::Passenger(const string& name, int age, const string& ticket, const string& cpf):
                        Person(name,age), ticketNumber(ticket), cpf(cpf){}


string Passenger::getCPF() const 
{ 
    return cpf; 
} 
string Passenger::getTicket() const 
{ 
    return ticketNumber; 
} 

void Passenger::setTicket(const std::string ticket)
{ 
    this->ticketNumber = ticket;
}
void Passenger::setCPF(const std::string cpf) 
{ 
    this->cpf = cpf; 
}

void Passenger::displayInfo() const{
        Person::displayInfo();
        cout<<"CPF: "<<cpf<<endl
            <<"Bilhete: "<<ticketNumber <<endl;
}
std::string Passenger::serializer() const {
    std::ostringstream oss;
    oss << Person::serialize()<< ","
        <<ticketNumber<< ","
        <<cpf<<endl;

    return oss.str();
}
void Passenger:: board() const{
        cout << name << " está embarcando com o bilhete: " << ticketNumber <<endl;
}
