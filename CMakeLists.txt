# cmake version to be used
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name
project(Create_raster)

set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++14") 

include_directories(./include/proj ./include/CGAL ./src)

# external_libraries
set(PROJ_LIB libproj.so)
find_package(CGAL)
link_directories(./lib/proj/lib )

# internal_libraries
add_library(Projection SHARED ./src/Projection.cpp ./src/Projection.h)
add_library(DTM SHARED ./src/DTM.cpp ./src/DTM.h)


# target
add_executable(create_raster ./src/main.cpp)

target_link_libraries(create_raster Projection DTM CGAL::CGAL ${PROJ_LIB})

