#include "../include/AirlineSystem.hpp"

// Nothing in constructor because The system will increase
// with user input
AirlineSystem::AirlineSystem(){}

// Destroying every element from the vectors
AirlineSystem::~AirlineSystem() {
    for (Airplane* airplane: airplanes)
        delete airplane;
    for (Pilot* pilot: pilots)
        delete pilot;
    for (Passenger* passenger: passengers)
        delete passenger;

    for (Flight* flight: flights_avaibles){
        flight->~Flight();
        delete flight;
    }
}

Airplane* AirlineSystem::getAirplane(std::string cod) {
    for (Airplane* airplane: airplanes) {
        if (cod == airplane->getCode())
            return airplane;
    }
    return NULL;
}
Pilot* AirlineSystem::getPilot(std::string licenseNumber){
    for (Pilot* pilot: pilots){
        if (licenseNumber == pilot->licenseNumber);
    }
}
Passenger* getPassenger(std::string ticketNumber);
Flight*    getFlight(std::string code);


// The plane in newAirplane only gets here after is created
// in the Menu, so there is not really a way to have a invalid
// Airplane at this point, because the Menu would not let this
// But just to be sure we check if the pointer is not NULL

bool AirlineSystem::registerNewAirplane(Airplane* newAirplane) {
    if (newAirplane == NULL)
        return false;
    this->airplanes.push_back(newAirplane); return true;
}
bool AirlineSystem::registerNewPilot(Pilot* newPilot) {
    if (newPilot == NULL)
        return false;

    this->pilots.push_back(newPilot); return true;
}
bool AirlineSystem::registerNewPassenger(Passenger* newPassenger){
    if (newPassenger == NULL)
        return false;

    this->passengers.push_back(newPassenger); return true;
}
bool AirlineSystem::registerNewFlight(Flight* newFlight) {
    if (newFlight == NULL)
        return false;

    this->flights_avaibles.push_back(newFlight); return true;
}
bool boardPassenger(Passenger* passengerToBoard) {
    std::cout << "TODO: boardPassenger()" << std::endl;
    return false;
}

void AirlineSystem::showAirplanes(void) {
    for (Airplane* airplane: airplanes) {
        airplane->showDetails();
        std::cout << std::endl << std::endl;
    }
}
void AirlineSystem::showPilots(void) {
    for (Pilot* pilot: pilots) {
        pilot->displayInfo();
        std::cout << std::endl << std::endl;
    }
}
void AirlineSystem::showPassengers(void) {
     for (Passenger* passenger: passengers) {
        passenger->displayInfo();
        std::cout << std::endl << std::endl;
    }
}
void AirlineSystem::showFlightsAvaibles(void) {
    for (Flight* flight: flights_avaibles) {
        flight->showData();
        std::cout << std::endl << std::endl;
    }
}
