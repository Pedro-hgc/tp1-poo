#pragma once
#include <iostream>
using namespace std;
class Person{
    protected:
        string name;
        int age;
    public:
    
        Person(const string& name, int age);
        virtual ~Person() = default;

        //Getters        
        std :: string getName()const;
        int getAge()const; 

        //Setters 
        void setName(const std:: string& name);    
        void setAge(int age);

        virtual void displayInfo() const;
};
