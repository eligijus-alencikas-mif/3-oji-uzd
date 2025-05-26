#ifndef STUDENTS_CALC_H
#define STUDENTS_CALC_H

#include <vector>
#include <algorithm>

#include "constant_definitions.h"
#include "student.h"
#include "../vector.hpp"

class Calc_Students
{
public:
    static void calc_grades(Vector<Student> &students);
    static void set_student_avg(Student &student);
    static void set_student_median(Student &student);
    static void sort_students(Vector<Student> &students, int sort_method);
    static bool student_sort_f_name(Student const &lhs, Student const &rhs);
    static bool student_sort_l_name(Student const &lhs, Student const &rhs);
    static bool student_sort_avg(Student const &lhs, Student const &rhs);
    static bool student_sort_med(Student const &lhs, Student const &rhs);
    static double calc_average(std::vector<int> &&scores, int &&egzam);
};

#endif // STUDENTS_CALC_H
