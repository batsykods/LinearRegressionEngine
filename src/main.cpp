#include "../include/dataset.h"
#include "../include/linear_regression.h"
#include "../include/utils.h"
#include "../include/metrics.h"

#include <iostream>
#include <vector>
#include <cstdlib>

int main(int argc, char* argv[]) {

    Dataset dataset;

    dataset.loadCSV(
        "D:/Projects/linear regression engine/data/house_prices.csv"
    );

    if (dataset.X.empty()) {

        std::cout
            << "Dataset failed to load\n";

        return 1;
    }

    std::vector<double> means;
    std::vector<double> stds;

    Utils::normalizeFeatures(
        dataset.X,
        means,
        stds
    );

    int splitIndex =
        dataset.X.size() * 0.8;

    std::vector<std::vector<double>> X_train;
    std::vector<double> y_train;

    std::vector<std::vector<double>> X_test;
    std::vector<double> y_test;

    for (int i = 0; i < dataset.X.size(); i++) {

        if (i < splitIndex) {

            X_train.push_back(
                dataset.X[i]
            );

            y_train.push_back(
                dataset.y[i]
            );
        }
        else {

            X_test.push_back(
                dataset.X[i]
            );

            y_test.push_back(
                dataset.y[i]
            );
        }
    }

    int features =
        X_train[0].size();

    LinearRegression model(features);

    model.train(
        X_train,
        y_train,
        1000,
        0.01
    );

    std::vector<double> predictions;

    for (auto& row : X_test) {

        predictions.push_back(
            model.predict(row)
        );
    }

    std::cout
        << "\nMSE: "
        << Metrics::mse(
            y_test,
            predictions
        );

    std::cout
        << "\nRMSE: "
        << Metrics::rmse(
            y_test,
            predictions
        );

    std::cout
        << "\nMAE: "
        << Metrics::mae(
            y_test,
            predictions
        );

    std::cout
        << "\nR2 Score: "
        << Metrics::r2Score(
            y_test,
            predictions
        );

    if (argc != 4) {

        std::cout
            << "\nUsage:\n"
            << "LinearRegressionEngine.exe "
            << "<size> <bedrooms> <bathrooms>\n";

        return 0;
    }

    double size =
        atof(argv[1]);

    double bedrooms =
        atof(argv[2]);

    double bathrooms =
        atof(argv[3]);

    std::vector<double> testInput =
    {
        Utils::normalizeValue(
            size,
            means[0],
            stds[0]
        ),

        Utils::normalizeValue(
            bedrooms,
            means[1],
            stds[1]
        ),

        Utils::normalizeValue(
            bathrooms,
            means[2],
            stds[2]
        )
    };

    double prediction =
        model.predict(testInput);

    std::cout
        << "\nPredicted Price: "
        << prediction
        << "\n";

    return 0;
}