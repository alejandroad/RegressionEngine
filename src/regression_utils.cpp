#include "regression_utils.hpp"

void print_data(const std::vector<DataPoint>& dataset) {
    for (DataPoint dp : dataset) {
        std::cout << "X : " <<  " Y : " <<  std::endl;
    }
};


void load_data_points(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "[ERROR] Could not open file: " << filename << std::endl;
        return;
    }

    std::string line;
    int line_number = 0;

    while (std::getline(file, line)) {
        line_number++;

        if (line_number == 1 && line.find("date") != std::string::npos) {
            continue;
        }

        std::stringstream ss(line);
        std::string date, max_temp_str, min_temp_str, mean_temp_str, precip_str;

        std::getline(ss, date, ',');
        std::getline(ss, max_temp_str, ',');
        std::getline(ss, min_temp_str, ',');
        std::getline(ss, mean_temp_str, ',');
        std::getline(ss, precip_str);
        precip_str.erase(precip_str.find_last_not_of(" \t\r\n") + 1);

        if (max_temp_str.empty() || min_temp_str.empty()) {
            std::cerr << "[WARN] Skipping line " << line_number << " due to empty temperature values.\n";
            continue;
        }

        try {
            DataPoint dp;
            std::vector<double> features;
            dp.date = strdup(date.c_str()); 
            dp.target = std::stod(max_temp_str);

            features.push_back(std::stod(min_temp_str));
            features.push_back(std::stod(mean_temp_str));
            features.push_back((precip_str == "T" || precip_str.empty()) ? 0.0 : std::stod(precip_str));

            dp.features = features;

            dataset.push_back(dp);
        } catch (const std::invalid_argument& e) {
            std::cerr << "[ERROR] Invalid data at line " << line_number << ": " << line << std::endl;
            continue;
        } catch (const std::out_of_range& e) {
            std::cerr << "[ERROR] Out-of-range value at line " << line_number << ": " << line << std::endl;
            continue;
        }
    }

    std::cout << "[INFO] Loaded " << dataset.size() << " data points from " << filename << std::endl;
    file.close();
}

