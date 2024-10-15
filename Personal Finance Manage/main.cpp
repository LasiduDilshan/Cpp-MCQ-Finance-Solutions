#include <iostream>
#include "FinanceManager.h"

int main() {
    FinanceManager manager;

    // Load budgets and expenses from CSV files
    //manager.loadBudgetsFromCSV("budgets.csv");
    //manager.loadExpensesFromCSV("expenses.csv");
    manager.loadBudgetsFromCSV("large_budgets.csv");
    manager.loadExpensesFromCSV("large_expenses.csv");

    // Track monthly finances and generate output
    manager.trackMonthlyFinances("output.csv");

    std::cout << "Monthly financial tracking completed. Check output.csv." << std::endl;

    return 0;
}
