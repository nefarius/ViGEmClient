Project(ViGEmClient)
cmake_minimum_required(VERSION 3.20.2)

# use -DViGEmClient_DLL=ON on the cmake command line to change this value
option(ViGEmClient_DLL "Generate a dynamic library instead of a static library" OFF)

set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/ViGEmClient.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Internal.h ${CMAKE_CURRENT_SOURCE_DIR}/src/resource.h ${CMAKE_CURRENT_SOURCE_DIR}/src/ViGEmClient.rc)
if(ViGEmClient_DLL)
	# Generate a dynamic library with proper link dependencies
	add_library(ViGEmClient SHARED EXCLUDE_FROM_ALL ${SOURCES})
	target_link_libraries (ViGEmClient setupAPI.lib)
else()
	# Generate a static library, no link dependencies needed
	add_library(ViGEmClient EXCLUDE_FROM_ALL ${SOURCES})
endif()
target_include_directories(ViGEmClient PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
