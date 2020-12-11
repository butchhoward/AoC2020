#include "day08_test.h"
#include "day08_lib.h"
#include "test_runner.h"

#include <string>
#include <sstream>
#include <fstream>

using namespace day08lib;
using namespace day08test;

namespace {

std::string sample_data = 
    "nop +0\n"  //0     0                   
    "acc +1\n"  //1     1           7       
    "jmp +4\n"  //2     2                   
    "acc +3\n"  //3             5
    "jmp -3\n"  //4             6
    "acc -99\n" //5         
    "acc +1\n"  //6         3               
    "jmp -4\n"  //7         4   
    "acc +6\n"  //8
    ;

bool test_sample_data_part1()
{
    std::istringstream data_stream(sample_data);
    auto p1 = part1_solve(data_stream);
    return 5 == p1;
}

bool test_sample_data_part2()
{
    std::istringstream data_stream(sample_data);
    auto p2 = part2_solve(data_stream);
    return 8 == p2;
}


bool test_data()
{
    std::ifstream datafile("./data/day08_data.txt");
    if(!datafile)
    {
        std::cout << "Error opening input file" << std::endl;
        return false;
    }
    auto p1 = part1_solve(datafile);

    std::ifstream datafile2("./data/day08_data.txt");
    auto p2 = part2_solve(datafile2);

    return     (1832 == p1)
            && (662 == p2)
           ;
}

}

bool day08test::day08_test()
{
   test_runner::Tests tests = {
        {"test_sample_data_part1", test_sample_data_part1}
        ,{"test_sample_data_part2", test_sample_data_part2}
        ,{"test_data", test_data}
        //,{"XXXNextTest", XXX_test}
    };

    return test_runner::run_tests("day08_test", tests);
}
