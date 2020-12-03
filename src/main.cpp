#include "day01.h"
#include "day02.h"
#include "day03.h"
//MAKEMODULE INCLUDE MARKER. DO NOT DELETE


#include <iostream>
#include <string>
#include <sstream>

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

    switch (day) {
    case 1: day01(datafile); break;
    case 2: day02(datafile); break;
    case 999: day03(datafile); break;
    //MAKEMODULE LIST MARKER. DO NOT DELETE
    default:
        std::cerr << "unknown day. did you forget to update the switch in main.cpp?" << std::endl;
    }

    return 0;
}
