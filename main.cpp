#include <iostream>
#include "vector.hpp"

int main(int argc, char **argv)
{
    Vector<int> my_vector;
    my_vector.push_back(1);
    my_vector.push_back(2);

    my_vector.at(5); // This will throw an exception

    return 0;
}
