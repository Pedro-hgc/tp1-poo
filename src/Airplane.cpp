#include "../include/Airplane.hpp"
#include <iostream>
#include <sstream>

Airplane::Airplane() {}
Airplane::Airplane(const std::string& c, const std::string& m,
                   int cap, float mv, float ha){

    cod = c;
    model = m;
    capacity = cap;
    mediumVelocity = mv;
    autonomy = ha;
}
Airplane::~Airplane() {
    std::cout << "Destructor called to Airplane " << this->cod << std::endl;
}

// Setters Implementation
void Airplane::setAutonomy(float autonomy) {
    this->autonomy= autonomy;
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
float Airplane::getAutonomy() const {
    return autonomy;
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
        << this->autonomy;

    return oss.str();
}

void Airplane::showDetails() const {
    std::cout << "Código do avião: "  << cod << std::endl;
    std::cout << "Modelo do avião: "  << model << std::endl;
    std::cout << "Capacidade do avião: "  << capacity << std::endl;
    std::cout << "Velocidade Media do avião: "  << mediumVelocity << std::endl;
    std::cout << "Autonomia do avião: "  << autonomy << std::endl;
}
