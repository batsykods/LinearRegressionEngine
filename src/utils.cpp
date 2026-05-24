#include "../include/utils.h"

#include <cmath>
#include <vector>

double Utils::mean(
    const std::vector<double>& data
) {

    double sum = 0.0;

    for (double val : data) {
        sum += val;
    }

    return sum / data.size();
}

double Utils::stddev(
    const std::vector<double>& data
) {

    double m = mean(data);

    double variance = 0.0;

    for (double val : data) {

        variance +=
            (val - m)
            * (val - m);
    }

    variance /= data.size();

    return sqrt(variance);
}

void Utils::normalizeFeatures(
    std::vector<std::vector<double>>& X,
    std::vector<double>& means,
    std::vector<double>& stds
) {

    int numFeatures =
        X[0].size();

    means.resize(numFeatures);
    stds.resize(numFeatures);

    for (int col = 0;
         col < numFeatures;
         col++) {

        std::vector<double> values;

        for (auto& row : X) {

            values.push_back(
                row[col]
            );
        }

        means[col] =
            mean(values);

        stds[col] =
            stddev(values);

        for (auto& row : X) {

            row[col] =
                (row[col] - means[col])
                / stds[col];
        }
    }
}

double Utils::normalizeValue(
    double value,
    double meanValue,
    double stdValue
) {

    return
        (value - meanValue)
        / stdValue;
}