#include "day06_test.h"
#include "day06_lib.h"
#include "test_runner.h"
#include <sstream>
#include <fstream>
#include <iostream>

using namespace day06lib;
using namespace day06test;

namespace {


std::string sample_data = 
    "abc\n"
    "\n"
    "a\n"
    "b\n"
    "c\n"
    "\n"
    "ab\n"
    "ac\n"
    "\n"
    "a\n"
    "a\n"
    "a\n"
    "a\n"
    "\n"
    "b\n"
    ;

bool test_sample_data()
{
    std::istringstream data_stream(sample_data);
    return 11 == part1_solve(data_stream);
}

}

bool day06test::day06_test()
{
   test_runner::Tests tests = {
        {"test_sample_data", test_sample_data}
        //,{"XXXNextTest", XXX_test}
    };

    return test_runner::run_tests("day06_test", tests);
}
