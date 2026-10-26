#ifndef TRADINGBOT_H
#define TRADINGBOT_H

#include "portfolio.h"
#include "exchange.h"

class tradingbot {
private:
    portfolio userportfolio;
    exchange exchangeapi;
    double coinprices[4];

public:
    tradingbot();

    void showportfolio() const;
    void depositcash(double amount);
    void withdrawcash(double amount);
    void buycoin(int walletindex, double quantity);
    void sellcoin(int walletindex, double quantity);
    void pricealert(int walletindex, double pricelimit) const;
    void compareportfolio(const portfolio& otherportfolio) const;
};

#endif
