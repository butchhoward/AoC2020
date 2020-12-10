#include "day07.h"
#include "day07_lib.h"
#include <iostream>
#include <fstream>

using namespace day07lib;

int day07(const std::string& filename)
{
    std::ifstream datafile(filename);
    if(!datafile)
    {
        std::cout << "Error opening input file" << std::endl;
        return -1;
    }
    std::cout << "Day 07 Part 1 Solution= " << day07lib::part1_solve(datafile) << std::endl;

    std::ifstream datafile2(filename);
    std::cout << "Day 07 Part 2 Solution= " << day07lib::part2_solve(datafile2) << std::endl;

    return -1;
}
