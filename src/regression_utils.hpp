#ifndef REGRESSION_UTILS_HPP
#define REGRESSION_UTILS_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

struct DataPoint {
    std::vector<double> features;
    double target;
    std::string date;
};

extern std::vector<DataPoint> dataset;

void print_data(const std::vector<DataPoint>& dataset); 
void load_data_points(const std::string& filename);



#endif
