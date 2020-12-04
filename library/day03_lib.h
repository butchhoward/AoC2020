#ifndef DAY03_LIB_H
#define DAY03_LIB_H

#include <string>
#include <vector>
#include <iostream>
#include <limits>


namespace day03lib {

typedef struct Tree 
{
    Tree() :
        x(std::numeric_limits<std::size_t>::max()), y(std::numeric_limits<std::size_t>::max())
    {
    }
    Tree(std::size_t xx, std::size_t yy) :
        x(xx), y(yy)
    {
    }

    std::size_t x;
    std::size_t y;
} Tree;

inline bool operator==(const Tree& lhs, const Tree& rhs)
{
    // return true;
    return lhs.x == rhs.x && 
           lhs.y == rhs.y;
}

inline bool operator!=(const Tree& lhs, const Tree& rhs)
{
    return !(lhs == rhs);
}
    
typedef std::vector<Tree> Trees;

typedef struct TreeInfo 
{
    TreeInfo() :
        max_x(0), max_y(0)
    {
    }

    Trees trees;
    std::size_t max_x;
    std::size_t max_y;
} TreeInfo;


Trees parse_data_line( const std::string& tree_line, std::size_t y );
TreeInfo parse_data_stream(  std::istream& tree_stream );

std::size_t part1_solve(std::istream& tree_stream);
std::size_t part2_solve(std::istream& tree_stream);

}
#endif
