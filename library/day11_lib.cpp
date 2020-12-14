#include "day11_lib.h"

#include <iostream>
#include <sstream>
#include <cstddef>
#include <vector>
#include <ranges>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace day11lib;

namespace {

typedef enum {
    FLOOR,
    OCCUPIED,
    EMPTY
} SeatState;

typedef std::vector<SeatState> SeatRow;
typedef std::vector<SeatRow> Seats;

std::ostream& operator<<(std::ostream &os, const SeatState& cs)
{
    char c('?');
    switch (cs)
    { 
        case SeatState::FLOOR: c = '.'; break;
        case SeatState::OCCUPIED: c = '#'; break;
        case SeatState::EMPTY: c = 'L'; break;
        default: break;
    }
    os << c;
    return os;
}

std::ostream& operator<<(std::ostream &os, const SeatRow& cs)
{
    for ( auto j : cs)
    {
        os << j;
    }
    return os;
}
std::ostream& operator<<(std::ostream &os, const Seats& cs)
{
    for ( auto j : cs)
    {
        os << j << std::endl;
    }
    return os;
}

SeatRow parse_datarow(const std::string& datarow)
{
    SeatRow row;

    for (auto c : datarow)
    {
        SeatState s(SeatState::FLOOR);
        switch (c)
        {
            case 'L': s = SeatState::EMPTY; break;
            case '#': s = SeatState::OCCUPIED; break;
            default: break;
        }
        row.push_back(s);
    }
    return row;
}

std::pair<Seats,bool> choose_seats( const Seats& original_seats)
{

    auto count_adjacent = [original_seats](std::size_t r, std::size_t f)
    {
        int count(0);

        int rb = r - 1;
        if (rb < 0)
            rb = 0;
        int re = r + 2;
        if (re > int(original_seats.size()))
            re = original_seats.size();

        int fb = f - 1;
        if (fb < 0)
            fb = 0;
        int fe = f + 2;
        if (fe > int(original_seats[0].size()))
            fe = original_seats[0].size();

        for (int ri = rb; ri < re; ++ri)
        {
            for (int fi = fb; fi < fe; ++fi)
            {
                if ( ri == int(r) && fi == int(f))
                    continue;

                if ( original_seats[ri][fi] == SeatState::OCCUPIED)
                {
                    ++count;
                }
            }
        }

        return count;
    };

    auto update = [](SeatState s, int adj)
    {
        if ( s == SeatState::EMPTY && adj == 0)
        {
            return SeatState::OCCUPIED;
        }
        else if ( s == SeatState::OCCUPIED && adj >= 4)
        {
            return SeatState::EMPTY;
        }
        return s;
    };


    Seats new_seats;
    bool changed(false);
    
    for (std::size_t r = 0; r < original_seats.size(); ++r)
    {
        SeatRow new_row;
        for (std::size_t f = 0; f < original_seats[0].size(); ++f)
        {
            auto a = count_adjacent(r,f);
            auto n = update(original_seats[r][f], a);

            changed |= (n != original_seats[r][f]);

            new_row.push_back(n);
        }
        new_seats.push_back(new_row);
    }

    return {new_seats, changed};
}


Seats parse_datastream(std::istream& data_stream)
{
    Seats data;

    std::string line;
    for (;std::getline(data_stream, line);)
    {   
        data.push_back( parse_datarow(line));
    }
    
    return data;
}

}

std::size_t day11lib::part1_solve(std::istream& data_stream)
{
    auto seats = parse_datastream(data_stream);

    int count(0);
    for(;;)
    {
        auto sp = choose_seats(seats); 

        if (sp.second == true)
        {   
            ++count;
            seats = sp.first;
        }
        else
        {
            break;
        }
    }
    std::size_t seated(0);
    for ( auto r : seats )
        seated += std::count( r.begin(), r.end(), SeatState::OCCUPIED);

    return seated;
}

std::size_t day11lib::part2_solve(std::istream& data_stream)
{
    auto things = parse_datastream(data_stream);
    return 0;
}
