#include <iostream>
#include <chrono>
#include <vector>
#include "../vector.hpp"

int main(int argc, char *argv[])
{
    size_t size = 10000;
    size_t num_of_tests = 10;

    std::cout << "\nCustom vector and std::vector speed comparison test\n\n";
    std::cout << "Number of tests run for average: " << num_of_tests << std::endl;

    for (size_t multiplier = 1; multiplier <= 10000; multiplier *= 10)
    {
        size_t std_vector_resize = 0;
        size_t custom_vector_resize = 0;

        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Testing with size: " << size * multiplier << std::endl;

        std::vector<std::chrono::duration<double>> std_vec_sizes;
        std::vector<std::chrono::duration<double>> my_vec_sizes;

        std::chrono::duration<double> elapsed;

        for (size_t i = 0; i < num_of_tests; ++i)
        {
            auto start = std::chrono::high_resolution_clock::now();

            std::vector<int> std_vector;

            for (size_t i = 0; i < size * multiplier; ++i)
            {
                if (std_vector.size() == std_vector.capacity())
                {
                    std_vector_resize++;
                }
                std_vector.push_back(i);
            }

            auto end = std::chrono::high_resolution_clock::now();
            elapsed = end - start;
            std_vec_sizes.push_back(elapsed);

            std_vector.clear();

            start = std::chrono::high_resolution_clock::now();

            Vector<int> custom_vector;

            for (size_t i = 0; i < size * multiplier; ++i)
            {
                if (custom_vector.get_size() == custom_vector.get_capacity())
                {
                    custom_vector_resize++;
                }
                custom_vector.push_back(i);
            }

            end = std::chrono::high_resolution_clock::now();
            elapsed = end - start;
            my_vec_sizes.push_back(elapsed);

            custom_vector.clear();
        }

        double std_vec_avg = 0;
        for (const auto &duration : std_vec_sizes)
        {
            std_vec_avg += duration.count();
        }
        std_vec_avg /= std_vec_sizes.size();

        double my_vec_avg = 0;
        for (const auto &duration : my_vec_sizes)
        {
            my_vec_avg += duration.count();
        }
        my_vec_avg /= my_vec_sizes.size();
        std::cout << "Average time for std::vector: " << std_vec_avg << " seconds\n";
        std::cout << "Average time for custom Vector: " << my_vec_avg << " seconds\n";
        std::cout << "Resize calls for std::vector: " << std_vector_resize << std::endl;
        std::cout << "Resize calls for custom Vector: " << custom_vector_resize << std::endl;
    }

    std::cout << "----------------------------------------" << std::endl;

    return 0;
}