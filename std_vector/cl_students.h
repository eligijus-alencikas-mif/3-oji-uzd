#ifndef CL_STUDENTS_H
#define CL_STUDENTS_H

#include <vector>
#include <iostream>
#include <limits>

#include "generator.h"
#include "inputs.h"
#include "student.h"

using std::cout;
typedef std::numeric_limits<int> int_lim;

class CL_Students
{
public:
    static std::vector<Student> get_user_input(const bool &generate_names, const bool &generate_grades);
    static void gen_names(Student &student);
    static void CL_names(Student &student, int students_size);
    static void gen_grades(Student &student, int students_size);
    static void CL_grades(Student &student, int students_size);
};

#endif // CL_STUDENTS_H
