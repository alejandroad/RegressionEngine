#include "regression_utils.hpp"

std::vector<DataPoint> dataset;

int main () {
    std::string filename = "data/normalized_data.csv";

    load_data_points(filename);

    //print_data(dataset);

    return 0;
}