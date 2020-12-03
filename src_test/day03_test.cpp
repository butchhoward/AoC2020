#include "day03_test.h"
#include "day03_lib.h"
#include "test_runner.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace day03lib;

bool day03_test_parse_data_line()
{
    /*
..##.......
#...#...#..
.#....#..#.
..#.#...#.#
.#...##..#.
..#.##.....
.#.#.#....#
.#........#
#.##...#...
#...##....#
.#..#...#.#
    */

    auto trees = parse_data_line("..##.......", 0);

    return trees.size() == 2 &&
           std::ranges::find_if(trees, [](const Tree& tree){ return tree == Tree(2,0); } ) != trees.end() &&
           std::ranges::find_if(trees, [](const Tree& tree){ return tree == Tree(3,0); } ) != trees.end() 
           ;
}

bool day03_test_parse_data_stream()
{
    std::string ss =               //y,x
                   "..##.......\n" //0,2 0,3
                   "#...#...#..\n"
                   ".#....#..#.\n"
                   "..#.#...#.#\n"
                   ".#...##..#.\n"
                   "..#.##.....\n"
                   ".#.#.#....#\n"
                   ".#........#\n"
                   "#.##...#...\n"
                   "#...##....#\n"
                   ".#..#...#.#\n" //10,1 10,4 10,8 10,10
                   ;

    std::istringstream tree_stream(ss);
    auto trees = parse_data_stream(tree_stream);

    return trees.size() == 37 &&
           std::ranges::find_if(trees, [](const Tree& tree){ return tree == Tree(2,0); } ) != trees.end() &&
           std::ranges::find_if(trees, [](const Tree& tree){ return tree == Tree(3,0); } ) != trees.end() && 
           std::ranges::find_if(trees, [](const Tree& tree){ return tree == Tree(1,10); } ) != trees.end() &&
           std::ranges::find_if(trees, [](const Tree& tree){ return tree == Tree(10,10); } ) != trees.end() &&
           std::ranges::find_if(trees, [](const Tree& tree){ return tree.y > 10; } ) == trees.end()
           ;
}


bool day03_test()
{
   test_runner::Tests tests = {
        {"day03_test_parse_data_line", day03_test_parse_data_line},
        {"day03_test_parse_data_stream", day03_test_parse_data_stream}
        //,{"XXXNextTest", XXX_test}
    };

    return test_runner::run_tests(tests);
}
