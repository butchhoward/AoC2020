#ifndef DAY05_LIB_H
#define DAY05_LIB_H

#include <cstddef>
#include <iostream>
#include <vector>

namespace day05lib {


std::size_t part1_solve(std::istream& data_stream);

typedef std::vector<int> Seats;

Seats parse_data_stream( std::istream& tree_stream );

}
#endif
