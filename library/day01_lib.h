#ifndef DAY01_LIB_H
#define DAY01_LIB_H

#include <string>
#include <vector>
#include <utility>

int day01_solve( std::vector<int> expenses );

std::vector<int> day01_parse_data(const std::string& filename);

std::pair<int, int> find_pair_sums_to_2020(std::vector<int> expenses);

#endif
