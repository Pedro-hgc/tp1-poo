#pragma once
#include <string>

class Person {
protected:
    std::string name;
    int age;
   
    
public:
    Person(const std::string& name, int age);
    virtual ~Person() = default;

    // Getters
    std::string getName() const;
    int getAge() const;


    // Setters
    void setName(const std::string& name);
    void setAge(int age);

    virtual std::string serializer() const;
    virtual void displayInfo() const;
};

