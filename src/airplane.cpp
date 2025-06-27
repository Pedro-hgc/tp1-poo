#include "../include/airplane.hpp"
#include <iostream>
#include <sstream>

Airplane::Airplane() {}
Airplane::Airplane(const std::string& c, const std::string& m,
                   int cap, float mv, float ha){

    autonomyHours = ha;
    mediumVelocity = mv;
    capacity = cap;
    cod = c;
    model = m;
}
Airplane::~Airplane() {
    std::cout << "Destructor called to Airplane " << this->cod << std::endl;
}

// Setters Implementation
void Airplane::setAutonomyHours(float autonomyHours) {
    this->autonomyHours = autonomyHours;
}
void Airplane::setMediumVelocity(float mediumVelocity) {
    this->mediumVelocity = mediumVelocity;
}
void Airplane::setCapacity(int capacity) {
    this->capacity = capacity;
}
void Airplane::setCode(const std::string cod) {
    this->cod = cod;
}
void Airplane::setModel(const std::string model) {
    this->model = model;
}

// Getters Implementation
float Airplane::getAutonomyHours() const {
    return autonomyHours;
}
float Airplane::getMediumVelocity() const {
    return mediumVelocity;
}
int Airplane::getCapacity() const {
    return capacity;
}
std::string Airplane::getCode() const {
    return cod;
}
std::string Airplane::getModel() const {
    return model;
}

// Methods
std::string Airplane::serializer() const {
    std::ostringstream oss;
    oss << this->cod            << ","
        << this->model          << ","
        << this->capacity       << ","
        << this->mediumVelocity << ","
        << this->autonomyHours  << std::endl;

    return oss.str();
}

void Airplane::showDetails() const {
    std::cout << "Airplane Code: "  << cod << std::endl;
    std::cout << "Airplane Model: "  << model << std::endl;
    std::cout << "Airplane Capacity: "  << capacity << std::endl;
    std::cout << "Airplane Medium Velocity: "  << mediumVelocity << std::endl;
    std::cout << "Airplane Autonomy Hours: "  << autonomyHours << std::endl;
}
