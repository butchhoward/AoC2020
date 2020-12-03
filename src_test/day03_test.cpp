#include "day03_test.h"
#include "day03_lib.h"
#include "test_runner.h"

using namespace day03lib;

bool day03_test_XXX()
{
    return 0 == lib_function();
}

bool day03_test()
{
   test_runner::Tests tests = {
        {"XXX Test", day03_test_XXX}
        //,{"XXXNextTest", XXX_test}
    };

    return test_runner::run_tests(tests);
}
