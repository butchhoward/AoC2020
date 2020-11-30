#include "test_runner.h"

#include "day01_test.h"
//MAKEMODULE INCLUDE MARKER. DO NOT DELETE

int main()
{
    test_runner::Tests tests = {
        {"day01_test", day01_test}
        //MAKEMODULE LIST MARKER. DO NOT DELETE
    };

    return test_runner::run_tests(tests) ? 0 : 1;
}
