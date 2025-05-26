#include "students_calc.h"

void Calc_Students::calc_grades(Vector<Student> &students)
{
    for (Student &student : students)
    {
        set_student_avg(student);
        set_student_median(student);
    }
}

void Calc_Students::set_student_avg(Student &student)
{
    if (student.get_hw_scores().empty())
    {
        student.set_final_score_avg(EXAM_WEIGHT * static_cast<double>(student.get_exam_score()));
        return;
    }

    student.set_final_score_avg(calc_average(student.get_hw_scores(), student.get_exam_score()));
}

double Calc_Students::calc_average(std::vector<int> &&scores, int &&egzam)
{
    double hw_sum = 0;
    double hw_avg = 0;

    for (const int hw_score : scores)
    {
        hw_sum += hw_score;
    }

    hw_avg = hw_sum / static_cast<double>(scores.size());
    return (HW_WEIGHT * hw_avg + EXAM_WEIGHT * static_cast<double>(egzam));
}

void Calc_Students::set_student_median(Student &student)
{
    std::vector<int> scores = student.get_hw_scores();
    scores.push_back(student.get_exam_score());

    std::sort(scores.begin(), scores.end());

    if (scores.size() % 2 == 0)
    {
        student.set_final_score_med((scores[(scores.size() / 2) - 1] + scores[scores.size() / 2]) / static_cast<
                                                                                                        double>(
                                                                                                        2));
    }
    else
    {
        student.set_final_score_med(scores[(scores.size() - 1) / 2]);
    }
}

void Calc_Students::sort_students(Vector<Student> &students, int sort_method)
{
    switch (sort_method)
    {
    case 1:
        std::sort(students.begin(), students.end(), student_sort_f_name);
        break;
    case 2:
        std::sort(students.begin(), students.end(), student_sort_l_name);
        break;
    case 3:
        std::sort(students.begin(), students.end(), student_sort_avg);
        break;
    case 4:
        std::sort(students.begin(), students.end(), student_sort_med);
        break;
    default:
        break;
    }
}

bool Calc_Students::student_sort_f_name(Student const &lhs, Student const &rhs)
{
    return lhs.get_f_name() < rhs.get_f_name();
}

bool Calc_Students::student_sort_l_name(Student const &lhs, Student const &rhs)
{
    return lhs.get_l_name() < rhs.get_l_name();
}

bool Calc_Students::student_sort_avg(Student const &lhs, Student const &rhs)
{
    return lhs.get_final_score_avg() < rhs.get_final_score_avg();
}

bool Calc_Students::student_sort_med(Student const &lhs, Student const &rhs)
{
    return lhs.get_final_score_med() < rhs.get_final_score_med();
}
