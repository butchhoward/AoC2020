#include "day04_test.h"
#include "day04_lib.h"
#include "test_runner.h"

using namespace day04lib;

bool day04_test_XXX()
{
    return 0 == lib_function();
}

bool day04_test()
{
   test_runner::Tests tests = {
        {"XXX Test", day04_test_XXX}
        //,{"XXXNextTest", XXX_test}
    };

    return test_runner::run_tests("day04_test", tests);
}
