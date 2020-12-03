#include "test_runner.h"
#include <ctime>
#include <chrono>
using namespace test_runner;

bool test_runner::run_tests( const test_runner::Tests& tests )
{
    return run_tests( "", tests);
}

bool test_runner::run_tests( const std::string& prefix, const test_runner::Tests& tests, OutputStyle output_style)
{
    auto suite_start = std::chrono::steady_clock::now();
    if (output_style != OutputStyle::NONE)
    {
        std::cout << "START: " << prefix << std::endl;
    }

    int failed_tests(0);

    for (auto t : tests)
    {
        auto start = std::chrono::steady_clock::now();
        auto test_result = t.test();
        auto end = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        if (output_style == OutputStyle::ALL)
        {
            if ( test_result )
            {
                std::cout << "\tPASSED: "<< t.description << " ( " << elapsed.count() << " us )" <<  std::endl;
            }
            else 
            {
                ++failed_tests;
                std::cerr << "\tFAILED: "<< t.description << " ( " << elapsed.count() << " us )" << std::endl;
            }
        }
    }

    auto suite_end = std::chrono::steady_clock::now();
    auto suite_elapsed = std::chrono::duration_cast<std::chrono::microseconds>(suite_end - suite_start);

    if (output_style != OutputStyle::NONE)
    {
        std::cout << "FINISHED: " << prefix << " Tests: " << tests.size() << " Failing: " << failed_tests <<  " ( " << suite_elapsed.count() << " us )" << std::endl;
    }

    return failed_tests == 0;
}


