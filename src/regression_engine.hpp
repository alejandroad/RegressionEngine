#ifndef REGRESSION_ENGINE_HPP
#define REGRESSION_ENGINE_HPP

#include "regression_utils.hpp"

class RegressionEngine {

    std::vector<DataPoint>& dataset;
    std::vector<float> weights;
    float bias_term;
    
    float mse;
    float r_squared;
    bool trained;

    public:
        RegressionEngine(std::vector<DataPoint>& dataset);
        void train();
        float predict(const std::vector<float>& features) const;
        std::vector<float> batch_predict() const;
        void compute_mse();
        float compute_r_squared() const;
        void change_dataset(const std::vector<DataPoint>& dataset);
        void print_model() const;
        void normalize_features();
        void denormalize_features();
        void save_model(const std::string& path);
        void load_model(...);
};

#endif