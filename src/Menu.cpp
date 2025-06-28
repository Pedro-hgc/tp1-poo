#include "../include/Menu.hpp"
#include "../include/InputUtils.hpp"
#include <format>

Menu::Menu() {
    this->system = new AirlineSystem();
}
Menu::~Menu(){
    this->system->~AirlineSystem();
    delete this->system;
}

MenuOption Menu::displayMenu(void) {
    std::cout << "======= SISTEMA DE CONTROLE DE VOOS =======" << std::endl;
    std::cout << "1. Cadastrar Aeronave" << std::endl;
    std::cout << "2. Cadastrar Piloto" << std::endl;
    std::cout << "3. Cadastrar Passageiro" << std::endl;
    std::cout << "4. Criar Voo" << std::endl;
    std::cout << "5. Embarcar Passageiro" << std::endl;
    std::cout << "6. Listar voos" << std::endl;
    std::cout << "7. Listar Passageiros de um voo" << std::endl;
    std::cout << "8. Gerar relatórios e estatísticas" << std::endl;
    std::cout << "9. Salvar dados e sair" << std::endl;
    std::cout << "============================================" << std::endl;


    int option = InputUtils::safeGetIntegerInRange("Escolha uma opção: ", 1, 9);
    return (MenuOption)option;

}

bool Menu::registerAirplane(void) {

    std::string cod = InputUtils::safeGetLine("Digite o código da Aeronave: ");

    std::string model = InputUtils::safeGetLine("Digite o modelo da Aernonave: ");

    int capacity = InputUtils::safeGetInt("Digite a capacidade da Aeronave: ");

    float medium_vel = InputUtils::safeGetFloat("Digite a Velocidade Media da Aeronave: ");

    float autonomy = InputUtils::safeGetFloat("Digite a Autonomia do Avião (milhas): ");

    Airplane* newAirplane = new Airplane(cod, model, capacity, medium_vel, autonomy);
    return this->system->registerNewAirplane(newAirplane);
}

bool Menu::registerPilot(void) {
    std::string name = InputUtils::safeGetLine("Digite o nome do Piloto: ");

    int age = InputUtils::safeGetInt("Digite a idade de " + name + ": ");

    std::string license = InputUtils::safeGetLine("Digite a Licença de " + name + ": ");

    int hours = InputUtils::safeGetInt("Digite quantas Horas " + name + " já voou: ");

    Pilot* pilot = new Pilot(name, age, license, hours);

    return this->system->registerNewPilot(pilot);
}

bool Menu::registerPassenger(void) {
    std::string name = InputUtils::safeGetLine("Digite o nome do Passageiro: ");

    int age = InputUtils::safeGetInt("Digite a idade de " + name + ": ");

    std::string ticket = InputUtils::safeGetLine("Digite o número do bilhete de " + name + ": ");

    Passenger* passenger = new Passenger(name, age, ticket, "");

    return this->system->registerNewPassenger(passenger);
}

bool Menu::registerNewFlight() {
    std::string code = InputUtils::safeGetLine("Digite o código do voo: ");
    std::string origin = InputUtils::safeGetLine("Digite a origem do voo: ");
    std::string destination = InputUtils::safeGetLine("Digite o destino do voo: ");

    std::cout << "Escolha entre uma das Aeronaves abaixo através do código:" << std::endl;
    this->system->showAirplanes();

    Airplane* airplaneChosen = NULL;
    while (airplaneChosen == NULL){
        std::string airplaneCode = InputUtils::safeGetLine("Digite o código da Aeronave desejada: ");
        airplaneChosen = this->system->getAirplane(airplaneCode);
    }

    Pilot* pilot = NULL, *copilot = NULL;

    std::cout << "Escolha um dos Pilotos abaixo para ser o Comandante do voo: ";
    this->system->showPilots();
    while (pilot == NULL){
        std::string license = InputUtils::safeGetLine("Digite a licença do Comandante Escolhido: ");
        pilot = this->system->getPilot(license);
    }



}
