#include "day09.h"
#include "day09_lib.h"
#include <iostream>
#include <fstream>

using namespace day09lib;

int day09(const std::string& filename)
{
    std::ifstream datafile(filename);
    if(!datafile)
    {
        std::cout << "Error opening input file" << std::endl;
        return -1;
    }
    auto p1 = day09lib::part1_solve(25, datafile);
    std::cout << "Day 09 Part 1 Solution= " << p1 << std::endl;

    std::ifstream datafile2(filename);
    std::cout << "Day 09 Part 2 Solution= " << day09lib::part2_solve(p1, datafile2) << std::endl;

    return -1;
}
