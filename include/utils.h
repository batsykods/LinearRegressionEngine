#ifndef UTILS_H
#define UTILS_H

#include <vector>

class Utils {

public:

    static double mean(
        const std::vector<double>& data
    );

    static double stddev(
        const std::vector<double>& data
    );

    static void normalizeFeatures(
        std::vector<std::vector<double>>& X,
        std::vector<double>& means,
        std::vector<double>& stds
    );

    static double normalizeValue(
        double value,
        double meanValue,
        double stdValue
    );
};

#endif