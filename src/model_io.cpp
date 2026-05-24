#include "../include/model_io.h"

#include <fstream>

void ModelIO::saveModel(
    const std::string& filename,
    const std::vector<double>& weights,
    double bias,
    double meanValue,
    double stdValue
) {

    std::ofstream file(filename);

    file << weights.size() << std::endl;

    for (double w : weights) {

        file << w << " ";
    }

    file << std::endl;

    file << bias << std::endl;

    file << meanValue << std::endl;

    file << stdValue << std::endl;

    file.close();
}

void ModelIO::loadModel(
    const std::string& filename,
    std::vector<double>& weights,
    double& bias,
    double& meanValue,
    double& stdValue
) {

    std::ifstream file(filename);

    int size;

    file >> size;

    weights.resize(size);

    for (int i = 0; i < size; i++) {

        file >> weights[i];
    }

    file >> bias;

    file >> meanValue;

    file >> stdValue;

    file.close();
}