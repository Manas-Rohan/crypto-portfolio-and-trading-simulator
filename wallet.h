#ifndef WALLET_H
#define WALLET_H

#include "currency.h"
#include "balance.h"

class wallet {
private:
    currency coininfo;
    balance walletbalance;

public:
    wallet();
    wallet(currency c, double amount);

    string getname() const;
    string getticker() const;
    double getamount() const;
    void setamount(double amount);

    wallet& operator+=(double amount);
    wallet& operator-=(double amount);
};

#endif
