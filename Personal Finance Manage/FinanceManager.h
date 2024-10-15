#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <vector>
#include "Budget.h"
#include "Expense.h"

class FinanceManager {
public:
    FinanceManager();
    void addExpense(const Expense& expense); // <-- Declare addExpense here
    void loadBudgetsFromCSV(const std::string& filename);
    void loadExpensesFromCSV(const std::string& filename);
    void trackMonthlyFinances(const std::string& outputFilename);

private:
    std::vector<Expense> expenses;
    std::vector<Budget> budgets;

};

#endif // FINANCEMANAGER_H