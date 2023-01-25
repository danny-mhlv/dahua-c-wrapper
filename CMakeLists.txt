cmake_minimum_required(VERSION 3.24)
project(clibgo)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

add_subdirectory(wrapper dhwrapper)
add_subdirectory(library dhlibrary)
add_subdirectory(test_exec exec_test)