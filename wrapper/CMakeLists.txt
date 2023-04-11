cmake_minimum_required(VERSION 3.24)
project(clg_wrapper)

# Wrapper
add_library(wrapper SHARED dh-wrap.cpp
        data-structures/camera-structs.h
        enums.h
        data-structures/video-structs.h
        data-structures/common-structs.h
        data-structures/device-structs.h
        data-structures/config-structs.h
        constants/config-constants.h
        constants/common-constants.h
        constants/state-constants.h
        constants/config-commands.h)

#target_compile_options(wrapper PUBLIC -v)
target_link_options(wrapper PUBLIC -Wl,--no-as-needed -Wl,--export-dynamic)

target_include_directories(wrapper
        PUBLIC /usr/local/include/dahua)

target_link_directories(wrapper
        PUBLIC /usr/local/lib/dahua)

target_link_libraries(wrapper dhnetsdk dhconfigsdk)