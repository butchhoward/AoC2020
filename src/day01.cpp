#include "day01.h"
#include "day01_lib.h"
#include <sstream>
#include <iostream>

int day01(const std::string& filename)
{
    auto expenses = day01_parse_data(filename);

    std::cout << "Day 01 Part 1 Solution= " << day01_part1_solve(expenses) << std::endl;
    std::cout << "Day 01 Part 2 Solution= " << day01_part2_solve(expenses) << std::endl;

    return -1;
}
