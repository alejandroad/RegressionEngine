#ifndef REGRESSION_UTILS_HPP
#define REGRESSION_UTILS_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

struct DataPoint {
    double min_temp_x;
    double max_temp_y;
    std::string date;
    double wind_speed;
};

extern std::vector<DataPoint> dataset;

void print_data(const std::vector<DataPoint>& dataset); 
void load_data_points(const std::string& filename);



#endif
