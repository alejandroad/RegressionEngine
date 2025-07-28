#ifndef REGRESSION_ENGINE_HPP
#define REGRESSION_ENGINE_HPP

#include "regression_utils.hpp"

class RegressionEngine {

    std::vector<DataPoint>& dataset;

    float mse;
    float slope;
    float intercept;
    bool trained;

    public:
        RegressionEngine(std::vector<DataPoint>& dataset);
        void train();
        float predict(float x) const;
        void compute_mse() const;
        float compute_r_squared() const;
        void change_dataset(const std::vector<DataPoint>& dataset);
        void print_model();
        void save_model(const std::string& path);
        void load_model(...);
};

#endif