#include "day02_lib.h"
#include <algorithm>

int day02_part1_solve(const PasswordData& password_data)
{

    return std::ranges::count_if(password_data.begin(), password_data.end(),
                                [](const PasswordItem& p)
                                { 
                                    auto c = std::ranges::count(p.password.begin(), p.password.end(), p.letter);
                                    return c >= p.min_count && c <= p.max_count; 
                                });

}
