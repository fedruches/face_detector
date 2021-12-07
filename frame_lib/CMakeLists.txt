cmake_minimum_required(VERSION 3.5)

project(grabberLib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED COMPONENTS thread)

include_directories(
    ${OpenCV_INCLUDE_DIRS}
    ${Boost_INCLUDE_DIR}
    ${BOOST_LOCKFREE_DIR})


add_library(${PROJECT_NAME} grabber.cpp frame_processor.cpp)
target_link_libraries(${PROJECT_NAME}
    ${OpenCV_LIBS}
    ${Boost_LIBRARIES})