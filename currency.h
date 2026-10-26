#ifndef CURRENCY_H
#define CURRENCY_H

#include <string>
using namespace std;

class currency {
private:
    string currencyname;
    string cointicker;

public:
    currency();
    currency(string n, string t);

    string getname() const;
    string getticker() const;
};

#endif
