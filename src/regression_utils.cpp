#include "regression_utils.hpp"

void print_data(const std::vector<DataPoint>& dataset) {
    for (DataPoint dp : dataset) {
        std::cout << "X : " << dp.min_temp_x << " Y : " << dp.max_temp_y << std::endl;
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
        std::string date, max_temp_str, min_temp_str, skip_col, wind_speed_str;

        std::cout << line << std::endl;

        // std::getline(ss, date, ',');
        // std::getline(ss, max_temp_str, ',');
        // std::getline(ss, min_temp_str, ',');
        // std::getline(ss, skip_col, ',');
        // std::getline(ss, wind_speed_str, ',');

        // if (max_temp_str.empty() || min_temp_str.empty()) {
        //     std::cerr << "[WARN] Skipping line " << line_number << " due to empty temperature values.\n";
        //     continue;
        // }

        // try {
        //     DataPoint dp;
        //     dp.date = strdup(date.c_str()); // Allocate memory for char*
        //     dp.max_temp_y = std::stod(max_temp_str);
        //     dp.min_temp_x = std::stod(min_temp_str);
        //     dp.wind_speed = (wind_speed_str == "T" || wind_speed_str.empty()) ? 0.0 : std::stod(wind_speed_str);

        //     dataset.push_back(dp);
        // } catch (const std::invalid_argument& e) {
        //     std::cerr << "[ERROR] Invalid data at line " << line_number << ": " << line << std::endl;
        //     continue;
        // } catch (const std::out_of_range& e) {
        //     std::cerr << "[ERROR] Out-of-range value at line " << line_number << ": " << line << std::endl;
        //     continue;
        // }
    }

    std::cout << "[INFO] Loaded " << dataset.size() << " data points from " << filename << std::endl;
    file.close();
}

