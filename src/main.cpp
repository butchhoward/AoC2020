#include "day01.h"
#include "day02.h"
#include "day03.h"
#include "day04.h"
#include "day05.h"
//MAKEMODULE INCLUDE MARKER. DO NOT DELETE


#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <chrono>


int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cout << "Need a day and a file name" << std::endl;
        std::exit(1);
    }

    int day(0);
    std::istringstream stream(argv[1]);
    stream >> day;
    std::string datafile(argv[2]);

    auto start = std::chrono::steady_clock::now();

    switch (day) {
    case 1: day01(datafile); break;
    case 2: day02(datafile); break;
    case 3: day03(datafile); break;
    case 4: day04(datafile); break;
    case 5: day05(datafile); break;
    //MAKEMODULE LIST MARKER. DO NOT DELETE
    default:
        std::cerr << "unknown day. did you forget to update the switch in main.cpp?" << std::endl;
    }

    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "\tTime: " << elapsed.count() << " microseconds" <<  std::endl;

    return 0;
}
