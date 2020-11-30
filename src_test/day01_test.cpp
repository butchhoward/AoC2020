#include "day01_test.h"
#include "day01_lib.h"
#include "test_runner.h"

bool day01_test_XXX()
{
    return false;
}

bool day01_test()
{
   test_runner::Tests tests = {
        {"XXX Test", day01_test_XXX}
        //,{"XXX", XXX_test}
    };

    return test_runner::run_tests(tests);
}
