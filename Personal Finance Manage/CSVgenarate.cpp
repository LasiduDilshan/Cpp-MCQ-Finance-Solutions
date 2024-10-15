#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed for random number generation
    std::srand(std::time(nullptr));

    // Create expenses.csv
    std::ofstream expensesFile("large_expenses.csv");
    if (!expensesFile.is_open()) {
        std::cerr << "Error opening expenses file!" << std::endl;
        return 1;
    }

    std::string months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    // Generate random expenses
    for (int i = 0; i < 100000; ++i) { // Generate 10,000 expense entries
        std::string month = months[std::rand() % 12];
        std::string category = "Category" + std::to_string(std::rand() % 10);
        double amount = std::rand() % 1000 + 1; // Random amount between 1 and 1000
        expensesFile << month << ", " << category << ", " << amount << "\n";
    }
    expensesFile.close();
    std::cout << "Large expenses.csv file created successfully!" << std::endl;

    // Create budgets.csv
    std::ofstream budgetsFile("large_budgets.csv");
    if (!budgetsFile.is_open()) {
        std::cerr << "Error opening budgets file!" << std::endl;
        return 1;
    }

    double baseBudget = 10000000.0; // Starting budget
    double increment = 2000000.0; // Increment for each month

    // Generate budgets for each month
    for (int i = 0; i < 12; ++i) {
        budgetsFile << months[i] << ", " << (baseBudget + i * increment) << "\n";
    }
    budgetsFile.close();
    std::cout << "Budgets.csv file created successfully!" << std::endl;

    return 0;
}
