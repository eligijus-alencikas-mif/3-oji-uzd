#ifndef STUDENT_TEST_H
#define STUDENT_TEST_H

#include "student.h"
#include "students_calc.h"
#include <tuple>
#include <string>
#include <iostream>
#include <sstream>

class StudentTest
{
public:
    static bool test_destructor();
    static bool test_copy_constructor();
    static bool test_copy_assignment_operator();
    static bool test_move_constructor();
    static bool test_move_assignment_operator();
    static std::tuple<bool, std::string> test_all();
    static bool test_input_operator();
    static bool test_output_operator();
};

#endif // STUDENT_TEST_H