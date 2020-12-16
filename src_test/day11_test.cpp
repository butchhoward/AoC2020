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

std::string weird_data = 
        "#.LL.LL.L#\n"
        "#LLLLLL.LL\n"
        "L.L.L..L..\n"
        "LLLL.LL.LL\n"
        "L.LL.LL.LL\n"
        "L.LLLLL.LL\n"
        "..L.L.....\n"
        "LLLLLLLLL#\n"
        "#.LLLLLL.L\n"
        "#.LLLLL.L#\n"
        ;

bool test_sample_data()
{
    std::istringstream data_stream(sample_data);
    auto p = part1_solve(data_stream);
    return 37 == p;
}

bool test_sample_data_part2()
{
    std::istringstream data_stream(sample_data);
    auto p = part2_solve(data_stream);
    return 26 == p;
}

bool test_weird_data()
{
    std::istringstream data_stream(weird_data);
    auto p = part2_solve1(data_stream);
    return  55 == p;
}

bool test_each_part2_sample_data_iteration()
{
    std::string iteration0 =
    ".......#.\n"
    "...#.....\n"
    ".#.......\n"
    ".........\n"
    "..#L....#\n"
    "....#....\n"
    ".........\n"
    "#........\n"
    "...#.....\n"
    ;

    std::string iteration1 =
    ".............\n"
    ".............\n"
    ".............\n"
    ".............\n"
    ".L.L.#.#.#.#.\n"
    ".............\n"
    ".............\n"
    ".............\n"
    ".............\n"
    ;

    typedef struct TestData {
        const std::string seatsdata;
        std::size_t r;
        std::size_t f;
        int expected;
    } TestData;

    std::vector<TestData> datas = {
         {iteration0,4,3,8}
        ,{iteration1,4,1,0}
        // ,{iteration2,2}
        // ,{iteration3,3}
        // ,{iteration4,4}
        // ,{iteration5,5}
        // ,{iteration6,6}
    };

    bool success(true);
    for ( auto d : datas )
    {
        std::istringstream data_stream(d.seatsdata);
        auto seats = parse_datastream(data_stream);
        auto p = count_visible(d.r, d.f, seats);
        std::cout << "expected: " << d.expected << " actual:" << p << std::endl;
        if ( success && p != d.expected)
            success = false;
    }

    return  success;
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
        // {"test_sample_data", test_sample_data}
        // ,{"test_sample_data_part2", test_sample_data_part2}
        // ,{"test_weird_data", test_weird_data}
        {"test_each_part2_sample_data_iteration", test_each_part2_sample_data_iteration}
        // ,{"test_data", test_data}
    };

    return test_runner::run_tests("day11_test", tests);
}
