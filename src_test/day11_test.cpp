#include "day11_test.h"
#include "day11_lib.h"
#include "test_runner.h"
#include <sstream>
#include <fstream>
#include <string>

using namespace day11lib;
using namespace day11test;

namespace {

std::string sample_data = 
        "L.LL.LL.LL\n"
        "LLLLLLL.LL\n"
        "L.L.L..L..\n"
        "LLLL.LL.LL\n"
        "L.LL.LL.LL\n"
        "L.LLLLL.LL\n"
        "..L.L.....\n"
        "LLLLLLLLLL\n"
        "L.LLLLLL.L\n"
        "L.LLLLL.LL\n"
        ;

bool test_sample_data()
{
    std::istringstream data_stream(sample_data);
    auto p = part1_solve(data_stream);

    return 37 == p;
}


bool test_data()
{
    std::string data_file_name = "./data/day11_data.txt";

    std::ifstream datafile(data_file_name);
    if(!datafile)
    {
        std::cout << "Error opening input file" << std::endl;
        return false;
    }
    auto p1 = part1_solve(datafile);

    std::ifstream datafile2(data_file_name);
    auto p2 = part2_solve(datafile2);

    return     (2424 == p1)
            && (6908379398144 == p2)
           ;
}


}

bool day11test::day11_test()
{
   test_runner::Tests tests = {
        {"test_sample_data", test_sample_data}
        //,{"XXXNextTest", XXX_test}
    };

    return test_runner::run_tests("day11_test", tests);
}
