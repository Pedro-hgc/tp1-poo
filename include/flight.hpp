#pragma once

// Language Classes
#include <string>
#include <vector>
#include <algorithm>

// Project Classes
#include "airplane.hpp"
#include "pilot.hpp"
#include "passenger.hpp"

class Flight {
private:
        Airplane* airplane;
        Pilot* pilot;
        Pilot* copilot;
        float estimatedDuration;
        int scalesNumber;

        std::string origin;
        std::string destination;
        std::string arrivalDate;
        std::string departureDate;
        std::string distance;
        std::vector<Passenger*> passengers;
        std::string code;
public:
        // Constructors
        Flight();
        Flight(std::string, std::string, std::string, Airplane*, Pilot*, Pilot*);

        // Destructor
        ~Flight();

        // Setters
        void setAirplane(Airplane*);
        void setPilot(Pilot*);
        void setCopilot(Pilot*);
        void setCode(const std::string);
        void setArrivalDate(const std::string);
        void setDepartureDate(const std::string);
        void setDestination(const std::string);
        void setOrigin(const std::string);
        void setDistance(const std::string);

        // Getters
        Airplane* getAirplane() const;
        Pilot* getPilot() const;
        Pilot* getCopilot() const;
        float getEstimatedDuration() const;
        int getScalesNumber() const;

        std::string getOrigin() const;
        std::string getDestination() const;
        std::string getArrivalDate() const;
        std::string getDepartureDate() const;
        std::string getDistance() const;
        std::vector<Passenger*> getPassengers() const;
        std::string getCode() const;

        // Methods
        void addPassenger(Passenger*);
        void removePassenger(Passenger*);

        float calculateDuration();
        int calculateScalesNumber();

        std::string serializer() const;
        void showData() const;
};
