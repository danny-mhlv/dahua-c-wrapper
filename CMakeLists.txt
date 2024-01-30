cmake_minimum_required(VERSION 3.24)
project(dahua-c-wrapper LANGUAGES C CXX)
include(GNUInstallDirs)

set(WRAPPER_NAME ${PROJECT_NAME})

set(${WRAPPER_NAME}_SRC
	src/dh-wrap.cpp
	src/default-callbacks.cpp)

set(${WRAPPER_NAME}_INC
	include/dh-wrap.h)

add_library(${WRAPPER_NAME} SHARED ${${WRAPPER_NAME}_SRC} ${${WRAPPER_NAME}_INC})

target_link_options(${WRAPPER_NAME} PUBLIC -Wl,--no-as-needed -Wl,--export-dynamic)

set(DAHUA_INC_PATH "${CMAKE_INSTALL_INCLUDEDIR}/dahua" CACHE PATH "Dahua SDK include directory")
set(DAHUA_LIB_PATH "${CMAKE_INSTALL_LIBDIR}" CACHE PATH "Dahua SDK library directory")

# External dependency (Original Dahua library)
target_include_directories(${WRAPPER_NAME}
	PUBLIC 
		${DAHUA_INC_PATH}
)

find_library(DAHUA_LIBS
	NAMES
		dhnetsdk
		dhconfigsdk
	HINTS
		${DAHUA_LIB_PATH}
	REQUIRED
)
target_link_libraries(${WRAPPER_NAME}
	PUBLIC
		${DAHUA_LIBS}
)

install(TARGETS ${WRAPPER_NAME}
	EXPORT ${WRAPPER_NAME}
	LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}/${WRAPPER_NAME}"           COMPONENT shlib
	PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${WRAPPER_NAME}" COMPONENT dev
)

install(DIRECTORY "${PROJECT_SOURCE_DIR}/include" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${WRAPPER_NAME}"
	FILES_MATCHING PATTERN "*.h"
)