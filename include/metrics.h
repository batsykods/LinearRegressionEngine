#ifndef METRICS_H
#define METRICS_H

#include <vector>

class Metrics {

public:

    static double mse(
        const std::vector<double>& actual,
        const std::vector<double>& predicted
    );

    static double rmse(
        const std::vector<double>& actual,
        const std::vector<double>& predicted
    );

    static double mae(
        const std::vector<double>& actual,
        const std::vector<double>& predicted
    );

    static double r2Score(
        const std::vector<double>& actual,
        const std::vector<double>& predicted
    );
};

#endif