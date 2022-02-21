Project(ViGEmClient)
cmake_minimum_required(VERSION 3.20.2)

set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/ViGEmClient.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Internal.h ${CMAKE_CURRENT_SOURCE_DIR}/src/resource.h ${CMAKE_CURRENT_SOURCE_DIR}/src/ViGEmClient.rc)
add_library(ViGEmClient EXCLUDE_FROM_ALL ${SOURCES})
target_include_directories(ViGEmClient PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
