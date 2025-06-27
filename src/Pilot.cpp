#include <iostream>
#include "../include/Pilot.hpp"
using namespace std;

Pilot::Pilot(const string& name, int age, const string& license, int hours):Person(name,age),licenseNumber(license), flightHours(hours){}
void Pilot::fly() const{
    cout<<name <<" está pilotando o avião! ( Licença: "<<licenseNumber<< " ) "<<endl;
}

void Pilot::displayInfo() const{
    Person::displayInfo();
    cout<<"Licença: "<< licenseNumber << ", Horas de Vôo: "<< flightHours<< endl;
}
