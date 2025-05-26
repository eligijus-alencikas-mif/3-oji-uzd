#ifndef INPUTS_H
#define INPUTS_H

#include <iostream>
#include <limits>

using std::cin;
using std::cout;
typedef std::numeric_limits<int> int_lim;

class CLInputs
{
public:
    static int numInput(const std::string &prompt, const int limit_max = int_lim::max(),
                        const int limit_min = int_lim::min());

    static std::string strInput(const std::string &prompt, const int limit_max = int_lim::max(),
                                const int limit_min = int_lim::min());
};

#endif // INPUTS_H
