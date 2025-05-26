#ifndef PROCESS_SETTINGS_H
#define PROCESS_SETTINGS_H

struct Process_settings
{
    bool generate_names = false;
    bool generate_grades = false;
    bool get_students_from_file = false;
    int sort_method = 0;
    bool output_to_file = false;
    bool generate_input_file = false;
    int input_file_student_num = 0;
    int input_file_student_hw = 0;
    std::string input_file_name;
    int distribution_strategy = 0;
};

#endif // PROCESS_SETTINGS_H
