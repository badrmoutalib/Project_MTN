# cmake version to be used
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name
project(Create_raster)

set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++11") 

include_directories(../include/proj ../include/CGAL ../include/catch ../src)

# external_libraries
set(PROJ_LIB libproj.so)
find_package(CGAL)
link_directories(./lib/proj/lib )

# internal_libraries
add_library(Projection SHARED ../src/Projection.cpp ../src/Projection.h)


# target
add_executable(test1 ./test_Projection.cpp)

target_link_libraries(test1 Projection ${PROJ_LIB})

