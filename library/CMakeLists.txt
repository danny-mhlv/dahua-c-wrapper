cmake_minimum_required(VERSION 3.24)
project(clg_lib C)

set(CMAKE_C_STANDARD 11)

# Library
add_library(dhlib SHARED
        library.c)

target_include_directories(dhlib
        PUBLIC /usr/local/include/dahua)

target_link_directories(dhlib
        PUBLIC /usr/local/lib/dahua)

target_link_libraries(dhlib dhwrap)