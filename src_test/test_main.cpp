#include "test_runner.h"

#include "day01_test.h"
#include "day02_test.h"
#include "day03_test.h"
//MAKEMODULE INCLUDE MARKER. DO NOT DELETE

int main()
{
    test_runner::Tests tests = {
        {"day01_test", day01_test}
        ,{"day02_test", day02_test}
        ,{"day03_test", day03_test}
        //MAKEMODULE LIST MARKER. DO NOT DELETE
    };

    return test_runner::run_tests(tests) ? 0 : 1;
}
