#include "FinanceManager.h"
#include "Expense.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <numeric>
#include <vector>
#include <map>
#include <algorithm> // For std::find
#include <stdexcept> // For std::out_of_range
#include <iomanip> // Include for std::fixed and std::setprecision


FinanceManager::FinanceManager() {}

// Define addExpense
void FinanceManager::addExpense(const Expense& expense) {
    expenses.push_back(expense); // Add the expense to the vector
}

// Implement loadBudgetsFromCSV
void FinanceManager::loadBudgetsFromCSV(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening budgets file!" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string month;
        double amount;
        if (ss >> month >> amount) {
            budgets.push_back(Budget(amount));
        }
    }

    file.close();
}

// Implement loadExpensesFromCSV
void FinanceManager::loadExpensesFromCSV(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening expenses file!" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string month;
        std::string name;
        double amount;

        // Capture 'month', 'name', and 'amount'
        if (std::getline(ss, month, ',') && std::getline(ss, name, ',') && ss >> amount) {
            addExpense(Expense(month, name, amount, Category("Miscellaneous"))); // Store expenses
        }
    }

    file.close();
}

// Implement trackMonthlyFinances
void FinanceManager::trackMonthlyFinances(const std::string& outputFilename) {
    std::ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file!" << std::endl;
        return;
    }

    double carryover = 0.0;

    // Output the header
    outputFile << "Month,Total Expenses,Budget,Remaining Budget,Carryover\n";

    // Define the correct order of months
    std::vector<std::string> monthOrder = {
        "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December"
    };

    // Set fixed and precision for output
    outputFile << std::fixed << std::setprecision(2);
    std::cout << std::fixed << std::setprecision(2); // For console output as well

    for (const auto& currentMonth : monthOrder) {
        // Calculate total expenses for the current month
        double totalExpenses = std::accumulate(expenses.begin(), expenses.end(), 0.0,
            [currentMonth](double sum, const Expense& exp) { 
                return sum + (exp.getMonth() == currentMonth ? exp.getAmount() : 0); 
            });

        // Find the corresponding budget index for the month
        size_t budgetIndex = std::distance(monthOrder.begin(), std::find(monthOrder.begin(), monthOrder.end(), currentMonth));
        double remainingBudget = budgets[budgetIndex].getAmount() - totalExpenses + carryover;

        // Write the tracking data for the month
        outputFile << currentMonth << "," << totalExpenses << "," 
                   << budgets[budgetIndex].getAmount() << "," << remainingBudget << "," << carryover << "\n";
        
        // Print the current month and total expenses to the console
        std::cout << "Current Month: " << currentMonth << ", Total Expenses: " << totalExpenses << std::endl;

        // Carry over any remaining budget to the next month
        carryover = (remainingBudget > 0) ? remainingBudget : 0;
    }

    outputFile.close();
}