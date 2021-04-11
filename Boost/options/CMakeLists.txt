cmake_minimum_required(VERSION 3.19)
project(parameter)

set(BOOST_ROOT /home/frederik/Programming)
set(CMAKE_CXX_STANDARD 17)
set(SOURCES main.cpp)

find_package(Boost 1.71.0 COMPONENTS program_options)

if(Boost_FOUND)
    message("BoostNotFound")
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(parameter ${SOURCES})
    target_link_libraries(parameter ${Boost_LIBRARIES})
endif()

