#ifndef DAY01_LIB_H
#define DAY01_LIB_H

#include <string>
#include <vector>
#include <utility>
#include <tuple>

int day01_part1_solve( std::vector<int> expenses );
int day01_part2_solve( std::vector<int> expenses );

std::vector<int> day01_parse_data(const std::string& filename);

std::vector<int> find_pair_sums_to_2020(std::vector<int> expenses);
std::vector<int> find_triplet_sums_to_2020(std::vector<int> expenses);


#endif
