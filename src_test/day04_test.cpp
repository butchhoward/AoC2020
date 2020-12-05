#include "day04_test.h"
#include "day04_lib.h"
#include "test_runner.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace day04lib;


const std::string sample_data = 
        "ecl:gry pid:860033327 eyr:2020 hcl:#fffffd\n"
        "byr:1937 iyr:2017 cid:147 hgt:183cm\n"
        "\n"
        "iyr:2013 ecl:amb cid:350 eyr:2023 pid:028048884\n"
        "hcl:#cfa07d byr:1929\n"
        "\n"
        "hcl:#ae17e1 iyr:2013\n"
        "eyr:2024\n"
        "ecl:brn pid:760753108 byr:1931\n"
        "hgt:179cm\n"
        "\n"
        "hcl:#cfa07d eyr:2025 pid:166559648\n"
        "iyr:2011 ecl:brn hgt:59in\n"
        "\n"
    ;

bool day04_test_sample_data()
{
    std::istringstream passport_stream(sample_data);
    return 2 == part1_solve(passport_stream);
}

bool day04_test_data()
{
    std::ifstream datafile("./data/day04_data.txt");
    if(!datafile)
    {
        std::cout << "Error opening input file" << std::endl;
        return false;
    }
    auto p1 = part1_solve(datafile);
    std::cout << "Day 4 p1=" << p1 << std::endl;

    return (204 == p1)
           ;
}

bool day04_test()
{
   test_runner::Tests tests = {
        {"day04_test_sample_data", day04_test_sample_data}
        ,{"day04_test_data", day04_test_data}
        //,{"XXXNextTest", XXX_test}
    };

    return test_runner::run_tests("day04_test", tests);
}
