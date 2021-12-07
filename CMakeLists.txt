cmake_minimum_required(VERSION 3.5)

project(face_detection LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)
include_directories(
    ${OpenCV_INCLUDE_DIRS}
    frame_lib)

add_subdirectory(frame_lib)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} grabberLib)