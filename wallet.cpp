#include "wallet.h"

wallet::wallet() {
    coininfo = currency();
    walletbalance = balance();
}

wallet::wallet(currency c, double amount) {
    coininfo = c;
    walletbalance = balance(amount);
}

string wallet::getname() const {
    return coininfo.getname();
}

string wallet::getticker() const {
    return coininfo.getticker();
}

double wallet::getamount() const {
    return walletbalance.getamount();
}

void wallet::setamount(double amount) {
    walletbalance.setamount(amount);
}

wallet& wallet::operator+=(double amount) {
    if (amount > 0) {
        walletbalance.setamount(walletbalance.getamount() + amount);
    }
    return *this;
}

wallet& wallet::operator-=(double amount) {
    if (amount > 0 && amount <= walletbalance.getamount()) {
        walletbalance.setamount(walletbalance.getamount() - amount);
    }
    return *this;
}
