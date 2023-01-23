cmake_minimum_required(VERSION 3.24)
project(clibgo)

add_subdirectory(library so_library)
add_subdirectory(wrapper so_wrapper)
add_subdirectory(test_exec exec_test)