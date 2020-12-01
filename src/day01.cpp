#include "day01.h"
#include "day01_lib.h"
#include <sstream>
#include <iostream>

int day01(const std::string& filename)
{
    auto expenses = day01_parse_data(filename);
    auto solution = day01_solve(expenses);

    std::cout << "Day 01 Part 1 Solution= " << solution << std::endl;

    return -1;
}
