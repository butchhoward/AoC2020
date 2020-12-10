#include "day08_test.h"
#include "day08_lib.h"
#include "test_runner.h"

using namespace day08lib;
using namespace day08test;

namespace {

std::string sample_data = 
    "nop +0\n"
    "acc +1\n"
    "jmp +4\n"
    "acc +3\n"
    "jmp -3\n"
    "acc -99\n"
    "acc +1\n"
    "jmp -4\n"
    "acc +6\n"
    ;

bool test_XXX()
{
    return 0 == lib_function();
}

}

bool day08test::day08_test()
{
   test_runner::Tests tests = {
        {"XXX Test", test_XXX}
        //,{"XXXNextTest", XXX_test}
    };

    return test_runner::run_tests("day08_test", tests);
}
