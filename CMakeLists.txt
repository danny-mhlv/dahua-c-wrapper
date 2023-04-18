cmake_minimum_required(VERSION 3.24)
project(dahua-c-wrapper)

set(USER_DAHUA_PATH_LIB "/usr/local/lib/dahua" CACHE STRING "Path to Dahua library files")
set(USER_DAHUA_PATH_INC "/usr/local/include/dahua" CACHE STRING "Path to Dahua include files")

add_library(wrapper SHARED dh-wrap.cpp default-callbacks.cpp)

target_link_options(wrapper PUBLIC -Wl,--no-as-needed -Wl,--export-dynamic)

target_include_directories(wrapper
        PUBLIC ${USER_DAHUA_PATH_INC})

target_link_directories(wrapper
        PUBLIC ${USER_DAHUA_PATH_LIB})

target_link_libraries(wrapper dhnetsdk dhconfigsdk)