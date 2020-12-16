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

typedef std::pair<Seats,bool> SeatChooserResult;
typedef std::function<int (std::size_t, std::size_t, const Seats&)> SeatNearbyCounter;
typedef std::function<SeatState (SeatState, int)> SeatStateUpdater;


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

}

int day11lib::count_visible(std::size_t r, std::size_t f, const Seats& original_seats)
{
    int count(0);

    auto compass_count = [original_seats](int r, int f, int rd, int fd, int re, int fe)
    {
        int count(0);

        for (;;)
        {
            r = r + rd;
            if (r < 0 || r >= int(original_seats.size()))
                break;

            f = f + fd;
            if (f < 0 || f >= int(original_seats[0].size()))
                break;

            if (original_seats[r][f] != SeatState::FLOOR)
            {
                if ( original_seats[r][f] == SeatState::OCCUPIED)
                {
                    ++count;
                }
                break;
            }
        }

        return count;
    };

    const int re(original_seats.size());

    const int fe(original_seats[0].size());

    count += compass_count(r, f, -1, -1, re, fe); // NW
    count += compass_count(r, f, -1,  0, re, fe); // N
    count += compass_count(r, f, -1,  1, re, fe); // NE
    count += compass_count(r, f,  0,  1, re, fe); // E
    count += compass_count(r, f,  1,  1, re, fe); // SE
    count += compass_count(r, f,  1,  0, re, fe); // S
    count += compass_count(r, f, -1,  1, re, fe); // SW
    count += compass_count(r, f,  0, -1, re, fe); // W

    return count;
}

namespace {

int count_adjacent(std::size_t r, std::size_t f, const Seats& original_seats)
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


SeatState adjacent_with_limit(SeatState s, int adj, int limit)
{
    if ( s == SeatState::EMPTY && adj == 0)
    {
        return SeatState::OCCUPIED;
    }
    else if ( s == SeatState::OCCUPIED && adj >= limit)
    {
        return SeatState::EMPTY;
    }
    return s;
};


SeatState adjacent_4_limit(SeatState s, int adj)
{
    return adjacent_with_limit(s, adj, 4);
};

SeatState adjacent_5_limit(SeatState s, int adj)
{
    return adjacent_with_limit(s, adj, 5);
};


SeatChooserResult choose_seats( const Seats& original_seats, SeatNearbyCounter seat_counter, SeatStateUpdater updater )
{

    Seats new_seats;
    bool changed(false);
    
    for (std::size_t r = 0; r < original_seats.size(); ++r)
    {
        SeatRow new_row;
        for (std::size_t f = 0; f < original_seats[0].size(); ++f)
        {
            auto a = seat_counter(r,f, original_seats);
            auto n = updater(original_seats[r][f], a);
            std::cout << " " << n << a;

            changed |= (n != original_seats[r][f]);

            new_row.push_back(n);
        }
        new_seats.push_back(new_row);
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return {new_seats, changed};
}

}

Seats day11lib::parse_datastream(std::istream& data_stream)
{
    Seats data;

    std::string line;
    for (;std::getline(data_stream, line);)
    {   
        data.push_back( parse_datarow(line));
    }
    
    return data;
}


namespace {
std::size_t count_seated(const Seats& seats)
{
    std::size_t seated(0);
    for ( auto r : seats )
        seated += std::count( r.begin(), r.end(), SeatState::OCCUPIED);
    return seated;
}   

}


std::size_t iterate_to_equilibrium_and_count(Seats& seats, SeatNearbyCounter seat_counter, SeatStateUpdater updater)
{
    std::cout << std::endl << std::endl << "start: " << std::endl << seats << std::endl;

    int count(0);
    for(;;)
    {
        auto sp = choose_seats(seats, seat_counter, updater); 
        std::cout << std::endl << std::endl << "iteration: " << count << std::endl << sp.first << std::endl;

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
    return count_seated(seats);
}
std::size_t day11lib::part1_solve(std::istream& data_stream)
{
    auto seats = parse_datastream(data_stream);
    auto seated = iterate_to_equilibrium_and_count(seats, count_adjacent, adjacent_4_limit);
    return seated;
}

std::size_t day11lib::part2_solve(std::istream& data_stream)
{
    auto seats = parse_datastream(data_stream);
    auto seated = iterate_to_equilibrium_and_count(seats, count_visible, adjacent_5_limit);
    std::cout << "seated: " << seated << std::endl << seats << std::endl;
    return seated;
} 

std::size_t day11lib::part2_solve1(std::istream& data_stream)
{
    auto seats = parse_datastream(data_stream);
    auto sp = choose_seats(seats, count_visible, adjacent_5_limit); 
    auto c = count_seated(sp.first);
    return c;
} 
