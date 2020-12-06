#include "day06.h"
#include "day06_lib.h"
#include <iostream>
#include <fstream>

using namespace day06lib;

int day06(const std::string& filename)
{
    std::ifstream datafile(filename);
    if(!datafile)
    {
        std::cout << "Error opening input file" << std::endl;
        return -1;
    }
    std::cout << "Day 06 Part 1 Solution= " << day06lib::part1_solve(datafile) << std::endl;

    std::ifstream datafile2(filename);
    std::cout << "Day 06 Part 2 Solution= " << day06lib::part2_solve(datafile2) << std::endl;

    return -1;
}
