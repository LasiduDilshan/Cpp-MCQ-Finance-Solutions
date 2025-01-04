#include "Budget.h"

Budget::Budget(double amount) : amount(amount) {}

void Budget::setAmount(double amount) {
    this->amount = amount;
}

double Budget::getAmount() const {
    return amount;
}
