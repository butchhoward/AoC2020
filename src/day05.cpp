#include "day05.h"
#include "day05_lib.h"
#include <iostream>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace day05lib;

int day05(const std::string& filename)
{
    std::ifstream datafile(filename);
    if(!datafile)
    {
        std::cout << "Error opening input file" << std::endl;
        return -1;
    }

    std::cout << "Day 05 Part 1 Solution= " << day05lib::part1_solve(datafile) << std::endl;

    // std::ifstream datafile2(filename);
    // std::cout << "Day 05 Part 2 Solution= " << day05lib::part2_solve(datafile2) << std::endl;

    return -1;
}
