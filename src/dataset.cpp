#include "../include/dataset.h"

#include <fstream>
#include <sstream>

void Dataset::loadCSV(const std::string& filename) {

    std::ifstream file(filename);

    std::string line;

    while (getline(file, line)) {

        std::stringstream ss(line);

        std::string value;

        std::vector<double> row;

        while (getline(ss, value, ',')) {

            row.push_back(std::stod(value));
        }

        y.push_back(row.back());

        row.pop_back();

        X.push_back(row);
    }
}