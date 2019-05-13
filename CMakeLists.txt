cmake_minimum_required(VERSION 3.13)
project(Bar)

set(CMAKE_CXX_STANDARD 11)

add_executable(Bar main.cpp Observer.h Subject.h ProgressBar.cpp ProgressBar.h FileTransfer.cpp FileTransfer.h)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Bar ${SFML_LIBRARIES})
endif ()