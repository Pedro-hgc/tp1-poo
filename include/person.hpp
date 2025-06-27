#pragma once 

class Person{
    protected:
        std :: string name;
    public:
        Person(const std:: string& name);
        virtual ~Person() = default;

        //Getters        
        std :: string getName()const;
        int getAge()const; 

        //Setters 
        void setName(const std:: string& name);    
        void setAge(int age);

        virtual void displayInfo() const;
};