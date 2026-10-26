#ifndef EXCHANGEAPI_H
#define EXCHANGEAPI_H

#include <string>
using namespace std;

class exchange {
public:
    double getprice(string cointicker) const;
    bool placeorder(string cointicker, string ordertype, double quantity) const;
};

#endif
