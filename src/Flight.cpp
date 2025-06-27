#include "../include/Flight.hpp"

// Constructors
Flight::Flight(){};
Flight::Flight(std::string code, std::string origin, std::string destination, Airplane* airplane, Pilot* pilot, Pilot* copilot) {
   this->code = code;
   this->origin = origin;
   this->destination = destination;
   this->airplane = airplane;
   this->pilot = pilot;
   this->copilot = copilot;
}

// Destructors
Flight::~Flight() {
    for (Passenger* passenger: passengers)
        delete passenger;
}

// Setters
void Flight::setAirplane(Airplane* airplane) {
    this->airplane = airplane;
}
void Flight::setPilot(Pilot* pilot) {
    this->pilot = pilot;
}
void Flight::setCopilot(Pilot* copilot) {
    this->copilot = copilot;
}
void Flight::setCode(const std::string code) {
    this->code = code;
}
void Flight::setArrivalDate(const std::string arrivalDate) {
    this->arrivalDate = arrivalDate;
}
void Flight::setDepartureDate(const std::string departureDate) {
    this->departureDate = departureDate;
}
void Flight::setDestination(const std::string destination) {
    this->destination = destination;
}
void Flight::setOrigin(const std::string origin) {
    this->origin = origin;
}
void Flight::setDistance(const std::string distance) {
    this->distance = distance;
}

// Getters
Airplane* Flight::getAirplane() const {
    return this->airplane;
}
Pilot* Flight::getPilot() const {
    return this->pilot;
}
Pilot* Flight::getCopilot() const {
    return this->copilot;
}
float Flight::getEstimatedDuration() const{
    return this->estimatedDuration;
}
int Flight::getScalesNumber() const {
    return this->scalesNumber;
}

std::string Flight::getOrigin() const {
    return this->origin;
}
std::string Flight::getDestination() const {
    return this->destination;
}
std::string Flight::getArrivalDate() const {
    return this->arrivalDate;
}
std::string Flight::getDepartureDate() const {
    return this->departureDate;
}
std::string Flight::getDistance() const {
    return this->distance;
}
std::vector<Passenger*> Flight::getPassengers() const {
    return this->passengers;
}
std::string Flight::getCode() const {
    return this->code;
}

// Methods
void Flight::addPassenger(Passenger* new_passenger) {
    passengers.push_back(new_passenger);
}
void Flight::removePassenger(Passenger* passenger) {
    std::cout << "TODO: Remove Passenger" << std::endl;
}

float Flight::calculateDuration() {
    std::cout << "TOOD: calculateDuration()" << std::endl;
    return 0;
}

int Flight::calculateScalesNumber(){
   std::cout << "TODO: calculateScalesNumber()" << std::endl;
   return -1;
}

std::string Flight::serializer() const {
    return "TODO: serializer()\n" ;
}

void Flight::showData() const {
    std::cout << "Airplane:" << std::endl;
    this->airplane->showDetails();
}
