#include "portfolio.h"
#include <iostream>
#include <iomanip>
using namespace std;

portfolio::portfolio() {
    walletcount = 4;
    walletlist[0] = wallet(currency("Indian Rupee", "INR"), 100000);
    walletlist[1] = wallet(currency("Bitcoin", "BTC"), 0);
    walletlist[2] = wallet(currency("Ethereum", "ETH"), 0);
    walletlist[3] = wallet(currency("Dogecoin", "DOGE"), 0);
}

int portfolio::getcount() const {
    return walletcount;
}

wallet& portfolio::getwallet(int index) {
    return walletlist[index];
}

const wallet& portfolio::getwallet(int index) const {
    return walletlist[index];
}

double portfolio::totalvalue(const double coinprices[]) const {
    double total = 0;
    for (int i = 0; i < walletcount; i++) {
        total += walletlist[i].getamount() * coinprices[i];
    }
    return total;
}

void portfolio::show(const double coinprices[]) const {
    cout << "\n----------- MY PORTFOLIO -----------\n";
    cout << left << setw(18) << "currency"
         << setw(12) << "Ticker"
         << setw(16) << "balance"
         << "Price\n";
    for (int i = 0; i < walletcount; i++) {
        cout << left << setw(18) << walletlist[i].getname()
             << setw(12) << walletlist[i].getticker()
             << setw(16) << fixed << setprecision(4) << walletlist[i].getamount()
             << fixed << setprecision(2) << coinprices[i] << '\n';
    }
    cout << "portfolio value: Rs. " << fixed << setprecision(2)
         << totalvalue(coinprices) << "\n";
}


bool portfolio::operator>(const portfolio& otherportfolio) const {
    double coinprices[4] = {1, 6000000, 250000, 12};
    double myvalue = totalvalue(coinprices);
    double othervalue = otherportfolio.totalvalue(coinprices);
    return myvalue > othervalue;
}

bool portfolio::operator<(const portfolio& otherportfolio) const {
    double coinprices[4] = {1, 6000000, 250000, 12};
    double myvalue = totalvalue(coinprices);
    double othervalue = otherportfolio.totalvalue(coinprices);
    return myvalue < othervalue;
}
