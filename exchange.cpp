#include "exchange.h"
#include <iostream>
using namespace std;

// These are sample coinprices
double exchange::getprice(string cointicker) const {
    if (cointicker == "INR") return 1;
    if (cointicker == "BTC") return 6000000;
    if (cointicker == "ETH") return 250000;
    if (cointicker == "DOGE") return 12;
    return 0;
}

bool exchange::placeorder(string cointicker, string ordertype, double quantity) const {
    if (getprice(cointicker) == 0 || quantity <= 0) {
        cout << "Invalid order.\n";
        return false;
    }

    cout << "Simulated " << ordertype << " order: "
         << quantity << " " << cointicker << "\n";
    return true;
}
