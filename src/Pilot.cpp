#include "../include/Pilot.hpp"
#include <sstream>
#include <iostream>

Pilot::Pilot(const std::string& name, int age, const std::string& license, const std::string& registration, int hours)
        :Person(name,age),licenseNumber(license),registration(registration), flightHours(hours){}
void Pilot::fly() const{
    std::cout<<name <<" está pilotando o avião! ( Breve: "<<licenseNumber<< " Matricula:" << registration<< ")" << std::endl;
}
        
void Pilot::displayInfo() const{
    Person::displayInfo();
    std::cout <<"Brevê: " << licenseNumber << std::endl
    << "Matricula: " <<registration<< std::endl
    << "Horas de Vôo: "<< flightHours<< std::endl;
}

std::string Pilot::getLicense()const
{
    return licenseNumber;
}
std::string Pilot::getRegistration() const
{
    return registration;
}
int Pilot::getHours() const
{
    return this->flightHours;
}

 void Pilot::setLicense(const std::string& license)
{
    this->licenseNumber=license;
}
void Pilot::setHours(int hours)
{  
    this->flightHours= hours;
}
void Pilot::setRegistration(const std::string& registration)
{ 
    this->registration = registration;
}

std::string Pilot::serializer() const {
    std::ostringstream oss;
    oss
        << "piloto" << ","
        << this->name << ","
        << this->registration<< ","
        << this->licenseNumber<< ","
        << this->flightHours;
    return oss.str();
}

