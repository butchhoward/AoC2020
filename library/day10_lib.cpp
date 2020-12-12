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
#include <functional>

using namespace day10lib;

namespace {

typedef int Jolt;
typedef std::vector<Jolt> Chargers;


// std::ostream& operator<<(std::ostream &os, const Chargers& cs)
// {
//     for ( auto j : cs)
//     {
//         os << j << ", ";
//     }
//     return os;
// }

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


Chargers get_next_chargers(const Chargers& chargers, Jolt current)
{
    Chargers next_chargers;
    std::ranges::copy_if(chargers, std::back_inserter(next_chargers), [current](auto c){ return c == current+1 || c == current+2 || c==current+3;});
    return next_chargers;
};

// void build_sub_chain_the_super_low_way_with_recursion(const Chargers& chargers, Jolt max_charger, Jolt current, Chargers& chain)
// {

//     auto get_next_chargers = [chargers](Jolt current)->Chargers
//                             {
//                                 Chargers next_chargers;
//                                 std::ranges::copy_if(chargers, std::back_inserter(next_chargers), [current](auto c){ return c == current+1 || c == current+2 || c==current+3;});
//                                 return next_chargers;
//                             };


//     // std::cout << "build_sub_chain: " << current << std::endl;
    
//     auto next_chargers = get_next_chargers(current);
//     // std::cout << "next_chargers: " << next_chargers << std::endl;

//     Chargers longest_sub;
//     for (auto c : next_chargers )
//     {
//         Chargers sub;
//         if ( c == max_charger)
//         {   
//             // std::cout << "maxxed" << std::endl;
//             sub.push_back(max_charger);
//         }
//         else
//         {
//             build_sub_chain(chargers, max_charger, c, sub);
//         }
        
//         if (sub.size() > longest_sub.size())
//         {
//             // std::cout << "longer subchain: " << sub.size() << " > " << longest_sub.size() << std::endl;
//             longest_sub.clear();
//             std::ranges::copy(sub, std::back_inserter(longest_sub));
//         }
//     }
//     chain.push_back(current);
//     if (longest_sub.size() > 0)
//     {
//         std::ranges::copy(longest_sub, std::back_inserter(chain));
//     }
//     // std::cout << " chain returned: " << chain << std::endl;
// }
//
//
// Chargers build_chain_the_super_low_way(const Chargers& chargers)
// {
//     std::cout << "build_chain: chargers.size=" << chargers.size() <<  std::endl;

//     Chargers chain;
//     if (chargers.size() == 0)
//     {
//         return chain;
//     }

//     auto max_charger = *std::max_element(chargers.begin(), chargers.end());
//     std::cout << "max_charger=" << max_charger <<  std::endl;
//     auto device = max_charger + 3;


//     std::cout << "build_chain: begin" <<  std::endl;

//     build_sub_chain(chargers, max_charger, 0, chain);
//     chain.push_back(device);

//     return chain;
// }



//the super fast way
Chargers build_chain(const Chargers& chargers)
{
    Chargers chain;
    if (chargers.size() == 0)
    {
        return chain;
    }

    auto max_charger = *std::max_element(chargers.begin(), chargers.end());
    Jolt current(0);
    chain.push_back(current);
    do
    {
        auto next_chargers = get_next_chargers(chargers, current);
        current = *std::min_element(next_chargers.begin(), next_chargers.end());
        chain.push_back(current);
    } while (current != max_charger);

    chain.push_back(max_charger + 3);

    return chain;
}


typedef std::pair<std::size_t, std::size_t> Diff13Counts;
Diff13Counts count_diffs(const Chargers& chargers)
{
    if (chargers.size() < 2)
    {
        return std::make_pair(0,0);
    }

    std::size_t diff1(0), diff3(0);

    auto c1 = chargers.begin();
    auto c2 = std::next(c1);
    for(;c2 != chargers.end(); ++c1, ++c2)
    {
        auto diff = *c2 - *c1;
        switch (diff)
        {
            case 1 : ++diff1; break;
            case 3 : ++diff3; break;
            default: break;
        }
    }
    return std::make_pair(diff1,diff3);
}

}

std::size_t day10lib::part1_solve(std::istream& data_stream)
{
    auto chargers = parse_datastream(data_stream);
    auto chain = build_chain(chargers);
    auto diffs = count_diffs(chain);
    return diffs.first * diffs.second;
}

std::size_t day10lib::part2_solve(std::istream& data_stream)
{
    auto chargers = parse_datastream(data_stream);
    return 0;
}
