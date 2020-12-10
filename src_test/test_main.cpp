#include "test_runner.h"

#include "day01_test.h"
#include "day02_test.h"
#include "day03_test.h"
#include "day04_test.h"
#include "day05_test.h"
#include "day06_test.h"
#include "day07_test.h"
#include "day08_test.h"
//MAKEMODULE INCLUDE MARKER. DO NOT DELETE

int main()
{
    test_runner::Tests tests = {
        {"day01_test", day01_test}
        ,{"day02_test", day02_test}
        ,{"day03_test", day03_test}
        ,{"day04_test", day04_test}
        ,{"day05_test", day05test::day05_test}
        ,{"day06_test", day06test::day06_test}
        ,{"day07_test", day07test::day07_test}
        ,{"day08_test", day08test::day08_test}
        //MAKEMODULE LIST MARKER. DO NOT DELETE
    };

    return test_runner::run_tests("Test Main", tests, test_runner::OutputStyle::SUMMARY) ? 0 : 1;
}
