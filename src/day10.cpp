#include "day10.h"
#include "day10_lib.h"
#include <iostream>
#include <fstream>

using namespace day10lib;

int day10(const std::string& filename)
{
    std::ifstream datafile(filename);
    if(!datafile)
    {
        std::cout << "Error opening input file" << std::endl;
        return -1;
    }
    std::cout << "Day 10 Part 1 Solution= " << day10lib::part1_solve(datafile) << std::endl;

    std::ifstream datafile2(filename);
    std::cout << "Day 10 Part 2 Solution= " << day10lib::part2_solve(datafile2) << std::endl;

    return -1;
}
