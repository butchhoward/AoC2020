#include "day10_test.h"
#include "day10_lib.h"
#include "test_runner.h"
#include <sstream>
#include <fstream>
#include <string>

using namespace day10lib;
using namespace day10test;

namespace {

std::string sample_data =
    "16\n"
    "10\n"
    "15\n"
    "5\n"
    "1\n"
    "11\n"
    "7\n"
    "19\n"
    "6\n"
    "12\n"
    "4\n"
    ;

std::string other_sample_data =
    "28\n"
    "33\n"
    "18\n"
    "42\n"
    "31\n"
    "14\n"
    "46\n"
    "20\n"
    "48\n"
    "47\n"
    "24\n"
    "23\n"
    "49\n"
    "45\n"
    "19\n"
    "38\n"
    "39\n"
    "11\n"
    "1\n"
    "32\n"
    "25\n"
    "35\n"
    "8\n"
    "17\n"
    "7\n"
    "9\n"
    "4\n"
    "2\n"
    "34\n"
    "10\n"
    "3\n"
    ;


bool test_sample_data()
{
    std::istringstream data_stream(sample_data);
    auto p = part1_solve(data_stream);
    return 7*5 == p;
}

bool test_other_sample_data()
{
    std::istringstream data_stream(other_sample_data);
    auto p = part1_solve(data_stream);
    return 22*10 == p;
}

bool test_sample_data_part2()
{
    std::istringstream data_stream(sample_data);
    auto p = part2_solve(data_stream);
    return 8 == p;
}

bool test_other_sample_data_part2()
{
    std::istringstream data_stream(other_sample_data);
    auto p = part2_solve(data_stream);
    return 19208 == p;
}


bool test_data()
{
    std::string data_file_name = "./data/day10_data.txt";

    std::ifstream datafile(data_file_name);
    if(!datafile)
    {
        std::cout << "Error opening input file" << std::endl;
        return false;
    }
    auto p1 = part1_solve(datafile);

    std::ifstream datafile2(data_file_name);
    auto p2 = part2_solve(datafile2);

    return     (65*32 == p1)
            && (6908379398144 == p2)
           ;
}



}

bool day10test::day10_test()
{
   test_runner::Tests tests = {
        {"test_sample_data", test_sample_data}
        ,{"test_other_sample_data", test_other_sample_data}
        ,{"test_sample_data_part2", test_sample_data_part2}
        ,{"test_other_sample_data_part2", test_other_sample_data_part2}
        ,{"test_data", test_data}
    };

    return test_runner::run_tests("day10_test", tests);
}
