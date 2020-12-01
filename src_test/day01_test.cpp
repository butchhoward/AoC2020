#include "day01_test.h"
#include "day01_lib.h"
#include "test_runner.h"

bool day01_test_sample_data()
{
    std::vector<int> expenses = {
        1721,
        979,
        366,
        299,
        675,
        1456
    };

    int solution = day01_solve( expenses );
    return  514579 == solution;
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


bool day01_test()
{
   test_runner::Tests tests = {
        {"Sample data Test", day01_test_sample_data}
        ,{"Find 2020 pair", day01_test_finds_2020_pair}
        ,{"Pair not found", day01_test_does_not_find_2020_pair}
        //,{"XXX", XXX_test}
    };

    return test_runner::run_tests(tests);
}
