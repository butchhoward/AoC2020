#include "day06_lib.h"

#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <cstddef>



using namespace day06lib;

typedef std::set<char> GroupAnswers;
typedef std::vector<GroupAnswers> Answers;

Answers parse_datastream(std::istream& data_stream )
{
    Answers answers;
    GroupAnswers group_answers;

    std::string person_answer;
    for (;std::getline(data_stream, person_answer);)
    {
        if (person_answer.length() == 0)
        {
            answers.push_back(group_answers);
            group_answers.clear();
        }
        else 
        {
            for ( auto a : person_answer )
            {
                group_answers.insert(a);
            }
        }
    }
    if (person_answer.length() != 0)
    {
        for ( auto a : person_answer )
        {
            group_answers.insert(a);
        }
    }
    if (group_answers.size() != 0 )
    {
        answers.push_back(group_answers);
    }

    return answers;

}

std::size_t day06lib::part1_solve(std::istream& data_stream)
{
    auto answers = parse_datastream(data_stream);
    std::size_t sum(0);
    for ( auto a : answers )
    {
        sum += a.size();
    }
    return sum;
}
