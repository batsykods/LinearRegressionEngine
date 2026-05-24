#ifndef MODEL_IO_H
#define MODEL_IO_H

#include <vector>
#include <string>

class ModelIO {

public:

    static void saveModel(
        const std::string& filename,
        const std::vector<double>& weights,
        double bias,
        double meanValue,
        double stdValue
    );

    static void loadModel(
        const std::string& filename,
        std::vector<double>& weights,
        double& bias,
        double& meanValue,
        double& stdValue
    );
};

#endif