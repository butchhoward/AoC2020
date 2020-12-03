#include "day02_test.h"
#include "day02_lib.h"
#include "test_runner.h"

using namespace day02lib;

bool day02_test_sample_data()
{

    /*

    1-3 a: abcde
    1-3 b: cdefg
    2-9 c: ccccccccc

    Line 2 is an invalid password
    */

   day02lib::PasswordData password_data = { 
       PasswordItem(1,2,'a', "abcde"),
       PasswordItem(1,3,'b', "cdefg"),
       PasswordItem(2,9,'c', "ccccccccc")
   };

    return 2 == part1_solve( password_data );
}


bool day02_test_sample_data_part2()
{
   day02lib::PasswordData password_data = { 
       PasswordItem(1,2,'a', "abcde"),
       PasswordItem(1,3,'b', "cdefg"),
       PasswordItem(2,9,'c', "ccccccccc")
   };

    return 1 == part2_solve( password_data );
}

bool day02_test_other_data_part2()
{
   day02lib::PasswordData password_data = { 
       PasswordItem(1,2,'a', "abcde"),      //valid
       PasswordItem(1,3,'b', "cdefg"),      //invalid
       PasswordItem(2,9,'c', "ccccccccc"),   //invalid
       PasswordItem(2,9,'c', "ababababa"),   //invalid
       PasswordItem(8,9,'b', "ababababa")   //valid
   };

    return 2 == part2_solve( password_data );
}


bool day02_test_data()
{
    auto password_data = parse_data("./data/day02_data.txt");
    return 582 == part1_solve( password_data ) && 
           729 == part2_solve( password_data );
}

bool day02_test()
{
   test_runner::Tests tests = {
        {"day02_test_sample_data", day02_test_sample_data}
        ,{"day02_test_other_data_part2", day02_test_other_data_part2}
        ,{"day02_test_data", day02_test_data}
        ,{"day02_test_sample_data_part2", day02_test_sample_data_part2}
        //,{"XXX", XXX_test}
    };

    return test_runner::run_tests("day02_test", tests);
}
