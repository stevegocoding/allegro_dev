cmake_minimum_required(VERSION 2.8)

# The solution
project(allegro_dev)

# Include necessary submodules
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/packages" )

# Dependencies DLL directory
set(DEP_DLL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/deps/bin/) 

# Dependencies include path
include_directories(${PROJECT_SOURCE_DIR}/deps/include/) 

# Dependencies lib path
link_directories(${PROJECT_SOURCE_DIR}/deps/lib/) 

# Subdirectory 
add_subdirectory(data)
add_subdirectory(src)