#include "day02_test.h"
#include "day02_lib.h"
#include "test_runner.h"

bool day02_test_sample_data()
{

    /*

    1-3 a: abcde
    1-3 b: cdefg
    2-9 c: ccccccccc

    Line 2 is an invalid password
    */

   PasswordData password_data = { 
       PasswordItem(1,2,'a', "abcde"),
       PasswordItem(1,3,'b', "cdefg"),
       PasswordItem(2,9,'c', "ccccccccc")
   };

    return 2 == day02_part1_solve( password_data );
}

bool day02_test()
{
   test_runner::Tests tests = {
        {"day02_test_sample_data", day02_test_sample_data}
        //,{"XXX", XXX_test}
    };

    return test_runner::run_tests(tests);
}
