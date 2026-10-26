AUTOMATED CRYPTO PORTFOLIO & TRADING BOT
Mid-semester C++ version (up to operator overloading)

This is a simple classroom simulator. It uses sample prices only and does not connect to a real exchange.

Features:
- Show wallet balances and total portfolio value
- Deposit and withdraw cash
- Buy and sell BTC, ETH and DOGE using sample prices
- Check a price alert using a user-entered limit
- Operator overloading: +=, -=, < and >
- Separate header (.h) and source (.cpp) files

Compile with g++:
g++ -std=c++11 main.cpp currency.cpp balance.cpp wallet.cpp portfolio.cpp exchange.cpp tradingbot.cpp -o crypto_bot

Run:
./crypto_bot

Main files:
- currency.h/.cpp: currency name and ticker
- balance.h/.cpp: stores an amount
- wallet.h/.cpp: wallet and += / -= operators
- portfolio.h/.cpp: manages wallets and comparison operators
- exchange.h/.cpp: sample prices and simulated orders
- tradingbot.h/.cpp: buy/sell logic and portfolio operations
- main.cpp: menu
