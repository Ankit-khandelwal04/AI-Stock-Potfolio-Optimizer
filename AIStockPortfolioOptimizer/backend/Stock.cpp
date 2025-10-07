#include "Stock.h"

Stock::Stock(const std::string& symbol, const std::string& name, double price, double risk, double expectedReturn)
    : symbol(symbol), name(name), price(price), risk(risk), expectedReturn(expectedReturn) {}

std::string Stock::getSymbol() const {
    return symbol;
}

std::string Stock::getName() const {
    return name;
}

double Stock::getPrice() const {
    return price;
}

double Stock::getRisk() const {
    return risk;
}

double Stock::getExpectedReturn() const {
    return expectedReturn;
}

void Stock::setPrice(double newPrice) {
    price = newPrice;
}

void Stock::setRisk(double newRisk) {
    risk = newRisk;
}

void Stock::setExpectedReturn(double newExpectedReturn) {
    expectedReturn = newExpectedReturn;
}