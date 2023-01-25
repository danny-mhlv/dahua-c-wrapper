cmake_minimum_required(VERSION 3.24)
project(clg_test_x C)

# Test executable
add_executable(test_x main.c)

target_include_directories(test_x
        PUBLIC /usr/local/include/dahua)

target_link_directories(test_x
        PUBLIC /usr/local/lib/dahua
        PUBLIC ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

target_link_libraries(test_x dhlib)