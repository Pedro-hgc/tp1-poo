#include <iostream>
#include "../include/Pilot.hpp"
using namespace std;

Pilot::Pilot(const string& name, int age, const string& license, const string& registration, int hours)
        :Person(name,age),licenseNumber(license),registration(registration), flightHours(hours){}
void Pilot::fly() const{
    cout<<name <<" está pilotando o avião! ( Breve: "<<licenseNumber<< " Matricula:" << registration<< ")" <<endl;
}
        
void Pilot::displayInfo() const{
    Person::displayInfo();
    cout<<"Licença: " << licenseNumber <<endl
    <<", Breve" <<registration<<endl
    << ", Horas de Vôo: "<< flightHours<< endl;
}

string Pilot::getLicense()const
{
    return licenseNumber;
}
string Pilot::getRegistration() const
{
    return registration;
}
int Pilot::getHours() const
{
    return hours;
}

 void Pilot::setLicense(const license)
{
    licenseNumber=license;
}
void Pilot::setHours(int hours)
{  
    this->hours = hours;
}
void Pilot::setRegistration(const string& registration) 
{ 
    this->resitration = registration; 
}

std::string Pilot::serializer() const {
    std::ostringstream oss;
    oss << this->licenseNumber<< ","
        << this->registration<< ","
        << this->flightHours<<std::endl;
    return oss.str();
}

