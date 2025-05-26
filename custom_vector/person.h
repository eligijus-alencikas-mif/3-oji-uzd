#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
protected:
    std::string f_name, l_name;

public:
    Person(std::string f_name, std::string l_name) : f_name(f_name), l_name(l_name) {};
    Person() : f_name(""), l_name("") {};
    ~Person()
    {
        f_name.clear();
        l_name.clear();
    };

    std::string get_f_name() const { return f_name; };
    std::string get_l_name() const { return l_name; };

    void set_f_name(std::string f_name) { this->f_name = f_name; };
    void set_l_name(std::string l_name) { this->l_name = l_name; };

    virtual std::string get_full_name() = 0;
};

#endif // PERSON_H