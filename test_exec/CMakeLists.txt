cmake_minimum_required(VERSION 3.24)
project(test_exec C)

# Test executable
add_executable(test_exec main.c)

target_link_options(test_exec PUBLIC -Wl,--no-as-needed -Wl,--export-dynamic)

target_include_directories(test_exec
        PUBLIC /usr/local/include/dahua
        PUBLIC ../wrapper)

target_link_directories(test_exec
        PUBLIC /usr/local/lib/dahua
        PUBLIC ../cmake-build-debug/wrapper)

target_link_libraries(test_exec wrapper dhnetsdk)