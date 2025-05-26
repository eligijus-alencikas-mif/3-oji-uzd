#include "main.h"

typedef std::numeric_limits<int> int_lim;

int main()
{
    Timer t;

    Process_settings settings{};

    srand(time(nullptr));

    int choice = CLInputs::numInput(
        "Pasirinkte duomenu generavimo metoda (1 - Ranka, 2 - Generuoti pazymius, 3 - Generuoti ir pazymius ir studentu vardus, pavardes, 4 - Skaityti is failo, 5 - Generuoti faila, 6 - Baigti darba, 7 - Testuoti Studento klase): ",
        7, 1);

    switch (choice)
    {
    case 1:
        settings.generate_names = false;
        settings.generate_grades = false;
        settings.get_students_from_file = false;
        break;
    case 2:
        settings.generate_grades = true;
        break;
    case 3:
        settings.generate_names = true;
        settings.generate_grades = true;
        break;
    case 4:
        settings.get_students_from_file = true;
        break;
    case 5:
        settings.generate_input_file = true;
        break;
    case 7:
    {
        auto result = StudentTest::test_all();
        std::cout << std::get<1>(result);
    }
        return 0;
    default:
        return 0;
    }

    if (settings.generate_input_file)
    {
        int student_num = CLInputs::numInput("Iveskite sugeneruoto failo studentu skaiciu: ", int_lim::max(), 1);
        int hw_num = CLInputs::numInput("Iveskite sugeneruot failo namu darbu skaiciu: ", int_lim::max(), 1);
        std::string file_name = CLInputs::strInput("Iveskite sugeneruoto failo pavadinima: ");

        t.initialize_watch(2, "Failo kurimo laikas");
        t.start_watch(2);
        FileGen::gen_file(student_num, hw_num, file_name);
        t.pause_watch(2);
        cout << "Baigtas failo kurimas\n";
        return 0;
    }

    File_students file;

    if (settings.get_students_from_file)
    {
        settings.input_file_name = CLInputs::strInput("Iveskite nuskaitomo failo pavadinima: ");
        file.open(settings.input_file_name);
        if (!file.file_opened)
            return 0;
    }

    settings.sort_method = CLInputs::numInput(
        "Pasirinkite rusiavimo buda (1 - pagal varda, 2 - pagal pavarde, 3 - pagal pazymiu vidurki, 4 - pagal pazymiu mediana, 5 - nerusiuoti): ",
        5, 1);
    settings.output_to_file = CLInputs::numInput("Pasirinkite isvesties buda (1 - terminalas, 2 - failas): ", 2, 1) ==
                              2;

    t.initialize_watch(1, "Pilnas veikimo laikas");
    t.start_watch(1);

    Vector<Student> students;

    if (settings.get_students_from_file)
    {
        t.initialize_watch(3, "Nuskaitymo is failo laikas");
        t.start_watch(3);
        file.read_students(students);
        t.pause_watch(3);
    }
    else
    {
        students = CL_Students::get_user_input(
            settings.generate_names,
            settings.generate_grades);
    }

    t.initialize_watch(4, "Pazymiu skaiciavimo laikas");
    t.start_watch(4);
    Calc_Students::calc_grades(students);
    t.pause_watch(4);
    t.initialize_watch(5, "Pazymiu rusiavimo laikas");
    t.start_watch(5);
    Calc_Students::sort_students(students, settings.sort_method);
    t.pause_watch(5);

    Vector<Student> low_st;
    Vector<Student> high_st;

    Output_students output;

    if (settings.output_to_file)
        output.open_file("out.txt");
    output.output_students(students, settings.output_to_file);
    if (settings.output_to_file)
        output.close_file();

    t.initialize_watch(6, "Studentu skirstymo laikas");
    t.start_watch(6);

    size_t students_new_size = 0;
    for (size_t i = 0; i < students.get_size(); i++)
    {
        auto student = students[i];
        if (student.get_final_score_avg() < 5.0)
        {
            low_st.push_back(student);
        }
        else
        {
            students.at(students_new_size++) = student;
        }
    }
    students.resize(students_new_size);

    t.pause_watch(6);

    t.initialize_watch(7, "Studentu isvedimo laikas");
    t.start_watch(7);
    output.open_file("nuskriaustukai.txt");
    output.output_students(low_st, true);
    output.close_file();
    low_st.clear();

    output.open_file("galvociai.txt");

    output.output_students(students, true);
    output.close_file();
    students.clear();
    t.pause_watch(7);

    t.pause_watch(1);
    t.write_times("laikai.txt");
    return 0;
}
