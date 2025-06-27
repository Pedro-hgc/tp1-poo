#include <iostream>
#include "pilot.hpp"
using namespace std

class Pilot : public Person{
    private:
        std :: licenseMNumber;
        inf flighthours;
    public:
        Pilot(const std:: string& name, int age, const std :: string& license, int hours);
        
        //Pilot-specifc methods        
        void fly()const;
        void displayInfo() const override;
};