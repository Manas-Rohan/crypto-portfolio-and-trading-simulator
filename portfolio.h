#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include "wallet.h"

class portfolio {
private:
    wallet walletlist[4];
    int walletcount;

public:
    portfolio();

    int getcount() const;
    wallet& getwallet(int index);
    const wallet& getwallet(int index) const;
    double totalvalue(const double coinprices[]) const;
    void show(const double coinprices[]) const;

    bool operator>(const portfolio& otherportfolio) const;
    bool operator<(const portfolio& otherportfolio) const;
};

#endif
