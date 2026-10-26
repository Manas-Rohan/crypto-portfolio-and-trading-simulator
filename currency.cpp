#include "currency.h"

currency::currency() {
    currencyname = "Unknown";
    cointicker = "NA";
}

currency::currency(string n, string t) {
    currencyname = n;
    cointicker = t;
}

string currency::getname() const {
    return currencyname;
}

string currency::getticker() const {
    return cointicker;
}
