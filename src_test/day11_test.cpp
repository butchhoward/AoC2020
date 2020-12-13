#include "day11_test.h"
#include "day11_lib.h"
#include "test_runner.h"

using namespace day11lib;
using namespace day11test;

namespace {

bool test_XXX()
{
    return 0 == lib_function();
}

}

bool day11test::day11_test()
{
   test_runner::Tests tests = {
        {"XXX Test", test_XXX}
        //,{"XXXNextTest", XXX_test}
    };

    return test_runner::run_tests("day11_test", tests);
}
