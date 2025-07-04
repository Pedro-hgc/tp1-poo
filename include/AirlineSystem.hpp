#pragma once

#include <vector>

#include "Airplane.hpp"
#include "Pilot.hpp"
#include "Passenger.hpp"
#include "Flight.hpp"

class AirlineSystem {
private:
        std::vector<Airplane*> airplanes;
        std::vector<Pilot*> pilots;
        std::vector<Passenger*> passengers;
        std::vector<Flight*> flights_avaibles;

public:
        AirlineSystem();
        ~AirlineSystem();

        // The Class Menu will have a system.
        // Inside the class Menu will have options
        // This options creates Airplanes, Pilots, Passengers
        // After is created in the method from Menu, then
        // The Object will be pushed to the correct vector
        bool registerNewAirplane(Airplane* newAirplane);
        bool registerNewPilot(Pilot* newPilot);
        bool registerNewPassenger(Passenger* newPassenger);
        bool registerNewFlight(Flight* newFlight);
        bool boardPassenger(Passenger* passengerToBoard);

        // This is used to get the INFO from All elements.
        // Will be used by menu to show: the Passengers Registered
        // Flights avaibles, Pilots registered, etc.
        // Will show in the interface the information.
        // So if a specif Pilot is wanted then will pass to
        // getPilot(The license showed by showPilots())
        void showAirplanes(void);
        void showPilots(void);
        void showPassengers(void);

        void showFlightsAvaibles(void);

        // This is used to get ONE element from the Vectors
        Airplane*  getAirplane(std::string cod);
        Pilot*     getPilot(std::string licenseNumber);
        Passenger* getPassenger(std::string cpf);
        Flight*    getFlight(std::string code);

        int getNumOfPassengers(void);

};
