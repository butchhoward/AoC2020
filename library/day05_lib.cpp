#include "day05_lib.h"

#include <string>
#include <sstream>
#include <ranges>
#include <algorithm>
#include <iostream>

using namespace day05lib;


int find_it(int bottom, int top, const std::string& bp, char F)
{
    for ( auto c : bp)
    {
        auto range = (top-bottom+1)/2;

        if (c == F)
        {
            top -= range;
        }
        else 
        {
            bottom += range;
        }
    }
    return bottom;
}

Seats::value_type calculate_id( const std::string& bp)
{
    return find_it(0, 127, bp.substr(0,7), 'F' ) * 8 + find_it(0, 7, bp.substr(7,3), 'L' );
}

Seats parse_data_stream( std::istream& data_stream )
{
    Seats seats;

    std::string bp;
    for (;std::getline(data_stream, bp);)
    {
        seats.push_back(calculate_id(bp));
    }

    return seats;

}
std::size_t day05lib::part1_solve(std::istream& data_stream)
{
    return std::ranges::max(parse_data_stream(data_stream));
}

Seats::value_type day05lib::part2_solve(std::istream& data_stream)
{
    auto seats = parse_data_stream(data_stream);
    for ( auto s : seats)
    {
        if ( std::find(seats.begin(), seats.end(), s+1) == seats.end() 
          && std::find(seats.begin(), seats.end(), s+2) != seats.end() 
        )
        {
            return s+1;
        }
    }

    return 0;
}
