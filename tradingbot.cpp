#include "tradingbot.h"
#include <iostream>
#include <iomanip>
using namespace std;

tradingbot::tradingbot() {
    coinprices[0] = exchangeapi.getprice("INR");
    coinprices[1] = exchangeapi.getprice("BTC");
    coinprices[2] = exchangeapi.getprice("ETH");
    coinprices[3] = exchangeapi.getprice("DOGE");
}

void tradingbot::showportfolio() const {
    userportfolio.show(coinprices);
}

void tradingbot::depositcash(double amount) {
    if (amount <= 0) {
        cout << "Enter a positive amount.\n";
        return;
    }
    userportfolio.getwallet(0) += amount;
    cout << "Cash deposited.\n";
}

void tradingbot::withdrawcash(double amount) {
    if (amount <= 0 || amount > userportfolio.getwallet(0).getamount()) {
        cout << "Invalid amount or insufficient cashwallet.\n";
        return;
    }
    userportfolio.getwallet(0) -= amount;
    cout << "Cash withdrawn.\n";
}

void tradingbot::buycoin(int walletindex, double quantity) {
    if (walletindex < 1 || walletindex > 3 || quantity <= 0) {
        cout << "Invalid selection or quantity.\n";
        return;
    }

    wallet& cashwallet = userportfolio.getwallet(0);
    wallet& coinwallet = userportfolio.getwallet(walletindex);
    double buycost = quantity * coinprices[walletindex];

    if (buycost > cashwallet.getamount()) {
        cout << "Not enough cashwallet for this purchase.\n";
        return;
    }

    if (exchangeapi.placeorder(coinwallet.getticker(), "BUY", quantity)) {
        cashwallet -= buycost;
        coinwallet += quantity;
        cout << "Purchase successful. Cost: Rs. "
             << fixed << setprecision(2) << buycost << "\n";
    }
}

void tradingbot::sellcoin(int walletindex, double quantity) {
    if (walletindex < 1 || walletindex > 3 || quantity <= 0) {
        cout << "Invalid selection or quantity.\n";
        return;
    }

    wallet& cashwallet = userportfolio.getwallet(0);
    wallet& coinwallet = userportfolio.getwallet(walletindex);

    if (quantity > coinwallet.getamount()) {
        cout << "Not enough coins in your wallet.\n";
        return;
    }

    double amount = quantity * coinprices[walletindex];
    if (exchangeapi.placeorder(coinwallet.getticker(), "SELL", quantity)) {
        coinwallet -= quantity;
        cashwallet += amount;
        cout << "Sale successful. Received: Rs. "
             << fixed << setprecision(2) << amount << "\n";
    }
}

void tradingbot::pricealert(int walletindex, double pricelimit) const {
    if (walletindex < 1 || walletindex > 3 || pricelimit <= 0) {
        cout << "Invalid selection or price pricelimit.\n";
        return;
    }

    if (coinprices[walletindex] <= pricelimit) {
        cout << "Alert: price is at or below your pricelimit.\n";
    } else {
        cout << "Price is above your pricelimit.\n";
    }
}

void tradingbot::compareportfolio(const portfolio& otherportfolio) const {
    if (userportfolio > otherportfolio) {
        cout << "Your portfolio is worth more than the comparison userportfolio.\n";
    } else if (userportfolio < otherportfolio) {
        cout << "Your portfolio is worth less than the comparison userportfolio.\n";
    } else {
        cout << "Both portfolios have equal value.\n";
    }
}
