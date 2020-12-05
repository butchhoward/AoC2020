#ifndef DAY04_LIB_H
#define DAY04_LIB_H

#include <string>
#include <cstddef>
#include <iostream>
#include <map>
#include <vector>

namespace day04lib {


typedef struct Passport 
{
    Passport()
    {
    }
    std::map<std::string, std::string> fields;

} Passport;

typedef std::vector<Passport> Passports;

std::ostream & operator<<(std::ostream &os, const Passports& ps);
std::ostream & operator<<(std::ostream &os, const Passport& p);


Passports parse_data_stream(  std::istream& tree_stream );

std::size_t part1_solve(std::istream& tree_stream);

}
#endif
