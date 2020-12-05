#include "day05_test.h"
#include "day05_lib.h"
#include "test_runner.h"

using namespace day05lib;

bool day05_test_XXX()
{
    return 0 == lib_function();
}

bool day05_test()
{
   test_runner::Tests tests = {
        {"XXX Test", day05_test_XXX}
        //,{"XXXNextTest", XXX_test}
    };

    return test_runner::run_tests("day05_test", tests);
}
