cmake_minimum_required(VERSION 3.24)
project(clg_test_x C)

# Test executable
add_executable(test_x main.c)

target_link_options(test_x PUBLIC -Wl,--no-as-needed -Wl,--export-dynamic)

target_include_directories(test_x
        PUBLIC /usr/local/include/dahua)

target_link_directories(test_x
        PUBLIC /usr/local/lib/dahua
        PUBLIC ../cmake-build-debug-gcc/so_wrapper
        PUBLIC ../cmake-build-debug-gcc/so_library)

target_link_libraries(test_x lib wrapper dhnetsdk)