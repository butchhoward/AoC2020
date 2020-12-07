#include "day01.h"
#include "day02.h"
#include "day03.h"
#include "day04.h"
#include "day05.h"
#include "day06.h"
#include "day07.h"
//MAKEMODULE INCLUDE MARKER. DO NOT DELETE


#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <ctime>
#include <chrono>

#define MAX_DAYS 7

void solve_a_day(int day, std::string datafile)
{

    auto start = std::chrono::steady_clock::now();

    switch (day) {
    case 1: day01(datafile); break;
    case 2: day02(datafile); break;
    case 3: day03(datafile); break;
    case 4: day04(datafile); break;
    case 5: day05(datafile); break;
    case 6: day06(datafile); break;
    case 999: day07(datafile); break;
    //MAKEMODULE LIST MARKER. DO NOT DELETE
    default:
        std::cerr << "unknown day. did you forget to create the data file '" << datafile << "'?" << std::endl;
    }

    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "\tTime: " << elapsed.count() << " microseconds" <<  std::endl;

}

int main(int argc, char *argv[])
{
    int min_day(1);
    int max_day(MAX_DAYS);

    if (argc == 2)
    {
        std::istringstream stream(argv[1]);
        stream >> max_day;
        min_day = max_day;

        if (max_day < 1 || max_day > MAX_DAYS)
        {
            std::cout << "Use a day between 1 and " << MAX_DAYS << std::endl;
            return 1;
        }
    }
  
    auto start = std::chrono::steady_clock::now();

    for (auto day = min_day; day <= max_day; ++day)
    {
        //dayNN_data.txt
        std::stringstream datafile;
        datafile << "./data/day" << std::setfill('0') << std::setw(2) << day << "_data.txt";

        solve_a_day(day, datafile.str());
    }

    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Total Time: " << elapsed.count() << " microseconds" <<  std::endl;


    return 0;
}
