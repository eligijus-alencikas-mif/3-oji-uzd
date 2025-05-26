#ifndef GENERATOR_H
#define GENERATOR_H

#include <string>
#include <vector>

class Generator {
    static const std::vector<std::string> first_names;
    static const std::vector<std::string> last_names;

public:
    static std::string gen_f_name() ;
    static std::string gen_l_name() ;

    static std::string gen_name();
    std::vector<std::string> gen_names(unsigned long num_of_name) const;
    static int rand_int(const int min, const int max);

};


#endif //GENERATOR_H
