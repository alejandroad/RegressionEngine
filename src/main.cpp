#include <iostream>
#include <vector>
#include "functions.hpp"

int main () {

    std::vector<int> ints = {1, 2, 3, 4};

    std::vector<double> doubles(ints.begin(), ints.end());

    print_data(doubles);

    return 0;
}