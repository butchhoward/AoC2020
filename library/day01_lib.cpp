#include "day01_lib.h"

#include <fstream>
#include <iostream>
#include <sstream>


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

std::pair<int, int> find_pair_sums_to_2020(std::vector<int> expenses)
{
    for (auto i = expenses.begin(); i != expenses.end(); i++ )
    {
        for (auto k = i; k != expenses.end(); k++ )
        {
            if (*i + *k == 2020)
            {
                return std::make_pair(*i, *k);
            }
        }

    }

    return std::make_pair(0, 0);
}

int day01_solve( std::vector<int> expenses )
{
    auto expense_pair = find_pair_sums_to_2020(expenses);
    int solution = expense_pair.first * expense_pair.second;
    return solution;
}
