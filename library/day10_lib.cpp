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

Chargers get_next_chargers( const Chargers& chargers, Jolt current)
{
    Chargers next_chargers;
    std::ranges::copy_if(chargers, std::back_inserter(next_chargers), [current](auto c){ return c == current+1 || c == current+2 || c==current+3;});
    return next_chargers;
};


Chargers build_chain(Chargers& chargers)
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


typedef std::map<Jolt, Chargers> MemoBranches;

MemoBranches build_branch_memo( Chargers& chargers)
{
    MemoBranches memo;
    if (chargers.size() == 0)
    {
        return memo;
    }

    auto next_chargers_wall = get_next_chargers(chargers, 0);
    memo.insert({0, next_chargers_wall});

    for ( auto c : chargers )
    {
        auto next_chargers = get_next_chargers(chargers, c);
        memo.insert({c, next_chargers});
    };

    auto max_charger = *std::max_element(chargers.begin(), chargers.end());
    Chargers device = {max_charger + 3};
    memo.insert_or_assign(max_charger, device);


    return memo;
}


std::size_t count_them( const MemoBranches& memos, std::map<Jolt, std::size_t>& subnode_totals, Jolt c)
{
    std::size_t total(0);


    auto b = memos.find(c);
    if ( b != memos.end())
    {
        auto b_chargers = b->second.size();
        if ( b_chargers > 1 )
        {
            total += b_chargers-1;
        }

        for ( auto sub_b : b->second )
        {
            auto snt = subnode_totals.find(sub_b);
            if (snt != subnode_totals.end())
            {
                total += snt->second;
            }
            else
            {
                auto sub_n_count = count_them(memos, subnode_totals, sub_b);
                subnode_totals.insert_or_assign(sub_b, sub_n_count);
                total += sub_n_count;
            } 
        }
    }

    return total;
};


std::size_t count_possible_chains( Chargers chargers )
{

/*
    I tried several other thjings that either did not calculate the values needed ot ran for too long (>>2hours) without getting a result.

    A hint about using memoization from our slack finally got me in a good direction. Thanks PaulS, LuisC, TylerV, AndrewA, MaisamS, et.al.

    recurse down the connections recording the branch-counts at each node then count the leaf nodes
    so for the sample data
        1,1
        4,3
        5,2
        6,1 
        7,1 
        10,2
        11,1
        12,1
        15,1
        16,1
        19,1
    As we recurse, check the memoization to see if we have aleady crawled a node.

    maybe crawl the optimal path (see part1), recording the nodes and counts, then recurse just that tabulation for the branches? (<<-- this!)
    
*/
    
    auto memos = build_branch_memo(chargers);
    std::map<Jolt, std::size_t> subnode_totals;
    return 1+count_them(memos, subnode_totals, 0);
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
    if (chargers.size() == 0)
    {
        return 0;
    }
    return count_possible_chains(chargers);
}
