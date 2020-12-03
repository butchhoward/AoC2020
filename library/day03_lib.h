#ifndef DAY03_LIB_H
#define DAY03_LIB_H

#include <string>
#include <vector>
#include <iostream>


namespace day03lib {

typedef struct Tree 
{
    Tree() :
        x(-1), y(-1)
    {
    }
    Tree(int xx, int yy) :
        x(xx), y(yy)
    {
    }

    int x;
    int y;
} Tree;

inline bool operator==(const Tree& lhs, const Tree& rhs)
{
    return lhs.x == rhs.x && 
           lhs.y == rhs.y;
}
    
typedef std::vector<Tree> Trees;

Trees parse_data_line( const std::string& tree_line, int y );
Trees parse_data_stream(  std::istream& tree_stream );

int lib_function();

}
#endif
