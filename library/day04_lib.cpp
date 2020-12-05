#include "day04_lib.h"
#include <ranges>
#include <algorithm>
#include <string>

using namespace day04lib;


std::ostream & day04lib::operator<<(std::ostream &os, const Passports& ps)
{
    for ( auto p : ps)
    {
        os << p << std::endl << std::endl;
    }
    return os;
}

std::ostream & day04lib::operator<<(std::ostream &os, const Passport& p)
{

    for ( auto f : p.fields )
    {
        os << f.first << ":" << f.second << " ";
    }

    return os;
}


//from https://www.fluentcpp.com/2019/05/14/3-types-of-macros-that-improve-c-code/
#define FWD(...) ::std::forward<decltype(__VA_ARGS__)>(__VA_ARGS__)


Passport parse_data_line( const std::string& pp )
{
    //this was a deep c++20 hole I fell into...lots of learning here

    //from https://brevzin.github.io/c++/2020/07/06/split-view/
    auto split_strs = [](auto&& pattern){
        return std::ranges::views::split(FWD(pattern))
            | std::ranges::views::transform([](auto p){
                auto c = p | std::ranges::views::common;
                return std::string(c.begin(), c.end());
            });
    };

    Passport passport;
    
    auto fields = pp | split_strs(' ');
    auto fields_as_vector = std::vector<std::string>(fields.begin(), fields.end());
    for ( auto field : fields_as_vector )
    {
        auto kvs = field | split_strs(':');
        auto kvs_as_vector = std::vector<std::string>(kvs.begin(), kvs.end());
        if ( kvs_as_vector.size() != 2)
            continue;

        passport.fields.insert_or_assign(kvs_as_vector[0], kvs_as_vector[1]);
    }

    return passport;
}

Passports day04lib::parse_data_stream(  std::istream& passport_stream )
{
    Passports passports;

    std::string ppline;
    std::string pp;
    for (;std::getline(passport_stream, ppline);)
    {
        if (ppline.length() == 0)
        {
            Passport passport = parse_data_line( pp );
            passports.push_back(passport);
            pp.clear();
        }
        else 
        {
            pp += " ";
            pp += ppline;
        }
    }
    if (pp.length() > 0)
    {
        Passport passport = parse_data_line( pp );
        passports.push_back(passport);
    }

    return passports;
}

std::size_t day04lib::part1_solve(std::istream& passport_stream)
{
    Passports passports = parse_data_stream(passport_stream);

    auto keycomp = [](const std::pair<std::string, std::string>& p1, const std::pair<std::string, std::string>& p2)
                        {
                            return p1.first < p2.first;
                        };

    std::map<std::string, std::string> keyfields = {
             {"byr",""}
            ,{"iyr",""}
            ,{"eyr",""}
            ,{"hgt",""}
            ,{"hcl",""}
            ,{"ecl",""}
            ,{"pid",""}
    };

    return std::ranges::count_if(passports.begin(), passports.end(),
                                [keyfields,keycomp](const Passport& p)
                                { 
                                    return std::includes(p.fields.begin(), p.fields.end(), keyfields.begin(), keyfields.end(), keycomp);
                                });

}
