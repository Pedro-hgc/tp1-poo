#pragma once

#include <string>

class Airplane {

private:

    float autonomyHours;
    float mediumVelocity;
    int capacity;
    std::string cod;
    std::string model;

public:
        Airplane();
        Airplane( const std::string& c,
                   const std::string& m,
                   int cap,
                   float mv,
                   float ha
        );
        ~Airplane();

        // Setters
        void setAutonomyHours(float);
        void setMediumVelocity(float);
        void setCapacity(int);
        void setCode(const std::string );
        void setModel(const std::string );

        // Getters
        float getAutonomyHours() const;
        float getMediumVelocity() const;
        int getCapacity() const;
        std::string getCode() const;
        std::string getModel() const;

        std::string serializer() const;
        void showDetails() const;

};
