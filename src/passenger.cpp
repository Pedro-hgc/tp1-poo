#include <iostream>
#include "../include/person.hpp"
#include "../include/passenger.hpp"

using namespace std;

<<<<<<< HEAD
Passenger::Passenger(const string& name, int age, const string& ticket, const string cpf): 
                        Person(name,age), ticketNumber(ticket), cpf(cpf){}

void Passenger:: board() const{
        cout << name << " está embarcando com o ticket: " << ticketNumber <<endl;
}
void Passenger:: displayInfo(){
        cout << "Nome:" << name << " , idade: " << age << ", CPF:" << cpf << "Bilhete" << ticketNumber;
}
void Passenger::setCpf(const std::string cpf) 
{ 
    this->cpf = cpf; }
string Passenger::getCPF() const 
{ 
    return cpf; } 
std::string Passenger::serializer() const {
    std::ostringstream oss;
    oss <<this->name<< " , "
        <<this->cpf << " , "
        <<this->ticketNumber<< " , "
        <<std::endl;

    return oss.str();
}
=======
Passenger::Passenger(const string& name, int age, const string& ticket, string seat)
:Person(name,age), ticketNumber(ticket), seatAssignment(seat){}

void Passenger:: board() const{
    cout << name << " está embarcando com o ticket: " << ticketNumber << " Cadeira: ( " << seatAssignment <<" )"<<endl;
}

void Passenger :: displayInfo() const{
    Person::displayInfo();
    cout<< "Ticket: " << ticketNumber << " Cadeira: ( " << seatAssignment <<" )"<<endl;
}
>>>>>>> 7b23416179e9ab4c68d001c3bd221a17239e135d
