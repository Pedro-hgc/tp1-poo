#include "../include/person.hpp"
#include <iostream>

Person::Person(const std::string& name, int age) :
    name(name), age(age){}

// Getters
std::string Person::getName() const { return name; }
int Person::getAge() const { return age; }


// Setters
void Person::setName(const std::string& name) { this->name = name; }
void Person::setAge(int age) { this->age = age; }


void Person::displayInfo() const {
    std::cout << "Nome: " << name << "\nIdade: " << age << std::endl;
}