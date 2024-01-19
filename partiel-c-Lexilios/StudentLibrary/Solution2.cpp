#include "Solution2.h"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <ostream>

// Don't forget to enable the exercise in the SudentConfiguration.h file !
#include "StudentConfiguration.h"
#ifdef COMPILE_EXERCICE_2

float Solution2::GetBalance(const std::string& accountName)
{
    std::ifstream file("BankAccount/" + accountName + ".txt");
    if (!file.is_open()) {
        throw std::runtime_error("File not found");
    }

    float balance = 0.0f;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string operation;
        float amount;
        if ((iss >> operation >> amount)) {
            if (operation == "DEPOSIT") {
                balance += amount;
            }
            else if (operation == "WITHDRAW") {
                balance -= amount;
            }
        }
    }

    file.close();
    return balance;
}

#endif
