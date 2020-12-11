#include "day09_test.h"
#include "day09_lib.h"
#include "test_runner.h"

using namespace day09lib;
using namespace day09test;

namespace {

bool test_XXX()
{
    return 0 == lib_function();
}

}

bool day09test::day09_test()
{
   test_runner::Tests tests = {
        {"XXX Test", test_XXX}
        //,{"XXXNextTest", XXX_test}
    };

    return test_runner::run_tests("day09_test", tests);
}
