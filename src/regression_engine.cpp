#include "regression_utils.hpp"
#include "regression_engine.hpp"

RegressionEngine::RegressionEngine(std::vector<DataPoint> &datasetReference) 
    :   dataset(datasetReference),
        mse(0), 
        slope(0), 
        intercept(0), 
        trained(false) {}