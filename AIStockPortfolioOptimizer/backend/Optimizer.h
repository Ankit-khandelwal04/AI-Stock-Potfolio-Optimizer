#ifndef OPTIMIZER_H
#define OPTIMIZER_H

#include <vector>
#include "Stock.h"

class Optimizer {
public:
    // budget is represented as an integer (e.g. whole currency units) because
    // the DP knapsack implementation requires discrete capacity indexing.
    std::vector<double> optimize(const std::vector<Stock>& stocks, int budget, double riskTolerance);
};

#endif // OPTIMIZER_H