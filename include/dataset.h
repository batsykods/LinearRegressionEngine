#ifndef DATASET_H
#define DATASET_H

#include <vector>
#include <string>

class Dataset {
public:

    std::vector<std::vector<double>> X;
    std::vector<double> y;

    void loadCSV(const std::string& filename);
};

#endif