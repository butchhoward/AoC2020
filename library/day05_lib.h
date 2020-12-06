#ifndef DAY05_LIB_H
#define DAY05_LIB_H

#include <cstddef>
#include <iostream>
#include <vector>

namespace day05lib {

typedef std::vector<int> Seats;

std::size_t part1_solve(std::istream& data_stream);
Seats::value_type part2_solve(std::istream& data_stream);


}
#endif
