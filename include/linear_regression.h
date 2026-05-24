#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H

#include <vector>

class LinearRegression {

private:

    std::vector<double> weights;
    double bias;

public:

        void setWeights(
        const std::vector<double>& newWeights
    );

    void setBias(double newBias);

    std::vector<double> getWeights();
    double getBias();

    LinearRegression(int numFeatures);

    double predict(
        const std::vector<double>& x
    );

    void train(
        const std::vector<std::vector<double>>& X,
        const std::vector<double>& y,
        int epochs,
        double learningRate
    );

    double computeCost(
        const std::vector<std::vector<double>>& X,
        const std::vector<double>& y
    );

    void printWeights();
};

#endif