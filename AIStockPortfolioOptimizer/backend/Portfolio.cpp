#include "Portfolio.h"
#include "Stock.h"
#include <numeric>

void Portfolio::addStock(const Stock& stock) {
    stocks[stock.getSymbol()] = stock;
}

void Portfolio::removeStock(const std::string& symbol) {
    stocks.erase(symbol);
}

double Portfolio::calculateTotalValue() {
    double totalValue = 0.0;
    for (const auto& pair : stocks) {
        totalValue += pair.second.getPrice();
    }
    return totalValue;
}

double Portfolio::getRisk() {
    if (stocks.empty()) return 0.0;
    double totalRisk = 0.0;
    for (const auto& pair : stocks) {
        totalRisk += pair.second.getRisk();
    }
    return totalRisk / static_cast<double>(stocks.size());
}

double Portfolio::getExpectedReturn() {
    if (stocks.empty()) return 0.0;
    double totalReturn = 0.0;
    for (const auto& pair : stocks) {
        totalReturn += pair.second.getExpectedReturn();
    }
    return totalReturn / static_cast<double>(stocks.size());
}

std::vector<Stock> Portfolio::getStocks() const {
    std::vector<Stock> out;
    out.reserve(stocks.size());
    for (const auto& pair : stocks) out.push_back(pair.second);
    return out;
}