#include "day04.h"
#include "day04_lib.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace day04lib;

int day04(const std::string& filename)
{
    std::ifstream datafile(filename);
    if(!datafile)
    {
        std::cout << "Error opening input file" << std::endl;
        return -1;
    }

    std::cout << "Day 04 Part 1 Solution= " << day04lib::part1_solve(datafile) << std::endl;

    std::ifstream datafile2(filename);
    std::cout << "Day 04 Part 2 Solution= " << day04lib::part2_solve(datafile2) << std::endl;

    return -1;
}
