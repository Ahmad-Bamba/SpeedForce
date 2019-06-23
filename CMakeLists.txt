cmake_minimum_required (VERSION 3.0.2...3.13)

if (${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy (VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif ()

project (SpeedForce VERSION 0.0.1
        	    DESCRIPTION "Vector math library for Python 3.x"
                    LANGUAGES CXX)

add_executable (ctests src/ctests.cpp)
target_include_directories(ctests PUBLIC include)
