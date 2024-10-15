#ifndef BUDGET_H
#define BUDGET_H

class Budget {
public:
    Budget(double amount = 0.0);
    void setAmount(double amount);
    double getAmount() const;

private:
    double amount;
};

#endif // BUDGET_H
