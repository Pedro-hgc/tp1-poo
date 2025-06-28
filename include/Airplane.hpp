#pragma once

#include <string>

class Airplane {
private:

    float autonomy;
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
        void setAutonomy(float);
        void setMediumVelocity(float);
        void setCapacity(int);
        void setCode(const std::string );
        void setModel(const std::string );

        // Getters
        float getAutonomy() const;
        float getMediumVelocity() const;
        int getCapacity() const;
        std::string getCode() const;
        std::string getModel() const;

        std::string serializer() const;
        void showDetails() const;

};
