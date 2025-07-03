#include "include/AirlineSystem.hpp"
#include "include/Airplane.hpp"
#include "include/Flight.hpp"
#include "include/Passenger.hpp"
#include "include/Pilot.hpp"
#include "include/Menu.hpp"
#include <iostream>
#include <limits>

using namespace std;

void safeGetLine(std::istream& is, std::string& str) {
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(is, str);
}
void registerAirplane(AirlineSystem*);
void registerPilot(AirlineSystem*);

void showTestMenu() {
    std::cout << "1. Cadastrar Aeronave" << std::endl;
    std::cout << "2. Cadastrar Piloto" << std::endl;
    std::cout << "3. Cadastrar Passageiro" << std::endl;
    std::cout << "4. Criar Voo" << std::endl;
    std::cout << "5. Embarcar Passageiro" << std::endl;
    std::cout << "6. Listar voos" << std::endl;
    std::cout << "7. Listar Passageiros em voo" << std::endl;
    std::cout << "Escolha uma opção: " << std::endl;

}
int main(void) {
    /*
    AirlineSystem system;

    Airplane* airplane = new Airplane("0001", "Boeing", 100, 120, 21);
    Pilot* pilot = new Pilot("Jorge Alberto", 25, "ooox", 250);
    Pilot* copilot = new Pilot("Jorge Armando", 28, "uuux", 100);

    Flight* flight = new Flight("000", "Brazil", "Dubai", airplane, pilot, copilot);
    flight->setDistance("2000");

    std::cout << "Scales Number: " << flight->calculateAndSetScalesNumber() << std::endl;
    flight->calculateAndSetDuration();

    int hours = (int) flight->getEstimatedDuration();
    int minutes = ((flight->getEstimatedDuration() - hours) * 60);
    std::cout << "Estimated duration -- " << hours << " hours, " << minutes << " minutes" << std::endl;
 */
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
/*
            case MenuOption::PASSENGERS_OF_FLIGHT:
                systemMenu.showPassengersOfFlight();
                break;
            case MenuOption::GENERATE_STATICS:
                systemMenu.generateStatics();
                break;
            case MenuOption::SAVE_AND_EXIT:
                systemMenu.saveAndExit();
                break;*/
            default:
                    break;
        }
    }
}
