#include <iostream>
#include "../include/pilot.hpp"
using namespace std;


Pilot::Pilot(const string& name, int age, const string& license, const string& registration, int hours):Person(name,age),licenseNumber(license),registration(registration), flightHours(hours){}
void Pilot::fly() const{
    cout<<name <<" está pilotando o avião! ( Licença: "<<licenseNumber<< " Breve:" << registration<< ")" <<endl;
}
        
void Pilot::displayInfo() const{
    Person::displayInfo();
    cout<<"Licença: " << licenseNumber <<", Breve" << registration<< ", Horas de Vôo: "<< flightHours<< endl;
}
 void Pilot::setLicense(const std::license)
{
    licenseNumber=license;
}
void Pilot::setHours(int hours)
{  
    this->hours = hours;
}
void Pilot::setCpf(const std::string& registration) 
{ 
    this->registration = registration; 
}

string Pilot::getLicense()const
{
    return license;
}
int Pilot::getHours()
{
    return hours;
}
string Pilot::getBreve() const 
{ 
    return registration; 
} 
std::string Pilot::serializer() const {
    std::ostringstream oss;
    oss << this->licenseNumber<< " , "
        << this->registration<< " , "
        << this->flightHours<< " , "<< std::endl;

    return oss.str();
}