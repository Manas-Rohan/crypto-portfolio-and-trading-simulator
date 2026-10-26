#ifndef BALANCE_H
#define BALANCE_H

class balance {
private:
    double amount;

public:
    balance();
    balance(double value);

    double getamount() const;
    void setamount(double value);
};

#endif
