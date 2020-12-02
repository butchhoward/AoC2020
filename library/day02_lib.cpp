#include "day02_lib.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace day02lib;

std::ostream & day02lib::operator<<(std::ostream &os, const PasswordItem& pw)
{
    os << pw.min_count << '-' << pw.max_count << ' ' << pw.letter << ": " << pw.password;
    return os;
}

int day02lib::part1_solve(const PasswordData& password_data)
{

    return std::ranges::count_if(password_data.begin(), password_data.end(),
                                [](const PasswordItem& p)
                                { 
                                    std::string::size_type c = std::ranges::count(p.password.begin(), p.password.end(), p.letter);
                                    return c >= p.min_count && c <= p.max_count; 
                                });

}

int day02lib::part2_solve(const PasswordData& password_data)
{

    return std::ranges::count_if(password_data.begin(), password_data.end(),
                                [](const PasswordItem& p)
                                { 
                                    if (p.max_count > p.password.size() || p.min_count > p.password.size() ||
                                        p.max_count < 1                  || p.min_count < 1)
                                    {
                                        return false;
                                    }

                                    auto a = p.password.at(p.min_count-1); 
                                    auto b = p.password.at(p.max_count-1); 
                                    return ( a != b ) && ( a == p.letter || b == p.letter );
                                });

}

PasswordData day02lib::parse_data(const std::string& filename)
{
    PasswordData password_data;

    std::ifstream datafile(filename);
    if(!datafile)
    {
        std::cout << "Error opening input file" << std::endl;
        return password_data;
    }


    std::string value;
    while (std::getline(datafile, value))
    {
        if (value.size() == 0)
            continue;

        std::istringstream ss(value);
        PasswordItem pw;
        char eat_this_dash='\0';
        char eat_this_colon='\0';

        //2-6 c: fcpwjqhcgtffzlbj
        //white space is skipped, so no need to manually extract those
        ss  >> pw.min_count
            >> eat_this_dash
            >> pw.max_count
            >> pw.letter
            >> eat_this_colon
            >> pw.password 
            ;
        
        password_data.push_back(pw);
    }

     
    return password_data;
}
