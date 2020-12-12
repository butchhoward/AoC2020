#include "day10_test.h"
#include "day10_lib.h"
#include "test_runner.h"
#include <sstream>
#include <fstream>

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
    std::cout << "sample_data p= " << p << std::endl;
    return 7*5 == p;
}

bool test_other_sample_data()
{
    std::istringstream data_stream(other_sample_data);
    auto p = part1_solve(data_stream);
    std::cout << "othersample_data p= " << p << std::endl;
    return 22*10 == p;
}

}

bool day10test::day10_test()
{
   test_runner::Tests tests = {
        {"test_sample_data", test_sample_data}
        ,{"test_other_sample_data", test_other_sample_data}
    };

    return test_runner::run_tests("day10_test", tests);
}
