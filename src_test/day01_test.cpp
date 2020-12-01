#include "day01_test.h"
#include "day01_lib.h"
#include "test_runner.h"

bool day01_part1_test_sample_data()
{
    std::vector<int> expenses = {
        1721,
        979,
        366,
        299,
        675,
        1456
    };

    int solution = day01_part1_solve( expenses );
    return  514579 == solution;
}

bool day01_part2_test_sample_data()
{
    std::vector<int> expenses = {
        1721,
        979,
        366,
        299,
        675,
        1456
    };

    int solution = day01_part2_solve( expenses );
    return  241861950 == solution;
}

bool day01_test_finds_2020_pair()
{
    std::vector<int> expenses = {
        1721,
        979,
        366,
        299,
        675,
        1456
    };

    auto expense_pair = find_pair_sums_to_2020(expenses);

    return expense_pair.first == 1721 && expense_pair.second == 299;
}

bool day01_test_does_not_find_2020_pair()
{
    std::vector<int> expenses = {
        979,
        366,
        299,
        675,
        1456
    };

    auto expense_pair = find_pair_sums_to_2020(expenses);

    return expense_pair.first == 0 && expense_pair.second == 0;
}

bool day01_test_finds_2020_triplet()
{
    std::vector<int> expenses = {
        1721,
        979,
        366,
        299,
        675,
        1456
    };

    auto expense_found = find_triplet_sums_to_2020(expenses);

    // 979, 366, and 675
    return std::get<0>(expense_found) == 979 && 
           std::get<1>(expense_found) == 366 &&
           std::get<2>(expense_found) == 675
           ;
}

bool day01_test_does_not_find_2020_triplet()
{
    std::vector<int> expenses = {
        1721,
        366,
        299,
        675,
        1456
    };

    auto expense_found = find_triplet_sums_to_2020(expenses);

    return std::get<0>(expense_found) == 0 && 
           std::get<1>(expense_found) == 0 &&
           std::get<2>(expense_found) == 0
           ;
}


bool day01_test()
{
   test_runner::Tests tests = {
        {"Sample data Test Part1", day01_part1_test_sample_data}
        ,{"Sample data Test Part2", day01_part2_test_sample_data}
        ,{"Find 2020 pair", day01_test_finds_2020_pair}
        ,{"Pair not found", day01_test_does_not_find_2020_pair}
        ,{"2020 triplet found", day01_test_finds_2020_triplet}
        ,{"triplet not found", day01_test_does_not_find_2020_triplet}
        //,{"XXX", XXX_test}
    };

    return test_runner::run_tests(tests);
}
