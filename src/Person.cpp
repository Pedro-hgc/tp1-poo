#include "../include/Person.hpp"
#include <iostream>
using namespace std;

Person::Person(const string& name, int age) : name(name), age(age){}
    string Person::getName()const{return name;}
    int Person::getAge()const {return age;}

    void Person::setName(const string& name){this->name=name;}
    void Person::setAge(int age){this->age=age;}

    void Person::displayInfo()const{
        std::cout << "Nome: "<< name <<  ", Idade: " << age << endl;
}
