#include "day08.h"
#include "day08_lib.h"
#include <iostream>
#include <fstream>

using namespace day08lib;

int day08(const std::string& filename)
{
    std::ifstream datafile(filename);
    if(!datafile)
    {
        std::cout << "Error opening input file" << std::endl;
        return -1;
    }
    std::cout << "Day 08 Part 1 Solution= " << day08lib::part1_solve(datafile) << std::endl;

    std::ifstream datafile2(filename);
    std::cout << "Day 08 Part 2 Solution= " << day08lib::part2_solve(datafile2) << std::endl;

    return -1;
}
