#include "balance.h"

balance::balance() {
    amount = 0;
}

balance::balance(double value) {
    amount = value;
}

double balance::getamount() const {
    return amount;
}

void balance::setamount(double value) {
    amount = value;
}
