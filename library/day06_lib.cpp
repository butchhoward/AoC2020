#include "day06_lib.h"

#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <cstddef>



using namespace day06lib;

typedef struct GroupAnswers
{
    std::vector<std::string> member_answers;
    void clear()
    {
        member_answers.clear();
    }
} GroupAnswers;

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
            group_answers.member_answers.push_back(person_answer);
        }
    }
    if (person_answer.length() != 0)
    {
        group_answers.member_answers.push_back(person_answer);
    }
    if (group_answers.member_answers.size() != 0 )
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
        std::set<char> anyone_answered;
        for ( auto m : a.member_answers )
        {
            for ( auto c : m)
            {
                anyone_answered.insert(c);
            }
        }
        sum += anyone_answered.size();
    }
    return sum;
}

std::size_t day06lib::part2_solve(std::istream& data_stream)
{
    auto answers = parse_datastream(data_stream);
    std::size_t sum(0);
    for ( auto a : answers )
    {
        std::vector<std::string>::iterator m = a.member_answers.begin();
        std::string everyone_answered(*m);
        for ( ++m; m != a.member_answers.end(); ++m)
        {
            std::ranges::sort(everyone_answered);
            std::ranges::sort(*m);
            std::string s;
            std::set_intersection(everyone_answered.begin(), everyone_answered.end(),
                                    m->begin(), m->end(),
                                    std::back_inserter(s));
            everyone_answered = s;     
        }
        sum += everyone_answered.size();
    }
    return sum;
}
