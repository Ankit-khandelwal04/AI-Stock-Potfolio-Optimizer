#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include <vector>
#include <string>
#include <unordered_map>
#include "Stock.h"

class Portfolio {
public:
    void addStock(const Stock& stock);
    void removeStock(const std::string& symbol);
    double calculateTotalValue();
    double getRisk();
    double getExpectedReturn();

    // Return a vector view of stocks for iteration (copy of values)
    std::vector<Stock> getStocks() const;

private:
    std::unordered_map<std::string, Stock> stocks;
};

#endif // PORTFOLIO_H