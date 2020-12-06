#include "day05_test.h"
#include "day05_lib.h"
#include "test_runner.h"
#include <sstream>
#include <fstream>
#include <iostream>


using namespace day05lib;
using namespace day05test;

// FBFBBFFRLR: row 44, column 5, seat ID 357,
// BFFFBBFRRR: row 70, column 7, seat ID 567.
// FFFBBBFRRR: row 14, column 7, seat ID 119.
// BBFFBBFRLL: row 102, column 4, seat ID 820.
std::string sample_data = 
    "FBFBBFFRLR\n"
    "BFFFBBFRRR\n"
    "FFFBBBFRRR\n"
    "BBFFBBFRLL\n"
;


bool day05_test_sample_data()
{
    std::istringstream data_stream(sample_data);
    return 820 == part1_solve(data_stream);
}


bool day05_test_data()
{
    std::ifstream datafile("./data/day05_data.txt");
    if(!datafile)
    {
        std::cout << "Error opening input file" << std::endl;
        return false;
    }
    auto p1 = part1_solve(datafile);

    std::ifstream datafile2("./data/day05_data.txt");
    auto p2 = part2_solve(datafile2);

    return     (864 == p1)
            && (739 == p2)
           ;
}

bool day05test::day05_test()
{
   test_runner::Tests tests = {
        {"test_sample_data", day05_test_sample_data}
        ,{"day05_test_data", day05_test_data}
        //,{"XXXNextTest", XXX_test}
    };

    return test_runner::run_tests("day05_test", tests);
}
