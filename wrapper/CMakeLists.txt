cmake_minimum_required(VERSION 3.24)
project(clg_wrapper)

# Wrapper
add_library(wrapper SHARED dh-wrap.cpp default-callbacks.cpp)

target_link_options(wrapper PUBLIC -Wl,--no-as-needed -Wl,--export-dynamic)

target_include_directories(wrapper
        PUBLIC /usr/local/include/dahua)

target_link_directories(wrapper
        PUBLIC /usr/local/lib/dahua)

target_link_libraries(wrapper dhnetsdk dhconfigsdk)