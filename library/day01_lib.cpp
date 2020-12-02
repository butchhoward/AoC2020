#include "day01_lib.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <numeric>


std::vector<int> day01_parse_data(const std::string& filename)
{
    std::vector<int> expenses;

    std::ifstream datafile(filename);
    if(!datafile)
    {
        std::cout << "Error opening input file" << std::endl;
        return expenses;
    }


    std::string value;
    while (std::getline(datafile, value))
    {
        int expense{0};
        std::istringstream s_value(value);
        s_value >> expense;
        expenses.push_back(expense);
    }

    return expenses;
}

std::vector<int> find_pair_sums_to_2020(std::vector<int> expenses)
{
    std::vector<int> result;

    for (auto i = expenses.begin(); i != expenses.end(); i++ )
    {
        for (auto k = i+1; k != expenses.end(); k++ )
        {
            if (*i + *k == 2020)
            {
                result.push_back(*i);
                result.push_back(*k);
                return result;
            }
        }

    }

    return result;
}

std::vector<int> find_triplet_sums_to_2020(std::vector<int> expenses)
{
    std::vector<int> result;

    for (auto i = expenses.begin(); i != expenses.end(); i++ )
    {
        for (auto k = i+1; k != expenses.end(); k++ )
        {
            for (auto m = k+1; m != expenses.end(); m++ )
            {
                if (*i + *k + *m == 2020) 
                {
                    result.push_back(*i);
                    result.push_back(*k);
                    result.push_back(*m);
                    return result;
                }
            }
        }
    }

    return result;

}


int day01_part1_solve( std::vector<int> expenses )
{
    auto expenses_found = find_pair_sums_to_2020(expenses);
    int solution = std::reduce(expenses_found.begin(), expenses_found.end(), 1,
                                [](int a, int b){ return a*b; });
    return solution;
}

int day01_part2_solve( std::vector<int> expenses )
{

    auto expenses_found = find_triplet_sums_to_2020(expenses);
    int solution = std::reduce(expenses_found.begin(), expenses_found.end(), 1, 
                                [](int a, int b){ return a*b; });
    return solution;
}

