#include "day09_lib.h"
#include <vector>
#include <iterator>
#include <sstream>
#include <utility>
#include <algorithm>
#include <numeric>

using namespace day09lib;

typedef int XMASValue;
typedef std::vector<XMASValue> XMASData;

namespace {

bool find_pair_that_sums_to( XMASValue v, int preamble_size, const XMASData::iterator preamble_begin, XMASData::iterator data_end)
{

    for(auto moving_preamble_begin = preamble_begin; moving_preamble_begin != data_end; ++moving_preamble_begin)
    {
        auto moving_preamble_end = std::next(moving_preamble_begin,preamble_size);
        auto p1 = moving_preamble_begin;
        for ( auto outer = 0; outer < preamble_size; ++outer, ++p1)
        {
            if (p1 == data_end || p1 == moving_preamble_end)
            {
                return false;
            }

            auto p2 = std::next(p1);
            for (auto inner = outer+1; inner < preamble_size; ++inner, ++p2)
            {
                if (p2 == data_end || p2 == moving_preamble_end)
                {
                    return false;
                }


                if (*p1 + *p2 == v)
                {
                    return true;
                }
            }
        }
    }
    return false;
}


XMASData::iterator find_first_invalid(int preamble_size, XMASData& data)
{

    XMASData::iterator preamble_begin = data.begin();

    for(auto v = std::next(preamble_begin, preamble_size); v != data.end(); ++v, ++preamble_begin)
    {
        if ( !find_pair_that_sums_to(*v, preamble_size, preamble_begin, data.end()) )
        {
            return v;
        }
    }
    return data.end();
}

typedef std::pair<XMASData::iterator, XMASData::iterator> XMASIteratorPair;
XMASIteratorPair find_sequence_sums_to(int invalid_value, XMASData& data)
{
    for (XMASData::size_type window_size = 2; window_size <= data.size(); ++window_size)
    {
        auto window_begin = data.begin();
        auto window_end = std::next(window_begin, window_size);
        std::size_t window_end_index(window_size);
        for ( ;window_end_index < data.size() ; ++window_end_index, ++window_begin, ++window_end )
        {
            auto sum = std::accumulate(window_begin, window_end, 0);
            if (sum == invalid_value)
            {
                return std::make_pair(window_begin, window_end);
            }
        }
    }
    
    return std::make_pair(data.end(), data.end());
}

XMASData parse_datastream(std::istream& data_stream)
{
    XMASData data;

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

std::size_t day09lib::part1_solve(int preamble_size, std::istream& data_stream)
{
    auto data = parse_datastream(data_stream);
    auto invalid = find_first_invalid(preamble_size, data);
    if (invalid == data.end())
    {
        return 0;
    }

    return *invalid;
}

std::size_t day09lib::part2_solve(int invalid_value, std::istream& data_stream)
{
    auto data = parse_datastream(data_stream);
    auto seq_info = find_sequence_sums_to(invalid_value, data);
    if (seq_info.first == data.end())
    {
        std::cout << "!!!part2_solve: FAILED!!" << std::endl;
        return 0;
    }

    auto v_min = std::ranges::min_element(seq_info.first, seq_info.second);
    auto v_max = std::ranges::max_element(seq_info.first, seq_info.second);
    return *v_max + *v_min;
}
