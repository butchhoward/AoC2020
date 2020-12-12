#include "day10_lib.h"

#include <iostream>
#include <sstream>
#include <cstddef>
#include <vector>
#include <ranges>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>

using namespace day10lib;

namespace {

typedef int Jolts;
typedef std::vector<Jolts> Chargers;

Chargers parse_datastream(std::istream& data_stream)
{
    Chargers data;

    std::string line;
    for (;std::getline(data_stream, line);)
    {   
        std::istringstream v(line);
        int value;
        v >> value;
        data.push_back(value);
    }
    
    return data;
}


}

std::size_t day10lib::part1_solve(std::istream& data_stream)
{
    auto chargers = parse_datastream(data_stream);
    // auto colors = find_all_bags_can_hold_color(bag_rules, BagColor("shiny gold"));
    return 0;
}

std::size_t day10lib::part2_solve(std::istream& data_stream)
{
    auto chargers = parse_datastream(data_stream);
    return 0;
}
