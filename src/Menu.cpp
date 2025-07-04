#include "../include/Menu.hpp"
#include "../include/InputUtils.hpp"
#include <iostream>

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

    std::string registration = InputUtils::safeGetLine("Digite a Matricula de " + name + ": ");
    std::string license = InputUtils::safeGetLine("Digite o Brevê de " + name + ": ");

    int hours = InputUtils::safeGetInt("Digite quantas Horas " + name + " já voou: ");

    Pilot* pilot = new Pilot(name, age, license, registration, hours);

    return this->system->registerNewPilot(pilot);
}

bool Menu::registerPassenger(void) {
    std::string name = InputUtils::safeGetLine("Digite o nome do Passageiro: ");

    int age = InputUtils::safeGetInt("Digite a idade de " + name + ": ");

    std::string ticket = InputUtils::safeGetLine("Digite o número do bilhete de " + name + ": ");
    std::string cpf = InputUtils::safeGetLine("Digite o CPF de " + name + ": ");

    Passenger* passenger = new Passenger(name, age, ticket, cpf);

    return this->system->registerNewPassenger(passenger);
}

bool Menu::registerNewFlight() {
    std::string code = InputUtils::safeGetLine("Digite o código do voo: ");
    std::string origin = InputUtils::safeGetLine("Digite a origem do voo: ");
    std::string destination = InputUtils::safeGetLine("Digite o destino do voo: ");
    std::string distance = InputUtils::safeGetLine("Digite a Distância do voo: ");
    std::string departureTime= InputUtils::safeGetLine("Digite a Data e Hora de saída Prevista: ");
    std::string arrivalTime = InputUtils::safeGetLine("Digite a Data e Hora de chegada Estimada: ");

    std::cout << "Escolha entre uma das Aeronaves abaixo através do código:" << std::endl;
    this->system->showAirplanes();

    Airplane* airplaneChosen = NULL;
    while (airplaneChosen == NULL){
        std::string airplaneCode = InputUtils::safeGetLine("Digite o código da Aeronave desejada: ");
        airplaneChosen = this->system->getAirplane(airplaneCode);
    }

    Pilot* pilot = NULL, *copilot = NULL;

    std::cout << "Escolha um dos Pilotos abaixo para ser o Comandante do voo: " << std::endl;
    this->system->showPilots();
    while (pilot == NULL){
        std::string license = InputUtils::safeGetLine("Digite a licença do Comandante Escolhido: ");
        pilot = this->system->getPilot(license);

    }
    std::cout << "Comandante " << pilot->getName() << " escolhido!" << std::endl;

    std::cout << "Agora escolha outro Piloto para ser o Primeiro Oficial do voo: " << std::endl;
    while (copilot == NULL || copilot->getLicense() == pilot->getLicense()){
        std::string license = InputUtils::safeGetLine("Digite a licença do Primeiro Oficial Escolhido: ");
        copilot = this->system->getPilot(license);

    }
    std::cout << "Primeiro Oficial " << copilot->getName() << "escolhido!" << std::endl;


    Flight* newFlight = new Flight(code, origin, destination, airplaneChosen, pilot, copilot );

    newFlight->setDistance(distance);
    newFlight->setDepartureDate(departureTime);
    newFlight->setArrivalDate(arrivalTime);
    newFlight->calculateAndSetDuration();
    newFlight->calculateAndSetScalesNumber();

    if (this->system->getNumOfPassengers() != 0) {
        std::cout << "Escolha os Passageiros abaixo que deseja embarcar" << std::endl;
        this->system->showPassengers();

        std::string  cpfOfPassenger;
        do {
            Passenger* passengerToEmbark;
            cpfOfPassenger = InputUtils::safeGetLine("Digite o CPF do Passageiro para embarca-lo ou FIM caso queira parar: ");
            passengerToEmbark = this->system->getPassenger(cpfOfPassenger);
            if (passengerToEmbark != NULL){
                newFlight->addPassenger(passengerToEmbark);
                std::cout << "Passageiro " <<  passengerToEmbark->getName() << " embarcado!" << std::endl;
            }
        }while(cpfOfPassenger != "FIM");
    }


    this->system->registerNewFlight(newFlight);
    return true;

}

void Menu::boardPassenger(void) {
    std::cout << " --------- Os voos registrados são --------- " << std::endl << std::endl;
    this->system->showFlightsAvaibles();
    std::string code;
    Flight *flightSelected = NULL;
    do {
        code = InputUtils::safeGetLine("Selecione um dos Voos registrados através do código: ");
        flightSelected = this->system->getFlight(code);
    } while (flightSelected == NULL && code != "VOLTAR");

    std::cout << std::endl << "-------- Os Passageiros registrados são --------" << std::endl << std::endl;
    this->system->showPassengers();

    if (flightSelected == NULL) return;

    Passenger* passengerSelected = NULL;
    do {
        code = InputUtils::safeGetLine("Digite o CPF do passageiro a embarcar: ");
        passengerSelected = this->system->getPassenger(code);
        if (passengerSelected != NULL){
            if (flightSelected->addPassenger(passengerSelected))
                std::cout << "Passageiro " << passengerSelected->getName() << " adicionado ao voo " << flightSelected->getCode() << " com sucesso!" << std::endl;
            else
                return;
        }
    }while (code != "FIM");
}

void Menu::showFlightsList(void) {
    std::cout << " --------- Os voos registrados são --------- " << std::endl << std::endl;
    this->system->showFlightsAvaibles();

}

void Menu::showPassengersOfFlight(void) {
    std::cout << " --------- Os voos registrados são --------- " << std::endl << std::endl;
    this->system->showFlightsAvaibles();
    std::string code;
    Flight *flightSelected = NULL;
    do {
        code = InputUtils::safeGetLine("Selecione um dos Voos registrados através do código: ");
        flightSelected = this->system->getFlight(code);
    } while (flightSelected == NULL && code != "VOLTAR");

    std::cout << "Código da Aeronave: " << flightSelected->getAirplane()->getCode() << std::endl;
    std::cout << "Modelo da Aeronave: " << flightSelected->getAirplane()->getModel() << std::endl;

    std::vector<Passenger*> passenger = flightSelected->getPassengers();


    std::cout << "------- Nome dos Passageiros A bordo -------" << std::endl;
    for (Passenger* p: passenger)
        std::cout << p->getName() << std::endl;
}
