#include "day03_test.h"
#include "day03_lib.h"
#include "test_runner.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace day03lib;

const std::string sample_data(  //y,x
//               01234567890
                "..##.......\n" //0 0,2 0,3
                "#...#...#..\n" //1 
                ".#....#..#.\n" //2 
                "..#.#...#.#\n" //3 
                ".#...##..#.\n" //4 
                "..#.##.....\n" //5 
                ".#.#.#....#\n" //6 
                ".#........#\n" //7 
                "#.##...#...\n" //8 
                "#...##....#\n" //9 
                ".#..#...#.#\n" //0 10,1 10,4 10,8 10,10
)
                ;

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

    std::istringstream tree_stream(sample_data);
    auto tree_info = parse_data_stream(tree_stream);

    return tree_info.trees.size() == 37
           && std::ranges::find_if(tree_info.trees, [](const Tree& tree){ return tree == Tree(2,0); } ) != tree_info.trees.end()
           && std::ranges::find_if(tree_info.trees, [](const Tree& tree){ return tree == Tree(3,0); } ) != tree_info.trees.end()
           && std::ranges::find_if(tree_info.trees, [](const Tree& tree){ return tree == Tree(1,10); } ) != tree_info.trees.end()
           && std::ranges::find_if(tree_info.trees, [](const Tree& tree){ return tree == Tree(10,10); } ) != tree_info.trees.end()
           && std::ranges::find_if(tree_info.trees, [](const Tree& tree){ return tree.y > 10; } ) == tree_info.trees.end()
           && tree_info.max_x == 10 && tree_info.max_y == 10
           ;
}

bool test_sample_data()
{
    std::istringstream tree_stream(sample_data);

    return 7 == part1_solve(tree_stream);
}

bool day03_test_data()
{

    std::ifstream datafile("./data/day03_data.txt");
    if(!datafile)
    {
        std::cout << "Error opening input file" << std::endl;
        return -1;
    }

    return 193 == part1_solve(datafile)
            ;
}

bool day03_test()
{
   test_runner::Tests tests = {
        {"test_parse_data_line", day03_test_parse_data_line},
        {"test_parse_data_stream", day03_test_parse_data_stream},
        {"test_sample_data", test_sample_data},
        {"test_data", day03_test_data}
        //,{"XXXNextTest", XXX_test}
    };

    return test_runner::run_tests("day03_test", tests);
}
