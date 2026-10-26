#include <iostream>
#include <limits>
#include "tradingbot.h"
using namespace std;

int main() {
    tradingbot bot;
    int choice;

    do {
        cout << "\n         CRYPTO PORTFOLIO SIMULATOR          \n";
        cout << "1. Show portfolio\n";
        cout << "2. Deposit cash\n";
        cout << "3. Withdraw cash\n";
        cout << "4. Buy cryptocurrency\n";
        cout << "5. Sell cryptocurrency\n";
        cout << "6. Check price alert\n";
        cout << "7. Compare with an a fresh portfolio\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Enter a number:\n";
            return 0;
        }

        double amount;
        int coinchoice;

        switch (choice) {
        case 1:
            bot.showportfolio();
            break;

        case 2:
            cout << "Amount to deposit (Rs.): ";
            cin >> amount;
            bot.depositcash(amount);
            break;

        case 3:
            cout << "Amount to withdraw (Rs.): ";
            cin >> amount;
            bot.withdrawcash(amount);
            break;

        case 4:
            cout << "Choose coin: 1. BTC  2. ETH  3. DOGE: ";
            cin >> coinchoice;
            cout << "Quantity to buy: ";
            cin >> amount;
            bot.buycoin(coinchoice, amount);
            break;

        case 5:
            cout << "Choose coin: 1. BTC  2. ETH  3. DOGE: ";
            cin >> coinchoice;
            cout << "Quantity to sell: ";
            cin >> amount;
            bot.sellcoin(coinchoice, amount);
            break;

        case 6:
            cout << "Choose coin: 1. BTC  2. ETH  3. DOGE: ";
            cin >> coinchoice;
            cout << "Enter alert price in Rs.: ";
            cin >> amount;
            bot.pricealert(coinchoice, amount);
            break;

        case 7: {
            portfolio emptyportfolio;
            // Compare both portfolios to check their values.
            bot.compareportfolio(emptyportfolio);
            break;
        }

        case 0:
            cout << "Exiting simulator.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
