#include "../include/metrics.h"

#include <cmath>

double Metrics::mse(
    const std::vector<double>& actual,
    const std::vector<double>& predicted
) {

    double error = 0.0;

    for (int i = 0; i < actual.size(); i++) {

        double diff =
            actual[i] - predicted[i];

        error += diff * diff;
    }

    return error / actual.size();
}

double Metrics::rmse(
    const std::vector<double>& actual,
    const std::vector<double>& predicted
) {

    return sqrt(
        mse(actual, predicted)
    );
}

double Metrics::mae(
    const std::vector<double>& actual,
    const std::vector<double>& predicted
) {

    double error = 0.0;

    for (int i = 0; i < actual.size(); i++) {

        error += abs(
            actual[i] - predicted[i]
        );
    }

    return error / actual.size();
}

double Metrics::r2Score(
    const std::vector<double>& actual,
    const std::vector<double>& predicted
) {

    double mean = 0.0;

    for (double val : actual) {
        mean += val;
    }

    mean /= actual.size();

    double ssTotal = 0.0;
    double ssResidual = 0.0;

    for (int i = 0; i < actual.size(); i++) {

        ssTotal +=
            (actual[i] - mean)
            * (actual[i] - mean);

        ssResidual +=
            (actual[i] - predicted[i])
            * (actual[i] - predicted[i]);
    }

    return 1 -
        (ssResidual / ssTotal);
}