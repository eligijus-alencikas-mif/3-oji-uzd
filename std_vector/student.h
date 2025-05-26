#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include <string>
#include "person.h"
#include "constant_definitions.h"
#include <vector>
#include <string>
#include <iostream>
#include <limits>

class Student : public Person
{
private:
    std::vector<int> hw_scores;
    int exam_score{};
    double final_score_avg{};
    double final_score_med{};
    bool allow_cval_mod = true;

public:
    Student(std::string f_name = "", std::string l_name = "", std::vector<int> hw_scores = {}, int exam_score = 0) : Person(f_name, l_name), hw_scores(hw_scores), exam_score(exam_score) {};

    ~Student();
    Student(const Student &other);

    Student &operator=(const Student &other);
    Student(Student &&other) noexcept;
    Student &operator=(Student &&other) noexcept;

    friend std::ostream &operator<<(std::ostream &os, const Student &student);
    friend std::istream &operator>>(std::istream &is, Student &student);

    std::vector<int> get_hw_scores() const;
    int get_exam_score() const;
    double get_final_score_avg() const;
    double get_final_score_med() const;
    void set_hw_scores(std::vector<int> hw_scores);
    void set_exam_score(int exam_score);
    void set_final_score_avg(double final_score_avg);
    void set_final_score_med(double final_score_med);
    void push_hw_score(int hw_score);
    void disallow_cval_mod();
    std::string get_full_name() override;
};

#endif // STUDENT_H
