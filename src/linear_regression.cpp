#include "../include/linear_regression.h"

#include <iostream>

LinearRegression::LinearRegression(
    int numFeatures
) {

    weights.resize(numFeatures, 0.0);

    bias = 0.0;
}

double LinearRegression::predict(
    const std::vector<double>& x
) {

    double result = bias;

    for (int i = 0; i < x.size(); i++) {

        result += weights[i] * x[i];
    }

    return result;
}

double LinearRegression::computeCost(
    const std::vector<std::vector<double>>& X,
    const std::vector<double>& y
) {

    int m = X.size();

    double cost = 0.0;

    for (int i = 0; i < m; i++) {

        double prediction = predict(X[i]);

        double error = prediction - y[i];

        cost += error * error;
    }

    return cost / (2 * m);
}

void LinearRegression::train(
    const std::vector<std::vector<double>>& X,
    const std::vector<double>& y,
    int epochs,
    double learningRate
) {

    int m = X.size();

    int n = weights.size();

    for (int epoch = 0; epoch < epochs; epoch++) {

        std::vector<double> dw(n, 0.0);

        double db = 0.0;

        for (int i = 0; i < m; i++) {

            double prediction = predict(X[i]);

            double error = prediction - y[i];

            for (int j = 0; j < n; j++) {

                dw[j] += error * X[i][j];
            }

            db += error;
        }

        for (int j = 0; j < n; j++) {

            weights[j] -=
                learningRate * dw[j] / m;
        }

        bias -= learningRate * db / m;

        if (epoch % 100 == 0) {

            std::cout
                << "Epoch "
                << epoch
                << " Cost: "
                << computeCost(X, y)
                << std::endl;
        }
    }
}

void LinearRegression::printWeights() {

    std::cout << "Weights:\n";

    for (double w : weights) {

        std::cout << w << " ";
    }

    std::cout
        << "\nBias: "
        << bias
        << std::endl;
}

std::vector<double>
LinearRegression::getWeights() {

    return weights;
}

double LinearRegression::getBias() {

    return bias;
}
void LinearRegression::setWeights(
    const std::vector<double>& newWeights
) {

    weights = newWeights;
}

void LinearRegression::setBias(
    double newBias
) {

    bias = newBias;
}