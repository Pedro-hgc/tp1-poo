#pragma once 
#include"Person.hpp"

class Pilot : public Person{

private:
    std::string licenseNumber;
    std::string registration;
    int flightHours;
        
public:
    Pilot(const std:: string& name, int age, const std :: string& licenseNumber, const std::string& registration, int hours);
        
    std::string getLicense() const;
    std::string getRegistration() const;
    int getHours() const;
 
    void setLicense(const std::string& licenseNumber);
    void setRegistration(const std::string& registration);
    void setHours(int hours);

    

    std::string serializer() const ;
    void displayInfo() const override;
    //Pilot-specifc methods        
    void fly()const;
    
};
