#pragma once 
#include"person.hpp"
#include "pilot.hpp"


class Pilot : public Person{
    private:
        std ::string licenseNumber;
        int flightHours;
    public:
        Pilot(const std:: string& name, int age, const std :: string& license, int hours);
        
        //Pilot-specifc methods        
        void fly()const;
        void displayInfo() const;
};