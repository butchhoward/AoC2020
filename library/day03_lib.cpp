#include "day03_lib.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace day03lib;

Trees day03lib::parse_data_line( const std::string& tree_line, std::size_t y)
{
    Trees trees;

    std::istringstream ss(tree_line);
    for (auto x = 0;;x++)
    {
        char c;
        ss >> c;
        if (ss.eof())
        {
            break;
        }

        if ( c == '#')
        {
            Tree tree(x,y);
            trees.push_back(tree);
        }
    }

    return trees;

}

TreeInfo day03lib::parse_data_stream(  std::istream& tree_stream )
{
    TreeInfo tree_info;

    std::string tree_line;
    for (;std::getline(tree_stream, tree_line); tree_info.max_y++)
    {
        if (tree_line.size() == 0)
        {
            break;
        }
        if (tree_line.size() > tree_info.max_x)
        {
            tree_info.max_x = tree_line.size();
        }

        Trees trees_from_line = parse_data_line(tree_line, tree_info.max_y);
        tree_info.trees.reserve(tree_info.trees.size() + trees_from_line.size());
        tree_info.trees.insert(tree_info.trees.end(), trees_from_line.begin(), trees_from_line.end());
    }
    --tree_info.max_y;
    --tree_info.max_x;

    return tree_info;
}


int day03lib::part1_solve(std::istream& tree_stream)
{

    auto tree_info = parse_data_stream( tree_stream );

    int count(0);
    std::size_t x(0);
    std::size_t y(0);

    for (; y <= tree_info.max_y;)
    {
        x = (x + 3) % (tree_info.max_x+1);
        y += 1;

        if ( std::ranges::find(tree_info.trees, Tree(x,y)) != tree_info.trees.end() )
        {
            ++count;
        }
    }

    return count;

}
