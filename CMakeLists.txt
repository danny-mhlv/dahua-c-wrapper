cmake_minimum_required(VERSION 3.24)
project(dahua-c-wrapper LANGUAGES C CXX)
include(GNUInstallDirs)

set(WRAPPER_NAME ${PROJECT_NAME})

set(${WRAPPER_NAME}_SRC
        src/dh-wrap.cpp
        src/default-callbacks.cpp)

set(${WRAPPER_NAME}_INC
        include/dh-wrap.h
)

add_library(${WRAPPER_NAME} SHARED ${${WRAPPER_NAME}_SRC} ${${WRAPPER_NAME}_INC})

target_link_options(${WRAPPER_NAME} PUBLIC -Wl,--no-as-needed -Wl,--export-dynamic)

# External dependency (Original Dahua library)
target_include_directories(${WRAPPER_NAME}
        PUBLIC "${CMAKE_INSTALL_INCLUDEDIR}/dahua")
target_link_directories(${WRAPPER_NAME}
        PUBLIC "${CMAKE_INSTALL_LIBDIR}")
target_link_libraries(${WRAPPER_NAME} dhnetsdk dhconfigsdk)

install(TARGETS ${WRAPPER_NAME}
        EXPORT ${WRAPPER_NAME}
        LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}/${WRAPPER_NAME}"           COMPONENT shlib
        PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${WRAPPER_NAME}" COMPONENT dev
)

install(DIRECTORY "${PROJECT_SOURCE_DIR}/include" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${WRAPPER_NAME}"
        FILES_MATCHING PATTERN "*.h"
)