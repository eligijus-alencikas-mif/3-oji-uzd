#ifndef FILE_GEN_H
#define FILE_GEN_H

#include <fstream>
#include <iostream>
#include <string>
#include "generator.h"
#include "constant_definitions.h"
#include "timer.h"

class FileGen {
public:
    static void gen_file(std::uint64_t num_students, std::uint64_t num_hw, const std::string &file_name);
};


#endif //FILE_GEN_H
