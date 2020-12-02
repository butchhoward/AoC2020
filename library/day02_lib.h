#ifndef DAY02_LIB_H
#define DAY02_LIB_H

#include <string>
#include <vector>

namespace day02lib {

typedef struct PasswordItem 
{
    PasswordItem() :
        min_count(0),
        max_count(0),
        letter('\0')
    {
    }
    PasswordItem(int min_c, int max_c, char abc, const std::string pw) :
        min_count(min_c),
        max_count(max_c),
        letter(abc),
        password(pw)
    {
    }
    std::string::size_type min_count;
    std::string::size_type max_count;
    char letter;
    std::string password;
} PasswordItem;

typedef std::vector<PasswordItem> PasswordData;

std::ostream & operator <<(std::ostream &os, const PasswordItem& pw);


PasswordData parse_data(const std::string& filename);

int part1_solve(const PasswordData& password_data);
int part2_solve(const PasswordData& password_data);

}

#endif
