#ifndef DAY11_LIB_H
#define DAY11_LIB_H

#include <iostream>
#include <cstddef>
#include <vector>

namespace day11lib {

std::size_t part1_solve(std::istream& data_stream);
std::size_t part2_solve(std::istream& data_stream);
std::size_t part2_solve1(std::istream& data_stream);

typedef enum {
    FLOOR,
    OCCUPIED,
    EMPTY
} SeatState;

typedef std::vector<SeatState> SeatRow;
typedef std::vector<SeatRow> Seats;
int count_visible(std::size_t r, std::size_t f, const Seats& original_seats);
Seats parse_datastream(std::istream& data_stream);

}
#endif
