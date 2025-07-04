#pragma once

#include "AirlineSystem.hpp"

enum class MenuOption {
    REGISTER_AIRPLANE    = 1,
    REGISTER_PILOT       = 2,
    REGISTER_PASSENGER   = 3,
    REGISTER_FLIGHT      = 4,
    BOARD_PASSENGER      = 5,
    LIST_FLIGHTS         = 6,
    PASSENGERS_OF_FLIGHT = 7,
    SAVE_AND_EXIT        = 8,
};

class Menu {
private:
        AirlineSystem* system;
public:
        Menu();
        ~Menu();
        MenuOption displayMenu(void);

        bool registerAirplane       (void);
        bool registerPilot          (void);
        bool registerPassenger      (void);
        bool registerNewFlight      (void);
        void boardPassenger         (void);
        void showFlightsList        (void);
        void showPassengersOfFlight (void);
        void saveAndExit            (void);

};
