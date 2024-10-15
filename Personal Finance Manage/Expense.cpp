#include "Expense.h"

Expense::Expense(std::string month, std::string name, double amount, Category category)
    : month(month), name(name), amount(amount), category(category) {}

double Expense::getAmount() const {
    return amount;
}

std::string Expense::getMonth() const {
    return month;  // Return the month
}

std::string Expense::getName() const {
    return name;
}

Category Expense::getCategory() const {
    return category;
}
