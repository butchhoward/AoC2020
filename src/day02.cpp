#include "day02.h"
#include "day02_lib.h"
#include <sstream>
#include <iostream>

int day02(const std::string& filename)
{

    day02lib::PasswordData password_data = day02lib::parse_data(filename);

    std::cout << "Day 02 Part 1 Solution= " << day02lib::part1_solve(password_data) << std::endl;
    std::cout << "Day 02 Part 2 Solution= " << day02lib::part2_solve(password_data) << std::endl;

    return -1;
}
