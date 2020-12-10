#include "day07_test.h"
#include "day07_lib.h"
#include "test_runner.h"
#include <string>
#include <sstream>

using namespace day07lib;
using namespace day07test;


namespace {


std::string sample_data =
    "light red bags contain 1 bright white bag, 2 muted yellow bags.\n"
    "dark orange bags contain 3 bright white bags, 4 muted yellow bags.\n"
    "bright white bags contain 1 shiny gold bag.\n"
    "muted yellow bags contain 2 shiny gold bags, 9 faded blue bags.\n"
    "shiny gold bags contain 1 dark olive bag, 2 vibrant plum bags.\n"
    "dark olive bags contain 3 faded blue bags, 4 dotted black bags.\n"
    "vibrant plum bags contain 5 faded blue bags, 6 dotted black bags.\n"
    "faded blue bags contain no other bags.\n"
    "dotted black bags contain no other bags.\n"
    ;



bool test_sample_data()
{
    std::istringstream data_stream(sample_data);
    auto p1 = part1_solve(data_stream);
    std::cout << "Part1=" << p1 << std::endl;
    return 4 == p1;
}

}

bool day07test::day07_test()
{
   test_runner::Tests tests = {
        {"test_sample_data", test_sample_data}
        //,{"XXXNextTest", XXX_test}
    };

    return test_runner::run_tests("day07_test", tests);
}
