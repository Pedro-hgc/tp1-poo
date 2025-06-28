#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "flight.hpp"
#include "airplane.hpp"
#include "person.hpp"
#include "passenger.hpp"

class Menu{
public:
// Funções internas do menu
static void registerAirplane();
static void registerPilot();
static void registerPassenger();
static void createFlight();
static void boardPassenger();
static void listFlights();
static void listFlightPassengers();
static void generateReports();
static void saveData();
static void clearInputBuffer();

static void displayMenu();
static void option(int);

};
