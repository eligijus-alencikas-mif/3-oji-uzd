#include "read_students.h"

File_students::File_students(const std::string &file_name)
{
    this->openFile(file_name);
    this->count_hw();
}

File_students::File_students() {}

File_students::~File_students()
{
    this->closeFile();
}

void File_students::open(const std::string &file_name)
{
    this->openFile(file_name);
    this->count_hw();
}

void File_students::openFile(const std::string &file_name)
{
    try
    {
        this->file.open(file_name);
        if (!this->file.is_open())
        {
            this->file_opened = false;
            std::cerr << "Nebuvo galima atidaryti failo" << std::endl;
        }
        else
        {
            this->file_opened = true;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Ivyko klaida" << "\n";
        this->error = "ERROR: " + static_cast<std::string>(e.what());
    }
}

void File_students::closeFile()
{
    try
    {
        this->file.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Ivyko klaida" << "\n";
        this->error = "ERROR: " + static_cast<std::string>(e.what());
    }
}

void File_students::count_hw()
{
    try
    {
        std::string line;
        std::getline(this->file, line);
        this->num_of_hw = 0;

        std::istringstream iss(line);

        while (iss >> this->word)
        {
            this->num_of_hw++;
            if (this->word == "Egz.")
            {
                break;
            }
        }
        this->num_of_hw -= 3;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Ivyko klaida" << "\n";

        this->error = "ERROR: " + static_cast<std::string>(e.what());
    }
}

void File_students::read_students(Vector<Student> &students)
{
    try
    {
        std::string line;

        while (std::getline(this->file, line))
        {
            std::istringstream iss(line);
            Student student;
            std::string temp;
            iss >> temp;
            student.set_f_name(temp);
            iss >> temp;
            student.set_l_name(temp);

            for (int i = 0; i < this->num_of_hw; i++)
            {
                std::string grade;
                iss >> grade;
                student.push_hw_score(stoi(grade));
            }
            std::string exam_score;
            iss >> exam_score;
            student.set_exam_score(stoi(exam_score));
            student.disallow_cval_mod();
            students.push_back(student);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Ivyko klaida" << "\n";
        this->error = "ERROR: " + static_cast<std::string>(e.what());
    }
}
