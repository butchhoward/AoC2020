#include "day07_test.h"
#include "day07_lib.h"
#include "test_runner.h"

using namespace day07lib;
using namespace day07test;

namespace {

bool test_XXX()
{
    return 0 == lib_function();
}

}

bool day07test::day07_test()
{
   test_runner::Tests tests = {
        {"XXX Test", test_XXX}
        //,{"XXXNextTest", XXX_test}
    };

    return test_runner::run_tests("day07_test", tests);
}

