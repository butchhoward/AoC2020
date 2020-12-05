#include "day04_lib.h"
#include <ranges>
#include <algorithm>
#include <string>
#include <sstream>

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

std::map<std::string, std::string> keyfields = {
         {"byr",""}
        ,{"iyr",""}
        ,{"eyr",""}
        ,{"hgt",""}
        ,{"hcl",""}
        ,{"ecl",""}
        ,{"pid",""}
};

bool keycomp (const std::pair<std::string, std::string>& p1, const std::pair<std::string, std::string>& p2)
{
    return p1.first < p2.first;
}

std::size_t day04lib::part1_solve(std::istream& passport_stream)
{
    Passports passports = parse_data_stream(passport_stream);

    return std::ranges::count_if(passports.begin(), passports.end(),
                                [](const Passport& p)
                                { 
                                    return std::includes(p.fields.begin(), p.fields.end(), keyfields.begin(), keyfields.end(), keycomp);
                                });

}

// byr (Birth Year) - four digits; at least 1920 and at most 2002.
bool validate_byr(const std::string& v)
{
    return v.length() == 4
        && v >= "1920" && v <= "2002"
    ;
}

// iyr (Issue Year) - four digits; at least 2010 and at most 2020.
bool validate_iyr(const std::string& v)
{
    return v.length() == 4
        && v >= "2010" && v <= "2020"
    ;
}

// eyr (Expiration Year) - four digits; at least 2020 and at most 2030.
bool validate_eyr(const std::string& v)
{
    return v.length() == 4
        && v >= "2020" && v <= "2030"
    ;
}

// hgt (Height) - a number followed by either cm or in:
// If cm, the number must be at least 150 and at most 193.
// If in, the number must be at least 59 and at most 76.
bool validate_hgt(const std::string& v)
{
    if (v.length() < 3)
        return false;

    std::istringstream ss(v);
    int h;
    std::string d;

    ss >> h
       >> d;

    if (d == "in")
    {
        if ( h >= 59 && h <= 76 )
            return true;
    }
    else if(d == "cm")
    {
        if ( h >= 150 && h <= 193 )
            return true;
    }

    return false;
}

// hcl (Hair Color) - a # followed by exactly six characters 0-9 or a-f.
bool validate_hcl(const std::string& v)
{
    if (v.length() != 7)
        return false;

    auto i = v.begin();
    ++i;

    std::string valid("0123456789abcdefABCDEF");
    return std::all_of(i, v.end(), 
                [valid](const char c)
                { 
                    return valid.find(c) != std::string::npos; 
                }
            );
}

// ecl (Eye Color) - exactly one of: amb blu brn gry grn hzl oth.
bool validate_ecl(const std::string& v)
{
    std::vector<std::string> valid( {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"} );
    return std::ranges::find(valid, v) != valid.end(); 
}

// pid (Passport ID) - a nine-digit number, including leading zeroes.
bool validate_pid(const std::string& v)
{
    if (v.length() != 9)
        return false;

    std::string valid("0123456789");
    return std::all_of(v.begin(), v.end(), 
                [valid](char c)
                { 
                    return valid.find(c) != std::string::npos; 
                }
            );
};

// cid (Country ID) - ignored, missing or not.
bool validate_cid(const std::string& v)
{
    (void)v;
    return true;
};

std::map<std::string, std::function<bool(const std::string&)>> keyfield_validators = {
         {"byr",validate_byr}
        ,{"iyr",validate_iyr}
        ,{"eyr",validate_eyr}
        ,{"hgt",validate_hgt}
        ,{"hcl",validate_hcl}
        ,{"ecl",validate_ecl}
        ,{"pid",validate_pid}
        ,{"cid",validate_cid}
};

bool validate(const std::pair<std::string, std::string>& p1 )
{
    auto i = keyfield_validators.find(p1.first);
    if ( i == keyfield_validators.end())
        return true;
    return i->second(p1.second);
}

std::size_t day04lib::part2_solve(std::istream& passport_stream)
{
    Passports passports = parse_data_stream(passport_stream);

    auto i = std::ranges::count_if(passports.begin(), passports.end(),
                                [](const Passport& p)
                                { 
                                    return std::includes(p.fields.begin(), p.fields.end(), keyfields.begin(), keyfields.end(), keycomp)
                                           && 
                                           std::all_of( p.fields.begin(), p.fields.end(), validate) 
                                    ;
                                });

    return i;
}
