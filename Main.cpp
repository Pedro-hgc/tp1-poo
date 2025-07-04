#include "include/AirlineSystem.hpp"
#include "include/Airplane.hpp"
#include "include/Flight.hpp"
#include "include/Passenger.hpp"
#include "include/Pilot.hpp"
#include "include/Menu.hpp"
#include <iostream>
#include <limits>


int main(void) {
    Menu systemMenu;
    while (1) {
        switch(systemMenu.displayMenu()) {
            case MenuOption::REGISTER_AIRPLANE:
                if(systemMenu.registerAirplane())
                    std::cout << "Avião registrado com Sucesso na base de dados!" << std::endl;
                break;
            case MenuOption::REGISTER_PILOT:
                if(systemMenu.registerPilot())
                    std::cout << "Piloto registrado com Sucesso na base de dados!" << std::endl;
                break;

            case MenuOption::REGISTER_PASSENGER:
                if(systemMenu.registerPassenger())
                    std::cout << "Passageiro registrado com Sucesso na base de dados!" << std::endl;
                break;

            case MenuOption::REGISTER_FLIGHT:
                if(systemMenu.registerNewFlight())
                    std::cout << "Voo registrado com Sucesso na base de dados!" << std::endl;
                break;

            case MenuOption::BOARD_PASSENGER:
                systemMenu.boardPassenger();
                break;
            case MenuOption::LIST_FLIGHTS:
                systemMenu.showFlightsList();
                break;

            case MenuOption::PASSENGERS_OF_FLIGHT:
                systemMenu.showPassengersOfFlight();
                break;
           case MenuOption::SAVE_AND_EXIT:
                systemMenu.saveAndExit();
                break;
            default:
                    break;
        }
    }
}
