#include "day09_test.h"
#include "day09_lib.h"
#include "test_runner.h"
#include <sstream>
#include <fstream>

using namespace day09lib;
using namespace day09test;

namespace {


std::string sample_data =
        "35\n"
        "20\n"
        "15\n"
        "25\n"
        "47\n"
        "40\n"
        "62\n"
        "55\n"
        "65\n"
        "95\n"
        "102\n"
        "117\n"
        "150\n"
        "182\n"
        "127\n"
        "219\n"
        "299\n"
        "277\n"
        "309\n"
        "576\n"
    ;

bool test_1_25_part1()
{
    std::stringstream data_stream;
    for ( auto i = 1; i<=25;++i)
    {
        data_stream << i << "\n";
    }
    data_stream << 30 << "\n";
    data_stream << 100 << "\n";

    auto p1 = part1_solve(25, data_stream);
    return 100 == p1;
}

bool test_sample_data_part1()
{
    std::istringstream data_stream(sample_data);
    auto p1 = part1_solve(5, data_stream);
    return 127 == p1;
}


bool test_data()
{
    std::ifstream datafile("./data/day09_data.txt");
    if(!datafile)
    {
        std::cout << "Error opening input file" << std::endl;
        return false;
    }
    auto p1 = part1_solve(25, datafile);

    // std::ifstream datafile2("./data/day08_data.txt");
    // auto p2 = part2_solve(datafile2);

    return     (15690279 == p1)
            // && (662 == p2)
           ;
}


}

bool day09test::day09_test()
{
   test_runner::Tests tests = {
        {"test_1_25_part1", test_1_25_part1}
        ,{"test_sample_data_part1", test_sample_data_part1}
        ,{"test_data", test_data}
    };

    return test_runner::run_tests("day09_test", tests);
}
