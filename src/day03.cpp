#include "day03.h"
#include "day03_lib.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace day03lib;

int day03(const std::string& filename)
{

    std::ifstream datafile(filename);
    if(!datafile)
    {
        std::cout << "Error opening input file" << std::endl;
        return -1;
    }

    std::cout << "Day 03 Part 1 Solution= " << day03lib::part1_solve(datafile) << std::endl;


    return -1;
}
