#include "test_runner.h"
#include <ctime>
#include <chrono>
#include <sstream>
#include <iomanip>


using namespace test_runner;

namespace {

std::string format_duration(std::chrono::microseconds timeInMicroSec)
{
    auto c(timeInMicroSec.count());
    std::ostringstream oss;
    oss << std::setfill('0') 
        << (c % 1000000000) / 1000000
        << "."
        << std::setw(3)
        << (c % 1000000) / 1000
        << ","
        << std::setw(3)
        << c % 1000;
    return oss.str();
}

}

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

        if (! test_result )
        {
            ++failed_tests;
        }

        if (output_style == OutputStyle::ALL)
        {
            if ( test_result )
            {
                std::cout << "\tPASSED: "<< t.description << " ( " << format_duration(elapsed) << " )" <<  std::endl;
            }
            else 
            {
                std::cerr << "\tFAILED: "<< t.description << " ( " << format_duration(elapsed) << " )" << std::endl;
            }
        }
    }

    auto suite_end = std::chrono::steady_clock::now();
    auto suite_elapsed = std::chrono::duration_cast<std::chrono::microseconds>(suite_end - suite_start);

    if (output_style != OutputStyle::NONE)
    {
        std::cout << "FINISHED: " << prefix << " Tests: " << tests.size() << " Failing: " << failed_tests <<  " ( " << format_duration(suite_elapsed) << " )" << std::endl;
    }

    return failed_tests == 0;
}


