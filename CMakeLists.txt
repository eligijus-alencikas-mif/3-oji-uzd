cmake_minimum_required(VERSION 3.10)
project(my_vector)

set(GOOGLETEST_VERSION 1.15.2)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-O3")

enable_testing()

add_subdirectory(googletest)

include_directories(googletest/include)

add_executable(mytests 
    test/main.cpp
)

target_link_libraries(mytests PRIVATE gtest)

include(GoogleTest)

gtest_discover_tests(mytests)

# Add the executable
add_executable(my_vector
    main.cpp
)

add_executable(vector_speedtest
    test/speedtest.cpp
)

add_executable(1.5v
    std_vector/main.cpp
    std_vector/cl_students.cpp
    std_vector/file_gen.cpp
    std_vector/generator.cpp
    std_vector/output_students.cpp
    std_vector/read_students.cpp
    std_vector/students_calc.cpp
    std_vector/timer.cpp
    std_vector/student.cpp
    std_vector/inputs.cpp
    std_vector/student_test.cpp
)

add_executable(1.5v_custom
    custom_vector/main.cpp
    custom_vector/cl_students.cpp
    custom_vector/file_gen.cpp
    custom_vector/generator.cpp
    custom_vector/output_students.cpp
    custom_vector/read_students.cpp
    custom_vector/students_calc.cpp
    custom_vector/timer.cpp
    custom_vector/student.cpp
    custom_vector/inputs.cpp
    custom_vector/student_test.cpp
)

# Include directories
target_include_directories(my_vector PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)