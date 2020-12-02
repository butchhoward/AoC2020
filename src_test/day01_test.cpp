#include "day01_test.h"
#include "day01_lib.h"
#include "test_runner.h"
#include <algorithm>


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

    return std::find(expense_pair.begin(), expense_pair.end(), 1721) != expense_pair.end() && 
           std::find(expense_pair.begin(), expense_pair.end(), 299) != expense_pair.end();
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

    return expense_pair.size() == 0;
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
    return std::find(expense_found.begin(), expense_found.end(), 979) != expense_found.end() && 
           std::find(expense_found.begin(), expense_found.end(), 366) != expense_found.end()  &&
           std::find(expense_found.begin(), expense_found.end(), 675) != expense_found.end() 
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

    return expense_found.size() == 0;
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
