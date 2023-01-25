cmake_minimum_required(VERSION 3.24)
project(clg_wrap)

# Wrapper
add_library(dhwrap SHARED
        wrapper.cpp buffer.cpp)

target_include_directories(dhwrap
        PUBLIC /usr/local/include/dahua)

target_link_directories(dhwrap
        PUBLIC /usr/local/lib/dahua)

target_link_libraries(dhwrap dhnetsdk)