#include "regression_utils.hpp"

std::vector<DataPoint> dataset;

int main () {
    std::string filename = "data/normalized_data.csv";

    load_data_points(filename);

    return 0;
}