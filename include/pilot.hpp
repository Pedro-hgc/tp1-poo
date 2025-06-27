#pragma once 
#include"person.hpp"

class Pilot : public Person{

    private:
        std ::string licenseNumber;
        std ::string registration;
        int flightHours;
        
    public:
        Pilot(const std:: string& name, int age, const std :: string& license, const std::string& registration, int hours);
        std::string serializer() const; 
        void Pilot::setLicense(const std::license);
        void Pilot::setHours(int hours);
        void Pilot::setCpf(const std::string& registration);
        string Pilot::getLicense()const;
        int Pilot::getHours();
        string Pilot::getBreve() const;

        //Pilot-specifc methods        
        void fly()const;
        void displayInfo() const;
};
