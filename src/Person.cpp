#include "../include/Person.hpp"
#include <iostream>
#include <sstream>

using namespace std;

Person::Person(const string& name, int age) :
    name(name), age(age){}


    // Getters
string Person::getName() const 
{ 
    return name; 
}
int Person::getAge() const 
{ 
    return age; 
}


// Setters
void Person::setName(const string& name) 
{ 
    this->name = name; 
}
void Person::setAge(int age) 
{ 
    this->age = age; 
}

std::string Person::serialize() const {
    std::ostringstream oss;
    oss<< name << ","<<age;
    return oss.str();
}

void Person::displayInfo() const {
    std::cout << "Nome: " << name << endl 
    <<"Idade: " << age << endl;
}

