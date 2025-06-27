#include <iostream>
#include "../include/menu.hpp"
using namespace std;

void Menu::displayMenu() {
    cout << "===== SISTEMA DE CONTROLE DE VOOS =====" << endl;
    cout << "1. Cadastrar aeronave" << endl;
    cout << "2. Cadastrar piloto" << endl;
    cout << "3. Cadastrar passageiro" << endl;
    cout << "4. Criar voo" << endl;
    cout << "5. Embarcar passageiro em voo" << endl;
    cout << "6. Listar voos" << endl;
    cout << "7. Listar passageiros de um voo" << endl;
    cout << "8. Gerar relatórios e estatísticas" << endl;
    cout << "9. Salvar dados e sair" << endl;
    cout << "=======================================" << endl;
    cout << "Escolha uma opção: ";
}
void Menu::option(int option) {
    switch (option) {
        case 1: registerAirplane(); break;
        case 2: registerPilot(); break;
        case 3: registerPassenger(); break;
        case 4: createFlight(); break;
        case 5: boardPassenger(); break;
        case 6: listFlights(); break;
        case 7: listFlightPassengers(); break;
        case 8: generateReports(); break;
        case 9: saveData(); break;
        default: cerr << "Opção inválida!" << endl;
    }
}

