#include "day03_lib.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace day03lib;

Trees day03lib::parse_data_line( const std::string& tree_line, int y)
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

Trees day03lib::parse_data_stream(  std::istream& tree_stream )
{
    Trees trees;

    std::string tree_line;
    for (auto y = 0; std::getline(tree_stream, tree_line); ++y)
    {
        if (tree_line.size() == 0)
            continue;

        Trees trees_from_line = parse_data_line(tree_line, y);
        trees.reserve(trees.size() + trees_from_line.size());
        trees.insert(trees.end(), trees_from_line.begin(), trees_from_line.end());
    }

    return trees;
}
