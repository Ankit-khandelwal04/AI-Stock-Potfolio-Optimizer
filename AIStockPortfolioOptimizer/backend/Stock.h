#ifndef STOCK_H
#define STOCK_H

#include <string>

class Stock {
public:
    // Constructor
    Stock(const std::string& symbol, const std::string& name, double price, double risk, double expectedReturn);

    // Accessor methods
    std::string getSymbol() const;
    std::string getName() const;
    double getPrice() const;
    double getRisk() const;
    double getExpectedReturn() const;

    // Mutator methods
    void setPrice(double price);
    void setRisk(double risk);
    void setExpectedReturn(double expectedReturn);

private:
    std::string symbol;
    std::string name;
    double price;
    double risk;
    double expectedReturn;
};

#endif // STOCK_H