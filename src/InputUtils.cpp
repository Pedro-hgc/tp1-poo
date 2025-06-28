#include "../include/InputUtils.hpp"
#include <iostream>
#include <limits>
#include <sstream>

void InputUtils::flushStdin(void) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string InputUtils::safeGetLine(const std::string& prompt) {
    std::string input;

    while (true) {
        std::cout << prompt;

        if (std::getline(std::cin, input)) {
            if (!input.empty())
                return input;
        }
        else {
            InputUtils::flushStdin();
        }
    }

}

int InputUtils::safeGetInt(const std::string& prompt) {
    std::string input;
    int value;

    while (true) {
        std::cout << prompt;
        input = safeGetLine("");

        std::stringstream ss(input);

        if (ss >> value && ss.eof())
            return value;
        else
            std::cout << "Valor passado não é um inteiro!" << std::endl;
    }
}

int InputUtils::safeGetIntegerInRange(const std::string& prompt, int min, int max) {
   int value;

   while (true) {
       value = safeGetInt(prompt);

       if (value >= min && value <= max)
           return value;

       std::cout << "O valor deve estar no intervalo [" << min << "-" << max << "]. Tente novamente!" << std::endl;
   }
}
float InputUtils::safeGetFloat(const std::string& prompt) {
    std::string input;
    float value;

    while (true) {
        std::cout << prompt;
        input = safeGetLine("");

        std::stringstream ss(input);
        if (ss >> value && ss.eof())
            return value;

        std::cout << "Valor passado não é um Float válido!" << std::endl;
    }

}
