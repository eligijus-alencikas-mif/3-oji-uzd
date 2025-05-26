#include "inputs.h"

int CLInputs::numInput(const std::string &prompt, const int limit_max, const int limit_min)
{
    try
    {
        int num;
        while (true)
        {
            cout << prompt;
            if (cin >> num)
            {
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if (num > limit_max)
                {
                    cout << "Ivestas per didelis skaicius\n";
                    continue;
                }
                if (num < limit_min)
                {
                    cout << "Ivestas per mazas skaicius\n";
                    continue;
                }
                break;
            }
            else
            {
                cout << "Klaidinga ivestis\n";
                cin.clear();
                cin.ignore(int_lim::max(), '\n');
            }
        }
        return num;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Ivyko klaida" << "\n";
        return std::numeric_limits<int>::min();
    }
}

std::string CLInputs::strInput(const std::string &prompt, const int limit_max, const int limit_min)
{
    try
    {
        std::string str;
        while (true)
        {
            cout << prompt;
            if (cin >> str)
            {
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if (static_cast<int>(str.length()) > limit_max)
                {
                    cout << "Per ilga ivestis\n";
                    continue;
                }
                if (static_cast<int>(str.length()) < limit_min)
                {
                    cout << "Per trumpa ivestis\n";
                    continue;
                }
                break;
            }
            else
            {
                cout << "Klaidinga ivestis\n";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        return str;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Ivyko klaida" << "\n";
        return "ERROR: " + static_cast<std::string>(e.what());
    }
}