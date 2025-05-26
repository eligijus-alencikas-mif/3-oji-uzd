#include "student_test.h"

bool StudentTest::test_destructor()
{
    Student *student;
    new Student("John", "Doe", {9, 8, 5}, 3);
    delete student;
    return true;
}

bool StudentTest::test_copy_constructor()
{
    Student original("John", "Doe", {9, 8, 5}, 3);
    Student copy(original); // Copy constructor should be called here

    // Check if the copied object has the same data as the original
    return (copy.get_f_name() == original.get_f_name() &&
            copy.get_l_name() == original.get_l_name() &&
            copy.get_hw_scores() == original.get_hw_scores() &&
            copy.get_exam_score() == original.get_exam_score() &&
            copy.get_final_score_avg() == original.get_final_score_avg() &&
            copy.get_final_score_med() == original.get_final_score_med());
}

bool StudentTest::test_copy_assignment_operator()
{
    Student original("John", "Doe", {9, 8, 5}, 3);
    Student copy("Jane", "Smith", {4, 1, 3}, 10); // Different data

    copy = original; // Copy assignment operator should be called here

    // Check if the copied object has the same data as the original
    return (copy.get_f_name() == original.get_f_name() &&
            copy.get_l_name() == original.get_l_name() &&
            copy.get_hw_scores() == original.get_hw_scores() &&
            copy.get_exam_score() == original.get_exam_score() &&
            copy.get_final_score_avg() == original.get_final_score_avg() &&
            copy.get_final_score_med() == original.get_final_score_med());
}

bool StudentTest::test_move_constructor()
{
    Student original("John", "Doe", {9, 8, 5}, 3);
    Calc_Students::set_student_avg(original);
    Calc_Students::set_student_median(original);
    Student moved(std::move(original)); // Move constructor should be called here

    // Check if the moved object has the same data as the original
    return (moved.get_f_name() == "John" &&
            moved.get_l_name() == "Doe" &&
            moved.get_hw_scores() == std::vector<int>{9, 8, 5} &&
            moved.get_exam_score() == 3 &&
            moved.get_final_score_avg() == Calc_Students::calc_average(std::vector<int>{9, 8, 5}, 3) &&
            moved.get_final_score_med() == 6.5);
}

bool StudentTest::test_move_assignment_operator()
{
    Student original("John", "Doe", {9, 8, 5}, 3);
    Calc_Students::set_student_avg(original);
    Calc_Students::set_student_median(original);
    Student moved("Jane", "Smith", {4, 1, 3}, 10); // Different data

    moved = std::move(original); // Move assignment operator should be called here

    // Check if the moved object has the same data as the original
    return (moved.get_f_name() == "John" &&
            moved.get_l_name() == "Doe" &&
            moved.get_hw_scores() == std::vector<int>{9, 8, 5} &&
            moved.get_exam_score() == 3 &&
            moved.get_final_score_avg() == Calc_Students::calc_average(std::vector<int>{9, 8, 5}, 3) &&
            moved.get_final_score_med() == 6.5);
}

bool StudentTest::test_input_operator()
{
    std::istringstream input("John Doe 9 8 5 -1 3");
    Student student;
    input >> student;

    // Check if the student object has the expected data
    return (student.get_f_name() == "John" &&
            student.get_l_name() == "Doe" &&
            student.get_hw_scores() == std::vector<int>{9, 8, 5} &&
            student.get_exam_score() == 3);
}

bool StudentTest::test_output_operator()
{
    Student student("John", "Doe", {9, 8, 5}, 3);
    std::ostringstream output;
    output << student;
    // Check if the output string matches the expected format
    std::string expected_output = "John Doe\nNamu darbu rezultatai: 9 8 5\nEgzamino rezultatas: 3\nGalutinis balas (Vidurkis): 0\nGalutinis balas (Mediana): 0\n";
    return (output.str() == expected_output);
}

std::tuple<bool, std::string> StudentTest::test_all()
{
    std::tuple<bool, std::string> result = {true, ""};

    if (test_destructor())
    {
        std::get<1>(result) += "Destructor test passed.\n";
    }
    else
    {
        std::get<0>(result) = false;
        std::get<1>(result) += "Destructor test failed.\n";
    }
    if (test_copy_constructor())
    {
        std::get<1>(result) += "Copy constructor test passed.\n";
    }
    else
    {
        std::get<0>(result) = false;
        std::get<1>(result) += "Copy constructor test failed.\n";
    }
    if (test_copy_assignment_operator())
    {
        std::get<1>(result) += "Copy assignment operator test passed.\n";
    }
    else
    {
        std::get<0>(result) = false;
        std::get<1>(result) += "Copy assignment operator test failed.\n";
    }
    if (test_move_constructor())
    {
        std::get<1>(result) += "Move constructor test passed.\n";
    }
    else
    {
        std::get<0>(result) = false;
        std::get<1>(result) += "Move constructor test failed.\n";
    }
    if (test_move_assignment_operator())
    {
        std::get<1>(result) += "Move assignment operator test passed.\n";
    }
    else
    {
        std::get<0>(result) = false;
        std::get<1>(result) += "Move assignment operator test failed.\n";
    }
    if (test_input_operator())
    {
        std::get<1>(result) += "Input operator test passed.\n";
    }
    else
    {
        std::get<0>(result) = false;
        std::get<1>(result) += "Input operator test failed.\n";
    }
    if (test_output_operator())
    {
        std::get<1>(result) += "Output operator test passed.\n";
    }
    else
    {
        std::get<0>(result) = false;
        std::get<1>(result) += "Output operator test failed.\n";
    }

    return result;
}
