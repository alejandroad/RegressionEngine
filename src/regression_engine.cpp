#include "regression_utils.hpp"
#include "regression_engine.hpp"

RegressionEngine::RegressionEngine(std::vector<DataPoint> &datasetReference)
    : dataset(datasetReference),
      mse(0.0f),
      r_squared(0.0f),
      bias_term(0.0f),
      trained(false) 
{
    if (!dataset.empty()) {
        size_t num_features = dataset[0].features.size();
        weights = std::vector<float>(num_features, 0.0f);  
    }
}