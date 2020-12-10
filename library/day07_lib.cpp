#include "day07_lib.h"
#include <iostream>
#include <sstream>
#include <cstddef>
#include <vector>
#include <ranges>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>

using namespace day07lib;

namespace {

typedef std::string BagColor;

typedef struct BagType
{
    BagType() :
        count(0)
    {}
    BagType(size_t c, const BagColor& s) :
        color(s), count(c)
    {}
    BagColor color;
    std::size_t count;
} BagType;

typedef std::vector<BagType> Bags;


typedef struct BagRule
{
    BagRule()    
        {}
    BagRule(const std::string s) :
        bag(1, s)
    {}
    BagType bag;
    Bags inner_bags;

} BagRule;

typedef std::pair<BagColor, BagRule> BagRulesMapPair;
typedef std::map<BagRulesMapPair::first_type, BagRulesMapPair::second_type> BagRules;

static inline void ltrim(std::string &s, const std::string& what) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [what](unsigned char ch) {
        return what.find(ch) == std::string::npos;
    }));
}

static inline void rtrim(std::string &s, const std::string& what) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [what](unsigned char ch) {
        return what.find(ch) == std::string::npos;
    }).base(), s.end());
}

static inline void trim(std::string &s, const std::string& what) {
    ltrim(s, what);
    rtrim(s, what);
}

static inline std::string ltrim_copy(std::string s, const std::string& what) {
    ltrim(s, what);
    return s;
}

static inline std::string rtrim_copy(std::string s, const std::string& what) {
    rtrim(s, what);
    return s;
}

static inline std::string trim_copy(std::string s, const std::string& what) {
    trim(s, what);
    return s;
}




//from https://www.fluentcpp.com/2019/05/14/3-types-of-macros-that-improve-c-code/
#define FWD(...) ::std::forward<decltype(__VA_ARGS__)>(__VA_ARGS__)

BagRule parse_line(const std::string& line)
{
    //used twice now, should probably rafactor to a common thing.
    //from https://brevzin.github.io/c++/2020/07/06/split-view/
    auto split_strs = [](auto&& pattern)
    {
        return std::ranges::views::split(FWD(pattern))
            | std::ranges::views::transform([](auto p){
                auto c = p | std::ranges::views::common;
                return std::string(c.begin(), c.end());
            });
    };

    std::string bags_contained_marker(" bags contain ");
    std::size_t bags_contained_marker_pos = line.find(bags_contained_marker);
    auto bag_color = line.substr(0, bags_contained_marker_pos);
    auto contained = line.substr(bags_contained_marker_pos + bags_contained_marker.length(), std::string::npos);

    BagRule bagrule(bag_color);

    auto contains = contained | split_strs(',');
    auto c_as_vector = std::vector<std::string>(contains.begin(), contains.end());
    for ( auto b : c_as_vector )
    {
        trim(b, " .");
        auto color_pos =  b.find(' ');
        auto tail_pos = b.rfind(' ');

        auto count_s = b.substr(0, color_pos);
        auto inner_bags = b.substr(color_pos+1, tail_pos-color_pos-1);

        std::size_t count(0);
        
        if (count_s == "no")
        {
            count = 0;
            inner_bags.clear();
        }
        else
        {
            count = std::atoi(count_s.c_str());
        }
       
        BagType bag( count, inner_bags);
        bagrule.inner_bags.push_back(bag);
    }
    return bagrule;
}

BagRules parse_datastream(std::istream& data_stream)
{
    BagRules bagrules;

    std::string line;
    for (;std::getline(data_stream, line);)
    {
        BagRule bagrule = parse_line(line);
        bagrules.insert({bagrule.bag.color, bagrule});
    }

    return bagrules;
}

}

typedef std::set<BagColor> BagColorSet;

BagColorSet find_all_bags_can_hold_color( const BagRules& bagrules, const BagColor& color, const BagColorSet& init={})
{
    BagColorSet c = std::accumulate<BagRules::const_iterator, BagColorSet>(bagrules.begin(), bagrules.end(), init, 
                    [bagrules, color](BagColorSet init, const BagRulesMapPair& r)
                    {
                        if (r.first == color || r.second.inner_bags.size() == 0)
                        {
                            return init;
                        }

                        auto b = std::find_if( r.second.inner_bags.begin(), r.second.inner_bags.end(), 
                                                [r,color](const Bags::value_type& b)
                                                    { 
                                                        return b.color == color;
                                                    }
                                            );

                        if ( b == r.second.inner_bags.end() )
                        {
                            return init;
                        }

                        ;
                        init.insert(r.first);                                    
                        return find_all_bags_can_hold_color( bagrules, r.first, init );
                    }
                );
    return c;
}

std::size_t count_bags_inside( const BagRules& bagrules, const BagColor& color)
{
    if ( color.empty() )
    {
        return 0;
    }

    auto bagrule_it = std::find_if(bagrules.begin(), bagrules.end(), [color](auto b){return b.second.bag.color == color;});
    if ( bagrule_it == bagrules.end() || bagrule_it->second.inner_bags.size() == 0)
    {
        return 0;
    }

    auto inner_bags = bagrule_it->second.inner_bags;

    return std::accumulate(inner_bags.begin(), inner_bags.end(), 0, 
                                    [bagrules](size_t init, auto bag)
                                    {
                                        return init + bag.count + (bag.count * count_bags_inside(bagrules, bag.color));
                                    } 
                                );
}

std::size_t day07lib::part1_solve(std::istream& data_stream)
{
    auto bag_rules = parse_datastream(data_stream);
    auto colors = find_all_bags_can_hold_color(bag_rules, BagColor("shiny gold"));
    return colors.size();
}

std::size_t day07lib::part2_solve(std::istream& data_stream)
{
    auto bag_rules = parse_datastream(data_stream);
    return count_bags_inside(bag_rules, BagColor("shiny gold"));
}
