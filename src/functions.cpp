#include <iostream>
#include "functions.hpp"

template<typename T>

void print_data(std::vector<T>& data) {
    for (T data_point : data) {
        std::cout << "X : " << data_point << "\n" << std::endl;
    }
};
