#include <iostream>
#include "../include/person.hpp"
#include "../include/passenger.hpp"

using namespace std;

Passenger::Passenger(const string& name, int age, const string& ticket, string seat): 
                        Person(name,age), ticketNumber(ticket), seatAssignment(seat){}

        void Passenger:: board() const{
            cout << name << " está embarcando com o ticket: " << ticketNumber << " Cadeira: ( " << seatAssignment <<" )"<<endl;
        }

        void Passenger :: displayInfo() const{
            Person::displayInfo();
            cout<< "Ticket: " << ticketNumber << " Cadeira: ( " << seatAssignment <<" )"<<endl;
        }
