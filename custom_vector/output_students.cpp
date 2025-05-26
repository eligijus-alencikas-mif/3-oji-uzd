#include "output_students.h"

Output_students::Output_students()
{
    output = std::ofstream();
}

Output_students::~Output_students()
{
    this->close_file();
}

void Output_students::open_file(const std::string &file_name)
{
    try
    {
        if (output.is_open())
        {
            this->close_file();
        }
        output.open(file_name);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Ivyko klaida" << "\n";
        this->error = "ERROR: " + static_cast<std::string>(e.what());
    }
}

void Output_students::close_file()
{
    try
    {
        output.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Ivyko klaida" << "\n";
        this->error = "ERROR: " + static_cast<std::string>(e.what());
    }
}

void Output_students::output_students(Vector<Student> const &students, const bool &out_to_file)
{
    try
    {
        if (out_to_file)
        {
            this->output_file(students);
        }
        else
        {
            this->output_terminal(students);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Ivyko klaida" << "\n";
        this->error = "ERROR: " + static_cast<std::string>(e.what());
    }
}

void Output_students::output_file(Vector<Student> const &students)
{
    try
    {
        this->output
            << std::setw(NAME_LENGTH) << std::left << "Vardas"
            << std::setw(NAME_LENGTH) << std::left << "Pavarde"
            << "Galutinis (Vid.) Galutinis (Med.)"
            << '\n';
        const size_t line_length = (NAME_LENGTH * 2) + 33;
        for (size_t i = 0; i < line_length; i++)
        {
            this->output << "-";
        }
        this->output << '\n';

        for (const Student &student : students)
        {
            this->output << std::setw(NAME_LENGTH) << std::left << student.get_f_name()
                         << std::setw(NAME_LENGTH) << std::left << student.get_l_name()
                         << std::setw(17) << std::left << std::setprecision(3) << student.get_final_score_avg()
                         << std::setprecision(3) << student.get_final_score_med()
                         << '\n';
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Ivyko klaida" << "\n";
        this->error = "ERROR: " + static_cast<std::string>(e.what());
    }
}

void Output_students::output_terminal(Vector<Student> const &students)
{
    try
    {
        cout << '\n'
             << std::setw(NAME_LENGTH) << std::left << "Vardas"
             << std::setw(NAME_LENGTH) << std::left << "Pavarde"
             << "Galutinis (Vid.) Galutinis (Med.)"
             << '\n';
        const size_t line_length = (NAME_LENGTH * 2) + 33;
        for (size_t i = 0; i < line_length; i++)
        {
            cout << "-";
        }
        cout << '\n';

        for (Student const &student : students)
        {
            cout << std::setw(NAME_LENGTH) << std::left << student.get_f_name()
                 << std::setw(NAME_LENGTH) << std::left << student.get_l_name()
                 << std::setw(17) << std::left << std::setprecision(3) << student.get_final_score_avg()
                 << std::setprecision(3) << student.get_final_score_med()
                 << '\n';
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Ivyko klaida" << "\n";
        this->error = "ERROR: " + static_cast<std::string>(e.what());
    }
}