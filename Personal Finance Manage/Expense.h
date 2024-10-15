#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>
#include "Category.h"

class Expense {
public:
    Expense(std::string month, std::string name, double amount, Category category);
    double getAmount() const;
    std::string getMonth() const;  // Add a getter for month
    std::string getName() const;
    Category getCategory() const;

private:
    std::string month;  // Add a month field
    std::string name;
    double amount;
    Category category;
};

#endif // EXPENSE_H
