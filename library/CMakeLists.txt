cmake_minimum_required(VERSION 3.24)
project(clg_lib C)

set(CMAKE_C_STANDARD 11)

# Library
add_library(lib SHARED
        library.c buffer.c mt-funcs.c callbacks.c)

target_compile_options(lib PUBLIC -v)
#target_link_options(lib PUBLIC -Wl,--no-as-needed -Wl,--export-dynamic)

target_include_directories(lib
        PUBLIC /usr/local/include/dahua)

target_link_directories(lib
        PUBLIC /usr/local/lib/dahua)

target_link_libraries(lib dhnetsdk)