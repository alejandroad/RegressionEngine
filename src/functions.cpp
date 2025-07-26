#include <iostream>
#include "functions.hpp"
#include <vector>

void print_data(std::vector<double>& data) {
    for (double data_point : data) {
        std::cout << "X : " << data_point << "\n" << std::endl;
    }
};
